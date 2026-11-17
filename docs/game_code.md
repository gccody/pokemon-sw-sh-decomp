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
  another type in between (a 168-byte `vf_type`).
- **The object itself** (`inline_dtor`: its destructor is inline, so a
  derived D0 and its thunks are copies of it). Of its 113 direct
  descendants, 58 have the inline shape, but only 1 defines a function write
  can make its key function; the others only have undecompiled ones. 35
  store a type created by an out-of-line function (`0x7100603810`), and 14
  have another type in between.

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

Left are about 50 of other shapes, which store more than one vptr
(multiple inheritance) or initialise a field as well.
