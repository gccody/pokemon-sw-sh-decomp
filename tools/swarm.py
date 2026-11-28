#!/usr/bin/env python3
"""Coordinate parallel units: one command per step, batch PRs, metrics.

Run it in the coordinator's batch worktree (a worktree of its own, never the
main checkout other sessions use), with the batch branch checked out:

    python tools/swarm.py init                      # start swarm/batch-1 at origin/master here
    python tools/swarm.py start u7c3a40             # worker worktree ../swarm-w-u7c3a40 + its brief
    python tools/swarm.py brief u7c3a40 --worktree ../swarm-w-u7c3a40   # the brief again
    python tools/swarm.py finish u7c3a40 --next u7c3b00   # integrate, record, reuse the worktree
    python tools/swarm.py finish u7c3b00            # ... or tear it down (no --next)
    python tools/swarm.py status                    # the batch, the open batch PR, the workers
    python tools/swarm.py open                      # push the batch, open its PR, auto-merge it
    python tools/swarm.py sync                      # after the batch PR landed: rebase onto master
    python tools/swarm.py metrics                   # functions/h, units/h, coordinator min/unit, CI runs

`finish` does what the coordinator did by hand in run 1, as one step:

1. `tools/integrate.py swarm-unit/<unit>` onto the batch branch (it keeps
   its checks: name conflicts, regressions, the base, lint/pytest/ruff/
   clang-format). If it fails, the batch branch goes back to where it was
   and the worker's worktree is left as it is, to fix there.
2. The unit's PR section (`.swarm/integrate-<unit>.md`) is kept in the batch
   state, so `open` can write the PR body.
3. The worker's worktree gets the next unit (`--next`, reusing its build
   dirs: worktree_setup.py reuse) and its brief is printed, or it's torn
   down. The unit's branch is deleted (`--keep-branch` keeps it).
4. `sync`, then `open` if the batch is due (`--batch-size` units, default 8,
   or the oldest unit `--batch-minutes` old, default 60) and no batch PR is
   still open.

Batch PRs: units collect on `swarm/batch-<N>`, one commit (group) per unit,
and fix-ups the coordinator commits there ride along. `open` pushes the
batch, opens one PR with every unit's section, and turns on auto-merge for
that PR only (rebase: each commit lands as it is). Only one batch PR is open
at a time: units finished meanwhile go on `swarm/batch-<N+1>`, which starts at
the open PR's head and stays local, so nothing restacks on GitHub. When the
PR lands (with new hashes, since GitHub rebases it), `sync` replays the new
batch's own commits onto origin/master (`git rebase --onto`).

State: `.swarm/batch.json` and `.swarm/metrics.jsonl` in this worktree
(`.swarm/` is untracked; worktree_setup.py excludes it).

The brief is the "## The brief" section of docs/agents/worker.md with
`{UNIT}`, `{WORKTREE}`, `{BRANCH}`, `{MAIN}` (the main checkout), `{PY}` (the
venv's python, relative), `{COAUTHOR}` (`--co-author`, `$PKMN_CO_AUTHOR` or
`git config swarm.coauthor`; empty: the line is dropped) and `{BASE}` filled
in. Nothing here hard-codes a user or session path.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import time
from dataclasses import asdict, dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ROOT  # noqa: E402

STATE = ROOT / ".swarm" / "batch.json"
METRICS = ROOT / ".swarm" / "metrics.jsonl"
WORKER_DOC = ROOT / "docs" / "agents" / "worker.md"
BRANCH_PREFIX = "swarm/batch-"
UNIT_BRANCH = "swarm-unit/"
BATCH_SIZE = 8
BATCH_MINUTES = 60
BODY_LIMIT = 60000  # GitHub's limit is 65,536 characters
PLACEHOLDERS = ("UNIT", "WORKTREE", "BRANCH", "MAIN", "PY", "COAUTHOR", "BASE")


def git(*args: str, cwd: Path | None = None, check: bool = True) -> str:
    r = subprocess.run(["git", *args], cwd=cwd or ROOT, capture_output=True, text=True)
    if check and r.returncode:
        raise SystemExit(f"git {' '.join(args)} failed:\n{r.stdout}{r.stderr}")
    return r.stdout.strip()


def venv_python() -> str:
    return ".venv\\Scripts\\python" if os.name == "nt" else ".venv/bin/python"


# --------------------------------------------------------------------------- state (tested)
@dataclass
class UnitRecord:
    unit: str
    matched: int = 0
    nonmatching: int = 0
    skipped: int = 0
    named: int = 0
    finished: float = 0.0       # time.time() when finish ended
    seconds: float = 0.0        # how long finish took (coordinator time)
    section: str = ""           # the PR section integrate.py wrote
    commits: list[str] = field(default_factory=list)  # subjects of its commits (hashes change on rebase)


@dataclass
class OpenBatch:
    batch: int
    pr: int
    url: str
    head: str
    units: list[str]
    opened: float


@dataclass
class State:
    batch: int = 1
    branch: str = f"{BRANCH_PREFIX}1"
    base: str = ""              # the commit the batch started from (origin/master, or an open PR's head)
    units: list[UnitRecord] = field(default_factory=list)
    open: list[OpenBatch] = field(default_factory=list)

    @staticmethod
    def from_json(d: dict) -> State:
        s = State(d.get("batch", 1), d.get("branch", f"{BRANCH_PREFIX}1"), d.get("base", ""))
        s.units = [UnitRecord(**u) for u in d.get("units", [])]
        s.open = [OpenBatch(**o) for o in d.get("open", [])]
        return s

    def to_json(self) -> str:
        return json.dumps(asdict(self), indent=2) + "\n"


def load_state(path: Path | None = None) -> State:
    path = path or STATE
    if not path.exists():
        raise SystemExit(f"no batch state ({path}): run `swarm.py init` first")
    return State.from_json(json.loads(path.read_text(encoding="utf-8")))


def save_state(s: State, path: Path | None = None) -> None:
    path = path or STATE
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(s.to_json(), encoding="utf-8")


def log_event(event: str, path: Path | None = None, now: float | None = None, **data) -> None:
    path = path or METRICS
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "a", encoding="utf-8", newline="\n") as f:
        f.write(json.dumps({"event": event, "t": round(now if now is not None else time.time(), 1), **data}) + "\n")


def read_events(path: Path | None = None) -> list[dict]:
    path = path or METRICS
    if not path.exists():
        return []
    return [json.loads(ln) for ln in path.read_text(encoding="utf-8").splitlines() if ln.strip()]


def batch_due(s: State, now: float, size: int = BATCH_SIZE, minutes: float = BATCH_MINUTES) -> bool:
    """Whether the batch should become a PR now: enough units, or the oldest
    has waited long enough. Never while another batch PR is open."""
    if s.open or not s.units:
        return False
    return len(s.units) >= size or now - min(u.finished for u in s.units) >= minutes * 60


# --------------------------------------------------------------------------- text (tested)
_SUMMARY = re.compile(r"matched (\d+) \(\d+ bytes\), m/M (\d+), skipped (\d+), named (\d+)")


def parse_section(md: str) -> tuple[int, int, int, int]:
    """matched, m/M, skipped, named from integrate.py's `.swarm/integrate-<unit>.md`."""
    m = _SUMMARY.search(md)
    return tuple(int(g) for g in m.groups()) if m else (0, 0, 0, 0)


def brief_template(doc: str) -> str:
    """The "## The brief" section of docs/agents/worker.md, without its heading."""
    m = re.search(r"^## The brief[^\n]*\n(.*?)(?=^## |\Z)", doc, re.S | re.M)
    if m is None:
        raise SystemExit("docs/agents/worker.md has no \"## The brief\" section")
    return m.group(1).strip("\n") + "\n"


def fill_brief(template: str, values: dict[str, str]) -> str:
    """Fill `{NAME}` placeholders. A line whose placeholder has no value (an
    empty co-author) is dropped. An unknown `{NAME}` is an error, so a
    template typo can't reach a worker."""
    unknown = sorted(set(re.findall(r"\{([A-Z_]+)\}", template)) - set(PLACEHOLDERS))
    if unknown:
        raise SystemExit(f"the brief template has unknown placeholders: {', '.join(unknown)}")
    out = []
    for line in template.splitlines():
        names = re.findall(r"\{([A-Z_]+)\}", line)
        if any(not values.get(n) for n in names):
            continue
        for n in names:
            line = line.replace("{" + n + "}", values[n])
        out.append(line)
    return "\n".join(out) + "\n"


def pr_title(batch: int, units: list[UnitRecord]) -> str:
    matched = sum(u.matched for u in units)
    return f"swarm batch {batch}: {len(units)} units, {matched} functions match"


def pr_body(batch: int, units: list[UnitRecord], extra_commits: list[str], totals: str,
            co_author_note: str = "") -> str:
    """The batch PR's body, in the repository's template."""
    rows = ["| Unit | Matched | m/M | Skipped | Named |", "|---|--:|--:|--:|--:|"]
    for u in units:
        rows.append(f"| `{u.unit}` | {u.matched} | {u.nonmatching} | {u.skipped} | {u.named} |")
    rows.append(f"| **total** | **{sum(u.matched for u in units)}** | {sum(u.nonmatching for u in units)} "
                f"| {sum(u.skipped for u in units)} | {sum(u.named for u in units)} |")
    head = [
        "## What this does", "",
        f"Batch {batch} of the parallel-unit run: {len(units)} units from `tools/units.py`, one commit "
        "group per unit (the worker's source commits, then `tools/integrate.py`'s data commit), so "
        "rebase-merge lands each unit's history as it is.", "", *rows, "",
    ]
    if extra_commits:
        head += ["Other commits in the batch (coordinator fix-ups):", "",
                 *[f"- {c}" for c in extra_commits], ""]
    head += ["## `tools/check.py` output", "",
             "`tools/integrate.py` ran `check.py --update --record-data` (both games) after each unit, on top "
             "of the batch. Whole build after the last unit:", "", "```", totals or "(not recorded)", "```", ""]
    tail = [
        "## Checklist", "",
        "- [x] `python tools/check.py` was run against **both** Sword and Shield, and the statuses in "
        "`data/functions.csv` come from `--update` (not edited by hand)",
        "- [x] Non-matching functions are marked `m`/`M` and have a `// NON_MATCHING: <reason>` comment",
        "- [x] Code follows each function's scope (no `PKMN_*` macros in `common` code)",
        "- [x] Reconstructed structs have `PKMN_SIZE_ASSERT` / `PKMN_OFFSET_ASSERT`",
        "- [x] `python tools/lint.py` and `python -m pytest` pass, and the code is `clang-format`ted",
        "- [x] Nothing extracted from the game is included (binaries, assets, large dumped tables, keys)", "",
        "## AI assistance", "",
        "- [ ] No AI tools were used",
        "- [x] An AI assistant helped (say which, and with what: naming, struct layouts, code, tooling)", "",
        co_author_note or "AI workers wrote the code, one unit each; `tools/integrate.py` checked and recorded "
        "every unit, and check.py decided every status.", "",
    ]
    sections = ["## Units", ""]
    for u in units:
        sections += [u.section.strip().replace("## Unit ", "### Unit ", 1), ""]
    body = "\n".join(head + sections + tail)
    if len(body) > BODY_LIMIT:  # keep the table and checklist; cut the per-unit check lines
        short = ["## Units", "", "(Per-unit check.py lines cut: the body would pass GitHub's limit. They're in "
                 "each unit's data commit message and `.swarm/integrate-<unit>.md`.)", ""]
        body = "\n".join(head + short + tail)
    return body


def extra_commits(log: str, unit_subjects: set[str]) -> list[str]:
    """`git log --format=%h %s` lines that aren't a unit's data commit."""
    out = []
    for line in log.splitlines():
        sha, _, subject = line.partition(" ")
        if subject.startswith("data: unit ") or subject in unit_subjects:
            continue
        out.append(f"{sha} {subject}")
    return out


def metrics(events: list[dict], ci_runs: int | None = None, since: float | None = None) -> dict:
    """Rates over the finished units in the window (from `since`, else the first start)."""
    ev = [e for e in events if since is None or e["t"] >= since]
    fin = [e for e in ev if e["event"] == "finish" and e.get("ok", True)]
    starts = [e["t"] for e in ev if e["event"] in ("start", "finish")]
    if not fin or not starts:
        return {"units": 0}
    hours = max((max(e["t"] for e in fin) - min(starts)) / 3600, 1e-9)
    matched = sum(e.get("matched", 0) for e in fin)
    coord = sum(e.get("seconds", 0) for e in ev if e["event"] in ("finish", "open", "sync"))
    landed = sum(len(e.get("units", [])) for e in ev if e["event"] == "landed")
    out = {"units": len(fin), "hours": round(hours, 2), "functions_matched": matched,
           "functions_per_hour": round(matched / hours, 1), "units_per_hour": round(len(fin) / hours, 1),
           "coordinator_min_per_unit": round(coord / 60 / len(fin), 2), "units_landed": landed,
           "failed_finishes": sum(1 for e in ev if e["event"] == "finish" and not e.get("ok", True))}
    if ci_runs is not None and landed:
        out["ci_runs"] = ci_runs
        out["ci_runs_per_landed_unit"] = round(ci_runs / landed, 2)
    return out


# --------------------------------------------------------------------------- commands
def main_checkout() -> Path:
    return Path(git("rev-parse", "--path-format=absolute", "--git-common-dir")).parent


def co_author(arg: str | None) -> str:
    if arg:
        return arg
    return os.environ.get("PKMN_CO_AUTHOR") or git("config", "--get", "swarm.coauthor", check=False)


def ensure_batch_worktree(s: State | None = None) -> None:
    if ROOT.resolve() == main_checkout().resolve():
        raise SystemExit("run swarm.py in the coordinator's own worktree, not the main checkout")
    if s is not None and git("branch", "--show-current") != s.branch:
        raise SystemExit(f"check out the batch branch {s.branch} here first")


def default_worktree(unit: str) -> Path:
    return main_checkout().parent / f"swarm-w-{unit}"


def brief_for(unit: str, worktree: Path, author: str) -> str:
    template = brief_template(WORKER_DOC.read_text(encoding="utf-8"))
    return fill_brief(template, {
        "UNIT": unit, "WORKTREE": str(worktree), "BRANCH": f"{UNIT_BRANCH}{unit}", "MAIN": str(main_checkout()),
        "PY": venv_python(), "COAUTHOR": author, "BASE": git("rev-parse", "--short", "HEAD"),
    })


def run_tool(argv: list[str], cwd: Path = ROOT) -> tuple[int, str]:
    r = subprocess.run([sys.executable, *argv], cwd=cwd, capture_output=True, text=True)
    return r.returncode, r.stdout + r.stderr


def cmd_init(args) -> int:
    ensure_batch_worktree()
    if STATE.exists() and not args.force:
        raise SystemExit(f"{STATE.relative_to(ROOT).as_posix()} exists (--force starts over)")
    if git("status", "--porcelain", "--untracked-files=no"):
        raise SystemExit("this worktree has uncommitted changes to tracked files")
    git("fetch", "-q", "origin")
    n = args.batch
    branch = f"{BRANCH_PREFIX}{n}"
    git("switch", "-q", "-C", branch, args.base)
    s = State(n, branch, git("rev-parse", "HEAD"))
    save_state(s)
    log_event("init", batch=n)
    print(f"batch {n}: {branch} at {s.base[:10]}")
    return 0


def cmd_brief(args) -> int:
    wt = Path(args.worktree).resolve() if args.worktree else default_worktree(args.unit)
    sys.stdout.write(brief_for(args.unit, wt, co_author(args.co_author)))
    return 0


def worktree_setup(*argv: str) -> None:
    code, out = run_tool([str(ROOT / "tools" / "worktree_setup.py"), *argv])
    print(out.rstrip())
    if code:
        raise SystemExit(f"worktree_setup.py {argv[0]} failed")


def cmd_start(args) -> int:
    s = load_state()
    ensure_batch_worktree(s)
    wt = Path(args.path).resolve() if args.path else default_worktree(args.unit)
    worktree_setup("create", str(wt), "--branch", f"{UNIT_BRANCH}{args.unit}", "--unit", args.unit,
                   "--base", "HEAD", "--workers", str(args.workers))
    log_event("start", unit=args.unit, worktree=str(wt))
    print("\n----- brief -----\n" + brief_for(args.unit, wt, co_author(args.co_author)))
    return 0


def cmd_finish(args) -> int:
    t0 = time.time()
    s = load_state()
    ensure_batch_worktree(s)
    import integrate

    branch = f"{UNIT_BRANCH}{args.unit}"
    wt = integrate.worktree_of(branch)
    before = git("rev-parse", "HEAD")
    argv = [str(ROOT / "tools" / "integrate.py"), branch]
    if args.sidecar:
        argv += ["--sidecar", args.sidecar]
    if args.base:
        argv += ["--base", args.base]
    code, out = run_tool(argv)
    print("\n".join(ln for ln in out.splitlines() if not ln.startswith("warning")))
    section = ROOT / ".swarm" / f"integrate-{args.unit}.md"
    if code or "summary for the PR" not in out or not section.exists():
        subprocess.run(["git", "cherry-pick", "--abort"], cwd=ROOT, capture_output=True)
        git("reset", "-q", "--hard", before)
        log_event("finish", unit=args.unit, ok=False, seconds=round(time.time() - t0, 1))
        raise SystemExit(f"integration of {args.unit} failed: {s.branch} is back at {before[:10]}; "
                         f"fix it in {wt or 'the worker worktree'} and finish again")
    md = section.read_text(encoding="utf-8")
    matched, mm, skipped, named = parse_section(md)
    rec = UnitRecord(args.unit, matched, mm, skipped, named, time.time(), 0.0, md,
                     git("log", "--format=%s", f"{before}..HEAD").splitlines())
    if wt is not None and not args.keep_worktree:
        if args.next:
            worktree_setup("reuse", str(wt), "--branch", f"{UNIT_BRANCH}{args.next}", "--unit", args.next,
                           "--workers", str(args.workers))
        else:
            worktree_setup("teardown", str(wt), "--force")
    if not args.keep_branch and (args.next or wt is None or not args.keep_worktree):
        git("branch", "-D", branch, check=False)
    rec.seconds = round(time.time() - t0, 1)
    s.units.append(rec)
    save_state(s)
    log_event("finish", unit=args.unit, ok=True, matched=matched, nonmatching=mm, skipped=skipped,
              seconds=rec.seconds)
    print(f"\n{args.unit}: matched {matched}, m/M {mm}, skipped {skipped} ({rec.seconds:.0f} s); "
          f"batch {s.batch} now has {len(s.units)} units")
    if args.next and wt is not None:
        log_event("start", unit=args.next, worktree=str(wt))
        print("\n----- brief -----\n" + brief_for(args.next, wt, co_author(args.co_author)))
    if not args.no_auto:
        do_sync(s)
        if batch_due(s, time.time(), args.batch_size, args.batch_minutes):
            do_open(s, dry_run=False)
    return 0


def gh(*args: str, check: bool = True) -> str:
    r = subprocess.run(["gh", *args], cwd=ROOT, capture_output=True, text=True)
    if check and r.returncode:
        raise SystemExit(f"gh {' '.join(args)} failed:\n{r.stdout}{r.stderr}")
    return r.stdout.strip()


def last_totals() -> str:
    logs = sorted((ROOT / ".swarm").glob("check-*.log"), key=lambda p: p.stat().st_mtime)
    for p in reversed(logs):
        for ln in reversed(p.read_text(encoding="utf-8", errors="replace").splitlines()):
            if re.match(r"\d+ matching, \d+ not matching", ln):
                return ln
    return ""


def do_open(s: State, dry_run: bool, title: str | None = None) -> int:
    t0 = time.time()
    if not s.units:
        print("nothing to open: the batch has no units")
        return 0
    if s.open:
        print(f"batch PR #{s.open[0].pr} is still open: run `swarm.py sync` once it lands")
        return 0
    log = git("log", "--format=%h %s", f"{s.base}..HEAD")
    mine = {c for u in s.units for c in u.commits}
    body = pr_body(s.batch, s.units, extra_commits(log, mine), last_totals())
    t = title or pr_title(s.batch, s.units)
    body_file = ROOT / ".swarm" / f"pr-batch-{s.batch}.md"
    body_file.write_text(body, encoding="utf-8")
    if dry_run:
        print(f"{t}\n(body: {body_file.relative_to(ROOT).as_posix()})")
        return 0
    git("push", "-q", "--force-with-lease", "-u", "origin", s.branch)
    url = gh("pr", "create", "--base", "master", "--head", s.branch, "--title", t, "--body-file", str(body_file))
    url = url.splitlines()[-1].strip()
    pr = int(url.rstrip("/").rsplit("/", 1)[-1])
    gh("pr", "merge", str(pr), "--rebase", "--auto")
    head = git("rev-parse", "HEAD")
    s.open.append(OpenBatch(s.batch, pr, url, head, [u.unit for u in s.units], time.time()))
    print(f"opened {url} ({len(s.units)} units, auto-merge on)")
    s.batch += 1
    s.branch = f"{BRANCH_PREFIX}{s.batch}"
    s.base = head
    s.units = []
    git("switch", "-q", "-c", s.branch)
    save_state(s)
    log_event("open", batch=s.batch - 1, pr=pr, units=s.open[-1].units, seconds=round(time.time() - t0, 1))
    print(f"now on {s.branch}")
    return 0


def do_sync(s: State) -> int:
    """Rebase the batch onto origin/master once its predecessor's PR has landed."""
    t0 = time.time()
    if not s.open:
        return 0
    ob = s.open[0]
    info = json.loads(gh("pr", "view", str(ob.pr), "--json", "state,mergeStateStatus"))
    if info["state"] == "OPEN":
        print(f"batch PR #{ob.pr}: open ({info.get('mergeStateStatus', '?')})")
        return 0
    if info["state"] != "MERGED":
        raise SystemExit(f"batch PR #{ob.pr} was closed without merging: reopen it or drop it from "
                         f"{STATE.relative_to(ROOT).as_posix()}")
    git("fetch", "-q", "origin")
    if git("status", "--porcelain", "--untracked-files=no"):
        raise SystemExit("uncommitted changes to tracked files: commit them before syncing")
    r = subprocess.run(["git", "rebase", "-q", "--onto", "origin/master", ob.head, s.branch], cwd=ROOT,
                       capture_output=True, text=True)
    if r.returncode:
        subprocess.run(["git", "rebase", "--abort"], cwd=ROOT, capture_output=True)
        raise SystemExit(f"rebasing {s.branch} onto origin/master failed (aborted):\n{r.stdout}{r.stderr}\n"
                         "If data/functions.csv conflicts, re-run the unit's integration on the new base.")
    s.base = git("rev-parse", "origin/master")
    s.open.pop(0)
    save_state(s)
    log_event("landed", batch=ob.batch, pr=ob.pr, units=ob.units)
    log_event("sync", seconds=round(time.time() - t0, 1))
    print(f"batch PR #{ob.pr} landed; {s.branch} rebased onto origin/master ({s.base[:10]})")
    return 0


def cmd_open(args) -> int:
    s = load_state()
    ensure_batch_worktree(s)
    if not args.dry_run:
        do_sync(s)
    return do_open(s, args.dry_run, args.title)


def cmd_sync(args) -> int:
    s = load_state()
    ensure_batch_worktree(s)
    return do_sync(s)


def cmd_status(args) -> int:
    s = load_state()
    print(f"batch {s.batch} on {s.branch} (base {s.base[:10]}): {len(s.units)} units, "
          f"{sum(u.matched for u in s.units)} matched")
    for u in s.units:
        print(f"  {u.unit:12} matched {u.matched:3}  m/M {u.nonmatching:2}  skipped {u.skipped:2}  "
              f"({u.seconds:.0f} s)")
    for ob in s.open:
        print(f"open batch {ob.batch}: {ob.url} ({len(ob.units)} units)")
    workers = [ln[len("branch refs/heads/" + UNIT_BRANCH):] for ln in git("worktree", "list", "--porcelain")
               .splitlines() if ln.startswith("branch refs/heads/" + UNIT_BRANCH)]
    print(f"workers: {' '.join(workers) or 'none'}")
    return 0


def cmd_metrics(args) -> int:
    events = read_events()
    since = None
    if args.since:
        since = time.mktime(time.strptime(args.since, "%Y-%m-%dT%H:%M"))
    ci = None
    if not args.no_ci:
        out = gh("run", "list", "--workflow", "ci.yml", "--limit", "500", "--json", "headBranch,event", check=False)
        if out:
            ci = sum(1 for r in json.loads(out) if r["headBranch"].startswith(BRANCH_PREFIX))
    print(json.dumps(metrics(events, ci, since), indent=2))
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("init", help="start a batch branch here")
    p.add_argument("--base", default="origin/master")
    p.add_argument("--batch", type=int, default=1, help="the batch number to start at")
    p.add_argument("--force", action="store_true")
    for name in ("brief", "start"):
        p = sub.add_parser(name, help="print a worker's brief" if name == "brief" else
                           "make a worker worktree for a unit and print its brief")
        p.add_argument("unit")
        if name == "brief":
            p.add_argument("--worktree", help="the worker's worktree (default: ../swarm-w-<unit>)")
        else:
            p.add_argument("--path", help="the worktree to create (default: ../swarm-w-<unit>)")
            p.add_argument("--workers", type=int, default=6)
        p.add_argument("--co-author", help="the Co-Authored-By line workers end commits with")
    p = sub.add_parser("finish", help="integrate a finished unit and reuse or tear down its worktree")
    p.add_argument("unit")
    p.add_argument("--next", help="give the worker's worktree this unit next")
    p.add_argument("--sidecar", help="the unit's sidecar (default: its worktree's)")
    p.add_argument("--base", help="the commit the unit branch started from (default: the sidecar's)")
    p.add_argument("--keep-worktree", action="store_true")
    p.add_argument("--keep-branch", action="store_true")
    p.add_argument("--no-auto", action="store_true", help="don't sync or open the batch PR afterwards")
    p.add_argument("--batch-size", type=int, default=BATCH_SIZE)
    p.add_argument("--batch-minutes", type=float, default=BATCH_MINUTES)
    p.add_argument("--workers", type=int, default=6)
    p.add_argument("--co-author")
    p = sub.add_parser("open", help="push the batch and open its PR with auto-merge")
    p.add_argument("--title")
    p.add_argument("--dry-run", action="store_true", help="write the body, push nothing")
    sub.add_parser("sync", help="rebase the batch onto origin/master after the open batch PR landed")
    sub.add_parser("status", help="the batch, its PR and the workers")
    p = sub.add_parser("metrics", help="rates from .swarm/metrics.jsonl (and CI runs from gh)")
    p.add_argument("--since", help="only events from this local time on (YYYY-MM-DDTHH:MM)")
    p.add_argument("--no-ci", action="store_true")
    args = ap.parse_args(argv)
    return {"init": cmd_init, "brief": cmd_brief, "start": cmd_start, "finish": cmd_finish, "open": cmd_open,
            "sync": cmd_sync, "status": cmd_status, "metrics": cmd_metrics}[args.cmd](args)


if __name__ == "__main__":
    raise SystemExit(main())
