"""tools/get_llvm.py without the network: synthetic archives laid out like the
LLVM 6/7 release tarballs."""
from __future__ import annotations

import io
import os
import subprocess
import tarfile

import pytest

import get_llvm

TOP = "clang+llvm-7.0.1-x86_64-linux-gnu-ubuntu-18.04"


def can_symlink(tmp_path) -> bool:
    try:
        os.symlink("target", tmp_path / "probe")
    except (OSError, NotImplementedError):
        return False
    os.unlink(tmp_path / "probe")
    return True


def make_tarball(path, files: dict[str, bytes], links: dict[str, str], top: str = TOP) -> None:
    """Write a .tar.xz with everything under TOP/. Symlinks come first, before
    their targets, as the stream extractor can see them in any order."""
    with tarfile.open(path, "w:xz") as t:
        for name, target in links.items():
            info = tarfile.TarInfo(f"{top}/{name}")
            info.type = tarfile.SYMTYPE
            info.linkname = target
            t.addfile(info)
        for name, data in files.items():
            info = tarfile.TarInfo(f"{top}/{name}")
            info.size = len(data)
            info.mode = 0o755
            t.addfile(info, io.BytesIO(data))


@pytest.mark.parametrize("rel, keep", [
    ("bin/clang", True),
    ("bin/clang-7", True),
    ("bin/clang-6.0", True),
    ("bin/clang++", False),
    ("bin/clang-cl", False),
    ("bin/clang-format", False),
    ("bin/llvm-ar", False),
    ("lib/clang/7.0.1/include/stddef.h", True),
    ("lib/clang/7.0.1/include/sanitizer/asan_interface.h", True),
    ("lib/clang/7.0.1/lib/linux/libclang_rt.asan-x86_64.a", False),
    ("lib/libLLVM.a", False),
])
def test_keep_compiler(rel, keep):
    assert get_llvm.keep_compiler(rel) is keep


def test_linux_tarball_with_symlinks(tmp_path):
    if not can_symlink(tmp_path):
        pytest.skip("symlinks not available on this platform/account")
    tarball = tmp_path / "llvm.tar.xz"
    make_tarball(tarball,
                 files={"bin/clang-7": b"CLANG", "bin/llvm-ar": b"AR",
                        "lib/clang/7.0.1/include/stddef.h": b"/* */",
                        "lib/libLLVM.a": b"LIB"},
                 links={"bin/clang": "clang-7", "bin/clang++": "clang", "bin/clang-cl": "clang"})
    out = tmp_path / "clang"
    get_llvm.extract_tar(tarball, out, get_llvm.keep_compiler)
    clang = get_llvm.finish_layout(out, exe="")

    assert clang == out / "bin" / "clang"
    assert sorted(p.name for p in (out / "bin").iterdir()) == ["clang", "clang++", "clang-7"]
    assert os.readlink(out / "bin" / "clang") == "clang-7"
    # clang++ is a link to clang, not a second copy of the binary
    assert os.readlink(out / "bin" / "clang++") == "clang"
    assert (out / "bin" / "clang++").read_bytes() == b"CLANG"
    assert (out / "lib" / "clang" / "7.0.1" / "include" / "stddef.h").exists()
    assert not (out / "lib" / "libLLVM.a").exists()


def test_plain_clang7_is_renamed(tmp_path):
    bindir = tmp_path / "bin"
    bindir.mkdir()
    (bindir / "clang-7").write_bytes(b"CLANG")
    clang = get_llvm.finish_layout(tmp_path, exe="")
    assert clang == bindir / "clang"
    assert clang.read_bytes() == b"CLANG"
    assert not (bindir / "clang-7").exists()
    assert (bindir / "clang++").read_bytes() == b"CLANG"  # symlink, or copy where that isn't allowed


def test_dangling_clang_symlink_is_replaced(tmp_path):
    if not can_symlink(tmp_path):
        pytest.skip("symlinks not available on this platform/account")
    bindir = tmp_path / "bin"
    bindir.mkdir()
    (bindir / "clang").symlink_to("missing")
    (bindir / "clang-7").write_bytes(b"CLANG")
    clang = get_llvm.finish_layout(tmp_path, exe="")
    assert not clang.is_symlink()
    assert clang.read_bytes() == b"CLANG"


def test_windows_layout_copies_clangxx(tmp_path):
    bindir = tmp_path / "bin"
    bindir.mkdir()
    (bindir / "clang.exe").write_bytes(b"CLANG")
    clang = get_llvm.finish_layout(tmp_path, exe=".exe")
    clangxx = bindir / "clang++.exe"
    assert clang == bindir / "clang.exe"
    assert clangxx.read_bytes() == b"CLANG"
    assert not clangxx.is_symlink()


def test_finish_layout_is_idempotent(tmp_path):
    bindir = tmp_path / "bin"
    bindir.mkdir()
    (bindir / "clang-7").write_bytes(b"CLANG")
    get_llvm.finish_layout(tmp_path, exe="")
    get_llvm.finish_layout(tmp_path, exe="")
    assert sorted(p.name for p in bindir.iterdir()) == ["clang", "clang++"]


def test_run_failure_hint():
    err = ("clang: error while loading shared libraries: libtinfo.so.5: "
           "cannot open shared object file: No such file or directory")
    assert "libtinfo5" in get_llvm.run_failure_hint(err)
    assert get_llvm.run_failure_hint("Segmentation fault") is None


def test_plain_clang60_is_renamed(tmp_path):
    """LLVM 6 names the binary clang-6.0 (major.minor), LLVM 7 clang-7."""
    bindir = tmp_path / "bin"
    bindir.mkdir()
    (bindir / "clang-6.0").write_bytes(b"CLANG6")
    clang = get_llvm.finish_layout(tmp_path, exe="")
    assert clang.read_bytes() == b"CLANG6"
    assert sorted(p.name for p in bindir.iterdir()) == ["clang", "clang++"]


# --- versions, arguments, output directories ---

def test_parse_args_defaults():
    a = get_llvm.parse_args([])
    assert (a.compiler, a.tools) == (get_llvm.DEFAULT_COMPILER, True)
    a = get_llvm.parse_args(["--compiler"])
    assert (a.compiler, a.tools) == ("7.0.1", False)
    a = get_llvm.parse_args(["--tools"])
    assert (a.compiler, a.tools) == (None, True)
    a = get_llvm.parse_args(["--compiler", "--tools"])
    assert (a.compiler, a.tools) == ("7.0.1", True)


@pytest.mark.parametrize("argv", [["--compiler", "6.0.1"], ["--compiler=6.0.1"]])
def test_parse_args_version(argv):
    a = get_llvm.parse_args(argv)
    assert (a.compiler, a.tools) == ("6.0.1", False)


@pytest.mark.parametrize("bad", ["6.0.0", "7", "latest"])
def test_parse_args_unknown_version(bad, capsys):
    with pytest.raises(SystemExit) as e:
        get_llvm.parse_args(["--compiler", bad])
    assert e.value.code == 2
    err = capsys.readouterr().err
    assert f"unsupported clang version '{bad}'" in err
    assert "supported: 6.0.1, 7.0.1" in err


def test_compiler_dir(tmp_path):
    assert get_llvm.compiler_dir("7.0.1", tmp_path) == tmp_path / "clang"
    assert get_llvm.compiler_dir("6.0.1", tmp_path) == tmp_path / "clang-6.0.1"
    assert get_llvm.compiler_dir("6.0.1") == get_llvm.TOOLCHAIN / "clang-6.0.1"


def test_compiler_table():
    assert get_llvm.DEFAULT_COMPILER in get_llvm.COMPILERS
    for version, assets in get_llvm.COMPILERS.items():
        for on, (build, url) in assets.items():
            assert f"/{build}/" in url and build in url.rsplit("/", 1)[1], (version, on)
            # Only the documented macOS stand-in may differ from the requested version.
            assert build == version or (version, build, on[0]) == ("7.0.1", "7.0.0", "Darwin")
    # LLVM never published a macOS 6.0.1 build.
    assert not any(on[0] == "Darwin" for on in get_llvm.COMPILERS["6.0.1"])


@pytest.mark.parametrize("out, want, ok", [
    ("clang version 7.0.1 (tags/RELEASE_701/final)\nTarget: x86_64-pc-windows-msvc\n", "7.0.1", True),
    ("clang version 6.0.1 (tags/RELEASE_601/final)\nTarget: x86_64-unknown-linux-gnu\n", "6.0.1", True),
    ("clang version 7.0.0 (tags/RELEASE_700/final)\n", "7.0.0", True),
    ("clang version 7.0.1 (tags/RELEASE_701/final)\n", "6.0.1", False),
    ("clang version 6.0.10\n", "6.0.1", False),
    ("clang version 16.0.1\n", "6.0.1", False),
    ("Target: x86_64\nclang version 6.0.1\n", "6.0.1", False),  # version must be on the first line
    ("", "6.0.1", False),
])
def test_check_version(out, want, ok):
    problem = get_llvm.check_version(out, want)
    assert (problem is None) is ok
    if not ok:
        assert f"is not clang {want}" in problem


def fake_install(tmp_path, monkeypatch, version, reported, on=("Linux", "x86_64")):
    """Run install_compiler against a synthetic tarball and a fake `clang --version`."""
    tarball = tmp_path / "dl.tar.xz"
    major = version.split(".")[0]
    binary = "clang-6.0" if major == "6" else f"clang-{major}"
    make_tarball(tarball, files={f"bin/{binary}": b"CLANG", f"lib/clang/{version}/include/stddef.h": b"/* */",
                                 "bin/llvm-ar": b"AR"},
                 links={}, top=f"clang+llvm-{version}-x86_64-linux-gnu")
    monkeypatch.setattr(get_llvm, "download", lambda url, dest: tarball)
    seen = []

    def run_version(clang):
        seen.append(clang)
        return subprocess.CompletedProcess([str(clang), "--version"], 0, f"clang version {reported} (tags)\n", "")

    monkeypatch.setattr(get_llvm, "run_version", run_version)
    toolchain = tmp_path / "toolchain"
    rc = get_llvm.install_compiler(version, toolchain, on)
    return rc, toolchain, seen


def test_install_second_compiler_goes_to_its_own_dir(tmp_path, monkeypatch, capsys):
    rc, toolchain, seen = fake_install(tmp_path, monkeypatch, "6.0.1", "6.0.1")
    assert rc == 0
    out = toolchain / "clang-6.0.1"
    assert seen == [out / "bin" / "clang"]
    assert (out / "bin" / "clang").read_bytes() == b"CLANG"
    assert (out / "bin" / "clang++").read_bytes() == b"CLANG"
    assert (out / "lib" / "clang" / "6.0.1" / "include" / "stddef.h").exists()
    assert not (toolchain / "clang").exists()  # the matching compiler's dir is untouched
    assert "ok: clang version 6.0.1" in capsys.readouterr().out


def test_install_default_compiler_dir(tmp_path, monkeypatch):
    rc, toolchain, _ = fake_install(tmp_path, monkeypatch, "7.0.1", "7.0.1")
    assert rc == 0
    assert (toolchain / "clang" / "bin" / "clang").exists()
    assert not (toolchain / "clang-7.0.1").exists()


def test_install_rejects_wrong_version(tmp_path, monkeypatch, capsys):
    rc, _, _ = fake_install(tmp_path, monkeypatch, "6.0.1", "7.0.1")
    assert rc == 1
    assert "is not clang 6.0.1" in capsys.readouterr().out


def test_install_macos_7_accepts_its_700_build(tmp_path, monkeypatch):
    rc, _, _ = fake_install(tmp_path, monkeypatch, "7.0.1", "7.0.0", on=("Darwin", "arm64"))
    assert rc == 0


def test_install_unsupported_host(tmp_path, monkeypatch, capsys):
    monkeypatch.setattr(get_llvm, "download", lambda url, dest: pytest.fail("must not download"))
    assert get_llvm.install_compiler("6.0.1", tmp_path, ("Darwin", "arm64")) == 1
    out = capsys.readouterr().out
    assert "no prebuilt clang 6.0.1" in out and "clang-6.0.1" in out
    assert not (tmp_path / "clang-6.0.1").exists()


# --- --library-compilers: COMPILER_VERSION entries in CMakeLists.txt ---

SETTINGS = """\
include(cmake/LibrarySettings.cmake)

# pkmn_library_settings(lib/commented COMPILER_VERSION 5.0.2)
#[[ pkmn_library_settings(lib/bracket-commented COMPILER_VERSION 5.0.2) ]]
pkmn_library_settings(lib/lua
  EVIDENCE "docs/compiler.md, section Method (a (paren) and \\"quotes\\")"
  DEFINES LUA_COMPAT_5_2 LUA_USE_POSIX)

PKMN_Library_Settings(lib/physx/  # trailing slash, odd case, comment inside
  EVIDENCE [=[docs/compiler.md, COMPILER_VERSION 9.9.9 in a bracket]=]
  COMPILER_VERSION 6.0.1
  OPTIONS -fexceptions $<$<COMPILE_LANGUAGE:CXX>:-std=gnu++14>)
my_pkmn_library_settings(lib/other COMPILER_VERSION 5.0.2)
pkmn_library_settings(src/game COMPILER_VERSION "7.0.1")
"""


def test_cmake_commands_lexer():
    cmds = get_llvm.cmake_commands('if(A AND (B OR C))\nset(x "a b" [[c d]] e#f\n  g)\n')
    assert cmds == [("if", ["A", "AND", "(B OR C)"], 1), ("set", ["x", "a b", "c d", "e", "g"], 2)]


def test_library_compiler_entries():
    assert get_llvm.library_compiler_entries(SETTINGS) == [("lib/physx", "6.0.1"), ("src/game", "7.0.1")]


def test_library_compiler_entries_none():
    # master's CMakeLists.txt has no pkmn_library_settings() at all.
    assert get_llvm.library_compiler_entries("project(x)\nadd_library(pkmn OBJECT ${S})\n") == []
    assert get_llvm.library_compiler_entries("") == []


@pytest.mark.parametrize("text, msg", [
    ("pkmn_library_settings(lib/x COMPILER_VERSION ${V})", "is not a literal"),
    ("pkmn_library_settings(lib/x COMPILER_VERSION 6.0)", "is not a literal"),
    ("pkmn_library_settings(lib/x COMPILER_VERSION)", "is not a literal"),
    ("set(a b)\npkmn_library_settings(lib/x COMPILER_VERSION 6.0.1", "line 2: unterminated"),
    ('pkmn_library_settings(lib/x EVIDENCE "open', "unterminated string"),
])
def test_library_compiler_entries_errors(text, msg):
    with pytest.raises(get_llvm.CMakeParseError, match=msg):
        get_llvm.library_compiler_entries(text)


def make_repo(tmp_path, cmakelists: str | None, files=()):
    root = tmp_path / "repo"
    root.mkdir()
    if cmakelists is not None:
        (root / "CMakeLists.txt").write_text(cmakelists, encoding="utf-8")
    for f in files:
        (root / f).parent.mkdir(parents=True, exist_ok=True)
        (root / f).write_text("", encoding="utf-8")
    return root


def test_needed_library_compilers_only_with_sources(tmp_path):
    text = ("pkmn_library_settings(lib/physx COMPILER_VERSION 6.0.1)\n"
            "pkmn_library_settings(lib/lua COMPILER_VERSION 5.0.2)\n"
            "pkmn_library_settings(lib/main COMPILER_VERSION 7.0.1)\n"
            "pkmn_library_settings(tools COMPILER_VERSION 4.0.1)\n")
    # Headers alone, a lookalike directory, or sources outside src/ and lib/ don't count.
    root = make_repo(tmp_path, text, ["lib/physx/include/Px.h", "lib/physxlike/a.cpp", "tools/x.c",
                                      "lib/main/m.c"])
    assert get_llvm.needed_library_compilers(root) == []  # 7.0.1 is the main compiler
    (root / "lib/physx/source/deep").mkdir(parents=True)
    (root / "lib/physx/source/deep/Gu.cpp").write_text("", encoding="utf-8")
    (root / "lib/lua/lapi.c").parent.mkdir(parents=True)
    (root / "lib/lua/lapi.c").write_text("", encoding="utf-8")
    assert get_llvm.needed_library_compilers(root) == ["5.0.2", "6.0.1"]


def test_needed_library_compilers_no_cmakelists(tmp_path):
    assert get_llvm.needed_library_compilers(make_repo(tmp_path, None)) == []


def test_repo_cmakelists_parses():
    get_llvm.needed_library_compilers()  # the real CMakeLists.txt must stay parseable


def test_install_library_compilers_noop(tmp_path, monkeypatch, capsys):
    monkeypatch.setattr(get_llvm, "install_compiler", lambda *a: pytest.fail("must not install"))
    root = make_repo(tmp_path, "project(x)\n", ["src/a.cpp"])
    assert get_llvm.install_library_compilers(root, tmp_path / "toolchain", ("Linux", "x86_64")) == 0
    assert "no library with sources needs" in capsys.readouterr().out


def test_install_library_compilers(tmp_path, monkeypatch, capsys):
    root = make_repo(tmp_path, "pkmn_library_settings(lib/physx COMPILER_VERSION 6.0.1)\n",
                     ["lib/physx/a.cpp"])
    calls = []
    monkeypatch.setattr(get_llvm, "install_compiler", lambda v, t, on: calls.append((v, t, on)) or 0)
    toolchain = tmp_path / "toolchain"
    on = ("Linux", "x86_64")
    assert get_llvm.install_library_compilers(root, toolchain, on) == 0
    assert calls == [("6.0.1", toolchain, on)]

    # Already installed and reporting the right version: skipped.
    clang = toolchain / "clang-6.0.1" / "bin" / "clang"
    clang.parent.mkdir(parents=True)
    clang.write_bytes(b"")
    monkeypatch.setattr(get_llvm, "run_version", lambda c: subprocess.CompletedProcess(
        [str(c)], 0, "clang version 6.0.1 (tags/RELEASE_601/final)\n", ""))
    calls.clear()
    assert get_llvm.install_library_compilers(root, toolchain, on) == 0
    assert calls == [] and "already installed" in capsys.readouterr().out

    # Installed, but the wrong version: reinstalled.
    monkeypatch.setattr(get_llvm, "run_version", lambda c: subprocess.CompletedProcess(
        [str(c)], 0, "clang version 7.0.1\n", ""))
    assert get_llvm.install_library_compilers(root, toolchain, on) == 0
    assert calls == [("6.0.1", toolchain, on)]


def test_install_library_compilers_unknown_version(tmp_path, monkeypatch, capsys):
    root = make_repo(tmp_path, "pkmn_library_settings(lib/x COMPILER_VERSION 5.0.2)\n", ["lib/x/a.c"])
    monkeypatch.setattr(get_llvm, "install_compiler", lambda *a: pytest.fail("must not install"))
    assert get_llvm.install_library_compilers(root, tmp_path, ("Linux", "x86_64")) == 1
    assert "can't install" in capsys.readouterr().out


def test_install_library_compilers_macos_refuses_601(tmp_path, monkeypatch, capsys):
    root = make_repo(tmp_path, "pkmn_library_settings(lib/physx COMPILER_VERSION 6.0.1)\n",
                     ["lib/physx/a.cpp"])
    monkeypatch.setattr(get_llvm, "download", lambda url, dest: pytest.fail("must not download"))
    assert get_llvm.install_library_compilers(root, tmp_path, ("Darwin", "arm64")) == 1
    assert "no prebuilt clang 6.0.1" in capsys.readouterr().out


def test_parse_args_library_compilers():
    a = get_llvm.parse_args(["--library-compilers"])
    assert (a.compiler, a.tools, a.library_compilers) == (None, False, True)
    a = get_llvm.parse_args(["--compiler", "--library-compilers"])
    assert (a.compiler, a.tools, a.library_compilers) == ("7.0.1", False, True)
    a = get_llvm.parse_args(["--list-library-compilers"])
    assert (a.compiler, a.tools, a.list_library_compilers) == (None, False, True)
    with pytest.raises(SystemExit):
        get_llvm.parse_args(["--list-library-compilers", "--compiler"])


def test_main_list_library_compilers(tmp_path, monkeypatch, capsys):
    root = make_repo(tmp_path, "pkmn_library_settings(lib/physx COMPILER_VERSION 6.0.1)\n", [])
    monkeypatch.setattr(get_llvm, "ROOT", root)
    assert get_llvm.main(["--list-library-compilers"]) == 0
    assert capsys.readouterr().out == ""
    (root / "lib/physx").mkdir(parents=True)
    (root / "lib/physx/a.cpp").write_text("", encoding="utf-8")
    assert get_llvm.main(["--list-library-compilers"]) == 0
    assert capsys.readouterr().out == "6.0.1\n"
