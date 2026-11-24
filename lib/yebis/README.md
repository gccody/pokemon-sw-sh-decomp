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

## License key material

YEBIS checks a license at start-up (`ppfx.cpp`, 0x7100418840, with
`UT/ppfxLicense.cpp`). The check passes two 32-byte strings from the
executable's rodata to the decoder: Sword 0x7101b32879 and 0x7101b05d89.
They're Silicon Studio's license key material, so they're never written
into this repository, printed, or copied into notes or PR text. The code
refers to them only as undefined externs. check.py compares a reference
to a data symbol by its address (the `data_symbols.csv` row), not by
content, so the functions can match without the bytes.

A build that needs the bytes themselves (a byte-identical executable)
must generate their definitions at build time from the user's own
`data/original/` dump. Those generated files are gitignored, like the
`*.pb.cc` files that `tools/protos.py generate` writes. Don't add a
fallback that spells the bytes out. Tools that print strings or data
(`funcs.py show` aside) must not be pointed at those two addresses.

Two idioms decided the decoder (0x71004ba5a0):
- **An argument the callee doesn't use, kept in the caller:** the original
  passes `this` to 0x71004baf20 (`mov x0, x19` before each call). LLVM's
  dead-argument pass turns an unused `this` into undef at the call sites,
  and the move disappears. The callee used `this` before inlining: its bit
  reads call an inline member (`Unk_NibbleBit`). Write it that way rather
  than adding a fake use.
- **The stack slots follow the declaration order:** the tree's leaves are
  declared first, then the inner node, with every pointer before every size.
  The frees follow that order too.

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

## PPFX's texture shader set and TinyEffect string

`YEBIS_draft/src/GPU/GPUTextureUtil.cpp` has `PPFX::TEXSHADERSET::CreateEffect`
(0x7100463fd0, 36,868 bytes: it was the largest undecompiled function) and the
eight helpers before it. The class and the function are named by its log lines
(`"TEXSHADERSET::CreateEffect(): IGPUEffect::CreateEffectFromFile() ..."`),
which leave the namespace out as they do for `PPFX::IGPUEffect`. The function
is the list of the effect's parameters and techniques: 265 handle lookups, 141
calls of the helpers and 68 families of numbered techniques (`tech_MadT1_Sn`
with `n` from 1 to 32), each a call of one inline helper (its locals sit above the function's own in
the frame, which is where inlined allocas go, so it wasn't a macro). The body
and the class's layout (`field_<offset>`, arrays from the address
progressions) were generated from a symbolic trace of the original's calls
and stores and then kept as source.

The helpers' suffix tables and their "filled in" flags are static variables
of the GPUTextureUtil translation unit, which LLVM merged into one object
(0x71024e45d0, `.L_MergedGlobals`, used by functions from 0x7100462fe0 to
0x7100499b70) and whose flags it shrank to one bit. They are written as the
real statics (file-scope tables and flags, function-local statics), and the
TU's static initialiser 0x7100499b70 matches: the comment above
`Unk_24e4a18` in `GPUTextureUtil.cpp` gives the layout and why the order of
the functions and their statics decides it.

`YEBIS_draft/src/GPU/TinyEffect/TFXString.{h,cpp}` is the string those use
(`TFXString.cpp` is the `__FILE__` of its allocations and asserts; `Clear`
and `Construct` their `__func__`). 20 of its functions match. What its code
shows: the constructors are inline and call functions that return the string
by reference (LLVM 7 doesn't tail-call a callee whose return value carries
`dereferenceable` from a caller that returns nothing, and none of the
by-value operators tail-calls them); the range checks read the length into a
local first (the early-exit block is then laid out last). Not matching:
`Unk_4525a0` (a number's digits: one `msub` is scheduled later than the
original's). Not written: `Unk_451900`, `Unk_451f00`, `Unk_4520d0`,
`Unk_452400`.

## PPFX's src/GPU classes (0x7100481000-0x71004bc640)

Notes of the work on the rest of `src/GPU` (`GPUResourceManage.cpp`,
`GPURenderTexturePool.cpp`, `GPUGlareDef.cpp`, ...), for whoever continues.

**Each `.cpp` is one TU, and its statics decide a lot.** Every src/GPU TU
includes a header with static objects (`Unk_Statics.h`: two objects made by
`Unk_410f90_set`, a reflection handle, 24 white points and an angle). LLVM's
GlobalMerge puts a TU's statics in one block, sorted by size (stable), so
the offsets its functions use tell the TU's whole set of statics: 4-byte
ones first, then the 8-byte white points (and function-local statics'
guards), the 0x20-byte objects, the handle (0x78), and the TU's own tables
after them. A TU whose only statics are the header's has a 616-byte static
initialiser (five of them match that way); a file's own statics shift the
block, which is how to find them. A function that reads a TU's statics only
matches once the TU has all of them.

**The vectors' elements aren't plain floats** (`include/PPFX/ppfxTypes.h`):
the initialisers store the white points as integers. What shows it is one
constant materialised as another plus a small difference (`add w8, w8,
#0xa7d`): LLVM's constant hoisting only does that to integer immediates.
A constructor taking element objects by reference and copying them as
objects compiles to that; one taking floats doesn't.

**Allocation** (`Unk_Array.h`): single objects are a placement new on
`Unk_4b99a0`'s result without a null check; arrays keep their count before
the first element, and their delete loop can't be removed. PPFX's containers
are libc++'s (`std::vector`, `std::list`) on `Unk_StlAllocator`
(`GPUMemoryAllocator.h`, whose line 440 is the allocation's `__LINE__`), so
`lib/yebis/YEBIS_draft` is built with libc++'s headers (CMakeLists.txt).

**Idioms that decided matches**

- Struct copies are `memmove`, not assignments: the zeroing before a copy
  survives in the original, which a `memcpy` (what an assignment is) lets
  LLVM remove. Clearing an object is `memset(this, 0, sizeof(*this))`.
- `CGPUResourceManage::RegisterStaticGPUDevice` takes the object as a
  parameter (it's static): the pointer is spilled at entry because its
  address goes to `push_back`.
- An inline setter (`Unk_SetC(bool)`) converts its flag where it is called;
  a plain assignment of a `bool` parameter reuses the conversion made at the
  function's entry, and the two end up in different blocks.
- A description built in an inline function (`CRenderTexture::Unk_Create`)
  sits above the caller's own locals in the frame.
- `if (++count >= limit) break;` after `array[count] = x` keeps the counter
  in one register; `array[count++] = x; if (count >= limit)` doesn't.
- Functions that lib/yebis/leaf's generated callers already name
  (`Unk_49fc60`, `Unk_49ca70`, ...) keep that free-function name. Their first
  parameter is typed as the class (`CRenderTexturePool*` for `Unk_49fc60`):
  casting a `void*` inside the body turns the member addresses into byte GEPs
  that Reassociate ranks lower, which swaps compare and add operands.

**Names**: `CGPUResourceManage::RegisterStaticGPUDevice` and
`CRenderTexturePool::AllocateTextures` are named by their log lines, the
classes by RTTI (CGPUBaseResourceManage is CGPUResourceManage's base; its
vtable isn't in the executable). Virtual functions are `vf<slot>`, as
lib/yebis/class names them.

## SiCore (0x71004bc640 to 0x71004ca7a0)

SiSDK3's core library starts YEBIS's second half. Its TUs, in address order
(a TU ends with its static initialiser; the ones that only construct the TU's
`SiReflectionPropertyHandle` are lib/yebis/static's):

| Range | File | What |
|---|---|---|
| 0x4bc640-0x4bc6c0 | `Unk_4bc640.cpp` | the kernel's allocator or the static one |
| 0x4bc7f0-0x4bf5e0 | `SiCore_FixedHeapAllocator2.cpp` | the allocator over fixed regions, its header pool |
| 0x4bf660-0x4bf6b0 | `Unk_4bf660.cpp` | the allocator and count every object keeps: its constructor |
| 0x4bf730-0x4c2cd0 | `SiCore_Kernel_Impl.cpp` | `SiKernel` (lib/yebis/class has its accessors) |
| 0x4c2cd0 | `Unk_4c2cd0.cpp` | the static `SiHeapAllocator` (the kernel TU's initialiser) |
| 0x4c2d70-0x4c32e0 | `SiCore_HeapAllocator.cpp` | the allocator over the memory system |
| 0x4c3360-0x4c35c0 | `Unk_4c3360.cpp` | CRC-32 |
| 0x4c3640-0x4c4100 | `Unk_4c3650.cpp` | `SiMemorySystem`: malloc with a header, 65536 lists by address |
| 0x4c4290-0x4c6010 | `SiCore_String.cpp` (0x71004c49f0's allocation's `__FILE__`) | string functions, `SiString`'s out-of-line members |
| 0x4c6090-0x4c8620 | `SiCore_StringTable_Impl.cpp` | `SiStringTable` and its `Entry` |
| 0x4c86a0-0x4c8840 | `Unk_4c86a0.cpp` | `SiCoreCriticalSection`, the scoped lock |
| 0x4c88c0-0x4c8ef0 | `SiCore_SystemInfo_Impl.cpp` | `SiSystemInfo` |
| 0x4c8f70-0x4ca620 | `SiCore_Utility.cpp` (the default allocator callback's `__FILE__`) | ids (`SI_GUID`), the tick's period, noise, a string's formatting, names of numbers, the default allocator's callback; a report function, languages (not written) |
| 0x4ca6a0-0x4ca7a0 | `Unk_4ca6a0.cpp` | the noise's tables |

What decided matches here, beyond the list above:

- **A trap that returns** (`b.ne` over the word `0xe7ffdefe`, code going on
  after it) is `__builtin_debugtrap()`: on AArch64 it's lowered like a trap,
  without ending the block. `__builtin_trap()` ends it. The allocators trap
  like that on an allocation number, address or size set for debugging.
- **CallSiteSplitting** (LLVM 7, -O3) duplicates a call whose argument is
  tested for null right before it: `if (p != nullptr) list.Remove(p);
  list.AddTail(p);` gets a second, specialised `AddTail` for the null path.
  The original has one: its null test is inside `Remove`.
- `size_t index = a / b; array[index]->n++;` loads the array after the
  division; `array[a / b]->n++` loads it first, and the registers follow.
- An address taken as `(u8*)this + 8` isn't shared with the member's own
  address: `SiMemorySystem`'s destructor locks through the first and destroys
  the second, and so keeps `this` alone across its calls.
- `&blocks[middle + 1]` and `blocks + middle + 1` are the same address but not
  the same order of the two additions around it; a recursive sort's second
  call needed the first form (the tail call becomes the loop).
- Two inner scans of a partition, each `while (a) { if (++i >= j) break; }`,
  are bottom-tested in the original: LoopRotate leaves a loop alone whose
  latch already exits, so they are written `if (a) { do { ... } while (a); }`.
- The registers of two loop counters follow their declarations: declaring
  the index first or the count first swaps them (`size_t i; int n = 0;` or
  `int lines = 0; for (s64 j = 0; ...)`).
- `for (...; n < limit && p != nullptr; p = p->next) { a[n] = p; n++; }`: the
  limit in the loop's condition and the increment as its own statement give
  one widened counter; `a[n++] = p` with a `break` gives two.
- A class's function that has an unused parameter and is called with
  different constants for it is `inline` (or a template): the calls keep
  their constants only for a function the linker may replace.
- `Unk_Clear()` as `Unk_Empty(); field_20 = 0; field_28 = 0;` (a nested
  inline function) and as five statements differ in which stores the exits
  of `SiString`'s capacity setter share.
- When only the order of a few stores differs, permuting the statements with
  a script and the single-TU compile settles it in minutes (four to six
  statements; the order that matches is often not the address order).

`SiKernel` added these (the class is `SiKernel : ISiKernel : ISiInterface` by
its RTTI; the file writes it as one class):

- **One more inline function is one more run of the function passes**, and it
  shows. `SiArray`'s clear (0x71004e3050: free, then six zero stores) keeps
  `m_pData`'s store apart from the two after it when it is inlined straight
  into a function that also reads `m_pData` in a loop (GVN's scalar PRE makes
  the address a phi, and MemCpyOpt can't merge through a phi); through an
  inline wrapper (`Unk_FreeAll() { Unk_4e3050(); }`) MemCpyOpt has already made
  the three stores one 24-byte memset in the wrapper, and the caller keeps
  `&m_pData` in a register for it (`str xzr, [x20]; stp xzr, xzr, [x20, #8]`).
  The array's destructor is such a level by itself. The kernel's set-up has
  the same thing one level up: the string tables' array gets its allocator and
  its buffer in a kernel inline function of its own (`Unk_SetTablesAllocator`),
  which is why the buffer's free is gone on the path where the allocator
  changed (jump threading in the inline function, then GVN's load PRE in the
  caller) and the buffer's address is computed on both paths.
- `if (p != nullptr) f(p); else f(&global);` is two calls that the back end
  merges; `f(p != nullptr ? p : &global)` is a select that loads the global's
  address from the GOT on both paths.
- A counter that is read again after every write (`ldr; add; str; ldr`) is
  `volatile`: the kernel's set-up count, and the reference count's member
  (its constructor stores the count and the word after it one by one, where
  two plain 32-bit constants would be one 64-bit store).
- `SiArray::RemoveByIndex` takes an `int` and compares a signed 64-bit index
  with the count; the loop that calls it counts an `int` down. The mix of
  `sxtw` and signed compares in the removal says so.
- `SiString`'s clears in the kernel are the nested one (`Unk_EmptyAll`): the
  16-byte store of buffer and length comes before the two single stores.
- A buffer on the stack that is 0x404 bytes when 0x400 are passed on
  (`sub sp, #0x420`, the buffer at `sp+0xc`): `char buffer[0x400 + 4]`.
- A function that keeps its `int` result in x0 through a loop and returns
  without setting it returns that value: `vf20` returns the array's count.
- Globals reached with `adrp`+`add`/`str` instead of the GOT, but used from
  another TU's code too, are hidden-visibility globals here
  (`__attribute__((visibility("hidden")))`): the kernel pointer, the tick's
  period, the kernel's own string table's id.
- The append's growth (`step != 0 ? step + reserved : (2 * reserved != 0 ?
  2 * reserved : 1)`) is a branch in IR that the back end's early
  if-conversion turns into `csel` or leaves, by the code around it: written
  as a default that is then overridden it is always a `csel`, which matches
  `vf20` better and breaks two of SiGfx's readers. It stays a branch.
- Float code is scheduled twice (the post-RA scheduler of the Cortex-A57
  tuning): the registers follow the order before register allocation, the
  instructions the one after it. `Unk_4ca6a0` needed its three products as
  named locals; the noise function itself (0x71004c9110, 344 bytes) has the
  right instructions in another order and isn't written.

`SiStringTable` (RTTI: `SiStringTable : ISiStringTable`, which is on
`ISiInterface` and, at 8, `ISiNamedObject`; `SiStringTable::Entry :
ISiStringTable::IEntry : ISiInterface`) added these:

- **The second base's vtable is thunks.** The table overrides the named
  object's three functions, so they are the last three slots of its own vtable
  and the second vtable has `_ZThn8_` thunks of them and of the destructors,
  with the small ones inlined into the thunk (0x71004c7000, 0x71004c7070,
  0x71004c70c0, 0x71004c70e0). leafgen had taken 0x71004c70c0 for a slot 3 of
  the table; the class's accessors are in the TU now, not in lib/yebis/class.
- A function that ends in a virtual call and still returns through its own
  epilogue returns a reference (`const SiString<char>&`): a pointer result
  would be a tail call.
- A member function whose `this` is reloaded before every call although the
  callee ignores it (the sort's partition) is `inline`: for a function the
  linker can't replace, the callers pass anything.
- One constructor with a default argument, not two: `StringPerLanguage(
  ISiAllocator* = nullptr)`. With a second constructor for no allocator, the
  language's zero and the null allocator are one 16-byte store in an entry's
  four, where the original has two stores.
- `StringPerLanguage`'s assignment copies the language and the string, not
  its 128-byte buffer: its own `operator=`.
- A value read twice with nothing between the reads (`ldr w8, [x26, #4]`
  twice in `Entry::vf7`) is a test written twice: `if (a == b) return ...;
  if (a.language == b.language) ...`. Jump threading merges the two tests
  after GVN has run, and nothing removes the second load then.
- The registers of a binary search's bounds follow their declarations
  (`int high = count - 1; int low = 0;`, both before the first test), and
  with them the operand order of `(low + high) >> 1`.
- Store orders by permutation again: `SiString::Unk_SetView` (length,
  capacity, flag, growth) and `Unk_SetBuffer`.

Not matching yet in these files (status `m`, each with its reason in the
source): `SiFixedHeapAllocator2`'s constructor and `Unk_4bd610`,
`SiPool::Unk_4bcfa0`, `Unk_4c5a40`, `Unk_4c4d90`, `SiKernel::vf20` (block
layout). Not written: the fixed allocator's `vf8` and `vf9` (allocate and
free, 1.4 KB each, intrusive list work throughout), `SiPool::Unk_4be7d0`, the
string TU's conversions (`Unk_4c42b0`, `Unk_4c4700`, `Unk_4c49f0`,
`Unk_4c4f60`, `Unk_4c5280` and smaller ones), the kernel's map of reflected
classes (insert 0x71004c09a0 and erase 0x71004c0e60, a red-black tree whose
nodes have their colour at +0x30), `SiString`'s assignment in the string
table's TU (`Unk_4c8020`: a copy loop unrolled by four), and of the last TU the
report function (0x71004c9090, variadic), the noise (0x71004c9110) and the
languages (0x71004c9390 on). `SiStringTable::vf11` is `m` (where the result's
0 is set). `Unk_4c5930` (a number's digits in groups of three, 264 bytes) was
two instructions away when the work stopped: a 64-bit digit count whose low
32 bits are tested against 0xff, then a bottom-tested loop over a pointer into
the digits with a `size_t` counter, `if (static_cast<s64>(pos) + 1 >= size) {
pos++; break; } pos++;`, and the count decremented for the commas.

## PPFX's GPU layer (0x710040f550 to 0x7100481000)

Each `C:/workspace/YEBIS_draft/src/**/*.cpp` is its own translation unit: its
static initialiser (`_GLOBAL__sub_I_<file>.cpp`) is the last function of its
address range, which is how the ranges below were found. Files whose name no
log line gives are `Unk_<address of the initialiser>.cpp`.

| Range | File |
| --- | --- |
| 0x40f610 to 0x417870 | colour science, matrices: its initialiser (0x415f40, 6,444 bytes) also fills two CIE tables |
| 0x417870 to 0x4190d0 | `src/ppfx.cpp` |
| 0x4190e0 to 0x43dc70 | `src/GPU/GPUPostEffect.cpp` (initialiser 0x43d330) |
| 0x43dc70 to 0x4437f0 | `GPUInterfaceDevice.cpp` (initialiser 0x443570) |
| 0x4437f0 to 0x445dc0 | `GPUInterfaceSurface.cpp` |
| 0x445dc0 to 0x445f10 | `Unk_445e80.cpp`: `IGPUInterface` |
| 0x445f10 to 0x446330 | `Unk_4460c0.cpp` |
| 0x446330 to 0x446a90 | `GPUInterfaceResource.cpp` |
| 0x446a90 to 0x4472c0 | `Unk_447050.cpp`: the formats' names |
| 0x4472c0 to 0x448b70 | `GPUInterfaceTexture.cpp` |
| 0x448b70 to 0x44a050 | `GPUInterfaceBuffer.cpp` |
| 0x44a050 to 0x44ab80 | `GPUInterfaceQuery.cpp` |
| 0x44ab80 to 0x450eb0 | `TinyEffect/TinyEffect.cpp` (initialiser 0x450bf0) |
| 0x450eb0 to 0x452f00 | `TinyEffect/TFXString.cpp` |
| 0x452f00 to 0x45fe50 | `GPURenderGlare.cpp` (initialiser 0x45fbe0) |
| 0x461d60 on | `GPUTextureUtil.cpp` |

### The static objects of every TU

`src/GPU/Unk_StaticsBase.h` and `Unk_Statics.h` (placeholder names) define what
each initialiser constructs: two colour spaces' primaries and SiSDK3's
reflection handle (the base header: IGPUInterface's TU and TFXString.cpp have
only these, a 144-byte initialiser), then 24 CIE standard illuminants and an
angle. They are `static` and dynamically initialised, so LLVM's GlobalMerge
puts a TU's into one object, sorted by size (stable), with the TU's other
internal statics: an initialiser that doesn't match yet (GPURenderGlare.cpp,
ppfx.cpp, GPUInterfaceDevice.cpp, TinyEffect.cpp, GPUPostEffect.cpp, the
colour TU) is missing statics its functions use, and the gaps in the merged
object give their sizes. The illuminants are stored as integers (ppfxTypes.h
says why), and LLVM's constant hoisting then derives D60's x from D70's y
(`add w8, w8, #0xa7d`), which is what breaks the stores' pairing at that point.

### Idioms that decided matches here

- A destructor's vtable slots: `IGPUInterface`'s slot 2 is its complete
  destructor (leafgen had named it `vf2`); an abstract class's deleting
  destructor is a trap.
- `ldrb; eor w, w, #1` passed as an argument, in a branch LLVM didn't turn
  into a select: the parameter is an `int`, not a `bool` (the zext makes the
  block cost 3, over SimplifyCFG's folding threshold of 2).
- Two stores of a path's result with a common tail but no `csel`: each path
  ends in its own `return` (the stores can't be merged into the return block,
  which has the early returns' conditional edges).
- A constructor's store order that no body order reproduces: a
  mem-initializer list.
- `CPostEffect::Unk_426a50` (the viewports): the repeated block is an inline
  helper that takes the four fractions by value (their registers are s0 to s2
  in the original) and converts the texture's size at each use; an alternate
  rectangle is chosen field by field (the two it compared stay values, the
  other two become loads through address phis); a first call whose `this`
  member is read after the fractions' addresses are taken but before they are
  read is an inline wrapper with `const f32&` parameters.

Scratch tools used (not in the repository): an annotated disassembler (names,
strings, GOT targets, folded constants), a one-TU compile-and-compare loop
(`qc.py` of the notes), a straight-line emulator for static initialisers, and
generators for placeholder interfaces (`Unk_SiGfx.h`) and for a class's
members from an offset table (`GPUPostEffect.h`, between the UNK_FIELDS
markers).

More, from CTextureUtil's and CRenderGlare's release and reset functions:

- The release of a `CGPUResourceManage` is inline in every user
  (`PPFX_SAFE_RELEASE`, GPUInterface.h): decrement, and at zero the allocator
  is read, the destructor called through slot 4 and the object freed. An
  `IGPUInterface`'s is the virtual call of slot 1. With `UNK_DELETE` and
  `UNK_DELETE_ARRAY` (Unk_Array.h) a function that only releases members is a
  list of macro calls in the order of the code, and matches at once.
- A run of members set to zero comes back as memsets: MemCpyOpt merges the
  zero stores that follow each other in the code (no other store or load
  between them) when a range has four stores or 16 bytes, puts the memset
  where the run ends, and the backend expands it last address first. So a
  group of stores in descending address order is such a range, whatever the
  order in the source; a store of another value ends the run; and a store of a
  non-zero constant can be emitted before the stores that precede it in the
  source (next to another store of the same constant, or at the block's
  start). CRenderGlare's reset was found that way: write the stores in the
  order of the code, then move the non-zero ones to where the runs must end.
- An inline function too large for LLVM's default threshold that is inlined in
  two callers has the `inline` keyword (the hint raises the threshold from 250
  to 325, times 1.5 for a single block).
- `cmp w9, #1` on a count just incremented, where `count + 1 > 1` would follow
  from the test before it: the increment wraps (GPUClassUtil.h's shared
  CTextureUtil), and the release tests `count <= 1` before it decrements.

From CTextureUtil's rectangles and the DrawRectGPU functions that draw them
(0x7100471960 on; GPUTextureUtil.cpp's block between the DRAWRECTGPU markers):

- **Parameter order shows in two places.** The copies of the arguments at a
  call come in the order of the parameters (integer and floating-point
  registers interleaved as declared; the post-RA scheduler then keeps the
  order among equals), and the allocator hands out callee-saved registers by
  the length of each parameter's live range, which the position of its copy at
  every call changes. These functions take their floating-point parameters
  first, then the pointers, and the flags last: with the flags first the same
  instructions came out with the registers permuted (six floating-point ones
  in the six-set rectangle), and with zero in several floating-point
  parameters the copies of `fmov s0, wzr` came in another order.
- A pointer to a member kept in a register across blocks (`mov x24, x20;
  ldr x0, [x24, #0x30]!` in one block, `add x24, x20, #0x30` on the edge that
  skips it) is GVN's PRE of the member's address. It needs the address to be
  one expression everywhere: a `reinterpret_cast` of the loaded pointer makes
  instcombine retype the load, the address becomes a second expression, and
  the PRE (and with it the block order) is lost. Hence the effect view's
  `SetupGraphicsPipelineState` under IGPUEffect's symbol.
- The condition's spelling places the blocks: `(flags & 0x20000) == 0` and
  `!(flags & 0x20000)` branch the other way round, and with an edge split
  between them that decides which block falls through.
- Element-wise copies of a vertex: the original reads all of a corner's
  elements, then writes them (a temporary vertex copied into the array, which
  SROA turns into loads followed by stores). The DAG combiner then merges
  pairs of 32-bit stores of loads into 64-bit ones where a following store
  loads from the same array, which is why the last set of every vertex (and
  the position) stay 32-bit pairs.
- `ucvtf s0, s8` after `ldp s8, s9, [x20, #0x54]` (the integer loaded into a
  floating-point register): load and conversion were in one block when
  instructions were selected, and MachineSink moved the conversion later. A
  conversion written in the caller is sunk by the first instcombine instead
  (into the block of its use, across the inline call that becomes a loop
  later) and loads into a general register: so the source's coordinates come
  from an inline function (`Unk_GetCoords`), the target's size from plain
  code, and the loop over the texture's parents from another inline function
  (`Unk_GetTexture`).
- A float constant kept in a register over several blocks (`fmov s2, #1.0`
  once, then `fadd s4, s3, s2` in each unrolled iteration) is used by an
  instruction of the block that dominates the others: `next = offset + 1.0f`
  is computed before the test, not in its `else`.
- `adrp x8, sym+0x10; add x8, x8, #lo12` for an element of a static array
  (not base register plus offset): the compiler folds the smallest offset a
  block uses into the address, but only when the offset is inside the object,
  so the hidden `extern` declarations of this TU's scratch arrays need their
  sizes.
- Stores of `0.0f` through the vector types' element objects are integer
  stores (`store i32 0`); written as plain floats they are `store float 0.0`.
  Both become `str wzr`, but only the second makes the block's zero constant
  exist before a later call's arguments are lowered.
- `-(offset * dx)` is `fnmul`; `-offset * dx` with the negation used twice is
  `fneg` and two `fmul`.
- YEBIS keeps its asserts while the build defines `NDEBUG` for everything:
  `GPUTextureUtil.h` undefines it before `<assert.h>` (as TFXString.cpp
  does). Without that the inline `GetHandle_tex2D_aTexture` loses its check,
  and its callers' loops come out with pointer increments and no index.
- A callee's result tested with `tbz w0, #0` whose blocks are laid out as for
  a comparison with zero is a `bool` result (`Unk_442c50_get`): a `u32`
  result masked with 1 gets no branch weights, a `bool` one does.
- The order of the operands of a commutative operation is the order of their
  definitions: Reassociate puts the operand with the lower rank first, also
  for floating-point multiplications it does not reassociate. `fmul s2, s4,
  s1` with `s4` loaded in a later block than `s1` was computed means the load
  is earlier in the source (and MachineSink moved it); two loads multiplied
  come in the order they are read in.
- A technique chosen between two tables with the same indices
  (`flag ? a[i][j] : b[i][j]`) is one address computation and a `csel` of the
  two final addresses when both tables are members indexed directly. Through
  a pointer to a member (`(&a)[i][j]`) LLVM selects the base first and
  indexes after, and keeps the base in a register across calls. Hence
  `TEXSHADERSET`'s tables with the dimensions the functions index them by
  (`[2][8][22]`, `[2][8][8][22]`, the motion blur's groups of 7).
- The scratch vectors are part of the TU's merged statics: an element with a
  variable index is `block + 0x448 + index * 16` in the original. They are
  the file's `static Unk_Float4 Unk_24e4a18[32]` and `Unk_24e4c18[32]`, which
  GlobalMerge places at +0x448 and +0x648.
- `(a + b + 1) < 1` stays a comparison of the sum plus one (no `tbnz` on the
  sum's sign) when the source's association is `a + 1 + b`: reassociating
  drops the no-wrap flags the fold needs. Where a count is computed (before
  the first use of its operands, or just before its own use) also decides
  which callee-saved register it gets.
- A technique getter that gives 0 for one index (`index == 21 ? 0 :
  table[n][index]`, tech_MadT2_Sn and tech_MadScalarWeightT1_Sn have no
  technique 21) shows as one compare ahead of the search loop: the loop is
  unswitched on it and the copy that finds nothing is deleted. Written as an
  `if` around the loop, the index's sign extension is folded into the shift.
- Three functions log as `DrawRectGPU_MadT1_Sn` (0x7100475560, 0x7100475960,
  0x7100476580). Only 0x7100475960 draws tech_MadT1_Sn alone, so it has the
  name; the other two (the colour grading LUT's and tech_MadT2_Sn's) keep
  placeholders.
- A `bool` that is a `switch`'s result in one branch and a range check in the
  other, then selects between two constants, must get the `switch` from an
  inline function (`Unk_47b560_Format`). In one function InstCombine pushes
  the select into the predecessors before the inliner runs, and the range
  check becomes a table load; after inlining, jump threading sees the select
  first and the range check stays a branch to the block the cases share.
- Floats written into the scratch vectors four to an element are indexed
  through the first element (`Unk_24e4a18[0].field_0[i].field_0`): with a
  global at the root of the address the copy loop costs one more unit and
  unrolls by 2, through a `f32*` to the member it unrolls by 4.
- The matrix helpers of the first TU (Unk_415f40.cpp) zero their elements
  with one chained assignment (`m[0][1] = m[0][2] = ... = 0.0f`, stores from
  right to left), and compute every element of a transformed vector before
  they store one (all loads come first). `m * v` is the order of every
  product: the first element's has the matrix element first because it is
  read first, the others the vector's (Reassociate's ranks, above).
- `MATRIXT44_MatrixMultiply` is an inline function of ppfxTypes.h with three
  asserts (lines 19571 to 19573); the header has its own assert macro
  (`PPFX_TYPES_ASSERT`) so that including it does not switch `NDEBUG` for
  anyone. Plain loops over `i` and `j` into a local matrix give the original:
  rows 0 and 2 load the second matrix again and rows 1 and 3 reuse the loads
  (GVN looks back 100 instructions).
- The helpers' matrices end with `m[0][3] = m[1][3] = m[2][3] = 0.0f;
  m[3][0] = m[3][1] = m[3][2] = 0.0f; m[3][3] = 1.0f;` after the 3x3 part in
  row order (`Unk_RotationAxis`, which `Unk_40fde0` has three times).
- Vectors chosen by a `switch` and stored after it (`Unk_474570`: the masks
  of the SSAO upsample) are two locals with initial values, a `switch` without
  `default` inside `if (mode != 0)`: the elements become integer phis, the
  jump table gets its entry for 1 from the range check's default, and the
  rest of the function's registers and spill slots follow. Stores in each
  `case` are merged per case instead.
- A size read from one of two objects (`targetTexture ? a->field_4c :
  b->field_54`) and converted to float after a call stays in a callee-saved
  floating-point register (`ldr s11`, later `ucvtf s2, s11`) when the
  conversion is written where the value is read; MachineSink moves the
  conversion, not the load. A comparison written before a run of loops
  (`bool same = ratio <= 0.005f;`) is moved to its use by CodeGenPrepare and
  leaves the select that feeds it before the loops.

## SiSDK3's SiIO, SiOS and SiGfx classes (0x71004ed630 to 0x7100596d20)

The hand-written classes of this range are under `sisdk/3.0/SDK/Core/Libsrc`,
each in the files its `__FILE__` names (`SiIO/Source/SiIO_VFS_Impl.cpp`, ...);
where a translation unit's name isn't in the executable the file is a
placeholder named after its first function (`SiOS/Source/Unk_596410.cpp`,
`SiGfx/Source/NX/Unk_Pools.cpp`).

### What every class has

- After the vtable pointer comes `Unk_4bf660` (`Include/SiCore/Unk_4bf660.h`):
  the allocator that made the object and its reference count, with an
  out-of-line constructor (0x71004bf660) and an empty out-of-line destructor
  (0x71004bf6a0, which leafgen had named `Unk_4bf6a0_update`). It's a member
  (`field_8`), not a base: a class with a second base has its own at another
  offset.
- The reference counts (`UNK_REFCOUNT_DEFINE`) are compiled only in the
  class's own translation unit, which defines `UNK_<CLASS>_IMPL` before it
  includes the header. Other code can then include the header for the layout.
- An object is made with `UNK_SI_NEW(allocator, 0x10) T(...)` (the allocator's
  slot 7, with `__FILE__` and `__LINE__`: a `#line` before each keeps the
  original's line), bytes with `UNK_ALLOC`/`UNK_FREE` (`Unk_Alloc.h`, slots 8
  and 9). PPFX's code has a `UNK_NEW` of its own, hence the name.
- A function that leafgen had named keeps that name. Where it's really a
  constructor or destructor, the class's own one is inline and the named
  function calls it (`Unk_596410`, SiOSCriticalSection's constructor), and a
  class that has such an object as a member holds a wrapper that calls the
  named function (`Unk_CriticalSection`, `Unk_596640`'s destructor).
- `check.py` reads the base variant of a constructor (C2) out of a C1 name
  only without template arguments, so the row of `SiPool<ResourceItem>`'s
  constructor has the C1 name its callers use.

### Containers

- `SI_NEW_ARRAY` is a statement: it allocates, then constructs each element
  of a class that has a constructor, the test for one decided at compile time
  (`__has_trivial_constructor`). The original's code shows both halves: with a
  constructor the caller's null test is threaded through the macro's (one
  test right after the allocation, then the loop's own first test, which an
  inline function would have merged before it was inlined); without one no
  test is left at all (an empty loop's would have been threaded the same way).
- `SiArray<T>::Unk_4bf190` (the reserve) then matches for class elements too.
  `instances/SiArray_Elements.cpp` has 17 more copies; a copy that no caller
  ties to a type has a placeholder element type named after it, with the size
  it allocates and the constructor its loop shows (a trivially copyable class
  is copied as bytes, so nothing else of it shows). Copies whose callers are
  written are instantiated by their callers' translation units, under their
  RTTI names (`SiIOVFSEntry`, `SiGfxShaderEffectVariation::VariationItem`, the
  package's arrays of definitions and variations).
- The inline members the callers show are placeholders in `SiCore_Array.h`:
  `Unk_SetCount`, `Unk_Reserve`, `Unk_ReserveAtLeast` (which also clamps the
  count), `Unk_Add` (grows by `field_40` elements, or to twice the room).
  Their failure paths store the count, then the two range pointers.
- `SiArray`'s assignment (`operator=`, it returns nothing) matches in all
  four copies once its clear goes through one more inline (`Unk_FreeAll()`
  rather than `Unk_4e3050()`): that function's own optimisation zeroes the
  three pointers as one block before it's inlined, so the later `field_30`
  stores don't reuse an address computed early; `if (x != 0) {main} else if
  (...)` keeps the pointer-element copy's loop end from being duplicated.
- `SiString`: the default constructor takes the kernel's allocator, the
  assignment is out of line (0x71004c8020), `Unk_Clear` frees and empties
  (line 344), `Unk_StringCStr` is the buffer or the empty string
  (0x71024e9360). `Unk_StringFuncs.h` declares the string's out-of-line
  functions as SiIO and SiGfx call them.
- `SiPool<T>`: a constructor (allocator, flag), slot 2 makes room, `Unk_Get`
  is the item of an index; written as quotient, then remainder, then the two
  lookups, which is the order the original computes them in.
- `SiLinkedList<T>` (`SiCore_LinkedList.h`) is the list with allocated nodes.

### Idioms that decided matches here

- A destructor that reads the object's allocator has to read it through an
  inline getter of the class (`Unk_Allocator()`), not as
  `field_8.m_pAllocator`: read directly, the address is the one `field_8`'s
  destructor is called with at the end, so clang keeps it in a register across
  the body's calls; through a getter (already optimised when it's inlined) the
  two addresses are different expressions and the original's code comes out.
- `return false` for a null stream or object and `return true` at the end: the
  original's `cbz x0` to the epilogue (x0 is the null pointer) with
  `mov w0, #1` only on the other path. A function that always returned true
  has the `mov` after both.
- `if (a == nullptr || b == nullptr) return false;` as one condition gives the
  one `mov w22, wzr` before both tests; a test that needs a load of something
  that isn't `this` is a statement of its own.
- A `while` loop whose body ends in two `continue`s has two back edges, which
  LoopSimplify turns into nested loops (the header isn't rotated then); an
  `if`/`else if` chain reaches the header through one block and is rotated.
  Which of the two becomes the inner loop follows the order the loop's
  variables are declared in (SiGfxShaderEffectDefinition::vf11).
- An unsigned count (`u32 count = field_ac; s32 high = count - 1;`) keeps the
  subtraction in 32 bits (`subs w10, w20, #1`); a signed one is widened for
  the index it becomes. A test against 1 rather than of `high == 0` puts the
  equal case first.
- `(s32)array.m_itemCount` in a loop's test, with a 64-bit index, gives the
  reload and `cmp x22, w8, sxtw` of the loops over a package's arrays.
- A loop of constructors is fully unrolled when the unrolled body is under
  the threshold (300 at -O3) and then deleted if a `memset` follows; the
  original's surviving loop of two elements per iteration (interleaved by the
  vectoriser) showed that the array had 64 elements of 0x20 bytes, not 32 of
  0x40 (`Unk_567b80`).
- A helper that's inlined in every caller and also has an out-of-line copy
  isn't `inline`: it's defined in the .cpp (SiGfxResourcePool's
  `Unk_534810`/`Unk_534870`).
- `if (item->field_20 != nullptr && item->field_20->f() == hash) return
  item->field_20;` reloads the member after the call, which needs one
  callee-saved register less than a local for it.
- A struct copy of 0x24 bytes is `ldp`/`ldp`/`ldr w`; member-by-member copies
  of {u32, u32, pair} halves give the 16-byte steps of the package's header
  writer, and field by field ones the 4/4/8 steps of its reader.
- Byte swaps written as swaps of the two halves, `va_end`, the widths of
  virtual functions' returns, `(s32)fwrite(...) == 1`, flag reads before the
  stores that follow: see the comments in `SiIO_NX_FileStream_Impl.cpp` and
  `SiIO_MemoryStream_Impl.cpp`.
- A function that doesn't use an argument loses it in its callers too (dead
  argument elimination, for functions of the translation unit): the package's
  readers and writers are inline members that use `this`, and their callers
  pass what the original passes.
- `SiString::Unk_Clear` clears the buffer's pointer between the capacity and
  the flags, and both lists' `AddTail` test the empty list first: the orders
  of the original's stores and branches (0x7100574a20, 0x710057d9a0).
- An abstract class's deleting destructor is a trap (4 bytes) and its complete
  destructor is the base one's alias; a class with nothing to destroy has
  `b _ZdlPv` (`SiGfxShaderEffectKey`).
- A kernel's pointer to itself is only written in its translation unit: a
  `static` would be removed with its stores, so it's declared
  `extern ... __attribute__((visibility("hidden")))`, as `lib/yebis/leaf`
  does, and read without the GOT. Counters that are read are `static`.
- The kernels' initialisation count is read again right after it's stored,
  with no call in between (`ldr`, `add`, `str`, `ldr`, `cmp`): a `volatile`
  member in the original, which is the only thing that makes clang reload
  it. `SiIOKernel` and `SiMathKernel` declare it so.
- A value-initialised pair of pointers (`field_18()`) gives the 16-byte zero
  before the other members' stores (the chunk handler's links); a zeroed local
  struct assigned after another member's store gives the archive's header.
- A loop that sets a result and breaks shares the return block; a ternary of
  two calls (`c ? f(a) : f(g())`) duplicates the call as the original does.
- Addresses used on both sides of a call become locals (`pair0`, `pair1` in
  `Unk_56d630`), which clang keeps in callee-saved registers; an index read
  into a local before the array's pointer gives the original's load order.
- `SiPool`'s instances are in files of their own (`instances/SiPool_*.cpp`):
  with a member's definition visible in the translation unit that calls it, it
  would be inlined there. The pool's constructor tests its parameter
  (`pAllocator == nullptr`) at the end, not the member it stored.
- The quad tree node's constructor isn't unrolled in its array's reserve and
  clears six words from the last pair to the first: four pointers cleared by a
  loop, then two words, a number and a flag (`instances/SiPool_QuadNode.cpp`).

### How it was done

A class's destructor gives its members (strings, arrays and their RTTI
element types, sub-objects with out-of-line destructors), its constructor
their initial values and the sizes in between; the translation unit is then
written in address order from a symbolic trace of each function (calls with
arguments, stores, branches) and checked function by function with a partial
build. Template instances were found by their first instructions (the reserve
compares `m_reservedCount`, the assignment copies `field_40`).

### Near misses (`m`) and what's left

The `m` functions each have their `NON_MATCHING` reason: register choices of
the allocator (SiIOVFS's entry reader and sort, two file stream functions, the
package's release `Unk_5686f0`, where two registers are exchanged between live
ranges of the same length), the order of independent stores (SiIOVFSManager's
mount and `Unk_583980`), a return block shared instead of duplicated or the
reverse (SiIOCSVDocument::vf15, SiGfxShaderEffectDefinition::vf11, the
package's vf15), a tail call where the original has a call (`Unk_55bc90`),
four bytes of frame (SiIOCSVDocument's constructor and vf17), an argument the
original still passes to a function that doesn't use it
(`SiIOBinaryArchive::Unk_57b9c0`).

Tried and not written:

- `SiPool::Unk_4be7d0` (0x7100532020, 0x7100534580, 0x71005000e0; the base
  instance is 0x71004be7d0): the reconstruction keeps `&m_pData` in a register
  across the loop and clears 24 bytes with one `memset`, where the original
  has a store and a `memset` of 16.
- Each library's table for a locale is written now (see the next section):
  the same comparison is in 0x71004f5100, 0x7100571c00 and 0x7100573480,
  which aren't.
- `Unk_57d4e0` and `Unk_594b10` have leafgen's names of functions without
  arguments but read `this`: they can't be written under those names.

Traced, not written: `SiOSKernel`, which is `SiMathKernel` with four more
reference-counted pointers (`field_30` to `field_48`): the getter
0x7100595960, the constructor 0x71005959e0, the destructors 0x7100595aa0 and
0x7100595bb0, the shutdown they call 0x7100595ae0, the initialisation
0x7100595c00, slots 5, 8, 9 and 11 (0x7100595db0, 0x7100595e20, 0x7100595e90,
0x7100595ef0), SiOS's initialisation and exit (0x7100595810, 0x7100595880) and
their static initialiser (0x71005958c0).

Not written yet, by translation unit: SiGfxNXCommandList and
SiGfxNXDrawContext (45 KB), SiGfxPrimitiveDrawHelper (26 KB, float code),
SiGfxShaderEffectVariationList (17 KB), SiGfxShaderEffect (17 KB),
SiGfxFreeTypeFaceCache (16 KB), SiGfxNXTexture and its pool (22 KB),
SiGfxNXDevice (14 KB), SiGfxImage and the DDS loader (19 KB),
SiGfxNXCanvas (10 KB), the CSV document's parser and writer, the small NX
resource classes, and of SiGfxShaderEffectPackage: slot 13 (0x7100568e60),
`Unk_56ca20`, `Unk_56d320` (needs the map's erase, 0x7100566f10),
`Unk_56ce60`, `Unk_56d040`, slot 21 (0x710056c880), the sort 0x71005692a0,
`ShaderEffectData`'s destructor (0x7100566cc0) and the program map's
(0x710056d950).

## Later round: NX resources (0x710055b740 to 0x7100566070), locale tables, the canvas

Written in this round: `SiGfxNXVolume`, `SiGfxNXVertexFormat`,
`SiGfxNXSurface`, `SiGfxNXFont` (each in `Libsrc/SiGfx/Source/NX/SiGfx_NX_<Class>_Impl.*`,
names from their `__FILE__`s), the small accessors of `SiGfxNXCanvas`, the
NX number tables (`Unk_562ee0.cpp`), the five locale tables
(`Unk_LocaleTable.h`), `SiGfxNXRootSignature`'s destructors.

### Idioms that decided matches here

- **The comparison without case is rotated on its own**
  (`Unk_StringCompare.h`). Its lowered characters are declared before the
  loop: declared in it, the returns in the loop leave a scope and the loop's
  end is merged with them before LoopRotate runs, and the loop is only rotated
  later, in its caller. The locale tables compare with constant strings and
  show the difference: the constant's first character isn't tested, an empty
  string jumps past all three comparisons, and the constant's end is a test of
  the index (`cmp x24, #7`).
- **`SiArray`'s clear has the array delete written out**, not a call of the
  inline `Unk_FreeData`: for an element with a large destructor
  (`SiGfxNXRootSignature`'s parameters, 0x71005581e0) the original has the
  delete's loop inline in the clear and the clear out of line. With the call,
  clang keeps `Unk_FreeData` out of line and inlines the clear.
- **A destructor that empties its arrays itself** (`field.Unk_FreeAll()` in
  the body, then the members' own destructors) has each array's vtable stored
  after its buffer is freed. `SiGfxNXRootSignature` and the object that holds
  a parameter's ranges do that.
- **A block zeroed by assigning a value-initialised struct**
  (`field_78 = Unk_78();`) stays apart from the zero stores next to it. With
  `memset`, MemCpyOpt merges a neighbouring zero store into it and the stores
  come out in another order (`SiGfxNXVolume::Unk_565c10`,
  `SiGfxNXSurface::Unk_55c9a0`).
- **Constructors value-initialise the resource's info and what follows it**
  (`field_60(0), field_64(), field_78()`) and assign the kind in the body:
  the hash's zero and the info's become one 64-bit zero store at 0x60, and the
  kind's store follows it.
- **The name's getters go with the class's translation unit.** leafgen had
  named the second vtable's slot 3 `vf3` in `lib/yebis/class`: it is the
  `_ZThn8_` thunk of the name's getter, and the class's own `vf3` is the
  reference count's. The getter and the hash's getter are defined with the
  class, which emits their thunks.
- **A loop over the elements with two limits** is
  `for (s32 i = 0; i < count && i < 32; i++)`: with an `int` counter the
  member's load is the second condition's only extra instruction, the two
  conditions become one block before the loop is rotated, and both tests end
  up at the loop's end (`cmp x21, #0x1f ; b.hi` then the count).
- **Switches that became tables** (`Unk_562ee0.cpp`): the cases are the
  original's table's entries; the first and last entries are
  never the default (LLVM wouldn't have included them), holes are left to the
  default, and cases that return their own value become a linear map or a
  mask test.
- **A member read into a local before a test of two pointers**
  (`Cache* p = field_268; if (text == nullptr || p == nullptr) return false;`)
  makes the two tests one block: the result is set before the first test
  (`mov w0, wzr ; cbz x1`) and every path shares one return
  (`SiGfxNXFont::vf21`). With the member read in the second test, each early
  return gets an epilogue of its own.
- **Two limits tested without a short circuit** (`(index > 3) | (index >=
  count)`, after `if (index < 0) return nullptr;`) keep the sign's test apart
  from the comparison with 3 (`tbnz ; cmp w1, #3 ; b.gt`): the count is read
  before either limit is tested, so their block can't be merged with the
  sign's. With `||`, InstCombine sinks the count's load behind the first
  limit, whose test then joins the sign's as one unsigned comparison. The
  index is a `const s32&` there: `SiGfxNXCanvas`'s slots that pass a member
  compare index and count in the order of two loads as written.
- **A function that stores through a class is a member of it.** With the
  object as an untyped pointer its member accesses are byte offsets, and two
  stores to different members at the ends of two branches are merged into one
  store with a computed offset (`SiGfxNXSurface::Unk_55cd70`).
- **A string with its buffer in itself** (`Unk_NXFontString<N>`: a
  `SiString<char>` followed by `char[N]`) has the buffer's address computed
  from the string's (`mov x8, sp ; add x8, x8, #0x30`), where a separate
  array's is one `add` from `sp`.
- **A thunk of a function that always returns the same value** calls it and
  loads the value itself (`bl ; mov w0, #1`) when the function is too large
  to be inlined into the thunk (`SiGfxNXFont`'s name setter).
- **Flags kept in a byte** have their masks as bytes (`and w9, w8, #0xf8`
  where an `u32` gives `#0xfffffff8`).

### Near misses and what's left

- The five locale tables (`m`): two registers exchanged in the loop that
  compares the language with "en". The two live ranges are within half an
  instruction of each other when registers are assigned.
- `SiArray<RootParameterEntry>::Unk_4e3050` (`m`): `subs`/`add` exchanged at
  the end of the loop over the parameters.
- `SiGfxNXVertexFormat`: `Unk_564cd0`, slots 17 and 20 (`M`). The elements'
  loops are the original's; the fill of the two tables before them and the
  second loop's loads aren't (notes in the file).
- `Unk_562f40` (`M`): the cases are the original's, the way they share code
  isn't. `Unk_563620` (`m`): the last select.

Traced, not written: `SiGfxNXTexture` (three bases: ISiInterface, the named
object at 8 and an interface with a GUID at 0x10, whose slots are the class's
17 and 18; `Unk_538d70` at 0x18, the device at 0x28, the name in a
64-character buffer of its own at 0x38, its hash at 0xa8, the kind at 0x1d4,
the levels and layers at 0x22c and 0x230, the surfaces' array's data at 0x260
and the volumes' at 0x2b0, the NVN texture at 0x328, the views at 0x370);
`SiGfxNXSurface`'s `Unk_55cd70` (its description from the NVN texture and the
texture it is part of: written since); `SiGfxNXCanvas`'s constructor,
destructor and the functions that make it; `SiGfxNXFont`'s slot 18, which
makes the face.

## Later round: draw context, buffer and texture slots, SiCore_Utility.cpp, format helpers, the utilities, PPFX's resources

Written in this round: `SiGfxNXDrawContext`'s forwarders and draw slots,
`SiGfxNXBuffer`, `SiGfxNXTexture`'s accessors (`NX/SiGfx_NX_<Class>_Impl.*`);
`SiCore_Utility.cpp` (the file's name is its allocator callback's
`__FILE__`) and `Unk_4cad50.cpp` with their static initialisers; the event
handler and enumeration converter templates of `SiCore_Reflection.h`; the
format helpers of `Libsrc/SiGfx/Source/SiGfx_Utility.cpp` (names of the
graphics interfaces and shader languages, bits and block bytes of a pixel
format, mip counters, pixel and index writers, the formatted append);
`SiGfxImageUtility`, `SiGfxDisplayUtility` and the constructors and
destructors of `SiGfxGeometryUtility` and `SiGfxTextureUtility`
(`SiGfx_<Class>_Impl.*`); PPFX's `IGPUResource` (`GPUInterfaceResource.*`)
and `IGPUPixelContainer` (`Unk_4460c0.cpp`).

### Idioms that decided matches here

- **A draw slot keeps the command list in a local** (`Unk_NXDrawCommandList*
  pList = field_28;`) and tests the instance count as `if (instances <= 1)
  { arrays } else { instanced }`.
- **The order of an expression's operands is the order of its loads**:
  `static_cast<s64>(field_8d4) * first + field_8c8`, `field_38 * field_30`.
  An index read into a local first (`s32 index = field_150; data[index]`) is
  loaded before the pointer it indexes. A call's result kept in a local
  before the next call (`void* font = field_18->vf56(index);
  field_3780.Unk_544010(font);`) is two statements in the original too.
- **A member read into a local before a test of several things**
  (`u32 kind = field_1d4; if (level < 0 || kind == 3) return nullptr;`)
  gives the texture accessors' single block.
- **The order two loop variables are declared in is the order of their
  phis**, and that decides more than their registers: `s32 i; u32 result =
  0; for (i = 0; ...)` for the bit reader of `SiCore_Utility.cpp`; and the
  mip counters copy their parameters to locals (`s32 n = 0; s32 w = width;
  s32 h = height;`), because Reassociate orders `w > 0 || h > 0` by the
  phis, whatever order the source has the two tests in.
- **A static object with a zeroing constructor keeps its store in the static
  initialiser only if some function of the TU changes it**
  (`Unk_4cad50.cpp`'s counter: the writer isn't in the executable and is
  listed in `data/absent_functions.csv`).
- **Tables of strings in `.data`** are zero in the image: their pointers are
  relocations (`check.Original("sword").dyn.slots[address - BASE]`). A table
  indexed without a range test is an array in the source (the interface and
  language names); with one it is a switch.
- **A switch compiled to a table keeps explicit cases that return the
  default's value** when they are at an end of the range: the bits per pixel
  table goes to case 104 because 94 to 104 are written out returning 0.
  `gen_lut.py`-style generation has to emit those cases.
- **Two cases that differ in one bit**: `switch (x) { case 44: case 45: }`
  gives `(x & ~1) == 44`; `x == 44 || x == 45` gives `(x | 1) == 45`.
- **The order of a switch's cases decides which case's last block shares the
  function's return** (the index writer's cases are 2, 4, 3, 5).
- **A clamp that stays in front of the branch it shares a test with**:
  `size_t length = static_cast<u32>(n < 0 ? 0 : n); if (!(n < 0)) { ... }`.
  Widened where it is declared, the select has a use in its own block and
  isn't sunk into the `if`; with the same test as the `if`, the compare has
  two uses and the select isn't turned into a maximum (`bic`).
- **Counting an array down**: `for (s32 i = static_cast<s32>(count - 1); i >=
  0; i--)` (the subtraction in `size_t`, then truncated) gives `subs ; b.mi`
  and a 64-bit index whose sign is tested in 32 bits (the image utility's
  searches); `static_cast<s32>(count) - 1` gives `cmp #1 ; b.lt`
  (`SiArray::Unk_RemoveValue`).
- **Appending a C string to a `SiString`** (`Unk_StringAppend` in
  `Unk_StringFuncs.h`) sets the capacity without comparing it first.
- **The utilities** have an `Unk_4bf660` at 8 and arrays of pointers after
  it: `: field_8(pAllocator), field_18(pAllocator)` and a destructor whose
  body is `Unk_ReleaseAll(&field_18);`. Their reference counts are at
  `#line 32` of their headers (`SiGfxDisplayUtility`: 33).
- **An abstract class's complete and deleting destructors are traps** (clang
  emits `brk` for them: `IGPUPixelContainer`'s slot 3). Its base destructor
  is a function of its own (`b ~IGPUResource`) only when the destructor is
  defined in the .cpp; an implicit one is replaced by the base's in the
  vtable.
- **`push_back` of an lvalue compares the end with `!=`, of an rvalue with
  `<`** (libc++ 7): `IGPUResource* self = this; list.push_back(self);`.
- **A chain of `if (x & bit) flags |= other;`** is ordered by Reassociate:
  the order of the source's tests showed only in the registers. Trying the
  120 orders found `IGPUResource::vf4`'s; the member tested last was read
  into a local first.

### Near misses and what's left

- `SiGfxNXDrawContext`: slot 15 (`m`) and slot 20 (`M`); `SiGfxNXTexture`:
  slots 27 and 28 (`M`). Notes in the files.
- `IGPUResource`'s base destructor (`m`): one branch. For an empty list the
  original goes straight to the end, the source's `std::find` and `erase`
  to the test after the search. The deleting destructor, which has it
  inline, matches. An `empty()` test around it, a loop by hand and the range
  `erase` were tried.
- `IGPUPixelContainer`'s slot 7 (`m`): where -6 is put in `w0` (its note).
- `SiGfxImageUtility`'s slot 18 and the three functions it calls
  (0x71004d1a70, 0x71004d2110, 0x71004d2280), `SiGfxPerformanceUtility`
  (traced: its constructor's members are in the notes below),
  `SiGfxShaderUtility`, the rest of the format helpers' TU (0x71004ed720,
  0x71004ed850 to 0x71004ee870) aren't written.
- `SiGfxPerformanceUtility` (0x2a0 bytes): `Unk_4bf660` at 8; 0x20 two
  bools (true, false); floats 60, 14, 5, 10, 0.5 from 0x34, `u32` 1 at 0x48,
  -1 at 0x4c; arrays of `RenderPerfBarSegmentData` (12 bytes) at 0x60 and
  `RenderPerfBarTextData` (0x88 bytes) at 0xb0; an object destroyed by
  0x71004e2120 at 0x108 (its count of pairs of interfaces at 0x11c, 4 at
  first); arrays of `RollingPerfData<float>` and `<int>` (0x68 bytes) at
  0x160, 0x1b0, 0x200 and 0x250.
- PPFX's resource classes (0x71004437f0 to 0x7100449de0), by RTTI:
  `IGPUSurface : IGPUPixelContainer`; `IGPUTexture` and `IGPUVolumeTexture :
  IGPUBaseTexture : IGPUPixelContainer`; `IGPUVertexBuffer` and
  `IGPUIndexBuffer : IGPUBuffer : IGPUResource` (`GPUInterfaceSurface.*`,
  `GPUInterfaceTexture.*`, `GPUInterfaceBuffer.*`). Written: the surface's
  destructors, slots 12 and 13 and the function that wraps a SiGfx render
  target (0x7100445620); all of `IGPUBaseTexture`'s small slots (the rows
  leafgen had named after `IGPUVolumeTexture`, whose vtable comes first),
  the textures' destructors and `IGPUTexture`'s slots 10, 23 and 24;
  `IGPUBuffer`'s destructors and `Unmap`. What decided them:
  - the surface's constructor is inline in the functions that make one; a
    member it assigns in its body rather than its initialiser list
    (`field_80`) is stored after the ones the list has;
  - `IGPUBaseTexture`'s deleting destructor (a trap) isn't in the
    executable, nothing keeps the abstract class's vtable: it is in
    `data/absent_functions.csv`;
  - the textures' destructors call the bytes-per-pixel helper before they
    multiply (`Unk_446ae0(format) * width * height`);
  - slot 21's two paths that store the applied state share the store
    (`if (check) { ...; if (state == applied) return 1; } else { field_78 =
    state; } field_7c = state;`);
  - `Unmap` reads the buffers' array and the index into locals before the
    device.
- Left there: the surface's slots 10, 11, 14 to 16 and the functions that
  make surfaces (0x7100443920 to 0x7100445740); `IGPUBaseTexture`'s slot 9
  (0x7100447320, the lock) and the textures' slots 11 and 22 and their
  makers; `IGPUBuffer::Map`, the buffers' builders and makers (the vertex
  and index buffers' deleting destructors come with those: their vtables
  are only emitted where a buffer is constructed). `IGPUBuffer`'s base
  destructor is `m`: the two reloads after the loop's calls are exchanged.
  `IGPUBuffer`'s constructor, as the makers have it inline: 0x44 and 0x48
  zero, the array at 0x50 null, the map information at 0x60 (3, 0, -1, 0,
  false, four zero words), 0x58 zero, the two bools at 0x5d zero, 0xa0
  null, 0xa8 the address of 0x50; then the base's `field_20 = false`, the
  kind (8, 6 for a vertex buffer), the usage, and the flags without 0x300
  when the usage has 0x800.
- Small functions leafgen doesn't write, added by hand in its style
  (`lib/yebis/leaf/Unk_455350.cpp`, and two generated class files): setters
  that select between a float and a default (`if (value <= 0.0f) value =
  64.0f;` gives `fcsel ..., hi`; `value > 0.0f ? value : 64.0f` gives
  `gt`), copies of two- and four-float structures, comparators for sorts.
- `CPostEffect`'s setters whose floats the generated API wrappers of
  `lib/yebis/leaf/Unk_4182e0.cpp` had dropped (0x7100423780, 0x7100423b50,
  0x7100423cd0, 0x71004253e0): the wrappers pass the floats now, and both
  rows are renamed. Two floats stored as one 64-bit word (`fmov ; bfi ;
  stur x8`) are a two-float structure built first and then assigned
  (`Unk_Float2 value(a, b); s32 view = field_860; field_858[view].field_44 =
  value;`): the value before the index, the index before the array.
- `SiYebisAllocator` (`GPUMemoryAllocator.*`): its block has the address
  handed out and the element count in front, and the distance back to the
  block in the eight bytes before the address. Its free computes the block
  before it reads PPFX's allocator.
- `ISiGfxKernel::EventHandler` and the draw helpers' handlers: the base's
  destructor is inline (its deleting one a trap); a handler's destructor
  defined in its .cpp is a function of its own with the base's inline (it
  stores the base's vtable), where an inline one is replaced by the base's.
  The base's reference counts are defined only for the TU that asks
  (`UNK_SIGFX_KERNEL_EVENTHANDLER_DEFINE`), now that other headers include
  it.


## Later round: the shader effect's variation list and effect, the NX pools' own resources, the FreeType face, SiMath's projection

The variation list (`SiGfx_ShaderEffectVariationList_Impl.{h,cpp}`) has its
three element types under `ISiGfxShaderEffectVariationList` (RTTI names
them): a variation (0x140 bytes: two `SiGfxShaderEffectKey`s whose bytes are
in four bytes of their own or in an array, its strings and their hash), an
effect's data and a name that wasn't found. The effect
(`SiGfx_ShaderEffect_Impl.{h,cpp}`) is 0x178 bytes: its name, a lock, its
techniques and program map, and the callback it gives SiGfx's kernel to be
told when a program is compiled. `ShaderProgramMap`'s destructor is defined
in that header under the package's guard: its `__FILE__` is the header and
the original has it in the package's translation unit. The NX vertex format
and font pools make their own resources in slot 7 (`SiGfx_NX_VertexFormatPool.cpp`,
`SiGfx_NX_FontPool.cpp`). `Unk_DirectMap.h` is SiSDK3's `SiDirectMap`, an
intrusive map (the FreeType face's glyphs are their own nodes).

### Idioms that decided matches here

- Loads of a parameter's fields hoisted out of a loop mean a reference
  parameter (dereferenceable); through a pointer they stay in the loop
  (the variation list's slots 5 and 6, the keys).
- `cmp; ccmp ..., #2, hs; b.hi`, or two branches to one block, is a
  three-way compare written `if (a < b) return -1; if (a > b) return 1;`.
  Written as `!=` and then `?:` it folds into one `b.ne` (the keys' compare,
  the variations' sort).
- Store merging only joins stores of the same size: a 4-byte store left
  alone next to a merged 8-byte pair means the pair is one 8-byte struct
  assigned as a whole from a temporary (`field_94 = Unk_94();`, a memcpy that
  becomes one 64-bit store). The same for bytes: a byte, a merged two-byte
  pair, a byte (`Unk_538d70`'s constructor: a two-byte struct
  value-initialised; it needs no `volatile`).
- A list element whose links are stored before its other members has them
  as a value-initialised base (`: Unk_Links<T>()`, `RequestNotFoundEntry`).
- A value read into a local before a loop (an allocator) lets LLVM unswitch
  the loop on it; read through the member it's reloaded every iteration
  (the effect's `Unk_576780`).
- An object whose constructor reads something of its owner after its
  vtable is stored takes the owner, not the value (`CompileRequestCallback`).
- Many copies of one block with the same `__LINE__` for their allocation are
  an inline helper inlined at each call (the NX vertex format pool's sixteen
  formats, 0x7100563a40: local constant arrays per block, which clang copies
  from rodata or stores by itself; index 15 reuses index 3's name).
- A max whose argument is computed again when it's the greater
  (`cmp #2; b.lt`, then the same calls again) is a macro
  `((a) > (b) ? (a) : (b))` (`SiGfxNXVolume::Unk_565c80`).
- A byte that is stored as it was loaded (`strb w8`, then `cbz w8`) is a
  `u8`; a `bool` gives `cmp; cset`.
- Reads of all inputs before the result's constructor give the loads-first
  order of SiMath's projection matrix (0x7100594590); the stores of its
  constants follow the statements' order within what the scheduler allows.
- An `if`/`else if` chain instead of `continue`s gives one rotated search
  loop.
- A member function of a class template that the original calls by its
  complete-object name (D1) resolves in `check.py` through the alias of the
  translation unit that instantiates it; `qc`-style one-file checks need a
  D1 row of their own for it.
- An explicit instantiation declaration (`extern template
  SiPool<SiGfxFreeTypeGlyph, 16>::~SiPool();`) keeps a header's template
  member from being emitted (and compared) in a translation unit that only
  calls it.

### Near misses and what's left

Near misses, each with its `NON_MATCHING` reason: the variation list's slot
10 (its run-length loops' 64-bit index), slot 14 (the end of a case-sensitive
compare kept as a value), slot 22 (a `found` flag), its stream reader
(registers); the variation's slot 12 (the zeros' loop's addresses); the
effect's slot 17 and `Unk_576780` (an address sunk into a call's block,
registers); `ShaderProgramMap`'s destructor and the package's slot 21 and 13
(a spilled register, shared return blocks, loop guards); SiIO's
decompression, the file stream's slot 39 and the CSV document's line reader
(registers, a duplicated epilogue, a peeled first read); the texture
utility's descriptor (the order of its stores); the FreeType face's
constructor (one register); the image flip `Unk_4ee110` (a 32-bit counter
LLVM folds here).

Not written: the effect's slot 12 (0x7100576c30) and its helpers, its
program requests (0x71005785d0, 0x7100578c30), `Unk_578b10` (needs SiString's
copy constructor 0x71004c45c0), the map erase of the effect's programs
(0x7100566f10, SiCore's 0x71004c0e60 is the same template), the face's map
insert (0x7100500a30, an intrusive red-black insert), the canvas's
constructor and setup (0x71004fb6d0, 0x71004fbb20, 0x71004fc8a0), the font
pool's own fonts (0x71004fe990), the device's constructor.

## Later round: the font pool's own font, the canvas's setup and teardown, the FreeType face's loading, SiGfx images, the texture chunk's data

The NX font pool (`SiGfx_NX_FontPool.cpp`) now makes its own font (the
kernel's font directory plus a file name, a description of the face with
`Unk_FontDesc`, then the four strings of characters it renders first) and
holds the resource pools' item-of-index lookup `SiPool::Unk_4fef10`, whose
only instance the original has in this translation unit. The font's slot 18
(`SiGfx_NX_Font_Impl.cpp`) opens the face and makes its glyph cache. The face
(`SiGfx_FreeType_Face.{h,cpp}`) reads FreeType's `FT_FaceRec_` through a
placeholder view (`Unk_FTFace`, its members' FreeType names in comments) and
is opened through `SiGfxFreeTypeManager`. The canvas (`SiGfx_NX_Canvas_Impl.{h,cpp}`)
has its real layout (its description at 0xc0, its render targets' summary at
0x70, the heap blocks of its window's textures at 0x248) with its
constructor, the setup on a window made for it, its buffers and its teardown.
`SiGfx_Image.cpp` has the image of noise 0x71004f4390 and the 1D and 2D
image setups. The texture chunk's data (`Unk_4efb80`) embeds the NX
texture's description. SiMath's view volume has its constructor and
destructor in `Unk_594590.cpp`; `Include/SiMath/Unk_Matrix.h` is the 4x4
matrix SiGfx's callers use (four `float32x4_t` rows with a copy constructor
of its own: it's returned in memory).

### Idioms that decided matches here

- A string read through a pointer (`x20`) before a copy constructor call
  that it follows in the source is an argument of an inline function that
  takes it by value: the font pool's path is `Unk_StringConcat(dir, name)`,
  whose append grows like the character append (`Unk_StringAppendGrow`).
- A value read before a struct is constructed (`ldr w8` sunk into the join
  after the allocator's selection) is read into a local before the
  constructor runs (the font description's size).
- A call through the table of a named object's base (`ldr x8, [x0, #8]!`)
  is a call through that base, `static_cast<Base*>(p)->vf()`; through the
  class itself it uses the primary table's overriding entry.
- A buffer address built as `mov x8, sp; add x8, x8, #0x30` is the buffer
  of an `Unk_NXString<N>`, a string that holds its own characters.
- `x < 2 ? 1 : x >> 1` gives `cmp #2; csinc ge`; `x > 1 ? x >> 1 : 1` gives
  `cmp #1; csinc gt` (the image's 2D setup). A count's guard folded to `cmn
  w9, #1` needs the count computed in `s32` (a `u32` field converted first).
- In a loop over pixels, the order of the locals' declarations (the pointer
  first, then the lowest and highest values) decides the order of their
  zeroings; the outer coordinate's division is hoisted only when it's a
  local of the outer loop; a loop test written `size > i` keeps the
  original's operand order.
- A string cleared in a destructor with `Unk_EmptyAll` keeps its stores
  apart; `Unk_Clear` merges two of them (the texture chunk's data).
- The free of an array element whose address the original computes again
  after the call is written out (`if (a) SI_FREE(a, p[i]); p[i] = nullptr;`),
  not through `Unk_Free`'s reference (the canvas's slot 19).
- Zeroed arrays stored in descending `stp`s after the members' constructors
  are loops (or a memset) in the constructor's body (the canvas).
- The blocks of a BC4 image are read as unaligned 32-bit words masked to 24
  bits (`ldur w8, [x1, #2]`, `[x1, #5]`, even past the block); the original
  computes each middle byte from the masked word, which this source doesn't
  reproduce (0x71004ee660).

### Near misses and what's left

Near misses: the orthographic projection 0x71004ee020 (the product's
scheduling), the key's text 0x71004eddf0 (a 64-bit load of the size for
hashes that take an int), the block flip 0x71004ee660 (the BC4 rows'
middle bytes), the face's size measures 0x71005006c0 (scheduling), the
resource pool's lookup 0x71004fef10 (a null test the original doesn't
have), the image's 1D and 2D setups (register order), the texture chunk's
data constructor (the order of the description's zeroed blocks, shared with
the NX texture's constructor), the canvas's colour buffers 0x71004fc4d0 (one
more saved register).

Later in the round: the package's shader of a stage 0x710056ce60 and the
effect's program from its shaders 0x71005785d0 matched once the member tested
with the first pointer was read into a local (the README's earlier idiom of
`SiGfxNXFont::vf21`); the effect's builder passes its unused second argument
on to the inline that fetches each stage's shader, which is why its callers
still pass zero. `ShaderProgramCompileEntry` has its constructor (two keys
copied into its own bytes) and its release; `SiArray<SIGFX_SHADER_PREPROCESSOR>`'s
reserve calls an out-of-line array new (0x710056e4e0) where `SiCore_Array.h`
expands `SI_NEW_ARRAY`: it's an explicit specialisation at the end of the
package's file (its `#line` names the header). SiIO's byte order mark test
0x7100583340 matched with the UTF-8 mark's test written first: the two tests
become a switch that compares in the reverse order.

Not written: the canvas's own window 0x71004fbb20 and its slot 26
0x71004fd080 (NVN builder sequences), the block-compressed image flip
0x71004ee290 (its switch is unswitched for formats 0x46 and 0x47 and its
stride table is guarded by the mask of `Unk_4ed0f0`'s cases).


## Later round: the hard tail (near misses revisited)

Every `m` function was revisited with variant searches (statement, case and
declaration permutations compiled in parallel). What decided the matches, and
what the optimized IR showed about the ones that stay:

### Idioms that decided matches here

- One more inline level gives the inlined body one more run of the function
  passes: `IGPUResource`'s and `IGPUBuffer`'s base destructors matched once
  the list search and erase, or the per-element release, moved into a static
  inline helper (the deleting destructors, which inline the base one, already
  matched).
- Inline cost decides call against inline: `-Rpass=inline -Rpass-missed=inline`
  on qc's compile line (for analysis only) prints the costs. An `operator=`
  written `{ Copy(other); return *this; }` costs 260 against a threshold of
  250 and stays a call, as in the original.
- A test LLVM adds by unswitching (CutLeft's `count >= 1`) mustn't be written
  out: written, it lands before the length test.
- `*(p + n - 1)` and `p[n - 1]` schedule differently: with the pointer form the
  first character is loaded before the last one's address is computed.
- A `u32` passed to a `size_t` parameter is zero-extended with `mov w1, wN`,
  and that copy comes first among a call's argument copies.
- A wrap test `offset + sizeof(x) >= limit` is 64-bit; the original's `add w;
  cmp w` is `offset + static_cast<u32>(sizeof(x))`.
- `(flags & 0x20000) == 0` and `!(flags & 0x20000)` place the blocks
  differently; `a ? x : (b ? y : 0)` written as an `if`/`else` into a local
  keeps the outer `csel ne`, folded into one expression it becomes `csel eq`.
- An element reached as `SiArray<T>& row = array[i];` stays one address across
  later tests and calls; `&array.m_pData[i]` lets InstCombine fold the address
  into each member's offset, and the base is computed again before a call.
- The order of a switch's cases decides which tails the branch folder merges:
  most orders give the same code, a few give the original's (permute them).
  Where each case stores with the field offset folded in and the result is
  held outside `w0`, the element's offset is computed inside each case.
- `field_10 = field_10 | bit` and `field_10 |= bit` order the load and the
  shift differently.
- `if (a < b && next < current) current = next;` gives an `fccmp` chain; a
  minimum of a select doesn't.
- One inline body in the original means one call of the helper in the source:
  rewrite early returns as nested conditions so each `return helper()` occurs
  once.
- `if (count > 0) { ... }` and an early `if (count < 1) return 0;` lay the
  unswitched loops out differently.
- The order of the loads decides Reassociate's order of a short-circuit
  chain's compares; an absolute value computed before an early-exit test on
  the same value reuses that test's `fcmp`.
- Store order can be the source's column order (a 3x3 part filled column by
  column after the zero chains).

### What the IR shows about what's left

- Reassociate ranks arguments by position (3 and up) and readnone intrinsics
  such as `llvm.maxnum` as ordinary instructions, and LLVM 7's Reassociate
  also reorders `i1` `and`s by rank: an argument's test always ends up before
  a load's. That is the `fmul σ, 2σ` against `2σ, σ` of the Gaussian family
  (0x7100413170 and its eleven siblings) and the `ccmp`s that come out as two
  blocks (0x710049e290, 0x710049d250, 0x71004a65a0).
- At the first InstCombine an argument ranks below a load, so `arg == load`
  is swapped: SiMap's insert (0x71004c09a0 and its copies) compares with the
  operands swapped because its node is the balancing function's argument
  until tail-call elimination makes it a loop variable.
- Early returns inside a scope with a local become selects on the cleanup slot
  in the first SimplifyCFG, then one `and`/`or` ordered by rank (SiIO's vf5,
  RootSignature's vf12).
- Reassociate breaks up `x - c` only when `x` is a single-use add: a surviving
  `(a + b) - c` next to `a - c` (the quad tree split 0x7100532ca0) means the
  original's sum had other uses.
- SiMap's erase (0x71004c0e60 and its copies): the original reloads the
  children after the stores to the returned iterator, as if they could alias;
  here they can't.
- The locale tables (0x71004ca820 and four copies) and most of the large PPFX
  functions differ only in the register allocator's tie-breaks.
