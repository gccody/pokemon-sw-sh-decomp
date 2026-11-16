# Compiler identification

**Result: upstream clang 7.0 at `-O3`, plus the NX platform flags below.**
`python tools/get_llvm.py` installs it into `toolchain/clang/`, and
`cmake/toolchain-nx64.cmake` uses it automatically.

Compiling Lua 5.3.4 this way reproduces **493 functions (158 KB of code)
byte-for-byte**, every function the sweep maps. No other version or flag set
comes close (see the tables below).

```
clang 7.0.1  --target=aarch64-none-elf -mcpu=cortex-a57+fp+simd+crypto+crc
  -O3 -g -D__ELF__ -funwind-tables -mno-implicit-float -fPIC
  -fno-omit-frame-pointer -fno-strict-aliasing -ffunction-sections -fdata-sections
  C++ only: -fno-exceptions -fno-rtti
```

`-g` matters: debug info changes LLVM 7's code (see "Debug info" below). The
tables below include it (without it, the best is 490).

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

The corpus is **Lua**. It is linked into `main` (`0x7101548410`–`0x7101570900`
in Sword, `0x71015484b0`–`0x71015709a0` in Shield, 517 functions) and was
compiled by Game Freak, not shipped prebuilt by a vendor. The sweeps below
searched `0x7101540000`–`0x7101570000`, the first estimate of the range. The
Pokédex app sits below Lua and NEX follows it (see `data/areas.csv`).
It is plain C, built with `_setjmp`/`_longjmp` (both imported). Nintendo's libc
is musl-based (`__nnmusl_init_dso` is imported), so musl 1.1.24 headers serve
as the sysroot.

Lua version: 5.3.4 with `LUA_COMPAT_5_2` and `LUA_USE_POSIX` scores best (5.3.3:
399 hits, 5.3.4: 416, 5.3.5: 410, 5.3.6: 403, before the last two flags were
found). The binary only contains the string `"Lua 5.3"`.

### Versions (final flags, Lua 5.3.4, 574 compiled functions, 472 mapped)

| Compiler | `-O3` hits | `-O3` bytes | `-O3` avg similarity | `-O2` hits | `-Os` hits |
|---|---:|---:|---:|---:|---:|
| clang 3.9.1 | 112 | 8,664 | 0.765 | 110 | 107 |
| clang 4.0.1 | 124 | 9,776 | 0.806 | 122 | 114 |
| clang 5.0.1 / 5.0.2 | 171 | 19,308 | 0.882 | 160 | 139 |
| clang 6.0.0 / 6.0.1 | 204 | 26,240 | 0.927 | 167 | 141 |
| **clang 7.0.0 / 7.0.1 / 7.1.0** | **493** | **157,660** | **1.000** | 335 | 225 |
| clang 8.0.0 / 8.0.1 | 247 | 43,964 | 0.952 | 185 | 132 |
| clang 9.0.1 | 80 | 6,564 | 0.847 | 67 | 63 |
| clang 10.0.0 | 39 | 1,420 | 0.704 | 37 | 38 |
| clang 11.0.0 | 37 | 1,260 | 0.695 | 35 | 36 |
| clang 19.1.7 | 27 | 760 | 0.560 | 26 | 28 |

The clang 19.1.7 row is from an earlier run without `-g` (that compiler isn't
among the candidates any more). `-g` changes the hits only for clang 7.

From clang 9 onward, small constants are encoded as `movz` (`mov w1, #2`)
instead of `orr w1, wzr, #2`, which on its own rules out every version from 9 on.

### Flags (clang 7.0.1 `-O3`, each row drops or changes one flag, 473 mapped)

| Variant | Hits | Bytes | Exact of mapped | What it shows |
|---|---:|---:|---:|---|
| **final** | **493** | **157,660** | **473** | |
| without `-g` (`-g0`) | 490 | 156,244 | 470 | The three `stackinuse` load pairs (see "Debug info"). `-gline-tables-only` gives the same as `-g0`. |
| without `-funwind-tables` | 493 | 157,660 | 473 | Every function has an FDE in `.eh_frame`. With `-g` the CFI is emitted anyway, so the flag doesn't show in the code. Without `-g` it does (111 hits): the CFI pseudo-instructions are scheduling boundaries in LLVM 7, so the prologue (`stp x29, x30` / `add x29, sp, #N`) is never interleaved with the body, and without them the post-RA scheduler moves `add x29` down. |
| `-mimplicit-float` | 417 | 107,392 | 397 | 16-byte copies and zeroing use `ldp`/`stp x` and `stp xzr, xzr`, never `ldr q`/`movi v0.2d, #0`. |
| `-fstrict-aliasing` | 433 | 102,256 | 413 | e.g. `lua_pushnil` reloads `L->top` after storing through a `TValue*`. |
| without `-D__ELF__` | 424 | 125,108 | 404 | Lua marks internals `visibility("hidden")` only under `__ELF__`. The NX triple defines it, but upstream `aarch64-none-elf` doesn't. Hidden symbols are reached with `adrp`+`add`, not through the GOT. |
| `-fno-pic` | 454 | 101,952 | 434 | Public globals do go through the GOT. |
| `-mcpu=generic` | 129 | 11,976 | 115 | Cortex-A57 scheduling model. |
| `-fomit-frame-pointer` | 76 | 8,500 | 76 | Frame pointers are kept. |
| `-fno-builtin` | 445 | 113,224 | 424 | Builtins are on, unlike in PhysX (see "PhysX"). |
| `-O2` | 335 | 57,528 | 315 | |

### Debug info (`-g`)

**The original was built with debug info, and with LLVM 7 that changes the
code.** Without `-g`, three Lua functions missed, all because of one load pair:
`luaD_shrinkstack` (`0x7101550ab0`), `lua_resume` (`0x71015516b0`) and
`luaD_pcall` (`0x7101551cd0`). Each inlines `stackinuse()`, whose loop reads
`ci->top` and then `ci->previous`:

```
original (both games)        clang 7.0.1 without -g
ldr  x10, [x9, #8]           ldp  x10, x9, [x9, #8]
ldr  x9, [x9, #0x10]         cmp  x8, x10
cmp  x8, x10                 csel x8, x10, x8, lo
csel x8, x10, x8, lo
```

With `-g`, clang 7.0.1 emits the original's two `ldr`. Here's why. Just before
`aarch64-ldst-opt` runs (`-mllvm -print-before=aarch64-ldst-opt`), the loop
body is `ldr x10, [x9, #8]`, `cmp`, `csel`, then
`DBG_VALUE $x9, !"ci", !DIExpression(DW_OP_plus_uconst, 16, DW_OP_deref, DW_OP_stack_value)`
(the location of `ci` after `ci = ci->previous`), then `ldr x9, [x9, #16]`.
`findMatchingInsn` in LLVM 7's `AArch64LoadStoreOptimizer.cpp` passes every
instruction it scans to `LiveRegUnits::accumulateUsedDefed`, including debug
instructions. Only the scan limit skips them (`isTransient`). The `DBG_VALUE`
therefore counts as a use of `x9` between the two loads, so the second load
can't be moved up. The first can't be moved down either, because `cmp` and
`csel` read `x10`. The loads stay unpaired.

The evidence:

- **`check.py`, all TUs built with `-g`:** the three functions match in both
  games, and nothing else changes (515 matching, 6 not matching: the
  `loadlib.c` functions Game Freak changed).
- **Sweep (Lua 5.3.4, 473 mapped):** clang 7.0.0, 7.0.1 and 7.1.0 with `-g` give
  493 hits and match all 473 mapped functions (avg similarity 1.0000), against
  490 and 470 without it. `-gline-tables-only` emits no `DBG_VALUE`s and changes
  nothing. With `-g`, clang 5.0.x, 6.0.x, 8.0.x and 9.0.1 score the same hits
  as without it.
- **The pattern is specific.** In the original's Lua range there are 40 `ldp`
  whose second destination is also the base register (20 of them inside
  loops), so pairing into the base register isn't blocked in general. There
  are exactly 3 adjacent, pairable `ldr` pairs whose second destination is the
  base: the three `stackinuse` loops. Both games are the same.
- **PhysX too.** On the full PhysX corpus (clang 6.0.1, final PhysX flags,
  `v3.4.2`, 143 TUs), `-g` raises the hits from 1,137 to 1,224 and the exact
  matches from 922 to 1,006 of 1,012 mapped (see "PhysX"). clang 6.0.1 also
  leaves the `stackinuse` loads unpaired with `-g`.

A `volatile` read of `ci->top` also matched all three (a debug use between the
loads blocks pairing the same way a volatile access does). Earlier hypotheses
were a vendor patch or a Game Freak source change. Neither is needed: this is
a known class of LLVM behaviour, debug info changing codegen. `-g` is in
`PKMN_CODEGEN_FLAGS`, and `lib/lua/ldo.c` is unmodified upstream source.

`tools/compiler_sweep.py` has `-g` in its base flags, so every sweep uses it
and a `-g0` variant switches it off. Existing build directories
keep their cached flags, so reconfigure (`cmake --preset <game> --fresh`) after
a toolchain flag change.

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
- **`-g` beyond Lua.** It's in the global flags because of the evidence in
  "Debug info". Game Freak's C++ hasn't been tested with it yet (the four C++
  functions checked so far match either way). If a game function misses only
  in load/store pairing or in scheduling around a variable's last use, check
  that the build really has `-g` before changing the source. The game code has
  60 adjacent pairable `ldr` pairs whose second destination is the base,
  against 1,334 such `ldp`. Debug info may explain some of those 60, but they
  haven't been checked one by one.
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

The sweep tool starts from the final flag set (including `-g`), then adds the
common flags after `--`, then each variant's flags. A variant's flags always come last, so a
variant can switch off a base or common flag (`-fno-unwind-tables`,
`-mimplicit-float`, `-U__ELF__`, `-O2`, ...). Before this order was fixed, the
common flags came last and silently overrode a conflicting variant. The Lua
tables above aren't affected: their common flags are only an include path and
two Lua defines, which no variant touches.

Linux note: the LLVM 7 Linux builds need `libtinfo.so.5` (`libtinfo5` /
`libncurses5` on Debian and Ubuntu). Ubuntu 24.04 no longer ships `libtinfo5`,
and a `libtinfo.so.5` -> `libtinfo.so.6` symlink does not work: clang fails with
``version `NCURSES_TINFO_5.0.19991023' not found`` (tested on 24.04), because
`libtinfo.so.6` only defines `NCURSES6_TINFO_*` symbol versions. Use Ubuntu
22.04 or an `ubuntu:22.04` container, as CI does. (The LLVM 6.0.1 Linux build,
used for PhysX, doesn't link libtinfo and runs on 24.04.)

## PhysX

**Result: PhysX was *not* built with Game Freak's compiler. It is upstream
clang 6.0.1 at `-O3` with debug info, C++ exceptions and strict aliasing on,
builtins and RTTI off, in a release configuration, from the public `v3.4.2`
source.**

Compiling 143 PhysX 3.4 TUs at `v3.4.2` this way reproduces **1,224 functions
(1,017 KB of code) byte-for-byte**. Of the 1,012 functions mapped by consensus,
1,006 match; the other six are mapping artifacts (see "Source revision"). With
the global toolchain's compiler (clang 7.0.1) and the same PhysX flags, 509
match. Earlier versions of this section measured the repository HEAD without
`-fno-builtin` and `-g`: 920 hits, or 928 at `v3.4.2`. HEAD (`5e42a5f`) with the
final flags gives 1,208.

```
clang 6.0.1  --target=aarch64-none-elf -mcpu=cortex-a57+fp+simd+crypto+crc
  -O3 -g -D__ELF__ -funwind-tables -mno-implicit-float -fPIC
  -fno-omit-frame-pointer -ffunction-sections -fdata-sections
  -fexceptions -fstrict-aliasing -fno-rtti -fno-builtin -std=gnu++14
  -D__NX__ -DNDEBUG -DPX_PHYSX_STATIC_LIB -DPX_FOUNDATION_DLL=0 -DPX_SUPPORT_PVD=0
```

### What `lib/physx` needs that differs from `cmake/toolchain-nx64.cmake`

| Setting | Global toolchain | PhysX | Evidence |
|---|---|---|---|
| Compiler | clang 7.0.1 | **clang 6.0.1** | Version table below: 1,224 hits against 509 for clang 7 with the same flags. |
| Builtins | on | **`-fno-builtin`** | 952 hits with builtins on. PhysX calls libm for everything: 664 `bl fabsf` and 433 `bl sqrtf`, and not one `fabs` or `fsqrt` instruction. The rest of `main` has 228 `fabs`, 205 `fsqrt` and no `fabsf` call. `-ffreestanding` (which implies `-fno-builtin`) gives identical code. |
| Exceptions | `-fno-exceptions` | **`-fexceptions`** (C++ exceptions on) | 953 hits without. 1,279 of the binary's 1,281 `zPLR` FDEs are in PhysX, and noexcept destructors have terminate pads. |
| Aliasing | `-fno-strict-aliasing` | **`-fstrict-aliasing`** | 1,095 hits without. |
| Language | `-std=c++17` | **`-std=gnu++14`** | gnu++11/14/17 give identical code. `-std=c++14`/`c++17` (non-GNU) break 16 TUs, because musl then hides `alloca`. `-std=gnu++98` drops to 1,073 hits. |
| Defines | | **`__NX__`, `NDEBUG`, `PX_PHYSX_STATIC_LIB`, `PX_FOUNDATION_DLL=0`, `PX_SUPPORT_PVD=0`** | See "Build configuration". |

Everything else is the same as the global flags: `-O3`, `-g`, `-fno-rtti`,
`-mcpu=cortex-a57+fp+simd+crypto+crc`, `-D__ELF__`, `-funwind-tables`,
`-mno-implicit-float`, `-fPIC`, `-fno-omit-frame-pointer`, `-ffunction-sections`,
`-fdata-sections` and default symbol visibility. `-fno-common`, `-fno-short-enums`
and `-nostdinc++` come from the sweep's base flags and weren't varied.

The upstream Linux makefiles (`PhysX_3.4/Source/compiler/linux64`) use
`-O3 -fno-strict-aliasing -fno-exceptions -fno-rtti -fvisibility=hidden`. The
Switch build differs in three of those, and in `-fno-builtin` and `-g`, so
don't take flags from them.

### Versions (PhysX flags, `v3.4.2`, 143 TUs, 1,821 compiled functions, 1,024 mapped)

| Compiler | `-O3` hits | `-O3` bytes | `-O3` avg similarity | `-O2` | `-fno-exceptions` | `-fno-strict-aliasing` | `-fbuiltin` | without `-g` |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| clang 3.9.1 | 400 | 44,516 | 0.737 | 400 | 330 | 408 | 380 | 390 |
| clang 4.0.1 | 459 | 55,508 | 0.784 | 456 | 371 | 460 | 439 | 444 |
| clang 5.0.1 / 5.0.2 | 746 | 162,876 | 0.900 | 705 | 603 | 718 | 678 | 726 |
| clang 6.0.0 | 1,218 | 1,005,320 | 0.994 | 947 | 948 | 1,092 | 948 | 1,134 |
| **clang 6.0.1** | **1,224** | **1,017,424** | **0.996** | 950 | 953 | 1,095 | 952 | 1,137 |
| clang 7.0.0 / 7.0.1 / 7.1.0 | 509 | 91,176 | 0.841 | 476 | 476 | 494 | 479 | 492 |
| clang 8.0.0 / 8.0.1 | 475 | 77,392 | 0.781 | 445 | 442 | 462 | 450 | 459 |
| clang 9.0.1 | 153 | 15,324 | 0.695 | 146 | 135 | 150 | 142 | 145 |
| clang 10.0.0 | 37 | 2,408 | 0.588 | 35 | 32 | 34 | 34 | 37 |
| clang 11.0.0 | 36 | 2,308 | 0.564 | 34 | 31 | 33 | 33 | 36 |

The columns after the first three give hits with that one change. clang 10
and 11 reject 19 and 20 of the TUs, so their rows are lower bounds, but
they're far behind even on the TUs they do compile. Every function that clang
6.0.0 reproduces, 6.0.1 reproduces too. Six are reproduced only by 6.0.1: both
`Gu::RTree::traverseRay` instances, `EPA::PenetrationDepth`,
`fullContactsGenerationConvexConvex`, `Gu::computeBounds` and
`ConvexMeshContactGeneration::generateContacts`. A vendor build based on a
later 6.0 branch can't be ruled out (there is no upstream 6.0.2).

### Flags (clang 6.0.1 `-O3`, `v3.4.2`, each row changes one thing, 1,012 mapped)

| Variant | Hits | Bytes | Exact of mapped | What it shows |
|---|---:|---:|---:|---|
| **final** | **1,224** | **1,017,424** | **1,006** | |
| `-fbuiltin` | 952 | 617,040 | 758 | `PxAbs`/`PxSqrt` become `fabs`/`fsqrt` instructions, and `memset`/`memcpy` idioms are formed (see "Source revision" for a case where that changes inlining). |
| without `-g` (`-g0`) | 1,137 | 881,360 | 922 | Debug instructions change scheduling and register allocation (see "Debug info"). `-gline-tables-only` gives the same as `-g0`. |
| `-fno-exceptions` | 953 | 746,600 | 787 | Cleanup landing pads are part of the original code. |
| `-fno-cxx-exceptions` | 1,092 | 946,896 | 908 | Keeps cleanups but drops noexcept enforcement. The original calls a shared terminate helper (`0x7101750e90`) after noexcept destructors (e.g. the `Gu::HeightField` D0 at `0x710014f2f0`), so C++ exceptions are fully on. |
| `-fno-strict-aliasing` | 1,095 | 823,696 | 899 | |
| `-O2` | 950 | 506,564 | 769 | |
| `-Os` | 657 | 162,752 | 538 | |
| `-mimplicit-float` | 760 | 335,460 | 611 | GPR-only copies, the same as game code. |
| `-mcpu=generic` | 135 | 6,040 | 70 | Cortex-A57 scheduling model. |
| `-fomit-frame-pointer` | 453 | 156,652 | 366 | |
| `-fno-pic` | 971 | 724,712 | 817 | |
| `-fvisibility=hidden` | 1,015 | 835,604 | 861 | Globals go through the GOT, unlike in the Linux build. |
| `-DPX_CHECKED=1` | 1,148 | 947,668 | 940 | Release, not checked. |
| `-std=gnu++98` | 1,073 | 951,908 | 896 | |
| `-ffast-math` | 523 | 107,472 | 357 | |
| `-ffreestanding`, `-frtti`, `-fno-unwind-tables`, `-fno-math-errno`, `-DPX_PROFILE=1`, `-DPX_SUPPORT_PVD=1`, `-std=gnu++11`/`gnu++17` | 1,224 | 1,017,424 | 1,006 | Not distinguishable with this corpus. RTTI is off because no PhysX class has a typeinfo name and PhysX vtables have no typeinfo slot. With `-g` the CFI is emitted anyway, so `-funwind-tables` no longer shows in the code; the binary's `.eh_frame` (an FDE for every function) is the evidence for it. `-fno-math-errno` changes nothing once builtins are off. |

The `-std` and `PX_SUPPORT_PVD` rows are real tests now. Before
`compiler_sweep.py`'s flag order was fixed, common flags after `--` overrode a
conflicting variant, so runs that passed `-std=gnu++14` or `-DPX_SUPPORT_PVD=0`
there didn't test those variants at all.

### Build configuration

PhysX ships debug, checked, profile and release configurations. The binary is a
**release** build:

- No `PX_CHECK_*` messages (such as `PxScene::addArticulation: empty
  articulations ...`), so `PX_CHECKED=0`.
- No `PX_PROFILE_ZONE` event names (`API.addActor`, `Sim.solveQueueTasks`), so
  `PX_PROFILE=0` (and `PX_DEBUG=0`).
- No `PX_ASSERT` expression strings, so asserts are compiled out (`NDEBUG`).
- No `PxPvd*` strings, so `PX_SUPPORT_PVD=0`, as in the upstream release config.
- Unconditional errors (`PxScene::addBroadPhaseRegion(): region bounds are
  empty...`) and the `__FILE__` paths of `PX_ALLOC` are present. Allocation-name
  getters return `<allocation names disabled>` or `__PRETTY_FUNCTION__`.

The `__FILE__` paths start with `C:/gitlab-runner/builds/.../physx/PhysX/` or
`./../../../../`, and some header paths use backslashes (`include\PsArray.h`).
The library was built from source on a Windows CI machine with an MSBuild-style
project. It's a prebuilt static library, which explains why its compiler is
older than the game's. The Switch platform sources are referenced
(`PxShared/src/foundation/src/switch/PsSwitchMutex.cpp`,
`PsSwitchPrintString.cpp`). PhysX selects them from `__NX__` (`PX_SWITCH`),
which upstream clang doesn't define.

### Source revision

**The binary's PhysX is the public `v3.4.2` tag (`b99b378`, "patch release
@24214033"). The corpus shows no difference from it: every mapped function
matches, apart from the mapping artifacts listed below.**

Every public revision since 3.4.1 that touches the corpus was swept with the
final configuration (clang 6.0.1, `-O3`, PhysX flags):

| Revision | Perforce CL | Hits | Bytes |
|---|---|---:|---:|
| `d1c812f` (`v3.4.1`) | 22845541 | 1,143 | 935,012 |
| `3cc1861` (3.4.1 update) | 23131702 | 1,196 | 980,352 |
| `57b71f8` (3.4.1 update) | 23173160 | 1,197 | 980,936 |
| `983c93a` | 23307153 | 1,197 | 980,936 |
| `b6db9a5` | 23472123 | 1,203 | 985,204 |
| `52dae55` | 23576764 | 1,210 | 1,000,524 |
| `238605d` | 23879214 | 1,219 | 1,007,956 |
| **`b99b378` (`v3.4.2`)** | **24214033** | **1,224** | **1,017,424** |
| `3f9977d` | 24698370 | 1,214 | 994,480 |
| `ad993f2` | 24990349 | 1,212 | 994,020 |
| `78cab22` | 25256367 | 1,210 | 993,988 |
| `326e240` (= HEAD `5e42a5f` for these files) | 25354359 | 1,208 | 991,100 |

`5f95687` (@23933511) doesn't touch the corpus. Of the two 3.4.1 updates,
`57b71f8` changes only `GuCCDSweepConvexMesh.cpp` against `3cc1861` (`matRot`
becomes `PxMat33(PxIdentity)`, one more hit). `983c93a` changes only two public
headers against `57b71f8` and compiles the same. Without `-fno-builtin` and
`-g` the ranking is the same (`v3.4.2` 928, HEAD 920).

Compared by original address, every revision's hits are a subset of the
`v3.4.2` hits:

- Over `238605d`: five PCM convex-vs-mesh functions (`PCMContactConvexMesh`,
  `PCMContactConvexHeightfield`, `PCMConvexVsMeshContactGeneration::
  generateTriangleFullContactManifold` and `generatePolyDataContactManifold`,
  and the `processHit` of its mesh callback).
- Over `3f9977d`: `epaPenetration`, `EPA::PenetrationDepth`, `Facet::silhouette`,
  both `RayRTreeCallback<0, true>::processResults`, `raycast_heightField` and
  `HFTraceSegmentCallback::faceHit`.
- Over HEAD: those seven, plus `barycentricCoordinates`, `BV4Tree(PxEMPTY)`,
  `HeightField::getTriangleAdjacencyIndices`,
  `SweepConvexMeshHitCallback::processHit` and `ConvexTraceSegmentReport::onEvent`.

Revisions before 3.4.1 are ruled out by path. They keep the Switch platform
files under `nx/` (`foundation/nx/PxNXIntrinsics.h`), while the binary's
`__FILE__` strings use the `switch/` names that 3.4.1 introduced (they don't
build with the stand-ins below either).

**`GuContactConvexMesh.cpp` is unmodified, too.** An earlier version of this
section concluded that it matched no public revision. That came from the
missing `-fno-builtin` and `-g`. With the final flags, every function the
linker placed in the TU's range (`0x7100127ca0`-`0x710012c4d0`, in source
order) matches `v3.4.2`. Only template instances such as `PxBounds3::transformFast`
live elsewhere:

- The 680-byte function `0x7100129340`, called from `contactHullMesh2`
  (`0x7100127dd0`) and `contactHullHeightfield2` (`0x71001285c0`), is the
  out-of-line `ConvexMeshContactGeneration` constructor. Its layout is the
  public one (`mEdgeCache.mIndex` at `0x488`, `mSize` at `0x508`,
  `mVertCache.mIndex` at `0x78c`). The two `CacheMap` constructors fill
  `mIndex` with `0xFF`. With builtins on, those loops become `memset` calls,
  the constructor becomes cheap enough to inline, and the callers grow to
  1,976 and 1,948 bytes. With `-fno-builtin` the loops stay loops (32 word
  stores each), the constructor stays out of line, and the callers are the
  original's 1,428 and 1,352 bytes. That is also why `contactBoxHeightfield`
  and `contactConvexHeightfield`, which pass arguments through to
  `contactHullHeightfield2`, missed before.
- `-g` then fixes the last floating-point register-allocation and scheduling
  differences, in the constructor and `contactHullMesh2`.
- `triangleConvexTest` (`0x7100129f50`, 5,612 bytes) is the only function in
  the TU that the sweep doesn't count. It differs in two `ldr s15, [xN, #lo12]`
  whose `adrp` is on another path. The sweep tracks `adrp` linearly, so it
  compares those two lo12 fields raw. That is a masking limitation, not a code
  difference.
- The two functions before the TU that had "no counterpart" (`0x7100127250`,
  1,292 bytes, and `0x7100127760`, 1,340 bytes) are `PxcTestFacesSepAxesBackface`
  and `PxcFindSeparatingAxes` from the preceding TU, `GuContactConvexConvex.cpp`.
  They match exactly, as does the rest of that TU (`0x7100124cd0`-`0x7100127ca0`).

So there's no need for PhysX 4.x sources or a non-public revision to explain
the binary's convex/mesh contact code.

The six mapped functions that miss with the final flags are mapping artifacts,
not differences:

- Three deleting destructors (`GuMeshFactory`, `TriangleMeshData`, `PxTaskMgr`).
  With addresses masked, they look like one PhysX core destructor outside the
  corpus (`0x7100021330`), so consensus mapped them onto it.
- `AABBTree::~AABBTree` (D1 and D2). At `-Os` it compiles to a 24-byte wrapper
  around `release()`, which matches the 24-byte wrapper at `0x71002ff480`. That
  function calls an import, so it isn't `AABBTree`'s destructor.
- `Array<PxDebugLine>::recreate` was mapped to `0x71002bd310` by another
  configuration. The final compile's best match is `0x71002bd460` (similarity
  0.887). The linker keeps one copy of each template instance, presumably
  from a TU outside the corpus.

### Area boundaries

These results also corrected `data/areas.csv`. The boundaries are identical in Shield.

- **PhysX is `0x7100010a90`-`0x71003035e0`.** It ends with PxFoundation
  (`PsFoundation.cpp`: "Foundation object exists already..."), the Switch
  mutex and PxTask (`TaskManager.cpp`: "PxTask dispatched twice"). Its vtables
  in `.data.rel.ro` run contiguously up to the TaskManager ones. Every unique
  sweep hit lies in `0x7100021330`-`0x71003032f0` (with the final flags,
  `0x71000ae470`-`0x71003032f0`). The first `zPLR` FDE is at
  `0x7100010f10`.
- **It starts with PhysX LowLevel's contact-method glue**
  (`0x7100010a90`-`0x7100010e30`, the same in both games):
  - `px_globals.cpp`: `PxvRegisterHeightFields` (`0x7100010a90`) stores 8
    function pointers at offsets `0x30`/`0xa0`/`0xd8`/`0x110` of two tables. Those
    are `[eSPHERE/eCAPSULE/eBOX/eCONVEXMESH][eHEIGHTFIELD]` of the two 7×7
    tables `g_ContactMethodTable` and `g_PCMContactMethodTable`. It then sets
    `gUnifiedHeightfieldCollision`. `PxvInit` (`0x7100010b20`) copies the
    24-byte offset table, and `PxvTerm` (`0x7100010b50`) is a bare `ret` (no GPU
    support).
  - `PxcContactMethodImpl.cpp`: `PxcInvalidContactPair` (`0x7100010b60`,
    `mov w0, wzr; ret`) appears in many table slots.
  - `PxcContact.cpp`: 44 one-instruction wrappers (`b Gu::contact*`), each
    referenced from one `R_AARCH64_RELATIVE` table slot or GOT entry. The
    targets are the Gu functions (e.g. `0x7100010c80` → `contactBoxHeightfield`).
    The source has 48 wrappers. The 4 missing ones are the `PxcLegacy*`
    heightfield wrappers, which are reachable only from
    `PxvRegisterLegacyHeightFields`, also absent (presumably dropped by the
    linker's `--gc-sections`).

  None of them need unwind personality data, so they have `zR` FDEs. That's
  why the first `zPLR` FDE comes later.
- **`0x71003035e0`-`0x710040f550` is Audiokinetic Wwise**, not PhysX. It has the
  thread names `AK::BankManager`, `AK::EventManager`, `AK::IOThread` and
  `AK::OpusDecodingThread`, `.bnk` loading, and "Load bank failed :
  incompatible bank version ... Wwise". It starts with static plugin-registration
  stubs (`0x71003035e0`, `0x71003f5170`) that link records into one shared list.
  Its FDEs are all `zR`, and it has no call edges into PhysX. See "Wwise" below
  for what the binary says about its compiler.
- **YEBIS starts at `0x710040f550`**, the first function that references the
  `sisdk/3.0/SDK/Core` source path. The functions after it are called only
  from YEBIS.

### Reproducing

Everything goes under `toolchain/candidates/` (gitignored). clang 6.0.0 and 5.0.1
come from the same release installers as the other compilers:

```sh
cd toolchain/candidates
7z x -oclang-6.0.0 LLVM-6.0.0-win64.exe bin/clang.exe 'lib/clang/*/include'   # likewise 5.0.1

cd src
git clone --filter=blob:none --sparse https://github.com/NVIDIAGameWorks/PhysX-3.4.git
git -C PhysX-3.4 sparse-checkout set PhysX_3.4/Source PhysX_3.4/Include PxShared/src PxShared/include
git -C PhysX-3.4 checkout v3.4.2      # the revision the binary was built from
# libc++ 7.0.1 headers, needed only for <new>
curl -LO https://releases.llvm.org/7.0.1/libcxx-7.0.1.src.tar.xz
tar xJf libcxx-7.0.1.src.tar.xz libcxx-7.0.1.src/include && mv libcxx-7.0.1.src libcxx-7.0.1
```

The NX platform headers aren't in the public repository. Three stand-ins,
derived from the Unix versions, are enough for these TUs. The intrinsics are
the same inline math and builtins.

```sh
P=PhysX-3.4/PxShared; S=physx-nx-shim
mkdir -p $S/foundation/switch $S/switch
sed '/#error/d' $P/include/foundation/unix/PxUnixIntrinsics.h > $S/foundation/switch/PxSwitchIntrinsics.h
sed '/#error/d' $P/src/foundation/include/unix/PsUnixIntrinsics.h > $S/switch/PsSwitchIntrinsics.h
printf '#include <stdlib.h>\nnamespace { inline void abort(const char*) { ::abort(); } }\n' > $S/switch/PsSwitchAbort.h
cd ../../..
```

Then run the sweep. Quote the globs so the shell doesn't expand them (`**` recurses).
The common flags after `--` hold the final configuration, and each variant
changes one thing (variants come last, so they win). An empty variant (`O3=`)
is the final configuration itself:

```sh
X=toolchain/candidates/src/PhysX-3.4; P=$X/PhysX_3.4/Source; G=$P/GeomUtils/src
python tools/compiler_sweep.py --compiler 'toolchain/candidates/clang-*' \
    --variant "O3=" --variant "O2=-O2" --variant "noeh=-fno-exceptions" \
    --variant "nostrict=-fno-strict-aliasing" --variant "builtin=-fbuiltin" --variant "g0=-g0" \
    --src "$X/PxShared/src/foundation/src/*.cpp" --src "$X/PxShared/src/task/src/*.cpp" \
    --src "$P/Common/src/*.cpp" --src "$G/**/*.cpp" \
    --range 0x7100010e30-0x71003035e0 \
    -- -O3 -fexceptions -fstrict-aliasing -fno-rtti -fno-builtin -std=gnu++14 \
       -nostdinc++ -isystem toolchain/candidates/src/libcxx-7.0.1/include \
       -isystem toolchain/candidates/sysroot/include \
       -D__NX__ -DNDEBUG -DPX_PHYSX_STATIC_LIB -DPX_FOUNDATION_DLL=0 -DPX_SUPPORT_PVD=0 \
       -D_LIBCPP_HAS_MUSL_LIBC -D_LIBCPP_HAS_THREAD_API_PTHREAD \
       -I toolchain/candidates/src/physx-nx-shim -I $X/PxShared/include \
       -I $X/PxShared/src/foundation/include -I $X/PxShared/src/foundation/include/unix \
       -I $X/PxShared/src/task/include -I $X/PxShared/src/pvd/include -I $X/PxShared/src/fastxml/include \
       -I $X/PhysX_3.4/Include -I $X/PhysX_3.4/Include/common -I $X/PhysX_3.4/Include/geometry \
       -I $X/PhysX_3.4/Include/GeomUtils -I $P/Common/include -I $P/Common/src \
       -I $P/GeomUtils/headers -I $P/GeomUtils/include -I $G \
       $(for d in contact common convex distance sweep gjk intersection mesh hf pcm ccd; do echo -I $G/$d; done)
```

The flag table uses `--compiler toolchain/candidates/clang-6.0.1` and one
variant per row (`-UPX_SUPPORT_PVD -DPX_SUPPORT_PVD=1`, `-std=gnu++98`, ...).

The corpus is PxFoundation's 7 portable TUs, PxTask's `TaskManager.cpp`, Common
(`Cm*`) and all of GeomUtils. The Windows-only `Cm*` files under
`Common/src/windows` aren't matched by `Common/src/*.cpp`. Each configuration
takes 10 to 30 seconds.

Notes for reproducing:

- **Keep the full history** (no `--depth 1`; `--filter=blob:none` keeps it
  small), or fetch the tags (`git fetch --unshallow --tags`). The source
  revision table needs it. To sweep another revision without touching the
  checkout, extract it with
  `git -C PhysX-3.4 archive <rev> PhysX_3.4/Source PhysX_3.4/Include PxShared/src PxShared/include | tar x -C <dir>`
  and point `X` at `<dir>`. The first extraction of a revision downloads its
  blobs, which takes about a minute.
- The stand-ins only cover the `switch/` header names, so revisions before
  3.4.1 (`nx/`) don't build with them. They're ruled out anyway (see "Source
  revision").
- A sweep with one compiler and one variant only maps its own hits, so `--show`
  lists nothing. To see the misses, add a second configuration (for example
  `-O2`) whose hits map them.
- Compiling a PhysX TU by hand needs `-D__ELF__`. Without it the libc++ 7
  `<__config>` stops with "Unknown object file format". The sweep adds it
  through its base flags, as it does `-g`. A hand build needs `-g` too, or the
  code differs (see the flag table).
- `compiler_sweep.py` leaves its objects in `sweep_*` directories under the
  system temp directory (about 3 MB per full configuration). Delete them when
  you're done.

### What's left open

- **The other PhysX libraries.** Only Foundation, Task, Common and GeomUtils
  were compiled. The core (`Np*`, `Sc*`, `Scb*`), LowLevel*, SceneQuery,
  extensions, cooking and cloth are public too and need only their own include
  paths, so they can be swept the same way. The flags should carry over,
  because a single CI build produced the whole library. What can't be
  reproduced from public material are the NX platform sources and headers
  (`PsSwitchMutex.cpp`, `PsSwitchPrintString.cpp`, `switch/NpMiddlewareInfo.h`,
  the real `Px`/`PsSwitchIntrinsics.h`). NVIDIA ships those only to Switch
  licensees, so those functions have to be decompiled like game code.
- **`PX_PROFILE`, `PX_SUPPORT_PVD` and `-std`.** Now properly tested (see the
  flag table): codegen is identical in this corpus, because GeomUtils, Common
  and Foundation don't use them. The strings say release without PVD, and
  `gnu++14` is clang 6's default. `PX_SUPPORT_PVD` and `PX_PROFILE` guard code
  in the core (`NpScene`, `ScScene`), so sweeping the core settles them.
- **`-fno-builtin` or `-ffreestanding`.** They produce identical objects for
  the whole corpus, and nothing in the binary tells them apart
  (`-ffreestanding` only adds `__STDC_HOSTED__=0`, which this code doesn't
  test). The docs use `-fno-builtin`. For decompiling PhysX, either works.
- **clang 6.0.1 or a later 6.0 vendor build.** Six functions separate 6.0.1
  from 6.0.0, none separate it from anything later. There is no later public
  6.0 release to test.
- **The sweep undercounts a little.** Its `adrp` tracking is linear, so a lo12
  load reached from an `adrp` on another path is compared raw
  (`triangleConvexTest` is one such case). `tools/check.py` resolves
  relocations and doesn't have this limitation.
- **Wwise's compiler and flags** (see below).

## Wwise

Audiokinetic Wwise (`0x71003035e0`-`0x710040f550`, 4,179 functions) is
proprietary, so there's no source to sweep. **Its compiler can't be identified
without source.** What the binary shows cheaply (Sword, same in Shield):

| Check | Wwise | Game code (`0x71005a0000`-`0x7100700000`) | PhysX |
|---|---|---|---|
| Small constants as `orr wN, wzr, #imm` / as `movz` | 5,681 / 28 | 6,383 / 20 | 11,601 / 28 |
| Non-leaf functions with a `stp x29, x30` frame record | 2,343 of 2,609 | 3,445 of 3,879 | 4,242 of 4,974 |
| `movi v.2d, #0` / `stp xzr, xzr` | 8 / 1,044 | 97 / 3,057 | 432 / 1,645 |
| FDE CIEs | `zR` only | `zR` only | `zPLR` and `zR` |
| Mangled typeinfo names in `.rodata` | none with `AK`/`Ak` | | none (`-fno-rtti`) |

So Wwise was built with clang older than 9. Small constants use the `orr` form,
and clang 9+ and GCC both emit `movz`. Frame pointers are kept, zeroing is
GPR-only (as with `-mno-implicit-float`), and there are no exception tables and
no RTTI. Builtins are on: Wwise has 52 `fabs` and 144 `fsqrt` instructions and
no `fabsf` call (PhysX has none of those instructions; see "PhysX"). Those
flags look like the game's configuration rather than PhysX's (`-fexceptions`,
`-fno-builtin`), but the clang version (anything up to 8) and the `-O` level
stay open. For comparison, YEBIS has 47 `PPFX` typeinfo names, so it was built
with RTTI.
