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
and destroys nothing).
