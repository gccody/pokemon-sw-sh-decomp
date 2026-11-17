"""tools/elfobj.py: the ELF64 relocatable reader check.py loads objects with.

Objects are written by hand: test_check_duplicates.make_object, and a small
section-list writer here for what make_object doesn't make."""
from __future__ import annotations

import struct

import pytest
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
from elftools.elf.sections import SymbolTableSection

import elfobj
from test_check_duplicates import Func, make_object

SHT_PROGBITS, SHT_SYMTAB, SHT_STRTAB, SHT_RELA, SHT_SYMTAB_SHNDX = 1, 2, 3, 4, 18
SHF_ALLOC, SHF_EXECINSTR = 0x2, 0x4


def write_elf(sections: list[tuple], symbols: list[tuple] = ()) -> bytes:
    """An ELF64 LE relocatable. sections: (name, type, flags, data, link, info, entsize);
    a ".symtab" (index len(sections) + 1) and ".strtab" are appended for `symbols`:
    (name, info, shndx, value, size)."""
    strtab = bytearray(b"\0")
    syms = [bytes(24)]
    for name, info, shndx, value, size in symbols:
        syms.append(struct.pack("<IBBHQQ", len(strtab), info, 0, shndx, value, size))
        strtab += name.encode() + b"\0"
    n = len(sections) + 1
    secs = [("", 0, 0, b"", 0, 0, 0), *sections,
            (".symtab", SHT_SYMTAB, 0, b"".join(syms), n + 1, 1, 24), (".strtab", SHT_STRTAB, 0, bytes(strtab), 0, 0, 0)]
    shstr = bytearray(b"\0")
    names = []
    for s in [*secs, (".shstrtab",)]:
        names.append(len(shstr) if s[0] else 0)
        shstr += s[0].encode() + b"\0" if s[0] else b""
    secs.append((".shstrtab", SHT_STRTAB, 0, bytes(shstr), 0, 0, 0))
    body = bytearray(64)
    offsets = []
    for s in secs:
        body += bytes(-len(body) % 8)
        offsets.append(len(body))
        body += s[3]
    body += bytes(-len(body) % 8)
    shoff = len(body)
    for (_, typ, flags, data, link, info, entsize), name_off, off in zip(secs, names, offsets):
        body += struct.pack("<IIQQQQIIQQ", name_off, typ, flags, 0, off, len(data), link, info, 8, entsize)
    body[:64] = (b"\x7fELF" + bytes([2, 1, 1]) + bytes(9)
                 + struct.pack("<HHIQQQIHHHHHH", 1, 183, 1, 0, 0, shoff, 0, 64, 0, 0, 64, len(secs), len(secs) - 1))
    return bytes(body)


def _pyelftools_view(buf: bytes, path):
    path.write_bytes(buf)
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        symtab = next(s for s in elf.iter_sections() if isinstance(s, SymbolTableSection))
        syms = [(s.name, s["st_info"]["bind"], s["st_info"]["type"], s["st_shndx"], s["st_value"], s["st_size"])
                for s in symtab.iter_symbols()]
        secs = [(s.name, s["sh_type"], s["sh_flags"], s["sh_entsize"]) for s in elf.iter_sections()]
        rels = {s["sh_info"]: [(r["r_offset"], r["r_info_type"], r["r_info_sym"], r["r_addend"])
                               for r in s.iter_relocations()]
                for s in elf.iter_sections() if isinstance(s, RelocationSection)}
    return syms, secs, rels


def test_matches_pyelftools(tmp_path):
    buf = make_object([Func("_Z1gv", bind="weak", comdat=True, string=b"hi"), Func("f@a", bind="local"),
                       Func("h", string=b"there")])
    syms, secs, rels = _pyelftools_view(buf, tmp_path / "a.o")
    elf = elfobj.parse(buf)
    assert [(s.name, s.bind, s.type, s.shndx, s.value, s.size) for s in elf.symbols] == syms
    assert [(s.name, s.type, s.flags, s.entsize) for s in elf.sections] == secs
    assert elf.relocations == rels and rels
    assert all(s.data() == b"" for s in elf.sections if not s.flags & SHF_ALLOC)
    text = elf.get_section(elf.symbols[-1].shndx)
    assert text.name == ".text.h" and text.data()[:4] == struct.pack("<I", 0xD65F03C0)


def test_keeps_only_loaded_sections_contents_and_relocations():
    rela = struct.pack("<QQq", 0, (1 << 32) | 257, 0)
    buf = write_elf([(".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR, b"\x01\x02\x03\x04", 0, 0, 0),
                     (".debug_info", SHT_PROGBITS, 0, b"debug", 0, 0, 0),
                     (".rela.text", SHT_RELA, 0, rela, 5, 1, 24),
                     (".rela.debug_info", SHT_RELA, 0, rela * 3, 5, 2, 24)],
                    [("f", 0x12, 1, 0, 4)])
    elf = elfobj.parse(buf)
    assert elf.get_section(1).data() == b"\x01\x02\x03\x04"
    assert elf.get_section(2).data() == b"" and elf.get_section(2).size == 5
    assert elf.relocations == {1: [(0, 257, 1, 0)]}
    everything = elfobj.parse(buf, keep_contents=lambda s: True, keep_relocations=lambda s: True)
    assert everything.get_section(2).data() == b"debug" and len(everything.relocations[2]) == 3


def test_extended_section_index_of_a_symbol():
    # a symbol in a section past SHN_LORESERVE says SHN_XINDEX and has its
    # index in the SHT_SYMTAB_SHNDX section; reserved indices get their names
    shndx = struct.pack("<4I", 0, 1, 0, 0)
    buf = write_elf([(".text", SHT_PROGBITS, SHF_ALLOC, b"\0" * 4, 0, 0, 0),
                     (".symtab_shndx", SHT_SYMTAB_SHNDX, 0, shndx, 3, 0, 4)],
                    [("big", 0x12, 0xFFFF, 0, 4), ("abs", 0x10, 0xFFF1, 5, 0), ("undef", 0x10, 0, 0, 0)])
    assert [s.shndx for s in elfobj.parse(buf).symbols] == ["SHN_UNDEF", 1, "SHN_ABS", "SHN_UNDEF"]


@pytest.mark.parametrize("buf", [b"", b"not an elf file at all" * 4, b"\x7fELF" + bytes([1, 1, 1]) + bytes(60)])
def test_rejects_what_it_cant_read(buf):
    with pytest.raises(elfobj.ElfError):
        elfobj.parse(buf)

