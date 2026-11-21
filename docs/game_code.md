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
| `game/battle_engine` | `0x71007c2d80`-`0x710082e410` | 2,802 | low confidence: 4 of its 49 segments have strings, all battle ones (effect sequences `ee501`..., battle BGM labels, `bin/battle/talk`, battle event labels `INEFFECTIVE_SKILL`, `BATTLE_DAIMAX`) |
| `game/battle_logic` | `0x7100891a20`-`0x71008bf520` | 1,487 | 20 `.pb.cc` TUs (`btl::net`, `source/net` and `source/netwatch`), the segments between them, and 2 before them that only call `btl::net` |
| `game/battle_app` | `0x71008ede90`-`0x710095b4b0` | 1,480 | `bin/appli/battle` layouts, `TopView`, `BossView`, `WazaSelectSubView`, `RaidResultView`, ... in 50 of 60 segments |
| `game/battle_scene` | `0x710095b4b0`-`0x7100a6e240` | 2,930 | `bin/battle/waza` particles, models and `.bseq` sequences, battle cameras, battle motions (`to_ba10_waitA01`), `Play_PV_Btl_*`, in all 7 segments |
| `game/blacklist` | `0x7100a6e240`-`0x7100a77140` | 177 | `common/blacklist.dat`, `bin/appli/blacklist` |
| `game/pokebox` | `0x7100a77140`-`0x7100ab9140` | 995 | `common/box.dat`, the box's views, one segment per box state (`boxtray_in`, `pokeicon_get`, `wallpaper`, ...), `bin/appli/pokebox` |
| `game/btl_spot` | `0x7100ac15f0`-`0x7100b2b110` | 2,422 | 2 `.pb.cc` TUs (`contents::btl_spot`), `bin/appli/btl_spot`, `StateBtlSpot*`/`ViewBtlSpot*` in 20 of 21 segments |
| `game/comp_organize` | `0x7100ba5d90`-`0x7100bba3d0` | 394 | 3 `.pb.cc` TUs (`ontents::comp_organize`, Game Freak's spelling) and the competition app before them, which calls them |
| `game/xmenu` | `0x7100e63560`-`0x7100e66990` | 66 | `FieldMenuRotomView`, `bin/appli/xmenu` in both segments; the one before (`FieldMenuView`) also holds nest-hole effects |
| `game/live_comm` | `0x7100f1fc50`-`0x7100f3b120` | 376 | Y-Comm: `common/live_comm.dat`, `LiveCommState*`/`LiveCommView*`, `bin/appli/live_comm` in all 10 segments |
| `game/live_tournament` | `0x7100f3d7e0`-`0x7100f590c0` | 497 | `common/live_tournament.dat`, `bin/appli/live_tournament`, its views, in all 11 segments |
| `game/mystery` | `0x7100f590c0`-`0x7100f97380` | 1,224 | Mystery Gift: `bin/appli/mystery`, `StateReceive*`, `sd9150_mysterygift`, in all 11 segments |
| `game/nesthole` | `0x7100f97380`-`0x7100fb2de0` | 733 | Max Raid dens: `common/nest.dat`, `View_NestHole`, `Play_UI_Gnest_*`, host/guest states, in 9 of 15 segments |
| `game/net_btl` | `0x7100fc5de0`-`0x7100fd7eb0` | 591 | link battles: `common/net_btl.dat`, `ViewNetBtl*`, `bin/appli/net_btl`, in all 3 segments |
| `game/net_contents/live` | `0x7100fe3340`-`0x7100ff22f0` | 398 | `.pb.cc` TUs of `battle/live` and `battle/poke_select` (`net_contents::battle`) and the segment that calls them |
| `game/net_contents/nbr` | `0x7100ff91e0`-`0x71010431f0` | 1,950 | `.pb.cc` TUs of `battle/nbr`, `nesthole`, `trade/box`, `trade/common`, the segments between them and the one before them (105 calls into `net_contents::battle`) |
| `game/net_request` | `0x710107beb0`-`0x7101104c80` | 3,741 | low confidence: `Request*` names (`RequestUploadCompetitionTeam`, `RequestSerialAuth`, `RequestPokemonValidation`, ...), the serial-code and validation URLs, in 14 of 86 segments |
| `game/pokecamp` | `0x7101114050`-`0x7101290e40` | 7,311 | 6 `.pb.cc` TUs (`contents::pokecamp`) and 102 segments around them: 56 name camp things (`Play_Camp_*`, `msg_pokecamp_*`, `bin/appli/pokecamp*`, curry and cooking), the other evidenced ones are camp scenes (tent, ball throw, greetings, the ingredient bag) |
| `game/pw` | `0x710129e040`-`0x71012b7bf0` | 457 | Poké Jobs: the job table's fields (`jobList`, `company_txt`), `sd8030_pokejob`, `bin/appli/pw`, in 10 of 12 segments |
| `game/pokelist` | `0x71012b7bf0`-`0x71012c9b90` | 261 | `common/pokelist.dat`, `PokeListView*`, `bin/appli/pokelist` |
| `game/status` | `0x71012ca770`-`0x71012ed1a0` | 469 | `common/status.dat`, `PokeStatus*`, `bin/appli/status` in 16 of 17 segments |
| `game/regulation` | `0x7101320670`-`0x7101323a60` | 76 | `bin/appli/regulation`, `ViewProgress` |
| `game/rental_team` | `0x7101323a60`-`0x710133d350` | 593 | `common/rental_team.dat`, `UploadTeamView`/`DownloadTeamView`, `StateSelectBattleTeam`, in all 6 segments |
| `game/btlteam_select` | `0x710142d4a0`-`0x710143a7a0` | 265 | `common/btl_team.dat`, `ViewTeamSelect`, `bin/appli/btlteam_select` |
| `game/trainer_license` | `0x7101455520`-`0x71014b14a0` | 1,903 | League Cards: `common/trainer_license*.dat`, `bin/appli/trlicense_album`, `ViewCard`, `StateAlbumList`, ... in all 12 segments |
| `game/waza_remember` | `0x7101507290`-`0x71015106d0` | 153 | move reminder: `common/waza_remember.dat`, `WazaRemenberView` (sic), in both segments |
| `game/xmenu_net` | `0x71015106d0`-`0x7101514310` | 48 | `common/xmenu_net.dat` |
| `game/pokedex` | `0x710151bfb0`-`0x7101548410` | 845 | `bin/appli/pokedex`, `ZKN_*` labels; the segment before starts with `xmenu_net` |

Shield's boundaries are the same functions, at its own addresses (the
`ShieldStart`/`ShieldEnd` columns; from `game/xmenu` on they are `0x30` to
`0xa0` later). The confidence is medium: inside a row every evidenced
segment names the subsystem, but the subsystem can extend past it into a
mixed or silent segment, and a silent segment inside a row (no strings, no
names, no calls) is assumed to belong. `battle_engine` and `net_request` are
low: most of their segments are silent.

Rows end at their last evidenced segment, and a segment that also holds
another subsystem's code stays out even when the subsystem plainly goes on
inside it. That is why the battle tower app (its segment also registers
the battle app's views), the report app (its segment also sets the option
volumes), the shop (its segment also holds the credits) and the League
Card renderer (after a segment that loads every language's message windows)
aren't rows. The `unk_*` row before `battle_logic` (`0x710082e410`) is about
200 segments of 4 to 6 functions, each TU with its own static initialiser,
and no strings at all: probably battle code too, but nothing says so.
Most of those segments are one class each on `Unk_23acc98` (the base whose
constructor is `0x710082a930`): its constructor, one or more functions that
take the object, a result (8 bytes: a flag and a value) and a parameter
block, its D0, and the colour constants' static initialiser every TU of
this kind has. `Unk_7e0080` holds all 239 of these objects
(`0x710081c630` creates them) and the functions call each other through it
(`src/unsorted/unk_82e410/Handler.h`). Their callees are the battle
engine's accessors (`0x71007ee6b0`, the battler's byte at `0x7d`, and the
like), so it is battle code, but which part is still unnamed.

`game/unk_8bf520` starts with a table of 129 conditions (`0x71023bad58`,
in the segment `0x71008c26c0`-`0x71008c6550`): each takes a context and an
array of 64-bit arguments and returns a flag or a number. They roll the
battle's xoroshiro128+ generator (`0x71007f8c20`, `random(256) < n`),
compare the battlers' types (three 5-bit fields), stats and move
effectiveness, and look through the party: likely the trainer AI's
conditions, though nothing names them
(`src/unsorted/unk_8bf520/Unk_8c26c0.cpp`).

`net_contents` is two rows because the 5 segments between them
(`0x7100ff22f0`-`0x7100ff91e0`) reference `Play_UI_common_report` and
`gpoke` and nothing of `net_contents`. They may well be its code, but nothing
says so.

What isn't placed yet (the 21 `game/unk_*` rows, 31,908 functions) needs the
same kind of evidence. `segments.py game/unk_bba3d0 --grep <pattern>` finds
the segments that name a candidate, and the runs above came from exactly
that. The biggest unplaced rows are `game/unk_bba3d0` (11,053 functions:
demos, field, script events, weather) and `game/unk_133d350` (4,505: the
report app, flags and works, scripts, cut scenes); both are a mix of field
code whose strings rarely name one subsystem.

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

### Batch 7: tail-call wrappers (`leafgen.py`, again)

Most directly called functions of at most 32 bytes that `leafgen.py`
refused (944 of 2,047) don't end in `ret`: they end in a tail call `b T`.
The lifter now takes those too. It runs the function up to the branch and
writes the call with the argument registers it left: up to the last one it
wrote, passing on the ones before it unchanged, so
`ldr x0, [x0, #8] ; b T` is `Unk_<T>(self->field_8);`. T is declared
`void Unk_<T>(...)` with `void*` for pointers, so that its name doesn't
depend on its callers' placeholder structs, and named `_Z<n>Unk_<T><params>`.
A caller is left out when T is in a table (a virtual function), already has
another name, is lifted itself, or is called with other parameter types by
another caller.

Of the 449 that compiled cleanly, 430 match in both games: game code,
gflib3 and gflnet3. Their 357 callees are named and stay undecompiled.
The others pass an argument with another width than the guess (a `u64`
where the original moves a 32-bit register) and were left out with
`--only`. check.py: 24,299 matching (23,869 before), 106 not matching.

The same lifter writes virtual functions as members (batch 4's
accessors): `vtables.py write` now takes those that end in a tail call
too, with `this` for a passed-on `self`, and declares their targets the
same way, unless a target is a virtual function, already has another name,
or is called with other types (forwarders call theirs with one `void*`).
269 match in both games (check.py: 24,568 matching, 106 not matching).

Virtual functions that return a string literal
(`adrp x0, S ; add x0, x0, S ; ret`) are written as `return "...";`:
check.py compares literals by their contents. 51 match, among them layout
paths and session state names. The commonest function that addresses
data, 215 of them, stores a vtable and one captured word into the caller's
buffer: libc++'s `std::function` `__clone(p)` for lambdas whose types aren't
known, left alone.

The lifter also takes `ldp`/`stp` (two loads or stores of adjacent
fields; `sp` and writeback forms, a frame, are still refused), and
functions up to 64 bytes: 68 more match. Most of the others that compile
read a field after the function stored to it, which the lifter doesn't
model; they compile to other code and are left out.

Globals too: `adrp x8, P ; ldr x8, [x8, #lo]` loads a GOT slot, the address
of a global another TU defines, and the lifter reads and writes it as an
`extern <type> Unk_<addr>;` (at offset 0 only: a field of a global is still
refused). 20 more match: 9 getters and 5 setters of a global, and 6 tail
calls that pass one on (check.py: 24,714 matching, 106 not matching).
`vtables.py write` lifts them in virtual functions too, along with members
that use no argument at all (`this` included). 131 more match: they
increment, reset or test a global, or pass one to a tail-called function
(check.py: 24,845 matching).
`check.py --record-data` puts the globals in `data/data_symbols.csv`, so
every reference to one is checked against the same address.

One branch is allowed too: a `cbz`/`cbnz` that skips the rest of the
function, to its final `ret` (`if (x != 0) { ... }`) or to a
`mov w0, wzr ; ret` after the path's own `ret` (`if (x == nullptr) return
0; return ...;`). It has to test a field or an argument before any store.
Commonest are a null-checked tail call and a getter through a pointer that
may be null. 119 more leaf functions match (check.py: 24,964 matching), and
53 more virtual ones, which `vtables.py write` lifts the same way
(check.py: 25,017 matching, 107 not matching).

Wide constants (`mov` then `movk` for each further 16 bits) are constants
too: 18 more leaf functions and 5 virtual ones match (check.py: 25,040
matching, 107 not matching).

A tail call to a leaf function already written (and matched) uses that
function's own prototype, from its source (`known_prototypes`: only where it
mangles to the name in functions.csv): what's passed to a pointer parameter
gets its type, so a field becomes an `Unk_<T>*` with `struct Unk_<T>;`
declared, and the other arguments have to match. 28 more leaf functions
match (check.py: 25,386 matching, 107 not matching).

Callers of one placeholder that write fewer argument registers than
another, with the same types otherwise, pass the rest on as they got them,
so they say so (`unify_arity`): `Unk_<T>(self->field_8, value);`, `value`
typed as the longest caller has it. 18 more match (check.py: 25,404
matching, 107 not matching).

The guard's other path may return any constant (`mov w0, #N ; ret`), and
stores before it are done either way, so they go before the `if`. 12 more
leaf functions and 12 virtual ones match (check.py: 25,428 matching, 107
not matching).

`startup` (`nnMain` and the allocator overrides, game code in
`data/areas.csv`) is in both tools' default areas now: 37 more virtual
functions match, of classes whose vtables are mostly its (check.py: 25,465
matching).

A derived class (Batch 4) used to lose its lifted members: their fields
would have to follow its base's. But a field is at the same offset of the
object whichever class declares it, so they go to the base's fields now
(`_readd_lifted`), when they don't conflict with the base's own, and an
override's signature to the base's family, when it has no other. A field
may point to a placeholder struct (the base declares it, named after
itself); a member whose return or parameter type names that struct stays
out. 98 more virtual functions match, most of them setting a flag through a
pointer field (check.py: 25,563 matching, 107 not matching).

An argument a function moves on with a 32-bit move (`mov w2, w3`) is a
32-bit one: the tail call's placeholder takes a `u32` there, not a `u64`
(which compiles to `mov x2, x3`). 33 more leaf functions and 21 virtual
ones match (check.py: 25,617 matching, 107 not matching).

With `-fno-strict-aliasing` a store may change what `self->field_N` reads,
so the compiler reads it again after one: a pointer the original loads
once but uses after a store was in a local. The lifter counts the loads,
and holds such a pointer in one (`Unk_<addr>_<off>* p0 = self->field_N;`).
9 more leaf functions match (check.py: 25,626 matching, 107 not matching).

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
indices. Destructors are strong evidence. When a class's destructor is
implicit (or inline and empty), none of its fields has a destructor, and its
only base with a non-trivial destructor is at offset 0, clang 7 with the
game's flags doesn't emit the class's D2: it uses the base's D2 in its place
(`TryEmitBaseDestructorAsAlias` in clang's `CGCXX.cpp`; constructor aliases
are on at `-O3`). So the derived vtable's slot 0 is the base's D2, and only
its D0 is the class's own: weak, emitted with the vtable in the TU of the
class's key function. The D0 calls the D2 and then `operator delete`, so it
is a bare `b operator delete` only when the base's D2 is empty and visible in
that TU: inline in a header, or defined in the same TU. Checked with this
reproducer, compiled with the flags `compile_commands.json` gives a TU:

```cpp
class B { public: virtual ~B(); virtual void f(); };
B::~B() {}      // without it (B's destructor in another TU): D0 = bl B::~B() D2 ; b operator delete
class D : public B { public: void f() override; };
void D::f() {}  // D's key function: D's vtable and its D0 are emitted here
// _ZTV1D: slot 0 = B::~B() D2 (ret), slot 1 = D::~D() D0 (weak, b operator delete)
```

541 game classes have that shape: slot 0 inherited from a class that owns an
empty D2, slot 1 their own `b operator delete`. 268 of them also own
something batch 3 defined, and in every one of the 268 the D0 lies in the
same static-initialiser segment as the first of those functions, as their
key function would put it. Batch 4 (below) matches them.

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

### Batch 4: derived classes, forwarders and accessors

`vtables.py write` also writes:

| Kind | Functions | Source |
|---|---:|---|
| derived D0 | 189 | `class Unk_23bd490 : public Unk_23bd320 { public: void vf2() override; };`: no destructor, the D0 comes with the vtable |
| forwarder | 2,096 | `void Unk_2409c28::vf5() { Unk_1034d10(this); }`, the callee declared `void Unk_1034d10(void* self);` |
| field accessor | 720 | `void vf22() { field_351 = 1; }`, `void vf3(u32 value) { field_10 = value; }`, `return field_60;` |
| nested accessor | 152 | `return field_1a8->field_a0->field_c8;` |

That's 3,157 functions, all common, all matching in both games (game code,
gflib3 and gflnet3). Five more lifted functions compiled to other code (a
different instruction order or register, a 32-bit argument returned
through `x0`) and were left out with `--only`, like batch 2's.

- **Derived classes.** A class with the shape above derives from the class
  that owns its slot 0, when the base guess agrees, its group has no
  secondary vtables, and it defines a function in its D0's file that can be
  its key function. It declares only the slots where it differs from its
  base, with the key function first: overrides can be declared in any
  order, new virtual functions only in slot order. When the base's
  destructor is defined in another file, the base's destructor becomes
  inline (one class so far), which is only done when the base has a key
  function of its own in its destructors' file, so that its own D2 and D0
  are still emitted there. A derived override uses its base's signature;
  a class whose own functions would need another one stays underived.
- **Forwarders.** A virtual function that is a bare `b T` passes all of its
  arguments on, so `Unk_<T>(this);` is the same tail call whatever T
  takes. It's written when T is in both games, in no vtable, isn't
  `operator delete` and has no name yet. The 721 callees are named
  `_Z<n>Unk_<addr>Pv` and stay undecompiled: rename the callers' calls with
  them.
- **Accessors.** What `tools/leafgen.py`'s lifter turns into a function of
  `self` and scalar arguments becomes a member: `self->field_N` is the
  class's own field, declared after the virtual functions, from offset 8
  (the vptr), with offset asserts. Pointers it loads from `this` are fields
  that point to placeholder structs named after the class and offset
  (`Unk_<_ZTV>_1a8`, `Unk_<_ZTV>_1a8_a0`), declared before the class. All of
  a class's accessors share its fields, so one that reads a field with
  another type, as an integer where another follows it as a pointer, or
  overlapping another field, is left out. The arguments are in the mangled
  name (`_ZN11Unk_24067f83vf3Ej`). A derived class's accessors are left out,
  because its fields would follow its base's.

`write` rewrites all of `src/unsorted/virtual`: a function it named before
(`_ZN<n>Unk_<_ZTV>...`, of the class of a vtable that holds it) is picked
again.

What's left in game code, gflib3 and gflnet3, and why:

- **Thunks** (4,306: `sub x0, x0, #N ; b T`). A thunk is emitted with the
  override it adjusts `this` for, so it can only be compiled with its
  target, and only 4 of the targets are decompiled. 2,923 are in the
  destructor slots of secondary vtables: their targets are the destructors
  of classes with several bases, which reset vptrs and destroy members.
  Each then needs its class modelled with its secondary bases at the
  offsets the secondary vtables' offset-to-top gives.
- **D0s that tail-call their D2** (974, slot 1 `b <slot 0>`). The D0 runs the
  D2 and then `operator delete`, so a D0 with no delete means the class
  has an empty class-specific `operator delete` (or one that inlines to
  nothing). They wait for their D2s; batch 5 (below) does the biggest
  group, 238 classes that share one D2.
- **Bare `b operator delete` D0s** (644). 80 have the shape above but their
  base's destructor is in another file and their base's key function isn't
  decompiled yet. 245 own nothing but their D0, so their vtable (and D0)
  was emitted in the TU of a constructor or a function that creates them.
  The rest have other shapes (secondary bases, a base guess that
  disagrees, a base that defines nothing simple).
- **Virtual-to-virtual forwarders** (about 100): `b T` where T is another
  class's virtual function, called through that class's name.
- **One template, 106 times: now written.** 106 classes have the same 4
  slots: a constant count, two getters `x0 + 32 * index + 8` / `+ 0x10` (a
  64-bit index into 32-byte entries right after the vptr) and a function
  that calls slot 16 of the entry's object with the entry's argument.
  Their counts differ (1 to 28), so it looks like a class template
  instantiated 106 times. `write` models the entries as an array
  (`m_entries[<count>]`, the count from slot 0) of `Unk_<_ZTV>_Entry`, and
  the three functions as element members:
  `void* vf1(u64 index) { return m_entries[index].field_0; }` and
  `if (Unk_<_ZTV>_Obj* obj = m_entries[index].field_8) obj->vf16(m_entries[index].field_10);`.
  The 312 of them in game code, gflib3 and gflnet3 (104 classes) match in
  both games; the other 2 classes are in `startup`. `--no-elements` leaves
  them out.

```sh
python tools/vtables.py summary --area game
python tools/vtables.py show 0x7102418858            # a vtable group: slots, owners, base guess, referrers
python tools/vtables.py write --names map.csv        # into src/unsorted/virtual (Sword's vtables)
python tools/funcs.py name --from-file map.csv
python tools/check.py                                # its OK lines are the ones to keep; then, as in batch 2:
python tools/vtables.py write --names ok_map.csv --only ok.txt
python tools/check.py --update
```

## gflib3's memory code (`src/gflib3`)

The first hand-decompiled gflib3 code, built with gflib3's library settings
(docs/compiler.md, "gflib3"). All of it matches in both games, with
placeholder names:

| File | Functions | What |
|---|---:|---|
| `Unk_65d670.cpp` | 11 | the heap globals: the global, debug and default heaps (named `GlobalHeap`/`DebugHeap` through vtable slot 22), and a heap that takes the default's place for one thread or all of them while it's set, under a static `nn::os::Mutex` whose destructor is emitted here |
| `Unk_5cf850.cpp` | 13 | one-call wrappers of `nn::os` events, light events and TLS (called up to 1,095 times each), an `atomic<bool>` getter |
| `Unk_65f110.cpp` | 7 | the TLSF pool resource's constructor, destructors and their two thunks; a static object of the same code |

`include/nn/os.h` gained `nn::os::Mutex` (the SDK's inline wrapper, its
destructor already named), `GetThreadId`, the event imports and the size of
`LightEventType` (0xc bytes: two layouts put it exactly before an 8-aligned
field). The globals are in `data/data_symbols.csv`, so `check.py` verifies
the references to them.

The pool resource shows how a class with a secondary base gets its thunks:
modelled with the secondary base at `+0x8` (whose fields, initialized
before the derived vptrs, are its own), the destructor's definition emits
the `_ZThn8_` thunks, and they match. The 4,306 thunks of batch 4's
"what's left" follow their destructors and overrides like that.

Next in this code: the pool resource's other virtual functions (25 slots
in its primary vtable, most of them inherited from `0x710236d0c8`, and the
leak dump `0x710065f360`), the TLSF pool itself (`0x710065ed00`, its
`deactivate` at `0x710065efa0`) and the heap class that slot 22 names.

### Batch 5: classes derived from a hand-written base

238 classes share one D2 (`0x7100e7c4c0`): their D0 is `b <it>`, with no
`operator delete`. It belongs to `Unk_23f43c8`
(`src/unsorted/Unk_23f43c8.h`), a class on gflib3's reference-counted
object (`src/gflib3/Unk_239a418.h`, whose vtable 3,006 functions
reference). Both are written by hand:

- **The object** has a 0x48-byte primary base, interfaces at `+0x48` and
  `+0x50`, and its count in a handle at `+0x58`. Its primary base and its
  `+0x48` interface declare the same functions (get the handle, add a
  reference, drop one), so one override fills both vtables, with
  this-adjusting thunks that have the body inlined. The family's
  `operator delete` is empty: `vf3` destroys an object and gives its memory
  back to its allocator.
- **Types.** Each class has a static type descriptor whose parent is its
  base's, from an inline static member (`Unk_GetType`). A class that
  overrides the interfaces' type getter gets a primary-vtable slot for it
  too (slot 6 of `Unk_23f43c8`).

`vtables.py write` derives classes from such a base (`EXTERNAL_BASES`): a
class whose slot 0 is the base's D2 and whose D0 is `b <it>` has an implicit
destructor. Its secondary vtables' destructor slots are then
`sub x0, x0, #N ; b <D2>` thunks, and when its type slot is a `b T` to a
function nothing else calls, T is its own `Unk_GetType` and the secondary
type slots are thunks of `vf_type` (their adjustment is dead). Such a
class gets a file of its own: the base's getter is only inlined into the
class's getter (T is 0x128 bytes, three levels of statics) when it's the
base getter's one caller in the TU. With two classes, it's called twice,
stays out of line, and then the class's getter is small enough to be
inlined into `vf_type`. So these classes were one TU each, as Game Freak
writes them.

| | Functions |
|---|---:|
| the object: its functions, destructors, thunks, interface type getters | 15 |
| `Unk_23f43c8`: destructors, thunks, type getter and its thunks, `vf7`-`vf10` | 13 (4 renamed) |
| 224 derived classes: D0 and 4 destructor thunks each | 1,120 |
| the 212 of them that override the type getter: `Unk_GetType` | 212 |
| their `vf_type` and its 2 thunks (written as forwarders before) | 636 renamed |

All of them match in both games. `vf7`-`vf10` of `Unk_23f43c8` and the
classes' type getters had been placed in other classes by the owner
heuristic (a tie) or written as forwarders; write now leaves the
hand-written classes' functions alone (`HANDWRITTEN`).

check.py: 23,337 matching (21,959 before this batch), 106 not matching.

### Batch 6: more hand-written bases, and the shapes of their families

Three more bases (`EXTERNAL_BASES`), and the three shapes a derived class's
type getter takes, which say how its TU was put together:

| Shape | Its slot 6 and the secondary type slots | Written as |
|---|---|---|
| tail | `b T` and `b T`: T, its getter, isn't inlined (its parent's is) | `vf_type` out of line, the key function |
| inline | the getter inlined into `vf_type`; `sub x0, x0, #N ; b <vf_type>` thunks | `vf_type` inline in the class (out of line, clang inlines it into the thunks); another function is the key |
| copy | `vf_type` with the getter inlined, calling its base's getter out of line; the secondary slots are copies of it | `vf_type` out of line; the base and all its derived classes are one TU |

- **`Unk_23f4318`** (in `Unk_23f43c8`'s TU): the object with its own type and
  an out-of-line destructor, nothing else. 6 classes derive from it.
- **`Unk_23d4470`**: three references, five 0x80-byte callables (a manager
  that disposes of their storage) and a fourth reference, in one TU with
  its 63 derived classes (`0x7100bba3d0`-`0x7100c23050`), which is why its
  getter is called, not inlined, by theirs (`shared_tu`). Its own
  definitions are `src/unsorted/Unk_23d4470.inl`, which the TU's generated
  file includes (`source`). 61 classes derive from it; the other 2 have
  another type in between (a 168-byte `vf_type`). That `vf_type` inlines
  the getter of the class in between as well, two guarded statics deep
  (`intermediate_type`). That class isn't known, so a placeholder
  `struct Unk_<its type object>` holds only its getter, and the derived
  class's getter chains to it. All 16 functions of the 2 classes match.
- **The object itself** (`inline_dtor`: its destructor is inline, so a
  derived D0 and its thunks are copies of it). Of its 113 direct
  descendants, 58 have the inline shape, but only 1 defines a function write
  can make its key function; the others only have undecompiled ones. 35
  store a type created by an out-of-line function (`0x7100603810`), and 14
  have another type in between. Those 14 are the `Unk_23d4470` shape
  (`intermediate_type`), but the getter their in-between type calls,
  `0x7100c657d0`, is another class's out-of-line getter: a sibling of
  `Unk_23d4470` (`static type(Unk_239a418_GetType())`), with 93 callers.
  Two placeholder structs stand in: the in-between class, holding its
  inline getter, and the class above it, which only declares its getter.
  That getter stays undefined but named, so these classes call it as the
  original does. They had matched lifted members already, which a class
  on a hand-written base couldn't keep. Now it can, when the members'
  fields come after the base's (`ExternalBase.size`) and an override is
  declared as the base declares it. So the 14 are written on the base: 112
  functions match (their `vf_type`s, the copies in the secondary vtables,
  the destructors and their thunks).

  Of the 35 that "store a type created by an out-of-line function", that
  function is the same kind of getter: another direct descendant's
  (`static type(Unk_239a418_GetType())`, three statics deep), out of line.
  Their `vf_type` makes three calls (guard, that getter, guard) and their
  secondary type slots are copies of it (`out_of_line_parent`). There are 9
  such getters; 22 classes are on the one at `0x710089b390`. Written with
  the placeholder above for the class that getter belongs to (its getter
  named, not defined), 33 classes match: 264 functions (check.py: 26,034
  matching, 107 not matching). The getter at `0x7100603810` is
  `Unk_239c050`'s: a direct descendant with the tail shape (`vf_type` is
  `b <getter>`, its secondary type slots too) and an implicit destructor.
  The tail shape now applies to the object when the getter is three
  statics deep and calls nothing else (`direct_getter`). Classes whose
  getters call it are allowed, and it is named after its type object as
  they name it (`Unk_27771e8::Unk_GetType`, inline, at the top of the
  file). It matches only with one of those classes in its file: when
  `vf_type` is the getter's one caller in the TU, clang inlines the getter
  into it. So the class is written with the one in its segment
  (`Unk_239bfa0`) and dropped when there's none. 3 classes match: 22
  functions (check.py: 26,056 matching, 107 not matching). The other 20
  getters with that shape (`b <getter>` slots, still forwarder callees)
  belong to classes with destructors of their own, which write doesn't
  model.

  Of the object's direct descendants with destructors of their own, 30
  only release one reference member (`Unk_239a418_Ref`) before the
  object's D2, inlined. Their destructor is implicit, with that member
  (`ref_members`: the D2's pattern is the object's with the release
  spliced in, `ref_dtor_pattern`, and it stores the class's own vtable).
  So the class declares the member, at its offset, and nothing else.
  The vtable check matters because a derived class with nothing to destroy
  shares its base's D2 (clang aliases it), and the owner heuristic may give
  that D2 to the derived class's vtable. check.py didn't check a
  placeholder vtable that data_symbols.csv didn't list yet, so the D2
  "matched" anyway (in Sword it would fail now). With the types the classes already had, 20 of the 30
  are written and all their functions match: 171 functions, the D2s, D0s
  and their thunks with the D2 inlined (check.py: 26,227 matching, 107 not
  matching). The rest have other type shapes, or their D2 is in another
  vtable.

A class's getter may now be called by other code of the class; it only
isn't its own when another vtable function calls it.

check.py: 23,869 matching (23,337 before this batch), 106 not matching.

Left of these families: the classes above that have no key function write
can define, the object's direct descendants with other type shapes, and
the bases of the remaining groups of D0s that tail-call a shared D2 (50,
21, 16, 14, 12, ... classes). Those bases are bigger: 17 to 69 slots, and
destructors that release owned objects, hashed-name handles (the FNV-1a
hash of "", `0xcbf29ce484222645`) and members with out-of-line
destructors.

### Batch 8: constructors that only call their base's

`Unk_D::Unk_D() {}` for a class derived from another, with nothing of its
own to initialise, is `bl <the base's constructor>` and then the store of
D's vptr (its `_ZTV` from the GOT, + 16), 48 bytes (`CTOR_PATTERN`). The
function is a referrer of D's vtable only, and what it calls first of B's
only, so both classes are known: `vtables.py ctors` writes the ones whose
D and B have one vtable each, aren't hand-written bases and aren't defined
anywhere else. Each file (`src/unsorted/ctor/`, one per segment) declares
the classes the same way: a constructor, and a destructor that isn't
defined there, so that the vtable stays the key function's TU's. A base
that is itself such a class derives from its own base there too.
`vtables.py write` leaves these classes alone (it still writes what their
vtables inherit, for the classes that own it).

153 constructors match, of 153 classes, and the 20 base constructors that
aren't among them get their names (`_ZN<B>C2Ev`, still U). The 153 vtables'
names agree with where the original loads them from (`check.py
--record-data` put them in `data_symbols.csv`). check.py: 25,193
matching, 107 not matching.

Another 118 looked like classes with a secondary vtable, but only
because of a bug: `nx.refs.decode` kept `adrp`'s page in a register that
`ldr x8, [x8, #lo]` (the GOT load) had just overwritten, so the
`add x8, x8, #0x10` after it seemed to address the next GOT slot, another
vtable's. With that fixed (nothing check.py compares changes), they're
written too, and all match: 271 constructors, check.py: 25,311 matching.
The constructor of a class without a base is only the vptr store
(`ROOT_CTOR_PATTERN`; an empty destructor doesn't store it, so nothing
else has that shape). 47 more match that way, one of them a base above
(check.py: 25,358 matching). A class with two constructors, or whose
constructor a derived class calls under another address, is left out:
only one function can be its C2.

A derived class's constructor may also zero fields (`str xzr|wzr` or
`stp xzr, xzr` to `[x19, #N]` around the vptr store, `ctor_fields`): they
become the class's own, after its base's (8 bytes for a placeholder base,
more if it zeroes fields of its own), typed by the store's width, and
`Unk_D::Unk_D() : field_10(0) {}`. A constructor that a constructor in the
same file calls is left out: clang would inline it there, and the original
calls it, so it's another TU's. 16 more match (check.py: 25,642 matching,
107 not matching).

Left are about 30 constructors of other shapes, which store more than one
vptr (multiple inheritance).

### Batch 9: reference members on out-of-line bases

On a hand-written base whose D2 is out of line (`Unk_23f43c8`,
`Unk_23d4470`), a class with reference members has a D2 of its own: its
vptrs, its members released (the last declared first), then
`b <the base's D2>` (`ref_tail_pattern`, `ref_members_tail`). The family's
`operator delete` is empty, so its D0 and its four destructor thunks are
copies of that D2. The class declares the members at their offsets and its
destructor stays implicit, as on the object (Batch 6).

The D2s and D0s matched at once, but most thunks didn't. Ours kept the
thunk's own `this` in a second register (`stp x20, x19`, 4 bytes longer),
where the original addresses the members from the adjusted pointer after
the vptr store's write-back (`str x9, [x19, #-0x48]!`, then
`str xzr, [x19, #0x80]`). InstCombine decides this. The thunk passes
`this - 0x48` on as the class, and InstCombine rewrites that pointer as
an element of `X[-1]`, at offset `sizeof(X) - 0x48` (`- 0x50` for the
other secondary vtable). When that offset is a field, the members are
indexed from it, `this - 0x48` stays one value (which the tail call needs
anyway), and the thunk matches. When it's inside a byte array, every
member's address folds into one array index from the thunk's `this`,
which then stays live across the release calls. For most of these classes
the offset falls in the object's primary base, whose bytes `0x28`-`0x48`
were `u8 _28[0x20]`. `Unk_239a418_Base` now has four `u64` fields there,
which changed nothing that matched before. In the original, some classes'
thunks are the longer form too: the offset lands in an array there. So
`ref_members_tail`'s thunks may be one instruction longer than their D2,
and check.py decides.

**`Unk_23f4e40`** (`src/unsorted/Unk_23f4e40.h`, `Unk_e9d210.cpp`) is a
fifth hand-written base: an abstract class on the object with four
references and a state at `+0x6c` that a member (`0x7100e9d4b0`) steps
through its pure `vf7`-`vf10`. Otherwise it has `Unk_23f43c8`'s shape:
its destructor is its key function, and its `vf_type` is inline. Its D0
is a trap (the class is abstract). Its 9 functions match.

| Base | Classes | Of them with reference members |
|---|---:|---:|
| `Unk_23f43c8` | 46 | 46 (1 to 5 members) |
| `Unk_23d4470` | 10 | 10 |
| `Unk_23f4e40` | 44 | 34 |

All their functions match in both games: 719 with `Unk_23f4e40`'s
(their D2s, D0s, destructor thunks and type getters; their `vf_type`s
and the thunks of those were written as forwarders before, and are
renamed). check.py: 26,946 matching (26,227 before this batch), 107 not
matching.

Left out: 13 classes whose thunks still differ. Ours are the longer form
where the original's are the short one, because the offset lands in a
byte array here and on a field there: in the padding write declares
(`u8 _348[0x28]`), in `Unk_23d4470_Callable`'s storage, or in a class
whose size isn't known (fields after its last member). Scalar padding
would fix the first, but it changes every generated class with fields.

### Batch 10: `Unk_23f4660`

The biggest base left after Batch 9: 50 classes share its D2
(`0x7100e7feb0`, 552 bytes) and 71 tail-call it from their own. It is
written by hand (`src/unsorted/Unk_23f4660.h`, `Unk_e7feb0.cpp`), and
its D2 needed every member it destroys, in order:

- a reference (`+0x5c0`);
- the object it owns (`+0x5a0`), a libc++ `std::unique_ptr` with a
  deleter that destroys it and gives its memory back to an allocator
  (`Unk_23f4660_Deleter`: allocator, size, alignment at `+0x5a8`). Its
  class (vtable `0x71023f47c0`, which has no destructor slots, so the
  deleter's destructor call is direct) has two references and a libc++
  `std::vector` of them, whose allocator frees through
  `Unk_239a418_Allocator::vf3(p, bytes, 8)` (`Unk_23f4660_Allocator`);
- a 0x4a0-byte member with a virtual destructor of its own, out of line
  (`Unk_23f4760`, `0x7100e800e0`). The D2 calls its D1, which check.py
  now resolves to the D2 row when nothing here compiles it
  (`base_structor`): the two are one function unless the class has
  virtual bases, and then the addresses differ and the call fails;
- two 0x30-byte names (`+0x78`, `+0xa8`, `Unk_23f4660_Name`): two
  references, the 64-bit FNV-1a hash of a string and the string. Their
  destructor resets them: it releases the first reference if `+0x18` is
  set, then stores the hash of `""` and `""`, and releases the second. The
  references are plain pointers: a destructor of their own would release
  the first a second time after the second's virtual call;
- a reference (`+0x70`), then the object's D2 inlined.

Its slots 7-16 are inline in the class except `vf10`: they were emitted
with a derived class's vtable in the TU before (`0x7100e7f510`-
`0x7100e7f590`), so the owner heuristic had given them to derived
classes, and they are renamed. Its type getter has two copies: the one
other TUs call (`0x7100e7f6c0`, `Unk_23f4660::Unk_GetType`, inline in the
class) and one only its own TU calls (`0x7100e81640`), which `vf_type`
and its thunks tail-call. Written as a function of its own, in a file of
its own (`Unk_e81640`), `vf_type` matches; with the getter inline in the
same TU, clang inlines it into `vf_type`.

With it, `vtables.py` writes 54 classes on it (`EXTERNAL_BASES`): 43 share
its D2 and 11 release 1 to 5 references first (Batch 9's shape). All their
functions match in both games: 342 new, the base's 7 (its D2, D0, four
destructor thunks and `Unk_e81640`) and 335 of the classes on it. Its
`vf_type`, the thunks of that and its slots 7-16 were matched forwarders
and members of other classes before, and are renamed. check.py: 27,288
matching (26,946 before), 107 not matching.

Left out: 12 classes on it whose thunks differ (the offset lands in
`Unk_23f4760`'s bytes), and the other classes that tail-call its D2,
which destroy other kinds of members.

**Where the thunks say there are fields.** Of the classes left out above and
in Batch 9 for their thunks, the original's thunks say what lies at
`sizeof(X) - 0x48` and `- 0x50`: a field when they are as long as the D2, an
array when they are one instruction longer. When all of a class's
destructor thunks are the short form, `write` now declares the padding in
the last 0x50 bytes of the class as `u64` fields instead of bytes
(`tail_padding_start`, `ClassSpec.scalar_tail`); otherwise the padding stays
bytes. 10 more classes match: 72 functions (check.py: 27,360 matching, 107
not matching). The rest can't be fixed in the classes themselves. Classes
with the same visible members have different thunks in the original (on
`Unk_23f4660`, with references at `0x5d0`/`0x5d8`, `Unk_242d838`'s are short
and `Unk_2439d60`'s long), so their real sizes differ by fields nothing reads,
and the offset lands in a base: `Unk_23f4760`'s bytes or
`Unk_23d4470_Callable`'s storage. Making those fields fixed some classes and
broke the others (a trial matched 7 more and lost one that had matched), so
the bases keep their bytes.

### Batch 11: more classes on the hand-written bases

Among the classes on hand-written bases that `write` refused, two cases
were simple:

- **A D2 too big to be inlined.** With enough reference members, the D2
  isn't inlined into the D0 and the thunks: the D0 is `b <D2>` and the
  thunks `sub x0, x0, #N ; b <D2>`. With the same implicit destructor,
  clang makes the same choice, so these are the same classes. A few have
  a D2 of the same size that the original's D0 tail-calls where ours
  inlines it; the trial leaves those out.
- **Lifted members with a callee or globals.** A class on a hand-written
  base kept out a lifted member that tail-calls a function or reads a
  global, and with it the whole class whenever that member had matched
  before. The file declares their callees and globals as it does for any
  lifted member.

13 more classes match: 98 functions (check.py: 27,458 matching, 107 not
matching).

### Batch 12: type getters out of line on the hand-written bases

Batch 6's "copy" shape (a `vf_type` with the class's getter inlined,
calling its parent's getter out of line, and secondary type slots that are
copies of it) was only written on `Unk_23d4470`, whose classes share one
TU, and on the object. On the other bases it has two forms, told apart by
the statics the called getter loads (each guarded static is two: its
guard, then the object):

- **The base's own getter** (`base_getter_copy`): it loads the same
  statics as the getter in the base's type slot (`base_type_statics`).
  The base's getter is inline in its header; a TU with several callers
  keeps it out of line, and the linker one copy of it (`0x71013a5bb0` for
  `Unk_23f4e40`, named `Unk_23f4e40::Unk_GetType`). A generated file only
  has that many callers when it holds two such classes or more, so a class
  that would be alone in its file isn't written: there, clang inlines the
  base's getter.
- **Another class's getter on the same base** (`out_of_line_parent`, now
  for every base): it loads its own type, then the base's getter's
  statics. As on the object, that class is a placeholder struct named
  after its type object, its getter named and not defined. When that
  class's own type slot is `b <its getter>` (Batch 5's tail shape) and
  other classes' `vf_type`s call the getter, the class is written too,
  with its getter named after its type object (#53's rule, on any base).
  On these bases, other virtual functions may call such a getter too (a
  type check in a slot-24 function, for one); only a call from another
  class's type slot counts against the class.

20 more classes match, 18 on `Unk_23f43c8` and 2 on `Unk_23f4660`: 162
functions (check.py: 27,620 matching, 107 not matching). None of the 20
classes on `Unk_23f4e40` whose getters call its getter's copy match yet.

### Batch 13: callables among the members

Batch 9's D2s, which release reference members and then tail-call their
base's, may also destroy `Unk_23d4470_Callable`s: if one holds a callable,
its four words are cleared and its manager (`+0x8`) disposes of the storage
(`+0x20`), as in `Unk_23d4470`'s own D2. `tail_members` reads both kinds from
the D2 (`_TAIL_MEMBERS`: the vptr stores, then the members, the last
declared first; a callable that comes first has its manager's load scheduled
between the vptr stores), and a file that declares such a member includes
`unsorted/Unk_23d4470.h`. The four words are cleared with `str xzr` or with
`stp xzr, xzr`, whichever reaches: clang pairs the stores only within
`stp`'s range.

21 more classes match, 12 on `Unk_23f43c8`, 5 on `Unk_23f4660` and 4 on
`Unk_23f4e40`: 147 functions (check.py: 27,767 matching, 107 not matching).
The other D2s that tail-call a hand-written base destroy members of other
kinds (owned objects with allocator deleters, members with out-of-line
destructors) or save more registers, so their instructions are scheduled
differently.

### Batch 14: `Unk_239bb58`

A gflib3 class on the object (`src/gflib3/Unk_239bb58.h`, `Unk_600c30.cpp`):
four references and a `u32` that `vf11` tests. Its D2 releases the
references, then the object's D2 is inlined; the D0 and the four thunks
are copies of it. Its type getter has two copies, as `Unk_23f4660`'s does:
the one other TUs call (`0x7100603900`, `Unk_239bb58::Unk_GetType`, inline
in the class) and one only its own TU calls (`0x7100601520`, `Unk_601520`,
in a file of its own), which `vf_type` and its thunks tail-call. Its 14
functions match, 5 of them matched before as the placeholder's
(`vf7`-`vf11`; `vf_type` and its thunks were forwarders and are renamed).
Two classes derive from it with D2s of their own that destroy more than
references (`0x7100603500`, `0x71005ff9d0`); 7 classes tail-call each of
those, so they are the next bases of this family.

With it, 2 classes on it match too: 20 new functions in all (check.py:
27,844 matching, 107 not matching, after #62 and #63).

### More hand-written bases (#62, #63)

Written in parallel, each with its `EXTERNAL_BASES` entry; the classes on
them are the next generator batches. The details are in the headers.

| Base | Shape | D2 shared / tail-called by | New |
|---|---|---|---:|
| `Unk_23c1a68` (`0x7100978f50`) | references, vectors of owning pointers, light events | | 9 |
| `Unk_23dc940` (`0x7100978cf0`), on `Unk_23c1a68` | a reference, a vector, `Unk_2399140`, `Unk_23c1a48` (vector of references) | 16 / 12 | 13 |
| `Unk_23dcdd0` (`0x7100c69450`), on `Unk_23dc940` | vectors, owned objects (`unique_ptr` with `Unk_23f4660_Deleter`) | 12 / 20 | 11 |
| `Unk_23c9470` (`0x7100ac70e0`), on `Unk_23f4660` | eight `std::function` slots, an owned array (`unique_ptr<T[]>`), references | 10 / 7 | 7 |
| `Unk_2399590` (`0x71005d1550`), gflib3 | a node with parent and child lists, locks, groups of callables | 8 / 15 | 11 |
| `Unk_23a45c8` (`0x71006ce5e0`), abstract | an array of references, allocator wrappers with `std::function`s | 0 / 10 | 6 |

What they needed beyond the earlier bases:

- **An explicit destructor.** `Unk_23dc940`'s is written in the class
  (`~Unk_23dc940() override {}`): clang treats an implicit destructor as
  inline-specified, which raises its inline threshold from 250 to 325, and
  the D2 (cost 305) was inlined into the D0 and the thunks, where the
  original tail-calls it.
- **Helpers where the original's code had them.** `Unk_23d4470_Callable`
  clears its four words in a `Clear()` member (in the destructor body they
  became a `memset` with another address order), and `Unk_2399590`'s
  find-and-erase is a helper of its own (`Unk_2399590_Nodes::Erase`;
  inline in the destructor, clang doesn't thread the empty vector past
  the "found?" check).
- **Data sizes.** A derived class may put fields in its base's tail
  padding, so `ExternalBase.size` is the data size (`Unk_23c9470`: 0x848 of
  0x850).
- **Slots with a parameter.** An `ExternalBase` slot may carry its
  parameter (a pointer to a class), and `write` declares and mangles the
  overrides with it (`Unk_2399590::vf7(Unk_2399590_Arg*)`).
- The container allocator is gflib3's (`Unk_239a418_StdAllocator`, in
  `gflib3/Unk_239a418.h`), and `Unk_239a418_Ref` has `Reset()`.
- A getter that the original's TU keeps out of line only because other code
  there calls it is declared, not defined (`Unk_23a45c8::Unk_GetType`):
  without that code, clang would inline it.

Most of the 16 classes that share `Unk_23dc940`'s D2 have `Unk_23dcdd0`'s
type shape: slot 6 calls the copy of `Unk_23dc940::Unk_GetType`
(`0x7100c6eac0`) out of line, and the secondary slots are copies with both
getters inlined, which `derive_external` doesn't model yet (an inline
`vf_type` gives that shape).

#67 added five more: `Unk_23f6328` (abstract, on `Unk_23f4660`; its member
class `Unk_236d3f8`'s destructors too), `Unk_24006c0` (on `Unk_23f43c8`),
`Unk_24034f8` (16-aligned, on `Unk_23f4660`), `Unk_23f5ec8` and
`Unk_23f2df0` on it (its `vf_type` tail-calls a TU-local getter,
`Unk_eb57c0`, as `Unk_e81640` does). 69 functions match, 29 of them matched
before under placeholder names. `Unk_23da950` (D2 `0x7100c277c0`) is on
gflib3's second reference-counted base (count at `+0x50`, vtables
`0x7102398c40`, `0x710239a4c0`), which 213 classes derive from.

### Batch 15: classes on the new bases

The first generator batch on #62-#64's bases. Two fixes were needed:

- A hand-written header may declare a placeholder struct for a getter
  (`Unk_23c1a68.h` declares `Unk_27771d8`), so a generated file that
  includes it doesn't declare that struct again (`header_structs`).
- On a base other than the object, a tail-shaped class's getter must load
  its own type and then exactly the base's getter's statics. The 7 tail-shaped
  classes on `Unk_23dc940` load one more guarded static: there is a class
  between them and `Unk_23dc940`, whose getter theirs inlines too. Written
  directly on `Unk_23dc940`, their getter came out one level short, small
  enough for clang to inline it into `vf_type`, and the forwarders they had
  matched as regressed. They're refused until that class is modelled.

13 classes match, 9 on `Unk_23c9470`, 2 on `Unk_2399590` and 2 on
`Unk_23c1a68`: 104 functions (check.py: 27,948 matching, 107 not matching).
The trial matched more functions (238), but a class is written only when
all its functions match. Most classes on `Unk_23dc940` have the inline
type shape and nothing else matched that could be their key function.

### Batch 16: classes on the object with an interface

About a hundred classes directly on the object have one more secondary
vtable, at `+0x60` (right after the object): an interface. Their D2s store
four vptrs (`str x9, [x0] ; str x8, [x0, #0x60] ; stp x10, x11, [x0, #0x48]`),
and the third vtable's functions aren't in the class's primary vtable: they
aren't overrides but the interface's own functions (99 distinct third
vtables among 108 classes, so mostly one instance per class, a mixin). Those
functions were already written as members of the placeholder class of the
vtable that owns them.

So such a class is written as
`class X : public Unk_239a418, public Unk_<that placeholder>`, its
fields after the interface's vptr (`+0x68`), when its D2 only releases
references (`ref_dtor_pattern(..., iface=True)`: the object's pattern with
the four-vptr head), the interface's functions all belong to one
placeholder class without fields, and the rest is a class on the object as
before (its other two secondary vtables, its type slot). The placeholder is
declared in the file before the class.

62 classes match: all 9 functions each (D2, D0, the four destructor thunks,
`vf_type` and its two copies), 558 functions (check.py: 28,559 matching,
107 not matching, with #67). The interface's functions are untouched.

### Batch 17: classes on #67's bases

The generator, unchanged, on #67's bases: 7 classes, 3 on `Unk_23f6328`, 3
on `Unk_24034f8` and 1 on `Unk_23f5ec8`, 56 functions (check.py: 28,615
matching, 107 not matching).

### Batch 18: a destructor as the key function

A class on the object with the inline type shape (Batch 6: `vf_type`
inline, its getter inlined into it, the secondary type slots
`sub x0, x0, #N ; b <vf_type>`) needs another function `write` can define
as its key function, so that its vtable, `vf_type` and the thunks are
emitted in its file. When it has none but has a D2 of its own (members to
destroy, Batch 6 and 16), its destructor is written out instead:
`~X() override;` declared before its other functions and `X::~X() {}`
defined in the file of its D2 (`ClassSpec.explicit_dtor`). Out of line, the
destructor compiles to the same D2, D0 and thunks as the implicit one for
these small D2s. A class that shares the object's D2 can't do this: a
written-out destructor would be a D2 of its own.

35 classes match, 29 plain and 6 with an interface: 315 functions
(check.py: 28,930 matching, 107 not matching).

### More hand-written bases (#70, #71)

Written in parallel with Batch 18, each with its `EXTERNAL_BASES` entry.
The details are in the headers and the PR descriptions.

| Base | Shape | New |
|---|---|---:|
| `Unk_241b640` (`0x71011622d0`), on the object | abstract, inline destructor; a vector of 0x90-byte entries with a callable, a reference | 39 (with the next three) |
| `Unk_23c44f8` (`0x710099cf10`), on the object | inline destructor, three references; `vf7(s32)` | |
| `Unk_23c2c68` (`0x7100999620`), on `Unk_23c44f8` | a reference, two signed counts | |
| `Unk_24284d0` (`0x710126bd00`), on the object | inline destructor; two references, six callables (the first five one member), five FNV-1a hashes of "" | |
| `Unk_239a4c0` (`0x710000d500`), gflib3 | the second reference-counted object: count at +0x50, an interface at +0x48, no types, an empty inline destructor | 85 (with 20 classes on it) |

What they needed:

- **Scalar parameters** in `ExternalBase` slots (`param_codes`: `s32` ->
  `i`, `u64` -> `m`), for `Unk_23c44f8::vf7(s32)` and `Unk_24284d0::vf7(u64)`.
- **A base without types** (`ExternalBase.type_slot = None`, and in the
  secondaries): `Unk_239a4c0` has no `vf_type`, so `derive_external`
  models no getters and declares the slots in `derived_order`.
- **An empty base destructor.** `Unk_239a4c0`'s destructor is inline and
  empty, and none of its fields has one, so its D2 stores no vptrs: a `ret`,
  the linker's one copy at `0x710000d500`. A derived class's D2 stores its
  two vptrs, releases its references (the last declared first) and returns
  (`ref_empty_pattern`, `ref_members_empty`).
- **Its destructor as the key function**, as in Batch 18 (`explicit_dtor`):
  the classes on `Unk_239a4c0` define nothing in their D0's file (their
  vtables were emitted where they're created).
- **One member for several callables.** `Unk_24284d0`'s D2 clears the
  first of five callables through a pointer to it (`add x9, x19, #0xa0`,
  then `stp xzr, xzr, [x9, ...]`). That's one member
  (`Unk_24284d0_Callables`): as five members or an array, they're
  addressed from `this`.

Left out, with the reasons:

- `Unk_242af50` (D2 `0x71012928c0`, on `Unk_24284d0`) and the classes on
  it have internal linkage. Their vptrs are stored with `adrp`+`add`
  instead of a GOT load, and their types are local statics. clang emits
  such a class only with code in its TU that uses it, such as its derived
  constructor.
- `Unk_24284d0`'s constructor (`0x710126ab20`) gives the same instructions
  in another order (the hash constant comes before the vptr stores). It's
  named, not defined.
- The classes on `Unk_241b640`: the base is abstract, so its D0 thunks are
  traps while a derived class's are copies of the D2, and
  `derive_external`'s inline-destructor thunk check refuses them all. Most
  sit on three classes in between, which override `vf_type`.
- On `Unk_239a4c0`, about 170 classes have D2s that destroy more than
  references. The large groups are on intermediate classes: 22 tail-call
  `Unk_23f5d00`'s D2 (`0x7100ead240`), and groups of 6, 4 and 3 share one
  D2. `Unk_2398c40`'s D2 holds owned objects with allocator deleters, and
  about 12 classes have a second interface at +0x58.

### Batch 19: tail-called destructors written out

A full trial on master after #70-#72 (`write` with every candidate) matched
138 more functions. None of those completes a class, so there was nothing
to keep. The classes' other functions are BAD in two ways:

- **D2s inlined into the thunks** (9 classes on out-of-line bases, with D2s
  of 204-324 bytes). The original's D0 and thunks tail-call the D2. An
  implicit destructor is inline-hinted: clang's threshold is 325 instead of
  250, and these D2s cost between the two. So a class whose D0 tail-calls
  its D2 (the "called" form of Batch 9) now gets its destructor written
  out, as in Batch 18 (`explicit_dtor`). That added the declaration and the
  definition to the 21 such classes that matched already. Their D2s cost
  more than 325, so the code is the same.
- **Thunks 4 bytes too long** (40, 14 classes, mostly on `Unk_23f4660`).
  The thunk's form depends on what lies at `sizeof(X) - 0x48` and
  `- 0x50` (`tail_padding_start`). For these small classes that's inside
  the base: in `Unk_23f4660`'s `field_100` (`Unk_23f4760`), whose tail is
  bytes. Classes of the same visible size there need different forms, so
  their sizes differ by fields their D2s don't touch. Making the base's
  tail scalar broke other classes before (Batch 10), so these stay.

9 classes match, 4 on `Unk_23f43c8`, 3 on `Unk_23f4660`, 1 on `Unk_23f4e40` and
1 on `Unk_24034f8`, all with D2s that their D0 and thunks tail-call: 65
functions (check.py: 29,119 matching, 107 not matching).

### More bases and parents (#74, #75)

Written in parallel with Batch 19. The details are in the headers and the
PR descriptions.

**`Unk_23f5d00`** (#74, 17 functions): a class on `Unk_239a4c0` (0x180
bytes) whose D2 (`0x7100ead240`) 22 classes tail-call. Its member at +0x60
is a holder of `Unk_23dba98`'s shape (`Unk_236d3d8`: a reference handed
to `Unk_5e2bc0` and dropped, two callables). The D2 runs the holder's
release step before the holder's own destructor runs it again, so it's a
helper both call (`Reset()`). Its destructor is the key function, too big
to inline: the D0 and the thunks tail-call it. For the classes on it:

- `tail_members` takes the number of vptrs, so a D2 that stores two (one
  secondary base, `Unk_239a4c0`'s) reads too.
- A D2 that is only `b <the base's D2>` has nothing to destroy, and its
  destructor is out of line: an empty body with no member to destroy, so
  clang skips the vptr stores (`CanSkipVTablePointerInitialization`).
  `write` gives it `explicit_dtor`.
- 3 classes match. The other 19 store their two vptrs and then tail-call
  the D2. Written as `X::~X() {}`, they come out as the bare `b <D2>`, so
  the originals' destructors have a body or a member that compiles to
  nothing, and the binary doesn't say what. They're left out.

**Classes on `Unk_241b640`** (#75, 20 functions):

- A D0 thunk of a class on an abstract base with an inline destructor is
  compared with the base's D1 thunk, because the base's D0 thunks are
  traps.
- A class whose type slots are another generated class's on the same base
  derives from that class (`ClassSpec.parent`). The parent is declared
  before it in each file, and a slot it doesn't define takes the
  signature of the first class on it that does.
- The three classes in between (`Unk_241d0c0`, `Unk_241d190`,
  `Unk_241e938`) are each alone in their TU, and alone, clang inlines
  `Unk_241b640::Unk_GetType` into their `vf_type`s. So a parent is declared
  but not defined (no type functions or destructors: its vtable isn't
  emitted), and only when classes on it are written.
- 4 classes match. 15 have no function `write` can define as their key
  function, 2 have Batch 9's tail form on an inline-destructor base, and 1
  has a 588-byte D2 of its own.

### `Unk_2419350`, a base the owner heuristic missed

Six vtables have `0x7101122e70` in slot 0, a D2 that releases two
references on `Unk_239a4c0`. It and every one of their D0s store
`0x7102419350`'s vtable: that's the base, `Unk_2419350`. The owner
heuristic gave its D2 and its seven small functions to `Unk_24192b0`
(`0x71024192b0`), which inherits all of them. Its destructor is implicit,
so inline: clang replaces an inline derived D2 with the base's, which is
why the classes on it with nothing to destroy share its D2, while their
D0s and thunks are copies of it. An out-of-line derived destructor
doesn't get that: the target is a linkonce symbol, so clang emits a D2 of
its own. So a class on it that defines nothing can't be written: no
key function, and no destructor to be one.

`Unk_2419350` is hand-written (`src/unsorted/Unk_2419350.h`,
`Unk_1122d20.cpp`, with `vf5` as the key function), with an `EXTERNAL_BASES`
entry. Its D2, D0 and two destructor thunks match (4 new), and its seven
functions are renamed from `Unk_24192b0`'s. In the original, one TU emits
both vtables' functions. `Unk_24192b0` defines nothing of its own to be its
key function, so its D0 and thunks stay U. Its vtable is stored only by
`0x710111db70`, in an earlier TU.

### Batch 20: owner ties broken by the stored vtable

`owners()` gives a function to the shortest vtable that holds it, and a tie
to the vtable at the lower address. A base and a class on it with
vtables of the same length tie on everything they share, and the class
on it often comes first: the base's D2, its type slot and its other
functions became the derived class's (`Unk_2419350`, `Unk_23bcdf0`).
`write` now breaks those ties by the vtable a shared D2 stores
(`prefer_stored`, on `stored_vtable_owners`'s rows of equal length): the
functions the two groups' vtables share are the base's. 127 of the 165
rows are such ties. `write --only <empty>` moved 19 files' classes, with
their names. A full trial had the same BAD lines as before, and no
REGRESSION or STALE ones.

5 classes match, 33 functions new, and 92 matched functions are renamed to
the classes that define them (check.py: 29,196 matching, 107 not matching).

### Batch 21: the base's D2, copied

Of the D2s that store another class's vtable than their owner's
(`vtables.py stored`), many are 80 bytes and store the object's: each is
a copy of `Unk_239a418`'s D2, owned by one class. That's #74's bare
destructor on an inline base: an out-of-line `~X() {}` with an empty
body and nothing to destroy, so clang skips X's vptr stores, and what's
left is the base's D2, inlined. X's D0 and thunks are copies of it, as
the base's are of the base's D2. `derive_external` now takes such a D2
(`inline_bare`: the same pattern and statics as the base's D2) and
writes the destructor out as the class's key function.

15 more D2s of that shape (`vtables.py stored`, 80 bytes) are classes on
`Unk_2431de8`, one of the five, whose `vf_type` they inherit. #75's
`ClassSpec.parent` takes only a parent in `typed`, one whose `vf_type` is
out of line, and `Unk_2431de8`'s is inline (Batch 6's shape). Letting an
inline-shaped class be a parent would write them: the next step for this
family. 30 unmatched classes inherit `Unk_2431de8`'s `vf_type` in all: 28
with the object's D2 copied, 2 with D2s of 272 and 372 bytes. It's the
only one of the 43 classes written with an inline `vf_type` that others
inherit.

5 classes match, 42 functions (check.py: 29,238 matching, 107 not matching).

### Batch 22: address-taken leaf functions, copies and moves

Next step 6 below: the leaf functions that `leafgen.py` refused only for how
they're reached. `--reach call,none,data` (default `call`) adds the ones
whose address is only taken in code (`none`: the copy operations of
type-erased callables, put in a table on their caller's stack, and
functions nothing references) and the ones in a function-pointer table that
isn't a vtable (`data`: no-op callbacks in static records). A vtable slot is
still never a candidate: `vtables.py` writes those as members. Their real
names come from templates and enclosing functions nobody has decompiled, so
they're placeholders like every other leaf (`Unk_<addr>_set`, ...).

Two shapes of those copy operations needed the lifter to change:

- **Struct copies.** A copy of x0's first 16, 24 or 32 bytes to x1 with
  `ldp` is clang's copy of a struct (memcpy order: `ldp x8, x9, [x0] ; ldr
  x10, [x0, #0x10] ; stp x9, x10, [x1, #8] ; str x8, [x1]`); field by field
  it copies with `ldr`/`str` in source order. `Emitter.copy` writes
  `*value = *self` (one struct type for both).
- **Moves.** `ldr x8, [x0] ; str xzr, [x0] ; str x8, [x1]` reads a field
  before a store that may overwrite it, so the source held it in a local
  (`u64 v0 = self->field_0; self->field_0 = 0; value->field_0 = v0;`).
  `lift` records how many stores ran before each load and each store
  (`load_seq`, `store_seq`), and `Emitter.value_locals` declares a local
  where a store between the load and its use may alias it (another
  pointer, or the same field: `-fno-strict-aliasing`). Before, the lifter
  read such a load where it was used, after the store: a different meaning,
  which check.py rejected.

The same run covers the libraries without public source that were built
like Game Freak's code (docs/compiler.md, "Nintendo SDK middleware" and
"Other middleware"): NEX, Pia, NintendoWare and the nn SDK's static
libraries (`middleware`, `middleware-nw`) in `lib/nx_middleware/leaf`, and
YEBIS in `lib/yebis/leaf`, up to 64 bytes. Wwise was built with clang 6.0.1
and isn't included.

```sh
python tools/leafgen.py write --max 32 --reach call,none,data
python tools/leafgen.py write --max 64 --reach call,none,data --area middleware --area middleware-nw     --out lib/nx_middleware/leaf
python tools/leafgen.py write --max 64 --reach call,none,data --area yebis --out lib/yebis/leaf
```

(`names` takes `--dir` for each directory.) The trial wrote 8,269
functions; 8,116 match, in both games: 7,161 in game code, 814 in NEX/Pia
and the SDK, 141 in YEBIS. The 153 that don't are mostly loads of a field
of a field (`ldr x8, [x1] ; ldr x9, [x0] ; str x9, [x8]`, which clang
orders differently from the lifted source), bitfield updates and tail calls
with their arguments loaded from memory (check.py: 37,354 matching, 107 not
matching).

### Batch 23: tables and strings a leaf returns

718 functions in static records are `mov w8, #N ; str w8, [x0] ; adrp x0, T ;
add x0, x0, T ; ret`: they store a count and return a table (`*count = N;
return table;`). `adrp` + `add`, not a GOT load, means the table is defined
in the function's own TU (default visibility goes through the GOT). Its
contents aren't written here (they're data): the lifter declares it
`extern const u8 Unk_<addr>[] __attribute__((visibility("hidden")));`,
which clang reaches the same way, and returns it. Where the address is a
C string, the function returns the literal instead (check.py compares
literals by content), and an address in code or in a vtable is refused.
`candidates()` sets the hook (`DATA_AT`) from the executable.

`--max 128` this time (128 adds nothing over 64). The trial wrote 962
functions, 769 match (766 game code, 3 NEX/Pia/SDK), and `--record-data`
recorded the 730 tables, each at the address its name gives, the same in
both games (check.py: 38,123 matching, 107 not matching).

### Batch 24: references added and dropped through the interface

gflib3's reference-counted objects (`src/gflib3/Unk_239a418.h`) have an
interface at `+0x48` whose slot 2 adds a reference and slot 3 drops one.
`Unk_239a418_Ref<T>` calls them as `static_cast<Unk_239a458*>(p)->vf4()`
and `->vf5()`: `ldr x8, [p, #0x48]! ; ldr x1, [x8, #0x10] ; br x1` (or
`#0x18`) as a tail call. The lifter now reads that shape (`Vptr`, `Iface`,
`VSlot`, `Lifted.vcall`): the field or argument becomes an `Unk_239a418*`,
and a file with such a function includes the header. Most are the copy
operations of type-erased callables that hold a reference (copy the
fields, then add a reference if the pointer isn't null) and releases of a
global's (`p = g; if (p) { g = nullptr; p->vf5(); }`).

Value locals (Batch 22) can now sit before a guard (the pointer a copy
stores, then tests), and a pointer field copied to another field makes that
one a pointer of the same type. A load into its own base register
(`ldr x0, [x0, #8]`) used to be recorded under the wrong key.

The trial wrote 758 functions; 511 match (509 of them with the reference
calls). Left: the copies that start with an `ldp` pair before the reference
(a struct copy of the first fields, then the `Ref`'s copy), which want the
callable's struct with a `Unk_239a418_Ref` member copied as a whole
(check.py: 38,634 matching, 107 not matching).

### Batch 25: calls in a frame

The lifter now takes straight-line functions that call: the prologue and
epilogue (the frame record and callee-saved registers saved to the stack,
`_is_frame`) are skipped, `bl T` is a call whose arguments are the registers
written since the previous call (or passed on from the caller, before the
first), x0-x18 are clobbered after it, x19-x28 keep their values, and w0/x0
read afterwards is its result (`u32` or `u64` as the function reads it,
held in a local `r<n>`). A final `b T` after the epilogue is the last call
of a void function. A call may change any memory, so a load before it that
is used after it is held in a local (Batch 22's value locals), and a
function returns x0 only if it wrote it after the last call. A frame
without a call, or a call without a frame, is refused.

Callees are declared like tail-call targets (`Unk_<T>` with `void*` for
pointers). A callee already matched (`KNOWN`) is called by its own
prototype; one named already as another caller's placeholder is called with
the parameters its mangled name spells (`placeholder_params`); other named
callees (SDK functions, members) are refused. Two functions of one file
that declare a callee with different return types don't compile together,
so `write_files` drops the later one (`consistent_declarations`).

The trial wrote 780 functions; 194 match (check.py: 38,828 matching, 107
not matching). Most of the others pass a pointer where the callee's other
callers pass an integer (or the other way round), so their callee's mangled
name differs, or reload a field the original kept in a register.

### Batch 26: guards in a frame, virtual calls

- **Guards in a frame.** A `cbz`/`cbnz` may now skip to the epilogue (the
  other path restores the frame before its `ret`), and a function with a
  guard may call. The guard is an event of its own in the statement order
  (`guard_seq`), so a load after it is read inside the `if`, and one before
  it, used after a store or call, is held in a local before the `if`.
- **Virtual calls.** `ldr x8, [obj] ; ldr x8, [x8, #slot] ; blr x8` with
  x0 = obj (or `br` as a tail call, the function's last statement) calls
  `obj->vf<slot / 8>(args...)`. obj's placeholder struct becomes
  polymorphic: a virtual function per slot up to the last one called, none
  defined (so no vtable is emitted), its fields after the vptr. The
  branch register isn't an argument.
- **References through the interface, not as tail calls**: `blr` through
  the `+0x48` interface (Batch 24) inside a frame, e.g. `Unk_239a418_Ref`'s
  destructor (`if (p) { p->vf5(); p = nullptr; }`).

The trial wrote 1,012 functions; 533 match (check.py: 39,361 matching, 107
not matching).

### Batch 27: more guards, and callees as their other callers see them

- **More guards.** Several branches to the same exit are early returns
  (`if (!p) return;`) inside the first guard, and a guard may test a bit
  (`tbz`/`tbnz`) or the flags (`b.<cond>`, after a `cmp`/`tst`), or a
  call's result.
- **Callees.** Within a run, a placeholder callee's parameters are declared
  the way most of its callers pass them, a pointer where any of them passes
  one (`unify_calls`, a second pass); a field passed where a pointer is
  wanted becomes a `void*`. Calls to matched leaf functions with longer
  names (`Unk_<addr>_getField8`) use their prototypes (`KNOWN`).
- **Files.** A function whose placeholder callee has the name of a struct
  in its file (`Unk_<addr>` is both the function at `<addr>` and the struct
  of that function's first argument) is dropped like a conflicting
  declaration: one such file failed to compile in the first trial.

The trials of these three changes added 24, 27 and 88 matches; the run
kept writes 89 functions, 88 match (check.py: 39,703 matching, 42 not
matching, with #86's libcurl).

What's left for the lifter, by refusal (game code, up to 128 bytes, after
this batch): stores to TU-local statics in static initialisers (~710,
which end in a tail call of `__cxa_atexit`), functions with stack locals
(~510), callees named but not placeholders (~490, mostly constructors of
the hand-written bases), branches to other code than the exit (~480),
extended and shifted register operands (~670). Each needs more than a
pattern: a structurer for `if`/`else`, or the callers' classes.

### Batch 28: two paths, and the TU's own globals

- **Two paths.** A function with one forward branch whose two paths each
  end in their own return (no join) is lifted path by path (`two_paths`):
  the code before the branch with each path, the branch the fallthrough
  didn't take recorded as its condition (`Lifted.split`). The statements
  before the branch must come out the same, and so must the parameters
  (`const` only where neither path writes through one); where one path
  returns a constant, the function returns the other's type. It's written
  `if (<the fallthrough's condition>) { ...; return; }` then the branch's
  path.
- **Globals of the TU.** `adrp x8, G ; ldr w0, [x8, #G]` (and the stores)
  reach a global without the GOT: the TU defines it. It's declared
  `extern u32 Unk_<addr> __attribute__((visibility("hidden")));` like the
  tables of Batch 23 (in `.data`, `.bss` or `.rodata`, not a string, code or
  a vtable).

The trial wrote 711 functions; 123 match: 37 in game code, 25 in NEX/Pia
and the SDK, 61 in YEBIS. `--record-data` recorded 36 globals, each at the
address its name gives (check.py: 39,826 matching, 42 not matching).

### Batch 29: Wwise, and `if` without `else`

- **Wwise.** Its leaf functions go to `lib/wwise/leaf`, built with clang
  6.0.1 like `lib/tlsf` (its own `pkmn_library_settings` entry, evidence
  docs/compiler.md, "Wwise"): 166 match, of 190 written.
- **`if (c) { A } B`.** `two_paths` also takes a branch that skips into code
  the fallthrough runs too: the fallthrough's path is the code before the
  branch, A and B, the branch's path the code before it and B, and B must
  come out the same at the end of both. 6 match, of about 20 written: B
  usually differs between the paths (a call's local is numbered after A's
  calls, or clang keeps a value in another register).

Bigger size limits add nothing (`--max 512` lifts 7 more than 128): what's
left is loops and nested branches. check.py: 39,997 matching, 42 not
matching.

### Batch 30: compares with an extended argument

`cmp w8, w1, uxtb` (or `uxth`) compares with an argument of 8 or 16 bits,
which the caller needn't have extended (the AAPCS64 leaves its upper bits
unspecified): the argument becomes a `u8` (`u16`). The shape is common (490
such compares in game code up to 128 bytes), but most of them sit in
functions with loops or several branches: 10 match (check.py: 40,007
matching, 42 not matching).

### Batch 31: decision trees

`decision_tree` generalizes `two_paths` to several forward branches without
joins: every path through the function (up to 16; an unconditional `b`
inside it is followed, one out of it is a tail call) is lifted on its own,
with each branch on it recorded as taken or as the condition it runs under
(`Lifted.splits`). The code between two branches must come out the same on
every path through it, and each path ends in its own return; it's written
as nested `if (<the fallthrough's condition>) { ...; return; }`. The size
limit goes to 256 bytes (more paths fit).

The trial wrote 711 functions; 87 match (check.py: 40,094 matching, 42 not
matching).

### Batch 32: what the mismatches showed

Compiling a sample of the trials' mismatches alone and comparing them
with the original found four fixes:

- **A virtual tail call after other calls** (`br x4` after the epilogue)
  is the function's last statement, not something it returns (58
  `unique_ptr`-like releases: take the pointer, null it, destroy the
  object and free it through its allocator).
- **A virtual call's object** loaded before an earlier call is held in a
  local, like a call's arguments.
- **Locals are declared in the order the function loads them**, not by
  name: clang numbers the callee-saved registers in that order.
- **A copied head.** A callable's copy that moves its first 16 bytes or
  more with `ldp`/`stp` and then copies a reference (Batch 24) starts with
  one struct, `Unk_<addr>_head`, assigned whole (`copy_head`).
- **`br xN`** (N < 8) as a virtual tail call passes x1..x(N-1) on: clang
  takes the first register after the arguments.

The trial wrote 634 functions; 170 match (check.py: 40,264 matching, 42
not matching).

### Batch 33: static objects of the TU, and the SDK's imports by name

- **Static objects.** `adrp x19, S ; add x19, x19, S` then stores through
  x19 write a static object of the TU: declared
  `extern Unk_<addr>_Data Unk_<addr> __attribute__((visibility("hidden")));`
  with a placeholder struct of its fields (`Unk_<addr>.field_N = ...`). A
  file drops a function whose struct another of its functions defines, or
  that declares a global with another type.
- **SDK imports.** A call to a PLT stub is a call to the import it names
  (check.py resolves it by name through the stub). A free function whose
  mangled name spells only builtin parameters is declared in its namespaces
  and called by its own name (`demangle_simple`): `u64
  nn::ldn::MakeIpv4Address(u8, u8, u8, u8)`, the result read as the caller
  reads it.

Most of the matches are one static initialiser, repeated in every TU that
includes an nn::ldn header: it builds three `Ipv4Address` constants with
`MakeIpv4Address` (127.0.0.1, the broadcast and the any address) and the
fields around them. The trial wrote 1,207 functions; 763 match, and
`--record-data` recorded the 751 static objects, each at the address its
name gives (check.py: 41,027 matching, 42 not matching).

### Batch 34: C library calls, namespaced pointer types, abort

- **The C library.** A C name doesn't spell its parameters: `LIBC` lists
  the ones game code calls (`memset`, `memcpy`, `strcmp`, ...), declared
  with C linkage and the builtins' own types (`LIBC_DECL`), so the call
  isn't a C++-mangled symbol.
- **Pointers to a type of the import's namespace** (`LockMutex(MutexType*)`):
  `demangle_simple` follows the mangling's substitutions (`S_`, `S0_`), the
  type is forward-declared in its namespaces, and a field passed as one
  becomes a pointer of that type.
- **`abort()`**, an import that doesn't return, ends a path
  (`Lifted.noreturn`): `if (...) { ...; return; } abort();`.

Two trials, 29 matches: most functions that call these also do things
the lifter doesn't (loops, stack locals). check.py: 41,056 matching, 42
not matching.
### Batch 35: implicit destructors with their constructors, `destroy_deallocate`

A census of why `write` leaves classes out (the refusal points in
`derive_external`, and the owners of the D2s classes share) found two
cheap groups.

**Classes with nothing but their destructors.** 238 classes in
game/battle_engine have 2-slot vtables: an empty D2 (`0x710081c590`, a
`ret`) and their own `b operator delete` D0, right after their
constructor. Their constructors (`src/unsorted/ctor`) all call
`Unk_23acc98`'s (`0x710082a930`), whose own vtable holds the same D2: it's
the root, with an empty inline destructor, and the others' destructors are
implicit, so clang uses its D2 for theirs. With no function to be a key
function, a class's vtable, and its D0 with it, is emitted in its
constructor's TU. `owners()` had given the D2 to a sibling,
`Unk_23acbb8` (the lowest of the tied vtables), and `write` wrote it an
out-of-line destructor.

- `ctor_bases` follows the constructors (`find_ctors`' shapes) from a
  class to its base, and `ctor_roots` finds, for an empty D2 in slot 0 of
  2-slot vtables, the class up that chain whose own 2-slot vtable holds it
  and whose base's doesn't.
- `write` gives such a D2 to its root and leaves the root to `ctors`
  (`Unk_81c590.cpp` goes; `Unk_23acbb8` is a constructor class now).
- `ctors` (`implicit_dtors`) declares those classes without a destructor
  and the root with `virtual ~R() {}`, when each D0 lies in its
  constructor's segment, and names the D0s and the root's D2
  (`_ZN11Unk_23acbb8D2Ev` becomes `_ZN11Unk_23acc98D2Ev`).

**`destroy_deallocate`.** Most of the classes with a `b operator delete`
after their destructors have an empty destructor pair and 7 slots: the
D2 and D0, two clones, `destroy` (a `ret`), a `b operator delete` and a
call. That's libc++'s `std::function` callable
(`__func`: `__clone()`, `__clone(__base*)`, `destroy()`,
`destroy_deallocate()`, `operator()`; no `target`s without RTTI) for a
trivially destructible lambda, whose `destroy_deallocate` frees the
object without destroying anything. `write` writes a `b operator delete`
after the destructors as `void vfN() { ::operator delete(this); }`: the
global one (classes on the object declare an empty one of their own).

237 new D0s, one constructor (`Unk_23acbb8`'s) and 285 `destroy_deallocate`s:
523 functions match, every candidate the trial wrote except two
constructors a batch before had left out (check.py: 41,579 matching, 42
not matching).

### Batch 36: locals on the stack

`sub sp, sp, #N` / `add sp, sp, #N` belong to the frame, and the frame's
other addresses (`add x1, sp, #8`, `sub x0, x29, #4`, loads and stores at
`[x29, #-k]` or `[sp, #k]`) are locals: `LocalAddr`, x29-relative. Each is
declared uninitialized at the top (`u32 l4;`), typed by how it's read or
written, or, when only its address is passed on, by its size up to the next
local or the frame record. That's the out-parameter shape: `u32 l4;
Unk_<T>(self, &l4); return l4;`, including SDK calls
(`nn::crypto::GenerateCryptographicallyRandomBytes(&l4, 4)`).

The trial wrote 545 functions; 38 match (check.py: 41,617 matching, 42 not
matching).

### Batch 37: base D2s with references, template members

Two shapes from a census of the D2s of classes on hand-written bases that
`write` refuses (the D2s that call or inline a hand-written base's D2,
grouped by pattern):

- **A base whose inline D2 has references of its own.** 22 classes on
  `Unk_23c44f8` (inline destructor, three references) have 232-byte D2s:
  their vptrs, a member at +0x80, then `Unk_23c44f8`'s D2 inlined, which
  stores its vptrs and releases +0x78, +0x68 and +0x60 before the object's
  part. `ref_members` took the inlined D2 to be the object's.
  It now takes the base's D2 as it is: the class's references, then the
  base's (its loads follow, and its statics follow the class's vtable).
  Their `vf7`s aren't written, so a class on an inline base with references
  and nothing else to be its key function gets its destructor written out
  (Batch 18), as on the empty base. 16 hold a reference; the other 6 hold a
  callable at +0x80, which `ref_members` doesn't read yet.
- **A member of a class template.** The 19 classes on `Unk_23f5d00` that
  store their vptrs and then only tail-call its D2 (#74): clang skips the
  vptr stores of a destructor whose body is empty when every member's
  destructor has an empty body too (`CanSkipVTablePointerInitialization`),
  and a destructor whose body it hasn't seen isn't empty
  (`FunctionDecl::hasTrivialBody`). A class template's members are
  instantiated at the end of the TU, and an out-of-line destructor is
  emitted where it's defined. So a member of a class template with an empty
  user-provided destructor gives exactly these D2s, D0s and thunks; a plain
  class's doesn't (checked with clang 7.0.1 and the game's flags). The
  member is `Unk_23f5d00_Member<void>` (`src/unsorted/Unk_23f5d00.h`) at
  +0x180; what it really is isn't known. `tail_members` reads the shape
  (`_STORED_ONLY`), and the destructor is the key function.

To size the trial, `write` ran with every candidate before and after the
change (`--out` to a scratch directory), and `--only` listed the 172 new
ones. All 172 match: 16 classes with 6 functions each (D2, D0, four
thunks) and 19 with 4 (check.py: 41,789 matching, 42 not matching).
### Batch 38: callables among the members of inline bases

`tail_members` (Batch 13) reads references and callables before a tail
call of an out-of-line base's D2. On an inline base, `ref_members` read
references only, the first of them right after the vptr stores.
`inline_members` reads what `tail_members` does, a callable first too (its
manager's load scheduled between the vptr stores, `_VPTRS_CALL`), followed
by the base's D2 inlined as `ref_dtor_pattern` splices it: the object's,
or one with references of its own (Batch 37). `tail_members`' decoding is
`_members`, shared.

The trial wrote 318 new functions for 38 classes: 30 on the object (the
callables first, then references; their `vf_type`s, getters and type
thunks too) and 8 on `Unk_23c44f8`, the 6 Batch 37 left out among them.
All match but `Unk_23c3170`'s D0 and thunks: its D2 (280 bytes, three
callables) matches, but the original's D0 and thunks inline it and ours
don't, a cost near clang's threshold. 312 functions are kept (check.py:
42,101 matching, 42 not matching).

### Batch 39: library classes' small virtual functions, as members

`vtables.py` writes Game Freak's classes only. The libraries' vtables
(YEBIS's and NEX/Pia's with RTTI, Wwise's without) have about 2,900 small
virtual functions of the kinds `vtables.py` lifts (constants, `ret`s,
`nullptr`s, small getters and setters, traps). `leafgen.py members` lifts
them like leaf functions and writes each as a member `vf<slot>` of its
class: the class's name is its RTTI's (`N4PPFX16SiYebisAllocatorE` is
`PPFX::SiYebisAllocator`; namespaces and enclosing classes mangle alike, and
templates are left out), or `Unk_<vtable>` without RTTI, like `vtables.py`'s.
The body reads through the leaf function's placeholder struct, `this` cast
to it. A function's owner is `vtables.owners`'; slots 0 and 1 (the
destructors) are left out, and so is a second function for a slot another
of the class's vtables already gave it. One file per class in
`lib/yebis/class`, `lib/nx_middleware/class` and `lib/wwise/class` (built with
clang 6.0.1 like the Wwise leaves); `member-names` reads the mangled names
from the build by each member's prefix.

The trial wrote 1,899 members of 507 classes; 1,893 match: 799 in YEBIS, 814
in NEX/Pia and the SDK, 280 in Wwise (check.py: 43,994 matching, 42 not
matching).

### Batch 40: the libraries' other virtual functions

`members --all-kinds` takes every slot function the lifter handles
(calls, guards, decision trees, ...), not only the small kinds, up to 256
bytes, and writes the members it wrote before again with their class
(rows named with a member's own prefix), so one run sees each class whole
and gives each `vf<slot>` one function. A class file that compiles member by
member but not together (two members declaring overloads of one placeholder
callee) keeps the members that still compile with the others.

The trial wrote 2,599 members, 708 of them new; 358 of the new ones match.
Rewritten with its class, one earlier member's slot went to another of the
class's functions (its name moved with it, and the old function is a
placeholder again), and one, `SiSDK3::SiGfxShaderGraphNodeType::vf2`, is no
longer written (check.py: 44,351 matching, 42 not matching).

### Batch 41: game classes' members through the whole lifter

`vtables.py`'s own lifter (`lift_member`) merges what a member reads into
its class's fields, so it takes only straight-line code up to 64 bytes
that touches `this`'s fields. When it refuses one, `cast_member` now tries
leafgen's whole lifter (calls, guards, decision trees, up to 256 bytes),
with `this` cast to the placeholder struct leafgen reads it through; the
struct and its callees' declarations go before the file's classes
(`Lifted.structs`). Its return and parameter types must be scalars (an
override's must match the base's), and it must compile alone. In a file, a
cast member whose declarations clash with another's (or with the file's
forwarder and tail-call declarations; a second parameter list for a callee
counts, as a call could be ambiguous) keeps only its declaration.

Of 9,000-odd slot functions of classes `vtables.py` writes, 258 lift that
way; 119 match after the keep run (check.py: 44,470 matching, 42 not
matching).

`leafgen.py members` can also take game areas (classes nobody defines under
`src/`), but `vtables.py` writes every named slot function, so the two
would compete for the same classes: game code's classes are left to
`vtables.py`.

### Batch 42: template library classes

About 850 of the libraries' unmatched virtual functions belong to template
classes (`nn::nex::DataStoreClientTemplate<nn::nex::DataStoreLogicServerClient>`,
`nn::nex::PseudoGlobalVariable<bool>`, ...), whose RTTI names `members`
refused. `template_class` takes the demangled name (llvm-cxxfilt) when all
its arguments are types (classes, scalars): the primary template and the
argument classes are declared, and the members go in an explicit
specialization, whose members mangle as the instantiation's. Each class file
now records its RTTI name (`// RTTI: ...`), and `member-names` takes the
mangled prefix from it.

75 more match (check.py: 44,545 matching, 42 not matching).

### Batch 43: paths that set up the frame and don't call

In a function with a frame, the path that returns early (before any call)
was refused as "a frame without a call"; one path of several may have the
function's frame and no call. Rewritten with their classes, the members of
earlier runs keep their slots ahead of new ones, are recognized by their
RTTI name's own mangling (template classes' too), and a library class that
a game class declares as its base (`vtables.py`, since Batch 41) is still
the library's. 31 more match (check.py: 44,576 matching, 42 not matching).

### Parameters the code says a function takes (`leafgen.py widen`, 2026-11-19)

A leaf's parameters used to be the argument registers it reads, and a tail
call's arguments the ones it wrote, up to the last. That's too few when it
passes registers on that it doesn't read: `ldr x0, [x0, #0x5a0] ; b
Unk_e809d0` (0x7100e809c0) was `Unk_e809c0_call(const Unk_e809c0*)`, but
Unk_e809d0 reads x1 too, and the leaf's 189 callers pass it. A hand-written
caller that passes the second argument couldn't call the matched name.

The rule now: **a function takes the argument registers its code reads,
itself or by passing them on untouched to what it calls, and the ones its
callers write for it.** `tools/nx/argregs.py` reads both from the
instructions:

- `Params` (`Resolver.params`): x0..x7 read before they're written, on any
  path, directly or through a copy (`mov x19, x1`). At a `bl T` or a tail
  call `b T`, the registers T reads (recursively, four levels deep) count as
  read; at an indirect call (`blr`/`br`) only those the function moved
  there for it (nothing says the target takes a register left untouched).
  The base of a load or store is a pointer, a register only read as `w<n>`
  32 bits. A function that stores x7 as it got it on the stack is variadic
  (`...`'s save area): those stores aren't parameters.
- `call_sites`: at each `bl F` / `b F`, the argument registers the caller
  wrote and didn't read again, when the write reaches the call with no
  conditional branch after it (one before a branch may be for the other
  path). With `-O3` a register isn't written for nothing, and x0..x7 don't
  survive a call: such a value is an argument. `adrp`/`adr` or an `add` to
  `sp` is a pointer.

`leafgen.inferred_types` turns that into parameter types: the ones declared
now, then one per further register, `void*` for a pointer, `u32` for 32
bits, `u64` otherwise; a placeholder callee's `u64` that it dereferences
becomes `void*` (no source spells it yet; a second choice keeps the
integers, for callers that pass a global or a computed value there).
`SIGNATURES` holds them, and `call_params(T)` is what a call to T passes:
T's prototype if it's a leaf already written (`KNOWN`), then `SIGNATURES`,
the longest caller's (`TAIL_TYPES`), or the parameters **T's placeholder name
in functions.csv** spells (`_Z10Unk_e809d0PvS_`: `NAMED`). So the name is
the signature: once a placeholder is renamed, every later run (`write`,
`vtables.py write`, ...) passes what it takes. `lift` pads a tail call (and
a call in a frame, before the first call) to that many arguments with the
registers the function leaves untouched, which makes them its parameters;
a field passed to a `void*` parameter holds a `void*` (a global too); a leaf
whose callers write more than it reads gets the rest as unused parameters
(`u32 /*unused*/`). Mangled names now spell substitutions (`encode_params`:
`(void*, void*)` is `PvS_`), so a placeholder can take two pointers.

`write` and `scan` infer the candidates' signatures (and their unnamed
callees', without the pointer upgrade) before the last lifting pass;
`--no-signatures` turns that off. `widen` does it for what's written:

```sh
python tools/leafgen.py widen --names widen.csv --report widen_report.csv
python tools/funcs.py name --force --from-file widen.csv
python tools/check.py                    # every renamed function should still be OK
python tools/check.py --update
```

It takes every matched leaf in `src/unsorted/leaf` and `lib/*/leaf` (`--dir`
for fewer) and every placeholder callee they declare, widens them, and
writes again each leaf that is widened or declares something that is.
Until nothing changes: a leaf called by another leaf's prototype (KNOWN)
gets its callers written again too. A leaf that doesn't lift or compile
again, or whose new declarations disagree with the rest of its file (a
global read as `u64` by its neighbours), stays as it is, and so does
everything it declares (a placeholder with a second choice tries that
first). Another source that calls one of them keeps it too (it would pass
other arguments); one that only declares it, or takes its address (the
battle sequence tables in `src/unsorted/Unk_9be950.cpp`), gets the new
declaration. `--only` limits the leaves that may change (a keep run).

The run: 550 matched leaves and 924 placeholder callees are narrower than
their code says (`--report`). 531 of the leaves take more parameters now
(19 stay), and 158 more are renamed because a parameter they pass on is a
pointer now; 776 placeholders are renamed (364 take more parameters, 412
take pointers), 148 stay: 132 because a caller can't be written again, 16
because other sources call them: `vtables.py`'s members (`Unk_68d9b0`,
called by `Unk_11cb690`'s with a `u64` field, is one), the battle
sequence functions (`Unk_8ea3b0`, `Unk_8ea490`, `Unk_140b690`), NEX and
`leafgen.py members`. 1,465 functions renamed, all of them still matching
(check.py: 49,967 matching; the only REGRESSIONs, 53 `vector<Unk_239a418_Ref<T>>`
growth functions of `src/gflib3/families`, are master's, since the
reference's copy constructor changed). `Unk_e809c0_call` is
`(const Unk_e809c0*, void*)` and `Unk_e809d0` `(void*, void*)` now.

Next: `vtables.py write` passes what a placeholder's name says too (it
lifts with leafgen's `call_params`, but `NAMED` is only filled when
`cast_member` runs first), so with `NAMED` filled from functions.csv
there, `widen` could rename the 12 placeholders `src/unsorted/virtual`
calls and `vtables.py write --only <empty>` would write their callers
again.

### The largest functions: generated tables (2026-11-19)

The four largest undecompiled functions of game code were tables written out
in full, and they matched by hand-written source with a generated body, about
2.2% of the code by bytes:

- **Battle sequence tables** (`src/unsorted/Unk_9be950.cpp`,
  `src/unsorted/Unk_23c4ef0.h`): the constructors of `Unk_23c4ef0`
  (`0x71009be950`, 239,176 bytes) and of the `Unk_23c4f18` it holds
  (`0x71009fd0e0`, 239,124 bytes) fill an `unordered_map<u64, function>`
  each with 385 `emplace`s, inlined: the same 385 hashes in both, mapped to
  functions of the same segment (one table's are mostly the `Unk_<addr>_update`
  no-ops). The map's memory comes from gflib3's allocator through a container
  allocator (`src/unsorted/Unk_2771620.h`) that pushes it on the thread's
  allocator stack (TLS slot `Unk_2771620`, 16 entries) while it constructs,
  and the map itself is made the same way (`Unk_2771620_MakeUnique`). The
  hashes must be `u64` literals (`ul`): a hex literal below 2^63 is a `long`,
  and libc++'s `emplace` then constructs the node first
  (`__emplace_unique_impl`), a different function. The destructors, `vf2`
  (`map->find(*hash)->second(...)`) and the map's `rehash`/`__rehash` match
  too. `Unk_23c4ef0::vf2` (`0x71009f93a0`, a `switch` on the hash) and the
  `Unk_95c520` it calls aren't decompiled.
- **239 objects on `Unk_23acc98`** (`src/unsorted/Unk_7e0080.h`,
  `src/unsorted/Unk_81c630.cpp`): `0x710081c630` (48,600 bytes) allocates and
  constructs each of 239 members of an object, each a class of its own on
  `Unk_23acc98` whose constructor passes its argument to `Unk_23acc98`'s
  (`0x710082a930`, which copies 0x60 bytes from it); `0x71007e0080` (13,356
  bytes) is the object's destructor. The constructors were `vtables.py
  ctors`' already, as `Unk_D::Unk_D() {}`: `CTOR_PARAMS` gives a root's
  family the parameter, and their classes go in a header of their own
  (`src/unsorted/ctor/Unk_23acc98.h`), which the constructor files and
  `Unk_81c630.cpp` include (a class defined elsewhere in `src/` would stop
  `ctors` from writing it). `ctors` also takes a constructor whose vptr is
  in a page's first GOT slot (`ldr x8, [x8]`): one more of the family.

The libraries' largest win was FreeType 2.8.1 in YEBIS (docs/compiler.md,
"FreeType 2.8.1"): 373 functions, 184,584 bytes. Byte progress after these:
25.16% (check.py: 44,938 matching, 42 not matching).

### One block repeated, and code without branches (2026-11-20)

Two rankings of the undecompiled functions find code that is written faster
than it reads: the share of a function's 8-instruction windows that recur
(immediates masked), and its conditional branches per KB. At the top of the
first was YEBIS's `PPFX::TEXSHADERSET::CreateEffect` (36,868 bytes, 92%
recurring, 26 branches: lib/yebis/README.md); the second lists about 260 KB of
functions over 1.5 KB with under 7 branches per KB, most of them static
initialisers (which need their TU's globals) and unrolled loops.

- `src/unsorted/Unk_dcfdf0.cpp` (3,088 bytes, matches): 46 parameters of the
  balloon minigame, each `field = root.Unk_11063e0("NAME").Unk_11067c0(field)`
  on the data document's nodes (`unsorted/Unk_1106320.h`). 113 undecompiled
  functions (144 KB) call those accessors; the others have loops over arrays
  and string values (references to release).
- `src/unsorted/Unk_138a350.cpp` (4,980 bytes, `M`): a history of 50 records
  of 0x68 bytes, shifted up by `std::copy_backward` (the pointer loop is
  small enough to unroll fully: 5 IR instructions a record, under the
  threshold of 300; an indexed loop isn't). Same instructions but for one
  store the scheduler lets float (the note in the file).
- `src/battle/battle_engine/Unk_813d60.cpp` (4,960 bytes, `M`): the reader of
  the battle commands' arguments, a switch over 46 argument formats (bytes,
  big-endian 16-, 24- and 32-bit values, bit fields in them), written from a
  bit-level walk of each case. 6 instructions differ, in which cases share
  their tails. Its writer, `0x71008151d0` (4,432 bytes), packs the same
  formats and isn't written.

### Type getters and kind tests (`tools/typegen.py`, 2026-11-19)

The functions that group by shape (unmatched functions hashed with branch
targets and adrp/lo12 fields masked: 3.7 MB in groups of two or more) were
led by the type getters: the `vf_type`s of classes on gflib3's object, the
out-of-line getters they call, and the kind tests that walk a type's
parents. `tools/typegen.py` rebuilds the type tree from them (every getter's
stores: 1,737 types, none with two parents) and writes them in
`src/unsorted/types` (its docstring has the details):

- 364 classes in the object's layout whose `vf_type` and thunks are
  getter-shaped, and 146 whose `vf_type` and thunks tail-call the
  class's own getter (vtables.py's forwarders to a placeholder `Unk_<G>(void*)`:
  their getters are renamed and emitted here, and vtables.py skips what this
  tool writes);
- 126 of the 159 kind tests, `Unk_61a530<T>`, one explicit instantiation per T;
- 153 `vf_type`s whose thunks are `sub x0, x0, #N ; b vf_type`, alone: as
  plain members of a struct named like their class (same symbol, same code,
  and no thunks emitted), in files of their own, since their types inline
  differently next to the forwarder classes;
- 114 more getters in vtable slots that none of the above covers (other
  layouts, secondary vtables' copies, classes left out): each a plain member
  `vf<slot>` of its owner vtable's placeholder class, in files of their own.

The inliner decides how much of a chain a getter inlines with
`shouldBeDeferred`, which counts the getter's callers in its TU: so the
levels each function inlines are spelled out (defined inline) and its cut
declared, never left to clang. What's left: those 153 classes' thunks (the
original's vf_type is inline, emitted with its class's vtable; defined
strongly here, the thunks lose the adjustment), 60 forwarder classes whose getter has no other caller in its segment (clang
inlines it into vf_type, the original didn't: deferred there, with callers
we don't have), and 33 kind tests whose type isn't named or whose chain
isn't one this tool spells.

Two more families of the same shape groups are worked out but don't match
yet, both on register allocation alone (same instructions):

- the lock-and-cast of a weak handle (`Unk_239a418_Handle`: count at +0x54,
  type at +0x58, object at +0x60 through its +0x50 interface), about 150
  instances (404-492 bytes, 70 KB; 0x710000e840 is one) plus 360 KB of
  functions that inline it: a relaxed load of the count, a
  `compare_exchange_weak` loop, the kind test inlined, the object adopted
  into the returned reference. Written with the loop as `do ... while`, two
  null returns and a named result copied out, registers match and only the
  copy is extra; every spelling without the copy permutes them.
- 188 wrappers like 0x7100790140 (54 KB) around a per-type creator (the
  function right after each): take `self->field_58` when the argument's
  reference is null, call the creator with a copy, and hand the result to
  `Unk_e809c0_call(target ? target : self->field_70, result)`.
  `Unk_e809c0_call` really takes two arguments (it passes the second to
  `Unk_e809d0`): it does now (`leafgen.py widen`, above), and nothing else
  calls either. The wrapper keeps the target's adjusted pointer between its
  AddRef and its Release, where the original recomputes it.

libc++'s `rehash`/`__rehash` of 51 unordered_maps on Unk_2771620's
allocator, keyed by u64 (37) or u32 (14), match by explicit instantiation
with a placeholder mapped type (`src/unsorted/Unk_597350.cpp`: their code
doesn't read it). Two more groups of `__rehash` (24 instances) pass another
alignment to the allocator and aren't written.

### Copies of type-erased callables (`tools/clonegen.py`, 2026-11-19)

vtables.py writes the simple slots of the `std::function` model classes (D2,
D0, `destroy`, `destroy_deallocate`), but not their two copies: slot 2
(`operator new` of the object's size, then a copy) and slot 3 (a copy into
the given storage). `tools/clonegen.py` writes them for every class whose
slots 2 and 3 store its own vtable: `return new Unk_C(*this);` and
`new (p) Unk_C(*this);` with the object's u64 fields. The vtable is reached
directly (adrp/add), not through the GOT, because a lambda's class is local
to its TU, so each class is declared `visibility("hidden")`. The fields are
the ones slot 3 copies, with their widths; one after a gap is aligned to land
where it is (a 16-byte aligned capture at +0x10). All 247 classes match (494
functions, `src/unsorted/clone`). vtables.py skips what clonegen writes.
### 45 pairs of classes of one template (`tools/registrygen.py`, 2026-11-19)

Eight shape groups of exactly 45 members each (72,360 bytes, all in game
code: bag, pokecamp, unk_133d350, unk_bba3d0, ...) are one template's code,
instantiated per type: for the first, `Unk_23aa2c8` and `Unk_23aa308` in
game/bag. `src/unsorted/registry/Unk_7be640.h` has the bodies and
`tools/registrygen.py` writes the instances (its docstring has the details):

- an outer class on `Unk_23daca0` (an abstract base with a memory resource
  at +0x8, which 166 functions' classes use) with eleven entries, each able
  to hold a TLSF pool resource (`Unk_239f910`, gflib3's, now in
  `src/gflib3/Unk_65f110.h`) made in a block of the memory resource: `vf2`
  makes entry 0's through a function of its own, `vf4` frees it, `vf5` the
  other ten's;
- an inner class at +0x28, on `Unk_236d228`: an object whose constructor
  adds it to a global table of 256 pointers (0x7102777f60, count at +0x800)
  and whose destructor (0x7100003340, not virtual) takes it out, both under
  gflib3's static lock (`Unk_65f110`'s object, which `Unk_2778770` now
  spells as the lock it is). It records the block, and a static pointer of
  its own points at it while it lives.

The originals are inline, emitted in the TU of a factory that makes an
object holding the outer class (0x71007be520 for the first: allocator stack,
three vptrs, the outer class at +0x558). With their callers there, LLVM 7's
inliner defers inlining the inner constructor into the outer one and
`Unk_236d228`'s D2 into the outer D2 (`shouldBeDeferred`), and the D0
inlines both levels of D2. The factories aren't one shape, so the instances
get the same decisions another way: the outer class's key function is `vf2`
(its vtable, inline D2, D0, `vf4` and `vf5` are emitted with it, and the D0
is the D2's caller that defers), and the inner constructors are defined in
a TU of their own (`Unk_7be720.cpp`), so the outer constructors call them.
Two details matter. The outer destructor is user-declared: an implicit one
gets clang's inline hint (threshold 325 instead of 250) and nothing is
deferred. And `Unk_23daca0`'s D2 stores its vptr though its body is empty:
clang keeps a destructor's vptr stores when a member is an anonymous union
(`FieldHasTrivialDestructorBody`), the only way found to get it.

Its D2 (0x7100c38fc0, slot 0 of its own vtable, which nothing calls) was
named `Unk_23daca0`'s constructor by `vtables.py ctors`, whose root pattern
(a 20-byte vptr store) can't tell a D2 with that body from a constructor of
a class without a base. It's the D2 now, and its class is defined here
(`ctors` skips classes defined elsewhere). 32 more of `ctors`' root
constructors are slot 0 of their own vtables, so D2s too: `find_ctors`
should leave vtable slots out.

The outer vtable's `vf3` and the inner one's four slots are `vtables.py`'s
(src/unsorted/virtual): the classes here declare them the same way, and
`write --only <empty file>` leaves its files unchanged.

What matches: 315 of the 360 functions (all but the D0s),
`Unk_23daca0`'s D0 (0x7100c38fe0) and the default-resource setter
(0x7100e7b5e0). The 45 D0s and `Unk_236d228`'s D2 don't: the D2's search
for `this`. The original compares the first pointer before its loop, merged
with the test for an empty table (`cmp` of the count times 8, `ccmp`); the
`std::find` here gives one loop, and so does every loop spelled out tried
(for, while, do-while, peeled by hand, with indices or a count). Hand-peeled
comes closest: it then differs only in testing the count, not the count
times 8, which suggests the original compared the end pointer before
instcombine could reduce it. They're `M`, with `NON_MATCHING` notes.
check.py: 46,721 matching and 88 not matching (was 46,404 and 42), in both
games; 26.44% of the code by bytes.
### Families on gflib3's allocator (`tools/familygen.py`, 2026-11-19)

Three more families of the shape groups are template instances or a class
shape repeated, on gflib3's container allocator (`Unk_2771620_Allocator`) and
its object. `tools/familygen.py` finds their instances and writes them in
`src/gflib3/families` (its docstring has the details); 498 functions, about
150 KB, match in both games:

| Family | File | Functions | Bytes |
|---|---|---:|---:|
| libc++'s `vector` growing on the allocator: `__push_back_slow_path` of pointers (39), of references moved in (29) or by const reference (9), of 4- and 16-byte elements (19), `reserve` of references (15) | `Unk_5ac520.cpp` | 111 | 51,900 |
| `Unk_New::Create<T>` of classes on `Unk_23f43c8` | `Unk_8d4190.cpp` | 273 | 86,716 |
| singletons' `vf3` and its +0x48 copy | `Unk_7c20.cpp` | 114 | 11,400 |

- **Vectors.** Each instance has an element type of its own (two of one type
  would have been merged), a placeholder named after its address. A vector
  of references copies its old elements when it grows: `Unk_239a418_Ref` has
  a move constructor now, not `noexcept` (libc++ then copies), which takes
  the pointer the way `Release()` does: the source is cleared before the
  destination is stored. 15 push_backs of 8- to 16-byte elements that aren't
  a u32, a reference or two u64 (alignment 16, a reference and an int, ...)
  don't match and aren't written; nor are the 0x80-byte callables'
  (`0x7101382340`, 24 instances: `__emplace_back_slow_path` of a lambda).
- **Factories** (`src/gflib3/Unk_New.h`): allocate `sizeof(T)` with the
  allocator current, construct, record the allocation in `field_8`-`field_20`.
  The first argument isn't used: `Create` is a member of a placeholder
  struct. `T` derives from `Unk_23f43c8` and inherits its constructor
  (`0x7100e7c430`, two references by value, now declared in its header and
  named; not decompiled); `T`'s members are read from the stores after it
  (zeros and constants, each run cut at natural alignment), its extra
  virtual functions from where its secondary vptrs point. When the members
  are stored before `T`'s vptr (the instruction after the constructor call
  isn't the vtable's `adrp`), they belong to a class between `T` and the
  base: `<T>_Parent`. Not written: 48 factories of another shape (an
  out-of-line constructor two classes down, copies of references), 13 that
  store registers the tool doesn't follow, 6 with vtables it doesn't read,
  and 19 that don't match (more virtual functions with members it doesn't
  order like the original). The same factory, inlined, makes 238 classes
  derived directly from the object (`Unk_239a418::Unk_239a418` first, 96 KB)
  and 178 on `Unk_23f4660` (the "creators" below, 94 KB): their members are
  references and handles the tool doesn't read.
- **Singletons.** 57 classes whose `vf3` destroys the instance their own
  global holds, the way `Unk_239a418::vf3` destroys an object
  (`Unk_7c20_Reset`); `this` isn't used, so the +0x48 thunk is a copy. One
  function is in two vtables (a class and one derived from it).

Looked at and left:

- the creators (`0x7100790260`, 178 instances, 132 shape groups): a
  manager's method that creates a class on `Unk_23f4660` (the factory
  inlined, its size 0x5f0 and alignment 16), sets its parent
  (`0x7100e7fe20`), pushes a reference to it into a vector at `+0x78` and
  returns it. Their derived members vary like the factories' do. The
  wrappers around them (`0x7100790140`, 188) also needed `Unk_e809c0_call`'s
  real signature (two arguments), which it has since `leafgen.py widen`;
- `0x7100005e20` (54) and `0x7100010530` (55): per-TU copies of one path
  builder: a name that doesn't start with `"data:/"` (the global at
  `0x710239a578`) gets it prepended (`alloca`, `strcat`) before the name is
  looked up (`0x710000d0c0`) and parsed (`0x71000105b0`); 23 KB, needs the
  string class and the parser's state;
- `0x710059bee0` (29) and `0x7100607550` (27): a finder under a spinlock
  (the owner thread at `+0xf0`, a light event at `+0xe4`) that walks two
  vectors with a kind test (`Unk_61a530<T>`, 0x710096ccf0 for one T) and returns the
  object; `0x7100795bc0` (118): a find by key with the kind test inlined;
- the destructors' thunks of classes on the object (`0x71005b2eb0`,
  `0x71005b2f30`, 174 each): vtables.py's inline-destructor shape, which
  needs a key function for each class.

## Hand-decompiled game code: the camp, Poke Jobs, the summary (2026-11-19)

Real decompilation in `game/pokecamp` and its neighbours (38 functions,
43 KB): `src/contents/pokecamp/source` (the original's
`prog/contents/pokecamp/source`, with its own `pkmn_library_settings` entry
like `src/unsorted`'s) and a few files in `src/unsorted`. What carries over:

- **Names are FNV-1a 64 with the offset basis `0xcbf29ce484222645`**, as
  `{hash, str, len}` (`src/unsorted/Unk_112dd40.h`). A literal's hash folds
  at compile time from a constexpr constructor; a name formatted into a
  `char[N]` buffer is hashed up to its terminator with length `N - 1`. The
  camp's three sound tables (`Unk_112a570.cpp`, `@Play_Camp_*` to `PMxxx_yy`
  voices and `kw*` motions) are such names in `Unk_2771620_Map`s, whose
  values have user-written copy constructors (the nodes are copied field by
  field).
- **Data documents** (`src/unsorted/Unk_1106320.h`): a node `{root, index}`
  returned by value through x8, with element (`0x7101106320`), member by
  name (`0x71011063e0`) and int/float/string getters. The Poke Job table's
  accessors (`Unk_129e3b0.cpp`) are `Node job = table.At(i); return
  job[name].GetInt(0);`: the named local gives the original's stack order.
  About 150 more callers of the member lookup are left in game code.
- **std::sort with a lambda** (`Unk_1298270.cpp`, `Unk_12e3f60.cpp`): the
  libc++ instances (`__sort`, `__sort3/4/5`, `__insertion_sort_incomplete`,
  7-16 KB a family) match once the comparator's shape does. The original
  inlines the comparator everywhere; LLVM 7 does that only when the helper
  the lambda calls is an *inline* (linkonce) function, so `shouldBeDeferred`
  keeps it out of the lambda until the lambda is inlined. A captured `this`
  is loaded once per call (lambda prologue), captured pointers are reloaded.
  The caller of a sort can be a `NON_MATCHING` host for its instances
  (status M), like `src/field/content`'s.
- Stack slots tell temporaries from locals: a temporary that outlives a full
  expression is a named local; an inline helper's slots come first (the
  inliner moves its allocas to the top of the entry block).

Left: the camp's sort of 9 objects (`0x710120de60`-`0x710120f350`, 5 KB; the
comparator's null checks are either not inlined or laid out differently,
attempts in the PR), `0x7101166ce0` (register allocation, `m`), and
`0x7101298270`, which matches but keeps the leaf generator's name because
`src/unsorted/leaf/Unk_12994f0.cpp` calls it as `Unk_1298270(void*,
unsigned int)`. `vector<Unk_23d4470_Callable>::__push_back_slow_path`
instances (0x7101119870 and others, ~600 bytes each) need that callable's
move and copy constructors (manager at +0x10, copier at +0x18).

### Battle sequence functions (`src/battle/battle_scene`, 2026-11-19)

The battle sequence tables (`src/unsorted/Unk_23c4ef0.h`) map 385 hashes to
248 functions `Unk_<addr>(void* seq, Unk_23c4ef0_Owner* owner, const u64*
cmd)` (167 KB, in the tables' TU, `0x71009be950`-`0x7100a6c510`). 87 of them
match (23.0 KB, `src/battle/battle_scene/Unk_a38ab0.cpp`). What they share:

- The owner is the battle scene's view system, a class on gflib3's
  `Unk_239a4c0` with 340 virtual slots (vtables `0x71023c0970` and
  `0x71023c5158`; `Unk_23c4ef0_Owner.h`). Its non-virtual helpers (0x7100952670
  ... in the battle app's code) are declared as its members: `Unk_952670` is
  a target's position (id 1 with an index under `Unk_9526f0`'s count means
  "all"), `Unk_960620`/`Unk_961f10` the same for other ids (10 = all).
- Arguments come from the sequence's readers (cursor at `+0x178`,
  `0x710140b690` ...; `Unk_23c4ef0_Seq.h`), the command's frames from
  `cmd[1]`. A vector is a struct holding a `float32x4_t`: its copies go
  through two general registers, high half first, because of
  `-mno-implicit-float`.
- Names hashed with 64-bit FNV-1a (`Unk_5cfad0_Literal` and
  `Unk_5cfaf0_Name`, gflib3's, in `unsorted/Unk_d0c0.h` with the string
  `Unk_d0c0_String` the contents' apps use too): `constexpr`, so
  one made from a literal is a constant, and a name given to a function is
  a temporary in the call (passed by reference, made after the object
  pointer is read).
- Positions' objects are references at `+0x548`/`+0x580`; groups of them are
  in three `unordered_map<s32, Ref>` at `+0x640`/`+0x660`/`+0x6a0`, looked up
  with `find(cmd->field_10)->second` (no end check: clang drops it because
  the end is dereferenced) and iterated as a pointer/count range.
- New objects use gflib3's idiom (`Unk_23c4ef0_New`: the allocator current
  while constructing, its memory recorded at `+0x8`...`+0x20`) and are
  added to the lists at `+0x530`/`+0x538`.
- `Unk_239a418_Ref`'s copy constructor tests the other reference's pointer:
  these functions use a copied reference without a null check, and only
  then does the null path keep the loaded pointer (as the original does)
  instead of folding it to zero or a trap.
- Locals are laid out in declaration order (the first at the highest
  address), and where the original loads a value before the argument it
  passes with it, the value was put in a local first (or the setter is an
  inline member function).

What blocks the others:

- 79 build type-erased callables whose copy, move and destroy functions
  leafgen matched as free functions (`Unk_a6a330_call` ...). A callable
  template would emit them again under its own names.
- Callees leafgen matched with fewer parameters than their callers pass
  (`Unk_960610_call`, `Unk_965ae0_call`, `Unk_794490_call`), or with `u64`
  for a pointer (`Unk_68d9b0`): calls with those names don't compile the
  same.
- A few differ in one register or one stack slot: `0x7100a58b70`,
  `0x7100a59270`, `0x7100a599d0`, `0x7100a5f360`, `0x7100a5f4a0`,
  `0x7100a46d60`, `0x7100a51f00`, `0x7100a50e30`.
- `Unk_95c520` (16,612 bytes, the conditions `Unk_23c4ef0::vf2` checks): 43
  lookups in the command's parameter map (`cmd+0x18`, `find(hash)->second`)
  feeding switches on the owner's state; regular, but long.
### gflnet3's p2p channels, by hand (2026-11-19)

Every protobuf data holder (a message with one `oneof`) has a channel on
gflnet3's `Unk_23a3578` (`src/gflnet3/src/p2p/Unk_23a3578.h`, vtable
`0x71023a3588`, abstract): a gflib3 reference-counted object with two
callables (`+0x60` sends bytes to one peer, `+0xe0` to every peer), an id
(`vf7`) and the bytes it receives (slot 8). Each holder's class adds its
listener (`+0x168`) and, as members, a receive function (`vf8`: parse with
the heap current, then call the listener's slot for the oneof's case), one
pack per message kind (a new holder from the channel's heap, its
`mutable_<field>()->CopyFrom`) and one send per kind. The generic send
(serialize, then `+0xe0`) is a member template of the base. The derived
classes have no destructor or type of their own: their vtables have the
base's D2 (`0x71006b7de0`) and `vf_type` (`0x71006b7f20`).
`src/gflnet3/src/p2p/Unk_6b8ad0.h` has the message (`Unk_6b8ad0_Message<T>`:
the heap and a `unique_ptr` with gflib3's deleter; `operator->` returns an
access that holds a heap scope, `0x710065da00`/`0x710065daf0`) and the
callable.

17 channels are found by their vtables (slot 7 is `0x71006b8010`). 16 are
written, with their receive functions and packs: gflnet3's block, ping and
sync data channels, the nine of `net_contents`, battle_logic's five
(`BtlDataHolder`, `BtlCmdDataHolder`, gflnet3's `SequenceDataHolder`, the
two watch holders), btl_spot's and comp_organize's. Pokecamp's
(`0x710241a3a8`) is left to `src/contents/pokecamp`. The block session
(`Unk_23a33b8`) and the ping listener (`Unk_23a3638`) are written as far as
their peer bookkeeping.

Facts that decided matches:

- **Data size copies.** The sessions' vectors hold entries with initialised
  members (not PODs), so assigning one copies their data size (`0x1e`,
  `0xe` bytes) and not the tail padding. A `std::pair` gives that size too,
  but more code.
- **`clear_message()` and `Clear()`.** A data holder's two functions have the
  same code, and their names were placed by link order; the inlined
  `mutable_<field>()` calls `clear_message()`, which put the names of four
  holders' pairs right.
- **Not matching (`M`).** The receive functions of holders with three or
  more kinds (8 functions, 5.3 KB) place the paths for the kinds (one
  `default_instance()` call each) in another order. No order of the cases,
  `if` chain, `default`, or local spelled out moves them.

The sends per kind (`g15`, `g16`, `g23` shapes), the send to one peer and the
serializer (member templates of the base, named here) and the channels' D0s
are families of ten or more and aren't written.
### The demo player's commands (`src/demo`, 2026-11-19)

The 429 KB segment `0x7100bba3d0`-`0x7100c23050` (in `game/unk_bba3d0`) is
the demo (cut-scene) player: its strings are `bin/demo/...`,
`bin/archive/demo/%s.gfpak`, `demoParamList`, `isDemoSkipEnable`. The
classes on `Unk_23d4470` (the hand-written base, `src/unsorted/Unk_23d4470.h`)
are the commands of a demo sequence. `0x7100bc27d0` makes one from a description
(`Unk_23d4470_Desc`: a 64-bit hash, two frames and a value): a `switch` on
the hash with 96 cases, whose names aren't in the executable (no string
hashes to any of them), each calling a `Creator<T>` that allocates the
command from the owner's allocator with the allocator current, constructs it
and records the allocation in it. 95 creators are out of line; the switch
inlines two.

What the creators show:

- **The commands are 16-byte aligned.** Every creator asks for alignment 16,
  and the sizes are multiples of 16 (`Unk_23d4470` itself is 0x350 bytes):
  the callable's storage is aligned like a `std::function`'s buffer (one
  allocated alone, `0x7100be2a50`, asks for 0x80 bytes aligned to 16). A
  derived class's fields still start at 0x348, in the base's tail padding.
- **The constructors are inherited** (`using Unk_23d4470::Unk_23d4470;`,
  fields with default member initializers): the owner reference the creator
  moves into the by-value parameter is released after the whole object is
  built, which a constructor of the derived class's own would do before its
  vptr stores. `Unk_239a418_Ref` has a move constructor for it.
- Some commands are on other commands (`Unk_23d4b50` on `Unk_23d6728`,
  `Unk_23d8f80` on `Unk_23d7a10`, which share virtual functions) or on an
  abstract base without a vtable of its own (`Unk_c02310`); a vector of four
  floats initialized together is a `float32x4_t`.

`src/demo/Unk_bc27d0.cpp` declares the classes again, with the members their
constructors set (`src/unsorted/virtual/Unk_bbbff0.cpp` has the functions
`vtables.py` writes for them). 81 creators match (24,856 bytes), with what
their members turned out to be:

- names: `Unk_23f4660_Name`, empty (the hash of `""` and `""`), and a
  0x80-byte text followed by its 0x20-byte name (`Unk_23d4470_Text`; vf7 of
  `Unk_23d7950`, `0x7100bfe1b0`, hashes the text into it);
- holders of two callables and a reference (`Unk_23dba98`'s shape): the
  class a command holds is on a base with the same slots (its vptr is
  stored after the members), named after that base's vtable, or after its
  vf0 when it has none (`Unk_967200`);
- `unordered_map`s on `Unk_2771620_Allocator`, whose default constructor
  takes the thread's current allocator (or the default heap);
- members with out-of-line constructors (`0x71007910a0`,
  `Unk_23f2df0_1e0`'s `0x71006835f0`).

Left:

- the 10 creators of one shape group (`0x7100bca180` and the like, classes
  without fields), for whoever writes that group (the template matches
  them);
- 3 creators and an out-of-line constructor (`0x7100bcba80`,
  `0x7100bcde40`, `0x7100bce7e0`, `0x7100be2540`) that copy a function-local
  static reference (guard `0x7102773730`, made by `0x71005e6770`). Its
  atexit destructor is `0x71005e6560`, matched as a free function
  (`Unk_5e6560_reset`, `src/unsorted/Unk_5e6560.cpp`): it is really
  `Unk_239a418_Ref<...>::~Unk_239a418_Ref`, and has to be renamed first;
- `0x7100bd6e20` (`Unk_23d7538`, 0xc90 bytes: holders on `Unk_236d308` with
  a member built by `0x71005fc550`);
- the switch, `0x7100bc27d0`. `vf7` has its parameters now. Its closest
  form so far: a function-scope `command` assigned in each case through a
  macro (`command = Ref(Creator<T>()(self->field_8,
  self->field_2b8->vf2(), desc)); command->vf7(...); return command;`, so
  the inliner sees each Creator and inlines exactly the default's and
  `0x7100be2540`'s), and a `default:` that returns its own reference (built
  in the return slot: the original stores the default's command there
  before `vf7`, and the others' after it). That gives the original's
  compare tree, case bodies and registers. The default path still differs:
  clang doesn't infer `nocapture` on the return slot, so it reloads the
  command from it before `vf7`, and the registers of that path change.
  With one `vf7` after the switch instead, GVN merges the cases'
  `&self->field_2b8` into a phi (an extra `add`) and the return slot and
  the description swap registers. `Unk_239a418_Ref` needs a move
  assignment and `operator->` for it.

### Destructors in the unplaced areas (hand-written, 2026-11-19)

Classes in `game/unk_133d350`, `unk_12ed1a0`, `unk_14b14a0`, `unk_143a7a0`,
`unk_fb2de0`, `unk_761f70`, `regulation` and `startup`, reconstructed from
their D2s by hand (`src/unsorted/<area>/`, one file per class or TU). A D2
shows the class's members in reverse, and the vtable address points it
stores show its slot counts (`add x9, x8, #N`: the secondary vtables come
right after the primary one, so N fixes how many slots the class has). The
D0 and the destructor thunks follow from the same definition. 237 functions
(46,880 bytes) match in both games, nearly all D2s with their D0s and
thunks, plus a few constructors and members of the classes on the way
(check.py: 47,399 matching, 42 not matching). Their shapes, by what the
members are:

| Member | What its destruction looks like | Written as |
|---|---|---|
| reference | `ldr x8, [x0, #0x48]! ; ldr x8, [x8, #0x18] ; blr` then `str xzr` | `Unk_239a418_Ref` |
| callable | `if (mgr) { zero 4 words; mgr(storage) }` (`str` one by one past offset 0x1f8, where `stp` can't reach) | `Unk_23d4470_Callable`, arrays of them unroll |
| `std::function` | `if (__f_ == &__buf_) destroy() else destroy_deallocate()` (slots 4 and 5) | libc++ `std::function`, 16-aligned |
| owned object | `p = ptr; ptr = 0; if (p) { ~T; allocator->vf3(p, size, align) }` | `std::unique_ptr<T, Unk_23f4660_Deleter>`; a polymorphic T is destroyed through slot 0, a `final` one inline |
| owned array | the same, `size / sizeof(T)` elements destroyed first | `std::unique_ptr<T[], Unk_23c9470_ArrayDeleter>` |
| vector | libc++ `std::vector` with `Unk_239a418_StdAllocator` (`vf3(p, cap - begin, align)`) | element alignment from the `vf3` call |
| holder | its own vptr, `Unk_5e2bc0(ref, this)`, the reference, two callables | `Unk_236d3d8`, `Unk_236d4d8`, `Unk_236d658` (src/unsorted/Unk_236d3d8.h), Unk_23c14c0's shape |
| array with a callback | the elements (`while (n--)`), then `vf3(data, cap * size, align)`, then its `std::function` | `Unk_131fb20_Array<T>` |
| words, list | `vf3(data, cap * 8, 8)`; nodes freed one by one | `Unk_2438308_Words<T>`, `Unk_2438308_List<Node>` |
| mutex | `nn::os::FinalizeMutex` | `nn::os::Mutex` |

The bases: `Unk_23f43c8`, `Unk_23f4318`, `Unk_23f4660`, `Unk_23f4e40`,
`Unk_239bd80` (out-of-line D2s, tail-called), the object itself and
`Unk_239a4c0` (5 slots, its count at `+0x50`: the "5-slot classes with an
interface at `+0x48`", whose bases store no vptrs), a placeholder 4-slot
base with an interface that declares its two functions
(`src/unsorted/Unk_23a7ca0_Base.h`), and new ones: `Unk_2444570`, the
abstract node of a tree of UI objects in `unk_14b14a0` (parent, next sibling
and first child; `vf26` appends a child, `vf10` shows a node and tells its
ancestors), its derived `Unk_24446c0` (out-of-line D2), `Unk_2434918` (two
`std::function` callbacks), and gflib3's `Unk_23994d8` (declared only).

What decided the matches:

- **Implicit or out-of-line.** A derived D2 that inlines its base's needs the
  base's destructor implicit (an in-class `{}` isn't inlined here); one that
  tail-calls it needs it declared and defined in its own TU. The class's key
  function then has to be another virtual function, declared before the
  type getter's override.
- **Thunks.** The adjusted `this` (`sizeof - 0x48`, `- 0x50`, `- 0x58`)
  must land on a field for the short form and in a byte array for the long
  one, so padding is `u64` fields or bytes by what the original's thunks
  say; a class's size can follow from it (two classes on `Unk_23994d8` are
  0x378 and 0x8a8 bytes for their thunks to match).
- **D0.** A copy of the D2 when the family's `operator delete` is empty
  (`static void operator delete(void*) {}` in the placeholder bases),
  otherwise a call to `_ZdlPv`; a D0 that is `b <D2>` (the D2 is too big to
  inline) is left in its shape group.
- `Unk_2434918` is 0x100 bytes, not 0x128: a derived class has a vector at
  `+0x108`.

Not matched: `Unk_24450e8` and `Unk_236d398`, whose first callable is
addressed from a separately computed pointer (`add x8, x19, #N` then
`stp xzr, xzr, [x8]`), which no spelling tried reproduced (an array, a
second base); `Unk_236d3b8`, a 64-holder loop whose induction variables
differ; and destructors that lock weak handles (`ldxr`/`stxr`) or call
undecompiled walks. `_Z11Unk_14e1a00mj` and `_Z11Unk_14e1a30mj` are
`Unk_2444570`'s bool setters, but their leaf-generated callers fixed the
names to `(u64, u32)`, and with those types the compare comes out reversed.

## The contents' apps (`src/contents`)

The menu apps of `prog/contents/...` (the box, the bag, Battle Stadium,
Mystery Gift, ...) are hand-written code on one framework, which
`src/contents/common/framework.h` reconstructs. An app is a set of states,
one TU each (the box's are the segments named `boxtray_in`, `marking`, ...):
a class on `Unk_23f43c8` whose vf7 enters the state, vf8 runs a frame of it
(1 when it's done) and vf9 leaves it. tools/vtables.py wrote their small
slots; the classes are declared again in `src/contents/<app>/state/*.cpp`
with the fields the hand-written functions use. What the states do:

- **Their name.** vf7 starts with `field_70 = Unk_d0c0_String("boxtray_in");`:
  `Unk_d0c0_String` (0x710000d0c0) is an 8-byte reference to a string object
  (`Unk_2399470`, on `Unk_239a4c0`), moved into the field. It and the names
  are gflib3's, in `unsorted/Unk_d0c0.h` (the battle sequence uses them too).
- **Their app and frame.** `field_68` and `field_60` are handles (an object's
  vf2): the object is the handle's +0x60, through the object's +0x50
  interface. A state casts them with the type getters: `Unk_DynamicCast<T>`
  checks for null first, converts to the interface, and walks the type's
  parents (`Unk_61a530<T>`, typegen's template, inlined or not as clang
  decides). The app (the box's `Unk_23c63c8`) may be null; the frame
  (`Unk_23f41d0`) is dereferenced, so clang drops its null paths.
- **Their views**, by hashed name: `Unk_StateView<T>(this, "View_Top")` looks
  in the frame's views (+0x548) for the one whose name (`Unk_23f4660` +0x5c0)
  has that hash. Names are `Unk_5cfaf0_Name`s: 64-bit FNV-1a from Game Freak's
  basis `0xcbf29ce484222645`, folded for a literal by a constexpr
  constructor, with a string object that keeps the characters (null for a
  literal). `tools/funcs.py show` only has the hash when the name's string is
  dropped; hashing every rodata string finds it (`TipsView`,
  `SystemMessageView`). The lookup (`std::find_if` with a lambda that copies
  the name) is a template member defined in `contents/common/views.h`.
  Whether clang inlines it depends on how big the cast inside is: in the box,
  the lookup of `View_Top` is called (0x7100a7bb80) and those of
  `SystemMessageView` and `TipsView` are inlined. Assigning the result to a
  local first, then to the field, keeps the field's store after the name's
  destructor, as in the original.
- **Checks.** A view that has to be there is checked with `UNK_CHECK`, which
  calls `nn::diag::detail::AbortImpl("", "", "", 0)`: Game Freak's assert
  without its strings.
- **Sounds** are named by static `Unk_5cfad0_Literal`s (hash, characters,
  count: the TU's .data.rel.ro, no destructor) that `Unk_1502120` plays.

The League Card album's states (`src/contents/trainer_license`) are the
same framework: most vf7s look up two to five views, store each into a
field and call one or two functions on it. A state that looks up several
views casts the frame once and keeps the views in a local; the app
(`Unk_243d5a8`) is either dereferenced (`Unk_AlbumApp(this)->field_80`, its
null paths dropped) or tested first (`if (Unk_243d5a8* app = ...)`), and the
code shows which. Reference members are copied into a local `Ref` around a
call (an `AddRef`, the call, a release).

Matching details learned on the box's states:

- A function template is no `inline` function: give a helper template the
  keyword, or clang's threshold for it is 225 instead of 325.
- A temporary passed by value (an argument's copy) has no lifetime markers,
  so it gets a stack slot of its own; a temporary bound to a `const&` shares
  one with the others. The box's `Unk_23f64b0::Unk_ebb140` takes its
  reference by value for that reason.
- A `switch` and an `if` chain compare in different orders: the box's `tips`
  state (0x7100a8a130) is a `switch` on the app's mode.
- tools/leafgen.py's names fix a leaf callee's parameters as it saw them.
  Calling one with other types goes through an inline wrapper with a
  `reinterpret_cast` to its placeholder struct (or `u64`), which costs
  nothing. But some leaves pass `x0` through without using it and are named
  without parameters (`_Z15Unk_a96af0_callv`, `_Z15Unk_a8b7e0_callv`,
  `_Z10Unk_eb6530v`, `_Z15Unk_ab3ad0_callv`): a caller that passes a view to
  one can't be written. Most of the box's vf8s that are left call one.
- Not solved: the box's `pokeicon_release` vf8s (0x7100a82ae0, 0x7100a87b00)
  `switch` on a menu item with a jump table from 0, cases 19-21 (1, 6-11)
  distinct and the others the default's code; every spelling tried gives a
  range check from the lowest case instead.

### The block store's templates (`src/unsorted/families`, 2026-11-19)

The largest shape groups of `game/unk_133d350` (46 × 580, 46 × 520, 45 × 540
and 56 × 320 bytes, next to the flag and work tables) are member templates of
one class, instantiated once per block type, whose code doesn't depend on the
type: `Unk_13471e0_Store` (`src/unsorted/families/Unk_13471e0.h`) keeps blocks
keyed by a u32 in a sorted vector of 32-byte entries (memory from
Unk_2771620's allocator), behind a recursive mutex at +0x78. Each block's
bytes are XORed word by word with an xorshift32 generator seeded by the key
and advanced once per bit set in it (`Unk_2431980`), through a stream over
the bytes (`Unk_24319a8`), its scrambled view (`Unk_2431940`) and a reader
(`Unk_2431910`) or writer (`Unk_24319f0`). Those classes are header-only in
the original (their destructors are never called, their vtables come with
every user), so they're written there, and `vtables.py write` leaves the
classes of `src/unsorted/families` (and their vtables' functions) alone.

How the generator's constructor inlines pinned the layout: each inline level
between it and its user alternately peels a devirtualized step out of the
popcount loop (loop rotation) and inlines it, so the original's two inlined
steps and one direct call put it three levels down (a key-taking constructor
of the scrambled view, the writer's constructor and the store's
`Unk_Writer`). The generator's index and the view's start offset are members
of base classes (`*_Base`): the implicit copy constructor then copies them
apart from the rest, as the original does, and the view's D2 is its base's
(an alias), which `Unk_2433478` shares.

Matched: the 46 instances each of the write (`Unk_13456e0`) and overwrite
(`Unk_1347350`) templates and 44 of the read (`Unk_1346030`), the generator, the
streams' small members and libc++'s `std::sort` instances on the entries.
Not matching: the 46 instances of the add (`Unk_13475a0`): the original takes
the mutex's address again for the sort's lock, and every spelling tried here
shares it with the outer lock; the scrambled view's read and write
(register allocation). The overload that takes the block by reference (the
bytes of an object) has 6 instances each of the write and overwrite (matched)
and of the add (not matching, as above). Not written yet: 4 writes of the
same shape that call another check and other overwrites, and the overloads
for scalars (a 300-byte write, 556-byte overwrite and 508-byte add per type,
16 writes in all): their checks compare the block's type code (8, 9, 10, 13,
... for u8, u16, u32, s16, ...) and are shared by the types of one code, as
are their typed writers, which aren't decompiled.

### Containers on Unk_2771620's allocator (2026-11-19)

Two more families of the shape groups are libc++ templates on the container
allocator of `src/unsorted/Unk_2771620.h`:

- 24 × 652 bytes in `game/unk_133d350`: `vector::__emplace_back_slow_path` of
  a type-erased callable (0x80 bytes, 16-aligned: four operations, then 0x60
  bytes of storage; `src/unsorted/families/Unk_1382340.cpp`). The callables
  added are empty, so constructing one only stores its operations, which are
  leafgen's `Unk_<addr>_call`/`_update` after each slow path. The operations
  are a struct copied whole: copied field by field, `__swap_out_circular_buffer`
  costs 260 against the inliner's 250 and stays out of line.
- 44 members of vectors of trivially copyable elements
  (`src/unsorted/families/Unk_2771620_Vector.cpp`: 18 `__push_back_slow_path`,
  17 `reserve`, 3 `__append`, 3 `assign`, 3 `__swap_out_circular_buffer` of
  `insert`), found by compiling the templates for elements of every size and
  alignment up to 0x200 and hashing them the way the shape groups are hashed.
  Only the element's size and alignment show in the code, so each function
  gets a placeholder element named after it. The sweep found 36 more
  `__push_back_slow_path` instances that `tools/familygen.py` already writes
  (`src/gflib3/families`, with pointer elements where they're 8 bytes), so
  they're left to it.
- The same sweep over other containers on the allocator found 4 maps'
  `operator[]` (`__emplace_unique_key_args`, u32 and u64 keys), 2 deques
  (`push_back`, `__add_back_capacity` and the `__split_buffer` members that
  grow their block maps), 5 members of vectors of `Unk_239a418_Ref` and 7 of
  vectors of `unique_ptr`s with `Unk_23f4660_Deleter`
  (`Unk_2771620_{Map,Deque,RefVector,OwnerVector}.cpp`). The 18 other
  members of vectors of references it found (`reserve`, push_back slow
  paths) are familygen's. The references' members (`__append`,
  `__swap_out_circular_buffer`) matched with a copy constructor that tests
  the copy's own pointer; since `Unk_239a418_Ref`'s copy tests the other
  reference's (for the battle sequence functions) they don't (`M`), like
  familygen's. `unordered_map`'s
  `operator[]` has 12 instances too, but they call `rehash` instances that
  `src/unsorted/Unk_597350.cpp` names with empty mapped types; the `int`-keyed
  `rehash` instances' `__rehash` callees don't match.
- Swept over every area, the same templates have 36 more instances in gflib3
  and gflnet3 that familygen doesn't write (and a third deque's
  `__add_back_capacity`), written in the same files.

`tools/shapes.py` does the grouping (`groups --area game`, `members <addr>`)
and the sweep (`sweep <object>`: which groups an object's functions have the
shape of). A sweep object is any TU that instantiates the candidates, compiled
with the build's flags; a shape match still has to be named and checked.
### Inlined factories and creators (`familygen.py` again, 2026-11-19)

Two more families, read by following one path through each function
(`walk`: symbolic registers and stack slots, the allocator stack's overflow
check and null references skipped) rather than by fixed offsets:

| Family | File | Candidates | Matched |
|---|---|---:|---:|
| `Unk_New::Create<T>` of classes on the object (constructor `0x71005e2350` out of line) and on `Unk_23f4660` (`0x7100e7f820`, inherited) | `Unk_1085320.cpp` | 249, 110 parsed | 87 (28,028 bytes) |
| `Unk_790260_Owner::Create<T>`: the creators | `Unk_790260.cpp` | 115, 106 parsed | 74 (42,380 bytes) |

- **Objects.** A class on the object takes its own constructor's
  parameters: what the factory loads from an argument before the base's
  constructor is a by-value parameter (a reference moved in or copied from a
  const&, `Unk_239a418_RefPair` — a reference and a u64 moved together — n
  u64s, or a scalar), what it loads after is a const&. Members come from
  those parameters (copied when a reference is added after the store, moved
  otherwise) or are constants; every by-value reference is dropped once,
  in reverse order, unless it was moved into a member. Classes on
  `Unk_23f4660` inherit its constructor (`(void*, u64, u64)`, now declared
  in its header) and start their members at `0x5cb`: the base's last
  fields are a u16 and a u8 (its constructor stores them so), and the
  Itanium ABI puts a derived class's members in a non-POD base's tail
  padding. The header's `u64 field_5c8` is now `u16 field_5c8; u8 field_5ca`.
- **Creators.** All 115 of the main shape share one owner layout (allocator
  at `+0x8`, a vector of references at `+0x78` whose slow path is the
  matched `0x7100790490`, `field_a8` passed to the base, a flag at `+0xc0`
  cleared) and one template (`CREATOR_HEADER`). It matches only when the
  parent is set and the vector's reference made through `result.m_ptr`, not
  the new object: through the object, clang keeps `object + 0x48` in a
  callee-saved register across `0x7100e7fe20` and reuses it, where the
  original computes it again.
- Not matched (left out by the trial): 23 objects and 32 creators whose
  members are stored in another order than their offsets (sub-objects with
  their own constructors: arrays of 0x40-byte entries, for one), 1 whose
  members are stored partly before its vptrs (`0x71011f6130`), and 2
  creators whose `Create` clang doesn't inline. Not parsed: 17 objects with
  a vector member reserved in the constructor (`b.eq` in the walk), 19
  with members that call (creator-like, `0x7101005a30`), 9 creators with
  other vptr layouts, and the creators' wrappers (`0x7100790140`).

### The objects' adders (`familygen.py`, 2026-11-20)

65 functions of the network requests (`0x7101050c60` and 51 of its shape,
380 bytes; `0x7101052df0` and 12 of its shape, 372 bytes) call one of the
object factories above each, and nothing else differs between them: a member
template of the objects' owner, `Unk_1050c60_Owner::Unk_Add<T>(const
Args&...)`, written in the objects' file after the classes
(`src/gflib3/families/Unk_1085320.cpp`). Unless the owner's flag at `+0x110`
is set, it makes a `T` from the owner's allocator (`+0x60`) with a weak
reference to the owner and its arguments, keeps a reference to it in the
owner's list (`+0xb0`) and returns a reference to the owner. 61 match (23 KB);
the other 4 call factories that aren't written.

What decided the match:

- the weak reference is the factories' `Unk_239a418_RefPair`: the object's
  handle (`m_handle`, copied through a temporary, so a reference is added
  twice and dropped once) and the object. A null object gives an empty pair
  (`stp xzr, xzr`), a null handle a pair of a null reference and the object
  (`stp xzr, x19`): no test of the handle in the source, the copy's own;
- the list's emplace is a member call on `field_b0` with a temporary
  reference: the object expression is evaluated first, so `this + 0xb0` is
  in a callee-saved register across the temporary's `vf4`. Passing the list
  to a free function computes it after.

Still left from the list above:

- the 118 lookups (`0x7100795bc0`): everything but the loop's block
  placement matches with a `std::find_if`. The original's exit phi has the
  vector's *end* on the empty-vector edge and on exhaustion, and the found
  iterator only on the match edge, so the match edge needs a copy (`mov
  x21, x22`) and falls through after the body, and block placement rotates
  the increment to the top. clang 7 gives *begin* on the empty edge
  (the iterator travels through `find_if` as an `i64` and is
  `inttoptr`'d back; the guard comes from the late LoopRotate, after GVN,
  so no equality replaces it), which merges the empty and found edges.
  Tried without success: a `find_if` returning `last`, `last != first`,
  `end()` read before `begin()`, iterators by reference, raw pointers, a
  hand loop with `break`, a `while` with the condition, a vector of
  references;
- the path builders (`0x7100005e20`, `0x7100010530`) inline the name from a
  reference (`0x71005cfaf0`'s body) and call `0x71005e6180` (a constructor
  from a name and a flag) and the parser `0x71000105b0`: decompile
  `0x71005cfaf0` as an inline function first;
- the finders under a spinlock, `0x71005ca410` and `0x71005d0130`: not
  looked at in this round.

## What's left of the small functions

After these batches (check.py: 25,626 matching), most of game code's
undecompiled functions of up to 16 bytes (11,761 by
`funcs.py patterns --area game --status U --max 16`) are blocked on something
bigger rather than on the lifters:

| Shape | Count | What it waits for |
|---|---|---|
| `sub x0, x0, #N ; b T` | 2,921 | Non-virtual thunks. The compiler emits one with the override it adjusts for, so its target has to be written first, in a class declared with its secondary bases. |
| `ret` | 2,869 | 952 are single function pointers inside static data objects, after data pointers: no-op callbacks in static records, not vtables. 1,915 are referenced nowhere. Nothing says what either belongs to. |
| `ldr x8, [x0] ; str x8, [x1] ; ret` | 2,703 | Copy operations of type-erased callables, one per lambda type. A caller builds a table of them (invoke, copy, ...) on its stack. They're template instances: one template covers them once the wrapper is known. `ldp`/`stp` (281) and `str xzr` (107) are their 16-byte and move variants. |
| `b T` | 1,426 | Forwarders, nearly all in data: `vtables.py` writes one only when its target can be a placeholder (in no vtable, unnamed). The others go to virtual functions, D2s or `operator delete` of classes not written yet. |
| `trap` | 115 | In vtables (an abstract class's deleting destructor, for one) of classes not written yet. |

Larger shapes have their own blockers:

- destructors of derived classes (`store vptr ; b <base D2>`), whose class
  would need its whole vtable declared, not the constructor files' minimal one;
- constructors with several vptrs (multiple inheritance);
- 16-byte values returned in `x0`:`x1`;
- functions that read a field after storing to it.

## Handoff (2026-11-17, updated 2026-11-19)

State after the type getters and the map instances (2026-11-19, later):
check.py reports 47,184 matching and 42 not matching; 26.52% of the code by
bytes. Before them, after the generated tables and FreeType: check.py
State after the allocator families (2026-11-19, later): check.py reports
45,783 matching and 49 not matching; 26.16% of the code by bytes (gflib3
4.4%, startup 10.9%). `tools/familygen.py` writes `src/gflib3/families`
(generated too).

State after the generated tables and FreeType (2026-11-19): check.py
reports 44,938 matching and 42 not matching, in both games; 25.16% of the
code by bytes. Every batch above came from `tools/leafgen.py`,
`tools/vtables.py` (`write`, `ctors`), `tools/typegen.py` and `tools/clonegen.py`.
Their sources in `src/unsorted/leaf`, `src/unsorted/virtual`, `src/unsorted/ctor`,
`src/unsorted/types` and `src/unsorted/clone` are generated: change the generator and rewrite them,
don't edit them by hand. Run `typegen.py write` before `vtables.py write`:
vtables.py skips what typegen writes.

### How a generator batch is run

`vtables.py write` rewrites every file in `src/unsorted/virtual`. It writes
all candidates unless `--only` lists the functions not named yet to keep:

```sh
python tools/vtables.py write --names trial.csv            # every candidate
python tools/funcs.py name --force --from-file trial.csv
python tools/check.py > trial.log                          # builds both games
# keep: trial.csv's addresses minus the BAD lines' sword addresses (only.txt)
git checkout -- src/unsorted/virtual data/functions.csv && git clean -fdq src/unsorted/virtual
python tools/vtables.py write --names keep.csv --only only.txt
python tools/funcs.py name --force --from-file keep.csv
python tools/check.py --update
python tools/check.py --no-build --record-data
```

A trial with every candidate doesn't build any more: since Batch 25 the
lifter gives `write` members with calls and virtual calls it can't declare.
Trial a new kind with `--only` listing its candidates (named functions are
always kept), as Batch 34 did. `ctors --only` lists every constructor to
write, named or not, and the D0s of `implicit_dtors` too.

Before committing a change to `vtables.py`, check that:

- `write --only <empty file>` leaves `src/unsorted/virtual` unchanged on
  master. Named functions are always kept, so that's the same sources, or
  the change broke a class.
- check.py reports no REGRESSION or STALE line. STALE means an O row that
  nothing compiles any more: a class was refused or rewritten without one
  of its matched functions.
- every new `_ZTV<n>Unk_<addr>` row in `data_symbols.csv` sits at `<addr>`.
  A placeholder class is named after its Sword vtable. check.py used not to
  check a vtable reference until the symbol was recorded, so a function
  given to the wrong class "matched", and `--record-data` then recorded the
  wrong address. That happened in #54 (a D2 shared with a derived class
  through an alias). Now Sword checks an unrecorded placeholder vtable
  against the address its name gives, so such a function is BAD in Sword;
  Shield still needs the recorded row.

Other pitfalls:

- A trial's BAD list always includes a few lifted members, such as
  `Unk_2399140::vf2`, that never match. `--only` leaves them out.
- The guarded type getters are sensitive to how many callers they have in
  the TU. clang inlines an inline getter into its only caller, so a class
  whose getter other classes call must share its file with one of them
  (#53). A class whose getter inlines the object's getter needs a file of
  its own.
- Each PR is two commits, the tool change and then the generated sources
  with the CSVs and docs. PRs land with `gh pr merge --rebase`.

### Next steps, by expected yield (2026-11-18)

The 2026-11-17 list is done as far as the generators go (Batches 9-21 and
the bases of #62-#76). What's left, roughly by yield:

0. **By bytes (2026-11-19):** the generators' batches add a few KB each now.
   What moved the byte count was public code (FreeType, found by its strings)
   and the largest functions (generated tables, "The largest functions"
   above). Next by size: functions that are one block repeated (rank the
   unmatched ones by how many 12-instruction windows recur; at the top are
   `0x7100f76f20`, `0x7101315d00`, `0x7100bc27d0`, `0x710165e380` and
   `0x710138a350`, 5-10 KB each), `Unk_95c520` (16,612 bytes: 43 lookups in
   a map of hashes, each feeding a `switch`) and the 239 functions of
   `Unk_23c4ef0`'s table (52 to 2,316 bytes).

1. **More hand-written bases.** Each unlocks the classes that share or
   tail-call its D2. `tools/vtables.py show` on a D2's vtable and a census
   of the D2s that tail-call each base D2 find them. The larger groups left:
   - on `Unk_239a4c0`: `0x7100d3a2b0` (4 classes share it), `0x7101212a90`
     (3), `Unk_23da950`'s `0x7100c277c0` (3; it inlines `Unk_239a418::vf5`
     for the reference at +0x100), and `Unk_2398c40` (owned objects with
     allocator deleters). `Unk_23f5d00` (#74) and `Unk_2419350` (#76) are
     done, and so are the 19 classes on `Unk_23f5d00` that store their
     vptrs before the tail call (Batch 37); `Unk_23f5d00`'s constructor
     needs a root class under `Unk_239a4c0_Base`;
   - the owner heuristic: a D2 belongs to the class whose vtable it stores.
     165 D2s (slot 0 of a primary vtable) store another vtable than their
     owner's: the hand-written bases' (`Unk_23f43c8`'s, with 247 vtables,
     `Unk_23d4470`'s, `Unk_23f4660`'s ...) and `Unk_2419350`'s among them,
     and 130 not matched yet. The largest of those in game code:
     `0x71006b7de0` (22 vtables, it stores `Unk_23a3578`'s: abstract, on the
     object, a reference and two callables, its `vf_type` inline, like
     `Unk_241b640`), `0x7101079c30` (14, `Unk_240ce88`), `0x71005ec610` (12,
     `Unk_2399708`), `0x7100b3c7b0` (9, `Unk_23cf5c8`) and `0x710116b030`
     (7, `Unk_241bfb0`). `python tools/vtables.py stored` lists them
     (`stored_vtable_owners`; with `--area game --unmatched`, 46 after
     #78). The cause is a tie: a class on the base with a vtable as long
     as the base's, at a lower address, owned everything they share,
     type slots too (`Unk_23bcdf0`'s `vf6` and secondary type thunks were
     `Unk_23bcd20`'s, `Unk_23bcd88`'s and `Unk_23bcdc8`'s). 127 of the 165
     are such ties, which `write` now breaks by the vtable the D2 stores
     (Batch 20); the rows still listed wait for other things. The other 38 have an owner with a shorter
     vtable, or store a base's vtable first;
   - on the object: the groups of 6 or fewer from the #62 survey.
   YEBIS (`0x71004bf6a0`, 75 classes) and NEX/Pia (`0x710165baa0`, 52) have
   bigger groups, but they're libraries with RTTI: their classes have real
   names, and `vtables.py` doesn't write library classes.
2. **More classes with an interface.** Batch 16 wrote 62 classes on the
   object with an interface at `+0x60`. Left: those whose D2s release other
   members than references, those with other type shapes, interfaces at
   other offsets (after a bigger base or members), and about 12 classes on
   `Unk_239a4c0` with a second interface at `+0x58`.
3. **The classes on the newest bases.** On `Unk_241b640` (#75), 15
   classes need a function `write` can define as their key function, and 2
   have Batch 9's tail form on an inline-destructor base. `Unk_24284d0`'s
   classes have internal linkage (anonymous namespace, `adrp`+`add`
   vptrs, local-static types): `write` would need anonymous namespaces, and
   they're emitted only with their constructors' TUs. On `Unk_23dc940`, 7
   tail-shaped classes have a class between them and the base. On
   `Unk_239bd80`, the classes' getters call `Unk_239bd80::Unk_GetType`'s
   copy, which loads the base's own getter's statics after `Unk_239bb58`'s
   (`base_type_statics` should follow a base `vf_type` that calls its
   parent's getter out of line).
4. **More member kinds in D2s** (`ref_members`, `tail_members`,
   `inline_members`, `ref_members_empty`): members that are themselves
   objects (a second object D2 inline), light events (`add x0, x19, #N ;
   bl Unk_5cf8d0`: in about 50 unmatched D2s, mostly with other members),
   vectors freed through an allocator, out-of-line member destructors
   (`add x0, x19, #N ; bl T`), owned objects with deleters, polymorphic
   members whose vptr the D2 stores (`Unk_23f5d00`'s +0x60). Each needs its
   idiom read the way `tail_members` reads references and callables.
5. **Getter copies alone in their files.** 20 classes on `Unk_23f4e40` call
   its getter's copy out of line, and in 14 segments they're alone: their
   TUs had other callers (type checks in bigger functions). They match once
   one of those functions is decompiled into the same file.
6. **Address-taken leaf functions.** Done in Batch 22 (`--reach`), with
   the libraries built like the game's code.
7. **The 107 that don't match:** libcurl and the generated protobuf
   initialisers, each its own investigation.

How the parallel work went (#62-#71): one agent per hand-written base
family, each in a worktree of its own (`isolation: worktree`), its PR
adding its `EXTERNAL_BASES` entries at its own place in the tuple and
regenerating with `write --only <empty>`. The generator batches for the
derived classes ran in one checkout only, after the bases merged. Rebasing
a base PR onto a newer master conflicts in `data/data_symbols.csv` (both
sides add rows: keep both, sorted by address) and, when two PRs grow the
same idea, in `vtables.py` (#71 and #72 both added an out-of-line
destructor as a key function; merged into `explicit_dtor`). After a
rebase, `write --only <empty>` must leave the generated files unchanged (or
change only what the merge changed) and check.py report master's count
plus the PR's.
