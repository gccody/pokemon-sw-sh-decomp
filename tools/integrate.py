#!/usr/bin/env python3
"""Put a finished unit on top of the stack: replay its commits, apply its
sidecar, check, and commit the data/ changes.

    python tools/integrate.py swarm-unit/u7c3a40 --new-branch swarm/002-u7c3a40
    python tools/integrate.py swarm-unit/u7c3a40 --sidecar ../w1/.swarm/sidecar.json

Run it in the stack's worktree, with the stack tip checked out and no
uncommitted changes to tracked files. Steps:

1. `--new-branch`: start that branch at the current HEAD (the stack tip).
2. Replay the unit branch's own commits with `git cherry-pick`: those after
   the commit the worktree was created from (`--base`, else the sidecar's
   `base`, which `worktree_setup.py create` records), or else those not on
   HEAD, leaving out any whose patch HEAD already has (a stack rebased since
   the unit started has its commits under other hashes). A commit that touches data/functions.csv or a path that
   must never be committed (FORBIDDEN) stops everything: units don't edit
   functions.csv, the sidecar carries what belongs there.
3. Apply the sidecar (the unit worktree's `.swarm/sidecar.json` unless
   `--sidecar` names one): names through `tools/funcs.py name --from-file`,
   then m/M statuses through `tools/funcs.py status`, for functions that are
   still U.
4. `tools/check.py --update --record-data` (it builds both games), so every
   status comes from check.py. A function that was O and isn't any more
   (REGRESSION or STALE) stops before anything is committed.
5. `tools/lint.py`, `python -m pytest -q`, `ruff check .` and
   `clang-format --dry-run --Werror` on the unit's C/C++ files under src/.
6. Commit data/functions.csv and data/data_symbols.csv with a message that
   says what matched.

It prints a summary (functions and bytes matched, m/M, skipped) and writes it
with the unit's check.py lines and the sidecar's report to
`.swarm/integrate-<unit>.md` for the PR. On a failure after step 2, the
replayed commits stay so they can be fixed; `git reset --hard ORIG` (printed)
goes back.
"""
from __future__ import annotations

import argparse
import json
import re
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, Function, read_functions_csv  # noqa: E402

FUNCTIONS_CSV = "data/functions.csv"
DATA_FILES = ("data/functions.csv", "data/data_symbols.csv")
FORBIDDEN = re.compile(r"(^|/)(data/original|assets/Pokemon [^/]*|build|\.cache|\.swarm|toolchain|\.venv)(/|$)"
                       r"|\.(xci|nsp|nca|nso|nro|elf|keys)$|\.pb\.(cc|h)$")
FORMATTED = (".c", ".cc", ".cpp", ".h", ".hpp", ".inl")


def git(*args: str, check: bool = True) -> str:
    r = subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True)
    if check and r.returncode:
        raise SystemExit(f"git {' '.join(args)} failed:\n{r.stdout}{r.stderr}")
    return r.stdout.strip()


# --------------------------------------------------------------------------- pure parts (tested)
def bad_paths(paths: list[str]) -> list[str]:
    """Paths a unit's commits must not touch."""
    return [p for p in paths if p == FUNCTIONS_CSV or FORBIDDEN.search(p)]


@dataclass
class Summary:
    matched: list[Function] = field(default_factory=list)
    nonmatching: list[Function] = field(default_factory=list)
    skipped: list[Function] = field(default_factory=list)
    regressions: list[Function] = field(default_factory=list)
    other: list[tuple[Function, str]] = field(default_factory=list)  # status changes outside the unit
    named: int = 0

    @property
    def matched_bytes(self) -> int:
        return sum(f.sword_size or f.shield_size or 0 for f in self.matched)

    def text(self) -> str:
        lines = [f"matched {len(self.matched)} ({self.matched_bytes} bytes), "
                 f"m/M {len(self.nonmatching)}, skipped {len(self.skipped)}, named {self.named}"]
        if self.regressions:
            lines.append(f"REGRESSIONS: {len(self.regressions)}")
        if self.other:
            lines.append(f"status changes outside the unit: {len(self.other)}")
        return "; ".join(lines)


def summarize(before: list[Function], after: list[Function], unit_keys: set[str]) -> Summary:
    """Compare functions.csv before and after integrating: what the unit's
    functions became, and every other status change."""
    old = {f.key: f for f in before}
    s = Summary()
    for f in after:
        o = old.get(f.key)
        if o is None:
            continue
        if f.name and f.name != o.name:
            s.named += 1
        if o.status == "O" and f.status != "O":
            s.regressions.append(f)
        if f.key in unit_keys:
            if f.status == "O" and o.status != "O":
                s.matched.append(f)
            elif f.status in ("m", "M") and o.status not in ("m", "M", "O"):
                s.nonmatching.append(f)
            elif f.status == "U":
                s.skipped.append(f)
        elif f.status != o.status and o.status != "O":
            s.other.append((f, f"{o.status}->{f.status}"))
    return s


def names_csv(names: list[dict], rows: list[Function]) -> str:
    """The sidecar's names as a `Name,Sword,Shield` file for funcs.py name --from-file."""
    by_sword = {f"0x{r.sword + BASE:x}": r for r in rows if r.sword is not None}
    out = ["Name,Sword,Shield"]
    for n in names:
        r = by_sword.get(n["addr"].lower())
        if r is None:
            raise SystemExit(f"sidecar names {n['addr']}, which isn't a Sword function start")
        sh = f"0x{r.shield + BASE:x}" if r.shield is not None else ""
        out.append(f"{n['name']},0x{r.sword + BASE:x},{sh}")
    return "\n".join(out) + "\n"


def check_lines(log: str, funcs: list[Function]) -> list[str]:
    """check.py's result lines, with their detail lines, for the given functions
    (found by the `[sword:0x..., shield:0x...]` addresses it prints)."""
    tags = {f"sword:0x{f.sword + BASE:x}" for f in funcs if f.sword is not None}
    out, keep = [], False
    for line in log.splitlines():
        if line.startswith(("OK ", "BAD")):
            m = re.search(r"\[([^\]]*)\]\s*$", line)
            keep = m is not None and any(t.strip() in tags for t in m.group(1).split(","))
            if keep:
                out.append(line)
        elif keep and line.startswith("      "):
            out.append(line)
        else:
            keep = False
    return out


# --------------------------------------------------------------------------- steps
def run(argv: list[str], log: Path | None = None) -> tuple[int, str]:
    print(f"$ {' '.join(argv)}", flush=True)
    r = subprocess.run(argv, cwd=ROOT, capture_output=True, text=True)
    out = r.stdout + r.stderr
    if log:
        log.write_text(out, encoding="utf-8")
    return r.returncode, out


def worktree_of(branch: str) -> Path | None:
    cur = None
    for line in git("worktree", "list", "--porcelain").splitlines():
        if line.startswith("worktree "):
            cur = Path(line[9:])
        elif line == f"branch refs/heads/{branch}" and cur is not None:
            return cur
    return None


def clang_format_exe() -> str | None:
    return shutil.which("clang-format") or next(
        (str(p) for p in (ROOT / ".venv" / "bin" / "clang-format", ROOT / ".venv" / "Scripts" / "clang-format.exe")
         if p.exists()), None)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("branch", help="the unit's branch")
    ap.add_argument("--new-branch", help="create this stack branch at HEAD first")
    ap.add_argument("--sidecar", type=Path, help="the unit's sidecar (default: its worktree's .swarm/sidecar.json)")
    ap.add_argument("--base", help="the commit the unit branch started from (default: the sidecar's base)")
    ap.add_argument("--skip-tests", action="store_true", help="skip lint/pytest/ruff/clang-format (not for PRs)")
    args = ap.parse_args(argv)

    if git("status", "--porcelain", "--untracked-files=no"):
        raise SystemExit("the stack worktree has uncommitted changes to tracked files")
    py = sys.executable
    orig = git("rev-parse", "HEAD")
    sidecar_path = args.sidecar
    if sidecar_path is None:
        wt = worktree_of(args.branch)
        if wt is None:
            raise SystemExit(f"no worktree has {args.branch} checked out: pass --sidecar")
        sidecar_path = wt / ".swarm" / "sidecar.json"
    sidecar = json.loads(sidecar_path.read_text(encoding="utf-8")) if sidecar_path.exists() else {}
    unit = sidecar.get("unit") or args.branch.rsplit("/", 1)[-1]

    # 2. the unit's commits
    base = args.base or sidecar.get("base")
    if base:
        commits = git("rev-list", "--reverse", "--no-merges", f"{base}..{args.branch}").split()
    else:
        commits = git("rev-list", "--reverse", "--no-merges", "--cherry-pick", "--right-only",
                      f"HEAD...{args.branch}").split()
    touched = []
    for c in commits:
        touched += git("diff-tree", "--no-commit-id", "--name-only", "-r", c).splitlines()
    bad = bad_paths(sorted(set(touched)))
    if bad:
        raise SystemExit(f"{args.branch} commits paths a unit mustn't: {', '.join(bad)}")
    if args.new_branch:
        git("switch", "-c", args.new_branch)
    if commits:
        r = subprocess.run(["git", "cherry-pick", "--allow-empty", *commits], cwd=ROOT, capture_output=True,
                           text=True)
        if r.returncode:
            subprocess.run(["git", "cherry-pick", "--abort"], cwd=ROOT)
            raise SystemExit(f"cherry-pick of {args.branch} failed (aborted):\n{r.stdout}{r.stderr}")
    print(f"replayed {len(commits)} commits of {args.branch}")

    # 3. the sidecar
    import units as U

    before = read_functions_csv()
    if sidecar.get("names"):
        with tempfile.NamedTemporaryFile("w", suffix=".csv", delete=False, encoding="utf-8") as tf:
            tf.write(names_csv(sidecar["names"], before))
        code, out = run([py, "tools/funcs.py", "name", "--from-file", tf.name])
        Path(tf.name).unlink()
        if code:
            raise SystemExit(f"funcs.py name failed:\n{out}\n(back: git reset --hard {orig})")
    rows_now = {f"0x{r.sword + BASE:x}": r for r in read_functions_csv() if r.sword is not None}
    for s in sidecar.get("statuses", []):
        r = rows_now.get(s["addr"].lower())
        if r is not None and r.status == "U":
            code, out = run([py, "tools/funcs.py", "status", s["addr"], s["status"]])
            if code:
                raise SystemExit(f"funcs.py status failed:\n{out}")

    # 4. check
    swarm = ROOT / ".swarm"
    swarm.mkdir(exist_ok=True)
    log = swarm / f"check-{unit}.log"
    _, out = run([py, "tools/check.py", "--update", "--record-data"], log)
    tail = [ln for ln in out.splitlines()[-12:] if ln.strip()]
    if "matching," not in out:
        raise SystemExit(f"check.py didn't finish (see {log}):\n" + "\n".join(tail)
                         + f"\n(back: git reset --hard {orig})")
    after = read_functions_csv()
    try:
        units, _ = U.load_units("UmMO")
        the_unit = U.find_unit(units, unit)
        keys = {f.key for f in the_unit.funcs}
    except SystemExit:
        keys = set()
    summary = summarize(before, after, keys)
    if summary.regressions:
        raise SystemExit("regressions (O before, not now): "
                         + ", ".join(f.display_name for f in summary.regressions[:10])
                         + f"\nsee {log}; nothing committed (back: git reset --hard {orig})")

    # 5. tests
    if not args.skip_tests:
        changed = git("diff", "--name-only", f"{orig}..HEAD").splitlines()
        fmt = [p for p in changed if p.startswith("src/") and p.endswith(FORMATTED) and (ROOT / p).exists()]
        steps = [[py, "tools/lint.py"], [py, "-m", "pytest", "-q", "-x"], [py, "-m", "ruff", "check", "."]]
        cf = clang_format_exe()
        if fmt and cf:
            steps.append([cf, "--dry-run", "--Werror", *fmt])
        elif fmt:
            print("warning: clang-format not found; formatting not checked")
        for st in steps:
            code, o = run(st)
            if code:
                raise SystemExit(f"{' '.join(st[:3])} failed:\n{o[-3000:]}\n(back: git reset --hard {orig})")

    # 6. commit
    git("add", *DATA_FILES)
    lines = check_lines(out, summary.matched + summary.nonmatching + summary.skipped)
    if git("diff", "--cached", "--name-only"):
        subject = (f"data: unit {unit}: {len(summary.matched)} functions match"
                   + (f", {len(summary.nonmatching)} m/M" if summary.nonmatching else ""))
        body = [summary.text(), "", "Statuses from tools/check.py --update; names from the unit's sidecar."]
        msg = subject + "\n\n" + "\n".join(body) + "\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\n"
        subprocess.run(["git", "commit", "-q", "-F", "-"], cwd=ROOT, input=msg, text=True, check=True)
    totals = next((ln for ln in reversed(out.splitlines()) if re.match(r"\d+ matching, \d+ not matching", ln)), "")
    report = [f"## Unit {unit}", "", summary.text(), "", f"check.py (both games): {totals}", "", "```",
              *lines, "```", ""]
    for f in summary.nonmatching:
        reason = next((s["reason"] for s in sidecar.get("statuses", []) if int(s["addr"], 16) - BASE == f.sword), "")
        report.append(f"- {f.status} 0x{f.sword + BASE:x} {f.name}: {reason}")
    if sidecar.get("report"):
        report += ["", "Worker report:", "", sidecar["report"]]
    (swarm / f"integrate-{unit}.md").write_text("\n".join(report) + "\n", encoding="utf-8")
    print("\n" + summary.text())
    print(f"check.py: {totals}")
    print(f"summary for the PR: {(swarm / f'integrate-{unit}.md').relative_to(ROOT).as_posix()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
