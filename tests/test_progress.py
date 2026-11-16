from __future__ import annotations

import progress
from common import AreaMap, read_areas_csv, read_functions_csv

AREAS_HEADER = "SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"


def test_read_areas_csv(write_csv):
    path = write_csv("areas.csv", AREAS_HEADER + (
        '0x7100000000,0x7100001000,0x7100000000,0x71000010a0,a,game,low,"x, y"\n'
        "0x7100001000,0x7100002000,,,b,library,high,z\n"
    ))
    a, b = read_areas_csv(path)
    assert (a.name, a.kind, a.confidence, a.evidence) == ("a", "game", "low", "x, y")
    assert a.range("sword") == (0, 0x1000)
    assert a.range("shield") == (0, 0x10A0)
    assert b.in_version("sword") and not b.in_version("shield")


def test_area_map_uses_each_games_columns(write_csv):
    areas = read_areas_csv(write_csv("areas.csv", AREAS_HEADER + (
        "0x7100000000,0x7100001000,0x7100000000,0x71000010a0,a,game,low,x\n"
        "0x7100001000,0x7100002000,0x71000010a0,0x71000020a0,b,game,low,y\n"
    )))
    sword, shield = AreaMap(areas, "sword"), AreaMap(areas, "shield")
    assert sword.area_of(0x1040) == "b"
    assert shield.area_of(0x1040) == "a"
    assert shield.area_of(0x10A0) == "b"
    assert sword.area_of(0x2000) is None
    assert shield.area_of(0x2000) == "b"


def test_area_tallies_are_per_game(write_csv, functions_csv):
    areas = read_areas_csv(write_csv("areas.csv", AREAS_HEADER + (
        "0x7100000000,0x7100001000,0x7100000000,0x71000010a0,a,game,low,x\n"
        "0x7100001000,0x7100002000,0x71000010a0,0x71000020a0,b,game,low,y\n"
        "0x7100002000,0x7100003000,,,sw,game,low,z\n"
    )))
    funcs = read_functions_csv(functions_csv(
        "0x0000007100000100,8,0x0000007100000100,8,common,O,",
        "0x0000007100001000,16,0x00000071000010a0,16,common,U,",
        "0x0000007100002000,4,,,sword,U,",
        ",,0x0000007100003000,4,shield,U,",
    ))
    t = progress.area_tallies(funcs, areas)
    assert {k: (v.n, v.bytes, v.done_n) for k, v in t["sword"].items()} == {
        "a": (1, 8, 1), "b": (1, 16, 0), "sw": (1, 4, 0)}
    assert {k: (v.n, v.bytes, v.done_n) for k, v in t["shield"].items()} == {
        "a": (1, 8, 1), "b": (1, 16, 0), "unassigned": (1, 4, 0)}
