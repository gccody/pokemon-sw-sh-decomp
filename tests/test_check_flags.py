"""check.py: a build dir must use the codegen flags of cmake/toolchain-nx64.cmake."""
from __future__ import annotations

import json

import pytest

import check

FLAGS = ["-mcpu=cortex-a57", "-fPIC", "-O3", "-g"]

TOOLCHAIN = """\
set(CMAKE_SYSTEM_NAME Generic)
set(PKMN_CODEGEN_FLAGS
  -mcpu=cortex-a57   # comment
  -fPIC

  -O3 -g             # two on one line
)
set(CMAKE_C_OUTPUT_EXTENSION .o)
"""


def command(*flags: str, file: str = "/src/a.c") -> dict:
    return {"directory": "/build", "file": file,
            "command": " ".join(["clang", "--target=aarch64-none-elf", "-DX", "-I/inc", *flags,
                                 "-O3", "-DNDEBUG", "-Wall", "-o", "a.o", "-c", file])}


@pytest.fixture
def build_dir(tmp_path):
    """build_dir(configured, *commands) -> a configured build dir."""

    def make(configured: list[str] | None, *commands: dict):
        d = tmp_path / "sword"
        d.mkdir(exist_ok=True)
        lines = ["CMAKE_C_FLAGS:STRING=", "PKMN_GAME:STRING=sword"]
        if configured is not None:
            lines.append("PKMN_CODEGEN_FLAGS_CONFIGURED:INTERNAL=" + ";".join(configured))
        (d / "CMakeCache.txt").write_text("\n".join(lines) + "\n", encoding="utf-8")
        (d / "compile_commands.json").write_text(json.dumps(list(commands)), encoding="utf-8")
        return d

    return make


def test_codegen_flags_parses_list(tmp_path):
    p = tmp_path / "toolchain.cmake"
    p.write_text(TOOLCHAIN, encoding="utf-8")
    assert check.codegen_flags(p) == FLAGS


def test_codegen_flags_of_repo_toolchain():
    flags = check.codegen_flags()
    assert flags[:2] == ["-mcpu=cortex-a57+fp+simd+crypto+crc", "-D__ELF__"]
    assert "-O3" in flags


@pytest.mark.parametrize("text", ["set(X 1)\n", "set(PKMN_CODEGEN_FLAGS\n  ${OTHER}\n)\n",
                                  'set(PKMN_CODEGEN_FLAGS\n  "-a -b"\n)\n'])
def test_codegen_flags_rejects_what_it_cant_read(tmp_path, text):
    p = tmp_path / "toolchain.cmake"
    p.write_text(text, encoding="utf-8")
    with pytest.raises(SystemExit):
        check.codegen_flags(p)


def test_stale_flag_sources():
    cc = [command(*FLAGS, file="/src/ok.c"),
          command("-mcpu=cortex-a57", "-fPIC", "-O3", file="/src/no_g.c"),        # flag missing
          command("-fPIC", "-mcpu=cortex-a57", "-O3", "-g", file="/src/order.c"),  # other order
          {"file": "/src/args.c", "arguments": ["clang", *FLAGS, "-c", "/src/args.c"]}]
    assert check.stale_flag_sources(cc, FLAGS) == ["/src/no_g.c", "/src/order.c"]


def test_check_codegen_flags_ok(build_dir):
    assert check.check_codegen_flags(build_dir(FLAGS, command(*FLAGS)), FLAGS) is None


def test_check_codegen_flags_old_configure(build_dir):
    # configured before the flags were recorded (CMAKE_<LANG>_FLAGS_INIT)
    err = check.check_codegen_flags(build_dir(None, command(*FLAGS)), FLAGS)
    assert "no record" in err and "cmake --build --preset sword" in err


def test_check_codegen_flags_removed_flag(build_dir):
    # -g removed from the toolchain file, build dir not reconfigured: the old
    # commands still contain the new list, so only the record shows it
    err = check.check_codegen_flags(build_dir(FLAGS, command(*FLAGS)), FLAGS[:-1])
    assert "configured: -mcpu=cortex-a57 -fPIC -O3 -g" in err


def test_check_codegen_flags_stale_command(build_dir):
    d = build_dir(FLAGS, command(*FLAGS), command(*FLAGS[:-1], file="/src/b.c"))
    err = check.check_codegen_flags(d, FLAGS)
    assert err.startswith("1 of the sources") and "/src/b.c" in err


def test_check_codegen_flags_not_configured(tmp_path):
    assert "isn't configured" in check.check_codegen_flags(tmp_path / "shield", FLAGS)
