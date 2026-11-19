#!/usr/bin/env python3
"""Write placeholder C++ for small straight-line leaf functions.

    python tools/leafgen.py scan --max 32               # what it can lift, by kind (Game Freak code)
    python tools/leafgen.py write --max 32              # into src/unsorted/leaf
    python tools/leafgen.py names --out map.csv         # after a build: the mangled names, for funcs.py

A *leaf* here is a function with no branch other than its final `ret` (or a
final tail call `b T`, see below) but one `cbz`/`cbnz` that skips the rest
(guard_shape), no other call, and no reference to
anything but its arguments: loads and stores
through x0..x7, constants, masks, shifts, compares and selects. That covers
getters and setters of nested fields, flag tests and updates, bitfields,
range checks and constant returns. A function that ends in `b T` instead
becomes `Unk_<T>(args...);`, with the argument registers it wrote (up to
the last one; the ones before it that it didn't touch are passed on) and T
declared `void Unk_<T>(...)`, `void*` for pointers. `lift()` turns one into C++: a placeholder
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


@dataclass(frozen=True)
class Page:
    addr: int             # what `adrp` computed (absolute)


@dataclass(frozen=True)
class Vptr:
    obj: object           # `ldr x8, [p, #0x48]!`: the vptr of p's interface at +0x48 (REF_IFACE)


@dataclass(frozen=True)
class Iface:
    obj: object           # ... and p + 0x48, the interface itself, which that writes back to p's register


@dataclass(frozen=True)
class VSlot:
    obj: object           # `ldr x1, [x8, #slot]` of such a vptr: one of its virtual functions
    slot: int


@dataclass(frozen=True)
class LocalAddr:
    off: int              # the address of a local on the stack: x29 + off (off < 0)


@dataclass(frozen=True)
class CallRet:
    index: int            # what the index-th call (Lifted.calls) returned in x0/w0


@dataclass(frozen=True)
class VTarget:
    obj: object           # a virtual call: `ldr x8, [obj] ; ldr x8, [x8, #slot] ; blr x8` with x0 = obj
    slot: int


@dataclass(frozen=True)
class RefTarget:
    obj: object           # a reference added or dropped (REF_SLOTS) through the interface at REF_IFACE
    slot: int


@dataclass(frozen=True)
class Call:
    target: int           # bl T (absolute)
    args: tuple           # x0.. at the call, up to the last one written since the previous call
    seq: int              # the store count before it (a call may change any memory)


@dataclass(frozen=True)
class DataAddr:
    addr: int             # what `adrp ; add` computed (absolute): the address of a string or a table


@dataclass(frozen=True)
class GlobalPtr:
    addr: int             # a global's address (relative), loaded from its GOT slot
    hidden: bool = False  # or one the TU defines (adrp + its offset, no GOT): declared hidden


# GOT slot -> what it holds (relative addresses), for `adrp ; ldr [slot]`: set
# by the callers that have the executable (main, tools/vtables.py).
GOT: dict[int, int] = {}

# gflib3's reference-counted objects (src/gflib3/Unk_239a418.h) keep an
# interface at +0x48 whose slot 2 adds a reference and slot 3 drops one:
# Unk_239a418_Ref<T> calls them as `static_cast<Unk_239a458*>(p)->vf4()` and
# `->vf5()`, `ldr x8, [p, #0x48]! ; ldr x1, [x8, #0x10 or #0x18] ; br x1` in a
# tail call. Every class on the object has that interface there.
# SDK imports called through the PLT (absolute stub address -> symbol name):
# check.py resolves a call to the name through the stub. Set by candidates().
IMPORTS: dict[int, str] = {}

_BUILTIN = {"h": "u8", "t": "u16", "j": "u32", "m": "u64", "a": "s8", "s": "s16", "i": "s32", "l": "s64",
            "b": "bool", "c": "char", "f": "f32", "d": "f64"}


# The C library functions game code calls, which a C name doesn't spell (musl's prototypes).
LIBC = {"memset": ["void*", "s32", "u64"], "memcpy": ["void*", "const void*", "u64"],
        "memmove": ["void*", "const void*", "u64"], "memcmp": ["const void*", "const void*", "u64"],
        "strcmp": ["const char*", "const char*"], "strncmp": ["const char*", "const char*", "u64"],
        "strncpy": ["char*", "const char*", "u64"], "strlen": ["const char*"], "strcpy": ["char*", "const char*"],
        "abort": []}
# their declarations (C linkage, the builtins' own types, so clang takes them as the library's)
LIBC_DECL = {"memset": 'extern "C" void* memset(void*, int, unsigned long);',
             "memcpy": 'extern "C" void* memcpy(void*, const void*, unsigned long);',
             "memmove": 'extern "C" void* memmove(void*, const void*, unsigned long);',
             "memcmp": 'extern "C" int memcmp(const void*, const void*, unsigned long);',
             "strcmp": 'extern "C" int strcmp(const char*, const char*);',
             "strncmp": 'extern "C" int strncmp(const char*, const char*, unsigned long);',
             "strncpy": 'extern "C" char* strncpy(char*, const char*, unsigned long);',
             "strlen": 'extern "C" unsigned long strlen(const char*);',
             "strcpy": 'extern "C" char* strcpy(char*, const char*);',
             "abort": 'extern "C" [[noreturn]] void abort();'}
NORETURN = {"abort"}  # a call to one ends its path


def demangle_simple(name: str) -> tuple[list[str], str, list[str]] | None:
    """(namespaces, name, parameter types) of a free function whose mangled name
    has only source names and builtin or `void*`/`const char*` parameters
    (`_ZN2nn3ldn15MakeIpv4AddressEhhhh`), or pointers to types of its own
    namespaces (`_ZN2nn2os9LockMutexEPNS0_9MutexTypeE`: `nn::os::MutexType*`,
    a parameter type `ns::Name*` spelled with its namespace); a C library
    function by LIBC; None for anything else."""
    if not name.startswith("_Z"):
        return ([], name, list(LIBC[name])) if name in LIBC else None
    rest, parts = name[2:], []
    nested = rest.startswith("N")
    if nested:
        rest = rest[1:]
    while rest and rest[0].isdigit():
        n = int(re.match(r"\d+", rest).group())
        rest = rest[len(str(n)):]
        parts.append(rest[:n])
        rest = rest[n:]
        if not nested:
            break
    if nested:
        if not rest.startswith("E"):
            return None
        rest = rest[1:]
    if not parts or any(not re.fullmatch(r"[A-Za-z_]\w*", x) for x in parts):
        return None
    # substitutions: the namespace prefixes (S_, S0_, ...), then each type as it's spelled
    subs = ["::".join(parts[:i + 1]) for i in range(len(parts) - 1)] if nested else []
    params = []
    if rest == "v":
        rest = ""
    while rest:
        for code, t in (("PKc", "const char*"), ("PKv", "const void*"), ("Pv", "void*"), ("Pc", "char*")):
            if rest.startswith(code):
                params.append(t)
                rest = rest[len(code):]
                break
        else:
            m = re.match(r"P(K?)N(S(\d*)_)?((?:\d+[A-Za-z_]\w*?)+)E", rest)
            if m and m.group(2) is not None:
                i = int(m.group(3)) + 1 if m.group(3) else 0
                if i >= len(subs):
                    return None
                scope, names, tail = subs[i], [], m.group(4)
                while tail:
                    n = int(re.match(r"\d+", tail).group())
                    tail = tail[len(str(n)):]
                    names.append(tail[:n])
                    tail = tail[n:]
                full = "::".join([scope, *names])
                if not full.startswith("::".join(parts[:-1]) + "::") or len(names) != 1:
                    return None  # only a type of the function's own namespace
                subs += [full, ("const " if m.group(1) else "") + full + "*"]
                params.append(("const " if m.group(1) else "") + names[0] + "*")
                rest = rest[m.end():]
                continue
            if rest[0] not in _BUILTIN:
                return None
            params.append(_BUILTIN[rest[0]])
            rest = rest[1:]
    return parts[:-1], parts[-1], params


# Sizes of the struct types copy_head makes (a struct's field of that type).
NESTED: dict[str, int] = {}

# Functions named in functions.csv (absolute address -> name), which a call may
# not declare as a placeholder: set by candidates().
NAMED: dict[int, str] = {}

# A placeholder callee's parameter types, as most of its callers in this run
# pass them (a pointer where any of them passes one): absolute address ->
# types. Set by main between two passes (unify_calls).
CALL_PARAMS: dict[int, tuple] = {}

REF_IFACE = 0x48
REF_SLOTS = {0x10: "vf4", 0x18: "vf5"}
REF_HEADER = '#include "gflib3/Unk_239a418.h"'


# What `adrp ; add` may point at, for a function that returns it: absolute
# address -> the string literal there (its C++ spelling), "" for other data
# (a table this TU defines), None for neither (code, a vtable: refused). Set
# by candidates(); without the executable every such address is refused.
DATA_AT = None


def data_at(addr: int) -> str | None:
    return DATA_AT(addr) if DATA_AT is not None else None


# Tail-call targets whose callers write fewer argument registers than others:
# address (absolute) -> the longest caller's parameter types, which the
# others pass on unchanged (unify_arity).
TAIL_TYPES: dict[int, list[str]] = {}

# Functions already written (and named) that a tail call can call by their own
# prototype: address (absolute) -> (return type, name, parameter types). Set
# by main from the sources (known_prototypes).
KNOWN: dict[int, tuple[str, str, list[str]]] = {}


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
    tail: int | None = None   # a final `b T`: T (absolute)
    args: list = field(default_factory=list)  # then: x0.. at the branch, up to the last one written
    guard: tuple | None = None  # (value, nonzero): the rest runs only if value != 0 (nonzero) or == 0
    zero_else: bool = False   # if it doesn't, the function returns else_value (else nothing)
    else_value: int = 0
    guard_stores: int = 0     # the stores before the guard: they're done either way
    narrow: set = field(default_factory=set)  # tail-call arguments an argument's 32 bits were moved into
    loads: Counter = field(default_factory=Counter)  # how often each load ran (more than once: reloaded)
    store_seq: list[int] = field(default_factory=list)  # per store: how many store instructions came before
    guard_seq: int = 0        # store instructions before the guard
    more_guards: list = field(default_factory=list)  # later guards to the same exit: (value, nonzero, seq)
    guard_kind: str = ""      # the first guard's mnemonic
    split: tuple | None = None  # two_paths: the branch the path didn't take, as a guard (value, nonzero)
    split_seq: int = 0        # the events before it
    noreturn: bool = False    # the path ends in a call that doesn't return (abort)
    splits: list = field(default_factory=list)  # decision_tree: per branch on the path, (guard or None, seq)
    vcall: tuple | None = None  # a final virtual tail call through REF_IFACE: (object, slot)
    calls: list = field(default_factory=list)  # Call, in order: a function with a frame
    ret_width: dict = field(default_factory=dict)  # call index -> widest read of its result (4: w0, 8: x0)
    load_seq: dict = field(default_factory=dict)  # Load -> the set of store counts it was loaded after
    stores_done: int = 0      # store instructions in all
    pairs: bool = False       # whether it loads with ldp (a struct copy, see Emitter.copy)


CALL_CODES = {"void*": "Pv", "bool": "b", "u8": "h", "s8": "a", "u16": "t", "s16": "s", "u32": "j", "s32": "i",
              "u64": "m", "s64": "l"}


def callee_name(target: int, types: list[str]) -> tuple[str, str]:
    """(placeholder name, mangled name) of a tail call's target: `void Unk_<T>(types...)`."""
    name = f"Unk_{target - BASE:x}"
    return name, f"_Z{len(name)}{name}" + ("".join(CALL_CODES[t] for t in types) or "v")


GUARDS = ("cbz", "cbnz", "tbz", "tbnz", *(f"b.{c}" for c in ("eq", "ne", "hi", "hs", "lo", "ls", "gt", "ge",
                                                               "lt", "le")))


CODE_TYPES = {v: k for k, v in CALL_CODES.items()}


def placeholder_params(name: str, target: int) -> list[str] | None:
    """The parameter types `callee_name` spelled into a placeholder's mangled
    name (`_Z11Unk_164d2f0mmm`: u64, u64, u64), or None for any other name."""
    short = f"Unk_{target - BASE:x}"
    prefix = f"_Z{len(short)}{short}"
    if not name.startswith(prefix):
        return None
    codes, out = name[len(prefix):], []
    if codes == "v":
        return []
    while codes:
        if codes.startswith("Pv"):
            out.append("void*")
            codes = codes[2:]
        elif codes[0] in CODE_TYPES and codes[0] != "P":
            out.append(CODE_TYPES[codes[0]])
            codes = codes[1:]
        else:
            return None
    return out


def guard_shape(insns: list[tuple[str, list[str]]], addr: int | None) -> tuple[int, list, int | None] | None:
    """For one `cbz`/`cbnz r, L` that skips the rest of the function:
    (its index, the path that doesn't branch, whether the other returns 0).

    L is either the final `ret` (`if (r) { ... }`: the path before it ends in
    `ret`, a tail call or falls through), or `mov w0, wzr ; ret` after the
    path's own `ret` (`if (!r) return 0; ...`). Other branches are refused."""
    ks = [i for i, (mn, _) in enumerate(insns) if mn in GUARDS]
    if not ks:
        return None
    k = ks[0]
    mn = insns[k][0]
    if addr is None:
        raise LiftError(f"{mn} without an address")
    to = (_imm(insns[k][1][-1]) - addr) // 4
    if not k + 1 < to < len(insns):
        raise LiftError(f"{mn} out of the function")
    # More guards to the same place, before it: early returns (Lifted.more_guards).
    if any((_imm(insns[j][1][-1]) - addr) // 4 != to or j > to for j in ks[1:]):
        raise LiftError(f"{mn}: more than one branch")
    rest = [(m, [o.strip() for o in ops]) for m, ops in insns[to:] if not _is_frame(m, ops)]
    zero: int | None = None  # what the other path returns (None: nothing)
    if rest == [("ret", [])]:
        pass
    elif len(rest) == 2 and rest[1] == ("ret", []) and rest[0][0] == "mov" and rest[0][1][0] in ("w0", "x0"):
        src = rest[0][1][1]
        if src in ("wzr", "xzr"):
            zero = 0
        elif src.startswith("#"):
            zero = _imm(src) & ((1 << (32 if rest[0][1][0] == "w0" else 64)) - 1)
        else:
            raise LiftError(f"{mn} to other code")
    else:
        raise LiftError(f"{mn} to other code")
    path = insns[:to]
    if zero is not None and path[-1][0] != "ret":
        # falls into the other return, or returns a tail call's result (void here)
        raise LiftError(f"{mn}: {'a tail call' if path[-1][0] == 'b' else 'the path falls'} or a constant")
    if path[-1][0] not in ("ret", "b"):
        path = path + [("ret", [])]
    return tuple(ks), path, zero


def lift(code: bytes, addr: int | None = None, path: list | None = None, split: int | None = None,
         splits: dict | None = None) -> Lifted:
    """Symbolically execute a straight-line leaf function (see the module docstring).

    With `addr`, the function may end in a tail call (`b T`) instead of `ret`:
    then `args` are the argument registers at the branch, up to the last
    one it wrote (the ones after it pass through, whatever T takes). It may
    also skip all that with one `cbz`/`cbnz` (guard_shape)."""
    if path is not None:
        insns, shape = list(path), None  # one path of a function with two (two_paths)
    else:
        insns = disassemble(code, addr or 0) if len(code) >= 4 and len(code) % 4 == 0 else []
        shape = guard_shape(insns, addr) if insns and insns[-1][0] == "ret" else None
    k, zero = None, None
    if shape is not None:
        k, insns, zero = shape
    if shape is None and insns and insns[-1][0] == "br":
        insns = insns + [("ret", [])]  # a virtual tail call, handled in the loop
    noreturn = bool(insns) and insns[-1][0] == "bl" and addr is not None and \
        IMPORTS.get(_imm(insns[-1][1][0])) in NORETURN
    if noreturn:
        insns = insns + [("ret", [])]  # abort(): the path's last statement
    tail = None
    if not insns:
        raise LiftError("doesn't end with ret")
    if addr is not None and insns[-1][0] == "b":
        tail = _imm(insns[-1][1][0])
    elif insns[-1][0] != "ret":
        raise LiftError("doesn't end with ret")
    regs: dict[tuple[str, int], object] = {}
    for i in range(8):
        regs[("x", i)] = Arg(i)
        regs[("f", i)] = Arg(i, fp=True)
    flags: Cmp | None = None
    out = Lifted()
    written: set[tuple[str, int]] = set()
    since: set[tuple[str, int]] = set()   # written since the last call
    framed = False
    inner = 0                             # calls before the last instruction (bl, blr): need a frame
    tail_br = False                       # the function ends in a virtual tail call (br)

    def call_args(virtual: bool, at_least: int = 0) -> tuple:
        """x0.. at a call: up to the last one written since the previous call
        (or the start), the ones before it passed on; for a virtual call x0 is
        the object, and the rest follow."""
        if any(("f", i) in since for i in range(8)):
            raise LiftError("floating-point call argument")
        n = max((i + 1 for i in range(8) if ("x", i) in since), default=at_least)
        n = max(n, at_least)
        args = []
        for i in range(1 if virtual else 0, n):
            v = regs.get(("x", i))
            if v is None:
                raise LiftError("call argument the previous call left")
            args.append(v)
        return tuple(args)

    def get(r: str) -> object:
        kind, n = _reg(r)
        if n is None:
            return Const(0, 8 if kind == "x" else 4)
        key = ("f", n) if kind in "sd" else ("x", n)
        if key not in regs:
            raise LiftError(f"read of {r} before it's written")
        v = regs[key]
        if isinstance(v, CallRet):
            out.ret_width[v.index] = max(out.ret_width.get(v.index, 0), 8 if kind == "x" else 4)
        if kind == "w" and isinstance(v, Const):
            return Const(v.value & 0xFFFFFFFF, 4)
        return v

    narrow: set[int] = set()

    def put(r: str, v: object) -> None:
        kind, n = _reg(r)
        if n is None:
            raise LiftError("write to zr")
        key = ("f", n) if kind in "sd" else ("x", n)
        regs[key] = v
        written.add(key)
        since.add(key)
        if key[0] == "x":
            narrow.discard(n)

    def width_of(r: str) -> int:
        return 8 if _reg(r)[0] in "xd" else 4

    def guard_value(mn: str, ops: list[str]) -> tuple[object, bool]:
        """(value, nonzero): the rest of the function runs if value != 0
        (nonzero) or == 0. cbz/cbnz test a register, tbz/tbnz one of its bits,
        b.<cond> the flags (value is then the condition the rest runs under)."""
        if mn.startswith("b."):
            if flags is None:
                raise LiftError(f"{mn} without flags")
            return Cmp(COND_INV[mn[2:]], flags.a, flags.b, flags.test), True
        v = get(ops[0])
        if not isinstance(v, (Load, Arg, CallRet)) or (isinstance(v, Load) and width_of(ops[0]) < WIDTH[v.type]):
            raise LiftError(f"{mn} of a computed value")
        if mn in ("tbz", "tbnz"):
            bit = _imm(ops[1])
            return Op("&", v, Const(1 << bit, width_of(ops[0])), width_of(ops[0])), mn == "tbz"
        return v, mn == "cbz"

    fp = 0  # x29 = sp + fp

    def local(mem: str) -> tuple[object, int] | None:
        """(LocalAddr, 0) for a load or store of a local: [x29, #-k] or [sp, #k]."""
        m = re.match(r"^\[(sp|x29)(?:, #(-?0x[0-9a-f]+|-?\d+))?\]$", mem.strip())
        if not m:
            return None
        k = int(m.group(2), 0) if m.group(2) else 0
        off = k if m.group(1) == "x29" else k - fp
        if off >= 0:
            raise LiftError("the frame record or the caller's frame")
        return LocalAddr(off), 0

    for idx, (mn, ops) in enumerate(insns[:-1]):
        if mn == "add" and [o.strip() for o in ops[:2]] == ["x29", "sp"]:
            fp = _imm(ops[2]) if len(ops) > 2 else 0
        if _is_frame(mn, ops):
            framed = True
            continue
        if mn in ("add", "sub") and len(ops) == 3 and ops[1].strip() in ("sp", "x29") and ops[2].strip().startswith("#"):
            imm = _imm(ops[2])
            off = (imm if mn == "add" else -imm) - (fp if ops[1].strip() == "sp" else 0)
            if off >= 0:
                raise LiftError("the frame record's address")
            put(ops[0], LocalAddr(off))
            continue  # the frame record and the callee-saved registers (x19-x28), kept across calls
        if mn in ("bl", "blr") and addr is not None:
            if mn == "blr":
                since.discard(("x", _reg(ops[0])[1]))
                v = get(ops[0])
                target = virtual_target(v)
                if target is None and isinstance(v, VSlot) and regs.get(("x", 0)) == Iface(v.obj):
                    target = RefTarget(v.obj, v.slot)
                elif target is None or regs.get(("x", 0)) != target.obj:
                    raise LiftError("blr")
            else:
                target = _imm(ops[0])
            out.calls.append(Call(target, call_args(mn == "blr"), out.stores_done))
            out.stores_done += 1
            inner += 1
            for i in list(range(19)):
                regs.pop(("x", i), None)
            for i in range(32):
                regs.pop(("f", i), None)
            regs[("x", 0)] = CallRet(len(out.calls) - 1)
            since.clear()
            flags = None
            continue
        if idx == split:
            out.split = guard_value(mn, ops)  # this path runs on if split's value is nonzero (or zero)
            out.split_seq = out.stores_done
            continue
        if splits is not None and idx in splits:
            # a branch of decision_tree's: taken (no condition kept) or not (the condition it runs under)
            out.splits.append((None if splits[idx] else guard_value(mn, ops), out.stores_done))
            continue
        if k is not None and idx in k[1:]:
            out.more_guards.append((*guard_value(mn, ops), out.stores_done))
            out.stores_done += 1
            continue
        if k is not None and idx == k[0]:
            out.guard = guard_value(mn, ops)
            out.guard_kind = mn
            out.guard_seq = out.stores_done
            out.stores_done += 1  # what's loaded after it is read inside the guard
            out.guard_stores = len(out.stores)
            out.zero_else = zero is not None
            out.else_value = zero or 0
            continue
        if mn == "adrp" and addr is not None:
            dst, page = ops
            put(dst, Page(_imm(page)))
        elif mn == "ldr" and ops[1].strip().endswith("]!"):
            dst, mem = ops
            base, off = _mem(mem.strip()[:-1])
            obj = get(f"x{base}")
            if off != REF_IFACE or _reg(dst)[0] != "x" or not isinstance(obj, (Load, Arg)) or \
                    (isinstance(obj, Arg) and obj.fp):
                raise LiftError(f"address {mem!r}")
            put(dst, Vptr(obj))
            put(f"x{base}", Iface(obj))
        elif mn == "ldr" and isinstance(get(f"x{_mem(ops[1])[0]}"), Vptr):
            dst, mem = ops
            base, off = _mem(mem)
            if off not in REF_SLOTS:
                raise LiftError(f"slot {off:#x} of the interface")
            put(dst, VSlot(get(f"x{base}").obj, off))
        elif mn == "br" and idx == len(insns) - 2:
            v = get(ops[0])
            target = virtual_target(v)
            if target is not None and regs.get(("x", 0)) == target.obj:
                since.discard(("x", _reg(ops[0])[1]))  # the function's address, not an argument
                # `br xN`: clang takes the first register after the arguments
                reg = _reg(ops[0])[1]
                out.calls.append(Call(target, call_args(True, reg if reg < 8 else 0), out.stores_done))
                out.stores_done += 1
                tail_br = True
                continue
            if not isinstance(v, VSlot) or regs.get(("x", 0)) != Iface(v.obj):
                raise LiftError("br")
            out.vcall = (v.obj, v.slot)
        elif mn in ("ldr", "ldur") or mn in LOADS:
            dst, mem = ops
            loc = local(mem)
            base, off = (None, 0) if loc else _mem(mem)
            kind = _reg(dst)[0]
            b = loc[0] if loc else get(f"x{base}")
            if isinstance(b, Page):
                # A GOT slot: the address of a global another TU defines.
                slot = b.addr + off - BASE
                if mn == "ldr" and kind == "x" and slot in GOT:
                    put(dst, GlobalPtr(GOT[slot]))
                    continue
                if data_at(b.addr + off) != "" or kind not in ("w", "x") and mn not in LOADS:
                    raise LiftError("adrp of data, not a GOT slot")
                # A global of this TU, read where it is (no GOT): the load below.
                b = GlobalPtr(b.addr + off - BASE, hidden=True)
                off = 0
            if isinstance(b, GlobalPtr) and off != 0:
                raise LiftError("global at an offset")
            if mn in LOADS:
                w, signed = LOADS[mn]
                t = int_type(w, signed)
            elif kind == "s":
                t = "f32"
            elif kind == "d":
                t = "f64"
            else:
                t = int_type(8 if kind == "x" else 4)
            ld = Load(b, off, t)  # b before the load: `ldr x0, [x0, #8]` overwrites it
            put(dst, ld)
            out.loads[ld] += 1
            out.load_seq.setdefault(ld, set()).add(out.stores_done)
        elif mn in ("str", "stur") or mn in STORES:
            src, mem = ops
            loc = local(mem)
            base, off = (None, 0) if loc else _mem(mem)
            kind = _reg(src)[0]
            if mn in STORES:
                t = int_type(STORES[mn])
            elif kind == "s":
                t = "f32"
            elif kind == "d":
                t = "f64"
            else:
                t = int_type(8 if kind == "x" else 4)
            b = loc[0] if loc else get(f"x{base}")
            if isinstance(b, Page) and data_at(b.addr + off) == "":
                b, off = GlobalPtr(b.addr + off - BASE, hidden=True), 0  # a global of this TU
            if isinstance(b, Page) or (isinstance(b, GlobalPtr) and off != 0):
                raise LiftError("store to data at an offset")
            out.stores.append((b, off, t, get(src)))
            out.store_seq.append(out.stores_done)
            out.stores_done += 1
        elif mn in ("ldp", "stp"):
            # A pair: two loads or stores of adjacent fields (base + immediate only:
            # writeback and sp, a frame, are refused by _mem).
            r1, r2, mem = ops
            base, off = _mem(mem)
            kind = _reg(r1)[0]
            if kind not in ("w", "x"):
                raise LiftError(f"{mn} of {kind} registers")
            w = 8 if kind == "x" else 4
            t = int_type(w)
            b = get(f"x{base}")
            if isinstance(b, (Page, GlobalPtr)):
                raise LiftError(f"{mn} of a global")
            if mn == "ldp":
                first, second = Load(b, off, t), Load(b, off + w, t)
                out.loads[first] += 1
                out.loads[second] += 1
                out.load_seq.setdefault(first, set()).add(out.stores_done)
                out.load_seq.setdefault(second, set()).add(out.stores_done)
                out.pairs = True
                put(r1, first)
                put(r2, second)
            else:
                out.stores.append((b, off, t, get(r1)))
                out.stores.append((b, off + w, t, get(r2)))
                out.store_seq += [out.stores_done, out.stores_done]
                out.stores_done += 1
        elif mn == "mov":
            dst, src = ops
            if src.startswith("#"):
                put(dst, Const(_imm(src) & ((1 << (8 * width_of(dst))) - 1), width_of(dst)))
            else:
                v = get(src)
                put(dst, v)
                if isinstance(v, Arg) and not v.fp and _reg(dst)[0] == "w" and _reg(src)[0] == "w":
                    narrow.add(_reg(dst)[1])  # `mov w2, w3`: a 32-bit argument passed on
        elif mn in ("movz", "movk"):
            # A wide constant, 16 bits at a time: movk keeps the others.
            dst, imm, *shift = ops
            sh = int(shift[0].split("#")[1], 0) if shift else 0
            w = width_of(dst)
            part = _imm(imm) << sh
            if mn == "movk":
                old = get(dst)
                if not isinstance(old, Const):
                    raise LiftError("movk of a computed value")
                part |= old.value & ~(0xFFFF << sh)
            put(dst, Const(part & ((1 << (8 * w)) - 1), w))
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
            if mn == "add" and isinstance(av, Page) and isinstance(bv, Const) and w == 8:
                put(dst, DataAddr(av.addr + bv.value))
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
            a, b, *ext = [o.strip() for o in ops]
            w = width_of(a)
            bv = Const(_imm(b), w) if b.startswith("#") else get(b)
            if ext:
                # `cmp w8, w1, uxtb`: an argument of 8 or 16 bits, which the caller
                # needn't have extended (the AAPCS64 leaves the upper bits unspecified)
                if ext not in (["uxtb"], ["uxth"]) or not isinstance(bv, Arg) or bv.fp:
                    raise LiftError(f"{mn} with an extended operand")
                bv = Op("&", bv, Const(0xFF if ext == ["uxtb"] else 0xFFFF, 4), 4)
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

    if framed != bool(inner):
        raise LiftError("a frame without a call" if framed else "bl without a frame")
    if tail_br or noreturn:
        out.noreturn = noreturn
        return out  # a virtual tail call (br) or abort(), the function's last statement: no return
    if out.vcall is not None:
        if out.guard is not None and out.zero_else:
            raise LiftError("cbz: returns something")
        if out.calls:
            raise LiftError("virtual tail call after a call")
        return out
    if out.calls:
        if tail is not None:
            # The last call, after the epilogue: a void function's last statement.
            if any(("f", i) in since for i in range(8)):
                raise LiftError("floating-point call argument")
            n = max((i + 1 for i in range(8) if ("x", i) in since), default=0)
            if any(("x", i) not in regs for i in range(n)):
                raise LiftError("call argument the previous call left")
            out.calls.append(Call(tail, tuple(regs[("x", i)] for i in range(n)), out.stores_done))
            out.stores_done += 1
            return out
        # After a call, x0 is what the function returns only if it wrote it since.
        written = since
    if tail is not None:
        if any(("f", i) in written for i in range(8)):
            raise LiftError("floating-point tail-call argument")
        n = max((i + 1 for i in range(8) if ("x", i) in written), default=0)
        n = max(n, len(TAIL_TYPES.get(tail, ())))  # the registers it passes on, as other callers set them
        out.tail, out.args = tail, [regs[("x", i)] for i in range(n)]
        out.narrow = {i for i in narrow if i < n}
        return out
    # The result: whatever the function left in w0/x0 or s0, if it wrote it.
    if ("x", 0) in written and ("f", 0) in written:
        raise LiftError("writes both x0 and s0")
    if ("x", 0) in written:
        out.ret = regs[("x", 0)]
    elif ("f", 0) in written:
        out.ret = regs[("f", 0)]
    if out.guard is not None and out.ret is not None and not out.zero_else:
        # The other path returns x0 as it was at the branch: 0 if cbz tested it.
        if out.more_guards or out.guard_kind != "cbz" or _reg(insns[k[0]][1][0])[1] != 0:
            raise LiftError("cbz: the other path returns something")
        out.zero_else = True
    if out.zero_else and (out.ret is None or ("f", 0) in written):
        raise LiftError("cbz: returns 0 on one path only")
    return out


_CALLEE_SAVED = {f"x{i}" for i in range(19, 31)}


def virtual_target(v: object) -> VTarget | None:
    """A virtual function loaded from an object's vptr: `ldr x8, [obj] ; ldr x8,
    [x8, #slot]`."""
    if isinstance(v, Load) and v.type == "u64" and isinstance(v.base, Load) and v.base.offset == 0 and \
            v.base.type == "u64" and v.offset % 8 == 0 and isinstance(v.base.base, (Arg, Load)) and \
            not (isinstance(v.base.base, Arg) and v.base.base.fp):
        return VTarget(v.base.base, v.offset)
    return None


def _is_frame(mn: str, ops: list[str]) -> bool:
    """A prologue or epilogue instruction: the frame record (x29, x30) and the
    callee-saved registers saved to or restored from the stack, `mov x29, sp`,
    `add x29, sp, #N`. Nothing else may use sp."""
    o = [x.strip() for x in ops]
    if mn in ("stp", "ldp") and len(o) >= 3 and o[2].startswith("[sp"):
        return o[0] in _CALLEE_SAVED and o[1] in _CALLEE_SAVED
    if mn in ("str", "ldr") and len(o) >= 2 and o[1].startswith("[sp"):
        return o[0] in _CALLEE_SAVED
    if mn in ("sub", "add") and o[:2] == ["sp", "sp"]:
        return True  # the frame's locals
    return (mn == "mov" and o == ["x29", "sp"]) or (mn == "add" and o[:2] == ["x29", "sp"])


def _mentions(e: object, x: object) -> bool:
    """Whether expression (or tuple of them) e uses x."""
    if e == x:
        return True
    if isinstance(e, tuple):
        return any(_mentions(y, x) for y in e)
    if isinstance(e, (Load, AddrOf)):
        return _mentions(e.base, x)
    if isinstance(e, Op):
        return _mentions(e.a, x) or _mentions(e.b, x)
    if isinstance(e, Cmp):
        return _mentions(e.a, x) or _mentions(e.b, x)
    if isinstance(e, Select):
        return _mentions(e.cond, x) or _mentions(e.a, x) or _mentions(e.b, x)
    return False


def _value_loads(e: object) -> list:
    """The loads whose value expression e uses (not the ones it only dereferences)."""
    if isinstance(e, Load):
        return [e]
    if isinstance(e, tuple):
        return [x for y in e for x in _value_loads(y)]
    if isinstance(e, (Op, Cmp)):
        return _value_loads(e.a) + _value_loads(e.b)
    if isinstance(e, Select):
        return _value_loads(e.cond) + _value_loads(e.a) + _value_loads(e.b)
    return []


def _may_alias(a: tuple, b: tuple) -> bool:
    """Whether two accesses (base, offset, type) may overlap: with
    -fno-strict-aliasing any two different pointers may, the same one only
    where the ranges meet."""
    if a[0] != b[0]:
        return True
    wa, wb = WIDTH.get(a[2], 8), WIDTH.get(b[2], 8)
    return a[1] < b[1] + wb and b[1] < a[1] + wa


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
    vslots: dict[int, tuple] = field(default_factory=dict)  # vtable offset -> (return type, parameter types)


class Emitter:
    """Renders a Lifted function as C++ with placeholder structs."""

    def __init__(self, addr: int, lifted: Lifted):
        self.short = f"{addr & 0xFFFFFFFFF:x}" if addr < BASE else f"{addr - BASE:x}"
        self.lifted = lifted
        self.structs: dict[object, StructDef] = {}
        self.arg_types: dict[int, str] = {}   # x0..x7
        self.globals: dict[int, str] = {}     # a global (relative address) -> its type
        self.fp_types: dict[int, str] = {}    # s0..s7 / d0..d7
        self.forward: set[str] = set()        # structs a known callee's parameters name
        self.locals: dict[object, str] = {}   # pointers held in a local (choose_locals)
        self.tables: set[int] = set()         # data a returned `adrp ; add` points at (absolute)
        self.hidden: set[int] = set()         # globals of this TU (relative)
        self.protos: set[str] = set()         # the callees' declarations (render_call)
        self.heads: list[StructDef] = []       # copy_head's struct
        self.statics: set[int] = set()        # static objects of this TU written through (absolute)
        self.ns_forward: set[str] = set()     # types of an import's namespace (render_call)
        self.stack: dict[int, str] = {}       # locals on the stack: offset from x29 -> type
        self.stack_addr: set[int] = set()     # ... and the ones whose address is taken
        self.passed: set[Arg] = set()         # arguments passed on to a call
        self.call_types: dict[int, str] = {}  # call index -> the type of the result it returns

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
        elif isinstance(base, DataAddr) and data_at(base.addr) == "":
            # a static object of this TU (adrp + add): `extern Unk_<addr>_Data Unk_<addr>`, hidden
            name = f"Unk_{base.addr - BASE:x}_Data"
            self.statics.add(base.addr)
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

    def stored_type(self, base: object, off: int) -> str:
        """The type of the field (or global) a store writes."""
        if isinstance(base, GlobalPtr):
            return self.globals[base.addr]
        if isinstance(base, LocalAddr):
            return self.stack[base.off]
        return self.structs[base].fields[off]

    def set_type(self, base: object, off: int, t: str) -> None:
        if isinstance(base, GlobalPtr):
            self.globals[base.addr] = t
        elif isinstance(base, LocalAddr):
            self.stack[base.off] = t
        else:
            self.structs[base].fields[off] = t

    def field_expr(self, load_base: object, offset: int, t: str) -> str:
        if isinstance(load_base, LocalAddr):  # a local on the stack, read or written whole
            if offset != 0:
                raise LiftError("a local's field")
            old = self.stack.get(load_base.off)
            if old is not None and old != t:
                raise LiftError("a local read as two types")
            self.stack[load_base.off] = t
            return f"l{-load_base.off:x}"
        if isinstance(load_base, GlobalPtr) and load_base.hidden:
            self.hidden.add(load_base.addr)
        if isinstance(load_base, GlobalPtr):   # the global itself (offset 0): `extern <t> Unk_<addr>;`
            old = self.globals.get(load_base.addr, t)
            if old != t and {old, t} != {"u8", "bool"}:
                raise LiftError(f"global is {old} and {t}")
            self.globals[load_base.addr] = "bool" if "bool" in (old, t) else t
            return f"Unk_{load_base.addr:x}"
        s = self.struct_for(load_base)
        self.set_field(s, offset, t)
        if isinstance(load_base, DataAddr):
            return f"Unk_{load_base.addr - BASE:x}.field_{offset:x}"
        return f"{self.ptr(load_base)}->field_{offset:x}"

    def choose_locals(self) -> list[str]:
        """Locals for the pointers the function loads once and stores through,
        when a statement after a store uses them again: with
        -fno-strict-aliasing a store may change what `self->field_N` reads, so
        the source that loaded it once held it in a local. Returns their
        declarations (render() first learns which loads are pointers)."""
        lf = self.lifted
        stmts: list[tuple[bool, object]] = [(True, (b, v)) for b, _, _, v in lf.stores[:lf.guard_stores]]
        if lf.guard is not None:
            stmts.append((False, lf.guard[0]))
        stmts += [(True, (b, v)) for b, _, _, v in lf.stores[lf.guard_stores:]]
        stmts.append((False, lf.ret if lf.tail is None else tuple(lf.args)))
        decls = []
        self.locals = {}
        for b in sorted({b for b, _, _, _ in lf.stores if isinstance(b, Load)}, key=repr):
            if lf.loads.get(b) != 1 or b not in self.structs:
                continue
            uses = [i for i, (_, st) in enumerate(stmts) if _mentions(st, b)]
            # reloaded: a use after a store that comes after the first use
            if not any(stmts[k][0] for j in uses for k in range(uses[0], j)):
                continue
            t = f"{self.struct_for(b).name}*"
            decls.append(f"    {t} p{len(decls)} = {self.field_expr(b.base, b.offset, t)};")
            self.locals[b] = f"p{len(decls) - 1}"
        return decls

    def ptr(self, base: object) -> str:
        if base in self.locals:
            return self.locals[base]
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
        if isinstance(e, (AddrOf, LocalAddr)):
            return "ptr"
        if isinstance(e, DataAddr):
            return "data"
        if isinstance(e, CallRet):
            return self.call_types.get(e.index, "u64")
        if isinstance(e, Arg):
            if e.fp:
                return self.fp_types.get(e.index, "f32")
            return self.arg_types.get(e.index, "u32")
        raise LiftError("type")

    def expr(self, e: object, want: str | None = None) -> str:
        if e in self.locals:
            return self.locals[e]
        if isinstance(e, LocalAddr):  # a local's address, passed on
            self.stack_addr.add(e.off)
            return f"&l{-e.off:x}"
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
            if e.op == "&" and isinstance(e.b, Const) and e.b.value in (0xFF, 0xFFFF) and isinstance(e.a, Arg):
                # An argument of 8 or 16 bits, extended where it's compared (lift's cmp)
                t = "u8" if e.b.value == 0xFF else "u16"
                if self.arg_types.setdefault(e.a.index, t) == t:
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
        if s.isidentifier():  # an argument the Op only masks (bool, u8, u16)
            return s
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
    def copy(self) -> tuple[str, str] | None:
        """A function that copies x0's first N bytes to x1 with ldp: the copy of a
        struct, which clang does like a memcpy (ldp/ldr, then stp/str in its own
        order). Field by field it would copy with ldr/str in source order."""
        lf = self.lifted
        if not lf.pairs or lf.ret is not None or lf.guard is not None or lf.tail is not None or not lf.stores:
            return None
        fields = {}
        for base, off, t, value in lf.stores:
            if base != Arg(1) or value != Load(Arg(0), off, t) or off in fields:
                return None
            fields[off] = t
        pos = 0
        for off in sorted(fields):
            if off != pos:
                return None
            pos += WIDTH[fields[off]]
        if pos <= 8:
            return None
        s = StructDef(f"Unk_{self.short}", dict(fields))
        func = f"void Unk_{self.short}_set(const {s.name}* self, {s.name}* value) {{\n    *value = *self;\n}}\n"
        return render_struct(s), func

    def stack_decls(self) -> list[str]:
        """The locals on the stack, uninitialized (what's stored to them is a
        statement): typed by how they're read or written, or, when only their
        address is passed on, by their size, up to the next local or the frame
        record."""
        offs = sorted(set(self.stack) | self.stack_addr)
        out = []
        for i, off in enumerate(offs):
            t = self.stack.get(off)
            if t is None:
                size = (offs[i + 1] if i + 1 < len(offs) else 0) - off
                t = {1: "u8", 2: "u16", 4: "u32", 8: "u64"}.get(size)
                if t is None:
                    raise LiftError("a local of another size")
            out.append(f"    {t} l{-off:x};")
        return out

    def copy_head(self) -> int | None:
        """The number of stores at the start that copy x0's first 16 bytes or
        more to x1 with ldp (a struct copy, see copy()) when the function does
        more after it: a callable's fields copied, then a reference added. The
        two structs then start with one struct of those fields, assigned
        whole. None if it doesn't start like that."""
        lf = self.lifted
        if not lf.pairs:
            return None
        # the fields read again (a reference the copy then adds) aren't the head's
        later = [lf.ret, lf.vcall[0] if lf.vcall else None, lf.guard[0] if lf.guard else None]
        later += [c.args for c in lf.calls] + [c.target.obj for c in lf.calls if isinstance(c.target, VTarget)]
        reread = {ld.offset for ld in _value_loads(tuple(later)) if ld.base == Arg(0)}
        k, fields = 0, {}
        for b, o, t, v in lf.stores:
            if b != Arg(1) or v != Load(Arg(0), o, t) or o in reread:
                break
            fields[o] = t
            k += 1
        pos = 0
        for o in sorted(fields):  # in memcpy order: contiguous from 0
            if o != pos:
                return None
            pos += WIDTH[fields[o]]
        if pos < 16 or k == len(lf.stores) and not lf.calls and lf.ret is None and lf.vcall is None:
            return None
        if lf.guard is not None and lf.guard_stores < k:
            return None
        rest = [v for _, _, _, v in lf.stores[k:]]
        if any(ld.base == Arg(0) and ld.offset < pos for ld in _value_loads(tuple(rest + later))):
            return None  # the head's fields read again
        name = f"Unk_{self.short}_head"
        head = StructDef(name, dict(fields))
        NESTED[name] = pos
        self.heads = [head]
        for a in (Arg(0), Arg(1)):
            st = self.struct_for(a)
            if any(o < pos for o in st.fields if o != 0) or st.fields.get(0, name) != name:
                raise LiftError("copied head's fields used otherwise")
            st.fields[0] = name
        return k

    def value_locals(self) -> dict[int, list[tuple[Load, str]]]:
        """Loads to hold in a local: their value is used after a store or a call
        that may overwrite what they read (a move: `v = self->f; self->f = 0;
        value->f = v;`), so the source read them first. -> {the store count
        when it was loaded: [(load, local name)]}: declared before the first
        store or call after it."""
        lf = self.lifted
        uses = [(lf.store_seq[i], v) for i, (_, _, _, v) in enumerate(lf.stores)]
        uses += [(c.seq, c.args) for c in lf.calls]
        # a virtual call's object, loaded before an earlier call: held too
        uses += [(c.seq, c.target.obj) for c in lf.calls if isinstance(c.target, VTarget)]
        if lf.ret is not None:
            uses.append((lf.stores_done, lf.ret))
        if lf.guard is not None:
            uses.append((lf.guard_seq, lf.guard[0]))
        if lf.vcall is not None:
            uses.append((lf.stores_done, lf.vcall[0]))
        need: dict[Load, int] = {}
        for seq, v in uses:
            for ld in _value_loads(v):
                epochs = lf.load_seq.get(ld)
                if not epochs or (ld.base == Arg(0) and ld.offset < getattr(self, "head_size", 0)):
                    continue
                epoch = min(epochs)
                between = [(b, o, t) for (b, o, t, _), q in zip(lf.stores, lf.store_seq) if epoch <= q < seq]
                if not any(_may_alias((ld.base, ld.offset, ld.type), x) for x in between) and \
                        not any(epoch <= c.seq < seq for c in lf.calls):
                    continue
                if len(epochs) > 1:
                    raise LiftError("read before a store, then reloaded")
                need[ld] = epoch
        out: dict[int, list[tuple[Load, str]]] = {}
        order = {ld: i for i, ld in enumerate(lf.loads)}  # in the order the function loads them
        for n, (ld, epoch) in enumerate(sorted(need.items(), key=lambda x: (x[1], order.get(x[0], 0)))):
            out.setdefault(epoch, []).append((ld, f"v{n}"))
        return out

    def render_call(self, j: int) -> str:
        """The statement for the j-th call: `Unk_<T>(args...);`, declared like a
        tail call's target (render_tail), returning u32 or u64 as the function
        reads w0 or x0 after it, into a local (`r<j>`). A target already written
        (KNOWN) is called by its own prototype."""
        lf = self.lifted
        c = lf.calls[j]
        width = lf.ret_width.get(j)
        if isinstance(c.target, VTarget):
            return self.render_virtual(j, c, width)
        if isinstance(c.target, RefTarget):
            obj = c.target.obj
            if width or c.args:
                raise LiftError("reference call with arguments or a result")
            if isinstance(obj, Arg):
                self.arg_types[obj.index] = "Unk_239a418*"
                self.passed.add(obj)
                p = self.arg_name(obj.index)
            elif isinstance(obj, Load):
                p = self.locals.get(obj) or self.field_expr(obj.base, obj.offset, "Unk_239a418*")
                if self.stored_type(obj.base, obj.offset) != "Unk_239a418*":
                    raise LiftError("interface of a field of another type")
            else:
                raise LiftError("interface of a computed pointer")
            return f"    static_cast<Unk_239a458*>({p})->{REF_SLOTS[c.target.slot]}();"
        if c.target in KNOWN:
            ret, callee, ptypes = KNOWN[c.target]
            if len(ptypes) != len(c.args) or (width and ret == "void"):
                raise LiftError("callee: other parameters")
            args = self.known_args(c.args, ptypes)
            self.protos.add(f"{ret} {callee}({', '.join(ptypes)});")
            rt = ret
        elif c.target in IMPORTS:
            # An SDK import: declared by its own (simple) name, in its namespaces.
            dm = demangle_simple(IMPORTS[c.target])
            if dm is None or dm[2] is None or len(dm[2]) != len(c.args):
                raise LiftError("callee: an import")
            spaces, fname, ptypes = dm
            args = []
            for e, pt in zip(c.args, ptypes):
                base_t = pt.removeprefix("const ")[:-1] if pt.endswith("*") else None
                named = base_t not in (None, "void", "char")
                q = ("const " if pt.startswith("const ") else "") + "::".join([*spaces, base_t]) + "*" \
                    if named else pt
                if named:
                    # a type of the callee's namespace: declared before the structs that hold one
                    fwd = f"struct {base_t};"
                    for ns in reversed(spaces):
                        fwd = f"namespace {ns} {{ {fwd} }}"
                    self.ns_forward.add(fwd)
                if isinstance(e, Arg) and not e.fp:
                    if self.arg_types.setdefault(e.index, q.removeprefix("const ")) != q.removeprefix("const "):
                        raise LiftError("callee: an argument of another type")
                    self.passed.add(e)
                    args.append(self.arg_name(e.index))
                elif pt.endswith("*") and (self.is_pointer(e) or self.type_of(e) == "ptr"):
                    if named and isinstance(e, Load) and not isinstance(e.base, GlobalPtr):
                        # a field passed as the namespace's type: the field is a pointer of that type
                        args.append(self.field_expr(e.base, e.offset, q.removeprefix("const ")))
                    elif named and isinstance(e, AddrOf):
                        # an object of that type inside the struct, at that offset
                        args.append(f"reinterpret_cast<{q}>({self.expr(e)})")
                    elif named:
                        raise LiftError("callee: a pointer of another type")
                    else:
                        args.append(self.expr(e))
                elif not pt.endswith("*") and not self.is_pointer(e) and self.type_of(e) in CALL_CODES:
                    args.append(self.expr(e, pt if pt in CALL_CODES else None))
                else:
                    raise LiftError("callee: an argument of another type")
            # one declaration for every caller in a file: what the result is read as is the caller's
            rt = {4: "u32", 8: "u64"}.get(width, "void")
            decl = f"u64 {fname}({', '.join(ptypes)});"
            if not spaces and fname in LIBC_DECL:
                if width and fname in ("memset", "memcpy", "memmove", "strncpy", "strcpy"):
                    raise LiftError("callee: a C library pointer result")
                decl, rt = LIBC_DECL[fname], ("s32" if width == 4 else "u64") if width else "void"
            for ns in reversed(spaces):
                decl = f"namespace {ns} {{ {decl} }}"
            self.protos.add(decl)
            callee = "::".join([*spaces, fname])
        elif c.target in NAMED:
            # Named already, as another caller's placeholder: call it with the
            # parameters its name spells.
            ptypes = placeholder_params(NAMED[c.target], c.target)
            if ptypes is None or len(ptypes) != len(c.args):
                raise LiftError("callee: named")
            args = []
            for e, pt in zip(c.args, ptypes):
                if isinstance(e, Arg) and not e.fp:
                    self.arg_types.setdefault(e.index, pt)
                    self.passed.add(e)
                    args.append(self.arg_name(e.index))
                elif pt == "void*" and (self.is_pointer(e) or self.type_of(e) == "ptr"):
                    args.append(self.expr(e))
                elif pt != "void*" and not self.is_pointer(e) and self.type_of(e) in CALL_CODES:
                    args.append(self.expr(e, pt))
                else:
                    raise LiftError("callee: an argument of another type")
            callee = callee_name(c.target, ptypes)[0]
            rt = {4: "u32", 8: "u64"}.get(width, "void")
            self.protos.add(f"{rt} {callee}({', '.join(ptypes)});")
        else:
            args, types = [], []
            want = CALL_PARAMS.get(c.target, ())
            want = want if len(want) == len(c.args) else ()
            for pos, e in enumerate(c.args):
                pt = want[pos] if want else None
                if isinstance(e, Arg) and not e.fp:
                    t = self.arg_types.setdefault(e.index, pt or ("void*" if e.index == 0 else "u64"))
                    self.passed.add(e)
                    args.append(self.arg_name(e.index))
                    types.append("void*" if t.endswith("*") else t)
                elif pt == "void*" and isinstance(e, Load) and e.type in ("u64", "s64") and                         not isinstance(e.base, GlobalPtr) and not self.is_pointer(e):
                    # what the callee's other callers pass as a pointer: the field holds one
                    args.append(self.field_expr(e.base, e.offset, "void*"))
                    types.append("void*")
                elif self.is_pointer(e) or self.type_of(e) == "ptr":
                    args.append(self.expr(e))
                    types.append("void*")
                else:
                    t = self.type_of(e)
                    if t not in CALL_CODES:
                        raise LiftError(f"call argument of type {t}")
                    args.append(self.expr(e, t))
                    types.append(t)
            callee, _ = callee_name(c.target, types)
            rt = {4: "u32", 8: "u64"}.get(width, "void")
            self.protos.add(f"{rt} {callee}({', '.join(types)});")
        call = f"{callee}({', '.join(args)})"
        if not width:
            return f"    {call};"
        if rt not in CALL_CODES:
            raise LiftError(f"call result of type {rt}")
        self.call_types[j] = rt
        self.locals[CallRet(j)] = f"r{j}"
        return f"    {rt} r{j} = {call};"

    def render_virtual(self, j: int, c: Call, width: int | None) -> str:
        """`obj->vf<N>(args...)`: obj's struct becomes polymorphic, with virtual
        functions declared up to the slot (none defined, so no vtable is
        emitted here) and its fields after the vptr."""
        obj, slot = c.target.obj, c.target.slot
        s = self.struct_for(obj)
        args, types = [], []
        for e in c.args:
            if isinstance(e, Arg) and not e.fp:
                t = self.arg_types.setdefault(e.index, "u64")
                self.passed.add(e)
                args.append(self.arg_name(e.index))
                types.append("void*" if t.endswith("*") else t)
            elif self.is_pointer(e) or self.type_of(e) == "ptr":
                args.append(self.expr(e))
                types.append("void*")
            else:
                t = self.type_of(e)
                if t not in CALL_CODES:
                    raise LiftError(f"call argument of type {t}")
                args.append(self.expr(e, t))
                types.append(t)
        rt = {4: "u32", 8: "u64"}.get(width, "void")
        old = s.vslots.get(slot)
        if old is not None and old != (rt, tuple(types)):
            raise LiftError("virtual function called two ways")
        s.vslots[slot] = (rt, tuple(types))
        if isinstance(obj, Arg):
            self.passed.add(obj)  # its virtual functions aren't const
        call = f"{self.ptr(obj)}->vf{slot // 8}({', '.join(args)})"
        if not width:
            return f"    {call};"
        self.call_types[j] = rt
        self.locals[CallRet(j)] = f"r{j}"
        return f"    {rt} r{j} = {call};"

    def known_args(self, args: tuple, ptypes: list[str]) -> list[str]:
        """The arguments of a call to a KNOWN function, each of its parameter's type."""
        out = []
        for e, pt in zip(args, ptypes):
            if pt.endswith("*"):
                if pt != "void*":
                    self.forward.add(pt.removeprefix("const ")[:-1])
                if isinstance(e, Arg) and not e.fp:
                    if self.arg_types.setdefault(e.index, pt) != pt:
                        raise LiftError("callee: a pointer of another type")
                    self.passed.add(e)
                    out.append(self.arg_name(e.index))
                elif isinstance(e, Load) and e.type in ("u64", "s64") and not isinstance(e.base, GlobalPtr):
                    out.append(self.field_expr(e.base, e.offset, pt.removeprefix("const ")))
                else:
                    raise LiftError("callee: a pointer argument")
            elif pt in CALL_CODES and not (isinstance(e, Arg) and e.fp) and not self.is_pointer(e):
                if isinstance(e, Arg):
                    if self.arg_types.setdefault(e.index, pt) != pt:
                        raise LiftError("callee: an argument of another type")
                    out.append(self.arg_name(e.index))
                else:
                    out.append(self.expr(e, pt))
            else:
                raise LiftError(f"callee: parameter {pt}")
        return out

    def render(self) -> tuple[str, str]:
        """(struct definitions, function definition)."""
        lf = self.lifted
        copied = self.copy()
        if copied is not None:
            return copied
        decls = self.choose_locals()
        head = self.copy_head()
        self.head_size = NESTED[self.heads[0].name] if head is not None else 0
        held = self.value_locals()
        body: list[str] = []
        stored = {base for base, _, _, _ in lf.stores}
        if lf.vcall is not None and isinstance(lf.vcall[0], Load):
            self.field_expr(lf.vcall[0].base, lf.vcall[0].offset, "Unk_239a418*")
        self.before = None
        self.early: list[tuple[int, str]] = []

        def known(ld: Load) -> str | None:
            if isinstance(ld.base, GlobalPtr):
                return self.globals.get(ld.base.addr)
            return self.structs[ld.base].fields.get(ld.offset) if ld.base in self.structs else None

        def hold(seq: int) -> None:
            # Locals are read before the guard (value_locals), so they go before it.
            for epoch in sorted(e for e in held if e <= seq):
                for ld, name in held.pop(epoch):
                    rhs = self.field_expr(ld.base, ld.offset, known(ld) or ld.type)
                    body.append(f"    {self.stored_type(ld.base, ld.offset)} {name} = {rhs};")
                    self.locals[ld] = name

        events = sorted([(q, 0, i) for i, q in enumerate(lf.store_seq)] +
                        [(c.seq, 1, j) for j, c in enumerate(lf.calls)])
        more = list(lf.more_guards)

        def guard_at(seq: int) -> None:
            if lf.guard is not None and self.before is None and seq > lf.guard_seq:
                hold(lf.guard_seq)
                self.before = len(body)
            while more and seq > more[0][2]:
                v, cbz, gseq = more.pop(0)
                hold(gseq)
                test = self.guard_cond(v, cbz, False)
                self.early.append((len(body), test))
                body.append(None)  # the return, once the function's type is known

        for seq, kind, i in events:
            guard_at(seq)
            hold(seq)
            if kind == 1:
                body.append(self.render_call(i))
                continue
            if head is not None and i < head:
                if i == 0:
                    body.append("    value->field_0 = self->field_0;")
                continue
            base, off, t, value = lf.stores[i]
            if isinstance(value, AddrOf):
                raise LiftError("stores an address")
            lhs = self.field_expr(base, off, t)
            if _is_bool_arg(value) and t == "u8":
                self.set_type(base, off, "bool")
                self.arg_types.setdefault(value.a.index, "bool")
            ft = self.stored_type(base, off)
            vt = known(value) if isinstance(value, Load) else None
            if vt is not None and vt.endswith("*") and ft in ("u64", "s64"):
                self.set_type(base, off, vt)  # a pointer copied: the field it goes to holds one too
                ft = vt
            rhs = self.expr(value, None if ft.endswith("*") else ft)
            if isinstance(value, Const) and value.value == 0 and ft.endswith("*"):
                rhs = "nullptr"
            body.append(f"    {lhs} = {rhs};")
        guard_at(lf.stores_done + 1)
        hold(lf.stores_done)
        if self.before is None:
            self.before = len(body)
        ret_type = "void"
        if lf.vcall is not None:
            obj, slot = lf.vcall
            if isinstance(obj, Arg):
                self.arg_types[obj.index] = "Unk_239a418*"
                p = self.locals.get(obj, self.arg_name(obj.index))
            else:
                p = self.locals.get(obj) or self.field_expr(obj.base, obj.offset, "Unk_239a418*")
                if self.stored_type(obj.base, obj.offset) != "Unk_239a418*":
                    raise LiftError("interface of a field of another type")
            body.append(f"    static_cast<Unk_239a458*>({p})->{REF_SLOTS[slot]}();")
        if lf.ret is not None:
            if isinstance(lf.ret, Arg) and lf.ret.index == 0 and not lf.ret.fp:
                raise LiftError("returns self")
            rt = "global" if isinstance(lf.ret, GlobalPtr) else self.type_of(lf.ret)
            if rt == "global":  # a global's address, from the GOT (or adrp + add for one of this TU)
                if lf.ret.hidden:
                    raise LiftError("address of a global of the TU")
                t = self.globals.setdefault(lf.ret.addr, "u8")
                rt, rhs = f"{t}*", f"&Unk_{lf.ret.addr:x}"
            elif rt == "data":  # a string literal, or a table the TU defines
                text = data_at(lf.ret.addr)
                if text is None:
                    raise LiftError("address of code or a vtable")
                if text:
                    rt, rhs = "const char*", f'"{text}"'
                else:
                    self.tables.add(lf.ret.addr)
                    rt, rhs = "const u8*", f"Unk_{lf.ret.addr - BASE:x}"
            elif rt == "ptr":  # the address of a field
                rt = "u8*" if lf.ret.base in stored or not isinstance(lf.ret.base, Arg) else "const u8*"
                rhs = self.expr(lf.ret)
            else:
                rhs = self.expr(lf.ret, rt)
            if isinstance(lf.ret, Load) and lf.ret.type in ("u64", "s64"):
                ft = self.stored_type(lf.ret.base, lf.ret.offset)
                if ft.endswith("*"):
                    rt = ft
            ret_type = rt
            body.append(f"    return {rhs};")
        for i, test in self.early:
            if ret_type != "void" and not lf.zero_else:
                raise LiftError("cbz: the other path returns something")
            other = f" {_const(lf.else_value, ret_type)}" if ret_type != "void" else ""
            body[i] = f"    if ({test}) return{other};"
        body = self.stack_decls() + decls + self.guarded(body, ret_type)
        params = []
        for i in range(max(self.arg_types, default=-1) + 1):
            t = self.arg_types.get(i)
            if t is None:
                params.append("void* /*unused*/" if i == 0 else "u32 /*unused*/")
                continue
            if t.endswith("*") and Arg(i) not in stored and Arg(i) not in self.passed:
                t = "const " + t
            params.append(f"{t} {self.arg_name(i)}")
        # Floating-point arguments take s0.. in order whatever the integer ones do.
        for i in range(max(self.fp_types, default=-1) + 1):
            t = self.fp_types.get(i)
            params.append(f"{t} {self.fp_name(i)}" if t else "f32 /*unused*/")
        name = self.function_name(ret_type)
        func = f"{ret_type} {name}({', '.join(params)}) {{\n" + "".join(line + "\n" for line in body) + "}\n"
        return self.render_structs(), func

    def render_known_tail(self, known: tuple[str, str, list[str]]) -> tuple[str, str]:
        """render_tail() of a call to a function already written (KNOWN): its
        own prototype, each argument of its parameter's type (a pointer
        passed on, field or argument, becomes that pointer)."""
        lf = self.lifted
        ret, callee, ptypes = known
        if len(ptypes) != len(lf.args):
            raise LiftError("callee: other parameters")
        decls = self.choose_locals()
        body: list[str] = []
        for base, off, t, value in lf.stores:
            if isinstance(value, AddrOf):
                raise LiftError("stores an address")
            lhs = self.field_expr(base, off, t)
            ft = self.stored_type(base, off)
            rhs = self.expr(value, None if ft.endswith("*") else ft)
            if isinstance(value, Const) and value.value == 0 and ft.endswith("*"):
                rhs = "nullptr"
            body.append(f"    {lhs} = {rhs};")
        args = []
        for e, pt in zip(lf.args, ptypes):
            if pt.endswith("*"):
                if pt != "void*":
                    self.forward.add(pt.removeprefix("const ")[:-1])
                if isinstance(e, Arg) and not e.fp:
                    if self.arg_types.setdefault(e.index, pt) != pt:
                        raise LiftError("callee: a pointer of another type")
                    args.append(self.arg_name(e.index))
                elif isinstance(e, Load) and e.type in ("u64", "s64") and not isinstance(e.base, GlobalPtr):
                    args.append(self.field_expr(e.base, e.offset, pt.removeprefix("const ")))
                else:
                    raise LiftError("callee: a pointer argument")
            elif pt in CALL_CODES and not (isinstance(e, Arg) and e.fp) and not self.is_pointer(e):
                if isinstance(e, Arg):
                    if self.arg_types.setdefault(e.index, pt) != pt:
                        raise LiftError("callee: an argument of another type")
                    args.append(self.arg_name(e.index))
                else:
                    args.append(self.expr(e, pt))
            else:
                raise LiftError(f"callee: parameter {pt}")
        body.append(f"    {callee}({', '.join(args)});")
        body = decls + self.guarded(body, "void")
        params = []
        for i in range(max(self.arg_types, default=-1) + 1):
            t = self.arg_types.get(i)
            if t is None:
                params.append("void* /*unused*/" if i == 0 else "u64 /*unused*/")
                continue
            if t.endswith("*") and not t.startswith("const ") and t != "void*" \
                    and Arg(i) not in {b for b, _, _, _ in lf.stores} and Arg(i) not in lf.args:
                t = "const " + t
            params.append(f"{t} {self.arg_name(i)}")
        self.callee = (lf.tail, tuple(ptypes))
        proto = f"{ret} {callee}({', '.join(ptypes)});\n"
        func = f"void Unk_{self.short}_call({', '.join(params)}) {{\n" + "".join(x + "\n" for x in body) + "}\n"
        structs = self.render_structs()
        return (structs + "\n" if structs else "") + proto, func

    def render_tail(self) -> tuple[str, str]:
        """render() of a function that ends in a tail call: its stores, then
        `Unk_<T>(args...);`, T declared with `void*` for pointers, so that its
        name doesn't depend on this function's placeholder structs."""
        lf = self.lifted
        if lf.more_guards:
            raise LiftError("cbz: more than one branch before a tail call")
        if lf.tail in KNOWN:
            return self.render_known_tail(KNOWN[lf.tail])
        decls = self.choose_locals()
        body: list[str] = []
        for base, off, t, value in lf.stores:
            if isinstance(value, AddrOf):
                raise LiftError("stores an address")
            lhs = self.field_expr(base, off, t)
            ft = self.stored_type(base, off)
            rhs = self.expr(value, None if ft.endswith("*") else ft)
            if isinstance(value, Const) and value.value == 0 and ft.endswith("*"):
                rhs = "nullptr"
            body.append(f"    {lhs} = {rhs};")
        args, types = [], []
        for e in lf.args:
            if isinstance(e, Arg) and not e.fp:
                pos = len(args)
                t = self.arg_types.get(e.index)
                if t is None:
                    padded = TAIL_TYPES.get(lf.tail, ())
                    t = padded[pos] if pos < len(padded) else "u32" if pos in lf.narrow else \
                        "void*" if e.index == 0 else "u64"
                    self.arg_types[e.index] = t
                if pos in lf.narrow and (t.endswith("*") or WIDTH.get(t, 8) > 4):
                    raise LiftError("tail-call argument narrowed from 64 bits")
                args.append(self.arg_name(e.index))
                types.append("void*" if t.endswith("*") else t)
            elif self.is_pointer(e) or self.type_of(e) == "ptr":
                args.append(self.expr(e))
                types.append("void*")
            else:
                t = self.type_of(e)
                if t not in CALL_CODES:
                    raise LiftError(f"tail-call argument of type {t}")
                args.append(self.expr(e, t))
                types.append(t)
        callee, _ = callee_name(lf.tail, types)
        body.append(f"    {callee}({', '.join(args)});")
        body = decls + self.guarded(body, "void")
        params = []
        for i in range(max(self.arg_types, default=-1) + 1):
            t = self.arg_types.get(i)
            if t is None:
                params.append("void* /*unused*/" if i == 0 else "u64 /*unused*/")
                continue
            # const when only read, unless it's passed on (to a void* parameter)
            if t.endswith("*") and t != "void*" and Arg(i) not in {b for b, _, _, _ in lf.stores} \
                    and Arg(i) not in lf.args:
                t = "const " + t
            params.append(f"{t} {self.arg_name(i)}")
        self.callee = (lf.tail, tuple(types))
        proto = f"void {callee}({', '.join(types)});\n"
        func = f"void Unk_{self.short}_call({', '.join(params)}) {{\n" + "".join(x + "\n" for x in body) + "}\n"
        structs = self.render_structs()
        return (structs + "\n" if structs else "") + proto, func

    def guard_cond(self, v: object, nonzero: bool, runs: bool) -> str:
        """The condition under which the rest of the function runs (runs) or
        the function returns (not runs), for a guard (value, nonzero)."""
        if isinstance(v, Cmp):
            return self.cond(v if runs == nonzero else Cmp(COND_INV[v.cond], v.a, v.b, v.test))
        w = 8 if self.is_pointer(v) or WIDTH.get(self.type_of(v), 8) == 8 else 4
        return self.cond(Cmp("ne" if runs == nonzero else "eq", v, Const(0, w)))

    def guarded(self, body: list[str], ret_type: str) -> list[str]:
        """body (the statements, and the return last if it returns) under lf.guard."""
        lf = self.lifted
        if lf.guard is None:
            return body
        v, nonzero = lf.guard
        n = getattr(self, "before", None)
        n = lf.guard_stores if n is None else n
        before, body = body[:n], body[n:]  # done either way
        if lf.zero_else:
            test = self.guard_cond(v, nonzero, False)
            other = _const(lf.else_value, ret_type)
            return [*before, f"    if ({test}) {{", f"        return {other};", "    }", *body]
        test = self.guard_cond(v, nonzero, True)
        return [*before, f"    if ({test}) {{", *("    " + line for line in body), "    }"]

    def function_name(self, ret_type: str) -> str:
        lf = self.lifted
        if lf.vcall is not None or lf.calls:
            verb = "call"
        elif lf.stores and lf.ret is None:
            verb = "set"
        elif ret_type == "bool":
            verb = "check"
        elif lf.ret is not None and not lf.stores:
            verb = "get"
        else:
            verb = "update"
        return f"Unk_{self.short}_{verb}"

    def render_structs(self) -> str:
        out = sorted(self.ns_forward)
        out += [f"struct {n};" for n in sorted(self.forward)]  # a known callee's, defined with it
        # another TU defines them, or this one (hidden: reached with adrp, not the GOT)
        out += [f"extern {t} Unk_{a:x}" + (' __attribute__((visibility("hidden")));' if a in self.hidden else ";")
                for a, t in sorted(self.globals.items())]
        # Defined in this TU (adrp ; add, not the GOT), with contents not written here.
        out += [f'extern const u8 Unk_{a - BASE:x}[] __attribute__((visibility("hidden")));'
                for a in sorted(self.tables)]
        # Children before parents, so a parent's pointer member names a complete type.
        order = sorted(self.structs.values(), key=lambda s: -s.name.count("_"))
        for s in [*self.heads, *order]:  # a copied head first: the others hold it
            out.append(render_struct(s))
        out += [f'extern Unk_{a - BASE:x}_Data Unk_{a - BASE:x} __attribute__((visibility("hidden")));'
                for a in sorted(self.statics)]
        out += sorted(self.protos)
        return "\n".join(out)


def render_struct(s: StructDef) -> str:
    lines = [f"struct {s.name} {{"]
    pos = 0
    if s.vslots:
        # Polymorphic: the vptr at 0, a virtual function per slot up to the last one called.
        if 0 in s.fields:
            raise LiftError("vptr read as a field")
        for slot in range(0, max(s.vslots) + 8, 8):
            rt, types = s.vslots.get(slot, ("void", ()))
            lines.append(f"    virtual {rt} vf{slot // 8}({', '.join(types)});")
        pos = 8
    asserts = []
    for off in sorted(s.fields):
        t = s.fields[off]
        w = 8 if t.endswith("*") else WIDTH[t] if t in WIDTH else min(8, NESTED[t])
        if off % w:
            raise LiftError(f"misaligned field {off:#x}")
        if off < pos:
            raise LiftError(f"overlapping field {off:#x}")
        if off > pos:
            lines.append(f"    u8 _{pos:x}[0x{off - pos:x}];")
        lines.append(f"    {t} field_{off:x};")
        asserts.append(f"PKMN_OFFSET_ASSERT({s.name}, field_{off:x}, 0x{off:x});")
        pos = off + (NESTED[t] if t in NESTED else w)
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
        return generate_one(addr, code)
    except LiftError:
        two = two_paths(addr, code) or decision_tree(addr, code)
        if two is None:
            raise
        return two


def _body(func: str) -> tuple[str, list[str]]:
    lines = func.rstrip("\n").split("\n")
    return lines[0], lines[1:-1]


_LOCAL = re.compile(r"^ +\S+\*? [vp]\d+ = ")


def two_paths(addr: int, code: bytes) -> tuple[str, str] | None:
    """A function with one forward branch whose two paths each end in their own
    return (no join): `if (<the fallthrough's condition>) { ...; return; }`, then
    the branch target's path. Each path is lifted on its own (the code before
    the branch with each), the statements before the branch must come out the
    same in both, and so must the signature. None if it isn't that shape."""
    try:
        insns = disassemble(code, addr) if len(code) >= 4 and len(code) % 4 == 0 else []
        ks = [i for i, (mn, _) in enumerate(insns) if mn in GUARDS]
        if len(ks) != 1:
            return None
        k = ks[0]
        to = (_imm(insns[k][1][-1]) - addr) // 4
        ends = ("ret", "b", "br")
        if not k + 1 < to < len(insns) or insns[-1][0] not in ends:
            return None
        if any(m in GUARDS or m.startswith("b.") for m, _ in insns[to:]):
            return None
        # Or the branch skips into code the other path falls into (`if (c) { A } B`):
        # the fallthrough runs A and B, the branch B alone.
        join = insns[to - 1][0] not in ends
        fall = lift(b"", addr, path=insns if join else insns[:to], split=k)
        taken = lift(b"", addr, path=insns[:k] + insns[to:])
        emitters = []
        for _rnd in range(3):  # the first two learn the fields and arguments, the last renders them all
            shared = emitters[0] if emitters else None
            emitters = []
            for lf in (taken, fall):
                e = Emitter(addr, lf)
                if shared is not None:
                    e.structs, e.arg_types, e.fp_types = shared.structs, shared.arg_types, shared.fp_types
                    e.globals, e.tables, e.hidden = shared.globals, shared.tables, shared.hidden
                    e.statics = shared.statics
                elif emitters:
                    e.structs, e.arg_types, e.fp_types = emitters[0].structs, emitters[0].arg_types, \
                        emitters[0].fp_types
                    e.globals, e.tables, e.hidden = emitters[0].globals, emitters[0].tables, emitters[0].hidden
                    e.statics = emitters[0].statics
                emitters.append(e)
            cond = emitters[1].guard_cond(fall.split[0], fall.split[1], True)
            out = [(Emitter.render_tail if lf.tail is not None else Emitter.render)(e)
                   for e, lf in zip(emitters, (taken, fall))]
        (s_t, f_t), (s_f, f_f) = out
        sig_t, body_t = _body(f_t)
        sig_f, body_f = _body(f_f)
        params_t, params_f = sig_t.split("(", 1)[1], sig_f.split("(", 1)[1]
        if params_t.replace("const ", "") != params_f.replace("const ", ""):
            raise LiftError("two paths: other parameters")
        # const only where neither path writes through it
        params = params_t if params_t.count("const ") <= params_f.count("const ") else params_f
        rt_t, rt_f = sig_t.split(" Unk_")[0], sig_f.split(" Unk_")[0]
        if rt_t != rt_f:
            # One path returns a constant: the function returns the other one's type.
            if "void" in (rt_t, rt_f) or rt_t not in CALL_CODES or rt_f not in CALL_CODES:
                raise LiftError("two paths: other return types")
            rt_t = rt_f if isinstance(taken.ret, Const) else rt_t
        sig_t = f"{rt_t} Unk_{sig_t.split(' Unk_', 1)[1].split('(', 1)[0]}({params}"
        if any(_LOCAL.match(x) for x in body_t + body_f):
            raise LiftError("two paths: locals")
        n = sum(1 for q in fall.store_seq if q < fall.split_seq) + sum(1 for c in fall.calls if c.seq < fall.split_seq)
        if body_t[:n] != body_f[:n] or len(body_t) <= n or len(body_f) <= n:
            raise LiftError("two paths: other statements before the branch")
        if join:
            # B, the branch's path after the prefix, must end the fallthrough's too.
            tail_b = body_t[n:]
            if len(body_f) - n <= len(tail_b) or body_f[len(body_f) - len(tail_b):] != tail_b:
                raise LiftError("two paths: the joined code differs")
            inner = ["    " + x for x in body_f[n:len(body_f) - len(tail_b)]]
            body = body_t[:n] + [f"    if ({cond}) {{"] + inner + ["    }"] + tail_b
            structs = s_t.rstrip("\n").split("\n") if s_t else []
            structs += [x for x in (s_f.rstrip("\n").split("\n") if s_f else []) if x not in structs and x]
            return "\n".join(structs) + ("\n" if structs else ""), sig_t + "\n" + "\n".join(body) + "\n}\n"
        inner = ["    " + x for x in body_f[n:]]
        if not body_f[-1].strip().startswith("return"):
            inner.append("        return;")
        body = body_t[:n] + [f"    if ({cond}) {{"] + inner + ["    }"] + body_t[n:]
        structs = s_t.rstrip("\n").split("\n") if s_t else []
        structs += [x for x in (s_f.rstrip("\n").split("\n") if s_f else []) if x not in structs and x]
        return "\n".join(structs) + ("\n" if structs else ""), sig_t + "\n" + "\n".join(body) + "\n}\n"
    except (LiftError, ValueError, KeyError, IndexError, StopIteration):
        return None


def _paths(insns: list, addr: int, limit: int = 16) -> list[tuple[list, dict]]:
    """Every path through a function whose branches all go forward: (its
    instructions, {index of a branch in them: taken}). An unconditional `b`
    inside the function is followed; one out of it is a tail call."""
    n = len(insns)
    out: list[tuple[list, dict]] = []

    def walk(i: int, acc: list, splits: dict) -> None:
        if len(out) > limit:
            raise LiftError("too many paths")
        while i < n:
            mn, ops = insns[i]
            if mn in GUARDS:
                t = (_imm(ops[-1]) - addr) // 4
                if not i < t < n:
                    raise LiftError("a branch back or out")
                walk(i + 1, acc + [insns[i]], {**splits, len(acc): False})
                walk(t, acc + [insns[i]], {**splits, len(acc): True})
                return
            if mn == "b":
                t = (_imm(ops[0]) - addr) // 4
                if i < t < n:
                    i = t
                    continue
                if 0 <= t <= i:
                    raise LiftError("a loop")
            acc = acc + [insns[i]]
            if mn in ("ret", "br", "b") or (mn == "bl" and IMPORTS.get(_imm(ops[0])) in NORETURN):
                out.append((acc, splits))
                return
            i += 1
        raise LiftError("falls off the end")

    walk(0, [], {})
    return out


def decision_tree(addr: int, code: bytes) -> tuple[str, str] | None:
    """A function of several forward branches and no joins, as nested `if`s:
    each path lifted on its own (two_paths, generalized), the code between two
    branches the same on every path through it, every path ending in its own
    return. None if it isn't that shape."""
    try:
        insns = disassemble(code, addr) if len(code) >= 4 and len(code) % 4 == 0 else []
        paths = _paths(insns, addr)
        if len(paths) < 2:
            return None
        lifted = [lift(b"", addr, path=acc, splits=sp) for acc, sp in paths]
        shared = None
        for _rnd in range(3):  # the first two learn the fields and arguments, the last renders them all
            ems, conds, out = [], [], []
            for lf in lifted:
                e = Emitter(addr, lf)
                base = shared or (ems[0] if ems else None)
                if base is not None:
                    e.structs, e.arg_types, e.fp_types = base.structs, base.arg_types, base.fp_types
                    e.globals, e.tables, e.hidden = base.globals, base.tables, base.hidden
                    e.statics = base.statics
                ems.append(e)
                conds.append([e.guard_cond(v[0], v[1], True) if v is not None else None for v, _ in lf.splits])
                out.append((Emitter.render_tail if lf.tail is not None else Emitter.render)(e))
            shared = ems[0]
        sigs, bodies = zip(*(_body(f) for _, f in out))
        params = [x.split("(", 1)[1] for x in sigs]
        if len({x.replace("const ", "") for x in params}) != 1:
            raise LiftError("paths: other parameters")
        param = min(params, key=lambda x: x.count("const "))
        rts = [x.split(" Unk_")[0] for x, lf in zip(sigs, lifted) if not lf.noreturn] or ["void"]
        if len(set(rts)) > 1:
            if "void" in rts or any(r not in CALL_CODES for r in rts):
                raise LiftError("paths: other return types")
            live = [(x.split(" Unk_")[0], lf) for x, lf in zip(sigs, lifted) if not lf.noreturn]
            rts = [r for r, lf in live if not isinstance(lf.ret, Const)] or rts
        if any(_LOCAL.match(x) for b in bodies for x in b):
            raise LiftError("paths: locals")
        # where each branch is in each path's lines
        pos = [[sum(1 for q in lf.store_seq if q < seq) + sum(1 for c in lf.calls if c.seq < seq)
                for _, seq in lf.splits] for lf in lifted]

        def build(group: list[int], level: int, starts: dict[int, int]) -> list[str]:
            ended = [i for i in group if len(lifted[i].splits) <= level]
            if ended:
                if len(group) != 1:
                    raise LiftError("paths: one ends where another branches")
                return list(bodies[group[0]][starts[group[0]]:])
            segs = [bodies[i][starts[i]:pos[i][level]] for i in group]
            if any(x != segs[0] for x in segs):
                raise LiftError("paths: other code between two branches")
            fall = [i for i in group if lifted[i].splits[level][0] is not None]
            taken = [i for i in group if lifted[i].splits[level][0] is None]
            if not fall or not taken:
                raise LiftError("paths: a branch without two sides")
            inner = build(fall, level + 1, {i: pos[i][level] for i in fall})
            if not inner or not (inner[-1].strip().startswith("return") or inner[-1].strip() == "abort();"):
                inner = inner + ["    return;"]
            rest = build(taken, level + 1, {i: pos[i][level] for i in taken})
            return segs[0] + [f"    if ({conds[fall[0]][level]}) {{"] + ["    " + x for x in inner] + ["    }"] + rest

        body = build(list(range(len(lifted))), 0, {i: 0 for i in range(len(lifted))})
        sig = f"{rts[0]} Unk_{sigs[0].split(' Unk_', 1)[1].split('(', 1)[0]}({param}"
        structs: list[str] = []
        for st, _ in out:
            structs += [x for x in (st.rstrip("\n").split("\n") if st else []) if x and x not in structs]
        return "\n".join(structs) + ("\n" if structs else ""), sig + "\n" + "\n".join(body) + "\n}\n"
    except (LiftError, ValueError, KeyError, IndexError, StopIteration):
        return None


def generate_one(addr: int, code: bytes) -> tuple[str, str]:
    try:
        lifted = lift(code, addr)
        first = Emitter(addr, lifted)
        render = Emitter.render_tail if lifted.tail is not None else Emitter.render
        render(first)  # learns which fields and arguments are pointers
        second = Emitter(addr, lifted)
        second.structs, second.arg_types, second.fp_types = first.structs, first.arg_types, first.fp_types
        second.globals = first.globals
        second.tables = first.tables
        second.hidden = first.hidden
        second.statics = first.statics
        second.call_types = first.call_types
        return render(second)
    except ValueError as e:  # an operand list of another shape (shifted or extended registers ...)
        raise LiftError(f"operands ({e})") from None


# --------------------------------------------------------------------------- files
def render_file(entries: list[tuple[int, str, str]]) -> str:
    """One TU of leaf functions: (addr, structs, function) in address order."""
    out = ["// Scope: common",
           "// Directly called leaf functions between two static initialisers (one or more",
           "// TUs). Placeholder types: rename and move once the owning classes are known.",
           "#include <types.h>", ""]
    if any("Unk_239a458" in func for _, _, func in entries):
        out[-1:] = ["", REF_HEADER, ""]
    for addr, structs, func in sorted(entries):
        if structs.strip():
            out.append(structs.rstrip("\n"))
            out.append("")
        out.append(f"// 0x{addr:x}")
        out.append(func.rstrip("\n"))
        out.append("")
    return "\n".join(out)


# --------------------------------------------------------------------------- CLI
REACH = ("call", "none", "data")


def candidates(args) -> list[tuple[int, bytes]]:
    """Common, unnamed, U functions in the area, reached the ways `--reach` lists
    (funcs.reference_kind; default only through B/BL), that end in ret with no
    other branch.

    `none` adds the functions whose address is only taken in code (the copy
    operations of type-erased callables, which their caller puts in a table on
    its stack) or that nothing references; `data` the ones in a function-pointer
    table that isn't a vtable (no-op callbacks in static records). A function
    in a vtable slot is never a candidate: vtables.py writes those, as members."""
    import funcs as F
    from common import AreaMap, area_names, in_area, load_module, nso_path, read_areas_csv, read_functions_csv
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = load_module("sword")
    img = mod["image"]
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), img, mod["text_end"])
    in_data = {v for v in dyn.slots.values() if isinstance(v, int)}
    GOT.update({slot: v for slot, v in dyn.slots.items() if isinstance(v, int)})
    called = F.branch_targets(img, 0, mod["text_end"] & ~3)
    areas = read_areas_csv()
    groups = args.area or ["game", "gflib3", "gflnet3", "startup"]
    for g in groups:
        if g not in area_names(areas):
            raise SystemExit(f"no area {g!r}")
    amap = AreaMap(areas, "sword")
    reach = set(getattr(args, "reach", None) or ["call"])
    global DATA_AT
    import segments
    import vtables as V
    nso = Nso(nso_path("sword").read_bytes())
    vts, _ = V.find_vtables(img, dyn.slots, {s for s, _ in mod["functions"]}, nso.data.mem_off, nso.data.end)
    vt_ranges = sorted((v.start, v.addr + 8 * len(v.slots)) for v in vts)
    ro_lo, ro_hi = mod["rodata"]

    def _data_at(a: int) -> str | None:
        r = a - BASE
        if not (ro_lo <= r < ro_hi or nso.data.mem_off <= r < nso.data.end + nso.bss_size):
            return None
        if any(lo <= r < hi for lo, hi in vt_ranges):
            return None
        text = segments.c_string(img, r, ro_lo, ro_hi)
        return text.replace("\\", "\\\\").replace('"', '\\"') if text is not None else ""

    DATA_AT = _data_at
    in_vtable = {t for v in vts for t in v.slots if isinstance(t, int)}
    out = []
    rows = read_functions_csv()
    NAMED.update({f.sword + BASE: f.name for f in rows if f.name and f.sword is not None})
    IMPORTS.update({pc + BASE: name for pc, name in dyn.plt.items()})
    for f in rows:
        if f.status != "U" or f.scope != "common" or f.name or f.sword is None:
            continue
        size = f.size("sword")
        if size > args.max:
            continue
        a = f.sword
        if not any(in_area(amap.area_of(a), g) for g in groups):
            continue
        if F.reference_kind(a, called, in_data) not in reach or a in in_vtable:
            continue
        out.append((a + BASE, img[a:a + size]))
    return out


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for name in ("scan", "write"):
        p = sub.add_parser(name)
        p.add_argument("--area", action="append", help="area or group (default: game, gflib3, gflnet3, startup)")
        p.add_argument("--max", type=int, default=32, help="largest function, in bytes (default 32)")
        p.add_argument("--reach", type=lambda x: x.split(","), default=["call"],
                       help=f"comma-separated ways the function is reached, of {','.join(REACH)} "
                            "(funcs.py patterns; default call). Vtable slots are always left to vtables.py")
        if name == "write":
            p.add_argument("--out", type=Path, default=ROOT / "src" / "unsorted" / "leaf")
            p.add_argument("--only", type=Path, help="file of addresses (one per line) to write; default all")
    p = sub.add_parser("members", help="library classes' small virtual functions, as members (cmd_members)")
    p.add_argument("--area", action="append", required=True, help="library area(s): middleware, yebis, wwise, ...")
    p.add_argument("--max", type=int, default=128)
    p.add_argument("--all-kinds", action="store_true", help="every slot function the lifter takes, not only the small kinds")
    p.add_argument("--out", type=Path, required=True)
    p.add_argument("--only", type=Path, help="file of addresses (one per line) to write; default all")
    p = sub.add_parser("member-names", help="Name,Sword,Shield of the members `members` wrote, from a build")
    p.add_argument("--out", type=Path, required=True)
    p.add_argument("--dir", type=Path, required=True)
    p.add_argument("--build", type=Path, default=ROOT / "build" / "sword")
    p = sub.add_parser("names", help="mangled names of the leaf functions in a build, as Name,Sword,Shield")
    p.add_argument("--out", type=Path, required=True)
    p.add_argument("--dir", type=Path, default=ROOT / "src" / "unsorted" / "leaf", help="the sources' directory")
    p.add_argument("--build", type=Path, default=ROOT / "build" / "sword")
    args = ap.parse_args(argv)
    if args.cmd == "names":
        return cmd_names(args)
    if args.cmd == "members":
        return cmd_members(args)
    if args.cmd == "member-names":
        return cmd_member_names(args)

    KNOWN.update(known_prototypes(ROOT / "src" / "unsorted" / "leaf"))
    cands = candidates(args)
    lifted: dict[int, tuple[str, str]] = {}
    why: Counter = Counter()
    for addr, code in cands:
        try:
            lifted[addr] = generate(addr, code)
        except LiftError as e:
            why[str(e).split(" ")[0]] += 1
    TAIL_TYPES.update(unify_arity(lifted))
    for addr, code in cands:  # again, the callers that pass more on now
        if addr in lifted and (m := PROTO.search(lifted[addr][0])) and int(m.group(2), 16) + BASE in TAIL_TYPES:
            try:
                lifted[addr] = generate(addr, code)
            except LiftError:
                del lifted[addr]
    lifted = callable_tails(lifted, why)
    CALL_PARAMS.update(unify_calls(lifted))
    if CALL_PARAMS:  # again, with the callees' parameters as most of their callers pass them
        for addr, code in cands:
            if addr in lifted and "_call(" in lifted[addr][1]:
                try:
                    lifted[addr] = generate(addr, code)
                except LiftError:
                    del lifted[addr]
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


PROTO = re.compile(r"^void (Unk_([0-9a-f]+))\((.*)\);$", re.M)


def unify_calls(lifted: dict[int, tuple[str, str]]) -> dict[int, tuple]:
    """The parameter types to declare each called placeholder with: by
    position, `void*` where any caller passes a pointer, otherwise the type most
    callers pass. Callers that disagree in number are left alone."""
    seen: dict[int, list[tuple]] = {}
    for structs, _ in lifted.values():
        for m in DECL.finditer(structs):
            params = tuple(x.strip() for x in m.group(3).split(",") if x.strip())
            seen.setdefault(int(m.group(2)[4:], 16) + BASE, []).append(params)
    out = {}
    for target, lists in seen.items():
        if len({len(x) for x in lists}) != 1 or len(lists) < 2:
            continue
        out[target] = tuple("void*" if "void*" in col else Counter(col).most_common(1)[0][0]
                            for col in zip(*lists))
    return out


def unify_arity(lifted: dict[int, tuple[str, str]]) -> dict[int, list[str]]:
    """Tail-call targets whose callers pass fewer arguments than the longest
    one, and otherwise the same types: target (absolute) -> the longest's
    types. A caller passes the registers it doesn't write on as it got them,
    so it can say so (TAIL_TYPES)."""
    sigs: dict[int, set[str]] = {}
    for structs, func in lifted.values():
        m = PROTO.search(structs)
        if m and "_call(" in func:
            sigs.setdefault(int(m.group(2), 16), set()).add(m.group(3))
    out = {}
    for t, ss in sigs.items():
        lists = sorted((x.split(", ") if x else [] for x in ss), key=len)
        longest = lists[-1]
        if len(lists) > 1 and all(lst == longest[:len(lst)] for lst in lists) and len(lists[0]) < len(longest):
            out[t + BASE] = longest
    return out


def callable_tails(lifted: dict[int, tuple[str, str]], why: Counter) -> dict[int, tuple[str, str]]:
    """The lifted functions, without the tail calls whose target can't be the
    placeholder `void Unk_<T>(...)`: one in no table (a virtual function is
    called by its class's name), unnamed or already named that, not lifted
    itself, and called with the same parameter types by every caller."""
    from common import load_module, nso_path, read_functions_csv
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = load_module("sword")
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), mod["image"], mod["text_end"])
    in_data = {v for v in dyn.slots.values() if isinstance(v, int)}
    GOT.update({slot: v for slot, v in dyn.slots.items() if isinstance(v, int)})
    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    sigs: dict[int, set[str]] = {}
    target: dict[int, int] = {}
    for a, (structs, func) in lifted.items():
        m = PROTO.search(structs)
        if m and "_call(" in func:
            t = int(m.group(2), 16)
            target[a] = t
            sigs.setdefault(t, set()).add(m.group(3))
    out = {}
    for a, v in lifted.items():
        t = target.get(a)
        if t is None:
            out[a] = v
            continue
        r = rows.get(t)
        types = next(iter(sigs[t])).split(", ") if next(iter(sigs[t])) else []
        name = callee_name(t + BASE, types)[1]
        if len(sigs[t]) > 1:
            why["callee"] += 1          # called with different types: its signature isn't known
        elif r is None or r.shield is None or t in in_data or t + BASE in lifted or (r.name and r.name != name):
            why["callee"] += 1
        else:
            out[a] = v
    return out


_DEF = re.compile(r"^(.+?) (Unk_[0-9a-f]+_(?:set|get|check|update|call)\w*)\((.*)\) \{$", re.M)
_STRUCT_PTR = re.compile(r"^(const )?(Unk_[0-9a-f_]+)\*$")


def mangle(name: str, ptypes: list[str]) -> str | None:
    """The mangled name of `name(ptypes)`, for leafgen's own parameter types
    (None for what it doesn't spell: a struct twice needs a substitution)."""
    codes = []
    seen = set()
    for t in ptypes:
        if t in CALL_CODES or t in ("f32", "f64"):
            codes.append(CALL_CODES.get(t) or {"f32": "f", "f64": "d"}[t])
            continue
        m = _STRUCT_PTR.match(t)
        if m is None or m.group(2) in seen:
            return None
        seen.add(m.group(2))
        codes.append(("PK" if m.group(1) else "P") + f"{len(m.group(2))}{m.group(2)}")
    return f"_Z{len(name)}{name}" + ("".join(codes) or "v")


def param_types(params: str) -> list[str]:
    """`const Unk_1* self, u32 value` -> ["const Unk_1*", "u32"]."""
    out = []
    for p in (x.strip() for x in params.split(",") if x.strip()):
        out.append(p.split(" /*")[0] if p.endswith("*/") else p.rsplit(" ", 1)[0])
    return out


def known_prototypes(leaf_dir: Path) -> dict[int, tuple[str, str, list[str]]]:
    """The leaf functions already matched (O), by address: their prototypes
    from the sources, where the name they mangle to is the one in
    functions.csv."""
    from common import read_functions_csv

    rows = {f.sword + BASE: f for f in read_functions_csv() if f.sword is not None and f.status == "O"}
    out = {}
    for path in sorted(leaf_dir.glob("*.cpp")):
        for addr, _, func in parse_file(path.read_text(encoding="utf-8")):
            m = _DEF.match(func)
            r = rows.get(addr)
            if m is None or r is None:
                continue
            ret, name, ptypes = m.group(1), m.group(2), param_types(m.group(3))
            if mangle(name, ptypes) == r.name:
                out[addr] = (ret, name, ptypes)
    return out


NAME = re.compile(r"Unk_([0-9a-f]+)_(?:set|get|check|update|call)")
CALLEE = re.compile(r"_Z\d+Unk_([0-9a-f]+)\w+")  # a tail call's target, undefined in the objects


# --------------------------------------------------------------------------- library classes' members
def _type_name(mangled: str) -> list[str] | None:
    """The names of a typeinfo's class, `N4PPFX16SiYebisAllocatorE` -> [PPFX,
    SiYebisAllocator] (namespaces or enclosing classes: both mangle alike);
    None for templates and anything else that isn't plain source names."""
    rest = mangled[1:-1] if mangled.startswith("N") and mangled.endswith("E") else mangled
    parts = []
    while rest:
        m = re.match(r"\d+", rest)
        if not m:
            return None
        n = int(m.group())
        rest = rest[len(m.group()):]
        name, rest = rest[:n], rest[n:]
        if not re.fullmatch(r"[A-Za-z_]\w*", name):
            return None
        parts.append(name)
    return parts or None


def _member_prefix(parts: list[str], member: str) -> str:
    return "_ZN" + "".join(f"{len(x)}{x}" for x in parts + [member]) + "E"


_SCALARS = {"bool", "char", "signed char", "unsigned char", "short", "unsigned short", "int", "unsigned int",
            "long", "unsigned long", "char const*", "void*"}


def template_class(mangled: str, demangled: str) -> tuple[list[str], list[str]] | None:
    """A template class's RTTI name, `N2nn3nex20PseudoGlobalVariableIbEE` with
    its demangling `nn::nex::PseudoGlobalVariable<bool>`: (the names, the
    last with its arguments, for the definitions; the declarations before its
    class: the classes its arguments name, the primary template). Only type
    arguments (classes, scalars), one level of template, None otherwise."""
    m = re.fullmatch(r"((?:\w+::)*)(\w+)<(.*)>", demangled)
    if not m or "<" in m.group(3) or "(" in m.group(3) or not mangled.startswith("N"):
        return None
    spaces = [x for x in m.group(1).split("::") if x]
    args = [a.strip() for a in m.group(3).split(",")]
    decls = []
    for a in args:
        if a in _SCALARS:
            continue
        if not re.fullmatch(r"(?:[A-Za-z_]\w*::)*[A-Za-z_]\w*", a):  # a class (not a value)
            return None
        *ns, name = a.split("::")
        d = f"class {name};"
        for n in reversed(ns):
            d = f"namespace {n} {{ {d} }}"
        decls.append(d)
    params = ", ".join(f"class T{i}" for i in range(len(args)))
    head = f"template <{params}> class {m.group(2)};"
    for n in reversed(spaces):
        head = f"namespace {n} {{ {head} }}"
    decls.append(head)
    return spaces + [f"{m.group(2)}<{', '.join(args)}>"], decls


_SIG = re.compile(r"^(.+?) (Unk_[0-9a-f]+_\w+)\((.*)\) \{$")


def as_member(func: str, cls: list[str], member: str) -> tuple[str, str] | None:
    """A lifted function's text as a member of class cls: (its declaration in
    the class, its definition). Its first parameter (self) is `this`, cast to
    the placeholder struct the body reads through; non-const, so the member's
    mangled name doesn't depend on whether the body writes through it."""
    lines = func.rstrip("\n").split("\n")
    m = _SIG.match(lines[0])
    if not m:
        return None
    ret, params = m.group(1), [x.strip() for x in m.group(3).split(",") if x.strip()]
    body = lines[1:-1]
    if params:
        first = params.pop(0)
        if first.endswith(" self"):
            t = first[:-len(" self")]
            if t.endswith("*") and t.removeprefix("const ").startswith("Unk_"):
                body = [f"    {t} self = reinterpret_cast<{t}>(this);"] + body
            elif t != "void*":
                return None  # self as an integer: not a member's this
        elif not first.startswith("void* /*unused*/"):
            return None
    decl = f"    {ret} {member}({', '.join(params)});"
    qual = "::".join(cls + [member])
    definition = f"{ret} {qual}({', '.join(params)}) {{\n" + "".join(x + "\n" for x in body) + "}\n"
    return decl, definition


def render_class_file(cls: list[str], members: list[tuple[int, str, str, str]], before: list[str] = (),
                      rtti: str = "") -> str:
    """One library class's members: (addr, structs, declaration, definition).
    A template class (template_class) is an explicit specialization, after
    the declarations `before`."""
    out = ["// Scope: common",
           "// Small virtual functions of a library class (tools/leafgen.py members): placeholder",
           "// member names vf<slot>, placeholder structs. The class's name is its RTTI's.",
           "#include <types.h>", ""]
    if any(REF_HEADER.split('"')[1] in st or "Unk_239a458" in d for _, st, _, d in members):
        out[-1:] = ["", REF_HEADER, ""]
    if rtti:
        out[3:3] = [f"// RTTI: {rtti}"]
    for _, structs, _, _ in members:
        if structs.strip():
            out += [structs.rstrip("\n"), ""]
    if before:
        out += [*before, ""]
    special = "template <> " if "<" in cls[-1] else ""
    head = f"{special}class {cls[-1]} {{\npublic:\n" + "\n".join(d for _, _, d, _ in members) + "\n};"
    for ns in reversed(cls[:-1]):
        head = f"namespace {ns} {{\n{head}\n}}  // namespace {ns}"
    out += [head, ""]
    for addr, _, _, definition in sorted(members):
        out += [f"// 0x{addr:x}", definition]
    return "\n".join(out).rstrip("\n") + "\n"


def cmd_members(args) -> int:
    """Library classes' small virtual functions (slot kinds constant, ret,
    zero, null, small, trap), lifted like the leaf functions and written as
    members `vf<slot>` of their class: its RTTI name (YEBIS, NEX/Pia, SDK
    classes) or, without RTTI, `Unk_<vtable>` like vtables.py's. Only the
    libraries: vtables.py writes Game Freak's classes. One file per class."""
    import vtables as V
    from common import in_area, load_module, nso_path, read_functions_csv
    from nx.module import DynInfo
    from nx.nso import Nso
    from segments import c_string

    candidates(argparse.Namespace(area=["game"], max=4, reach=["call"]))  # the hooks (GOT, DATA_AT, ...)
    KNOWN.update(known_prototypes(ROOT / "src" / "unsorted" / "leaf"))
    m = V.load("sword")
    mod = load_module("sword")
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), m.img, mod["text_end"])
    by = {v.addr: v for v in m.vtables}
    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    only = {int(x, 16) for x in args.only.read_text().split()} if args.only else None
    classes: dict[tuple, list] = {}
    extra: dict[tuple, tuple] = {}  # class -> (declarations before it, its RTTI name)
    why: Counter = Counter()
    # placeholder classes defined anywhere else under src/ aren't ours to write
    taken = V.defined_classes(ROOT / "src", skip=args.out)
    own = V.owners(m.vtables)
    if any(in_area("game", a) or a in ("gflib3", "gflnet3", "startup") for a in args.area):
        # game code: the owners vtables.py gives (the stored vtable's, an empty D2's root)
        own = V.prefer_stored(m, own)
        own.update((d2, (r, 0)) for d2, r in V.ctor_roots(m, V.ctor_bases(m)).items())
    game = any(in_area("game", a) or a in ("gflib3", "gflnet3", "startup") for a in args.area)
    for f, (va, slot) in own.items():
        v = by.get(va)
        r = rows.get(f)
        if v is None or r is None or r.scope != "common" or (r.status != "U" and not r.name):
            continue
        if not any(in_area(V.vtable_area(m, v), a) for a in args.area) or slot < 2 or r.size("sword") > args.max:
            continue
        kind = V.slot_kind(m.pattern(f))
        small = kind in ("constant", "ret", "zero", "null", "small", "trap")
        if not small and not (args.all_kinds and kind == "other"):
            continue
        if only is not None and f + BASE not in only:
            continue
        g = by.get(v.group, v)
        before: list[str] = []
        name = None
        if g.typeinfo is not None:
            p_ = dyn.slots.get(g.typeinfo + 8)
            name = c_string(m.img, p_, 0, len(m.img)) if isinstance(p_, int) else None
            cls = _type_name(name) if name else None
            if cls is None and name:
                t = template_class(name, demangled(name))
                if t is not None:
                    cls, before = t
        elif game:
            cls = [V.class_name(v)]  # the vtable's own class, as vtables.py names it
        else:
            cls = [V.class_name(g)]
        if cls is None:
            why["class name"] += 1
            continue
        if len(cls) == 1 and cls[0] in taken:
            why["class written elsewhere"] += 1  # by vtables.py, by hand, ...
            continue
        # unnamed and undecompiled, or one of ours from an earlier run (written again with its class)
        if r.name and not r.name.startswith(_member_prefix(cls, f"vf{slot}")) or not r.name and r.status != "U":
            continue
        try:
            structs, func = generate(f + BASE, m.img[f:f + r.size("sword")])
        except LiftError as e:
            why[str(e).split(" ")[0]] += 1
            continue
        mem = as_member(func, cls, f"vf{slot}")
        if mem is None:
            why["not a member"] += 1
            continue
        classes.setdefault(tuple(cls), []).append((f + BASE, structs, *mem))
        extra[tuple(cls)] = (before, name or "")
    clang = ROOT / "toolchain" / "clang" / "bin" / ("clang++.exe" if sys.platform == "win32" else "clang++")
    kept = {}
    for cls, members in classes.items():
        seen, ok = set(), []
        for x in members:  # one member per slot (a function in two of the class's vtables)
            member = x[2].split("(", 1)[0].rsplit(" ", 1)[-1]
            if member in seen:
                continue
            seen.add(member)
            if _compiles_text(render_class_file(list(cls), [x], *extra[cls]), clang) is None:
                ok.append(x)
            else:
                why["doesn't compile"] += 1
        if ok and _compiles_text(render_class_file(list(cls), ok, *extra[cls]), clang) is not None:
            # members that compile alone but not together (overloads of one placeholder
            # callee): keep each one only if the file still compiles with it
            together = []
            for x in ok:
                if _compiles_text(render_class_file(list(cls), together + [x], *extra[cls]), clang) is None:
                    together.append(x)
                else:
                    why["doesn't compile with the others"] += 1
            ok = together
        if ok:
            kept[cls] = ok
    args.out.mkdir(parents=True, exist_ok=True)
    from common import clang_format
    written = []
    for cls, members in kept.items():
        path = args.out / (re.sub(r"\W+", "_", "_".join(cls)).strip("_") + ".cpp")
        path.write_text(render_class_file(list(cls), members, *extra[cls]), encoding="utf-8", newline="\n")
        written.append(path)
    clang_format(written)
    print(f"wrote {sum(len(x) for x in kept.values())} members of {len(kept)} classes; refused: "
          + ", ".join(f"{k} {n}" for k, n in why.most_common(8)), file=sys.stderr)
    return 0


def demangled(type_name: str) -> str:
    """A type's mangled name (as RTTI spells it) demangled, by llvm-cxxfilt."""
    import subprocess

    tool = ROOT / "toolchain" / "llvm-19" / "bin" / ("llvm-cxxfilt.exe" if sys.platform == "win32" else "llvm-cxxfilt")
    r = subprocess.run([str(tool), "_ZTS" + type_name], capture_output=True, text=True)
    return r.stdout.strip().removeprefix("typeinfo name for ")


def _compiles_text(src: str, clang: Path) -> str | None:
    import subprocess

    extra = []
    if REF_HEADER in src:
        extra = ["-D__ELF__", "-fno-exceptions", "-fno-rtti", "-I", str(ROOT / "src"),
                 "-isystem", str(ROOT / "include" / "libcxx"), "-isystem", str(ROOT / "include" / "libc"),
                 "-D_GNU_SOURCE", "-D_LIBCPP_HAS_MUSL_LIBC", "-D_LIBCPP_HAS_THREAD_API_PTHREAD"]
    r = subprocess.run([str(clang), "-fsyntax-only", "-std=c++17", "-Wall", "-Wextra", "-Wno-unused-parameter",
                        "-Werror", "--target=aarch64-none-elf", "-nostdinc++", "-I", str(ROOT / "include"),
                        *extra, "-x", "c++", "-"], input=src, capture_output=True, text=True)
    return None if r.returncode == 0 else r.stderr[:200]


def cmd_member_names(args) -> int:
    """Name,Sword,Shield of the members in --dir's class files, from the
    objects of a build: the symbol that starts with the member's own prefix
    (class, vf<slot>), whatever its parameters mangle to."""
    import elfobj
    from common import read_functions_csv

    want: dict[str, int] = {}
    for path in args.dir.glob("*.cpp"):
        text = path.read_text(encoding="utf-8")
        rtti = re.search(r"^// RTTI: (\S+)$", text, re.M)
        if rtti and rtti.group(1).startswith("N"):  # the class's own nested name, as mangled
            for m in re.finditer(r"^// 0x([0-9a-f]+)\n.*?::(vf\d+)\(", text, re.M):
                v = m.group(2)
                want["_ZN" + rtti.group(1)[1:-1] + f"{len(v)}{v}E"] = int(m.group(1), 16)
            continue
        for m in re.finditer(r"^// 0x([0-9a-f]+)\n.*? ([\w:]+)::(vf\d+)\(", text, re.M):
            want[_member_prefix(m.group(2).split("::"), m.group(3))] = int(m.group(1), 16)
    stems = {p.name for p in args.dir.glob("*.cpp")}
    found: dict[int, str] = {}
    for o in args.build.rglob("*.o*"):
        if o.name.rsplit(".", 1)[0] not in stems:
            continue
        for sym in elfobj.parse(o.read_bytes()).symbols:
            if sym.type != "STT_FUNC" or sym.shndx == "SHN_UNDEF":
                continue
            for prefix, addr in want.items():
                if sym.name.startswith(prefix):
                    found[addr] = sym.name
    rows = [f for f in read_functions_csv() if f.sword is not None and f.sword + BASE in found and not f.name]
    with open(args.out, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for f in rows:
            fh.write(f"{found[f.sword + BASE]},{f.sword_str},{f.shield_str}\n")
    print(f"{len(rows)} names to {args.out}", file=sys.stderr)
    return 0


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
            m = CALLEE.fullmatch(sym.name)
            if m and sym.shndx == "SHN_UNDEF" and not NAME.search(sym.name):
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
    extra = []
    if REF_HEADER in src:  # src/unsorted's library settings (CMakeLists.txt): libc++ for <atomic>
        extra = ["-D__ELF__", "-fno-exceptions", "-fno-rtti", "-I", str(ROOT / "src"),
                 "-isystem", str(ROOT / "include" / "libcxx"), "-isystem", str(ROOT / "include" / "libc"),
                 "-D_GNU_SOURCE", "-D_LIBCPP_HAS_MUSL_LIBC", "-D_LIBCPP_HAS_THREAD_API_PTHREAD"]
    r = subprocess.run([str(clang), "-fsyntax-only", "-std=c++17", "-Wall", "-Wextra", "-Wno-unused-parameter",
                        "-Werror", "--target=aarch64-none-elf", "-nostdinc++", "-I", str(ROOT / "include"),
                        *extra, "-x", "c++", "-"], input=src, capture_output=True, text=True)
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
    from common import clang_format

    written = []
    for s, addrs in sorted(by_seg.items()):
        entries = [(a, *lifted[a]) for a in addrs]
        old = file_for_seg.get(s)
        if old is not None:
            entries = parse_file(old.read_text(encoding="utf-8")) + entries
            old.unlink()
        entries = consistent_declarations(entries)
        first = min(a for a, _, _ in entries)
        path = out_dir / f"Unk_{first - BASE:x}.cpp"
        path.write_text(render_file(entries), encoding="utf-8", newline="\n")
        written.append(path)
    if not clang_format(written):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    print(f"wrote {len(lifted)} functions into {len(by_seg)} files", file=sys.stderr)


STRUCT_NAME = re.compile(r"\bstruct (Unk_\w+)")
STRUCT_DEF = re.compile(r"^struct (Unk_\w+) \{", re.M)
EXTERN = re.compile(r"^extern (.+?) (Unk_[0-9a-f]+)\b", re.M)
DECL = re.compile(r"^([\w*]+) (Unk_[0-9a-f]+)\((.*)\);$", re.M)


def consistent_declarations(entries: list[tuple[int, str, str]],
                            overloads: bool = True) -> list[tuple[int, str, str]]:
    """The entries whose callee declarations agree with the ones before them:
    two functions of one file that declare a callee with the same parameters
    and different return types (one reads its result, as u32 or u64, the
    other doesn't) don't compile together, nor a callee and a struct of the
    same name (`Unk_<addr>` is both a placeholder function and the struct of
    that function's first argument). The later one is dropped."""
    seen: dict[tuple[str, str], str] = {}
    structs: set[str] = set()
    funcs: set[str] = set()
    externs: dict[str, str] = {}
    defs: set[str] = set()   # structs defined (a static object's struct is named after it, not the function)
    out = []
    for e in entries:
        decls = {(m.group(2), m.group(3)): m.group(1) for m in DECL.finditer(e[1])}
        names = set(STRUCT_NAME.findall(e[1]) + STRUCT_NAME.findall(e[2]))
        called = {name for name, _ in decls}
        defined = set(STRUCT_DEF.findall(e[1]))
        ext = {m.group(2): m.group(1) for m in EXTERN.finditer(e[1])}
        if any(externs.get(k, t) != t for k, t in ext.items()):
            print(f"  dropped 0x{e[0]:x}: declares a global another function of its file declares otherwise",
                  file=sys.stderr)
            continue
        # without overloads, a second parameter list for a callee is a clash too (a call may be ambiguous)
        clash = not overloads and any(n in funcs and (n, ps) not in seen for n, ps in decls)
        if any(seen.get(k, r) != r for k, r in decls.items()) or called & (structs | names) or names & funcs \
                or defined & defs or clash:
            print(f"  dropped 0x{e[0]:x}: declares a callee another function of its file declares otherwise",
                  file=sys.stderr)
            continue
        seen.update(decls)
        structs |= names
        funcs |= called
        defs |= defined
        externs.update(ext)
        out.append(e)
    return out


def parse_file(text: str) -> list[tuple[int, str, str]]:
    """(addr, structs, function) blocks of a leaf file written by render_file (or batch 1).

    A block is the struct definitions before a `// 0x<addr>` line (none for an
    empty function), that line, and the function: up to a line that is `}`, or
    the definition line itself when it ends with `{}`."""
    lines = text.split("#include <types.h>", 1)[1].splitlines()
    while lines and (not lines[0].strip() or lines[0].startswith("#include")):
        lines.pop(0)
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
