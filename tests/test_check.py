"""check.py pieces that need no game files: symbol naming and the absent list."""
from __future__ import annotations

import check


class FakeSymbol:
    def __init__(self, name: str, bind: str, typ: str = "STT_FUNC"):
        self.name = name
        self._d = {"st_info": {"bind": bind, "type": typ}}

    def __getitem__(self, key):
        return self._d[key]


def test_local_symbols_are_file_qualified():
    src = r"C:\repo\lib\lua\loslib.c"
    assert check._symbol_name(FakeSymbol("getfield", "STB_LOCAL"), src) == "getfield@loslib"
    assert check._symbol_name(FakeSymbol("syslib", "STB_LOCAL", "STT_OBJECT"), src) == "syslib@loslib"
    assert check._symbol_name(FakeSymbol("luaopen_os", "STB_GLOBAL"), src) == "luaopen_os"


def test_section_and_unnamed_symbols_are_not_qualified():
    src = "lib/lua/ldump.c"
    assert check._symbol_name(FakeSymbol("", "STB_LOCAL", "STT_SECTION"), src) == ""
    assert check._symbol_name(FakeSymbol("$d.2", "STB_LOCAL", "STT_NOTYPE"), src) == "$d.2"


def test_read_absent(write_csv):
    path = write_csv("absent_functions.csv", 'Name,Reason\nlua_setallocf,unreferenced\nb_and@lbitlib,"no bit32, at all"\n')
    assert check.read_absent(path) == {"lua_setallocf": "unreferenced", "b_and@lbitlib": "no bit32, at all"}
    assert check.read_absent(path.parent / "missing.csv") == {}
