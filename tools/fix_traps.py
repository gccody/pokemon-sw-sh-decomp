#!/usr/bin/env python3
"""Rewrite the AArch64 trap instruction in compiled objects to the NX encoding.

Every trap in the originals (`main` and the SDK modules `sdk`, `subsdk0`,
`subsdk1`, in both games) is the word 0xe7ffdefe, and none of them contains a
`brk`. Upstream clang lowers `llvm.trap` (`__builtin_trap()`, the deleting
destructor of an abstract class, a store or load through a null pointer that
the optimizer proved is reached, ...) to `brk #1` (0xd4200020) instead. The
placement is the same; only the word differs. docs/compiler.md ("Traps") has
the evidence. Nintendo's toolchain encodes the trap that way, and upstream
clang has no option for it, so the build runs every object through this
rewrite (cmake/CodegenFlags.cmake installs it as the compiler launcher):

    python tools/fix_traps.py --run -- <compiler> <args> -o <obj>   # compile, then rewrite <obj>
    python tools/fix_traps.py <obj> ...                             # rewrite objects in place
    python tools/fix_traps.py --check <obj> ...                     # exit 1 if any still has `brk #1`

What is rewritten, and nothing else: a 4-byte-aligned word 0xd4200020 in a
section with SHF_EXECINSTR, inside a code region (after a `$x` mapping symbol
and before the next `$d` one; a code section without mapping symbols counts as
code), with no relocation at that offset. Data in code sections, other `brk`
immediates and non-executable sections are left alone. Objects that aren't
little-endian ELF64 AArch64 relocatables are rejected. Rewriting is idempotent.

Standard library only: the build may run it with a Python that has none of
tools/requirements.txt.
"""
from __future__ import annotations

import argparse
import struct
import subprocess
import sys
from pathlib import Path

BRK_1 = 0xD4200020  # brk #1, upstream LLVM's AArch64 trap
NX_TRAP = 0xE7FFDEFE  # the trap word in the NX originals (the A32 `trap` encoding)

EM_AARCH64 = 183
ET_REL = 1
SHT_SYMTAB, SHT_RELA, SHT_REL = 2, 4, 9
SHF_EXECINSTR = 0x4
SHN_LORESERVE = 0xFF00


class NotAnObject(ValueError):
    pass


def _sections(data: bytes) -> list[dict]:
    if len(data) < 64 or data[:4] != b"\x7fELF":
        raise NotAnObject("not an ELF file")
    if data[4] != 2 or data[5] != 1:
        raise NotAnObject("not a little-endian ELF64 file")
    e_type, e_machine = struct.unpack_from("<HH", data, 16)
    if e_machine != EM_AARCH64:
        raise NotAnObject(f"not an AArch64 object (e_machine {e_machine})")
    if e_type != ET_REL:
        raise NotAnObject(f"not a relocatable object (e_type {e_type})")
    e_shoff, = struct.unpack_from("<Q", data, 40)
    e_shentsize, e_shnum = struct.unpack_from("<HH", data, 58)
    if e_shnum == 0 and e_shoff:
        e_shnum = struct.unpack_from("<Q", data, e_shoff + 32)[0]  # sh_size of section 0
    out = []
    for i in range(e_shnum):
        (name, typ, flags, _addr, off, size, link, info, _align, entsize) = struct.unpack_from(
            "<IIQQQQIIQQ", data, e_shoff + i * e_shentsize)
        out.append({"name": name, "type": typ, "flags": flags, "offset": off, "size": size,
                    "link": link, "info": info, "entsize": entsize})
    return out


def _cstr(data: bytes, off: int) -> str:
    end = data.index(b"\0", off)
    return data[off:end].decode("utf-8", "replace")


def trap_offsets(data: bytes) -> list[int]:
    """File offsets of the `brk #1` words that rewrite() changes."""
    secs = _sections(data)
    # mapping symbols ($x = code, $d = data) and relocated offsets, per section
    marks: dict[int, list[tuple[int, bool]]] = {}
    relocated: dict[int, set[int]] = {}
    for s in secs:
        if s["type"] == SHT_SYMTAB:
            strtab = secs[s["link"]]
            for off in range(s["offset"], s["offset"] + s["size"], s["entsize"] or 24):
                st_name, st_info, _other, st_shndx, st_value, _size = struct.unpack_from("<IBBHQQ", data, off)
                if st_info & 0xF != 0 or st_shndx == 0 or st_shndx >= SHN_LORESERVE:
                    continue  # mapping symbols are local NOTYPE symbols in a real section
                name = _cstr(data, strtab["offset"] + st_name) if st_name else ""
                kind = name.split(".", 1)[0]
                if kind in ("$x", "$d"):
                    marks.setdefault(st_shndx, []).append((st_value, kind == "$x"))
        elif s["type"] in (SHT_RELA, SHT_REL):
            ent = s["entsize"] or (24 if s["type"] == SHT_RELA else 16)
            target = relocated.setdefault(s["info"], set())
            for off in range(s["offset"], s["offset"] + s["size"], ent):
                r_offset, = struct.unpack_from("<Q", data, off)
                target.update(range(r_offset - r_offset % 4, r_offset + 4, 4))

    found = []
    for idx, s in enumerate(secs):
        if not s["flags"] & SHF_EXECINSTR or s["type"] != 1:  # SHT_PROGBITS only
            continue
        regions = sorted(marks.get(idx, [(0, True)]))
        relocs = relocated.get(idx, set())
        for n, (start, is_code) in enumerate(regions):
            if not is_code:
                continue
            end = regions[n + 1][0] if n + 1 < len(regions) else s["size"]
            for rel in range(start + (-start % 4), min(end, s["size"]) - 3, 4):
                if rel in relocs:
                    continue
                if struct.unpack_from("<I", data, s["offset"] + rel)[0] == BRK_1:
                    found.append(s["offset"] + rel)
    return found


def rewrite(data: bytes) -> tuple[bytes, int]:
    """Return `data` with every code `brk #1` replaced by the NX trap word, and the count."""
    offsets = trap_offsets(data)
    if not offsets:
        return data, 0
    out = bytearray(data)
    for off in offsets:
        struct.pack_into("<I", out, off, NX_TRAP)
    return bytes(out), len(offsets)


def rewrite_file(path: Path) -> int:
    data = path.read_bytes()
    new, n = rewrite(data)
    if n:
        tmp = path.with_name(path.name + ".traps.tmp")
        tmp.write_bytes(new)
        tmp.replace(path)
    return n


def output_of(cmd: list[str]) -> Path | None:
    """The object a compiler command line writes (`-o X`, `-oX` or `--output=X`)."""
    out = None
    for i, a in enumerate(cmd):
        if a == "-o" and i + 1 < len(cmd):
            out = cmd[i + 1]
        elif a.startswith("-o") and len(a) > 2 and not a.startswith("-obj"):  # not -objcmt-*
            out = a[2:]
        elif a.startswith("--output="):
            out = a.split("=", 1)[1]
    return Path(out) if out else None


def main(argv: list[str] | None = None) -> int:
    argv = sys.argv[1:] if argv is None else argv
    if "--run" in argv:
        i = argv.index("--run")
        cmd = argv[i + 1:]
        if cmd[:1] == ["--"]:
            cmd = cmd[1:]
        if not cmd:
            print("fix_traps.py: --run needs a compiler command", file=sys.stderr)
            return 2
        try:
            rc = subprocess.call(cmd)
        except OSError as e:
            print(f"fix_traps.py: can't run {cmd[0]}: {e}", file=sys.stderr)
            return 127
        if rc != 0:
            return rc
        out = output_of(cmd)
        if out is None or "-c" not in cmd or "-S" in cmd or "-E" in cmd:
            return 0  # not compiling to an object
        try:
            with open(out, "rb") as f:
                if f.read(4) != b"ELF":
                    return 0  # not an object (assembly, preprocessed source, ...)
            rewrite_file(out)
        except (NotAnObject, OSError) as e:
            print(f"fix_traps.py: {out}: {e}", file=sys.stderr)
            return 1
        return 0

    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("objects", nargs="+", type=Path)
    ap.add_argument("--check", action="store_true", help="only report objects that still contain `brk #1`")
    args = ap.parse_args(argv)
    status = 0
    for p in args.objects:
        try:
            if args.check:
                n = len(trap_offsets(p.read_bytes()))
                if n:
                    print(f"{p}: {n} `brk #1` not rewritten")
                    status = 1
            else:
                n = rewrite_file(p)
                if n:
                    print(f"{p}: rewrote {n} trap(s)")
        except (NotAnObject, OSError) as e:
            print(f"{p}: {e}", file=sys.stderr)
            status = 1
    return status


if __name__ == "__main__":
    sys.exit(main())
