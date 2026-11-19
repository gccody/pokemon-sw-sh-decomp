# lib/yebis

Functions of Silicon Studio YEBIS 3 and the SiSDK3 it's built on (the `yebis`
area of `data/areas.csv`). Their source isn't public, so nothing here is
upstream code. They're built with the game's flags: docs/compiler.md,
"Nintendo SDK middleware" and "Other middleware".

- `leaf/` is written by `tools/leafgen.py` (`--out lib/yebis/leaf`), placeholder
  structs and `Unk_<addr>` names like `src/unsorted/leaf`, from the executable.
  Rename them when the library's real names are known. See docs/game_code.md,
  Batch 22.
- `class/` (`tools/leafgen.py members`) holds its RTTI-named classes' small
  virtual functions, placeholder member names `vf<slot>`. See
  docs/game_code.md, Batch 39.
- `sisdk/` is SiSDK3's headers, reconstructed from the code that inlines them,
  at the paths their `__FILE__` literals give (below).
- `instances/` instantiates SiSDK3's class templates for the element types
  whose functions the executable has (RTTI names them).
- `static/` holds the static initialisers of YEBIS TUs whose only static
  object is a `SiReflectionPropertyHandle`.

## Names

YEBIS keeps RTTI: every vtable of `PPFX::` and `SiSDK3::` has its typeinfo, and
a class template's names its arguments too
(`SiSDK3::SiArray<SiSDK3::ISiAllocator*, 16>`). So class and template names
come from the typeinfo, and a virtual destructor's name from its slot. Asserts
compiled into the headers (`__assert_fail` with `__func__`) name a few members
(`m_itemCount`, `m_reservedCount`, `RemoveByIndex`). Everything else is a
placeholder: `field_<offset>`, `vf<slot>`, `Unk_<addr>`.

## Source paths

The `__FILE__` literals (the allocator's file/line arguments) are spelled
`C:/workspace/sisdk/3.0/SDK/Core/Include\SiCore/SiCore_Array.h` in YEBIS's TUs
(`C:/workspace/YEBIS_draft/src/...`) and `../../../../Include\SiCore/SiCore_Array.h`
in SiSDK3's own, compiled four directories below `sisdk/3.0/SDK/Core` (their
names aren't in the binary). `lib/yebis/` mirrors `C:/workspace/`
(`data/source_paths.csv`), so `lib/yebis/sisdk/3.0/SDK/Core/Include/SiCore/` is
the original's `SiCore` include directory, and check.py compares those
literals by the file they name. `__LINE__` is compared as is: the headers keep
the original's line numbers with `#line`.

## SiSDK3 containers

`SiSDK3::SiArray<T, ALIGN>` (`SiCore_Array.h`, 0x50 bytes): a vtable (a
virtual destructor only), the allocator, `m_itemCount`, `m_reservedCount`, the
element size, the buffer and three more words, and flags (bit 0: the buffer
isn't the array's own). The buffer is an array allocation of the allocator
(`ISiAllocator`, `SiCore_Memory.h`): its vf8 allocates, vf10 tells an array's
element count and vf9 frees. The array delete destroys each element first,
except for pointers and the builtin types (`unsigned long` isn't one of them,
`unsigned long long` is: SiArray<unsigned long>'s destructor asks for the count
and destroys nothing). It takes the pointer by reference (it clears it), and
its line parameter is 64-bit: its one out-of-line copy, 0x710056de40, shows
both.

The members are defined outside the class without `inline`, as the inlining
shows: the original keeps SiArray<RollingPerfData<float>>'s release
(0x71004e3050) out of line, which an inline hint would have inlined. That
instance, its `<int>` twin and two others still inline differently here
(clang defers the array delete into the destructor instead of the release:
the original TU's other calls decide that), so they aren't instantiated yet.

`SiDirectLinkedList<T*>` (`SiCore_LinkedList.h`) is intrusive: each element
type has its own links, at its own offsets.

`SiMap<K, V, Compare, 16>` (`SiCore_Map.h`) is a tree of nodes that know their
map; the single-object delete (`Unk_4c25a0`, by value, a 64-bit line) stays
out of line because a node's destructor deletes its children with it.

`SiReflectionPropertyBase` (`SiCore_Reflection.h`) has two strings and the
links of the list that holds it. Its derived templates
(`SiReflectionProperty<T>`, `SiReflectionPropertyArrayReference<T>`) add only
trivially destructible members, so clang replaces their destructors with the
base's where they're implicitly instantiated (one function, 0x71004d0140, in
all their vtables); the explicit instantiations here emit copies, listed in
`data/absent_functions.csv`. Only their deleting destructors are their own.

## Reference counts

Every SiSDK3 class (and PPFX's `SiYebisAllocator`) has its own copy of vtable
slots 2 and 3: an atomic increment of a count, and a decrement that, at zero,
calls the virtual destructor and frees the object through the allocator it
holds (unless the allocator is the object itself). The free's `__FILE__` is
the class's own header and its line is one per class, so the members come
from a macro expanded in each class's header: `UNK_REFCOUNT_DEFINE`
(`Include/SiCore/Unk_RefCount.h`, placeholder names, members `vf2`/`vf3`)
reproduces it. Each class gets its header at the path its `__FILE__` names
(`Libsrc/SiCore/Source/SiCore_Kernel_Impl.h`, `YEBIS_draft/src/GPU/...`), with
its layout as far as these functions read it, and a TU next to it that
includes it. A class with a second base keeps its count further on; ten of
those aren't written yet, because leafgen already gave `vf3` to a slot of
their secondary vtable. The GPU resources' slot 3 (`SiGfxNXBuffer`, ...) is
another macro, with deferred deletion, not written yet.

### Instances of identical code

Template instances whose code doesn't depend on the type (every 8-byte
element's `Unk_4bf190`, the reserve) are named only where the executable ties
an address to its type: a vtable slot (destructors), or a caller that's a
virtual function of a class whose vtable group's functions store
`SiArray<T>`'s vtable at the same offset of `this` that it calls the instance
on. 23 of the 47 copies of `Unk_4bf190` have such a caller; the other 24 are
called only from functions of no known class, so each is instantiated for a
placeholder pointee named after its copy (`Unk_<addr>*`): the code doesn't
depend on the type.

`SiPool<T, 16>` (`SiCore_Pool.h`) hands out T's from blocks (`DataArray`, the
first one inside the pool) and keeps them in a free and a used list. Its
destructor, deleting destructor and reset (slot 4) are written; its clear
(slot 3, `Unk_4be7d0`) is only declared, since its loop keeps other base
registers than the reconstruction, and its initialise and reserve (slots 2
and 5) need the element types' constructors (the reserve constructs every new
element in place).
