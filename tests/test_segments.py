"""tools/segments.py: segments between static initialisers and their evidence,
on hand-built images (no game files)."""
from __future__ import annotations

import struct

import pytest
import segments
from common import read_areas_csv

AREAS_HEADER = "SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"
RET = 0xD65F03C0


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def adrp(pc: int, target: int, rd: int = 0) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def add_lo12(target: int, rd: int = 0, rn: int = 0) -> int:
    return 0x91000000 | ((target & 0xFFF) << 10) | (rn << 5) | rd


def test_dynamic_tags_and_init_array():
    img = bytearray(0x100)
    struct.pack_into("<qQqQqQqQ", img, 0x40, 25, 0x80, 27, 24, 5, 0x10, 0, 0)
    tags = segments.dynamic_tags(bytes(img), 0x40)
    assert tags == {25: 0x80, 27: 24, 5: 0x10}
    # Slot 0x88 isn't relocated to a function (an import), so it is skipped.
    slots = {0x80: 0x1000, 0x88: "imported", 0x90: 0x900}
    assert segments.init_array_targets(tags, slots) == [0x1000, 0x900]
    assert segments.init_array_targets({}, slots) == []


def test_segments_end_after_each_initialiser():
    starts = [0x100, 0x110, 0x120, 0x130, 0x140, 0x150]
    # 0x110 and 0x140 are initialisers: each ends its segment.
    assert segments.segments(starts, [0x110, 0x140], 0x100, 0x160) == [
        (0x100, 0x120), (0x120, 0x150), (0x150, 0x160)]
    # The range cuts too, and initialisers outside it don't matter.
    assert segments.segments(starts, [0x110, 0x140], 0x120, 0x150) == [(0x120, 0x150)]
    # An initialiser that is the range's last function adds no empty segment.
    assert segments.segments(starts, [0x140], 0x100, 0x150) == [(0x100, 0x150)]
    assert segments.segments(starts, [], 0x100, 0x160) == [(0x100, 0x160)]


@pytest.mark.parametrize("name, scope", [
    ("_ZN3btl3net16protocol_buffers10RaidActionC2Ev", "btl::net"),
    ("_ZNK8contents8pokecamp2pb8Cooking8ByteSizeEv", "contents::pokecamp"),
    ("_ZN4pkmn10GetVersionEv", "pkmn::GetVersion"),
    ("_ZN6google8protobuf7Message8CopyFromERKS1_@message", "google::protobuf"),
    ("_ZNSt3__16vectorIiNS_9allocatorIiEEE8__appendEm", None),  # libc++
    ("_ZN5physx2Gu4Box3fooEv", "physx::Gu"),
    ("_ZN2nnE", "nn"),  # ends after one part
    ("luaL_traceback", None),
    ("GCTM@lgc", None),
    ("_Z3foov", None),
])
def test_name_scope(name, scope):
    assert segments.name_scope(name) == scope


def test_name_scope_depth():
    assert segments.name_scope("_ZN3btl3net3FooEv", depth=1) == "btl"
    assert segments.name_scope("_ZN3btl3net3FooEv", depth=3) == "btl::net::Foo"


def test_c_string():
    img = b"\0abc\0hello world\0\x01bad\0"
    assert segments.c_string(img, 5, 0, len(img)) == "hello world"
    assert segments.c_string(img, 1, 0, len(img)) is None      # shorter than MIN_STRING
    assert segments.c_string(img, 17, 0, len(img)) is None     # not printable
    assert segments.c_string(img, 5, 0, 5) is None             # outside [lo, hi)
    assert segments.c_string(b"\0" + b"x" * 20, 1, 0, 21) is None  # no terminator in range


def test_analyse():
    # Three functions: 0x100 (references "pokecamp/path" and calls 0x200),
    # 0x200 (named, an initialiser: ends the first segment), 0x300 (calls 0x200).
    rodata = 0x1000
    text = b"bin/appli/pokecamp/x.bin\0"
    img = bytearray(0x1100)
    img[rodata:rodata + len(text)] = text
    words_100 = [adrp(0x100, rodata), add_lo12(rodata), bl(0x108, 0x200), RET]
    struct.pack_into("<4I", img, 0x100, *words_100)
    struct.pack_into("<I", img, 0x200, RET)
    struct.pack_into("<2I", img, 0x300, bl(0x300, 0x200), RET)
    funcs = [(0x100, 16), (0x200, 4), (0x300, 8)]
    names = {0x200: "_ZN8contents8pokecamp3FooEv"}
    segs = segments.analyse(bytes(img), funcs, [0x200], names, {0x200: "O"}, (rodata, rodata + 0x100),
                            0x100, 0x400)
    assert [(s.start, s.end) for s in segs] == [(0x100, 0x300), (0x300, 0x400)]
    first, second = segs
    assert (first.functions, first.matching, first.size) == (2, 1, 0x200)
    assert first.strings == ["bin/appli/pokecamp/x.bin"]
    assert first.own == {"contents::pokecamp": 1}
    assert not first.calls  # a call inside the segment isn't evidence
    assert second.calls == {"contents::pokecamp": 1}
    assert "contents::pokecamp" in second.evidence()
    lines = segments.format_segment(first, max_strings=0)
    assert lines[0] == "0x7100000100-0x7100000300  2 functions, 512 bytes, 1 matching"
    assert lines[-1] == "    ... 1 more strings"


def test_parse_range(write_csv):
    path = write_csv("areas.csv", AREAS_HEADER + (
        "0x7100000000,0x7100001000,0x7100000000,0x7100001000,lib,library,high,x\n"
        "0x7100001000,0x7100002000,0x7100001000,0x7100002010,game/a,game,low,x\n"
        "0x7100002000,0x7100003000,0x7100002010,0x7100003010,game/b,game,low,x\n"
        "0x7100003000,0x7100004000,0x7100003010,0x7100004010,lua,library,high,x\n"
        "0x7100004000,0x7100005000,0x7100004010,0x7100005010,game2/c,game,low,x\n"
        "0x7100006000,0x7100007000,,,game2/d,game,low,x\n"))
    assert segments.parse_range("0x7100000100-0x7100000200", "sword", path) == (0x100, 0x200)
    assert segments.parse_range("game/b", "shield", path) == (0x2010, 0x3010)
    assert segments.parse_range("game", "sword", path) == (0x1000, 0x3000)
    assert segments.parse_range("game", "shield", path) == (0x1000, 0x3010)
    with pytest.raises(SystemExit, match="aren't contiguous"):
        segments.parse_range("game2", "sword", path)
    assert segments.parse_range("game2", "shield", path) == (0x4010, 0x5010)
    with pytest.raises(SystemExit, match="no shield range"):
        segments.parse_range("game2/d", "shield", path)
    with pytest.raises(SystemExit, match="neither"):
        segments.parse_range("gam", "sword", path)
    assert len(read_areas_csv(path)) == 6
