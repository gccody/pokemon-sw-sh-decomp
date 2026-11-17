from __future__ import annotations

import pytest

import funcs
from common import read_functions_csv


@pytest.fixture
def rows(functions_csv):
    return read_functions_csv(functions_csv(
        "0x0000007100000100,8,0x0000007100000110,8,common,U,",
        "0x0000007100000200,8,0x0000007100000200,8,diverged,O,_ZN4pkmn10GetVersionEv",
    ))


@pytest.mark.parametrize("query", ["0x7100000100", "0x100", "7100000110", "0x7100000110"])
def test_find_by_either_games_address(rows, query):
    assert funcs.find(rows, query) is rows[0]


def test_find_by_name_or_placeholder(rows):
    assert funcs.find(rows, "_ZN4pkmn10GetVersionEv") is rows[1]
    assert funcs.find(rows, "FUN_7100000100") is rows[0]


def test_find_unknown_exits(rows):
    with pytest.raises(SystemExit):
        funcs.find(rows, "0x7100009999")


def test_find_prefers_the_sword_address(functions_csv):
    """0x300 is row 0's Shield address and row 1's Sword address: Sword is canonical."""
    a, b = read_functions_csv(functions_csv(
        "0x0000007100000200,8,0x0000007100000300,8,common,U,",
        "0x0000007100000300,8,0x0000007100000400,8,common,U,",
    ))
    assert funcs.find([a, b], "0x7100000300") is b


@pytest.fixture
def lua_rows(functions_csv):
    return read_functions_csv(functions_csv(
        "0x0000007101546000,16,0x00000071015460a0,16,common,U,",
        "0x0000007101546100,16,0x00000071015461a0,16,common,U,",
        "0x0000007101546200,16,0x00000071015462a0,16,common,U,luaL_error",
        "0x0000007101546300,16,,,sword,U,",
    ))


def test_apply_names_from_a_map(lua_rows):
    changed, problems = funcs.apply_names(lua_rows, [
        ("getfield@lauxlib", 0x7101546000, 0x71015460A0),
        ("getfield@loslib", 0x7101546100, 0x71015461A0),
        ("luaL_error", 0x7101546200, 0x71015462A0),  # already named: no change
        ("sword_only", 0x7101546300, None),
    ])
    assert problems == []
    assert changed == 3
    assert [f.name for f in lua_rows] == ["getfield@lauxlib", "getfield@loslib", "luaL_error", "sword_only"]


@pytest.mark.parametrize(
    "entry, message",
    [
        (("a", 0x7101546000, 0x71015461A0), "different functions.csv rows"),
        (("a", 0x7101546004, None), "no sword function starts at"),
        (("luaL_error", 0x7101546000, None), "already used by"),
        (("other", 0x7101546200, None), "already named luaL_error"),
        (("not a name", 0x7101546000, None), "not a valid symbol name"),
        (("a", None, None), "no address"),
    ],
)
def test_apply_names_reports_conflicts(lua_rows, entry, message):
    changed, problems = funcs.apply_names(lua_rows, [entry])
    assert changed == 0
    assert len(problems) == 1 and message in problems[0], problems
    assert lua_rows[0].name == "" and lua_rows[2].name == "luaL_error"


def test_apply_names_force_renames(lua_rows):
    changed, problems = funcs.apply_names(lua_rows, [("luaL_error2", 0x7101546200, None)], force=True)
    assert (changed, problems) == (1, [])
    assert lua_rows[2].name == "luaL_error2"


def test_read_name_map(write_csv):
    path = write_csv("map.csv", "Name,Sword,Shield\ngetfield@lauxlib,0x7101546000,0x71015460a0\nx,0x7101546300,\n")
    assert funcs.read_name_map(path) == [
        ("getfield@lauxlib", 0x7101546000, 0x71015460A0),
        ("x", 0x7101546300, None),
    ]
    with pytest.raises(SystemExit):
        funcs.read_name_map(write_csv("bad.csv", "Name,Addr\nx,0x1\n"))


def list_args(**kw):
    import argparse
    base = dict(scope=None, status=None, min=None, max=None, range=None, area=None, unnamed=False, n=0)
    return argparse.Namespace(**{**base, **kw})


def test_list_by_area_uses_each_games_columns(write_csv, functions_csv, capsys):
    path = write_csv("areas.csv", (
        "SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"
        "0x7100000000,0x7100001000,0x7100000000,0x71000010a0,a,game,low,x\n"
        "0x7100001000,0x7100002000,0x71000010a0,0x71000020a0,b,library,high,y\n"
    ))
    rows = read_functions_csv(functions_csv(
        "0x0000007100000100,8,0x0000007100000100,8,common,U,",
        "0x0000007100001000,8,0x00000071000010a0,8,common,U,",
        ",,0x0000007100001040,8,shield,U,",
    ))
    funcs.cmd_list(list_args(area="b", areas_csv=path), rows)
    out = capsys.readouterr().out.splitlines()
    assert [line.split()[0] for line in out] == ["0x0000007100001000"]
    funcs.cmd_list(list_args(area="a", areas_csv=path), rows)
    out = capsys.readouterr().out.splitlines()
    assert [line.split()[:2] for line in out] == [["0x0000007100000100", "0x0000007100000100"],
                                                  ["-", "0x0000007100001040"]]
    with pytest.raises(SystemExit, match="no area 'c'"):
        funcs.cmd_list(list_args(area="c", areas_csv=path), rows)


def test_list_by_area_group(write_csv, functions_csv, capsys):
    path = write_csv("areas.csv", (
        "SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"
        "0x7100000000,0x7100001000,0x7100000000,0x7100001000,game/a,game,low,x\n"
        "0x7100001000,0x7100002000,0x7100001000,0x7100002000,game/b/c,game,low,y\n"
        "0x7100002000,0x7100003000,0x7100002000,0x7100003000,gamex,game,low,z\n"
    ))
    rows = read_functions_csv(functions_csv(
        "0x0000007100000100,8,0x0000007100000100,8,common,U,",
        "0x0000007100001000,8,0x0000007100001000,8,common,U,",
        "0x0000007100002000,8,0x0000007100002000,8,common,U,",
    ))
    funcs.cmd_list(list_args(area="game", areas_csv=path), rows)
    assert [line.split()[0] for line in capsys.readouterr().out.splitlines()] == [
        "0x0000007100000100", "0x0000007100001000"]  # not gamex
    funcs.cmd_list(list_args(area="game/b", areas_csv=path), rows)
    assert [line.split()[0] for line in capsys.readouterr().out.splitlines()] == ["0x0000007100001000"]
    with pytest.raises(SystemExit, match="no area 'game/'"):
        funcs.cmd_list(list_args(area="game/", areas_csv=path), rows)


def words(*w: int) -> bytes:
    import struct
    return struct.pack(f"<{len(w)}I", *w)


RET = 0xD65F03C0


@pytest.mark.parametrize("code, pattern", [
    (words(RET), "ret"),
    (words(0xD1002000, 0x14000040), "sub x0, x0, #N ; b T"),  # sub x0, x0, #8 ; b +0x100: a this-adjusting thunk
    (words(0xF9400800, RET), "ldr x0, [x0, #N] ; ret"),       # ldr x0, [x0, #0x10]
    (words(0x52800020, RET), "mov w0, #N ; ret"),             # mov w0, #1
    (words(0xE7FFDEFE), "trap"),                              # the NX trap word
    (words(0xFFFFFFFF, RET), ".word ; ret"),                  # undecodable words don't hide the rest
])
def test_pattern_of(code, pattern):
    assert funcs.pattern_of(code, 0x7100001000) == pattern


def test_pattern_of_ignores_the_address():
    code = words(0x94000010, RET)  # bl +0x40
    assert funcs.pattern_of(code, 0x7100001000) == funcs.pattern_of(code, 0x7100abc000) == "bl T ; ret"


def test_branch_targets():
    img = words(RET, 0x14000040, 0x97FFFFFF, 0x94000001, 0xF9400800)  # ret, b +0x100, bl -4, bl +4, ldr
    assert funcs.branch_targets(img, 0, len(img)) == {4 + 0x100, 8 - 4, 12 + 4}
    assert funcs.branch_targets(img, 8, 12) == {4}


@pytest.mark.parametrize("addr, kind", [(0x10, "data"), (0x20, "call"), (0x30, "both"), (0x40, "none")])
def test_reference_kind(addr, kind):
    assert funcs.reference_kind(addr, called={0x20, 0x30}, in_data={0x10, 0x30}) == kind


def test_select_is_shared_by_list_and_patterns(functions_csv):
    rows = read_functions_csv(functions_csv(
        "0x0000007100000100,8,0x0000007100000100,8,common,U,",
        "0x0000007100000200,64,0x0000007100000200,64,common,U,",
        "0x0000007100000300,8,0x0000007100000300,8,common,O,_Z1fv",
    ))
    picked = list(funcs.select(list_args(status="U", max=8), rows))
    assert [f.sword_str for f in picked] == ["0x0000007100000100"]
