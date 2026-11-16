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
data/data_symbols.csv; string/constant literals are compared by content. A
`__FILE__` literal of vendored code (a source path, listed by directory in
data/source_paths.csv) is compared by the file it names, because it spells the
vendor's checkout (see tools/source_paths.py).

Local (static) symbols are looked up by their file-qualified name,
`<symbol>@<file stem>` (see tools/symbols.py). Compiled functions listed in
data/absent_functions.csv are not in the executable and are skipped. Those in
data/unidentified_functions.csv are skipped too, and counted apart: vendored
code whose original hasn't been found (changed beyond recognition, inlined or
dropped, nobody knows yet). So are the weak/COMDAT functions of
data/foreign_copies.csv: the executable has them, but the linker kept the copy
of a library this repository doesn't build, so the copies compiled here aren't
the one to compare.

Weak and COMDAT definitions (inline functions, template instantiations) may be
emitted by several translation units, and the linker keeps one of them.
check.py keeps one copy for each distinct code+relocations, and a function
matches only if every distinct copy matches the original (see add_definition).
The exception is a copy the executable shows the linker kept: the linker
places the kept copy among the code of the TU it took it from, so when the
original lies inside the code of exactly one TU that emits a copy (between
that TU's first and last strong functions in functions.csv), only that copy
is compared (see kept_copy). Two strong definitions of one symbol are an error.

Symbols at the same address of one object are aliases (clang emits a complete
destructor or constructor, D1/C1, as an alias of the base one, D2/C2, when they
are the same code). functions.csv has one row per address, so an alias of a
checked function needs no row of its own and is skipped.

Before checking, each build dir must use the global codegen flags of
cmake/toolchain-nx64.cmake (PKMN_CODEGEN_FLAGS): its last configure recorded
the same list, and every command in its compile_commands.json contains it, in
order. Otherwise the objects were built with other flags and check.py stops.
It also stops if the build dir doesn't run tools/fix_traps.py on its objects
(cmake/TrapEncoding.cmake records that it does): without it, every trap is
`brk #1` instead of the NX trap word 0xe7ffdefe.
"""
from __future__ import annotations

import argparse
import csv
import json
import re
import shutil
import struct
import subprocess
import sys
from dataclasses import dataclass, field, replace
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, VERSIONS, Function, load_module, nso_path, read_functions_csv, write_functions_csv  # noqa: E402
from nx.module import DynInfo  # noqa: E402
from nx.nso import Nso  # noqa: E402
from nx.refs import decode, ldst_scale  # noqa: E402
import symbols  # noqa: E402
from source_paths import SourcePaths, read_source_paths  # noqa: E402

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
ABS64, PREL32 = 257, 261  # in data: address tables, jump tables
# TLS descriptor access (adrp x0; ldr x1, [x0]; add x0, x0; blr x1), which the
# linker relaxes to local-exec in an executable (see tls_relaxed)
TLSDESC_ADR_PAGE21, TLSDESC_LD64_LO12, TLSDESC_ADD_LO12, TLSDESC_CALL = 562, 563, 564, 569
TLSDESC = (TLSDESC_ADR_PAGE21, TLSDESC_LD64_LO12, TLSDESC_ADD_LO12, TLSDESC_CALL)
NOP = 0xD503201F
MAX_LITERAL = 1024  # bytes compared for a reference into a data section without entsize
SHF_MERGE, SHF_STRINGS, SHF_EXECINSTR = 0x10, 0x20, 0x4
GRP_COMDAT = 1
BRK_1, NX_TRAP = 0xD4200020, 0xE7FFDEFE  # upstream clang's trap, the originals' (tools/fix_traps.py)

ABSENT_CSV = ROOT / "data" / "absent_functions.csv"
FOREIGN_CSV = ROOT / "data" / "foreign_copies.csv"
UNIDENTIFIED_CSV = ROOT / "data" / "unidentified_functions.csv"
SOURCE_PATHS_CSV = ROOT / "data" / "source_paths.csv"
TOOLCHAIN_FILE = ROOT / "cmake" / "toolchain-nx64.cmake"


def read_absent(path: Path = ABSENT_CSV) -> dict[str, str]:
    """A Name,Reason CSV: the compiled functions that are not in the executable
    (data/absent_functions.csv), those whose original hasn't been identified
    (data/unidentified_functions.csv), or those whose copy in the executable is
    another library's (data/foreign_copies.csv): name -> reason."""
    if not path.exists():
        return {}
    with open(path, newline="", encoding="utf-8") as fh:
        return {r["Name"]: r["Reason"] for r in csv.DictReader(fh)}


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
    sym: str          # CSV name: file-qualified for local symbols
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
    source: str = ""
    # relocations of every section of the object: section index -> offset -> Reloc
    obj_relocs: dict[int, dict[int, Reloc]] = field(default_factory=dict, repr=False)
    # weak or COMDAT definition: other translation units may define it too
    mergeable: bool = False
    # code and relocations in a form comparable across objects (see _fingerprint)
    fingerprint: tuple = ()
    # copies of this (mergeable) function from other TUs whose fingerprint differs
    variants: list[CompiledFunc] = field(default_factory=list, repr=False)
    # the other TUs that emit this same copy (same fingerprint), after `source`
    also_in: list[str] = field(default_factory=list, repr=False)
    # other function symbols of the object at the same address (see alias_groups)
    aliases: tuple[str, ...] = ()

    def copies(self) -> list[CompiledFunc]:
        return [self, *self.variants]

    def sources(self) -> list[str]:
        """Every TU that emits this copy."""
        return [self.source, *self.also_in]


def add_definition(out: dict[str, CompiledFunc], cf: CompiledFunc) -> str | None:
    """Record compiled function `cf` in `out`, resolving duplicate definitions
    of one name the way the linker does. Returns a warning, or None.

    - Two strong definitions: error (SystemExit), as at link time.
    - Strong and weak/COMDAT: the strong one is kept, the other is dropped.
    - Two weak/COMDAT definitions: the first one is kept (load_objects reads
      objects in sorted path order). A copy whose code or relocations differ
      from every copy seen so far is kept as a variant and reported. Which
      copy the linker keeps depends on link order, so the function counts as
      matching only if every distinct copy matches the original, unless the
      executable shows which one it kept (see kept_copy).
    """
    prev = out.get(cf.name)
    if prev is None:
        out[cf.name] = cf
        return None
    if not prev.mergeable and not cf.mergeable:
        hint = ("local symbols are qualified by file stem (tools/symbols.py), so rename one file"
                if symbols.split(cf.name)[1] is not None else "two strong definitions; remove one")
        raise SystemExit(f"{cf.name} is defined in both {prev.source} and {cf.source}: {hint}")
    if not prev.mergeable:
        return None
    if not cf.mergeable:
        out[cf.name] = cf
        return None
    same = next((c for c in prev.copies() if c.fingerprint == cf.fingerprint), None)
    if same is not None:
        same.also_in.append(cf.source)
        return None
    prev.variants.append(cf)
    return (f"weak/COMDAT {cf.name} differs between {prev.source} and {cf.source} "
            f"(different flags or compiler?): every copy is checked against the original")


def _comdat_sections(elf: ELFFile) -> set[int]:
    """Indices of the sections that are members of a COMDAT group."""
    out: set[int] = set()
    for sec in elf.iter_sections():
        if sec["sh_type"] == "SHT_GROUP":
            words = struct.unpack(f"<{sec['sh_size'] // 4}I", sec.data())
            if words and words[0] & GRP_COMDAT:
                out.update(words[1:])
    return out


def _fingerprint(code: bytes, relocs: dict[int, Reloc], elf: ELFFile | None) -> tuple:
    """Code bytes plus relocations, with section-relative targets described
    independently of the object's layout: the string itself for a merged-string
    section, the constant's bytes for a merged-constant section (.rodata.cst16),
    otherwise the section name and offset."""
    rs = []
    for off, r in sorted(relocs.items()):
        target: tuple = (r.sym, r.addend)
        if elf is not None and r.sym_type == "STT_SECTION" and isinstance(r.sym_shndx, int):
            sec = elf.get_section(r.sym_shndx)
            start = r.sym_value + r.addend
            if sec["sh_flags"] & SHF_STRINGS and sec["sh_type"] != "SHT_NOBITS":
                blob = sec.data()
                end = blob.find(b"\0", start)
                target = ("string", _path_key(blob[start:end if end >= 0 else len(blob)]))
            elif sec["sh_flags"] & SHF_MERGE and sec["sh_entsize"] and sec["sh_type"] != "SHT_NOBITS":
                target = ("const", sec.data()[start:start + sec["sh_entsize"]])
            else:
                target = (sec.name, start)
        rs.append((off, r.type, target))
    return code, tuple(rs)


_ROOT_KEY = ROOT.as_posix().lower().encode()


def _path_key(s: bytes) -> bytes:
    """A __FILE__ path of this checkout with one kind of separator: clang spells
    one header with "\\" or "/" depending on the include that found it. No
    original names this checkout, so its paths only ever match through
    data/source_paths.csv, which compares them by the file they name."""
    key = s.replace(b"\\", b"/")
    return key if key.lower().startswith(_ROOT_KEY) else s


def _symbol_name(s, source: str) -> str:
    """CSV name of an ELF symbol of the object compiled from `source`."""
    local = s["st_info"]["bind"] == "STB_LOCAL" and s["st_info"]["type"] in ("STT_FUNC", "STT_OBJECT")
    return symbols.qualify(s.name, source, local and bool(s.name))


def codegen_flags(toolchain: Path = TOOLCHAIN_FILE) -> list[str]:
    """PKMN_CODEGEN_FLAGS of the toolchain file, in order."""
    m = re.search(r"^set\(PKMN_CODEGEN_FLAGS\s(.*?)^\)", toolchain.read_text(encoding="utf-8"), re.S | re.M)
    if not m:
        raise SystemExit(f"error: no set(PKMN_CODEGEN_FLAGS ...) in {toolchain}")
    flags = [w for line in m.group(1).splitlines() for w in line.split("#", 1)[0].split()]
    if not flags or any(c in w for w in flags for c in "\"'$;()"):
        raise SystemExit(f"error: can't read PKMN_CODEGEN_FLAGS in {toolchain} (plain flags only: no quotes, variables or generator expressions)")
    return flags


def _has_run(words: list[str], run: list[str]) -> bool:
    n = len(run)
    return any(words[i:i + n] == run for i in range(len(words) - n + 1))


def stale_flag_sources(compile_commands: list[dict], flags: list[str]) -> list[str]:
    """Sources whose compile command lacks `flags` as one contiguous run."""
    stale = []
    for e in compile_commands:
        words = e["arguments"] if "arguments" in e else e["command"].split()
        if not _has_run(words, flags):
            stale.append(e["file"])
    return stale


def configured_codegen_flags(cache: Path) -> list[str] | None:
    """PKMN_CODEGEN_FLAGS a build dir was last configured with (cmake/CodegenFlags.cmake
    records them in CMakeCache.txt), or None if it has no record."""
    prefix = "PKMN_CODEGEN_FLAGS_CONFIGURED:INTERNAL="
    for line in cache.read_text(encoding="utf-8", errors="replace").splitlines():
        if line.startswith(prefix):
            return line[len(prefix):].split(";")
    return None


def check_codegen_flags(build_dir: Path, flags: list[str]) -> str | None:
    """Error message if build_dir isn't configured and compiled with `flags`, else None."""
    cc, cache = build_dir / "compile_commands.json", build_dir / "CMakeCache.txt"
    if not cc.exists() or not cache.exists():
        return f"{build_dir} isn't configured: build first (cmake --preset {build_dir.name})"
    fix = (f"Rebuild (`cmake --build --preset {build_dir.name}`, or check.py without --no-build); "
           f"if that doesn't help, reconfigure with `cmake --preset {build_dir.name} --fresh`.")
    configured = configured_codegen_flags(cache)
    if configured != flags:
        was = "no record of them" if configured is None else " ".join(configured)
        return (f"{build_dir} is configured with other codegen flags than the toolchain file "
                f"(PKMN_CODEGEN_FLAGS):\n    configured: {was}\n    toolchain:  {' '.join(flags)}\n{fix}")
    stale = stale_flag_sources(json.loads(cc.read_text()), flags)
    if stale:
        return (f"{len(stale)} of the sources in {build_dir} (e.g. {stale[0]}) are not compiled with the "
                f"codegen flags of the toolchain file (PKMN_CODEGEN_FLAGS):\n    {' '.join(flags)}\n{fix}")
    return None


def check_trap_rewrite(build_dir: Path) -> str | None:
    """Error message if build_dir's objects aren't rewritten by tools/fix_traps.py, else None."""
    cache = build_dir / "CMakeCache.txt"
    text = cache.read_text(encoding="utf-8", errors="replace") if cache.exists() else ""
    if not any(line.startswith("PKMN_TRAP_REWRITE:INTERNAL=") for line in text.splitlines()):
        return (f"{build_dir} doesn't rewrite traps (cmake/TrapEncoding.cmake isn't in its configure), "
                f"so its traps are `brk #1`, not the NX trap word. Rebuild (`cmake --build --preset "
                f"{build_dir.name}`, or check.py without --no-build), or reconfigure with "
                f"`cmake --preset {build_dir.name} --fresh`.")
    return None


def strong_definition(name: str, builds) -> str | None:
    """The source of a strong (not weak/COMDAT) compiled definition of `name`,
    or None. A function of data/foreign_copies.csv may only have weak copies:
    a strong one is what the linker would keep."""
    return next((c[name].source for c in builds if name in c and not c[name].mergeable), None)


def with_aliases(by_name: dict[str, Function], builds) -> dict[str, Function]:
    """`by_name` plus every compiled name that has no row of its own but is an
    alias of one that does (C1 of C2, D1 of D2), mapped to that row."""
    out = dict(by_name)
    for compiled in builds:
        for name, cf in compiled.items():
            if name not in out:
                row = next((by_name[a] for a in cf.aliases if a in by_name), None)
                if row is not None:
                    out[name] = row
    return out


def alias_groups(syms: list[tuple[str, object, int, int]]) -> dict[str, tuple[str, ...]]:
    """For (name, section, value, size) function symbols of one object, the other
    names at the same section, value and size, for every name that has any."""
    at: dict[tuple, list[str]] = {}
    for name, shndx, value, size in syms:
        at.setdefault((shndx, value, size), []).append(name)
    return {n: tuple(o for o in names if o != n) for names in at.values() if len(names) > 1 for n in names}


def load_objects(build_dir: Path) -> dict[str, CompiledFunc]:
    out: dict[str, CompiledFunc] = {}
    # Only objects of sources that currently exist (stale .o files of deleted
    # sources linger in the build dir), taken from compile_commands.json.
    cc = json.loads((build_dir / "compile_commands.json").read_text())
    sources = {(Path(e["directory"]) / e["output"]).resolve(): e["file"] for e in cc if "output" in e}
    for obj in sorted(sources):
        source = sources[obj]
        if not obj.exists():
            continue
        fh = open(obj, "rb")
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        if not isinstance(symtab, SymbolTableSection):
            continue
        comdat = _comdat_sections(elf)
        rel_by_sec: dict[int, dict[int, Reloc]] = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection) and sec.is_RELA():
                rs = rel_by_sec.setdefault(sec["sh_info"], {})
                for r in sec.iter_relocations():
                    s = symtab.get_symbol(r["r_info_sym"])
                    rs[r["r_offset"]] = Reloc(r["r_info_type"], _symbol_name(s, source), s["st_info"]["type"],
                                              s["st_shndx"], s["st_value"], r["r_addend"])
        func_syms = [s for s in symtab.iter_symbols()
                     if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] not in ("SHN_UNDEF", "SHN_ABS")]
        aliases = alias_groups([(_symbol_name(s, source), s["st_shndx"], s["st_value"], s["st_size"])
                                for s in func_syms])
        for s in func_syms:
            sec = elf.get_section(s["st_shndx"])
            v, n = s["st_value"], s["st_size"]
            relocs = {off - v: r for off, r in rel_by_sec.get(s["st_shndx"], {}).items() if v <= off < v + n}
            name = _symbol_name(s, source)
            code = sec.data()[v:v + n]
            bind = s["st_info"]["bind"]
            mergeable = bind == "STB_WEAK" or (bind == "STB_GLOBAL" and s["st_shndx"] in comdat)
            w = add_definition(out, CompiledFunc(name, obj, code, relocs, elf, source, rel_by_sec,
                                                 mergeable, _fingerprint(code, relocs, elf),
                                                 aliases=aliases.get(name, ())))
            if w:
                print(f"warning ({build_dir.name}): {w}")
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


PAGE_RELOCS = (ADR_PREL_PG_HI21, ADR_PREL_PG_HI21_NC, ADR_GOT_PAGE)


def _adrp_page(w: int, pc: int) -> int:
    imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
    imm = imm - (1 << 21) if imm & (1 << 20) else imm
    return (pc & ~0xFFF) + (imm << 12)


def lo12_target(w: int, page: int, t: int) -> int:
    """The address a lo12 instruction `w` (relocation type `t`) forms from `page`."""
    if t == LD64_GOT_LO12_NC:
        return page + _imm12(w) * 8
    if t == ADD_ABS_LO12_NC:
        return page + (_imm12(w) << (12 if (w >> 22) & 1 else 0))
    return page + (_imm12(w) << ldst_scale(w))


def adrp_pairs(relocs: dict[int, Reloc], o_img: bytes, addr: int) -> dict[int, int]:
    """offset -> original target of each lo12 and GOT-lo12 instruction, paired
    with its `adrp` through the compiled relocations: an ADRP relocation of the
    same target whose original instruction writes the lo12's base register (the
    nearest one before it, else after it).

    The original's linear decode (nx.refs.decode) loses a page when an
    instruction in between has that number as its destination field, a SIMD
    write to v9 for x9's page for example. The code here is compared
    instruction by instruction anyway, so the compiled pairing holds for the
    original wherever the instructions agree."""
    def word(off: int) -> int:
        return struct.unpack_from("<I", o_img, addr + off)[0]

    pages = [(off, r) for off, r in sorted(relocs.items()) if r.type in PAGE_RELOCS]
    out: dict[int, int] = {}
    for off, r in relocs.items():
        if not (r.type in (LD64_GOT_LO12_NC, ADD_ABS_LO12_NC) or r.type in LDST_LO12):
            continue
        got = r.type == LD64_GOT_LO12_NC
        rn = (word(off) >> 5) & 0x1F
        cands = [p for p, pr in pages
                 if (pr.type == ADR_GOT_PAGE) == got and (pr.sym, pr.sym_shndx, pr.sym_value) == (r.sym, r.sym_shndx, r.sym_value)
                 and (got or pr.addend == r.addend) and word(p) & 0x1F == rn]
        before = [p for p in cands if p < off]
        p = before[-1] if before else (cands[0] if cands else None)
        if p is not None:
            out[off] = lo12_target(word(off), _adrp_page(word(p), addr + p), r.type)
    return out


def tls_relaxed(t: int, cw: int, ow: int) -> tuple[bool, int | None]:
    """Whether original word `ow` is the linker's local-exec relaxation of the
    TLS descriptor instruction `cw` (relocation `t`), and the bits of the
    thread-pointer offset it holds (hi for the movz, lo for the movk).

    In an executable, lld rewrites `adrp x0, :tlsdesc:v` to `movz x0,
    #:tprel_g1:v, lsl #16`, `ldr x1, [x0, :tlsdesc_lo12:v]` to `movk x0,
    #:tprel_g0_nc:v`, and the `add` and `blr x1` to nops."""
    if t == TLSDESC_ADR_PAGE21:
        ok = (cw & 0x9F00001F) == 0x90000000 and (ow & 0xFFE0001F) == 0xD2A00000  # adrp x0 / movz x0, lsl 16
        return ok, ((ow >> 5) & 0xFFFF) << 16 if ok else None
    if t == TLSDESC_LD64_LO12:
        ok = (cw & 0xFFC003FF) == 0xF9400001 and (ow & 0xFFE0001F) == 0xF2800000  # ldr x1, [x0] / movk x0
        return ok, (ow >> 5) & 0xFFFF if ok else None
    if t == TLSDESC_ADD_LO12:
        return (cw & 0xFFC003FF) == 0x91000000 and ow == NOP, None  # add x0, x0 / nop
    return cw == 0xD63F0020 and ow == NOP, None  # blr x1 / nop


def compare(cf: CompiledFunc, fn: Function, orig: Original, syms, verbose_name,
            paths: SourcePaths | None = None) -> Result:
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
    for off, t in adrp_pairs({o: r for o, r in cf.relocs.items() if o < n - n % 4}, o_img, addr).items():
        if o_targets.get(off) is None:
            o_targets[off] = t

    def expected_addr(r: Reloc) -> tuple[int | None, str]:
        """Absolute expected target for a reloc's symbol (None = unknown) + description."""
        name = r.sym
        if r.sym_type == "STT_SECTION" or (not name or name.startswith(".L")):
            sec = cf.elf.get_section(r.sym_shndx) if isinstance(r.sym_shndx, int) else None
            if sec is not None and not sec["sh_flags"] & SHF_STRINGS:
                # reference into a section of the same object: find the function
                # (code) or object (data) symbol covering the target there
                want = "STT_FUNC" if sec["sh_flags"] & SHF_EXECINSTR else "STT_OBJECT"
                symtab = cf.elf.get_section_by_name(".symtab")
                for s in symtab.iter_symbols():
                    if s["st_shndx"] == r.sym_shndx and s["st_info"]["type"] == want \
                            and s["st_value"] <= r.addend + r.sym_value < s["st_value"] + max(1, s["st_size"]):
                        sname = _symbol_name(s, cf.source)
                        delta = r.addend + r.sym_value - s["st_value"]
                        f = by_name.get(sname)
                        if f is not None and f.addr(v) is not None:
                            return f.addr(v) + delta, sname
                        if sname in data_syms[v]:
                            return data_syms[v][sname] + delta, sname
                        return None, sname
            return None, name or (sec.name if sec is not None else "<section>")
        f = by_name.get(name)
        if f is not None:
            return (f.addr(v) + r.addend if f.addr(v) is not None else None), name
        if name in data_syms[v]:
            return data_syms[v][name] + r.addend, name
        return None, name

    def data_relocs(shndx: int) -> dict[int, Reloc]:
        return cf.obj_relocs.get(shndx, {})

    def literal_error(r: Reloc, otgt: int) -> str | None:
        """Compare the literal `r` points at with the original at `otgt`.

        Returns None if equal, else an error. Pointers inside the literal (jump
        table entries, address tables) are compared by what they point at.
        Raises LookupError if the literal can't be verified."""
        if not isinstance(r.sym_shndx, int):
            raise LookupError
        sec = cf.elf.get_section(r.sym_shndx)
        if sec["sh_type"] == "SHT_NOBITS":
            raise LookupError
        blob = sec.data()
        start = r.sym_value + r.addend
        if sec["sh_flags"] & SHF_STRINGS:
            end = blob.find(b"\0", start)
            end = end + 1 if end >= 0 else len(blob)
            if paths is not None:
                o_end = o_img.find(b"\0", otgt)
                mine = blob[start:end].rstrip(b"\0").decode("latin-1")
                theirs = o_img[otgt:o_end if o_end >= 0 else otgt].decode("latin-1")
                same = paths.compare(cf.source, mine, theirs)
                if same is not None:
                    return None if same else f"source path {mine!r} names another file than the original's {theirs!r}"
        else:
            end = start + (sec["sh_entsize"] or min(MAX_LITERAL, len(blob) - start))
        ptrs = data_relocs(r.sym_shndx)
        label = verbose_name(r.sym) if r.sym else sec.name
        i = start
        while i < end:
            dr = ptrs.get(i)
            if dr is None:
                if blob[i] != o_img[otgt + i - start]:
                    return f"literal {label} contents differ at +{i - start:#x} ({blob[start:end][:24]!r})"
                i += 1
                continue
            at = otgt + i - start
            if dr.type == PREL32:
                # jump tables: `.word .LBB - .LJTI`, relative to the table start (the
                # referenced address), so the reloc addend includes the entry offset
                exp, desc = expected_addr(replace(dr, addend=dr.addend - (i - start)))
                target, i = otgt + struct.unpack_from("<i", o_img, at)[0], i + 4
            elif dr.type == ABS64:
                exp, desc = expected_addr(dr)
                target, i = orig.dyn.slots.get(at), i + 8
            else:
                raise LookupError
            where = f"literal {label} +{at - otgt:#x}"
            if isinstance(target, str):  # imported symbol
                if target != dr.sym:
                    return f"{where}: pointer to {target}, expected {verbose_name(desc)}"
            elif exp is not None:
                if target != exp:
                    return f"{where}: pointer to {verbose_name(desc)} differs"
            elif target is not None and isinstance(dr.sym_shndx, int) \
                    and cf.elf.get_section(dr.sym_shndx)["sh_flags"] & SHF_STRINGS:
                err = literal_error(dr, target)  # pointer to a string: compare the string
                if err:
                    return f"{where}: {err}"
            else:
                raise LookupError  # pointer to something unnamed
        return None

    tls_hi: dict[str, int] = {}  # TLS symbol -> high offset bits of its last movz
    tls: dict[str, tuple[int, set[int]]] = {}  # TLS symbol -> (first access, offsets loaded)
    for off in range(0, n - n % 4, 4):
        cw = struct.unpack_from("<I", cf.code, off)[0]
        ow = struct.unpack_from("<I", o_img, addr + off)[0]
        r = cf.relocs.get(off)
        if r is None:
            if cw == BRK_1 and ow == NX_TRAP:
                bad(off, "trap is `brk #1`, not rewritten to 0xe7ffdefe: the object wasn't compiled "
                         "through tools/fix_traps.py (cmake/TrapEncoding.cmake)")
            elif cw != ow:
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
            sec = cf.elf.get_section(r.sym_shndx) if isinstance(r.sym_shndx, int) else None
            if otgt is not None and (r.sym_type == "STT_FUNC" or sec is not None and sec["sh_flags"] & SHF_EXECINSTR):
                hint = by_addr[v].get(otgt)
                bad(off, f"address of unknown function {verbose_name(desc)} - original uses {otgt + BASE:#x} "
                         f"({hint.display_name if hint else '?'}); name it with tools/funcs.py name")
                continue
            try:
                if otgt is None:
                    raise LookupError
                err = literal_error(r, otgt)
            except LookupError:
                res.warnings.append(f"+{off:#05x}: unverified ref to {verbose_name(desc)}")
            else:
                if err:
                    bad(off, err)
        elif t in TLSDESC:
            ok, bits = tls_relaxed(t, cw, ow)
            if not ok:
                bad(off, f"TLS access to {verbose_name(r.sym)} isn't the local-exec relaxation "
                         f"of the descriptor sequence ({cw:08x} vs {ow:08x})")
            elif t == TLSDESC_ADR_PAGE21:
                tls_hi[r.sym] = bits
            elif t == TLSDESC_LD64_LO12:
                tls.setdefault(r.sym, (off, set()))[1].add(tls_hi.pop(r.sym, 0) | bits)
        else:
            res.warnings.append(f"+{off:#05x}: unhandled relocation type {t} ({r.sym})")
            if cw != ow:
                bad(off, "instruction differs")
    # Every access to one TLS variable must load the same thread-pointer
    # offset. Which variable is at that offset can't be checked: the NSO has no
    # TLS segment table to resolve it with.
    for sym, (first, values) in tls.items():
        if len(values) > 1:
            bad(first, f"TLS accesses to {verbose_name(sym)} load different offsets "
                       f"({', '.join(f'{x:#x}' for x in sorted(values))})")
        else:
            res.warnings.append(f"+{first:#05x}: TLS {verbose_name(sym)} at thread-pointer offset "
                                f"{min(values):#x}, relaxed to local-exec (the offset isn't verified)")
    return res


def tu_spans(compiled: dict[str, CompiledFunc], by_name: dict[str, Function],
             version: str) -> dict[str, tuple[int, int]]:
    """Source -> (lowest, highest) address in `version` of the TU's strong
    functions that have a row: the part of the executable that holds its code."""
    spans: dict[str, tuple[int, int]] = {}
    for name, cf in compiled.items():
        fn = by_name.get(name)
        if cf.mergeable or fn is None or not fn.in_version(version):
            continue
        a = fn.addr(version)
        lo, hi = spans.get(cf.source, (a, a))
        spans[cf.source] = (min(lo, a), max(hi, a))
    return spans


def kept_copy(cf: CompiledFunc, addr: int, spans: dict[str, tuple[int, int]]) -> CompiledFunc | None:
    """The copy of a weak/COMDAT function with differing copies that the
    executable shows the linker kept, or None if it doesn't show it.

    The linker keeps one copy and places it among the code of the TU it took
    it from. So when the original at `addr` lies inside the span (tu_spans) of
    TUs that emit only one of the copies, that's the copy in the executable."""
    if not cf.variants:
        return None
    holders = [c for c in cf.copies()
               if any(s in spans and spans[s][0] <= addr <= spans[s][1] for s in c.sources())]
    return holders[0] if len(holders) == 1 else None


def compare_copies(cf: CompiledFunc, fn: Function, orig: Original, syms,
                   verbose_name, paths: SourcePaths | None = None,
                   spans: dict[str, tuple[int, int]] | None = None) -> list[tuple[CompiledFunc, Result]]:
    """compare() for every distinct copy of a function (one unless weak/COMDAT
    copies differ), or only for the one the linker kept if `spans` show it."""
    kept = kept_copy(cf, fn.addr(orig.version), spans) if spans else None
    if kept is not None:
        res = compare(kept, fn, orig, syms, verbose_name, paths)
        others = ", ".join(c.source for c in cf.copies() if c is not kept)
        res.warnings.append(f"the original is inside {kept.source}'s code, so the linker kept its "
                            f"copy; the differing copies of {others} aren't compared")
        return [(kept, res)]
    return [(c, compare(c, fn, orig, syms, verbose_name, paths)) for c in cf.copies()]


def merge_results(per_copy: list[tuple[CompiledFunc, Result]]) -> Result:
    """One Result for all copies: OK only if every copy matches; messages name the copy's TU."""
    if len(per_copy) == 1:
        return per_copy[0][1]
    out = Result(all(r.ok for _, r in per_copy))
    for c, r in per_copy:
        out.errors += [f"[copy from {c.source}] {e}" for e in r.errors]
        out.warnings += [f"[copy from {c.source}] {w}" for w in r.warnings]
        if out.first_bad is None:
            out.first_bad = r.first_bad
    return out


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
        sym, stem = symbols.split(name)
        if not exe or not sym.startswith("_Z"):
            return name
        if sym not in cache:
            try:
                cache[sym] = subprocess.run([exe, sym], capture_output=True, text=True).stdout.strip() or sym
            except OSError:
                cache[sym] = sym
        return cache[sym] if stem is None else f"{cache[sym]}{symbols.LOCAL_SEP}{stem}"
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
    flags = codegen_flags()
    for v in VERSIONS:
        err = check_codegen_flags(ROOT / "build" / v, flags) or check_trap_rewrite(ROOT / "build" / v)
        if err:
            print(f"error: {err}", file=sys.stderr)
            return 2

    funcs = read_functions_csv()
    syms = load_symbol_tables(funcs)
    by_name = syms[0]
    dm = demangler()
    origs = {v: Original(v) for v in VERSIONS}
    compiled = {v: load_objects(ROOT / "build" / v) for v in VERSIONS}
    paths = SourcePaths(read_source_paths(SOURCE_PATHS_CSV), ROOT)
    # References resolve through aliases too: a call to a complete constructor
    # or destructor (C1/D1) reaches the row of the base one (C2/D2) it aliases.
    syms = (with_aliases(by_name, compiled.values()), *syms[1:])
    spans = {v: tu_spans(compiled[v], by_name, v) for v in VERSIONS}

    wanted = None
    if args.names:
        wanted = set()
        for q in args.names:
            for f in funcs:
                if q in (f.name, f.display_name) or (q.startswith("0x") and int(q, 16) - BASE in (f.sword, f.shield)):
                    wanted.add(f.key)

    all_names = sorted(set().union(*(c.keys() for c in compiled.values())))
    absent = read_absent()
    foreign = read_absent(FOREIGN_CSV)
    unidentified = read_absent(UNIDENTIFIED_CSV)
    n_ok = n_bad = n_absent = n_alias = n_foreign = n_unidentified = 0
    status_updates: dict[str, str] = {}
    for name in all_names:
        fn = by_name.get(name)
        if fn is None and name in absent:
            n_absent += 1
            continue
        if fn is None and name in unidentified:
            n_unidentified += 1
            continue
        if fn is None and any(a in by_name for c in compiled.values() if name in c for a in c[name].aliases):
            n_alias += 1
            continue
        if fn is None:
            if wanted is None:
                print(f"?? {dm(name)}  [{name}] is not in data/functions.csv - assign it: "
                      f"tools/funcs.py name <address> {name}")
            continue
        if wanted is not None and fn.key not in wanted:
            continue
        if name in foreign:
            strong = strong_definition(name, compiled.values())
            if strong is None:
                n_foreign += 1
                continue
            print(f"BAD {fn.scope:11} {dm(name)}  is in data/foreign_copies.csv, but {strong} "
                  f"defines it strongly, so the linker keeps that one")
            n_bad += 1
            continue
        results = {}
        per_copy: dict[str, list[tuple[CompiledFunc, Result]]] = {}
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
            per_copy[v] = compare_copies(cf, fn, origs[v], syms, dm, paths, spans[v])
            results[v] = merge_results(per_copy[v])
        ok = all(r.ok for r in results.values())
        tag = "OK " if ok else "BAD"
        print(f"{tag} {fn.scope:11} {dm(name)}  [{', '.join(f'{v}:{fn.addr(v) + BASE:#x}' for v in VERSIONS if fn.in_version(v))}]")
        for v, r in results.items():
            for e in r.errors:
                print(f"      {v}: {e}")
            if args.verbose or not ok:
                for w in r.warnings:
                    print(f"      {v}: warning: {w}")
            if args.diff and not r.ok:
                for c, cr in per_copy.get(v, []):
                    if not cr.ok:
                        if len(per_copy[v]) > 1:
                            print(f"      {v}: copy from {c.source}:")
                        print(side_by_side(c, fn, origs[v], cr))
        n_ok += ok
        n_bad += not ok
        if ok and fn.status != "O":
            status_updates[fn.key] = "O"
        elif not ok and fn.status == "O":
            status_updates[fn.key] = "M"
            print("      REGRESSION: was marked O in functions.csv")

    print(f"\n{n_ok} matching, {n_bad} not matching")
    if n_absent:
        print(f"({n_absent} compiled functions skipped as not in the executable: data/absent_functions.csv)")
    if n_unidentified:
        print(f"({n_unidentified} compiled functions skipped, their original not identified yet: "
              f"data/unidentified_functions.csv)")
    if n_foreign:
        print(f"({n_foreign} weak/COMDAT functions skipped: the executable keeps another library's copy, "
              f"data/foreign_copies.csv)")
    if n_alias and wanted is None:
        print(f"({n_alias} compiled aliases of checked functions skipped, e.g. D1 = D2 destructors)")
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
