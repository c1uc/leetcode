#!/usr/bin/env python3
"""Discord bot that automates LeetCode daily sync."""

import asyncio
import dataclasses
import datetime
import json
import os
import signal
import subprocess
import sys
from pathlib import Path
from zoneinfo import ZoneInfo

import discord
from discord import ui
from discord.ext import commands, tasks
from dotenv import load_dotenv

import sync_daily
import sync_submissions
from sync_submissions import SessionExpiredError


# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------

@dataclasses.dataclass(frozen=True)
class Config:
    """All bot configuration, loaded once from environment variables."""

    # Discord
    discord_token: str
    channel_id: int
    bot_version: str

    # Google Sheets
    sheet_id: str
    sheet_api_key: str
    gid: int
    submission_link_column: str
    creds_file: str
    date_col: str
    problem_col: str
    difficulty_col: str
    tags_col: str
    hyperlink_cell: str

    # Paths
    app_dir: Path
    repo_dir: Path
    session_file: Path
    state_file: Path

    # Schedule
    local_tz: ZoneInfo
    sync_time: datetime.time

    @classmethod
    def from_env(cls) -> "Config":
        load_dotenv()
        app_dir = Path(__file__).parent
        tz = ZoneInfo(os.environ.get("SYNC_TIMEZONE", "Asia/Taipei"))
        sync_hour, sync_minute = (
            os.environ.get("SYNC_TIME", "21:00").split(":")
        )
        return cls(
            discord_token=os.environ["DISCORD_TOKEN"],
            channel_id=int(os.environ["DISCORD_CHANNEL_ID"]),
            bot_version=os.environ.get("BOT_VERSION", "dev"),
            sheet_id=os.environ["SHEET_ID"],
            sheet_api_key=os.environ["SHEET_API_KEY"],
            gid=int(os.environ.get("GID", "0")),
            submission_link_column=os.environ.get("SUBMISSION_LINK_COLUMN", "A"),
            creds_file=os.environ["GOOGLE_SERVICE_ACCOUNT_FILE"],
            date_col=os.environ.get("DAILY_DATE_COLUMN", "A"),
            problem_col=os.environ.get("DAILY_PROBLEM_COLUMN", "B"),
            difficulty_col=os.environ.get("DAILY_DIFFICULTY_COLUMN", "C"),
            tags_col=os.environ.get("DAILY_TAGS_COLUMN", "D"),
            hyperlink_cell=os.environ.get("HYPERLINK_CELL", "H2"),
            app_dir=app_dir,
            repo_dir=Path(os.environ.get("REPO_DIR", "/app/repo")),
            session_file=app_dir / os.environ.get("LEETCODE_SESSION_FILE", "session.txt"),
            state_file=app_dir / ".last_sync.json",
            local_tz=tz,
            sync_time=datetime.time(hour=int(sync_hour), minute=int(sync_minute), tzinfo=tz),
        )


cfg = Config.from_env()

intents = discord.Intents.default()
bot = commands.Bot(command_prefix="!", intents=intents)
sync_lock = asyncio.Lock()


# ---------------------------------------------------------------------------
# State helpers
# ---------------------------------------------------------------------------

def read_session() -> str:
    return cfg.session_file.read_text().strip()


def save_state(state: dict) -> None:
    cfg.state_file.write_text(json.dumps(state, indent=2) + "\n")


def load_state() -> dict:
    if cfg.state_file.exists():
        return json.loads(cfg.state_file.read_text())
    return {}


def validate_session(session_cookie: str) -> bool:
    """Test if a LeetCode session cookie is valid."""
    try:
        sync_submissions.make_leetcode_session(session_cookie)
        return True
    except SessionExpiredError:
        return False


# ---------------------------------------------------------------------------
# Git operations
# ---------------------------------------------------------------------------

def git_commit_and_push(message: str, max_retries: int = 3) -> str:
    """Sync with remote, stage daily/ changes, commit, and push."""
    for attempt in range(max_retries):
        result = subprocess.run(
            ["git", "pull", "--rebase", "--autostash"],
            cwd=cfg.repo_dir, capture_output=True, text=True,
        )
        if result.returncode != 0:
            return f"git pull --rebase failed: {result.stderr}"

        result = subprocess.run(
            ["git", "add", "daily/"],
            cwd=cfg.repo_dir, capture_output=True, text=True,
        )
        if result.returncode != 0:
            return f"git add failed: {result.stderr}"

        status = subprocess.run(
            ["git", "diff", "--cached", "--quiet"],
            cwd=cfg.repo_dir, capture_output=True,
        )
        if status.returncode == 0:
            return "Nothing to commit."

        result = subprocess.run(
            ["git", "commit", "-m", message],
            cwd=cfg.repo_dir, capture_output=True, text=True,
        )
        if result.returncode != 0:
            return f"git commit failed: {result.stderr}"

        result = subprocess.run(
            ["git", "push"],
            cwd=cfg.repo_dir, capture_output=True, text=True,
        )
        if result.returncode == 0:
            return "Committed and pushed."

        if attempt < max_retries - 1:
            print(f"[WARN] Push attempt {attempt + 1} failed, retrying...", file=sys.stderr)
            continue

    return f"git push failed after {max_retries} attempts: {result.stderr}"


# ---------------------------------------------------------------------------
# Sync workflow
# ---------------------------------------------------------------------------

async def run_daily_sync(channel: discord.TextChannel) -> None:
    """Execute the full daily sync workflow."""
    results = {"daily_count": 0, "problems": [], "downloaded": [], "session_ok": True, "git": "", "errors": []}

    # Step 1: Sync daily problems to sheet
    try:
        count, problems = await asyncio.to_thread(
            sync_daily.run,
            sheet_id=cfg.sheet_id,
            creds_file=cfg.creds_file,
            gid=cfg.gid,
            date_col=cfg.date_col,
            problem_col=cfg.problem_col,
            difficulty_col=cfg.difficulty_col,
            tags_col=cfg.tags_col,
            link_cell=cfg.hyperlink_cell,
        )
        results["daily_count"] = count
        results["problems"] = problems
    except Exception as e:
        results["errors"].append(f"Daily sync failed: {e}")

    # Step 2: Sync submissions
    session_cookie = read_session()
    try:
        downloaded, failed = await asyncio.to_thread(
            sync_submissions.run,
            sheet_id=cfg.sheet_id,
            api_key=cfg.sheet_api_key,
            session_cookie=session_cookie,
            outdir=str(cfg.repo_dir / "daily"),
            gid=cfg.gid,
            col_letter=cfg.submission_link_column,
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
        if results["problems"]:
            p = results["problems"][-1]
            commit_parts = [p["date"], f"{p['id']}. {p['title']}"]
        else:
            d = results["downloaded"][-1]
            now = datetime.datetime.now(cfg.local_tz)
            today_str = f"{now.year}/{now.month}/{now.day}"
            commit_parts = [today_str, f"{d['id']}. {d['title']}"]
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
        "last_sync": datetime.datetime.now(cfg.local_tz).isoformat(),
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

    if not results["session_ok"]:
        await channel.send(
            "**\u26a0\ufe0f LeetCode session expired.** "
            "Please update with `/session` or edit `session.txt` manually."
        )


# ---------------------------------------------------------------------------
# Scheduled task
# ---------------------------------------------------------------------------

@tasks.loop(time=cfg.sync_time)
async def daily_sync_task():
    channel = bot.get_channel(cfg.channel_id)
    if channel is None:
        print(f"[ERROR] Channel {cfg.channel_id} not found.", file=sys.stderr)
        return
    async with sync_lock:
        await run_daily_sync(channel)


# ---------------------------------------------------------------------------
# Discord commands
# ---------------------------------------------------------------------------

@bot.tree.command(name="sync", description="Manually trigger the daily LeetCode sync")
async def sync_command(interaction: discord.Interaction):
    if sync_lock.locked():
        await interaction.response.send_message("Sync is already in progress. Please wait.", ephemeral=True)
        return

    await interaction.response.send_message("Starting sync...", ephemeral=True)
    channel = bot.get_channel(cfg.channel_id)
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
    embed.add_field(name="Next Sync", value=f"{cfg.sync_time} ({cfg.local_tz})", inline=False)

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
            cfg.session_file.write_text(token + "\n")
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


# ---------------------------------------------------------------------------
# Lifecycle
# ---------------------------------------------------------------------------

@bot.event
async def on_ready():
    print(f"Logged in as {bot.user} (ID: {bot.user.id})")
    print(f"Bot version: {cfg.bot_version}")

    await bot.tree.sync()
    print("Slash commands synced.")

    # Announce version change
    state = load_state()
    prev_version = state.get("version")
    if prev_version and prev_version != cfg.bot_version:
        channel = bot.get_channel(cfg.channel_id)
        if channel:
            embed = discord.Embed(
                title="Bot updated",
                description=f"`{prev_version}` \u2192 `{cfg.bot_version}`",
                color=discord.Color.blurple(),
            )
            await channel.send(embed=embed)
    state["version"] = cfg.bot_version
    save_state(state)

    # Validate session on startup
    try:
        session_cookie = read_session()
        valid = await asyncio.to_thread(validate_session, session_cookie)
        if valid:
            print("LeetCode session is valid.")
        else:
            print("[WARN] LeetCode session appears expired.", file=sys.stderr)
            channel = bot.get_channel(cfg.channel_id)
            if channel:
                await channel.send(
                    "**\u26a0\ufe0f Bot started, but LeetCode session is expired.** "
                    "Please update with `/session` or edit `session.txt`."
                )
    except Exception as e:
        print(f"[WARN] Session validation failed: {e}", file=sys.stderr)

    if not daily_sync_task.is_running():
        daily_sync_task.start()
    print(f"Daily sync scheduled for {cfg.sync_time}.")


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
    bot.run(cfg.discord_token)
