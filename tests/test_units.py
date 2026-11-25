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
