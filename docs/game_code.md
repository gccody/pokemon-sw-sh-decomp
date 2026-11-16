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
| `game` | `0x7100761f70`-`0x7101548410` | 67,162 | everything from `prog/`, starting with pml (`bin/pml/...` loaders) |

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
  calls nothing after itself. Protobuf's only calls back into gflnet3 go to
  `0x71006a54a0`, `std::__tree_balance_after_insert`: a linkonce libc++
  instantiation that the linker kept from a gflnet3 TU. gflib3's 70 calls
  into later code all go to instantiations like that (libc++, sol2).
- **Protobuf's version.** Each generated message's `AddDescriptors` calls
  `VerifyVersion` (`0x71006ff450`) with `3000000`, i.e. 3.0.0. Protobuf is
  BSD-3-Clause, so it could be vendored and matched the way sol2 was (1,622
  functions, 515 KB).

**Game Freak code has no RTTI.** The 1,264 typeinfo objects in `main` all
belong to the nn SDK (829), YEBIS (`SiSDK3` 349, `PPFX` 46), `pead` (34) and a
few libc++/NEX templates. None of the 2,218 vtables that have one is a Game
Freak class. So class names can't come from typeinfo. Vtables still exist,
with a null typeinfo slot.

The `game` area is still one row. Inside `prog/`, the string evidence is
sparse and interleaved: only 3,879 of its ~75,000 functions reference a
string at all. It does show clusters: `bin/appli/bag` around `0x71007952f0`,
`prog/battle/battle_logic` at `0x710089db10`-`0x71008bf2e0`,
`prog/network/net_contents` at `0x7100fea950`-`0x7101042f70`,
`prog/contents/pokecamp` at `0x710114a650`-`0x7101156e40`, and the Pokédex
app at the end. Their edges still need TU-level evidence before they can
become rows.

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
