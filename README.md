# leetcode
Daily Problems

## Setup

Requires Python 3.12+ and [uv](https://docs.astral.sh/uv/).

```bash
uv sync
```

Create a `.env` file (see `.env.example`) and add `credential.json` (Google service account) and `session.txt` (LeetCode session cookie).

## Running locally

```bash
uv run python bot.py
```

## Docker deployment

### Build locally

```bash
docker build -t leetcode-bot .
```

### Deploy with Docker Compose

1. Copy these files to your server:
   - `docker-compose.yml`
   - `.env`
   - `credential.json`
   - `session.txt`

2. Initialize the repo on the server (needed for git operations):
   ```bash
   git clone https://github.com/c1uc/leetcode.git && cd leetcode
   ```

3. Start the bot and Watchtower:
   ```bash
   docker compose up -d
   ```

Watchtower automatically pulls new images from GHCR every 5 minutes.

### Releasing a new version

```bash
git tag v1.0.0
git push origin v1.0.0
```

GitHub Actions will run tests, build the Docker image, and push it to `ghcr.io/c1uc/leetcode-bot`. Watchtower on the server will detect the new image and restart the bot automatically.

## CI/CD

- **CI** (`ci.yml`): Runs smoke tests on every push/PR to `main`.
- **Release** (`release.yml`): On tag push (`v*`), runs tests, builds a multi-platform Docker image (amd64 + arm64), and pushes to GHCR.
