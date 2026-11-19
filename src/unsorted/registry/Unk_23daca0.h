#pragma once
// An abstract base (vtable 0x71023dacb0: its D2, a trapping D0 and four pure
// functions) of 166 functions' classes, with a memory resource at +0x8.
#include "gflib3/Unk_65f110.h"

// A 16-byte handle: 0x71007c2da0 constructs it empty, 0x71007c2d90 from a
// pointer, and 0x71007c2db0 polls what it holds. Directly called leaf
// functions (src/unsorted/leaf/Unk_7c2d90.cpp), each declared with its own
// placeholder struct: they're one class's.
struct Unk_7c2da0 {
    u64 field_0;
    u64 field_8;
};
void Unk_7c2da0_set(Unk_7c2da0* self);
struct Unk_7c2d90 {
    u64 field_0;
    u64 field_8;
};
void Unk_7c2d90_set(Unk_7c2d90* self, u64 value);
bool Unk_7c2db0(void* self, u32 mode);

class Unk_23daca0 {
public:
    Unk_23daca0() : field_8(nullptr), field_10(nullptr) {
        Unk_7c2da0_set(&field_18);
        Unk_e7b5e0(nullptr);
    }
    // 0x7100c38fc0 (D2), 0x7100c38fe0 (D0). Its D2 stores the vptr though
    // its body is empty: clang keeps the vptr stores of a destructor when a
    // member is an anonymous union (FieldHasTrivialDestructorBody in
    // clang's CGClass.cpp). What the union holds isn't known.
    virtual ~Unk_23daca0() {}
    virtual void* vf2(u64 size) = 0;
    virtual u64 vf3() = 0;
    virtual bool vf4() = 0;
    virtual bool vf5() = 0;

    // 0x7100e7b5e0: the resource, or a default one if null.
    void Unk_e7b5e0(Unk_239f910_Base* resource);

    Unk_239f910_Base* field_8;
    union {
        void* field_10;
    };
    Unk_7c2da0 field_18;
};
PKMN_OFFSET_ASSERT(Unk_23daca0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23daca0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_23daca0, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_23daca0, 0x28);
