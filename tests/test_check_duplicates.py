"""check.py: a symbol defined by several translation units (weak / COMDAT
definitions such as inline functions and template instantiations).

The objects are tiny AArch64 ELF relocatables written by hand below."""
from __future__ import annotations

import json
import struct
from dataclasses import dataclass
from pathlib import Path

import pytest

import check

RET, NOP = struct.pack("<I", 0xD65F03C0), struct.pack("<I", 0xD503201F)
ADRP_X0, ADD_X0 = struct.pack("<I", 0x90000000), struct.pack("<I", 0x91000000)
STB = {"local": 0, "global": 1, "weak": 2}
STT_FUNC, STT_SECTION = 2, 3
SHT_PROGBITS, SHT_SYMTAB, SHT_STRTAB, SHT_RELA, SHT_GROUP = 1, 2, 3, 4, 17
SHF_ALLOC, SHF_EXECINSTR, SHF_MERGE, SHF_STRINGS, SHF_GROUP = 0x2, 0x4, 0x10, 0x20, 0x200


@dataclass
class Func:
    name: str
    code: bytes = RET
    bind: str = "global"
    comdat: bool = False
    # string the function takes the address of (adrp/add pair against a section symbol)
    string: bytes | None = None


@dataclass
class _Sec:
    name: str
    type: int
    flags: int = 0
    data: bytes = b""
    link: int = 0
    info: int = 0
    align: int = 1
    entsize: int = 0


def make_object(funcs: list[Func], strings_prefix: bytes = b"") -> bytes:
    """An ELF64 AArch64 relocatable defining `funcs`, each in its own section."""
    secs = [_Sec("", 0)]
    strtab = bytearray(b"\0")

    def name_off(s: str) -> int:
        strtab.extend(s.encode() + b"\0")
        return len(strtab) - len(s) - 1

    pool = bytearray(strings_prefix)
    str_offsets = {}
    for f in funcs:
        if f.string is not None:
            str_offsets[f.name] = len(pool)
            pool += f.string + b"\0"
    str_idx = None
    if pool:
        str_idx = len(secs)
        secs.append(_Sec(".rodata.str1.1", SHT_PROGBITS, SHF_ALLOC | SHF_MERGE | SHF_STRINGS, bytes(pool), entsize=1))

    # symbols: null, section symbol of the string pool, locals, then globals
    syms = [struct.pack("<IBBHQQ", 0, 0, 0, 0, 0, 0)]
    sec_sym = None
    if str_idx is not None:
        sec_sym = len(syms)
        syms.append(struct.pack("<IBBHQQ", 0, STT_SECTION, 0, str_idx, 0, 0))
    ordered = sorted(funcs, key=lambda f: f.bind != "local")
    n_local = len(syms) + sum(f.bind == "local" for f in funcs)
    groups = []
    rela = []
    for f in ordered:
        idx = len(secs)
        code = f.code + (ADRP_X0 + ADD_X0 if f.string is not None else b"")
        flags = SHF_ALLOC | SHF_EXECINSTR | (SHF_GROUP if f.comdat else 0)
        secs.append(_Sec(f".text.{f.name}", SHT_PROGBITS, flags, code, align=4))
        sym_index = len(syms)
        syms.append(struct.pack("<IBBHQQ", name_off(f.name), (STB[f.bind] << 4) | STT_FUNC, 0, idx, 0, len(code)))
        if f.comdat:
            groups.append((sym_index, idx))
        if f.string is not None:
            off, add = len(f.code), str_offsets[f.name]
            rela.append((idx, struct.pack("<QQq", off, (sec_sym << 32) | check.ADR_PREL_PG_HI21, add)
                         + struct.pack("<QQq", off + 4, (sec_sym << 32) | check.ADD_ABS_LO12_NC, add)))
    symtab_idx = len(secs) + len(groups) + len(rela)
    for sym_index, member in groups:
        secs.append(_Sec(".group", SHT_GROUP, 0, struct.pack("<II", check.GRP_COMDAT, member),
                         link=symtab_idx, info=sym_index, align=4, entsize=4))
    for target, data in rela:
        secs.append(_Sec(f".rela{secs[target].name}", SHT_RELA, 0, data, link=symtab_idx, info=target,
                         align=8, entsize=24))
    assert len(secs) == symtab_idx
    secs.append(_Sec(".symtab", SHT_SYMTAB, 0, b"".join(syms), link=symtab_idx + 1, info=n_local,
                     align=8, entsize=24))
    secs.append(_Sec(".strtab", SHT_STRTAB, 0, b""))
    secs.append(_Sec(".shstrtab", SHT_STRTAB, 0, b""))
    secs[-2].data = bytes(strtab)

    shstr = bytearray(b"\0")
    names = []
    for s in secs:
        if s.name:
            names.append(len(shstr))
            shstr.extend(s.name.encode() + b"\0")
        else:
            names.append(0)
    secs[-1].data = bytes(shstr)

    body = bytearray(b"\0" * 64)
    offsets = []
    for s in secs:
        while len(body) % 8:
            body.append(0)
        offsets.append(len(body))
        body += s.data
    while len(body) % 8:
        body.append(0)
    shoff = len(body)
    for s, name, off in zip(secs, names, offsets):
        body += struct.pack("<IIQQQQIIQQ", name, s.type, s.flags, 0, off if s.type else 0, len(s.data),
                            s.link, s.info, s.align, s.entsize)
    ident = b"\x7fELF" + bytes([2, 1, 1]) + b"\0" * 9
    body[:64] = ident + struct.pack("<HHIQQQIHHHHHH", 1, 183, 1, 0, 0, shoff, 0, 64, 0, 0, 64, len(secs),
                                    len(secs) - 1)
    return bytes(body)


@pytest.fixture
def build_dir(tmp_path):
    """build_dir({"lib/a.cpp": [Func, ...], ...}) -> a build directory with
    compile_commands.json and one object per source (in the given order)."""

    def make(objects: dict[str, list[Func] | bytes]) -> Path:
        d = tmp_path / "build"
        d.mkdir()
        cc = []
        for i, (source, funcs) in enumerate(objects.items()):
            out = f"obj{i}.o"
            (d / out).write_bytes(funcs if isinstance(funcs, bytes) else make_object(funcs))
            cc.append({"directory": str(d), "file": str(tmp_path / source), "output": out})
        (d / "compile_commands.json").write_text(json.dumps(cc))
        return d

    return make


def test_weak_duplicate_identical_is_one_entry(build_dir, capsys):
    d = build_dir({"a.cpp": [Func("_Z6inlinev", bind="weak"), Func("a")],
                   "b.cpp": [Func("_Z6inlinev", bind="weak"), Func("b")]})
    out = check.load_objects(d)
    assert sorted(out) == ["_Z6inlinev", "a", "b"]
    cf = out["_Z6inlinev"]
    assert cf.mergeable and cf.variants == [] and cf.source.endswith("a.cpp")
    assert capsys.readouterr().out == ""


def test_weak_duplicate_differing_is_a_warning_and_both_copies_are_kept(build_dir, capsys):
    d = build_dir({"a.cpp": [Func("_Z6inlinev", RET, bind="weak")],
                   "b.cpp": [Func("_Z6inlinev", NOP + RET, bind="weak")],
                   "c.cpp": [Func("_Z6inlinev", RET, bind="weak")]})
    cf = check.load_objects(d)["_Z6inlinev"]
    assert [c.code for c in cf.copies()] == [RET, NOP + RET]
    assert [Path(c.source).name for c in cf.copies()] == ["a.cpp", "b.cpp"]
    warning = capsys.readouterr().out
    assert warning.count("\n") == 1  # c.cpp is identical to a.cpp
    assert "_Z6inlinev" in warning and "a.cpp" in warning and "b.cpp" in warning


def test_strong_duplicate_is_an_error(build_dir):
    d = build_dir({"a.cpp": [Func("dup")], "b.cpp": [Func("dup")]})
    with pytest.raises(SystemExit, match="dup is defined in both .*two strong definitions"):
        check.load_objects(d)


def test_same_local_name_and_stem_is_an_error(build_dir):
    d = build_dir({"lib/x/util.c": [Func("helper", bind="local")], "lib/y/util.c": [Func("helper", bind="local")]})
    with pytest.raises(SystemExit, match="helper@util is defined in both .*rename one file"):
        check.load_objects(d)


def test_comdat_global_duplicate_is_merged(build_dir, capsys):
    d = build_dir({"a.cpp": [Func("_Z1fv", comdat=True)], "b.cpp": [Func("_Z1fv", comdat=True)]})
    out = check.load_objects(d)
    assert out["_Z1fv"].mergeable and out["_Z1fv"].variants == []
    assert capsys.readouterr().out == ""


@pytest.mark.parametrize("order", [("weak", "global"), ("global", "weak")])
def test_strong_definition_wins_over_weak(build_dir, order):
    code = {"weak": NOP + RET, "global": RET}
    d = build_dir({f"{b}.cpp": [Func("f", code[b], bind=b)] for b in order})
    cf = check.load_objects(d)["f"]
    assert not cf.mergeable and cf.code == RET and cf.variants == []


def test_same_local_name_in_two_files_is_qualified(build_dir):
    d = build_dir({"lib/x/one.c": [Func("helper", bind="local")], "lib/y/two.c": [Func("helper", bind="local")]})
    assert sorted(check.load_objects(d)) == ["helper@one", "helper@two"]


def test_fingerprint_compares_strings_not_their_offsets(build_dir, capsys):
    # The string is at a different offset of the merged-string section in each
    # object, but the code refers to the same string: identical copies.
    a = make_object([Func("_Z1gv", bind="weak", string=b"hello")])
    b = make_object([Func("_Z1gv", bind="weak", string=b"hello")], strings_prefix=b"other\0")
    c = make_object([Func("_Z1gv", bind="weak", string=b"bye")])
    out = check.load_objects(build_dir({"a.cpp": a, "b.cpp": b, "c.cpp": c}))
    assert [Path(c.source).name for c in out["_Z1gv"].copies()] == ["a.cpp", "c.cpp"]
    assert capsys.readouterr().out.count("\n") == 1


def test_merge_results_requires_every_copy_to_match():
    a = check.CompiledFunc("f", Path("a.o"), RET, {}, None, "a.cpp")
    b = check.CompiledFunc("f", Path("b.o"), RET, {}, None, "b.cpp")
    good, bad = check.Result(True), check.Result(False, ["+0x000: instruction differs"], first_bad=0)
    assert check.merge_results([(a, good)]) is good
    merged = check.merge_results([(a, good), (b, bad)])
    assert not merged.ok and merged.first_bad == 0
    assert merged.errors == ["[copy from b.cpp] +0x000: instruction differs"]
    assert check.merge_results([(a, good), (b, check.Result(True))]).ok


def test_alias_groups():
    # clang emits D1 as an alias of D2 (same section, value and size)
    syms = [("_ZN1AD2Ev", 3, 0, 4), ("_ZN1AD1Ev", 3, 0, 4), ("_ZN1AD0Ev", 4, 0, 4),
            ("other", 5, 0, 8), ("same_place_other_size", 5, 0, 4)]
    assert check.alias_groups(syms) == {"_ZN1AD2Ev": ("_ZN1AD1Ev",), "_ZN1AD1Ev": ("_ZN1AD2Ev",)}
