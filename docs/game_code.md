# Game Freak code

Notes on the parts of `main` that Game Freak wrote or vendored into its own
build: how `data/areas.csv` splits them, and how the undecompiled functions
break down. Addresses are Sword's. All of these areas start at the same
addresses in Shield, so the figures hold for both games.

## Areas

Game Freak's build tree has two halves, `RomBuild/program/lib/` (its
libraries) and `RomBuild/program/prog/` (the game). The `__FILE__` strings of
asserts and generated protobuf code spell them out. The libraries come first
in link order:

| Area | Range | Functions | Evidence |
|---|---|---:|---|
| `gflib3` | `0x7100596d20`-`0x710069d6e0` | 4,587 | `lib/gflib3/src/mem/...` source paths, heap names (`GlobalHeap`, `DebugHeap`), FileManager, render paths and shaders, movie player, hid |
| `gflnet3` | `0x710069d6e0`-`0x71006dea00` | 1,521 | `lib/gflnet3/src/p2p/...` source paths (its protobuf messages), bcat, nifm, Pia sessions, an HTTP thread on libcurl |
| `protobuf` | `0x71006dea00`-`0x7100761f70` | 1,622 | Protocol Buffers **3.0.0**, from `lib/gflnet3/external/include/google/protobuf/*.cc` |
| `game/...` | `0x7100761f70`-`0x7101548410` | 67,162 | everything from `prog/`, starting with pml (`bin/pml/...` loaders). Split into subsystems below |

How the boundaries were placed:

- **Static initialisers end their TU.** clang emits a TU's
  `_GLOBAL__sub_I_*` after all of the TU's other functions, so each
  `.init_array` entry (1,509 of them, in link order) marks the last
  function of a TU. The `.init_array` is the run of `R_AARCH64_RELATIVE`
  slots around `0x71024b7710`.
- **gflib3 → gflnet3.** Every static initialiser from `0x710069f610` to
  `0x71006de980` calls into `nn::ldn`, through a header the network code
  includes. Before that point none does. The boundary is the function after
  `0x710069d6a0`, the last initialiser without `nn::ldn`. The first direct
  calls into Pia come after it (`0x71006a2a40`).
- **gflnet3 → protobuf.** `0x71006de980`, a static initialiser of colour
  constants, ends the last gflnet3 TU. From `0x71006dea00` on, every
  function is called only from protobuf or from generated `*.pb.cc` code.
- **protobuf → game.** `0x7100761c20` (`strings::Substitute`) is the last
  protobuf function. `0x7100761f70` is a game size check, and the pml
  accessors that follow are called from all over the game.
- **Layering.** gflib3 calls nothing in gflnet3 or protobuf, and protobuf
  calls nothing after itself. Protobuf's calls back into gflnet3 all go to
  linkonce functions that the linker kept from a gflnet3 TU:
  `std::__tree_balance_after_insert` (`0x71006a54a0`, libc++) and
  protobuf's own inline
  `InternalMetadataWithArena::mutable_unknown_fields_slow` (`0x71006bd410`,
  66 calls, from the generated messages' Merge functions). gflnet3's own
  generated messages emit them first. gflib3's 70 calls into later code all
  go to instantiations like that (libc++, sol2).
- **Protobuf's version.** Each generated message's `AddDescriptors` calls
  `VerifyVersion` (`0x71006ff450`) with `3000000`, i.e. 3.0.0. It's vendored
  in `lib/protobuf`, and all of the area's 1,622 functions match
  (docs/compiler.md, "Protocol Buffers 3.0.0").

**Game Freak code has no RTTI.** The 1,264 typeinfo objects in `main` all
belong to the nn SDK (829), YEBIS (`SiSDK3` 349, `PPFX` 46), `pead` (34) and a
few libc++/NEX templates. None of the 2,218 vtables that have one is a Game
Freak class. So class names can't come from typeinfo. Vtables still exist,
with a null typeinfo slot.

## Subsystems

The `prog/` code (`0x7100761f70`-`0x7101548410`, 67,162 functions) is split
into rows named `game/<subsystem>`, and `game/unk_<address>` for the stretches
between them that aren't placed yet. `--area game` (`funcs.py`,
`fingerprint.py`, `segments.py`) still covers all of it.

Strings alone can't do this. Only 3,879 of these functions reference a string,
`__FILE__` paths appear only in the generated protobuf code, and resource
paths are referenced from all over (every app loads the common fonts and
message windows, and several load another app's layouts). Two more kinds of
evidence make it work:

- **Segments.** clang emits a TU's static initialiser after the TU's other
  functions, so each `.init_array` entry ends a TU. `tools/segments.py`
  splits code at those entries: 1,089 segments in `prog/`, the same in both
  games. A segment is one or more whole TUs, so a boundary between two
  segments can't split a TU. Every boundary below is one. Many of Game
  Freak's TUs have an initialiser: the box app's states, for example, are a
  segment of about 13 functions each (`View_Top` and the state's name).
- **Names and calls.** The generated protobuf TUs are named (see
  "Generated protobuf messages" in docs/compiler.md), each between two
  initialisers, and their namespaces say which `prog/` directory they're
  from. Their callers are the subsystem's own code. `segments.py` lists each
  segment's named namespaces (`own`) and the named namespaces it calls.

A row is a run of segments in which every segment that references anything
names the subsystem: its `.pb.cc` namespace, calls into it, its layouts
(`bin/appli/<app>/...`), its state and view names (`BagStateStart`,
`StateBtlSpotTop`, `PokeStatusInfoView`), sound events or message labels.
Strings that six or more segments reference (fonts, `CommonOptionBar`,
`anime_in`, the shared skybox and PC-door models) don't count either way.
A segment at either end that also holds another subsystem's code stays out
of the row, even when the subsystem starts inside it: the boundary can only
go between segments. The `Evidence` column of each row says what it found.

| Area | Sword | Functions | Evidence |
|---|---|---:|---|
| `game/bag` | `0x710079d210`-`0x71007bf610` | 610 | `bin/appli/bag`, `BagState*`/`BagView*` in all 3 segments. The bag's first functions (from `0x71007952f0`) share a segment with Wwise bank and font setup |
| `game/battle_logic` | `0x7100891a20`-`0x71008bf520` | 1,487 | 20 `.pb.cc` TUs (`btl::net`, `source/net` and `source/netwatch`), the segments between them, and 2 before them that only call `btl::net` |
| `game/pokebox` | `0x7100a77140`-`0x7100ab9140` | 995 | `common/box.dat`, the box's views, one segment per box state (`boxtray_in`, `pokeicon_get`, `wallpaper`, ...), `bin/appli/pokebox` |
| `game/btl_spot` | `0x7100ac15f0`-`0x7100b2b110` | 2,422 | 2 `.pb.cc` TUs (`contents::btl_spot`), `bin/appli/btl_spot`, `StateBtlSpot*`/`ViewBtlSpot*` in 20 of 21 segments |
| `game/comp_organize` | `0x7100ba5d90`-`0x7100bba3d0` | 394 | 3 `.pb.cc` TUs (`ontents::comp_organize`, Game Freak's spelling) and the competition app before them, which calls them |
| `game/net_contents/live` | `0x7100fe3340`-`0x7100ff22f0` | 398 | `.pb.cc` TUs of `battle/live` and `battle/poke_select` (`net_contents::battle`) and the segment that calls them |
| `game/net_contents/nbr` | `0x7100ff91e0`-`0x71010431f0` | 1,950 | `.pb.cc` TUs of `battle/nbr`, `nesthole`, `trade/box`, `trade/common`, the segments between them and the one before them (105 calls into `net_contents::battle`) |
| `game/pokecamp` | `0x7101114050`-`0x7101290e40` | 7,311 | 6 `.pb.cc` TUs (`contents::pokecamp`) and 102 segments around them: 56 name camp things (`Play_Camp_*`, `msg_pokecamp_*`, `bin/appli/pokecamp*`, curry and cooking), the other evidenced ones are camp scenes (tent, ball throw, greetings, the ingredient bag) |
| `game/status` | `0x71012ca770`-`0x71012ed1a0` | 469 | `common/status.dat`, `PokeStatus*`, `bin/appli/status` in 16 of 17 segments |
| `game/pokedex` | `0x710151bfb0`-`0x7101548410` | 845 | `bin/appli/pokedex`, `ZKN_*` labels; the segment before starts with `xmenu_net` |

Shield's boundaries are the same functions (from `game/net_contents/live` on,
`0x30` later; the end is Lua's start, `0x71015484b0`). The confidence is
medium: inside a row every evidenced segment names the subsystem, but the
subsystem can extend past it into a mixed or silent segment, and a silent
segment inside a row (no strings, no names, no calls) is assumed to belong.

`net_contents` is two rows because the 5 segments between them
(`0x7100ff22f0`-`0x7100ff91e0`) reference `Play_UI_common_report` and
`gpoke` and nothing of `net_contents`. They may well be its code, but nothing
says so.

What isn't placed yet (the 10 `game/unk_*` rows, 50,281 functions) needs the same kind of
evidence. `segments.py game/unk_bba3d0 --grep <pattern>` finds the segments
that name a candidate, and the runs above came from exactly that. Clear
candidates with fewer or less uniform segments are the battle app
(`bin/appli/battle`), xmenu, the live tournament, mystery gift, the trainer
license apps and the Poké Job (`pw`) app.

## The tiny functions

`tools/funcs.py patterns` groups functions by instruction pattern (immediates
as `#N`, branch targets as `T`) and by how they're reached:

```sh
python tools/funcs.py patterns --area game --status U --max 8
```

Before the first batch, gflib3, gflnet3 and game had 17,476 undecompiled
functions of at most 8 bytes:

| Reached through | Functions | What they are |
|---|---:|---|
| a pointer in `.data` | 13,686 | almost all vtable entries: virtual functions |
| B/BL only | 1,739 | ordinary out-of-line functions |
| neither | 2,051 | address taken in code (callbacks, sol2/`std::function` tables) or unused; 1,959 of them are a bare `ret` |

The biggest patterns:

| Pattern | Functions | Notes |
|---|---:|---|
| `ret` | 4,864 | empty functions: 2,811 in vtables (empty virtual overrides, trivial virtual destructors) |
| `sub x0, x0, #N ; b T` | 4,338 | all in vtables: the compiler's `this`-adjusting thunks (`_ZThn<N>_...`) for overrides in a secondary base |
| `b T` | 4,295 | 4,221 in vtables: virtual functions that forward to another function |
| `mov w0, #N ; ret` | 794 | 765 in vtables: virtual functions returning a constant (type IDs, flags) |
| `ldr x0, [x0, #N] ; ret` | 563 | getters, 414 called directly |
| `ldr x0, [x0, #N] ; b T` | 421 | forward a member to another function |

So most tiny functions can't be decompiled one at a time. A virtual
function's name and signature come from the class it belongs to, and a thunk
is emitted only along with its class and override. Those wait until vtables
are reconstructed into classes. Without RTTI, that means grouping functions
by the vtables that hold them.

### Batch 1: directly called leaf functions

The 1,215 functions that are called only through B/BL, are `common`, and are
one of these leaf patterns are written as placeholder code in
`src/unsorted/leaf/`:

| Kind | Pattern | Source | Functions |
|---|---|---|---:|
| getter | `ldr{,b,h} w0 / ldr x0 / ldr s0, [x0, #N] ; ret` | `return self->field_N;` | 798 |
| field address | `add x0, x0, #N ; ret` | `return &self->field_N;` | 132 |
| setter | `str{,b,h} w1 / str x1 / str s0, [x0, #N] ; ret` | `self->field_N = value;` | 131 |
| empty | `ret` | `{}` | 73 |
| clear | `str{,b,h} wzr / str xzr, [x0, #N] ; ret` | `self->field_N = 0;` | 70 |
| constant | `mov w0, #N` / `mov w0, wzr` / `mov x0, xzr ; ret` | `return N;` | 11 |

Each function gets its own placeholder struct (`Unk_<addr>`, with a
`field_<offset>` and an offset assert), because nothing yet says which ones
share a class. The field types follow the access width only: `u8`/`u16`/`u32`/`u64`
or `f32`, unsigned, pointers as `u64`, `bool` as `u8`. Functions between two
static initialisers share a file, named after the first one. Such a range
holds one or more whole TUs, because an initialiser is always the last
function of its TU. When a class is identified,
move its accessors next to it and give them real types.

### Batch 2: straight-line leaf functions (`tools/leafgen.py`)

Batch 1's six patterns leave a long tail: 1,165 directly called, common
leaf functions of at most 32 bytes in 667 patterns. `tools/leafgen.py`
lifts them instead of matching patterns. It executes a function's
instructions symbolically (loads and stores through the argument
registers, constants, masks, shifts, compares, `cset`/`csel`, `ubfx`,
`bfi`/`bfxil`) and writes C++ that computes the same thing:

| Kind | Functions | Example |
|---|---:|---|
| `set` | 269 | `self->field_20 = value;` (a `bool` when clang masks the argument with `& 1`), constant stores, several fields, nested `self->field_8->field_30 = 1;`, float arguments |
| `check` | 163 | `return self->field_10 == 3;`, flag tests `(self->field_8 & 0x10) == 0`, null tests, range checks `x >= 5 && x <= 7` (clang's `(x - 5) < 3`), signed compares (the field becomes `s32`) |
| `get` | 129 | nested getters `self->field_8->field_30`, bitfields `(self->field_c >> 3) & 1`, constants |
| `update` | 2 | read-modify-write of a field that also returns a value |

They match in both games: 510 in game code, 46 in gflib3 and 7 in gflnet3.
Each function gets placeholder structs like batch 1's: `Unk_<addr>` for
the first argument, `Unk_<addr>_<offset>` for a pointer loaded from it,
`Unk_<addr>_arg<n>` for other pointer arguments, fields typed by access
width and signedness. A pointer argument that is only read is `const`. The
functions go into batch 1's per-segment files (`leafgen.py` merges them in
address order and renames a file when its first function changes).

What it lifts is a guess at the spelling, not at the meaning. Anything it
doesn't model is refused: branches and calls, references to globals,
`ldp`/`stp`, multiplies, address arithmetic, pointer compares other than
null tests, 64-bit arithmetic that C would do in `int`. The C++ then has to
compile alone with `-Wall -Wextra -Werror`, because a wrong type guess under
C's integer promotions shows up as a warning (a tautological compare, a
shift past the type's width). Of 614 that compiled, 563 match. The other 51
differ in instruction order or register choice. That comes from how the
source was written (a reset followed by a copy, a 16-byte struct returned in
`x0`/`x1`), so they were dropped, not patched.

```sh
python tools/leafgen.py scan --max 32                 # candidates, lifted, refused (by reason)
python tools/leafgen.py write --max 32                # into src/unsorted/leaf
cmake --build --preset sword && cmake --build --preset shield
python tools/leafgen.py names --out map.csv           # the mangled names the build defined
python tools/funcs.py name --from-file map.csv
python tools/check.py --no-build > check.log          # its OK lines are the ones to keep
# Restore src/unsorted/leaf and data/functions.csv (git checkout, git clean), then:
python tools/leafgen.py write --max 32 --only ok.txt  # the OK addresses, one per line
python tools/funcs.py name --from-file ok_map.csv     # map.csv's rows for them
python tools/check.py --update
```

## Vtables and classes (`tools/vtables.py`)

Most of the tiny functions are virtual (see "The tiny functions"), and
without RTTI their classes can only come from the vtables. `tools/vtables.py`
finds them. With the Itanium ABI a vtable is an offset-to-top word, a
typeinfo word (0 with `-fno-rtti`) and then one function pointer per slot:
`R_AARCH64_RELATIVE` relocations to function starts, or
`__cxa_pure_virtual`. The address point an object's vptr holds is slot 0. A
run of such slots after that header is a vtable. A run that follows another
directly, with a negative offset-to-top, is a secondary vtable of the same
class (one per secondary base). Function-pointer runs without the header are
plain tables.

| | Whole `main` | Game code (`game/...`) | gflib3 |
|---|---:|---:|---:|
| vtables (the same in Shield) | 10,123 | 7,322 | 607 |
| groups (classes with a vtable) | 5,584 | 3,425 | 342 |
| secondary vtables | 4,539 | 4,000 | 277 |
| with typeinfo | 1,129 | 5 | 2 |
| without a referrer | 66 | 10 | 2 |

**Referrers** are the functions that reference a vtable: its class's
constructors and destructors. Game code loads the `_ZTV` symbol from the GOT
and adds 16 to get the address point. A secondary vtable is reached from
the same `_ZTV`, so its referrers are its group's.

**Owners.** A derived class's vtable starts with its base's slots, and every
slot it doesn't override holds the base's function. So the same function
appears in several vtables, and the shortest of them is the best guess at
the class that defines it. That is the function's owner, and only owned
functions are written as members of a class. `vtables.py show <vtable>`
marks inherited slots with the vtable they come from.

**Bases.** `show` and `csv` also guess each class's base: the other, no
longer, vtable that holds the most of the same functions at the same
indices. Destructors are strong evidence. Clang emits an empty destructor
that only destroys its base as an alias of the base's D2, so a derived
class's slot 0 is its base's D2. 539 game classes with an empty destructor
pair show this. Their own D0 (`b operator delete`) can be matched once the
placeholder classes have those bases (`class D : public B`, with `B`'s
destructor inline), which this tool doesn't write yet.

### Batch 3: simple virtual functions

`vtables.py write` declares a placeholder class per vtable that owns
something simple. The class is named `Unk_<address of its _ZTV>`, so it
lines up with the vtable symbol once that is named. Its virtual functions
are declared in slot order (`vf<slot>`, `= 0` where the slot is
`__cxa_pure_virtual`, a destructor for slots 0 and 1 when they are a
destructor pair). The simple functions it owns are defined:

| Kind | Functions | Source |
|---|---:|---|
| empty override | 1,726 | `void Unk_2418848::vf6() {}` |
| constant | 721 | `u32 vf3() { return 1; }`, `return 0;`, `void* vf5() { return nullptr; }` |
| empty destructor | 202 (101 pairs) | `Unk_X::~Unk_X() {}`: D2 is `ret`, D0 tail-calls `operator delete(void*)`, or traps for an abstract class |

That's 2,649 functions in 1,541 classes, all common, and all of them match in
both games. The return types (`void`, `u32`, `void*`) and the empty
parameter lists are placeholders. A function's mangled name doesn't include
its return type, but it does include its parameters, so give a function its
real signature (and rename it with `funcs.py name --force`) when its class
is known. Like the leaf batches, one file holds the functions between two
static initialisers (`src/unsorted/virtual/Unk_<first>.cpp`). A class with
functions in several such runs is declared, identically, in each file.

Not written yet, and the next steps:

- **Thunks** (4,060 in game code: `sub x0, x0, #N ; b T`). The compiler
  emits one with the override it adjusts for, so the class needs its
  secondary bases at the right offsets (the offset-to-top of its secondary
  vtables).
- **Derived destructors** (the 539 above), with the base guess.
- **Forwarders** (`b T`, 3,899) and small getters and setters (877). They
  need the callee's name, or fields in the class. `tools/leafgen.py`'s lifter
  can produce the latter as member functions.

```sh
python tools/vtables.py summary --area game
python tools/vtables.py show 0x7102418858            # a vtable group: slots, owners, base guess, referrers
python tools/vtables.py write --names map.csv        # into src/unsorted/virtual (Sword's vtables)
python tools/funcs.py name --from-file map.csv
python tools/check.py --update
```
