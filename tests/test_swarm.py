"""tools/swarm.py: batch state, the brief template, the PR body and metrics (no game files)."""
from __future__ import annotations

import json
from pathlib import Path

import pytest

import swarm

ROOT = Path(__file__).resolve().parent.parent

SECTION = """## Unit u7c3a40

matched 9 (412 bytes), m/M 2, skipped 1, named 3

check.py (both games): 60000 matching, 700 not matching

```
OK  common      f()  [sword:0x7100000010, shield:0x7100000010]
```
"""


def rec(unit: str, matched: int = 1, finished: float = 0.0, **kw) -> swarm.UnitRecord:
    return swarm.UnitRecord(unit, matched, finished=finished, section=f"## Unit {unit}\n\nmatched {matched}", **kw)


def test_state_round_trip(tmp_path):
    s = swarm.State(3, "swarm/batch-3", "abc", [rec("u10", 4, 5.0)],
                    [swarm.OpenBatch(2, 501, "https://x/pull/501", "def", ["u1", "u2"], 1.0)])
    p = tmp_path / ".swarm" / "batch.json"
    swarm.save_state(s, p)
    assert swarm.load_state(p) == s


def test_load_state_missing(tmp_path, monkeypatch):
    monkeypatch.setattr(swarm, "ROOT", tmp_path)
    with pytest.raises(SystemExit, match="swarm.py init"):
        swarm.load_state(tmp_path / ".swarm" / "batch.json")


def test_parse_section():
    assert swarm.parse_section(SECTION) == (9, 2, 1, 3)
    assert swarm.parse_section("nothing") == (0, 0, 0, 0)


def test_batch_due():
    now = 10_000.0
    s = swarm.State(units=[rec(f"u{i}", finished=now - 60) for i in range(3)])
    assert not swarm.batch_due(s, now, size=8, minutes=60)
    assert swarm.batch_due(s, now, size=3, minutes=60)
    s.units[0].finished = now - 3601
    assert swarm.batch_due(s, now, size=8, minutes=60)
    s.open.append(swarm.OpenBatch(1, 1, "", "", [], 0))
    assert not swarm.batch_due(s, now, size=1, minutes=0)   # one batch PR at a time
    assert not swarm.batch_due(swarm.State(), now, size=0, minutes=0)


def test_brief_template_from_the_doc():
    """The real docs/agents/worker.md has the section and only known placeholders."""
    t = swarm.brief_template((ROOT / "docs" / "agents" / "worker.md").read_text(encoding="utf-8"))
    vals = {k: f"<{k}>" for k in swarm.PLACEHOLDERS}
    out = swarm.fill_brief(t, vals)
    assert "<UNIT>" in out and "<WORKTREE>" in out and "<COAUTHOR>" in out
    assert "{" + "UNIT}" not in out
    assert "subagents" in out   # every brief says not to start subagents or forks
    assert "## How the coordinator" not in out


def test_fill_brief():
    t = "unit {UNIT} in {WORKTREE}\nsign with {COAUTHOR}\ndirs src/unsorted/{leaf,virtual}\n"
    out = swarm.fill_brief(t, {"UNIT": "u1", "WORKTREE": "/w", "COAUTHOR": ""})
    assert out == "unit u1 in /w\ndirs src/unsorted/{leaf,virtual}\n"   # the empty co-author line is dropped
    with pytest.raises(SystemExit, match="NOPE"):
        swarm.fill_brief("{NOPE}", {})


def test_brief_template_missing():
    with pytest.raises(SystemExit):
        swarm.brief_template("# nothing here\n")
    assert swarm.brief_template("## The brief\n\nhello\n\n## Next\nno\n") == "hello\n"


def test_pr_body():
    units = [swarm.UnitRecord("u1", 9, 2, 1, 3, section=SECTION), swarm.UnitRecord("u2", 4, section="## Unit u2\n")]
    body = swarm.pr_body(5, units, ["abc123 renames: fix u8 parameters"], "60000 matching, 700 not matching")
    assert "Batch 5" in body and "| `u1` | 9 | 2 | 1 | 3 |" in body and "| **total** | **13** |" in body
    assert "### Unit u7c3a40" in body and "abc123 renames" in body and "60000 matching" in body
    assert "- [x] An AI assistant helped" in body and "## Checklist" in body
    assert swarm.pr_title(5, units) == "swarm batch 5: 2 units, 13 functions match"


def test_pr_body_limit():
    big = swarm.UnitRecord("u1", 1, section="## Unit u1\n" + "x" * (swarm.BODY_LIMIT + 10))
    body = swarm.pr_body(1, [big], [], "")
    assert len(body) < swarm.BODY_LIMIT and "| `u1` |" in body and "## AI assistance" in body


def test_extra_commits():
    log = "a1 data: unit u1: 3 functions match\nb2 pokecamp: Unk_1's members\nc3 renames: u8 params\n"
    assert swarm.extra_commits(log, {"pokecamp: Unk_1's members"}) == ["c3 renames: u8 params"]


def test_metrics():
    ev = [{"event": "start", "t": 0, "unit": "u1"}, {"event": "start", "t": 0, "unit": "u2"},
          {"event": "finish", "t": 1800, "unit": "u1", "ok": True, "matched": 20, "seconds": 60},
          {"event": "finish", "t": 3000, "unit": "u2", "ok": False, "seconds": 30},
          {"event": "finish", "t": 3600, "unit": "u2", "ok": True, "matched": 10, "seconds": 90},
          {"event": "open", "t": 3600, "batch": 1, "pr": 7, "units": ["u1", "u2"], "seconds": 30},
          {"event": "landed", "t": 4000, "batch": 1, "pr": 7, "units": ["u1", "u2"]}]
    m = swarm.metrics(ev, ci_runs=1)
    assert m["units"] == 2 and m["hours"] == 1.0 and m["functions_per_hour"] == 30.0
    assert m["units_per_hour"] == 2.0 and m["coordinator_min_per_unit"] == 1.75
    assert m["units_landed"] == 2 and m["ci_runs_per_landed_unit"] == 0.5 and m["failed_finishes"] == 1
    assert swarm.metrics([]) == {"units": 0}
    assert swarm.metrics(ev, since=3500)["units"] == 1


def test_log_and_read_events(tmp_path):
    p = tmp_path / "m.jsonl"
    swarm.log_event("start", p, now=1.0, unit="u1")
    swarm.log_event("finish", p, now=2.0, unit="u1", matched=3)
    assert swarm.read_events(p) == [{"event": "start", "t": 1.0, "unit": "u1"},
                                    {"event": "finish", "t": 2.0, "unit": "u1", "matched": 3}]
    assert json.loads(p.read_text().splitlines()[0])["unit"] == "u1"
    assert swarm.read_events(tmp_path / "none.jsonl") == []


def test_venv_python(monkeypatch):
    monkeypatch.setattr(swarm.os, "name", "nt")
    assert swarm.venv_python() == ".venv\\Scripts\\python"
    monkeypatch.setattr(swarm.os, "name", "posix")
    assert swarm.venv_python() == ".venv/bin/python"


# --------------------------------------------------------------------------- git flows, in a throwaway repo
def _git(cwd: Path, *args: str) -> str:
    import subprocess

    return subprocess.run(["git", *args], cwd=cwd, check=True, capture_output=True, text=True).stdout.strip()


def _commit(cwd: Path, name: str, text: str, msg: str) -> str:
    (cwd / name).write_text(text, encoding="utf-8")
    _git(cwd, "add", name)
    _git(cwd, "commit", "-q", "-m", msg)
    return _git(cwd, "rev-parse", "HEAD")


@pytest.fixture
def repo(tmp_path, monkeypatch):
    """A clone of a bare 'origin' with one commit on master, set up as the batch worktree."""
    origin, work = tmp_path / "origin.git", tmp_path / "work"
    _git(tmp_path, "init", "-q", "--bare", "-b", "master", str(origin))
    _git(tmp_path, "clone", "-q", str(origin), str(work))
    for k, v in (("user.name", "t"), ("user.email", "t@example.invalid"), ("commit.gpgsign", "false")):
        _git(work, "config", k, v)
    _git(work, "switch", "-q", "-c", "master")
    _commit(work, "a.txt", "a\n", "initial")
    _git(work, "push", "-q", "-u", "origin", "master")
    monkeypatch.setattr(swarm, "ROOT", work)
    monkeypatch.setattr(swarm, "STATE", work / ".swarm" / "batch.json")
    monkeypatch.setattr(swarm, "METRICS", work / ".swarm" / "metrics.jsonl")
    monkeypatch.setattr(swarm, "main_checkout", lambda: tmp_path / "main")
    return work


class FakeGh:
    def __init__(self):
        self.calls, self.state = [], "OPEN"

    def __call__(self, *args, check=True):
        self.calls.append(args)
        if args[:2] == ("pr", "create"):
            return "https://github.com/o/r/pull/77"
        if args[:2] == ("pr", "view"):
            return json.dumps({"state": self.state, "mergeStateStatus": "CLEAN"})
        return ""


def test_init_open_sync(repo, monkeypatch):
    fake = FakeGh()
    monkeypatch.setattr(swarm, "gh", fake)
    assert swarm.main(["init"]) == 0
    s = swarm.load_state()
    assert s.branch == "swarm/batch-1" and _git(repo, "branch", "--show-current") == "swarm/batch-1"

    # a unit (its source commit + its data commit) and a coordinator fix-up
    _commit(repo, "u1.cpp", "x\n", "pokecamp: Unk_1's members")
    _commit(repo, "d.csv", "1\n", "data: unit u1: 1 functions match")
    _commit(repo, "h.h", "y\n", "renames: u8 parameters")
    s.units.append(swarm.UnitRecord("u1", 1, section="## Unit u1\n\nmatched 1 (4 bytes), m/M 0, skipped 0, named 0",
                                    commits=["pokecamp: Unk_1's members", "data: unit u1: 1 functions match"]))
    swarm.save_state(s)
    assert swarm.main(["open"]) == 0
    s = swarm.load_state()
    assert s.batch == 2 and s.branch == "swarm/batch-2" and s.units == []
    assert [o.pr for o in s.open] == [77] and s.open[0].units == ["u1"]
    assert ("pr", "merge", "77", "--rebase", "--auto") in fake.calls
    body = (repo / ".swarm" / "pr-batch-1.md").read_text(encoding="utf-8")
    assert "renames: u8 parameters" in body and "Unk_1's members" not in body.split("## Units")[0]
    assert _git(repo, "rev-parse", "origin/swarm/batch-1") == s.open[0].head

    # while the PR is open: no second PR, and sync leaves the branch alone
    _commit(repo, "u2.cpp", "z\n", "battle: Unk_2")
    s.units.append(swarm.UnitRecord("u2", 2, finished=1.0))
    swarm.save_state(s)
    assert swarm.main(["open"]) == 0 and len(fake.calls) == 3  # create, merge, then one view: still open
    assert swarm.main(["sync"]) == 0 and swarm.load_state().open

    # GitHub rebase-merges batch 1 onto a master that moved: new hashes
    own = _git(repo, "rev-parse", "HEAD")
    _git(repo, "switch", "-q", "--detach", "origin/master")
    _commit(repo, "other.txt", "o\n", "ci: something else landed first")
    _git(repo, "cherry-pick", f"origin/master..{s.open[0].head}")
    _git(repo, "push", "-q", "origin", "HEAD:master")
    _git(repo, "switch", "-q", "swarm/batch-2")
    assert _git(repo, "rev-parse", "HEAD") == own
    fake.state = "MERGED"
    assert swarm.main(["sync"]) == 0
    s = swarm.load_state()
    assert s.open == [] and s.base == _git(repo, "rev-parse", "origin/master")
    assert _git(repo, "log", "--format=%s", "origin/master..HEAD").splitlines() == ["battle: Unk_2"]
    assert [e["event"] for e in swarm.read_events()][-2:] == ["landed", "sync"]


def test_refuses_main_checkout(repo, monkeypatch):
    monkeypatch.setattr(swarm, "main_checkout", lambda: repo)
    with pytest.raises(SystemExit, match="main checkout"):
        swarm.main(["init"])


def test_sync_closed_unmerged(repo, monkeypatch):
    fake = FakeGh()
    fake.state = "CLOSED"
    monkeypatch.setattr(swarm, "gh", fake)
    swarm.main(["init"])
    s = swarm.load_state()
    s.open.append(swarm.OpenBatch(1, 5, "u", "h", [], 0))
    swarm.save_state(s)
    with pytest.raises(SystemExit, match="closed without merging"):
        swarm.main(["sync"])


def test_finish(repo, monkeypatch):
    import integrate

    monkeypatch.setattr(swarm, "gh", FakeGh())
    monkeypatch.setattr(integrate, "worktree_of", lambda branch: None)
    swarm.main(["init"])
    start = _git(repo, "rev-parse", "HEAD")
    calls = []

    def fake_tool(argv, cwd=None):
        calls.append(argv)
        _commit(repo, "u.cpp", f"{len(calls)}\n", "pokecamp: Unk_9")
        if len(calls) == 1:   # the first integration fails after replaying a commit
            return 1, "regressions (O before, not now)"
        (repo / ".swarm" / "integrate-u9.md").write_text(SECTION, encoding="utf-8")
        _commit(repo, "d.csv", "9\n", "data: unit u9: 9 functions match, 2 m/M")
        return 0, "summary for the PR: .swarm/integrate-u9.md"

    monkeypatch.setattr(swarm, "run_tool", fake_tool)
    with pytest.raises(SystemExit, match="integration of u9 failed"):
        swarm.main(["finish", "u9", "--no-auto"])
    assert _git(repo, "rev-parse", "HEAD") == start and swarm.load_state().units == []
    assert swarm.main(["finish", "u9", "--no-auto"]) == 0
    s = swarm.load_state()
    assert [(u.unit, u.matched, u.nonmatching, u.skipped) for u in s.units] == [("u9", 9, 2, 1)]
    assert s.units[0].commits == ["data: unit u9: 9 functions match, 2 m/M", "pokecamp: Unk_9"]
    ev = swarm.read_events()
    assert [(e["event"], e.get("ok")) for e in ev if e["event"] == "finish"] == [("finish", False), ("finish", True)]
