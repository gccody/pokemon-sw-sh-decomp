// Scope: common
// The 0x31d holders of loaded data that Unk_7814e0 loads (src/unsorted/
// unk_761f70/Unk_7814e0.h, which reads them as Unk_277a1a0_Entry): this TU
// defines the array, so its static initialiser (0x7100781470) constructs them
// (vtable 0x710236d618) and its array destructor (0x7100781300) destroys them
// (Unk_236d3d8's destructor, storing its vtable).
#include "unsorted/Unk_236d3d8.h"

// What the holders are constructed as (vtable 0x710236d618, with
// Unk_236d3d8's slots): their destructor is Unk_236d3d8's. (As in
// src/unsorted/Unk_23f5d00.h.)
class Unk_236d618 : public Unk_236d3d8 {};

// 0x7100781300: __cxx_global_array_dtor
// NON_MATCHING: addressing. The original clears field_8 in the destructor's
// body through [element, #0x34dc8 in a register] while it loads it through a
// pointer to it; this uses the pointer for both (the same with
// src/unsorted/Unk_23f5d00.h's Reset()).
// 0x7100781470: _GLOBAL__sub_I_Unk_781300.cpp
Unk_236d618 Unk_277a1a0[0x31d];
