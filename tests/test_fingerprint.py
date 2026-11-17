"""fingerprint.py: every metric on hand-encoded AArch64 words, the .eh_frame
CIE classification on a hand-built .eh_frame_hdr, and range resolution."""
from __future__ import annotations

import struct

import pytest

import fingerprint as fp
from common import BASE, read_functions_csv

RET = 0xD65F03C0
NOP = 0xD503201F
BL = 0x94000000
BLR_X8 = 0xD63F0100
STP_FP_LR_PRE = 0xA9BF7BFD  # stp x29, x30, [sp, #-16]!
MOV_FP_SP = 0x910003FD  # mov x29, sp
ADD_FP_SP_16 = 0x910043FD  # add x29, sp, #16


def scan(*words: int):
    return fp.scan_function(list(words))


# --------------------------------------------------------------------------- encodings
def test_logical_immediates():
    assert fp.logical_imm(0, 31, 0, 32) == 2  # orr w0, wzr, #2
    assert fp.logical_imm(0, 0, 7, 32) == 0xFF
    assert fp.logical_imm(1, 0, 31, 64) == 0xFFFFFFFF
    assert fp.logical_imm(0, 0, 0x3C, 32) == 0x55555555  # 2-bit element 01, replicated
    assert fp.logical_imm(0, 0, 31, 32) is None  # all ones: reserved
    assert 2 in fp.LOGICAL32 and 5 not in fp.LOGICAL32 and 0 not in fp.LOGICAL32
    assert len(fp.LOGICAL32) == 1302


def test_small_constants():
    c = scan(0x321F03E0,  # orr w0, wzr, #2
             0x52800041,  # movz w1, #2      (logical: clang 9+)
             0x528000A1,  # movz w1, #5      (not logical: any clang)
             0x52A00200,  # movz w0, #0x10, lsl #16 (0x100000, logical)
             0x321F07E0,  # orr w0, wzr, #6
             0xB27F03E0,  # orr x0, xzr, #2  (64-bit: not counted)
             0x320003E1,  # orr w1, wzr, #1
             RET)
    assert c["orr_wzr"] == 3
    assert c["movz_logical"] == 2


def test_orr_with_register_source_is_not_a_constant():
    assert scan(0x321F0020, RET)["orr_wzr"] == 0  # orr w0, w1, #2


def test_calling_and_frame_pointer():
    assert scan(STP_FP_LR_PRE, MOV_FP_SP, BL, RET)["frame_pointer"] == 1
    c = scan(STP_FP_LR_PRE, ADD_FP_SP_16, BLR_X8, RET)
    assert (c["calling"], c["frame_pointer"]) == (1, 1)
    c = scan(0xF81F0FFE, BL, RET)  # str x30, [sp, #-16]!: no frame pointer
    assert (c["calling"], c["frame_pointer"]) == (1, 0)
    c = scan(MOV_FP_SP, RET)  # leaf
    assert (c["functions"], c["calling"], c["frame_pointer"]) == (1, 0, 0)
    assert scan(0x14000000, RET)["calling"] == 0  # b (tail call) is not a call


def test_zeroing_idioms():
    c = scan(0x6F00E400,  # movi v0.2d, #0
             0x6F00E401,  # movi v1.2d, #0
             0xAD000400,  # stp q0, q1, [x0]
             0xA9017C1F,  # stp xzr, xzr, [x0, #16]
             0xA9007C1F,  # stp xzr, xzr, [x0]        contiguous with the previous (descending)
             0xA9027C1F,  # stp xzr, xzr, [x0, #32]   not contiguous with [x0]
             0xA9037D1F,  # stp xzr, xzr, [x8, #48]   other base
             0xA9BF7FFF,  # stp xzr, xzr, [sp, #-16]! (pre-index: not counted)
             0xA9007C3F,  # stp xzr, xzr, [x1]
             0xA9017C3F,  # stp xzr, xzr, [x1, #16]   contiguous (ascending)
             RET)
    assert c["movi_zero"] == 2
    assert c["stp_q"] == 1
    assert c["stp_xzr"] == 6
    assert c["stp_xzr_pairs"] == 2


def test_copies():
    c = scan(0xA9402428,  # ldp x8, x9, [x1]
             0xA9002408,  # stp x8, x9, [x0]      copy
             0xA9412428,  # ldp x8, x9, [x1, #16]
             0xA9012009,  # stp x9, x8, [x0, #16] registers swapped: not a copy
             0x3DC00020,  # ldr q0, [x1]
             0x3D800000,  # str q0, [x0]          copy
             0x3DC00021,  # ldr q1, [x1]
             0x3D800000,  # str q0, [x0]          other register
             RET)
    assert (c["ldp_stp_x"], c["ldr_str_q"]) == (1, 1)


def test_g_ldr_pairs():
    # Lua's stackinuse (docs/compiler.md): ldr x10, [x9, #8]; ldr x9, [x9, #0x10]
    c = scan(0xF940052A, 0xF9400929, RET)
    assert (c["g_ldr_pairs"], c["g_ldr_pairs_desc"]) == (1, 0)
    # descending: ldr x8, [x9, #0x80]; ldr x9, [x9, #0x78]
    c = scan(0xF9404128, 0xF9403D29, RET)
    assert (c["g_ldr_pairs"], c["g_ldr_pairs_desc"]) == (0, 1)
    # 32-bit: ldr w10, [x9, #4]; ldr w9, [x9, #8]
    assert scan(0xB940052A, 0xB9400929, RET)["g_ldr_pairs"] == 1


@pytest.mark.parametrize("w1, w2, why", [
    (0xF940052A, 0xF940092B, "second destination is not the base"),
    (0xF9400529, 0xF940092A, "first destination is the base"),
    (0xF940052A, 0xF9400D29, "offsets 8 and 24: not adjacent"),
    (0xF940052A, 0xB9400929, "different sizes"),
    (0xF940052A, 0xF940094A, "different bases"),
    (0xF940FD2A, 0xF9410129, "offsets 504/512: lower one is fine"),
    (0xF941012A, 0xF9410529, "offsets 512/520: beyond ldp's range"),
    (0xF94007EA, 0xF9400BFF, "sp base"),
])
def test_g_ldr_pair_rejects(w1, w2, why):
    c = scan(w1, w2, RET)
    expected = 1 if why.endswith("lower one is fine") else 0
    assert c["g_ldr_pairs"] + c["g_ldr_pairs_desc"] == expected, why


def test_g_ldr_pair_needs_consecutive_words():
    assert scan(0xF940052A, NOP, 0xF9400929, RET)["g_ldr_pairs"] == 0


def test_ldp_into_base():
    c = scan(0xA940A52A,  # ldp x10, x9, [x9, #8]
             0x29402528,  # ldp w8, w9, [x9]
             0xA9402528,  # ldp x8, x9, [x9]
             0xA9402428,  # ldp x8, x9, [x1]
             0xA9C0A52A,  # ldp x10, x9, [x9, #8]! (writeback: not counted)
             RET)
    assert c["g_ldp_base"] == 3


def test_and_before_variable_shift():
    AND = 0x92407D4A  # and x10, x10, #0xffffffff
    LSL = 0x1ACA218A  # lsl w10, w12, w10 (lslv: shift amount w10)
    c = scan(AND, LSL, RET)
    assert (c["and_shift"], c["and_shift_funcs"]) == (1, 1)
    assert scan(AND, NOP, NOP, NOP, LSL, RET)["and_shift"] == 1  # 4th instruction after
    assert scan(AND, NOP, NOP, NOP, NOP, LSL, RET)["and_shift"] == 0  # 5th
    assert scan(AND, 0x1AC0214A, RET)["and_shift"] == 0  # lsl w10, w10, w0: D is the value, not the amount
    assert scan(AND, 0x9ACA218A, RET)["and_shift"] == 0  # lsl x10, x12, x10: 64-bit shift
    assert scan(0x92407C2A, LSL, RET)["and_shift"] == 1  # and x10, x1, #0xffffffff
    c = scan(AND, LSL, AND, 0x1ACA258A, RET)  # ... then lsr w10, w12, w10
    assert (c["and_shift"], c["and_shift_funcs"]) == (2, 1)


# --------------------------------------------------------------------------- eh_frame
def _cie(aug: bytes, with_personality: bool) -> bytes:
    body = struct.pack("<I", 0) + b"\x01" + aug + b"\0" + b"\x04\x78\x1e"
    if with_personality:  # P (udata4 pointer), L, R
        augdata = b"\x03" + struct.pack("<I", 0x1234) + b"\x1b" + b"\x1b"
    else:  # R
        augdata = b"\x1b"
    body += bytes([len(augdata)]) + augdata
    body += b"\0" * (-(len(body) + 4) % 4)
    return struct.pack("<I", len(body)) + body


def _fde(at: int, cie_at: int, start: int, size: int, lsda: bool) -> bytes:
    body = struct.pack("<I", at + 4 - cie_at)
    body += struct.pack("<i", start - (at + 8)) + struct.pack("<i", size)
    body += b"\x04" + struct.pack("<i", 0) if lsda else b"\x00"
    body += b"\0" * (-(len(body) + 4) % 4)
    return struct.pack("<I", len(body)) + body


def _eh_image(funcs: list[tuple[int, int, bool]]) -> tuple[bytes, int]:
    """Image with code at 0x1000.., .eh_frame at 0x100, .eh_frame_hdr at 0x800."""
    img = bytearray(0x4000)
    o = 0x100
    cies = {}
    for name, pers in ((b"zR", False), (b"zPLR", True)):
        cies[pers] = o
        c = _cie(name, pers)
        img[o:o + len(c)] = c
        o += len(c)
    fdes = []
    for start, size, exc in funcs:
        f = _fde(o, cies[exc], start, size, exc)
        img[o:o + len(f)] = f
        fdes.append((start, o))
        o += len(f)
    hdr = 0x800
    table = b"".join(struct.pack("<ii", s - hdr, f - hdr) for s, f in sorted(fdes))
    h = bytes([1, 0x1B, 0x03, 0x3B]) + struct.pack("<i", 0x100 - (hdr + 4)) + struct.pack("<I", len(fdes)) + table
    img[hdr:hdr + len(h)] = h
    return bytes(img), hdr


def test_fde_augmentations():
    img, hdr = _eh_image([(0x1000, 8, False), (0x1010, 8, True), (0x1020, 4, False)])
    assert fp.fde_augmentations(img, hdr) == [(0x1000, "zR"), (0x1010, "zPLR"), (0x1020, "zR")]


def test_fingerprint_counts_functions_starting_in_range():
    words = [BL, RET, MOV_FP_SP, RET, 0x321F03E0, RET]
    img = bytearray(0x1000) + b"".join(struct.pack("<I", w) for w in words)
    mod = {"image": bytes(img), "functions": [(0x1000, 8), (0x1008, 8), (0x1010, 8)],
           "fdes": [(0x1000, "zR"), (0x1008, "zPLR"), (0x1010, "zR")]}
    c = fp.fingerprint(mod, 0x1004, 0x1018)  # the first function starts before the range
    assert c["functions"] == 2
    assert c["calling"] == 0
    assert c["orr_wzr"] == 1
    assert (c["fde_zR"], c["fde_zPLR"]) == (1, 1)
    assert all(c[m] == 0 for m in fp.METRICS if m not in ("functions", "orr_wzr"))


# --------------------------------------------------------------------------- typeinfo
@pytest.mark.parametrize("s, comps", [
    (b"N4PPFX6EffectE", [b"PPFX", b"Effect"]),
    (b"6SiSDK", None),  # length 6, only 5 characters follow
    (b"5SiSDK", [b"SiSDK"]),
    (b"N6SiSDK37SiArrayIN4PPFX10IGPUDevice17PipelineStateDataELi16EEE",
     [b"SiSDK3", b"SiArray", b"PPFX", b"IGPUDevice", b"PipelineStateData"]),
    (b"7SiArrayIiE", [b"SiArray"]),
    (b"4PPFXfoo", None),  # trailing garbage after a non-nested name
    (b"N4PPFX6Effect", None),  # nested without the closing E
    (b"C:/workspace/src/ppfx.cpp", None),
    (b"01A", None),
])
def test_mangled_components(s, comps):
    assert fp.mangled_components(s) == comps


def test_typeinfo_names():
    ro = b"\0".join([b"N4PPFX6EffectE", b"N6SiSDK37SiArrayIN4PPFX4TypeEEE", b"5SiSDK", b"PPFX: error", b""])
    c = fp.typeinfo_names(ro, ["PPFX", "AK"])
    assert (c["typeinfo_PPFX"], c["typeinfo_AK"]) == (2, 0)


# --------------------------------------------------------------------------- ranges
def test_read_areas_per_game(write_csv):
    path = write_csv("areas.csv", "SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"
                     "0x7101548410,0x7101570900,0x71015484b0,0x71015709a0,lua,library,high,x\n"
                     "0x7101570900,0x7101571000,,,swonly,game,low,y\n")
    assert fp.read_areas(path) == {"lua": {"sword": (0x7101548410, 0x7101570900),
                                           "shield": (0x71015484b0, 0x71015709a0)},
                                   "swonly": {"sword": (0x7101570900, 0x7101571000)}}


def test_read_areas_groups(write_csv):
    path = write_csv("areas.csv", "SwordStart,SwordEnd,ShieldStart,ShieldEnd,Area,Kind,Confidence,Evidence\n"
                     "0x7100001000,0x7100002000,0x7100001000,0x7100002010,game/a,game,low,x\n"
                     "0x7100002000,0x7100003000,0x7100002010,0x7100003010,game/b,game,low,x\n"
                     "0x7100003000,0x7100004000,0x7100003010,0x7100004010,lua,library,high,x\n"
                     "0x7100004000,0x7100005000,0x7100004010,0x7100005010,net/a,game,low,x\n"
                     "0x7100006000,0x7100007000,0x7100006010,0x7100007010,net/b,game,low,x\n")
    areas = fp.read_areas(path)
    assert areas["game"] == {"sword": (0x7100001000, 0x7100003000), "shield": (0x7100001000, 0x7100003010)}
    assert areas["game/b"]["shield"] == (0x7100002010, 0x7100003010)
    assert "net" not in areas  # its rows have a gap: only each row is a target
    assert set(areas) == {"game", "game/a", "game/b", "lua", "net/a", "net/b"}


def test_parse_target():
    areas = {"lua": {"sword": (1, 2)}}
    assert fp.parse_target("lua", areas) == ("lua", {"sword": (1, 2)})
    assert fp.parse_target("x=0x10-0x20", areas) == ("x", {"sword": (0x10, 0x20)})
    assert fp.parse_target("0x10-0x20,0x30-0x40", areas) == (
        "0x10-0x20,0x30-0x40", {"sword": (0x10, 0x20), "shield": (0x30, 0x40)})
    with pytest.raises(SystemExit):
        fp.parse_target("nope", areas)
    with pytest.raises(SystemExit):
        fp.parse_target("0x20-0x10", areas)


def test_shield_range_from_paired_functions(functions_csv):
    rows = read_functions_csv(functions_csv(
        "0x0000007101548410,16,0x00000071015484b0,16,common,U,",
        "0x0000007101548420,32,0x00000071015484c0,32,common,U,",
        "0x0000007101548440,8,,,sword,U,",
        "0x0000007101570900,16,0x00000071015709a0,16,common,U,",
    ))
    rng = {"sword": (0x7101548410, 0x7101570900)}
    assert fp.resolve(rng, "sword", rows) == ((0x7101548410, 0x7101570900), "given")
    assert fp.resolve(rng, "shield", rows) == ((0x71015484b0, 0x71015484e0), "functions.csv")
    assert fp.resolve({**rng, "shield": (5, 6)}, "shield", rows) == ((5, 6), "given")
    assert BASE == 0x7100000000
