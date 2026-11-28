# Generator candidates: the largest undecompiled shape groups

`tools/shapes.py groups` buckets functions by *shape* (their instruction words
with call targets and data addresses masked). Two functions of one shape are
the same code reaching other functions and data: one template instantiated
twice, or two copies of an inline function. A group of many U functions is
work a generator can do at once, the way `leafgen.py`, `typegen.py`,
`lockgen.py`, `familygen.py` and `clonegen.py` did for earlier batches
(docs/game_code.md). This page ranks what's left. No generator is written
yet; each row is a guess at what the code is, from the callees' names and the
first instructions, to check before writing one.

Snapshot: 2026-11-28, `master` at 5916bb64 (59,906 functions matching). U
functions only; `yebis` has none left. 15,241 of the 43,343 U functions
(2.28 MB of 14.64 MB) are in a group of two or more, in 2,917 groups. The
previous snapshot (2026-11-24, 741a521f, 56,559 matching) had 16,728 of
46,908 in 3,126 groups.

How it was computed: `shapes.executable_groups("U")` over the whole
executable, then over each area (the same as `shapes.py groups --area <area>`
for every row of data/areas.csv), ranked by total bytes. Re-run it before
starting a generator; the numbers move as units land.

## Families, by total bytes

A family is several shape groups that are one kind of code (the variants
differ in a frame size, a field offset or a register). The numbers are kept
as ids (other notes refer to them), so the table is in id order. By bytes,
family 2 (70.0 KB) now leads family 1 (62.6 KB): units took 51 of family 1's
functions and 5 of family 2's. Family 9 (22.8 KB) is larger than 8 (21.1 KB)
and 7 (19.6 KB), as it already was; the rest are in byte order.

| # | Family | Groups (functions x bytes) | Total | Where | What it probably is |
|--:|---|---|--:|---|---|
| 1 | Destructors of classes with three vptrs, and their thunk variants | `c09fcbbed1eb` 155x80, `7ebc2b49a270` 157x80, `26fbf9256a81` 99x80, `ee6b6c10781b` 34x240, `ff1f748ad51e` 34x240, `fae1b9e15069` 43x156, `a8483873fae0` 43x156 | ~63 KB (565) | game, gflib3, gflnet3 | Checked (2026-11-28): the D0s and destructor thunks of classes *derived from* a base with an inline destructor (399 on gflib3's object `Unk_239a418`, 84 on `0x71023a3578`, whose D2 is U, 68 on `Unk_241b640`; 14 are sibling classes' own D2s). Their slot 0 is the base's D2 and these are its copies, emitted wherever the class's vtable is: with its key function, or for a class without one, with its constructor. `vtables.py`'s `derive_external` already writes the classes it can; what's left has no own function written to be the key function. `typegen.py` now writes the 30 classes whose only own function is its `vf_type` on the object, `vf_type` as the key function: 150 matched. Then 3 more whose own slots after `vf_type` are only declared (`vf_type` stays the key function): +15. Left (2026-11-28): 41 of the 44 classes with own slots. 28 are on a class in between whose slots are U (`Unk_2431848` 14, `Unk_241d190` 8, `Unk_241d0c0` 4, `Unk_23dcb30` 2), 4 have a fourth vtable (another base), 1 is abstract, 3 have only U slots of their own, 3 have a `vf_type` that forwards to an unmatched getter, `Unk_241d190`'s key function would be in `vtables.py`'s files, and `Unk_241d0c0`'s `vf_type` is typegen's, declared on the object instead of `Unk_241b640`. Also 41 on bases not written (`0x71023a3578`, 204 functions). |
| 2 | Guarded static-local type getters | `d1211a1e6828` 84x296, `066a4a854740` 98x236, `6ae9155d5b75` 47x232, `1d60ca677a5b` 37x300 | ~70 KB (266) | game, gflib3 | `Unk_GetType()` with a function-local static under `__cxa_guard_acquire`/`release`, chaining to the parent's getter (2-4 levels inlined). Many are already named (`Unk_23de150::Unk_GetType`). `typegen.py` covers the one-level ones; this is the multi-level case. |
| 3 | `Create<T>` factory instances | `5f6118bb324c` 188x288 | 54 KB (188) | game (all over) | Calls `Unk_790260_Owner::Create<T>` and `Unk_e809c0_call`: one template member instantiated per T. Written by `tools/creategen.py` (2026-11-28, `src/gflib3/create`): 178 as `M`, 10 left (docs/game_code.md, "The creators' wrappers"). |
| 4 | View lookups by name, `Unk_a7bb80_Views::Unk_a7bb80<T>` | `82bedd704e78` 116x332, `ae18320baece` 23x260 | 44 KB (139) | game (every content) | 18 instances are named. A guarded type getter is inlined into a lookup through `Unk_5cfaf0_Name`: a template whose instances differ only in T. |
| 5 | Recursive locks on `+0xf0` | `ee11b2b7a239` 27x504, `d27803d8ccee` 13x792, `40a7f864a377` 29x336, `8e5fec7d6a64` 23x348 | ~42 KB (92) | game, gflib3 | `nn::os::GetCurrentThread`, an `ldaxr`/`stxr` owner swap at `+0xf0` and `Unk_5cf8f0(LightEventType*)`: the lock guard of `lockgen.py`'s family with a body inlined. |
| 6 | Name keys built from a literal | `d35d42abc79b` 28x472, `c8645e4a084a` 33x268, `d0d168480cac` 25x272 | ~29 KB (86) | game | A string literal into a stack temporary, then `0x7100c46830` (U, unnamed): a hashed-name constructor, then a lookup. Name `0x7100c46830` first; the rest differ by the literal. |
| 7 | Non-virtual thunks `sub x0, x0, #N ; b T` | `7c81366dadf4` 1201x8 (`#0x48`), `4383c7a895a5` 1034x8 (`#0x50`), 214 more with other N | ~20 KB (2,449) | game, gflib3 | The compiler emits each with its override, so a thunk matches only once its target is written in a class declared with its secondary bases (docs/game_code.md, "What's left of the small functions"). After family 1 (2026-11-28): 1,744 wait on a U target; 316 on a `vf_type` `typegen.py` writes strongly (the original's is inline, so its thunks keep the adjustment only in the constructor's TU; 60 of them now compile, as calls, and stay U); 317 on targets in hand-written files; 72 others. Family 1 unblocked none: its classes' thunks of other overrides need those overrides. |
| 8 | `vector<Unk_239a418_Ref2<...>>` growth | `c38c4bfe4547` 55x384 | 21 KB (55) | game | libc++ `vector` reallocation on the game's TLS allocator (`GetTlsValue`, `AbortImpl` on failure): a template instance per element type, like `src/unsorted/families`. |
| 9 | `strlen`/`strcat` path joins | `79e2510e815a` 55x128, `aa3986308156` 52x304 | ~23 KB (107) | game, startup | Two `strlen`s, two `strcat`s into a buffer, then `Unk_d0c0_String(const char*)`: an inline string-join helper. |
| 10 | Static unique_ptr releases | `cd2b286bed6e` 42x360 | 15 KB (42) | game | `Unk_b2cdf0(void*)`-style functions (21 named) that call a virtual destructor through each of several globals and clear them: the exit-time counterpart of `initgen.py`'s static initialisers. |
| 11 | Deleting destructors `bl D2 ; b operator delete` | `a5422d3b9e82` 260x36 | 9 KB (260) | middleware, game | D0s whose D2 isn't written yet. `vtables.py` writes them once the D2 is. |
| 12 | Serialize a protobuf message into a buffer | `f67606cabe42` 20x364 | 7 KB (20) | game, gflnet3 | `Unk_23a3578::Unk_6b8c00<Msg>` (5 named): a scope allocator, `MessageLite::SerializeToArray`, returning `unique_ptr<u8[]>`. One template over the message types. |

## The 20 largest single groups

| Shape | Functions x bytes | Total | First (Sword) | Family |
|---|---|--:|---|---|
| `5f6118bb324c` | 188 x 288 | 54,144 | `0x7100790140` | 3 |
| `82bedd704e78` | 116 x 332 | 38,512 | `0x7100795bc0` | 4 |
| `d1211a1e6828` | 84 x 296 | 24,864 | `0x71000027d0` | 2 |
| `066a4a854740` | 98 x 236 | 23,128 | `0x710060a900` | 2 |
| `c38c4bfe4547` | 55 x 384 | 21,120 | `0x710079a0a0` | 8 |
| `aa3986308156` | 52 x 304 | 15,808 | `0x71005e41e0` | 9 |
| `cd2b286bed6e` | 42 x 360 | 15,120 | `0x7100b2cdf0` | 10 |
| `9cc03e4fb177` | 31 x 472 | 14,632 | `0x71007aa240` | callable built on the stack from a literal (like 6) |
| `ee11b2b7a239` | 27 x 504 | 13,608 | `0x7100607550` | 5 |
| `d35d42abc79b` | 28 x 472 | 13,216 | `0x71008e7a70` | 6 |
| `56ad68c57d8b` | 26 x 508 | 13,208 | `0x71005ca410` | hash-table insert on gflib3's containers (14x480 `eeae76836de2` too) |
| `3aa21fa679bf` | 10 x 1320 | 13,200 | `0x7100c794a0` | 0x58-byte element array rebuild on the TLS allocator |
| `7ebc2b49a270` | 157 x 80 | 12,560 | `0x71005b2f30` | 1 |
| `c09fcbbed1eb` | 155 x 80 | 12,400 | `0x71005b2eb0` | 1 |
| `080af53fb2d0` | 41 x 276 | 11,316 | `0x71007bc7a0` | lookup through a global manager (`+0x68`) |
| `1d60ca677a5b` | 37 x 300 | 11,100 | `0x710096c590` | 2 |
| `10540ae9217f` | 10 x 1108 | 11,080 | `0x71008947d0` | a state-machine switch on `+0x80` (named `Unk_8aea70(void*)`, ...) |
| `fb811352ea2f` | 23 x 480 | 11,040 | `0x7100894db0` | the same states' update, net battle |
| `6ae9155d5b75` | 47 x 232 | 10,904 | `0x71005b2f90` | 2 |
| `d27803d8ccee` | 13 x 792 | 10,296 | `0x71009862e0` | 5 |

## Per area

The share of each area's U bytes that is in a group, and its largest group:

| Area | U bytes | In groups | Largest group |
|---|--:|--:|---|
| game/unk_bba3d0 | 2,068,588 | 15.5% | `066a4a854740` 45x236 (family 2) |
| game/pokecamp | 1,208,856 | 21.6% | `ee6b6c10781b` 34x240 (family 1) |
| middleware | 1,661,516 | 8.2% | `f5ab3ba2b48d` 6x1160 (Pia `ErrorResultVariant`) |
| gflib3 | 931,072 | 13.1% | `53411035a404` 5x668 |
| game/unk_b2b110 | 453,432 | 26.3% | `d27803d8ccee` 6x792 (family 5) |
| game/unk_133d350 | 695,792 | 14.7% | `14012d17e6e9` 16x300 |
| game/net_request | 266,080 | 37.8% | `3bbc5dcd76e5` 11x572 (request handlers, all named) |
| game/unk_e66990 | 636,004 | 14.6% | `5f6118bb324c` 16x288 (family 3) |
| game/btl_spot | 356,116 | 21.0% | `c38c4bfe4547` 17x384 (family 8) |
| game/net_contents/nbr | 148,712 | 41.9% | `fb811352ea2f` 15x480 |
| game/battle_scene | 530,432 | 13.1% | `aa3986308156` 16x304 (family 9) |
| wwise | 836,560 | 1.5% | `3734395c3ff1` 2x1408 (little repeats: hand work) |

`game/net_contents/nbr` (42%), `game/battle_logic` (40%) and
`game/net_request` (38%) are the areas where generators would do the most of
what's left; `wwise` (1.5%) and `game/unk_82e410` (1.8%) are nearly all
one-off code, for hand-written units.

## Lone `b` functions

1,027 U functions are a single `b T` (4 bytes; shape groups don't show them,
since every one has the same shape). By what T is, from `vtables.py`'s slots:

| Kind | Functions | Example (Sword) | Comes from |
|---|--:|---|---|
| D0 that tail-calls its own D2 (slot 1 `b` slot 0, no `operator delete` call) | 517 | `0x7100007c00` | The class's D2: clang emits this D0 with it. |
| D0 that is only `b operator delete` (the D2 is empty) | 173 | `0x71006227c0` | A class with a trivial body, declared with its base. |
| Override that forwards to the base's function in the same slot | 140 | `0x71008fdc80` | A derived class declared with its base, the slot not overridden in the source. |
| D2 that tail-calls the base's D2 (an empty derived destructor) | 92 | `0x710038e980` | The same, for slot 0. |
| Another slot or target | 85 | `0x71006a83e0` | Hand work. |
| Not in a vtable | 20 | `0x71000001e0` | Hand work. |

The coordinator's run-1 counts (268 forwarders, 186 `b operator delete`, ~80
D2s) used other buckets: a D2's `b base D2` is a same-slot forward too.

## Where to start

1. Family 1 (multiply-inherited destructors): the biggest, and it unblocks
   most of family 7's thunks.
2. Families 3 and 4: two templates, 329 functions, ~100 KB.
3. Family 2: extend `typegen.py` to chains of guarded getters.
4. Name `0x7100c46830` (family 6) and `0x71005dfda0` (what family 11's
   deleting destructors tail-call, probably a deallocation function) from
   evidence first; those groups then come cheaply.
5. The lone `b` functions (above): most come with a D2 or a class declared
   with its base, so they follow the generators that write those.
