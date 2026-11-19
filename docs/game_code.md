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

## Handoff (2026-11-17, updated 2026-11-18)

State after Batch 36: check.py reports 41,617 matching and 42 not
matching, in both games. Every batch above came from `tools/leafgen.py` and
`tools/vtables.py` (`write`, `ctors`). Their sources in `src/unsorted/leaf`,
`src/unsorted/virtual` and `src/unsorted/ctor` are generated: change the
generator and rewrite them, don't edit them by hand.

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

1. **More hand-written bases.** Each unlocks the classes that share or
   tail-call its D2. `tools/vtables.py show` on a D2's vtable and a census
   of the D2s that tail-call each base D2 find them. The larger groups left:
   - on `Unk_239a4c0`: `0x7100d3a2b0` (4 classes share it), `0x7101212a90`
     (3), `Unk_23da950`'s `0x7100c277c0` (3; it inlines `Unk_239a418::vf5`
     for the reference at +0x100), and `Unk_2398c40` (owned objects with
     allocator deleters). `Unk_23f5d00` (#74) and `Unk_2419350` (#76) are
     done; 19 classes on `Unk_23f5d00` store their vptrs before the tail
     call, which an empty `~X() {}` doesn't (#74), and `Unk_23f5d00`'s
     constructor needs a root class under `Unk_239a4c0_Base`;
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
   `ref_members_empty`): members that are themselves objects (a second
   object D2 inline), callables first, out-of-line member destructors
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
