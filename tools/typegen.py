#!/usr/bin/env python3
"""Type getters of gflib3's object: `vf_type` and the getters it calls.

    python tools/typegen.py census                      # what's there, and how much isn't matched
    python tools/typegen.py write --names n.csv         # src/unsorted/types, and the names to give
    python tools/typegen.py write --names n.csv --only keep.txt

A class on gflib3's reference-counted object (src/gflib3/Unk_239a418.h)
overrides the object's `vf_type`, which returns the class's type descriptor:
a function-local static holding its parent's descriptor,

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Parent::Unk_GetType());
        return &type;
    }

inline in a header, so the static is a weak symbol every TU reaches through
the GOT. clang inlines the parent's getter into the child's (a guarded
static each), as deep as its inliner goes; where it stops, it calls the
parent's getter out of line, a weak copy the linker keeps once. So every
getter of the executable is that code: guards (__cxa_guard_acquire/release),
GOT loads of the statics, stores of each parent into its child, and at most
one call. From those stores this tool rebuilds the tree of types (1,737 in
Sword, no type with two parents).

Where the inliner stopped depends on more than the getters: LLVM 7's
inliner defers inlining a parent into a linkonce getter when the getter's
own callers could inline it (shouldBeDeferred), so the result depends on how
many callers each getter had in its TU. Defining every getter inline and
letting clang decide reproduces about half of the originals. So each
function is written the way its own code shows: the levels it inlines are
defined inline, the getter it calls out of line is only declared (named as
its type's, in functions.csv). A type inlined by one function and only
called by another can't be both in one TU: `partition` splits a segment's
classes into files where it never is. What it writes, in src/unsorted/types:

- each class whose vtable group holds its `vf_type` in the object's three
  places (slot 6 of the primary vtable, slot 5 of the +0x48 one, slot 0 of
  the +0x50 one), when all three are getter-shaped (the body inlined into
  the thunks): declared on the object with a destructor that isn't defined
  here (its key function, so no vtable is emitted here), its `vf_type`
  defined, which also emits the thunks. A class whose thunks are
  `sub x0, x0, #N ; b vf_type` isn't written: the original's vf_type is
  inline, emitted with the vtable in its class's own TU, and a strong
  vf_type defined here makes clang drop the thunk's adjustment and call it
  (dead argument elimination needs an exact definition);
- each class whose `vf_type` and thunks tail-call (`b G`) the class's own
  getter G, too big to be inlined: the getter is defined in the class
  (inlining what G inlines), so its out-of-line copy is emitted here and
  named. vtables.py wrote these vf_types as forwarders to a placeholder
  `Unk_<G>(void*)`: a getter so named is renamed as its type's only when
  every matched function that calls it is written here, and vtables.py
  stops writing the forwarders (it skips the functions of
  src/unsorted/types, read from their address comments);
- the kind test (`Unk_61a530<T>`): whether an object's type, from its +0x50
  interface, is T or derives from it, one explicit instantiation per T.

A type is named by what already names it: its static in data_symbols.csv
(`_ZZN<n><Class>11Unk_GetTypeEvE4type`), else a getter of it named in
functions.csv, else the class whose `vf_type` returns it (one class), else
its type object (`Unk_<address>`). Each file declares its own structs for
the types it needs, inline or declared only, rather than including the
hand-written headers that define some of them.

A trial writes every candidate; then keep only what matched: `write --only`
with the trial's names minus check.py's BAD addresses. A forwarder class is
kept only if all of its functions, getter included, are listed.
"""
from __future__ import annotations

import argparse
import bisect
import re
import struct
import sys
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

OUT_DIR = ROOT / "src" / "unsorted" / "types"
TYPE = "const Unk_239a418_Type*"
OBJECT_HEADER = "gflib3/Unk_239a418.h"
# The object's own getter and the root type, in the object's header.
GLOBAL_GETTERS = {"Unk_239a418_GetType": "Unk_239a418_GetType()",
                  "Unk_239a418_RootType": "&Unk_239a418_RootType()"}
# Where a class on the object keeps vf_type: (offset-to-top, slot) of its vtable group.
OBJECT_SLOTS = ((0, 6), (0x48, 5), (0x50, 0))
STATIC_RE = re.compile(r"_ZZ(?:N(\d+)(\w+?)11Unk_GetTypeEv|(\d+)(\w+?)v)E4type")
FORWARD_NAME = re.compile(r"_Z\d+Unk_[0-9a-f]+Pv")  # vtables.py's forwarders' callees
# An object's kind test (Unk_<addr> below, a template on the type it tests
# for): the type of the object's +0x50 interface (slot 0, vf_type), and that
# type's ancestors, compared with the type's getter, inlined.
KIND_OF_PROLOGUE = (0xD10083FF, 0xA9017BFD, 0x910043FD,   # sub sp, sp, #0x20 ; stp x29, x30 ; add x29
                    0xF9400008, 0xF9400108, 0xD63F0100)   # ldr x8, [x0] ; ldr x8, [x8] ; blr x8
KIND_OF_EXTRA = {0xEB08001F: None, 0xF9400000: 0, 0x320003E0: 0, 0x2A1F03E0: 0,   # cmp ; ldr x0, [x0] ; mov w0
                 0xA9417BFD: None, 0x910083FF: None, 0xF90007E0: None,             # ldp ; add sp ; str x0, [sp]
                 0xAA0803E0: 0, 0x2A0003E8: 8, 0xF94007E0: 0}                      # mov x0, x8 ; mov w8, w0 ; ldr
KIND_OF_BODY = """template <class T>
bool {name}(Unk_239a498* object) {{
    const Unk_239a418_Type* type = object->vf_type();
    const Unk_239a418_Type* kind = T::Unk_GetType();
    for (; type != nullptr; type = type->field_0)
        if (type == kind)
            return true;
    return false;
}}"""
ADDR_RE = re.compile(r"^// (0x71[0-9a-f]+)", re.M)


@dataclass
class Getter:
    """A getter-shaped function: the types it initialises (child -> parent) and its call."""
    addr: int
    stores: dict[int, tuple]                 # type object -> ("obj", parent) | ("ret", callee) | ("zero",)
    top: int                                 # the type it returns
    calls: list[int] = field(default_factory=list)


def _bl_target(a: int, w: int) -> int:
    return a + (((w & 0x3FFFFFF) ^ 0x2000000) - 0x2000000) * 4


def parse_getter(img: bytes, f: int, size: int, got: dict[int, int], guards: tuple[int, int],
                 extra: dict[int, int | None] | None = None) -> Getter | None:
    """f as a getter, or None: only frame set-up, GOT loads, guard tests and
    calls, stores of a type (or of a call's result, or zero) into a type, and
    branches inside f. Registers are reloaded from the GOT before each use in
    these functions, so a linear scan tracks them. `extra`: other words
    allowed, each with the register it writes (None: none)."""
    regs: dict[int, tuple] = {}
    pages: dict[int, int] = {}
    stores: dict[int, tuple] = {}
    calls: list[int] = []
    for off in range(0, size, 4):
        a = f + off
        w = struct.unpack_from("<I", img, a)[0]
        if extra is not None and w in extra:
            regs.pop(extra[w], None)
        elif extra is not None and (w & 0xFF000010) == 0x54000000:  # b.cond, inside f only
            if not f <= a + (((w >> 5) & 0x7FFFF) ^ 0x40000) * 4 - 0x100000 < f + size:
                return None
        elif (w & 0x9F000000) == 0x90000000:  # adrp
            imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
            if imm & (1 << 20):
                imm -= 1 << 21
            pages[w & 31] = (a & ~0xFFF) + (imm << 12)
            regs.pop(w & 31, None)
        elif (w & 0xFFC00000) == 0xF9400000:  # ldr x, [x, #imm]: a GOT slot
            rn, rt = (w >> 5) & 31, w & 31
            if rn not in pages:
                return None
            t = got.get(pages.pop(rn) + ((w >> 10) & 0xFFF) * 8)
            if t is None:
                return None
            regs[rt] = ("obj", t)
        elif (w & 0xFFFFFC00) == 0x08DFFC00:  # ldarb w, [x]: a guard's test
            if regs.get((w >> 5) & 31, (None,))[0] != "obj":
                return None
            regs[w & 31] = None
        elif (w & 0xFC000000) == 0x94000000:  # bl
            t = _bl_target(a, w)
            if t not in guards:
                calls.append(t)
            regs = {0: ("ret", t)} if t not in guards else {}
            pages = {}
        elif (w & 0xFFC00000) == 0xF9000000 and ((w >> 10) & 0xFFF) == 0:  # str x, [x]
            d = regs.get((w >> 5) & 31)
            s = ("zero",) if (w & 31) == 31 else regs.get(w & 31)
            if not d or d[0] != "obj" or s is None:
                return None
            stores[d[1]] = s
        elif w in (0xA9BF7BFD, 0x910003FD, 0xA8C17BFD, 0xD65F03C0):  # frame, ret
            pass
        elif (w & 0x7E000000) in (0x34000000, 0x36000000):  # cbz/cbnz/tbz/tbnz
            pass
        elif (w & 0xFC000000) == 0x14000000:  # b, inside f only
            if not f <= _bl_target(a, w) < f + size:
                return None
        else:
            return None
    parents = {s[1] for s in stores.values() if s[0] == "obj"}
    tops = [d for d in stores if d not in parents]
    if len(tops) != 1:
        return None
    return Getter(f, stores, tops[0], calls)


class Types:
    """The getters of one game and the type tree they spell."""

    def __init__(self, m, rows: dict, data_names: dict[int, str]):
        self.m = m
        self.rows = rows
        acq, rel = self._imports(m.game, ("__cxa_guard_acquire", "__cxa_guard_release"))
        self.getters: dict[int, Getter] = {}
        for f, size in m.funcs:
            if size <= 4096:
                g = parse_getter(m.img, f, size, m.got, (acq, rel))
                if g is not None:
                    self.getters[f] = g
        self.kind_of: dict[int, Getter] = {}
        for f, size in m.funcs:
            if size > len(KIND_OF_PROLOGUE) * 4 and struct.unpack_from(f"<{len(KIND_OF_PROLOGUE)}I", m.img, f) \
                    == KIND_OF_PROLOGUE:
                n = len(KIND_OF_PROLOGUE) * 4
                g = parse_getter(m.img, f + n, size - n, m.got, (acq, rel), KIND_OF_EXTRA)
                if g is not None:
                    g.addr = f
                    self.kind_of[f] = g
        self.parent: dict[int, tuple] = {}
        self.conflicts: set[int] = set()
        for g in self.getters.values():
            for d, s in g.stores.items():
                if s[0] == "ret":
                    c = self.getters.get(s[1])
                    s = ("obj", c.top) if c is not None else ("?", s[1])
                if self.parent.setdefault(d, s) != s:
                    self.conflicts.add(d)
        self.slot_of: dict[int, list[tuple[int, int, int]]] = defaultdict(list)  # f -> (group, -offset, slot)
        for v in m.vtables:
            for i, f in enumerate(v.slots):
                if isinstance(f, int):
                    self.slot_of[f].append((v.group, -v.offset_to_top, i))
        self.data_names = data_names

    @staticmethod
    def _imports(game: str, names: tuple[str, ...]) -> list[int]:
        """The PLT stubs of SDK imports."""
        from common import load_module, nso_path
        from nx.module import DynInfo
        from nx.nso import Nso

        mod = load_module(game)
        dyn = DynInfo(Nso(nso_path(game).read_bytes()), mod["image"], mod["text_end"])
        return [dyn.plt_by_name[n] for n in names]


def static_getter(name: str) -> str | None:
    """The getter expression a type's static's name spells: `Cls::Unk_GetType()`, or a free getter's."""
    s = STATIC_RE.fullmatch(name)
    if s is None:
        return None
    if s[1] is not None:
        return f"{s[2]}::Unk_GetType()" if len(s[2]) == int(s[1]) else None
    if len(s[4]) != int(s[3]):
        return None
    return GLOBAL_GETTERS.get(s[4], f"{s[4]}()")


def member_getter(name: str) -> str | None:
    """The class of `_ZN<n><Class>11Unk_GetTypeEv`."""
    s = re.fullmatch(r"_ZN(\d+)(\w+)11Unk_GetTypeEv", name)
    return s[2] if s is not None and len(s[2]) == int(s[1]) else None


def getter_symbol(expr: str) -> str:
    """The mangled name of the function a getter expression calls."""
    expr = expr.lstrip("&").removesuffix("()")
    if "::" in expr:
        cls, fn = expr.split("::")
        return f"_ZN{len(cls)}{cls}{len(fn)}{fn}Ev"
    return f"_Z{len(expr)}{expr}v"


def read_data_names() -> dict[int, str]:
    import csv

    out = {}
    with open(ROOT / "data" / "data_symbols.csv", encoding="utf-8", newline="") as fh:
        for r in csv.DictReader(fh):
            if r["Name"].startswith("_ZZ") and r["Name"].endswith("E4type") and r["Sword"]:
                out[int(r["Sword"], 16) - BASE] = r["Name"]
    return out


def header_getters(root: Path) -> dict[str, str]:
    """Classes whose getter a header in src/ defines inline -> that header (relative to src/)."""
    out = {}
    for h in sorted(root.rglob("*.h")):
        text = h.read_text(encoding="utf-8", errors="replace")
        if "Unk_GetType() {" not in text:
            continue
        for c in re.finditer(r"^(?:class|struct) (\w+)\b[^;{]*\{", text, re.M):
            end = text.find("\n};", c.end())
            if "Unk_GetType() {" in text[c.end():end if end >= 0 else len(text)]:
                out.setdefault(c[1], h.relative_to(root).as_posix())
    return out


def vf_type_classes(root: Path, skip: Path = OUT_DIR) -> set[str]:
    """Classes src/ (but `skip`) declares with a vf_type of their own."""
    out = set()
    for p in sorted([*root.rglob("*.h"), *root.rglob("*.cpp")]):
        if skip in p.parents:
            continue
        text = p.read_text(encoding="utf-8", errors="replace")
        if "vf_type(" not in text:
            continue
        for c in re.finditer(r"^(?:class|struct) (\w+)\b[^;{]*\{", text, re.M):
            end = text.find("\n};", c.end())
            if "vf_type(" in text[c.end():end if end >= 0 else len(text)]:
                out.add(c[1])
        out |= set(re.findall(r"(\w+)::vf_type\(", text))
    return out


def written_addresses(out_dir: Path = OUT_DIR) -> set[int]:
    """The functions src/unsorted/types defines (its address comments), relative to BASE."""
    out = set()
    for p in out_dir.glob("*.cpp") if out_dir.exists() else ():
        for a in ADDR_RE.findall(p.read_text(encoding="utf-8")):
            out.add(int(a, 16) - BASE)
    return out


@dataclass
class ClassPlan:
    name: str
    group: int
    vf_type: int
    thunks: list[tuple[int, int]]            # (this adjustment, address)
    top: int
    inlined: list[int] = field(default_factory=list)  # the types vf_type initialises, its own first
    end: tuple = ()                          # the last one's parent: ("cut", getter) | ("zero",) | ("global", type)
    forward: int | None = None               # the getter vf_type tail-calls, when it isn't inlined
    bare: bool = False                       # vf_type only, not virtual here: its thunks aren't written


@dataclass
class KindPlan:
    """An instance of the kind test, for the type `top`."""
    addr: int
    top: int
    inlined: list[int] = field(default_factory=list)
    end: tuple = ()

    @property
    def name(self) -> str:  # not a C++ name: partition's key for it
        return f"<kind test 0x{self.addr + BASE:x}>"


def kind_of_name(t: Types) -> str:
    """The kind test's placeholder name, after its first instance."""
    return f"Unk_{min(t.kind_of):x}"


def kind_of_symbol(t: Types, cls: str) -> str:
    n = kind_of_name(t)
    return f"_Z{len(n)}{n}I{len(cls)}{cls}EbP11Unk_239a498"


def thunk_target(m, f: int, adj: int) -> int | None:
    """`sub x0, x0, #adj ; b T`'s T."""
    if m.sizes.get(f) != 8:
        return None
    w0, w1 = struct.unpack_from("<II", m.img, f)
    if w0 != (0xD1000000 | (adj << 10)) or (w1 & 0xFC000000) != 0x14000000:
        return None
    return _bl_target(f + 4, w1)


def is_global(e: str) -> bool:
    """A getter the object's header defines."""
    return e.removesuffix("()").lstrip("&") in GLOBAL_GETTERS


def branch_only(m, f: int) -> int | None:
    """A `b T` function's T."""
    if m.sizes.get(f) != 4:
        return None
    w = struct.unpack_from("<I", m.img, f)[0]
    return _bl_target(f, w) if (w & 0xFC000000) == 0x14000000 else None


def callers_of(m, targets: set[int]) -> dict[int, set[int]]:
    """target -> the functions that call it or branch to it."""
    out: dict[int, set[int]] = defaultdict(set)
    for f, size in m.funcs:
        for off in range(0, size, 4):
            w = struct.unpack_from("<I", m.img, f + off)[0]
            if (w & 0x7C000000) == 0x14000000:
                t = _bl_target(f + off, w)
                if t in targets and t != f:
                    out[t].add(f)
    return out


def plan(t: Types, taken: set[str], blocked: set[int]) -> tuple[list[ClassPlan], dict[int, str], list[str]]:
    """The classes on the object whose vf_type is getter-shaped or tail-calls
    a getter, every type's getter expression, and why classes were left out.
    A getter named as a forwarder's callee (`_Z<n>Unk_<addr>Pv`, vtables.py)
    is renamed as its type's, unless it's in `blocked`."""
    import vtables as vt

    m, rows = t.m, t.rows
    by_addr = {v.addr: v for v in m.vtables}
    groups: dict[int, dict[int, object]] = defaultdict(dict)  # group -> {-offset: vtable}
    for v in m.vtables:
        groups[v.group][-v.offset_to_top] = v
    skipped: list[str] = []
    classes: list[ClassPlan] = []
    own = vt.owners(m.vtables)
    for g, vs in sorted(groups.items()):
        try:
            fs = [vs[o].slots[i] for o, i in OBJECT_SLOTS]
        except (KeyError, IndexError):
            continue
        if not all(isinstance(f, int) for f in fs):
            continue
        fwd = branch_only(m, fs[0]) if fs[0] not in t.getters else None
        if fs[0] in t.getters:
            top = t.getters[fs[0]].top
        elif fwd in t.getters:
            top = t.getters[fwd].top
        else:
            continue
        thunks = []
        for (o, _), f in zip(OBJECT_SLOTS[1:], fs[1:]):
            if fwd is None and (f in t.getters and t.getters[f].top == top or thunk_target(m, f, o) == fs[0]) \
                    or fwd is not None and branch_only(m, f) == fwd:
                thunks.append((o, f))
        name = vt.class_name(by_addr[g])
        if len(thunks) != 2:
            skipped.append(f"{name}: its thunks aren't vf_type's")
            continue
        if own.get(fs[0], (None,))[0] != g:
            continue  # inherited: the class that owns it writes it
        classes.append(ClassPlan(name, g, fs[0], thunks, top, forward=fwd))

    # Each type's getter expression.
    owner: dict[int, list[str]] = defaultdict(list)
    for c in classes:
        owner[c.top].append(c.name)
    named_getter: dict[int, set[str]] = defaultdict(set)
    for f, g in t.getters.items():
        r = rows.get(f)
        if r is not None and r.name and f not in t.slot_of and (f in blocked or not FORWARD_NAME.fullmatch(r.name)):
            named_getter[g.top].add(r.name)
    expr: dict[int, str] = {}
    for ty in t.parent:
        if ty in t.data_names:
            e = static_getter(t.data_names[ty])
        elif len(named_getter[ty]) == 1 and member_getter(next(iter(named_getter[ty]))):
            e = f"{member_getter(next(iter(named_getter[ty])))}::Unk_GetType()"
        elif named_getter[ty]:
            continue  # named some other way: a wrapper, or a getter this tool can't spell
        elif len(owner[ty]) == 1 and owner[ty][0] not in taken:
            e = f"{owner[ty][0]}::Unk_GetType()"
        else:
            e = f"Unk_{ty:x}::Unk_GetType()"
        if e is not None:
            expr[ty] = e
    return classes, expr, skipped


def chain_of(t: Types, expr: dict[int, str], f: int, g: Getter | None = None) -> tuple[list[int], tuple] | None:
    """The types getter f initialises, from the one it returns up, and what
    the last one's parent is: the getter f calls out of line ("cut"), none
    ("zero"), or one of the object header's, inlined too ("global")."""
    g = g if g is not None else t.getters[f]
    out: list[int] = []
    ty = g.top
    while True:
        if ty not in g.stores or ty in out or ty not in expr or is_global(expr[ty]) or ty in t.conflicts:
            return None
        out.append(ty)
        s = g.stores[ty]
        if s[0] == "zero":
            return out, ("zero",)
        if s[0] == "ret":
            cg = t.getters.get(s[1])
            if cg is None or cg.top not in expr or is_global(expr[cg.top]) or s[1] in t.slot_of:
                return None
            return out, ("cut", s[1])
        p = s[1]
        if p not in expr or p not in g.stores:
            return None
        if is_global(expr[p]):
            return out, ("global", p)
        ty = p


def parent_expr(t: Types, expr: dict[int, str], c: ClassPlan, i: int) -> str:
    """The parent of c's i-th inlined type, spelled as this file calls it."""
    if i + 1 < len(c.inlined):
        return expr[c.inlined[i + 1]]
    if c.end[0] == "zero":
        return "nullptr"
    if c.end[0] == "global":
        return expr[c.end[1]]
    return expr[t.getters[c.end[1]].top]


def cls_of(e: str) -> str:
    return e.split("::")[0]


def render(t: Types, expr: dict[int, str], classes: list[ClassPlan]) -> str:
    """One file: the getters its vf_types call (declared), the types they
    inline (parents first, with their getters), then the classes."""
    parent: dict[int, str] = {}
    for c in classes:
        for i, ty in enumerate(c.inlined):
            parent[ty] = parent_expr(t, expr, c, i)
    cut = sorted({t.getters[c.end[1]].top for c in classes if c.end[0] == "cut"}, key=lambda ty: expr[ty])
    own = {c.top: c for c in classes if cls_of(expr[c.top]) == c.name}
    kinds = [c for c in classes if isinstance(c, KindPlan)]
    classes = [c for c in classes if not isinstance(c, KindPlan)]
    out = ["// Scope: common",
           "// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,",
           "// don't edit). Placeholder classes, named after their vtables, and types, named",
           "// after their type objects where no class is known: rename them once they are.",
           "#include <types.h>", "", f'#include "{OBJECT_HEADER}"', ""]
    for ty in cut:
        out += [f"// The type 0x{ty + BASE:x}: its getter is out of line.", f"struct {cls_of(expr[ty])} {{",
                f"    static {TYPE} Unk_GetType();", "};", ""]

    def getter(ty: int) -> list[str]:
        return [f"    static {TYPE} Unk_GetType() {{", f"        static Unk_239a418_Type type({parent[ty]});",
                "        return &type;", "    }"]

    def declare(c: ClassPlan) -> list[str]:
        th = ", ".join(f"0x{a + BASE:x} (+0x{o:x})" for o, a in c.thunks)
        how = [f"// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x{c.forward + BASE:x})."] \
            if c.forward is not None else []
        if c.bare:
            return [f"// vtable 0x{c.group + BASE:x}: vf_type (its thunks {th} aren't written: they",
                    "// call it, and the original's is inline, emitted with the class's vtable).",
                    "// Declared without its bases or its vtable: vf_type doesn't use them.",
                    f"struct {c.name} {{", *((*getter(c.top), "") if c.top in own else ()),
                    f"    {TYPE} vf_type();", "};", ""]
        return [f"// vtable 0x{c.group + BASE:x}: vf_type and its thunks {th}.", *how,
                "// Its base and its other functions aren't written here.",
                f"class {c.name} : public Unk_239a418 {{", "public:",
                *((*getter(c.top), "") if c.top in own else ()),
                f"    ~{c.name}() override;", f"    {TYPE} vf_type() override;", "};", ""]

    done: set[int] = set()
    by_expr = {expr[ty]: ty for ty in parent}

    def emit(ty: int) -> None:
        nonlocal out
        if ty in done:
            return
        done.add(ty)
        p = by_expr.get(parent[ty])
        if p is not None:
            emit(p)
        if ty in own:
            out += declare(own[ty])
        else:
            out += [f"// The type 0x{ty + BASE:x}.", f"struct {cls_of(expr[ty])} {{", *getter(ty), "};", ""]

    for ty in sorted(parent, key=lambda ty: expr[ty]):
        emit(ty)
    for c in classes:
        if c.top not in own:
            out += declare(c)
    for c in classes:
        out += [f"// 0x{c.vf_type + BASE:x}", *(f"// 0x{a + BASE:x}" for _, a in c.thunks if not c.bare),
                f"{TYPE} {c.name}::vf_type() {{",
                f"    return {'Unk_GetType()' if c.top in own else expr[c.top]};", "}", ""]
    if kinds:
        out += ["// Whether an object's type is the template argument or one derived from it,",
                "// through the object's +0x50 interface.", KIND_OF_BODY.format(name=kind_of_name(t)), ""]
        for k in kinds:
            out += [f"// 0x{k.addr + BASE:x}",
                    f"template bool {kind_of_name(t)}<{cls_of(expr[k.top])}>(Unk_239a498* object);", ""]
    return "\n".join(out).rstrip("\n") + "\n"


def load(game: str = "sword") -> Types:
    import vtables as vt
    from common import read_functions_csv

    m = vt.load(game)
    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    return Types(m, rows, read_data_names())


def _select(t: Types, only: set[int] | None, taken: set[str], blocked: set[int]):
    import vtables as vt

    classes, expr, skipped = plan(t, taken, blocked)
    rows = t.rows
    used = {r.name: a for a, r in rows.items() if r.name}

    def free(f: int, name: str) -> bool:
        r = rows.get(f)
        return r is not None and r.scope == "common" and r.shield is not None \
            and (r.status == "U" and not r.name and (only is None or f in only) or r.name == name)

    def forwarder(f: int, name: str) -> bool:
        """A forwarder vtables.py wrote (matched, named as its placeholder's member), or a free one."""
        r = rows.get(f)
        return free(f, name) or r is not None and r.status == "O" and r.scope == "common" \
            and r.shield is not None and vt.WRITTEN.fullmatch(r.name) is not None

    def getter_name(g: int) -> str | None:
        """The name to give getter g, its type's: None if g is named otherwise."""
        n = getter_symbol(expr[t.getters[g].top])
        r = rows.get(g)
        if r is None or r.shield is None or r.status == "O" and r.name != n:
            return None
        if r.name == n:
            return n
        if r.name and not (FORWARD_NAME.fullmatch(r.name) and g not in blocked):
            return None
        return n if used.get(n, g) == g and (only is None or g in only) else None

    keep = []
    for c in classes:
        if c.name in taken:
            skipped.append(f"{c.name}: declared with a vf_type elsewhere in src/")
            continue
        names = [(c.vf_type, vt.mangle(c.name, "vf_type"))]
        names += [(a, f"_ZThn{o}_N{len(c.name)}{c.name}7vf_typeEv") for o, a in c.thunks]
        if c.forward is None:
            if not all(a in t.getters for _, a in c.thunks):
                # `sub x0, x0, #N ; b vf_type`: the original's vf_type is inline,
                # emitted with its class's vtable in a TU not written here.
                # Defined strongly with a vtable around it, its thunks would lose
                # the adjustment, so it's written alone, as a plain member.
                c.bare = True
                names = names[:1]
            if not all(free(f, n) for f, n in names):
                continue
            ch = chain_of(t, expr, c.vf_type)
            if ch is None or not c.bare and any(chain_of(t, expr, a) != ch for _, a in c.thunks):
                skipped.append(f"{c.name}: its type's chain")
                continue
        else:
            if not all(forwarder(f, n) for f, n in names):
                continue
            ch = chain_of(t, expr, c.forward)
            n = getter_name(c.forward) if ch is not None else None
            if ch is None or cls_of(expr[c.top]) != c.name or n is None:
                skipped.append(f"{c.name}: its getter's chain or name")
                continue
            names.append((c.forward, n))
            if only is not None and not all(f in only or rows[f].name == n for f, n in names):
                continue  # all of it matched in the trial, or none of it is written
        c.inlined, c.end = ch
        if c.end[0] == "cut":
            n = getter_name(c.end[1])
            if n is None:
                skipped.append(f"{c.name}: the getter it calls is named otherwise")
                continue
            if rows[c.end[1]].name != n:
                names.append((c.end[1], n))
        keep.append((c, names))
    for f, g in sorted(t.kind_of.items()):
        if g.top not in expr or is_global(expr[g.top]):
            continue
        k = KindPlan(f, g.top)
        names = [(f, kind_of_symbol(t, cls_of(expr[g.top])))]
        ch = chain_of(t, expr, f, g)
        if not free(f, names[0][1]) or ch is None:
            skipped.append(f"{k.name}: its type's chain")
            continue
        k.inlined, k.end = ch
        if k.end[0] == "cut":
            n = getter_name(k.end[1])
            if n is None:
                skipped.append(f"{k.name}: the getter it calls is named otherwise")
                continue
            if rows[k.end[1]].name != n:
                names.append((k.end[1], n))
        keep.append((k, names))
    return keep, expr, skipped


def selection(t: Types, only: set[int] | None):
    """The classes to write, with the names to give (their functions and the
    getters they call), the getter expressions, and why the others weren't.
    A forwarder's callee is renamed only if every matched function that calls
    it is one of these: blocked otherwise, until nothing changes."""
    taken = set(header_getters(ROOT / "src")) | vf_type_classes(ROOT / "src")
    fwd = {f for f in t.getters if f in t.rows and FORWARD_NAME.fullmatch(t.rows[f].name or "")}
    callers = callers_of(t.m, fwd)
    blocked: set[int] = set()
    while True:
        keep, expr, skipped = _select(t, only, taken, blocked)
        written = {f for _, names in keep for f, _ in names}
        now = {g for g in fwd if any(t.rows[c].status == "O" and c not in written for c in callers.get(g, ()))
               or g not in written}
        if now <= blocked:
            return keep, expr, skipped
        blocked |= now


def partition(t: Types, expr: dict[int, str], classes: list[ClassPlan]) -> list[list[ClassPlan]]:
    """Classes in files where no type is both inlined and only declared, and
    no struct is declared twice."""
    files: list[tuple[list[ClassPlan], set[int], set[int], dict[str, int]]] = []
    for c in classes:
        inl = set(c.inlined)
        cut = {t.getters[c.end[1]].top} if c.end[0] == "cut" else set()
        names = {cls_of(expr[ty]): ty for ty in inl | cut}
        if c.name in names and names[c.name] != c.top:
            continue
        for cs, i, d, n in files:
            tops = {x.name: x.top for x in cs}
            if inl & d or cut & i or n.get(c.name, c.top) != c.top \
                    or any(tops.get(k, ty) != ty or n.get(k, ty) != ty for k, ty in names.items()):
                continue
            cs.append(c)
            i |= inl
            d |= cut
            n.update(names)
            break
        else:
            files.append(([c], inl, cut, dict(names)))
    return [cs for cs, *_ in files]


def cmd_census(t: Types, args) -> None:
    from collections import Counter

    st = Counter()
    for f in t.getters:
        k = "slot" if f in t.slot_of else "called"
        r = t.rows.get(f)
        st[(k, r.status if r else "?")] += t.m.sizes[f]
    print(f"{len(t.getters)} getters, {len(t.parent)} types, {len(t.conflicts)} with two parents")
    for k, n in sorted(st.items()):
        print(f"  {k[0]:6} {k[1]}  {n:8} bytes")
    keep, expr, skipped = selection(t, None)
    n = sum(t.m.sizes[f] for _, names in keep for f, _ in names[:3])
    print(f"writable: {len(keep)} classes, {n} bytes not matched yet")
    for why, k in Counter(s.split(": ", 1)[1] for s in skipped).most_common():
        print(f"  left out: {k:5} {why}")


def key(c) -> int:
    """Where a class's vf_type or a kind test is."""
    return c.addr if isinstance(c, KindPlan) else c.vf_type


def cmd_write(t: Types, args) -> None:
    import vtables as vt
    from common import clang_format

    only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()} if args.only else None
    keep, expr, _ = selection(t, only)
    seg_starts = vt.segment_starts(t.m)

    def seg(f: int) -> int:
        return seg_starts[bisect.bisect_right(seg_starts, f) - 1]

    by_seg: dict[int, list[ClassPlan]] = defaultdict(list)
    names: dict[int, str] = {}
    for c, _ in keep:
        by_seg[seg(key(c))].append(c)
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for old in OUT_DIR.glob("Unk_*.cpp"):
        old.unlink()
    n_files = 0
    written = set()
    for _, cs in sorted(by_seg.items()):
        bare = [c for c in cs if getattr(c, "bare", False)]  # apart: their types inline differently with more callers
        rest = [c for c in cs if not getattr(c, "bare", False)]
        for part in [*partition(t, expr, sorted(rest, key=key)), *partition(t, expr, sorted(bare, key=key))]:
            (OUT_DIR / f"Unk_{key(part[0]):x}.cpp").write_text(render(t, expr, part), encoding="utf-8",
                                                                newline="\n")
            written |= {c.name for c in part}
            n_files += 1
    for c, ns in keep:
        if c.name in written:
            names.update(ns)
    if not clang_format(sorted(OUT_DIR.glob("Unk_*.cpp"))):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for f, n in sorted(names.items()):
            r = t.rows[f]
            fh.write(f"{n},{r.sword_str},{r.shield_str}\n")
    print(f"{len(written)} classes in {n_files} files, {len(names)} names in {args.names}", file=sys.stderr)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("census")
    w = sub.add_parser("write")
    w.add_argument("--names", type=Path, required=True)
    w.add_argument("--only", type=Path)
    args = ap.parse_args(argv)
    t = load()
    {"census": cmd_census, "write": cmd_write}[args.cmd](t, args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
