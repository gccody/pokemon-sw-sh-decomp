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
