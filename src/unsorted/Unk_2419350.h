#pragma once
// A class on gflib3's other reference-counted object (vtable 0x7102419350),
// with two references. Placeholder names: rename once the class is known.
//
// Its D2 (0x7101122e70) and the D0s of the classes on it store this vtable:
// it's the base, though the owner heuristic gives its functions to
// Unk_24192b0 (vtable 0x71024192b0, which inherits all of them). Its
// destructor is implicit, so inline: the classes on it with nothing to
// destroy have its D2 in their slot 0 (clang replaces an inline derived D2
// with the base's), and their D0s and thunks are copies of it.
//
// In the original, one TU emits both vtables' functions: Unk_24192b0's D0,
// these functions, its thunks, then this class's D2, D0 and thunks.
// (Unk_24192b0's vtable is stored only by 0x710111db70, in an earlier TU.)
// Here vf5 is the key function, defined out of line with the others in
// Unk_1122d20.cpp, so this class's functions are emitted there. Unk_24192b0
// defines nothing of its own to be its key function, so its D0 and thunks
// wait for whatever emits them in the original.
#include <types.h>

#include "gflib3/Unk_239a4c0.h"

class Unk_2419350 : public Unk_239a4c0 {
public:
    virtual void vf5();
    virtual u32 vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual u32 vf10();
    virtual void vf11();

    Unk_239a418_Ref<Unk_239a418> field_58;
    Unk_239a418_Ref<Unk_239a418> field_60;
};
static_assert(sizeof(Unk_2419350) == 0x68, "Unk_2419350");
static_assert(__builtin_offsetof(Unk_2419350, field_58) == 0x58, "Unk_2419350::field_58");
static_assert(__builtin_offsetof(Unk_2419350, field_60) == 0x60, "Unk_2419350::field_60");
