"""nx.refs.decode masks out address-dependent fields so the same code at
different addresses compares equal. check.py and versiondiff.py rely on it."""
from __future__ import annotations

import struct

from nx.refs import decode

RET = 0xD65F03C0


def run(words: list[int], start: int = 0x1000):
    img = b"\0" * start + struct.pack(f"<{len(words)}I", *words)
    return list(decode(img, start, len(words) * 4))


def test_bl_target_and_mask():
    bl, ret = run([0x94000040, RET])  # bl +0x100
    assert bl[3] == 0x1100
    assert bl[2] == 0x94000000
    assert ret[2] == RET
    assert ret[3] is None


def test_backward_branch():
    _, b = run([RET, 0x17FFFFFF])  # b -4
    assert b[3] == 0x1000


def test_adrp_pairs_with_add_and_ldr():
    adrp, add, ldr, _ = run([
        0xB0000008,  # adrp x8, <page + 0x1000>
        0x91004100,  # add  x0, x8, #0x10
        0xF9400D01,  # ldr  x1, [x8, #0x18]
        RET,
    ])
    page = 0x2000
    assert adrp[3] is None  # the target is attributed to the consumer
    assert add[3] == page + 0x10
    assert ldr[3] == page + 0x18


def test_overwriting_the_page_register_ends_the_pair():
    *_, add = run([
        0xB0000008,  # adrp x8, <page + 0x1000>
        0xD2800008,  # mov  x8, #0
        0x91004100,  # add  x0, x8, #0x10  -> plain add now, no target
    ])
    assert add[3] is None
    assert add[2] == 0x91004100


def test_a_load_into_the_page_register_ends_the_pair():
    """adrp x8 ; ldr x8, [x8, #8] (a GOT slot) ; add x8, x8, #0x10: the add is
    on what the slot held (a vtable's _ZTV + 16), not on the page."""
    _, ldr, add = run([0xB0000008, 0xF9400508, 0x91004108])
    assert ldr[3] == 0x2008
    assert add[3] is None
    # a load into another register keeps it
    _, ldr, add = run([0xB0000008, 0xF9400509, 0x91004108])  # ldr x9, [x8, #8] ; add x8, x8, #0x10
    assert add[3] == 0x2010


def test_moved_code_masks_identically():
    """Same function with different call/page offsets, as when it moved between games."""
    a = run([0x94000040, 0xB0000008, 0x91004100, RET])
    b = run([0x94001000, 0x90000008, 0x91004100, RET], start=0x5000)
    assert [m for _, _, m, _ in a] == [m for _, _, m, _ in b]
    assert [w for _, w, _, _ in a] != [w for _, w, _, _ in b]
