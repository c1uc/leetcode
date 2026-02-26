#!/usr/bin/env python3
"""Check a Google Sheet for new LeetCode submission URLs and download them."""

import os
import sys
import requests
from pathlib import Path
from dotenv import load_dotenv

from fetch_submissions import GRAPHQL_URL, LANG_EXT, fetch_submission, parse_submission_url

SHEETS_API = "https://sheets.googleapis.com/v4/spreadsheets"
STATE_FILE = Path(__file__).parent / ".seen_urls"


def col_index_to_letter(index: int) -> str:
    """Convert 0-based column index to A1 column letter(s)."""
    result = ""
    n = index + 1
    while n:
        n, rem = divmod(n - 1, 26)
        result = chr(65 + rem) + result
    return result


def get_sheet_name(sheet_id: str, gid: int, api_key: str) -> str:
    resp = requests.get(
        f"{SHEETS_API}/{sheet_id}",
        params={"key": api_key, "fields": "sheets.properties"},
    )
    resp.raise_for_status()
    for sheet in resp.json()["sheets"]:
        props = sheet["properties"]
        if props["sheetId"] == gid:
            return props["title"]
    raise ValueError(f"No sheet found with GID {gid}")


def fetch_column_values(sheet_id: str, sheet_name: str, col_letter: str, api_key: str) -> list[str]:
    range_ = f"{sheet_name}!{col_letter}:{col_letter}"
    resp = requests.get(
        f"{SHEETS_API}/{sheet_id}/values/{range_}",
        params={"key": api_key},
    )
    resp.raise_for_status()
    rows = resp.json().get("values", [])
    return [row[0].strip() for row in rows if row and row[0].strip()]


def load_seen() -> set[str]:
    if STATE_FILE.exists():
        return set(STATE_FILE.read_text().splitlines())
    return set()


def save_seen(seen: set[str]) -> None:
    STATE_FILE.write_text("\n".join(sorted(seen)) + "\n")


def make_leetcode_session(leetcode_session_cookie: str) -> requests.Session:
    sess = requests.Session()
    sess.cookies.set("LEETCODE_SESSION", leetcode_session_cookie, domain="leetcode.com")
    sess.headers.update({"Content-Type": "application/json", "Referer": "https://leetcode.com"})
    sess.get(GRAPHQL_URL)
    csrf = sess.cookies.get("csrftoken", domain="leetcode.com")
    if not csrf:
        print("Failed to obtain csrftoken from LeetCode.", file=sys.stderr)
        sys.exit(1)
    sess.headers["x-csrftoken"] = csrf
    return sess


def main():
    load_dotenv()

    sheet_id = os.environ["SHEET_ID"]
    api_key = os.environ["SHEET_API_KEY"]
    gid = int(os.environ.get("GID", "0"))
    col_letter = os.environ.get("SUBMISSION_LINK_COLUMN", "A")
    leetcode_session = os.environ["LEETCODE_SESSION"]
    outdir = os.environ.get("OUTDIR", ".")

    sheet_name = get_sheet_name(sheet_id, gid, api_key)
    all_urls = fetch_column_values(sheet_id, sheet_name, col_letter, api_key)

    seen = load_seen()
    new_urls = [u for u in all_urls if u not in seen]

    if not new_urls:
        print("No new submissions.")
        return

    print(f"Found {len(new_urls)} new submission(s).")

    sess = make_leetcode_session(leetcode_session)
    failed = 0

    for url in new_urls:
        try:
            _, sid = parse_submission_url(url)
        except ValueError as e:
            print(f"[SKIP] {e}", file=sys.stderr)
            seen.add(url)
            failed += 1
            continue

        try:
            detail = fetch_submission(sess, sid)
        except Exception as e:
            print(f"[FAIL] {url}: {e}", file=sys.stderr)
            failed += 1
            continue

        code = detail["code"]
        lang = detail["lang"]["name"]
        q_slug = detail["question"]["titleSlug"]
        q_id = detail["question"]["questionFrontendId"]
        ext = LANG_EXT.get(lang, lang)

        filepath = f"{outdir}/{q_id}.{q_slug}.{ext}"
        with open(filepath, "w") as f:
            f.write(code)
            if not code.endswith("\n"):
                f.write("\n")

        print(f"[OK] {filepath}  ({lang})")
        seen.add(url)

    save_seen(seen)

    if failed:
        sys.exit(1)


if __name__ == "__main__":
    main()
