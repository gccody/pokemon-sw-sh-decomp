# Compiler identification

**Result: upstream clang 7.0 at `-O3`, plus the NX platform flags below.**
`python tools/get_llvm.py` installs it into `toolchain/clang/`, and
`cmake/toolchain-nx64.cmake` uses it automatically.

Compiling Lua 5.3.4 this way reproduces **490 functions (156 KB of code)
byte-for-byte**. No other version or flag set comes close (see the tables below).

```
clang 7.0.1  --target=aarch64-none-elf -mcpu=cortex-a57+fp+simd+crypto+crc
  -O3 -D__ELF__ -funwind-tables -mno-implicit-float -fPIC
  -fno-omit-frame-pointer -fno-strict-aliasing -ffunction-sections -fdata-sections
  C++ only: -fno-exceptions -fno-rtti
```

clang 7.0.0, 7.0.1 and 7.1.0 produce identical code on the whole corpus, so
they can't be told apart yet. The toolchain uses 7.0.1. Only an x86-64 build of
7.0.0 exists for macOS, so `get_llvm.py` installs that there.

## Method

`tools/compiler_sweep.py` compiles known source with each candidate compiler
and flag set. It then counts compiled functions whose instructions equal an
original function's instructions exactly, with address fields (B/BL, ADRP, the
lo12 half, ADR, LDR literal) masked out on both sides. This needs no names or
addresses. Hits from all configurations together give a name → address map, so
every configuration also gets a similarity score over the same functions.

The corpus is **Lua**. It is linked into `main` (`0x7101540000`–`0x7101570000`,
692 functions) and was compiled by Game Freak, not shipped prebuilt by a vendor.
It is plain C, built with `_setjmp`/`_longjmp` (both imported). Nintendo's libc
is musl-based (`__nnmusl_init_dso` is imported), so musl 1.1.24 headers serve
as the sysroot.

Lua version: 5.3.4 with `LUA_COMPAT_5_2` and `LUA_USE_POSIX` scores best (5.3.3:
399 hits, 5.3.4: 416, 5.3.5: 410, 5.3.6: 403, before the last two flags were
found). The binary only contains the string `"Lua 5.3"`.

### Versions (final flags, Lua 5.3.4, 574 compiled functions, 469 mapped)

| Compiler | `-O3` hits | `-O3` bytes | `-O3` avg similarity | `-O2` hits | `-Os` hits |
|---|---:|---:|---:|---:|---:|
| clang 3.9.1 | 112 | 8,664 | 0.766 | 110 | 107 |
| clang 4.0.1 | 124 | 9,776 | 0.807 | 122 | 114 |
| clang 5.0.2 | 171 | 19,308 | 0.882 | 160 | 139 |
| clang 6.0.1 | 204 | 26,240 | 0.927 | 167 | 141 |
| **clang 7.0.0 / 7.0.1 / 7.1.0** | **490** | **156,244** | **1.000** | 335 | 225 |
| clang 8.0.0 / 8.0.1 | 247 | 43,964 | 0.952 | 185 | 132 |
| clang 9.0.1 | 80 | 6,564 | 0.848 | 67 | 63 |
| clang 10.0.0 | 39 | 1,420 | 0.705 | 37 | 38 |
| clang 11.0.0 | 37 | 1,260 | 0.697 | 35 | 36 |
| clang 19.1.7 | 27 | 760 | 0.560 | 26 | 28 |

From clang 9 onward, small constants are encoded as `movz` (`mov w1, #2`)
instead of `orr w1, wzr, #2`, which on its own rules out every version from 9 on.

### Flags (clang 7.0.1 `-O3`, each row drops one flag)

| Variant | Hits | Bytes | What it shows |
|---|---:|---:|---|
| **final** | **490** | **156,244** | |
| without `-funwind-tables` | 111 | 23,504 | Every function has an FDE. The CFI pseudo-instructions are scheduling boundaries in LLVM 7, so the prologue (`stp x29, x30` / `add x29, sp, #N`) is never interleaved with the body. Without unwind tables the post-RA scheduler moves `add x29` down. |
| `-mimplicit-float` | 416 | 107,188 | 16-byte copies and zeroing use `ldp`/`stp x` and `stp xzr, xzr`, never `ldr q`/`movi v0.2d, #0`. |
| `-fstrict-aliasing` | 430 | 100,840 | e.g. `lua_pushnil` reloads `L->top` after storing through a `TValue*`. |
| without `-D__ELF__` | 421 | 123,692 | Lua marks internals `visibility("hidden")` only under `__ELF__`. The NX triple defines it, but upstream `aarch64-none-elf` doesn't. Hidden symbols are reached with `adrp`+`add`, not through the GOT. |
| `-fno-pic` | 451 | 100,536 | Public globals do go through the GOT. |
| `-mcpu=generic` | 129 | 11,976 | Cortex-A57 scheduling model. |
| `-fomit-frame-pointer` | 76 | 8,500 | Frame pointers are kept. |

### Beyond Lua

Two checks over the whole executable show these flags hold everywhere, not
only in Lua:

- **No implicit float.** Game code has 17,869 adjacent `stp xzr, xzr` pairs
  against 84 `movi v.2d, #0` + `stp q`, and 3,720 `ldp x`/`stp x` 16-byte copies
  against 155 `ldr q`/`str q` (those are explicit vector types). YEBIS and the
  middleware show the same pattern.
- **No exceptions in Game Freak code.** All 74,530 game FDEs use a `zR` CIE (no
  personality, no LSDA). PhysX has 1,250 `zPLR` FDEs: NVIDIA built it with
  exceptions, so check vendor libraries separately.

The four functions checked by `tools/check.py` still match in both games with
clang 7.0.1.

## What's left open

- **The `-O` level for Game Freak's C++ code.** Lua is `-O3`, and the toolchain
  defaults to that. Confirm it once the first real game functions are
  decompiled. If a TU won't match, try `-O2` before assuming the source is wrong.
- **The C++ standard version.** It's `-std=c++17` for now (clang 7 supports it).
- **A possible vendor patch.** Nintendo ships its own clang build. One deviation
  from upstream 7.0 has been seen: in `luaD_shrinkstack` (`0x7101550ab0`) the
  original loads `ci->top` and `ci->previous` with two `ldr`s where upstream
  emits one `ldp`. It may be a small source edit instead. Note any similar
  load/store-pairing differences you find.
- **The remaining Lua misses** are in libraries Game Freak changed or removed:
  `loslib`, `liolib` (`luaopen_io` creates 9 fields, not 11), `loadlib`,
  `lbitlib`, `lutf8lib`, and the `lauxlib` allocator and panic handler.

## Reproducing

The candidate compilers and the corpus go under `toolchain/candidates/`
(gitignored):

```sh
# compilers: Windows NSIS installers from releases.llvm.org (unpack with 7-Zip)
7z x -otoolchain/candidates/clang-7.0.1 LLVM-7.0.1-win64.exe bin/clang.exe 'lib/clang/*/include'

# corpus: Lua sources + musl headers as the sysroot
cd toolchain/candidates/src
curl -LO https://www.lua.org/ftp/lua-5.3.4.tar.gz && tar xzf lua-5.3.4.tar.gz
curl -LO https://musl.libc.org/releases/musl-1.1.24.tar.gz && tar xzf musl-1.1.24.tar.gz
M=musl-1.1.24 O=../sysroot/include
mkdir -p $O/bits && cp -r $M/include/* $O/ && cp $M/arch/generic/bits/* $M/arch/aarch64/bits/* $O/bits/
sed -f $M/tools/mkalltypes.sed $M/arch/aarch64/bits/alltypes.h.in $M/include/alltypes.h.in > $O/bits/alltypes.h
cd ../../..

python tools/compiler_sweep.py --compiler 'toolchain/candidates/clang-*' \
    --variant O3=-O3 --variant O2=-O2 \
    --src 'toolchain/candidates/src/lua-5.3.4/src/l*.c' --range 0x7101540000-0x7101570000 \
    -- -isystem toolchain/candidates/sysroot/include -DLUA_COMPAT_5_2 -DLUA_USE_POSIX
```

The sweep tool starts from the final flag set. A variant's flags come after it,
so they can switch one off (`-fno-unwind-tables`, `-mimplicit-float`, `-U__ELF__`, ...).

Linux note: the LLVM 7 Linux builds need `libtinfo.so.5` (`libtinfo5` /
`libncurses5` on Debian and Ubuntu).
