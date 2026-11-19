"""tools/piagen.py: Pia's function families, on hand-encoded instruction words
(no game files)."""
from __future__ import annotations

import struct

import piagen

ADDR = 0x7101662B80


def code(*words: int) -> bytes:
    return struct.pack(f"<{len(words)}I", *words)


def bl(at: int, target: int, op: int = 0x94000000) -> int:
    return op | ((target - at) // 4) & 0x3FFFFFF


def create_words(at: int, size_word: int, heap: int, new: int, ctor: int) -> list[int]:
    return [0xF81E0FF3, 0xA9017BFD, 0x910043FD, bl(at + 12, heap), 0xAA0003E1, size_word,
            bl(at + 24, new), 0xAA0003F3, 0xB4000060, 0xAA1303E0, bl(at + 40, ctor),
            0xA9417BFD, 0xAA1303E0, 0xF84207F3, 0xD65F03C0]


def test_decode_mov_w():
    assert piagen.decode_mov_w(0x52820A00, 0) == 0x1050      # mov w0, #0x1050 (movz)
    assert piagen.decode_mov_w(0x321C03E0, 0) == 0x10        # orr w0, wzr, #0x10
    assert piagen.decode_mov_w(0x321C03E2, 2) == 0x10        # the same into w2
    assert piagen.decode_mov_w(0x321C03E2, 0) is None        # another register
    assert piagen.decode_mov_w(0x52A00020, 0) is None        # movz with a shift (lsl #16)
    assert piagen.decode_bitmask32(0, 0b000111) == 0xFF      # 8 ones
    assert piagen.decode_bitmask32(0, 0b111100) == 0x55555555  # a 2-bit element, replicated


def test_match_create():
    words = create_words(ADDR, 0x52820A00, 0x7101652BD0, 0x71017162D0, 0x71016A9A20)
    c = piagen.match_create(code(*words), ADDR)
    assert c == piagen.Create(0x7101652BD0, 0x71017162D0, 0x1050, 0x71016A9A20)
    assert piagen.match_destroy(code(*words), ADDR) is None
    words[8] = 0xB4000080  # cbz to another place
    assert piagen.match_create(code(*words), ADDR) is None
    assert piagen.match_create(code(*words[:-1]), ADDR) is None


def test_match_destroy():
    at = 0x7101662920
    words = [0xB40001A1, 0xF81E0FF3, 0xA9017BFD, 0x910043FD, 0xF9400028, 0xF9400108, 0xAA0103E0,
             0xAA0103F3, 0xD63F0100, 0xA9417BFD, 0xAA1303E0, 0xF84207F3, bl(at + 48, 0x7101716390, 0x14000000),
             0xD65F03C0]
    assert piagen.match_destroy(code(*words), at) == piagen.Destroy(0x7101716390)
    words[5] = 0xF9400508  # ldr x8, [x8, #8]: slot 1, not the complete-object destructor
    assert piagen.match_destroy(code(*words), at) is None


def test_ctor_class():
    assert piagen.ctor_class("_ZN11Unk_245bc18C2Ev") == ["Unk_245bc18"]
    assert piagen.ctor_class("_ZN2nn3pia4mesh16MeshPacketWriterC2Ev") == ["nn", "pia", "mesh", "MeshPacketWriter"]
    assert piagen.ctor_class("_ZN11Unk_245bc18C2Ei") is None  # a parameter
    assert piagen.ctor_class("_ZN11Unk_245bc18D2Ev") is None


def test_render():
    cls = ["nn", "pia", "lan", "LanNetworkFactory"]
    create = piagen.Member(0x7101662B80, 15, "create", ["Unk_245bc18"], 0x1050)
    destroy = piagen.Member(0x7101662920, 11, "destroy")
    assert create.mangled(cls) == "_ZN2nn3pia3lan17LanNetworkFactory4vf15Ev"
    assert destroy.mangled(cls) == "_ZN2nn3pia3lan17LanNetworkFactory4vf11EP16Unk_1662920_arg1"
    src = piagen.render_file(cls, "N2nn3pia3lan17LanNetworkFactoryE", [create, destroy])
    assert "class Unk_245bc18 {\npublic:\n    Unk_245bc18();\n\n    u8 _0[0x1050];\n};" in src
    assert "struct Unk_1662920_arg1 {\n    virtual ~Unk_1662920_arg1();\n};" in src
    assert "namespace lan {\nclass LanNetworkFactory {" in src
    assert "Unk_245bc18* nn::pia::lan::LanNetworkFactory::vf15() {\n    return new (Unk_1652bd0()) Unk_245bc18();" in src
    assert "        object->~Unk_1662920_arg1();\n        Unk_1716390(object);" in src
    # members in address order
    assert src.index("// 0x7101662920") < src.index("// 0x7101662b80")


def result_words(at: int, value_word: int | None) -> list[int]:
    head = [0xD10103FF, 0xA9024FF4, 0xA9037BFD, 0x9100C3FD, 0xAA0803F3]
    if value_word is None:
        mid = [0x910023E8, 0xB27E0114, 0xAA1403E0, 0xB9000BFF]
    else:
        mid = [value_word, 0xB9000BE8, 0x910023E8, 0xB27E0114, 0xAA1403E0]
    first = len(head) + len(mid)
    words = head + mid + [0, 0x910063E1, 0xAA1403E0, 0xB9001BFF, 0, 0x910023E1, 0xAA1303E0, 0,
                          0xA9437BFD, 0xA9424FF4, 0x910103FF, 0xD65F03C0]
    for i, t in zip((first, first + 4, first + 7), (0x71017EA620, 0x71017EA630, 0x710165E060)):
        words[i] = bl(at + 4 * i, t)
    return words


def test_match_result():
    at = 0x71016675E0
    calls = (0x71017EA620, 0x71017EA630, 0x710165E060)
    k = piagen.match_result(code(*result_words(at, 0x52818168)), at)  # mov w8, #0xc0b
    assert k == piagen.Constant(0xC0B, calls)
    zero = piagen.match_result(code(*result_words(at, None)), at)
    assert zero == piagen.Constant(0, calls)
    assert piagen.match_result(code(*result_words(at, 0x52818169)), at) is None  # mov w9: not the value


def test_render_result():
    cls = ["nn", "pia", "lan", "LanMatchmakeSession"]
    x = piagen.Member(0x71016675E0, 27, "result", size=0xC0B)
    assert x.mangled(cls) == "_ZN2nn3pia3lan19LanMatchmakeSession4vf27Ev"
    src = piagen.render_file(cls, "N2nn3pia3lan19LanMatchmakeSessionE", [x])
    assert '#include "pia/common/Unk_165e060.h"' in src and "Unk_17162d0.h" not in src
    assert ("nn::pia::Unk_165e060 nn::pia::lan::LanMatchmakeSession::vf27() {\n"
            "    return nn::pia::Unk_165e060Value<0xc0b>();\n}") in src
