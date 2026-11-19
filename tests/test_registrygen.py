"""tools/registrygen.py: finding the instances of the family on hand-encoded
instructions, and what it writes for them (no game files)."""
from __future__ import annotations

import struct

import registrygen as R

NOP = 0xD503201F
RET = 0xD65F03C0
SIZES = {"ctor": 0xDC, "inner_ctor": 0xEC, "vf2": 0x58, "d2": 0x7C, "d0": 0x170, "vf3": 8,
         "vf4": 0xA0, "vf5": 0xBC, "create": 0xE0}


def adrp(rd: int, pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def ldr(rt: int, rn: int, off: int) -> int:
    return 0xF9400000 | ((off // 8) << 10) | (rn << 5) | rt


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def test_masked_keeps_only_what_instances_share():
    a = struct.pack("<5I", adrp(8, 0x1000, 0x80510), ldr(8, 8, 0x510), bl(0x1008, 0x5000),
                    ldr(9, 0, 0x58), 0x91004108)          # add x8, x8, #0x10 (x8 was the GOT load's)
    b = struct.pack("<5I", adrp(8, 0x2000, 0x93960), ldr(8, 8, 0x960), bl(0x2008, 0x7000),
                    ldr(9, 0, 0x58), 0x91004108)
    assert R.masked(a) == R.masked(b)
    # a field load from another register keeps its offset
    c = struct.pack("<5I", adrp(8, 0x2000, 0x93960), ldr(8, 8, 0x960), bl(0x2008, 0x7000),
                    ldr(9, 0, 0x60), 0x91004108)
    assert R.masked(a) != R.masked(c)


def test_branch_target_and_got_slot():
    img = struct.pack("<3I", bl(0, 0x400), adrp(8, 4, 0x80518), ldr(8, 8, 0x518))
    assert R.branch_target(img, 0) == 0x400
    assert R.got_slot(img, 4) == 0x80518
    assert R.got_slot(img, 0) is None


class Image:
    """Functions at fixed addresses, NOPs but for what find_instances reads."""

    def __init__(self):
        self.words: dict[int, int] = {}
        self.funcs: list[tuple[int, int]] = []
        self.slots: dict[int, int] = {}

    def func(self, at: int, role: str) -> int:
        for k in range(0, SIZES[role] - 4, 4):
            self.words.setdefault(at + k, NOP)
        self.words[at + SIZES[role] - 4] = RET
        self.funcs.append((at, SIZES[role]))
        return at

    def got(self, pc: int, rd: int, slot: int, value: int) -> None:
        self.words[pc] = adrp(rd, pc, slot)
        self.words[pc + 4] = ldr(rd, rd, slot & 0xFFF)
        self.slots[slot] = value

    def instance(self, base: int, got: int, outer: int, inner: int, instance: int) -> dict[str, int]:
        a = {r: self.func(base + 0x200 * k, r) for k, r in enumerate(SIZES)}
        self.got(a["ctor"] + R.OUTER_ZTV, 8, got, outer)
        self.words[a["ctor"] + R.INNER_CTOR_CALL] = bl(a["ctor"] + R.INNER_CTOR_CALL, a["inner_ctor"])
        self.got(a["inner_ctor"] + R.INNER_ZTV, 8, got + 8, inner)
        self.got(a["inner_ctor"] + R.INSTANCE_GOT, 8, got + 16, instance)
        self.words[a["vf2"] + R.CREATE_CALL] = bl(a["vf2"] + R.CREATE_CALL, a["create"])
        for k, r in enumerate(R.OUTER_SLOTS):
            self.slots[outer + 0x10 + 8 * k] = a[r]
        return a

    def image(self) -> bytes:
        top = max(self.words) + 4
        return b"".join(struct.pack("<I", self.words.get(k, 0)) for k in range(0, top, 4))


def test_find_instances_reads_each_from_its_code():
    im = Image()
    first = im.instance(0x1000, 0x80000, 0x23AA2C8, 0x23AA308, 0x27CEA98)
    second = im.instance(0x4000, 0x81000, 0x23AA338, 0x23AA378, 0x27CEAB0)
    im.func(0x7000, "ctor")      # a constructor's shape, but nothing it reads is an instance's
    found = R.find_instances(im.image(), sorted(im.funcs), im.slots, first=first["ctor"])
    assert [(x.outer, x.inner, x.instance) for x in found] == [
        (0x23AA2C8, 0x23AA308, 0x27CEA98), (0x23AA338, 0x23AA378, 0x27CEAB0)]
    assert found[1].addr("create") == second["create"]
    assert found[1].addr("d0") == second["d0"]


def instance() -> R.Instance:
    funcs = (("ctor", 0x7BE640), ("inner_ctor", 0x7BE720), ("d2", 0x7BE810), ("d0", 0x7BE890),
             ("vf2", 0x7BEA00), ("vf4", 0x7BEA70), ("vf5", 0x7BEB10), ("create", 0x7BEC20))
    return R.Instance(0x23AA2C8, 0x23AA308, 0x27CEA98, funcs)


def test_mangled_names():
    names = R.mangled(instance())
    assert names["ctor"] == "_ZN11Unk_23aa2c8C2Ev"
    assert names["inner_ctor"] == "_ZN11Unk_23aa308C2Ev"
    assert names["d0"] == "_ZN11Unk_23aa2c8D0Ev"
    assert names["vf2"] == "_ZN11Unk_23aa2c83vf2Em"
    assert names["create"] == "_Z10Unk_7bec20P16Unk_7be640_EntryRKjmP16Unk_239f910_Base"
    big = R.Instance(0x2447148, 0x2447188, 0x27D1000, (("create", 0x1510160),))
    assert R.mangled(big)["create"].startswith("_Z11Unk_1510160P16")
    assert dict(R.expected_slot_names(instance()))["inner_vf1"] == "_ZN11Unk_23aa3083vf1Em"


def test_render_names_both_games_addresses():
    x = instance()
    shield = {0x7BE640: 0x7BE670}
    h = R.render_header(x, shield)
    assert "extern Unk_23aa308* Unk_27cea98;" in h
    assert "class Unk_23aa2c8 : public Unk_23daca0 {" in h
    assert "Unk_7bea70_Body(Unk_27cea98, m_entry)" in h
    src = R.render_source(x, shield)
    assert "// 0x71007be640 (Shield 0x71007be670)\nUnk_23aa2c8::Unk_23aa2c8() {}" in src
    assert "return Unk_7bec20(&m_entry, kind, size, field_8);" in src
    ctors = R.render_ctors([x], shield)
    assert '#include "unsorted/registry/Unk_23aa2c8.h"' in ctors
    assert "Unk_23aa308::Unk_23aa308() : m_entries() {\n    Unk_27cea98 = this;\n}\n" in ctors
