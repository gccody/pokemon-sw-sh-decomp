#!/usr/bin/env python3
"""Download the toolchain into toolchain/ (gitignored).

    python tools/get_llvm.py              # both of the below
    python tools/get_llvm.py --compiler   # toolchain/clang:   clang 7.0.1, the matching compiler
    python tools/get_llvm.py --tools      # toolchain/llvm-19: llvm-objdump, llvm-cxxfilt, clang-format, ld.lld

The game was built with a clang 7.0-based compiler (NintendoSDK 7.3.2); see
docs/compiler.md for how that was established. cmake/toolchain-nx64.cmake
picks up toolchain/clang automatically. The newer LLVM utilities are only
used by the tooling (disassembly, demangling, formatting), never to compile.

On Windows, LLVM 7 ships only as an NSIS installer, so 7-Zip (7z/7za/7zz or
NanaZip) must be on PATH to unpack it. On Linux it needs libtinfo.so.5
(`libtinfo5` on Debian and Ubuntu up to 22.04). Nothing is installed system-wide.
"""
from __future__ import annotations

import argparse
import platform
import shutil
import subprocess
import sys
import tarfile
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOLCHAIN = ROOT / "toolchain"
EXE = ".exe" if platform.system() == "Windows" else ""

COMPILER_VERSION = "7.0.1"
# releases.llvm.org hosts the LLVM 7 binaries (GitHub has none for 7.0.x).
# macOS only has a 7.0.0 build; 7.0.0, 7.0.1 and 7.1.0 generate identical
# code on the identification corpus.
COMPILER_ASSETS = {
    ("Windows", "AMD64"): "https://releases.llvm.org/7.0.1/LLVM-7.0.1-win64.exe",
    ("Linux", "x86_64"): "https://releases.llvm.org/7.0.1/clang+llvm-7.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz",
    ("Linux", "aarch64"): "https://releases.llvm.org/7.0.1/clang+llvm-7.0.1-aarch64-linux-gnu.tar.xz",
    ("Darwin", "x86_64"): "https://releases.llvm.org/7.0.0/clang+llvm-7.0.0-x86_64-apple-darwin.tar.xz",
    ("Darwin", "arm64"): "https://releases.llvm.org/7.0.0/clang+llvm-7.0.0-x86_64-apple-darwin.tar.xz",  # Rosetta
}

TOOLS_VERSION = "19.1.7"
TOOLS_ASSETS = {
    ("Windows", "AMD64"): f"clang+llvm-{TOOLS_VERSION}-x86_64-pc-windows-msvc.tar.xz",
    ("Linux", "x86_64"): f"LLVM-{TOOLS_VERSION}-Linux-X64.tar.xz",
    ("Linux", "aarch64"): f"clang+llvm-{TOOLS_VERSION}-aarch64-linux-gnu.tar.xz",
    ("Darwin", "arm64"): f"LLVM-{TOOLS_VERSION}-macOS-ARM64.tar.xz",
    ("Darwin", "x86_64"): f"LLVM-{TOOLS_VERSION}-macOS-X64.tar.xz",
}
TOOLS_WANT = {"ld.lld", "llvm-objdump", "llvm-cxxfilt", "llvm-readelf", "clang-format"}


def host() -> tuple[str, str]:
    return platform.system(), platform.machine()


def download(url: str, dest: Path) -> Path:
    dest.parent.mkdir(parents=True, exist_ok=True)
    if not dest.exists():
        print(f"downloading {url}")
        part = dest.with_suffix(dest.suffix + ".part")
        with urllib.request.urlopen(url) as r, open(part, "wb") as f:
            shutil.copyfileobj(r, f, 1 << 20)
        part.replace(dest)
    return dest


def extract_tar(tarball: Path, out: Path, keep) -> None:
    """Extract members for which keep(relative path) is true, stripping the top dir."""
    with tarfile.open(tarball, "r|xz") as t:
        for m in t:
            parts = m.name.split("/", 1)
            if len(parts) == 2 and keep(parts[1]):
                m.name = parts[1]
                t.extract(m, out, filter="data")


def keep_compiler(rel: str) -> bool:
    """Members of a Linux/macOS LLVM 7 tarball that the compiler needs."""
    return rel in ("bin/clang", "bin/clang-7") or (rel.startswith("lib/clang/") and "/include/" in rel)


def finish_layout(out: Path, exe: str = EXE) -> Path:
    """Make sure out/bin has clang and clang++, and return the clang path.

    In the LLVM 7 tarballs bin/clang-7 is the binary and bin/clang is a
    symlink to it (a plain clang-7 is renamed). clang++ is only a name: clang
    picks the C++ driver from argv[0]. It becomes a symlink to clang, saving
    a second ~80 MB binary, except on Windows (exe=".exe"), where it is a
    copy as before, and wherever a symlink can't be created.
    """
    bindir = out / "bin"
    clang = bindir / f"clang{exe}"
    clang7 = bindir / f"clang-7{exe}"
    if not clang.exists() and clang7.exists():
        if clang.is_symlink():  # dangling
            clang.unlink()
        clang7.rename(clang)
    clangxx = bindir / f"clang++{exe}"
    if not clangxx.exists():
        if clangxx.is_symlink():
            clangxx.unlink()
        linked = False
        if not exe:
            try:
                clangxx.symlink_to(clang.name)
                linked = True
            except OSError:
                pass
        if not linked:
            shutil.copy2(clang, clangxx)
    return clang


def run_failure_hint(stderr: str) -> str | None:
    """Explain the usual reason a freshly unpacked LLVM 7 doesn't start."""
    if "libtinfo.so.5" in stderr:
        return ("the Linux builds of LLVM 7 need libtinfo.so.5: install libtinfo5 (Debian, Ubuntu <= 22.04) "
                "or ncurses5-compat-libs. Ubuntu 24.04 no longer ships it, and on Debian/Ubuntu a symlink to "
                "libtinfo.so.6 is not enough (its symbols carry different version tags)")
    return None


def install_compiler() -> int:
    url = COMPILER_ASSETS.get(host())
    if url is None:
        print(f"no prebuilt clang {COMPILER_VERSION} configured for {host()}; "
              f"install it yourself and set PKMN_CLANG_ROOT")
        return 1
    out = TOOLCHAIN / "clang"
    archive = download(url, TOOLCHAIN / "download" / url.rsplit("/", 1)[1])
    print(f"extracting into {out}")
    if url.endswith(".exe"):
        sevenzip = next((shutil.which(n) for n in ("7z", "7za", "7zz", "NanaZip") if shutil.which(n)), None)
        if sevenzip is None:
            print("7-Zip is required to unpack the LLVM 7 Windows installer (e.g. `winget install 7zip.7zip`)")
            return 1
        out.mkdir(parents=True, exist_ok=True)
        subprocess.run([sevenzip, "x", "-y", f"-o{out}", str(archive), f"bin/clang{EXE}", "lib/clang/*/include"],
                       check=True, stdout=subprocess.DEVNULL)
    else:
        extract_tar(archive, out, keep_compiler)
    clang = finish_layout(out)
    try:
        r = subprocess.run([str(clang), "--version"], capture_output=True, text=True)
    except OSError as e:
        print(f"installed, but {clang} does not run: {e}")
        return 1
    if r.returncode != 0:
        print(f"installed, but {clang} does not run (exit {r.returncode}):\n{r.stderr.strip()}")
        hint = run_failure_hint(r.stderr)
        if hint:
            print(hint)
        return 1
    ver = r.stdout.splitlines()[0] if r.stdout else ""
    if "version 7.0." not in ver:
        print(f"installed, but {clang} is not clang 7.0.x: {ver!r}")
        return 1
    archive.unlink()
    print(f"ok: {ver}")
    return 0


def install_tools() -> int:
    asset = TOOLS_ASSETS.get(host())
    if asset is None:
        print(f"no prebuilt LLVM {TOOLS_VERSION} configured for {host()}; any recent llvm-objdump/llvm-cxxfilt on PATH works")
        return 1
    out = TOOLCHAIN / "llvm-19"
    url = f"https://github.com/llvm/llvm-project/releases/download/llvmorg-{TOOLS_VERSION}/{asset}"
    archive = download(url, TOOLCHAIN / "download" / asset)
    print(f"extracting into {out}")
    extract_tar(archive, out, lambda rel: rel.startswith("bin/") and rel[4:].removesuffix(EXE) in TOOLS_WANT)
    archive.unlink()
    print(f"ok: {out / 'bin'}")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--compiler", action="store_true", help=f"only install clang {COMPILER_VERSION}")
    ap.add_argument("--tools", action="store_true", help=f"only install the LLVM {TOOLS_VERSION} utilities")
    args = ap.parse_args()
    both = not (args.compiler or args.tools)
    rc = 0
    if args.compiler or both:
        rc |= install_compiler()
    if args.tools or both:
        rc |= install_tools()
    return rc


if __name__ == "__main__":
    sys.exit(main())
