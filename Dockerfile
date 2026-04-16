FROM python:3.12-slim AS builder
COPY --from=ghcr.io/astral-sh/uv:latest /uv /uvx /bin/
WORKDIR /app
COPY pyproject.toml uv.lock ./
RUN uv sync --frozen --no-dev

FROM python:3.12-slim
ARG BOT_VERSION=dev
ENV BOT_VERSION=${BOT_VERSION}
RUN apt-get update && apt-get install -y --no-install-recommends git && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY --from=builder /app/.venv /app/.venv
COPY bot.py sync_daily.py sync_submissions.py fetch_submissions.py export.py ./
COPY entrypoint.sh ./
ENV PATH="/app/.venv/bin:$PATH"
HEALTHCHECK --interval=60s --timeout=10s --retries=3 CMD python -c "import os; os.kill(1, 0)" || exit 1
ENTRYPOINT ["/app/entrypoint.sh"]
CMD ["python", "bot.py"]
