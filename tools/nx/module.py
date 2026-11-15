"""Original-executable views used by the checker: dynamic relocations, GOT and PLT."""
from __future__ import annotations

import struct

from nx.nso import Nso

R_AARCH64_ABS64 = 257
R_AARCH64_GLOB_DAT = 1025
R_AARCH64_JUMP_SLOT = 1026
R_AARCH64_RELATIVE = 1027


class DynInfo:
    """Resolves GOT slots and PLT stubs of an NSO to what they point at."""

    def __init__(self, nso: Nso, img: bytes, text_end: int):
        self.img = img
        tags: dict[int, int] = {}
        d = nso.mod0.dynamic
        while True:
            t, v = struct.unpack_from("<qQ", img, d)
            d += 16
            if t == 0:
                break
            tags[t] = v
        symtab, strtab = tags[6], tags[5]

        def symname(idx: int) -> str:
            nm = struct.unpack_from("<I", img, symtab + idx * 24)[0]
            return img[strtab + nm:img.index(b"\0", strtab + nm)].decode()

        # slot address -> int (absolute target) or str (imported symbol name)
        self.slots: dict[int, int | str] = {}
        for start, size in ((tags.get(7), tags.get(8)), (tags.get(0x17), tags.get(2))):
            if not start:
                continue
            for o in range(start, start + size, 24):
                off, info, addend = struct.unpack_from("<QQq", img, o)
                typ, sym = info & 0xFFFFFFFF, info >> 32
                if typ == R_AARCH64_RELATIVE:
                    self.slots[off] = addend
                elif typ in (R_AARCH64_GLOB_DAT, R_AARCH64_JUMP_SLOT, R_AARCH64_ABS64) and sym:
                    self.slots[off] = symname(sym)

        # PLT stubs: adrp x16, P ; ldr x17, [x16, #o] ; add x16, x16, #o ; br x17
        self.plt: dict[int, str] = {}       # stub address -> import name
        self.plt_by_name: dict[str, int] = {}
        lo = max(0, text_end - 0x40000) & ~3  # PLT sits at the very end of .text
        for pc in range(lo, text_end - 12, 4):
            w0, w1, _, w3 = struct.unpack_from("<4I", img, pc)
            if (w0 & 0x9F00001F) == 0x90000010 and (w1 & 0xFFC003FF) == 0xF9400211 and w3 == 0xD61F0220:
                imm = ((w0 >> 29) & 3) | (((w0 >> 5) & 0x7FFFF) << 2)
                if imm & (1 << 20):
                    imm -= 1 << 21
                slot = (pc & ~0xFFF) + (imm << 12) + ((w1 >> 10) & 0xFFF) * 8
                name = self.slots.get(slot)
                if isinstance(name, str):
                    self.plt[pc] = name
                    self.plt_by_name.setdefault(name, pc)
