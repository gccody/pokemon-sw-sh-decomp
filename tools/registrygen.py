#!/usr/bin/env python3
"""A family of 45 pairs of game classes, one template's code each:
src/unsorted/registry.

    python tools/registrygen.py census                  # the instances, and what's matched
    python tools/registrygen.py write --names n.csv     # their sources, and the names to give

Each instance is two placeholder classes, named after their vtables:

- an outer class on Unk_23daca0 (src/unsorted/registry/Unk_23daca0.h), with
  six vtable slots (D2, D0, vf2..vf5) and eleven entries that can each hold
  a TLSF pool resource made in a block of a memory resource;
- an inner class at +0x28 of it, on the registered object Unk_236d228
  (src/unsorted/registry/Unk_236d228.h), with four slots and a static
  pointer to itself (a global of its own).

Their code is the same in every instance, but for the GOT slots (the two
vtables, the static pointer) and the call targets (the inner constructor,
the function vf2 calls). The bodies are in the family's header
(src/unsorted/registry/Unk_7be640.h, the first instance's outer
constructor). This tool finds the instances: the functions whose code is the
first outer constructor's with the immediates of adrp/lo12 pairs and the
targets of b/bl masked (`masked`); from each, the GOT slots and call targets
its code reads, the vtables' slots, and the function vf2 calls; every
function it takes must have the masked code of the first instance's
function in the same place. It writes, for each instance, a header with the
two classes (`Unk_<outer>.h`) and a file with the outer class's functions
that aren't inline (`Unk_<outer>.cpp`), and one file with every inner
constructor (Unk_7be720.cpp): defined in another TU, so the outer
constructor calls it rather than inlining it (see the family header).

The outer vtable's vf3 and the inner one's four slots are tools/vtables.py's
(src/unsorted/virtual): the classes here declare them the same way and
don't define them.
"""
from __future__ import annotations

import argparse
import csv
import struct
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

OUT_DIR = ROOT / "src" / "unsorted" / "registry"
FIRST = 0x7BE640            # the first instance's outer constructor (Sword, relative to BASE)
CTORS_FILE = "Unk_7be720.cpp"  # the inner constructors (the first one's address)
FAMILY_HEADER = "unsorted/registry/Unk_7be640.h"

# Where the outer constructor loads the outer _ZTV (adrp at +0x38, ldr at
# +0x3c) and calls the inner constructor (bl at +0x4c); where the inner
# constructor loads the inner _ZTV (+0xb0) and the static pointer (+0xc8);
# where vf2 calls the function that makes the resource (bl at +0x30).
OUTER_ZTV, INNER_CTOR_CALL = 0x38, 0x4C
INNER_ZTV, INSTANCE_GOT = 0xB0, 0xC8
CREATE_CALL = 0x30
OUTER_SLOTS = ("d2", "d0", "vf2", "vf3", "vf4", "vf5")
INNER_SLOTS = 4


def masked(code: bytes) -> bytes:
    """`code` with the targets of b/bl, the immediates of adrp and the lo12
    immediates (ld/st unsigned offset, add) of registers an adrp set masked:
    the code two instances of one template share."""
    out = []
    pages: set[int] = set()     # registers an adrp set, until overwritten
    for i in range(0, len(code) - 3, 4):
        w = struct.unpack_from("<I", code, i)[0]
        if (w & 0x9F000000) == 0x90000000:             # adrp
            pages.add(w & 31)
            w &= 0x9F00001F
        elif (w & 0x7C000000) == 0x14000000:           # b / bl
            w &= 0xFC000000
        else:
            rn, rd = (w >> 5) & 31, w & 31
            if rn in pages and ((w & 0x3B000000) == 0x39000000 or (w & 0x7F800000) == 0x11000000):
                w &= ~(0xFFF << 10)                   # ld/st [xN, #lo12] / add xD, xN, #lo12
            pages.discard(rd)
        out.append(struct.pack("<I", w))
    return b"".join(out)


def branch_target(img: bytes, pc: int) -> int | None:
    """The target of the b/bl at pc."""
    w = struct.unpack_from("<I", img, pc)[0]
    if (w & 0x7C000000) != 0x14000000:
        return None
    imm = w & 0x3FFFFFF
    return pc + ((imm - (1 << 26) if imm & (1 << 25) else imm) << 2)


def got_slot(img: bytes, pc: int) -> int | None:
    """The GOT slot an `adrp xN ; ldr xN, [xN, #lo12]` pair at pc loads."""
    w0, w1 = struct.unpack_from("<2I", img, pc)
    if (w0 & 0x9F000000) != 0x90000000 or (w1 & 0xFFC00000) != 0xF9400000 or (w1 >> 5) & 31 != w0 & 31:
        return None
    imm = ((w0 >> 29) & 3) | (((w0 >> 5) & 0x7FFFF) << 2)
    if imm & (1 << 20):
        imm -= 1 << 21
    return (pc & ~0xFFF) + (imm << 12) + ((w1 >> 10) & 0xFFF) * 8


@dataclass(frozen=True)
class Instance:
    outer: int          # the outer _ZTV (class Unk_<outer>), relative to BASE
    inner: int          # the inner _ZTV
    instance: int       # the inner class's static pointer
    funcs: tuple        # ((role, sword address), ...): ctor, inner_ctor, d2, d0, vf2, vf4, vf5, create

    def addr(self, role: str) -> int:
        return dict(self.funcs)[role]


def cls(addr: int) -> str:
    return f"Unk_{addr:x}"


def nested(name: str, member: str) -> str:
    return f"_ZN{len(name)}{name}{member}E"


def mangled(inst: Instance) -> dict[str, str]:
    """The name each role's function gets."""
    o, i = cls(inst.outer), cls(inst.inner)
    create = cls(inst.addr("create"))
    return {
        "ctor": nested(o, "C2") + "v",
        "inner_ctor": nested(i, "C2") + "v",
        "d2": nested(o, "D2") + "v",
        "d0": nested(o, "D0") + "v",
        "vf2": nested(o, "3vf2") + "m",
        "vf4": nested(o, "3vf4") + "v",
        "vf5": nested(o, "3vf5") + "v",
        "create": f"_Z{len(create)}{create}P16Unk_7be640_EntryRKjmP16Unk_239f910_Base",
    }


def expected_slot_names(inst: Instance) -> list[tuple[str, str]]:
    """(role, name) of the functions src/unsorted/virtual defines: the outer
    vf3 and the inner vf0..vf3."""
    o, i = cls(inst.outer), cls(inst.inner)
    return [("vf3", nested(o, "3vf3") + "v"), ("inner_vf0", nested(i, "3vf0") + "v"),
            ("inner_vf1", nested(i, "3vf1") + "m"), ("inner_vf2", nested(i, "3vf2") + "m"),
            ("inner_vf3", nested(i, "3vf3") + "m")]


def find_instances(img: bytes, funcs: list[tuple[int, int]], slots: dict, first: int = FIRST) -> list[Instance]:
    """Every instance, from the outer constructors with the code of the first
    one's (at `first`). slots: GOT and data slot -> the address it holds."""
    size = dict(funcs)

    def code(f: int) -> bytes:
        return masked(img[f:f + size[f]])

    def vtable_slots(ztv: int, n: int) -> list[int | None]:
        out = []
        for k in range(n):
            t = slots.get(ztv + 0x10 + 8 * k)
            out.append(t if isinstance(t, int) else None)
        return out

    def read(ctor: int) -> Instance | None:
        outer = slots.get(got_slot(img, ctor + OUTER_ZTV))
        inner_ctor = branch_target(img, ctor + INNER_CTOR_CALL)
        if not isinstance(outer, int) or inner_ctor not in size:
            return None
        inner = slots.get(got_slot(img, inner_ctor + INNER_ZTV))
        instance = slots.get(got_slot(img, inner_ctor + INSTANCE_GOT))
        if not isinstance(inner, int) or not isinstance(instance, int):
            return None
        vt = dict(zip(OUTER_SLOTS, vtable_slots(outer, len(OUTER_SLOTS))))
        if any(vt[r] not in size for r in OUTER_SLOTS):
            return None
        create = branch_target(img, vt["vf2"] + CREATE_CALL)
        if create not in size:
            return None
        roles = (("ctor", ctor), ("inner_ctor", inner_ctor), ("d2", vt["d2"]), ("d0", vt["d0"]),
                 ("vf2", vt["vf2"]), ("vf4", vt["vf4"]), ("vf5", vt["vf5"]), ("create", create))
        return Instance(outer, inner, instance, roles)

    model = read(first)
    if model is None:
        raise SystemExit(f"{first + BASE:#x} isn't the first instance's outer constructor")
    shapes = {r: code(a) for r, a in model.funcs}
    out = []
    for f, n in funcs:
        if n != size[first] or code(f) != shapes["ctor"]:
            continue
        inst = read(f)
        if inst is None or any(code(a) != shapes[r] for r, a in inst.funcs):
            print(f"{f + BASE:#x}: an outer constructor's code, but not the rest of an instance",
                  file=sys.stderr)
            continue
        out.append(inst)
    return out


def address(sword: int, shield: int | None) -> str:
    """An address comment: Sword's, and Shield's when it differs."""
    s = f"{sword + BASE:#x}"
    return s if shield in (None, sword) else f"{s} (Shield {shield + BASE:#x})"


def render_header(inst: Instance, shield: dict[int, int]) -> str:
    o, i, g, c = cls(inst.outer), cls(inst.inner), cls(inst.instance), cls(inst.addr("create"))

    def at(role: str) -> str:
        a = inst.addr(role)
        return address(a, shield.get(a))

    return f"""#pragma once
// Generated by tools/registrygen.py: an instance of the family of
// {FAMILY_HEADER} (outer vtable {inst.outer + BASE:#x}, inner {inst.inner + BASE:#x}).
#include "{FAMILY_HEADER}"

class {i};
// {inst.instance + BASE:#x}: the inner object, while it lives.
extern {i}* {g};

class {i} : public Unk_236d228 {{
public:
    // {at("inner_ctor")} ({CTORS_FILE})
    {i}();
    ~{i}() {{
        {g} = nullptr;
        Unk_7be720_Release(m_entries[0]);
    }}
    u32 vf0() override;
    void* vf1(u64 index) override;
    void* vf2(u64 index) override;
    void vf3(u64 index) override;

    Unk_7be720_Entry m_entries[1];
}};
PKMN_OFFSET_ASSERT({i}, m_entries, 0x8);
PKMN_SIZE_ASSERT({i}, 0x28);

Unk_239f910* {c}(Unk_7be640_Entry* entry, const u32& kind, u64 size, Unk_239f910_Base* resource);

class {o} : public Unk_23daca0 {{
public:
    {o}();
    // {at("d2")}, {at("d0")} (D0)
    // NON_MATCHING: the D0, which inlines Unk_236d228's D2 (see there).
    ~{o}() override {{}}
    void* vf2(u64 size) override;
    u64 vf3() override;
    // {at("vf4")}
    bool vf4() override {{ return Unk_7bea70_Body({g}, m_entry); }}
    // {at("vf5")}
    bool vf5() override {{ return Unk_7beb10_Body({g}, m_entries); }}

    {i} m_inner;
    Unk_7be640_Entry m_entry;
    Unk_7be640_Entry m_entries[10];
}};
PKMN_OFFSET_ASSERT({o}, m_inner, 0x28);
PKMN_OFFSET_ASSERT({o}, m_entry, 0x50);
PKMN_OFFSET_ASSERT({o}, m_entries, 0x70);
PKMN_SIZE_ASSERT({o}, 0x1b0);
"""


def render_source(inst: Instance, shield: dict[int, int]) -> str:
    o, g, c = cls(inst.outer), cls(inst.instance), cls(inst.addr("create"))

    def at(role: str) -> str:
        a = inst.addr(role)
        return address(a, shield.get(a))

    return f"""// Scope: common
// Generated by tools/registrygen.py.
#include "unsorted/registry/{o}.h"

// {at("ctor")}
{o}::{o}() {{}}

// {at("vf2")}
void* {o}::vf2(u64 size) {{
    if (!size || m_entry.field_8)
        nn::diag::detail::AbortImpl("", "", "", 0);
    u32 kind = 0;
    return {c}(&m_entry, kind, size, field_8);
}}

// {at("create")}
Unk_239f910* {c}(Unk_7be640_Entry* entry, const u32& kind, u64 size, Unk_239f910_Base* resource) {{
    return Unk_7bec20_Body({g}, entry, kind, size, resource);
}}
"""


def render_ctors(insts: list[Instance], shield: dict[int, int]) -> str:
    out = ["// Scope: common",
           "// Generated by tools/registrygen.py: the inner constructors of the family of",
           f"// {FAMILY_HEADER}, in a TU of their own so that the outer constructors",
           "// call them (see the family header).",
           *(f'#include "unsorted/registry/{cls(x.outer)}.h"' for x in insts), ""]
    for x in sorted(insts, key=lambda x: x.addr("inner_ctor")):
        i, g = cls(x.inner), cls(x.instance)
        a = x.addr("inner_ctor")
        out += [f"// {address(a, shield.get(a))}", f"{i}::{i}() : m_entries() {{", f"    {g} = this;", "}", ""]
    return "\n".join(out[:-1]) + "\n"


def load():
    from common import load_module, nso_path, read_functions_csv
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = load_module("sword")
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), mod["image"], mod["text_end"])
    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    insts = find_instances(mod["image"], mod["functions"], dyn.slots)
    return insts, rows


def cmd_census(args) -> None:
    insts, rows = load()
    total = done = 0
    for x in insts:
        st = "".join(rows[a].status if a in rows else "?" for _, a in x.funcs)
        n = sum(rows[a].sword_size for _, a in x.funcs if a in rows)
        total += n
        done += sum(rows[a].sword_size for _, a in x.funcs if a in rows and rows[a].status == "O")
        print(f"{x.addr('ctor') + BASE:#x}  {cls(x.outer)} / {cls(x.inner)}  {n:5} bytes  {st}")
    print(f"{len(insts)} instances, {total} bytes, {done} matched")


def cmd_write(args) -> None:
    from common import clang_format

    insts, rows = load()
    shield = {a: r.shield for a, r in rows.items() if r.shield is not None}
    problems = []
    for x in insts:
        for role, name in expected_slot_names(x):
            if not any(r.name == name for r in rows.values()):
                problems.append(f"{cls(x.outer)}: {name} ({role}) isn't in functions.csv")
        for _, a in x.funcs:
            r = rows.get(a)
            if r is None or r.scope != "common" or r.shield is None:
                problems.append(f"{a + BASE:#x}: not a common function of both games")
    if problems:
        raise SystemExit("\n".join(problems))
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    paths = []
    for x in insts:
        for suffix, text in ((".h", render_header(x, shield)), (".cpp", render_source(x, shield))):
            p = OUT_DIR / f"{cls(x.outer)}{suffix}"
            p.write_text(text, encoding="utf-8", newline="\n")
            paths.append(p)
    p = OUT_DIR / CTORS_FILE
    p.write_text(render_ctors(insts, shield), encoding="utf-8", newline="\n")
    paths.append(p)
    if not clang_format(paths):
        print("clang-format isn't on PATH: format the sources before committing them")
    if args.names:
        with open(args.names, "w", newline="", encoding="utf-8") as fh:
            w = csv.writer(fh, lineterminator="\n")
            w.writerow(["Name", "Sword", "Shield"])
            for x in insts:
                names = mangled(x)
                for role, a in x.funcs:
                    w.writerow([names[role], f"{a + BASE:#x}", f"{shield[a] + BASE:#x}"])
    print(f"{len(insts)} instances: {len(paths)} files in {OUT_DIR.relative_to(ROOT)}")


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("census")
    w = sub.add_parser("write")
    w.add_argument("--names", type=Path, help="write the names to give (Name,Sword,Shield) to this CSV")
    args = ap.parse_args(argv)
    {"census": cmd_census, "write": cmd_write}[args.cmd](args)
    return 0


if __name__ == "__main__":
    sys.exit(main())
