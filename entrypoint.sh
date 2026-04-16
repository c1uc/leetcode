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
