#!/usr/bin/env python3
"""Say which tests a CI run needs, from the paths a pull request changes.

    python tools/ci_changes.py --base HEAD^1            # PR merge commit vs. its base: prints all|data|none
    python tools/ci_changes.py --all                    # push / manual runs: always all
    git diff --name-only A B | python tools/ci_changes.py --stdin

The required checks on master are exact job names, so CI can't leave a job
out with a workflow-level `paths:` filter (the check would stay pending).
The test jobs run this instead, and skip steps:

- `all`: a path the test suite depends on changed: tools/, tests/, the
  Python and CMake configuration, the workflows, or a file a test reads
  (docs/agents/worker.md, cmake/, CMakeLists.txt, ...): see TOOLING. The
  whole suite runs.
- `data`: no such path, but data/ changed (a batch of matched units). Only
  the tests that read the repository's data files run (DATA_TESTS);
  `tools/lint.py` checks them in the lint job anyway.
- `none`: only sources (src/, lib/, include/), docs or similar changed.
  Nothing the tests read changed, so the job passes without installing
  anything; the Build jobs compile those sources.

With `$GITHUB_OUTPUT` set, it also writes `tests=<kind>` there.
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
from pathlib import PurePosixPath

TOOLING_DIRS = ("tools/", "tests/", ".github/", "cmake/", "docs/agents/")
TOOLING_FILES = ("pyproject.toml", "ruff.toml", "setup.cfg", "pytest.ini", "conftest.py", "CMakeLists.txt",
                 "CMakePresets.json")
DATA_DIRS = ("data/",)
DATA_TESTS = ("tests/test_common.py", "tests/test_lint.py")


def classify(paths: list[str]) -> str:
    """all, data or none (see the module docstring)."""
    kind = "none"
    for p in paths:
        p = PurePosixPath(p.strip().replace("\\", "/")).as_posix()
        if not p or p == ".":
            continue
        name = p.rsplit("/", 1)[-1]
        if p.startswith(TOOLING_DIRS) or p in TOOLING_FILES or (name.startswith("requirements") and name.endswith(".txt")):
            return "all"
        if p.startswith(DATA_DIRS):
            kind = "data"
    return kind


def changed(base: str, head: str = "HEAD") -> list[str]:
    r = subprocess.run(["git", "diff", "--name-only", base, head], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f"git diff failed:\n{r.stderr}")
    return r.stdout.splitlines()


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--base", help="compare HEAD (or --head) with this commit")
    g.add_argument("--stdin", action="store_true", help="read the changed paths from stdin")
    g.add_argument("--all", action="store_true", help="not a pull request: run everything")
    ap.add_argument("--head", default="HEAD")
    args = ap.parse_args(argv)
    if args.all:
        kind = "all"
    else:
        paths = sys.stdin.read().splitlines() if args.stdin else changed(args.base, args.head)
        kind = classify(paths)
    print(kind)
    out = os.environ.get("GITHUB_OUTPUT")
    if out:
        with open(out, "a", encoding="utf-8") as f:
            f.write(f"tests={kind}\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
