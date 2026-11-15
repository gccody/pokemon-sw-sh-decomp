"""Shared paths, version metadata and the functions.csv format."""
from __future__ import annotations

import csv
import json
import pickle
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ORIGINAL = ROOT / "data" / "original"   # gitignored: per-contributor extracted binaries
CACHE = ROOT / "build" / "cache"
VERSIONS = ("sword", "shield")
BASE = 0x7100000000  # conventional load address used by IDA/Ghidra/decomp.me

VERSION_INFO = json.loads((ROOT / "tools" / "versions.json").read_text())


# --------------------------------------------------------------------------- module loading
def nso_path(version: str) -> Path:
    return ORIGINAL / version / "main"


def load_module(version: str) -> dict:
    """Decompressed image + function list for a version's main, cached."""
    from nx.ehframe import functions_from_eh_frame
    from nx.nso import Nso

    src = nso_path(version)
    if not src.exists():
        raise SystemExit(f"{src} missing - run tools/setup.py first")
    cache = CACHE / f"{version}.pickle"
    if cache.exists() and cache.stat().st_mtime >= src.stat().st_mtime:
        return pickle.loads(cache.read_bytes())
    nso = Nso(src.read_bytes())
    img = nso.image()
    funcs = functions_from_eh_frame(img, nso.mod0.eh_frame_hdr_start)
    funcs = sorted(funcs + _fde_less_functions(img, funcs))
    mod = {
        "image": img,
        "functions": funcs,
        "text_end": nso.text.end,
        "rodata": (nso.rodata.mem_off, nso.rodata.end),
        "data_start": nso.data.mem_off,
        "bss": (nso.mod0.bss_start, nso.mod0.bss_end),
        "build_id": nso.build_id[:0x14].hex(),
    }
    CACHE.mkdir(parents=True, exist_ok=True)
    cache.write_bytes(pickle.dumps(mod))
    return mod


def _fde_less_functions(img: bytes, funcs: list[tuple[int, int]]) -> list[tuple[int, int]]:
    """Code between FDE-covered functions (nounwind asm/noreturn stubs).

    Gaps are normally alignment padding (0 / udf #0, or NOP); anything else is
    treated as one extra function spanning the non-padding words."""
    import struct
    pad = {0x00000000, 0xD503201F}
    extra = []
    for (a, s), (b, _) in zip(funcs, funcs[1:]):
        words = [(o, struct.unpack_from("<I", img, o)[0]) for o in range(a + s, b, 4)]
        code = [o for o, w in words if w not in pad]
        if code:
            extra.append((code[0], code[-1] + 4 - code[0]))
    return extra


# --------------------------------------------------------------------------- functions.csv
# Status (same letters as botw / OdysseyDecomp):
#   O = matching   m = minor diff (regalloc/ordering)   M = major diff / non-matching
#   U = undecompiled   L = library (decompiled elsewhere / not our code)
STATUSES = ("O", "m", "M", "U", "L")
SCOPES = ("common", "common-data", "diverged", "sword", "shield")
HEADER = ["Sword", "SwordSize", "Shield", "ShieldSize", "Scope", "Status", "Name"]


def _addr(s: str) -> int | None:
    return int(s, 16) - BASE if s else None


def _fmt(a: int | None) -> str:
    return f"0x{a + BASE:016x}" if a is not None else ""


@dataclass
class Function:
    sword: int | None
    shield: int | None
    sword_size: int | None
    shield_size: int | None
    scope: str
    status: str = "U"
    name: str = ""
    extra: dict = field(default_factory=dict)

    @property
    def key(self) -> str:
        return f"sw:{self.sword:x}" if self.sword is not None else f"sh:{self.shield:x}"

    @property
    def sword_str(self) -> str:
        return _fmt(self.sword)

    @property
    def shield_str(self) -> str:
        return _fmt(self.shield)

    def addr(self, version: str) -> int | None:
        return self.sword if version == "sword" else self.shield

    def size(self, version: str) -> int | None:
        return self.sword_size if version == "sword" else self.shield_size

    def in_version(self, version: str) -> bool:
        return self.addr(version) is not None

    @property
    def display_name(self) -> str:
        if self.name:
            return self.name
        return f"FUN_{self.sword + BASE:010x}" if self.sword is not None else f"FUN_sh_{self.shield + BASE:010x}"


def read_functions_csv(path: Path | None = None) -> list[Function]:
    path = path or ROOT / "data" / "functions.csv"
    out = []
    with open(path, newline="", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            out.append(Function(
                sword=_addr(r["Sword"]), shield=_addr(r["Shield"]),
                sword_size=int(r["SwordSize"]) if r["SwordSize"] else None,
                shield_size=int(r["ShieldSize"]) if r["ShieldSize"] else None,
                scope=r["Scope"], status=r["Status"], name=r["Name"]))
    return out


def write_functions_csv(path: Path, rows: list[Function]) -> None:
    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f, lineterminator="\n")
        w.writerow(HEADER)
        for r in rows:
            w.writerow([r.sword_str, r.sword_size if r.sword_size is not None else "",
                        r.shield_str, r.shield_size if r.shield_size is not None else "",
                        r.scope, r.status, r.name])
