#!/usr/bin/env python3
"""Families of same-shape functions on gflib3's memory code, written from the executable.

    python tools/familygen.py census                     # candidates, written, matched, by family
    python tools/familygen.py write --names n.csv        # src/gflib3/families, and the names to give
    python tools/familygen.py write --names n.csv --all  # a trial: every candidate
    python tools/familygen.py write --names n.csv --only add.txt   # the kept ones and these

Unmatched functions that are the same code once branch targets and
adrp/lo12 fields are masked are instances of one source: a template, or a
class shape repeated. Three such families are on gflib3's allocator
(src/unsorted/Unk_2771620.h) and its reference-counted object
(src/gflib3/Unk_239a418.h). This tool finds their instances and writes them,
in src/gflib3/families:

- `vectors`: libc++ 7's `vector<T, Unk_2771620_Allocator<T>>` growing:
  `__push_back_slow_path` and `reserve`. Each instance is its own element
  type (the linker would have merged two of one type), so each gets a
  placeholder named after its Sword address. Three shapes are known by an
  instance (`VECTOR_SEEDS`: pointers by const reference, references moved
  in, reserve of references); the other push_backs are found by their
  prologue (the size from `asr x23, x8, #log2(size)`) and written with the
  element `ESIZE_ELEMENT` gives that size: a u32, a reference by const
  reference, or two u64. Element types that are more than that don't match
  and aren't kept. The references are `Unk_239a418_Ref2`, whose copy tests
  the pointer it stored (the growth loads each old element once).
- `factories`: `Unk_New::Create<T>` (src/gflib3/Unk_New.h) for classes on
  `Unk_23f43c8` (src/unsorted/Unk_23f43c8.h): allocate sizeof(T) from an
  allocator made current, construct T from two references (the base's
  out-of-line constructor, then T's vptrs and members), record the
  allocation in the object (field_8 to field_20). T is named after the
  vtable it stores; its size is the allocation's; its vtable has as many
  more slots as the secondary vptrs' offsets say; its members are read from
  the stores after the base's constructor: zeros and constants (movz, movn,
  movk, orr), each byte's run cut at natural alignment, an unstored run an
  uninitialised member. When the first instruction after the constructor
  call is a store, not the vtable's adrp, the members are stored before
  T's vptr: they belong to a class between T and the base (`<T>_Parent`).
- `singletons`: classes whose vf3 (slot 3 of the primary vtable, slot 1 of
  the one at +0x48) destroys the instance a global of theirs holds, the way
  Unk_239a418::vf3 destroys an object. The function doesn't use `this`, so
  its +0x48 thunk is a copy of it.

A row is kept (written again) when its name is the one written for it and
check.py matched it; `--only` adds addresses, `--all` writes every
candidate. A trial: `write --all`, name, check.py, then `write --only` with
the trial's names minus check.py's BAD addresses.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

OUT_DIR = ROOT / "src" / "gflib3" / "families"
VECTOR_FILE = "Unk_5ac520.cpp"
FACTORY_FILE = "Unk_8d4190.cpp"
SINGLETON_FILE = "Unk_7c20.cpp"

GET_TLS = 0x17E9010            # nn::os::GetTlsValue (PLT): the allocator stack's slot
FACTORY_BASE_CTOR = 0xE7C430   # Unk_23f43c8::Unk_23f43c8(Ref, Ref)
FACTORY_BASE_SIZE = 0x78       # sizeof(Unk_23f43c8)
FACTORY_BASE_SLOTS = 11        # its primary vtable's slots
LDR_X0_SP_8 = 0xF94007E0       # ldr x0, [sp, #8]: the factory releases its arguments
SINGLETON_SEED = 0x7C20        # Unk_236d328::vf3
VECTOR_SEEDS = {0x5AC520: "ptr", 0x5E7430: "refm", 0x5E7880: "reserve"}
ESIZE_ELEMENT = {4: "s4c", 8: "refc", 16: "s16c"}
XZR = 31


# ------------------------------------------------------------------------- AArch64

def _sext(v: int, bits: int) -> int:
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def bl_target(pc: int, w: int) -> int | None:
    if (w & 0xFC000000) == 0x94000000:
        return pc + _sext(w & 0x3FFFFFF, 26) * 4
    return None


def bitmask(n: int, immr: int, imms: int, bits: int) -> int:
    """The value of a logical immediate (DecodeBitMasks)."""
    length = ((n << 6) | (~imms & 0x3F)).bit_length() - 1
    esize = 1 << length
    levels = esize - 1
    s, r = imms & levels, immr & levels
    welem = (1 << (s + 1)) - 1
    welem = ((welem >> r) | (welem << (esize - r))) & ((1 << esize) - 1)
    v = 0
    for i in range(bits // esize):
        v |= welem << (i * esize)
    return v


def const_def(w: int):
    """(rd, value) for a constant written to a register: movz, movn, orr rd, zr, #imm;
    (rd, ("movk", shift, imm16)) for a movk; None otherwise."""
    sf = w >> 31
    rd = w & 31
    mask = 0xFFFFFFFFFFFFFFFF if sf else 0xFFFFFFFF
    hw = (w >> 21) & 3
    imm16 = (w >> 5) & 0xFFFF
    if (w & 0x7F800000) == 0x52800000:   # movz
        return rd, imm16 << (16 * hw)
    if (w & 0x7F800000) == 0x12800000:   # movn
        return rd, ~(imm16 << (16 * hw)) & mask
    if (w & 0x7F800000) == 0x72800000:   # movk
        return rd, ("movk", 16 * hw, imm16)
    if (w & 0x7F8003E0) == 0x320003E0:   # orr rd, zr, #bitmask
        return rd, bitmask((w >> 22) & 1, (w >> 16) & 0x3F, (w >> 10) & 0x3F, 64 if sf else 32)
    return None


def store(w: int):
    """(rn, [(rt, offset, size), ...]) for a general-register store (str, stur, stp
    with a signed offset), "simd" for a SIMD one, None for anything else."""
    rn, rt = (w >> 5) & 31, w & 31
    if (w & 0x3B000000) == 0x39000000 and not (w >> 22) & 3:    # STR (unsigned offset)
        if (w >> 26) & 1:
            return "simd"
        size = 1 << (w >> 30)
        return rn, [(rt, ((w >> 10) & 0xFFF) * size, size)]
    if (w & 0x3B200C00) == 0x38000000 and not (w >> 22) & 3:    # STUR
        if (w >> 26) & 1:
            return "simd"
        return rn, [(rt, _sext((w >> 12) & 0x1FF, 9), 1 << (w >> 30))]
    if (w & 0x3BC00000) == 0x29000000:                          # STP (signed offset)
        if (w >> 26) & 1:
            return "simd"
        size = 8 if w >> 31 else 4
        off = _sext((w >> 15) & 0x7F, 7) * size
        return rn, [(rt, off, size), ((w >> 10) & 31, off + size, size)]
    return None


def masked(img: bytes, off: int, size: int) -> bytes:
    """A function's words with b/bl targets and adrp(+add/ldr lo12) fields zeroed."""
    pages = set()
    out = []
    for o in range(off, off + size, 4):
        w = struct.unpack_from("<I", img, o)[0]
        if (w & 0x7C000000) == 0x14000000:
            w &= 0xFC000000
        elif (w & 0x9F000000) == 0x90000000:
            pages.add(w & 31)
            w &= 0x9F00001F
        elif (w & 0xFF800000) == 0x91000000 and ((w >> 5) & 31) in pages:
            w &= 0xFFC003FF
        elif (w & 0x3B000000) == 0x39000000 and ((w >> 5) & 31) in pages:
            w &= 0xFFC003FF
        out.append(w)
    return struct.pack(f"<{len(out)}I", *out)


# ------------------------------------------------------------------------- the executable

@dataclass
class Module:
    img: bytes
    rows: dict                      # sword address -> functions.csv row
    slots: dict                     # data address -> target (int) or import name (str)
    funcs: set = field(default_factory=set)
    data_names: dict = field(default_factory=dict)
    _refs: dict | None = None

    def word(self, a: int) -> int:
        return struct.unpack_from("<I", self.img, a)[0]

    def words(self, a: int, size: int) -> list[tuple[int, int]]:
        return [(o, self.word(o)) for o in range(a, a + size, 4)]

    def shape(self, a: int) -> bytes:
        return hashlib.sha1(masked(self.img, a, self.rows[a].sword_size)).digest()

    def data_refs(self, target: int) -> list[int]:
        """The data slots (vtable entries) relocated to `target`."""
        if self._refs is None:
            self._refs = {}
            for s, t in self.slots.items():
                if isinstance(t, int):
                    self._refs.setdefault(t, []).append(s)
        return sorted(self._refs.get(target, []))

    def got_target(self, a: int, size: int) -> list[int]:
        """The data a function loads through the GOT (adrp + ldr), in order."""
        from nx.refs import decode
        out = []
        for _, w, _, t in decode(self.img, a, size):
            if t is not None and t in self.slots and (w & 0x3B000000) == 0x39000000:
                v = self.slots[t]
                if isinstance(v, int):
                    out.append(v)
        return out


def load() -> Module:
    from common import load_module, nso_path, read_functions_csv
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = load_module("sword")
    img = mod["image"]
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), img, mod["text_end"])
    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    names = {}
    with open(ROOT / "data" / "data_symbols.csv", newline="", encoding="utf-8") as fh:
        for r in csv.DictReader(fh):
            if r["Sword"]:
                names[int(r["Sword"], 16) - BASE] = r["Name"]
    return Module(img, rows, dyn.slots, {a for a, _ in mod["functions"]}, names)


def placeholder(a: int) -> str:
    return f"Unk_{a:x}"


def mangled_class(name: str) -> str:
    return f"{len(name)}{name}"


# ------------------------------------------------------------------------- vectors

VECTOR_ELEMENTS = {
    # variant: (declaration of the placeholder, the vector's element, push_back's argument)
    "ptr": ("struct {T};", "{T}*", "{T}* const&"),
    "refm": ("struct {T} : Unk_239a418 {{}};", "Unk_239a418_Ref2<{T}>", "Unk_239a418_Ref2<{T}>"),
    "reserve": ("struct {T} : Unk_239a418 {{}};", "Unk_239a418_Ref2<{T}>", None),
    "refc": ("struct {T} : Unk_239a418 {{}};", "Unk_239a418_Ref2<{T}>", "Unk_239a418_Ref2<{T}> const&"),
    "s4c": ("struct {T} {{\n    u32 field_0;\n}};", "{T}", "{T} const&"),
    "s16c": ("struct {T} {{\n    u64 field_0;\n    u64 field_8;\n}};", "{T}", "{T} const&"),
}
VECTOR_COMMENTS = {
    "ptr": "Pointers, pushed by const reference.",
    "refm": "References, moved in (the old elements are copied: the move isn't noexcept).",
    "reserve": "reserve of vectors of references.",
    "refc": "References, pushed by const reference.",
    "s4c": "Four-byte elements.",
    "s16c": "Sixteen-byte elements.",
}


def vector_name(variant: str, t: str) -> str:
    c = mangled_class(t)
    if variant == "ptr":
        return f"_ZNSt3__16vectorIP{c}21Unk_2771620_AllocatorIS2_EE21__push_back_slow_pathIRKS2_EEvOT_"
    if variant in ("refm", "refc", "reserve"):
        head = f"_ZNSt3__16vectorI16Unk_239a418_Ref2I{c}E21Unk_2771620_AllocatorIS3_EE"
        if variant == "reserve":
            return head + "7reserveEm"
        return head + "21__push_back_slow_pathI" + ("RKS3_" if variant == "refc" else "S3_") + "EEvOT_"
    return f"_ZNSt3__16vectorI{c}21Unk_2771620_AllocatorIS1_EE21__push_back_slow_pathIRKS1_EEvOT_"


def vector_instance(variant: str, t: str) -> str:
    decl, elem, arg = VECTOR_ELEMENTS[variant]
    decl = decl.replace("{T}", t).replace("{{", "{").replace("}}", "}")
    elem = elem.replace("{T}", t)
    if arg is None:
        inst = f"template void Unk_2771620_Vector<{elem}>::reserve(size_t);"
    else:
        arg = arg.replace("{T}", t)
        param = arg if arg.endswith("&") else arg + "&&"
        inst = f"template void Unk_2771620_Vector<{elem}>::__push_back_slow_path<{arg}>({param});"
    return f"{decl}\n{inst}"


def push_back_size(m: Module, a: int) -> int | None:
    """The element size of a __push_back_slow_path on the allocator, from its prologue."""
    size = m.rows[a].sword_size
    for o in range(a, a + min(0x30, size - 12), 4):
        if m.word(o) == 0xA9402009 and m.word(o + 4) == 0xCB090108 and (m.word(o + 8) & 0xFFC0FFE0) == 0x9340FD00:
            if GET_TLS not in {bl_target(p, w) for p, w in m.words(a, size)}:
                return None
            return 1 << ((m.word(o + 8) >> 16) & 0x3F)
    return None


def vector_candidates(m: Module) -> dict[int, str]:
    seeds = {}
    for a, v in VECTOR_SEEDS.items():
        seeds[(m.rows[a].sword_size, m.shape(a))] = v
    out = {}
    for a, r in m.rows.items():
        if not r.sword_size or r.sword_size < 0x60 or r.status not in "UO":
            continue
        if r.status == "O" and not r.name.startswith("_ZNSt3__16vectorI"):
            continue
        v = seeds.get((r.sword_size, m.shape(a)))
        if v is None:
            es = push_back_size(m, a)
            v = ESIZE_ELEMENT.get(es) if es else None
        if v is not None:
            out[a] = v
    return out


def vector_source(chosen: dict[int, str]) -> str:
    parts = [VECTOR_HEADER]
    for variant in VECTOR_ELEMENTS:
        mine = sorted(a for a, v in chosen.items() if v == variant)
        if not mine:
            continue
        parts.append(f"// {VECTOR_COMMENTS[variant]}\n")
        for a in mine:
            parts.append(f"// 0x{a + BASE:x}\n{vector_instance(variant, placeholder(a))}\n")
    return "\n".join(parts)


VECTOR_HEADER = """// Scope: common
//
// libc++'s vector on gflib3's container allocator (src/unsorted/Unk_2771620.h)
// growing: each instance has an element type of its own (the linker would have
// merged two of the same type), a placeholder named after the instance's Sword
// address. Their users aren't decompiled yet. Written by tools/familygen.py:
// regenerate, don't edit.
#include <vector>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"

template <class T>
using Unk_2771620_Vector = std::vector<T, Unk_2771620_Allocator<T>>;
"""


# ------------------------------------------------------------------------- factories

@dataclass
class Factory:
    addr: int
    cls: str
    size: int
    extra_slots: int
    fields: list            # (offset, width, value or None)
    parented: bool


def layout(base: int, size: int, stored: dict[int, int]) -> list[tuple[int, int, int | None]]:
    """Members from base to size: each run of stored (or unstored) bytes cut at natural
    alignment; a short unstored tail is padding."""
    out = []
    off = base
    while off < size:
        width = 8
        while width > 1 and (off % width or off + width > size):
            width //= 2
        while width > 1 and len({b in stored for b in range(off, off + width)}) > 1:
            width //= 2
        if off not in stored and size - off < 8 and all(b not in stored for b in range(off, size)) and out:
            break
        value = None
        if off in stored:
            value = sum(stored[off + k] << (8 * k) for k in range(width))
        out.append((off, width, value))
        off += width
    return out


def parse_factory(m: Module, a: int) -> Factory | str:
    """A factory's class, or why it isn't one this tool writes."""
    size_ = m.rows[a].sword_size
    ins = m.words(a, size_)
    words = dict(ins)
    calls = [p for p, w in ins if bl_target(p, w) == FACTORY_BASE_CTOR]
    if not calls:
        return "no call to the base's constructor"
    i_bl = calls[0]
    alloc = None
    for _, w in ins:                       # sizeof: `mov w1, #size` before the first blr
        c = const_def(w)
        if c is not None and c[0] == 1 and not isinstance(c[1], tuple):
            alloc = c[1]
            break
        if (w & 0xFFFFFC1F) == 0xD63F0000:
            break
    this_reg = None
    for p in range(i_bl - 4, max(a - 4, i_bl - 40), -4):
        if (words[p] & 0xFFE0FFFF) == 0xAA0003E0:   # mov x0, xN
            this_reg = (words[p] >> 16) & 31
            break
    if alloc is None or this_reg is None:
        return "not the factory's shape"
    vt = None
    regs: dict[int, int] = {}
    adds = []
    stored: dict[int, int] = {}
    got = {o: t for o, t in got_loads(m, a, size_)}
    o = i_bl + 4
    while o in words and words[o] != LDR_X0_SP_8:
        w = words[o]
        if o in got and vt is None:
            vt = got[o]
        if (w & 0xFFC00000) == 0x91000000:   # add xd, xn, #imm: the vptrs
            adds.append((w >> 10) & 0xFFF)
        c = const_def(w)
        if c is not None:
            rd, v = c
            if isinstance(v, tuple):
                if rd in regs:
                    regs[rd] = (regs[rd] & ~(0xFFFF << v[1])) | (v[2] << v[1])
            else:
                regs[rd] = v
            o += 4
            continue
        st = store(w)
        if st == "simd":
            return f"SIMD store at +{o - a:#x}"
        if st is not None:
            rn, parts = st
            if rn == 31:
                return f"stack store at +{o - a:#x}"
            if rn == this_reg:
                for rt, off, width in parts:
                    if off in (0, 0x48, 0x50) and width == 8 and rt != XZR:
                        continue
                    if rt == XZR:
                        val = 0
                    elif rt in regs:
                        val = regs[rt]
                    else:
                        return f"store of x{rt} at +{o - a:#x}"
                    for k in range(width):
                        stored[off + k] = (val >> (8 * k)) & 0xFF
        o += 4
    if vt is None:
        return "no vtable"
    if any(b < FACTORY_BASE_SIZE or b >= alloc for b in stored):
        return "stores outside its members"
    sec = sorted(i for i in adds if 0x10 < i < 0x800)
    if len(sec) != 2 or sec[1] - sec[0] != 0x40:
        return f"vtable offsets {sec}"
    extra = (sec[0] - 0x20) // 8 - FACTORY_BASE_SLOTS
    if extra < 0:
        return "a shorter vtable than the base's"
    fields = layout(FACTORY_BASE_SIZE, alloc, stored)
    parented = (m.word(i_bl + 4) & 0x9F000000) != 0x90000000 and any(v is not None for _, _, v in fields)
    return Factory(a, placeholder(vt), alloc, extra, fields, parented)


def got_loads(m: Module, a: int, size: int) -> list[tuple[int, int]]:
    """(address of the ldr, what the GOT slot holds) for a function's GOT loads."""
    from nx.refs import decode
    out = []
    for o, w, _, t in decode(m.img, a, size):
        if t is not None and (w & 0x3B000000) == 0x39000000 and isinstance(m.slots.get(t), int):
            out.append((a + o, m.slots[t]))
    return out


def factory_candidates(m: Module) -> list[int]:
    out = []
    for a, r in m.rows.items():
        if not r.sword_size or r.sword_size > 400 or r.status not in "UO":
            continue
        if r.status == "O" and not r.name.startswith("_ZN7Unk_New6Create"):
            continue
        if any(bl_target(p, w) == FACTORY_BASE_CTOR for p, w in m.words(a, r.sword_size)):
            out.append(a)
    return sorted(out)


def factory_name(cls: str) -> str:
    return (f"_ZN7Unk_New6CreateI{mangled_class(cls)}J15Unk_239a418_RefI11Unk_239a418ES4_EEEPT_"
            "P21Unk_239a418_AllocatorDpOT0_")


def member(off: int, width: int, value: int | None) -> str:
    ty = {8: "u64", 4: "u32", 2: "u16", 1: "u8"}[width]
    init = "" if value is None else " = 0" if value == 0 else f" = {value:#x}"
    return f"    {ty} field_{off:x}{init};"


def factory_class(f: Factory) -> str:
    out = [f"// 0x{f.addr + BASE:x}"]
    base = "Unk_23f43c8"
    fields = f.fields
    if f.parented:
        parent = f"{f.cls}_Parent"
        out += ["// Its members are its parent's: they're stored before its vptr.",
                f"class {parent} : public Unk_23f43c8 {{", "public:",
                "    using Unk_23f43c8::Unk_23f43c8;", f"    ~{parent}() override;", ""]
        out += [member(*x) for x in fields]
        out += ["};"]
        base, fields = parent, []
    out += [f"class {f.cls} : public {base} {{", "public:", f"    using {base}::{base};",
            f"    ~{f.cls}() override;"]
    out += [f"    virtual void vf{FACTORY_BASE_SLOTS + k}();" for k in range(f.extra_slots)]
    if fields:
        out.append("")
        out += [member(*x) for x in fields]
    out += ["};", f'static_assert(sizeof({f.cls}) == {f.size:#x}, "{f.cls}");',
            f"template {f.cls}* Unk_New::Create<{f.cls}>(Unk_239a418_Allocator*, Unk_Ref&&, Unk_Ref&&);"]
    return "\n".join(out) + "\n"


FACTORY_HEADER = """// Scope: common
//
// Unk_New::Create (src/gflib3/Unk_New.h) of classes on Unk_23f43c8
// (src/unsorted/Unk_23f43c8.h), each made from two references. The classes are
// named after their vtables; their members are what the factories store after
// the base's constructor. Written by tools/familygen.py: regenerate, don't
// edit.
#include "gflib3/Unk_New.h"
#include "unsorted/Unk_23f43c8.h"

using Unk_Ref = Unk_239a418_Ref<Unk_239a418>;
"""


# ------------------------------------------------------------------------- singletons

@dataclass
class Singleton:
    addr: int
    thunk: int
    cls: str
    instance: str
    extra_slots: int


def vtable_of(m: Module, slot: int) -> tuple[int, int, int, int]:
    """(address point, index, offset-to-top, slots) of the vtable a data slot is in."""
    def is_fn(s: int) -> bool:
        v = m.slots.get(s)
        return (isinstance(v, int) and v in m.funcs) or v == "__cxa_pure_virtual"
    ap = slot
    while is_fn(ap - 8):
        ap -= 8
    end = slot
    while is_fn(end + 8):
        end += 8
    return ap, (slot - ap) // 8, struct.unpack_from("<q", m.img, ap - 16)[0], (end - ap) // 8 + 1


def singletons(m: Module) -> list[Singleton]:
    seed = m.rows[SINGLETON_SEED]
    shape = m.shape(SINGLETON_SEED)
    prim, thunks = {}, {}
    for a, r in m.rows.items():
        if r.sword_size != seed.sword_size or r.status not in "UO" or m.shape(a) != shape:
            continue
        got = m.got_target(a, r.sword_size)
        if len(got) != 1:
            continue
        for s in m.data_refs(a):
            ap, idx, ott, n = vtable_of(m, s)
            if idx == 3 and ott == 0:
                prim.setdefault(a, (ap, n, got[0]))
            elif idx == 1 and ott == -0x48 and n == 2:
                thunks.setdefault(got[0], a)
    out = []
    for a, (ap, n, g) in sorted(prim.items()):
        if g in thunks:
            out.append(Singleton(a, thunks[g], placeholder(ap - 16), m.data_names.get(g, placeholder(g)), n - 4))
    return out


def singleton_names(s: Singleton) -> dict[int, str]:
    c = mangled_class(s.cls)
    return {s.addr: f"_ZN{c}3vf3Ev", s.thunk: f"_ZThn72_N{c}3vf3Ev"}


def singleton_class(s: Singleton) -> str:
    out = [f"class {s.cls} : public Unk_7c20_Base, public Unk_7c20_Interface {{", "public:",
           f"    ~{s.cls}() override;", "    void vf3() override;"]
    out += [f"    virtual void vf{4 + k}();" for k in range(s.extra_slots)]
    out += ["};", f"extern {s.cls}* {s.instance};", "",
            f"// 0x{s.addr + BASE:x}, its thunk from +0x48 0x{s.thunk + BASE:x}",
            f"void {s.cls}::vf3() {{", f"    Unk_7c20_Reset({s.instance});", "}"]
    return "\n".join(out) + "\n"


SINGLETON_HEADER = """// Scope: common
//
// Classes whose vf3 (slot 3 of their primary vtable, slot 1 of the one at +0x48)
// destroys the instance a global of theirs holds, the way Unk_239a418::vf3
// destroys an object: the global is cleared first, then the instance's
// destructor runs (a virtual call) and its memory goes back to the allocator
// it keeps (field_8; the allocation in field_10-field_20). The function doesn't
// use `this`, so its thunk is a copy. The classes are those instances
// (0x7100007860 creates Unk_236d328's and stores it in its global). Placeholder
// names, after the vtables and the globals' addresses. Written by
// tools/familygen.py: regenerate, don't edit.
#include "gflib3/Unk_239a418.h"

// Their primary base, 0x48 bytes laid out like Unk_239a418_Base.
class Unk_7c20_Base {
public:
    virtual ~Unk_7c20_Base();
    virtual void vf2();
    virtual void vf3();

    Unk_239a418_Allocator* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
};
static_assert(sizeof(Unk_7c20_Base) == 0x48, "Unk_7c20_Base");

// The interface at +0x48: the same two functions.
class Unk_7c20_Interface {
public:
    virtual void vf2();
    virtual void vf3();
};

// Clears `instance`, then destroys what it held.
template <class T>
void Unk_7c20_Reset(T*& instance) {
    T* p = instance;
    instance = nullptr;
    if (p != nullptr) {
        Unk_239a418_Allocator* allocator = p->field_8;
        u64 arg1 = p->field_10;
        u64 arg2 = p->field_18;
        u64 arg3 = p->field_20;
        p->~T();
        allocator->vf3(arg1, arg2, arg3);
    }
}
"""


# ------------------------------------------------------------------------- commands

def kept(m: Module, a: int, name: str, only: set[int] | None, everything: bool) -> bool:
    r = m.rows[a]
    return everything or (only is not None and a in only) or (r.status == "O" and r.name == name)


@dataclass
class Plan:
    vectors: dict = field(default_factory=dict)     # address -> variant
    factories: list = field(default_factory=list)
    singletons: list = field(default_factory=list)
    names: dict = field(default_factory=dict)       # address -> name
    candidates: dict = field(default_factory=dict)  # family -> [addresses]
    skipped: list = field(default_factory=list)     # (address, reason)


def plan(m: Module, only: set[int] | None = None, everything: bool = False) -> Plan:
    p = Plan()
    vc = vector_candidates(m)
    p.candidates["vectors"] = sorted(vc)
    for a, v in sorted(vc.items()):
        n = vector_name(v, placeholder(a))
        if kept(m, a, n, only, everything):
            p.vectors[a] = v
            p.names[a] = n
    fc = factory_candidates(m)
    p.candidates["factories"] = fc
    classes = set()
    for a in fc:
        f = parse_factory(m, a)
        if isinstance(f, str):
            p.skipped.append((a, f))
            continue
        n = factory_name(f.cls)
        if f.cls in classes or not kept(m, a, n, only, everything):
            continue
        classes.add(f.cls)
        p.factories.append(f)
        p.names[a] = n
    ss = singletons(m)
    p.candidates["singletons"] = [s.addr for s in ss] + [s.thunk for s in ss]
    for s in ss:
        ns = singleton_names(s)
        if all(kept(m, a, n, only, everything) for a, n in ns.items()):
            p.singletons.append(s)
            p.names.update(ns)
    return p


def sources(p: Plan) -> dict[str, str]:
    out = {}
    if p.vectors:
        out[VECTOR_FILE] = vector_source(p.vectors)
    if p.factories:
        out[FACTORY_FILE] = FACTORY_HEADER + "\n" + "\n".join(factory_class(f) for f in p.factories)
    if p.singletons:
        out[SINGLETON_FILE] = SINGLETON_HEADER + "\n" + "\n".join(singleton_class(s) for s in p.singletons)
    return out


def cmd_write(m: Module, args) -> None:
    from common import clang_format

    only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()} if args.only else None
    p = plan(m, only, args.all)
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for f in (VECTOR_FILE, FACTORY_FILE, SINGLETON_FILE):
        (OUT_DIR / f).unlink(missing_ok=True)
    written = []
    for f, text in sources(p).items():
        (OUT_DIR / f).write_text(text, encoding="utf-8", newline="\n")
        written.append(OUT_DIR / f)
    if written and not clang_format(written):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for a, n in sorted(p.names.items()):
            r = m.rows[a]
            fh.write(f"{n},{r.sword_str},{r.shield_str}\n")
    print(f"{len(p.vectors)} vector functions, {len(p.factories)} factories, "
          f"{len(p.singletons)} singletons; {len(p.names)} names in {args.names}", file=sys.stderr)


def cmd_census(m: Module, args) -> None:
    p = plan(m, everything=True)
    for fam, addrs in p.candidates.items():
        done = [a for a in addrs if m.rows[a].status == "O"]
        size = sum(m.rows[a].sword_size for a in addrs)
        dsize = sum(m.rows[a].sword_size for a in done)
        print(f"{fam:12s} {len(addrs):5d} candidates ({size:7d} bytes), {len(done):5d} matched ({dsize:7d} bytes)")
    reasons: dict[str, int] = {}
    for _, why in p.skipped:
        key = why.split(" at ")[0]
        reasons[key] = reasons.get(key, 0) + 1
    for why, n in sorted(reasons.items(), key=lambda kv: -kv[1]):
        print(f"  factories not written: {n:4d} {why}")


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("census")
    w = sub.add_parser("write")
    w.add_argument("--names", type=Path, required=True)
    g = w.add_mutually_exclusive_group()
    g.add_argument("--only", type=Path, help="addresses to write besides the kept ones")
    g.add_argument("--all", action="store_true", help="write every candidate (a trial)")
    args = ap.parse_args(argv)
    m = load()
    {"census": cmd_census, "write": cmd_write}[args.cmd](m, args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
