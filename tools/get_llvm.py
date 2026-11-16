#!/usr/bin/env python3
"""Download the toolchain into toolchain/ (gitignored).

    python tools/get_llvm.py                    # --compiler and --tools
    python tools/get_llvm.py --compiler         # toolchain/clang:       clang 7.0.1, the matching compiler
    python tools/get_llvm.py --compiler 6.0.1   # toolchain/clang-6.0.1: clang 6.0.1, for libraries built with it
    python tools/get_llvm.py --tools            # toolchain/llvm-19:     llvm-objdump, llvm-cxxfilt, clang-format, ld.lld
    python tools/get_llvm.py --library-compilers       # every COMPILER_VERSION clang the build needs
    python tools/get_llvm.py --list-library-compilers  # print those versions, one per line

The game was built with a clang 7.0-based compiler (NintendoSDK 7.3.2); see
docs/compiler.md for how that was established. cmake/toolchain-nx64.cmake
picks up toolchain/clang automatically. The newer LLVM utilities are only
used by the tooling (disassembly, demangling, formatting), never to compile.

Some prebuilt libraries were compiled with a different clang (PhysX 3.4:
clang 6.0.1). Their CMake settings name it with
`pkmn_library_settings(... COMPILER_VERSION <version>)`, and building them
needs `--compiler <version>`, which installs that clang into
toolchain/clang-<version>/ with the same layout as toolchain/clang (bin/clang,
bin/clang++ and clang's own headers). Each version has its own directory, so
installing one never touches another.

`--library-compilers` reads the `pkmn_library_settings()` calls in
CMakeLists.txt and installs the COMPILER_VERSION clang of every entry whose
directory has sources (*.c/*.cpp under src/ or lib/, as CMake globs them).
CMake never looks for the compiler of an entry without sources, so neither
does this. Versions that are already installed are skipped, and with no such
entries it does nothing. `--list-library-compilers` prints the versions it
would install, for CI's cache key, so CMakeLists.txt stays the only place that
names them.

On Windows, LLVM 6 and 7 ship only as NSIS installers, so 7-Zip (7z/7za/7zz or
NanaZip) must be on PATH to unpack them. On Linux, clang 7.0.1 needs
libtinfo.so.5 (`libtinfo5` on Debian and Ubuntu up to 22.04); the 6.0.1 build
doesn't link it and runs on Ubuntu 24.04 as is. LLVM published no macOS build
of 6.0.1, only 6.0.0, which compiles PhysX differently, so 6.0.1 is not offered
there. Nothing is installed system-wide.
"""
from __future__ import annotations

import argparse
import platform
import re
import shutil
import subprocess
import sys
import tarfile
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOLCHAIN = ROOT / "toolchain"

DEFAULT_COMPILER = "7.0.1"
_R = "https://releases.llvm.org"
# clang version -> host -> (version of the build, URL). releases.llvm.org hosts
# the LLVM 6 and 7 binaries (GitHub has none for them). The installed clang must
# report the build version. That's the requested version, except for 7.0.1 on
# macOS, which only has a 7.0.0 build: 7.0.0, 7.0.1 and 7.1.0 generate
# identical code on the identification corpus.
COMPILERS: dict[str, dict[tuple[str, str], tuple[str, str]]] = {
    "7.0.1": {
        ("Windows", "AMD64"): ("7.0.1", f"{_R}/7.0.1/LLVM-7.0.1-win64.exe"),
        ("Linux", "x86_64"): ("7.0.1", f"{_R}/7.0.1/clang+llvm-7.0.1-x86_64-linux-gnu-ubuntu-18.04.tar.xz"),
        ("Linux", "aarch64"): ("7.0.1", f"{_R}/7.0.1/clang+llvm-7.0.1-aarch64-linux-gnu.tar.xz"),
        ("Darwin", "x86_64"): ("7.0.0", f"{_R}/7.0.0/clang+llvm-7.0.0-x86_64-apple-darwin.tar.xz"),
        ("Darwin", "arm64"): ("7.0.0", f"{_R}/7.0.0/clang+llvm-7.0.0-x86_64-apple-darwin.tar.xz"),  # Rosetta
    },
    # No macOS build of 6.0.1 exists. 6.0.0 has one, but it differs from 6.0.1
    # in two PhysX functions (Gu::RTree::traverseRay<0>/<1>), so it's no stand-in.
    "6.0.1": {
        ("Windows", "AMD64"): ("6.0.1", f"{_R}/6.0.1/LLVM-6.0.1-win64.exe"),
        ("Linux", "x86_64"): ("6.0.1", f"{_R}/6.0.1/clang+llvm-6.0.1-x86_64-linux-gnu-ubuntu-16.04.tar.xz"),
        ("Linux", "aarch64"): ("6.0.1", f"{_R}/6.0.1/clang+llvm-6.0.1-aarch64-linux-gnu.tar.xz"),
    },
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

# The real binary in a Linux/macOS tarball: bin/clang-7 (LLVM 7), bin/clang-6.0 (LLVM 6).
VERSIONED_CLANG = re.compile(r"clang-\d+(\.\d+)?")


def host() -> tuple[str, str]:
    return platform.system(), platform.machine()


def exe_suffix(on: tuple[str, str]) -> str:
    return ".exe" if on[0] == "Windows" else ""


EXE = exe_suffix(host())


def compiler_dir(version: str, toolchain: Path = TOOLCHAIN) -> Path:
    """toolchain/clang for the matching compiler, toolchain/clang-<version> for any other."""
    return toolchain / ("clang" if version == DEFAULT_COMPILER else f"clang-{version}")


def compiler_arg(value: str) -> str:
    """argparse type for --compiler: one of the versions in COMPILERS."""
    if value not in COMPILERS:
        raise argparse.ArgumentTypeError(
            f"unsupported clang version {value!r} (supported: {', '.join(sorted(COMPILERS))})")
    return value


# --- COMPILER_VERSION entries in CMakeLists.txt ---

# What CMakeLists.txt's PKMN_SOURCES glob counts as a source.
SOURCE_DIRS = ("src", "lib")
SOURCE_SUFFIXES = (".c", ".cpp")

_BRACKET_OPEN = re.compile(r"\[(=*)\[")
_COMMAND = re.compile(r"[A-Za-z_][A-Za-z0-9_]*[ \t]*\(")
_VERSION = re.compile(r"\d+\.\d+\.\d+")


class CMakeParseError(ValueError):
    pass


def cmake_commands(text: str) -> list[tuple[str, list[str], int]]:
    """(lowercased name, arguments, line) of every command call in CMake text.

    A small CMake lexer: # and #[[ ]] comments are skipped, "quoted" and
    [[bracket]] arguments become one argument without their delimiters, and
    unquoted arguments are split on whitespace. Nested parentheses (as in
    if(...) conditions) stay part of the arguments. Variable references are not
    expanded.
    """
    commands = []
    i, n, line = 0, len(text), 1

    def bracket_end(start: int, eq: str) -> int:
        end = text.find(f"]{eq}]", start)
        if end < 0:
            raise CMakeParseError(f"line {line}: unterminated bracket")
        return end

    while i < n:
        c = text[i]
        if c == "#":
            m = _BRACKET_OPEN.match(text, i + 1)
            if m:
                end = bracket_end(m.end(), m.group(1)) + len(m.group(1)) + 2
            else:
                end = text.find("\n", i)
                end = n if end < 0 else end
            line += text.count("\n", i, end)
            i = end
            continue
        m = re.compile(r"[A-Za-z_][A-Za-z0-9_]*[ \t]*\(").match(text, i)
        if not m:
            line += c == "\n"
            i += 1
            continue
        name = m.group(0).rstrip(" \t(").lower()
        start_line = line
        i = m.end()
        args: list[str] = []
        cur: list[str] | None = None
        depth = 1
        while True:
            if i >= n:
                raise CMakeParseError(f"line {start_line}: unterminated {name}(")
            c = text[i]
            if c == '"':
                j = i + 1
                buf = []
                while j < n and text[j] != '"':
                    if text[j] == "\\" and j + 1 < n:
                        buf.append(text[j + 1])
                        j += 2
                    else:
                        buf.append(text[j])
                        j += 1
                if j >= n:
                    raise CMakeParseError(f"line {line}: unterminated string")
                line += text.count("\n", i, j)
                cur = (cur or []) + buf
                i = j + 1
                continue
            if c == "[" and (b := _BRACKET_OPEN.match(text, i)):
                end = bracket_end(b.end(), b.group(1))
                line += text.count("\n", i, end)
                cur = (cur or []) + [text[b.end():end]]
                i = end + len(b.group(1)) + 2
                continue
            if c == "#":  # a comment, which also ends an unquoted argument
                if cur is not None:
                    args.append("".join(cur))
                    cur = None
                b = _BRACKET_OPEN.match(text, i + 1)
                if b:
                    end = bracket_end(b.end(), b.group(1)) + len(b.group(1)) + 2
                else:
                    end = text.find("\n", i)
                    end = n if end < 0 else end
                line += text.count("\n", i, end)
                i = end
                continue
            if c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
                if depth == 0:
                    if cur is not None:
                        args.append("".join(cur))
                    i += 1
                    break
            if c.isspace() and depth == 1:
                if cur is not None:
                    args.append("".join(cur))
                    cur = None
                line += c == "\n"
            else:
                cur = (cur or []) + [c]
            i += 1
        commands.append((name, args, start_line))
    return commands


def library_compiler_entries(text: str) -> list[tuple[str, str]]:
    """(dir, version) of every pkmn_library_settings() call with a COMPILER_VERSION."""
    entries = []
    for name, args, line in cmake_commands(text):
        if name != "pkmn_library_settings" or "COMPILER_VERSION" not in args:
            continue
        dir_ = args[0].rstrip("/")
        k = args.index("COMPILER_VERSION")
        version = args[k + 1] if k + 1 < len(args) else ""
        if not _VERSION.fullmatch(version):
            raise CMakeParseError(f"line {line}: pkmn_library_settings({dir_}): COMPILER_VERSION {version!r} "
                                  "is not a literal full clang version such as 6.0.1")
        entries.append((dir_, version))
    return entries


def has_sources(dir_: str, root: Path = ROOT) -> bool:
    """Whether CMake's PKMN_SOURCES glob finds a source under root/<dir_>/."""
    base = root / dir_
    if not base.is_dir() or not any(base == root / d or root / d in base.parents for d in SOURCE_DIRS):
        return False
    return any(p.suffix in SOURCE_SUFFIXES and p.is_file() for p in base.rglob("*"))


def needed_library_compilers(root: Path = ROOT) -> list[str]:
    """COMPILER_VERSIONs of the entries in root/CMakeLists.txt that have sources:
    sorted, once each, without the main compiler (always installed anyway)."""
    cmakelists = root / "CMakeLists.txt"
    text = cmakelists.read_text(encoding="utf-8") if cmakelists.exists() else ""
    versions = {v for d, v in library_compiler_entries(text) if has_sources(d, root)}
    versions.discard(DEFAULT_COMPILER)
    return sorted(versions, key=lambda v: tuple(map(int, v.split("."))))


def installed_version(clang: Path) -> str | None:
    """The version an existing clang reports, or None if it doesn't run."""
    try:
        r = run_version(clang)
    except OSError:
        return None
    return reported_version(r.stdout) if r.returncode == 0 else None


def install_library_compilers(root: Path = ROOT, toolchain: Path = TOOLCHAIN,
                              on: tuple[str, str] | None = None) -> int:
    on = on or host()
    try:
        versions = needed_library_compilers(root)
    except CMakeParseError as e:
        print(f"CMakeLists.txt: {e}")
        return 1
    if not versions:
        print("no library with sources needs a clang other than the main one")
        return 0
    rc = 0
    for version in versions:
        if version not in COMPILERS:
            print(f"CMakeLists.txt asks for clang {version}, which get_llvm.py can't install "
                  f"(supported: {', '.join(sorted(COMPILERS))})")
            rc = 1
            continue
        asset = COMPILERS[version].get(on)
        out = compiler_dir(version, toolchain)
        clang = out / "bin" / f"clang{exe_suffix(on)}"
        if asset and clang.exists() and installed_version(clang) == asset[0]:
            print(f"ok: clang {version} is already installed in {out}")
            continue
        rc |= install_compiler(version, toolchain, on)
    return rc


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
    """Members of a Linux/macOS LLVM tarball that the compiler needs."""
    if rel.startswith("bin/"):
        name = rel[4:]
        return name == "clang" or VERSIONED_CLANG.fullmatch(name) is not None
    return rel.startswith("lib/clang/") and "/include/" in rel


def finish_layout(out: Path, exe: str = EXE) -> Path:
    """Make sure out/bin has clang and clang++, and return the clang path.

    In the LLVM tarballs bin/clang-7 (bin/clang-6.0 in LLVM 6) is the binary
    and bin/clang is a symlink to it (a plain versioned binary is renamed).
    clang++ is only a name: clang picks the C++ driver from argv[0]. It
    becomes a symlink to clang, saving a second ~80 MB binary, except on
    Windows (exe=".exe"), where it is a copy as before, and wherever a symlink
    can't be created.
    """
    bindir = out / "bin"
    clang = bindir / f"clang{exe}"
    if not clang.exists():
        versioned = sorted(p for p in bindir.iterdir()
                           if p.name.endswith(exe) and VERSIONED_CLANG.fullmatch(p.name[:len(p.name) - len(exe)]))
        if versioned:
            if clang.is_symlink():  # dangling
                clang.unlink()
            versioned[0].rename(clang)
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


def reported_version(version_output: str) -> str | None:
    """The version on the first line of `clang --version` ("clang version 6.0.1 (tags/...)")."""
    first = version_output.splitlines()[0] if version_output else ""
    m = re.search(r"\bclang version (\d+\.\d+\.\d+)\b", first)
    return m.group(1) if m else None


def check_version(version_output: str, want: str) -> str | None:
    """None if `clang --version` printed version `want`, else what's wrong."""
    if reported_version(version_output) == want:
        return None
    first = version_output.splitlines()[0] if version_output else ""
    return f"is not clang {want}: {first!r}"


def run_version(clang: Path) -> subprocess.CompletedProcess:
    return subprocess.run([str(clang), "--version"], capture_output=True, text=True)


def install_compiler(version: str = DEFAULT_COMPILER, toolchain: Path = TOOLCHAIN,
                     on: tuple[str, str] | None = None) -> int:
    on = on or host()
    out = compiler_dir(version, toolchain)
    asset = COMPILERS[version].get(on)
    if asset is None:
        print(f"no prebuilt clang {version} configured for {on}; install it yourself into {out} "
              "(bin/clang, bin/clang++, lib/clang/*/include)"
              + (" or set PKMN_CLANG_ROOT" if version == DEFAULT_COMPILER else ""))
        return 1
    build_version, url = asset
    exe = exe_suffix(on)
    archive = download(url, toolchain / "download" / url.rsplit("/", 1)[1])
    print(f"extracting into {out}")
    if url.endswith(".exe"):
        sevenzip = next((shutil.which(n) for n in ("7z", "7za", "7zz", "NanaZip") if shutil.which(n)), None)
        if sevenzip is None:
            print(f"7-Zip is required to unpack the LLVM {version} Windows installer (e.g. `winget install 7zip.7zip`)")
            return 1
        out.mkdir(parents=True, exist_ok=True)
        subprocess.run([sevenzip, "x", "-y", f"-o{out}", str(archive), f"bin/clang{exe}", "lib/clang/*/include"],
                       check=True, stdout=subprocess.DEVNULL)
    else:
        extract_tar(archive, out, keep_compiler)
    clang = finish_layout(out, exe)
    try:
        r = run_version(clang)
    except OSError as e:
        print(f"installed, but {clang} does not run: {e}")
        return 1
    if r.returncode != 0:
        print(f"installed, but {clang} does not run (exit {r.returncode}):\n{r.stderr.strip()}")
        hint = run_failure_hint(r.stderr)
        if hint:
            print(hint)
        return 1
    problem = check_version(r.stdout, build_version)
    if problem:
        print(f"installed, but {clang} {problem}")
        return 1
    archive.unlink()
    print(f"ok: {r.stdout.splitlines()[0]}")
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


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--compiler", nargs="?", const=DEFAULT_COMPILER, type=compiler_arg, metavar="VERSION",
                    help=f"only install clang VERSION (default {DEFAULT_COMPILER}; "
                         f"supported: {', '.join(sorted(COMPILERS))})")
    ap.add_argument("--tools", action="store_true", help=f"only install the LLVM {TOOLS_VERSION} utilities")
    ap.add_argument("--library-compilers", action="store_true",
                    help="install the COMPILER_VERSION clang of every pkmn_library_settings() entry "
                         "in CMakeLists.txt that has sources")
    ap.add_argument("--list-library-compilers", action="store_true",
                    help="print the versions --library-compilers installs, one per line, and exit")
    args = ap.parse_args(argv)
    if args.list_library_compilers:
        if args.compiler or args.tools or args.library_compilers:
            ap.error("--list-library-compilers can't be combined with other options")
    elif args.compiler is None and not args.tools and not args.library_compilers:
        # nothing chosen: the matching compiler and the tools
        args.compiler, args.tools = DEFAULT_COMPILER, True
    return args


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    if args.list_library_compilers:
        try:
            versions = needed_library_compilers(ROOT)
        except CMakeParseError as e:
            print(f"CMakeLists.txt: {e}", file=sys.stderr)
            return 1
        print("\n".join(versions), end="\n" if versions else "")
        return 0
    rc = 0
    if args.compiler:
        rc |= install_compiler(args.compiler)
    if args.library_compilers:
        rc |= install_library_compilers(ROOT)
    if args.tools:
        rc |= install_tools()
    return rc


if __name__ == "__main__":
    sys.exit(main())
