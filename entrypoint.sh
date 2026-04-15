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

# Normalize .git ownership so git can write objects during fetch/pull.
# Safe no-op when permissions are already correct. Errors ignored so the
# bot starts even if we lack chown privileges (e.g., rootless Docker).
if [ -d /app/.git ]; then
    chown -R "$(id -u):$(id -g)" /app/.git 2>/dev/null || true
    chmod -R u+rwX,g+rwX /app/.git 2>/dev/null || true
fi

exec "$@"
