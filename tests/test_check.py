"""check.py pieces that need no game files: symbol naming, the absent list and TLS relaxation."""
from __future__ import annotations

import struct
from pathlib import Path

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


# --- TLS descriptor accesses, relaxed to local-exec by the linker ---

def _w(*words: int) -> bytes:
    return b"".join(struct.pack("<I", w) for w in words)


TLS_COMPILED = (0x90000000, 0xF9400001, 0x91000000, 0xD63F0020)  # adrp x0; ldr x1, [x0]; add x0, x0; blr x1
MRS, LDR_X9 = 0xD53BD048, 0xF8606909  # mrs x8, tpidr_el0; ldr x9, [x8, x0]


def _tls_compare(original_words: tuple[int, ...], accesses: int = 1):
    code = _w(*(TLS_COMPILED * accesses), MRS, LDR_X9, 0xD65F03C0)
    relocs = {}
    for a in range(accesses):
        for i, t in enumerate(check.TLSDESC):
            relocs[16 * a + 4 * i] = check.Reloc(t, "_ZN1A6cache_E", "STT_TLS", 3, 0, 0)
    cf = check.CompiledFunc("f", Path("a.o"), code, relocs, None, "a.cpp")
    img = bytes(0x100) + _w(*original_words, MRS, LDR_X9, 0xD65F03C0)
    fn = check.Function(0x100, None, len(code), None, "common", name="f")
    orig = type("O", (), {"version": "sword", "img": img, "dyn": None})()
    return check.compare(cf, fn, orig, ({}, {"sword": {}}, {"sword": {}}), str)


def test_tls_descriptor_matches_its_local_exec_relaxation():
    res = _tls_compare((0xD2A00000, 0xF2800200, check.NOP, check.NOP))  # movz x0, #0, lsl 16; movk x0, #0x10
    assert res.ok, res.errors
    assert any("offset 0x10" in w for w in res.warnings)


def test_tls_descriptor_against_other_code_differs():
    res = _tls_compare((0xD2A00000, 0xF2800200, check.NOP, 0xD503201F + 0x1000))
    assert not res.ok and "local-exec" in res.errors[0]


def test_tls_accesses_must_load_one_offset():
    relaxed = (0xD2A00000, 0xF2800200, check.NOP, check.NOP)
    assert _tls_compare(relaxed * 2, accesses=2).ok
    other = (0xD2A00000, 0xF2800400, check.NOP, check.NOP)  # movk x0, #0x20
    res = _tls_compare(relaxed + other, accesses=2)
    assert not res.ok and "different offsets (0x10, 0x20)" in res.errors[0]
