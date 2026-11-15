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
AREAS_HEADER = "Start,End,Area,Kind,Confidence,Evidence\n"


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


def test_areas(write_csv):
    ok = write_csv(
        "areas.csv",
        AREAS_HEADER + "0x7100000000,0x7100001000,a,game,low,x\n0x7100001000,0x7100002000,b,library,high,y\n",
    )
    assert lint.lint_areas(ok) == []
    bad = write_csv(
        "areas.csv",
        AREAS_HEADER + "0x7100000000,0x7100002000,a,game,low,x\n0x7100001000,0x7100003000,b,lib,sure,y\n",
    )
    errors = lint.lint_areas(bad)
    assert any("overlaps" in e for e in errors)
    assert any("Kind" in e for e in errors)
    assert any("Confidence" in e for e in errors)


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
