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
of YEBIS's src/GPU translation unit, which LLVM merged into one object
(0x71024e45d0, used by functions from 0x7100462fe0 to 0x7100499b70: the TU is
every src/GPU file) and whose flags it shrank to one bit. They can't be
defined before the whole TU is here, so the file declares the block as it is
in the executable (`Unk_24e45d0_Statics`) and tests bit 0 of each flag.

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
  (`Unk_49fc60`, `Unk_49ca70`, ...) keep that free-function name; the body
  casts its first parameter to the class.

**Names**: `CGPUResourceManage::RegisterStaticGPUDevice` and
`CRenderTexturePool::AllocateTextures` are named by their log lines, the
classes by RTTI (CGPUBaseResourceManage is CGPUResourceManage's base; its
vtable isn't in the executable). Virtual functions are `vf<slot>`, as
lib/yebis/class names them.

## SiCore (0x71004bc640 to 0x71004c8ef0)

SiSDK3's core library starts YEBIS's second half. Its TUs, in address order
(a TU ends with its static initialiser; the ones that only construct the TU's
`SiReflectionPropertyHandle` are lib/yebis/static's):

| Range | File | What |
|---|---|---|
| 0x4bc640-0x4bc6c0 | `Unk_4bc640.cpp` | the kernel's allocator or the static one |
| 0x4bc7f0-0x4bf5e0 | `SiCore_FixedHeapAllocator2.cpp` | the allocator over fixed regions, its header pool |
| 0x4bf730-0x4c2cd0 | `SiCore_Kernel_Impl.cpp` | `SiKernel` (not written: lib/yebis/class has its accessors) |
| 0x4c2cd0 | `Unk_4c2cd0.cpp` | the static `SiHeapAllocator` (the initialiser is the TU) |
| 0x4c2d70-0x4c32e0 | `SiCore_HeapAllocator.cpp` | the allocator over the memory system |
| 0x4c3360-0x4c35c0 | `Unk_4c3360.cpp` | CRC-32 |
| 0x4c3640-0x4c4100 | `Unk_4c3650.cpp` | `SiMemorySystem`: malloc with a header, 65536 lists by address |
| 0x4c4290-0x4c6010 | `Unk_4c4290.cpp` | string functions, `SiString`'s out-of-line members |
| 0x4c6090-0x4c8620 | `SiCore_StringTable_Impl.cpp` | `SiStringTable` (not written) |
| 0x4c86a0-0x4c8840 | `Unk_4c86a0.cpp` | `SiCoreCriticalSection`, the scoped lock |
| 0x4c88c0-0x4c8ef0 | `SiCore_SystemInfo_Impl.cpp` | `SiSystemInfo` |

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

Not matching yet in these files (status `m`, each with its reason in the
source): `SiFixedHeapAllocator2`'s constructor and `Unk_4bd610`,
`SiPool::Unk_4bcfa0`, `Unk_4c5a40`. Not written: the fixed allocator's `vf8`
and `vf9` (allocate and free, 1.4 KB each, intrusive list work throughout),
`SiPool::Unk_4be7d0`, the string TU's conversions (`Unk_4c42b0`, `Unk_4c4700`,
`Unk_4c49f0`, `Unk_4c4f60`, `Unk_4c5280` and smaller ones), `SiKernel`,
`SiStringTable`, `SiSystemInfo::Unk_4c8b50`.

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
- `SiArray`'s assignment (`operator=`, it returns nothing) is written but one
  address away in all four copies (`m`): the original computes `&field_30`
  where its loop starts and stores through `this` before it.
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
the allocator (SiIOVFS's entry reader and sort, two file stream functions),
the order of independent stores (SiIOVFSManager's mount, the variation's
release), a return block shared instead of duplicated or the reverse
(SiIOCSVDocument::vf15, SiGfxShaderEffectDefinition::vf11, the package's
vf15), a tail call where the original has a call (`Unk_55bc90`), four bytes of
frame (SiIOCSVDocument's constructor and vf17).

Not written yet, by translation unit: SiGfxNXCommandList and
SiGfxNXDrawContext (45 KB), SiGfxPrimitiveDrawHelper (26 KB, float code),
the rest of SiGfxShaderEffectPackage (its effects' data, 15 KB),
SiGfxShaderEffectVariationList (17 KB), SiGfxShaderEffect (17 KB),
SiGfxFreeTypeFaceCache (16 KB), SiGfxNXTexture and its pool (22 KB),
SiGfxNXDevice (14 KB), SiGfxImage and the DDS loader (19 KB),
SiGfxNXCanvas (10 KB), SiIOBinaryArchive (9 KB), the CSV document's parser
and writer, and the small NX resource classes. `SiPool`'s slots 2, 3 and 5
(three instances each) and the quad tree nodes' reserve need their element
types' assignments.
