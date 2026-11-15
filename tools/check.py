#!/usr/bin/env python3
"""Build the decomp for both games and check every compiled function against
the original executables.

    python tools/check.py                 # build sword+shield, check everything
    python tools/check.py _ZN4pkmn10GetVersionEv   # one function (mangled or FUN_/address)
    python tools/check.py --diff NAME     # side-by-side asm for mismatches
    python tools/check.py --update        # write O for matches / demote regressions in functions.csv
    python tools/check.py --no-build      # skip the cmake build step

A function is matching (O) only when it matches in *every* game it exists in:
common/common-data/diverged functions are checked against Sword AND Shield,
sword/shield-only functions against their game.

Relocation-aware: calls, ADRP/lo12 pairs, GOT loads and SDK imports (via PLT)
are resolved by symbol name through data/functions.csv and
data/data_symbols.csv; string/constant literals are compared by content.
"""
from __future__ import annotations

import argparse
import csv
import shutil
import struct
import subprocess
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, VERSIONS, Function, load_module, nso_path, read_functions_csv, write_functions_csv  # noqa: E402
from nx.module import DynInfo  # noqa: E402
from nx.nso import Nso  # noqa: E402
from nx.refs import decode, ldst_scale  # noqa: E402

from elftools.elf.elffile import ELFFile  # noqa: E402
from elftools.elf.sections import SymbolTableSection  # noqa: E402
from elftools.elf.relocation import RelocationSection  # noqa: E402

# AArch64 ELF relocation types
CALL26, JUMP26 = 283, 282
ADR_PREL_PG_HI21, ADR_PREL_PG_HI21_NC = 275, 276
ADR_PREL_LO21, LD_PREL_LO19 = 274, 273
ADD_ABS_LO12_NC = 277
LDST_LO12 = {278, 284, 285, 286, 299}
ADR_GOT_PAGE, LD64_GOT_LO12_NC = 311, 312
SHF_STRINGS, SHF_EXECINSTR = 0x20, 0x4


# --------------------------------------------------------------------------- originals
class Original:
    def __init__(self, version: str):
        mod = load_module(version)
        self.version = version
        self.img: bytes = mod["image"]
        self.dyn = DynInfo(Nso(nso_path(version).read_bytes()), self.img, mod["text_end"])


def load_symbol_tables(funcs: list[Function]):
    by_name: dict[str, Function] = {}
    by_addr: dict[str, dict[int, Function]] = {v: {} for v in VERSIONS}
    for f in funcs:
        if f.name:
            by_name[f.name] = f
        for v in VERSIONS:
            a = f.addr(v)
            if a is not None:
                by_addr[v][a] = f
    data: dict[str, dict[str, int]] = {v: {} for v in VERSIONS}
    p = ROOT / "data" / "data_symbols.csv"
    if p.exists():
        with open(p, newline="", encoding="utf-8") as fh:
            for r in csv.DictReader(fh):
                for v, col in (("sword", "Sword"), ("shield", "Shield")):
                    if r[col]:
                        data[v][r["Name"]] = int(r[col], 16) - BASE
    return by_name, by_addr, data


# --------------------------------------------------------------------------- compiled objects
@dataclass
class Reloc:
    type: int
    sym: str
    sym_type: str
    sym_shndx: int | str
    sym_value: int
    addend: int


@dataclass
class CompiledFunc:
    name: str
    obj: Path
    code: bytes
    relocs: dict[int, Reloc]
    elf: ELFFile = field(repr=False)


def load_objects(build_dir: Path) -> dict[str, CompiledFunc]:
    out: dict[str, CompiledFunc] = {}
    # Only objects of sources that currently exist (stale .o files of deleted
    # sources linger in the build dir), taken from compile_commands.json.
    import json
    cc = json.loads((build_dir / "compile_commands.json").read_text())
    objs = sorted({(Path(e["directory"]) / e["output"]).resolve() for e in cc if "output" in e})
    for obj in objs:
        if not obj.exists():
            continue
        fh = open(obj, "rb")
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        if not isinstance(symtab, SymbolTableSection):
            continue
        rel_by_sec: dict[int, dict[int, Reloc]] = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection) and sec.is_RELA():
                rs = rel_by_sec.setdefault(sec["sh_info"], {})
                for r in sec.iter_relocations():
                    s = symtab.get_symbol(r["r_info_sym"])
                    rs[r["r_offset"]] = Reloc(r["r_info_type"], s.name, s["st_info"]["type"],
                                              s["st_shndx"], s["st_value"], r["r_addend"])
        for s in symtab.iter_symbols():
            if s["st_info"]["type"] != "STT_FUNC" or s["st_shndx"] in ("SHN_UNDEF", "SHN_ABS"):
                continue
            sec = elf.get_section(s["st_shndx"])
            v, n = s["st_value"], s["st_size"]
            relocs = {off - v: r for off, r in rel_by_sec.get(s["st_shndx"], {}).items() if v <= off < v + n}
            out[s.name] = CompiledFunc(s.name, obj, sec.data()[v:v + n], relocs, elf)
    return out


# --------------------------------------------------------------------------- comparison
@dataclass
class Result:
    ok: bool
    errors: list[str] = field(default_factory=list)
    warnings: list[str] = field(default_factory=list)
    first_bad: int | None = None


def _imm12(w: int) -> int:
    return (w >> 10) & 0xFFF


def compare(cf: CompiledFunc, fn: Function, orig: Original, syms, verbose_name) -> Result:
    by_name, by_addr, data_syms = syms
    v = orig.version
    addr, size = fn.addr(v), fn.size(v)
    res = Result(True)

    def bad(off: int, msg: str):
        res.ok = False
        res.errors.append(f"+{off:#05x}: {msg}")
        if res.first_bad is None:
            res.first_bad = off

    if len(cf.code) != size:
        bad(min(len(cf.code), size or 0), f"size {len(cf.code)} != original {size}")
    n = min(len(cf.code), size or 0)
    o_img = orig.img
    o_targets = {off: t for off, _, _, t in decode(o_img, addr, n - n % 4)} if n >= 4 else {}

    def expected_addr(r: Reloc) -> tuple[int | None, str]:
        """Absolute expected target for a reloc's symbol (None = unknown) + description."""
        name = r.sym
        if r.sym_type == "STT_SECTION" or (not name or name.startswith(".L")):
            sec = cf.elf.get_section(r.sym_shndx) if isinstance(r.sym_shndx, int) else None
            if sec is not None and sec["sh_flags"] & SHF_EXECINSTR:
                # reference to code in the same object: find the function symbol there
                symtab = cf.elf.get_section_by_name(".symtab")
                for s in symtab.iter_symbols():
                    if s["st_shndx"] == r.sym_shndx and s["st_info"]["type"] == "STT_FUNC" \
                            and s["st_value"] <= r.addend + r.sym_value < s["st_value"] + max(1, s["st_size"]):
                        f = by_name.get(s.name)
                        if f is not None and f.addr(v) is not None:
                            return f.addr(v) + r.addend + r.sym_value - s["st_value"], s.name
                        return None, s.name
            return None, name or (sec.name if sec is not None else "<section>")
        f = by_name.get(name)
        if f is not None:
            return (f.addr(v) + r.addend if f.addr(v) is not None else None), name
        if name in data_syms[v]:
            return data_syms[v][name] + r.addend, name
        return None, name

    def literal_bytes(r: Reloc) -> bytes | None:
        if not isinstance(r.sym_shndx, int):
            return None
        sec = cf.elf.get_section(r.sym_shndx)
        if sec["sh_type"] == "SHT_NOBITS":
            return None
        blob = sec.data()
        start = r.sym_value + r.addend
        if sec["sh_flags"] & SHF_STRINGS:
            end = blob.find(b"\0", start)
            return blob[start:end + 1 if end >= 0 else len(blob)]
        ent = sec["sh_entsize"] or min(64, len(blob) - start)
        return blob[start:start + ent]

    for off in range(0, n - n % 4, 4):
        cw = struct.unpack_from("<I", cf.code, off)[0]
        ow = struct.unpack_from("<I", o_img, addr + off)[0]
        r = cf.relocs.get(off)
        if r is None:
            if cw != ow:
                bad(off, f"instruction differs ({cw:08x} vs {ow:08x})")
            continue
        pc = addr + off
        t = r.type
        if t in (CALL26, JUMP26):
            if (cw & 0xFC000000) != (ow & 0xFC000000):
                bad(off, "b/bl kind differs"); continue
            imm = ow & 0x3FFFFFF
            otgt = pc + ((imm - (1 << 26) if imm & (1 << 25) else imm) << 2)
            exp, desc = expected_addr(r)
            if exp is None and r.sym in orig.dyn.plt_by_name:
                exp = orig.dyn.plt_by_name[r.sym]
            if exp is None:
                hint = by_addr[v].get(otgt)
                hint_s = (hint.display_name if hint else orig.dyn.plt.get(otgt, "?"))
                bad(off, f"call to unknown symbol {verbose_name(desc)} - original calls "
                         f"{otgt + BASE:#x} ({hint_s}); name it with tools/funcs.py name")
            elif exp != otgt:
                bad(off, f"calls {verbose_name(desc)} ({exp + BASE:#x}) but original calls {otgt + BASE:#x}")
        elif t in (ADR_PREL_PG_HI21, ADR_PREL_PG_HI21_NC, ADR_GOT_PAGE):
            if (cw & 0x9F00001F) != (ow & 0x9F00001F):
                bad(off, "adrp register differs"); continue
            if t == ADR_GOT_PAGE:
                continue  # verified through the paired LD64_GOT_LO12_NC
            exp, _ = expected_addr(r)
            if exp is not None:
                imm = ((ow >> 29) & 3) | (((ow >> 5) & 0x7FFFF) << 2)
                imm = imm - (1 << 21) if imm & (1 << 20) else imm
                if (pc & ~0xFFF) + (imm << 12) != exp & ~0xFFF:
                    bad(off, f"adrp page for {verbose_name(r.sym)} differs")
        elif t == LD64_GOT_LO12_NC:
            if (cw & 0xFFC003FF) != (ow & 0xFFC003FF):
                bad(off, "GOT load differs"); continue
            slot = o_targets.get(off)
            target = orig.dyn.slots.get(slot) if slot is not None else None
            exp, desc = expected_addr(r)
            if target is None:
                bad(off, f"original GOT slot for {verbose_name(desc)} not resolvable")
            elif isinstance(target, str):
                if target != r.sym:
                    bad(off, f"GOT import {target} != {verbose_name(desc)}")
            elif exp is None:
                res.warnings.append(f"+{off:#05x}: GOT ref to unknown symbol {verbose_name(desc)} "
                                    f"(original -> {target + BASE:#x}); add it to data_symbols.csv/functions.csv")
            elif exp != target:
                bad(off, f"GOT ref {verbose_name(desc)} ({exp + BASE:#x}) != original {target + BASE:#x}")
        elif t == ADD_ABS_LO12_NC or t in LDST_LO12 or t in (ADR_PREL_LO21, LD_PREL_LO19):
            mask = {ADD_ABS_LO12_NC: 0xFFC003FF, ADR_PREL_LO21: 0x9F00001F, LD_PREL_LO19: 0xFF00001F}.get(t, 0xFFC003FF)
            if (cw & mask) != (ow & mask):
                bad(off, "instruction differs (ignoring address field)"); continue
            exp, desc = expected_addr(r)
            otgt = o_targets.get(off)
            if exp is not None:
                if t == ADD_ABS_LO12_NC:
                    good = _imm12(ow) == exp & 0xFFF
                elif t in LDST_LO12:
                    good = _imm12(ow) << ldst_scale(ow) == exp & 0xFFF
                else:
                    good = otgt == exp
                if not good:
                    bad(off, f"low bits of {verbose_name(desc)} differ")
                continue
            lit = literal_bytes(r)
            if lit is None or otgt is None:
                res.warnings.append(f"+{off:#05x}: unverified ref to {verbose_name(desc)}")
            elif o_img[otgt:otgt + len(lit)] != lit:
                bad(off, f"literal {verbose_name(desc)} contents differ ({lit[:24]!r})")
        else:
            res.warnings.append(f"+{off:#05x}: unhandled relocation type {t} ({r.sym})")
            if cw != ow:
                bad(off, "instruction differs")
    return res


# --------------------------------------------------------------------------- output
def side_by_side(cf: CompiledFunc, fn: Function, orig: Original, res: Result) -> str:
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    a = fn.addr(orig.version)
    size = max(len(cf.code), fn.size(orig.version) or 0)
    mine = {i.address: f"{i.mnemonic} {i.op_str}" for i in md.disasm(cf.code, 0)}
    theirs = {i.address - a: f"{i.mnemonic} {i.op_str}" for i in md.disasm(orig.img[a:a + (fn.size(orig.version) or 0)], a)}
    bad_offs = {int(e.split(":")[0][1:], 16) for e in res.errors if e.startswith("+")}
    lines = [f"      {'compiled':44} original ({orig.version} {a + BASE:#x})"]
    for off in range(0, size, 4):
        mark = ">>" if off in bad_offs else "  "
        r = cf.relocs.get(off)
        m = mine.get(off, "")
        if r is not None:
            m += f"  <{r.sym}>"
        lines.append(f"{mark}{off:4x}  {m[:44]:44} {theirs.get(off, '')}")
    return "\n".join(lines)


def demangler():
    exe = shutil.which("llvm-cxxfilt") or next((str(p) for p in ROOT.glob("toolchain/*/bin/llvm-cxxfilt*")), None)
    cache: dict[str, str] = {}

    def dm(name: str) -> str:
        if not exe or not name.startswith("_Z"):
            return name
        if name not in cache:
            try:
                cache[name] = subprocess.run([exe, name], capture_output=True, text=True).stdout.strip() or name
            except OSError:
                cache[name] = name
        return cache[name]
    return dm


def build(versions: list[str]) -> None:
    cmake = shutil.which("cmake") or "cmake"
    for v in versions:
        bdir = ROOT / "build" / v
        if not (bdir / "build.ninja").exists():
            subprocess.run([cmake, "--preset", v], cwd=ROOT, check=True)
        subprocess.run([cmake, "--build", "--preset", v], cwd=ROOT, check=True)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names", nargs="*", help="only check these functions (mangled name, FUN_ name or address)")
    ap.add_argument("--diff", action="store_true", help="print side-by-side disassembly for mismatches")
    ap.add_argument("--update", action="store_true", help="update Status in data/functions.csv")
    ap.add_argument("--no-build", action="store_true")
    ap.add_argument("-v", "--verbose", action="store_true", help="also print warnings for matching functions")
    args = ap.parse_args()

    if not args.no_build:
        build(list(VERSIONS))

    funcs = read_functions_csv()
    syms = load_symbol_tables(funcs)
    by_name = syms[0]
    dm = demangler()
    origs = {v: Original(v) for v in VERSIONS}
    compiled = {v: load_objects(ROOT / "build" / v) for v in VERSIONS}

    wanted = None
    if args.names:
        wanted = set()
        for q in args.names:
            for f in funcs:
                if q in (f.name, f.display_name) or (q.startswith("0x") and int(q, 16) - BASE in (f.sword, f.shield)):
                    wanted.add(f.key)

    all_names = sorted(set().union(*(c.keys() for c in compiled.values())))
    n_ok = n_bad = 0
    status_updates: dict[str, str] = {}
    for name in all_names:
        fn = by_name.get(name)
        if fn is None:
            if wanted is None:
                print(f"?? {dm(name)}  [{name}] is not in data/functions.csv - assign it: "
                      f"tools/funcs.py name <address> {name}")
            continue
        if wanted is not None and fn.key not in wanted:
            continue
        results = {}
        for v in VERSIONS:
            cf = compiled[v].get(name)
            if not fn.in_version(v):
                if cf is not None:
                    results[v] = Result(False, [f"compiled for {v}, but the function only exists in "
                                                f"{fn.scope} - guard it with #if PKMN_IS_{fn.scope.upper()}"])
                continue
            if cf is None:
                results[v] = Result(False, [f"not compiled in the {v} build (missing #if branch?)"])
                continue
            results[v] = compare(cf, fn, origs[v], syms, dm)
        ok = all(r.ok for r in results.values())
        tag = "OK " if ok else "BAD"
        print(f"{tag} {fn.scope:11} {dm(name)}  [{', '.join(f'{v}:{fn.addr(v) + BASE:#x}' for v in VERSIONS if fn.in_version(v))}]")
        for v, r in results.items():
            for e in r.errors:
                print(f"      {v}: {e}")
            if args.verbose or not ok:
                for w in r.warnings:
                    print(f"      {v}: warning: {w}")
            if args.diff and not r.ok and v in compiled and name in compiled[v]:
                print(side_by_side(compiled[v][name], fn, origs[v], r))
        n_ok += ok
        n_bad += not ok
        if ok and fn.status != "O":
            status_updates[fn.key] = "O"
        elif not ok and fn.status == "O":
            status_updates[fn.key] = "M"
            print("      REGRESSION: was marked O in functions.csv")

    print(f"\n{n_ok} matching, {n_bad} not matching")
    if args.update and status_updates:
        for f in funcs:
            if f.key in status_updates:
                f.status = status_updates[f.key]
        write_functions_csv(ROOT / "data" / "functions.csv", funcs)
        print(f"updated {len(status_updates)} status entries in data/functions.csv")
    elif status_updates and not args.update:
        print(f"({len(status_updates)} status changes pending - rerun with --update)")
    return 0 if n_bad == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
