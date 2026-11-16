#pragma once
// Placeholder types: rename once the owning classes are identified.
#include <types.h>

// The objects these pointers refer to have a second polymorphic base at +0x48
// (the calls go through its vtable). Taking a reference calls its slot 2
// (+0x10), dropping one calls slot 3 (+0x18).
struct Unk_5e6560_Base {
    virtual void vf_00();
    u8 _8[0x40];
};
PKMN_SIZE_ASSERT(Unk_5e6560_Base, 0x48);

struct Unk_5e6560_Iface {
    virtual void vf_00();
    virtual void vf_08();
    virtual void vf_10();
    virtual void vf_18();
};
PKMN_SIZE_ASSERT(Unk_5e6560_Iface, 0x8);

struct Unk_5e6560_Obj : Unk_5e6560_Base, Unk_5e6560_Iface {};
PKMN_SIZE_ASSERT(Unk_5e6560_Obj, 0x50);

struct Unk_5e6560 {
    Unk_5e6560_Obj* ptr;

    Unk_5e6560(const Unk_5e6560& other) : ptr(other.ptr) {
        if (ptr)
            ptr->vf_10();
    }
};
PKMN_SIZE_ASSERT(Unk_5e6560, 0x8);

void Unk_5e6560_reset(Unk_5e6560* self);

// A 0x20-byte value ending in an Unk_5e6560; several classes return a copy of
// one. Its copy constructor is user-written: the fields are copied one by one
// (an implicit one would memcpy the first three). The last two loads stay two
// ldr only with -g: the DBG_VALUE of Unk_5e6560's `other` (x0 + 0x20) sits
// between them, and the second load overwrites x0.
struct Unk_5e6560_Value {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    Unk_5e6560 field_18;

    Unk_5e6560_Value(const Unk_5e6560_Value& other)
        : field_0(other.field_0),
          field_8(other.field_8),
          field_10(other.field_10),
          field_18(other.field_18) {}
};
PKMN_OFFSET_ASSERT(Unk_5e6560_Value, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_5e6560_Value, 0x20);
