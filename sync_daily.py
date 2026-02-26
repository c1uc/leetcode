#!/usr/bin/env python3
"""Append missing LeetCode daily problem entries to a Google Sheet."""

import datetime
import os
import sys

import requests
from dotenv import load_dotenv
from google.oauth2 import service_account
from googleapiclient.discovery import build

LEETCODE_GRAPHQL = "https://leetcode.com/graphql/"
DAILY_CHALLENGE_QUERY = """
query dailyCodingQuestionRecords($year: Int!, $month: Int!) {
    dailyCodingChallengeV2(year: $year, month: $month) {
        challenges {
            date
            question {
                questionFrontendId
                title
                titleSlug
                difficulty
                topicTags {
                    name
                }
            }
        }
    }
}
"""
SCOPES = ["https://www.googleapis.com/auth/spreadsheets"]

DIFFICULTY_OPTIONS = ["Easy", "Medium", "Hard"]

# All LeetCode topic tags (alphabetical), excluding contest tags
ALL_LEETCODE_TAGS = [
    "Array", "Backtracking", "Binary Indexed Tree", "Binary Search",
    "Binary Search Tree", "Binary Tree", "Bit Manipulation", "Bitmask",
    "Breadth-First Search", "Bucket Sort", "Combinatorics", "Concurrency",
    "Counting", "Counting Sort", "Data Stream", "Database",
    "Depth-First Search", "Design", "Divide and Conquer", "Doubly-Linked List",
    "Dynamic Programming", "Enumeration", "Eulerian Circuit", "Game Theory",
    "Geometry", "Graph", "Greedy", "Hash Function", "Hash Table",
    "Heap (Priority Queue)", "Interactive", "Iterator", "Line Sweep",
    "Linked List", "Math", "Matrix", "Memoization", "Merge Sort",
    "Minimum Spanning Tree", "Monotonic Queue", "Monotonic Stack",
    "Number Theory", "Ordered Set", "Prefix Sum", "Probability and Statistics",
    "Queue", "Quickselect", "Radix Sort", "Randomized", "Recursion",
    "Rejection Sampling", "Rolling Hash", "Segment Tree", "Shell",
    "Simulation", "Sliding Window", "Sorting", "Stack", "String",
    "String Matching", "Strongly Connected Component", "Suffix Array",
    "Topological Sort", "Tree", "Trie", "Two Pointers", "Union Find",
]

# Tag names from LeetCode API that should be excluded
_CONTEST_TAG_KEYWORDS = ("weekly", "biweekly", "contest")


def fetch_monthly_challenges(year: int, month: int) -> dict[str, dict]:
    """Return {YYYY-MM-DD: {id, title, slug, difficulty, tags}} for the given month."""
    resp = requests.post(
        LEETCODE_GRAPHQL,
        json={"query": DAILY_CHALLENGE_QUERY, "variables": {"year": year, "month": month}},
        headers={"Content-Type": "application/json", "Referer": "https://leetcode.com"},
    )
    resp.raise_for_status()
    challenges = resp.json()["data"]["dailyCodingChallengeV2"]["challenges"]
    return {
        c["date"]: {
            "id": c["question"]["questionFrontendId"],
            "title": c["question"]["title"],
            "slug": c["question"]["titleSlug"],
            "difficulty": c["question"]["difficulty"],
            "tags": [
                t["name"] for t in c["question"]["topicTags"]
                if not any(kw in t["name"].lower() for kw in _CONTEST_TAG_KEYWORDS)
            ],
        }
        for c in challenges
    }


def get_sheets(creds_file: str):
    creds = service_account.Credentials.from_service_account_file(creds_file, scopes=SCOPES)
    return build("sheets", "v4", credentials=creds, cache_discovery=False).spreadsheets()


def get_sheet_name(sheets, sheet_id: str, gid: int) -> str:
    meta = sheets.get(spreadsheetId=sheet_id, fields="sheets.properties").execute()
    for sheet in meta["sheets"]:
        if sheet["properties"]["sheetId"] == gid:
            return sheet["properties"]["title"]
    raise ValueError(f"No sheet found with GID {gid}")


def read_column(sheets, sheet_id: str, sheet_name: str, col: str) -> list[str]:
    result = sheets.values().get(
        spreadsheetId=sheet_id,
        range=f"{sheet_name}!{col}:{col}",
    ).execute()
    return [row[0].strip() if row else "" for row in result.get("values", [])]


def col_letter_to_index(col: str) -> int:
    """Convert A1-notation column letter(s) to a 0-based index. E.g. A→0, B→1, Z→25, AA→26."""
    col = col.upper()
    result = 0
    for ch in col:
        result = result * 26 + (ord(ch) - ord("A") + 1)
    return result - 1


def format_date(d: datetime.date) -> str:
    """Format as 2025/4/23 (no zero-padding)."""
    return f"{d.year}/{d.month}/{d.day}"


def parse_sheet_date(s: str) -> datetime.date:
    y, m, d = s.split("/")
    return datetime.date(int(y), int(m), int(d))


def main():
    load_dotenv()

    sheet_id = os.environ["SHEET_ID"]
    gid = int(os.environ.get("GID", "0"))
    date_col = os.environ.get("DAILY_DATE_COLUMN", "A")
    problem_col = os.environ.get("DAILY_PROBLEM_COLUMN", "B")
    difficulty_col = os.environ.get("DAILY_DIFFICULTY_COLUMN", "C")
    tags_col = os.environ.get("DAILY_TAGS_COLUMN", "D")
    creds_file = os.environ["GOOGLE_SERVICE_ACCOUNT_FILE"]

    sheets = get_sheets(creds_file)
    sheet_name = get_sheet_name(sheets, sheet_id, gid)

    date_values = read_column(sheets, sheet_id, sheet_name, date_col)
    last_row = max((i + 1 for i, v in enumerate(date_values) if v), default=0)

    if last_row == 0:
        print("No existing date entries found in the sheet.", file=sys.stderr)
        sys.exit(1)

    last_date = parse_sheet_date(date_values[last_row - 1])
    today = datetime.datetime.now(datetime.timezone.utc).date()

    missing = []
    d = last_date + datetime.timedelta(days=1)
    while d <= today:
        missing.append(d)
        d += datetime.timedelta(days=1)

    if not missing:
        print("Sheet is already up to date.")
        return

    print(f"Adding {len(missing)} missing entries (up to {format_date(today)})...")

    # Fetch LeetCode daily problems grouped by month to minimise API calls
    monthly_cache: dict[tuple[int, int], dict] = {}

    def get_problem(d: datetime.date) -> dict | None:
        key = (d.year, d.month)
        if key not in monthly_cache:
            monthly_cache[key] = fetch_monthly_challenges(d.year, d.month)
        return monthly_cache[key].get(d.strftime("%Y-%m-%d"))

    value_ranges = []
    format_requests = []
    problem_col_index = col_letter_to_index(problem_col)
    difficulty_col_index = col_letter_to_index(difficulty_col)
    tags_col_index = col_letter_to_index(tags_col)
    first_new_row = last_row + 1
    next_row = first_new_row

    for d in missing:
        problem = get_problem(d)
        if problem is None:
            print(f"[WARN] No daily problem found for {format_date(d)}, skipping", file=sys.stderr)
            continue

        title_text = f"{problem['id']}. {problem['title']}"
        url = f"https://leetcode.com/problems/{problem['slug']}/"
        hyperlink = f'=HYPERLINK("{url}","{title_text}")'
        tags_str = ", ".join(problem["tags"])

        value_ranges += [
            {"range": f"{sheet_name}!{date_col}{next_row}", "values": [[format_date(d)]]},
            {"range": f"{sheet_name}!{problem_col}{next_row}", "values": [[hyperlink]]},
            {"range": f"{sheet_name}!{difficulty_col}{next_row}", "values": [[problem["difficulty"]]]},
            {"range": f"{sheet_name}!{tags_col}{next_row}", "values": [[tags_str]]},
        ]
        # Hyperlink style for problem cell
        format_requests.append({
            "repeatCell": {
                "range": {
                    "sheetId": gid,
                    "startRowIndex": next_row - 1,
                    "endRowIndex": next_row,
                    "startColumnIndex": problem_col_index,
                    "endColumnIndex": problem_col_index + 1,
                },
                "cell": {
                    "userEnteredFormat": {
                        "textFormat": {
                            "foregroundColor": {"red": 17/255, "green": 85/255, "blue": 204/255},
                            "underline": True,
                        }
                    }
                },
                "fields": "userEnteredFormat.textFormat",
            }
        })
        print(f"  [{format_date(d)}] {problem['difficulty']:6s}  {title_text}")
        next_row += 1

    if not value_ranges:
        print("Nothing to write.")
        return

    last_new_row = next_row - 1  # inclusive, 1-based

    # Strict dropdown for difficulty (Easy / Medium / Hard)
    format_requests.append({
        "setDataValidation": {
            "range": {
                "sheetId": gid,
                "startRowIndex": first_new_row - 1,
                "endRowIndex": last_new_row,
                "startColumnIndex": difficulty_col_index,
                "endColumnIndex": difficulty_col_index + 1,
            },
            "rule": {
                "condition": {
                    "type": "ONE_OF_LIST",
                    "values": [{"userEnteredValue": v} for v in DIFFICULTY_OPTIONS],
                },
                "showCustomUi": True,
                "strict": True,
            },
        }
    })

    # Non-strict dropdown for tags (shows all known tags; cell holds comma-separated values)
    format_requests.append({
        "setDataValidation": {
            "range": {
                "sheetId": gid,
                "startRowIndex": first_new_row - 1,
                "endRowIndex": last_new_row,
                "startColumnIndex": tags_col_index,
                "endColumnIndex": tags_col_index + 1,
            },
            "rule": {
                "condition": {
                    "type": "ONE_OF_LIST",
                    "values": [{"userEnteredValue": t} for t in ALL_LEETCODE_TAGS],
                },
                "showCustomUi": True,
                "strict": False,
            },
        }
    })

    sheets.values().batchUpdate(
        spreadsheetId=sheet_id,
        body={"data": value_ranges, "valueInputOption": "USER_ENTERED"},
    ).execute()

    style_requests = [r for r in format_requests if "repeatCell" in r]
    validation_requests = [r for r in format_requests if "setDataValidation" in r]

    if style_requests:
        sheets.batchUpdate(
            spreadsheetId=sheet_id,
            body={"requests": style_requests},
        ).execute()

    if validation_requests:
        try:
            sheets.batchUpdate(
                spreadsheetId=sheet_id,
                body={"requests": validation_requests},
            ).execute()
        except Exception as e:
            if "typed columns" in str(e):
                print(
                    "[INFO] Skipped data validation: columns already have a type set in the sheet.",
                    file=sys.stderr,
                )
            else:
                raise

    print(f"Done. Added {len(missing)} entries.")


if __name__ == "__main__":
    main()
