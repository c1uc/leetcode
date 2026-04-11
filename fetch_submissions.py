#!/usr/bin/env python3
"""Fetch submitted code from LeetCode submission URLs and save to files."""

import argparse
import re
import sys
import requests

GRAPHQL_URL = "https://leetcode.com/graphql/"

SUBMISSION_DETAIL_QUERY = """
query submissionDetails($submissionId: Int!) {
    submissionDetails(submissionId: $submissionId) {
        code
        lang {
            name
            verboseName
        }
        question {
            questionFrontendId
            title
            titleSlug
        }
    }
}
"""

LANG_EXT = {
    "cpp": "cpp",
    "java": "java",
    "python": "py",
    "python3": "py",
    "c": "c",
    "csharp": "cs",
    "javascript": "js",
    "typescript": "ts",
    "php": "php",
    "swift": "swift",
    "kotlin": "kt",
    "dart": "dart",
    "golang": "go",
    "ruby": "rb",
    "scala": "scala",
    "rust": "rs",
    "racket": "rkt",
    "erlang": "erl",
    "elixir": "ex",
    "mysql": "sql",
    "mssql": "sql",
    "oraclesql": "sql",
    "pythondata": "py",
    "postgresql": "sql",
    "bash": "sh",
}

SUBMISSION_URL_RE = re.compile(
    r"https?://leetcode\.com/problems/([^/]+)/submissions/(\d+)"
)


def parse_submission_url(url: str) -> tuple[str, int]:
    m = SUBMISSION_URL_RE.match(url)
    if not m:
        raise ValueError(f"Invalid submission URL: {url}")
    return m.group(1), int(m.group(2))


def fetch_submission(session: requests.Session, submission_id: int) -> dict:
    resp = session.post(
        GRAPHQL_URL,
        json={
            "query": SUBMISSION_DETAIL_QUERY,
            "variables": {"submissionId": submission_id},
        },
    )
    resp.raise_for_status()
    data = resp.json()
    if "errors" in data:
        raise RuntimeError(f"GraphQL errors: {data['errors']}")
    detail = data.get("data", {}).get("submissionDetails")
    if not detail:
        raise RuntimeError(
            f"No submission details returned for {submission_id}. "
            "Check that your LEETCODE_SESSION cookie is valid."
        )
    return detail


def main():
    parser = argparse.ArgumentParser(
        description="Fetch LeetCode submission code and save to files."
    )
    parser.add_argument(
        "urls",
        nargs="*",
        help="LeetCode submission URLs",
    )
    parser.add_argument(
        "-f", "--file",
        help="Text file with one submission URL per line",
    )
    parser.add_argument(
        "--session",
        required=True,
        help="LEETCODE_SESSION cookie value",
    )
    parser.add_argument(
        "-o", "--outdir",
        default=".",
        help="Output directory (default: current directory)",
    )
    args = parser.parse_intermixed_args()

    urls = list(args.urls)
    if args.file:
        with open(args.file) as f:
            for line in f:
                line = line.strip()
                if line and not line.startswith("#"):
                    urls.append(line)
    if not urls:
        parser.error("No URLs provided. Pass URLs as arguments or via -f/--file.")

    sess = requests.Session()
    sess.cookies.set("LEETCODE_SESSION", args.session, domain="leetcode.com")
    sess.headers.update({
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com",
    })

    # GET the graphql endpoint to obtain a csrftoken from Set-Cookie
    sess.get(GRAPHQL_URL)
    csrf = sess.cookies.get("csrftoken", domain="leetcode.com")
    if not csrf:
        print("Failed to obtain csrftoken from LeetCode.", file=sys.stderr)
        sys.exit(1)
    sess.headers["x-csrftoken"] = csrf

    failed = 0
    for url in urls:
        try:
            _, sid = parse_submission_url(url)
        except ValueError as e:
            print(f"[SKIP] {e}", file=sys.stderr)
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

        filename = f"{q_id}.{q_slug}.{ext}"
        filepath = f"{args.outdir}/{filename}"

        with open(filepath, "w") as f:
            f.write(code)
            if not code.endswith("\n"):
                f.write("\n")

        print(f"[OK] {filepath}  ({lang})")

    if failed:
        sys.exit(1)


if __name__ == "__main__":
    main()
