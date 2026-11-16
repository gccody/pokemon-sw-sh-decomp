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
tables below were measured without it, which is why they top out at 490.

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
| **final + `-g`** | **493** | **157,660** | All 473 mapped functions match (470 without). See "Debug info". |

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
- **PhysX too.** On the PhysX corpus (clang 6.0.1, PhysX flags, revision
  `5e42a5f`, 127 TUs in that run), adding `-g` raises the hits from 699 to 716
  and matches all 566 mapped functions (549 without). The PhysX tables above
  were measured without `-g`. clang 6.0.1 also leaves the `stackinuse` loads
  unpaired with `-g`.

A `volatile` read of `ci->top` also matched all three (a debug use between the
loads blocks pairing the same way a volatile access does). Earlier hypotheses
were a vendor patch or a Game Freak source change. Neither is needed: this is
a known class of LLVM behaviour, debug info changing codegen. `-g` is in
`PKMN_CODEGEN_FLAGS`, and `lib/lua/ldo.c` is unmodified upstream source.

Sweeps should pass `-g` (`--variant "O3g=-O3 -g"`) until
`tools/compiler_sweep.py`'s base flags include it. Existing build directories
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

The sweep tool starts from the final flag set. A variant's flags come after it,
so they can switch one off (`-fno-unwind-tables`, `-mimplicit-float`, `-U__ELF__`, ...).

Linux note: the LLVM 7 Linux builds need `libtinfo.so.5` (`libtinfo5` /
`libncurses5` on Debian and Ubuntu). Ubuntu 24.04 no longer ships `libtinfo5`,
and a `libtinfo.so.5` -> `libtinfo.so.6` symlink does not work: clang fails with
``version `NCURSES_TINFO_5.0.19991023' not found`` (tested on 24.04), because
`libtinfo.so.6` only defines `NCURSES6_TINFO_*` symbol versions. Use Ubuntu
22.04 or an `ubuntu:22.04` container, as CI does. (The LLVM 6.0.1 Linux build,
used for PhysX, doesn't link libtinfo and runs on 24.04.)

## PhysX

**Result: PhysX was *not* built with Game Freak's compiler. It is upstream
clang 6.0.1 at `-O3`, with C++ exceptions and strict aliasing on, RTTI off,
in a release configuration.**

Compiling 143 PhysX 3.4 TUs this way reproduces **920 functions (584 KB of code)
byte-for-byte**, and 726 of the 732 functions mapped by consensus match. With
the global toolchain's compiler (clang 7.0.1) and the same PhysX flags, 463 match.
These numbers and the tables below come from the repository HEAD. The binary
is closest to the `v3.4.2` tag, which gives **928 functions (596 KB)** with the
same compiler and flags (see "Source revision").

```
clang 6.0.1  --target=aarch64-none-elf -mcpu=cortex-a57+fp+simd+crypto+crc
  -O3 -D__ELF__ -funwind-tables -mno-implicit-float -fPIC
  -fno-omit-frame-pointer -ffunction-sections -fdata-sections
  -fexceptions -fstrict-aliasing -fno-rtti -std=gnu++14
  -D__NX__ -DNDEBUG -DPX_PHYSX_STATIC_LIB -DPX_FOUNDATION_DLL=0 -DPX_SUPPORT_PVD=0
```

### What `lib/physx` needs that differs from `cmake/toolchain-nx64.cmake`

| Setting | Global toolchain | PhysX | Evidence |
|---|---|---|---|
| Compiler | clang 7.0.1 | **clang 6.0.1** | Version table below: 920 hits against 463 for clang 7 with the same flags. |
| Exceptions | `-fno-exceptions` | **`-fexceptions`** (C++ exceptions on) | 757 hits without. 1,279 of the binary's 1,281 `zPLR` FDEs are in PhysX, and noexcept destructors have terminate pads. |
| Aliasing | `-fno-strict-aliasing` | **`-fstrict-aliasing`** | 855 hits without. |
| Language | `-std=c++17` | **`-std=gnu++14`** | gnu++11/14/17 give identical code. `-std=c++17` (non-GNU) breaks 16 TUs because musl then hides `alloca`. `-std=gnu++98` drops to 806 hits. |
| Defines | | **`__NX__`, `NDEBUG`, `PX_PHYSX_STATIC_LIB`, `PX_FOUNDATION_DLL=0`, `PX_SUPPORT_PVD=0`** | See "Build configuration". |

Everything else is the same as the global flags: `-O3`, `-fno-rtti`,
`-mcpu=cortex-a57+fp+simd+crypto+crc`, `-D__ELF__`, `-funwind-tables`,
`-mno-implicit-float`, `-fPIC`, `-fno-omit-frame-pointer`, `-ffunction-sections`,
`-fdata-sections` and default symbol visibility. `-fno-common`, `-fno-short-enums`
and `-nostdinc++` come from the sweep's base flags and weren't varied.

The upstream Linux makefiles (`PhysX_3.4/Source/compiler/linux64`) use
`-O3 -fno-strict-aliasing -fno-exceptions -fno-rtti -fvisibility=hidden`. The
Switch build differs in three of those, so don't take flags from them.

### Versions (PhysX flags, 143 TUs, 1,815 compiled functions, 742 mapped)

| Compiler | `-O3` hits | `-O3` bytes | `-O3` avg similarity | `-O2` hits | `-fno-exceptions` hits | `-fno-strict-aliasing` hits |
|---|---:|---:|---:|---:|---:|---:|
| clang 3.9.1 | 373 | 36,512 | 0.786 | 373 | 306 | 379 |
| clang 4.0.1 | 425 | 46,768 | 0.828 | 422 | 340 | 427 |
| clang 5.0.1 / 5.0.2 | 659 | 122,040 | 0.929 | 631 | 550 | 638 |
| clang 6.0.0 | 918 | 582,580 | 0.989 | 766 | 755 | 853 |
| **clang 6.0.1** | **920** | **584,120** | **0.991** | 768 | 757 | 855 |
| clang 7.0.0 / 7.0.1 / 7.1.0 | 463 | 74,872 | 0.859 | 435 | 431 | 449 |
| clang 8.0.0 / 8.0.1 | 435 | 66,524 | 0.809 | 407 | 403 | 423 |
| clang 9.0.1 | 137 | 9,840 | 0.725 | 130 | 119 | 134 |
| clang 10.0.0 | 33 | 2,096 | 0.608 | 31 | 28 | 30 |
| clang 11.0.0 | 32 | 1,996 | 0.587 | 30 | 27 | 29 |

clang 10 and 11 reject 19 and 20 of the TUs, so their rows are lower bounds,
but they're far behind even on the TUs they do compile. 6.0.0 and 6.0.1 differ
in exactly two functions, `Gu::RTree::traverseRay<0>` and `<1>`, and only 6.0.1
reproduces them. A vendor build based on a later 6.0 branch can't be ruled out
(there is no upstream 6.0.2).

### Flags (clang 6.0.1 `-O3`, each row changes one thing, 732 mapped)

| Variant | Hits | Bytes | Exact of mapped | What it shows |
|---|---:|---:|---:|---|
| **final** | **920** | **584,120** | **726** | |
| `-frtti` | 920 | 584,120 | 726 | RTTI doesn't change code. It's off because no PhysX class has a typeinfo name, and PhysX vtables have no typeinfo slot. |
| `-fno-exceptions` | 757 | 502,724 | 605 | Cleanup landing pads are part of the original code. |
| `-fno-cxx-exceptions` | 826 | 563,540 | 659 | Keeps cleanups but drops noexcept enforcement. The original calls a shared terminate helper (`0x7101750e90`) after noexcept destructors (e.g. the `Gu::HeightField` D0 at `0x710014f2f0`), so C++ exceptions are fully on. |
| `-fno-strict-aliasing` | 855 | 509,836 | 676 | |
| `-O2` | 768 | 299,508 | 599 | |
| `-fno-unwind-tables` | 851 | 574,020 | 679 | |
| `-mimplicit-float` | 677 | 220,736 | 540 | GPR-only copies, the same as game code. |
| `-mcpu=generic` | 132 | 5,936 | 70 | Cortex-A57 scheduling model. |
| `-fomit-frame-pointer` | 397 | 106,708 | 310 | |
| `-fno-pic` | 753 | 438,600 | 618 | |
| `-fvisibility=hidden` | 782 | 521,460 | 647 | Globals go through the GOT, unlike in the Linux build. |
| `-DPX_CHECKED=1` | 869 | 557,928 | 686 | Release, not checked. |
| `-DPX_PROFILE=1`, `-DPX_SUPPORT_PVD=1`, `-std=gnu++11`/`gnu++17` | 920 | 584,120 | 726 | Not distinguishable with this corpus. |

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
@24214033"), except for at least `GuContactConvexMesh.cpp`, which matches no
public revision.**

The public revisions since 3.4.1 that touch the corpus were swept with the
final configuration (clang 6.0.1, `-O3`, PhysX flags). The two 3.4.1 updates
`3cc1861` and `57b71f8` were only checked on `GuContactConvexMesh.cpp`.

| Revision | Perforce CL | Hits | Bytes |
|---|---|---:|---:|
| `d1c812f` (`v3.4.1`) | 22845541 | 875 | 560,240 |
| `983c93a` | 23307153 | 910 | 584,248 |
| `b6db9a5` | 23472123 | 916 | 588,516 |
| `52dae55` | 23576764 | 917 | 588,568 |
| `238605d` | 23879214 | 925 | 591,924 |
| **`b99b378` (`v3.4.2`)** | **24214033** | **928** | **596,024** |
| `3f9977d` | 24698370 | 925 | 585,960 |
| `ad993f2` | 24990349 | 923 | 585,500 |
| `78cab22` | 25256367 | 921 | 585,468 |
| `326e240` (= HEAD `5e42a5f` for these files) | 25354359 | 920 | 584,120 |

The `v3.4.2` hits are a strict superset of those of its neighbours and of HEAD:

- Over `238605d`: three `PCMConvexVsMeshContactGeneration` functions.
- Over `3f9977d`: `epaPenetration`, `EPA::PenetrationDepth` and `Facet::silhouette`.
- Over HEAD: those three, plus `barycentricCoordinates`, both
  `BV4Tree(PxEMPTY)` constructors, `HeightField::getTriangleAdjacencyIndices`
  and `ConvexTraceSegmentReport::onEvent`.

Revisions before 3.4.1 are ruled out by path. They keep the Switch platform
files under `nx/` (`foundation/nx/PxNXIntrinsics.h`), while the binary's
`__FILE__` strings use the `switch/` names that 3.4.1 introduced (they don't
build with the stand-ins below either).

The heightfield code of `GuContactConvexMesh.cpp` compiles the same in every
revision from 3.4.1 to HEAD, and it doesn't match the binary:

- `Gu::contactBoxHeightfield` and `contactConvexHeightfield` are where the
  "one more argument" difference shows up. It isn't a change to their source.
  Both callers match exactly when the TU is built at `-O2` or with
  `-DPX_CHECKED=1`. The difference therefore comes from the static
  `contactHullHeightfield2`. Its body decides how `-O3` interprocedural
  passes (probably argument promotion) rewrite its parameters.
- The original `contactHullHeightfield2` (`0x71001285c0`) is 1,352 bytes. No
  variant reproduces it (1,948 at `-O3`, 1,252 at `-O2`, 2,068 checked). It
  calls an out-of-line 680-byte function (`0x7100129340`), roughly where `-O2`
  outlines the `ConvexMeshContactGeneration` constructor (792 bytes).
- The original TU also has two functions with no counterpart in the compiled
  TU (`0x7100127250`, 1,292 bytes, and `0x7100127760`, 1,340 bytes).
  `contactHullMesh2`, `generateLastContacts` and `generateContacts` differ as well.

So the library was built from `v3.4.2` with changes to the convex-vs-mesh and
heightfield contact code. That could be an NVIDIA platform drop or a local
patch; nothing in the binary tells them apart. Expect more TUs outside the
corpus to differ the same way.

The other misses at HEAD are `Array<PxDebugLine>::recreate` and three deleting
destructors. Masking addresses makes those three look like one PhysX core
destructor outside the corpus (`0x7100021330`), so consensus mapped them onto it.

### Area boundaries

These results also corrected `data/areas.csv`. The boundaries are identical in Shield.

- **PhysX is `0x7100010a90`-`0x71003035e0`.** It ends with PxFoundation
  (`PsFoundation.cpp`: "Foundation object exists already..."), the Switch
  mutex and PxTask (`TaskManager.cpp`: "PxTask dispatched twice"). Its vtables
  in `.data.rel.ro` run contiguously up to the TaskManager ones. Every unique
  sweep hit lies in `0x7100021330`-`0x7100302f50`. The first `zPLR` FDE is at
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
git -C PhysX-3.4 checkout v3.4.2      # the revision the binary is closest to
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
The common flags after `--` come *after* each variant's flags, so they must not
contain anything a variant should change (`-std`, `PX_SUPPORT_PVD`):

```sh
X=toolchain/candidates/src/PhysX-3.4; P=$X/PhysX_3.4/Source; G=$P/GeomUtils/src
B="-O3 -fexceptions -fstrict-aliasing -std=gnu++14 -DPX_SUPPORT_PVD=0"
python tools/compiler_sweep.py --compiler 'toolchain/candidates/clang-*' \
    --variant "O3=$B" --variant "O2=$B -O2" --variant "noeh=$B -fno-exceptions" \
    --variant "nostrict=$B -fno-strict-aliasing" \
    --src "$X/PxShared/src/foundation/src/*.cpp" --src "$X/PxShared/src/task/src/*.cpp" \
    --src "$P/Common/src/*.cpp" --src "$G/**/*.cpp" \
    --range 0x7100010e30-0x71003035e0 \
    -- -fno-rtti -nostdinc++ -isystem toolchain/candidates/src/libcxx-7.0.1/include \
       -isystem toolchain/candidates/sysroot/include \
       -D__NX__ -DNDEBUG -DPX_PHYSX_STATIC_LIB -DPX_FOUNDATION_DLL=0 \
       -D_LIBCPP_HAS_MUSL_LIBC -D_LIBCPP_HAS_THREAD_API_PTHREAD \
       -I toolchain/candidates/src/physx-nx-shim -I $X/PxShared/include \
       -I $X/PxShared/src/foundation/include -I $X/PxShared/src/foundation/include/unix \
       -I $X/PxShared/src/task/include -I $X/PxShared/src/pvd/include -I $X/PxShared/src/fastxml/include \
       -I $X/PhysX_3.4/Include -I $X/PhysX_3.4/Include/common -I $X/PhysX_3.4/Include/geometry \
       -I $X/PhysX_3.4/Include/GeomUtils -I $P/Common/include -I $P/Common/src \
       -I $P/GeomUtils/headers -I $P/GeomUtils/include -I $G \
       $(for d in contact common convex distance sweep gjk intersection mesh hf pcm ccd; do echo -I $G/$d; done)
```

The corpus is PxFoundation's 7 portable TUs, PxTask's `TaskManager.cpp`, Common
(`Cm*`) and all of GeomUtils. The Windows-only `Cm*` files under
`Common/src/windows` aren't matched by `Common/src/*.cpp`. Each configuration
takes about 10 seconds.

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
  through its base flags.
- `compiler_sweep.py` leaves its objects in `sweep_*` directories under the
  system temp directory (about 3 MB per full configuration). Delete them when
  you're done.

### What's left open

- **The other PhysX libraries.** Only Foundation, Task, Common and GeomUtils
  were compiled. The core (`Np*`, `Sc*`, `Scb*`), LowLevel*, SceneQuery,
  extensions, cooking and cloth need their own include paths and probably more
  NX stand-ins (`switch/NpMiddlewareInfo.h`, the `PsSwitch*.cpp` sources). The
  flags should carry over, because a single CI build produced the whole library.
- **PhysX's local changes.** The base revision is `v3.4.2` (see "Source
  revision"), but `GuContactConvexMesh.cpp` matches no public revision. Expect
  that in other TUs too. When a PhysX function won't match, diff it against
  the `v3.4.2` source before treating it as a decompilation problem.
- **`PX_PROFILE`, `PX_SUPPORT_PVD` and `-std`.** Codegen doesn't tell them apart
  in this corpus. The strings say release without PVD, and `gnu++14` is clang 6's
  default.
- **Wwise** is clang 6.0.x too, but with the game's aliasing and exception
  flags (see below).

## Wwise

**Result: Wwise 2017.2, built with upstream clang 6.0.x (like PhysX, not the
game's 7.0.1) at `-O2` or `-O3`, with the game's codegen flags. That means
strict aliasing off, unlike PhysX.**

```
clang 6.0.0 or 6.0.1  --target=aarch64-none-elf -mcpu=cortex-a57+fp+simd+crypto+crc
  -O3 (or -O2) -DNDEBUG -D__ELF__ -funwind-tables -mno-implicit-float -fPIC
  -fno-omit-frame-pointer -fno-strict-aliasing -ffunction-sections -fdata-sections
  C++: -fno-exceptions -fno-rtti (from the binary, not from the corpus)
```

Wwise (`0x71003035e0`-`0x710040f550`, 4,179 functions) is proprietary. It
contains one piece of public code that compiles to identical machine code:
Matthew Conte's **TLSF** allocator, which backs Wwise's memory manager.
Compiled with clang 6.0.0 or 6.0.1, it reproduces **all 8 TLSF functions in
the binary (2,596 bytes) byte-for-byte, in both games**. No other version gets
more than 6.

Confidence:

- **High** that the TLSF TU was built with clang 6.0.x, `-O2`/`-O3`,
  `-fno-strict-aliasing`, unwind tables, frame pointers and the Cortex-A57
  model.
- **Medium** that this holds for all of Wwise. It's one TU, but it sits inside
  the Wwise block, it's reached only through Wwise's allocator wrappers, and
  Audiokinetic ships the sound engine as one set of prebuilt libraries. The
  fingerprints below agree.
- **Not determined:** 6.0.0 vs 6.0.1, `-O2` vs `-O3`, and `-g`.

### Version

The bank loader (`0x7100343f80`) rejects banks whose version isn't 128. It
prints "Load bank failed : incompatible bank version. Bank was generated with
%s version of Wwise. The Bank version is %d and the current SDK version is %d",
with `mov w5, #0x80` as the SDK version and "an older"/"a newer" chosen by
`cmp w4, #0x7f`. The binary has no Wwise version string. Audiokinetic doesn't
publish a bank-version table, but the open-source bank parser
[wwiser](https://github.com/bnnm/wwiser) (`wwiser/parser/wdefs.py`) lists
**bank version 128 as Wwise 2017.2**. 2017.1 is 125/126 and 2018.1 is 132. Its
example games for 128 include Let's Go Pikachu (Switch).

### Public code in Wwise

Wwise references only 12 strings, so most of this comes from constant tables
(the public source's tables searched for in the image, not dumped) and from code
shape.

| Candidate | Found? | Usable as a corpus? |
|---|---|---|
| **TLSF** | `tlsf_create: Pool size must be at least %d bytes.` (`0x71003049d0`) | **Yes**, see below |
| libvorbis | The float window tables `vwin256` to `vwin4096` of `window.c` are in `.data`, all used by `0x7100406560` | No. That function and the rest of the decoder are Wwise's own rewrite: libvorbis + libogg compiled with clang 6.0.1/7.0.1 at `-O2`/`-O3`/`-Os` give 0 hits, and the closest functions have similarity < 0.4. The fixed-point Tremor tables aren't present. |
| libopus | No | Opus goes through the SDK's `nn::codec::HardwareOpusDecoder` (imported). `AK::OpusDecodingThread` is the thread that drives it. |
| Kiss FFT | `kiss fft usage error: improper alloc` | Not Wwise: it's referenced from game code (`0x710078e07c`), and upstream `kiss_fft.c`/`kiss_fftr.c` give 0 hits there. |
| zlib, CRC-32, MurmurHash3, xxHash32 | No strings, no CRC-32 table, no `movz`/`movk` of their constants in the Wwise range | |
| FNV-1 | The 32-bit prime and offset basis (`0x01000193`, `0x811c9dc5`) are built 14 and 12 times | No. Wwise's ID hashing, a few instructions with no library code around it. |

### TLSF corpus

The binary's TLSF is the **2.0** release with one fix from 3.x:

- `tlsf_create(void* mem, size_t bytes)` and its "Pool size must be at least"
  message are 2.0. 3.0 split pool creation into `tlsf_add_pool`, with different
  messages.
- `tlsf_malloc` and `tlsf_memalign` use 3.x's `adjust_request_size`, which
  checks `aligned < block_size_max` instead of `size < block_size_max`
  (mattconte/tlsf `2b73b8a`, "Fix block_size_max handling in
  adjust_request_size", 2016). Plain 2.0 misses exactly those two functions.
  3.x misses `tlsf_create` and `block_locate_free`.
- `tlsf_realloc`, `tlsf_check_heap` and `tlsf_walk_heap` aren't in the binary
  (presumably dropped by `--gc-sections`).

The Wwise side of TLSF is `0x71003045e0`-`0x7100305450`: allocator wrappers
called from 1,024 Wwise functions (and 3 game functions), including the bank
loader, with the TLSF functions between them. All addresses are the same in Shield.

**Versions** (2.0 + the `2b73b8a` `adjust_request_size`, `-DNDEBUG`, 8 mapped):

| Compiler | `-O3` hits | `-O3` bytes | `-O3` avg similarity | `-O2` hits | `-Os` hits |
|---|---:|---:|---:|---:|---:|
| clang 3.9.1 | 1 | 16 | 0.736 | 1 | 1 |
| clang 4.0.1 | 3 | 464 | 0.814 | 3 | 2 |
| clang 5.0.1 / 5.0.2 | 6 | 1,748 | 0.820 | 6 | 2 |
| **clang 6.0.0 / 6.0.1** | **8** | **2,596** | **1.000** | **8** | 2 |
| clang 7.0.0 / 7.0.1 / 7.1.0 | 2 | 104 | 0.779 | 2 | 2 |
| clang 8.0.0 / 8.0.1 | 2 | 104 | 0.683 | 2 | 2 |
| clang 9.0.1 | 1 | 16 | 0.658 | 1 | 1 |
| clang 10.0.0 / 11.0.0 | 1 | 16 | 0.614 | 1 | 1 |

The two functions every version from 4 to 8 gets are `tlsf_block_size` and
`tlsf_malloc`. Where clang 7 differs, it's a redundant zero extension that
clang 6 keeps before a 32-bit variable shift. The original has
`and x10, x10, #0xffffffff` / `lsl w10, w12, w10` (`block_merge_next`, the
`fl_bitmap` update in the inlined `remove_free_block`), and clang 7 drops the
`and`. Unmodified upstream sources score lower but agree: TLSF 2.0 alone gets
6/6 mapped with clang 6.0.x (5.0.x: 4, 7.x: 1), and mattconte `2b73b8a` gets
5/5 (5.0.x and 6.0.x: 5, 7.x: 2).

**Flags** (clang 6.0.1, `-O3 -DNDEBUG`, each row changes one thing, 8 mapped):

| Variant | Hits | Bytes | What it shows |
|---|---:|---:|---|
| **final** | **8** | **2,596** | |
| without `-DNDEBUG` | 2 | 104 | `tlsf_assert` is `assert`, and asserts are compiled out. |
| `-O2` | 8 | 2,596 | Not distinguishable. |
| `-Os` / `-O1` | 2 / 0 | | |
| `-fstrict-aliasing` | 3 | 496 | Strict aliasing is off, as in the game and unlike PhysX. |
| `-fno-unwind-tables` | 4 | 1,024 | |
| `-fomit-frame-pointer` | 4 | 1,024 | |
| `-mcpu=generic` | 1 | 16 | |
| `-g`, `-mimplicit-float`, `-fno-pic`, `-fvisibility=hidden`, `-U__ELF__`, C++ (`-x c++ -std=gnu++14`, with or without `-fexceptions`) | 8 | 2,596 | Not distinguishable with this corpus. |

The binary decides what TLSF can't:

- **Exceptions off.** All Wwise FDEs are `zR`, even though Wwise is C++ with
  destructors. With `-fexceptions` there would be `zPLR` FDEs, as in PhysX.
- **No RTTI.** There are no `AK`/`Ak` typeinfo names.
- **No implicit float.** See the table below.

### Fingerprints over the whole block

Sword. Shield's Wwise has the same layout.

| Check | Wwise | Game code (`0x71005a0000`-`0x7100700000`) | PhysX |
|---|---|---|---|
| Small constants as `orr wN, wzr, #imm` / as `movz` | 5,681 / 28 | 6,383 / 20 | 11,601 / 28 |
| Non-leaf functions with a `stp x29, x30` frame record | 2,343 of 2,609 | 3,445 of 3,879 | 4,242 of 4,974 |
| `movi v.2d, #0` / `stp xzr, xzr` | 8 / 1,044 | 97 / 3,057 | 432 / 1,645 |
| FDE CIEs | `zR` only | `zR` only | `zPLR` and `zR` |
| Mangled typeinfo names in `.rodata` | none with `AK`/`Ak` | | none (`-fno-rtti`) |
| Adjacent pairable `ldr` pairs whose second destination is the base / `ldp` with that form | **0 / 40** | 11 / 162 | 5 / 157 |
| `and xN, xM, #0xffffffff` feeding a 32-bit variable shift within 4 instructions | 11 in 7 functions | 0 | 1 |

- **The `ldr` pair row is the `-g` fingerprint** (see "Debug info"). Both
  `-g` builds have it: game code 11 against 162, Lua 3 against 40. Wwise has
  none against 40. With the game's rate about 3 would be expected, so **Wwise
  was probably built without `-g`**. That's low confidence: it's a small
  count, and the pattern depends on the source. TLSF itself compiles the same
  with or without `-g`.
- **The `and` row** is the clang 6 idiom TLSF shows. 3 of the 7 functions are
  TLSF. The other 4 are elsewhere in Wwise (`0x71003a9300`, `0x71003ad140`,
  `0x7100408370`, `0x710040b1b0`). It never appears in the clang 7.0.1 regions
  (game code, Lua). That's only supporting evidence: a small hand-written
  reproducer didn't trigger it in clang 6.0.1 either, so it depends on the
  source too.

### Reproducing

Fetch the sources into `toolchain/candidates/src` (all small). `samplecount/tlsf`
is an unmodified import of Conte's TLSF 2.0 (its `VERSION` file says `2.0`).
The barebox copies of 2.0 are modified, so don't use them.

```sh
cd toolchain/candidates/src
git clone https://github.com/samplecount/tlsf.git tlsf-2.0
git clone --filter=blob:none https://github.com/mattconte/tlsf.git tlsf
mkdir tlsf-wwise && cp tlsf-2.0/tlsf.h tlsf-2.0/tlsfbits.h tlsf-wwise/
git -C tlsf show 2b73b8a:tlsf.c > tlsf-2b73b8a.c
python - <<'EOF'
import re
pat = re.compile(r"static size_t adjust_request_size\(.*?\n\}\n", re.S)
a = open("tlsf-2.0/tlsf.c").read()
fix = pat.search(open("tlsf-2b73b8a.c").read()).group(0)
open("tlsf-wwise/tlsf.c", "w", newline="\n").write(pat.sub(lambda m: fix, a, count=1))
EOF
cd ../../..

B="-O3 -DNDEBUG"
python tools/compiler_sweep.py --compiler 'toolchain/candidates/clang-*' \
    --variant "O3=$B" --variant "O2=$B -O2" --variant "Os=$B -Os" --variant "O3g=$B -g" \
    --src toolchain/candidates/src/tlsf-wwise/tlsf.c --range 0x71003035e0-0x710040f550 \
    -- -isystem toolchain/candidates/sysroot/include
```

For the flags table, use `--compiler toolchain/candidates/clang-6.0.1` with
variants such as `"strict=$B -fstrict-aliasing"`. Keep every flag that changes
in the variants and only the include path after `--`. Add `--game shield` to
check Shield. Each configuration takes about a second.

### What's left open

- **6.0.0 vs 6.0.1, `-O2` vs `-O3`.** TLSF is too small to tell them apart,
  and no other public code in Wwise compiles to the same instructions.
- **`-g`.** Probably off (fingerprint above), not proven.
- **Whether every Wwise library used the same configuration.** Only the
  memory manager's TLSF was compiled. The plugin-registration stubs and the
  codecs are separate libraries in the Wwise SDK.
- **How the Vorbis decoder was derived.** Its window tables are libvorbis's,
  but the code isn't. Matching it needs the decompilation route.

## Other middleware

Fingerprints with the same definitions as above (Sword):

| Region | Small consts `movz` / `orr` | Frame records (calling functions) | `movi #0` / `stp xzr, xzr` | FDEs `zR` / `zPLR` | `-g` `ldr` pairs / `ldp` |
|---|---|---|---|---|---|
| YEBIS (`0x710040f550`-`0x71005a0000`) | 78 / 9,819 | 2,455 of 2,474 | 3 / 1,059 | 5,183 / 0 | 5 / 255 |
| After Lua (`0x7101570900`-`0x71017ec260`) | 380 / 15,358 | 6,329 of 6,344 | 116 / 1,123 | 10,846 / 1 | 1 / 868 |

In this table, "small constants" counts only immediates that `orr` can
encode, "frame records" counts functions with a `bl` whose first 12
instructions hold `stp x29, x30`, and `stp xzr, xzr` counts single
instructions. That's why the numbers differ from the Wwise table above.

- **YEBIS embeds zlib 1.2.5**: the `"1.2.5"` version string and inflate's
  `header crc mismatch`, used by SiIO's `SiIO_Codec_ZLib_Impl.h` (the code is
  around `0x710058be50`-`0x7100596000`). Upstream zlib 1.2.5 reproduces **30
  functions (34,116 bytes) byte-for-byte with clang 7.0.x at `-O3` and exactly
  the game's flags, in both games**. clang 8.0.x gets 17, 6.0.x gets 3, and
  9.0.1 gets 0. Each flag change loses hits (clang 7.0.1, `-O3`):
  `-O2` 8, `-Os` 3, `-fstrict-aliasing` 20, `-fno-unwind-tables` 18,
  `-mimplicit-float` 20, `-fomit-frame-pointer` 15, `-fno-pic` 27 and
  `-mcpu=generic` 3. `-g` and `-fvisibility=hidden` give 30 as well. So at
  least YEBIS's zlib was built with the game's toolchain, unlike Wwise and
  PhysX. Silicon Studio may have used the same compiler, or Game Freak may have
  built YEBIS from source. Nothing here tells those apart. YEBIS also keeps RTTI
  (47 `PPFX` typeinfo names) and has no exception tables.

  ```sh
  cd toolchain/candidates/src && curl -LO https://zlib.net/fossils/zlib-1.2.5.tar.gz && tar xzf zlib-1.2.5.tar.gz && cd ../../..
  Z=toolchain/candidates/src/zlib-1.2.5
  python tools/compiler_sweep.py --compiler 'toolchain/candidates/clang-*' \
      --variant O3=-O3 --variant O3g="-O3 -g" --variant O2=-O2 --variant Os=-Os \
      --src "$Z/[a-di-z]*.c" --src "$Z/gz*.c" --range 0x710040f550-0x71005a0000 \
      -- -isystem toolchain/candidates/sysroot/include
  ```

  (The two globs leave out `example.c` and `minigzip.c`.)
- **After Lua** (NEX 4.6.8, Pia, NintendoWare, nn SDK static libraries): all
  `orr`-form constants (clang older than 9), frame pointers, GPR-only zeroing
  and no exception tables (1 `zPLR` FDE). Only 1 `-g` `ldr` pair against 868
  `ldp`, so these libraries probably weren't built with `-g`. NEX's source isn't
  public. The block does contain public code that could identify Nintendo's
  SDK compiler later: libcurl 7.55.1 (`libcurl/7.55.1`,
  `NintendoSDK_libcurl-7_3_2-Release`), a zlib 1.2.11 build
  (`1.2.11.f-NINTENDO-SDK-v1`) and LZ4 (`nlib_LZ4-19_0226`). Those weren't
  swept here.
