#!/usr/bin/env python3
"""Static initialisers that only store constants, written as functions.

    python tools/initgen.py census                       # the candidates, and why some aren't written
    python tools/initgen.py write --names n.csv          # src/unsorted/init, and the names to give
    python tools/initgen.py write --names n.csv --all    # a trial: every candidate
    python tools/initgen.py write --names n.csv --only add.txt --order split

A TU's static initialiser stores what its globals' constructors computed. For
many it is constants only: the three addresses an nn::ldn header makes with
`nn::ldn::MakeIpv4Address` (tools/leafgen.py writes the initialisers that do
nothing else, docs/game_code.md "Batch 33"), then numbers, vectors of four
floats, tables of hashed names (a hash, the string and its length), and a
destructor registered with `__cxa_atexit`. clang merges the TU's statics
into one object and addresses them from one register, so the function is
written the way leafgen writes them: a placeholder struct at the address the
code uses, `extern` with hidden visibility (reached without the GOT), and
one statement a store.

A candidate is a function with no branch but calls of `MakeIpv4Address` and a
final `ret` or `b __cxa_atexit`, that only

- loads constants (`mov`/`movk`, `ldr q/d/s` from the literal pool), addresses
  (`adrp` + `add`) and pointers from the GOT (`adrp` + `ldr`),
- stores them through such an address (`str`, `stur`, `strh`, `strb`, `stp`).

What is stored decides a field: an integer of the store's width, a pointer
(a string literal when it points at one in `.rodata`, else an `extern`
placeholder), a float, or four floats stored together (`Unk_Init_Vec4::Set`,
a NEON store: four `float` stores would be merged into two integer ones). A
struct starts at the address aligned as its fields need, since the register
may point into the middle of the merged object.

The stores between two calls don't depend on each other, so the compiler
orders them by what its instruction selection and scheduler make of the
order of the statements. That order isn't known, so a few are tried
(`--order`), and a file records the one it was written in (a comment) and is
written again with it:

- `asm`: the stores as the original has them.
- `split`: the stores of integers and pointers as the original has them,
  then the vectors by address.
- `delay`: the original's order, but each store of an integer or a pointer
  after the next vector's (a vector's constant is loaded ahead of its store,
  and the store of the statement before it lands in between).
- `address`: every store by address (a table of entries, written in order).
- `wide`: the stores narrower than 8 bytes as the original has them (the
  header's statics), then the others by address.

Each function is a file of its own (`src/unsorted/init/Unk_<address>.cpp`):
two initialisers lay different fields over neighbouring statics. A row is
kept (written again) when its name is the one written for it and check.py
matched it; `--only` adds addresses, `--all` writes every candidate.
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

OUT_DIR = ROOT / "src" / "unsorted" / "init"
LDN = "_ZN2nn3ldn15MakeIpv4AddressEhhhh"
ATEXIT = 0x1C0              # __cxa_atexit, in functions.csv
DSO = 0x236D000             # __dso_handle, in data_symbols.csv
ORDERS = ("asm", "split", "delay", "address", "wide")
ORDER_LINE = re.compile(r"^// Order: (\w+)$", re.M)
SIMPLE_FUNCTION = re.compile(r"^_Z(\d+)(\w+?)(Pv|v)$")


class Refuse(Exception):
    """Why a function isn't one this tool writes."""


@dataclass(frozen=True)
class Const:
    value: int


@dataclass(frozen=True)
class Ret:
    index: int          # the result of the index-th call


@dataclass(frozen=True)
class Addr:
    addr: int
    got: bool = False   # loaded from the GOT
    root: int = 0       # the address the register was first given (the object's)


@dataclass(frozen=True)
class Vec:
    words: tuple        # four 32-bit words


@dataclass(frozen=True)
class Fp:
    bits: int
    width: int          # 4 or 8


@dataclass(frozen=True)
class Page:
    page: int


@dataclass(frozen=True)
class Store:
    root: int           # the object's address (what the register was first given)
    got: bool
    off: int            # from the root
    width: int
    value: object


@dataclass(frozen=True)
class Call:
    index: int
    args: tuple


@dataclass
class Init:
    addr: int
    events: list = field(default_factory=list)      # Store and Call, in the original's order
    atexit: tuple | None = None                     # (function, object): Addr, and Addr or Const(0)


def _fp_reg(op: str) -> tuple[int, int] | None:
    """(number, width in bytes) of a q, d or s register operand."""
    if len(op) > 1 and op[0] in "qds" and op[1:].isdigit():
        return int(op[1:]), {"q": 16, "d": 8, "s": 4}[op[0]]
    return None


def parse(m, a: int, plt: dict) -> Init:
    """The stores and calls of the function at `a`; raises Refuse."""
    import familygen as F

    size = m.rows[a].sword_size
    try:
        insns = F.disassemble(m, a, size)
    except F.WalkError as e:
        raise Refuse(str(e)) from None
    regs: dict = {}
    fregs: dict = {}
    out = Init(a)
    calls = 0

    def value(op: str):
        r = F._reg(op)
        if r is None:
            raise Refuse(f"operand {op}")
        n, width = r
        if n == F.XZR:
            return Const(0), width
        if n not in regs:
            raise Refuse(f"{op} isn't set")
        return regs[n], width

    for pc, mn, ops in insns:
        last = pc == a + size - 4
        mem = next((F._mem(ops, i) for i, o in enumerate(ops) if o.startswith("[")), None)
        if mem is not None and mem[0] == F.SP:
            if mn in ("ldp", "ldr"):
                for o in ops[:2 if mn == "ldp" else 1]:
                    r = F._reg(o)
                    if r is None or r[0] < 19:
                        raise Refuse("a load from the stack")
                    regs.pop(r[0], None)
                continue
            if mn in ("stp", "str"):
                continue
            raise Refuse(f"{mn} on the stack")
        if mn in ("add", "sub") and ops[0] in ("x29", "fp", "sp"):
            continue
        if mn == "ret":
            if not last:
                raise Refuse("a return before the end")
            break
        if mn == "mov":
            dst = F._reg(ops[0])
            if dst is None or dst[0] in (F.XZR, F.SP):
                raise Refuse(f"mov to {ops[0]}")
            if ops[1].startswith("#"):
                regs[dst[0]] = Const(F._imm(ops[1]) & ((1 << (8 * dst[1])) - 1))
            else:
                regs[dst[0]] = value(ops[1])[0]
            continue
        if mn == "movk":
            dst = F._reg(ops[0])
            cur = regs.get(dst[0]) if dst else None
            if not isinstance(cur, Const):
                raise Refuse("movk of what isn't a constant")
            shift = int(ops[2].split("#")[1], 0) if len(ops) > 2 else 0
            v = (cur.value & ~(0xFFFF << shift)) | (F._imm(ops[1]) << shift)
            regs[dst[0]] = Const(v & ((1 << (8 * dst[1])) - 1))
            continue
        if mn == "adrp":
            regs[F._reg(ops[0])[0]] = Page(F._imm(ops[1]))
            continue
        if mn == "add" and len(ops) == 3 and ops[2].startswith("#"):
            dst, src = F._reg(ops[0]), F._reg(ops[1])
            cur = regs.get(src[0]) if src else None
            if isinstance(cur, Page):
                t = cur.page + F._imm(ops[2])
                regs[dst[0]] = Addr(t, False, t)
            elif isinstance(cur, Addr):
                regs[dst[0]] = Addr(cur.addr + F._imm(ops[2]), cur.got, cur.root)
            else:
                raise Refuse("add to what isn't an address")
            continue
        if mn == "ldr" and mem is not None and mem[2] == "":
            cur = regs.get(mem[0])
            if not isinstance(cur, Page):
                raise Refuse("a load through a pointer")
            t = cur.page + mem[1]
            fp = _fp_reg(ops[0])
            if fp is not None:
                if fp[1] == 16:
                    fregs[fp[0]] = Vec(struct.unpack_from("<4I", m.img, t))
                else:
                    bits = struct.unpack_from("<Q" if fp[1] == 8 else "<I", m.img, t)[0]
                    fregs[fp[0]] = Fp(bits, fp[1])
                continue
            dst = F._reg(ops[0])
            target = m.slots.get(t)
            if dst is None or dst[1] != 8 or not isinstance(target, int):
                raise Refuse("a load of data that isn't a GOT slot")
            regs[dst[0]] = Addr(target, True, target)
            continue
        if mn in ("str", "stur", "strh", "sturh", "strb", "sturb", "stp") and mem is not None and mem[2] == "":
            base = regs.get(mem[0])
            if not isinstance(base, Addr):
                raise Refuse("a store through what isn't an address")
            off = base.addr - base.root + mem[1]
            for o in ops[:2 if mn == "stp" else 1]:
                fp = _fp_reg(o)
                if fp is not None:
                    if fp[0] not in fregs:
                        raise Refuse(f"{o} isn't set")
                    v, width = fregs[fp[0]], fp[1]
                else:
                    v, width = value(o)
                    width = {"strh": 2, "sturh": 2, "strb": 1, "sturb": 1}.get(mn, width)
                    if isinstance(v, Const):
                        v = Const(v.value & ((1 << (8 * width)) - 1))
                    elif isinstance(v, Ret) and width != 4 or isinstance(v, Addr) and width != 8:
                        raise Refuse("a value stored in part")
                    elif isinstance(v, Page):
                        raise Refuse("a page stored")
                out.events.append(Store(base.root, base.got, off, width, v))
                off += width
            continue
        if mn == "bl":
            if plt.get(F._imm(ops[0])) != LDN:
                raise Refuse("a call")
            args = []
            for n in range(4):
                if not isinstance(regs.get(n), Const):
                    raise Refuse("an argument that isn't a constant")
                args.append(regs[n].value & 0xFF)
            for n in range(19):
                regs.pop(n, None)
            fregs.clear()
            regs[0] = Ret(calls)
            out.events.append(Call(calls, tuple(args)))
            calls += 1
            continue
        if mn == "b" and last:
            if F._imm(ops[0]) != ATEXIT:
                raise Refuse("a tail call")
            fn, obj, dso = regs.get(0), regs.get(1), regs.get(2)
            if not isinstance(fn, Addr) or not isinstance(dso, Addr) or dso.addr != DSO:
                raise Refuse("__cxa_atexit's arguments")
            if not (isinstance(obj, Addr) or obj == Const(0)):
                raise Refuse("__cxa_atexit's object")
            out.atexit = (fn, obj)
            break
        raise Refuse(mn)
    else:
        raise Refuse("no return")
    if not any(isinstance(e, Store) for e in out.events):
        raise Refuse("no store")
    return out


# ------------------------------------------------------------------------- the source

def f32_literal(bits: int) -> str:
    """A float literal that reads back as these bits."""
    if bits == 0:
        return "0"
    exp = (bits >> 23) & 0xFF
    if exp == 0xFF or exp == 0:
        raise Refuse("a float that isn't a number of normal size")
    v = struct.unpack("<f", struct.pack("<I", bits))[0]
    for p in range(1, 10):
        s = f"{v:.{p}g}"
        if struct.pack("<f", float(s)) == struct.pack("<I", bits):
            break
    else:
        raise Refuse("a float no literal gives")
    if "e" not in s and "." not in s:
        s += ".0"
    return s + "f"


def f64_literal(bits: int) -> str:
    if bits == 0:
        return "0"
    exp = (bits >> 52) & 0x7FF
    if exp == 0x7FF or exp == 0:
        raise Refuse("a double that isn't a number of normal size")
    s = repr(struct.unpack("<d", struct.pack("<Q", bits))[0])
    return s if ("e" in s or "." in s) else s + ".0"


def int_literal(v: int) -> str:
    return str(v) if v < 10 else f"0x{v:x}"


def c_string(m, a: int, rodata: tuple[int, int]) -> str | None:
    """The string literal at `a` in .rodata, or None when there's no printable string there."""
    if not rodata[0] <= a < rodata[1]:
        return None
    end = m.img.find(b"\0", a, a + 512)
    if end < 0:
        return None
    raw = m.img[a:end]
    if any(c < 0x20 or c > 0x7E for c in raw):
        return None
    text = raw.decode("ascii").replace("\\", "\\\\").replace('"', '\\"')
    return '"' + text.replace("??", "?\\?") + '"'


VEC4 = """// Four floats stored together.
struct Unk_Init_Vec4 {
    void Set(f32 x, f32 y, f32 z, f32 w) {
        float32x4_t value = {x, y, z, w};
        vst1q_f32(v, value);
    }

    f32 v[4];
};
"""

KIND_TYPE = {("int", 1): "u8", ("int", 2): "u16", ("int", 4): "u32", ("int", 8): "u64", ("f", 4): "f32",
             ("f", 8): "f64", ("vec", 16): "Unk_Init_Vec4"}
KIND_ALIGN = {"vec": 4}


@dataclass
class Source:
    text: str
    names: dict             # address -> the mangled name to give it


def ordered(run: list, order: str) -> list:
    """The stores between two calls, in the order their statements are written in."""
    if order == "split":
        vecs = [e for e in run if isinstance(e.value, Vec)]
        rest = [e for e in run if not isinstance(e.value, Vec)]
        return rest + sorted(vecs, key=lambda e: (e.root, e.off))
    if order == "delay":
        out, held = [], []
        for e in run:
            if isinstance(e.value, Vec):
                out.append(e)
                out.extend(held)
                held = []
            else:
                held.append(e)
        return out + held
    if order == "address":
        return sorted(run, key=lambda e: (e.root, e.off))
    if order == "wide":
        narrow = [e for e in run if e.width < 8]
        return narrow + sorted((e for e in run if e.width >= 8), key=lambda e: (e.root, e.off))
    return list(run)


def function_name(a: int) -> str:
    stem = f"Unk_{a:x}_init"
    return f"_Z{len(stem)}{stem}v"


def emit(m, init: Init, order: str, rodata: tuple[int, int]) -> Source:
    """The file of one initialiser; raises Refuse."""
    names = {init.addr: function_name(init.addr)}
    externs: dict[str, str] = {}        # declaration by symbol
    has_vec = False

    def data_symbol(a: int, got: bool, const: bool) -> str:
        """An address that isn't a field of the structs: an extern placeholder."""
        known = m.data_names.get(a)
        sym = f"Unk_{a:x}"
        if known is not None and known != sym:
            raise Refuse("data with a name of its own")
        if a in m.rows:
            raise Refuse("a function's address stored")
        hidden = "" if got else ' __attribute__((visibility("hidden")))'
        externs[sym] = f"extern {'const ' if const else ''}u8 {sym}[]{hidden};"
        return sym

    # the objects: fields by offset from the root
    objects: dict[tuple[int, bool], dict[int, tuple[str, int, str]]] = {}
    for e in init.events:
        if not isinstance(e, Store):
            continue
        v = e.value
        if isinstance(v, Vec):
            kind, ctype, has_vec = "vec", "Unk_Init_Vec4", True
        elif isinstance(v, Fp):
            kind, ctype = "f", KIND_TYPE[("f", e.width)]
        elif isinstance(v, Addr):
            kind = "ptr"
            ctype = "const char*" if c_string(m, v.addr, rodata) is not None else (
                "const u8*" if rodata[0] <= v.addr < rodata[1] else "u8*")
        else:
            kind, ctype = "int", KIND_TYPE[("int", e.width)]
        fields = objects.setdefault((e.root, e.got), {})
        new = (kind, e.width, ctype)
        if fields.setdefault(e.off, new) != new:
            raise Refuse("a field stored two ways")
    structs, symbols = [], {}
    for (root, got), fields in sorted(objects.items()):
        align = max(KIND_ALIGN.get(k, w) for k, w, _ in fields.values())
        if got and root % align:
            raise Refuse("a field that isn't aligned")
        sym_addr = root & ~(align - 1)
        delta = root - sym_addr
        known = m.data_names.get(sym_addr)
        sym = f"Unk_{sym_addr:x}"
        if known is not None and known != sym:
            raise Refuse("data with a name of its own")
        lines, asserts, at = [f"struct {sym}_Data {{"], [], 0
        for off in sorted(fields):
            kind, width, ctype = fields[off]
            pos = delta + off
            if pos < at:
                raise Refuse("fields that overlap")
            if (sym_addr + pos) % KIND_ALIGN.get(kind, width):
                raise Refuse("a field that isn't aligned")
            if pos > at:
                lines.append(f"    u8 _{at:x}[0x{pos - at:x}];")
            lines.append(f"    {ctype} field_{pos:x};")
            asserts.append(f"PKMN_OFFSET_ASSERT({sym}_Data, field_{pos:x}, 0x{pos:x});")
            at = pos + width
        structs.append("\n".join(lines + ["};"] + asserts))
        hidden = "" if got else ' __attribute__((visibility("hidden")))'
        structs.append(f"extern {sym}_Data {sym}{hidden};")
        symbols[(root, got)] = (sym, delta)

    def field_of(v: Addr) -> str | None:
        """`&object.field` (or `&object`) for an address in one of the structs."""
        for (root, got), fields in objects.items():
            if got != v.got:
                continue
            sym, delta = symbols[(root, got)]
            if (v.addr - root) in fields:
                return f"&{sym}.field_{delta + v.addr - root:x}"
            if v.addr == root - delta:
                return f"&{sym}"
        return None

    def statement(e) -> str:
        if isinstance(e, Call):
            return (f"    u32 r{e.index} = nn::ldn::MakeIpv4Address("
                    f"{', '.join(int_literal(x) for x in e.args)});")
        sym, delta = symbols[(e.root, e.got)]
        target = f"{sym}.field_{delta + e.off:x}"
        v = e.value
        if isinstance(v, Vec):
            return f"    {target}.Set({', '.join(f32_literal(w) for w in v.words)});"
        if isinstance(v, Fp):
            return f"    {target} = {f32_literal(v.bits) if v.width == 4 else f64_literal(v.bits)};"
        if isinstance(v, Ret):
            return f"    {target} = r{v.index};"
        if isinstance(v, Addr):
            text = c_string(m, v.addr, rodata)
            if text is None:
                inner = field_of(v)
                text = (f"reinterpret_cast<u8*>({inner})" if inner is not None
                        else data_symbol(v.addr, v.got, rodata[0] <= v.addr < rodata[1]))
            return f"    {target} = {text};"
        return f"    {target} = {int_literal(v.value)};"

    # the statements: the stores between two calls in the order asked for
    body, run = [], []

    def flush() -> None:
        body.extend(statement(e) for e in ordered(run, order))
        run.clear()

    for e in init.events:
        if isinstance(e, Call):
            flush()
            body.append(statement(e))
        else:
            run.append(e)
    flush()
    declarations = []
    if any(isinstance(e, Call) for e in init.events):
        declarations.append("namespace nn {\nnamespace ldn {\nu64 MakeIpv4Address(u8, u8, u8, u8);\n}\n}  // namespace nn")
    if init.atexit is not None:
        fn, obj = init.atexit
        row = m.rows.get(fn.addr)
        if row is None:
            raise Refuse("__cxa_atexit's function isn't one")
        hidden = "" if fn.got else ' __attribute__((visibility("hidden")))'
        if not row.name:
            stem = f"Unk_{fn.addr:x}"
            names[fn.addr] = f"_Z{len(stem)}{stem}Pv"
            params = "void*"
        else:
            g = SIMPLE_FUNCTION.match(row.name)
            if not g or int(g.group(1)) != len(g.group(2)):
                raise Refuse("__cxa_atexit's function has a name that isn't a plain function's")
            stem, params = g.group(2), "void*" if g.group(3) == "Pv" else ""
        declarations.append(f"void {stem}({params}){hidden};")
        fn_text = stem if params else f"reinterpret_cast<void (*)(void*)>({stem})"
        if isinstance(obj, Const):
            obj_text = "nullptr"
        else:
            obj_text = field_of(obj) or data_symbol(obj.addr, obj.got, False)
        declarations.append('extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);\n'
                            'extern "C" void* __dso_handle __attribute__((visibility("hidden")));')
        body.append(f"    __cxa_atexit({fn_text}, {obj_text}, &__dso_handle);")
    head = ["// Scope: common",
            "// A static initialiser, as a function: the statics it sets are one placeholder struct",
            "// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.",
            f"// Order: {order}"]
    if has_vec:
        head.append("#include <arm_neon.h>\n")
    head.append("#include <types.h>\n")
    parts = head + ([VEC4] if has_vec else []) + [s + "\n" for s in structs]
    parts += sorted(externs.values()) + declarations
    parts += ["", f"// 0x{init.addr + BASE:x}", f"void Unk_{init.addr:x}_init() {{"] + body + ["}", ""]
    return Source("\n".join(parts), names)


# ------------------------------------------------------------------------- the plan

def is_candidate(m, a: int, plt: dict) -> bool:
    """A function without a conditional branch that calls MakeIpv4Address or ends in `b __cxa_atexit`."""
    r = m.rows[a]
    if not r.sword_size or r.sword_size < 16:
        return False
    ws = struct.unpack_from(f"<{r.sword_size // 4}I", m.img, a)
    ldn = tail = False
    for i, w in enumerate(ws):
        if (w & 0xFF000010) == 0x54000000 or (w & 0x7E000000) in (0x34000000, 0x36000000):
            return False
        if (w & 0xFC000000) == 0x94000000:
            d = w & 0x3FFFFFF
            ldn |= plt.get(a + 4 * i + ((d - (1 << 26)) if d & (1 << 25) else d) * 4) == LDN
    last = ws[-1]
    if (last & 0xFC000000) == 0x14000000:
        d = last & 0x3FFFFFF
        tail = a + 4 * (len(ws) - 1) + ((d - (1 << 26)) if d & (1 << 25) else d) * 4 == ATEXIT
    return ldn or tail


def existing_orders() -> dict[int, str]:
    out = {}
    for p in OUT_DIR.glob("Unk_*.cpp"):
        g = ORDER_LINE.search(p.read_text(encoding="utf-8"))
        if g and g.group(1) in ORDERS:
            out[int(p.stem[4:], 16)] = g.group(1)
    return out


def plan(m, plt: dict, rodata: tuple[int, int], only: set[int] | None = None, everything: bool = False,
         order: str = "asm", orders: dict[int, str] | None = None):
    """({address: Source}, the candidates, [(address, why not)])."""
    orders = orders or {}
    out, candidates, skipped = {}, [], []
    for a in sorted(m.rows):
        r = m.rows[a]
        mine = r.name == function_name(a)
        if r.status not in "UO" or (r.status == "O" and not mine) or (r.name and not mine):
            continue
        if not is_candidate(m, a, plt):
            continue
        candidates.append(a)
        try:
            init = parse(m, a, plt)
            # A matched one keeps the order its file was written in; the others are trials of `order`.
            src = emit(m, init, orders.get(a, order) if r.status == "O" else order, rodata)
        except Refuse as e:
            skipped.append((a, str(e)))
            continue
        if everything or (only is not None and a in only) or (r.status == "O" and mine):
            out[a] = src
    return out, candidates, skipped


def environment():
    """(the module, the PLT's names by address, .rodata's range)."""
    import familygen
    from common import load_module, nso_path
    from nx.module import DynInfo
    from nx.nso import Nso

    m = familygen.load()
    mod = load_module("sword")
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), mod["image"], mod["text_end"])
    return m, dyn.plt, tuple(mod["rodata"])


def cmd_census(args) -> None:
    m, plt, rodata = environment()
    out, candidates, skipped = plan(m, plt, rodata, everything=True)
    done = [a for a in candidates if m.rows[a].status == "O"]
    print(f"{len(candidates)} candidates ({sum(m.rows[a].sword_size for a in candidates)} bytes), "
          f"{len(done)} matched ({sum(m.rows[a].sword_size for a in done)} bytes), {len(out)} writable "
          f"({sum(m.rows[a].sword_size for a in out)} bytes)")
    why = Counter(w for _, w in skipped)
    for w, n in why.most_common():
        print(f"  not written: {n:4d} {w}")


def cmd_write(args) -> None:
    from common import clang_format

    m, plt, rodata = environment()
    only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()} if args.only else None
    out, _, _ = plan(m, plt, rodata, only, args.all, args.order, existing_orders())
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for old in OUT_DIR.glob("Unk_*.cpp"):
        old.unlink()
    written = []
    for a, src in out.items():
        path = OUT_DIR / f"Unk_{a:x}.cpp"
        path.write_text(src.text, encoding="utf-8", newline="\n")
        written.append(path)
    if written and not clang_format(written):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        seen = set()
        for src in out.values():
            for a, n in src.names.items():
                if a not in seen:
                    seen.add(a)
                    r = m.rows[a]
                    fh.write(f"{n},{r.sword_str},{r.shield_str}\n")
    print(f"{len(out)} initialisers; their names in {args.names}", file=sys.stderr)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("census")
    w = sub.add_parser("write")
    w.add_argument("--names", type=Path, required=True)
    w.add_argument("--order", choices=ORDERS, default="asm", help="the order of the newly written ones")
    g = w.add_mutually_exclusive_group()
    g.add_argument("--only", type=Path, help="addresses to write besides the kept ones")
    g.add_argument("--all", action="store_true", help="write every candidate (a trial)")
    args = ap.parse_args(argv)
    {"census": cmd_census, "write": cmd_write}[args.cmd](args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
