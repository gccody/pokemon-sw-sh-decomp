"""tools/fix_traps.py: `brk #1` -> 0xe7ffdefe in the code of AArch64 objects, nothing else.

The objects are built by hand (minimal ELF64 relocatables), so no compiler or
game files are needed.
"""
from __future__ import annotations

import struct
import sys

import pytest

import check
import fix_traps

BRK_1, NX_TRAP = 0xD4200020, 0xE7FFDEFE
BRK_F000 = 0xD43E0000  # brk #0xf000 (llvm.debugtrap in later LLVM)
RET, NOP = 0xD65F03C0, 0xD503201F
SHF_ALLOC, SHF_EXECINSTR = 0x2, 0x4


def words(*ws: int) -> bytes:
    return b"".join(struct.pack("<I", w) for w in ws)


def make_object(sections: list[dict], *, machine: int = 183, e_type: int = 1,
                elf_class: int = 2) -> bytes:
    """An ELF64 relocatable with the given sections, a .symtab, .strtab and .shstrtab.

    Each section: {"name", "data", "flags", ["type"], ["symbols": [(name, offset)]],
    ["relocs": [offset, ...]]}. Relocations become a .rela<name> section."""
    shstr, strtab = bytearray(b"\0"), bytearray(b"\0")

    def add(tab: bytearray, s: str) -> int:
        off = len(tab)
        tab += s.encode() + b"\0"
        return off

    secs = [{"name": 0, "type": 0, "flags": 0, "data": b"", "link": 0, "info": 0, "entsize": 0}]
    symbols = [bytes(24)]
    for s in sections:
        idx = len(secs)
        secs.append({"name": add(shstr, s["name"]), "type": s.get("type", 1), "flags": s["flags"],
                     "data": s["data"], "link": 0, "info": 0, "entsize": 0})
        for name, value in s.get("symbols", []):
            symbols.append(struct.pack("<IBBHQQ", add(strtab, name), 0, 0, idx, value, 0))
        s["_idx"] = idx
    symtab_idx = len(secs)
    strtab_idx = symtab_idx + 1
    secs.append({"name": add(shstr, ".symtab"), "type": 2, "flags": 0, "data": b"".join(symbols),
                 "link": strtab_idx, "info": len(symbols), "entsize": 24})
    secs.append({"name": add(shstr, ".strtab"), "type": 3, "flags": 0, "data": bytes(strtab),
                 "link": 0, "info": 0, "entsize": 0})
    for s in sections:
        if s.get("relocs"):
            rela = b"".join(struct.pack("<QQq", off, (1 << 32) | 283, 0) for off in s["relocs"])
            secs.append({"name": add(shstr, ".rela" + s["name"]), "type": 4, "flags": 0, "data": rela,
                         "link": symtab_idx, "info": s["_idx"], "entsize": 24})
    shstrndx = len(secs)
    secs.append({"name": add(shstr, ".shstrtab"), "type": 3, "flags": 0, "data": bytes(shstr),
                 "link": 0, "info": 0, "entsize": 0})

    body = bytearray(64)
    offsets = []
    for s in secs:
        while len(body) % 8:
            body += b"\0"
        offsets.append(len(body))
        body += s["data"]
    while len(body) % 8:
        body += b"\0"
    shoff = len(body)
    for s, off in zip(secs, offsets):
        body += struct.pack("<IIQQQQIIQQ", s["name"], s["type"], s["flags"], 0, off if s["data"] else 0,
                            len(s["data"]), s["link"], s["info"], 4, s["entsize"])
    ident = b"\x7fELF" + bytes([elf_class, 1, 1]) + bytes(9)
    struct.pack_into("<16sHHIQQQIHHHHHH", body, 0, ident, e_type, machine, 1, 0, 0, shoff, 0, 64, 0, 0,
                     64, len(secs), shstrndx)
    return bytes(body)


def code(name: str, *ws: int, **kw) -> dict:
    return {"name": name, "data": words(*ws), "flags": SHF_ALLOC | SHF_EXECINSTR,
            "symbols": kw.pop("symbols", [("$x.0", 0)]), **kw}


def text_words(obj: bytes, index: int) -> list[int]:
    sec = fix_traps._sections(obj)[index]
    return list(struct.unpack_from(f"<{sec['size'] // 4}I", obj, sec["offset"]))


def test_rewrites_code_traps_only():
    obj = make_object([
        code(".text._ZN1AD0Ev", BRK_1),                       # abstract class D0: a lone trap
        code(".text._Z2swi", NOP, RET, BRK_1, BRK_F000),      # trap after the switch; other brk kept
        {"name": ".rodata", "data": words(BRK_1, BRK_1), "flags": SHF_ALLOC},  # data: untouched
    ])
    new, n = fix_traps.rewrite(obj)
    assert n == 2
    assert text_words(new, 1) == [NX_TRAP]
    assert text_words(new, 2) == [NOP, RET, NX_TRAP, BRK_F000]
    assert text_words(new, 3) == [BRK_1, BRK_1]
    assert len(new) == len(obj)
    # only the two words changed
    assert sum(a != b for a, b in zip(obj, new)) <= 8


def test_idempotent():
    obj = make_object([code(".text.f", BRK_1, RET)])
    once, n1 = fix_traps.rewrite(obj)
    twice, n2 = fix_traps.rewrite(once)
    assert (n1, n2) == (1, 0)
    assert twice == once


def test_data_mapping_symbol_in_code_section():
    # $d marks a literal pool / data inside the code section: keep it
    obj = make_object([code(".text.f", BRK_1, RET, BRK_1, BRK_1, BRK_1,
                            symbols=[("$x.0", 0), ("$d.1", 8), ("$x.2", 12)])])
    new, n = fix_traps.rewrite(obj)
    assert n == 3
    assert text_words(new, 1) == [NX_TRAP, RET, BRK_1, NX_TRAP, NX_TRAP]


def test_section_without_mapping_symbols_is_code():
    obj = make_object([code(".text.f", RET, BRK_1, symbols=[])])
    assert fix_traps.rewrite(obj)[1] == 1


def test_relocated_word_is_not_touched():
    # a word with a relocation is an address-carrying instruction or data, never a plain trap
    obj = make_object([code(".text.f", BRK_1, BRK_1, relocs=[4])])
    new, n = fix_traps.rewrite(obj)
    assert n == 1
    assert text_words(new, 1) == [NX_TRAP, BRK_1]


def test_non_executable_section_is_not_touched():
    obj = make_object([{"name": ".data", "data": words(BRK_1), "flags": SHF_ALLOC, "symbols": [("$x.0", 0)]}])
    assert fix_traps.rewrite(obj) == (obj, 0)


@pytest.mark.parametrize("kw", [{"machine": 62}, {"e_type": 2}, {"elf_class": 1}])
def test_rejects_other_files(kw):
    with pytest.raises(fix_traps.NotAnObject):
        fix_traps.rewrite(make_object([code(".text.f", BRK_1)], **kw))
    with pytest.raises(fix_traps.NotAnObject):
        fix_traps.rewrite(b"!<arch>\n")


def test_rewrite_file_and_check(tmp_path, capsys):
    p = tmp_path / "a.o"
    p.write_bytes(make_object([code(".text.f", BRK_1, RET)]))
    assert fix_traps.main(["--check", str(p)]) == 1
    assert fix_traps.main([str(p)]) == 0
    assert fix_traps.main(["--check", str(p)]) == 0
    assert text_words(p.read_bytes(), 1) == [NX_TRAP, RET]
    assert not list(tmp_path.glob("*.tmp"))


@pytest.mark.parametrize("cmd, out", [
    (["clang", "-c", "a.c", "-o", "x/a.o"], "x/a.o"),
    (["clang", "-ox/a.o", "-c", "a.c"], "x/a.o"),
    (["clang", "--output=a.o", "-c", "a.c"], "a.o"),
    (["clang", "-objcmt-migrate-all", "-c", "a.c"], None),
    (["clang", "-c", "a.c"], None),
])
def test_output_of(cmd, out):
    assert fix_traps.output_of(cmd) == out


def test_run_compiles_then_rewrites(tmp_path):
    # the "compiler" is Python writing an object with a trap to the -o path
    obj = make_object([code(".text.f", BRK_1)])
    src = tmp_path / "obj.bin"
    src.write_bytes(obj)
    out = tmp_path / "a.o"
    fake_cc = [sys.executable, "-c", f"import shutil,sys; shutil.copy({str(src)!r}, sys.argv[-1])"]
    assert fix_traps.main(["--run", "--", *fake_cc, "-c", "-o", str(out)]) == 0
    assert text_words(out.read_bytes(), 1) == [NX_TRAP]


def test_run_passes_compiler_failure_through(tmp_path):
    fail = [sys.executable, "-c", "import sys; sys.exit(3)"]
    assert fix_traps.main(["--run", "--", *fail, "-c", "-o", str(tmp_path / "a.o")]) == 3
    assert fix_traps.main(["--run", "--", str(tmp_path / "no-such-compiler"), "-c", "a.c"]) == 127


def test_run_ignores_non_object_outputs(tmp_path):
    out = tmp_path / "a.s"
    write = [sys.executable, "-c", "import sys; open(sys.argv[-1], 'w').write('x')"]
    assert fix_traps.main(["--run", "--", *write, "-S", "-c", "-o", str(out)]) == 0
    assert fix_traps.main(["--run", "--", *write, "-o", str(out)]) == 0  # not ELF: left alone
    elf = make_object([code(".text.f", BRK_1)], machine=62)
    src = tmp_path / "x86.bin"
    src.write_bytes(elf)
    copy = [sys.executable, "-c", f"import shutil,sys; shutil.copy({str(src)!r}, sys.argv[-1])"]
    assert fix_traps.main(["--run", "--", *copy, "-o", str(tmp_path / "b.o")]) == 1  # ELF, wrong machine


def test_check_py_requires_trap_rewrite(tmp_path):
    d = tmp_path / "shield"
    d.mkdir()
    (d / "CMakeCache.txt").write_text("PKMN_GAME:STRING=shield\n", encoding="utf-8")
    assert "doesn't rewrite traps" in check.check_trap_rewrite(d)
    (d / "CMakeCache.txt").write_text("PKMN_TRAP_REWRITE:INTERNAL=/repo/tools/fix_traps.py\n", encoding="utf-8")
    assert check.check_trap_rewrite(d) is None


def test_check_py_uses_the_same_words():
    assert (check.BRK_1, check.NX_TRAP) == (fix_traps.BRK_1, fix_traps.NX_TRAP) == (BRK_1, NX_TRAP)


def test_call_exit_codes_and_missing_program(tmp_path):
    assert fix_traps.call([sys.executable, "-c", "import sys; sys.exit(5)"]) == 5
    assert fix_traps.call([sys.executable, "-c", "pass"]) == 0
    with pytest.raises(OSError):
        fix_traps.call([str(tmp_path / "no-such-compiler")])


def test_run_path_imports_little():
    """--run is the per-object launcher: it mustn't pull in subprocess, argparse or pathlib
    where the OS can spawn directly (Python's start-up is most of its cost)."""
    import subprocess

    code = ("import sys; sys.argv = ['fix_traps.py', '--run', '--', sys.executable, '-c', 'pass']; "
            "import fix_traps; rc = fix_traps.main(); "
            "print(rc, *sorted(m for m in ('subprocess', 'argparse', 'pathlib') if m in sys.modules))")
    out = subprocess.run([sys.executable, "-S", "-c", code], cwd=str(fix_traps.__file__).rsplit("fix_traps.py", 1)[0],
                         capture_output=True, text=True, check=True).stdout.split()
    assert out[0] == "0"
    import os
    if hasattr(os, "posix_spawnp"):
        assert out[1:] == []
