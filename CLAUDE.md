@AGENTS.md

## Claude Code notes

- On Windows, the Bash tool may not have `ninja` on `PATH`. Find it with
  `where ninja` in PowerShell and prepend its directory before running
  `tools/check.py` or `cmake`.
- Run tools through the venv (`.venv/Scripts/python tools/...`), not the system Python.
- Personal, machine-specific notes go in `CLAUDE.local.md` (gitignored), not here.
