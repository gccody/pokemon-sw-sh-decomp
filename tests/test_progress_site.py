from __future__ import annotations

import json
import shutil
import subprocess

import pytest

import progress_site as ps
from common import read_areas_csv, read_functions_csv

AREAS_HEADER = "SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"
AREAS = AREAS_HEADER + (
    "0x7100000000,0x7100001000,0x7100000000,0x71000010a0,startup,game,low,x\n"
    "0x7100001000,0x7100002000,0x71000010a0,0x71000020a0,lua,library,high,y\n"
    "0x7100002000,0x7100003000,0x71000020a0,0x71000030a0,game/bag,game,medium,z\n"
)
HEADER = "Sword,SwordSize,Shield,ShieldSize,Scope,Status,Name"
A = "0x0000007100000100,8,0x0000007100000100,8,common,{},{}"
B = "0x0000007100001000,16,0x00000071000010a0,16,common,{},"
C = ",,0x00000071000020a0,4,shield,{},"

ST = {s: i for i, s in enumerate(ps.STATUSES)}
N = len(ps.STATUSES)


def counts(c, status):
    """(functions, bytes) with `status` in a counts list."""
    return c[ST[status]], c[N + ST[status]]


def log(*commits):
    """`git log -p -U0` output: commits are (sha, [removed], [added])."""
    out = []
    for sha, removed, added in commits:
        out.append(f"{ps.COMMIT_MARK}{sha} 2026-01-0{len(out) % 9 + 1}T00:00:00+00:00 subject {sha}")
        out += ["", "diff --git a/data/functions.csv b/data/functions.csv",
                "--- a/data/functions.csv", "+++ b/data/functions.csv", "@@ -1 +1 @@"]
        out += ["-" + r for r in removed] + ["+" + r for r in added]
        out.append("\\ No newline at end of file")
    return out


@pytest.fixture
def areas(write_csv):
    return read_areas_csv(write_csv("areas.csv", AREAS))


def test_parse_log_splits_commits_and_skips_headers():
    c1, c2 = ps.parse_log(log(("a1", [], [HEADER, A.format("U", "")]),
                              ("b2", [A.format("U", "")], [A.format("O", "_Z1fv")])))
    assert (c1.sha, c1.subject, c1.removed, c1.added) == ("a1", "subject a1", [], [HEADER, A.format("U", "")])
    assert c2.removed == [A.format("U", "")] and c2.added == [A.format("O", "_Z1fv")]


def test_history_follows_rows(areas):
    points = ps.build_history(ps.parse_log(log(
        ("a1", [], [HEADER, A.format("U", ""), B.format("U"), C.format("U")]),
        ("b2", [A.format("U", ""), C.format("U")], [A.format("O", "_Z1fv"), C.format("O")]),
        ("c3", [], []),  # e.g. only the header's line ending changed
        ("d4", [C.format("O")], [C.format("m")]),
    )), areas)
    assert [p["sha"] for p in points] == ["a1", "b2", "c3", "d4"]
    first, second, third, fourth = points
    assert counts(first["games"]["sword"], "U") == (2, 24)
    assert counts(first["games"]["shield"], "U") == (3, 28)
    assert counts(second["games"]["sword"], "O") == (1, 8)
    assert counts(second["games"]["shield"], "O") == (2, 12)
    assert second["matched_n"] == 2 and second["lost_n"] == 0
    assert second["matched"] == ["_Z1fv", "FUN_sh_71000020a0"]  # largest first
    assert fourth["matched_n"] == 0 and fourth["lost_n"] == 1
    # Areas: every area in the first point, then only the ones that changed.
    names = ps.area_order(areas)
    assert sorted(names[i] for i in first["areas"]["sword"]) == ["lua", "startup"]
    assert sorted(names[i] for i in first["areas"]["shield"]) == ["game/bag", "lua", "startup"]
    assert sorted(names[i] for i in second["areas"]["sword"]) == ["startup"]
    assert sorted(names[i] for i in second["areas"]["shield"]) == ["game/bag", "startup"]
    assert third["areas"] == {}
    assert list(fourth["areas"]) == ["shield"]


def test_history_reads_rows_with_each_commits_header(areas):
    """A later commit may add a column; rows are read by name, with their own header."""
    wide = HEADER + ",Extra"
    points = ps.build_history(ps.parse_log(log(
        ("a1", [], [HEADER, A.format("U", "")]),
        ("b2", [HEADER, A.format("U", "")], [wide, A.format("O", "") + ",x"]),
    )), areas)
    assert counts(points[1]["games"]["sword"], "O") == (1, 8)
    assert counts(points[1]["games"]["sword"], "U") == (0, 0)
    assert points[1]["matched_n"] == 1


def test_history_uses_todays_areas_and_counts_the_rest_as_unassigned(areas):
    out = "0x0000007100009000,4,0x0000007100009000,4,common,U,"
    points = ps.build_history(ps.parse_log(log(("a1", [], [HEADER, out]))), areas)
    names = ps.area_order(areas)
    assert [names[i] for i in points[0]["areas"]["sword"]] == [ps.UNASSIGNED]


def test_snapshot_groups_by_kind_and_places_by_sword_address(areas, functions_csv):
    funcs = read_functions_csv(functions_csv(A.format("O", "_Z1fv"), B.format("U"), C.format("U")))
    summary, lists = ps.snapshot(funcs, areas)
    by_name = {a["name"]: a for a in summary["areas"]}
    assert [by_name[n]["kind"] for n in ("startup", "lua", "game/bag")] == ["gflib", "library", "game"]
    assert ps.UNASSIGNED not in by_name  # no function is outside the areas
    assert counts(by_name["game/bag"]["counts"]["shield"], "U") == (1, 4)
    assert counts(by_name["game/bag"]["counts"]["sword"], "U") == (0, 0)
    assert counts(summary["games"]["sword"], "O") == (1, 8)
    assert by_name["lua"]["ranges"]["shield"] == [0x71000010A0, 0x71000020A0]
    assert [len(lists[n]) for n in ("startup", "lua", "game/bag")] == [1, 1, 1]
    assert counts(summary["scope_counts"]["shield"], "U") == (1, 4)


def test_function_rows_drop_trailing_blanks(functions_csv):
    funcs = read_functions_csv(functions_csv(A.format("O", "_Z1fv"), C.format("U")))
    rows = ps.function_rows(funcs, {"_Z1fv": "f()"}, {s: i for i, s in enumerate(ps.SCOPES)})
    assert rows[0] == [0x100, 8, 0x100, 8, ps.SCOPES.index("common"), "O", "_Z1fv", "f()"]
    assert rows[1] == [None, None, 0x20A0, 4, ps.SCOPES.index("shield"), "U"]


def test_write_site(tmp_path, areas, functions_csv):
    funcs = read_functions_csv(functions_csv(A.format("O", ""), B.format("U"), C.format("U")))
    commits = ps.parse_log(log(("a1", [], [HEADER, A.format("O", ""), B.format("U"), C.format("U")])))
    out = tmp_path / "site"
    written = ps.write_site(out, funcs, areas, commits, repo=tmp_path)
    for name in (*ps.STATIC_FILES, "data/summary.json", "data/history.json", ".nojekyll"):
        assert (out / name).exists(), name
    summary = json.loads((out / "data" / "summary.json").read_text(encoding="utf-8"))
    assert summary["history"] is True and summary["functions"] == 3
    for a in summary["areas"]:
        assert a["file"] in written
        assert isinstance(json.loads((out / a["file"]).read_text(encoding="utf-8")), list)
    history = json.loads((out / "data" / "history.json").read_text(encoding="utf-8"))
    assert history["areas"] == ps.area_order(areas)
    assert [p["sha"] for p in history["points"]] == ["a1"]
    # The last history point and the snapshot agree.
    assert history["points"][-1]["games"] == summary["games"]


def test_write_site_without_history(tmp_path, areas, functions_csv):
    funcs = read_functions_csv(functions_csv(A.format("U", "")))
    ps.write_site(tmp_path / "site", funcs, areas, None, repo=tmp_path)
    summary = json.loads((tmp_path / "site" / "data" / "summary.json").read_text(encoding="utf-8"))
    assert summary["history"] is False


@pytest.mark.skipif(shutil.which("git") is None, reason="needs git")
def test_git_log_reads_first_parent_history(tmp_path, areas):
    def git(*args):
        subprocess.run(["git", "-c", "user.name=t", "-c", "user.email=t@example.com", *args],
                       cwd=tmp_path, check=True, capture_output=True)

    csv_path = tmp_path / "data" / "functions.csv"
    csv_path.parent.mkdir()
    git("init", "-q", "-b", "main")
    for status in ("U", "O"):
        csv_path.write_text(f"{HEADER}\n{A.format(status, '')}\n{B.format('U')}\n", encoding="utf-8", newline="\n")
        git("add", "-A")
        git("commit", "-q", "-m", f"status {status}")
    (tmp_path / "other.txt").write_text("x", encoding="utf-8")
    git("add", "-A")
    git("commit", "-q", "-m", "unrelated")
    commits = ps.git_log(tmp_path, "HEAD")
    assert [c.subject for c in commits] == ["status U", "status O"]
    points = ps.build_history(commits, areas)
    assert counts(points[-1]["games"]["sword"], "O") == (1, 8)
    assert points[-1]["matched_n"] == 1
