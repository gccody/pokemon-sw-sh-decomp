#pragma once
// gflib3's other reference-counted object (vtable 0x710239a4c0): it keeps its
// count itself, at +0x50, where Unk_239a418 keeps it in a handle. 256 other
// vtables have its vf3 and vf4 (slots 3 and 4): 212 its vf2 as well, among
// them Unk_2398c40 (vtable 0x7102398c40), and 44 override vf2. Placeholder
// names: rename once the classes are known.
//
// Its primary base and the interface at +0x48 declare the same functions (add
// a reference, drop one), so one override fills both vtables: the +0x48
// vtable gets this-adjusting thunks with the body inlined. vf2 destroys the
// object and gives its memory back to its allocator, as Unk_239a418::vf3
// does; the family's operator delete is empty.
//
// Its destructor is inline and empty, and none of its fields has a
// destructor, so its D2 stores no vptrs: it is a `ret`. Every copy of it is
// one function, the linker's (0x710000d500, emitted with an earlier TU's
// static object of a class on it), and a derived class with nothing to
// destroy uses it as its own D2 (docs/game_code.md, "Bases"): Unk_2399470
// (vtable 0x7102399470) does. Its D0 and the thunks of both are `ret`s too.
//
// vf2 is its key function, defined in Unk_239a418's TU (src/gflib3/
// Unk_5e2700.cpp): its D0 and thunks follow the object's functions there. vf3
// and vf4 are inline: their one copy (0x71005cfe90-0x71005cff4c) is the one
// emitted with Unk_2399470's vtable, in an earlier TU.
#include <atomic>

#include <types.h>

#include "gflib3/Unk_239a418.h"

// The primary base, 0x48 bytes: the allocator and the allocation from 0x8,
// as in Unk_239a418_Base.
class Unk_239a4c0_Base {
public:
    virtual ~Unk_239a4c0_Base() {}
    virtual void vf2();  // destroy and free
    virtual void vf3();  // add a reference
    virtual void vf4();  // drop a reference

    static void operator delete(void*) {}

    Unk_239a418_Allocator* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    // Scalars, not bytes, as in Unk_239a418_Base: a derived class's
    // destructor thunk addresses its members from the adjusted `this` only
    // when that lands on a field.
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
};
static_assert(sizeof(Unk_239a4c0_Base) == 0x48, "Unk_239a4c0_Base");

// The interface at +0x48 (vtable 0x710239a4f8).
class Unk_239a4f8 {
public:
    virtual ~Unk_239a4f8() {}
    virtual void vf3();
    virtual void vf4();
};

class Unk_239a4c0 : public Unk_239a4c0_Base, public Unk_239a4f8 {
public:
    ~Unk_239a4c0() override {}
    void vf2() override;
    void vf3() override { ++field_50; }
    void vf4() override {
        if (--field_50 == 0)
            vf2();
    }

    std::atomic<s32> field_50;
};
static_assert(sizeof(Unk_239a4c0) == 0x58, "Unk_239a4c0");
static_assert(__builtin_offsetof(Unk_239a4c0, field_50) == 0x50, "Unk_239a4c0::field_50");
