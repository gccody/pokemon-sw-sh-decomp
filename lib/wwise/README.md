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
