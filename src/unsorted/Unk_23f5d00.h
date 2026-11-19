#pragma once
// A class on gflib3's other reference-counted object (src/gflib3/
// Unk_239a4c0.h), vtable 0x71023f5d00, 6 slots, 0x180 bytes, constructed by
// 0x7100ead190: a holder of a reference (Unk_236d618) and a reference. (The
// constructor isn't decompiled: it inlines Unk_239a4c0's, which stores a root
// class's vptr, 0x710236d378, and takes the allocator from a TLS stack.) Its
// destructor is its key function, out of line and too big to be inlined:
// its D0 and its thunks tail-call its D2. Slot 5 is its own (a static's
// address; the derived classes override it). Placeholder names: rename once
// the classes are known.
//
// 22 classes tail-call its D2 from their own. Unk_23d0770 releases a
// reference first. Unk_23d07e0 and Unk_23f4dd0 have their destructors out
// of line with nothing to do: clang can't alias this D2 from another TU, and
// with an empty body and no member to destroy it skips the vptr stores
// (CanSkipVTablePointerInitialization), so their D2s, D0s and thunks only
// tail-call this one. The other 19 store their two vptrs first, and their
// D0s and thunks are copies of their D2s: they hold a member of a class
// template with an empty destructor (Unk_23f5d00_Member, below).
#include <types.h>

#include "gflib3/Unk_239a4c0.h"
#include "gflib3/Unk_5e2bc0.h"
#include "unsorted/Unk_23d4470.h"

// A class with two callables (vtable 0x710236d3d8: vf0 and vf1 invoke them,
// 0x7100008190 and 0x71000081b0) and a reference to an object, which it
// hands to Unk_5e2bc0 and drops when it goes: Unk_23dba98's shape
// (src/unsorted/Unk_23f2df0.h). 231 functions store its vtable. Reset() is
// its destructor's body; its owner here calls it first too.
class Unk_236d3d8 {
public:
    virtual void vf0();
    virtual void vf1();

    ~Unk_236d3d8() { Reset(); }

    void Reset() {
        if (field_8.m_ptr)
            Unk_5e2bc0(field_8.m_ptr, this);
        field_8.Reset();
    }

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_236d3d8) == 0x110, "Unk_236d3d8");
static_assert(__builtin_offsetof(Unk_236d3d8, field_10) == 0x10, "Unk_236d3d8::field_10");
static_assert(__builtin_offsetof(Unk_236d3d8, field_90) == 0x90, "Unk_236d3d8::field_90");

// The class Unk_23f5d00's member is constructed as (vtable 0x710236d618, with
// Unk_236d3d8's slots): its destructor is Unk_236d3d8's.
class Unk_236d618 : public Unk_236d3d8 {};

// What the 19 classes on Unk_23f5d00 whose D2s store their vptrs and then
// only tail-call its D2 hold. clang skips the vptr stores of a destructor
// with an empty body when every member's destructor has an empty body too
// (CanSkipVTablePointerInitialization in CGClass.cpp), and a destructor whose
// body it hasn't seen isn't empty (FunctionDecl::hasTrivialBody). A class
// template's members are instantiated at the end of the TU, while an
// out-of-line destructor is emitted where it's defined: so a member of a
// class template with a user-provided empty destructor makes the D2 store the
// vptrs, and is then inlined into nothing. A member of a plain class with
// such a destructor doesn't (checked with clang 7.0.1 and the game's flags).
// What the template and its member are isn't known.
template <typename T>
class Unk_23f5d00_Member {
public:
    ~Unk_23f5d00_Member() {}
};

class Unk_23f5d00 : public Unk_239a4c0 {
public:
    ~Unk_23f5d00() override;
    virtual u8* vf5();

    u64 field_58;
    Unk_236d618 field_60;
    Unk_239a418_Ref<Unk_239a418> field_170;
    u64 field_178;
};
static_assert(sizeof(Unk_23f5d00) == 0x180, "Unk_23f5d00");
static_assert(__builtin_offsetof(Unk_23f5d00, field_58) == 0x58, "Unk_23f5d00::field_58");
static_assert(__builtin_offsetof(Unk_23f5d00, field_60) == 0x60, "Unk_23f5d00::field_60");
static_assert(__builtin_offsetof(Unk_23f5d00, field_170) == 0x170, "Unk_23f5d00::field_170");
static_assert(__builtin_offsetof(Unk_23f5d00, field_178) == 0x178, "Unk_23f5d00::field_178");
