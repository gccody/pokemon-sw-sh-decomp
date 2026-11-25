#!/usr/bin/env python3
"""Make a git worktree of this repository ready to build and check.

    python tools/worktree_setup.py                     # set up the checkout this script is in
    python tools/worktree_setup.py --jobs 4            # ... with ninja running 4 compiles at once
    python tools/worktree_setup.py create ../w1 --branch swarm-unit/u7c3a40 --unit u7c3a40 [--base HEAD]
    python tools/worktree_setup.py teardown ../w1      # remove the worktree, its build dir and its branch link
    python tools/worktree_setup.py reuse ../w1 --branch swarm-unit/u7c3b00 --unit u7c3b00   # next unit, same build dir

Setting up (safe to run again):

1. Links the main checkout's `.venv`, `toolchain`, `data/original` and
   `.cache/ghidra` into this one (symlinks; directory junctions on Windows),
   and makes sure git ignores them: `.git/info/exclude` (shared by every
   worktree) gets `/.venv`, `/toolchain`, `/data/original` and `/.swarm`;
   `.cache/` is a real directory here, which `.gitignore` already covers.
2. Runs `tools/get_physx.py` and `tools/protos.py generate`, which write files
   git never tracks.
3. Configures `build/sword` and `build/shield` with a ninja job pool of
   `--jobs` compiles (default: CPU cores / `--workers`, at least 1), so
   several worktrees building at once don't overload the machine, and with
   ccache as the compiler launcher if it's on PATH. The codegen flags aren't
   touched.
4. With `--unit`, starts the unit's sidecar (`.swarm/sidecar.json`, see
   tools/units.py) if there's none yet, with the commit the worktree started
   from as `base` (tools/integrate.py replays the commits after it).

`reuse` gives a finished worker's worktree the next unit: it drops the
local data/functions.csv and data/data_symbols.csv changes, starts the new
branch at this checkout's HEAD (the stack tip; `--base` for another), keeps
the old sidecar as `.swarm/sidecar-<old unit>.json` and starts a new one.
The build dirs stay, so the next build only recompiles what changed.

`teardown` and `reuse` refuse the main checkout, and a worktree with changes to tracked
files other than data/functions.csv and data/data_symbols.csv (which a worker
changes but never commits) unless `--force` is given.
"""
from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LINKS = (".venv", "toolchain", "data/original", ".cache/ghidra")
EXCLUDES = ("/.venv", "/toolchain", "/data/original", "/.swarm")
LOCAL_CHANGES = ("data/functions.csv", "data/data_symbols.csv")
GAMES = ("sword", "shield")


def git(*args: str, cwd: Path = ROOT, check: bool = True) -> str:
    return subprocess.run(["git", *args], cwd=cwd, check=check, capture_output=True, text=True).stdout.rstrip()


# --------------------------------------------------------------------------- pure parts (tested)
def default_jobs(cpus: int | None, workers: int) -> int:
    return max(1, (cpus or 1) // max(1, workers))


def missing_excludes(text: str, wanted=EXCLUDES) -> list[str]:
    have = {line.strip() for line in text.splitlines()}
    return [w for w in wanted if w not in have]


def add_excludes(path: Path, wanted=EXCLUDES) -> list[str]:
    text = path.read_text(encoding="utf-8") if path.exists() else ""
    add = missing_excludes(text, wanted)
    if add:
        path.parent.mkdir(parents=True, exist_ok=True)
        with open(path, "a", encoding="utf-8", newline="\n") as f:
            if text and not text.endswith("\n"):
                f.write("\n")
            f.write("# tools/worktree_setup.py: links to the main checkout, the unit sidecar\n")
            f.write("".join(w + "\n" for w in add))
    return add


def link_dir(link: Path, target: Path) -> str:
    """Make `link` point at directory `target`. Returns what was done. An
    existing link to the same target is kept; anything else there is left
    alone and reported."""
    if link.is_symlink() or (os.name == "nt" and link.exists() and _is_junction(link)):
        if Path(os.path.realpath(link)) == Path(os.path.realpath(target)):
            return "ok"
        return f"points elsewhere ({os.path.realpath(link)}), left as it is"
    if link.exists():
        return "exists (not a link), left as it is"
    if not target.exists():
        return f"skipped: {target} doesn't exist"
    link.parent.mkdir(parents=True, exist_ok=True)
    if os.name == "nt":
        import _winapi
        _winapi.CreateJunction(str(target), str(link))
    else:
        link.symlink_to(target, target_is_directory=True)
    return "linked"


def _is_junction(p: Path) -> bool:
    try:
        return bool(getattr(os.path, "isjunction", lambda _: False)(p))
    except OSError:
        return False


def cmake_args(game: str, jobs: int, launcher: str | None) -> list[str]:
    args = ["--preset", game, f"-DCMAKE_JOB_POOLS=compile={jobs}", "-DCMAKE_JOB_POOL_COMPILE=compile"]
    if launcher:
        args += [f"-DCMAKE_C_COMPILER_LAUNCHER={launcher}", f"-DCMAKE_CXX_COMPILER_LAUNCHER={launcher}"]
    return args


def unexpected_changes(porcelain: str, allowed=LOCAL_CHANGES) -> list[str]:
    """Tracked files changed in a `git status --porcelain` listing, other than `allowed`."""
    out = []
    for line in porcelain.splitlines():
        if not line or line.startswith("??"):
            continue
        path = line[3:].split(" -> ")[-1].strip('"')
        if path not in allowed:
            out.append(path)
    return out


# --------------------------------------------------------------------------- commands
def main_checkout(root: Path = ROOT) -> Path:
    common = Path(git("rev-parse", "--path-format=absolute", "--git-common-dir", cwd=root))
    return common.parent


def setup(root: Path, jobs: int, unit: str | None, configure: bool = True, base: str | None = None) -> int:
    main = main_checkout(root)
    common = Path(git("rev-parse", "--path-format=absolute", "--git-common-dir", cwd=root))
    added = add_excludes(common / "info" / "exclude")
    if added:
        print(f"info/exclude: added {' '.join(added)}")
    if main.resolve() != root.resolve():
        for rel in LINKS:
            print(f"{rel}: {link_dir(root / rel, main / rel)}")
    else:
        print("this is the main checkout: nothing to link")
    py = sys.executable
    for argv in (["tools/get_physx.py"], ["tools/protos.py", "generate"]):
        print(f"running {' '.join(argv)}")
        r = subprocess.run([py, *argv], cwd=root, capture_output=True, text=True)
        if r.returncode:
            print(r.stdout + r.stderr)
            return r.returncode
    if configure:
        launcher = shutil.which("ccache")
        cmake = shutil.which("cmake") or "cmake"
        for g in GAMES:
            print(f"configuring build/{g} (-j {jobs}{', ccache' if launcher else ''})")
            r = subprocess.run([cmake, *cmake_args(g, jobs, launcher)], cwd=root, capture_output=True, text=True)
            if r.returncode:
                print(r.stdout[-4000:] + r.stderr[-4000:])
                return r.returncode
    if unit:
        sc = root / ".swarm" / "sidecar.json"
        if not sc.exists():
            sc.parent.mkdir(parents=True, exist_ok=True)
            data = {"unit": unit, "base": base or git("rev-parse", "HEAD", cwd=root),
                    "names": [], "statuses": [], "report": ""}
            sc.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
            print(f"started {sc.relative_to(root).as_posix()} for {unit}")
    print(f"ready: {root}")
    return 0


def cmd_create(args) -> int:
    path = Path(args.path).resolve()
    if path.exists():
        print(f"{path} exists: setting it up again")
    else:
        git("worktree", "add", "-b", args.branch, str(path), args.base)
        print(f"created {path} on {args.branch} from {args.base}")
    return setup(path, args.jobs, args.unit, not args.no_configure)


def cmd_teardown(args) -> int:
    path = Path(args.path).resolve()
    if path == main_checkout().resolve():
        raise SystemExit("refusing to tear down the main checkout")
    listed = git("worktree", "list", "--porcelain")
    if f"worktree {path.as_posix()}" not in listed and f"worktree {path}" not in listed:
        raise SystemExit(f"{path} isn't a worktree of this repository")
    changed = unexpected_changes(git("status", "--porcelain", cwd=path))
    if changed and not args.force:
        raise SystemExit(f"{path} has uncommitted changes to {', '.join(changed[:5])}: commit them, or --force")
    for rel in LINKS:  # unlink first, so nothing can follow a link into the main checkout
        p = path / rel
        if p.is_symlink():
            p.unlink()
        elif os.name == "nt" and _is_junction(p):
            os.rmdir(p)
    git("worktree", "remove", "--force", str(path))
    print(f"removed {path}")
    return 0


def archived_sidecar(swarm: Path, unit: str) -> Path:
    """Where `reuse` keeps the finished unit's sidecar (never overwriting one)."""
    p = swarm / f"sidecar-{unit or 'unknown'}.json"
    n = 1
    while p.exists():
        n += 1
        p = swarm / f"sidecar-{unit or 'unknown'}-{n}.json"
    return p


def cmd_reuse(args) -> int:
    path = Path(args.path).resolve()
    if path == main_checkout().resolve():
        raise SystemExit("refusing to reuse the main checkout")
    changed = unexpected_changes(git("status", "--porcelain", cwd=path))
    if changed:
        raise SystemExit(f"{path} has uncommitted changes to {', '.join(changed[:5])}: commit them first")
    base = git("rev-parse", args.base)  # resolved here: the stack tip of the checkout running this
    git("checkout", "--", *LOCAL_CHANGES, cwd=path)
    git("switch", "-q", "-c", args.branch, base, cwd=path)
    swarm = path / ".swarm"
    sc = swarm / "sidecar.json"
    if sc.exists():
        old = json.loads(sc.read_text(encoding="utf-8")).get("unit", "")
        sc.rename(archived_sidecar(swarm, old))
    print(f"{path}: now {args.branch} at {base[:10]}")
    return setup(path, args.jobs, args.unit, not args.no_configure, base)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--jobs", type=int, help="compiles ninja runs at once (default: CPU cores / --workers)")
    ap.add_argument("--workers", type=int, default=int(os.environ.get("PKMN_WORKERS", "6")),
                    help="worktrees expected to build at once (default 6, or $PKMN_WORKERS)")
    ap.add_argument("--unit", help="start this unit's sidecar")
    ap.add_argument("--no-configure", action="store_true", help="skip configuring the build dirs")
    sub = ap.add_subparsers(dest="cmd")
    p = sub.add_parser("create", help="add a worktree and set it up")
    p.add_argument("path")
    p.add_argument("--branch", required=True)
    p.add_argument("--base", default="HEAD", help="commit to start the branch from (default HEAD)")
    p.add_argument("--unit")
    p.add_argument("--jobs", type=int, dest="jobs_sub")
    p = sub.add_parser("reuse", help="give a finished worker's worktree the next unit, keeping its build dirs")
    p.add_argument("path")
    p.add_argument("--branch", required=True)
    p.add_argument("--unit", required=True)
    p.add_argument("--base", default="HEAD", help="commit to start the branch from (default: this checkout's HEAD)")
    p.add_argument("--jobs", type=int, dest="jobs_sub")
    p = sub.add_parser("teardown", help="remove a worktree and its build dir")
    p.add_argument("path")
    p.add_argument("--force", action="store_true")
    args = ap.parse_args(argv)
    if args.cmd in ("create", "reuse") and args.jobs_sub:
        args.jobs = args.jobs_sub
    if args.jobs is None:
        args.jobs = int(os.environ.get("PKMN_JOBS") or default_jobs(os.cpu_count(), args.workers))
    if args.cmd == "create":
        return cmd_create(args)
    if args.cmd == "teardown":
        return cmd_teardown(args)
    if args.cmd == "reuse":
        return cmd_reuse(args)
    if not args.unit:
        sc = ROOT / ".swarm" / "sidecar.json"
        args.unit = None if sc.exists() else os.environ.get("PKMN_UNIT")
    return setup(ROOT, args.jobs, args.unit, not args.no_configure)


if __name__ == "__main__":
    raise SystemExit(main())
