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

**Left out, and why**

- `0x710035f4e0`, `0x710035f550` (destructor pair of the object of
  `Unk_35f4e0.cpp`): the loop that empties the list stores either the next
  item or null in two branches (`cbz next`), and every way tried to write
  "remove the first item" compiles to one store. The same list's `AddFirst`
  has two branches too and matches (`Unk_362360_List::AddFirst`).
- `0x71003627c0` is `m`: the loads of an array's items and length before a
  loop come out in the other order.
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
