#!/usr/bin/env python3
"""Discord bot that automates LeetCode daily sync at 8:00 AM CST."""

import asyncio
import datetime
import json
import os
import signal
import subprocess
import sys
from pathlib import Path
from zoneinfo import ZoneInfo

import discord
from discord import app_commands, ui
from discord.ext import commands, tasks
from dotenv import load_dotenv

import sync_daily
import sync_submissions
from sync_submissions import SessionExpiredError

load_dotenv()

DISCORD_TOKEN = os.environ["DISCORD_TOKEN"]
CHANNEL_ID = int(os.environ["DISCORD_CHANNEL_ID"])

SHEET_ID = os.environ["SHEET_ID"]
SHEET_API_KEY = os.environ["SHEET_API_KEY"]
GID = int(os.environ.get("GID", "0"))
SUBMISSION_LINK_COLUMN = os.environ.get("SUBMISSION_LINK_COLUMN", "A")
CREDS_FILE = os.environ["GOOGLE_SERVICE_ACCOUNT_FILE"]
DATE_COL = os.environ.get("DAILY_DATE_COLUMN", "A")
PROBLEM_COL = os.environ.get("DAILY_PROBLEM_COLUMN", "B")
DIFFICULTY_COL = os.environ.get("DAILY_DIFFICULTY_COLUMN", "C")
TAGS_COL = os.environ.get("DAILY_TAGS_COLUMN", "D")
HYPERLINK_CELL = os.environ.get("HYPERLINK_CELL", "H2")

REPO_DIR = Path(__file__).parent
SESSION_FILE = REPO_DIR / os.environ.get("LEETCODE_SESSION_FILE", "session.txt")
STATE_FILE = REPO_DIR / ".last_sync.json"

CST = ZoneInfo("America/Chicago")
SYNC_TIME = datetime.time(hour=8, minute=0, tzinfo=CST)

intents = discord.Intents.default()
bot = commands.Bot(command_prefix="!", intents=intents)
sync_lock = asyncio.Lock()


def read_session() -> str:
    return SESSION_FILE.read_text().strip()


def save_state(state: dict) -> None:
    STATE_FILE.write_text(json.dumps(state, indent=2) + "\n")


def load_state() -> dict:
    if STATE_FILE.exists():
        return json.loads(STATE_FILE.read_text())
    return {}


def validate_session(session_cookie: str) -> bool:
    """Test if a LeetCode session cookie is valid by attempting to create a session."""
    try:
        sync_submissions.make_leetcode_session(session_cookie)
        return True
    except SessionExpiredError:
        return False


def git_commit_and_push(message: str) -> str:
    """Stage daily/ changes, commit, and push. Returns status message."""
    result = subprocess.run(
        ["git", "add", "daily/"],
        cwd=REPO_DIR, capture_output=True, text=True,
    )
    if result.returncode != 0:
        return f"git add failed: {result.stderr}"

    # Check if there's anything to commit
    status = subprocess.run(
        ["git", "diff", "--cached", "--quiet"],
        cwd=REPO_DIR, capture_output=True,
    )
    if status.returncode == 0:
        return "Nothing to commit."

    result = subprocess.run(
        ["git", "commit", "-m", message],
        cwd=REPO_DIR, capture_output=True, text=True,
    )
    if result.returncode != 0:
        return f"git commit failed: {result.stderr}"

    result = subprocess.run(
        ["git", "push"],
        cwd=REPO_DIR, capture_output=True, text=True,
    )
    if result.returncode != 0:
        return f"git push failed: {result.stderr}"

    return "Committed and pushed."


async def run_daily_sync(channel: discord.TextChannel) -> None:
    """Execute the full daily sync workflow."""
    results = {"daily_count": 0, "problems": [], "downloaded": [], "session_ok": True, "git": "", "errors": []}

    # Step 1: Sync daily problems to sheet (no auth needed)
    try:
        count, problems = await asyncio.to_thread(
            sync_daily.run,
            sheet_id=SHEET_ID,
            creds_file=CREDS_FILE,
            gid=GID,
            date_col=DATE_COL,
            problem_col=PROBLEM_COL,
            difficulty_col=DIFFICULTY_COL,
            tags_col=TAGS_COL,
            link_cell=HYPERLINK_CELL,
        )
        results["daily_count"] = count
        results["problems"] = problems
    except Exception as e:
        results["errors"].append(f"Daily sync failed: {e}")

    # Step 2: Sync submissions (needs auth)
    session_cookie = read_session()
    try:
        downloaded, failed = await asyncio.to_thread(
            sync_submissions.run,
            sheet_id=SHEET_ID,
            api_key=SHEET_API_KEY,
            session_cookie=session_cookie,
            outdir=str(REPO_DIR / "daily"),
            gid=GID,
            col_letter=SUBMISSION_LINK_COLUMN,
        )
        results["downloaded"] = downloaded
        if failed:
            results["errors"].append(f"{failed} submission(s) failed to download.")
    except SessionExpiredError:
        results["session_ok"] = False
        results["errors"].append("LeetCode session expired.")
    except Exception as e:
        results["errors"].append(f"Submission sync failed: {e}")

    # Step 3: Git commit and push
    if results["problems"] or results["downloaded"]:
        now = datetime.datetime.now(CST)
        today_str = f"{now.year}/{now.month}/{now.day}"
        commit_parts = [today_str]
        if results["problems"]:
            p = results["problems"][-1]
            commit_parts.append(f"{p['id']}. {p['title']}")
        elif results["downloaded"]:
            d = results["downloaded"][-1]
            commit_parts.append(f"{d['id']}. {d['title']}")
        commit_msg = "\t".join(commit_parts)
        try:
            git_result = await asyncio.to_thread(git_commit_and_push, commit_msg)
            results["git"] = git_result
        except Exception as e:
            results["errors"].append(f"Git failed: {e}")
    else:
        results["git"] = "Nothing to commit."

    # Step 4: Save state
    save_state({
        "last_sync": datetime.datetime.now(CST).isoformat(),
        "daily_count": results["daily_count"],
        "downloaded_count": len(results["downloaded"]),
        "session_ok": results["session_ok"],
        "errors": results["errors"],
    })

    # Step 5: Post summary to Discord
    embed = discord.Embed(
        title="LeetCode Daily Sync",
        timestamp=datetime.datetime.now(datetime.timezone.utc),
        color=discord.Color.green() if not results["errors"] else discord.Color.orange(),
    )

    if results["problems"]:
        problem_lines = []
        for p in results["problems"]:
            problem_lines.append(f"[{p['id']}. {p['title']}](https://leetcode.com/problems/{p['slug']}/) ({p['difficulty']})")
        embed.add_field(name="Daily Problems Added", value="\n".join(problem_lines[:5]), inline=False)
    else:
        embed.add_field(name="Daily Problems", value="Sheet already up to date.", inline=False)

    if results["downloaded"]:
        dl_names = [Path(d["path"]).name for d in results["downloaded"]]
        embed.add_field(name="Submissions Downloaded", value="\n".join(dl_names[:10]), inline=False)

    embed.add_field(name="Git", value=results["git"], inline=False)

    if results["errors"]:
        embed.add_field(name="Errors", value="\n".join(results["errors"]), inline=False)

    await channel.send(embed=embed)

    # Session expiry notification
    if not results["session_ok"]:
        await channel.send(
            "**\u26a0\ufe0f LeetCode session expired.** "
            "Please update with `/session` or edit `session.txt` manually."
        )


@tasks.loop(time=SYNC_TIME)
async def daily_sync_task():
    channel = bot.get_channel(CHANNEL_ID)
    if channel is None:
        print(f"[ERROR] Channel {CHANNEL_ID} not found.", file=sys.stderr)
        return
    async with sync_lock:
        await run_daily_sync(channel)


@bot.event
async def on_ready():
    print(f"Logged in as {bot.user} (ID: {bot.user.id})")

    # Sync slash commands
    await bot.tree.sync()
    print("Slash commands synced.")

    # Validate session on startup
    try:
        session_cookie = read_session()
        valid = await asyncio.to_thread(validate_session, session_cookie)
        if valid:
            print("LeetCode session is valid.")
        else:
            print("[WARN] LeetCode session appears expired.", file=sys.stderr)
            channel = bot.get_channel(CHANNEL_ID)
            if channel:
                await channel.send(
                    "**\u26a0\ufe0f Bot started, but LeetCode session is expired.** "
                    "Please update with `/session` or edit `session.txt`."
                )
    except Exception as e:
        print(f"[WARN] Session validation failed: {e}", file=sys.stderr)

    # Start the daily sync task
    if not daily_sync_task.is_running():
        daily_sync_task.start()
    print(f"Daily sync scheduled for {SYNC_TIME} Central Time.")


@bot.tree.command(name="sync", description="Manually trigger the daily LeetCode sync")
async def sync_command(interaction: discord.Interaction):
    if sync_lock.locked():
        await interaction.response.send_message("Sync is already in progress. Please wait.", ephemeral=True)
        return

    await interaction.response.send_message("Starting sync...", ephemeral=True)
    channel = bot.get_channel(CHANNEL_ID)
    if channel is None:
        await interaction.followup.send("Notification channel not found.", ephemeral=True)
        return

    async with sync_lock:
        await run_daily_sync(channel)


@bot.tree.command(name="status", description="Show last sync status and session validity")
async def status_command(interaction: discord.Interaction):
    state = load_state()
    session_cookie = read_session()
    valid = await asyncio.to_thread(validate_session, session_cookie)

    embed = discord.Embed(title="LeetCode Bot Status", color=discord.Color.blue())

    if state.get("last_sync"):
        embed.add_field(name="Last Sync", value=state["last_sync"], inline=False)
        embed.add_field(name="Problems Added", value=str(state.get("daily_count", 0)), inline=True)
        embed.add_field(name="Files Downloaded", value=str(state.get("downloaded_count", 0)), inline=True)
        if state.get("errors"):
            embed.add_field(name="Last Errors", value="\n".join(state["errors"]), inline=False)
    else:
        embed.add_field(name="Last Sync", value="Never", inline=False)

    embed.add_field(
        name="Session",
        value="\u2705 Valid" if valid else "\u274c Expired",
        inline=False,
    )
    embed.add_field(name="Next Sync", value=f"{SYNC_TIME} Central Time", inline=False)

    await interaction.response.send_message(embed=embed, ephemeral=True)


class SessionModal(ui.Modal, title="Update LeetCode Session"):
    session_token = ui.TextInput(
        label="LeetCode Session Token",
        style=discord.TextStyle.long,
        placeholder="Paste your LEETCODE_SESSION cookie value here...",
        required=True,
    )

    async def on_submit(self, interaction: discord.Interaction):
        token = self.session_token.value.strip()
        if not token:
            await interaction.response.send_message("Token cannot be empty.", ephemeral=True)
            return

        await interaction.response.defer(ephemeral=True)

        valid = await asyncio.to_thread(validate_session, token)
        if valid:
            SESSION_FILE.write_text(token + "\n")
            await interaction.followup.send("\u2705 Session updated and verified!", ephemeral=True)
        else:
            await interaction.followup.send(
                "\u274c Token appears invalid or expired. Session was NOT updated. "
                "Please check that you copied the full LEETCODE_SESSION cookie value.",
                ephemeral=True,
            )


@bot.tree.command(name="session", description="Update the LeetCode session token")
async def session_command(interaction: discord.Interaction):
    await interaction.response.send_modal(SessionModal())


def handle_sigterm(signum, frame):
    """Graceful shutdown: wait for sync to finish, then close bot."""
    async def shutdown():
        if sync_lock.locked():
            async with sync_lock:
                pass
        await bot.close()

    loop = bot.loop
    if loop and loop.is_running():
        loop.create_task(shutdown())


signal.signal(signal.SIGTERM, handle_sigterm)

if __name__ == "__main__":
    bot.run(DISCORD_TOKEN)
