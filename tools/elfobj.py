"""A minimal reader for the ELF64 little-endian relocatables check.py loads.

pyelftools parses each symbol and relocation entry through `construct`, one
call per entry. check.py read about 10 million relocations that way, and on
a build with protobuf a check of one function took over 6 minutes, 99.8% of
it in that parsing. This reads the section headers, symbol table and RELA
sections with `struct.iter_unpack` instead, and keeps only what check.py
uses: every section's header, the contents and relocations of the sections
loaded at run time (SHF_ALLOC: the code and data that code can refer to, not
the debug info, which holds most of an object's relocations) and the symbols.

Only what relocatable objects use is handled: no program headers, no REL
(only RELA), no big-endian or 32-bit ELF.
"""
from __future__ import annotations

import struct
from dataclasses import dataclass, field

SHT_NAMES = {0: "SHT_NULL", 1: "SHT_PROGBITS", 2: "SHT_SYMTAB", 3: "SHT_STRTAB", 4: "SHT_RELA",
             5: "SHT_HASH", 6: "SHT_DYNAMIC", 7: "SHT_NOTE", 8: "SHT_NOBITS", 9: "SHT_REL",
             11: "SHT_DYNSYM", 14: "SHT_INIT_ARRAY", 15: "SHT_FINI_ARRAY", 16: "SHT_PREINIT_ARRAY",
             17: "SHT_GROUP", 18: "SHT_SYMTAB_SHNDX"}
STT_NAMES = {0: "STT_NOTYPE", 1: "STT_OBJECT", 2: "STT_FUNC", 3: "STT_SECTION", 4: "STT_FILE",
             5: "STT_COMMON", 6: "STT_TLS", 10: "STT_GNU_IFUNC"}
STB_NAMES = {0: "STB_LOCAL", 1: "STB_GLOBAL", 2: "STB_WEAK", 10: "STB_GNU_UNIQUE"}
SHN_UNDEF, SHN_LORESERVE, SHN_ABS, SHN_COMMON, SHN_XINDEX = 0, 0xFF00, 0xFFF1, 0xFFF2, 0xFFFF
SHN_NAMES = {SHN_UNDEF: "SHN_UNDEF", SHN_ABS: "SHN_ABS", SHN_COMMON: "SHN_COMMON"}
SHF_ALLOC = 0x2

_EHDR = struct.Struct("<16sHHIQQQIHHHHHH")
_SHDR = struct.Struct("<IIQQQQIIQQ")
_SYM = struct.Struct("<IBBHQQ")
_RELA = struct.Struct("<QQq")


class ElfError(ValueError):
    pass


@dataclass(slots=True)
class Section:
    index: int
    name: str
    type: str          # SHT_* name (or the number, for a type not in SHT_NAMES)
    flags: int
    size: int
    link: int
    info: int
    entsize: int
    contents: bytes = b""  # empty unless SHF_ALLOC (and not SHT_NOBITS)

    def data(self) -> bytes:
        return self.contents


@dataclass(slots=True)
class Symbol:
    name: str
    bind: str          # STB_* name
    type: str          # STT_* name
    shndx: int | str   # section index, or "SHN_UNDEF" / "SHN_ABS" / "SHN_COMMON"
    value: int
    size: int


@dataclass(slots=True)
class ObjFile:
    sections: list[Section]
    symbols: list[Symbol]
    # section index -> its RELA entries (offset, type, symbol index, addend),
    # only for sections that have any
    relocations: dict[int, list[tuple[int, int, int, int]]] = field(default_factory=dict)

    def get_section(self, index: int) -> Section:
        return self.sections[index]

    def section_by_name(self, name: str) -> Section | None:
        return next((s for s in self.sections if s.name == name), None)


def _cstr(blob: bytes, off: int) -> str:
    end = blob.find(b"\0", off)
    return blob[off:end if end >= 0 else len(blob)].decode("utf-8", "replace")


def _allocated(sec: Section) -> bool:
    return bool(sec.flags & SHF_ALLOC)


def parse(buf: bytes, keep_contents=_allocated, keep_relocations=_allocated) -> ObjFile:
    """Parse an ELF64 little-endian relocatable. `keep_contents(section)` says
    whose contents to keep, `keep_relocations(section)` whose relocations
    (default for both: the SHF_ALLOC sections)."""
    if buf[:4] != b"\x7fELF" or len(buf) < _EHDR.size:
        raise ElfError("not an ELF file")
    if buf[4] != 2 or buf[5] != 1:
        raise ElfError("not a 64-bit little-endian ELF file")
    (_, _, _, _, _, _, shoff, _, _, _, _, shentsize, shnum, shstrndx) = _EHDR.unpack_from(buf)
    if shoff == 0:
        return ObjFile([], [])
    if shentsize != _SHDR.size:
        raise ElfError(f"unexpected section header size {shentsize}")
    first = _SHDR.unpack_from(buf, shoff)
    if shnum == 0:  # more than SHN_LORESERVE sections: the count is in section 0
        shnum = first[5]
    if shstrndx == SHN_XINDEX:
        shstrndx = first[6]
    hdrs = [_SHDR.unpack_from(buf, shoff + i * _SHDR.size) for i in range(shnum)]

    def raw(h) -> bytes:
        return b"" if h[1] == 8 else buf[h[4]:h[4] + h[5]]  # SHT_NOBITS has no file contents

    shstr = raw(hdrs[shstrndx]) if shstrndx < shnum else b""
    sections = []
    for i, (name, typ, flags, _, _, size, link, info, _, entsize) in enumerate(hdrs):
        sec = Section(i, _cstr(shstr, name), SHT_NAMES.get(typ, typ), flags, size, link, info, entsize)
        if typ != 8 and keep_contents(sec):
            sec.contents = raw(hdrs[i])
        sections.append(sec)

    symbols: list[Symbol] = []
    symtab_index = next((i for i, h in enumerate(hdrs) if h[1] == 2), None)
    if symtab_index is not None:
        h = hdrs[symtab_index]
        strtab = raw(hdrs[h[6]]) if h[6] < shnum else b""
        xindex = next((raw(x) for x in hdrs if x[1] == 18 and x[6] == symtab_index), b"")
        names: dict[int, str] = {}
        for k, (name, info, _, shndx, value, size) in enumerate(_SYM.iter_unpack(raw(h)[:h[5] - h[5] % _SYM.size])):
            if shndx == SHN_XINDEX and xindex:
                shndx = struct.unpack_from("<I", xindex, 4 * k)[0]
            elif shndx in SHN_NAMES or SHN_LORESERVE <= shndx:
                shndx = SHN_NAMES.get(shndx, f"SHN_{shndx:#x}")
            if name not in names:
                names[name] = _cstr(strtab, name)
            symbols.append(Symbol(names[name], STB_NAMES.get(info >> 4, info >> 4),
                                  STT_NAMES.get(info & 0xF, info & 0xF), shndx, value, size))

    relocations: dict[int, list[tuple[int, int, int, int]]] = {}
    for h in hdrs:
        if h[1] != 4 or not keep_relocations(sections[h[7]]):  # SHT_RELA
            continue
        data = raw(h)
        relocations.setdefault(h[7], []).extend(
            (off, info & 0xFFFFFFFF, info >> 32, addend)
            for off, info, addend in _RELA.iter_unpack(data[:len(data) - len(data) % _RELA.size]))
    return ObjFile(sections, symbols, relocations)
