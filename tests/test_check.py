"""check.py pieces that need no game files: symbol naming, the absent list and TLS relaxation."""
from __future__ import annotations

import struct
from pathlib import Path

import check
import elfobj


def FakeSymbol(name: str, bind: str, typ: str = "STT_FUNC") -> elfobj.Symbol:
    return elfobj.Symbol(name, bind, typ, 1, 0, 0)


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


def test_base_structor():
    assert check.base_structor("_ZN11Unk_23f4760D1Ev") == "_ZN11Unk_23f4760D2Ev"
    assert check.base_structor("_ZN3FooIiEC1Ei") is None                 # a template: not read
    assert check.base_structor("_ZN3Foo2C1C1ENS_2C1E") == "_ZN3Foo2C1C2ENS_2C1E"  # a class named C1
    assert check.base_structor("_ZN11Unk_23f4760D2Ev") is None
    assert check.base_structor("_ZN11Unk_23f4760D0Ev") is None
    assert check.base_structor("_ZThn72_N11Unk_23f4760D1Ev") is None  # a thunk: its name has no D2 variant


# --- placeholder vtables: `_ZTV<n>Unk_<hex>` is at BASE + hex in Sword ---

def test_placeholder_vtable():
    pv = check.placeholder_vtable
    assert pv("_ZTV11Unk_23f43c8", "sword", 0x1000000, 0x3000000) == 0x23f43c8
    assert pv("_ZTV11Unk_23f43c8", "shield", 0x1000000, 0x3000000) is None    # named after Sword's
    assert pv("_ZTV10Unk_65d680", "sword", 0x1000000, 0x3000000) is None      # a function's address
    assert pv("_ZTV11Unk_23f43c8", "sword", 0x1000000, 0x2000000) is None     # outside the image
    assert pv("_ZTV9Unk_23f43c8", "sword", 0x1000000, 0x3000000) is None      # not one name
    assert pv("_ZTV11Unk_23f43c8_1a8", "sword", 0x1000000, 0x3000000) is None
    assert pv("_ZN11Unk_23f43c8D2Ev", "sword", 0x1000000, 0x3000000) is None


def _got_compare(sym: str, slot_target: int, version: str = "sword"):
    """A function that loads `sym` from the GOT: adrp x8 ; ldr x8, [x8, #8] ; ret,
    the original's GOT slot (0x1008) holding `slot_target`."""
    code = _w(0x90000008, 0xF9400108, 0xD65F03C0)
    relocs = {0: check.Reloc(check.ADR_GOT_PAGE, sym, "STT_OBJECT", "SHN_UNDEF", 0, 0),
              4: check.Reloc(check.LD64_GOT_LO12_NC, sym, "STT_OBJECT", "SHN_UNDEF", 0, 0)}
    cf = check.CompiledFunc("f", Path("a.o"), code, relocs, None, "a.cpp")
    img = bytes(0x100) + _w(0xB0000008, 0xF9400508, 0xD65F03C0) + bytes(0x3000)
    fn = check.Function(0x100, 0x100, len(code), len(code), "common", name="f")
    dyn = type("D", (), {"slots": {0x1008: slot_target}, "plt_by_name": {}})()
    orig = type("O", (), {"version": version, "img": img, "text_end": 0x800, "dyn": dyn})()
    return check.compare(cf, fn, orig, ({}, {version: {}}, {version: {}}), str)


def test_unrecorded_placeholder_vtable_is_checked_by_its_name_in_sword():
    res = _got_compare("_ZTV8Unk_2000", 0x2000)
    assert res.ok, res.errors
    assert res.unknown == [("_ZTV8Unk_2000", 0x2000)]  # --record-data still records it
    res = _got_compare("_ZTV8Unk_2000", 0x2100)        # another class's vtable
    assert not res.ok and "_ZTV8Unk_2000" in res.errors[0]


def test_unrecorded_placeholder_vtable_is_unknown_in_shield_and_in_code():
    res = _got_compare("_ZTV8Unk_2000", 0x2100, "shield")
    assert res.ok and res.unknown == [("_ZTV8Unk_2000", 0x2100)]
    res = _got_compare("_ZTV7Unk_400", 0x2100)        # named after a function
    assert res.ok and res.unknown == [("_ZTV7Unk_400", 0x2100)]


def test_data_symbol_rows():
    seen = {
        "_ZZ3FoovE1x": {"sword": {0x2000}, "shield": {0x2010}},
        "Unk_3000": {"sword": {0x3000, 0x3008}, "shield": {0x3000}},     # two addresses: a conflict
        "_Z3Barv": {"sword": {0x1000}},                                  # a function start
        ".rodata": {"sword": {0x4000}},                                  # a section, not a symbol
    }
    rows, conflicts, funcs = check.data_symbol_rows(seen, {"sword": {0x1000}, "shield": set()})
    assert rows == {"_ZZ3FoovE1x": {"sword": 0x2000, "shield": 0x2010}}
    assert conflicts == ["Unk_3000"] and funcs == ["_Z3Barv"]


def test_record_data_symbols(tmp_path):
    path = tmp_path / "data_symbols.csv"
    path.write_text("Sword,Shield,Size,Name\n0x7100003000,0x7100003000,8,Unk_3000\n", encoding="utf-8")
    n = check.record_data_symbols(path, {"Unk_3000": {"sword": 0x3000}, "a": {"sword": 0x2000, "shield": 0x2010},
                                         "b": {"shield": 0x4000}})
    assert n == 2
    assert path.read_bytes() == (b"Sword,Shield,Size,Name\n0x7100002000,0x7100002010,,a\n"
                                 b"0x7100003000,0x7100003000,8,Unk_3000\n,0x7100004000,,b\n")


def test_stale_rows():
    from common import Function

    def row(name, status):
        return Function(sword=0x100, shield=0x100, sword_size=4, shield_size=4, scope="common", status=status, name=name)

    funcs = [row("_Z1av", "O"), row("_Z1bv", "O"), row("_Z1cv", "U"), row("", "O")]
    assert [f.name for f in check.stale_rows(funcs, {"_Z1av"})] == ["_Z1bv"]
