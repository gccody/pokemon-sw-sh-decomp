#!/usr/bin/env python3
"""Write placeholder C++ for small straight-line leaf functions.

    python tools/leafgen.py scan --max 32               # what it can lift, by kind (game, gflib3, gflnet3)
    python tools/leafgen.py write --max 32              # into src/unsorted/leaf
    python tools/leafgen.py names --out map.csv         # after a build: the mangled names, for funcs.py

A *leaf* here is a function with no branch other than its final `ret`, no
call, and no reference to anything but its arguments: loads and stores
through x0..x7, constants, masks, shifts, compares and selects. That covers
getters and setters of nested fields, flag tests and updates, bitfields,
range checks and constant returns. `lift()` turns one into C++: a placeholder
struct per pointer it dereferences (`Unk_<addr>` for the first argument,
`Unk_<addr>_<offset>` for a pointer loaded from it, ...), with a field per
offset (`field_<offset>`, typed by the access width and signedness), and a
function body that computes the same thing.

The C++ is a guess at the source that check.py then judges. `write` keeps
only what compiles alone without a warning (C's integer promotions can turn
a wrong type guess into a different meaning, and those warn). Then build,
`names` reads the mangled names from the objects (Name,Sword,Shield, for
`funcs.py name --from-file`), and check.py says what matches: rerun `write
--only` with those addresses (docs/game_code.md, "Batch 2"). What `lift()`
doesn't understand it refuses (LiftError), so nothing it writes is a guess
about semantics: only about how the source spelled them.

Like batch 1 (src/unsorted/leaf/), the functions between two static
initialisers go in one file, named after the first one, because such a run
is one or more whole TUs (tools/segments.py).
"""
from __future__ import annotations

import argparse
import re
import struct
import sys
from collections import Counter
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

RET = 0xD65F03C0


class LiftError(Exception):
    """The function uses something lift() doesn't model."""


# --------------------------------------------------------------------------- types
WIDTH = {"u8": 1, "s8": 1, "bool": 1, "u16": 2, "s16": 2, "u32": 4, "s32": 4, "u64": 8, "s64": 8,
         "f32": 4, "f64": 8}
SIGNED = {"s8", "s16", "s32", "s64"}


def int_type(width: int, signed: bool = False) -> str:
    return {1: "s8", 2: "s16", 4: "s32", 8: "s64"}[width] if signed else {1: "u8", 2: "u16", 4: "u32",
                                                                          8: "u64"}[width]


# --------------------------------------------------------------------------- expressions
@dataclass(frozen=True)
class Arg:
    index: int
    fp: bool = False


@dataclass(frozen=True)
class Load:
    base: object          # the pointer expression
    offset: int
    type: str             # field type


@dataclass(frozen=True)
class Const:
    value: int
    width: int            # 4 (w) or 8 (x)


@dataclass(frozen=True)
class Op:
    op: str               # & | ^ + - << >> (logical) >>s (arithmetic) ~
    a: object
    b: object = None
    width: int = 4


@dataclass(frozen=True)
class Cmp:
    cond: str             # eq ne hi hs lo ls gt ge lt le
    a: object
    b: object
    test: bool = False    # tst (a & b) instead of cmp (a - b)


@dataclass(frozen=True)
class Select:
    cond: Cmp
    a: object
    b: object
    width: int


@dataclass(frozen=True)
class AddrOf:
    base: object
    offset: int


COND_INV = {"eq": "ne", "ne": "eq", "hi": "ls", "ls": "hi", "hs": "lo", "lo": "hs", "gt": "le", "le": "gt",
            "ge": "lt", "lt": "ge"}
UNSIGNED_CONDS = {"hi", "hs", "lo", "ls"}
SIGNED_CONDS = {"gt", "ge", "lt", "le"}


# --------------------------------------------------------------------------- decoding
_REG = re.compile(r"^(?:([wx])(\d+)|([wx])zr|(sp)|([sd])(\d+))$")


def _reg(s: str) -> tuple[str, int | None]:
    """'w8' -> ('w', 8), 'xzr' -> ('x', None), 's0' -> ('s', 0)."""
    m = _REG.match(s.strip())
    if not m:
        raise LiftError(f"register {s!r}")
    if m.group(1):
        return m.group(1), int(m.group(2))
    if m.group(3):
        return m.group(3), None
    if m.group(4):
        raise LiftError("sp")
    return m.group(5), int(m.group(6))


def _imm(s: str) -> int:
    s = s.strip().lstrip("#")
    return int(s, 0)


def _mem(s: str) -> tuple[int, int]:
    """'[x0, #0x10]' -> (0, 0x10). Only base + immediate."""
    m = re.match(r"^\[(x\d+)(?:, #(-?0x[0-9a-f]+|-?\d+))?\]$", s.strip())
    if not m:
        raise LiftError(f"address {s!r}")
    return int(m.group(1)[1:]), int(m.group(2), 0) if m.group(2) else 0


def _split_ops(op_str: str) -> list[str]:
    out, depth, cur = [], 0, ""
    for ch in op_str:
        if ch == "[":
            depth += 1
        elif ch == "]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def disassemble(code: bytes, addr: int = 0) -> list[tuple[str, list[str]]]:
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    out = []
    n = len(code) // 4
    insns = list(md.disasm(code, addr))
    if len(insns) != n:
        raise LiftError("undecodable word")
    for i in insns:
        out.append((i.mnemonic, _split_ops(i.op_str)))
    return out


# --------------------------------------------------------------------------- lifting
LOADS = {"ldrb": (1, False), "ldrsb": (1, True), "ldrh": (2, False), "ldrsh": (2, True), "ldrsw": (4, True),
         "ldurb": (1, False), "ldursb": (1, True), "ldurh": (2, False), "ldursh": (2, True), "ldursw": (4, True)}
STORES = {"strb": 1, "strh": 2, "sturb": 1, "sturh": 2}
CONDS = set(COND_INV)


@dataclass
class Lifted:
    stores: list[tuple[object, int, str, object]] = field(default_factory=list)  # (base, offset, type, value)
    ret: object = None    # what w0/x0 or s0 holds at the ret, if the function wrote it


def lift(code: bytes) -> Lifted:
    """Symbolically execute a straight-line leaf function (see the module docstring)."""
    if len(code) < 4 or struct.unpack_from("<I", code, len(code) - 4)[0] != RET:
        raise LiftError("doesn't end with ret")
    insns = disassemble(code)
    regs: dict[tuple[str, int], object] = {}
    for i in range(8):
        regs[("x", i)] = Arg(i)
        regs[("f", i)] = Arg(i, fp=True)
    flags: Cmp | None = None
    out = Lifted()
    written: set[tuple[str, int]] = set()

    def get(r: str) -> object:
        kind, n = _reg(r)
        if n is None:
            return Const(0, 8 if kind == "x" else 4)
        key = ("f", n) if kind in "sd" else ("x", n)
        if key not in regs:
            raise LiftError(f"read of {r} before it's written")
        v = regs[key]
        if kind == "w" and isinstance(v, Const):
            return Const(v.value & 0xFFFFFFFF, 4)
        return v

    def put(r: str, v: object) -> None:
        kind, n = _reg(r)
        if n is None:
            raise LiftError("write to zr")
        key = ("f", n) if kind in "sd" else ("x", n)
        regs[key] = v
        written.add(key)

    def width_of(r: str) -> int:
        return 8 if _reg(r)[0] in "xd" else 4

    for mn, ops in insns[:-1]:
        if mn in ("ldr", "ldur") or mn in LOADS:
            dst, mem = ops
            base, off = _mem(mem)
            kind = _reg(dst)[0]
            if mn in LOADS:
                w, signed = LOADS[mn]
                t = int_type(w, signed)
            elif kind == "s":
                t = "f32"
            elif kind == "d":
                t = "f64"
            else:
                t = int_type(8 if kind == "x" else 4)
            put(dst, Load(get(f"x{base}"), off, t))
        elif mn in ("str", "stur") or mn in STORES:
            src, mem = ops
            base, off = _mem(mem)
            kind = _reg(src)[0]
            if mn in STORES:
                t = int_type(STORES[mn])
            elif kind == "s":
                t = "f32"
            elif kind == "d":
                t = "f64"
            else:
                t = int_type(8 if kind == "x" else 4)
            out.stores.append((get(f"x{base}"), off, t, get(src)))
        elif mn == "mov":
            dst, src = ops
            if src.startswith("#"):
                put(dst, Const(_imm(src) & ((1 << (8 * width_of(dst))) - 1), width_of(dst)))
            else:
                put(dst, get(src))
        elif mn in ("movz", "movk"):
            raise LiftError(mn)
        elif mn in ("and", "orr", "eor", "add", "sub", "lsl", "lsr", "asr"):
            if len(ops) != 3:
                raise LiftError(f"{mn} with a shifted operand")
            dst, a, b = ops
            w = width_of(dst)
            av = get(a)
            bv = Const(_imm(b), w) if b.startswith("#") else get(b)
            if mn in ("add", "sub") and isinstance(bv, Const) and _is_pointer_like(av) and w == 8 and mn == "add":
                put(dst, AddrOf(av, bv.value))
                continue
            sym = {"and": "&", "orr": "|", "eor": "^", "add": "+", "sub": "-", "lsl": "<<", "lsr": ">>",
                   "asr": ">>s"}[mn]
            put(dst, Op(sym, av, bv, w))
        elif mn == "mvn":
            dst, a = ops
            put(dst, Op("~", get(a), None, width_of(dst)))
        elif mn == "neg":
            dst, a = ops
            put(dst, Op("-", Const(0, width_of(dst)), get(a), width_of(dst)))
        elif mn == "ubfx":
            dst, src, lsb, wid = ops
            w = width_of(dst)
            put(dst, Op("&", Op(">>", get(src), Const(_imm(lsb), w), w), Const((1 << _imm(wid)) - 1, w), w))
        elif mn in ("bfxil", "bfi"):
            dst, src, lsb, wid = ops
            w = width_of(dst)
            lsb_v, wid_v = _imm(lsb), _imm(wid)
            mask = (1 << wid_v) - 1
            full = (1 << (8 * w)) - 1
            if mn == "bfxil":
                part = Op("&", Op(">>", get(src), Const(lsb_v, w), w) if lsb_v else get(src), Const(mask, w), w)
                put(dst, Op("|", Op("&", get(dst), Const(full & ~mask, w), w), part, w))
            else:
                part = Op("<<", Op("&", get(src), Const(mask, w), w), Const(lsb_v, w), w) if lsb_v else \
                    Op("&", get(src), Const(mask, w), w)
                put(dst, Op("|", Op("&", get(dst), Const(full & ~(mask << lsb_v), w), w), part, w))
        elif mn in ("cmp", "cmn", "tst"):
            a, b = ops
            w = width_of(a)
            bv = Const(_imm(b), w) if b.startswith("#") else get(b)
            if mn == "cmn":
                if not isinstance(bv, Const):
                    raise LiftError("cmn register")
                bv = Const((-bv.value) & ((1 << (8 * w)) - 1), w)
            flags = Cmp("?", get(a), bv, test=mn == "tst")
        elif mn == "cset":
            dst, cond = ops
            if flags is None or cond not in CONDS:
                raise LiftError("cset without flags")
            put(dst, Cmp(cond, flags.a, flags.b, flags.test))
        elif mn == "csel":
            dst, a, b, cond = ops
            if flags is None or cond not in CONDS:
                raise LiftError("csel without flags")
            put(dst, Select(Cmp(cond, flags.a, flags.b, flags.test), get(a), get(b), width_of(dst)))
        else:
            raise LiftError(mn)

    # The result: whatever the function left in w0/x0 or s0, if it wrote it.
    if ("x", 0) in written and ("f", 0) in written:
        raise LiftError("writes both x0 and s0")
    if ("x", 0) in written:
        out.ret = regs[("x", 0)]
    elif ("f", 0) in written:
        out.ret = regs[("f", 0)]
    return out


def _is_bool_arg(e: object) -> bool:
    """`value & 1` of an argument: how clang stores or tests a bool argument."""
    return isinstance(e, Op) and e.op == "&" and isinstance(e.b, Const) and e.b.value == 1 and isinstance(e.a, Arg)


def _is_pointer_like(e: object) -> bool:
    return isinstance(e, Arg) or (isinstance(e, Load) and e.type in ("u64", "s64"))


# --------------------------------------------------------------------------- C++ emission
@dataclass
class StructDef:
    name: str
    fields: dict[int, str] = field(default_factory=dict)  # offset -> type (a type name or "<struct>*")


class Emitter:
    """Renders a Lifted function as C++ with placeholder structs."""

    def __init__(self, addr: int, lifted: Lifted):
        self.short = f"{addr & 0xFFFFFFFFF:x}" if addr < BASE else f"{addr - BASE:x}"
        self.lifted = lifted
        self.structs: dict[object, StructDef] = {}
        self.arg_types: dict[int, str] = {}   # x0..x7
        self.fp_types: dict[int, str] = {}    # s0..s7 / d0..d7

    # -- structs
    def struct_for(self, base: object) -> StructDef:
        if base in self.structs:
            return self.structs[base]
        if isinstance(base, Arg) and not base.fp:
            name = f"Unk_{self.short}" if base.index == 0 else f"Unk_{self.short}_arg{base.index}"
            self.arg_types[base.index] = f"{name}*"
        elif isinstance(base, Load) and base.type in ("u64", "s64"):
            parent = self.struct_for(base.base)
            name = f"{parent.name}_{base.offset:x}"
            self.set_field(parent, base.offset, f"{name}*")
        else:
            raise LiftError("dereference of a computed pointer")
        s = StructDef(name)
        self.structs[base] = s
        return s

    def set_field(self, s: StructDef, offset: int, t: str) -> None:
        old = s.fields.get(offset)
        if old is None:
            s.fields[offset] = t
        elif old != t:
            # A plain integer field read as a pointer elsewhere becomes the pointer.
            if old.endswith("*") and t in ("u64", "s64"):
                return
            if t.endswith("*") and old in ("u64", "s64"):
                s.fields[offset] = t
                return
            if {old, t} <= {"u8", "bool"}:
                s.fields[offset] = "bool" if "bool" in (old, t) else "u8"
                return
            raise LiftError(f"field {offset:#x} is {old} and {t}")

    def field_expr(self, load_base: object, offset: int, t: str) -> str:
        s = self.struct_for(load_base)
        self.set_field(s, offset, t)
        return f"{self.ptr(load_base)}->field_{offset:x}"

    def ptr(self, base: object) -> str:
        if isinstance(base, Arg):
            return self.arg_name(base.index)
        if isinstance(base, Load):
            return self.field_expr(base.base, base.offset, f"{self.struct_for(base).name}*")
        raise LiftError("pointer")

    @staticmethod
    def arg_name(i: int) -> str:
        return "self" if i == 0 else ("value" if i == 1 else f"arg{i}")

    @staticmethod
    def fp_name(i: int) -> str:
        return "fvalue" if i == 0 else f"farg{i}"

    # -- expressions
    def is_pointer(self, e: object) -> bool:
        """Whether e renders as a pointer (so far: render() runs twice to know them all)."""
        if isinstance(e, AddrOf):
            return True
        if isinstance(e, Arg) and not e.fp:
            return self.arg_types.get(e.index, "").endswith("*")
        if isinstance(e, Load):
            s = self.structs.get(e.base)
            return s is not None and s.fields.get(e.offset, "").endswith("*")
        return False

    def c_width(self, e: object) -> int:
        """The width C computes e in, after the usual arithmetic conversions (int is 4)."""
        if isinstance(e, Const):
            return 4 if e.value < 1 << 31 else 8
        if isinstance(e, Op):
            return max(4, self.c_width(e.a), self.c_width(e.b) if e.b is not None else 4)
        if isinstance(e, Select):
            return max(4, self.c_width(e.a), self.c_width(e.b))
        return max(4, WIDTH.get(self.type_of(e), 8))

    def type_of(self, e: object) -> str:
        if isinstance(e, Load):
            return e.type
        if isinstance(e, Cmp):
            return "bool"
        if isinstance(e, Const):
            return int_type(e.width)
        if isinstance(e, Op):
            return int_type(e.width, e.op == ">>s")
        if isinstance(e, Select):
            return int_type(e.width)
        if isinstance(e, AddrOf):
            return "ptr"
        if isinstance(e, Arg):
            if e.fp:
                return self.fp_types.get(e.index, "f32")
            return self.arg_types.get(e.index, "u32")
        raise LiftError("type")

    def expr(self, e: object, want: str | None = None) -> str:
        if isinstance(e, Const):
            return _const(e.value, want or int_type(e.width))
        if isinstance(e, Arg):
            if e.fp:
                if want not in (None, "f32", "f64"):
                    raise LiftError("float argument used as an integer")
                self.fp_types.setdefault(e.index, want or "f32")
                return self.fp_name(e.index)
            if e.index == 0 and want != "self":
                raise LiftError("self used as a value")
            self.arg_types.setdefault(e.index, want or "u32")
            return self.arg_name(e.index)
        if isinstance(e, Load):
            return self.field_expr(e.base, e.offset, e.type)
        if isinstance(e, AddrOf):
            s = self.struct_for(e.base)
            self.set_field(s, e.offset, "u8")
            return f"&{self.ptr(e.base)}->field_{e.offset:x}"
        if isinstance(e, Op):
            if self.is_pointer(e.a) or self.is_pointer(e.b):
                raise LiftError("arithmetic on a pointer")
            if e.op in ("<<", "+", "-") and e.width == 8 and self.c_width(e) < 8:
                raise LiftError("64-bit arithmetic that C would do in int")
            if any(isinstance(x, Arg) and x.fp for x in (e.a, e.b)):
                raise LiftError("integer arithmetic on a float argument")
            if e.op == "~":
                return f"~{self.paren(e.a)}"
            if e.op == "&" and isinstance(e.b, Const) and e.b.value == 1 and isinstance(e.a, Arg):
                # A bool argument: clang masks it to bit 0 where it's stored or tested.
                self.arg_types.setdefault(e.a.index, "bool")
                if self.arg_types[e.a.index] == "bool":
                    return self.arg_name(e.a.index)
            op = ">>" if e.op == ">>s" else e.op
            return f"{self.paren(e.a)} {op} {self.paren(e.b)}"
        if isinstance(e, Cmp):
            return self.cond(e)
        if isinstance(e, Select):
            if self.is_pointer(e.a) or self.is_pointer(e.b):
                raise LiftError("select of a pointer")
            return f"{self.cond(e.cond)} ? {self.paren(e.a)} : {self.paren(e.b)}"
        raise LiftError("expression")

    def paren(self, e: object) -> str:
        s = self.expr(e)
        return f"({s})" if isinstance(e, (Op, Cmp, Select)) and not (isinstance(e, Op) and e.op == "~") else s

    def cond(self, c: Cmp) -> str:
        if c.test:
            if c.cond not in ("eq", "ne"):
                raise LiftError("tst with an ordered condition")
            if isinstance(c.b, Const) and c.b.value == 1 and isinstance(c.a, Arg):
                self.arg_types.setdefault(c.a.index, "bool")
                if self.arg_types[c.a.index] == "bool":
                    name = self.arg_name(c.a.index)
                    return name if c.cond == "ne" else f"!{name}"
            inner = f"({self.paren(c.a)} & {self.paren(c.b)})"
            return f"{inner} != 0" if c.cond == "ne" else f"{inner} == 0"
        if isinstance(c.a, Op) and c.a.op == "-" and isinstance(c.a.b, Const) and isinstance(c.b, Const) \
                and c.cond in ("lo", "ls"):
            # (x - lo) < n, unsigned: clang's form of the range check lo <= x < lo + n.
            lo = c.a.b.value
            hi = lo + c.b.value - (1 if c.cond == "lo" else 0)
            t = self.type_of(c.a.a)
            if t in SIGNED or t == "bool":
                raise LiftError("range check of a signed value")
            x = self.paren(c.a.a)
            return f"{x} >= {_const(lo, t)} && {x} <= {_const(hi, t)}" if lo else f"{x} <= {_const(hi, t)}"
        if isinstance(c.a, Op) and c.cond in UNSIGNED_CONDS:
            raise LiftError("unsigned compare of an arithmetic result")
        if self.is_pointer(c.a) or self.is_pointer(c.b):
            if c.cond in ("eq", "ne") and isinstance(c.b, Const) and c.b.value == 0:
                return f"{self.paren(c.a)} {'==' if c.cond == 'eq' else '!='} nullptr"
            raise LiftError("pointer compare")
        ta = self.type_of(c.a)
        if c.cond in SIGNED_CONDS and ta not in SIGNED:
            if isinstance(c.a, Load) and c.a.type in ("u32", "u64"):
                c = Cmp(c.cond, Load(c.a.base, c.a.offset, "s" + c.a.type[1:]), c.b, c.test)
            else:
                raise LiftError("signed compare of an unsigned value")
        if c.cond in UNSIGNED_CONDS and ta in SIGNED:
            raise LiftError("unsigned compare of a signed value")
        op = {"eq": "==", "ne": "!=", "hi": ">", "hs": ">=", "lo": "<", "ls": "<=", "gt": ">", "ge": ">=",
              "lt": "<", "le": "<="}[c.cond]
        if not isinstance(c.b, Const):
            return f"{self.paren(c.a)} {op} {self.paren(c.b)}"
        # The constant as the compare saw it: a w register compares 32 bits.
        want = self.type_of(c.a)
        if want in SIGNED:
            want = int_type(max(4, WIDTH[want]), True)
        return f"{self.paren(c.a)} {op} {_const(c.b.value, want)}"

    # -- the whole function
    def render(self) -> tuple[str, str]:
        """(struct definitions, function definition)."""
        lf = self.lifted
        body: list[str] = []
        stored = {base for base, _, _, _ in lf.stores}
        for base, off, t, value in lf.stores:
            if isinstance(value, AddrOf):
                raise LiftError("stores an address")
            lhs = self.field_expr(base, off, t)
            if _is_bool_arg(value) and t == "u8":
                self.structs[base].fields[off] = "bool"
                self.arg_types.setdefault(value.a.index, "bool")
            ft = self.structs[base].fields[off]
            rhs = self.expr(value, None if ft.endswith("*") else ft)
            if isinstance(value, Const) and value.value == 0 and ft.endswith("*"):
                rhs = "nullptr"
            body.append(f"    {lhs} = {rhs};")
        ret_type = "void"
        if lf.ret is not None:
            if isinstance(lf.ret, Arg) and lf.ret.index == 0 and not lf.ret.fp:
                raise LiftError("returns self")
            rt = self.type_of(lf.ret)
            if rt == "ptr":  # the address of a field
                rt = "u8*" if lf.ret.base in stored or not isinstance(lf.ret.base, Arg) else "const u8*"
                rhs = self.expr(lf.ret)
            else:
                rhs = self.expr(lf.ret, rt)
            if isinstance(lf.ret, Load) and lf.ret.type in ("u64", "s64"):
                ft = self.structs[lf.ret.base].fields[lf.ret.offset]
                if ft.endswith("*"):
                    rt = ft
            ret_type = rt
            body.append(f"    return {rhs};")
        params = []
        for i in range(max(self.arg_types, default=-1) + 1):
            t = self.arg_types.get(i)
            if t is None:
                params.append("void* /*unused*/" if i == 0 else "u32 /*unused*/")
                continue
            if t.endswith("*") and Arg(i) not in stored:
                t = "const " + t
            params.append(f"{t} {self.arg_name(i)}")
        # Floating-point arguments take s0.. in order whatever the integer ones do.
        for i in range(max(self.fp_types, default=-1) + 1):
            t = self.fp_types.get(i)
            params.append(f"{t} {self.fp_name(i)}" if t else "f32 /*unused*/")
        name = self.function_name(ret_type)
        func = f"{ret_type} {name}({', '.join(params)}) {{\n" + "".join(line + "\n" for line in body) + "}\n"
        return self.render_structs(), func

    def function_name(self, ret_type: str) -> str:
        lf = self.lifted
        if lf.stores and lf.ret is None:
            verb = "set"
        elif ret_type == "bool":
            verb = "check"
        elif lf.ret is not None and not lf.stores:
            verb = "get"
        else:
            verb = "update"
        return f"Unk_{self.short}_{verb}"

    def render_structs(self) -> str:
        out = []
        # Children before parents, so a parent's pointer member names a complete type.
        order = sorted(self.structs.values(), key=lambda s: -s.name.count("_"))
        for s in order:
            out.append(render_struct(s))
        return "\n".join(out)


def render_struct(s: StructDef) -> str:
    lines = [f"struct {s.name} {{"]
    pos = 0
    asserts = []
    for off in sorted(s.fields):
        t = s.fields[off]
        w = 8 if t.endswith("*") else WIDTH[t]
        if off % w:
            raise LiftError(f"misaligned field {off:#x}")
        if off < pos:
            raise LiftError(f"overlapping field {off:#x}")
        if off > pos:
            lines.append(f"    u8 _{pos:x}[0x{off - pos:x}];")
        lines.append(f"    {t} field_{off:x};")
        asserts.append(f"PKMN_OFFSET_ASSERT({s.name}, field_{off:x}, 0x{off:x});")
        pos = off + w
    lines.append("};")
    return "\n".join(lines + asserts) + "\n"


def _const(v: int, t: str) -> str:
    if t == "bool":
        return "true" if v else "false"
    if t in ("f32", "f64"):
        raise LiftError("float constant")
    if t.endswith("*"):
        if v:
            raise LiftError("pointer constant")
        return "nullptr"
    bits = 8 * WIDTH.get(t, 4)
    if t in SIGNED and v >= 1 << (bits - 1):
        v -= 1 << bits
        return str(v)
    if t in SIGNED or v < 10:
        return str(v)
    return f"0x{v:x}"


def generate(addr: int, code: bytes) -> tuple[str, str]:
    """(structs, function) of the leaf at `addr` (absolute), or LiftError."""
    try:
        lifted = lift(code)
        first = Emitter(addr, lifted)
        first.render()  # learns which fields and arguments are pointers
        second = Emitter(addr, lifted)
        second.structs, second.arg_types, second.fp_types = first.structs, first.arg_types, first.fp_types
        return second.render()
    except ValueError as e:  # an operand list of another shape (shifted or extended registers ...)
        raise LiftError(f"operands ({e})") from None


# --------------------------------------------------------------------------- files
def render_file(entries: list[tuple[int, str, str]]) -> str:
    """One TU of leaf functions: (addr, structs, function) in address order."""
    out = ["// Scope: common",
           "// Directly called leaf functions between two static initialisers (one or more",
           "// TUs). Placeholder types: rename and move once the owning classes are known.",
           "#include <types.h>", ""]
    for addr, structs, func in sorted(entries):
        if structs.strip():
            out.append(structs.rstrip("\n"))
            out.append("")
        out.append(f"// 0x{addr:x}")
        out.append(func.rstrip("\n"))
        out.append("")
    return "\n".join(out)


# --------------------------------------------------------------------------- CLI
def candidates(args) -> list[tuple[int, bytes]]:
    """Common, unnamed, U functions in the area, called only through B/BL, that end
    in ret with no other branch."""
    import funcs as F
    from common import AreaMap, area_names, in_area, load_module, nso_path, read_areas_csv, read_functions_csv
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = load_module("sword")
    img = mod["image"]
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), img, mod["text_end"])
    in_data = {v for v in dyn.slots.values() if isinstance(v, int)}
    called = F.branch_targets(img, 0, mod["text_end"] & ~3)
    areas = read_areas_csv()
    groups = args.area or ["game", "gflib3", "gflnet3"]
    for g in groups:
        if g not in area_names(areas):
            raise SystemExit(f"no area {g!r}")
    amap = AreaMap(areas, "sword")
    out = []
    for f in read_functions_csv():
        if f.status != "U" or f.scope != "common" or f.name or f.sword is None:
            continue
        size = f.size("sword")
        if size > args.max:
            continue
        a = f.sword
        if not any(in_area(amap.area_of(a), g) for g in groups):
            continue
        if F.reference_kind(a, called, in_data) != "call":
            continue
        out.append((a + BASE, img[a:a + size]))
    return out


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for name in ("scan", "write"):
        p = sub.add_parser(name)
        p.add_argument("--area", action="append", help="area or group (default: game, gflib3, gflnet3)")
        p.add_argument("--max", type=int, default=32, help="largest function, in bytes (default 32)")
        if name == "write":
            p.add_argument("--out", type=Path, default=ROOT / "src" / "unsorted" / "leaf")
            p.add_argument("--only", type=Path, help="file of addresses (one per line) to write; default all")
    p = sub.add_parser("names", help="mangled names of the leaf functions in a build, as Name,Sword,Shield")
    p.add_argument("--out", type=Path, required=True)
    p.add_argument("--dir", type=Path, default=ROOT / "src" / "unsorted" / "leaf", help="the sources' directory")
    p.add_argument("--build", type=Path, default=ROOT / "build" / "sword")
    args = ap.parse_args(argv)
    if args.cmd == "names":
        return cmd_names(args)

    cands = candidates(args)
    lifted: dict[int, tuple[str, str]] = {}
    why: Counter = Counter()
    for addr, code in cands:
        try:
            lifted[addr] = generate(addr, code)
        except LiftError as e:
            why[str(e).split(" ")[0]] += 1
    print(f"{len(cands)} candidates, {len(lifted)} lifted", file=sys.stderr)
    if args.cmd == "scan":
        kinds = Counter(func.split("(")[0].rsplit("_", 1)[1] for _, func in lifted.values())
        print("lifted: " + ", ".join(f"{k} {v}" for k, v in kinds.most_common()))
        print("refused: " + ", ".join(f"{k} {v}" for k, v in why.most_common(15)))
        return 0
    only = None
    if args.only:
        only = {int(x, 16) for x in args.only.read_text().split()}
    lifted = {a: v for a, v in lifted.items() if only is None or a in only}
    clang = ROOT / "toolchain" / "clang" / "bin" / ("clang++.exe" if sys.platform == "win32" else "clang++")
    if not clang.exists():
        raise SystemExit(f"{clang} missing: run tools/get_llvm.py")
    write_files(args.out, keep_compiling(lifted, clang))
    return 0


NAME = re.compile(r"Unk_([0-9a-f]+)_(?:set|get|check|update)")


def cmd_names(args) -> int:
    """Name,Sword,Shield of the unnamed functions whose leafgen function the build defines."""
    import elfobj
    from common import read_functions_csv

    stems = {p.name for p in args.dir.glob("*.cpp")}
    objs = [o for o in args.build.rglob("*.o*") if o.name.rsplit(".", 1)[0] in stems]
    if not objs:
        raise SystemExit(f"no objects of {args.dir} under {args.build}: build first")
    found: dict[int, str] = {}
    for o in objs:
        for sym in elfobj.parse(o.read_bytes()).symbols:
            m = NAME.search(sym.name)
            if m and sym.type == "STT_FUNC" and sym.shndx != "SHN_UNDEF":
                found[int(m.group(1), 16) + BASE] = sym.name
    rows = [f for f in read_functions_csv() if f.sword is not None and f.sword + BASE in found and not f.name]
    with open(args.out, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for f in rows:
            fh.write(f"{found[f.sword + BASE]},{f.sword_str},{f.shield_str}\n")
    print(f"{len(rows)} names to {args.out}", file=sys.stderr)
    return 0


def segment_of(addrs: list[int]) -> dict[int, int]:
    """addr -> the first function of its segment (tools/segments.py), for the file name."""
    import bisect

    import segments
    from common import load_module, nso_path
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = load_module("sword")
    img = mod["image"]
    nso = Nso(nso_path("sword").read_bytes())
    dyn = DynInfo(nso, img, mod["text_end"])
    inits = set(segments.init_array_targets(segments.dynamic_tags(img, nso.mod0.dynamic), dyn.slots))
    starts = [s for s, _ in mod["functions"]]
    # Segment starts: the function after each initialiser.
    seg_starts = sorted({starts[i + 1] for i, s in enumerate(starts[:-1]) if s in inits} | {0})
    out = {}
    for a in addrs:
        i = bisect.bisect_right(seg_starts, a - BASE) - 1
        out[a] = seg_starts[i]
    return out


def compiles(addr: int, structs: str, func: str, clang: Path) -> str | None:
    """None if the function compiles alone without a warning, else the first diagnostic.

    The generated C++ only guesses types, and C's integer promotions can make a
    guess mean something else (a tautological compare, a shift past the width).
    Those warn, so a warning drops the function like an error does."""
    import subprocess

    src = render_file([(addr, structs, func)])
    r = subprocess.run([str(clang), "-fsyntax-only", "-std=c++17", "-Wall", "-Wextra", "-Wno-unused-parameter",
                        "-Werror", "--target=aarch64-none-elf", "-nostdinc++", "-I", str(ROOT / "include"),
                        "-x", "c++", "-"], input=src, capture_output=True, text=True)
    if r.returncode == 0:
        return None
    return next((line for line in r.stderr.splitlines() if "error" in line), r.stderr.strip()[:200])


def keep_compiling(lifted: dict[int, tuple[str, str]], clang: Path) -> dict[int, tuple[str, str]]:
    from concurrent.futures import ThreadPoolExecutor

    with ThreadPoolExecutor() as pool:
        results = dict(zip(lifted, pool.map(lambda a: compiles(a, *lifted[a], clang), lifted)))
    dropped = {a: why for a, why in results.items() if why is not None}
    for a, why in sorted(dropped.items())[:10]:
        print(f"  dropped 0x{a:x}: {why.split('error: ', 1)[-1]}", file=sys.stderr)
    print(f"{len(dropped)} don't compile cleanly, dropped", file=sys.stderr)
    return {a: v for a, v in lifted.items() if a not in dropped}


def write_files(out_dir: Path, lifted: dict[int, tuple[str, str]]) -> None:
    """Merge the lifted functions into out_dir's per-segment files (one per run of
    functions between two static initialisers, named after its first function)."""
    seg = segment_of(list(lifted))
    existing = {}
    for p in out_dir.glob("Unk_*.cpp"):
        addrs = [int(m, 16) for m in re.findall(r"^// 0x([0-9a-f]+)$", p.read_text(encoding="utf-8"), re.M)]
        if addrs:
            existing[p] = addrs
    by_seg: dict[int, list[int]] = {}
    for a in lifted:
        by_seg.setdefault(seg[a], []).append(a)
    seg_of_existing = segment_of([a for addrs in existing.values() for a in addrs])
    file_for_seg: dict[int, Path] = {}
    for p, addrs in existing.items():
        file_for_seg[seg_of_existing[addrs[0]]] = p
    for s, addrs in sorted(by_seg.items()):
        entries = [(a, *lifted[a]) for a in addrs]
        old = file_for_seg.get(s)
        if old is not None:
            entries += parse_file(old.read_text(encoding="utf-8"))
            old.unlink()
        first = min(a for a, _, _ in entries)
        path = out_dir / f"Unk_{first - BASE:x}.cpp"
        path.write_text(render_file(entries), encoding="utf-8", newline="\n")
    print(f"wrote {len(lifted)} functions into {len(by_seg)} files", file=sys.stderr)


def parse_file(text: str) -> list[tuple[int, str, str]]:
    """(addr, structs, function) blocks of a leaf file written by render_file (or batch 1).

    A block is the struct definitions before a `// 0x<addr>` line (none for an
    empty function), that line, and the function: up to a line that is `}`, or
    the definition line itself when it ends with `{}`."""
    lines = text.split("#include <types.h>", 1)[1].splitlines()
    out = []
    pending: list[str] = []
    i = 0
    while i < len(lines):
        m = re.match(r"^// 0x([0-9a-f]+)$", lines[i])
        if not m:
            pending.append(lines[i])
            i += 1
            continue
        func = []
        i += 1
        while i < len(lines):
            func.append(lines[i])
            i += 1
            if func[-1] == "}" or func[-1].endswith("{}"):
                break
        structs = "\n".join(pending).strip("\n")
        out.append((int(m.group(1), 16), structs + "\n" if structs else "", "\n".join(func) + "\n"))
        pending = []
    return out


if __name__ == "__main__":
    raise SystemExit(main())
