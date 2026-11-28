#!/usr/bin/env python3
"""Families of same-shape functions on gflib3's memory code, written from the executable.

    python tools/familygen.py census                     # candidates, written, matched, by family
    python tools/familygen.py write --names n.csv        # src/gflib3/families, and the names to give
    python tools/familygen.py write --names n.csv --all  # a trial: every candidate
    python tools/familygen.py write --names n.csv --only add.txt   # the kept ones and these

Unmatched functions that are the same code once branch targets and
adrp/lo12 fields are masked are instances of one source: a template, or a
class shape repeated. Eight such families are on gflib3's allocator
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
- `objects`: the same factory (`Unk_New::Create<T>`) for classes on a base
  constructed out of line (`OBJECT_BASES`): gflib3's object itself
  (0x71005e2350, no arguments: T's constructor takes the factory's) and
  Unk_23f4660 (0x7100e7f820, three: T inherits them). These factories are
  read by following one path through them (`walk`: symbolic registers, the
  allocator stack's overflow check and null references skipped), which gives
  what is loaded from each argument and when, what is stored to the object,
  and the references added and dropped. An argument loaded before the
  base's constructor is a by-value parameter: a reference moved in (the
  argument cleared) or copied from a const& (a reference added), a
  reference and a u64 moved together (`Unk_239a418_RefPair`), n u64s
  (`Unk_1085320_Words<n>`), or a scalar; one loaded after it is a const&
  read where a member is initialised. Members are the stores after the
  base's constructor: from a parameter (copied when a reference is added
  after the store, else moved) or constants, laid out like `factories`'.
  Each by-value reference must be dropped once, in reverse order, unless it
  was moved into a member. Members stored before the vtable is loaded are a
  parent's (`<T>_Parent`), as in `factories`. A derived class's members
  start at the base's data size: Unk_23f4660's tail padding (0x5cb) is used.
- `creators`: a template member of an owner (`Unk_790260_Owner::Create<T>`)
  that makes a T on Unk_23f4660 with the owner's allocator (the factory
  inlined: `construction` on the walk's events up to the result), sets its
  parent (0x7100e7fe20), pushes a reference to it into the owner's vector
  (whose slow path is the `vectors` instance 0x7100790490) and returns one.
  Everything after the construction must do what the seed's (0x7100790260)
  does, compared symbolically.
- `adders`: a template member of the owners of some of those objects
  (`Unk_1050c60_Owner::Unk_Add<T>`, in the objects' file after the classes):
  unless a flag is set, make a T from the owner's allocator with a weak
  reference to the owner (its handle and itself, `Unk_Weak`) and the
  arguments, by const reference; keep a reference to it in the owner's list
  (+0xb0, whose emplace 0x7101054f70 isn't decompiled); return a reference
  to the owner. The candidates are the functions of the seeds' shapes (one
  argument, none) that call the flag's getter, a factory and the emplace; an
  instance is written when its factory is (its class and the argument types
  are the factory's).
- `steps`: four virtual functions of those classes, the steps of a request,
  and the three thunks of their interface at +0x60, which inline them (in the
  objects' file, after the adders): vf7 makes what the step runs, once (a
  function of its own per class); vf9, vf10 and vf11 tell the owner behind
  the weak reference that the step is done (a function per kind of owner),
  failed or was cancelled (`Unk_1050c60_Owner::Unk_Cancel`, and `Unk_Fail` of
  the owner's kind, `STEP_OWNERS`: the owners differ by their result at
  +0x320, and so does what a failure hands them). A class is a step when the
  seven functions in its vtables have the shapes of the seed's
  (Unk_240b658's, vf10 one of the kinds') and call what they call; all seven
  are written or none.
- `makes`: what a step's vf7 calls, a function per class (in the objects'
  file, after the steps): make a task from the manager's allocator
  (`Unk_2771620_MakeUnique`: zeroed, then its vptrs), give it a weak
  reference to the step's interface and a copy of the step's member at
  +0x80, hand it to the manager (0x71006a1f80). The tasks are classes of
  their own, named after their vtables, with a last member that has a vtable
  too; their members are a class between their base and them. Written for
  the shapes of `MAKE_SEEDS` (a u32, a reference or two words copied; a task
  with nothing after that member, or with a zeroed u32); the body is spelled
  out in each, since clang inlines a shared one into vf7.

A row is kept (written again) when its name is the one written for it and
check.py matched it; `--only` adds addresses, `--all` writes every
candidate. A trial: `write --all`, name, check.py, then `write --only` with
the trial's names minus check.py's BAD addresses.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import re
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

OUT_DIR = ROOT / "src" / "gflib3" / "families"
# another generator's output (tools/shapes.py): what it defines isn't kept here
OTHER_DIRS = (ROOT / "src" / "unsorted" / "families",)
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


# ------------------------------------------------------------------------- the walk

class Sym:
    """A symbolic register value: `kind` names what it is, `key` the rest of it,
    `delta` a constant added (a pointer's adjustment)."""
    __slots__ = ("kind", "key", "delta")

    def __init__(self, kind: str, key: tuple = (), delta: int = 0):
        self.kind, self.key, self.delta = kind, key, delta

    def plus(self, n: int) -> Sym:
        return Sym(self.kind, self.key, self.delta + n)

    def ident(self) -> tuple:
        return (self.kind, self.key)

    def __eq__(self, other):
        return isinstance(other, Sym) and (self.kind, self.key, self.delta) == (other.kind, other.key, other.delta)

    def __hash__(self):
        return hash((self.kind, self.key, self.delta))

    def __repr__(self):
        return f"Sym({self.kind}, {self.key}, {self.delta:#x})"


class WalkError(Exception):
    pass


def _split_ops(op_str: str) -> list[str]:
    out, cur, depth = [], "", 0
    for ch in op_str:
        depth += ch == "["
        depth -= ch == "]"
        if ch == "," and not depth:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def _reg(op: str) -> tuple[int, int] | None:
    """(number, width in bytes) of a general register operand; 31 is the zero register."""
    if op in ("xzr", "wzr"):
        return XZR, 8 if op[0] == "x" else 4
    if op == "sp":
        return SP, 8
    if op in ("fp", "lr"):
        return (29 if op == "fp" else 30), 8
    if len(op) > 1 and op[0] in "xw" and op[1:].isdigit():
        return int(op[1:]), 8 if op[0] == "x" else 4
    return None


def _imm(op: str) -> int:
    return int(op.lstrip("#"), 0)


def _mem(ops: list[str], i: int) -> tuple[int, int, str] | None:
    """(base register, offset, mode) of ops[i], a memory operand: mode is "" (offset),
    "pre" (written back first) or "post" (written back after, by ops[i + 1])."""
    s = ops[i]
    if not s.startswith("["):
        return None
    pre = s.endswith("!")
    inner = [x.strip() for x in s.strip("[]!").split(",")]
    base = _reg(inner[0])
    if base is None:
        return None
    if len(inner) == 1:
        if len(ops) > i + 1 and ops[i + 1].startswith("#"):
            return base[0], _imm(ops[i + 1]), "post"
        return base[0], 0, ""
    if len(inner) == 2 and inner[1].startswith("#"):
        return base[0], _imm(inner[1]), "pre" if pre else ""
    return base[0], 0, "reg"   # register offset


SP = 32
STORE_WIDTH = {"str": 0, "stur": 0, "strb": 1, "sturb": 1, "strh": 2, "sturh": 2, "stp": 0}
LOAD_WIDTH = {"ldr": 0, "ldur": 0, "ldrb": 1, "ldurb": 1, "ldrh": 2, "ldurh": 2, "ldp": 0}
INV_COND = {"eq": "ne", "ne": "eq", "hs": "lo", "lo": "hs", "hi": "ls", "ls": "hi", "ge": "lt", "lt": "ge",
            "gt": "le", "le": "gt"}


@dataclass
class Walk:
    """What one path through a function did, in order: `events` are
    ("store", base, offset, width, value), ("load", base, offset, width, value),
    ("call", target), ("vcall", object, slot) and ("ret",)."""
    events: list = field(default_factory=list)


def disassemble(m: Module, a: int, size: int) -> list[tuple[int, str, list[str]]]:
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    out = [(i.address, i.mnemonic, _split_ops(i.op_str)) for i in md.disasm(m.img[a:a + size], a)]
    if len(out) != size // 4:
        raise WalkError("undecodable word")
    return out


def walk(m: Module, a: int, size: int, regs: dict[int, object], choose) -> Walk:
    """Follow one path through a function from `regs`, the symbolic arguments.

    Loads through argument pointers give symbolic values; a load from what a
    symbolic value points at is its vptr, a load from a vptr a slot, and `blr`
    of a slot a virtual call. adrp + ldr through the GOT gives ("got", target).
    `choose(mnemonic, value, target)` picks a conditional branch's way: True to
    branch, False to fall through, None to refuse the function. A register
    written by anything not followed is unknown (None); using an unknown
    pointer refuses the function (WalkError)."""
    insns = disassemble(m, a, size)
    at = {p: k for k, (p, _, _) in enumerate(insns)}
    w = Walk()
    r: dict[int, object] = dict(regs)
    pages: dict[int, int] = {}
    stack: dict[int, object] = {}       # what's stored at [sp, #offset] (sp moves only around the body)
    flags: tuple | None = None
    k, steps = 0, 0

    def get(op: str):
        rg = _reg(op)
        if rg is None:
            raise WalkError(f"operand {op}")
        if rg[0] == XZR:
            return 0
        v = r.get(rg[0])
        if isinstance(v, int) and rg[1] == 4:
            return v & 0xFFFFFFFF
        return v

    def put(op: str, v) -> None:
        rg = _reg(op)
        if rg is None:
            raise WalkError(f"operand {op}")
        if rg[0] != XZR:
            r[rg[0]] = v & 0xFFFFFFFF if isinstance(v, int) and rg[1] == 4 else v
            pages.pop(rg[0], None)

    def clobber() -> None:
        for n in range(0, 19):
            r.pop(n, None)
            pages.pop(n, None)

    while True:
        steps += 1
        if k >= len(insns) or steps > 4 * len(insns):
            raise WalkError("ran off the function")
        pc, mn, ops = insns[k]
        k += 1
        if mn in ("nop", "cmp", "cmn", "tst"):
            if mn == "cmp" and len(ops) == 2:
                flags = (get(ops[0]), _imm(ops[1]) if ops[1].startswith("#") else get(ops[1]))
            continue
        if mn == "ret":
            w.events.append(("ret",))
            return w
        if mn == "mov" and len(ops) == 2:
            put(ops[0], _imm(ops[1]) if ops[1].startswith("#") else get(ops[1]))
            continue
        if mn in ("movz", "movn", "movk"):
            v = _imm(ops[1])
            sh = int(ops[2].split("#")[1], 0) if len(ops) > 2 else 0
            width = _reg(ops[0])[1]
            if mn == "movk":
                old = get(ops[0])
                if not isinstance(old, int):
                    raise WalkError("movk of an unknown value")
                put(ops[0], (old & ~(0xFFFF << sh)) | (v << sh))
            else:
                v <<= sh
                put(ops[0], (~v) & ((1 << (8 * width)) - 1) if mn == "movn" else v)
            continue
        if mn == "orr" and len(ops) == 3 and _reg(ops[1]) and _reg(ops[1])[0] == XZR and ops[2].startswith("#"):
            put(ops[0], _imm(ops[2]))
            continue
        if mn == "adrp":
            put(ops[0], None)
            pages[_reg(ops[0])[0]] = _imm(ops[1])
            continue
        if mn in ("add", "sub") and len(ops) == 3 and ops[2].startswith("#"):
            src = _reg(ops[1])
            n = _imm(ops[2]) * (1 if mn == "add" else -1)
            if src and src[0] in pages:
                put(ops[0], Sym("adr", (pages[src[0]] + n,)))
                continue
            v = Sym("sp", (), 0) if src and src[0] == SP else get(ops[1])
            if _reg(ops[0])[0] == SP:
                continue
            put(ops[0], v.plus(n) if isinstance(v, Sym) else (v + n) & 0xFFFFFFFFFFFFFFFF if isinstance(v, int)
                else None)
            continue
        if mn in STORE_WIDTH or mn in LOAD_WIDTH:
            pair = mn in ("stp", "ldp")
            regs_ = ops[:2] if pair else ops[:1]
            mem = _mem(ops, 2 if pair else 1)
            if mem is None:
                raise WalkError(f"{mn} {ops}")
            base, off, mode = mem
            rw = _reg(regs_[0])
            if rw is None:
                raise WalkError(f"{mn} {ops}")     # a SIMD register
            width = (STORE_WIDTH.get(mn) if mn in STORE_WIDTH else LOAD_WIDTH[mn]) or rw[1]
            if base in pages and mode == "" and not pair and mn == "ldr":
                slot = pages[base] + off
                v = m.slots.get(slot)
                put(regs_[0], Sym("got", (v,)) if v is not None else Sym("data", (slot,)))
                w.events.append(("got", v))
                continue
            bv = None if base == SP else r.get(base)
            ea_off = 0 if mode == "post" else off
            if mode == "reg":
                if mn in STORE_WIDTH:
                    w.events.append(("store", bv, None, width, None))
                    continue
                put(regs_[0], None)
                continue
            for j, op in enumerate(regs_):
                o = ea_off + j * width
                if mn in STORE_WIDTH:
                    if base == SP:
                        stack[o] = get(op) if width == 8 else None
                    else:
                        w.events.append(("store", bv, (bv.delta if isinstance(bv, Sym) else 0) + o, width,
                                         get(op)))
                else:
                    if base == SP:
                        put(op, stack.get(o) if width == 8 and mode == "" else None)
                        continue
                    if bv is None:
                        put(op, None)
                        continue
                    if not isinstance(bv, Sym):
                        raise WalkError(f"load through {bv!r}")
                    v = Sym("mem", (bv.ident(), bv.delta + o, width))
                    w.events.append(("load", bv, bv.delta + o, width, v))
                    put(op, v)
            if mode in ("pre", "post") and base != SP:
                if not isinstance(bv, Sym):
                    raise WalkError("write-back of an unknown base")
                r[base] = bv.plus(off)
            continue
        if mn == "bl":
            t = _imm(ops[0])
            w.events.append(("call", t, {n: r.get(n) for n in range(8)}))
            clobber()
            r[0] = Sym("ret", (t, pc))
            continue
        if mn == "blr":
            f = get(ops[0])
            if not (isinstance(f, Sym) and f.kind == "mem"):
                raise WalkError("blr of an unknown function")
            (vkind, vkey), slot = f.key[0], f.key[1]
            if vkind != "mem" or f.delta:
                raise WalkError("blr of a function not in a vtable")
            obj_ident, obj_off, _ = vkey
            obj = Sym(obj_ident[0], obj_ident[1], obj_off)
            if r.get(0) != obj:
                raise WalkError("a virtual call on another object than x0")
            w.events.append(("vcall", obj, slot, {n: r.get(n) for n in range(1, 8)}))
            clobber()
            r[0] = Sym("ret", (obj.ident(), obj.delta, slot, pc))
            continue
        if mn == "b":
            k = at.get(_imm(ops[0]))
            if k is None:
                raise WalkError("a branch out of the function")
            continue
        if mn in ("cbz", "cbnz") or mn.startswith("b."):
            if mn.startswith("b."):
                value, tgt = (mn[2:], flags), _imm(ops[0])
            else:
                value, tgt = get(ops[0]), _imm(ops[1])
            way = choose(mn, value, tgt)
            if way is None:
                raise WalkError(f"{mn} at +{pc - a:#x}")
            if way:
                k = at.get(tgt)
                if k is None:
                    raise WalkError("a branch out of the function")
            continue
        if mn.startswith("b") and mn not in ("bic", "bics", "bfi", "bfxil"):
            raise WalkError(f"{mn}")
        # anything else: its destination is unknown
        if ops and _reg(ops[0]):
            put(ops[0], None)
            continue
        raise WalkError(f"{mn} {ops}")


# ------------------------------------------------------------------------- objects

OBJECT_CTOR = 0x5E2350      # Unk_239a418::Unk_239a418()
OBJECT_SLOTS = 6            # its primary vtable's slots
ABORT = 0x17E8FE0           # abort (PLT)
OBJECT_FILE = "Unk_1085320.cpp"
# the functions the objects and creators call out of line, named as declared
OUT_OF_LINE = {
    0xE7F820: "_ZN11Unk_23f4660C2EPvmm",
    0xE7FE20: "_ZN11Unk_23f466010Unk_e7fe20E15Unk_239a418_RefI11Unk_239a418E",
}
REF_ADD, REF_DROP = 0x10, 0x18      # the +0x48 interface's slots: add a reference, drop one
ALLOC_NEW = 0x10                    # the allocator's slot 2
SCALAR = {1: "u8", 2: "u16", 4: "u32", 8: "u64"}
SCALAR_CODE = {"u8": "h", "u16": "t", "u32": "j", "u64": "m"}
REF = "Unk_Ref"
PAIR = "Unk_239a418_RefPair"
# what a reference copied from a const& is kept as: its copy tests its own pointer
# (src/gflib3/Unk_239a418.h), which the factories' code shows
REF2 = "Unk_239a418_Ref2<Unk_239a418>"


@dataclass
class Param:
    kind: str           # "ref", "pair" (a reference and a u64), "words<n>" (n u64s), or a scalar type
    by_value: bool      # constructed before the base (a by-value parameter), else a const&
    moved: bool         # moved from the argument (which is cleared), else copied


@dataclass
class Member:
    offset: int
    kind: str                   # "ref", "pair", "words<n>", or a scalar type
    param: int | None = None    # initialised from this parameter, else to `value`
    value: int | None = None    # a constant (None without a param: uninitialised)
    moved: bool = False         # std::move(param)


@dataclass(frozen=True)
class ObjectBase:
    """A base the factories construct out of line: its constructor, data size
    (where a derived class's members start: the tail padding is reused),
    primary vtable's slots and constructor's parameters (none: the class
    takes its own; some: the class inherits them)."""
    name: str
    ctor: int
    size: int
    slots: int
    args: tuple = ()


OBJECT_BASES = {
    OBJECT_CTOR: ObjectBase("Unk_239a418", OBJECT_CTOR, 0x60, OBJECT_SLOTS),
    0xE7F820: ObjectBase("Unk_23f4660", 0xE7F820, 0x5CB, 17, ("void*", "u64", "u64")),
}


@dataclass
class ObjectFactory:
    addr: int
    cls: str
    size: int
    align: int
    extra_slots: int
    interface: bool             # an interface of its own at +0x60
    params: list
    members: list
    base: ObjectBase = OBJECT_BASES[OBJECT_CTOR]
    parented: bool = False      # its members are a parent's: stored before its vptrs


def object_candidates(m: Module) -> list[int]:
    out = []
    for a, r in m.rows.items():
        if not r.sword_size or r.sword_size > 1200 or r.status not in "UO":
            continue
        if r.status == "O" and not r.name.startswith("_ZN7Unk_New6Create"):
            continue
        calls = [t for t in (bl_target(p, w) for p, w in m.words(a, r.sword_size)) if t is not None]
        if calls and calls[0] == GET_TLS and sum(calls.count(c) for c in OBJECT_BASES) == 1:
            out.append(a)
    return sorted(out)


def _object_choose(mn: str, value, target: int, abort_at: set[int]):
    """An object factory's path: past the allocator stack's overflow check (a
    branch to abort), on with the allocation and every reference not null."""
    if mn.startswith("b."):
        return False if target in abort_at else None
    if isinstance(value, Sym) and value.kind in ("ret", "mem"):
        return mn == "cbnz"
    if isinstance(value, int) and mn in ("cbz", "cbnz"):
        return (value == 0) == (mn == "cbz")
    return None


def _is_stack(v) -> bool:
    return isinstance(v, Sym) and v.kind == "ret" and v.key[0] == GET_TLS


def _object_params(loads: dict, clears: dict, adds: dict, ctor: int) -> list[Param] | str:
    params = []
    for n in sorted(loads):
        ls = loads[n]
        shape = sorted({(off, width) for off, width, _, _ in ls})
        after = {i > ctor for _, _, i, _ in ls}
        cleared = clears.get(n, set())
        vid = next(v for off, _, _, v in ls if off == 0) if any(off == 0 for off, _, _, _ in ls) else None
        if len(after) != 1:
            return f"argument {n} read before and after the constructor"
        if cleared - {0}:
            return f"argument {n} cleared at {sorted(cleared)}"
        copied = any(i < ctor for i in adds.get(vid, []))
        words = len(shape) > 1 and shape == [(8 * k, 8) for k in range(len(shape))]
        if words and not cleared and not adds.get(vid):
            params.append(Param(f"words{len(shape)}", after == {False}, False))
        elif after == {False}:
            if shape == [(0, 8)] and cleared:
                params.append(Param("ref", True, True))
            elif shape == [(0, 8)] and copied:
                params.append(Param("ref", True, False))
            elif shape == [(0, 8), (8, 8)] and (cleared or copied):
                params.append(Param("pair", True, bool(cleared)))
            elif len(shape) == 1 and shape[0][0] == 0 and not cleared:
                params.append(Param(SCALAR[shape[0][1]], True, False))
            else:
                return f"argument {n}: {shape}"
        else:
            if len(shape) != 1 or shape[0][0] != 0 or cleared:
                return f"argument {n}: {shape} by reference"
            params.append(Param("ref" if shape == [(0, 8)] and adds.get(vid) else SCALAR[shape[0][1]], False, False))
    if sorted(loads) != list(range(2, 2 + len(params))):
        return f"arguments {sorted(loads)}"
    return params


def parse_object(m: Module, a: int) -> ObjectFactory | str:
    """An object factory's class and its constructor, or why it isn't one this tool writes."""
    size = m.rows[a].sword_size
    abort_at = {p for p, w in m.words(a, size) if bl_target(p, w) == ABORT}
    regs = {1: Sym("alloc")}
    for n in range(2, 8):
        regs[n] = Sym("arg", (n,))
    try:
        w = walk(m, a, size, regs, lambda mn, v, t: _object_choose(mn, v, t, abort_at))
    except WalkError as e:
        return f"walk: {e}"
    return construction(a, w.events)


def construction(a: int, ev: list, inherited: bool = False, allocator: Sym | None = None) -> ObjectFactory | str:
    """The class an allocation is constructed as, from a walk's events: the
    base's constructor called on it, then its vptrs and members stored, and
    the allocation recorded. `inherited`: the base's arguments are the
    caller's to check (a creator's); else they are the factory's arguments,
    by value, in order. `allocator`: what the allocation is made through (the
    factory's second argument by default)."""
    allocator = allocator or Sym("alloc")
    alloc = next((e for e in ev if e[0] == "vcall" and e[1] == allocator and e[2] == ALLOC_NEW), None)
    ctors = [i for i, e in enumerate(ev) if e[0] == "call" and e[1] in OBJECT_BASES]
    if alloc is None or len(ctors) != 1:
        return "not the factory's shape"
    ctor = ctors[0]
    ob = OBJECT_BASES[ev[ctor][1]]
    obj = ev[ctor][2][0]
    alloc_size, alloc_align = alloc[3].get(1), alloc[3].get(2)
    if not (isinstance(obj, Sym) and obj.kind == "ret" and obj.key[:2] == (allocator.ident(), allocator.delta)
            and not obj.delta):
        return "the constructor isn't called on the allocation"
    if not isinstance(alloc_size, int) or alloc_align not in (8, 16):
        return "not the factory's shape"
    oid = obj.ident()
    loads: dict[int, list] = {}
    clears: dict[int, set] = {}
    adds: dict[tuple, list] = {}
    drops: list = []
    stores: list = []
    vptrs: dict[int, tuple] = {}
    for i, e in enumerate(ev):
        if e[0] == "load":
            base = e[1]
            if base.kind == "arg":
                if base.delta:
                    return "a load through an adjusted argument"
                loads.setdefault(base.key[0], []).append((e[2], e[3], i, e[4].ident()))
            elif base.ident() == oid:
                return "reads the object"
        elif e[0] == "store":
            base, off, width, val = e[1:]
            if _is_stack(base):
                continue
            if isinstance(base, Sym) and base.kind == "arg":
                if val != 0 or base.delta:
                    return "a store to an argument"
                clears.setdefault(base.key[0], set()).add(off)
                continue
            if not (isinstance(base, Sym) and base.ident() == oid):
                return f"a store through {base!r}"
            if i < ctor:
                return "a store to the object before its constructor"
            if off is None:
                return "an indexed store to the object"
            record = {8: allocator, 0x10: obj, 0x18: alloc_size, 0x20: alloc_align}
            if off in record:
                if width != 8 or val != record[off]:
                    return f"a store at +{off:#x}"
                continue
            if isinstance(val, Sym) and val.kind == "got":
                if width != 8:
                    return "a narrow vptr store"
                vptrs[off] = (val.key[0], val.delta)
                continue
            if off < ob.size:
                return f"a store at +{off:#x}"
            stores.append((off, width, val, i))
        elif e[0] == "vcall":
            o, slot = e[1], e[2]
            if o == allocator:
                if slot != ALLOC_NEW:
                    return f"the allocator's slot {slot:#x}"
                continue
            if o.delta != 0x48 or slot not in (REF_ADD, REF_DROP):
                return f"a virtual call {slot:#x} on {o!r}"
            if slot == REF_ADD:
                adds.setdefault((o.kind, o.key), []).append(i)
            else:
                drops.append(((o.kind, o.key), i))
        elif e[0] == "call" and e[1] != GET_TLS and e[1] not in OBJECT_BASES:
            return f"a call to {e[1] + BASE:#x}"
    # the vptrs: one vtable's, at 0, 0x48 and 0x50, and at 0x60 for an interface
    if not {0, 0x48, 0x50} <= set(vptrs) <= {0, 0x48, 0x50, 0x60} or len({v for v, _ in vptrs.values()}) != 1:
        return f"vptrs at {sorted(vptrs)}"
    vt = vptrs[0][0]
    d = {off: dd for off, (_, dd) in vptrs.items()}
    extra = (d[0x48] - 0x20) // 8 - ob.slots
    if d[0] != 0x10 or extra < 0 or d[0x50] != d[0x48] + 0x40 or (0x60 in d and d[0x60] != d[0x50] + 0x28):
        return f"vtable offsets {sorted(d.values())}"
    if 0x60 in d and ob.size != 0x60:
        return "an interface after a bigger base"
    if ob.args:
        # the class inherits the base's constructor: its arguments are the factory's
        if inherited:
            if loads or clears:
                return "reads its arguments"
        else:
            regs = ev[ctor][2]
            want = [Sym("mem", (("arg", (n,)), 0, 8)) for n in range(2, 2 + len(ob.args))]
            if [regs.get(k) for k in range(1, 1 + len(ob.args))] != want or sorted(loads) != list(
                    range(2, 2 + len(ob.args))) or any(i > ctor or (o, wd) != (0, 8) for n in loads
                                                         for o, wd, i, _ in loads[n]) or clears or adds:
                return "the base's arguments aren't the factory's"
        params = [Param(t, True, False) for t in ob.args]
        loads = {}
    else:
        params = _object_params(loads, clears, adds, ctor)
        if isinstance(params, str):
            return params
    start = 0x68 if 0x60 in d else ob.size
    members = _object_members(params, loads, stores, adds, drops, ctor, alloc_size, start)
    if isinstance(members, str):
        return members
    if ob.args and any(s.param is not None for s in members):
        return "a member from the base's arguments"
    # members stored before the vtable is loaded: a class between it and the base holds them
    got = next((i for i, e in enumerate(ev) if i > ctor and e[0] == "got" and e[1] == vt), None)
    parented = got is not None and any(i < got for _, _, _, i in stores)
    if parented and not ob.args and params:
        return "a parent's members from its parameters"
    return ObjectFactory(a, placeholder(vt), alloc_size, alloc_align, extra, 0x60 in d, params, members, ob,
                         parented)


def _object_members(params, loads, stores, adds, drops, ctor, size, start) -> list[Member] | str:
    """The members from `start` to `size`: the parameters' and the constants'."""
    vids = {n: next(v for off, _, _, v in loads[n] if off == 0) for n in loads}
    by_vid = {}
    for n, v in vids.items():
        by_vid[v[1][0]] = n        # a load's ident: ("mem", (("arg", (n,)), off, width))
    special: dict[int, Member] = {}
    consts: dict[int, int] = {}
    seen = set()
    for off, width, val, i in stores:
        if isinstance(val, int):
            for k in range(width):
                consts[off + k] = (val >> (8 * k)) & 0xFF
            continue
        if not (isinstance(val, Sym) and val.kind == "mem" and val.key[0][0] == "arg" and not val.delta):
            return f"stores {val!r} at +{off:#x}"
        n, comp, cw = val.key[0][1][0], val.key[1], val.key[2]
        p = params[n - 2]
        if (n, comp) in seen:
            return f"argument {n} stored twice"
        seen.add((n, comp))
        if p.kind in ("ref", "pair"):
            if comp == 8 and p.kind == "pair":
                continue                  # checked with its reference
            if comp != 0 or width != 8:
                return f"argument {n} stored at +{off:#x}"
            if p.kind == "pair":
                tail = [s for s in stores if s[0] == off + 8]
                if len(tail) != 1 or tail[0][2] != Sym("mem", (("arg", (n,)), 8, 8)):
                    return f"argument {n}'s pair split"
            vid = vids[n]
            later = [j for j in adds.get(vid, []) if j > i]
            moved = not later
            if moved and not p.by_value:
                return f"argument {n} moved from a reference"
            special[off] = Member(off, p.kind, n - 2, moved=moved)
        elif p.kind.startswith("words"):
            if comp:
                continue                  # checked with the first word
            nw = int(p.kind[5:])
            got = {s[0]: s[2] for s in stores if off <= s[0] < off + 8 * nw and s[1] == 8}
            if got != {off + 8 * k: Sym("mem", (("arg", (n,)), 8 * k, 8)) for k in range(nw)}:
                return f"argument {n}'s words split"
            special[off] = Member(off, p.kind, n - 2)
        else:
            if comp != 0 or SCALAR.get(width) != p.kind and SCALAR.get(cw) != p.kind:
                return f"argument {n} stored at +{off:#x} as {width}"
            special[off] = Member(off, SCALAR[width], n - 2)
    # every reference added once per copy and dropped once per by-value copy
    for n, p in enumerate(params, 2):
        if p.kind not in ("ref", "pair"):
            continue
        vid = vids[n]
        mems = [s for s in special.values() if s.param == n - 2]
        want_adds = (p.by_value and not p.moved) + sum(not s.moved for s in mems)
        if len(adds.get(vid, [])) != want_adds:
            return f"argument {n}'s references added {len(adds.get(vid, []))} times"
        want_drops = 1 if p.by_value and not any(s.moved for s in mems) else 0
        if sum(1 for v, _ in drops if v == vid) != want_drops:
            return f"argument {n}'s references dropped"
    if len(drops) != sum(1 for v, _ in drops if v in vids.values()):
        return "drops a reference it doesn't hold"
    order = [by_vid[v[1][0]] for v, _ in drops]
    if order != sorted(order, reverse=True):
        return "drops its parameters out of order"
    widths = {"ref": 8, "pair": 16, "u8": 1, "u16": 2, "u32": 4, "u64": 8}
    widths.update({s.kind: 8 * int(s.kind[5:]) for s in special.values() if s.kind.startswith("words")})
    out = []
    off = start
    for so in sorted(special) + [size]:
        if so < off:
            return f"members overlap at +{so:#x}"
        gap = {b: v for b, v in consts.items() if off <= b < so}
        if so > off:
            out += [Member(o, SCALAR[wd], value=v) for o, wd, v in layout(off, so, gap)]
        if so == size:
            break
        s = special[so]
        if any(so <= b < so + widths[s.kind] for b in consts):
            return f"a constant inside the member at +{so:#x}"
        out.append(s)
        off = so + widths[s.kind]
    if any(b >= size or b < start for b in consts):
        return "stores outside its members"
    return out


def mangle_types(types: list[str], subs: list[str]) -> str:
    """Itanium mangling of the types of a template argument pack, with the
    substitutions `subs` already made (extended in place)."""
    def name(n: str) -> str:
        return f"{len(n)}{n}"

    def sub(full: str) -> str | None:
        if full in subs:
            i = subs.index(full)
            return "S_" if i == 0 else f"S{_b36(i - 1)}_"
        return None

    def plain(t: str) -> tuple[str, str]:
        """(mangled with substitutions, the full spelling) of a type without cv or &."""
        if t in SCALAR_CODE:
            return SCALAR_CODE[t], SCALAR_CODE[t]
        if t == "void*":
            s = sub("Pv")
            if s:
                return s, "Pv"
            subs.append("Pv")
            return "Pv", "Pv"
        if t == REF:
            tmpl, arg = name("Unk_239a418_Ref"), name("Unk_239a418")
            full = f"{tmpl}I{arg}E"
            s = sub(full)
            if s:
                return s, full
            out = sub(tmpl) or tmpl
            if tmpl not in subs:
                subs.append(tmpl)
            out += "I" + (sub(arg) or arg) + "E"
            if arg not in subs:
                subs.append(arg)
            subs.append(full)
            return out, full
        full = name(t)
        s = sub(full)
        if s:
            return s, full
        subs.append(full)
        return full, full

    out = ""
    for t in types:
        ref = t.endswith("&") and not t.endswith("&&")
        base = t.removeprefix("const ").removesuffix(" const&").rstrip("&")
        if not ref:
            out += plain(base)[0]
            continue
        full_k = "K" + plain_full(base)
        s = sub("R" + full_k)
        if s:
            out += s
            continue
        sk = sub(full_k)
        if sk:
            out += "R" + sk
        else:
            out += "RK" + plain(base)[0]
            subs.append(full_k)
        subs.append("R" + full_k)
    return out


def _b36(n: int) -> str:
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    s = ""
    while True:
        s = digits[n % 36] + s
        n //= 36
        if not n:
            return s


def plain_full(t: str) -> str:
    if t in SCALAR_CODE:
        return SCALAR_CODE[t]
    if t == "void*":
        return "Pv"
    if t == REF:
        return "15Unk_239a418_RefI11Unk_239a418E"
    return f"{len(t)}{t}"


def object_type(kind: str) -> str:
    if kind.startswith("words"):
        return f"Unk_1085320_Words{kind[5:]}"
    return {"ref": REF, "pair": PAIR}.get(kind, kind)


def words_struct(kind: str) -> str:
    n = int(kind[5:])
    body = "".join(f"    u64 field_{8 * k:x};\n" for k in range(n))
    return f"struct {object_type(kind)} {{\n{body}}};\n"


def cref(t: str) -> str:
    return f"{t} const&" if t.endswith("*") else f"const {t}&"


def create_args(f: ObjectFactory) -> list[str]:
    """Create's argument types (its pack, as deduced from them)."""
    out = []
    for p in f.params:
        t = object_type(p.kind)
        out.append(t if p.moved else cref(t))
    return out


def object_name(f: ObjectFactory) -> str:
    cls = mangled_class(f.cls)
    subs = ["7Unk_New", "7Unk_New6Create", cls]
    pack = mangle_types(create_args(f), subs)
    return f"_ZN7Unk_New6CreateI{cls}J{pack}EEEPT_P21Unk_239a418_AllocatorDpOT0_"


def object_class(f: ObjectFactory, step: Step | None = None) -> str:
    interface = f"Unk_1085320_Step<{step.owner.code}>" if step else "Unk_1085320_Interface"
    bases = f"public {f.base.name}" + (f", public {interface}" if f.interface else "")
    align = "alignas(16) " if f.align == 16 else ""
    copied = {k for k, p in enumerate(f.params) if p.kind == "ref" and not p.moved}
    ps = []
    for k, p in enumerate(f.params):
        t = object_type(p.kind)
        ps.append((f"{REF2 if k in copied else t} a{k}") if p.by_value else f"{cref(t)} a{k}")
    inits = []
    for s in f.members:
        if s.param is not None:
            inits.append(f"field_{s.offset:x}(" + (f"std::move(a{s.param})" if s.moved else f"a{s.param}") + ")")
    fields = []
    for s in f.members:
        if s.param is not None:
            t = REF2 if s.param in copied and s.kind == "ref" else object_type(s.kind)
            fields.append(f"    {t} field_{s.offset:x};")
        else:
            fields.append(member(s.offset, {"u8": 1, "u16": 2, "u32": 4, "u64": 8}[s.kind], s.value))
    out = [f"// 0x{f.addr + BASE:x}"]
    base = f.base.name
    if f.parented:
        parent = f"{f.cls}_Parent"
        out += ["// Its members are its parent's: they're stored before its vptrs.",
                f"class {align}{parent} : {bases} {{", "public:", f"    using {base}::{base};",
                f"    ~{parent}() override;", ""] + fields + ["};"]
        bases, base, fields = f"public {parent}", parent, []
    out += [f"class {align}{f.cls} : {bases} {{", "public:"]
    if f.base.args or f.parented:
        out.append(f"    using {base}::{base};")
    else:
        ctor = f"    {f.cls}({', '.join(ps)})"
        out.append(ctor + (" : " + ", ".join(inits) if inits else "") + " {}")
    out.append(f"    ~{f.cls}() override;")
    if step:
        out += ["    virtual void vf6();", "    virtual u64 vf7();", "    virtual void vf8();",
                "    void vf9() override;", f"    void vf10({step.owner.code} code) override;",
                "    void vf11() override;"]
    else:
        out += [f"    virtual void vf{f.base.slots + k}();" for k in range(f.extra_slots)]
    if fields:
        out += [""] + fields
    args = ", ".join(t if t.endswith("&") else t + "&&" for t in create_args(f))
    out += ["};", f'static_assert(sizeof({f.cls}) == {f.size:#x}, "{f.cls}");',
            f"template {f.cls}* Unk_New::Create<{f.cls}>(Unk_239a418_Allocator*" + (", " + args if args else "")
            + ");"]
    return "\n".join(out) + "\n"


OBJECT_HEADER = """// Scope: common
//
// Unk_New::Create (src/gflib3/Unk_New.h) of classes derived directly from
// gflib3's object (src/gflib3/Unk_239a418.h), its constructor out of line
// (0x71005e2350) and theirs inline, and of classes on Unk_23f4660
// (src/unsorted/Unk_23f4660.h), which inherit its constructor. The classes are named after their vtables;
// their constructors take what the factories read from the arguments: a
// reference or a reference and a u64 (moved in, or copied from a const&), a
// scalar by value, or a const& read after the base is constructed; their
// members are what the factories store after the base: those parameters and
// constants. Written by tools/familygen.py: regenerate, don't edit.
#include <memory>
#include <utility>

#include "gflib3/Unk_New.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"

using Unk_Ref = Unk_239a418_Ref<Unk_239a418>;

// A reference and a u64 passed together (moved: only the reference is cleared).
struct Unk_239a418_RefPair {
    Unk_Ref field_0;
    u64 field_8;
};

// Stands for the interface at +0x60 some of the classes have: each its own,
// only its vptr's place matters here.
class Unk_1085320_Interface {
public:
    virtual void vf0();
};

// A value that may be absent: the flag first.
template <class T>
struct Unk_1085320_Optional {
    Unk_1085320_Optional() : m_has(false) {}
    Unk_1085320_Optional(const Unk_1085320_Optional& other) : m_has(false) {
        if (other.m_has) {
            m_value = other.m_value;
            m_has = true;
        }
    }
    Unk_1085320_Optional& operator=(const Unk_1085320_Optional& other) {
        if (m_has) {
            if (other.m_has)
                m_value = other.m_value;
            else
                m_has = false;
        } else if (other.m_has) {
            m_value = other.m_value;
            m_has = true;
        }
        return *this;
    }

    bool m_has;
    T m_value;
};

// The interface at +0x60 of a step of a request (the steps, below): what its
// owner is told when the step is done, fails (with what a failure leaves,
// `Code`) or is cancelled.
template <class Code>
class Unk_1085320_Step {
public:
    virtual void vf9() = 0;
    virtual void vf10(Code code) = 0;
    virtual void vf11() = 0;
};
"""


# ------------------------------------------------------------------------- creators

CREATOR_SEED = 0x790260         # the first: Unk_790260_Owner::Create<Unk_23a8? >
CREATOR_FILE = "Unk_790260.cpp"
SET_PARENT = 0xE7FE20           # Unk_23f4660::Unk_e7fe20(Ref)
ABORT_IMPL = 0x17E9BC0          # nn::diag::detail::AbortImpl (PLT)
CREATOR_PUSH = 0x790490         # the owner's vector's __push_back_slow_path (vectors' Unk_790490)
CREATOR_CALLS = (GET_TLS, 0xE7F820, SET_PARENT, GET_TLS, CREATOR_PUSH, ABORT, ABORT_IMPL)
OWNER = "Unk_790260_Owner"


def creator_candidates(m: Module) -> list[int]:
    out = []
    for a, r in m.rows.items():
        if not r.sword_size or r.sword_size > 1200 or r.status not in "UO":
            continue
        if r.status == "O" and not r.name.startswith(f"_ZN{mangled_class(OWNER)}6Create"):
            continue
        calls = tuple(t for t in (bl_target(p, w) for p, w in m.words(a, r.sword_size)) if t is not None)
        if calls == CREATOR_CALLS:
            out.append(a)
    return sorted(out)


def abort_blocks(m: Module, a: int, size: int, targets: tuple) -> set[int]:
    """The addresses of the blocks that end in a call to one of `targets` (abort)."""
    out = set()
    words = dict(m.words(a, size))
    for p, w in words.items():
        if bl_target(p, w) in targets:
            q = p
            while q in words:
                out.add(q)
                prev = words.get(q - 4)
                if prev is None or (prev & 0x7C000000) in (0x14000000, 0x54000000) or (prev & 0x7E000000) in (
                        0x34000000, 0x36000000) or prev == 0xD65F03C0 or bl_target(q - 4, prev) is not None:
                    break
                q -= 4
    return out


def _creator_tail(ev: list, obj: Sym) -> list:
    """What a creator does after the construction, for comparing with the seed's:
    calls, virtual calls and stores outside the stack, symbolically (the
    object and stack addresses by kind, not by where they were made)."""
    def norm(v):
        if isinstance(v, Sym) and v.kind == "sp":
            return ("sp",)
        if isinstance(v, Sym) and v.ident() == obj.ident():
            return ("obj", v.delta)
        if isinstance(v, Sym) and v.kind == "mem":
            inner = Sym(v.key[0][0], v.key[0][1])
            return ("mem", norm(inner), v.key[1], v.key[2], v.delta)
        return v

    out = []
    for e in ev:
        if e[0] == "call":
            out.append(("call", e[1], tuple(norm(e[2].get(k)) for k in range(2))))
        elif e[0] == "vcall":
            out.append(("vcall", norm(e[1]), e[2]))
        elif e[0] == "store" and not _is_stack(e[1]):
            out.append(("store", norm(e[1]), e[2], e[3], norm(e[4])))
    return out


def parse_creator(m: Module, a: int, seed_tail: list | None = None) -> ObjectFactory | str:
    """A creator's class (the construction part of it), or why it isn't one this tool writes."""
    size = m.rows[a].sword_size
    abort_at = abort_blocks(m, a, size, (ABORT, ABORT_IMPL))

    def choose(mn, value, target):
        if target in abort_at or mn == "b.hs":
            return False        # not to abort, and the vector's fast path
        return _object_choose(mn, value, target, abort_at)

    regs = {0: Sym("self"), 1: Sym("parent"), 2: Sym("a2"), 8: Sym("sret")}
    try:
        w = walk(m, a, size, regs, choose)
    except WalkError as e:
        return f"walk: {e}"
    ev = w.events
    cut = next((i for i, e in enumerate(ev) if e[0] == "store" and e[1] == Sym("sret")), None)
    if cut is None:
        return "no result"
    allocator = Sym("mem", (("self", ()), 8, 8))
    f = construction(a, ev[:cut], inherited=True, allocator=allocator)
    if isinstance(f, str):
        return f
    if f.base.name != "Unk_23f4660" or f.interface:
        return "not on Unk_23f4660"
    ctor = next(e for e in ev if e[0] == "call" and e[1] == f.base.ctor)
    want = [Sym("self"), Sym("a2"), Sym("mem", (("self", ()), 0xA8, 8))]
    if [ctor[2].get(k) for k in (1, 2, 3)] != want:
        return "the base's arguments aren't the owner's"
    tail = _creator_tail(ev[cut:], ctor[2][0])
    if seed_tail is not None and tail != seed_tail:
        return "the creator's tail differs"
    f.creator_tail = tail
    return f


def creator_name(cls: str) -> str:
    o = mangled_class(OWNER)
    return (f"_ZN{o}6CreateI{mangled_class(cls)}EE15Unk_239a418_RefIT_ES2_I11Unk_239a418EPKc")


def creator_class(f: ObjectFactory) -> str:
    text = object_class(f)
    lines = text.rstrip("\n").split("\n")
    assert lines[-1].startswith("template ")
    lines[-1] = (f"template Unk_239a418_Ref<{f.cls}> {OWNER}::Create<{f.cls}>(Unk_Ref parent, const char* name);")
    return "\n".join(lines) + "\n"


CREATOR_HEADER = """// Scope: common
//
// The creators of an owner (Unk_790260_Owner, placeholder, src/gflib3/Unk_790260.h):
// each makes a class on Unk_23f4660 (src/unsorted/Unk_23f4660.h) with the
// owner's allocator, sets its parent, keeps a reference to it and returns one.
// One template, an instance per class; the classes are named after their
// vtables, their members are what the creators store after Unk_23f4660's
// constructor.
// Written by tools/familygen.py: regenerate, don't edit.
#include <nn/os.h>

#include "gflib3/Unk_790260.h"
#include "gflib3/Unk_New.h"

template <class T>
Unk_239a418_Ref<T> Unk_790260_Owner::Create(Unk_Ref parent, const char* name) {
    if (!parent.m_ptr)
        nn::diag::detail::AbortImpl("", "", "", 0);
    // Unk_23f4660's constructor (not decompiled) is declared with a u64 there.
    Unk_239a418_Ref<T> result(Unk_New().Create<T>(field_8, this, reinterpret_cast<u64>(name), u64(field_a8)));
    // Through the result, not the new object: clang then computes the
    // object's interface again for the vector's reference, as the original does.
    result.m_ptr->Unk_e7fe20(parent);
    field_78.push_back(
        Unk_239a418_Ref2<Unk_790490>(static_cast<Unk_790490*>(static_cast<Unk_239a418*>(result.m_ptr))));
    field_c0 = false;
    return result;
}
"""


# ------------------------------------------------------------------------- adders

ADDER_SEEDS = (0x1050C60, 0x1052DF0)   # Unk_1050c60_Owner::Unk_Add<T> with one argument, and with none
ADDER_OWNER = "Unk_1050c60_Owner"
ADDER_GETTER = 0x6CE100                # Unk_6ce100_getField110 (src/unsorted/leaf)
ADDER_LIST = 0x1054F70                 # the owner's list's emplace, not decompiled
ADDER_NAMES = {ADDER_LIST: "_ZN16Unk_1054f70_List11Unk_1054f70EO15Unk_239a418_RefI11Unk_239a418E"}


def adder_candidates(m: Module) -> dict[int, int]:
    """The adders (the functions of the seeds' shapes) and the factory each calls."""
    want = {(m.rows[s].sword_size, m.shape(s)) for s in ADDER_SEEDS if s in m.rows}
    out = {}
    for a, r in m.rows.items():
        if not r.sword_size or (r.sword_size, m.shape(a)) not in want:
            continue
        calls = [x for x in (bl_target(o, w) for o, w in m.words(a, r.sword_size)) if x is not None]
        if len(calls) == 3 and calls[0] == ADDER_GETTER and calls[2] == ADDER_LIST:
            out[a] = calls[1]
    return out


def adder_args(f: ObjectFactory) -> list[str] | None:
    """What an adder passes on to its factory after the weak reference: the
    types of its `const&` parameters. None when the factory takes anything
    else than a moved pair and const references."""
    args = create_args(f)
    if not args or args[0] != PAIR or not all(x.endswith("&") for x in args[1:]):
        return None
    return [x.removeprefix("const ").removesuffix(" const&").rstrip("&") for x in args[1:]]


def adder_name(f: ObjectFactory) -> str | None:
    args = adder_args(f)
    if args is None:
        return None
    owner, cls = mangled_class(ADDER_OWNER), mangled_class(f.cls)
    subs = [owner, f"{owner}7Unk_Add", cls]
    pack = mangle_types(args, subs)
    ret = mangle_types([REF], subs)
    return f"_ZN{owner}7Unk_AddI{cls}J{pack}EEE{ret}DpRKT0_"


def adder_instance(a: int, f: ObjectFactory) -> str:
    params = ", ".join(cref(object_type(x)) for x in adder_args(f))
    return f"// 0x{a + BASE:x}\ntemplate Unk_Ref {ADDER_OWNER}::Unk_Add<{f.cls}>({params});\n"


ADDER_HEADER = """
// The adders. An owner of such objects (a class on the object, with its
// allocator at +0x60 and a list of references at +0xb0) makes one with a weak
// reference to itself (its handle and itself) and what it is given, keeps a
// reference to it in the list and returns a reference to itself: one member
// template, an instance per class. A set flag (+0x110, through the leaf getter
// 0x71006ce100) skips the rest. The list's emplace (0x7101054f70) isn't
// decompiled.
struct Unk_6ce100;
u32 Unk_6ce100_getField110(const Unk_6ce100* self);
struct Unk_6ce3c0;
void Unk_6ce3c0_setField110(Unk_6ce3c0* self, u32 value);

// A type-erased callable, 0x80 bytes, like Unk_23d4470_Callable
// (src/unsorted/Unk_23d4470.h): an invoker (+0x0) that takes the storage
// (+0x20) and references to the arguments. Callers test it before they call it.
template <class Signature>
class Unk_1050c60_Callable;

template <class R, class... Args>
class Unk_1050c60_Callable<R(Args...)> {
public:
    explicit operator bool() const { return field_0 != nullptr; }
    R operator()(Args... args) { return field_0(field_20, std::forward<Args>(args)...); }

    R (*field_0)(void* storage, Args&&... args);
    void (*field_8)(void*);
    u64 field_10;
    u64 field_18;
    u8 field_20[0x60];
};

// An owner's result (+0x320): each kind of owner has its own.
struct Unk_1050c60_Result;

struct Unk_1054f70_List {
    void Unk_1054f70(Unk_Ref&& ref);

    u8 _0[0x60];
};

// A weak reference to an object: its handle, and the object itself.
inline Unk_239a418_RefPair Unk_Weak(Unk_239a418* object) {
    if (object == nullptr)
        return Unk_239a418_RefPair{Unk_Ref(), 0};
    Unk_239a418_Ref<Unk_239a418_Handle> handle(object->m_handle);
    return Unk_239a418_RefPair{Unk_Ref(reinterpret_cast<Unk_239a418*>(handle.m_ptr)),
                               reinterpret_cast<u64>(object)};
}

class Unk_1050c60_Owner : public Unk_239a418 {
public:
    template <class T, class... Args>
    Unk_Ref Unk_Add(const Args&... args) {
        if (Unk_6ce100_getField110(reinterpret_cast<const Unk_6ce100*>(this)))
            return Unk_Ref(this);
        Unk_239a418_Allocator* allocator = field_60;
        Unk_Ref object(Unk_New().Create<T>(allocator, Unk_Weak(this), args...));
        field_b0.Unk_1054f70(Unk_Ref(object));
        return Unk_Ref(this);
    }

    void Unk_6ce580();
    void Unk_SetState(u32 state) { Unk_6ce3c0_setField110(reinterpret_cast<Unk_6ce3c0*>(this), state); }
    void Unk_Cancel() {
        Unk_6ce580();
        Unk_SetState(6);
        if (field_2a0)
            field_2a0();
        if (field_1a0)
            field_1a0();
    }

    Unk_239a418_Allocator* field_60;
    u8 _68[0x48];
    Unk_1054f70_List field_b0;
    u32 field_110;
    u8 _114[0x8c];
    alignas(16) Unk_1050c60_Callable<void()> field_1a0;
    Unk_1050c60_Callable<void(Unk_1050c60_Result&)> field_220;
    Unk_1050c60_Callable<void()> field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_1050c60_Owner, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_1050c60_Owner, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_1050c60_Owner, field_1a0, 0x1a0);
PKMN_SIZE_ASSERT(Unk_1050c60_Owner, 0x320);
"""


# ------------------------------------------------------------------------- steps

STEP_SEED = 0x240B658            # the vtables of Unk_240b658, whose seven functions are the shapes
STEP_INTERFACE = 0xE8            # its interface's slots, from the first vtable's start
STEP_STOP = 0x6CE580             # Unk_1050c60_Owner::Unk_6ce580, not decompiled
STEP_SET_STATE = 0x6CE3C0        # Unk_6ce3c0_setField110 (src/unsorted/leaf)
STEP_NAMES = {STEP_STOP: "_ZN17Unk_1050c60_Owner10Unk_6ce580Ev"}


@dataclass(frozen=True)
class StepOwner:
    """An owner with a result: what its steps' failure hands it (`code`,
    mangled `mangled`) and the members after the owner's own (0x320)."""
    name: str
    code: str
    mangled: str
    members: tuple[str, ...]
    param: str                   # Unk_Fail's parameter, by value
    arg: str                     # what a step passes for it
    keep: str                    # how Unk_Fail keeps it


_OPTIONAL = "const Unk_1085320_Optional<u32>*"
_OPTIONAL_MANGLED = "PK20Unk_1085320_OptionalIjE"
# by the address of vf10 of the first class of each
STEP_OWNERS = {
    0x1054690: StepOwner("Unk_1054690_Owner", _OPTIONAL, _OPTIONAL_MANGLED,
                         ("u8 field_320[0x3c];", "Unk_1085320_Optional<u32> field_35c;"),
                         "Unk_1085320_Optional<u32>", "*code", "field_35c = code;"),
    0x1056D00: StepOwner("Unk_1056d00_Owner", _OPTIONAL, _OPTIONAL_MANGLED,
                         ("u8 field_320[0x34];", "Unk_1085320_Optional<u32> field_354;"),
                         "Unk_1085320_Optional<u32>", "*code", "field_354 = code;"),
    0x1059AA0: StepOwner("Unk_1059aa0_Owner", "u64", "m", ("u64 field_320;",), "u64", "code", "field_320 = code;"),
}


@dataclass
class Step:
    cls: str
    funcs: dict                 # "vf7", "vf9", "vf10", "vf11" and their thunks "t9", "t10", "t11" -> address
    owner: StepOwner
    make: int                   # what vf7 calls
    done: int                   # what vf9 tail-calls with the owner


def _calls(m: Module, a: int) -> tuple[list[int], list[int]]:
    """A function's bl targets, and its b targets outside itself."""
    size = m.rows[a].sword_size
    bls, bs = [], []
    for o, w in m.words(a, size):
        if (w & 0xFC000000) == 0x94000000:
            bls.append(o + _sext(w & 0x3FFFFFF, 26) * 4)
        elif (w & 0xFC000000) == 0x14000000:
            x = o + _sext(w & 0x3FFFFFF, 26) * 4
            if not a <= x < a + size:
                bs.append(x)
    return bls, bs


def step_slots(m: Module, vt: int) -> dict | None:
    """The seven functions of a step's vtables that the family writes."""
    out = {f"vf{k}": m.slots.get(vt + 0x10 + 8 * k) for k in (7, 9, 10, 11)}
    out.update({f"t{9 + k}": m.slots.get(vt + STEP_INTERFACE + 8 * k) for k in range(3)})
    if not all(isinstance(a, int) and a in m.rows and m.rows[a].sword_size for a in out.values()):
        return None
    return out


def parse_step(m: Module, f: ObjectFactory) -> Step | str:
    """The step a written object is, or why it isn't one."""
    if not f.interface or f.extra_slots != 6 or f.base.args or not f.params or f.params[0].kind != "pair":
        return "not a class with a weak reference and the interface"
    if not any(s.offset == 0x80 for s in f.members) or not any(s.offset == 0x78 and s.kind == "u64"
                                                               for s in f.members):
        return "no members at +0x78 and +0x80"
    seed, funcs = step_slots(m, STEP_SEED), step_slots(m, int(f.cls[4:], 16))
    if seed is None or funcs is None:
        return "its vtables' slots aren't functions"

    def same(key: str, like: int | None = None) -> bool:
        a, b = funcs[key], seed[key] if like is None else like
        return m.rows[a].sword_size == m.rows[b].sword_size and m.shape(a) == m.shape(b)

    if not all(same(k) for k in ("vf7", "vf9", "vf11", "t9", "t11")):
        return "other shapes"
    owner = None
    for first, o in STEP_OWNERS.items():
        # the thunk of that first class's vf10: the same slot of its interface
        vt = next((v for v in (s - 0x10 - 8 * 10 for s in m.data_refs(first)) if step_slots(m, v)), None)
        if vt is not None and same("vf10", first) and same("t10", step_slots(m, vt)["t10"]):
            owner = o
    if owner is None:
        return "another failure"
    for k in ("vf10", "vf11", "t10", "t11"):
        if _calls(m, funcs[k])[0] != [STEP_STOP, STEP_SET_STATE]:
            return "other calls"
    make, done = _calls(m, funcs["vf7"])[0], _calls(m, funcs["vf9"])[1]
    if len(make) != 1 or len(done) != 1 or _calls(m, funcs["t9"])[1] != done:
        return "other calls"
    return Step(f.cls, funcs, owner, make[0], done[0])


def step_names(m: Module, s: Step) -> dict[int, str] | str:
    """The names of a step's functions and of the two it calls, or why they can't be given."""
    cls = mangled_class(s.cls)
    names = {
        s.funcs["vf7"]: f"_ZN{cls}3vf7Ev", s.funcs["vf9"]: f"_ZN{cls}3vf9Ev",
        s.funcs["vf10"]: f"_ZN{cls}4vf10E{s.owner.mangled}", s.funcs["vf11"]: f"_ZN{cls}4vf11Ev",
        s.funcs["t9"]: f"_ZThn96_N{cls}3vf9Ev", s.funcs["t10"]: f"_ZThn96_N{cls}4vf10E{s.owner.mangled}",
        s.funcs["t11"]: f"_ZThn96_N{cls}4vf11Ev",
        s.make: f"_Z{len(placeholder(s.make))}{placeholder(s.make)}P{cls}Pv",
        s.done: f"_Z{len(placeholder(s.done))}{placeholder(s.done)}P17Unk_1050c60_Owner",
    }
    for a in (s.make, s.done):
        r = m.rows.get(a)
        if r is None:
            return f"0x{a + BASE:x} isn't a function"
        if r.name and r.name != names[a]:
            return f"0x{a + BASE:x} is named otherwise"
    return names


def step_functions(s: Step) -> str:
    cls, f = s.cls, s.funcs
    return f"""// 0x{f["vf7"] + BASE:x}
u64 {cls}::vf7() {{
    if (field_78 == 0)
        field_78 = {placeholder(s.make)}(this, &field_80);
    return field_78;
}}

// 0x{f["vf9"] + BASE:x}
// 0x{f["t9"] + BASE:x}
void {cls}::vf9() {{
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        {placeholder(s.done)}(owner);
}}

// 0x{f["vf10"] + BASE:x}
// 0x{f["t10"] + BASE:x}
void {cls}::vf10({s.owner.code} code) {{
    if ({s.owner.name}* owner = Unk_WeakGet<{s.owner.name}>(field_68))
        owner->Unk_Fail({s.owner.arg});
}}

// 0x{f["vf11"] + BASE:x}
// 0x{f["t11"] + BASE:x}
void {cls}::vf11() {{
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}}
"""


def step_header(steps: list[Step]) -> str:
    owners = []
    for o in STEP_OWNERS.values():
        if not any(s.owner is o for s in steps):
            continue
        members = "\n".join(f"    {x}" for x in o.members)
        owners.append(f"""class {o.name} : public Unk_1050c60_Owner {{
public:
    void Unk_Fail({o.param} code) {{
        {o.keep}
        Unk_6ce580();
        Unk_SetState(4);
        if (field_220)
            field_220(reinterpret_cast<Unk_1050c60_Result&>(field_320));
        if (field_1a0)
            field_1a0();
    }}

{members}
}};
""")
    decls = sorted({f"u64 {placeholder(s.make)}({s.cls}* self, void* arg);" for s in steps}
                   | {f"void {placeholder(s.done)}(Unk_1050c60_Owner* owner);" for s in steps})
    return STEP_HEADER + "\n" + "\n".join(owners) + "\n" + "\n".join(decls) + "\n"


STEP_HEADER = """
// The steps: the classes the adders make are the steps of a request, and four
// of their virtual functions are the same in every one of them (so are the
// interface's thunks, which inline them). vf7 makes what the step runs, once
// (a function of its own per class, not decompiled). The other three are the
// interface: they tell the owner, if the weak reference still has one, that
// the step is done (a function of the owner's, not decompiled), that it
// failed (the owner keeps what the failure leaves, stops, goes to state 4 and
// calls its failure callable with its result, then its last one) or that it
// was cancelled (state 6, the cancel callable, the last one). The owners
// differ by their result, at +0x320: three kinds are known by their steps.

// The weak reference's object, while its handle counts references.
template <class T>
inline T* Unk_WeakGet(const Unk_239a418_RefPair& weak) {
    Unk_239a418_Handle* handle = reinterpret_cast<Unk_239a418_Handle*>(weak.field_0.m_ptr);
    if (handle != nullptr && handle->field_54.load() != 0)
        return reinterpret_cast<T*>(weak.field_8);
    return nullptr;
}
"""


# ------------------------------------------------------------------------- makes

MAKE_MANAGER = 0x2778C18         # the global the makes read: the manager (data symbol Unk_2778c18)
MAKE_ALLOCATOR = 0x6A1F70        # Unk_6a1f70_getField58 (src/unsorted/leaf): the manager's allocator
MAKE_RUN = 0x6A1F80              # the manager takes the task, not decompiled
MAKE_NAMES = {MAKE_RUN: "_Z10Unk_6a1f80P10Unk_6a1f70NSt3__110unique_ptrI15Unk_6a1f80_Task19Unk_23f4660_DeleterEE"}
@dataclass(frozen=True)
class MakeShape:
    """A shape of make: the type of the step's member at +0x80, the task's
    member that keeps a copy of it (+0x28), the task's members after the one
    with a vtable that follows, and whether the task's vtable is loaded
    before that member's.

    The members after that one are a class of the task's own between the
    members' class and the task: initialised after the member's vptr is
    stored and before the task's."""
    arg: str
    member: str
    after: tuple[str, ...] = ()
    task_first: bool = False


_REF_MEMBER = "Unk_1054d30_Ref<Unk_239a418>"
# by their first function
MAKE_SEEDS = {
    0x1054D30: MakeShape("u32", "u32"),
    0x10868C0: MakeShape("Unk_Ref", _REF_MEMBER),
    0x10B2610: MakeShape("u32", "u32", after=("u32 field_38 = 0;",)),
    0x10B3120: MakeShape("Unk_1085320_Words2", "Unk_1085320_Words2", task_first=True),
}


@dataclass
class Make:
    addr: int
    step: Step
    shape: MakeShape
    task: int                   # the task's vtable
    tail: int                   # the vtable of the task's last member

    @property
    def arg(self) -> str:
        return self.shape.arg

    @property
    def member(self) -> str:
        return self.shape.member


def parse_make(m: Module, s: Step) -> Make | str:
    """What a step's vf7 calls, when it has the shape of a seed."""
    r = m.rows[s.make]
    seed = next((x for x in MAKE_SEEDS if x in m.rows and m.rows[x].sword_size == r.sword_size
                 and m.shape(x) == m.shape(s.make)), None)
    if seed is None:
        return "another shape"
    shape = MAKE_SEEDS[seed]
    got = m.got_target(s.make, r.sword_size)
    if len(got) != 4 or got[0] != MAKE_MANAGER:
        return "other globals"
    calls = _calls(m, s.make)[0]
    if calls[:1] != [MAKE_ALLOCATOR] or MAKE_RUN not in calls:
        return "other calls"
    task, tail = (got[2], got[3]) if shape.task_first else (got[3], got[2])
    return Make(s.make, s, shape, task, tail)


def make_classes(makes: list[Make]) -> str | list[str]:
    """The tasks and their last members, each once; an error if two makes disagree on a task."""
    tails, tasks, out = set(), {}, []
    for k in makes:
        spec = (k.step.owner.code, k.shape, k.tail)
        if k.task in tasks:
            if tasks[k.task] != spec:
                return f"the task {placeholder(k.task)} is made two ways"
            continue
        tasks[k.task] = spec
        if k.tail not in tails:
            tails.add(k.tail)
            out.append(f"class {placeholder(k.tail)} {{\npublic:\n    virtual void vf0();\n}};\n")
        members = (f"Unk_1054d30_TaskOf<Unk_1085320_Step<{k.step.owner.code}>, {k.member}, "
                   f"{placeholder(k.tail)}>")
        if k.shape.after:
            # more members after that one: a class of the task's own between the two
            after = "".join(f"    {x}\n" for x in k.shape.after)
            out.append(f"class {placeholder(k.task)}_Members\n    : public {members} {{\npublic:\n{after}}};\n")
            members = f"{placeholder(k.task)}_Members"
        out.append(f"class {placeholder(k.task)}\n    : public {members} {{\npublic:\n"
                   f"    ~{placeholder(k.task)}() override;\n}};\n")
    return out


def make_function(k: Make) -> str:
    # written out in each: through a shared inline function, clang inlines the
    # make into the vf7 that calls it
    return f"""// 0x{k.addr + BASE:x}
u64 {placeholder(k.addr)}({k.step.cls}* self, void* arg) {{
    Unk_6a1f70* manager = Unk_2778c18;
    if (manager == nullptr)
        return 0;
    Unk_239a418_Allocator* allocator = reinterpret_cast<Unk_239a418_Allocator*>(Unk_6a1f70_getField58(manager));
    if (allocator == nullptr)
        return 0;
    auto task = Unk_2771620_MakeUnique<{placeholder(k.task)}>(allocator);
    task->field_18 = Unk_1054d30_MakeWeak<Unk_1085320_Step<{k.step.owner.code}>>(self);
    task->field_28 = *static_cast<const {k.arg}*>(arg);
    return Unk_6a1f80(manager, std::move(task));
}}
"""


MAKE_HEADER = """
// The makes: what a step's vf7 calls. Each makes a task from the manager's
// allocator (the global Unk_2778c18, its allocator through the leaf getter
// 0x71006a1f70), gives it a weak reference to the step's interface and a copy
// of the step's member at +0x80, and hands it to the manager (0x71006a1f80,
// not decompiled), which returns what the step keeps. The tasks are classes
// of their own (their vtables are all the executable says about them): a
// base of 0x18 bytes, the weak reference, the copy, and a last member with a
// vtable of its own; they have no constructor, they're zeroed where they're made.

// A reference with no constructor of its own (zeroed with its owner), whose
// copy tests the pointer it stored and whose assignment takes a copy and swaps.
template <class T>
class Unk_1054d30_Ref {
public:
    Unk_1054d30_Ref() = default;
    Unk_1054d30_Ref(const Unk_1054d30_Ref& other) : m_ptr(other.m_ptr) {
        if (m_ptr)
            static_cast<Unk_239a458*>(m_ptr)->vf4();
    }
    Unk_1054d30_Ref(const Unk_239a418_Ref<T>& other) : m_ptr(other.m_ptr) {
        if (m_ptr)
            static_cast<Unk_239a458*>(m_ptr)->vf4();
    }
    ~Unk_1054d30_Ref() {
        if (m_ptr) {
            static_cast<Unk_239a458*>(m_ptr)->vf5();
            m_ptr = nullptr;
        }
    }
    Unk_1054d30_Ref& operator=(Unk_1054d30_Ref other) {
        T* p = other.m_ptr;
        other.m_ptr = m_ptr;
        m_ptr = p;
        return *this;
    }

    T* m_ptr;
};

// A weak reference: the object's handle, and the object as a T.
template <class T>
struct Unk_1054d30_Weak {
    Unk_1054d30_Weak() = default;
    Unk_1054d30_Weak(const Unk_1054d30_Ref<Unk_239a418_Handle>& handle, T* ptr) : m_handle(handle), m_ptr(ptr) {}

    Unk_1054d30_Ref<Unk_239a418_Handle> m_handle;
    T* m_ptr;
};

inline Unk_1054d30_Ref<Unk_239a418_Handle> Unk_1054d30_Handle(const Unk_239a418* object) {
    return Unk_1054d30_Ref<Unk_239a418_Handle>(object->m_handle);
}

template <class T, class U>
inline Unk_1054d30_Weak<T> Unk_1054d30_MakeWeak(U* object) {
    if (object == nullptr)
        return Unk_1054d30_Weak<T>();
    return Unk_1054d30_Weak<T>(Unk_1054d30_Handle(object), object);
}

struct Unk_6a1f70;
u64 Unk_6a1f70_getField58(const Unk_6a1f70* self);
extern Unk_6a1f70* Unk_2778c18;

// What the manager runs: the tasks' base.
class Unk_6a1f80_Task {
public:
    virtual ~Unk_6a1f80_Task();

    u64 field_8;
    u64 field_10;
};

u64 Unk_6a1f80(Unk_6a1f70* manager, std::unique_ptr<Unk_6a1f80_Task, Unk_23f4660_Deleter> task);

// A task's members: they're a class between the base and the task (the
// task's vptr is stored before its last member's).
template <class Step, class Arg, class Tail>
class Unk_1054d30_TaskOf : public Unk_6a1f80_Task {
public:
    Unk_1054d30_Weak<Step> field_18;
    Arg field_28;
    Tail field_30;
};
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

ADDR_COMMENT = re.compile(r"^// 0x(71[0-9a-f]{8})$", re.M)
_elsewhere: set[int] | None = None


def written_elsewhere(dirs=None) -> set[int]:
    """The functions other generators' files define (their address comments), relative to BASE."""
    global _elsewhere
    if dirs is None and _elsewhere is not None:
        return _elsewhere
    out = set()
    for d in dirs if dirs is not None else OTHER_DIRS:
        for p in sorted(d.glob("*.cpp")) if d.exists() else ():
            out.update(int(x, 16) - BASE for x in ADDR_COMMENT.findall(p.read_text(encoding="utf-8")))
    if dirs is None:
        _elsewhere = out
    return out


def kept(m: Module, a: int, name: str, only: set[int] | None, everything: bool) -> bool:
    r = m.rows[a]
    if a in written_elsewhere():
        return False
    return everything or (only is not None and a in only) or (r.status == "O" and r.name == name)


@dataclass
class Plan:
    vectors: dict = field(default_factory=dict)     # address -> variant
    factories: list = field(default_factory=list)
    singletons: list = field(default_factory=list)
    objects: list = field(default_factory=list)
    creators: list = field(default_factory=list)
    adders: list = field(default_factory=list)       # (address, its factory)
    steps: list = field(default_factory=list)
    makes: list = field(default_factory=list)
    names: dict = field(default_factory=dict)       # address -> name
    candidates: dict = field(default_factory=dict)  # family -> [addresses]
    skipped: list = field(default_factory=list)     # (family, address, reason)


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
            p.skipped.append(("factories", a, f))
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
    oc = object_candidates(m)
    p.candidates["objects"] = oc
    for a in oc:
        o = parse_object(m, a)
        if isinstance(o, str):
            p.skipped.append(("objects", a, o))
            continue
        n = object_name(o)
        if o.cls in classes or not kept(m, a, n, only, everything):
            continue
        classes.add(o.cls)
        p.objects.append(o)
        p.names[a] = n
    cc = creator_candidates(m)
    p.candidates["creators"] = cc
    seed = parse_creator(m, CREATOR_SEED)
    seed_tail = None if isinstance(seed, str) else seed.creator_tail
    for a in cc:
        c = parse_creator(m, a, seed_tail)
        if isinstance(c, str):
            p.skipped.append(("creators", a, c))
            continue
        n = creator_name(c.cls)
        if c.cls in classes or not kept(m, a, n, only, everything):
            continue
        classes.add(c.cls)
        p.creators.append(c)
        p.names[a] = n
    ac = adder_candidates(m)
    p.candidates["adders"] = sorted(ac)
    written = {o.addr: o for o in p.objects}
    for a in sorted(ac):
        o = written.get(ac[a])
        n = adder_name(o) if o is not None else None
        if n is None:
            p.skipped.append(("adders", a, "its factory isn't written" if o is None
                              else "its factory takes more than const references"))
            continue
        if kept(m, a, n, only, everything):
            p.adders.append((a, o))
            p.names[a] = n
    if p.adders:
        p.names.update(ADDER_NAMES)
    p.candidates["steps"] = []
    for o in p.objects:
        s = parse_step(m, o)
        if isinstance(s, str):
            if o.params and o.params[0].kind == "pair" and o.interface:
                p.skipped.append(("steps", o.addr, s))
            continue
        p.candidates["steps"] += sorted(s.funcs.values())
        ns = step_names(m, s)
        if isinstance(ns, str):
            p.skipped.append(("steps", o.addr, ns))
            continue
        if all(kept(m, a, ns[a], only, everything) for a in s.funcs.values()):
            p.steps.append(s)
            p.names.update(ns)
    if p.steps:
        p.names.update(STEP_NAMES)
    p.candidates["makes"] = sorted(s.make for s in p.steps)
    for s in p.steps:
        k = parse_make(m, s)
        if isinstance(k, str):
            p.skipped.append(("makes", s.make, k))
        elif kept(m, k.addr, p.names[k.addr], only, everything):
            p.makes.append(k)
    if isinstance(make_classes(p.makes), str):
        p.skipped += [("makes", k.addr, make_classes(p.makes)) for k in p.makes]
        p.makes = []
    if p.makes:
        p.names.update(MAKE_NAMES)
    if p.objects or p.creators:
        p.names.update(OUT_OF_LINE)
    return p


def sources(p: Plan) -> dict[str, str]:
    out = {}
    if p.vectors:
        out[VECTOR_FILE] = vector_source(p.vectors)
    if p.factories:
        out[FACTORY_FILE] = FACTORY_HEADER + "\n" + "\n".join(factory_class(f) for f in p.factories)
    if p.singletons:
        out[SINGLETON_FILE] = SINGLETON_HEADER + "\n" + "\n".join(singleton_class(s) for s in p.singletons)
    if p.creators:
        out[CREATOR_FILE] = CREATOR_HEADER + "\n" + "\n".join(creator_class(c) for c in p.creators)
    if p.objects:
        words = sorted({q.kind for o in p.objects for q in o.params if q.kind.startswith("words")},
                       key=lambda k: int(k[5:]))
        stepped = {s.cls: s for s in p.steps}
        out[OBJECT_FILE] = (OBJECT_HEADER + "".join("\n" + words_struct(k) for k in words) + "\n"
                            + "\n".join(object_class(o, stepped.get(o.cls)) for o in p.objects))
        if p.adders or p.steps:
            out[OBJECT_FILE] += ADDER_HEADER
        if p.adders:
            out[OBJECT_FILE] += "\n" + "\n".join(adder_instance(a, o) for a, o in p.adders)
        if p.steps:
            out[OBJECT_FILE] += step_header(p.steps) + "\n" + "\n".join(step_functions(s) for s in p.steps)
        if p.makes:
            out[OBJECT_FILE] += (MAKE_HEADER + "\n" + "\n".join(make_classes(p.makes)) + "\n"
                                 + "\n".join(make_function(k) for k in p.makes))
    return out


def cmd_write(m: Module, args) -> None:
    from common import clang_format

    only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()} if args.only else None
    p = plan(m, only, args.all)
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for f in (VECTOR_FILE, FACTORY_FILE, SINGLETON_FILE, OBJECT_FILE, CREATOR_FILE):
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
          f"{len(p.singletons)} singletons, {len(p.objects)} objects, {len(p.creators)} creators, "
          f"{len(p.adders)} adders, {len(p.steps)} steps, {len(p.makes)} makes; "
          f"{len(p.names)} names in {args.names}",
          file=sys.stderr)


def cmd_census(m: Module, args) -> None:
    p = plan(m, everything=True)
    for fam, addrs in p.candidates.items():
        done = [a for a in addrs if m.rows[a].status == "O"]
        size = sum(m.rows[a].sword_size for a in addrs)
        dsize = sum(m.rows[a].sword_size for a in done)
        print(f"{fam:12s} {len(addrs):5d} candidates ({size:7d} bytes), {len(done):5d} matched ({dsize:7d} bytes)")
    reasons: dict[tuple[str, str], int] = {}
    for fam, _, why in p.skipped:
        key = (fam, why.split(" at ")[0])
        reasons[key] = reasons.get(key, 0) + 1
    for (fam, why), n in sorted(reasons.items(), key=lambda kv: (kv[0][0], -kv[1])):
        print(f"  {fam} not written: {n:4d} {why}")


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
