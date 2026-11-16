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

## PhysX

**Result: PhysX was *not* built with Game Freak's compiler. It is upstream
clang 6.0.1 at `-O3`, with C++ exceptions and strict aliasing on, RTTI off,
in a release configuration.**

Compiling 143 PhysX 3.4 TUs this way reproduces **920 functions (584 KB of code)
byte-for-byte**, and 726 of the 732 functions mapped by consensus match. With
the global toolchain's compiler (clang 7.0.1) and the same PhysX flags, 463 match.

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

The binary is a slightly different 3.4 revision from the public repository's
HEAD (`5e42a5f`, "PhysX 3.4, APEX 1.4 patch release @25354359"). Two of the six
mapped misses are source differences: in the original, `Gu::contactBoxHeightfield`
and `contactConvexHeightfield` pass one more argument to `contactHullHeightfield`.
The other misses are `Array<PxDebugLine>::recreate` and three deleting destructors.
Masking addresses makes those three look like one PhysX core destructor outside
the corpus (`0x7100021330`), so consensus mapped them onto it.

### Area boundaries

These results also corrected `data/areas.csv`. The boundaries are identical in Shield.

- **PhysX is `0x7100010e30`-`0x71003035e0`.** It ends with PxFoundation
  (`PsFoundation.cpp`: "Foundation object exists already..."), the Switch
  mutex and PxTask (`TaskManager.cpp`: "PxTask dispatched twice"). Its vtables
  in `.data.rel.ro` run contiguously up to the TaskManager ones. Every unique
  sweep hit lies in `0x7100021330`-`0x7100302f50`. The first `zPLR` FDE is at
  `0x7100010f10`. Below `0x7100010e30` sits a block of one-instruction
  `ret`/`b` thunks into PhysX that is still unresolved.
- **`0x71003035e0`-`0x710040f550` is Audiokinetic Wwise**, not PhysX. It has the
  thread names `AK::BankManager`, `AK::EventManager`, `AK::IOThread` and
  `AK::OpusDecodingThread`, `.bnk` loading, and "Load bank failed :
  incompatible bank version ... Wwise". It starts with static plugin-registration
  stubs (`0x71003035e0`, `0x71003f5170`) that link records into one shared list.
  Its FDEs are all `zR`, and it has no call edges into PhysX. Its compiler
  hasn't been identified.
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
git clone --depth 1 --filter=blob:none --sparse https://github.com/NVIDIAGameWorks/PhysX-3.4.git
git -C PhysX-3.4 sparse-checkout set PhysX_3.4/Source PhysX_3.4/Include PxShared/src PxShared/include
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

### What's left open

- **The other PhysX libraries.** Only Foundation, Task, Common and GeomUtils
  were compiled. The core (`Np*`, `Sc*`, `Scb*`), LowLevel*, SceneQuery,
  extensions, cooking and cloth need their own include paths and probably more
  NX stand-ins (`switch/NpMiddlewareInfo.h`, the `PsSwitch*.cpp` sources). The
  flags should carry over, because a single CI build produced the whole library.
- **The exact PhysX revision.** The binary differs from the repository HEAD in
  at least the heightfield contact functions. Look for a matching 3.4.x
  revision before treating a non-matching function as a decompilation problem.
- **`PX_PROFILE`, `PX_SUPPORT_PVD` and `-std`.** Codegen doesn't tell them apart
  in this corpus. The strings say release without PVD, and `gnu++14` is clang 6's
  default.
- **Wwise's compiler and flags**, and the thunk block at `0x7100010a90`-`0x7100010e30`.
