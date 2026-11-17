"""The local-symbol naming convention (tools/symbols.py) shared by every tool."""
from __future__ import annotations

import pytest

import symbols


@pytest.mark.parametrize(
    "source",
    ["lib/lua/lauxlib.c", "C:\\repo\\lib\\lua\\lauxlib.c", "/abs/lib/lua/lauxlib.c", "lauxlib.c"],
)
def test_file_stem_ignores_directories_on_every_platform(source):
    assert symbols.file_stem(source) == "lauxlib"


def test_only_local_symbols_are_qualified():
    assert symbols.qualify("getfield", "lib/lua/loslib.c", local=True) == "getfield@loslib"
    assert symbols.qualify("luaL_error", "lib/lua/lauxlib.c", local=False) == "luaL_error"
    assert symbols.qualify("getfield", None, local=True) == "getfield"


def test_same_static_in_two_files_gets_two_names():
    a = symbols.qualify("getfield", "lib/lua/lauxlib.c", True)
    b = symbols.qualify("getfield", "lib/lua/loslib.c", True)
    assert a != b


def test_split_round_trips():
    assert symbols.split("getfield@lauxlib") == ("getfield", "lauxlib")
    assert symbols.split("luaL_error") == ("luaL_error", None)
    assert symbols.split("_ZL3fooi@Unk_7eef40") == ("_ZL3fooi", "Unk_7eef40")


@pytest.mark.parametrize(
    "name",
    ["luaL_error", "_ZN4pkmn10GetVersionEv", "getfield@lauxlib", "utf8_decode.limits@lutf8lib",
     "_ZN12_GLOBAL__N_13fooEv@Unk_7eef40", ".L_MergedGlobals@descriptor.pb", ".L_MergedGlobals.3@lstrlib"],
)
def test_valid_names(name):
    assert symbols.is_valid_name(name)


@pytest.mark.parametrize(
    "name",
    ["", "pkmn::GetVersion()", "get field", "getfield@", "@lauxlib", "a@b@c", "1abc", "getfield@lua/lauxlib",
     ".L_MergedGlobals", ".L_str@lstrlib", ".rodata@lstrlib"],
)
def test_invalid_names(name):
    assert not symbols.is_valid_name(name)
