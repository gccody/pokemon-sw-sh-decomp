from __future__ import annotations

import pytest

import lint
from common import ROOT

GOOD = (
    "0x0000007100000100,8,0x0000007100000100,8,common,U,",
    "0x0000007100000200,12,0x0000007100000210,16,diverged,O,_ZN4pkmn10GetVersionEv",
    "0x0000007100000300,4,,,sword,U,",
    ",,0x0000007100000400,4,shield,U,",
)
AREAS_HEADER = "SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"


def errors_for(functions_csv, *rows):
    errors, _, _ = lint.lint_functions(functions_csv(*rows))
    return errors


def test_repository_data_is_clean():
    errors, n, _ = lint.lint_functions(ROOT / "data" / "functions.csv")
    assert errors == []
    assert n > 100_000
    assert lint.lint_data_symbols(ROOT / "data" / "data_symbols.csv") == []
    assert lint.lint_areas(ROOT / "data" / "areas.csv") == []


def test_good_rows_pass(functions_csv):
    assert errors_for(functions_csv, *GOOD) == []


@pytest.mark.parametrize(
    "row, message",
    [
        ("0x0000007100000100,8,0x0000007100000100,8,commn,U,", "bad scope"),
        ("0x0000007100000100,8,0x0000007100000100,8,common,X,", "bad status"),
        ("0x0000007100000100,8,,,common,U,", "scope common but present in sword=True shield=False"),
        ("0x0000007100000100,8,0x0000007100000100,8,sword,U,", "scope sword but present"),
        ("0x0000007100000100,6,0x0000007100000100,6,common,U,", "bad sword address/size"),
        ("0x0000007100000102,8,0x0000007100000100,8,common,U,", "bad sword address/size"),
        ("0x0000007100000100,8,0x0000007100000100,12,common,U,", "common function with different sizes"),
        ("0x0000007100000100,8,0x0000007100000100,8,common,O,pkmn::GetVersion()", "must be a symbol name"),
    ],
)
def test_bad_rows_are_reported(functions_csv, row, message):
    errors = errors_for(functions_csv, row)
    assert any(message in e for e in errors), errors


def test_rows_must_be_sorted(functions_csv):
    errors = errors_for(functions_csv, GOOD[1], GOOD[0])
    assert any("sorted" in e for e in errors)


def test_duplicate_names(functions_csv):
    errors = errors_for(
        functions_csv,
        "0x0000007100000100,8,0x0000007100000100,8,common,O,_Z1fv",
        "0x0000007100000200,8,0x0000007100000200,8,common,O,_Z1fv",
    )
    assert any("duplicate name _Z1fv" in e for e in errors)


def test_wrong_header(write_csv):
    errors, n, _ = lint.lint_functions(write_csv("functions.csv", "Addr,Size,Name\n"))
    assert n == 0
    assert "header" in errors[0]


def test_data_symbols(write_csv):
    ok = write_csv("data_symbols.csv", "Sword,Shield,Size,Name\n0x7101000000,0x7101000010,8,gFoo\n")
    assert lint.lint_data_symbols(ok) == []
    bad = write_csv(
        "data_symbols.csv",
        "Sword,Shield,Size,Name\n0x7101000000,,8,gFoo\n1234,,8,gBar\n0x7101000020,,0x8,gFoo\n",
    )
    errors = lint.lint_data_symbols(bad)
    assert any("bad Sword address" in e for e in errors)
    assert any("Size must be" in e for e in errors)
    assert any("duplicate name gFoo" in e for e in errors)


def areas_csv(write_csv, *rows):
    return write_csv("areas.csv", AREAS_HEADER + "".join(r + "\n" for r in rows))


def test_areas(write_csv):
    ok = areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x7100001000,a,game,low,x",
        "0x7100001000,0x7100002000,0x7100001000,0x71000020a0,b,library,high,y",
    )
    assert lint.lint_areas(ok) == []
    bad = areas_csv(
        write_csv,
        "0x7100000000,0x7100002000,0x7100000000,0x7100002000,a,game,low,x",
        "0x7100001000,0x7100003000,0x7100002000,0x7100003000,b,lib,sure,y",
    )
    errors = lint.lint_areas(bad)
    assert any("sword range overlaps" in e for e in errors)
    assert not any("shield range overlaps" in e for e in errors)
    assert any("Kind" in e for e in errors)
    assert any("Confidence" in e for e in errors)


def test_areas_are_checked_per_game(write_csv):
    # Sword is fine, Shield's second area starts before the first one ends.
    errors = lint.lint_areas(areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x7100001010,a,game,low,x",
        "0x7100001000,0x7100002000,0x7100001000,0x7100002000,b,game,low,y",
    ))
    assert any("shield range overlaps" in e for e in errors), errors
    assert not any("sword range" in e for e in errors), errors
    # The same areas in a different order in Shield.
    errors = lint.lint_areas(areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100001000,0x7100002000,a,game,low,x",
        "0x7100001000,0x7100002000,0x7100000000,0x7100001000,b,game,low,y",
    ))
    assert any("shield range overlaps the previous row or is out of order" in e for e in errors), errors


@pytest.mark.parametrize(
    "row, message",
    [
        ("0x7100001000,0x7100001000,0x7100000000,0x7100001000,a,game,low,x", "bad sword range"),
        ("0x7100000000,0x7100001000,0x7100000000,,a,game,low,x", "bad shield range"),
        ("0x7100000000,0x7100001000,7100000000,0x7100001000,a,game,low,x", "bad shield range"),
        ("0x0000000000,0x7100001000,0x7100000000,0x7100001000,a,game,low,x", "bad sword range"),
        (",,,,a,game,low,x", "needs a range for at least one game"),
        ("0x7100000000,0x7100001000,0x7100000000,0x7100001000,,game,low,x", "empty Area"),
    ],
)
def test_bad_area_rows(write_csv, row, message):
    errors = lint.lint_areas(areas_csv(write_csv, row))
    assert any(message in e for e in errors), errors


def test_area_in_one_game_only(write_csv):
    path = areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x7100001000,a,game,low,x",
        "0x7100001000,0x7100001100,,,sword_only,game,low,y",
        "0x7100001100,0x7100002000,0x7100001000,0x7100002000,b,game,low,z",
    )
    assert lint.lint_areas(path) == []


def test_duplicate_area_names(write_csv):
    errors = lint.lint_areas(areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x7100001000,a,game,low,x",
        "0x7100001000,0x7100002000,0x7100001000,0x7100002000,a,game,low,y",
    ))
    assert any("duplicate Area a" in e for e in errors), errors


def test_old_single_game_header_is_rejected(write_csv):
    path = write_csv("areas.csv", "Start,End,Area,Kind,Confidence,Evidence\n0x7100000000,0x7100001000,a,game,low,x\n")
    assert "header" in lint.lint_areas(path)[0]


def test_functions_must_be_in_the_same_area_in_both_games(write_csv, functions_csv):
    funcs = lint.read_functions_csv(functions_csv(
        "0x0000007100000100,8,0x0000007100000100,8,common,U,",
        "0x0000007100001000,8,0x00000071000010a0,8,common,U,",
        "0x0000007100001800,8,,,sword,U,",
    ))
    # Shield's boundary moves with the functions: no error.
    ok = areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x71000010a0,a,game,low,x",
        "0x7100001000,0x7100002000,0x71000010a0,0x7100002000,b,game,low,y",
    )
    assert lint.lint_areas(ok, funcs) == []
    # Shield's boundary too far up: the second function changes area.
    bad = areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x7100001100,a,game,low,x",
        "0x7100001000,0x7100002000,0x7100001100,0x7100002000,b,game,low,y",
    )
    assert lint.lint_areas(bad, funcs) == [
        "areas.csv: a sword end is the function 0x0000007100001000 / 0x00000071000010a0, "
        "so its shield end must be 0x71000010a0, not 0x7100001100",
        "areas.csv: b sword start is the function 0x0000007100001000 / 0x00000071000010a0, "
        "so its shield start must be 0x71000010a0, not 0x7100001100",
        "areas.csv: function 0x0000007100001000 / 0x00000071000010a0 is in area b in sword but a in shield",
    ]
    # A Shield boundary copied from Sword: each function still lands in the same area
    # (the shift is smaller than the functions around it), but the boundary does not pair up.
    copied = areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x7100001000,a,game,low,x",
        "0x7100001000,0x7100002000,0x7100001000,0x7100002000,b,game,low,y",
    )
    errors = lint.lint_areas(copied, funcs)
    assert len(errors) == 2 and all("must be 0x71000010a0, not 0x7100001000" in e for e in errors), errors
    # A boundary that is a function start only in Shield is paired the other way round.
    funcs.append(lint.Function(sword=0x1F00, shield=0x1F80, sword_size=4, shield_size=4, scope="common"))
    shield_side = areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x71000010a0,a,game,low,x",
        "0x7100001000,0x7100001f40,0x71000010a0,0x7100001f80,b,game,low,y",
    )
    errors = lint.lint_areas(shield_side, funcs)
    assert any("b shield end is the function" in e and "sword end must be 0x7100001f00" in e for e in errors), errors
    # Not covered in Shield at all.
    short = areas_csv(
        write_csv,
        "0x7100000000,0x7100001000,0x7100000000,0x7100000100,a,game,low,x",
        "0x7100001000,0x7100002000,0x71000010a0,0x7100002000,b,game,low,y",
    )
    assert any("in area a in sword but (none) in shield" in e for e in lint.lint_areas(short, funcs))


def test_repository_areas_match_functions():
    funcs = lint.read_functions_csv(ROOT / "data" / "functions.csv")
    assert lint.lint_areas(ROOT / "data" / "areas.csv", funcs) == []


@pytest.mark.parametrize(
    "path",
    ["main.nso", "game.XCI", "prod.keys", "data/original/sword/main", "assets/Pokemon Sword/readme.txt"],
)
def test_game_data_is_rejected(tmp_path, path):
    assert lint.lint_tracked_files([path], root=tmp_path)


def test_large_files_are_rejected(tmp_path):
    (tmp_path / "big.dat").write_bytes(b"\0" * (lint.MAX_TRACKED_BYTES + 1))
    (tmp_path / "small.cpp").write_text("int x;\n")
    assert lint.lint_tracked_files(["small.cpp"], root=tmp_path) == []
    assert "too large" in lint.lint_tracked_files(["big.dat"], root=tmp_path)[0]


def test_repository_tracks_no_game_data():
    tracked = lint.git_tracked_files()
    if tracked is None:
        pytest.skip("not a git checkout")
    assert lint.lint_tracked_files(tracked) == []


def test_file_qualified_local_names_pass(functions_csv):
    errors = errors_for(
        functions_csv,
        "0x0000007100000100,8,0x0000007100000100,8,common,O,getfield@lauxlib",
        "0x0000007100000200,8,0x0000007100000200,8,common,O,getfield@loslib",
    )
    assert errors == []
    errors = errors_for(functions_csv, "0x0000007100000100,8,0x0000007100000100,8,common,O,getfield@")
    assert any("must be a symbol name" in e for e in errors)


ABSENT_HEADER = "Name,Reason\n"


def test_absent_functions(write_csv):
    ok = write_csv("absent_functions.csv", ABSENT_HEADER + "b@x,unreferenced\nlua_setallocf,unreferenced\n")
    assert lint.lint_absent(ok, {"luaL_error"}) == []
    bad = write_csv(
        "absent_functions.csv",
        ABSENT_HEADER + "luaL_error,x\nz,\nz,dup\na b,x\n",
    )
    errors = lint.lint_absent(bad, {"luaL_error"})
    assert any("is in functions.csv" in e for e in errors)
    assert any("give a reason" in e for e in errors)
    assert any("duplicate name z" in e for e in errors)
    assert any("bad name 'a b'" in e for e in errors)
    assert any("sorted" in e for e in errors)
    assert "header" in lint.lint_absent(write_csv("absent_functions.csv", "Name\nx\n"))[0]


def test_repository_absent_functions_are_clean():
    names = {f.name for f in lint.read_functions_csv(ROOT / "data" / "functions.csv") if f.name}
    assert lint.lint_absent(ROOT / "data" / "absent_functions.csv", names) == []
