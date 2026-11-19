#pragma once
// The base of small classes that hold Unk_236d3d8 holders (vtables with 4
// slots and a 2-slot one at +0x48, e.g. 0x71023a7ca0): a primary base with a
// virtual destructor and two functions, and an interface at +0x48 that
// declares the same two (one override fills both). Neither destructor has
// anything to do. Placeholder names: rename once the classes are known.
#include "unsorted/Unk_236d3d8.h"

class Unk_23a7ca0_Primary {
public:
    virtual ~Unk_23a7ca0_Primary() {}
    virtual void vf2();
    virtual void vf3();

    // The family's operator delete is empty: a D0 is a copy of its D2.
    static void operator delete(void*) {}

    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
};
static_assert(sizeof(Unk_23a7ca0_Primary) == 0x48, "Unk_23a7ca0_Primary");

class Unk_23a7ca0_Interface {
public:
    virtual void vf2();
    virtual void vf3();
};
