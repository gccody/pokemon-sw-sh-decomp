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
original function's instructions exactly, apart from address fields. The
compiled object's relocations say where those are: every instruction with a
relocation (calls and tail calls, `adrp`, the lo12 half of `add`/`ldr`/`str`,
GOT loads, ...) has its immediate field masked, and so does the original's
instruction at the same offset, by its instruction class. Everything else,
including struct offsets and branches inside the function, has to be
identical. This needs no names or addresses. Hits from all configurations
together give a name → address map, so every configuration also gets a
similarity score over the same functions.

Earlier versions masked both sides by tracking `adrp` linearly through the
code. A lo12 load whose `adrp` sat on another path (laid out after it) was then
compared raw and counted as a miss. The relocation-based masking fixed that.
It changed no Lua or TLSF hit count, and it added 20 PhysX hits (see "PhysX").
It also no longer masks branches that need no relocation, so functions that
differ only in their internal branches stop mapping onto each other.
Similarity scores move by up to about 0.02. The Wwise and Nintendo SDK tables
below were measured before the change; their hit counts were re-checked
(TLSF, zlib) and are the same.

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
  `loadlib.c` functions Game Freak changed, matched later by reconstructing
  its `readable()` change; see "What's left open").
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
  `v3.4.2`, 143 TUs), `-g` raises the hits from 1,151 to 1,244 and the exact
  matches from 936 to 1,026 of 1,032 mapped. It raises the hits in every other
  PhysX library but LowLevel too (see "PhysX"). clang 6.0.1 also
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

- **No implicit float.** Game code (`0x7100596d20`-`0x7101548410`) has 37,688
  `stp xzr, xzr` (17,946 contiguous pairs) against 703 `movi v.2d, #0`, and
  3,748 `ldp x`/`stp x` 16-byte copies against 155 `ldr q`/`str q` (those are
  explicit vector types). YEBIS and the middleware show the same pattern.
- **No exceptions in Game Freak code.** All 74,892 game FDEs use a `zR` CIE (no
  personality, no LSDA). PhysX has 1,280 `zPLR` FDEs: NVIDIA built it with
  exceptions, so check vendor libraries separately.

These counts come from `tools/fingerprint.py` (see "Codegen fingerprints" at
the end for the definitions and the full table). Earlier versions of this
section measured older, narrower game-code ranges with ad-hoc scripts (17,869
pairs, 3,720 copies, 74,530 FDEs, 1,250 `zPLR`).

The four functions checked by `tools/check.py` still match in both games with
clang 7.0.1.

### Traps

**Result: the traps are where upstream clang puts them. Only their encoding
differs: Nintendo's toolchain writes the word `0xe7ffdefe` where upstream
clang writes `brk #1` (`0xd4200020`). No clang option changes the encoding, so
the build rewrites it in every object (`tools/fix_traps.py`, run as the
compiler launcher by `cmake/TrapEncoding.cmake`).** With that, functions
with a trap match in both games, for example the deleting destructors
`0x710067b7b0` and `0x710067b7d0`. Compiled without the rewrite, they
fail on that one word.

**The encoding.** Every trap in every module Nintendo's toolchain built is
`0xe7ffdefe`, the A32 encoding LLVM's ARM backend uses for `trap` (in A64 it's
an unallocated encoding, so it raises an undefined-instruction exception).
None of the modules has a `brk` with any immediate. The counts are the same
in both games:

| Module | Built by | `0xe7ffdefe` | `brk` |
|---|---|---:|---:|
| `main` | Game Freak (clang 7.0.1), PhysX (clang 6.0.1), Wwise, YEBIS, middleware | 650 | 0 |
| `sdk` | Nintendo | 264 | 0 |
| `subsdk0` | Nintendo | 309 | 0 |
| `subsdk1` | Nintendo | 1 | 0 |
| `rtld` | Nintendo | 0 | 0 |

Code built with two clang versions (7.0.1 for Game Freak's code, 6.0.1 for
PhysX) has the same word, and so do the SDK modules, which Nintendo builds
and links separately from `main`. So it comes from the NX toolchain, not from any one
library's source or build. Upstream clang 6.0.1 and 7.0.1 both lower
`llvm.trap` to `brk #1` for `aarch64-none-elf`, and their `-mllvm --help-hidden`
has no option for the encoding. In LLVM 7, `llvm.debugtrap` is `brk #1` too,
so the originals can't show whether the toolchain also rewrites debug traps
(the build rewrites every `brk #1`). No public source documents a vendor
patch, and none mentions `0xe7ffdefe` on AArch64. Whether Nintendo's clang
emits it directly (a patched AArch64 trap lowering) or an assembler or linker
step rewrites it can't be told from the binary, and it makes no difference to
the objects. Confidence: high that it's the toolchain, unknown which stage.

**The placement.** The traps are `llvm.trap` calls that upstream clang and
LLVM create by themselves, without any option. By context, in both games:

| Context | Count | Game code | What it is |
|---|---:|---:|---|
| The whole function is one trap word, referenced from a vtable | 332 | 158 | Deleting destructor (D0) of an abstract class. Clang emits it as `llvm.trap` because it can never be called. The vtable slot before it is the D1. |
| Last word of a function, after a call | 193 | 186 | Code on a path where a pointer is known to be null: the call (often with `x0 = 0`, e.g. a constructor or `memset`) is kept, and the store through the null pointer after it becomes a trap. |
| Last word of a function, after anything else | 113 | 100 | The same for a null path that is branched to (`cbz x, <trap>`), typically a pointer converted to a base class at a non-zero offset (null check) and then used for a virtual call. |
| Inside a function | 12 | 3 | The same, laid out mid-function. |
| **Total** | **650** | **447** | |

LLVM turns a store through a null pointer into `llvm.trap` (SimplifyCFG,
`changeToUnreachable` with `UseLLVMTrap`), and InstCombine turns a load from
null into such a store first. These are all upstream passes at `-O3`.

It isn't LLVM's trap-on-unreachable (`TargetOptions::TrapUnreachable`, which
some vendor toolchains turn on; LLVM 7 has it as `-mllvm -trap-unreachable`):

- 5,813 game functions end in a call to a function that doesn't return, with
  no trap after it. PhysX has 1,246 such functions, Lua 96, and none of them
  has a trap either. With trap-on-unreachable, each would end in one.
- Lua, built by Game Freak with the global flags, has no trap at all.
  Compiling `lib/lua` with `-mllvm -trap-unreachable` gives 159 traps.
- Of the 18 functions called right before a trap, 17 never end a function
  without one, so they aren't `noreturn`. The trap belongs to the code after
  the call.

So the global flags stay as they are.

**The rewrite.** `tools/fix_traps.py --run -- <compiler command>` compiles, then
replaces `brk #1` with `0xe7ffdefe` in the object, in place. It changes only
4-byte-aligned words in executable sections, inside code regions (`$x`
mapping symbols, never `$d` data), at offsets without a relocation. Other
`brk` immediates, data and other sections are left alone, and running it twice
changes nothing. `cmake/TrapEncoding.cmake` makes it the C and C++ compiler
launcher, so it applies to every target, including libraries with their own
`COMPILER_VERSION`, and `compile_commands.json` keeps the plain compiler
command. `tools/check.py` stops if a build dir doesn't rewrite traps, and it
names the cause when a compiled `brk #1` meets the original's trap word.
`tests/test_fix_traps.py` covers the rewrite with hand-built objects.

The PhysX sweep's 31 lone traps (see "What the sweep doesn't reproduce") are
the same case: deleting destructors of abstract classes, the same code once
the trap word is rewritten. `compiler_sweep.py` compiles without the build,
so it still sees `brk #1`.

## What's left open

Game Freak's C++ was tested with 32 small decompiled game functions
(all `common`: getters and setters, struct copies, delegate calls and invokers,
`find_if`-style loops, an array remove, small branchy functions, two float
functions). All 32 match in both games with the global flags. Each TU under
`src/` was also recompiled with one flag appended and checked against both
games:

| Variant | OK of 32 | Lost |
|---|---|---|
| global flags (`-O3 -g -std=c++17`) | 32 | – |
| `-g0` or `-gline-tables-only` | 28 | `0x71005e65b0`, `0x7100601110`, `0x7100c864f0`, `0x71014f7a50` |
| `-O2` or `-Os` | 22 | `0x71007f2e90`, `0x7100a6d3c0`, `0x7100ea5d80`, `0x7100f4ac50`, `0x7100ffd350`, `0x71014e6d50`, `0x71014f5fb0`, `0x71014f7960`, `0x71014f79b0`, `0x71014f7a50` |
| `-O1` | 12 | 20 |
| `-O2 -mllvm -tail-dup-placement-threshold=4` | 30 | `0x71014f7960`, `0x71014f79b0` |
| `-O3 -mllvm -tail-dup-placement-aggressive-threshold=2` | 23 | the 9 `-O2` losses other than `0x71014f7960` |
| `-std=c++11`, `c++14`, `gnu++14`, `gnu++17` | 32 | none |

No function matches only with a changed flag.

- **The `-O` level for Game Freak's C++ code: `-O3`.** Ten of the 32
  functions match at `-O3` and at neither `-O2` nor `-Os`. Eight of them
  differ by one mechanism: LLVM 7's block placement duplicates a small shared
  tail (here 3 or 4 instructions ending in `ret`, such as `cmp; csel; ret` or
  `sub; str; ret`) into each predecessor up to 4 instructions at `-O3`
  (`tail-dup-placement-aggressive-threshold`), but only up to 2 at `-O2`/`-Os`
  (`tail-dup-placement-threshold`). The original has those tails duplicated.
  The two `-mllvm` rows show that this is the cause: raising the `-O2`
  threshold to 4 makes those 8 match, and lowering the `-O3` one to 2 breaks
  them. The other two need something else from `-O3`. In `0x71014f7960` a debug
  value of an inlined iterator survives at `-O2`/`-Os` and keeps its begin/end
  loads apart (two `ldr` instead of the original's `ldp`), and `0x71014f79b0`
  still differs at `-O2` with the higher threshold. Seven of the
  eight were picked for this: a scan for small leaf functions whose `ret`
  tail of 3-4 instructions appears twice found 59 undecompiled ones of at most
  0x60 bytes. Of 8 tried from that list, 7 matched and all 7 match only at
  `-O3`. The eighth (`0x7100ab9960`) wasn't matched (operand order of an
  `orr`), so it says nothing about `-O`. The other two new functions came
  from a scan for small functions with loops: `0x71014f79b0` is `-O3`-only,
  and `0x71008130b0` (an array remove) also matches at `-O2`/`-Os`.
- **The C++ standard version: not discriminated.** c++11, c++14, c++17,
  gnu++14 and gnu++17 give identical code for all 32 functions. `-std=c++17`
  stays as the default. Only code using a feature whose codegen differs
  between standards (guaranteed copy elision, aligned `new`, inline
  variables) could tell them apart. The sol2 glue is built as C++14 (see
  "sol2"), but only because sol2 switches on `__cplusplus` itself, so it
  says nothing about the rest of the game.
- **`-g` beyond Lua: confirmed for Game Freak's C++.** Four of the game's
  adjacent pairable `ldr` pairs whose second destination is the base match
  only with `-g` (63 such pairs in game code, 62 with ascending and 1 with
  descending offsets, against 1,339 `ldp` into the base: `g_ldr_pairs`,
  `g_ldr_pairs_desc` and `g_ldp_base` in "Codegen fingerprints"; 60 by the
  earlier count). Three are getters that return a 0x20-byte value by copy
  (`0x71005e65b0`, `0x7100601110`, `0x7100c864f0`). The value's user-written
  copy constructor ends with a member whose own copy constructor is inlined.
  That leaves `DBG_VALUE $x0, "other", DW_OP_plus_uconst 0x18` between
  `ldr x9, [x0, #0x18]` and `ldr x0, [x0, #0x20]`, the same `aarch64-ldst-opt`
  case as Lua's `stackinuse`. With `-g0` or `-gline-tables-only` they become
  `ldp x9, x0, [x0, #0x18]`. The fourth, `0x71014f7a50`, is a `find_if` over
  an iterator class, written as a member function of the range and inlined
  into the caller. There, two debug values sit between `ldr x9, [x8]` and
  `ldr x8, [x8, #8]`: the predicate's `slot` argument in the peeled first
  iteration (the begin pointer, `x9`) and `end()`'s `this` (`x8`). With both
  destination registers used in between, the pass can merge the pair in
  neither direction. Whether a pair stays unpaired depends on which inlined
  debug values survive, so it follows the source's inlining structure: the
  same search written out in the caller (`0x71014f7960`, `0x71014f79b0`)
  pairs into an `ldp`, as in the original. The remaining 59 have not been
  checked one by one.
- **Lua is done.** Every Lua function in the executable matches in both games
  (517). What Game Freak changed is reproduced in `lib/lua` under
  `#if 0 /* not in Pokémon SwSh */`: `loslib` keeps only `os.clock`, `liolib`
  drops `popen` and `tmpfile` (`luaopen_io` creates 9 fields, not 11), and
  `loadlib`'s `readable()` always fails, so `require` only finds
  `package.preload` modules. What isn't in the executable at all (all of
  `lbitlib`, `luaL_openlibs`, `luaL_newstate` with the `lauxlib` allocator and
  panic handler, `lua_setallocf` and a few unused API functions) is listed in
  `data/absent_functions.csv`, which `check.py` skips.

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
builtins and RTTI off, in a release configuration (`PX_PROFILE=0`,
`PX_SUPPORT_PVD=0`), from the public `v3.4.2` source. Every PhysX library in
the binary was built with the same flags.** `lib/physx` now builds all of it,
and all 8,247 functions match in both games (see "`lib/physx`"). The sweep
results below are how that was established.

Compiling the 386 TUs of the PhysX 3.4 libraries that are in the binary (see
"The other libraries") this way, with stand-ins for the non-public NX headers,
**reproduces every PhysX function in the binary except 39 NX platform
functions**. 8,208 of the 8,247 original functions (3,036,832 of 3,039,340
bytes) have the same code as a compiled function, and 7,796 of those are
attributed to their compiled name. 31 of them differ only in the trap
instruction's encoding (see "What the sweep doesn't reproduce"). No function
shows a source or codegen difference, in either game. Counting
`compiler_sweep.py`'s way (a compiled function of at least 16 bytes that equals
exactly one original), that's 3,925 originals (2,294,668 bytes) and 7,600 hits,
and all 4,707 functions mapped by consensus match. The first corpus, 143 TUs
of Foundation, Task, Common and GeomUtils, gives 1,244 hits (1,075 KB). With
the global toolchain's compiler (clang 7.0.1) and the same PhysX flags, it
gives 510.

The tables below were measured with the first, Unix-derived stand-ins (see
"Reproducing"), and their counts are for those. The corrected stand-ins add 33
hits over the 386 TUs (7,567 → 7,600).

The numbers here use `compiler_sweep.py`'s relocation-based masking (see
"Method"). With the old linear masking the first corpus gave 1,224 hits, and
before `-fno-builtin` and `-g` were found, 928.

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
| Compiler | clang 7.0.1 | **clang 6.0.1** | Version table below: 1,244 hits against 510 for clang 7 with the same flags. |
| Builtins | on | **`-fno-builtin`** | 961 hits with builtins on. PhysX calls libm for everything: 664 `bl fabsf` and 433 `bl sqrtf`, and not one `fabs` or `fsqrt` instruction. The rest of `main` has 228 `fabs`, 205 `fsqrt` and no `fabsf` call. `-ffreestanding` (which implies `-fno-builtin`) gives byte-identical objects for all 384 TUs that compile. |
| Exceptions | `-fno-exceptions` | **`-fexceptions`** (C++ exceptions on) | 966 hits without. 1,280 of the binary's 1,281 `zPLR` FDEs are in PhysX (the other one is after Lua; `tools/fingerprint.py`, both games), and noexcept destructors have terminate pads. |
| Aliasing | `-fno-strict-aliasing` | **`-fstrict-aliasing`** | 1,109 hits without. |
| Language | `-std=c++17` | **`-std=gnu++14`** | gnu++11/14/17 give byte-identical objects for all 384 TUs that compile, so the code can't tell them apart. gnu++14 is clang 6's default. `-std=c++14`/`c++17` (non-GNU) break 140 more TUs, because musl then hides `alloca`. `-std=gnu++98` drops to 1,090 hits. |
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

### Versions (PhysX flags, `v3.4.2`, 143 TUs, 1,821 compiled functions, 1,036 mapped)

The first corpus: PxFoundation's 7 portable TUs, PxTask's `TaskManager.cpp`,
Common (`Cm*`) and all of GeomUtils.

| Compiler | `-O3` hits | `-O3` bytes | `-O3` avg similarity | `-O2` | `-fno-exceptions` | `-fno-strict-aliasing` | `-fbuiltin` | without `-g` |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| clang 3.9.1 | 400 | 44,516 | 0.722 | 400 | 330 | 408 | 380 | 390 |
| clang 4.0.1 | 459 | 55,508 | 0.769 | 456 | 371 | 460 | 439 | 444 |
| clang 5.0.1 / 5.0.2 | 748 | 164,164 | 0.891 | 706 | 605 | 719 | 680 | 728 |
| clang 6.0.0 | 1,238 | 1,063,188 | 0.994 | 952 | 961 | 1,106 | 957 | 1,148 |
| **clang 6.0.1** | **1,244** | **1,075,292** | **0.996** | 955 | 966 | 1,109 | 961 | 1,151 |
| clang 7.0.0 / 7.0.1 / 7.1.0 | 510 | 92,100 | 0.827 | 476 | 477 | 494 | 480 | 493 |
| clang 8.0.0 / 8.0.1 | 475 | 77,392 | 0.768 | 445 | 442 | 462 | 450 | 459 |
| clang 9.0.1 | 153 | 15,324 | 0.678 | 146 | 135 | 150 | 142 | 145 |
| clang 10.0.0 | 37 | 2,408 | 0.569 | 35 | 32 | 34 | 34 | 37 |
| clang 11.0.0 | 36 | 2,308 | 0.544 | 34 | 31 | 33 | 33 | 36 |

The columns after the first three give hits with that one change. clang 10
and 11 reject 19 and 20 of the TUs, so their rows are lower bounds, but
they're far behind even on the TUs they do compile. Every function that clang
6.0.0 reproduces, 6.0.1 reproduces too. Six are reproduced only by 6.0.1: both
`Gu::RTree::traverseRay` instances, `EPA::PenetrationDepth`,
`fullContactsGenerationConvexConvex`, `Gu::computeBounds` and
`ConvexMeshContactGeneration::generateContacts`. A vendor build based on a
later 6.0 branch can't be ruled out (there is no upstream 6.0.2).

### Flags (clang 6.0.1 `-O3`, `v3.4.2`, 143 TUs, each row changes one thing, 1,032 mapped)

| Variant | Hits | Bytes | Exact of mapped | What it shows |
|---|---:|---:|---:|---|
| **final** | **1,244** | **1,075,292** | **1,026** | |
| `-fbuiltin` | 961 | 632,536 | 764 | `PxAbs`/`PxSqrt` become `fabs`/`fsqrt` instructions, and `memset`/`memcpy` idioms are formed (see "Source revision" for a case where that changes inlining). |
| without `-g` (`-g0`) | 1,151 | 915,224 | 936 | Debug instructions change scheduling and register allocation (see "Debug info"). `-gline-tables-only` gives the same as `-g0`. |
| `-fno-exceptions` | 966 | 774,652 | 800 | Cleanup landing pads are part of the original code. |
| `-fno-cxx-exceptions` | 1,109 | 991,524 | 925 | Keeps cleanups but drops noexcept enforcement. The original calls a shared terminate helper (`0x7101750e90`) after noexcept destructors (e.g. the `Gu::HeightField` D0 at `0x710014f2f0`), so C++ exceptions are fully on. |
| `-fno-strict-aliasing` | 1,109 | 858,452 | 913 | |
| `-O2` | 955 | 513,580 | 774 | |
| `-Os` | 659 | 166,148 | 540 | |
| `-mimplicit-float` | 767 | 350,400 | 618 | GPR-only copies, the same as game code. |
| `-mcpu=generic` | 135 | 6,040 | 70 | Cortex-A57 scheduling model. |
| `-fomit-frame-pointer` | 459 | 172,772 | 372 | |
| `-fno-pic` | 987 | 768,068 | 833 | |
| `-fvisibility=hidden` | 1,032 | 881,252 | 878 | Globals go through the GOT, unlike in the Linux build. |
| `-DPX_CHECKED=1` | 1,164 | 991,764 | 956 | Release, not checked. |
| `-std=gnu++98` | 1,090 | 996,536 | 913 | |
| `-ffast-math` | 523 | 107,472 | 357 | |
| `-ffreestanding`, `-frtti`, `-fno-unwind-tables`, `-fno-math-errno`, `-DPX_PROFILE=1`, `-DPX_SUPPORT_PVD=1`, `-std=gnu++11`/`gnu++17` | 1,244 | 1,075,292 | 1,026 | Not distinguishable with this corpus (`PX_PROFILE` and `PX_SUPPORT_PVD` are, with the other libraries: see below). RTTI is off because no PhysX class has a typeinfo name and PhysX vtables have no typeinfo slot. With `-g` the CFI is emitted anyway, so `-funwind-tables` no longer shows in the code; the binary's `.eh_frame` (an FDE for every function) is the evidence for it. `-fno-math-errno` changes nothing once builtins are off. |

The `-std` and `PX_SUPPORT_PVD` rows are real tests now. Before
`compiler_sweep.py`'s flag order was fixed, common flags after `--` overrode a
conflicting variant, so runs that passed `-std=gnu++14` or `-DPX_SUPPORT_PVD=0`
there didn't test those variants at all.

### The other libraries

Every PhysX 3.4 library was swept on its own, with the source list and include
paths of its upstream `linux64` makefile (release configuration), the final
flags, and the whole PhysX range (`0x7100010a90`-`0x71003035e0`). One variant per
column (hits). The first row is the 143-TU corpus above:

| Library | TUs | Compiled | **Hits** | Exact / mapped | `-O2` | `-fno-exceptions` | `-fno-strict-aliasing` | `-fbuiltin` | `-g0` | `PX_PROFILE=1` | `PX_SUPPORT_PVD=1` | `gnu++98` | Distinct originals only it hits |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| Foundation, Task, Common, GeomUtils | 143 | 1,821 | **1,244** | 1,026 / 1,032 | 955 | 966 | 1,109 | 961 | 1,151 | 1,244 | 1,244 | 1,090 | ≥ 727 |
| PhysX (core: `Np*`, `Scb*`, cloth/particle API, ImmediateMode, MetaData) | 42 | 3,040 | **1,655** | 990 / 998 | 1,164 | 1,229 | 1,452 | 1,522 | 1,651 | 1,613 | 1,345 | 1,270 | 857 |
| SimulationController (`Sc*`) | 43 | 1,681 | **1,286** | 881 / 886 | 924 | 954 | 1,020 | 1,118 | 1,272 | 1,242 | 1,286 | 969 | 766 |
| LowLevel (`Px*`, `Pxc*`, `Pxv*`) | 21 | 487 | **322** | 219 / 220 | 241 | 238 | 234 | 258 | 322 | 311 | 322 | 245 | 175 |
| LowLevelAABB (`Bp*`) | 7 | 325 | **220** | 157 / 159 | 164 | 145 | 171 | 177 | 217 | 216 | 220 | 146 | 117 |
| LowLevelDynamics (`Dy*`) | 24 | 324 | **236** | 160 / 160 | 178 | 191 | 189 | 189 | 227 | 229 | 236 | 197 | 150 |
| LowLevelCloth (`Sw*`, scalar/NEON) | 13 | 514 | **330** | 268 / 268 | 251 | 281 | 293 | 307 | 323 | 313 | 330 | 289 | 239 |
| LowLevelParticles (`Pt*`) | 16 | 291 | **207** | 168 / 169 | 146 | 136 | 156 | 164 | 195 | 207 | 207 | 146 | 121 |
| SceneQuery (`Sq*`) | 13 | 335 | **226** | 176 / 178 | 159 | 160 | 183 | 189 | 224 | 213 | 226 | 160 | 150 |
| PhysXExtensions (joints, CPU dispatcher, binary and RepX serialization) | 54 | 2,811 | **1,828** | 607 / 635 | 830 | 1,631 | 1,067 | 1,528 | 1,824 | 1,824 | 1,822 | 1,620 | 511 |
| PhysXVehicle | 18 | 1,244 | 203 | 20 / 24 | 34 | 203 | 109 | 173 | 203 | 203 | 203 | 203 | **0** |
| PhysXCharacterKinematic | 10 | 293 | 34 | 10 / 12 | 23 | 29 | 25 | 33 | 34 | 34 | 34 | 24 | **0** |
| PhysXCooking | 19 | 348 | 59 | 17 / 20 | 40 | 48 | 52 | 57 | 59 | 59 | 59 | 45 | **0** |
| PxPvdSDK | 11 | 776 | 86 | 26 / 32 | 63 | 56 | 73 | 79 | 86 | 86 | 86 | 42 | **0** |
| PsFastXml | 1 | 9 | 0 | 0 / 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | **0** |

"Distinct originals only it hits" comes from one combined run over all 445 TUs
(counting hits at a single address only): the original functions that this
library's TUs, and no other library's, reproduce. For the first row it's the
sum over its four libraries. `gnu++11` and `gnu++17` equal the final column in
every row. Every final-config miss in the table is the same mapping artifact
as in "Source revision": a deleting destructor that a `-O2` hit mapped onto the
shared D0 helper at `0x7100021330` or `0x71000415d0` (60 vs 64 or 56 vs 60
bytes).

What this settles:

- **Every library in the binary has the same flags.** In every row that the
  binary contains, the final configuration scores best, and `-O2`,
  `-fno-exceptions`, `-fno-strict-aliasing`, `-fbuiltin` and `gnu++98` each
  lose hits. `-g0` loses hits in every library except LowLevel (no difference
  there).
- **`PX_PROFILE=0`.** `PX_PROFILE=1` turns on `PX_PROFILE_ZONE`, and loses hits
  in every library with profile zones: 1,655 → 1,613 in the core, 1,286 →
  1,242 in SimulationController, 7,567 → 7,425 over the 386 TUs.
- **`PX_SUPPORT_PVD=0`.** It only matters in the core (and slightly in
  Extensions), where `PX_SUPPORT_PVD=1` drops the hits from 1,655 to 1,345
  (7,567 → 7,251 over the 386 TUs).
- **`-std` can't be settled from code.** gnu++11, gnu++14 and gnu++17 give
  byte-identical objects for all 384 TUs that compile (every function
  compared), as do `-fno-builtin` and `-ffreestanding`.
- **Cloth and particles are in the binary**, both the low-level solvers and
  the core and SimulationController front-ends (`NpCloth.cpp`, `SwSolver.cpp`,
  `PtContextCpu.cpp`, `ScClothSim.cpp` in the `__FILE__` strings, 239 and 121
  exclusive hits). So is PhysXExtensions: joints, `DefaultCpuDispatcher`,
  binary deserialization and RepX.
- **Vehicle, character controller, cooking, the PVD SDK and FastXml are not.**
  Their few hits are header templates (`Ps::Array`, `Cm::RenderBuffer`, ...)
  that other libraries reproduce too: not one original function is hit only
  by them. The binary has no `PxVehicle`, `PxController`, `PxCooking`,
  `QuickHull`, `PxPvd` or `FastXml` strings, and none of their source paths.

### What the sweep doesn't reproduce

**Every original function in the PhysX range is accounted for. No function
needs a source difference to explain it.** Earlier versions of this section
said that 4,354 of the 8,247 functions (797 KB, 26%) weren't reproduced. Most
of that was counting. The sweep counts a compiled function only when its code
equals exactly one original, and only from 16 bytes up. The rest came from
three NX header functions whose stand-ins were wrong.

| Class (both games, same class at every address) | Functions | Bytes | Under 16 bytes |
|---|---:|---:|---:|
| Same code, and attributed to the compiled name | 7,765 | 3,027,092 | 1,434 |
| Same code apart from the trap word (`brk #1` compiled, `0xe7ffdefe` in the binary) | 31 | 124 | 31 |
| Same code as a compiled function, but not attributable (identical copies) | 412 | 9,616 | 364 |
| NX platform code (no public source) | 39 | 2,508 | 11 |
| Source or codegen difference | **0** | 0 | 0 |
| **Total** | **8,247** | **3,039,340** | **1,840** |

The three causes:

- **Identical instances.** With the final stand-ins, 6,379 originals of at
  least 16 bytes (3,021,224 bytes) have the same code as a compiled function.
  2,454 of them have the same code as other originals too, so the sweep
  doesn't count them. Instances of one template for different types, or a
  `static` function from a header compiled into every TU that includes it,
  differ only in their call and data targets, which the masking ignores. The
  RepX serializers are the extreme case:
  `Vd::PvdPropertyFilter<Sn::RepXVisitorWriter<T>>::handleAccessor<N,
  PxRepXPropertyAccessor<N, T, float, float>>` is 248 bytes, and 154 originals
  have exactly that code, one per float property. All 533 functions of the
  RepX block at `0x7100243a80`-`0x7100279b5c` are attributed, although only 80
  of them match a single address.
- **Small functions.** 1,840 originals are under 16 bytes. With
  `--min-size 4`, 1,801 of them have the same code as a compiled function.
  Most are a `ret`, a constant return or a tail call, so a code match alone
  means little there. 1,465 are attributed by name (31 of those with the trap
  word). 11 are NX platform code.
- **The NX headers.** The first stand-ins were the Unix intrinsics headers.
  The binary's are different in three inline functions:
  - `shdfnd::lowestSetBitUnsafe` (`PsSwitchIntrinsics.h`) is a De Bruijn
    multiply, `table[((v & -v) * 0x077CB531) >> 27]`, not `__builtin_ctz`. The
    table is the standard 32-entry one, loaded through the GOT, which fits a
    function-local `static` of an inline function. The PhysX range has no
    `rbit`. This explained 26 functions (45 KB), among them
    `Dy::partitionContactConstraints` (10,624 bytes),
    `IG::IslandSim::processLostEdges`, `PxsCCDContext::updateCCD`, three
    `Sc::Scene` task functions, `PxsContext::fillManagerTouchEvents` and the
    particle code that seemed to differ.
  - `shdfnd::highestSetBitUnsafe` is the matching De Bruijn log2 (OR-smear,
    `* 0x07C4ACDD >> 27`, the standard table) instead of `31 - __builtin_clz`.
    The 9 `clz` in the PhysX range are all in LowLevelCloth's `SwCollision`,
    which uses its own builtin. This explained 4 functions (3.8 KB):
    `TempAllocator::allocate`, `Bp::SimpleAABBManager::updateAABBsAndBP`,
    `MBP::populateNewRegion` and one `Pt::ParticleData::removeParticlesV`.
  - `PxIsFinite(float)` (`PxSwitchIntrinsics.h`) calls the SDK:
    `!nn::cstd::IsNan(a) && !nn::cstd::IsInf(a)`. Both are imports
    (`_ZN2nn4cstd5IsNanEf`, `_ZN2nn4cstd5IsInfEf`), and PhysX calls them in 15
    pairs. This explained `Sq::ExtendedBucketPruner::refitMarkedNodes` and
    `PxsCCDPair::sweepAdvanceToToi` (3.9 KB).

  "Reproducing" has the corrected stand-ins. The headers' other functions,
  such as `countLeadingZeros`, change no compiled function, so the code can't
  check them.

**The trap word.** Every trap in `main` is the word `0xe7ffdefe`, the A32
encoding of LLVM's ARM `trap` (650 in both games: 447 in game code, 71 in
Wwise, 31 in PhysX). `main` has no `brk` at all. Upstream clang lowers
`llvm.trap` to `brk #1` on AArch64. In PhysX the 31 are deleting destructors
that compile to a lone trap, and they match once `brk #1` is read as
`0xe7ffdefe`. So the trap encoding is a property of the toolchain, not of
PhysX's compiler alone. The build rewrites it in every object (see "Traps").

**The NX platform code** is 39 functions (2,508 bytes):

- 37 in Foundation's Switch TUs at `0x71002ff460`-`0x710030000c`:
  `FPUGuard`, `MutexImpl`, `ReadWriteLock`, `printString`, `SyncImpl`,
  `ThreadImpl` and the `Tls*` functions. 27 of them call `nn::os` imports
  (`InitializeMutex`, `CreateThread`, `AllocateTlsSlot`, ...) or
  `nn::diag::detail::LogImpl`. The sweep compiles the Unix versions, and those
  differ. The rest of the block matches the Unix code: `SListImpl` (6
  functions), `FPUGuard`'s destructor, and one 8-byte `getSize` that several
  `*Impl` classes share.
- `NpSetMiddlewareInfo` (`0x71000b4db0`, calls `nn::util::ReferSymbol`) and
  `Ext::DefaultCpuDispatcher::getAffinityMasks` (`0x71001f4470`, calls
  `nn::os::GetThreadAvailableCoreMask`), whose Switch sources aren't public
  either.

All 39 are reconstructed in `lib/physx` now (see "`lib/physx`").

**How attribution works** (`tools/sweep_attribute.py`). It reads one
configuration's objects and uses the relocation targets that the masking
ignores:

- A call that reaches a PLT stub in the original must call that import by name
  in the compiled code. Otherwise the code isn't the same. That removes 1,257
  coincidental matches, for example a compiled `b pthread_self` against the
  original `b nn::os::GetCurrentThread`.
- A compiled name whose code equals exactly one original is pinned there.
- Once a name is pinned to an original with the same code, each of its calls
  pins the callee's name to the original's branch target. Each vtable it
  references (`adrp`/lo12 or a GOT load) pins the virtual functions to the
  original vtable's slots. This repeats until nothing changes.
- An original is *attributed* when a name with the same code is pinned to it.
  If only the code matches, it is *not attributable*: 412 identical copies,
  such as the per-TU `static` `Gu::unsupportedMidphase`/
  `unsupportedConvexSweepMidphase` from a header, which are reached only
  through function-pointer tables in data. If a pinned name's code differs, it
  *differs*. Only the platform functions are left in that class.

11 names get pinned to two addresses and are left out, mostly
`RayRTreeCallback<0, false>` members (two originals each), whose callers have
identical code. The pinning is a heuristic. A wrong pin would show up as a
conflict like these, but it can't be ruled out.

These counts are for the sweep's objects. With the build's own objects
(`sweep_attribute.py build/sword --source-prefix lib/physx/`) and these
additions, every original gets exactly one name. See "`lib/physx`" below.

- **Taken addresses.** A pinned function's `adrp`/lo12 or GOT reference to a
  compiled function pins that function to the address. That's how the `Dy`
  solver tables are filled: `DYNAMIC_ARTICULATION_REGISTRATION(x)` is `0` in
  the initialisers, and `SolverCoreRegisterArticulationFns` stores
  `solveExt1DBlock` and the others at run time.
- **Local tables.** The assembler writes a reference to a `static` object as
  its section symbol plus an offset. So each local pointer table is also found
  by its section, which pins the `Gu::unsupportedMidphase` copies through
  `gMidphaseRaycastTable` and the others.
- **One function per original.** A call whose original target is pinned to
  another function disagrees. A name whose code differs from its original
  gives way to one whose code is the same. Names pinned by unique code before
  their callees were pinned are checked again at the end. This settled
  `0x71000b4000`: it calls `PxvRegisterHeightFields`, so it is
  `PxRegisterHeightFields`, not the identical `PxRegisterLegacyHeightFields`,
  which calls the absent `PxvRegisterLegacyHeightFields`.
- **Link order.** With `-ffunction-sections`, the linker keeps each object's
  functions in section order, one object after another. An original without a
  pin, between two pinned functions of one TU, gets the name of the one
  candidate in that TU that fits there. Where two names are left on one
  address, the one that something references wins: `--gc-sections` drops
  functions that nothing references. Complete and base structors (C1/C2,
  D1/D2) count as one name, recorded as the base one, as in `functions.csv`.

### `lib/physx`

The sweep's results carry over to the build: `lib/physx` holds the 385 TUs in
the binary, compiled by the `pkmn_library_settings(lib/physx ...)` entry with
the flags above. **All 8,247 functions of the PhysX range match `check.py` in
both games and are `O` in `functions.csv`,** the 39 NX platform functions
included.

**Sources.** The text is the BSD-3 HEAD revision (@25354359). Where HEAD's code
differs from `v3.4.2`'s, the file has `v3.4.2`'s code, hunk by hunk: 83 files.
HEAD's text is kept wherever only comments differ, and every line keeps its
`v3.4.2` line number, because `__LINE__` is in the code (`PX_ALLOC`,
`getFoundation().error`). Before that restore, the HEAD build lost about 1,050
attributions to header and layout changes and shifted line numbers. Line 1 of
each restored file lists its `v3.4.2` lines. `v3.4.2` isn't BSD-licensed, so
the 83 files aren't in the repository. `tools/get_physx.py` rebuilds them from
NVIDIA's public repository: HEAD's file, `v3.4.2`'s file and the same
hunk-by-hunk rule. It checks each result against the SHA-256 in
`data/physx_v342.csv`, and CMake won't configure until they all match
(`lib/physx/README.md`). The TU
list, the include directories (in makefile order) and `PX_BUILD_NUMBER` come
from `v3.4.2`'s `linux64` makefiles. The 22 libc++ 7.0.1 headers that PhysX
reads are vendored, unchanged, in `include/libcxx`.

**`__FILE__`.** The vendor built from
`C:/gitlab-runner/builds/ba119cc0/0/research_and_development/physx/PhysX/`.
TUs appear under that absolute path. Headers appear relative to the
makefile's directory, `PhysX_3.4/Source/compiler/nx/` for the PhysX libraries
and `PxShared/src/compiler/nx/` for PxShared's (`./../../../../PxShared/src/foundation/include\PsArray.h`,
`./../../foundation/include/PsArray.h`). clang joins an `-I` directory and a
name with `\` on Windows, so one header can be spelled both ways.
`data/source_paths.csv` records the two build directories, and `check.py`
compares a literal that names a file under `lib/physx` by the file it names,
not byte for byte (`tools/source_paths.py`). The fingerprint that compares
weak copies across TUs folds the separators of this checkout's paths. It also
compares merged constants (`.rodata.cst16`) by value, so identical template
copies no longer look different.

**Attribution in the build.** `sweep_attribute.py` reads a CMake build
directory too. With the additions in "How attribution works", all 8,247
originals get one name, the same in both games: 8,174 pinned, 73 placed by link
order. `funcs.py name --from-file` applied them. The 1,848 compiled functions
that aren't in the binary (inlined everywhere, or dropped by `--gc-sections`,
such as `PxvRegisterLegacyHeightFields`, `BitArray()` and
`MutexImpl::trylock`) are in `data/absent_functions.csv`.

**Data.** `data/data_symbols.csv` has 566 PhysX data objects: 383 vtables,
dispatch tables, globals, guard variables and function-local statics. Each was
placed by decoding the original's `adrp`/lo12 or GOT reference in every
attributed function that refers to it. Only objects on which every reference
agrees, in both games, are kept, and none of them overlap. `check.py` needs
them where a function loads a vtable or global through the GOT. (Doing this
found a bug in `sweep_attribute.lo12`: it multiplied a load's offset by
`ldst_scale`, which is a shift, so byte loads decoded as offset 0. The fix
changes no function name.) Four of those loads also needed a fix in
`check.py`. Its linear decode of the original drops an `adrp`'s page at any
instruction whose destination field has that register's number, so
`fmul v9.4s` ends `x9`'s page 53 instructions before the GOT load that uses
it. `check.py` now pairs such a load with its `adrp` through the compiled
relocations (`adrp_pairs`), which hold wherever the instructions are the same.

**`__clang_call_terminate`** is called from PhysX's noexcept landing pads, but
the executable's copy (Sword `0x7101750e90`, Shield `0x7101750f30`) is in the
SDK middleware block. It has a frame record (`stp x29, x30, [sp, #-0x10]!;
mov x29, sp`). Upstream clang 6.0.1, 7.0.1, 8.0.1, 9.0.1, 10.0.0 and 11.0.0 all
emit this helper without one (`str x30, [sp, #-0x10]!`), even with
`-fno-omit-frame-pointer`. clang 19 emits the binary's form. So the linker kept
a copy from a middleware library built by a much newer clang, and discarded
`lib/physx`'s. It's listed in `data/foreign_copies.csv`, which `check.py`
skips.

`check.py --update` (both games), with Lua and the earlier functions:

```
8804 matching, 0 not matching
(1848 compiled functions skipped as not in the executable: data/absent_functions.csv)
(1 weak/COMDAT functions skipped: the executable keeps another library's copy, data/foreign_copies.csv)
(311 compiled aliases of checked functions skipped, e.g. D1 = D2 destructors)
```

**The NX platform code** is reconstructed from the binary in
`PxShared/src/foundation/src/switch/` and two more `switch/` TUs. The calls go
through `include/nn/os.h`, declared from the imports' mangled names. Every SDK
function is `noexcept`: the callers have no landing pads for them. What the
code shows:

- **Mutex** (`PsSwitchMutex.cpp`, named by `__FILE__`). It's the Unix one over
  `nn::os::MutexType` (recursive, `InitializeMutex(m, true, 0)`), plus the owner
  `Thread::Id`. `unlock()` always checks the owner and reports
  `eINVALID_OPERATION` "Mutex must be unlocked only by thread that has already
  acquired lock" on line 98. `trylock` isn't in the binary.
- **ReadWriteLock.** `PX_ALLOC` is on line 124. The impl's constructor zeroes
  the reader count (the original stores it through the new pointer, not
  through `mImpl`). The writer waits with `SleepThread(TimeSpan{1})`, not a
  bare spin.
- **Sync.** A condition variable, a non-recursive mutex, `setCounter` and
  `is_set` (0x30 bytes). The timed `wait` counts system ticks:
  `timeout = frequency * ms / 1000`, `TimedWaitConditionVariable(...,
  ConvertToTimeSpan(timeout))`, while `GetSystemTick() <= end + 1 - (end >> 4)`
  with `end = start + timeout`. The source of that limit is a guess. It's
  written as the binary computes it.
- **Thread.** `nn::os::ThreadType` comes first (0x1a8 bytes), then the name,
  the stack (allocated by a 4 KiB `AlignedAllocator`, default 512 KiB), the
  core mask (`-1`, meaning all available cores, until set), `quitNow`, the
  state and the entry function. `start()` creates the thread at the stored
  priority (default 16), then sets the core mask and name and starts it. TLS is
  `AllocateTlsSlot` and friends, with `-1` returned on failure.
- **printString** (`PsSwitchPrintString.cpp`, named by `__FILE__`). It logs the
  string, then `"\n"`, through `nn::diag::detail::LogImpl`, on lines 44 and
  45. The metadata is assigned member by member, like the SDK's log macro.
- **FPUGuard.** The Unix code plus `fesetround(0x1000000)` (FPCR's
  flush-to-zero bit). **Atomics** and **SList** are the Unix code.
- `NpSetMiddlewareInfo` refers to the string `"SDK MW+NVIDIA+PhysX-3_4_2-release"`
  through `nn::util::ReferSymbol`. `getAffinityMasks` fills every entry with
  `GetThreadAvailableCoreMask()`. Their file names are guesses.

### Build configuration

PhysX ships debug, checked, profile and release configurations. The binary is a
**release** build:

- No `PX_CHECK_*` messages (such as `PxScene::addArticulation: empty
  articulations ...`), so `PX_CHECKED=0`.
- No `PX_PROFILE_ZONE` event names (`API.addActor`, `Sim.solveQueueTasks`), so
  `PX_PROFILE=0` (and `PX_DEBUG=0`). The code agrees: `PX_PROFILE=1` loses hits
  in the core, SimulationController and most other libraries (see "The other
  libraries").
- No `PX_ASSERT` expression strings, so asserts are compiled out (`NDEBUG`).
- No `PxPvd*` strings, so `PX_SUPPORT_PVD=0`, as in the upstream release config.
  The core's code agrees (1,655 hits, 1,345 with `PX_SUPPORT_PVD=1`).
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
matches, apart from the mapping artifacts listed below. The same holds for the
other libraries (see "The other libraries").**

Every public revision since 3.4.1 that touches the corpus was swept with the
final configuration (clang 6.0.1, `-O3`, PhysX flags) on the 143-TU corpus:

| Revision | Perforce CL | Hits | Bytes |
|---|---|---:|---:|
| `d1c812f` (`v3.4.1`) | 22845541 | 1,162 | 987,656 |
| `3cc1861` (3.4.1 update) | 23131702 | 1,215 | 1,032,996 |
| `57b71f8` (3.4.1 update) | 23173160 | 1,217 | 1,038,804 |
| `983c93a` | 23307153 | 1,217 | 1,038,804 |
| `b6db9a5` | 23472123 | 1,223 | 1,043,072 |
| `52dae55` | 23576764 | 1,230 | 1,058,392 |
| `238605d` | 23879214 | 1,239 | 1,065,824 |
| **`b99b378` (`v3.4.2`)** | **24214033** | **1,244** | **1,075,292** |
| `3f9977d` | 24698370 | 1,223 | 1,048,260 |
| `ad993f2` | 24990349 | 1,221 | 1,047,800 |
| `78cab22` | 25256367 | 1,219 | 1,047,768 |
| `326e240` (= HEAD `5e42a5f` for these files) | 25354359 | 1,217 | 1,044,880 |

`5f95687` (@23933511) doesn't touch the corpus. Of the two 3.4.1 updates,
`57b71f8` changes only `GuCCDSweepConvexMesh.cpp` against `3cc1861` (`matRot`
becomes `PxMat33(PxIdentity)`, two more hits). `983c93a` changes only two public
headers against `57b71f8` and compiles the same. Without `-fno-builtin` and
`-g`, or with the old masking, the ranking is the same (`v3.4.2` 928 and 1,224,
HEAD 920 and 1,208).

Compared by original address, every revision's hits are a subset of the
`v3.4.2` hits:

- Over `238605d`: five PCM convex-vs-mesh functions (`PCMContactConvexMesh`,
  `PCMContactConvexHeightfield`, `PCMConvexVsMeshContactGeneration::
  generateTriangleFullContactManifold` and `generatePolyDataContactManifold`,
  and the `processHit` of its mesh callback).
- Over `3f9977d` (15): `epaPenetration`, `EPA::PenetrationDepth`,
  `Facet::silhouette`, both `RayRTreeCallback<0, true>::processResults`,
  `raycast_heightField`, `HFTraceSegmentCallback::faceHit`,
  `HeightFieldTraceUtil::traceSegment<TriggerTraceSegmentCallback>`, and the
  two `Gu::HeightField` constructors, its destructors (D1, D0 and their
  thunks) and `HeightField::createObject`.
- Over HEAD (20): those 15, plus `barycentricCoordinates`, `BV4Tree(PxEMPTY)`,
  `HeightField::getTriangleAdjacencyIndices`,
  `SweepConvexMeshHitCallback::processHit` and `ConvexTraceSegmentReport::onEvent`.

(Distinct original addresses with a unique hit, re-measured with the
relocation-based masking. No revision hits an address that `v3.4.2` doesn't.)

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
- `triangleConvexTest` (`0x7100129f50`, 5,612 bytes) matches too. It has two
  `ldr s15, [xN, #lo12]` whose `adrp` is on another path. The sweep used to
  track `adrp` linearly, compared those two lo12 fields raw and didn't count
  it. With the relocation-based masking it's a hit, like 19 other functions
  that missed for the same reason.
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
  in `.data.rel.ro` run contiguously up to the TaskManager ones. With all
  libraries swept, the 4,743 mapped functions span exactly
  `0x7100010a90` (`PxvRegisterHeightFields`) to `0x71003032f0`, at the same
  addresses in both games. The first `zPLR` FDE is at `0x7100010f10`.
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
- **YEBIS ends at `0x7100596d20`, where Game Freak code starts.** It's the
  same address in both games. An earlier guess, `0x71005a0000`, was inside
  the function at `0x710059fe00` and put 181 game functions in YEBIS. The
  evidence:
  - **Static initialisers.** clang emits a TU's initialiser after its other
    functions, and `.init_array` lists them in link order. YEBIS's run ends
    with entries 285-287 (of 1,508): `0x71005966e0`, `0x7100596770` and
    `0x7100596ca0`. All three have the same shape: they construct one SiSDK
    object and register its destructor. The last TU also holds `0x71005967f0`,
    the last function that references a YEBIS source path
    (`SiCore_String.inl`). Entry 288 is `0x71005cf950`, in game code.
  - **RTTI.** The last vtables with `SiSDK3` typeinfo (`SiOSMutex`,
    `SiOSCriticalSection`) end at `0x71005966d0`. No vtable with typeinfo
    points into `0x7100596d20`-`0x7100620000`.
  - **Call graph.** Nothing in `0x710040f550`-`0x7100596d20` calls code after
    it, apart from 10 calls into two libc++ red-black-tree helpers
    (`0x71006a54a0` and `0x71006f9720`, shaped like `__tree_balance_after_insert`
    and `__tree_remove`). Those are inline template code that the linker kept
    in a game TU. From `0x7100596d20` on, nothing in YEBIS calls these
    functions, and they call Game Freak code, for example `0x710065d700`
    next to the `GlobalHeap`/`DebugHeap` strings and the functions that cite
    `gflib3/src/mem` source paths. The first ones
    read FlatBuffers tables. Moving the end to `0x71005a00c0` adds 152 calls
    from "YEBIS" into game code. Both games give the same counts.

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

The NX platform headers aren't in the public repository. This script writes
stand-ins for them into `toolchain/candidates/src/physx-nx-shim`. Run it from
the repository root as `python physx_shim.py toolchain/candidates/src/PhysX-3.4`.
The two intrinsics headers are the Unix ones, except that `PxIsFinite(float)`,
`lowestSetBitUnsafe` and `highestSetBitUnsafe` are written the way the binary
has them (see "What the sweep doesn't reproduce"). The version, flag and library tables were
measured with the plain Unix copies (the first two `write` calls without their
edits). `NpMiddlewareInfo.h` is only needed by the core's `NpPhysics.cpp`. The
last four files make Foundation's `PsUnixThread.cpp` and `PsUnixTime.cpp`
compile against musl. `unix/PsUnixTime.cpp` is a stand-in TU that compiles the
real one with the Unix member layout of `shdfnd::Time`. The binary has the
Switch versions of both instead.

```python
# physx_shim.py: python physx_shim.py <PhysX-3.4 dir>   (writes toolchain/candidates/src/physx-nx-shim)
import re, sys
from pathlib import Path

X = Path(sys.argv[1]).resolve()
S = Path("toolchain/candidates/src/physx-nx-shim")
PX, PS = X / "PxShared/include/foundation", X / "PxShared/src/foundation"


def write(rel, text):
    (S / rel).parent.mkdir(parents=True, exist_ok=True)
    (S / rel).write_text(text, newline="\n")


def sub(text, old, new):
    assert text.count(old) == 1, old
    return text.replace(old, new)


def unix(path):  # the Unix header without its platform #error
    return "".join(l for l in path.read_text().splitlines(True) if "#error" not in l)


# isFinite(float) calls the SDK's nn::cstd::IsNan and IsInf
px = unix(PX / "unix/PxUnixIntrinsics.h")
px = re.sub(r"(bool isFinite\(float a\)\n\{\n).*?\n\}", r"\1\treturn !nn::cstd::IsNan(a) && !nn::cstd::IsInf(a);\n}",
            px, count=1, flags=re.S)
px = sub(px, "namespace physx\n{\nnamespace intrinsics",
         "namespace nn\n{\nnamespace cstd\n{\nbool IsNan(float);\nbool IsInf(float);\n}\n}\n\n"
         "namespace physx\n{\nnamespace intrinsics")
write("foundation/switch/PxSwitchIntrinsics.h", px)

# highestSetBitUnsafe and lowestSetBitUnsafe are De Bruijn multiplies with a table
ps = unix(PS / "include/unix/PsUnixIntrinsics.h")
ps = sub(ps, "\treturn 31 - __builtin_clz(v);",
         "\tstatic const uint32_t table[32] = { 0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,\n"
         "\t                                    8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31 };\n"
         "\tv |= v >> 1;\n\tv |= v >> 2;\n\tv |= v >> 4;\n\tv |= v >> 8;\n\tv |= v >> 16;\n"
         "\treturn table[(v * 0x07C4ACDDu) >> 27];")
ps = sub(ps, "\treturn __builtin_ctz(v);",
         "\tstatic const uint32_t table[32] = { 0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,\n"
         "\t                                    31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9 };\n"
         "\treturn int32_t(table[((v & (0 - v)) * 0x077CB531u) >> 27]);")
write("switch/PsSwitchIntrinsics.h", ps)
write("switch/PsSwitchAbort.h", "#include <stdlib.h>\nnamespace { inline void abort(const char*) { ::abort(); } }\n")
write("switch/NpMiddlewareInfo.h", "#pragma once\nvoid NpSetMiddlewareInfo();\n")

# Foundation's two Unix TUs that need more than musl has (the binary has the Switch ones instead)
write("bits/local_lim.h", "#pragma once\n#include <limits.h>\n")
write("asm/unistd.h", "#pragma once\n#include <sys/syscall.h>\n#define __NR_gettid SYS_gettid\n"
      "#define __NR_sched_getaffinity SYS_sched_getaffinity\n#define __NR_sched_setaffinity SYS_sched_setaffinity\n")
write("unix/PsTime.h", sub((PS / "include/PsTime.h").read_text(),
                           "#if PX_LINUX || PX_ANDROID || PX_APPLE_FAMILY || PX_PS4\n\tSecond mLastTime;",
                           "#if 1\n\tSecond mLastTime;"))
write("unix/PsUnixTime.cpp", f'#include "PsTime.h"\n#include "{(PS / "src/unix/PsUnixTime.cpp").as_posix()}"\n')
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
  system temp directory (about 3 MB per configuration of the 143-TU corpus,
  25 MB for all libraries). Point `TMP`/`TMPDIR` at a directory of your own and
  delete them when you're done.

#### The other libraries

Each library's sources, include paths and defines come from its upstream
makefile, `PhysX_3.4/Source/compiler/linux64/Makefile.<Library>.mk`. This
script turns those into `compiler_sweep.py` arguments, one per line, for an
`@FILE` response file (the full list doesn't fit on a Windows command line).
It skips GPU, Windows, Linux-device and SSE2/AVX sources, and the makefile's
DLL-export and PVD defines:

```python
# physx_args.py: python physx_args.py <PhysX-3.4 dir> PhysX[+SceneQuery+...] > lib.rsp
import os, re, sys
from pathlib import Path

X, libs = Path(sys.argv[1]), sys.argv[2].split("+")
mk = X / "PhysX_3.4/Source/compiler/linux64"
skip = re.compile(r"/(gpu|windows|linux|sse2|avx|PhysXGpu)/|PhysXIndicator|PxGpu|NpPhysicsGpu")
C = Path("toolchain/candidates")
inc = [C / "src/physx-nx-shim", X / "PxShared/src/foundation/include/unix", X / "PxShared/src/task/include"]
srcs, defs = [], []
for lib in libs:
    text = (mk / f"Makefile.{lib}.mk").read_text()
    for kind, v in re.findall(rf"^{lib}_(release_hpaths|release_defines|cppfiles)\s*\+=\s*(\S+)", text, re.M):
        p = Path(os.path.normpath(mk / v))
        if kind == "release_hpaths" and p.exists() and p not in inc:
            inc.append(p)
        elif kind == "cppfiles" and p.exists() and not skip.search(v):
            alt = C / "src/physx-nx-shim/unix" / p.name  # stand-in TU (physx_shim.py)
            srcs.append(alt if alt.exists() else p)
        elif kind == "release_defines" and not re.search(r"EXPORTS|_DLL|PVD|NDEBUG|STATIC_LIB", v):
            defs.append(v)
args = [a for s in srcs for a in ("--src", str(s))]
args += ["--", "-O3", "-fexceptions", "-fstrict-aliasing", "-fno-rtti", "-fno-builtin", "-std=gnu++14",
         "-nostdinc++", "-isystem", str(C / "src/libcxx-7.0.1/include"), "-isystem", str(C / "sysroot/include"),
         "-D__NX__", "-DNDEBUG", "-DPX_PHYSX_STATIC_LIB", "-DPX_FOUNDATION_DLL=0", "-DPX_SUPPORT_PVD=0",
         "-D_LIBCPP_HAS_MUSL_LIBC", "-D_LIBCPP_HAS_THREAD_API_PTHREAD", *[f"-D{d}" for d in sorted(set(defs))]]
args += [a for p in inc for a in ("-I", str(p))]
print("\n".join(args))
```

Then, for one library and the variants of the table (the response file goes
last, because it ends with `--` and the common flags):

```sh
X=toolchain/candidates/src/PhysX-3.4
python physx_args.py $X SimulationController > lib.rsp
python tools/compiler_sweep.py --compiler toolchain/candidates/clang-6.0.1 \
    --range 0x7100010a90-0x71003035e0 \
    --variant "O3=" --variant "O2=-O2" --variant "noeh=-fno-exceptions" \
    --variant "nostrict=-fno-strict-aliasing" --variant "builtin=-fbuiltin" --variant "g0=-g0" \
    --variant "profile=-DPX_PROFILE=1" --variant "pvd=-UPX_SUPPORT_PVD -DPX_SUPPORT_PVD=1" \
    --variant "std98=-std=gnu++98" --variant "std11=-std=gnu++11" --variant "std17=-std=gnu++17" \
    @lib.rsp
```

The libraries are `PhysX`, `SimulationController`, `LowLevel`, `LowLevelAABB`,
`LowLevelDynamics`, `LowLevelCloth`, `LowLevelParticles`, `SceneQuery`,
`PhysXExtensions`, `PhysXVehicle`, `PhysXCharacterKinematic`, `PhysXCooking`,
`PxPvdSDK` and `PsFastXml`, plus `PxFoundation`, `PxTask` and `PhysXCommon`
for the whole set. The 12 libraries in the binary together
(`PxFoundation+PxTask+PhysXCommon+PhysX+SimulationController+LowLevel+LowLevelAABB+LowLevelDynamics+LowLevelCloth+LowLevelParticles+SceneQuery+PhysXExtensions`,
386 TUs) give the headline numbers. All 386 compile with the stand-ins above.
(Without the last four, `PsUnixThread.cpp` and `PsUnixTime.cpp` don't, and the
other numbers stay the same.) A configuration takes 1 to 3 minutes for a big
library.

The classification in "What the sweep doesn't reproduce" comes from the final
configuration's objects. `--obj-dir` keeps them, and `--min-size 4` counts the
small functions too. A sweep takes about a minute, and `sweep_attribute.py`
takes about two per game:

```sh
L=PxFoundation+PxTask+PhysXCommon+PhysX+SimulationController+LowLevel+LowLevelAABB+LowLevelDynamics+LowLevelCloth+LowLevelParticles+SceneQuery+PhysXExtensions
R=0x7100010a90-0x71003035e0
python physx_args.py toolchain/candidates/src/PhysX-3.4 $L > all.rsp
python tools/compiler_sweep.py --compiler toolchain/candidates/clang-6.0.1 --range $R \
    --variant "O3=" --obj-dir build/physx-sweep @all.rsp                  # 7,600 hits, 4,707 mapped
python tools/compiler_sweep.py --compiler toolchain/candidates/clang-6.0.1 --range $R \
    --variant "O3=" --min-size 4 --hits-out hits4.csv @all.rsp             # small functions
python tools/sweep_attribute.py build/physx-sweep/clang-6.0.1_O3 --range $R --game sword --out attr_sword.csv
python tools/sweep_attribute.py build/physx-sweep/clang-6.0.1_O3 --range $R --game shield --out attr_shield.csv
```

`sweep_attribute.py` prints the class table, and `--out` lists every original
with its class and names. `build/` is gitignored. The `--min-size 4` run
writes its objects to a `sweep_*` temp directory: delete it afterwards.

#### Reproducing `lib/physx`

The scripts are in `docs/physx/`. Run them from the repository root. `V342`
and `HEAD` are `git archive` extractions of `v3.4.2` and of the HEAD revision,
as above.

```sh
# 1. HEAD's text for the TUs in the binary and the headers they read, plus the
#    libc++ headers. NX stand-ins come from lib/physx (its PxSwitchIntrinsics.h,
#    PsSwitchIntrinsics.h, PsSwitchAbort.h, NpMiddlewareInfo.h, at their paths).
python docs/physx/vendor_physx.py $V342 $HEAD <nx-headers> <stage> <out>
# 2. v3.4.2's code wherever HEAD's differs (comment-only hunks keep HEAD's text),
#    with the note on line 1: the files of data/physx_v342.csv (not committed)
python tools/get_physx.py [--clone toolchain/candidates/src/PhysX-3.4]
# 3. Names: attribute each game, then apply the Name column
#    (Name,Sword,Shield; tools/funcs.py name --from-file)
python tools/sweep_attribute.py build/sword --source-prefix lib/physx/ \
    --range 0x7100010a90-0x71003035e0 --game sword --out attr_sword.csv   # likewise shield
# 4. The data objects for data/data_symbols.csv
python docs/physx/physx_data_symbols.py physx_data.csv
```

On the current tree, steps 2 and 3 reproduce `lib/physx` and its names byte for
byte: the same 83 files (their SHA-256 is checked), and the same 8,247 names
in both games. The
Switch TUs, the stand-in headers, `lib/physx/README.md` and `LICENSE.md` are
kept in the tree, not generated. The compiled functions that are missing from
the executable go in `data/absent_functions.csv`: every `lib/physx` function
that isn't named, an alias of a named one, or in `foreign_copies.csv`.

### What's left open

Settled since the first version of this list:

- **The NX platform code.** Reconstructed in `lib/physx`, and all 39
  functions match in both games (see "`lib/physx`").
- **Attribution limits.** Every original has one name now, through taken
  addresses, local tables, the one-function-per-original check and link order
  (see "How attribution works"). The 412 unattributable copies and the
  ambiguous pairs are gone, and `check.py` confirms each name's code and
  references.

Left, and not decidable from the binary. None of these change what the build
must do to match:

- **The rest of the NX headers.** The code fixes three inline functions of
  the intrinsics headers (`lowestSetBitUnsafe`, `highestSetBitUnsafe`,
  `PxIsFinite`) and every function in the Switch TUs. The headers' other
  inline functions (`countLeadingZeros`, `PxSqrt`, ...) aren't used in a way
  that changes any compiled function, so nothing can test them. The stand-ins
  keep the Unix versions. The Switch TUs' file names are evidenced only for
  `PsSwitchMutex.cpp` and `PsSwitchPrintString.cpp` (`__FILE__`). The others
  follow upstream's naming, and their line numbers aren't in the code.
- **Which stage writes the trap word.** For matching it's settled: the NX
  toolchain encodes `llvm.trap` as `0xe7ffdefe`, and the build rewrites
  `brk #1` (see "Traps"). The word is the same in game code, Wwise and PhysX,
  three compilers. That points at something they share (the SDK's clang
  driver or its linker), not at any one compiler. The binary doesn't say which.
- **`-std`.** gnu++11, gnu++14 and gnu++17 give byte-identical objects for
  every library, and gnu++98 and the non-GNU modes are ruled out. The build
  uses clang 6's default, `gnu++14`. (`PX_PROFILE` and `PX_SUPPORT_PVD` are
  settled: both 0.)
- **`-fno-builtin` or `-ffreestanding`.** They produce identical objects for
  every library. `-ffreestanding` only adds `__STDC_HOSTED__=0`, which this
  code doesn't test. The build uses `-fno-builtin`.
- **clang 6.0.1 or a later 6.0 vendor build.** Six functions separate 6.0.1
  from 6.0.0, and with 6.0.1 all 8,247 match. No public 6.0 release is later
  than 6.0.1, so nothing later can be tested.
- **Wwise** is clang 6.0.x too, but with the game's aliasing and exception
  flags (see below).

## sol2

**Result: sol2 v2.20.4 (the tag's `single/sol/sol.hpp`), instantiated by one
Game Freak TU built with the game's clang 7.0.1 and global flags plus
`-std=c++14` and `-DNDEBUG`.** That TU is the Lua glue of the symbol-encounter
AI: it loads `bin/field/param/symbol_encount/ai.blua` and binds
`field::content`'s Haxe types into a global table `fromcpp`. sol2 is vendored
unchanged as `lib/sol/sol.hpp` (MIT, with its `LICENSE.txt`). The TU is
`src/field/content/Unk_df22f0.cpp`, and its build settings are the
`pkmn_library_settings(src/field/content ...)` entry. **`check.py` reports
1,041 functions of this block (280,484 bytes) `OK` in both games**: all of
its sol2 and libc++ instances and the three empty Log functions. With them
the other sol2 TU's `move_assign<false>`, which five of them call, matches
too. The registration and
one helper are `M`.

### Where it is

One TU, Sword `0x7100dedfa0`-`0x7100e366b0`. Shield is the same code
`0x30` higher: every `functions.csv` row from `0x7100deb970` (the
PokemonObject constructor) to `0x7100e36ec0` has the same size in both games
and sits at Sword + `0x30`, so the TU is `0x7100dedfd0`-`0x7100e366e0` there.

In Sword:

| Range | What |
|---|---|
| `0x7100dedfa0`-`0x7100dee930` | Game code: a class whose vtable is at GOT slot `0x71024a6390`, the loader `0x7100dee1b0` (it loads `ai.blua` and hands over five function pointers, the first being the registration), the first of three callables that call a script function (`0x7100dee870`) |
| `0x7100dee930`-`0x7100df20e0` | sol2 instances, starting with the two that the callable calls |
| `0x7100df20e0`-`0x7100df22f0` | Game code: the other two callables, the three empty `fromcpp.Log` functions |
| `0x7100df22f0`-`0x7100df5a20` | The registration (8,308 bytes), `0x7100df4370` (creates `fromcpp`), and one `new_usertype` helper per type (`0x7100df4440`, a template) |
| `0x7100df5a20`-`0x7100e366b0` | sol2 instances, up to the last `new_enum` `tuple_set` (`0x7100e36570`, 312 bytes) |

The compiled TU's sections come in the same order, except for the callable's
two instances (they come last; the original callables are callables of some
type-erased wrapper, see "What's left open") and the missing
`0x7100df4370`.

- **The bound types live in the neighbouring code**: HaxeSymbolPokemonObject's
  constructor `0x7100deb970` and methods `0x7100debaa0`-`0x7100ded8a0`,
  HaxeVector3's `0x7100ded9e0`-`0x7100dedc60`, then after the block
  HaxeVector2's (`0x7100e366b0`, `HaxeVector2::Create`, a `ret`) and
  HaxeFieldFunc's, up to `0x7100e36ec0`. They are named (see "Names") and
  still `U`. They're out-of-line functions of types the glue only uses, so
  the TU most likely ends at `0x7100e366b0`.
- The start is less certain. `0x7100dedc60` and `0x7100deddd0` (the latter
  references the skybox and `unit_obj_door` gfpak paths, and calls the
  former) look unrelated to Lua, so `0x7100dedfa0` is the first function that
  clearly belongs to the glue.
- **Almost no sol2 code outside it.** No other function in `main` references
  a sol2 string (`sol:`, `usertype`, `metatable`, ...; the other hits are
  Lua's own). One other TU uses sol2: around `0x710065b6a0`-`0x710065c034`,
  next to code that opens the Lua standard libraries (`0x710065ba20`
  references `"debug"`, `"io"`, `"base"`, ...), probably the owner of the
  `sol::state`. The linker kept its copy of
  `sol::basic_reference<false>::move_assign<false>` (`0x710065bf00`, 308
  bytes), which five instances of this block call. It's named, and matches
  with the same source.

`data/areas.csv` gets no row for it: it is template code inside one Game
Freak TU, not a separately built library, and the `game` row already says
that it holds sol2 instances. The start boundary also isn't certain enough.

### Version

Strings narrow it to v2.18.5 or later: `"value is not a valid userdata"`,
`"value at this index does not properly reflect the desired type"`,
`"cannot properly align memory for '%s'"` and `"aligned allocation of userdata
block (pointer section) for '%s' failed"` first appear in v2.18.5's single
header. `ctti_get_type_name`'s `__PRETTY_FUNCTION__` strings (20 in the
block) name every bound type and give the exact member pointer types, so the
binding could be written out exactly (see "The TU"). The `ctti` function itself
compiles the same for every version from v2.18.7, so the instances
decide. Every tag's single header, compiled as the final TU (clang 7.0.1, the
final flags; hits and bytes as in "Method", over `0x7100dedf00`-`0x7100e366b0`,
1,069 original functions):

| sol2 | `-std` | Compiled | **Hits** | Hit bytes |
|---|---|---|---|---|
| v2.18.6, v2.18.7, v2.19.0 | c++17 | 1,028 | 673 | 111,644 |
| v2.19.4 | c++17 | 1,023 | 823 | 196,808 |
| v2.19.4, v2.19.5 | c++14 | 1,024 | 971 | 257,788 |
| v2.20.0, v2.20.1, v2.20.2 | c++14 | 1,028 | 988 | 264,616 |
| v2.20.3 (`-include array`) | c++14 | 1,032 | 996 | 265,864 |
| **v2.20.4** | **c++14** | 1,044 | **1,004** | **280,264** |
| v2.20.4 | c++17 | 1,043 | 840 | 212,372 |
| v2.20.5, v2.20.6 | c++14 | 1,044 | 978 | 269,712 |

The sweep counts functions of 16 bytes or more; `check.py`, which also
checks the smaller ones, gets more (see the top of this section).

- **v2.20.4 is the unique best**, with every mapped function exact. Only
  v2.20.4 has `usertype_metatable::core_indexing_call` (`0x7100e01000` and
  `0x7100e01230` in Sword); v2.20.5 changed `runtime_object_call` and
  `runtime_new_index` to four arguments, and v2.20.2 and earlier also have a
  different `unique_destruct`.
- The v2.20.4 tag's single header says "generated with sol v2.20.3 (revision
  daa9993)", dated 2018-08-04. It isn't v2.20.3's (2018-06-16, revision
  968989b): it adds `#include <array>` (v2.20.3's single header doesn't compile
  without it) and differs in code. Either way, it is what the tag ships and
  what matches.
- v2.18.6, v2.18.7 and v2.19.0 don't compile as C++14
  (`static_trampoline_noexcept` is only declared for C++17), so they appear
  with `-std=c++17` only. v2.18.5 doesn't compile without exceptions.

### Build settings

Each row changes one thing against the final configuration (v2.20.4, clang
7.0.1, global flags, `-std=c++14 -DNDEBUG`):

| Variant | Compiled | **Hits** | Hit bytes |
|---|---|---|---|
| **final** | 1,044 | **1,004** | **280,264** |
| `-std=gnu++14` | 1,044 | 1,004 | 280,264 |
| `-g0` | 1,044 | 1,003 | 279,124 |
| `-UNDEBUG` | 1,044 | 864 | 225,400 |
| `-std=c++17` | 1,043 | 840 | 212,372 |
| `-std=c++17 -UNDEBUG` | 1,043 | 836 | 211,908 |
| `-std=c++11` | doesn't compile (`std::make_index_sequence`) | | |
| `-DSOL_SAFE_REFERENCES=1` | 1,048 | 992 | 273,396 |
| `-DSOL_SAFE_FUNCTION_CALLS=1` | 1,106 | 936 | 268,060 |
| `-DSOL_NO_MEMORY_ALIGNMENT=1` | 1,041 | 831 | 237,280 |
| `-DSOL_SAFE_USERTYPE=1` | 1,119 | 788 | 260,456 |
| `-DSOL_SAFE_GETTER=1` | 1,030 | 635 | 232,808 |
| `-DSOL_CHECK_ARGUMENTS=1` | 1,214 | 609 | 222,936 |
| `-O2` | 1,043 | 913 | 175,920 |
| `-Os` | 1,151 | 604 | 51,980 |
| clang 7.0.0, 7.1.0 | 1,044 | 1,004 | 280,264 |
| clang 6.0.1 | 1,043 | 720 | 77,620 |
| clang 8.0.0 | 1,044 | 447 | 85,324 |

clang 7.0.0, 7.0.1 and 7.1.0 give the same code, as for Lua, so this TU was
built with the game's compiler. `-g0` loses one function, so `-g` stays on,
as for the rest of the game.

- **C++14.** sol2 tests `__cplusplus` itself (`SOL_CXX17_FEATURES`): with
  C++17 it uses `std::string_view` and C++17 `noexcept` function types, and
  the executable has sol2's own `basic_string_view` instances instead
  (`is_indexer`, `core_indexing_call` and the `tuple_set`s differ). c++11
  doesn't compile sol2 v2.20.4. gnu++14 gives the same code as c++14, so the
  entry uses c++14. This says nothing about the rest of the game, where the
  standard isn't visible (see "What's left open").
- **`NDEBUG`.** sol2's `assert`s (in `sol::optional`, and the
  `assert(false && ...)` paths) are compiled out: none of their expression
  strings is in rodata. `__assert_fail` is imported by `main`, so other code
  keeps its asserts, and `NDEBUG` can't be global.
- **No sol2 safety defines.** `SOL_CHECK_ARGUMENTS`, `SOL_SAFE_USERTYPE`,
  `SOL_SAFE_FUNCTION_CALLS`, `SOL_SAFE_REFERENCES`, `SOL_SAFE_GETTER` and
  `SOL_NO_MEMORY_ALIGNMENT` each lose functions. `-O3` defines
  `__OPTIMIZE__`, which keeps sol2's debug-mode default from turning them on.
- `_GNU_SOURCE`, `_LIBCPP_HAS_MUSL_LIBC` and `_LIBCPP_HAS_THREAD_API_PTHREAD`
  only make libc++ 7.0.1 compile against musl (`<locale>` needs `strtof_l`
  and the other `_l` functions). The libc++ headers the TU reads are vendored
  in `include/libcxx` like PhysX's (`SYSTEM_INCLUDES`). `lib/lua` is on the
  include path for sol2's `<lua.hpp>`.

### The TU

`ctti_get_type_name`'s strings give the class names (`field::content::
HaxeVector2`, `HaxeVector3`, `HaxeFieldFunc`, `HaxeSymbolPokemonObject`) and,
in the `usertype_metatable` instances' names, every member pointer type in
registration order (the PokemonObject one is 8,865 characters). The Lua keys
come from the registration's string arguments. Getting every instance exact
needed:

- **PokemonObject has a user-provided, out-of-line default constructor**
  (`0x7100deb970`, a `memset` of `0x10c` bytes). sol2's `constructor_list`
  wrappers call it. The type is `0x110` bytes: the callables copy `0x110`
  bytes of it into a local.
- **Vector2 and Vector3 have constructors but no default one.** sol2 gives a
  default-constructible usertype a `"new"`, and the executable has none for
  them (with a default constructor, 7 more instances appear).
- **The Log functions are passed by reference** (`"Print", f`, not `&f`): it
  changes the `tuple_set` instance.
- **The enum values.** WeatherType's are `int` prvalues (0-8). The other
  enums' are `unsigned int` (their `tuple_set`s load them with `ldr w`, not
  `ldrsw`), and the registration stores them into a zeroed `0x100`-byte local
  array first, so they may have been the values of `unsigned` enums or array
  elements. BalloonType is 0, 1, 2, 3, 8, 9 and MotionState is 1, 2, 3.
  RaycastTarget's three values are read through the GOT from `const unsigned
  int`s at `0x7101f25c58`, `0x7101f25c5c` and `0x7101f25c60` (1, 2 and
  `0xffffffff`, a mask), so they are objects defined in another TU.
- **The callables call the script with the object by reference.**
  `0x7100dee930` is `unsafe_function::call` with a `HaxeSymbolPokemonObject&`
  (no null check, pushed as a pointer), and `0x7100deea20` is the
  `table["CLwixWp"][name]` lookup with a `const char*` key.

### Names

1,174 rows of the block are named: 1,038 instances with their mangled names
(upstream sol2 and libc++ templates over the bound types; 1,033 `O`, five
waiting), the three Log functions (`O`), the 131 bound functions (`U`, in the
neighbouring TUs) and the two `M` functions. The bound methods are
named `field::content::<Class>::<Lua key>` with the ctti signature: the
registration pairs each Lua key with its function's GOT slot. That the C++
names equal the Lua keys is an assumption (the class names are certain).
Game Freak's own functions in the TU get
placeholders (`Unk_df22f0`, `Unk_df4440`, `Unk_df22c0`, ...). The two
copies of `walk_all_bases` are internal and file-qualified (`@Unk_df22f0`);
`<true>`'s address is taken first, as in the compiled code.
`lib/sol/enum_newindex.cpp` (a hand-written `fail_on_newindex`) is gone:
`sol.hpp` defines it, and the TU emits it.

### Reproducing

```sh
# sol2 single headers, one directory per tag (only sol/, sol.hpp and single/)
for t in v2.18.6 v2.18.7 v2.19.0 v2.19.4 v2.19.5 v2.20.0 v2.20.1 v2.20.2 v2.20.3 v2.20.4 v2.20.5 v2.20.6; do
  mkdir -p toolchain/candidates/src/sol2-v2/$t/single/sol
  curl -sfL -o toolchain/candidates/src/sol2-v2/$t/single/sol/sol.hpp \
    https://raw.githubusercontent.com/ThePhD/sol2/$t/single/sol/sol.hpp
done
# libc++ 7.0.1 headers (the full tree; include/libcxx only has what v2.20.4 reads)
#   toolchain/candidates/src/libcxx-7.0.1/include, see "PhysX: Reproducing"
T=toolchain/candidates/src/sol2-v2 X=toolchain/candidates/src/libcxx-7.0.1/include
COMMON="-O3 -fno-exceptions -fno-rtti -nostdinc++ -std=c++14 -DNDEBUG -D_GNU_SOURCE \
  -D_LIBCPP_HAS_MUSL_LIBC -D_LIBCPP_HAS_THREAD_API_PTHREAD -I lib/lua -isystem $X \
  -I include -I src -isystem include/libc -DPKMN_VERSION=PKMN_VERSION_SWORD"
# versions: each variant puts a tag's single/ before lib/ (the TU includes <sol/sol.hpp>)
python tools/compiler_sweep.py --compiler toolchain/candidates/clang-7.0.1 \
    --variant "v2.20.4=-I $T/v2.20.4/single" --variant "v2.20.5=-I $T/v2.20.5/single" \
    --variant "v2.20.3=-I $T/v2.20.3/single -include array" \
    --variant "v2.19.0-cxx17=-I $T/v2.19.0/single -std=c++17" ... \
    --src src/field/content/Unk_df22f0.cpp --range 0x7100dedf00-0x7100e366b0 -- $COMMON
# flags: --variant "base=-I lib" --variant "cxx17=-I lib -std=c++17" --variant "no-NDEBUG=-I lib -UNDEBUG" ...
# compilers: --compiler toolchain/candidates/clang-{6.0.1,7.0.0,7.0.1,7.1.0,8.0.0} --variant "base=-I lib"
python tools/check.py   # builds both games with the pkmn_library_settings entry
```

### What's left open

- **The registration, `0x7100df22f0` (`Unk_df22f0`, `M`).** Every call it
  makes matches, but the original creates `fromcpp` through `0x7100df4370`, a
  separate 208-byte function. That function takes the address of an
  8-byte object on the caller's stack (which holds the registration's
  argument, a pointer to an object whose `+8` is a `state_view`, i.e. a
  `sol::state`), and returns a copy of the new table: the stack frame (`0xd10`
  against `0xc90` bytes) and the stores that build the argument lists differ.
  It looks like a lambda that captures the state by reference, but a
  lambda called once would be inlined. Not found yet.
- **The callables (`0x7100dee870`, `0x7100df2100`, `0x7100df21e0`).** They
  differ only in the script function they call (`SLNoy2O`, `SLW05E4` and
  `SelxSXW` in table `CLwixWp`, obfuscated Haxe names). Each sits with
  12-byte and 4-byte functions that look like a type-erased callable's
  (clone, destroy, ...). `Unk_dee870` is written as a plain function only to
  instantiate the two sol2 functions it calls, and it is `M`.
- **The rest of the TU's own functions** (`0x7100dedfa0`-`0x7100dee830`, the
  class around the loader, and the small functions next to the callables) are
  still `U`. They're plain game code and don't involve sol2 beyond what is
  matched.
- **The enum types.** The values match, but whether they were `unsigned`
  enums, `unsigned` constants or array elements can't be seen, so the
  registration passes literals.

## Protocol Buffers 3.0.0

**Result: Google's protobuf 3.0.0 runtime, vendored by gflnet3 and built
with the game's clang 7.0.x and global flags plus `NDEBUG`, `HAVE_PTHREAD` and
`GOOGLE_PROTOBUF_NO_RTTI`.** The 32 TUs that have code in `main` are vendored
unchanged in `lib/protobuf` (BSD-3-Clause, `lib/protobuf/README.md`), and the
`pkmn_library_settings(lib/protobuf ...)` entry is this section's
configuration. **`check.py` reports all 1,622 of the area's functions `OK`
in both games**, and seven protobuf inlines the linker kept in gflnet3's code.
Four of them needed `include/libc` to follow the SDK's headers instead of
musl's in two places (see "The SDK's libc headers").

### Where it is

`data/areas.csv`'s `protobuf` row, `0x71006dea00`-`0x7100761f70` in both
games (docs/game_code.md has the boundaries). `__FILE__` names
`C:/jenkins/workspace/orion/RomBuild/program/lib/gflnet3/external/include/google/protobuf/<file>.cc`,
and headers found through `-I` are spelled `external/include\google/protobuf/...`.
So the TUs sit next to their headers, and `external/include` was the include
directory. `lib/protobuf` keeps that layout: it is the `INCLUDES` directory,
and `data/source_paths.csv` maps the literals onto it. Every literal is
absolute, so the row's `WorkDir` is never used.

The version is pinned by the generated code: every `AddDescriptors` passes
`3000000` to `VerifyVersion`. It's the full runtime, not `libprotobuf-lite`:
`descriptor.cc`, `text_format.cc`, `dynamic_message.cc` and the reflection
code are all there.

The TUs in link order, by their strong functions' addresses (Sword; Shield is
the same):

| Range | TU |
|---|---|
| `0x71006dea00`-`0x71006f8d80` | `descriptor.cc` |
| `0x71006fd780`-`0x7100700af0` | `stubs/strutil.cc`, `stubs/common.cc`, `stubs/once.cc`, `stubs/status.cc` |
| `0x7100700b80`-`0x710070dfa0` | `text_format.cc`, `message_lite.cc`, `io/coded_stream.cc`, `io/zero_copy_stream_impl_lite.cc`, `io/zero_copy_stream.cc`, `arena.cc`, `stubs/stringprintf.cc` |
| `0x710070e020`-`0x7100715270` | `unknown_field_set.cc`, `wire_format.cc`, `wire_format_lite.cc`, `generated_message_util.cc`, `stubs/structurally_valid.cc` |
| `0x7100715370`-`0x710073ed10` | `dynamic_message.cc`, `message.cc`, `map_field.cc`, `repeated_field.cc`, `reflection_ops.cc`, `extension_set.cc`, `generated_message_reflection.cc`, `extension_set_heavy.cc` |
| `0x7100740780`-`0x7100742df0` | `io/tokenizer.cc`, `io/strtod.cc`, `any.cc` |
| `0x7100742ef0`-`0x7100761c20` | `descriptor.pb.cc`, `arenastring.cc`, `descriptor_database.cc`, `stubs/substitute.cc` |

The rest of upstream's `libprotobuf` defines nothing in `main`: `compiler/`, `util/`, the well-known types' `*.pb.cc` other than
`descriptor.pb.cc`, `io/printer.cc`, `io/gzip_stream.cc`,
`io/zero_copy_stream_impl.cc`, `service.cc`, `stubs/bytestream.cc`,
`stubs/int128.cc`, `stubs/stringpiece.cc`, `stubs/time.cc`, ... In a sweep of
all 73 of upstream's TUs (below), none of their strong functions hits, and
every original of the area is accounted for by the 32.
`arena.cc` and `stubs/status.cc` had no strong hit either, but the
attribution places their functions (the arena ones differ only in TLS
access, see "`check.py`").

### Build settings

Upstream's 73 `libprotobuf` and `libprotobuf-lite` TUs (`cmake/*.cmake` of
the tag, minus the x86 atomics and `type_info_test_helper.cc`) with libc++
7.0.1 and musl, over the area (1,622 functions, Sword; Shield the same).
Hits and bytes as in "Method":

| Variant | Compiled | **Hits** | Hit bytes | Mapped | Exact |
|---|---:|---:|---:|---:|---:|
| `-std=c++11` | 4,967 | 1,475 | 329,656 | 1,126 | 702 |
| `-std=gnu++98 -DNDEBUG` | 4,839 | 1,855 | 457,776 | 1,124 | 987 |
| `-std=c++11 -DNDEBUG` | 4,828 | 2,011 | 602,992 | 1,128 | 1,111 |
| **`-std=c++14 -DNDEBUG`** | 4,828 | **2,028** | **611,164** | 1,128 | **1,128** |

Each row below changes one thing against `-std=c++14 -DNDEBUG`, clang 7.0.1:

| Variant | **Hits** | Hit bytes | Exact |
|---|---:|---:|---:|
| **final** | **2,028** | **611,164** | **1,128** |
| `-std=c++17`, `-std=gnu++14`, `-g0` | 2,028 | 611,164 | 1,128 |
| `-fstrict-aliasing` | 1,896 | 512,208 | 1,037 |
| `-fno-builtin` | 1,447 | 305,208 | 715 |
| `-O2` | 1,351 | 211,048 | 667 |
| clang 7.0.0, 7.1.0 | 2,028 | 611,164 | 1,128 |
| clang 8.0.0 | 1,486 | 248,444 | 720 |
| clang 6.0.1 | 515 | 37,836 | 196 |

- **The game's compiler and flags.** clang 7.0.0, 7.0.1 and 7.1.0 give the
  same code, and every mapped function is exact. So the global flags stay, and
  C++11 to C++17 can't be told apart: the global `-std=c++17` is kept.
- **`NDEBUG`.** Without it every `GOOGLE_DCHECK` stays in. None of their
  messages is in rodata, and C++11 without it loses 536 hits. `main` imports
  `__assert_fail`, so `NDEBUG` can't be global (as for sol2).
- **`HAVE_PTHREAD`.** `stubs/common.cc`'s `Mutex` needs a threading library.
  `main` imports `pthread_mutex_init`, `_lock`, `_unlock` and `_destroy`, and
  has the `"pthread_mutex_lock: "` message, so it's upstream's pthread code.
- **`GOOGLE_PROTOBUF_NO_RTTI`.** The global `-fno-rtti` needs it:
  `arena.h`, `casts.h` and `generated_message_reflection.h` use
  `typeid`/`dynamic_cast` otherwise. Game Freak code has no RTTI anyway
  (docs/game_code.md).
- **The thread-local arena cache.** `Arena::thread_cache_` is a real TLS
  variable (`mrs tpidr_el0`), upstream's default. Neither
  `GOOGLE_PROTOBUF_NO_THREADLOCAL` nor `PROTOBUF_USE_DLLS` is defined.
- `_GNU_SOURCE`, `_LIBCPP_HAS_MUSL_LIBC` and `_LIBCPP_HAS_THREAD_API_PTHREAD`
  make libc++ 7.0.1 compile against musl, as for sol2. The 8 libc++ headers
  protobuf reads that `include/libcxx` didn't have yet (`__tree`, `cfloat`,
  `deque`, `iostream`, `map`, `set`, `stack`, `unordered_set`) are added
  unchanged.

### Names

`sweep_attribute.py` over the build dirs (`--source-prefix lib/protobuf/`,
the area's range), the same in both games: 1,551 originals pinned to a
compiled function with the same code, 60 placed by link order and 6 pinned by
the call graph whose code differs. Five are named by hand:

- `Arena::SlowAlloc` (`0x710070dc50`): `AllocateAligned`'s slow-path tail
  call, with the compiled function's 372 bytes.
- `Closure::~Closure` D2 (`0x71006fff50`): in `common.cc`,
  `FunctionClosure0`'s destructors are aliases of it, and both classes'
  vtables point there.
- `MessageLite::SerializeToArray` (`0x710070b2e0`). With `NDEBUG` it and
  `SerializePartialToArray` compile to the same 160 bytes, and `main` has one
  copy. The linker doesn't fold identical code (thousands of byte-identical
  functions, such as the bare `ret`s, keep their own addresses), so the other
  one was unreferenced and dropped. Which one can't be told from the binary:
  nothing in protobuf calls either, and its 20 callers are one Game Freak
  helper inlined into 20 functions (`0x71006b8c00`, ...). The helper gets the
  message's `ByteSize()`, allocates and clears a buffer, and calls this
  function, and its code is the same with either call. The row has
  `SerializeToArray`, the name callers normally use, and
  `SerializePartialToArray` is in `data/absent_functions.csv`. Nothing
  depends on the choice: both compile to these bytes, and a decompiled caller
  calls whatever name the row has.
- `descriptor_database.cc`'s const and non-const `__tree::__lower_bound` for
  `map<pair<string, int>, pair<const void*, int>>` (`0x71007617e0`,
  `0x71007619d0`): the same code, so they go in the TU's section order.

Seven protobuf inlines are in gflnet3's code, because a gflnet3 TU emitted
them first. Each is named from a reference in matched code:

| Address | Function | Evidence |
|---|---|---|
| `0x71006a54a0` | `std::__tree_balance_after_insert` | 73 calls from matched protobuf code (`DescriptorBuilder`, the `std::map` instances, ...) |
| `0x71006bd2f0` | `MessageLite::GetArena` | vtable slot 5 of the `descriptor.pb.cc` messages, after `New(Arena*)` |
| `0x71006bd300` | `MessageLite::GetMaybeArenaPointer` | vtable slot 6 |
| `0x71006bd340` | `Message::GetReflection` | a vtable slot of the same messages |
| `0x71006bd410` | `InternalMetadataWithArena::mutable_unknown_fields_slow` | 66 calls from the generated `Merge` functions |
| `0x71006bd4a0` | `arena_destruct_object<InternalMetadataWithArena::Container>` | its address is taken in `mutable_unknown_fields_slow` |
| `0x71006bd4b0` | `arena_delete_object<Message>` | every `Arena::Own<T>` of a message type passes it (`arena.h`'s `OwnInternal`), and the 26 matched `Own` instances load it from one GOT slot |

`0x71006bd300` has the same code as `GenericTypeHandler<Message>::GetArena`,
and `0x71006bd4b0` the same as `arena_delete_object<MessageLite>`. But the
first is reached only through vtables (122 slots, no direct call), and the
second through the GOT slot that `Own<Message>` loads. The vtable slots come
from `data/data_symbols.csv` (below): each compiled slot's relocation names
the function, and the original's slot at the same offset gives the address.
A sweep over gflnet3's range by unique code alone also pins
`StringOutputStream::SetString` to an 8-byte setter at `0x71006dd740`. That
isn't evidence, and `SetString` is a strong function of
`zero_copy_stream_impl_lite.cc`, which would sit in that TU's code, so the
setter stays unnamed.

**Data.** `data/data_symbols.csv` gets protobuf's 154 data objects (vtables,
`default_instance_`s, `empty_string_`, `kTypeToCppTypeMap`, ...), placed
with `docs/physx/physx_data_symbols.py --prefix lib/protobuf/ --range
0x71006dea00-0x7100761f70`. `check.py` then verifies the GOT loads of them,
which were warnings before, and every one agrees. The script now uses only
the name `functions.csv` gives an address (or a C1/D1 alias of it). A
function that isn't in `main` can have the same code as one that is: the
structors of `SimpleDescriptorDatabase` have `EncodedDescriptorDatabase`'s,
and `DescriptorPoolDatabase`'s constructor has `StringOutputStream`'s. Their
references put those classes' vtables at the other classes' addresses. For
PhysX the script gives the same 566 rows as before, plus
`RayRTreeCallback<0,false>`'s vtable, which an absent `collide<0,0>` used to
contradict.

Of the other compiled functions, the 753 strong ones that aren't in `main`
are in `data/absent_functions.csv`. Every original in the area has a name,
so a strong function of these TUs that isn't one of them was dropped or
inlined. The 69 weak copies (inline functions, templates) with no original
are in `data/unidentified_functions.csv`. No matched function calls one,
loads one or has one in a vtable. So each was inlined everywhere, or `main`
has the copy of a TU that isn't built here (gflnet3's or the game's generated
messages, see "Next").

### `check.py`

Two cases needed `check.py` changes:

- **Weak copies that differ between TUs.**
  `GenericTypeHandler<T>::NewFromPrototype` is emitted by `descriptor.cc`,
  which inlines `New()` (112 bytes), and by `descriptor.pb.cc`, which
  tail-calls it (8 bytes). `check.py` required every distinct copy to match,
  because the linker keeps one by link order. But the executable shows which
  one: the linker places the kept copy among the code of the TU it took it
  from, and all nine originals are inside `descriptor.cc`'s code. Now, when
  the original lies inside exactly one copy's TUs (between their first and
  last strong functions with a row), only that copy is compared, and a
  warning names the others (`kept_copy`).
- **TLS.** clang emits `Arena::thread_cache_`'s accesses as the TLS
  descriptor sequence (`adrp x0`, `ldr x1, [x0]`, `add x0, x0`, `blr x1`).
  In an executable, lld relaxes it to local-exec: `movz x0, #hi, lsl #16`,
  `movk x0, #lo`, two `nop`s. `check.py` now accepts exactly that, and
  requires every access to one variable to load the same thread-pointer
  offset (`0x10` here). Which variable is at that offset can't be checked:
  the NSO has no TLS segment table. `Arena::AddListNode`, `AllocateAligned`
  and `SlowAlloc` match with it.

### The SDK's libc headers

musl 1.1.24's headers stand in for the SDK's libc (`include/libc`), and four
protobuf functions showed two places where the SDK's differ.
`include/libc/README.md` lists the changes, and each has an `NX:` comment:

- **`errno.h`: `__errno_location` isn't `const`.** `FloatToBuffer`
  (`0x71006fee00`) calls `__errno_location` again after `strtof` to read
  `errno`, where musl's `__attribute__((const))` lets the compiler reuse the
  first call's result. Without the attribute it matches, and so does
  libcurl's `curl_getdate` (`0x7101764750`, `parsedate.c`), which was `M`.
- **`bits/alltypes.h`: `pthread_mutex_t` is `0x20` bytes.** `Mutex::Mutex`
  (`0x71006fff70`), `InitLogSilencerCount` (`0x71006ffc20`) and
  `InitShutdownFunctions` (`0x7100700140`) allocate `Mutex::Internal`, which
  holds only a `pthread_mutex_t`, with `operator new(0x20)`. musl's is 40.
  The layout beyond the size isn't visible, so the union keeps musl's shape
  with 8 ints.

With both changes, a full rebuild and `check.py` give every other function
the same result as before, in both games.

`check.py --update` (both games), with everything before:

```
12824 matching, 82 not matching
(2628 compiled functions skipped as not in the executable: data/absent_functions.csv)
(278 compiled functions skipped, their original not identified yet: data/unidentified_functions.csv)
(1 weak/COMDAT functions skipped: the executable keeps another library's copy, data/foreign_copies.csv)
(405 compiled aliases of checked functions skipped, e.g. D1 = D2 destructors)
```

Before protobuf, 11,194 matched and 83 didn't. The 82 that don't match now
are libcurl's and sol2's `M` functions, less `curl_getdate`.

### Reproducing

```sh
cd toolchain/candidates/src
mkdir protobuf-3.0.0-dl && cd protobuf-3.0.0-dl
curl -LO https://github.com/protocolbuffers/protobuf/archive/refs/tags/v3.0.0.tar.gz && tar xzf v3.0.0.tar.gz
cd ../../../..
P=toolchain/candidates/src/protobuf-3.0.0-dl/protobuf-3.0.0 X=toolchain/candidates/src/libcxx-7.0.1/include
# upstream's library TUs, one --src per line
cat $P/cmake/libprotobuf-lite.cmake $P/cmake/libprotobuf.cmake | grep -oE 'src/google/protobuf/[^ ]+\.cc' \
  | grep -v -E 'x86_|test_helper' | sed "s#^#--src\n$P/#" > pb_src.rsp
COMMON="-O3 -fno-exceptions -fno-rtti -nostdinc++ -isystem $X -I $P/src -isystem include/libc \
  -DHAVE_PTHREAD -DGOOGLE_PROTOBUF_NO_RTTI -D_GNU_SOURCE -D_LIBCPP_HAS_MUSL_LIBC -D_LIBCPP_HAS_THREAD_API_PTHREAD"
python tools/compiler_sweep.py --compiler toolchain/candidates/clang-7.0.1 \
    --variant "cxx11=-std=c++11" --variant "cxx11nd=-std=c++11 -DNDEBUG" \
    --variant "cxx14nd=-std=c++14 -DNDEBUG" --variant "gnu98nd=-std=gnu++98 -DNDEBUG" \
    --range 0x71006dea00-0x7100761f70 @pb_src.rsp -- $COMMON
# flags: COMMON+="-std=c++14 -DNDEBUG", --variant "final=" --variant "cxx17=-std=c++17" --variant "O2=-O2" ...
# compilers: --compiler toolchain/candidates/clang-{6.0.1,7.0.0,7.1.0,8.0.0} --variant "final="
# names: build both games, then
python tools/sweep_attribute.py build/sword --source-prefix lib/protobuf/ \
    --range 0x71006dea00-0x7100761f70 --game sword --out attr_sword.csv   # and shield
```

### The generated messages

Game Freak's own messages, which use this runtime, are matched too: see
"Generated protobuf messages", next.

## Generated protobuf messages

**Result: Game Freak's own messages are protoc 3.0.0 output for 73 `.proto`
files, built like the runtime (the game's clang 7.0.x and flags, `NDEBUG`).**
The `.proto` files are in `src/`, reconstructed from the descriptors in
`main` by `tools/protos.py extract`, and `tools/protos.py generate` regenerates
their code (`src/**/<name>.pb.cc`, `.pb.h`, not committed). **`check.py`
reports 2,414 of their functions `OK` in both games.** 24 are `M` (see "What
doesn't match"), and eight are another TU's copies.

### The `.proto` files

Every generated file registers its serialized `FileDescriptorProto` with
`DescriptorPool::InternalAddGeneratedFile` (`0x71006e1400`). Besides
protobuf's own `descriptor.proto` there are 73, called from 221 places (clang
inlines `protobuf_AddDesc_<file>` into some callers). All are proto3, without
file options, and they have 96 messages in 18 packages. The descriptor is the
`.proto` in full (messages, fields, oneofs, maps, enums, imports), except for
comments and formatting, which the code doesn't depend on.

`extract` decodes each descriptor with a schema of the fields it knows (an
unknown field is an error), prints proto3 source, and checks it: protoc 3.0.0
compiles the file back, and its descriptor must equal the original. All 73
do. `--descriptor_set_out` adds `json_name`, which the C++ generator's embedded
descriptor (`FileDescriptor::CopyTo`) leaves out, so it's ignored there. The
descriptor literal in each generated `.pb.cc` is then compared byte for byte by
`check.py`, like any literal.

Each file goes where its code was compiled. The `__FILE__` literal of each
`.pb.cc` (`MergeFromFail`'s `GOOGLE_CHECK`) gives the directory, e.g.
`.../RomBuild/program/prog/network/net_contents/source/battle/nbr/protocol_buffers/out/data/`
and `.../lib/gflnet3/src/p2p/sync/protocol_buffers/ping/out/data/`. The 73
names are unique, so all 74 literals (with `descriptor.pb.cc`'s) map one to
one. `data/source_paths.csv` maps `src/battle/`, `src/contents/` and
`src/network/` onto `RomBuild/program/prog/`, and `src/gflnet3/` onto
`RomBuild/program/lib/gflnet3/`. So the files are in 20 directories:
gflnet3's 11 (framework, session block, sync data and ping), and the game's
62 (`battle_logic`'s net and netwatch, `net_contents`' battle, nesthole and
trade, `pokecamp`, `comp_organize`, `btl_spot`).

### Building them

`generate` runs protoc on each file by its bare name, from its directory, with
every directory on the import path: the code says `// source: <name>.proto`
and includes `"<dep>.pb.h"`, as Game Freak's did. The output embeds the
serialized descriptor, a copy of the game's rodata, so it isn't committed
(`src/.gitignore`, and lint rejects a tracked `.pb.cc`/`.pb.h` under `src/`).
protoc is Google's v3.0.0 release, downloaded into `toolchain/protoc-3.0.0`
and checked against its SHA-256 (Windows, Linux x86-64, macOS x86-64). CI
generates the code before it configures, and `CMakeLists.txt` refuses to
configure while a generated file is missing or older than its `.proto` or
`tools/protos.py`.

The build settings are the runtime's (`pkmn_library_settings`, one entry per
directory). A sweep of the 73 generated TUs over gflnet3 and the game
(`0x710069d6e0`-`0x7101548410`, 70,305 originals, clang 7.0.1):

| Variant | Compiled | Hits | Hit bytes | Mapped | Exact |
|---|---:|---:|---:|---:|---:|
| **`-DNDEBUG`** | 3,872 | **2,469** | **328,964** | 781 | **781** |
| without `NDEBUG` | 3,882 | 2,112 | 254,360 | 781 | 661 |

As for the runtime, `NDEBUG` keeps the protobuf headers' `DCHECK`s out.

**One virtual function more.** Each of the 96 generated classes in `main` has
a 27th vtable slot (offset `0xd0`, after `GetMetadata`), which protoc 3.0.0's
classes don't have, and neither do protobuf's own `descriptor.pb.cc` classes
(their vtables end at `GetMetadata`). It points to `mov w0, #1; ret`, a
function of the class emitted at the end of its `.pb.cc`, right after
`GetCachedSize`, the way protoc's header-inline virtuals are. So Game
Freak's generator adds an inline `bool ... const { return true; }` to every
message class, presumably at protoc's `class_scope` insertion point. The name
isn't in the binary (no strings, no RTTI). `generate` inserts `virtual bool
Unk_vfunc_d0() const { return true; }` at each `class_scope` insertion point,
and the vtables then have the original's slots: data/data_symbols.csv places
them, and their slot relocations name all 96 overrides at the original's
addresses.

### Names

`sweep_attribute.py` over both builds (`--source-prefix src/`, gflnet3 and the
game) names 2,305 originals of the generated TUs, the same in both games.
A name placed by link order is kept only inside its TU's code (between its
first and last pinned function) or where `check.py` verifies the code's
references. That drops `CookingData::SharedDtor`, a `ret` placed among
thousands of identical ones at `0x71006de7d0`, and two static initialisers
placed on other TUs' 4-byte `b` stubs. Then:

- 12 callees of matched functions that were pinned by calls but differ: the
  `protobuf_AddDesc_*` of four `*_data_holder` files and eight
  `NewFromPrototype` instances. `btl_spot_data_holder`'s `AddDesc` is
  `0x7100b0f3a0`, which registers its descriptor and calls its dependency's.
- 19 static initialisers: the function that tail-calls the TU's
  `protobuf_AddDesc_*` (or inlines it and registers the descriptor), at the
  end of the TU's code.
- 16 functions of the `*_data_holder` TUs (`SetCachedSize`, `New(Arena*)`,
  `Arena::Own`, `clear_message`), the only same-code candidates of the TU.
- The 96 `Unk_vfunc_d0`: 92 by their vtable slots, and the four of the
  `*_data_holder` classes (whose vtables nothing pins) at the same place in
  their TU, after `GetCachedSize`.

`data/data_symbols.csv` gets the generated code's 287 data objects (vtables,
`default_instance_`s, descriptors, reflection pointers, ...), placed by
`docs/physx/physx_data_symbols.py` with `--prefix src/<dir>/`, and every GOT
load of them agrees. With every original in the generated TUs' code named,
the 862 compiled functions that aren't in `main` (inlined or dropped:
`SharedCtor`, `descriptor()`, `InternalSwap`, ...) are in
`data/absent_functions.csv`, and eight weak copies without an original in
`data/unidentified_functions.csv`.

The eight `GenericTypeHandler<T>::NewFromPrototype` of `PlayerPosition` and
seven `KwSyncData_*` messages are another TU's copies
(`data/foreign_copies.csv`): the copy in `main` is before the code of the
`.pb.cc` that defines `T`, and calls `T`'s constructor out of line, which that
`.pb.cc` inlines. So the linker kept the copy of a Game Freak TU that uses the
message, which isn't built here.

`check.py --update` (both games), with everything before:

```
15238 matching, 106 not matching
(3490 compiled functions skipped as not in the executable: data/absent_functions.csv)
(286 compiled functions skipped, their original not identified yet: data/unidentified_functions.csv)
(9 weak/COMDAT functions skipped: the executable keeps another library's copy, data/foreign_copies.csv)
(598 compiled aliases of checked functions skipped, e.g. D1 = D2 destructors)
```

Before the generated messages, 12,824 matched and 82 didn't. The 106 are those
82 and the 24 below.

### What doesn't match

24 functions, all from a Game Freak header that some TUs include before the
generated code, whose dynamically initialised constants are TU-local statics:

- **gflnet3's 11 `.pb.cc`.** Their static initialisers (`0x71006bd4d0`, ...)
  first build colour constants (three calls of `0x71017e8f30` with 0x7f/0xff/0
  components) and then tail-call or inline `protobuf_AddDesc_*`. In the four
  `*_data_holder` TUs (and `btl_spot_data_holder`'s, below) those statics are
  also merged with the TU's own (`.L_MergedGlobals`), so `protobuf_AddDesc_*`
  addresses its `already_here` flag and the oneof-case pointer at other
  offsets (`+0x33` and `+0x60`, not `+0` and `+0x18`).
- **pokecamp's 6.** The static initialisers copy a 48-byte constant (three
  `q` loads) into a TU-local object first.
- **btl_spot's 2.** The static initialisers store 600,000 and 7,000 (two
  millisecond timeouts?) three times into a TU-local object first.

That's 19 static initialisers and 5 `AddDesc` functions, `M`. The other 54
generated TUs have no such statics, and their static initialisers match.
Matching these needs the header, which isn't known.

### Reproducing

```sh
python tools/protos.py extract     # rewrites src/**/*.proto and checks each with protoc
python tools/protos.py generate    # the .pb.cc/.pb.h
# the sweep: protoc's output for the 73 files, one config with and one without NDEBUG
P=lib/protobuf X=include/libcxx
python tools/compiler_sweep.py --compiler toolchain/candidates/clang-7.0.1 \
    --variant "nd=-DNDEBUG" --variant "debug=" --range 0x710069d6e0-0x7101548410 \
    --src "src/**/*.pb.cc" -- -O3 -fno-exceptions -fno-rtti -nostdinc++ -std=c++14 \
    -isystem $X -I $P $(for d in $(dirname $(find src -name '*.proto') | sort -u); do echo -I $d; done) \
    -isystem include/libc -DHAVE_PTHREAD -DGOOGLE_PROTOBUF_NO_RTTI -D_GNU_SOURCE \
    -D_LIBCPP_HAS_MUSL_LIBC -D_LIBCPP_HAS_THREAD_API_PTHREAD
# names: build both games, then (Sword; Shield: --game shield --range 0x710069d6e0-0x71015484b0)
python tools/sweep_attribute.py build/sword --source-prefix src/ \
    --range 0x710069d6e0-0x7101548410 --game sword --out attr_sword.csv
for d in gflnet3 network battle contents; do
  python docs/physx/physx_data_symbols.py ds_$d.csv --prefix src/$d/ --range 0x710069d6e0-0x7101548410
done
```

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
Compiled with clang 6.0.0 or 6.0.1, it reproduces **all 8 TLSF functions the
sweep maps (2,596 bytes) byte-for-byte, in both games**. No other version gets
more than 6. It's vendored in `lib/tlsf` and built with clang 6.0.1, and all
9 of its functions in the binary match (see "`lib/tlsf`" below).

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
- The fix's author is Martin Dufour of Audiokinetic (`mdufour@audiokinetic.com`
  in the commit), Wwise's vendor. So the patch most likely went upstream from
  Wwise's copy, not the other way round, which explains a 2.0 release with one
  3.x function.

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

From `tools/fingerprint.py` (metric names in backticks, defined in "Codegen
fingerprints"). Every figure is the same in Shield.

| Check | Wwise | Game code | PhysX |
|---|---|---|---|
| Small constants: `orr wN, wzr, #imm` / `movz` of a logical immediate (`orr_wzr` / `movz_logical`) | 5,681 / 28 | 90,457 / 161 | 11,601 / 28 |
| Calling functions that set up `x29` (`frame_pointer` of `calling`) | 2,609 of 2,609 | 43,978 of 43,978 | 4,974 of 4,974 |
| `movi v.2d, #0` / `stp xzr, xzr` (`movi_zero` / `stp_xzr`) | 8 / 1,044 | 703 / 37,688 | 432 / 1,645 |
| FDE CIEs (`fde_*`) | 4,179 `zR` | 74,892 `zR` | 6,967 `zR`, 1,280 `zPLR` |
| Mangled typeinfo names in `.rodata` (`--typeinfo AK --typeinfo Ak`) | none | | none (`-fno-rtti`) |
| Unpaired `ldr` pairs into the base, ascending / descending offsets / `ldp` into the base (`g_ldr_pairs` / `g_ldr_pairs_desc` / `g_ldp_base`) | **0 / 11 / 40** | 62 / 1 / 1,339 | 5 / 0 / 158 |
| `and xD, xS, #0xffffffff` feeding a 32-bit variable shift within 4 instructions (`and_shift`, `and_shift_funcs`) | 11 in 7 functions | 0 | 1 in 1 |

```sh
python tools/fingerprint.py wwise physx \
    game=0x7100596d20-0x7101548410,0x7100596d20-0x71015484b0 --typeinfo AK --typeinfo Ak
```

Corrections against the first version of this table, which ad-hoc scripts
computed: the game column was a sample (`0x71005a0000`-`0x7100700000`: 6,383 /
20, 3,445 of 3,879, 97 / 3,057, 11 / 162, 0) and is now all of game code. The
frame-record row counted functions with a `bl` or `blr` that had `stp x29,
x30` among their first 6 instructions (2,343 of 2,609, 3,445 of 3,879, 4,242
of 4,974). That measured prologue scheduling, not frame pointers: every
calling function in every region sets up `x29`. PhysX's `ldp` figure was 157.
The other figures reproduce exactly.

- **The `ldr` pair row is the `-g` fingerprint** (see "Debug info"), and it
  doesn't settle Wwise. In the `stackinuse` order (ascending offsets) the `-g`
  builds have it: game code 62 against 1,339 `ldp`, Lua 3 against 40. Wwise
  has none against 40 (about 2 expected at the game's rate). But Wwise has 11
  unpaired loads into the base in the other order, 10 of them the same inlined
  idiom (`ldr x8, [x9, #0x80]` / `ldr x9, [x9, #0x78]`), against 1 in all of
  game code and none in Lua, PhysX or YEBIS. clang 6.0.1 and 7.0.1 pair that
  order in a small loop, with or without `-g` (`ldp x0, x9, [x0, #120]`), so
  something blocks it in Wwise, and debug info is one candidate. An earlier
  version of this section counted the ascending order only and concluded
  "probably without `-g`". **`-g` for Wwise is undetermined.** TLSF itself
  compiles the same with or without `-g`.
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

### `lib/tlsf`

`lib/tlsf` holds the source the sweep used: TLSF 2.0 from `samplecount/tlsf`
with 2b73b8a's `adjust_request_size`, and nothing else changed (provenance and
both licenses in `lib/tlsf/COPYRIGHT`). `pkmn_library_settings(lib/tlsf ...)`
builds it with `COMPILER_VERSION 6.0.1` and `NDEBUG`, on top of the global
flags, which are the game's (`-fno-strict-aliasing`, `-fno-exceptions`, `-g`).
6.0.1 rather than 6.0.0 only because PhysX needs 6.0.1 already: the two give
the same TLSF.

| Function | Sword = Shield | Size |
|---|---|---:|
| `tlsf_block_size` | `0x71003049b0` | 16 |
| `tlsf_overhead` | `0x71003049c0` | 8 |
| `tlsf_create` | `0x71003049d0` | 456 |
| `tlsf_malloc` | `0x7100304ba0` | 88 |
| `block_locate_free@tlsf` | `0x7100304c00` | 392 |
| `block_prepare_used@tlsf` | `0x7100304d90` | 360 |
| `tlsf_memalign` | `0x7100304f00` | 536 |
| `tlsf_free` | `0x7100305120` | 492 |
| `block_merge_next@tlsf` | `0x7100305310` | 256 |

The sweep skips functions under 16 bytes, so it didn't map `tlsf_overhead`
(`mov w0, #0x1998 ; ret`: `sizeof(pool_t)` is 6,536 on 64-bit, plus two
8-byte block headers). Its place is the evidence: between `tlsf_block_size`
and `tlsf_create`, in source order. The rest of the TU is in
`data/absent_functions.csv`: `tlsf_destroy` (an empty function),
`tlsf_realloc`, `tlsf_check_heap`, `tlsf_walk_heap` and `default_walker`.
`integrity_walker` is inlined into `tlsf_check_heap`. The other static
functions are inlined everywhere.

This is the only TLSF in `main`. Swept over the whole executable with clang 5
to 11, TLSF 2.0, the Wwise source and mattconte's current 3.x (`deff9ab`)
hit nothing larger than 8 bytes outside these functions. gflib3 has a TLSF
heap of its own (`lib/gflib3/src/mem/internal/tlsf_pool.cpp`, the `__FILE__`
of `0x710065efa0`), but it isn't this code: over gflib3's range, both sources
give no hit with clang 6.0.1 or 7.0.1, as C or as C++ (`-x c++
-std=gnu++14`), with or without `NDEBUG`.

### What's left open

- **6.0.0 vs 6.0.1, `-O2` vs `-O3`.** TLSF is too small to tell them apart,
  and no other public code in Wwise compiles to the same instructions.
- **`-g`.** Undetermined: no `ldr` pair in the `stackinuse` order, but 11
  unexplained unpaired loads in the other order (fingerprint above).
- **Whether every Wwise library used the same configuration.** Only the
  memory manager's TLSF was compiled. The plugin-registration stubs and the
  codecs are separate libraries in the Wwise SDK.
- **How the Vorbis decoder was derived.** Its window tables are libvorbis's,
  but the code isn't. Matching it needs the decompilation route.

## Other middleware

The same `tools/fingerprint.py` metrics as the Wwise table. Every figure is
the same in Shield.

| Region | `movz_logical` / `orr_wzr` | `frame_pointer` of `calling` | `movi_zero` / `stp_xzr` | `fde_zR` / `fde_zPLR` | `g_ldr_pairs` / `g_ldr_pairs_desc` / `g_ldp_base` |
|---|---|---|---|---|---|
| YEBIS (`0x710040f550`-`0x7100596d20`) | 78 / 9,677 | 3,014 of 3,014 | 2 / 4,931 | 5,002 / 0 | **0 / 0 / 250** |
| After Lua (`0x7101570900`-`0x71017ec260`) | 380 / 15,358 | 6,758 of 6,758 | 116 / 2,855 | 10,846 / 1 | 1 / 0 / 868 |

```sh
python tools/fingerprint.py yebis=0x710040f550-0x7100596d20 middleware --typeinfo PPFX
```

Corrections against the first version of this table: its frame-record column
counted functions with a `bl` whose first 12 instructions hold `stp x29, x30`
(2,380 of 2,399 and 6,329 of 6,344); every calling function sets up `x29`.
Its `stp xzr, xzr` column (1,059 for YEBIS, 1,123 after Lua) matched no
definition that could be found; with the Wwise table's definition the counts
are 4,931 and 2,855. The other figures reproduce exactly. Over the first,
wrong YEBIS range (`0x710040f550`-`0x71005a0000`, 181 game functions more)
the tool gives the old figures too: 78 / 9,819, 3 `movi`, 5,183 FDEs and 5 /
255 `-g` pairs.

- **YEBIS has no `-g` `ldr` pair**, in either order. All 5 counted over the
  old range are in the game functions after `0x7100596d20`. At the game's rate
  (62 against 1,339) about 12 would be expected against 250 `ldp`, so **YEBIS
  was probably built without `-g`**, like the libraries after Lua (1 against
  868, about 40 expected). The confidence is low: the pattern depends on the
  source. zlib compiles the same with or without `-g`, so it doesn't settle
  the question. YEBIS keeps RTTI: 47 typeinfo names have a `PPFX` component
  (`--typeinfo PPFX`; 46 start with it, one is an `SiSDK3::SiArray` of a
  `PPFX` type).

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
  (47 `PPFX` typeinfo names, see above) and has no exception tables.

  ```sh
  cd toolchain/candidates/src && curl -LO https://zlib.net/fossils/zlib-1.2.5.tar.gz && tar xzf zlib-1.2.5.tar.gz && cd ../../..
  Z=toolchain/candidates/src/zlib-1.2.5
  python tools/compiler_sweep.py --compiler 'toolchain/candidates/clang-*' \
      --variant O3=-O3 --variant O3g="-O3 -g" --variant O2=-O2 --variant Os=-Os \
      --src "$Z/[a-di-z]*.c" --src "$Z/gz*.c" --range 0x710040f550-0x7100596d20 \
      -- -isystem toolchain/candidates/sysroot/include
  ```

  (The two globs leave out `example.c` and `minigzip.c`.) With the
  corrected range, clang 7.0.1 `-O3` still gives 30 functions (34,116 bytes)
  in both games, the same as over `0x710040f550`-`0x71005a0000`.

  **All of it matches now, in `lib/zlib`.** The zlib code is one contiguous
  block, `0x710058be50`-`0x7100594470` at the same addresses in both games:
  33 functions, `compress2` first and `zutil.c`'s `zlibVersion`, `zcalloc`
  and `zcfree` last. The sweep's default `--min-size 16` hides those three
  (12, 8 and 8 bytes); with `--min-size 4` it maps 34 names. One address
  gets two: `zlibVersion` and `get_crc_table` both compile to `adrp; add;
  ret`. The address it loads is odd (a string, not the 4-byte-aligned CRC
  table), and the function sits after `inftrees.c`'s, where `zutil.c` comes
  in link order, so it's `zlibVersion`. `zcalloc` is `mul w0, w2, w1; b
  malloc` and `zcfree` `mov x0, x1; b free`, upstream's
  `sizeof(uInt) > 2` paths. The functions before and after the block call
  into it but aren't zlib (YEBIS's SiIO).

  `lib/zlib` is the upstream source, unmodified, for the 10 TUs with functions
  in the executable (`adler32 compress crc32 deflate inffast inflate inftrees
  trees uncompr zutil`) and their headers, built with the global flags (no
  `pkmn_library_settings` entry). `check.py` reports all 33 `OK` in both
  games. The other 27 functions those TUs compile (`compress`,
  `compressBound`, `deflateParams`, `inflateSync`, `crc32_combine`, `zError`,
  ...) aren't in the executable: swept over all of `main`, they match nothing
  but 4-byte tail calls (`b`), which any thunk matches. They're in
  `data/absent_functions.csv`. `gz*.c` and `infback.c` have no function in
  the executable and aren't vendored.

  ```sh
  python tools/compiler_sweep.py --compiler toolchain/candidates/clang-7.0.1 --variant O3=-O3 \
      --min-size 4 --src "$Z/[a-di-z]*.c" --src "$Z/gz*.c" \
      --range 0x710058be00-0x7100594470 --map-out zlib_map.csv \
      -- -isystem toolchain/candidates/sysroot/include
  ```

  The second zlib-like string, `invalid distance code` at `0x7100516b50`
  (6,732 bytes), is another inflater in YEBIS. No zlib 1.2.5 function
  matches it.
- **After Lua** (NEX 4.6.8, Pia, NintendoWare, nn SDK static libraries): all
  `orr`-form constants (clang older than 9), frame pointers, GPR-only zeroing
  and no exception tables (1 `zPLR` FDE). Only 1 `-g` `ldr` pair against 868
  `ldp`, so these libraries probably weren't built with `-g`. NEX's source isn't
  public. Its libcurl 7.55.1 identifies the SDK's compiler, see "Nintendo SDK
  middleware".

## Nintendo SDK middleware

**Result: Nintendo's SDK 7.3.2 libraries were built with clang 7.0.x at `-O3`
and the game's codegen flags, the same compiler as Game Freak's code (unlike
PhysX and Wwise).** Two public libraries show it, and they agree:

| Library | Where | Best | Hits | Bytes | Exact of mapped |
|---|---|---|---:|---:|---:|
| libcurl 7.55.1 (`NintendoSDK_libcurl-7_3_2-Release`) | `main`, after Lua | clang 7.0.0 / 7.0.1 / 7.1.0 `-O3` | 84 | 20,824 | 82 of 83 (Shield: 84 hits, the same) |
| zlib 1.2.11 (`NintendoSDK_libz-7_3_2-Release`) | the `sdk` NSO, not `main` | clang 7.0.0 / 7.0.1 / 7.1.0 `-O3` | 58 | 35,604 | 55 of 55 (Shield the same) |

Confidence: **high** for the compiler major version and `-O3` (both libraries,
every mapped zlib function, two independent SDK components, both games).
7.0.0, 7.0.1 and 7.1.0 can't be told apart here either. Nintendo's own NX clang
is presumably a vendor build of 7.0; these corpora show no difference from
upstream. `-g` is **not determined**: both corpora compile the same with or
without it. The fingerprints (1 `-g` `ldr` pair against 868 `ldp` after Lua)
suggest no debug info, at low confidence.

### What is in the block

The `SDK MW+<vendor>+<library>` strings in `main` list the middleware linked
in (`nlib_LZ4-19_0226`, `PhysX-3_4_2-release`, `NEX-4_6_8`, ...). Of the
public libraries named in the post-Lua block:

- **libcurl 7.55.1** is in `main`, in its own area (Sword
  `0x7101750ea0`-`0x7101779270`, see below). `libcurl/7.55.1` is referenced
  from `0x7101776e40`, the version string's builder. It is the corpus for the
  table below, and it's vendored in `lib/curl`.
- **zlib 1.2.11 is not in `main`.** `main` only holds `1.2.11.f-NINTENDO-SDK-v1`,
  the `ZLIB_VERSION` that its callers pass to `inflateInit2_`/`deflateInit2_`
  (`0x710165dbb0`, `0x71016615f0`, `0x7101763df0`, ...): upstream zlib has
  no counterpart there (best similarity below 0.62, mostly below 0.3). The
  library itself, with its `deflate 1.2.11 Copyright` and `inflate 1.2.11
  Copyright` strings, is in the `sdk` NSO (`nnSdk-7_3_2-Release`). The zlib
  in `main` (`incorrect header check`) is YEBIS's 1.2.5.
- **LZ4 code isn't found in `main`.** Nothing in `main` builds LZ4's hash
  prime (`0x9E3779B1`, also xxHash's), and no `lz4.c` 1.8.3 function, the
  decompressors included, has a counterpart above similarity 0.36. Only the
  `nlib_LZ4` tag is there. It isn't in the `sdk` NSO's strings either, so its
  version wasn't identified and it wasn't swept.

### libcurl 7.55.1 (`main`, Sword `0x7101750ea0`-`0x7101779270`)

Nintendo's libcurl is vendored in `lib/curl` (`lib/curl/README.md`): 55 TUs of
upstream 7.55.1, unchanged, and a `curl_config.h` reconstructed from the
binary. `CMakeLists.txt` builds them with the global flags and curl's defines
for a static library (`pkmn_library_settings(lib/curl ...)`, this section is
its evidence). With that configuration, 391 compiled functions, **84 reproduce
byte for byte (20,824 bytes) in both games**. The rest depends on changes
Nintendo made to curl's own files, which aren't public (see "What doesn't
match").

The compiler and flags (the vendored corpus over the libcurl area, Sword):

| Compiler | `-O3` hits | `-O3` bytes | `-O3` avg similarity | `-O2` hits | `-Os` hits | `-O3 -g0` hits |
|---|---:|---:|---:|---:|---:|---:|
| clang 3.9.1 | 18 | 676 | 0.747 | 18 | 18 | 17 |
| clang 4.0.1 | 17 | 548 | 0.759 | 17 | 17 | 16 |
| clang 5.0.1 / 5.0.2 | 24 | 1,064 | 0.811 | 22 | 20 | 23 |
| clang 6.0.0 / 6.0.1 | 28 | 1,704 | 0.868 / 0.869 | 25 | 23 | 27 |
| **clang 7.0.0 / 7.0.1 / 7.1.0** | **84** | **20,824** | **0.991** | 62 | 45 | 84 |
| clang 8.0.0 / 8.0.1 | 66 | 9,848 | 0.939 | 53 | 41 | 65 |
| clang 9.0.1 | 28 | 1,912 | 0.836 | 25 | 20 | 28 |
| clang 10.0.0 | 21 | 1,232 | 0.735 | 19 | 16 | 20 |
| clang 11.0.0 | 20 | 1,176 | 0.723 | 18 | 15 | 19 |

83 functions are mapped over all configurations. clang 7.0.x reproduces 82 of
them, and every one of the 82 that clang 7.0.1 maps by itself, in both games.
Shield gives the same 84 hits and 20,824 bytes. The first version of this table
(all 103 TUs of upstream's `lib/` with a minimal POSIX `curl_config.h`, over
the whole block) separated the versions the same way: 76 hits (18,828 bytes)
for clang 7.0.x, 59 for 8.0.x, 25 for 6.0.x.

Flags (clang 7.0.1, each row changes one thing; the zlib column is the `sdk`
NSO's zlib 1.2.11, see below):

| Variant | libcurl hits | zlib hits | What it shows |
|---|---:|---:|---|
| **`-O3`, the game's flags** | **84** | **58** | |
| `-O2` / `-Os` | 62 / 45 | 30 / 7 | `-O3`. |
| `-fstrict-aliasing` | 78 | 40 | Strict aliasing off, as in the game. |
| `-fno-builtin` | 70 | 52 | Builtins on. |
| `-fstrict-aliasing -fno-builtin` (PhysX's differences) | 66 | 36 | Not PhysX's configuration. |
| `-fomit-frame-pointer` | 38 | 32 | |
| `-mimplicit-float` | 73 | 41 | |
| `-fno-pic` | 75 | 49 | |
| `-mcpu=generic` | 29 | 14 | Cortex-A57 model. |
| `-fvisibility=hidden` | 84 | 55 | zlib: default visibility. |
| `-g0`, `-fno-unwind-tables`, `-U__ELF__`, `-DNDEBUG` | 84 | 58 | Not distinguishable (with `-g` the CFI is emitted anyway). |

#### Area boundaries

The libcurl area is Sword `0x7101750ea0`-`0x7101779270`, Shield
`0x7101750f40`-`0x7101779310` (395 functions, the same in both games, `data/areas.csv`):

- **Start.** `0x7101750ea0` is `curl_global_init_mem`. It null-checks five
  callbacks (`CURLE_FAILED_INIT`), counts the init calls, stores the callbacks
  through Nintendo's allocator setup and runs `global_init` inlined:
  `Curl_ssl_init` when `flags & CURL_GLOBAL_SSL`, the resolver's global init,
  and the `SDK MW+Nintendo+NintendoSDK_libcurl-7_3_2-Release` tag function
  (`0x7101778420`). Before it are the `nlib_LZ4-19_0226` tag (`0x7101750e80`)
  and `__clang_call_terminate` (`0x7101750e90`, called from the code before it).
- **Inside.** Upstream code comes first, though not in upstream's
  `Makefile.inc` order (`easy`, `cookie`, `connect`, `conncache`,
  `asyn-thread`, `hash`, `hostip`, ..., `md5`, `version`, `vtls`,
  `wildcard`). Then the tag function, then Nintendo's glue: `nn::nsd::ResolveEx`
  (called from `Curl_setopt`), `nn::nifm::GetCurrentProxySetting` (called
  from url.c's connection setup, `0x71017703c0`), `fopen`/`fread`/`fclose` stubs that abort, and
  the resolver thread (`nnosCreateThread`, named `LibcurlResolver`). The
  `nn::ssl` backend (`nnssl*` imports, the `"nn::ssl"` version string,
  referenced from `0x7101777ed0`) sits between `vtls.c`'s code and
  `wildcard.c`'s.
- **End.** `0x7101779250` is the last function called from `asyn-thread.c`'s
  code. `0x7101779270` and everything after it is called only from NintendoWare
  (Font, `0x7101782330` on), whose `SDK MW+Nintendo+NintendoWare_Font` tag
  function is at `0x710177b2a0`.

#### The configuration

Nintendo's `curl_config.h` isn't public. `lib/curl/lib/curl_config.h`
reconstructs it from these observations (each one is also a comment there):

- **Protocols: HTTP and HTTPS only.** `curl_version_info()`'s static data
  (Sword `0x7102461568`, resolved through the relocations) has the protocol
  list `{"http", "https", NULL}`. The only `Curl_handler` tables are HTTP and
  HTTPS (`0x7102461218`, `0x71024612a0`; HTTPS has `connect_it` and `getsock`).
  No FTP, FILE, DICT, TELNET, TFTP, RTSP, IMAP, POP3, SMTP, SMB, GOPHER or LDAP
  code or string is in the binary. So all of them are `CURL_DISABLE_*`.
  Cookies, proxies (HTTP CONNECT, SOCKS4/5), digest and basic auth, `.netrc`
  and the verbose strings are in, so those aren't disabled.
- **Features `0x8c`** (`curl_version_info()`'s `features`): `SSL | LIBZ |
  ASYNCHDNS`. Without `CURL_VERSION_IPV6`, `ENABLE_IPV6` isn't defined. Without
  `LARGEFILE`, `SIZEOF_OFF_T` isn't defined, and without `UNIX_SOCKETS`,
  `USE_UNIX_SOCKETS` isn't either. `host` is `"Nintendo"` (`OS`), `age` is 3
  and `version_num` is `0x073701`.
- **TLS: Nintendo's `nn::ssl` backend.** Upstream 7.55.1 has no such backend.
  `USE_SSL` needs a backend's fields in `urldata.h`'s `struct
  ssl_connect_data` (otherwise `#error`), so it can't be defined here, and
  `vtls/` isn't vendored.
- **libz.** `curl_version()` appends `" zlib/%s"` and `content_encoding.c`'s
  strings are there, so `HAVE_LIBZ`/`HAVE_ZLIB_H`. zlib 1.2.11's headers are in
  `lib/curl/zlib`. That matters even for code that never calls zlib:
  `struct SingleRequest` holds a `z_stream`, and `struct Curl_easy`'s offsets
  depend on it.
- **Resolver: threaded.** ASYNCHDNS without c-ares (no `" c-ares/"` in
  `curl_version()`) is `asyn-thread.c` (`"Could not resolve %s: %s"`), so
  `USE_THREADS_POSIX`/`HAVE_PTHREAD_H`. The thread itself is Nintendo's
  (`nn::os`, `"LibcurlResolver"`). There are no `pthread_*` imports, so
  `curl_threads.c` isn't vendored.
- **`SIZEOF_TIME_T` undefined** (`curl_setup.h` then assumes 4).
  `curlx_tvdiff` has the `SIZEOF_TIME_T < 8` overflow check: it returns
  `0x7fffffff` when the difference is at least `0x7fffffff/1000` seconds.
  It matches only that way.
- **`bool` is one byte** (`HAVE_STDBOOL_H`, `HAVE_BOOL_T`). `Curl_open` sets
  `ssl.primary.verifypeer` and `verifyhost` with one `strh` of `0x101`. curl's
  own 4-byte `enum bool` gives other offsets.
- **curl's own `inet_pton`, `inet_ntop`, `strtok_r`, `memrchr`.** No libc
  import for any of them, and `Curl_inet_pton` (with `inet_pton4` inlined,
  `0x7101757690`), `Curl_inet_ntop`, `Curl_strtok_r` and `Curl_memrchr`
  match. So `HAVE_INET_PTON` and the others aren't defined. Neither are
  `HAVE_GMTIME_R` (`gmtime` is imported, `gmtime_r` isn't), `HAVE_GETADDRINFO`,
  `HAVE_SIGNAL` or `HAVE_GETTIMEOFDAY` (none of them is imported).
  `HAVE_STRDUP` is defined: the default `strdup` callback is a GOT load of
  `strdup`. `HAVE_POLL_FINE` is defined, because `nnsocketPoll` is imported and
  `select` isn't. `HAVE_FCNTL_O_NONBLOCK` is defined because `nnsocketFcntl`
  is imported.

How the hits grew, over the libcurl area, Sword (Shield the same):

| Configuration | Hits | Bytes |
|---|---:|---:|
| The minimal `curl_config.h`, upstream's 103 TUs | 75 | 18,812 |
| `OS "Nintendo"`, HTTP/HTTPS only, no IPv6 and no `SIZEOF_OFF_T`, libz, threaded resolver | 79 | 19,580 |
| `SIZEOF_TIME_T` undefined | 81 | 19,696 |
| `vauth/*.c` added (`vauth/digest.c`) | 83 | 20,488 |
| `HAVE_INET_PTON` undefined (final; `lib/curl`'s 55 TUs give the same) | **84** | **20,824** |

`HAVE_POLL_FINE`, `HAVE_SIGNAL` and `HAVE_STRUCT_SOCKADDR_STORAGE` don't
change the hits. They follow the imports, or musl where there's no evidence.
`SIZEOF_TIME_T 8` loses 2.

#### What doesn't match

A function matches only where Nintendo's changes don't reach it. The
differences, from the near misses (struct offsets and calls compared by hand):

- **Allocation.** curl's `malloc()`, `free()`, `realloc()`, `strdup()` and
  `calloc()` call Nintendo's wrappers directly (Sword `0x7101778330`,
  `...340`, `...350`, `...360`, `...370`). Each one tail-calls through a table
  of five pointers that `curl_global_init_mem` fills (`0x71017782f0`;
  `0x71017782a0` sets the defaults, `main`'s allocator and `strdup`).
  Upstream's `curl_memory.h` calls through the `Curl_cmalloc`, ... variables
  instead. So no function that allocates matches. `0x7101778330`'s code equals
  upstream's `sh_freeentry`, and `curl_free`'s too (a tail call through a GOT
  pointer), but it's the `malloc` wrapper, so it isn't named.
- **`struct Curl_easy`.** Nintendo's `struct UserDefined` is 0x68 bytes larger.
  `Curl_open` initialises three new byte fields right after `proxyauth` (`set`
  + `0x58`: 1, 0, 0). So `set.fdebug` is 8 bytes further on than upstream's.
  `set.dns_cache_timeout` and `set.verbose` (`0x6c8`, upstream `0x660`) are
  0x68 bytes further on, and so is every field after `set` (`state.*`,
  `info.*` ...). `sizeof(struct Curl_easy)` is `0x5140`.
- **`struct connectdata`.** It holds four `ssl_connect_data`s with the `nn::ssl`
  backend's fields, which aren't known.
- **Sockets, time, files and zlib.** Sockets go through `nnsocket*`, and
  `SOCKERRNO` through `nnsocketGetLastErrno`. `send` gets flags 0 (no
  `MSG_NOSIGNAL`) and there's no `MSG_FASTOPEN` path, unlike with musl's
  headers. The errno values are Linux's. Time comes from
  `nnosGetSystemTick`, the resolver from `nnsocketGetHostByNameWithOptions`
  and `nn::nsd::ResolveEx`. `fopen`/`fread`/`fclose` are stubs that abort.
  `ZLIB_VERSION` is `"1.2.11.f-NINTENDO-SDK-v1"`, and the zlib calls go to
  YEBIS's zlib in `main` (`inflateInit_` `0x71005918f0`, `inflateEnd`
  `0x7100593530`).

#### Names and `check.py`

The names come from `sweep_attribute.py` over the build (`build/sword` and
`build/shield`, `--source-prefix lib/curl/`), the same in both games:

- 97 functions with the same code and a pinned name, and 6 more placed by link
  order (`multi_freeamsg`, `llist_dtor`, `curl_strnequal`, ...). Of these 103,
  `check.py` confirms 100. `Curl_FormReader` calls the abort stubs,
  `Curl_unencode_deflate_write` passes the SDK's `ZLIB_VERSION`, and
  `Curl_unencode_cleanup` and `Curl_unencode_deflate_write` call YEBIS's zlib,
  whose functions aren't named yet.
- 22 pinned by the call graph (callers or callees with the same code) whose code
  differs: `Curl_hash_init`, `Curl_infof`, `Curl_setopt`, `Curl_close`, ...
- 53 identified by their string literals: a compiled function and an original
  with the same set of strings (8 characters or longer), unique on both sides.
  Examples are `Curl_http`, `Curl_SOCKS5` and `Curl_readwrite`.
- 4 identified by hand: `curl_global_init_mem`, `curl_global_cleanup`,
  `curl_easy_init` (it calls `Curl_open` and inlines `global_init`) and
  `Curl_open` (`calloc(1, 0x5140)` and the `0xc0dedbad` magic).

The 82 named functions that didn't match got status `M`. Two have matched
since: `Curl_unencode_cleanup` once YEBIS's zlib was named, and
`curl_getdate` once `include/libc`'s `errno.h` stopped declaring
`__errno_location` `const`, as the SDK's doesn't ("Protocol Buffers 3.0.0",
"The SDK's libc headers"). So 80 are `M` now. The other 209 compiled
functions have no original identified (inlined, dropped by the linker, or
changed by Nintendo too far to recognise). They're in
`data/unidentified_functions.csv`, which `check.py` skips and counts apart
from the functions known to be absent. Nintendo's glue (the allocator wrappers and
table, the `nn::ssl` backend, the `nsd`/`nifm` code, the resolver thread, the
stubs) isn't public and stays unnamed.

`check.py --update` (both games), with everything before. The 100 new
matches are libcurl's (Lua, PhysX and the rest give 8,804, as before), and the
82 that don't match are libcurl's `M` functions:

```
8904 matching, 82 not matching
(1848 compiled functions skipped as not in the executable: data/absent_functions.csv)
(209 compiled functions skipped, their original not identified yet: data/unidentified_functions.csv)
(1 weak/COMDAT functions skipped: the executable keeps another library's copy, data/foreign_copies.csv)
(311 compiled aliases of checked functions skipped, e.g. D1 = D2 destructors)
```

### zlib 1.2.11 (the `sdk` NSO)

Unmodified upstream 1.2.11, 15 TUs (114 compiled functions, 55 mapped). Every
mapped function matches with clang 7.0.x `-O3`, with or without `-g`:

| Compiler | `-O3` hits | `-O3` bytes | `-O3` avg similarity | `-O2` hits | `-Os` hits |
|---|---:|---:|---:|---:|---:|
| clang 3.9.1 | 0 | 0 | 0.564 | 0 | 0 |
| clang 4.0.1 | 2 | 396 | 0.651 | 2 | 1 |
| clang 5.0.1 / 5.0.2 | 13 | 2,668 | 0.831 | 12 | 3 |
| clang 6.0.0 / 6.0.1 | 17 | 4,020 | 0.886 | 15 | 4 |
| **clang 7.0.0 / 7.0.1 / 7.1.0** | **58** | **35,604** | **1.000** | 30 | 7 |
| clang 8.0.0 / 8.0.1 | 41 | 13,436 | 0.915 | 27 | 6 |
| clang 9.0.1 | 1 | 72 | 0.645 | 1 | 1 |
| clang 10.0.0 / 11.0.0 | 1 | 72 | 0.576 / 0.564 | 1 | 1 |

`-g0` gives the same hits for every version except clang 6.0.x (16).

### Reproducing

```sh
cd toolchain/candidates/src
curl -LO https://curl.se/download/curl-7.55.1.tar.xz && tar xJf curl-7.55.1.tar.xz curl-7.55.1/lib curl-7.55.1/include
curl -LO https://zlib.net/fossils/zlib-1.2.11.tar.gz && tar xzf zlib-1.2.11.tar.gz
cd ../../..
```

libcurl: `lib/curl` is the corpus (the vendored TUs, with the reconstructed
`lib/curl/lib/curl_config.h`):

```sh
C=toolchain/candidates; L=lib/curl
python tools/compiler_sweep.py --compiler "$C/clang-*"     --variant O3=-O3 --variant O2=-O2 --variant Os=-Os --variant O3g0="-O3 -g0"     --src "$L/lib/*.c" --src "$L/lib/vauth/*.c" --range 0x7101750ea0-0x7101779270     -- -isystem $C/sysroot/include -DHAVE_CONFIG_H -DBUILDING_LIBCURL -DCURL_STATICLIB        -I $L/include -I $L/lib -I $L/zlib
```

Shield: `--game shield --range 0x7101750f40-0x7101779310`. For the flag table,
use `--compiler $C/clang-7.0.1` and variants such as `"strict=-O3
-fstrict-aliasing"`. For the progression table, compile upstream's
`curl-7.55.1/lib/*.c` (and `lib/vauth/*.c`) against each step's
`curl_config.h`, with `-I toolchain/candidates/src/zlib-1.2.11` for `zlib.h`.
The first, minimal `curl_config.h` is the usual `HAVE_*_H` headers,
`HAVE_BOOL_T`, `HAVE_SOCKET SELECT RECV SEND STRDUP STRTOLL GETTIMEOFDAY SIGNAL
FCNTL_O_NONBLOCK INET_PTON SOCKADDR_IN6_SIN6_SCOPE_ID
STRUCT_SOCKADDR_STORAGE`, `ENABLE_IPV6`, `SIZEOF_INT 4`, `SIZEOF_SHORT 2`,
`SIZEOF_LONG`/`SIZE_T`/`TIME_T`/`OFF_T 8`, POSIX `recv`/`send` types,
`OS "aarch64-nintendo-switch"` and `CURL_DISABLE_LDAP`.

The names: build both games, then

```sh
python tools/sweep_attribute.py build/sword --source-prefix lib/curl/     --range 0x7101750ea0-0x7101779270 --game sword --out attr_sword.csv
python tools/sweep_attribute.py build/shield --source-prefix lib/curl/     --range 0x7101750f40-0x7101779310 --game shield --out attr_shield.csv
```

and take the `Name` (or the single `differs` name) that both games agree on,
except `sh_freeentry@multi` (see above).

zlib is in the `sdk` NSO, so pass `--module sdk` (the default is `main`):

```sh
Z=toolchain/candidates/src/zlib-1.2.11
python tools/compiler_sweep.py --module sdk --compiler 'toolchain/candidates/clang-*' \
    --variant O3=-O3 --variant O2=-O2 --variant Os=-Os --variant O3g0="-O3 -g0" \
    --src "$Z/[a-di-z]*.c" --src "$Z/gz*.c" \
    -- -isystem toolchain/candidates/sysroot/include
```

Without `--range` it searches the whole NSO (26,669 functions). Add `--game
shield` for Shield. `data/functions.csv` only covers `main`, so with
`--module` use `--map-out` without `--range` (both games are then searched
whole). Each libcurl configuration takes about 15 seconds, each
zlib one about 3.

### What's left open

- **NEX, Pia and the nn SDK code itself.** They aren't public. The SDK's
  libraries share one build system, so clang 7.0 `-O3` with the game's flags
  is the working assumption for all of them, but only libcurl and zlib were
  measured.
- **LZ4 (`nlib_LZ4-19_0226`).** No LZ4 code was found in `main` (see above).
- **The rest of libcurl.** The configuration is reconstructed (see
  "libcurl 7.55.1"). What's left needs Nintendo's changes to curl's own
  files (`urldata.h`, `curl_memory.h`, the `nn::ssl` backend, the socket,
  time and resolver glue), which aren't public.
- **`-g`.** Neither corpus distinguishes it.

## gflib3

**Result: gflib3, Game Freak's engine library, was built like the rest of
Game Freak's code (clang 7.0.1, the global flags), against libc++ 7.0.1's
headers and with its asserts on.** `src/gflib3` has its own
`pkmn_library_settings` entry in `CMakeLists.txt` for that. It adds libc++'s
headers (`SYSTEM_INCLUDES include/libcxx`) and the defines they need on musl
(`_GNU_SOURCE _LIBCPP_HAS_MUSL_LIBC _LIBCPP_HAS_THREAD_API_PTHREAD`, as for
`src/field/content`), and nothing else: no codegen flag differs.

- **libc++.** gflib3 calls libc++ template instantiations: all 70 of its calls
  into code after it go to instantiations like `std::__tree_balance_after_insert`
  (docs/game_code.md, "Areas"). Its memory code uses `std::atomic`: the TLSF
  pool resource's destructor (`0x710065f220`) locks with a
  `compare_exchange_strong` loop (`ldaxr`/`stxr`, acquire), waiting on a light
  event between tries, and unlocks with an `exchange(nullptr, release)`
  (`ldxr`/`stlxr`). Compiled with libc++ 7.0.1's `<atomic>` it matches in both
  games, and so does an acquire `load` of an `atomic<bool>` (`0x71005cf850`).
- **Asserts on, so no `NDEBUG`.** The `__FILE__` and `__func__` strings of
  gflib3's asserts are in `main` (`lib/gflib3/src/mem/internal/tlsf_pool.cpp`
  with `deactivate`, `mem/tlsf_pool_resource.cpp` with `do_dump_no_lock`).

With this entry, the 31 functions of `src/gflib3` match in both games.

## Codegen fingerprints

`tools/fingerprint.py` counts compiler idioms over an address range, per game,
without any source code. Its docstring defines every metric exactly. A
function belongs to a range when its start address is in it, and only its own
instructions are scanned. Targets are `data/areas.csv` names or
`label=LO-HI[,SHLO-SHHI]` (Sword, then optionally Shield). Without a Shield
range, the tool reads the area's Shield columns (when `areas.csv` has them) or
pairs the Sword range with Shield through `data/functions.csv`.

```sh
python tools/fingerprint.py --game sword physx wwise yebis=0x710040f550-0x7100596d20 \
    game=0x7100596d20-0x7101548410 lua=0x7101548410-0x7101570900 middleware --typeinfo PPFX
```

(`yebis` and `game` are explicit because `data/areas.csv` still has the old
boundary `0x71005a0000`.) Sword:

| Metric | PhysX | Wwise | YEBIS | Game code | Lua | After Lua |
|---|---:|---:|---:|---:|---:|---:|
| `functions` | 8,247 | 4,179 | 5,002 | 74,892 | 517 | 10,848 |
| `calling` | 4,974 | 2,609 | 3,014 | 43,978 | 432 | 6,758 |
| `frame_pointer` | 4,974 | 2,609 | 3,014 | 43,978 | 432 | 6,758 |
| `orr_wzr` | 11,601 | 5,681 | 9,677 | 90,457 | 1,559 | 15,358 |
| `movz_logical` | 28 | 28 | 78 | 161 | 12 | 380 |
| `movi_zero` | 432 | 8 | 2 | 703 | 0 | 116 |
| `stp_xzr` | 1,645 | 1,044 | 4,931 | 37,688 | 27 | 2,855 |
| `stp_xzr_pairs` | 198 | 89 | 1,160 | 17,946 | 12 | 1,120 |
| `stp_q` | 1,286 | 163 | 52 | 804 | 12 | 242 |
| `ldp_stp_x` | 13 | 343 | 364 | 3,748 | 78 | 405 |
| `ldr_str_q` | 56 | 9 | 0 | 155 | 0 | 27 |
| `g_ldr_pairs` | 5 | 0 | 0 | 62 | 3 | 1 |
| `g_ldr_pairs_desc` | 0 | 11 | 0 | 1 | 0 | 0 |
| `g_ldp_base` | 158 | 40 | 250 | 1,339 | 40 | 868 |
| `and_shift` | 1 | 11 | 0 | 0 | 0 | 0 |
| `and_shift_funcs` | 1 | 7 | 0 | 0 | 0 | 0 |
| `fde_zPLR` | 1,280 | 0 | 0 | 0 | 0 | 1 |
| `fde_zR` | 6,967 | 4,179 | 5,002 | 74,892 | 517 | 10,846 |
| `typeinfo_PPFX` (module-wide) | 47 | | | | | |

Without `--game sword` (both games), Shield gives the same figures except
`orr_wzr` in game code (90,461). The Shield ranges are
`0x7100596d20`-`0x71015484b0` (game code) and `0x71015484b0`-`0x71015709a0`
(Lua); add them after a comma. The rest pair through `functions.csv`.

What separates the regions:

- **clang ≤ 8 vs ≥ 9:** `orr_wzr` against `movz_logical`. Every region is
  overwhelmingly `orr`, so nothing here was built with clang 9 or later.
- **clang 6 vs 7:** `and_shift` (only Wwise and one PhysX function), and the
  sweeps above. It depends on the source, so its absence proves nothing.
- **`-fexceptions`:** `fde_zPLR` (PhysX only, plus one FDE after Lua).
- **Frame pointers:** `frame_pointer` equals `calling` everywhere.
- **Implicit float:** `movi_zero` and `ldr_str_q` stay small next to
  `stp_xzr` and `ldp_stp_x`. PhysX's 432 `movi` and 1,286 `stp q` are its
  explicit SIMD math.
- **`-g`:** `g_ldr_pairs` against `g_ldp_base` (low confidence, see "Debug
  info" and Wwise).
