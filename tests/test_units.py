"""tools/units.py: chunks, parts, file assignment, ordering and the sidecar,
on hand-built rows (no game files)."""
from __future__ import annotations

import pytest
import units as U
from common import BASE, Function, read_areas_csv

AREAS = ("SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"
         "0x7100000000,0x7100001000,0x7100000000,0x7100001000,game/a,game,low,x\n"
         "0x7100001000,0x7100002000,0x7100001000,0x7100002000,yebis,library,high,x\n"
         "0x7100002000,0x7100003000,0x7100002000,0x7100003000,middleware,library,high,x\n")


def fn(addr: int, size: int, status: str = "U", name: str = "") -> Function:
    return Function(addr, addr, size, size, "common", status, name)


@pytest.fixture
def areas(write_csv):
    return read_areas_csv(write_csv("areas.csv", AREAS))


def test_address_comments():
    text = "// 0x7100000010\nvoid f() {}\n  // Sword 0x7100000020, Shield 0x7100000030\nint x; // 0x7100000040\n"
    assert U.address_comments(text) == [0x10, 0x20]


def test_chunk_limits():
    fs = [fn(i * 16, 16) for i in range(5)]
    assert [len(c) for c in U.chunk(fs, max_funcs=2, max_bytes=1000)] == [2, 2, 1]
    assert [len(c) for c in U.chunk(fs, max_funcs=10, max_bytes=40)] == [2, 2, 1]
    big = [fn(0, 4000), fn(4000, 8)]
    assert [len(c) for c in U.chunk(big, max_bytes=100)] == [1, 1]


def test_generated_dirs():
    assert U.is_generated("src/unsorted/leaf/Unk_1.cpp")
    assert U.is_generated("lib/wwise/class/x.cpp")
    assert not U.is_generated("src/unsorted/Unk_1.cpp")
    assert not U.is_generated("src/unsorted/leafy/Unk_1.cpp")


def test_build_units_cuts_at_segments_and_skips_excluded_areas(areas):
    rows = [fn(0x0, 8), fn(0x10, 8, "O"), fn(0x20, 8),          # segment 1, game/a
            fn(0x40, 8),                                       # segment 2, game/a
            fn(0x1000, 8),                                     # yebis: excluded
            fn(0x2000, 8, "M")]                                # middleware
    segs = [(0x0, 0x40), (0x40, 0x1000), (0x1000, 0x3000)]
    units = U.build_units(rows, areas, segs, {})
    assert [u.id for u in units] == ["u0", "u2000"]           # both game/a segments in one unit
    assert [len(p.funcs) for p in units[0].parts] == [3, 1]
    assert [p.file for p in units[0].parts] == ["src/unsorted/a/Unk_0.cpp", "src/unsorted/a/Unk_40.cpp"]
    assert units[1].parts[0].file == "lib/middleware/Unk_2000.cpp"
    assert [f.sword for f in units[0].work] == [0x0, 0x20, 0x40]
    assert units[1].work == []
    mm = U.build_units(rows, areas, segs, {}, statuses="mM")
    assert [u.id for u in U.ordered(mm)] == ["u2000"]


def test_files_reuse_hand_written_homes_once(areas):
    rows = [fn(0x0, 8), fn(0x10, 8), fn(0x20, 8)]
    segs = [(0x0, 0x10), (0x10, 0x20), (0x20, 0x1000)]
    index = {0x0: "src/x/Home.cpp", 0x10: "src/x/Home.cpp", 0x20: "src/unsorted/leaf/Gen.cpp"}
    units = U.build_units(rows, areas, segs, index, unit_funcs=1)  # one part per unit
    files = [u.parts[0].file for u in units]
    # the first part takes Home.cpp; the second can't share it, so it gets a new file
    # in the nearest hand-written file's directory; generated files are never a home
    assert files == ["src/x/Home.cpp", "src/x/Unk_10.cpp", "src/x/Unk_20.cpp"]
    assert not units[0].parts[0].new_file and units[1].parts[0].new_file
    assert len(set(files)) == len(files)


def test_score_and_order(areas):
    rows = [fn(0x0, 8), fn(0x100, 400), fn(0x300, 8, name="_Z1fv")]
    segs = [(0x0, 0x100), (0x100, 0x300), (0x300, 0x1000)]
    calls = {0x0: [0x300], 0x100: [0x999]}
    units = U.build_units(rows, areas, segs, {}, calls_of=lambda f: calls.get(f.sword, []), unit_funcs=1)
    by = {u.id: u for u in units}
    assert by["u0"].score == 8 + U.CALL_COST                    # a named callee isn't unknown
    assert by["u100"].score == 400 + U.CALL_COST + U.UNKNOWN_COST
    assert by["u300"].score == 8
    assert [u.id for u in U.ordered(units)] == ["u300", "u0", "u100"]  # by score per function


def test_unit_ids():
    assert U.unit_id(0x7c3a40) == "u7c3a40"
    assert U.parse_unit_id("U7C3A40") == 0x7c3a40
    with pytest.raises(SystemExit):
        U.parse_unit_id("7c3a40")


def test_sidecar_roundtrip(tmp_path):
    p = tmp_path / ".swarm" / "sidecar.json"
    data = U.read_sidecar(p)
    assert data == {"unit": "", "base": "", "names": [], "statuses": [], "report": ""}
    U.sidecar_name(data, "0x7100000010", "_Z1fv", "string 'f'")
    U.sidecar_name(data, "0x7100000010", "_Z1gv")            # renaming replaces
    U.sidecar_status(data, "0x7100000020", "M", "regalloc")
    with pytest.raises(SystemExit):
        U.sidecar_status(data, "0x7100000020", "O", "x")
    with pytest.raises(SystemExit):
        U.sidecar_status(data, "0x7100000020", "m", " ")
    U.write_sidecar(data, p)
    back = U.read_sidecar(p)
    assert back["names"] == [{"addr": "0x7100000010", "name": "_Z1gv", "evidence": ""}]
    assert back["statuses"] == [{"addr": "0x7100000020", "status": "M", "reason": "regalloc"}]


def test_norm_addr():
    assert U.norm_addr("0x7100000010") == "0x7100000010"
    assert U.norm_addr("10") == f"0x{BASE + 0x10:x}"


def test_blocked_shape():
    assert U.blocked_shape([0x14000010])                      # b T
    assert U.blocked_shape([0xD1012000, 0x17FFFFF0])          # sub x0, x0, #0x48 ; b T
    assert not U.blocked_shape([0xD65F03C0])                  # ret
    assert not U.blocked_shape([0xD1012021, 0x14000010])      # sub x1, x1, #0x48 ; b T
    assert not U.blocked_shape([0x94000010])                  # bl T
    assert not U.blocked_shape([0x14000010, 0x14000010, 0x14000010])


def test_blocked_functions_cost_more(areas):
    rows = [fn(0x0, 4), fn(0x100, 40)]
    units = U.build_units(rows, areas, [(0x0, 0x100), (0x100, 0x1000)], {}, unit_funcs=1,
                          blocked=lambda f: f.sword == 0x0)
    assert units[0].score == 4 + U.BLOCKED_COST
    assert [u.id for u in U.ordered(units)] == ["u100", "u0"]


def test_new_files_avoid_include_dirs(areas):
    rows = [fn(0x0, 8), fn(0x10, 8)]
    index = {0x4: "lib/x/include/y/Z.cpp", 0x8: "lib/x/src/W.cpp"}
    units = U.build_units(rows, areas, [(0x0, 0x10), (0x10, 0x1000)], index, unit_funcs=1)
    assert all("include" not in p.file for u in units for p in u.parts)


def test_source_files():
    index = {0x8: "lib/x/src/W.cpp", 0x4: "lib/x/include/y/Z.h", 0x2: "src/unsorted/leaf/Unk_2.cpp",
             0x1: "src/a/B.cpp"}
    assert U.source_files(index) == [(0x1, "src/a/B.cpp"), (0x8, "lib/x/src/W.cpp")]


def test_sidecar_retypes(tmp_path):
    p = tmp_path / ".swarm" / "sidecar.json"
    data = U.read_sidecar(p)
    U.sidecar_retype(data, "0x7100000010", "_Z1fh", "_Z1fj")
    U.sidecar_retype(data, "0x7100000010", "_Z1ft", "_Z1fj")   # again: replaces
    U.write_sidecar(data, p)
    assert U.read_sidecar(p)["retypes"] == [{"addr": "0x7100000010", "name": "_Z1ft", "old": "_Z1fj"}]
    p.write_text('{"unit": "u1", "names": []}', encoding="utf-8")   # an older sidecar
    assert U.read_sidecar(p)["retypes"] == []


def test_record_retype_runs_retype_py(tmp_path, monkeypatch):
    """record retype applies tools/retype.py here and records it only if that worked."""
    import subprocess
    import types

    p = tmp_path / ".swarm" / "sidecar.json"
    read, write = U.read_sidecar, U.write_sidecar
    monkeypatch.setattr(U, "read_sidecar", lambda path=p: read(path))
    monkeypatch.setattr(U, "write_sidecar", lambda data, path=p: write(data, path))
    monkeypatch.setattr(U, "SIDECAR", p)
    monkeypatch.setattr(U, "ROOT", tmp_path)
    monkeypatch.setattr(U, "read_functions_csv", lambda: [fn(0x10, 8, "O", "_Z1fj")])
    runs = []
    rc = [0]
    monkeypatch.setattr(subprocess, "run", lambda argv, **kw: runs.append(argv[1:]) or types.SimpleNamespace(
        returncode=rc[0]))
    args = types.SimpleNamespace(what="retype", addr="0x10", value="_Z1fh", evidence=None, reason=None)
    U.write_sidecar(U.read_sidecar(p), p)
    assert U.cmd_record(args) == 0
    assert runs == [[str(tmp_path / "tools" / "retype.py"), f"0x{BASE + 0x10:x}", "_Z1fh", "--apply"]]
    assert U.read_sidecar(p)["retypes"] == [{"addr": f"0x{BASE + 0x10:x}", "name": "_Z1fh", "old": "_Z1fj"}]
    rc[0] = 1
    args.value = "_Z1ft"
    with pytest.raises(SystemExit):
        U.cmd_record(args)
    assert U.read_sidecar(p)["retypes"][0]["name"] == "_Z1fh"


# --------------------------------------------------------------------------- tied blocks (E1)
def links(calls=None, vtables=None, members=None, taken=()) -> U.Links:
    return U.Links(calls={k: set(v) for k, v in (calls or {}).items()},
                   vtables={k: set(v) for k, v in (vtables or {}).items()},
                   members={k: set(v) for k, v in (members or {}).items()}, taken=set(taken))


def run_of(n: int, size: int = 16) -> list:
    return [fn(i * size, size) for i in range(n)]


def test_tied_blocks_calls():
    run = run_of(20)
    at = [f.sword for f in run]
    # 0 -> 2 ties 0..2; 5 -> 4 too; 10 -> 19 is too far; 12 -> 13's callee is also called from outside
    lk = links({at[0]: [at[2]], at[5]: [at[4]], at[10]: [at[19]], at[12]: [at[13]], 0x9000: [at[13]]})
    assert U.tied_blocks(run, lk) == [(0, 2), (4, 5)]
    assert U.tied_blocks(run, lk, near=9) == [(0, 2), (4, 5), (10, 19)]
    # overlapping spans merge
    lk = links({at[0]: [at[3]], at[2]: [at[5]]})
    assert U.tied_blocks(run, lk) == [(0, 5)]
    # `bounds`: what counts as the run for "only the run calls it"
    lk = links({at[1]: [at[2]], 0x9000: [at[2]]})
    assert U.tied_blocks(run, lk) == []
    assert U.tied_blocks(run, lk, bounds=(0, 0x10000)) == [(1, 2)]


def test_tied_blocks_classes():
    run = run_of(20)
    at = [f.sword for f in run]
    # a class: ctor at 3 and dtor at 9 address vtable group 0x100; it owns the slot function at 12
    lk = links(vtables={at[3]: [0x100], at[9]: [0x100]}, members={0x100: [at[12], 0x9000]})
    assert U.tied_blocks(run, lk) == [(3, 12)]
    assert U.tied_blocks(run, lk, members=False) == [(3, 9)]
    assert U.tied_blocks(run, lk, classes=False) == []
    # a vtable that code outside the run addresses too doesn't tie
    lk = links(vtables={at[3]: [0x100], at[9]: [0x100], 0x9000: [0x100]})
    assert U.tied_blocks(run, lk) == []


def test_cut_run_keeps_blocks_and_other_cuts():
    run = run_of(40)
    at = [f.sword for f in run]
    old = U.chunk(run)                                   # 16 + 16 + 8
    assert [len(c) for c in old] == [16, 16, 8]
    parts, over = U.cut_run(run, links({at[14]: [at[18]]}))
    assert over == []
    # the block 14..18 crosses the first cut: that stretch (0..31) is cut again with the block as one
    # atom (0..13, 14..29, 30..31); the cut at 32 survives, so the last part is the old one
    assert [len(p) for p in parts] == [14, 16, 2, 8]
    assert parts[-1] == old[-1]
    assert [f.sword for f in parts[1]][:5] == at[14:19]
    # no tie: chunk()'s cut
    assert U.cut_run(run, links())[0] == old
    assert U.cut_run(run, None) == (old, [])


def test_cut_run_cap_falls_back_level_by_level():
    run = run_of(40)
    at = [f.sword for f in run]
    # a class spanning everything (above a cap of 10), with a near call 20 -> 21 inside it
    lk = links({at[20]: [at[21]]}, vtables={at[0]: [0x100], at[39]: [0x100]})
    parts, over = U.cut_run(run, lk, cap_funcs=10)
    assert over == [(0, 640)]                           # the class is above the cap: reported
    assert any(at[20] in [f.sword for f in p] and at[21] in [f.sword for f in p] for p in parts)  # the call ties
    keep, over = U.tie_run(run, lk, cap_funcs=1)
    assert keep == [] and over == [(0, 640)]


def test_build_units_never_split_a_block(areas):
    rows = [fn(i * 16, 16) for i in range(100)]                    # one segment, game/a
    at = [f.sword for f in rows]
    lk = links({at[30]: [at[34]]})                                  # crosses the unit cut at 32
    before = U.build_units(rows, areas, [(0, 0x1000)], {})
    after = U.build_units(rows, areas, [(0, 0x1000)], {}, links=lk)
    assert [u.id for u in before] == ["u0", "u200", "u400", "u600"]
    unit_of = {f.sword: u.id for u in after for f in u.funcs}
    assert unit_of[at[30]] == unit_of[at[34]]
    # the units the block doesn't touch keep their IDs and extents
    assert {(u.start, u.end) for u in before if u.start >= 0x400} <= {(u.start, u.end) for u in after}
    assert sum(len(u.funcs) for u in after) == 100
    assert all(not u.loose for u in after)
    # a class of all 100 (within the cap): one unit, one file
    big = links(vtables={at[0]: [0x100], at[99]: [0x100]})
    units = U.build_units(rows, areas, [(0, 0x1000)], {}, links=big)
    assert [(u.start, u.end, len(u.parts)) for u in units] == [(0, 1600, 1)]


def test_build_units_reports_loose(areas, monkeypatch):
    # above the cap: cut as before, and reported on every unit the block crosses
    monkeypatch.setattr(U, "GROUP_CAP_FUNCS", 8)
    rows = [fn(i * 16, 16) for i in range(100)]
    at = [f.sword for f in rows]
    big = links(vtables={at[0]: [0x100], at[99]: [0x100]})
    before = U.build_units(rows, areas, [(0, 0x1000)], {})
    units = U.build_units(rows, areas, [(0, 0x1000)], {}, links=big)
    assert [(u.start, u.end) for u in units] == [(u.start, u.end) for u in before]
    assert all(u.loose == [(0, 1600)] for u in units)
    pos = {f.sword: i for i, f in enumerate(rows)}
    assert U.crossing_ties(units[0], big, pos) == [("class", 0x100, [at[99]])]
    assert U.crossing_ties(units[1], big, pos) == []      # it addresses no vtable


def test_crossing_ties_calls(areas, monkeypatch):
    monkeypatch.setattr(U, "GROUP_CAP_FUNCS", 4)
    rows = [fn(i * 16, 16) for i in range(40)]
    at = [f.sword for f in rows]
    # a chain of near calls (0 -> 3 -> 6 -> ... -> 36): one block above the cap at every level
    lk = links({at[i]: [at[i + 3]] for i in range(0, 36, 3)})
    units = U.build_units(rows, areas, [(0, 0x1000)], {}, links=lk, unit_funcs=8)
    assert units[0].loose == [(0, 37 * 16)]
    pos = {f.sword: i for i, f in enumerate(rows)}
    assert [len(u.funcs) for u in units][:2] == [16, 16]     # MAX_FUNCS parts, one per unit
    assert U.crossing_ties(units[0], lk, pos) == [("call", at[15], at[18])]
    assert U.crossing_ties(units[1], lk, pos) == [("call", at[15], at[18]), ("call", at[30], at[33])]


def test_group_stable():
    parts = [U.Part([fn(i * 16, 16)], (0, 0x1000), "game/a") for i in range(6)]
    old = list(parts)
    assert [len(g) for g in U.group_stable(parts, old, max_funcs=2)] == [2, 2, 2]
    # parts 1 and 2 merged: only the stretch from the old unit start 0 to the next surviving one (4) changes
    merged = [parts[0], U.Part(parts[1].funcs + parts[2].funcs, (0, 0x1000), "game/a"), parts[3], parts[4], parts[5]]
    groups = U.group_stable(merged, old, max_funcs=2)
    assert [g[0].start for g in groups] == [0x0, 0x10, 0x30, 0x40]
    assert [g[0].start for g in groups][-1] == 0x40 and len(groups[-1]) == 2


def test_local_calls_and_inlined(areas):
    rows = [fn(0x0, 16), fn(0x10, 16), fn(0x20, 16), fn(0x30, 16)]
    lk = links({0x0: [0x10, 0x20, 0x9000]}, taken=[0x30])
    index = {0x20: "src/unsorted/leaf/Gen.cpp"}             # already written, in a generated file
    u = U.build_units(rows, areas, [(0, 0x1000)], index, links=lk)[0]
    assert u.parts[0].file == "src/unsorted/a/Unk_0.cpp"
    calls = U.local_calls(u, lk, index)
    assert calls == {0x0: [(0x10, "src/unsorted/a/Unk_0.cpp", True), (0x20, "src/unsorted/leaf/Gen.cpp", False)]}
    # 0x0 has no caller and isn't taken; 0x30's address is taken
    assert U.inlined_in_original(u, lk) == [0x0]


def test_exe_links():
    import struct

    import vtables as V
    words = {0x0: [0x94000004,            # bl 0x10
                   0x90000000,            # adrp x0, 0
                   0x91044000,            # add x0, x0, #0x110 (the vtable's address point)
                   0xD65F03C0],
             0x10: [0x90000001,           # adrp x1, 0
                    0x91008021,           # add x1, x1, #0x20 (function 0x20's address)
                    0xD65F03C0, 0xD503201F],
             0x20: [0xD65F03C0]}
    img = bytearray(0x200)
    for a, ws in words.items():
        struct.pack_into(f"<{len(ws)}I", img, a, *ws)
    funcs = [(0x0, 16), (0x10, 16), (0x20, 4)]
    vt = V.Vtable(0x110, 0, None, [0x20], group=0x110)
    lk = U.exe_links(bytes(img), funcs, {0x110: 0x20}, [vt])
    assert lk.calls == {0x0: {0x10}}
    assert lk.vtables == {0x0: {0x110}}
    assert lk.members == {0x110: {0x20}}
    assert lk.taken == {0x20}
    assert lk.callers == {0x10: {0x0}} and lk.referrers == {0x110: {0x0}}
