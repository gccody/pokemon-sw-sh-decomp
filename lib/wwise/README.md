# lib/wwise: placeholders

Functions of Audiokinetic Wwise 2017.2 (the `wwise` area of `data/areas.csv`).
Its source isn't public, so nothing here is upstream code: `leaf/` is written
by `tools/leafgen.py` (`--out lib/wwise/leaf`), placeholder structs and
`Unk_<addr>` names like `src/unsorted/leaf`, from the executable. Wwise was
built with clang 6.0.1, not the game's 7.0.1 (docs/compiler.md, "Wwise"), so
this directory has its own `pkmn_library_settings` entry in `CMakeLists.txt`.
See docs/game_code.md, Batch 29.

`class/` (tools/leafgen.py members) holds its classes' small virtual functions as members `vf<slot>` of `Unk_<vtable>` classes (Wwise has no RTTI). See docs/game_code.md, Batch 39.

`src/` is decompiled by hand, still with placeholder names (no Wwise symbol is
known): the memory manager around TLSF (`Unk_3043e0.cpp`, `Unk_305410.cpp`),
Wwise's container templates as their code shows them (`containers.h`: a
growable array, intrusive and pooled lists, the hash tables' prime sizes),
the bank manager's readers (`Unk_3476d0.cpp`, `Unk_347550.cpp`,
`Unk_347060.cpp`, `Unk_34e250.cpp`), a self-registering base class template
(`registered.cpp`), and families of functions that differ only in constants
(`families.cpp`, `deleting_dtors.cpp`, `thunks.cpp`, `tiny.cpp`, `Unk_3352d0.cpp`). One
template or macro stands for every member of a family; the constants are
the original's. Wwise is built with floating-point contraction
(docs/compiler.md, "Wwise").


## Range 0x710035ead0-0x71003b6ee0

Notes of the sessions that work on this part of the block (`src/Unk_35ead0.cpp`
onwards). Placeholder names throughout; what a thing probably is in Wwise's
terms is only said here, as a guess.

**Headers that other ranges can use**

- `Unk_KeyArray.h`: `Unk_GrowArray` (the array whose `AddLast` grows it by
  `kGrowBy` items and constructs the item with a placement new, whose null
  check is in the code) and `Unk_KeyArray` (items with a key: `Exists`,
  `Set(key)`, `Set(key, item)`). Its `GrowArray` copies with
  `Move(items[i], field_0[i])`: for a struct item that decides which of the
  two pointers the copy loop advances first.
- `Unk_HashList.h`: `Unk_HashListBare<T, P>::Reserve` and
  `Unk_HashList<T, P>::Reserve` (the table of an object that owns its items:
  a word before the buckets, and the bucket computed with the table's
  length). `P` gives an item's key and link. Instantiate one member with
  `template u32 Unk_HashListBare<Item, Policy>::Reserve(u32);` and name the
  function with the mangled name of the instance. These are the "rehash"
  functions an earlier session left as near misses (10 in the block: 5 here,
  `0x7100335420` through the index template, and `0x71003bc420`,
  `0x71003bcaa0`, `0x71003ee4a0`, `0x71003ee840`, `0x71003eef50`,
  `0x7100404a20` and the two-word-table ones `0x7100349f00`, `0x710034a2b0`,
  `0x710034aa50` in the other ranges). What decided them: the prime search
  written as `newSize = 0; for (...) if (prime > size) { newSize = prime;
  break; }` (returning from the loop, as `Unk_HashPrime` does, compares
  `size >= 53` where the original has `size > 52`), and `AddLast(nullptr)`
  through the placement new.
- `Unk_Indexed.h`: the indexed objects (`Unk_Indexed`, `Unk_Index`, moved
  from `families.cpp`), `Unk_IndexedAdd<Offset>` (insert into the index, the
  table grown at a load factor of 0.9) and `Unk_IndexedGetAndAddRef<Offset>`.

**What the compiler does that the source has to allow for**

- A table that is a global defined in its TU (the plugin and codec tables of
  `Unk_35ead0.cpp`): its `GrowArray` copy loop keeps the old items in a
  register, because a 24-byte item can't overlap the 16-byte table object
  (BasicAA's object-size rule). With only an `extern` declaration the size
  isn't known and the items pointer is reloaded every iteration. So define
  such globals where their functions are.
- `Set(key, item)` (copying the item in both the found and the added branch)
  and `Set(key)` followed by assignments give different code: the first keeps
  the null test of the result out of the branches.
- A `memcpy` whose size is a 32-bit product (`count * 12` computed in `w`
  registers after the allocation computed it in 64 bits) is a call through an
  inline wrapper with a `u32` size (`Unk_MemCpy` in `Unk_360c20.h`).
- Base destructor: `0x7100363530` is the destructor of the indexed objects'
  base class, but `tools/vtables.py ctors` took it for a constructor and it
  has that name (`_ZN11Unk_2380db0C2Ev`). The destructors here are free
  functions that end with `Unk_IndexedDtor(self)` (a placement new of
  `Unk_2380db0`) and store their vptrs with `Unk_SetVtable(self, Unk_<vtable>)`.

**More that the compiler does (second batch)**

- `Unk_GrowArray::Term` destroys its items first (`RemoveAll`, a loop over
  `Begin()`..`End()` that calls the destructors, nothing for trivial items).
  Without that loop the destructors `Unk_3627c0` and `Unk_366110` had two
  loads in the other order; with it they match.
- The code prefers early returns: `if (result != 1) { ...; return result; }`
  and a final `return 1` gave `Unk_360550`'s code where one `return result`
  at the end didn't.
- Whether a `Reserve(count)` is inside `if (count != 0)` or called
  unconditionally (it tests the count itself) decides whether the first
  load in the loop that follows is hoisted (`Unk_35ff30` has it
  unconditional three times, `Unk_363980` guarded).
- An item added through `AddLast()` and then assigned from a struct passed
  **by value** keeps one store of the constructor (`strb wzr` in
  `Unk_35ff30`): `value->Set(Unk_360c20_Value)`.
- A member function that the original inlines and the compiler here doesn't
  (cost just over the threshold): write its body in the caller
  (`Unk_367120`). No `always_inline`.
- A helper whose unused parameter gets `mov w3, #1` in the caller is a
  template (or another TU): dead-argument elimination turns the argument
  into `undef` only for functions with an exact definition (`Unk_366f90`).
- A temporary passed as an argument (`Unk_366f90_Key()`) is constructed
  around the other arguments' loads; a named local before the call isn't.
- A `switch` with a jump table of four entries where the source seems to
  have three cases: two cases share a body (`case 0: case 3:` in
  `Unk_363fa0`); the table says which.
- The parameter of a virtual function that arrives in `x1` and is used as
  `w1` is a small struct passed by value (`Unk_363cb0_Id`).
- Calls with more arguments than the callee's recorded name has
  (`Unk_39b730_call`, `Unk_3b1cc0`): through a function pointer cast, and a
  comment.

**More that the compiler does (third batch)**

- **A cast at a call can change the caller's registers.** The second tree's
  first level was a class of this file's naming whose `RemoveAll` had to be
  called under the name `Unk_3babc0.h` gave it (`Unk_39f8e0(Unk_2382c60_Item*)`).
  The `bitcast` before each call left the root's removal (`0x710039a5b0`)
  with the same instructions and four callee-saved registers permuted. The
  class has that header's name now, so the call needs no cast.
- **A function that only has a declaration counts as free to inline
  through.** A wrapper that passes a callback to the tree's visit
  (`Unk_36b920`) had the whole visit inlined (2 KB for 84 bytes) until the
  callback was defined in the same file: the inliner gives the bonus for an
  indirect call it can resolve, and a declaration costs nothing.
- **Arguments in the order of their loads.** A float argument that is read
  before a struct argument is built is to the left of it in the call (`f32`
  and integer arguments don't share registers, so the order doesn't show
  otherwise); a value computed before the call's other loads is a local
  (`Unk_36a6b0`).
- **Filling a struct member by member** (loads and stores in turn) is not
  a constructor with one argument a member (all loads, then all stores).
- **Locals get their stack slots in the order of their declarations**, the
  first one highest (`Unk_23829f8::vf5`: the two `u32` a stream call writes
  to were swapped).
- **The width of an expression decides where a zero extension is.** Where a
  `u16` count is compared and later turned into a number of bytes, the
  original extends it twice (`cmp w8, w21, uxth` and `and w8, w21, #0xffff`):
  the bytes are computed in 64 bits (`(u64(count) + 7) >> 3`, narrowed
  later), so EarlyCSE doesn't share the extension with the comparison's
  (`Unk_23829b0::vf6`). The copy of the same class computes them in 32 bits.
- **A `void*` parameter puts casts in compares.** `Unk_362d20` (a destructor
  that `deleting_dtors.cpp` declared with `void*`) compares a member's
  address with a pointer; the address is a cast of a byte offset there, and
  InstCombine moves casts to the right of a compare (m, one instruction).

**The two five-level trees (`Unk_36fa70.cpp`)**: sorted arrays of nodes
(vptr, value, flag, the next level's array, key; 0x30 bytes at
`0x710036fa70`, 0x28 at `0x71003a1830` where the value is a `u32`), the last
level an array of 16-byte items. One set of macros writes every level of
both (`UNK_36FA70_NODE`, `_LAST`, `_ROOT`), and the functions are members
that call the same member of the level below: `Set`/`Insert`/`GrowArray`/
`Unset` of the arrays, `Remove` and `RemoveAll` of a key, `ForEach` (a
callback for every value, which says what to drop), `ForEach` and `Visit`
by a key with wildcards, `Has` and `Find`. 87 functions, 40 KB. What they
needed:

- **A node is a base class with the fields and a derived class with the
  key**, each with a vtable, so that the vptr is stored after the members.
  The value is a class around a pointer in the first tree and a plain `u32`
  in the second; the last level's array has a constructor of its own. All
  three change which address GVN keeps across the placement new's null test.
- **Which accessor reads the length decides an operand order.** The visits
  end with "no value and no nodes left". With `IsEmpty()` the length's load
  is merged early with the loop's `End()` (same accessor class), it ranks
  below the flag's load and Reassociate puts it first (`orr w8, w8, w9`);
  with `Length() == 0` (the base class's accessor, another GEP) the merge
  comes after Reassociate and the flag stays first, as in the original.
- **The order of an `if`/`else` in the source decides block placement
  ties.** `if (filter.IsAnyHere()) { loop } else { one node }` matches all
  five levels of the visit by a key; with the branches swapped one level's
  loop test is duplicated instead of the final test.
- **An explicit `inline`** on `Visit` (three functions, two levels each):
  the level below is inlined at a cost between 250 and 325.
- **`if (flag) return &value; return nullptr;` is not `return flag ? &value
  : nullptr;`.** The first leaves a conditional branch to the return block,
  which SimplifyCFG turns into a return of its own for that path; the
  function's other returns are then all null and share one block
  (`cbz x0` to `mov x0, xzr; ret`). With `?:` the return block keeps a phi,
  the null check's edge gets a block of its own for the copy, and AArch64's
  redundant-copy pass deletes `mov x0, xzr` after `cbz x0` (a bare `ret`).
- **Two values compared by value are both loaded first**: the functor's
  test of the last level is `cmp`/`ccmp` (`Unk_36fa70_Key5::IsWider(other,
  key)`, both structs by value), the levels above it branch after each load
  (members with a reference).
- Near misses left: `0x71003a0510` (M: the original reads the last level's
  key again in every iteration, here GVN's load PRE keeps the read before
  the loop for the first one), `0x71003a3bb0`/`0x710036e100` (m: `cset`
  and `and` in the other order), `0x710039f290`/`0x710036d790` (m: a null
  check branches to the other of two `ret`s) and the `Set` paths
  `0x7100370110`/`0x710036b090`/`0x710039c830` (M: the original shares the
  block that sets a node's value between the inlined levels).

**Left out, and why**

- `0x710035f4e0`, `0x710035f550` (destructor pair of the object of
  `Unk_35f4e0.cpp`): the loop that empties the list stores either the next
  item or null in two branches (`cbz next`), and every way tried to write
  "remove the first item" compiles to one store. The same list's `AddFirst`
  has two branches too and matches (`Unk_362360_List::AddFirst`).
- `0x7100361c80` is `m` (two loads after a call in the other order),
  `0x7100366380` is `m` (two instructions before a loop), `0x71003807d0` is
  `M` (block layout of the array's copy loop).
- `0x71003641b0`, `0x71003637d0` (the list of playing items returned to a
  pool of 0x3c00-byte chunks): heavy register shuffling, not tried.
- `0x7100391040` (972 bytes, a bank reader that sets bitfields): not tried.
- `0x7100394850` (M): the stream write of `Unk_23829b0`. The original sets the
  failure's result before the first, third and fourth write only (the
  writes of two bytes, whose size is the same constant); here before the
  fifth too.
- `0x7100395830`, `0x7100395920`, `0x7100395a20`, `0x7100395b30`-`0x7100396050`:
  classes built on `Unk_Registered`, whose template is in `registered.cpp`
  and would have to move to a header first.
- `0x710035fa60` (1,176 bytes) parses a RIFF file (`RIFF`/`WAVE`/`fmt `/`data`
  /`cue `/`LIST`/`smpl`... chunk tags in registers): not tried.


## Range 0x71003b6ee0-0x710040f550

Notes from decompiling this range (the switch container and its subscriber
classes, the switch and state managers, and what follows).

The container templates decide most of the code here, because nearly every
function inlines some of them. What made them match:

- **Iterators are structs returned by value** (`Unk_Array::Iterator`,
  `Unk_KeyList::Iterator`). With raw pointers the search after `FindEx` is
  folded with the loop's end test; with the struct the compiler keeps the
  loop's exit value and the `End()` compared after it apart, which is what
  the original shows (`mov x8, x9` after the loop, then `cmp x9, x8`).
- **`GrowArray` constructs each item in place before it assigns it**
  (`new (items + i, Unk_Placement()) T; items[i] = field_0[i];`). The
  placement-new's address is the first use of `items + i`, so the
  destination is computed before the source is loaded.
- **Items that are pointers must be pointers in the source.** An integer of
  the same size (`u64` for an object pointer) schedules the same copy loop
  differently.
- **`Insert` has an inline hint.** The original inlines it into
  `Unk_SortedKeyArray::Set` together with the array growth, past the default
  threshold (cost 260 and 305 against 250; an explicit `inline` gives 325).
  When a container function is called out of line here but inlined in the
  original, compare the inliner's remarks (`-Rpass=inline
  -Rpass-missed=inline`) before changing the code.
- **A loop that searches a constant table belongs in the function that uses
  the result** (`Unk_HashListBare::Reserve` and the prime table), not in a
  helper: a helper is unrolled on its own and then inlined, which puts the
  code after the loop behind all the unrolled tests, and one compare comes
  out as `cmp #0x35; b.hs` instead of the original's `cmp #0x34; b.hi`.
- **A struct passed by value to an inlined function** shows as a copy through
  two registers with the padding carried along (`Unk_23837d0::SetNodeParams`:
  12 bytes as `x26` and `w23`, the bit-fields inserted into the low byte of
  `w23`). Assigning the struct directly copies it piecewise instead.
- **A parameter the callee doesn't use isn't set up by callers in the same
  TU** (`Unk_3b8370`'s `this`): the callee is in the caller's file.
- The bank readers take the address of their data pointer parameter
  (`Unk_ReadBank<T>(data)` on a reference to the parameter itself), so every
  read stores the pointer back; reading an 8-byte struct in one go is one
  load, two 4-byte reads are two loads with a store between them.

Classes with destructors are written as real classes (`Unk_23837a8`,
`Unk_2383770`): an abstract base's deleting destructor is the 4-byte trap,
its complete destructor an alias of the base one.

What the switch container's own functions (`Unk_23837d0.cpp`) showed:

- **The intrusive lists are one template with policies** (`block_pool.h`:
  `Unk_ListPolicy<T, Count, Last>`; `Unk_ListLight` counts its items,
  `Unk_ListWithLast` keeps the last one). "Remove the first item" stores the
  next item or null in two branches (`cbz next`; `str next` / `str xzr`)
  only when the next item is read through a function returning a reference
  (`Unk_ListNext<T>::Get`) and a call follows the store of null (the last
  item's policy: `SetLast(nullptr)`, empty in a list without one). Before
  the inliner runs, the load that only feeds the store becomes an integer
  load, and the call keeps the two stores from being merged; afterwards
  they have different types and stay apart. Written with the member
  directly, the two stores fold into one. (This is the form the destructor
  at `0x710035f4e0` needs.)
- **A test of an item against an optional filter compares first and asks
  for "no filter" second**: `(item->object == object || object == nullptr)`.
  The second block then has no load, the two tests fold into one `or`, and
  the loop is unswitched on every invariant (`Unk_3b92b0`: four copies of
  each loop). With the null test first, the loop that knows `object !=
  nullptr` isn't unswitched on the second filter.
- **The children's array holds one-pointer structures**, and its binary
  search takes the item's address before it reads the key through it
  (`Unk_23837d0_Children`). The address then has a use that isn't a load, so
  LICM doesn't compute it again after the loop, and the original's
  `add x10, x11, w14, sxtw #3; ldr x15, [x10]` comes out. With plain pointers
  (or with `Unk_SortedKeyArray`'s search) the load takes the index instead.
- **The class derives from the node class its parent pointer has**
  (`Unk_23837d0_Node`). `if (child->field_78 == self) ... self->vf3()` calls
  through `self`'s vtable with the loaded parent as `this`: the call's `this`
  is `self` converted to the base, which GVN replaces by the older equal
  value, and the vtable load isn't that conversion.
- **A loop that came from an inlined function has its entry test already**,
  and the test folds with an earlier one. `Unk_3b8500` looks a value up twice
  in a list (two inlined `Exists`) and then walks the list: the walk's
  `first != nullptr` is only removed when the walk is an inline function of
  its own (`Unk_23837d0_AskNodes`), rotated before it is inlined; written in
  place, the loop is rotated after jump threading and the test stays.
- **A structure passed by value is put together before the call**, and the
  instructions that do it are sunk to the top of the block that stores it
  (`AddLastGrowValue`: `mov w10, #1; bfi x10, x11, #32, #32` before the
  item's address). By reference, they come after the item's constructor.
- **The key of a group's value is default-constructed and then given its
  fields** (`key.field_0 = object; key.field_8 = 0;`): that order of the
  stores is the original's; the constructor with the object isn't.
- A global the TU defines is reached without the GOT: declare it with
  hidden visibility (`Unk_24deec8`, the pool of the playing children).

Open:

- `Unk_3b7ed0` (the switch container's bank reader, `m`): block placement
  only. The original has no shared preheader block before the loop over the
  switch values (both paths into the loop set the counter themselves, and the
  head of the loop is duplicated after the list's preallocation); here the
  preheader survives. Probably the order of the IR blocks: an empty block is
  only removed before placement when it doesn't fall through to its successor.
- `0x71003b7820` and the other static initialisers that construct a lock:
  the lock's destructor is named as a function taking the mutex
  (`Unk_32ec70`), so the `__cxa_atexit` call can't come from a class's
  destructor yet.


## Range 0x71003035e0-0x710035ead0

Notes of the sessions that work on this part of the block. Placeholder names
throughout.

**What is where**

- `Unk_237e948.*`: the Opus decoding thread ("AK::OpusDecodingThread", 24
  decoder slots on the SDK's `nn::codec::HardwareOpusDecoder`), a global object
  constructed by the TU's static initialiser.
- `Unk_334a10.cpp`, `Unk_3358b0.*`: the audio thread ("AK::EventManager") and
  the audio manager it serves (the message queue, two lists of waiting
  actions). `Unk_Thread.h` has the thread wrapper (an `nn::os` thread, its
  stack and the properties the platform settings give each thread).
- `Unk_334be0.*`: the object index (14 hash tables with their locks, the
  object `Unk_Indexed.h`'s `Unk_24bbbb8` points at).
- `Unk_237c170.h`, `Unk_237d540.h`: the base classes of the sound engine's
  nodes. `Unk_307850.cpp`, `Unk_30d8c0.cpp`, `Unk_30ed50.cpp`: three node
  classes on them.
- The node hierarchy, as the vtables and the constructors show it:
  `Unk_2382098` (the root, 0xa0 bytes, 71 slots) -> `Unk_2381d78` (0xb8, 74)
  for one family, and two templates on either: `Unk_NodeParent<T>` (T and its
  sorted children, two more slots, abstract) and `Unk_NodeActiveParent<P>`
  (what a node passes on to its children; no vtable of its own in the
  executable). The same template code is there twice, over the root with the
  children at 0xa0 and over `Unk_2381d78` with them at 0xb8.
  `Unk_NodeParentImpl.h` has the templates' member functions and the inline
  virtual functions of the two classes: a file includes it when it is the
  first class of an instantiation, as the executable has one copy of each.
- `Unk_34ae50.cpp`: `Unk_237f528`, the plain container node over
  `Unk_2381d78`. `Unk_237ff98.h`, `Unk_351840.cpp`: the node class with two
  sets of children over the root (0x168 bytes), and `Unk_34d760.cpp`: the class
  derived from it.

**What the compiler does that the source has to allow for**

- **Volatile members.** Code that keeps every load and store apart and in
  source order, where the compiler would merge adjacent zero stores or keep a
  value in a register, works on `volatile` fields: the slots' fields the
  decoding thread shares with its clients, the message queue's pointers, the
  audio manager's counters. A zeroing loop over a volatile array stays 24
  `strb`. Non-volatile stores between two volatile ones keep their place too.
- **Real classes for classes with several vtables.** The destructors' thunks
  for the vtable at 0x18 are the destructor's body inlined behind the pointer
  adjustment. Written as a class with virtual functions and the creator's
  `new (pool) T(id)`, the compiler emits the vtable, D2, D0 and both thunks.
  The thunk only comes out as in the original when the class's last members
  are declared with their real types: instcombine rewrites `this - 0x18 + x`
  as an offset from the unadjusted pointer when it finds a field of the class
  at that offset, and it looks at offset `sizeof(class) - 0x18` first. A byte
  array as padding there makes every access relative to the unadjusted
  pointer, and the thunk gets longer.
  `Unk_NodeA/B/C` in `Unk_237c170.h` give the three vtables their shape (83,
  17 and 3 slots); a slot's declaration gets its signature when a class
  overrides it (an override with another signature would add a slot).
  A class whose key function is in another TU doesn't get its vtable here:
  define its first out-of-line virtual function in the same file.
- **The creators.** `new (pool) T(id)` with the constructor inline, then
  `Register()`: a virtual call of slot 17 (the node's kind), folded to a
  constant where the constructor's vptr store is still visible (no call
  between it and the load), and a real virtual call otherwise.
- **Inline helpers that take what they need as parameters** decide the order
  of loads: `queue.Init(pool, size)` loads the pool ID before the size, and
  `queue.Term(pool)` loads it before the null test. A thread routine that
  casts its argument and calls an inline member function keeps the member's
  GEPs whole (`this + i + 8`); the same loop written on the `void*` argument
  splits them and hoists `this + 8`.
- **`AkDelete`-like code** reads the pool ID before the destructor call:
  `int pool = Unk_237e820; p->~T(); Unk_3047c0(pool, p);`, with the pointer in
  a local first when the member is volatile.
- **Clamps** are `if (v >= 0) { if (v > 1) v = 1; } else v = 0;`: the
  conditional-operator forms become `fmin`/`fcsel mi`, this one the original's
  `fcsel le`/`fcsel lt`.
- A helper that two functions inline whole needs `always_inline`: the two
  list flushes of `Unk_3358b0.cpp` are one shared function otherwise.

- **Fast math.** The library is built with `-ffast-math`
  (`docs/compiler.md`, "Fast math"): an accumulating float add has the loaded
  value first and the accumulator second whatever the source says, and
  `a > b ? a : b` on floats is an `fmaxnm`. `fmaxf()` is an `fmax` with the
  flag, so a maximum in the original's `fmaxnm` is the comparison.
- **A float parameter's place in the signature.** The registers are the same
  wherever it is, but not the order of the argument copies at the function's
  start, which the scheduler and then the register allocator follow: slots 26
  and 27 take their float first (`vf26(f32, void*, void*, bool)`). With it
  last, `this` and the first pointer argument come out in each other's
  callee-saved register. `-mllvm -print-machineinstrs` shows the copies before
  the allocator.
- **Whose destructor a slot is.** A class with an empty out-of-line
  destructor has its own D2 (the base's body inline, or a tail call when the
  base's is in another file), D0 and thunks at the start of its file. A
  template base's D2, with a trap for its D0 when it is abstract, comes later
  in the file, with the template's other functions in vtable order.
- **Tests that share a return.** `if (a) return true; if (b) return true;`
  keeps one branch and one copy of the return for each test, except where
  SimplifyCFG folds a test into the one before it: only a test with at most
  one more instruction than the compare, none of them a load the compiler
  can't speculate. So the order of two adjacent tests shows in which of them
  share the `mov w0, #1`: in `Unk_3536a0` the pointer at 0x88 is tested
  before the bit of the word at 0x9c, though the code tests the bit first.
  Such a function is the predicate itself, out of line, not a wrapper of an
  inline one.
- **A loop over an array that calls out** reloads the array's fields: the
  reverse walks are `--i; items[i]->f(); if (i > length) i = length;`, with
  the decrement before the items are loaded.
- **Reading the passes.** `-mllvm -print-after-all -mllvm
  -filter-print-funcs=<mangled name>` prints one function's IR after every
  pass, and `-S -emit-llvm` the final IR: that is how the fast-math order and
  the folded tests were found.

**Left out, and why**

- `0x7100305830`, `0x7100306180`, `0x7100306340`, `0x71003064b0`,
  `0x7100306630`, `0x71003067b0` (the module at `Unk_305720.cpp`): loops over
  the object list. The original unswitches them on both invariant conditions
  and keeps two copies of the loop variable; every spelling tried is
  unswitched on one condition only, at any `-loop-unswitch-threshold`.
- `0x7100306c70`: the search loop's two exits stay two branches in the
  original (`cbz`; `cmp`, `b.eq`), merged into a `ccmp` here.
- `0x7100333b10` (`m`): the Opus thread's constructor, 1,412 bytes, matches
  but for the first three instructions (the vtable's address is loaded after
  the first store).
- `0x7100334cf0`, `0x7100334f70`, `0x71003351b0` (the object index), and
  `0x7100335df0`, `0x7100335f00` (the audio manager's flushes: the original
  tests the action type 0x503 before 0x403): see their `NON_MATCHING` notes.
- `0x7100307b70` (`m`): two stores of the inlined constructor swapped.
- `0x7100307f00`, `0x710030e250`, `0x710030f2c0` (slot 75, "can this node be
  a child"): the binary search over the children comes out without the
  original's null test of the found position, and the return blocks in
  another order.
- `0x7100336100` (the message queue's reserve, compare-and-swap loops),
  `0x7100335c40` and `0x71003368e0` (the message switches): not tried.
- `0x7100352670` (slot 22 of `Unk_237ff98`, `M`): the walk over both sets of
  children. The original reloads the current array's length through the array
  pointer; this keeps a second pointer to the length across the loop (the
  header's GEP is shared with the body's before the loop is rotated). Slot 30,
  the same walk with a test in the body, matches.
- `0x7100353010` (`M`): two property lookups in a row on one set. This keeps
  the pointer to the values for the second (GVN's scalar PRE through the PHI
  of the count, new in LLVM 6); the original computes it again. clang 5.0.2
  doesn't give the original either.
- `0x7100355690` (`M`): the list item is in `x0` here and in `x8` in the
  original.
- `0x7100355880` (240 bytes): creates an `Unk_2380608`, whose constructor
  takes two arguments here (`0x1820`, 0) but has the name of one without
  (`Unk_2380608::Unk_2380608()`, from the generated constructors).
- `0x710034b0a0`, `0x7100354be0`, `0x71003550b0`, `0x7100357770`,
  `0x71003578d0` and the three slot-75 functions above: binary searches over
  the sorted children, which match with clang 5.0.2 and not 6.0.1 (LICM's
  clone of the item's address).
- The rest of `Unk_237ff98` (about 35 functions, 15 KB): not written. The
  larger ones are slot 42 (`0x7100352830`), 52 (`0x7100353820`), 23
  (`0x7100353c40`), 77 (`0x7100356100`), the two static walks over all nodes
  of the class (`0x71003521d0`, `0x7100352440`), and `0x71003552e0`,
  `0x7100355510` (what a node does to another's value). Its fields so far are
  in `Unk_237ff98.h`; the slots not written have placeholder signatures.
- An object held by value is called through a pointer where the original's
  call is virtual (`Unk_237ff98_Item28::User()`): clang calls a member
  object's virtual function directly.
