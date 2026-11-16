"""compiler_sweep.py's BASE_FLAGS must stay the C-safe subset of
cmake/toolchain-nx64.cmake's PKMN_CODEGEN_FLAGS (minus the -O level), so the
sweeps measure the flags the decomp really builds with."""
from __future__ import annotations

import re

from compiler_sweep import BASE_FLAGS
from common import ROOT

TOOLCHAIN = ROOT / "cmake" / "toolchain-nx64.cmake"

# Toolchain flags the sweep leaves out on purpose, and why.
EXCLUDED = {
    "-O3": "the -O level is what the sweeps vary (each variant sets its own)",
    "-fno-exceptions": "C++ only; PhysX needs -fexceptions, so C++ corpora pass it explicitly",
    "-fno-rtti": "C++ only; C++ corpora pass it after --",
    "-nostdinc++": "C++ only; C++ corpora pass it (and their libc++ include path) after --",
}

# BASE_FLAGS entries that PKMN_CODEGEN_FLAGS doesn't list, and why.
SWEEP_ONLY = {
    "--target=aarch64-none-elf": "CMake passes the target through CMAKE_C_COMPILER_TARGET",
    "-nostdlibinc": "the sweep compiles against toolchain/candidates/sysroot, not the host's headers",
    "-g": "debug info (docs/compiler.md, 'Debug info')",
}

# Flags whose position can't matter: nothing else in either list switches them.
ORDER_FREE = {"-g"}


def toolchain_flags(text: str) -> list[str]:
    m = re.search(r"set\(PKMN_CODEGEN_FLAGS\b(.*?)\n\)", text, re.S)
    assert m, "PKMN_CODEGEN_FLAGS not found"
    body = "\n".join(line.split("#", 1)[0] for line in m.group(1).splitlines())
    return body.split()


def compiler_target(text: str) -> str:
    m = re.search(r"set\(CMAKE_C_COMPILER_TARGET\s+(\S+)\)", text)
    assert m, "CMAKE_C_COMPILER_TARGET not found"
    return m.group(1)


def test_parser_handles_comments_and_trailing_flags():
    text = "set(PKMN_CODEGEN_FLAGS\n  -a   # note -b\n  -c\n  -O3\n)\nset(X -d)\n"
    assert toolchain_flags(text) == ["-a", "-c", "-O3"]


def test_base_flags_are_toolchain_flags():
    text = TOOLCHAIN.read_text(encoding="utf-8")
    tc = toolchain_flags(text)
    assert f"--target={compiler_target(text)}" in BASE_FLAGS
    unknown = [f for f in BASE_FLAGS if f not in tc and f not in SWEEP_ONLY]
    assert not unknown, f"BASE_FLAGS entries missing from PKMN_CODEGEN_FLAGS: {unknown}"


def test_only_documented_toolchain_flags_are_left_out():
    tc = toolchain_flags(TOOLCHAIN.read_text(encoding="utf-8"))
    missing = {f for f in tc if f not in BASE_FLAGS}
    assert missing == set(EXCLUDED), (
        f"undocumented: {sorted(missing - set(EXCLUDED))}, stale: {sorted(set(EXCLUDED) - missing)}")


def test_shared_flags_keep_the_toolchain_order():
    tc = toolchain_flags(TOOLCHAIN.read_text(encoding="utf-8"))
    shared = set(tc) & set(BASE_FLAGS) - ORDER_FREE
    assert [f for f in BASE_FLAGS if f in shared] == [f for f in tc if f in shared]
