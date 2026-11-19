#!/usr/bin/env python3
"""Write families of Pia's small functions as C++, into lib/pia/gen.

    python tools/piagen.py write --names names.csv   # then: funcs.py name --from-file names.csv
    python tools/piagen.py write --only addrs.txt    # keep only these functions (after check.py)

Pia (lib/pia/README.md) has families of small functions that are the same
code with other constants. They're virtual functions of RTTI-named classes
(`nn::pia::lan::LanNetworkFactory`...), so each is written as a member
`vf<slot>` of its class, like tools/leafgen.py members, one file per class.

The families (docs/compiler.md, "Pia 5.18.0"):

- create (15 instructions): `bl heap ; mov x1, x0 ; mov w0, #size ; bl new ;
  cbz ; bl ctor`, i.e. `return new (Unk_1652bd0()) T();`, T of that size,
  with a non-throwing `operator new(size_t, pead::Heap*)` (so the result is
  null-checked) and a placeholder heap (lib/pia/common/Unk_17162d0.h). T is
  the class whose constructor is called: its name in functions.csv, or,
  for an unnamed constructor, `Unk_<vtable>` after the one vtable group it
  refers to, as tools/vtables.py names constructors (then it's named too).
- destroy (14 instructions): `cbz x1 ; ldr x8, [x1] ; ldr x8, [x8] ; blr x8 ;
  b free`, i.e. `if (p) { p->~T(); Unk_1716390(p); }` (a virtual call of
  the complete-object destructor, slot 0). The parameter's class is a
  placeholder, `Unk_<addr>_arg1`, with a virtual destructor.

- result (21 or 22 instructions): a member that returns a fixed result,
  `return Unk_165e060Value<value>();` (lib/pia/common/Unk_165e060.h): the
  value into a stack Unk_165e060, its ErrorResultVariant made and assigned
  success, copied into the caller's. Its parameters, which it doesn't use,
  aren't known: the member has none.

They only take functions whose owner (tools/vtables.py owners) has a plain
RTTI name. `--names` writes the mangled names (Name,Sword,Shield) of the
members and of the callees it named, for `funcs.py name --from-file`.
"""
from __future__ import annotations

import argparse
import re
import struct
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

OUT = ROOT / "lib" / "pia" / "gen"
PIA_START = 0x1651510  # Sword, relative: the first Pia function (docs/compiler.md, "Pia 5.18.0")
PIA_END = 0x1750E80    # the nlib_LZ4 tag, the end of the middleware area's Pia part

HEAP = "_Z11Unk_1652bd0v"
NEW = "_ZnwmPN4pead4HeapE"  # operator new(size_t, pead::Heap*)
FREE = "_Z11Unk_1716390Pv"

# Instruction words with their variable fields masked: (word, mask) per instruction.
_BL = (0x94000000, 0xFC000000)
_B = (0x14000000, 0xFC000000)
CREATE = [
    (0xF81E0FF3, ~0), (0xA9017BFD, ~0), (0x910043FD, ~0),  # str x19, [sp, #-0x20]! ; stp x29, x30 ; add x29
    _BL,                                                    # bl heap
    (0xAA0003E1, ~0),                                       # mov x1, x0
    None,                                                   # mov w0, #size
    _BL,                                                    # bl new
    (0xAA0003F3, ~0),                                       # mov x19, x0
    (0xB4000060, ~0),                                       # cbz x0, +12 (past the constructor)
    (0xAA1303E0, ~0),                                       # mov x0, x19
    _BL,                                                    # bl ctor
    (0xA9417BFD, ~0), (0xAA1303E0, ~0), (0xF84207F3, ~0), (0xD65F03C0, ~0),  # ldp ; mov x0, x19 ; ldr x19 ; ret
]
DESTROY = [
    (0xB40001A1, ~0),                                       # cbz x1, ret
    (0xF81E0FF3, ~0), (0xA9017BFD, ~0), (0x910043FD, ~0),
    (0xF9400028, ~0), (0xF9400108, ~0),                     # ldr x8, [x1] ; ldr x8, [x8]
    (0xAA0103E0, ~0), (0xAA0103F3, ~0), (0xD63F0100, ~0),   # mov x0, x1 ; mov x19, x1 ; blr x8
    (0xA9417BFD, ~0), (0xAA1303E0, ~0), (0xF84207F3, ~0),
    _B,                                                     # b free
    (0xD65F03C0, ~0),
]


# A member that returns a fixed result (lib/pia/common/Unk_165e060.h): the
# value into a stack Unk_165e060 (None: its mov), its ErrorResultVariant made
# and assigned success, then copied into the caller's (x8).
_RESULT_HEAD = [(0xD10103FF, ~0), (0xA9024FF4, ~0), (0xA9037BFD, ~0), (0x9100C3FD, ~0), (0xAA0803F3, ~0)]
_RESULT_TAIL = [_BL, (0x910063E1, ~0), (0xAA1403E0, ~0), (0xB9001BFF, ~0), _BL, (0x910023E1, ~0),
                (0xAA1303E0, ~0), _BL, (0xA9437BFD, ~0), (0xA9424FF4, ~0), (0x910103FF, ~0), (0xD65F03C0, ~0)]
RESULT = _RESULT_HEAD + [None, (0xB9000BE8, ~0), (0x910023E8, ~0), (0xB27E0114, ~0), (0xAA1403E0, ~0)] + _RESULT_TAIL
RESULT_ZERO = _RESULT_HEAD + [(0x910023E8, ~0), (0xB27E0114, ~0), (0xAA1403E0, ~0), (0xB9000BFF, ~0)] + _RESULT_TAIL
RESULT_CALLS = ("_ZN2nn3err18ErrorResultVariantC1Ev", "_ZN2nn3err18ErrorResultVariantaSERKNS_6ResultE",
                "_ZN2nn3pia11Unk_165e060C2ERKS1_")


@dataclass
class Constant:
    value: int
    calls: tuple[int, int, int]  # ErrorResultVariant(), its operator=(Result), the copy constructor


@dataclass
class Create:
    heap: int   # call targets, absolute
    new: int
    size: int
    ctor: int


@dataclass
class Destroy:
    free: int


def _target(word: int, at: int) -> int:
    imm = word & 0x3FFFFFF
    if imm & (1 << 25):
        imm -= 1 << 26
    return at + imm * 4


def decode_mov_w(word: int, reg: int) -> int | None:
    """The constant of `mov wN, #imm` (movz with no shift, or orr wN, wzr, #bitmask)."""
    if word & 0xFFE0001F == 0x52800000 | reg:
        return (word >> 5) & 0xFFFF
    if word & 0xFF8003FF == 0x320003E0 | reg:  # orr (32-bit, N=0), Rn = wzr
        return decode_bitmask32((word >> 16) & 0x3F, (word >> 10) & 0x3F)
    return None


def decode_bitmask32(immr: int, imms: int) -> int | None:
    """A 32-bit logical immediate (N=0): DecodeBitMasks of the ARMv8 ARM."""
    combined = ~imms & 0x3F
    if combined == 0:
        return None
    size = 1 << (combined.bit_length() - 1)
    levels = size - 1
    s, r = imms & levels, immr & levels
    if s == levels:
        return None
    elem = (1 << (s + 1)) - 1
    elem = ((elem >> r) | (elem << (size - r))) & ((1 << size) - 1)
    value = 0
    for i in range(0, 32, size):
        value |= elem << i
    return value


def _words(code: bytes) -> list[int]:
    return list(struct.unpack(f"<{len(code) // 4}I", code[:len(code) // 4 * 4]))


def _fits(words: list[int], template: list) -> bool:
    if len(words) != len(template):
        return False
    return all(t is None or w & t[1] == t[0] & t[1] for w, t in zip(words, template))


def match_create(code: bytes, addr: int) -> Create | None:
    """A factory's create member, `return new (heap()) T();` (addr: the function's)."""
    w = _words(code)
    if not _fits(w, CREATE):
        return None
    size = decode_mov_w(w[5], 0)
    if size is None:
        return None
    return Create(_target(w[3], addr + 12), _target(w[6], addr + 24), size, _target(w[10], addr + 40))


def match_result(code: bytes, addr: int) -> Constant | None:
    """A member that returns a fixed result, `return Unk_165e060Value<value>();`."""
    w = _words(code)
    if _fits(w, RESULT_ZERO):
        value, first = 0, 9
    elif _fits(w, RESULT):
        value, first = decode_mov_w(w[5], 8), 10
        if value is None:
            return None
    else:
        return None
    calls = tuple(_target(w[i], addr + 4 * i) for i in (first, first + 4, first + 7))
    return Constant(value, calls)


def match_destroy(code: bytes, addr: int) -> Destroy | None:
    """A factory's destroy member, `if (p) { p->~T(); free(p); }`."""
    w = _words(code)
    if not _fits(w, DESTROY):
        return None
    return Destroy(_target(w[12], addr + 48))


# --------------------------------------------------------------------------- names
def mangle_nested(parts: list[str], tail: str) -> str:
    """`_ZN` + the length-prefixed parts + tail (`4vf11EPv`...)."""
    return "_ZN" + "".join(f"{len(p)}{p}" for p in parts) + tail


def ctor_class(name: str) -> list[str] | None:
    """The class of a base-object constructor's mangled name with no
    parameters, `_ZN11Unk_245bc18C2Ev` -> [Unk_245bc18]."""
    m = re.fullmatch(r"_ZN((?:\d+\w+?)+)C2Ev", name)
    if not m:
        return None
    rest, parts = m.group(1), []
    while rest:
        n = re.match(r"\d+", rest)
        if not n:
            return None
        k = int(n.group())
        rest = rest[len(n.group()):]
        if len(rest) < k:
            return None
        parts.append(rest[:k])
        rest = rest[k:]
    return parts if all(re.fullmatch(r"[A-Za-z_]\w*", p) for p in parts) else None


def class_decl(parts: list[str], body: str) -> str:
    """`class X { body };` inside its namespaces (the parts before the last)."""
    out = f"class {parts[-1]} {{\npublic:\n{body}\n}};"
    for ns in reversed(parts[:-1]):
        out = f"namespace {ns} {{\n{out}\n}}  // namespace {ns}"
    return out


@dataclass
class Member:
    addr: int            # Sword, absolute
    slot: int
    kind: str            # create / destroy
    created: list[str] | None = None  # create: the class constructed
    size: int = 0                     # create: its size; result: the value

    @property
    def arg_type(self) -> str:
        return f"Unk_{self.addr - BASE:x}_arg1"

    def mangled(self, cls: list[str]) -> str:
        member = f"vf{self.slot}"
        params = f"P{len(self.arg_type)}{self.arg_type}" if self.kind == "destroy" else "v"
        return mangle_nested(cls, f"{len(member)}{member}E{params}")

    def declaration(self) -> str:
        if self.kind == "result":
            return f"    nn::pia::Unk_165e060 vf{self.slot}();"
        if self.kind == "create":
            return f"    {'::'.join(self.created)}* vf{self.slot}();"
        return f"    void vf{self.slot}({self.arg_type}* object);"

    def definition(self, cls: list[str]) -> str:
        q = "::".join(cls)
        if self.kind == "result":
            return (f"// 0x{self.addr:x}\nnn::pia::Unk_165e060 {q}::vf{self.slot}() {{\n"
                    f"    return nn::pia::Unk_165e060Value<0x{self.size:x}>();\n}}\n")
        if self.kind == "create":
            t = "::".join(self.created)
            return (f"// 0x{self.addr:x}\n{t}* {q}::vf{self.slot}() {{\n"
                    f"    return new (Unk_1652bd0()) {t}();\n}}\n")
        return (f"// 0x{self.addr:x}\nvoid {q}::vf{self.slot}({self.arg_type}* object) {{\n"
                f"    if (object != nullptr) {{\n        object->~{self.arg_type}();\n"
                f"        Unk_1716390(object);\n    }}\n}}\n")


def render_file(cls: list[str], rtti: str, members: list[Member]) -> str:
    """One class's generated members, with the declarations they need."""
    members = sorted(members, key=lambda x: x.addr)
    out = ["// Scope: common",
           "// Generated by tools/piagen.py write: members of one of Pia's families of small",
           "// functions (see the tool). Placeholder names (lib/pia/README.md).",
           f"// RTTI: {rtti}"]
    kinds = {x.kind for x in members}
    if kinds & {"create", "destroy"}:
        out.append('#include "pia/common/Unk_17162d0.h"')
    if "result" in kinds:
        out.append('#include "pia/common/Unk_165e060.h"')
    out.append("")
    created: dict[tuple, int] = {}
    for x in members:
        if x.kind == "create":
            created.setdefault(tuple(x.created), x.size)
    for c, size in created.items():
        out += [class_decl(list(c), f"    {c[-1]}();\n\n    u8 _0[0x{size:x}];"), ""]
    for x in members:
        if x.kind == "destroy":
            out += [f"struct {x.arg_type} {{\n    virtual ~{x.arg_type}();\n}};", ""]
    out += [class_decl(cls, "\n".join(x.declaration() for x in members)), ""]
    for x in members:
        out.append(x.definition(cls))
    return "\n".join(out).rstrip("\n") + "\n"


def file_name(cls: list[str]) -> str:
    return "_".join(cls) + ".cpp"


# --------------------------------------------------------------------------- the executable
def cmd_write(args) -> int:
    import vtables as V
    from common import load_module, nso_path, read_functions_csv
    from leafgen import _type_name
    from nx.module import DynInfo
    from nx.nso import Nso
    from segments import c_string

    m = V.load("sword")
    mod = load_module("sword")
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), m.img, mod["text_end"])
    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    by = {v.addr: v for v in m.vtables}
    own = V.owners(m.vtables)
    refs: dict[int, set[int]] = {}
    for v in m.vtables:
        for f in v.referrers:
            refs.setdefault(f, set()).add(v.group)
    only = {int(x, 16) for x in args.only.read_text().split()} if args.only else None
    names: dict[int, str] = {}  # relative Sword address -> name to give
    wanted = {"heap": HEAP, "new": NEW, "free": FREE}
    fixed: dict[str, int] = {}
    classes: dict[tuple, tuple[str, list[Member]]] = {}
    refused: dict[str, int] = {}

    def refuse(why: str) -> None:
        refused[why] = refused.get(why, 0) + 1

    for f, r in sorted(rows.items()):
        if not PIA_START <= f < PIA_END or r.sword_size not in (56, 60, 84, 88):
            continue
        if only is not None and f + BASE not in only:
            continue
        code = m.img[f:f + r.sword_size]
        c = match_create(code, f + BASE)
        d = match_destroy(code, f + BASE) if c is None else None
        k = match_result(code, f + BASE) if c is None and d is None else None
        if c is None and d is None and k is None:
            continue
        if k is not None and any((dyn.plt.get(t - BASE) or getattr(rows.get(t - BASE), "name", None)) != n
                                 for t, n in zip(k.calls, RESULT_CALLS)):
            refuse("result calls")
            continue
        if f not in own:
            refuse("no owner")
            continue
        va, slot = own[f]
        g = by.get(by[va].group, by[va])
        p = dyn.slots.get(g.typeinfo + 8) if g.typeinfo is not None else None
        rtti = c_string(m.img, p, 0, len(m.img)) if isinstance(p, int) else None
        cls = _type_name(rtti) if rtti else None
        if cls is None:
            refuse("class name")
            continue
        x = Member(f + BASE, slot, "create" if c else "destroy" if d else "result")
        if r.name and r.name != x.mangled(cls) or not r.name and r.status != "U":
            refuse("named otherwise")
            continue
        calls = {"heap": c.heap, "new": c.new} if c else {"free": d.free} if d else {}
        if any(fixed.setdefault(k, t) != t for k, t in calls.items()):
            refuse("other allocator")
            continue
        if c:
            ctor = rows.get(c.ctor - BASE)
            if ctor is None:
                refuse("ctor")
                continue
            if ctor.name:
                x.created = ctor_class(ctor.name)
            elif len(refs.get(c.ctor - BASE, ())) == 1:
                (grp,) = refs[c.ctor - BASE]
                x.created = [V.class_name(by[grp])]
                names[c.ctor - BASE] = V.ctor_name(x.created[0])
            if x.created is None:
                refuse("ctor")
                continue
            x.size = c.size
        if k:
            x.size = k.value
        classes.setdefault(tuple(cls), (rtti, []))[1].append(x)
        names[f] = x.mangled(cls)
    for k, t in fixed.items():
        r = rows.get(t - BASE)
        if r is not None and not r.name:
            names[t - BASE] = wanted[k]
        elif r is not None and r.name != wanted[k]:
            print(f"{k} at 0x{t:x} is named {r.name}, not {wanted[k]}", file=sys.stderr)
            return 1
    OUT.mkdir(parents=True, exist_ok=True)
    for cls, (rtti, members) in classes.items():
        (OUT / file_name(list(cls))).write_text(render_file(list(cls), rtti, members), encoding="utf-8",
                                                newline="\n")
    if args.names:
        lines = ["Name,Sword,Shield"]
        for f, n in sorted(names.items()):
            r = rows[f]
            if r.name == n:
                continue
            lines.append(f"{n},{f + BASE:#x},{r.shield + BASE:#x}" if r.shield is not None else f"{n},{f + BASE:#x},")
        args.names.write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")
    n = sum(len(x[1]) for x in classes.values())
    print(f"wrote {n} members of {len(classes)} classes; refused: "
          + ", ".join(f"{k} {v}" for k, v in sorted(refused.items(), key=lambda kv: -kv[1])), file=sys.stderr)
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("write", help="every family's members, into lib/pia/gen")
    p.add_argument("--names", type=Path, help="write Name,Sword,Shield for funcs.py name --from-file")
    p.add_argument("--only", type=Path, help="file of addresses (one per line) to write")
    args = ap.parse_args(argv)
    return {"write": cmd_write}[args.cmd](args)


if __name__ == "__main__":
    raise SystemExit(main())
