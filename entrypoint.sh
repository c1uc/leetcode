#!/bin/sh
set -e

# Configure git user for commits
git config --global user.name "${GIT_USER_NAME:-leetcode-bot}"
git config --global user.email "${GIT_USER_EMAIL:-bot@noreply}"

# Configure git credentials for push (GitHub PAT)
if [ -n "$GIT_TOKEN" ]; then
    git config --global credential.helper store
    REPO_HOST="${GIT_HOST:-github.com}"
    echo "https://x-access-token:${GIT_TOKEN}@${REPO_HOST}" > ~/.git-credentials
    chmod 600 ~/.git-credentials
fi

# Docker creates directories when bind-mount sources don't exist on host.
# Replace any accidental directories with empty files.
for f in /app/.last_sync.json /app/.seen_urls; do
    if [ -d "$f" ]; then
        rmdir "$f" 2>/dev/null || true
        touch "$f"
    fi
done

REPO_DIR="${REPO_DIR:-/app/repo}"

# First run: clone. Subsequent runs: fetch & reset to origin.
if [ ! -d "$REPO_DIR/.git" ]; then
    echo "[entrypoint] Cloning repository..."
    git clone --single-branch --branch main "${GIT_REPO_URL}" "$REPO_DIR"
else
    echo "[entrypoint] Pulling latest..."
    git -C "$REPO_DIR" fetch origin
    git -C "$REPO_DIR" reset --hard origin/main
fi

exec "$@"
