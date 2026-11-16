"""tools/get_llvm.py without the network: synthetic archives laid out like the
LLVM 7 release tarballs."""
from __future__ import annotations

import io
import os
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


def make_tarball(path, files: dict[str, bytes], links: dict[str, str]) -> None:
    """Write a .tar.xz with everything under TOP/. Symlinks come first, before
    their targets, as the stream extractor can see them in any order."""
    with tarfile.open(path, "w:xz") as t:
        for name, target in links.items():
            info = tarfile.TarInfo(f"{TOP}/{name}")
            info.type = tarfile.SYMTYPE
            info.linkname = target
            t.addfile(info)
        for name, data in files.items():
            info = tarfile.TarInfo(f"{TOP}/{name}")
            info.size = len(data)
            info.mode = 0o755
            t.addfile(info, io.BytesIO(data))


@pytest.mark.parametrize("rel, keep", [
    ("bin/clang", True),
    ("bin/clang-7", True),
    ("bin/clang++", False),
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
