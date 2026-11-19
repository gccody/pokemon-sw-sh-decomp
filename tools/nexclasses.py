#!/usr/bin/env python3
"""NEX 4.6.8's DDL data classes, their members read from their destructors.

    python tools/nexclasses.py list                         # the classes and their members
    python tools/nexclasses.py write lib/nex/ddl/Classes.cpp --names n.csv

NEX's DDL compiler declares each data structure of a protocol as two classes:
`_DDL_X` (RTTI `N2nn3nex<n>_DDL_XE`), which holds the fields, and `X`, derived
from it and adding nothing. Their destructors are all the executable says
about the fields: `_DDL_X`'s base destructor (D2, slot 0 of both vtables:
`X`'s is an alias of it) stores `_DDL_X`'s vtable, then destroys the members
in reverse order of declaration. A member is

- a `nn::nex::String` (its vtable stored, then 0x71015bc310, which frees a
  heap buffer);
- a `qVector` (its buffer freed through 0x71015b9390 after setting the end to
  the begin), of scalars or of polymorphic elements of a size (each
  destroyed through its vtable, from the end);
- a `qList` (unlinked and each node freed), of scalars or of polymorphic
  elements;
- another class with an inline destructor (its vtable stored, then its own
  members), which is written the same way;
- or a class with an out-of-line destructor, which is called.

Scalars leave no trace: they become padding (`u8 _<offset>[n]`). Each class
then gets an out-of-line destructor (the D2 and the D0, which calls the D2 or
inlines it) and `X` one too (its D0). The member classes keep their RTTI
names, or the placeholder `Unk_<vtable>` of tools/vtables.py; elements are
`Unk_Element<size>`. Classes whose destructor reads anything else are left
out. tools/check.py then compares the destructors; whatever doesn't match is
listed in NOT_MATCHING and left out.
"""
from __future__ import annotations

import argparse
import csv
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE  # noqa: E402
from nexddl import NEX_HI, NEX_LO, Ins, Unrecognized  # noqa: E402

STRING_FREE = 0x15BC310   # nn::nex::String's: frees a heap buffer
FREE = 0x15B9390          # MemAllocator's deallocate
STRING_VT = 0x23A2640     # nn::nex::String's vtable (gflnet3's copy), address point
STRING_SIZE, VECTOR_SIZE, LIST_SIZE = 0x28, 0x18, 0x18

# Member classes lib/nex declares in a header (not declared again).
HEADERS = {"qBuffer": "nn/nex/RefCountedObject.h"}
# Classes another file of lib/nex declares (their destructors are written there).
ELSEWHERE = {"InetAddress", *HEADERS}
DELETE = 0x15B6E10        # RootObject's operator delete
ROOT_OBJECT = "N2nn3nex10RootObjectE"

# Classes the template recognizes but whose destructors don't match.
NOT_MATCHING: set[int] = set()


def disasm(code: bytes, addr: int) -> list[Ins]:
    import nexddl
    return nexddl.disasm(code, addr)


_REG = r"[xw]\d+|sp|xzr|wzr"
_MEM = re.compile(r"\[(x\d+|sp)(?:, #(-?0x[0-9a-f]+|-?\d+))?\](!?)")


def _int(s: str) -> int:
    return int(s.lstrip("#"), 0)


def _x(r: str) -> str:
    return "x" + r[1:] if r.startswith("w") else r


def events(ins: list[Ins], got: dict[int, int]) -> list[tuple]:
    """What a destructor does to `this` (x0 on entry), in order:
    ('vptr', offset, vtable address point), ('zero', offset) (a store of 0),
    ('elem', size) (a pointer stepped back by an element), ('vcall',),
    ('call', target, x0) with x0 ('this', offset), ('load', offset) or None.
    `got` maps a GOT slot to what it holds (relative addresses)."""
    regs: dict[str, tuple] = {"x0": ("this", 0)}
    ev: list[tuple] = []
    lo, hi = ins[0].addr - BASE, ins[-1].addr - BASE + 4

    def val(r: str):
        return regs.get(_x(r))

    def put(r: str, v) -> None:
        r = _x(r)
        if v is None:
            regs.pop(r, None)
        else:
            regs[r] = v

    def clobber() -> None:
        for k in range(19):
            regs.pop(f"x{k}", None)

    for x in ins:
        m = x.mnemonic
        ops = [s.strip() for s in re.split(r",(?![^\[]*\])", x.op_str)] if x.op_str else []
        if m == "adrp":
            put(ops[0], ("page", _int(ops[1]) - BASE))
        elif m == "ldr" and len(ops) == 2 and (mm := _MEM.fullmatch(ops[1])):
            b, off, wb = mm.group(1), int(mm.group(2) or "0", 0), mm.group(3)
            v = val(b)
            if off < 0 and wb:
                ev.append(("elem", -off))
                put(b, None)
                put(ops[0], None)
                continue
            if v and v[0] == "page" and not wb:
                t = got.get(v[1] + off)
                put(ops[0], ("got", t) if t is not None else None)
            elif v and v[0] == "this" and not wb:
                put(ops[0], ("load", v[1] + off))
            else:
                put(ops[0], None)
            if wb:
                put(b, None)
        elif m == "ldp" and len(ops) == 3 and (mm := _MEM.fullmatch(ops[2])) and not mm.group(3):
            v = val(mm.group(1))
            for k, r in enumerate(ops[:2]):
                off = int(mm.group(2) or "0", 0) + 8 * k
                put(r, ("load", v[1] + off) if v and v[0] == "this" else None)
        elif m == "add" and len(ops) == 3 and ops[2].startswith("#"):
            v, k = val(ops[1]), _int(ops[2])
            kinds = {"got": "vt", "this": "this", "page": "addr"}
            put(ops[0], (kinds[v[0]], v[1] + k) if v and v[0] in kinds else None)
        elif m == "mov" and len(ops) == 2 and re.fullmatch(_REG, ops[1]):
            put(ops[0], val(ops[1]))
        elif m in ("str", "stur", "strb", "strh", "sturb"):
            src = val(ops[0]) if ops[0] not in ("xzr", "wzr") else ("zero",)
            mm = _MEM.fullmatch(ops[1])
            if not mm:
                continue
            b = mm.group(1)
            bv = val(b)
            if len(ops) == 3:   # post-index: [b], #k
                off, step = 0, _int(ops[2])
            else:
                off = int(mm.group(2) or "0", 0)
                step = off if mm.group(3) else None
            if bv and bv[0] == "this":
                if src and src[0] == "vt" and m == "str":
                    ev.append(("vptr", bv[1] + off, src[1]))
                elif src == ("zero",) and m == "str":
                    ev.append(("zero", bv[1] + off))
                if step is not None:
                    put(b, ("this", bv[1] + step))
            elif step is not None:
                put(b, None)
        elif m in ("bl", "b") and x.op_str.startswith("#"):
            t = _int(x.op_str) - BASE
            if lo <= t < hi:
                continue
            ev.append(("call", t, val("x0")))
            if m == "bl":
                clobber()
        elif m in ("blr", "br"):
            ev.append(("vcall",))
            clobber()
        elif m in ("stp", "cmp", "cbz", "cbnz", "ret", "nop", "tbz", "tbnz") or m.startswith("b."):
            pass
        elif ops and re.fullmatch(r"[xw]\d+", ops[0]):
            put(ops[0], None)
    return ev


@dataclass
class Member:
    offset: int
    kind: str                 # string | vector | list | inline | call
    elem: int = 0             # vector/list: the element's size (0: scalars)
    vtable: int | None = None  # inline: the class's vtable (address point)
    target: int | None = None  # call: the destructor called; inline: the class's D2
    members: list[Member] = field(default_factory=list)  # inline: its members, relative


def members(ev: list[tuple], inline_events) -> tuple[int, list[Member]]:
    """The class's vtable (what it stores first) and its members in declaration
    order. `inline_events(vtable)` returns (D2, events of the D2) of a class
    whose destructor was inlined, or None."""
    if not ev or ev[0][0] != "vptr" or ev[0][1] != 0:
        raise Unrecognized("no store of the class's vtable first")
    out: list[Member] = []
    elem = zero = None
    vcall = False
    i = 1
    while i < len(ev):
        e = ev[i]
        if e[0] == "elem":
            elem = e[1]
        elif e[0] == "vcall":
            vcall = True
        elif e[0] == "zero":
            zero = e[1]
        elif e[0] == "vptr":
            off, vt = e[1], e[2]
            if vt == STRING_VT:
                if i + 1 < len(ev) and ev[i + 1][:3] == ("call", STRING_FREE, ("this", off)):
                    out.append(Member(off, "string"))
                    i += 2
                    continue
                raise Unrecognized(f"String at {off:#x} not destroyed")
            sub = inline_events(vt)
            if sub is None:
                raise Unrecognized(f"inline member at {off:#x} of an unknown class")
            d2, sev = sub
            own, mem = members(sev, inline_events)
            if own != vt:
                raise Unrecognized(f"inline member at {off:#x}: its destructor stores another vtable")
            n = len(sev) - 1
            if [_shift(x, off) for x in sev[1:]] != ev[i + 1:i + 1 + n]:
                raise Unrecognized(f"inline member at {off:#x} destroyed differently")
            out.append(Member(off, "inline", vtable=vt, target=d2, members=mem))
            i += 1 + n
            continue
        elif e[0] == "call":
            t, x0 = e[1], e[2]
            if t == FREE:
                if zero is not None:
                    out.append(Member(zero - 0x10, "list", elem=0x10 if vcall else 0))
                elif x0 and x0[0] == "load":
                    if (elem is not None) != vcall:
                        raise Unrecognized("a vector's elements destroyed oddly")
                    out.append(Member(x0[1], "vector", elem=elem or 0))
                else:
                    raise Unrecognized("a free of something else")
                elem = zero = None
                vcall = False
            elif x0 and x0[0] == "this" and x0[1] > 0:
                out.append(Member(x0[1], "call", target=t))
            else:
                raise Unrecognized(f"a call of {t + BASE:#x}")
        i += 1
    if elem is not None or zero is not None or vcall:
        raise Unrecognized("something left over")
    out.reverse()
    if any(a.offset >= b.offset for a, b in zip(out, out[1:])) or (out and out[0].offset < 8):
        raise Unrecognized("members out of order")
    return ev[0][2], out


def _shift(e: tuple, off: int) -> tuple:
    if e[0] in ("vptr", "zero"):
        return (e[0], e[1] + off, *e[2:])
    if e[0] == "call" and e[2] and e[2][0] in ("this", "load"):
        return ("call", e[1], (e[2][0], e[2][1] + off))
    return e


# --- C++ -------------------------------------------------------------------

def simple_name(rtti: str | None) -> str | None:
    """`nn::nex::X` of a plain RTTI name N2nn3nex<n>XE, else None."""
    m = re.fullmatch(r"N2nn3nex(\d+)(\w+)E", rtti or "")
    if not m or len(m.group(2)) != int(m.group(1)):
        return None
    return m.group(2)


def mangle(cls: str, nex: bool, what: str) -> str:
    """The mangled name of a destructor (`what`: D0, D1, D2) of class cls."""
    if nex:
        return f"_ZN2nn3nex{len(cls)}{cls}{what}Ev"
    return f"_ZN{len(cls)}{cls}{what}Ev"


@dataclass
class Klass:
    name: str                 # unqualified
    nex: bool                 # in nn::nex (an RTTI name), else a placeholder Unk_<vtable>
    vtable: int               # address point
    d2: int
    d0: int | None
    members: list[Member]
    derived: list[tuple[str, int]] = field(default_factory=list)  # (name, D0) of the classes X


@dataclass
class Model:
    classes: list[Klass]
    inline: dict[int, Klass]        # vtable -> class with an inline destructor (a member's type)
    opaque: dict[int, tuple[str, bool, int]]  # D2 -> (name, nex, size) of a class whose D2 is called
    written: set[int] = field(default_factory=set)  # those of them written here (not declared opaque)
    trivial: list[tuple[str, int, int]] = field(default_factory=list)  # (name, D2, D0): empty destructors


def size_of(m: Member, model: Model, nxt: int | None) -> int:
    if m.kind == "string":
        return STRING_SIZE
    if m.kind == "vector":
        return VECTOR_SIZE
    if m.kind == "list":
        return LIST_SIZE
    if m.kind == "inline":
        return class_size(model.inline[m.vtable].members, model)
    return model.opaque[m.target][2]


def class_size(mem: list[Member], model: Model) -> int:
    if not mem:
        return 8
    last = mem[-1]
    end = last.offset + size_of(last, model, None)
    return (end + 7) & ~7


def qualified(name: str, nex: bool) -> str:
    return f"nn::nex::{name}" if nex else name


def type_of(m: Member, model: Model) -> str:
    if m.kind == "string":
        return "nn::nex::String"
    if m.kind in ("vector", "list"):
        t = f"Unk_Element<{m.elem:#x}>" if m.elem else "u8"
        return f"nn::nex::{'qVector' if m.kind == 'vector' else 'qList'}<{t}>"
    if m.kind == "inline":
        k = model.inline[m.vtable]
        return qualified(k.name, k.nex)
    name, nex, _ = model.opaque[m.target]
    return qualified(name, nex)


def render_body(mem: list[Member], model: Model, indent: str = "    ") -> list[str]:
    out, pos = [], 8
    for m in mem:
        if m.offset > pos:
            out.append(f"{indent}u8 _{pos:x}[{m.offset - pos:#x}];")
        out.append(f"{indent}{type_of(m, model)} m_{m.offset:x};")
        pos = m.offset + size_of(m, model, None)
    return out


def render_class(k: Klass, model: Model, dtor: str) -> list[str]:
    out = [f"class {k.name} : public nn::nex::RootObject {{", "public:"]
    if dtor:
        out.append(f"    {dtor}")
    out += render_body(k.members, model)
    out.append("};")
    for m in k.members:
        out.append(f"PKMN_OFFSET_ASSERT({k.name}, m_{m.offset:x}, {m.offset:#x});")
    return out


HEADER = """// Scope: common
// NEX 4.6.8's DDL data classes (tools/nexclasses.py): each _DDL_X holds a
// structure's fields, and X derives from it. Only what their destructors show
// is declared (Strings, containers, member classes); the scalars are padding.
// The class names are their RTTI's; Unk_<vtable> are placeholders.
{includes}

// An element of a container of polymorphic objects (a placeholder: which class
// isn't known, only its size).
template <size_t N>
class Unk_Element : public nn::nex::RootObject {
public:
    virtual ~Unk_Element();
    u8 _8[N - 8];
};
"""


def render(model: Model) -> str:
    heads = {"nn/nex/String.h", "nn/nex/qList.h", "nn/nex/qVector.h"}
    heads |= {HEADERS[n] for n, nex, _ in model.opaque.values() if nex and n in HEADERS}
    out = [HEADER.replace("{includes}", "\n".join(f"#include <{h}>" for h in sorted(heads)))]
    # opaque member classes: declared, their destructors defined elsewhere
    for d2, (name, nex, size) in sorted(model.opaque.items(), key=lambda x: x[1][0]):
        if d2 in model.written or nex and name in HEADERS:
            continue
        body = [f"class {name} : public nn::nex::RootObject {{", "public:", f"    virtual ~{name}();"]
        if size > 8:
            body.append(f"    u8 _8[{size - 8:#x}];")
        body.append("};")
        out.append(_ns(nex, body))
    done: set[int] = set()

    def inline_class(vt: int) -> None:
        if vt in done:
            return
        k = model.inline[vt]
        for m in k.members:
            if m.kind == "inline":
                inline_class(m.vtable)
        done.add(vt)
        out.append(_ns(k.nex, render_class(k, model, "")))

    for k in model.classes:
        for m in k.members:
            if m.kind == "inline":
                inline_class(m.vtable)
    if model.trivial:
        body = []
        for name, d2, d0 in model.trivial:
            body += [f"class {name} : public RootObject {{", "public:", f"    virtual ~{name}();", "};", "",
                     f"// {d2 + BASE:#x} (D2), {d0 + BASE:#x} (D0)", f"{name}::~{name}() {{}}", ""]
        out.append("// Classes with nothing but an empty destructor of their own.\n" + _ns(True, body[:-1]))
    for k in ordered(model):
        body = render_class(k, model, f"virtual ~{k.name}();")
        for name, _ in k.derived:
            body += ["", f"class {name} : public {k.name} {{", "public:", f"    virtual ~{name}();", "};"]
        body += ["", f"// {k.d2 + BASE:#x} (D2)" + (f", {k.d0 + BASE:#x} (D0)" if k.d0 is not None else ""),
                 f"{k.name}::~{k.name}() {{}}"]
        for name, d0 in k.derived:
            body += ["", f"// {d0 + BASE:#x} (D0; the D2 is {k.name}'s)", f"{name}::~{name}() {{}}"]
        out.append(_ns(k.nex, body))
    return "\n".join(out).rstrip() + "\n"


def ordered(model: Model) -> list[Klass]:
    """The classes, each after the classes its members are."""
    by_d2 = {k.d2: k for k in model.classes}
    out: list[Klass] = []
    seen: set[int] = set()

    def visit(k: Klass) -> None:
        if k.d2 in seen:
            return
        seen.add(k.d2)
        for m in k.members:
            if m.kind == "call" and m.target in by_d2:
                visit(by_d2[m.target])
        out.append(k)

    for k in model.classes:
        visit(k)
    return out


def _ns(nex: bool, body: list[str]) -> str:
    if not nex:
        return "\n".join(body) + "\n"
    return "\n".join(["namespace nn {", "namespace nex {", "", *body, "", "}  // namespace nex",
                      "}  // namespace nn"]) + "\n"


def names(model: Model) -> dict[int, str]:
    """Sword address -> mangled name of each destructor the C++ defines or calls."""
    out = {}
    for k in model.classes:
        out[k.d2] = mangle(k.name, k.nex, "D2")
        if k.d0 is not None:
            out[k.d0] = mangle(k.name, k.nex, "D0")
        for name, d0 in k.derived:
            out[d0] = mangle(name, k.nex, "D0")
    for d2, (name, nex, _) in model.opaque.items():
        out.setdefault(d2, mangle(name, nex, "D2"))
    for name, d2, d0 in model.trivial:
        out[d2] = mangle(name, True, "D2")
        out[d0] = mangle(name, True, "D0")
    return out


# --- the executable ----------------------------------------------------------

@dataclass
class Vt:
    addr: int                 # address point
    name: str | None          # RTTI name
    slots: list
    start: int
    base: str | None = None   # the RTTI name of its (first) base class


def class_of(vt: Vt) -> tuple[str, bool] | None:
    n = simple_name(vt.name)
    if n is not None:
        return n, True
    if vt.name is None:
        return f"Unk_{vt.start:x}", False
    return None


def build(vts: dict[int, Vt], code_of, got: dict[int, int], known: dict[int, str],
          lo: int = NEX_LO, hi: int = NEX_HI, verbose: bool = False, done: set[int] = frozenset()) -> Model:
    """The DDL classes of vtables in [lo, hi). `code_of(addr)` returns the
    instructions of the function at addr; `known` holds functions.csv's names;
    the classes whose D2 is in `done` are written elsewhere and left out."""
    by_slot0: dict[int, list[Vt]] = {}
    for v in vts.values():
        if v.slots and isinstance(v.slots[0], int):
            by_slot0.setdefault(v.slots[0], []).append(v)
    cache: dict[int, list[tuple]] = {}

    def ev_of(f: int) -> list[tuple]:
        if f not in cache:
            cache[f] = events(code_of(f), got)
        return cache[f]

    def inline_events(vt: int):
        v = vts.get(vt)
        if v is None or not v.slots or not isinstance(v.slots[0], int):
            return None
        return v.slots[0], ev_of(v.slots[0])

    model = Model([], {}, {})
    sizes: dict[int, list[int]] = {}
    why: dict[str, int] = {}
    for d2, group in sorted(by_slot0.items()):
        if not lo <= d2 < hi or d2 in NOT_MATCHING or d2 in done:
            continue
        try:
            own, mem = members(ev_of(d2), inline_events)
            base = vts.get(own)
            if base is None or len(base.slots) != 2 or base.slots[0] != d2:
                raise Unrecognized("not a two-slot class")
            name = simple_name(base.name)
            if name is None or not name.startswith("_DDL_"):
                raise Unrecognized("not a _DDL_ class")
            derived = []
            for v in group:
                if v.addr == own:
                    continue
                dn = simple_name(v.name)
                if dn != name[len("_DDL_"):] or len(v.slots) != 2:
                    raise Unrecognized("another class shares the destructor")
                derived.append((dn, v.slots[1]))
            # the member classes
            pending_inline: dict[int, Klass] = {}
            pending_opaque: dict[int, tuple[str, bool]] = {}
            _collect(mem, vts, ev_of, known, pending_inline, pending_opaque)
        except Unrecognized as e:
            k = str(e).split(" at ")[0]
            why[k] = why.get(k, 0) + 1
            if verbose:
                print(f"  {d2 + BASE:#x}: {e}", file=sys.stderr)
            continue
        model.inline.update(pending_inline)
        for t, (n, nex) in pending_opaque.items():
            model.opaque.setdefault(t, (n, nex, 8))
        model.classes.append(Klass(name, True, own, d2, base.slots[1], mem, sorted(derived)))
        _gaps(mem, sizes)
    for t, gaps in sizes.items():
        n, nex, _ = model.opaque[t]
        model.opaque[t] = (n, nex, min(gaps))
    # a member whose class is written here too
    written = {k.d2: k for k in model.classes}
    for t in [t for t in model.opaque if t in written]:
        k = written[t]
        model.opaque[t] = (k.name, k.nex, class_size(k.members, model))
        model.written.add(t)
    model.trivial = trivial_classes(vts, by_slot0, code_of, lo, hi, done)
    if verbose:
        print("refused:", why, file=sys.stderr)
    return model


def trivial_classes(vts, by_slot0, code_of, lo, hi, done) -> list[tuple[str, int, int]]:
    """Classes derived from RootObject, with nothing but an empty destructor of
    their own: the D2 is a `ret` (the empty body stores no vtable), the D0
    tail-calls operator delete."""
    out = []
    for v in sorted(vts.values(), key=lambda v: v.addr):
        name = simple_name(v.name)
        if name is None or name in ELSEWHERE or v.base != ROOT_OBJECT or len(v.slots) != 2                 or not all(isinstance(s, int) for s in v.slots):
            continue
        d2, d0 = v.slots
        if not lo <= d2 < hi or not lo <= d0 < hi or d2 in done or len(by_slot0.get(d2, [])) != 1:
            continue
        c2, c0 = code_of(d2), code_of(d0)
        if [(x.mnemonic, x.op_str) for x in c2] != [("ret", "")]:
            continue
        if len(c0) != 1 or c0[0].mnemonic != "b" or _int(c0[0].op_str) - BASE != DELETE:
            continue
        out.append((name, d2, d0))
    return out


def _collect(mem: list[Member], vts, ev_of, known, inl: dict, opq: dict) -> None:
    for m in mem:
        if m.kind == "inline":
            c = class_of(vts[m.vtable])
            if c is None:
                raise Unrecognized(f"inline member at {m.offset:#x}: a template class")
            inl[m.vtable] = Klass(c[0], c[1], m.vtable, m.target, None, m.members)
            _collect(m.members, vts, ev_of, known, inl, opq)
        elif m.kind == "call":
            ev = ev_of(m.target)
            if not ev or ev[0][0] != "vptr" or ev[0][1] != 0 or ev[0][2] not in vts:
                raise Unrecognized(f"member at {m.offset:#x}: its destructor stores no vtable")
            v = vts[ev[0][2]]
            c = class_of(v)
            if c is None or v.slots[0] != m.target:
                raise Unrecognized(f"member at {m.offset:#x}: not its class's D2")
            name = known.get(m.target)
            if name and name != mangle(c[0], c[1], "D2"):
                raise Unrecognized(f"member at {m.offset:#x}: its destructor is named {name}")
            opq[m.target] = c


def _gaps(mem: list[Member], sizes: dict[int, list[int]]) -> None:
    """The room each called member's class has (the next member's offset): its
    size is at most the smallest."""
    for a, b in zip(mem, mem[1:]):
        if a.kind == "call":
            sizes.setdefault(a.target, []).append(b.offset - a.offset)


def load(verbose: bool = False) -> Model:
    from common import load_module, read_functions_csv
    import vtables as V
    m = V.load("sword")
    img = m.img
    funcs = dict(load_module("sword")["functions"])

    def tname(ti):
        t = m.got.get(ti + 8) if ti is not None else None
        if t is None:
            return None
        return img[t:img.index(b"\0", t)].decode(errors="replace")

    def bname(ti):
        b = m.got.get(ti + 16) if ti is not None else None
        return tname(b) if b is not None else None

    vts = {v.addr: Vt(v.addr, tname(v.typeinfo), v.slots, v.start, bname(v.typeinfo)) for v in m.vtables}
    rows = [f for f in read_functions_csv() if f.sword is not None]
    known = {f.sword: f.name for f in rows if f.name}
    done = {f.sword for f in rows if f.status == "O"}

    def code_of(a: int) -> list[Ins]:
        return disasm(img[a:a + funcs[a]], a + BASE)

    return build(vts, code_of, m.got, known, verbose=verbose, done=done)


def cmd_list(args) -> int:
    model = load(args.verbose)
    for k in model.classes:
        print(f"{k.d2 + BASE:#x} {k.name}: " + ", ".join(
            f"{m.kind}{'<' + hex(m.elem) + '>' if m.elem else ''}@{m.offset:#x}" for m in k.members))
    print(f"{len(model.classes)} classes", file=sys.stderr)
    return 0


def cmd_write(args) -> int:
    from common import read_functions_csv
    model = load(args.verbose)
    Path(args.out).write_text(render(model), encoding="utf-8", newline="\n")
    if args.names:
        rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
        with open(args.names, "w", newline="") as fh:
            w = csv.writer(fh, lineterminator="\n")
            w.writerow(("Name", "Sword", "Shield"))
            for a, n in sorted(names(model).items()):
                r = rows[a]
                w.writerow((n, f"{a + BASE:#x}", f"{r.shield + BASE:#x}" if r.shield is not None else ""))
    print(f"wrote {len(model.classes)} classes to {args.out}", file=sys.stderr)
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("list", help="the classes and their members")
    p.add_argument("-v", "--verbose", action="store_true")
    p.set_defaults(func=cmd_list)
    p = sub.add_parser("write", help="write the C++")
    p.add_argument("out")
    p.add_argument("--names", help="write a Name,Sword,Shield CSV for tools/funcs.py name --from-file")
    p.add_argument("-v", "--verbose", action="store_true")
    p.set_defaults(func=cmd_write)
    args = ap.parse_args()
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
