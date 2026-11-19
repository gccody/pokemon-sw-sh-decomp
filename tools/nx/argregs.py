"""Which argument registers a function takes, as far as its code and its callers show.

Two kinds of evidence, both from the instructions alone:

- **Its own code** (`Params`, `params_of`): the argument registers x0..x7 it
  reads before writing them, on any path, directly or through a copy
  (`mov x19, x1`). A register it passes on untouched to a call or a tail
  call counts when the callee reads it (recursively), so `ldr x0, [x0, #8] ;
  b T` takes x1 too when T reads x1. How it reads one says what it is: the
  base of a load or store is a pointer, a register read only in its 32-bit
  form (`w1`) a 32-bit value. An indirect call (`blr`/`br`) reads what the
  function moved into x0..x7 for it, but not a register it left untouched:
  nothing says the target takes that one.
- **Its callers** (`call_sites`): at each `bl F` / `b F`, the argument
  registers the caller wrote and didn't read again before the branch. With
  `-O3` nothing writes a register for nothing, and x0..x7 don't survive a
  call, so such a value is an argument of F.

The decoding is capstone's text (operands as leafgen.py splits them); only
the general-purpose registers are followed. Floating-point arguments are
not.
"""
from __future__ import annotations

import re
from dataclasses import dataclass, field

_REG = re.compile(r"^([wx])(\d+)$")
_MEM = re.compile(r"\[([^\]]*)\](!?)")
_ATOMIC = re.compile(r"^(?:ld(?:add|clr|eor|set|smax|smin|umax|umin)|swp)(?:a|al|l)?[bh]?$")
_ATOMIC_STORE = re.compile(r"^st(?:add|clr|eor|set|smax|smin|umax|umin)l?[bh]?$")
_CAS = re.compile(r"^casp?(?:a|al|l)?[bh]?$")
_EXCL_STORE = re.compile(r"^stl?x(?:r[bh]?|p)$")
_READ_WRITE = {"movk", "bfi", "bfxil", "bfm", "bfc"}
_ALL_READ = {"cmp", "cmn", "tst", "ccmp", "ccmn", "cbz", "cbnz", "tbz", "tbnz", "br", "blr", "ret", "prfm",
             "prfum", "msr", "dc", "ic", "at", "tlbi", "sys", "hint"}
BRANCHES = {"b", "cbz", "cbnz", "tbz", "tbnz"}
CALL_CLOBBERS = range(19)  # x0..x18 don't survive a call


def reg(op: str) -> tuple[int, int] | None:
    """`x3` -> (3, 8), `w3` -> (3, 4); None for anything else (xzr, sp, vector...)."""
    m = _REG.match(op.strip())
    if m is None or int(m.group(2)) > 30:
        return None
    return int(m.group(2)), 8 if m.group(1) == "x" else 4


def is_load(mn: str) -> bool:
    return mn.startswith(("ldr", "ldur", "ldp", "ldnp", "ldxr", "ldaxr", "ldar", "ldxp", "ldaxp", "ldapr",
                          "ldtr", "ld1", "ld2", "ld3", "ld4")) or mn == "ldtr"


def is_store(mn: str) -> bool:
    return mn.startswith(("str", "stur", "stp", "stnp", "stlr", "sttr", "st1", "st2", "st3", "st4")) \
        and not _EXCL_STORE.match(mn)


def access(mn: str, ops: list[str]) -> tuple[list[tuple[int, int, bool]], list[tuple[int, int]]]:
    """The general-purpose registers an instruction reads, as (n, width,
    whether it's an address base or index), and the ones it writes (n, width).

    Reads come first: an instruction that reads and writes a register (`add
    x1, x1, #8`) reads its old value."""
    reads: list[tuple[int, int, bool]] = []
    writes: list[tuple[int, int]] = []
    plain = []
    for o in ops:
        m = _MEM.fullmatch(o.strip())
        if m:
            parts = [p.strip() for p in m.group(1).split(",")]
            for j, p in enumerate(parts):
                r = reg(p)
                if r is not None:
                    reads.append((*r, j == 0))
            if m.group(2):  # pre-index writeback
                r = reg(parts[0])
                if r is not None:
                    writes.append(r)
            continue
        plain.append(o)
    mem_ops = [o for o in ops if _MEM.fullmatch(o.strip())]
    if mem_ops and len(ops) > ops.index(mem_ops[0]) + 1 and ops[ops.index(mem_ops[0]) + 1].startswith("#"):
        r = reg(_MEM.fullmatch(mem_ops[0].strip()).group(1).split(",")[0])  # post-index writeback
        if r is not None:
            writes.append(r)
    regs = [reg(o) for o in plain]
    if mn in _ALL_READ or mn.startswith("b.") or mn in ("b", "bl") or _ATOMIC_STORE.match(mn) or \
            (is_store(mn) and mem_ops):
        reads += [(*r, False) for r in regs if r is not None]
    elif _EXCL_STORE.match(mn):
        if regs and regs[0] is not None:
            writes.append(regs[0])
        reads += [(*r, False) for r in regs[1:] if r is not None]
    elif _CAS.match(mn):
        reads += [(*r, False) for r in regs if r is not None]
        writes += [r for r in regs[:len(regs) // 2] if r is not None]
    elif _ATOMIC.match(mn):
        if regs and regs[0] is not None:
            reads.append((*regs[0], False))
        writes += [r for r in regs[1:] if r is not None]
    elif is_load(mn) and mem_ops:
        writes += [r for r in regs if r is not None]
    elif regs:
        if mn in _READ_WRITE and regs[0] is not None:
            reads.append((*regs[0], False))
        reads += [(*r, False) for r in regs[1:] if r is not None]
        if regs[0] is not None:
            writes.append(regs[0])
    if mn == "bl" or mn == "blr":
        writes += [(i, 8) for i in CALL_CLOBBERS]
    return reads, writes


def target(ops: list[str]) -> int | None:
    """A direct branch's target (its last operand), absolute."""
    if not ops or not ops[-1].strip().startswith("#"):
        return None
    return int(ops[-1].strip().lstrip("#"), 0)


@dataclass
class Params:
    """What a function's code says about its argument registers x0..x7."""
    uses: dict[int, set[str]] = field(default_factory=dict)  # register -> {"ptr", "w", "x"}
    variadic: bool = False  # saves x7 as it got it on the stack: a `...` function's register save area

    @property
    def count(self) -> int:
        """How many: up to the last register it reads (the ones before it are parameters too)."""
        return max(self.uses, default=-1) + 1

    def kind(self, i: int) -> str | None:
        """`ptr` (an address base), `w` (only its 32 bits read), `x`, or None (not read)."""
        u = self.uses.get(i)
        if not u:
            return None
        return "ptr" if "ptr" in u else "w" if u == {"w"} else "x"


def _blocks(insns: list[tuple[int, str, list[str]]], start: int, end: int) -> dict[int, list[int]]:
    """Instruction index -> successor indices, for the function [start, end)."""
    index = {a: i for i, (a, _, _) in enumerate(insns)}
    succ: dict[int, list[int]] = {}
    for i, (_, mn, ops) in enumerate(insns):
        nxt = [i + 1] if i + 1 < len(insns) else []
        if mn == "ret" or mn == "br":
            succ[i] = []
        elif mn == "b":
            t = target(ops)
            succ[i] = [index[t]] if t is not None and start <= t < end and t in index else []
        elif mn.startswith("b.") or mn in ("cbz", "cbnz", "tbz", "tbnz"):
            t = target(ops)
            succ[i] = nxt + ([index[t]] if t is not None and t in index else [])
        else:
            succ[i] = nxt
    return succ


def analyze(insns: list[tuple[int, str, list[str]]], start: int, end: int, callee=None) -> Params:
    """Params of the function [start, end) whose instructions (absolute
    address, mnemonic, operands) are `insns`. `callee(addr)` gives the Params
    of a function it calls or tail-calls (None when unknown: then the call
    reads nothing)."""
    out = Params()
    if not insns:
        return out
    succ = _blocks(insns, start, end)
    # state: register -> the entry registers (0..7) whose value it holds
    init = {i: frozenset({i}) for i in range(8)}
    states: dict[int, dict[int, frozenset]] = {0: init}
    work = [0]

    spilled: dict[int, set[str]] = {}  # stored to the stack, as it got it

    def use(state: dict, n: int, kind: str, into: dict | None = None) -> None:
        for t in state.get(n, ()):
            (out.uses if into is None else into).setdefault(t, set()).add(kind)

    def call(state: dict, addr: int | None) -> None:
        p = callee(addr) if callee is not None and addr is not None else None
        if p is None:
            return
        for i, kinds in p.uses.items():
            for k in kinds:
                use(state, i, k)

    while work:
        i = work.pop()
        state = dict(states[i])
        a, mn, ops = insns[i]
        reads, writes = access(mn, ops)
        if mn == "mov" and len(ops) == 2 and reg(ops[0]) and reg(ops[1]):
            (d, _), (s, sw) = reg(ops[0]), reg(ops[1])
            if sw == 4:
                use(state, s, "w")
            state[d] = state.get(s, frozenset())
        else:
            stack = is_store(mn) and any(o.strip().startswith(("[sp", "[x29")) for o in ops)
            for n, w, base in reads:
                untouched = state.get(n) == frozenset({n})
                use(state, n, "ptr" if base else "w" if w == 4 else "x",
                    spilled if stack and not base and untouched else None)
            if mn in ("bl", "b") and not (mn == "b" and start <= (target(ops) or start) < end):
                call(state, target(ops))
            if mn in ("blr", "br"):
                for n in range(8):  # what it moved there for the call
                    if any(t != n for t in state.get(n, ())):
                        use(state, n, "x")
            if mn == "ret" and any(t != 0 for t in state.get(0, ())):
                use(state, 0, "x")  # returns an argument it moved into x0
            for n, _ in writes:
                state[n] = frozenset()
        for j in succ.get(i, []):
            old = states.get(j)
            if old is None:
                states[j] = state
                work.append(j)
                continue
            merged = {r: old.get(r, frozenset()) | state.get(r, frozenset()) for r in set(old) | set(state)}
            if merged != old:
                states[j] = merged
                work.append(j)
    if 7 in spilled:
        out.variadic = True  # what it saves of x1..x7 is the `...`, not parameters
    else:
        for t, kinds in spilled.items():
            out.uses.setdefault(t, set()).update(kinds)
    return out


def call_sites(insns: list[tuple[int, str, list[str]]], start: int, end: int,
               wanted: set[int] | None = None) -> dict[int, list[tuple[int, int, dict[int, str]]]]:
    """For the calls (`bl F`, and `b F` out of the function) in [start, end):
    F -> [(call address, arguments: up to the last register the caller wrote
    and didn't read before the call, {register: how its last write looks})].

    A write counts only when it reaches the call on every path, with no
    conditional branch after it: one before a branch may be for the other
    path. How a write looks: `ptr` for an address (`adrp`, `adr`, an `add`
    to one or to `sp`/`x29`), `w` for a 32-bit write, `x` otherwise. Only
    targets in `wanted`, when given."""
    out: dict[int, list] = {}
    if not insns:
        return out
    succ = _blocks(insns, start, end)
    # state: argument register -> how its pending write looks (written, not read since)
    states: dict[int, dict[int, str]] = {0: {}}
    work = [0]
    seen_calls: dict[int, dict[int, str]] = {}
    while work:
        i = work.pop()
        before = states[i]
        state = dict(before)
        a, mn, ops = insns[i]
        reads, writes = access(mn, ops)
        t = target(ops) if mn in ("bl", "b") else None
        if t is not None and (mn == "bl" or not start <= t < end) and (wanted is None or t in wanted):
            seen_calls[a] = dict(state)
        for n, _, _ in reads:
            state.pop(n, None)
        for n, w in writes:
            if n >= 8 or mn in ("bl", "blr"):
                continue
            look = "w" if w == 4 else "x"
            src = reg(ops[1]) if len(ops) >= 2 else None
            if mn in ("adrp", "adr") or (mn in ("add", "sub") and len(ops) >= 2 and (
                    ops[1].strip() in ("sp", "x29") or (src is not None and before.get(src[0]) == "ptr"))):
                look = "ptr"
            state[n] = look
        if mn in ("bl", "blr") or mn.startswith("b.") or mn in ("cbz", "cbnz", "tbz", "tbnz"):
            state = {}
        for j in succ.get(i, []):
            old = states.get(j)
            if old is None:
                states[j] = state
                work.append(j)
                continue
            merged = {r: v if old[r] == v else "x" for r, v in state.items() if r in old}
            if merged != old:
                states[j] = merged
                work.append(j)
    for a, _, ops in insns:
        if a in seen_calls:
            regs = seen_calls[a]
            out.setdefault(target(ops), []).append((a, max(regs, default=-1) + 1, regs))
    return out


def decode(img: bytes, start: int, size: int, base: int = 0) -> list[tuple[int, str, list[str]]]:
    """[start, start + size) of img as (absolute address, mnemonic, operands),
    up to the first word capstone doesn't decode."""
    import capstone

    from leafgen import _split_ops

    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    return [(i.address, i.mnemonic, _split_ops(i.op_str)) for i in md.disasm(img[start:start + size], start + base)]


class Resolver:
    """Params of the functions of an image, memoized, following calls up to
    `depth` levels (a callee deeper than that, or in a cycle, reads nothing)."""

    def __init__(self, img: bytes, functions: list[tuple[int, int]], base: int = 0, depth: int = 4,
                 known: dict[int, Params] | None = None, max_size: int = 0x4000):
        self.img, self.base, self.depth, self.max_size = img, base, depth, max_size
        self.size = dict(functions)
        self.known = dict(known or {})   # absolute address -> Params given (imports, ...)
        self.memo: dict[tuple[int, int], Params | None] = {}

    def insns(self, addr: int) -> list[tuple[int, str, list[str]]]:
        r = addr - self.base
        size = self.size.get(r)
        if size is None or size > self.max_size:
            return []
        return decode(self.img, r, size, self.base)

    def params(self, addr: int, depth: int | None = None) -> Params | None:
        if addr in self.known:
            return self.known[addr]
        depth = self.depth if depth is None else depth
        key = (addr, depth)
        if key in self.memo:
            return self.memo[key]
        r = addr - self.base
        if r not in self.size:
            return None
        self.memo[key] = None  # a cycle reads nothing
        insns = self.insns(addr)
        if not insns:
            return None
        callee = (lambda a: self.params(a, depth - 1)) if depth > 0 else None
        p = analyze(insns, addr, addr + self.size[r], callee)
        self.memo[key] = p
        return p


def callers(img: bytes, functions: list[tuple[int, int]], targets: set[int], text_end: int,
            base: int = 0) -> dict[int, set[int]]:
    """target -> the functions (start, absolute) with a B/BL word to it, for
    the targets (absolute) given: the ones call_sites needs to decode."""
    import bisect
    import struct

    starts = [s for s, _ in functions]
    sizes = dict(functions)
    out: dict[int, set[int]] = {}
    end = text_end & ~3
    for i, w in enumerate(struct.unpack_from(f"<{end // 4}I", img, 0)):
        if (w & 0x7C000000) != 0x14000000:
            continue
        imm = w & 0x3FFFFFF
        if imm & (1 << 25):
            imm -= 1 << 26
        pc = i * 4
        t = pc + imm * 4 + base
        if t not in targets:
            continue
        j = bisect.bisect_right(starts, pc) - 1
        if j >= 0 and pc < starts[j] + sizes[starts[j]]:
            out.setdefault(t, set()).add(starts[j] + base)
    return out
