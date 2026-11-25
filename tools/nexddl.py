#!/usr/bin/env python3
"""NEX 4.6.8's DDL-generated code, written as C++ from the executable.

    python tools/nexddl.py streams                  # list the stream-out functions and their fields
    python tools/nexddl.py streams --write          # write lib/nex/ddl/Streams.cpp + names
    python tools/nexddl.py classes                  # the RTTI-named DDL classes and their members

NEX's DDL compiler turns each protocol's data declarations into C++: a class
`_DDL_X` (RTTI `N2nn3nex<n>_DDL_XE`) that holds the fields, the class `X`
derived from it, and code that writes and reads the fields to and from a
`nn::nex::ByteStream`. All of it is very regular, so it is written from the
executable rather than by hand:

- **Stream-out functions.** Each one writes a structure: unless the stream
  writes them without headers (`ByteStream` +0x69), a version byte and a
  placeholder for the length, then each field in declaration order, then the
  length. A field is a scalar (`ByteStream`'s raw write, 0x71015c8ad0, with
  its size), a String, a bool, another structure or a container (`qVector`:
  a u32 count, then each element), each through its own function. The
  function's parameter is a placeholder struct with those fields at those
  offsets, named after the function (`Unk_<addr>`): nothing in the executable
  says which DDL class a stream function writes.
- **Classes.** (`classes`) Each RTTI-named `_DDL_X`/`X` pair, its members
  from its destructor.

The functions' names are placeholders (`Unk_<addr>`) except where the RTTI
names the class (destructors). The output is plain C++ that `tools/check.py`
then compares; whatever doesn't match is left out.
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE  # noqa: E402

WRITE = 0x15C8AD0       # bool Unk_15c8ad0(void* stream, u64 data, u64 size): ByteStream's raw write
SEEK = 0x15C8AA0        # ByteStream::Unk_15c8aa0(size_t): moves the write position
STRING_OUT = 0x162CEC0  # writes a nn::nex::String
BOOL_OUT = 0x15C8CA0    # writes a bool as one byte
STRING_IN = 0x162D000   # reads a nn::nex::String
BOOL_IN = 0x15C8CE0     # reads a bool (one byte, nonzero)
NEX_LO, NEX_HI = 0x1570900, 0x1650000  # NEX (Pia follows), relative to BASE

SCALAR = {1: "u8", 2: "u16", 4: "u32", 8: "u64"}

# Stream functions the templates recognize but don't match (tools/check.py), left
# out of the output: the reads' block placement differs (where the backend puts
# the shared error and return blocks), or a field after a call is read another way.
NOT_MATCHING = {
    0x158BD80, 0x158EF20, 0x158F650, 0x1590C40, 0x15911B0, 0x15913F0, 0x1591730, 0x15A34B0,
    0x15A7D60, 0x15AF0C0, 0x15AFEF0, 0x15B2F20, 0x1632870, 0x16337A0,
}


@dataclass
class Ins:
    addr: int
    mnemonic: str
    op_str: str


def disasm(code: bytes, addr: int) -> list[Ins]:
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    return [Ins(i.address, i.mnemonic, i.op_str) for i in md.disasm(code, addr)]


class Unrecognized(Exception):
    pass


@dataclass
class Field:
    kind: str                 # scalar | call | vector
    offset: int
    size: int = 0             # scalar size, or a vector's element size
    callee: int | None = None  # call: the field's function; vector: the element's (None: scalar elements)


@dataclass
class StreamOut:
    addr: int                 # relative to BASE
    size: int
    read: bool = False        # a stream-in function (reads the fields)
    fields: list[Field] = field(default_factory=list)
    version: int = 0          # the structure's version: the header writes min(its version byte, this)
    later: list[Field] = field(default_factory=list)  # fields of version 1, written only with the header


_IMM = r"#(-?0x[0-9a-f]+|-?\d+)"


def _imm(s: str) -> int:
    return int(s, 0)


def _target(op: str) -> int:
    return int(op.lstrip("#"), 16) - BASE


def _magic_div(ins: list[Ins], i: int, reg: str) -> tuple[int, int] | None:
    """The element size of `count = (end - begin) / size`, computed before
    instruction i: `sub x8, end, begin` then `asr`/`lsr` (a power of two) or a
    shift and a multiply by the inverse (`mov w9, #lo; movk w9, #hi, lsl
    #16; lsr; mul`). Returns (element size, index of the sub)."""
    shift, magic, j = 0, None, i - 1
    lo = hi = None
    while j >= 0 and i - j < 12:
        m, o = ins[j].mnemonic, ins[j].op_str
        if m == "sub" and re.fullmatch(r"x\d+, x\d+, x\d+", o):
            break
        if m in ("asr", "lsr"):
            mm = re.fullmatch(r"x\d+, x\d+, " + _IMM, o)
            if mm:
                shift = _imm(mm.group(1))
        if m == "mov" and re.fullmatch(r"w\d+, " + _IMM, o):
            lo = _imm(o.split("#")[1])
        if m == "movk":
            hi = _imm(o.split("#")[1].split(",")[0])
        j -= 1
    else:
        return None
    if lo is not None and hi is not None:
        magic = (hi << 16) | lo
    if magic is None:
        return 1 << shift, j
    # exact division by an odd number d: d * magic == 1 (mod 2**32)
    for odd in range(1, 512, 2):
        if (odd * magic) & 0xFFFFFFFF == 1:
            return odd << shift, j
    return None


def stream_out(code: bytes, addr: int) -> StreamOut:
    """The fields a stream-out function writes, in order."""
    ins = disasm(code, addr + BASE)
    if not any(i.mnemonic == "ldrb" and i.op_str.endswith("[x0, #0x69]") for i in ins[:12]):
        raise Unrecognized("no header flag")
    flag = next(i.op_str.split(",")[0] for i in ins[:12] if i.op_str.endswith("[x0, #0x69]"))
    obj = next((i.op_str.split(",")[0] for i in ins[:14] if i.mnemonic == "mov" and i.op_str.endswith(", x1")), None)
    if obj is None:
        raise Unrecognized("no object register")
    # the body: after the write of the length placeholder (str wzr; bl WRITE with w2 = 4)
    calls = [k for k, i in enumerate(ins) if i.mnemonic == "bl"]
    start = None
    for k in calls[:3]:
        if _target(ins[k].op_str) == WRITE and any(i.mnemonic == "str" and i.op_str.startswith("wzr")
                                                   for i in ins[max(0, k - 5):k]):
            start = k + 1
            break
    if start is None:
        raise Unrecognized("no length placeholder")
    end = next((k for k in range(start, len(ins)) if ins[k].mnemonic == "cbnz"
                and ins[k].op_str.startswith(flag + ",")), None)
    if end is None:
        raise Unrecognized("no trailer")
    out = StreamOut(addr, len(code))
    # min(version, N): `cmp w8, #N` before the version's write (`cmp w8, #0` for 0)
    for i in ins[:start]:
        mm = re.fullmatch(r"w\d+, " + _IMM, i.op_str)
        if i.mnemonic == "cmp" and mm:
            out.version = _imm(mm.group(1))
    out.fields = _fields(ins, start, end, obj)
    # fields of a later version, written only with the header: `ldrb w8, [obj, #8]; cbz w8, trailer`
    k = end + 1
    if k + 1 < len(ins) and ins[k].mnemonic == "ldrb" and ins[k].op_str.endswith(f"[{obj}, #8]") \
            and ins[k + 1].mnemonic == "cbz":
        to = _target(ins[k + 1].op_str.split(", ")[1]) + BASE
        stop = next((j for j in range(k + 2, len(ins)) if ins[j].addr == to), None)
        if stop is None:
            raise Unrecognized(f"versioned fields at {ins[k].addr:#x}")
        out.later = _fields(ins, k + 2, stop, obj)
    return out


def _fields(ins: list[Ins], k: int, end: int, obj: str) -> list[Field]:
    """The fields written by ins[k:end]."""
    fields = []
    regs: dict[str, tuple[str, int]] = {}
    while k < end:
        i = ins[k]
        m, o = i.mnemonic, i.op_str
        mm = re.fullmatch(r"(x\d+), (x\d+), " + _IMM, o)
        if m == "add" and mm:
            regs[mm.group(1)] = (mm.group(2), _imm(mm.group(3)))
        elif m == "mov" and re.fullmatch(r"([xw]\d+), " + _IMM, o):
            r, v = o.split(", #")
            regs[r] = ("imm", _imm(v))
        elif m == "mov" and re.fullmatch(r"x\d+, x\d+", o):
            r, src = o.split(", ")
            regs[r] = (src, 0)
        elif m == "ldp" and re.fullmatch(r"(x\d+), (x\d+), \[" + obj + r", " + _IMM + r"\]", o):
            # a container: count = (end - begin) / size, written from the stack, then a loop
            off = _imm(o.split("#")[1].rstrip("]"))
            f, k = _container(ins, k, end, obj, off)
            fields.append(f)
            regs = {}
            continue
        elif m == "ldr" and re.fullmatch(r"(x\d+), \[" + obj + r", " + _IMM + r"\]", o) and any(
                x.mnemonic == "str" and x.op_str.startswith("w" + o.split(",")[0][1:] + ", [sp")
                for x in ins[k + 1:k + 6]):
            off = _imm(o.split("#")[1].rstrip("]"))
            f, k = _list(ins, k, end, obj, off)
            fields.append(f)
            regs = {}
            continue
        elif m == "bl":
            t = _target(o)
            x1 = regs.get("x1")
            if x1 is None or x1[0] != obj:
                raise Unrecognized(f"call at {i.addr:#x} without a field")
            if t == WRITE:
                w2 = regs.get("w2")
                if w2 is None or w2[0] != "imm" or w2[1] not in SCALAR:
                    raise Unrecognized(f"write at {i.addr:#x} of an unknown size")
                fields.append(Field("scalar", x1[1], w2[1]))
            elif t == SEEK:
                raise Unrecognized(f"seek at {i.addr:#x}")
            else:
                fields.append(Field("call", x1[1], callee=t))
            regs = {}
        elif m in ("b", "cbz", "cbnz", "tbz", "tbnz", "ret", "blr", "br") or m.startswith("b."):
            raise Unrecognized(f"branch at {i.addr:#x}")
        k += 1
    return fields


def _container(ins: list[Ins], k: int, end: int, obj: str, off: int) -> tuple[Field, int]:
    """The container whose `ldp begin, end, [obj, #off]` is at k: its count
    write, then `ldp` again and a loop over the elements. Returns the field and
    the index after the loop."""
    w = next((j for j in range(k, min(k + 16, end)) if ins[j].mnemonic == "bl"), None)
    if w is None or _target(ins[w].op_str) != WRITE:
        raise Unrecognized(f"container at {ins[k].addr:#x} without a count")
    store = next((j for j in range(k, w) if ins[j].mnemonic == "str" and ins[j].op_str.startswith("w")), None)
    if store is None:
        raise Unrecognized(f"container at {ins[k].addr:#x}: no count store")
    d = _magic_div(ins, store, "")
    if d is None:
        raise Unrecognized(f"container at {ins[k].addr:#x}: no element size")
    esize = d[0]
    # the loop: ldp it, last, [obj, #off]; cmp; b.eq out; ...; bl elem; add it, it, #esize; cmp; b.ne
    j = w + 1
    if not (ins[j].mnemonic == "ldp" and ins[j].op_str.endswith(f"[{obj}, #{off:#x}]")):
        raise Unrecognized(f"container at {ins[k].addr:#x}: no loop")
    it = ins[j].op_str.split(",")[0]
    calls = []
    j += 1
    while j < end:
        m, o = ins[j].mnemonic, ins[j].op_str
        if m == "bl":
            calls.append(_target(o))
        if m == "b.ne":
            break
        j += 1
    else:
        raise Unrecognized(f"container at {ins[k].addr:#x}: no loop end")
    if len(calls) != 1:
        raise Unrecognized(f"container at {ins[k].addr:#x}: {len(calls)} calls per element")
    if not any(ins[x].mnemonic == "add" and re.fullmatch(rf"{it}, {it}, " + _IMM, ins[x].op_str)
               and _imm(ins[x].op_str.split("#")[1]) == esize for x in range(w, j)):
        raise Unrecognized(f"container at {ins[k].addr:#x}: element size")
    callee = calls[0]
    return Field("vector", off, esize, callee=None if callee == WRITE else callee), j + 1


def _list(ins: list[Ins], k: int, end: int, obj: str, off: int) -> tuple[Field, int]:
    """The qList whose size (`ldr xN, [obj, #off]`, std::list's size after its
    two sentinel pointers) is loaded at k: the count write, then a loop from
    the sentinel's next node over each node's value (node + 0x10)."""
    w = next((j for j in range(k, min(k + 8, end)) if ins[j].mnemonic == "bl"), None)
    if w is None or _target(ins[w].op_str) != WRITE:
        raise Unrecognized(f"list at {ins[k].addr:#x} without a count")
    j = w + 1
    if not (ins[j].mnemonic == "ldr" and ins[j].op_str.endswith(f"[{obj}, #{off - 8:#x}]")):
        raise Unrecognized(f"list at {ins[k].addr:#x}: no loop")
    it = ins[j].op_str.split(",")[0]
    calls, size = [], 0
    j += 1
    while j < end:
        m, o = ins[j].mnemonic, ins[j].op_str
        if m == "bl":
            calls.append(_target(o))
        if m == "mov" and re.fullmatch(r"w2, " + _IMM, o):
            size = _imm(o.split("#")[1])
        if m == "b.ne":
            break
        j += 1
    else:
        raise Unrecognized(f"list at {ins[k].addr:#x}: no loop end")
    if len(calls) != 1 or not any(ins[x].op_str == f"x1, {it}, #0x10" for x in range(w, j)):
        raise Unrecognized(f"list at {ins[k].addr:#x}: element")
    callee = calls[0]
    if callee == WRITE and size not in SCALAR:
        raise Unrecognized(f"list at {ins[k].addr:#x}: element size")
    return Field("list", off - 0x10, size if callee == WRITE else 0, callee=None if callee == WRITE else callee), j + 1




def stream_in(code: bytes, addr: int) -> StreamOut:
    """The fields a stream-in function reads. Its reads are inlined: each
    scalar's failure path zeroes the field (`str wzr, [obj, #off]`, the width
    is its size); a String, bool or structure is read by a call with x1 =
    obj + off. Fields are declared, laid out and read in the same order, so
    they're sorted by offset."""
    ins = disasm(code, addr + BASE)
    if not any(i.mnemonic == "strb" and i.op_str == "wzr, [x1, #8]" for i in ins[:10]):
        raise Unrecognized("no version reset")
    if not any(i.mnemonic == "ldrb" and i.op_str.endswith("[x0, #0x69]") for i in ins[:12]):
        raise Unrecognized("no header flag")
    objs = {"x1"}
    for i in ins[:16]:
        if i.mnemonic == "mov" and re.fullmatch(r"x\d+, x1", i.op_str):
            objs.add(i.op_str.split(",")[0])
    clobbered = False
    regs: dict[str, tuple[str, int]] = {}
    found: dict[int, Field] = {}
    widths = {"strb": 1, "strh": 2}
    for i in ins:
        m, o = i.mnemonic, i.op_str
        if m in ("blr", "br"):
            raise Unrecognized(f"indirect call at {i.addr:#x}")
        mm = re.fullmatch(r"(x\d+), (x\d+), " + _IMM, o)
        if m == "add" and mm:
            regs[mm.group(1)] = (mm.group(2), _imm(mm.group(3)))
            continue
        z = re.fullmatch(r"([wx])zr, \[(x\d+), " + _IMM + r"\]", o)
        if m in ("str", "strb", "strh") and z and (z.group(2) in objs - {"x1"} or z.group(2) == "x1" and not clobbered):
            off = _imm(z.group(3))
            if off == 8:
                continue
            size = widths.get(m, 8 if z.group(1) == "x" else 4)
            prev = found.get(off)
            if prev is not None and (prev.kind != "scalar" or prev.size != size):
                raise Unrecognized(f"field {off:#x} read two ways")
            found[off] = Field("scalar", off, size)
        if m == "bl":
            t = _target(o)
            x1 = regs.get("x1")
            if x1 is None or not (x1[0] in objs - {"x1"} or x1[0] == "x1" and not clobbered):
                raise Unrecognized(f"call at {i.addr:#x} without a field")
            found[x1[1]] = Field("call", x1[1], callee=t)
            clobbered = True
            regs = {}
        if m == "mov" and o.startswith("x1,"):
            regs["x1"] = (o.split(", ")[1], 0)
    if not found:
        raise Unrecognized("no fields")
    out = StreamOut(addr, len(code), read=True)
    out.fields = [found[k] for k in sorted(found)]
    return out


# --------------------------------------------------------------------------- C++
def struct_name(addr: int) -> str:
    return f"Unk_{addr:x}"


KNOWN_OUT = {STRING_OUT: ("nn::nex::String", 0x28, "NS0_6StringE"), BOOL_OUT: ("bool", 1, "b")}
KNOWN_IN = {STRING_IN: ("nn::nex::String", 0x28, "NS0_6StringE"), BOOL_IN: ("bool", 1, "b")}
KNOWN_TYPES = {**KNOWN_OUT, **KNOWN_IN}


def func_name(addr: int, read: bool) -> str:
    return f"Unk_{addr:x}_{'read' if read else 'write'}"


def mangled_name(addr: int, read: bool) -> str:
    """`Unk_<addr>_write(nn::nex::ByteStream*, <its struct> const&)` or
    `Unk_<addr>_read(nn::nex::ByteStream*, <its struct>&)`, mangled."""
    n = func_name(addr, read)
    arg = KNOWN_TYPES[addr][2] if addr in KNOWN_TYPES else f"{len(struct_name(addr))}{struct_name(addr)}"
    return f"_Z{len(n)}{n}PN2nn3nex10ByteStreamE{'R' if read else 'RK'}{arg}"


def field_type(f: Field) -> str:
    if f.kind == "scalar":
        return SCALAR[f.size]
    t = f.callee
    if f.kind in ("vector", "list"):
        elem = SCALAR[f.size] if t is None else (KNOWN_TYPES[t][0] if t in KNOWN_TYPES else struct_name(t))
        return f"nn::nex::{'qVector' if f.kind == 'vector' else 'qList'}<{elem}>"
    return KNOWN_TYPES[t][0] if t in KNOWN_TYPES else struct_name(t)


def write_statement(f: Field) -> str:
    name = f"v.field_{f.offset:x}"
    if f.kind == "scalar":
        return f"s->Write({name});"
    if f.kind == "call":
        return f"{func_name(f.callee, False)}(s, {name});"
    # the count is a local of an inlined helper: its stack slot comes before the function's own
    if f.callee is None:
        return f"WriteContainer(s, {name});"
    return f"WriteContainer(s, {name}, {func_name(f.callee, False)});"


def render_write(s: StreamOut) -> str:
    """The function: the header unless the stream leaves it out, the fields,
    then the length. Written out as the DDL compiler would, with no helper
    object: a helper's inlined constructor and destructor order the
    temporaries on the stack differently."""
    body = "\n".join("    " + write_statement(f) for f in s.fields)
    if s.later:
        body += "\n    if (!noHeader && v.GetVersion() >= 1) {\n" + "\n".join(
            "        " + write_statement(f) for f in s.later) + "\n    }"
    return f"""// {s.addr + BASE:#x}
void {func_name(s.addr, False)}(nn::nex::ByteStream* s, const {struct_name(s.addr)}& v) {{
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {{
        s->Write(std::min(v.GetVersion(), (u8){s.version}));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }}
{body}
    if (!noHeader) {{
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }}
}}
"""


def render_read(s: StreamOut) -> str:
    """The function: the version and the length unless the stream leaves them
    out, the fields (a scalar inline; anything else through its function,
    with the stream's error flag checked around it), then the end of the
    structure from its length. The last field's failure is kept in a flag:
    its `noHeader | err` stays a phi that the backend tail-duplicates, as in
    the original."""
    lines = []
    n = len(s.fields)
    for k, f in enumerate(s.fields):
        last = k == n - 1
        name = f"v.field_{f.offset:x}"
        if f.kind == "scalar":
            lines.append(f"bool err = !ReadField(s, {name});" if last else f"if (!ReadField(s, {name})) return;")
        else:
            lines.append("if (s->m_error) return;")
            lines.append(f"{func_name(f.callee, True)}(s, {name});")
            lines.append("bool err = s->m_error;" if last else "if (s->m_error) return;")
    body = "\n".join("    " + x for x in lines)
    return f"""// {s.addr + BASE:#x}
void {func_name(s.addr, True)}(nn::nex::ByteStream* s, {struct_name(s.addr)}& v) {{
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {{
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }}
    size_t start = s->m_pos;
    if (s->m_error) return;
{body}
    if (noHeader | err) return;
    EndStructure(s, start, length);
}}
"""


@dataclass
class TypeInfo:
    cpp: str
    size: int


class Layouts:
    """The placeholder structs' layouts: each stream function's parameter has
    the fields it writes or reads at their offsets. A struct that is an
    element of a container takes the element's size; a type written or read by
    a function that isn't one of these (opaque) gets the room it has."""

    def __init__(self, specs: dict[int, StreamOut]):
        self.specs = specs
        self.sizes: dict[int, int] = {}
        self.gaps: dict[int, int] = {}
        for s in specs.values():
            fs = sorted(s.fields + s.later, key=lambda f: f.offset)
            for a, b in zip(fs, fs[1:] + [None]):
                if a.kind == "vector" and a.callee is not None and a.callee not in KNOWN_TYPES:
                    self.sizes[a.callee] = a.size
                if a.kind == "call" and a.callee not in KNOWN_TYPES and a.callee not in specs and b is not None:
                    room = b.offset - a.offset
                    self.gaps[a.callee] = min(self.gaps.get(a.callee, room), room)

    def type_of(self, f: Field) -> TypeInfo:
        if f.kind == "scalar":
            return TypeInfo(SCALAR[f.size], f.size)
        if f.kind in ("vector", "list"):
            return TypeInfo(field_type(f), 0x18)
        if f.callee in KNOWN_TYPES:
            cpp, size, _ = KNOWN_TYPES[f.callee]
            return TypeInfo(cpp, size)
        return TypeInfo(struct_name(f.callee), self.size_of(f.callee))

    def size_of(self, t: int) -> int:
        if t in self.sizes:
            return self.sizes[t]
        if t in self.specs:
            end = 9
            for f in self.specs[t].fields + self.specs[t].later:
                end = max(end, f.offset + self.type_of(f).size)
            return (end + 7) & ~7
        return self.gaps.get(t, 8)

    def opaque(self) -> list[tuple[int, bool]]:
        """(function, reads) of the field types no function here handles."""
        return sorted({(f.callee, s.read) for s in self.specs.values() for f in s.fields + s.later
                       if f.callee is not None and f.callee not in KNOWN_TYPES and f.callee not in self.specs})


def render_struct(addr: int, lay: Layouts) -> str:
    s = lay.specs[addr]
    name = struct_name(addr)
    lines = [f"struct {name} {{", "    u8 _0[0x8];", "    u8 m_version;"]
    pos = 9
    asserts = []
    for f in sorted(s.fields + s.later, key=lambda f: f.offset):
        t = lay.type_of(f)
        if f.offset < pos:
            raise Unrecognized(f"{name}: field {f.offset:#x} overlaps")
        if f.offset > pos:
            lines.append(f"    u8 _{pos:x}[{f.offset - pos:#x}];")
        lines.append(f"    {t.cpp} field_{f.offset:x};")
        asserts.append(f"PKMN_OFFSET_ASSERT({name}, field_{f.offset:x}, {f.offset:#x});")
        pos = f.offset + t.size
    size = lay.size_of(addr)
    if size > pos:
        lines.append(f"    u8 _{pos:x}[{size - pos:#x}];")
    lines += ["", "    u8 GetVersion() const { return m_version; }", "};", f"PKMN_SIZE_ASSERT({name}, {size:#x});"]
    return "\n".join(lines + asserts) + "\n"


def render_opaque(t: int, read: bool, lay: Layouts) -> str:
    n = struct_name(t)
    const = "" if read else "const "
    verb = "read" if read else "written"
    return (f"// {verb} by {t + BASE:#x}, which isn't one of these functions\n"
            f"struct {n} {{\n    u8 _0[{lay.size_of(t):#x}];\n}};\n"
            f"void {func_name(t, read)}(nn::nex::ByteStream* s, {const}{n}& v);\n")


def order(specs: dict[int, StreamOut]) -> list[int]:
    """Structs before the structs that hold them."""
    done: list[int] = []
    seen: set[int] = set()

    def visit(a: int) -> None:
        if a in seen:
            return
        seen.add(a)
        for f in specs[a].fields + specs[a].later:
            if f.callee in specs:
                visit(f.callee)
        done.append(a)

    for a in sorted(specs):
        visit(a)
    return done


HEADER = """#pragma once
// NEX 4.6.8's DDL stream functions (tools/nexddl.py streams): each writes or
// reads a structure's fields to or from a ByteStream. The structures are
// placeholders named after their function: nothing says which DDL class each
// one is.
#include <nn/nex/ByteStream.h>
#include <nn/nex/String.h>
#include <nn/nex/qList.h>
#include <nn/nex/qVector.h>
"""

SOURCE = """// Scope: common
// NEX 4.6.8's DDL stream functions (tools/nexddl.py streams).
#include "Streams.h"

using nn::nex::EndStructure;
using nn::nex::ReadField;
using nn::nex::ReadLength;
"""


def prototype(s: StreamOut) -> str:
    const = "" if s.read else "const "
    return f"void {func_name(s.addr, s.read)}(nn::nex::ByteStream* s, {const}{struct_name(s.addr)}& v);"


def render_file(specs: dict[int, StreamOut]) -> tuple[str, str]:
    """(header, source): the structs and the prototypes, then the functions."""
    lay = Layouts(specs)
    out = [HEADER]
    for a, k in sorted(KNOWN_TYPES.items()):
        read = a in KNOWN_IN
        const = "" if read else "const "
        out.append(f"void {func_name(a, read)}(nn::nex::ByteStream* s, {const}{k[0]}& v);")
    out.append("")
    out += [render_opaque(t, r, lay) for t, r in lay.opaque()]
    out += [render_struct(a, lay) for a in order(specs)]
    out += [prototype(specs[a]) for a in order(specs)]
    src = [SOURCE]
    src += [(render_read if specs[a].read else render_write)(specs[a]) for a in order(specs)]
    return "\n".join(out) + "\n", "\n".join(src)


# --------------------------------------------------------------------------- protocol calls
MESSAGE_CTOR = 0x15DE0E0    # nn::nex::Message::Message()
MESSAGE_DTOR = 0x15DE2D0    # nn::nex::Message::~Message()
SET_PROTOCOL = 0x1630B10    # Message::Unk_1630b10(u16 protocolId, u32 request)
REGISTER = 0x1630A20        # Unk_1630a20(Message*, ProtocolCallContext*): the call's ID
SET_METHOD = 0x1630A90      # Message::Unk_1630a90(u32 methodId)
ADD_RESULT = 0x1630AC0      # Unk_1630ac0(ProtocolCallContext*, void*): where a result goes
CAN_DEFER = 0x1630B90       # Unk_1630b90(ClientProtocol*, u32)
SEND = 0x162F1A0            # Unk_162f1a0(ClientProtocol*, ProtocolCallContext*, Message*)
QRESULT = 0x15BBC10         # Unk_15bbc10(qResult*, const u32&)
SET_OUTCOME = 0x15C9360     # Unk_15c9360(ProtocolCallContext*, const qResult&)
ARG_REGS = [f"x{i}" for i in range(2, 8)]


@dataclass
class CallArg:
    reg: str                  # the argument register (x2...)
    kind: str                 # write (an input written by `callee`) | scalar (size) | result
    size: int = 0
    callee: int | None = None


@dataclass
class Call:
    addr: int
    size: int
    method: int
    args: list[CallArg] = field(default_factory=list)  # in the order the code uses them
    table: int | None = None   # the protocol's table of result handlers (a global)
    slot: int = 0              # the handler's index in it
    handler: int | None = None


def protocol_call(code: bytes, addr: int) -> Call:
    """A protocol client's call: a Message on the stack, the core's lock,
    the protocol and method IDs, each input written (with a check of the
    message's error flag after it), the results' addresses registered with the
    call context, the method's result handler stored in the protocol's table,
    then the message sent (after the lock is released when the protocol can
    defer it)."""
    ins = disasm(code, addr + BASE)
    bls = [(k, _target(i.op_str)) for k, i in enumerate(ins) if i.mnemonic == "bl"]
    if not bls or bls[0][1] != MESSAGE_CTOR:
        raise Unrecognized("no message")
    targets = [t for _, t in bls]
    for t in (SET_PROTOCOL, REGISTER, SET_METHOD, SEND, MESSAGE_DTOR):
        if t not in targets:
            raise Unrecognized(f"no call of {t + BASE:#x}")
    if any(i.mnemonic in ("blr",) for i in ins) is False:
        raise Unrecognized("no lock")
    # arguments: x2... saved into callee-saved registers before the message's constructor
    saved: dict[str, str] = {}
    for i in ins[:bls[0][0]]:
        mm = re.fullmatch(r"(x\d+), (x[2-7])", i.op_str)
        if i.mnemonic == "mov" and mm:
            saved[mm.group(1)] = mm.group(2)
    k = next(k for k, t in bls if t == SET_METHOD)
    prev = ins[k - 2:k]
    mm = next((re.fullmatch(r"w1, " + _IMM, i.op_str) for i in prev if i.mnemonic == "mov"
               and re.fullmatch(r"w1, " + _IMM, i.op_str)), None)
    if mm is None:
        raise Unrecognized("no method ID")
    out = Call(addr, len(code), _imm(mm.group(1)))
    end = next((j for j in range(k, len(ins)) if ins[j].mnemonic == "ldrb" and ins[j].op_str.endswith("#0x70]")),
               None)
    if end is None:
        raise Unrecognized("no deferral check")
    regs: dict[str, tuple[str, int]] = {}
    j = k + 1
    got: dict[str, int] = {}
    while j < end:
        i = ins[j]
        m, o = i.mnemonic, i.op_str
        if m == "mov" and re.fullmatch(r"([xw]\d+), " + _IMM, o):
            r, v = o.split(", #")
            regs[r] = ("imm", _imm(v))
        elif m == "mov" and re.fullmatch(r"x\d+, x\d+", o):
            r, src = o.split(", ")
            regs[r] = (src, 0)
        elif m == "ldr" and re.fullmatch(r"(x\d+), \[(x\d+), " + _IMM + r"\]", o) and ins[j - 2].mnemonic == "adrp":
            pass
        if m == "adrp":
            # a GOT load: adrp xN, page; ...; ldr xN, [xN, #lo]
            r = o.split(",")[0]
            page = int(o.split("#")[1], 16) - BASE
            lo = next((x for x in ins[j + 1:j + 4] if x.mnemonic == "ldr" and x.op_str.startswith(f"{r}, [{r}, #")), None)
            if lo is not None:
                got[r] = page + _imm(lo.op_str.split("#")[1].rstrip("]"))
        st = re.fullmatch(r"x9, \[x8(?:, " + _IMM + r")?\]", o)
        if m == "str" and st and "x8" in got and "x9" in got:
            out.table, out.slot, out.handler = got["x8"], (_imm(st.group(1)) if st.group(1) else 0) // 8, got["x9"]
        if m == "bl":
            t = _target(o)
            x1 = regs.get("x1")
            src = saved.get(x1[0]) if x1 and x1[1] == 0 else None
            if t in (QRESULT, SET_OUTCOME, SEND, MESSAGE_DTOR, CAN_DEFER):
                pass
            elif t == ADD_RESULT:
                if src is None:
                    raise Unrecognized(f"result at {i.addr:#x} isn't an argument")
                out.args.append(CallArg(src, "result"))
            elif src is None:
                raise Unrecognized(f"call at {i.addr:#x} without an argument")
            elif t == WRITE:
                w2 = regs.get("w2")
                if w2 is None or w2[0] != "imm" or w2[1] not in SCALAR:
                    raise Unrecognized(f"write at {i.addr:#x} of an unknown size")
                out.args.append(CallArg(src, "scalar", w2[1]))
            elif t in (SEND, MESSAGE_DTOR, CAN_DEFER):
                pass  # an input's error path, laid out before the next input
            else:
                out.args.append(CallArg(src, "write", callee=t))
            regs = {}
        ld = re.fullmatch(r"x\d+, x\d+, \[(x\d+)\]", o)
        if m == "ldp" and ld and ld.group(1) in saved:
            a, j = _call_container(ins, j, end, ld.group(1), saved[ld.group(1)])
            out.args.append(a)
            regs = {}
            continue
        if m in ("b.eq", "b.ne"):
            raise Unrecognized(f"loop at {i.addr:#x}")
        j += 1
    if len({a.reg for a in out.args}) != len(out.args):
        raise Unrecognized("an argument used twice")
    if out.table is not None:
        # the global the table is: a GOT slot's target
        pass
    return out


def _call_container(ins: list[Ins], k: int, end: int, reg: str, arg: str) -> tuple[CallArg, int]:
    """An input qVector (`ldp begin, end, [reg]` at k): its u32 count, then a
    loop writing each element. Returns the argument and the index after the loop."""
    w = next((j for j in range(k, min(k + 16, end)) if ins[j].mnemonic == "bl"), None)
    if w is None or _target(ins[w].op_str) != WRITE:
        raise Unrecognized(f"container at {ins[k].addr:#x} without a count")
    store = next((j for j in range(k, w) if ins[j].mnemonic in ("str", "stur") and ins[j].op_str.startswith("w")), None)
    d = _magic_div(ins, store, "") if store is not None else None
    if d is None:
        raise Unrecognized(f"container at {ins[k].addr:#x}: no element size")
    esize = d[0]
    j = w + 1
    if not (ins[j].mnemonic == "ldp" and ins[j].op_str.endswith(f"[{reg}]")):
        raise Unrecognized(f"container at {ins[k].addr:#x}: no loop")
    it = ins[j].op_str.split(",")[0]
    calls, size = [], 0
    j += 1
    while j < end:
        m, o = ins[j].mnemonic, ins[j].op_str
        if m == "bl":
            calls.append(_target(o))
        if m == "mov" and re.fullmatch(r"w2, " + _IMM, o):
            size = _imm(o.split("#")[1])
        if m == "b.ne":
            break
        j += 1
    else:
        raise Unrecognized(f"container at {ins[k].addr:#x}: no loop end")
    if len(calls) != 1:
        raise Unrecognized(f"container at {ins[k].addr:#x}: {len(calls)} calls per element")
    if not any(ins[x].mnemonic == "add" and re.fullmatch(rf"{it}, {it}, " + _IMM, ins[x].op_str)
               and _imm(ins[x].op_str.split("#")[1]) == esize for x in range(w, j)):
        raise Unrecognized(f"container at {ins[k].addr:#x}: element size")
    callee = calls[0]
    if callee == WRITE and size != esize:
        raise Unrecognized(f"container at {ins[k].addr:#x}: element write size")
    return CallArg(arg, "vector", esize, None if callee == WRITE else callee), j + 1


def resolve_got(img_slots: dict[int, int | str], c: Call) -> None:
    """The table's and the handler's addresses, from their GOT slots."""
    if c.table is not None:
        t, h = img_slots.get(c.table), img_slots.get(c.handler)
        if not isinstance(t, int) or not isinstance(h, int):
            raise Unrecognized("handler table not through the GOT")
        c.table, c.handler = t, h


def call_name(c: Call) -> str:
    return f"Unk_{c.addr:x}"


def arg_type(a: CallArg) -> str:
    if a.kind == "scalar":
        return f"const {SCALAR[a.size]}&"
    if a.kind == "vector":
        elem = SCALAR[a.size] if a.callee is None else (
            KNOWN_OUT[a.callee][0] if a.callee in KNOWN_OUT else struct_name(a.callee))
        return f"const nn::nex::qVector<{elem}>&"
    if a.kind == "result":
        return "void*"
    if a.callee in KNOWN_OUT:
        return f"const {KNOWN_OUT[a.callee][0]}&"
    return f"const {struct_name(a.callee)}&"


def call_params(c: Call) -> list[tuple[str, CallArg]]:
    """(name, arg) in register order."""
    by = {a.reg: a for a in c.args}
    regs = sorted(by, key=lambda r: int(r[1:]))
    if regs != ARG_REGS[:len(regs)]:
        raise Unrecognized("arguments not x2... in order")
    return [(f"arg{k + 2}", by[r]) for k, r in enumerate(regs)]


def render_call(c: Call, handler_names: dict[int, str]) -> str:
    params = call_params(c)
    sig = ", ".join(["nn::nex::ClientProtocol* self", "nn::nex::ProtocolCallContext* ctx"]
                    + [f"{arg_type(a)} {n}" for n, a in params])
    body = []
    for n, a in params:
        if a.kind == "result":
            continue
        if a.kind == "scalar":
            body.append(f"msg.Write({n});")
        elif a.kind == "vector" and a.callee is None:
            body.append(f"WriteContainer(&msg, {n});")
        elif a.kind == "vector":
            body.append(f"WriteContainer(&msg, {n}, {func_name(a.callee, False)});")
        else:
            fn = func_name(a.callee, False)
            body.append(f"{fn}(&msg, {n});")
        body.append("if (msg.m_error) {")
        # the result is passed by value (indirectly: a temporary clang 7 gives no lifetime,
        # so each one keeps its own stack slot)
        body.append("    Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));")
        body.append("    return true;")
        body.append("}")
    results = [n for n, a in params if a.kind == "result"]
    if results:
        body.append("if (ctx != nullptr) {")
        body += [f"    Unk_1630ac0(ctx, {n});" for n in results]
        body.append("}")
    if c.table is not None:
        body.append(f"Unk_{c.table:x}.m_handlers[{c.slot}] = {handler_names[c.handler]};")
    inner = "\n".join("        " + x for x in body)
    return f"""// {c.addr + BASE:#x}
bool {call_name(c)}({sig}) {{
    nn::nex::Message msg;
    {{
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {{
            return false;
        }}
        msg.Unk_1630a90({c.method:#x});
{inner}
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {{
            return Unk_162f1a0(self, ctx, &msg);
        }}
    }}
    return Unk_162f1a0(self, ctx, &msg);
}}
"""


CALLS_HEADER = """// Scope: common
// NEX 4.6.8's protocol clients' calls (tools/nexddl.py calls): each builds a
// Message (the protocol's and the method's IDs, then the inputs), registers
// where the results go and the method's result handler, and sends it. The
// functions and their parameters are placeholders: nothing names them.
#include <nn/nex/Call.h>
#include "Streams.h"
"""


# A result handler's parameters when its name gives them: the results' stream
# and the call's context. The protocol's table holds `void (*)()`, so such a
# handler is stored through a cast (no code of its own).
HANDLER_PARAMS = "PN2nn3nex10ByteStreamEPNS0_19ProtocolCallContextE"


def handler_decl(addr: int, name: str | None) -> tuple[str, str] | None:
    """(declaration, C++ expression stored in the table) of a result handler:
    `void Unk_<addr>()` unless it already has a name, which must then be a
    function without parameters or with the stream and the context."""
    if name is None:
        n = f"Unk_{addr:x}"
        return f"void {n}();", n
    mm = re.fullmatch(r"_Z(\d+)(\w+)v", name)
    if mm and len(mm.group(2)) == int(mm.group(1)):
        return f"void {mm.group(2)}();", mm.group(2)
    mm = re.fullmatch(r"_Z(\d+)(\w+)", name)
    if mm and mm.group(2).endswith(HANDLER_PARAMS):
        ident = mm.group(2)[:int(mm.group(1))]
        if mm.group(2) == ident + HANDLER_PARAMS and ident.isidentifier():
            return (f"void {ident}(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);",
                    f"reinterpret_cast<void (*)()>({ident})")
    return None


def render_calls(calls: list[Call], names: dict[int, str], streams: set[int]) -> str:
    """The calls; `streams` are the stream functions Streams.h declares (and
    defines the structs of)."""
    out = [CALLS_HEADER]
    decls = set()
    handler_names = {}
    for c in calls:
        for a in c.args:
            if a.kind in ("write", "vector") and a.callee is not None and a.callee not in KNOWN_OUT \
                    and a.callee not in streams:
                st = struct_name(a.callee)
                body = f" {{\n    u8 _0[{a.size:#x}];\n}}" if a.kind == "vector" else ""
                decls.add(f"struct {st}{body};\n"
                          f"void {func_name(a.callee, False)}(nn::nex::ByteStream* s, const {st}& v);")
        if c.table is not None:
            d, n = handler_decl(c.handler, names.get(c.handler))
            decls.add(d)
            handler_names[c.handler] = n
    tables = sorted({c.table for c in calls if c.table is not None})
    out += sorted(decls)
    out.append("")
    out += [f"extern Unk_Handlers Unk_{t:x};" for t in tables]
    out.append("")
    out += [render_call(c, handler_names) for c in calls]
    return "\n".join(out)


def call_mangled(c: Call) -> str:
    n = call_name(c)
    parts = ["PN2nn3nex14ClientProtocolE", "PNS0_19ProtocolCallContextE"]
    for _, a in call_params(c):
        if a.kind == "result":
            parts.append("Pv")
        elif a.kind == "scalar":
            parts.append("RK" + {1: "h", 2: "t", 4: "j", 8: "m"}[a.size])
        elif a.callee in KNOWN_OUT:
            parts.append("RK" + KNOWN_OUT[a.callee][2])
        else:
            s = struct_name(a.callee)
            parts.append(f"RK{len(s)}{s}")
    return f"_Z{len(n)}{n}" + "".join(parts)


# --------------------------------------------------------------------------- CLI
def load_specs(lo: int = NEX_LO, hi: int = NEX_HI, verbose: bool = False) -> dict[int, StreamOut]:
    from common import load_module, read_functions_csv
    img = load_module("sword")["image"]
    specs = {}
    why: dict[str, int] = {}
    for f in read_functions_csv():
        if f.sword is None or not lo <= f.sword < hi:
            continue
        if f.status == "O" and not (f.name or "").startswith("_Z"):
            continue
        a, n = f.sword, f.size("sword")
        errs = []
        for reader in (stream_out, stream_in):
            try:
                specs[a] = reader(img[a:a + n], a)
                break
            except Unrecognized as e:
                errs.append(str(e))
        else:
            k = " / ".join(e.split(" at ")[0] for e in errs)
            why[k] = why.get(k, 0) + 1
            if verbose and "no header flag / no version reset" not in k:
                print(f"  {a + BASE:#x}: {'; '.join(errs)}", file=sys.stderr)
    if verbose:
        print("refused:", why, file=sys.stderr)
    return specs


def cmd_streams(args) -> int:
    from common import read_functions_csv
    specs = load_specs(verbose=args.verbose)
    if args.only:
        keep = {int(x, 16) - BASE for x in args.only.split(",")}
        specs = {a: s for a, s in specs.items() if a in keep}
    drop = set() if args.all else set(NOT_MATCHING)
    if args.skip:
        drop |= {int(x, 16) - BASE for x in args.skip.split(",")}
    specs = {a: s for a, s in specs.items() if a not in drop}
    if not args.write:
        for a, s in sorted(specs.items()):
            print(f"{a + BASE:#x} {'R' if s.read else 'W'} {s.size:5}  " + " ".join(
                f"{f.kind[0]}{f.size or ''}@{f.offset:#x}" + (f":{f.callee + BASE:#x}" if f.callee is not None else "")
                for f in s.fields))
        print(f"{len(specs)} functions, {sum(s.size for s in specs.values())} bytes", file=sys.stderr)
        return 0
    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    out = Path(args.write)
    out.parent.mkdir(parents=True, exist_ok=True)
    header, source = render_file(specs)
    out.with_suffix(".h").write_text(header, encoding="utf-8", newline="\n")
    out.write_text(source, encoding="utf-8", newline="\n")
    if args.names:
        import csv
        fs = {(a, s.read) for a, s in specs.items()} | set(Layouts(specs).opaque())
        fs |= {(a, a in KNOWN_IN) for a in KNOWN_TYPES}
        with open(args.names, "w", newline="") as fh:
            w = csv.writer(fh, lineterminator="\n")
            w.writerow(("Name", "Sword", "Shield"))
            for a, read in sorted(fs):
                r = rows[a]
                w.writerow((mangled_name(a, read), f"{a + BASE:#x}",
                            f"{r.shield + BASE:#x}" if r.shield is not None else ""))
    print(f"wrote {len(specs)} functions to {out}", file=sys.stderr)
    return 0


# Calls the template recognizes but that aren't written: 0x710157a020 has a
# different body; 0x71015b4fa0, 0x71015b5210 and 0x71015b5480 already have names,
# as callees of lib/nx_middleware/leaf functions (which call them with other
# arguments).
CALLS_NOT_MATCHING = {0x157A020, 0x15B4FA0, 0x15B5210, 0x15B5480}


def load_calls(verbose: bool = False) -> tuple[list[Call], dict[int, str]]:
    from common import load_module, nso_path, read_functions_csv
    from nx.module import DynInfo
    from nx.nso import Nso
    mod = load_module("sword")
    img = mod["image"]
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), img, mod["text_end"])
    rows = [f for f in read_functions_csv() if f.sword is not None]
    names = {f.sword: f.name for f in rows if f.name}
    out, why = [], {}
    for f in rows:
        if not NEX_LO <= f.sword < NEX_HI or f.status == "O" and not (f.name or "").startswith("_Z11Unk_"):
            continue
        a, n = f.sword, f.size("sword")
        try:
            c = protocol_call(img[a:a + n], a)
            resolve_got(dyn.slots, c)
            call_params(c)
            if c.table is not None and handler_decl(c.handler, names.get(c.handler)) is None:
                raise Unrecognized("handler with parameters")
            out.append(c)
        except Unrecognized as e:
            k = str(e).split(" at ")[0]
            why[k] = why.get(k, 0) + 1
            if verbose and k != "no message":
                print(f"  {a + BASE:#x}: {e}", file=sys.stderr)
    if verbose:
        print("refused:", why, file=sys.stderr)
    return out, names


def cmd_calls(args) -> int:
    calls, names = load_calls(args.verbose)
    if args.only:
        keep = {int(x, 16) - BASE for x in args.only.split(",")}
        calls = [c for c in calls if c.addr in keep]
    if not args.all:
        calls = [c for c in calls if c.addr not in CALLS_NOT_MATCHING]
    if not args.write:
        for c in calls:
            print(f"{c.addr + BASE:#x} {c.size:5} method {c.method:#x}  " + " ".join(
                f"{a.reg}:{a.kind}{a.size or ''}" + (f":{a.callee + BASE:#x}" if a.callee is not None else "")
                for a in c.args) + (f"  handler {c.handler + BASE:#x}" if c.handler is not None else ""))
        print(f"{len(calls)} functions, {sum(c.size for c in calls)} bytes", file=sys.stderr)
        return 0
    streams = {a for a, s in load_specs().items() if not s.read and a not in NOT_MATCHING}
    Path(args.write).write_text(render_calls(calls, names, streams), encoding="utf-8", newline="\n")
    print(f"wrote {len(calls)} functions to {args.write}", file=sys.stderr)
    return 0


_PLACEHOLDER = re.compile(r"_Z(\d+)(Unk_[0-9a-f]+\w*)")


def names_from_objects(paths: list[str]) -> dict[int, str]:
    """Sword address (relative) -> mangled name of each placeholder function
    `Unk_<addr>`, `Unk_<addr>_write` or `Unk_<addr>_read` the objects define."""
    import elfobj
    out = {}
    for p in paths:
        e = elfobj.parse(Path(p).read_bytes())
        for s in e.symbols:
            mm = _PLACEHOLDER.match(s.name)
            if not mm or s.type != "STT_FUNC" or isinstance(s.shndx, str) or len(mm.group(2)) < int(mm.group(1)):
                continue
            base = mm.group(2)[:int(mm.group(1))]
            am = re.fullmatch(r"Unk_([0-9a-f]+)(_write|_read)?", base)
            if am:
                out[int(am.group(1), 16)] = s.name
    return out


def cmd_names(args) -> int:
    import csv
    from common import read_functions_csv
    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    w = csv.writer(sys.stdout, lineterminator="\n")
    w.writerow(("Name", "Sword", "Shield"))
    for a, n in sorted(names_from_objects(args.objects).items()):
        r = rows.get(a)
        if r is not None:
            w.writerow((n, f"{a + BASE:#x}", f"{r.shield + BASE:#x}" if r.shield is not None else ""))
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("streams", help="the stream functions")
    p.add_argument("--write", help="write the C++ to this file")
    p.add_argument("--names", help="write a Name,Sword,Shield CSV for tools/funcs.py name --from-file")
    p.add_argument("--only", help="comma-separated addresses")
    p.add_argument("--skip", help="comma-separated addresses to leave out")
    p.add_argument("--all", action="store_true", help="also the functions known not to match (NOT_MATCHING)")
    p.add_argument("-v", "--verbose", action="store_true")
    p.set_defaults(func=cmd_streams)
    p = sub.add_parser("calls", help="the protocol clients' calls")
    p.add_argument("--write", help="write the C++ to this file")
    p.add_argument("--only", help="comma-separated addresses")
    p.add_argument("--all", action="store_true", help="also the functions known not to match (CALLS_NOT_MATCHING)")
    p.add_argument("-v", "--verbose", action="store_true")
    p.set_defaults(func=cmd_calls)
    p = sub.add_parser("names", help="a Name,Sword,Shield CSV of the placeholder functions objects define")
    p.add_argument("objects", nargs="+")
    p.set_defaults(func=cmd_names)
    args = ap.parse_args()
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
