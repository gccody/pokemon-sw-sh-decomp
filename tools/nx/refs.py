"""AArch64 helpers: decode PC-relative references so functions can be compared
independent of where code/data happens to land in each game version."""
from __future__ import annotations

import struct

# opcode classes -----------------------------------------------------------
def is_b_bl(w: int) -> bool:
    return (w & 0x7C000000) == 0x14000000


def is_adrp(w: int) -> bool:
    return (w & 0x9F000000) == 0x90000000


def is_adr(w: int) -> bool:
    return (w & 0x9F000000) == 0x10000000


def is_ldr_literal(w: int) -> bool:
    return (w & 0x3B000000) == 0x18000000


def is_add_imm64(w: int) -> bool:
    return (w & 0xFF800000) == 0x91000000  # ADD Xd, Xn, #imm{, lsl #12}


def is_ldst_uimm(w: int) -> bool:
    return (w & 0x3B000000) == 0x39000000  # LDR/STR (immediate, unsigned offset), incl. SIMD


def _sext(v: int, bits: int) -> int:
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def ldst_scale(w: int) -> int:
    size = w >> 30
    if (w >> 26) & 1 and ((w >> 22) & 3) in (2, 3):  # 128-bit SIMD q-reg
        return 4
    return size


def decode(img: bytes, start: int, size: int):
    """Yield (offset, word, masked_word, target_or_None) for each instruction.

    `masked_word` has every address-dependent field zeroed; `target` is the
    absolute address referenced (for B/BL/ADR/ADRP+lo12/LDR literal)."""
    words = struct.unpack_from(f"<{size // 4}I", img, start)
    pages: dict[int, int] = {}
    for i, w in enumerate(words):
        pc = start + i * 4
        tgt = None
        m = w
        if is_b_bl(w):
            tgt = pc + _sext(w & 0x3FFFFFF, 26) * 4
            m = w & 0xFC000000
        elif is_adrp(w):
            imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
            pages[w & 0x1F] = (pc & ~0xFFF) + (_sext(imm, 21) << 12)
            m = w & 0x9F00001F
            # the full target is attributed to the consuming lo12 instruction
        elif is_adr(w):
            imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
            tgt = pc + _sext(imm, 21)
            m = w & 0x9F00001F
        elif is_ldr_literal(w):
            tgt = pc + _sext((w >> 5) & 0x7FFFF, 19) * 4
            m = w & 0xFF00001F
        elif is_add_imm64(w) and ((w >> 5) & 0x1F) in pages:
            rn = (w >> 5) & 0x1F
            imm = (w >> 10) & 0xFFF
            if (w >> 22) & 1:
                imm <<= 12
            tgt = pages[rn] + imm
            m = w & 0xFF8003FF
            if (w & 0x1F) == rn:
                del pages[rn]
        elif is_ldst_uimm(w) and ((w >> 5) & 0x1F) in pages:
            rn = (w >> 5) & 0x1F
            tgt = pages[rn] + ((w >> 10) & 0xFFF) * (1 << ldst_scale(w))
            m = w & 0xFFC003FF
        elif (w & 0x1F) in pages and _writes_rd(w):
            # any other write to a tracked register ends the ADRP pairing.
            # A spurious drop only makes a later lo12 compare raw (-> reported
            # as a difference), never produces a false match.
            del pages[w & 0x1F]
        yield i * 4, w, m, tgt


def _writes_rd(w: int) -> bool:
    if (w & 0x1C000000) == 0x14000000:  # branches, cbz/tbz, b.cond
        return False
    if (w & 0x0A000000) == 0x08000000 and not (w >> 22) & 1:  # stores (single/pair)
        return False
    return True
