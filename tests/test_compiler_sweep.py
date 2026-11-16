"""compiler_sweep.py: the consensus name -> address map for both games
(--map-out), and the --src globs used for the corpora in docs/compiler.md
(Lua: one directory, PhysX: a recursive tree)."""
from __future__ import annotations

import compiler_sweep
import funcs
from common import BASE, read_functions_csv
from compiler_sweep import find_sources


def test_consensus_keeps_only_unanimous_unique_hits():
    configs = [
        {"a": [0x10], "b": [0x20], "c": [0x30, 0x40], "d": [0x50]},
        {"a": [0x10], "b": [0x24], "c": [0x30], "e": [0x60]},
    ]
    assert compiler_sweep.consensus(configs) == {"a": 0x10, "d": 0x50, "e": 0x60}


def test_find_hits_ignores_tiny_functions():
    ret = (0xD65F03C0).to_bytes(4, "little")
    nop = (0xD503201F).to_bytes(4, "little")
    big = nop * 3 + ret
    index = {compiler_sweep.masked(big): [0x100], compiler_sweep.masked(ret): [0x200]}
    assert compiler_sweep.find_hits({"big": big, "tiny": ret, "miss": nop * 4}, index) == {"big": [0x100]}


def test_other_game_range_follows_paired_rows(functions_csv):
    rows = read_functions_csv(functions_csv(
        "0x0000007101540000,16,0x0000007101540100,16,common,U,",
        "0x0000007101540010,32,0x0000007101540110,32,common,U,",
        "0x0000007101541000,16,0x0000007101541100,16,common,U,",
        "0x0000007101541010,8,,,sword,U,",
    ))
    lo, hi = 0x1540000, 0x1541000  # first two rows only
    assert compiler_sweep.other_game_range("sword", "shield", lo, hi, rows) == (0x1540100, 0x1540130)


def test_written_map_is_what_funcs_name_reads(tmp_path):
    maps = {"sword": {"getfield@lauxlib": 0x1546000, "only_sword": 0x1546300},
            "shield": {"getfield@lauxlib": 0x15460A0}}
    path = tmp_path / "map.csv"
    assert compiler_sweep.write_map(path, maps) == 2
    assert path.read_text(encoding="utf-8").splitlines()[0] == "Name,Sword,Shield"
    assert funcs.read_name_map(path) == [
        ("getfield@lauxlib", 0x1546000 + BASE, 0x15460A0 + BASE),
        ("only_sword", 0x1546300 + BASE, None),
    ]


def test_find_sources_recursive_and_dedup(tmp_path):
    for rel in ("a.cpp", "sub/b.cpp", "sub/deep/c.cpp", "sub/d.h"):
        p = tmp_path / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text("", encoding="utf-8")
    flat = find_sources([str(tmp_path / "*.cpp")])
    assert [p.name for p in flat] == ["a.cpp"]
    deep = find_sources([str(tmp_path / "**" / "*.cpp"), str(tmp_path / "sub" / "*.cpp")])
    assert sorted(p.name for p in deep) == ["a.cpp", "b.cpp", "c.cpp"]


def test_find_sources_no_match(tmp_path):
    assert find_sources([str(tmp_path / "*.c")]) == []
