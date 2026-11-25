// Scope: common
// The named handle's last slot and its destructors, and the slots of the
// unnamed one (Unk_23a8100, declared by src/unsorted/virtual/Unk_792950.cpp):
// it is looked up as it is, without a name to test. The slots are written as
// free functions until the classes' signatures are known. Placeholder names:
// rename once the classes are known.
#include <types.h>

#include "unsorted/Unk_793990.h"

// Unk_23a8100 (vtable 0x71023a8110): nothing of it is read.
struct Unk_23a8100_Self;

// Slot 7.
// 0x71007941a0
bool Unk_7941a0(Unk_23a8158* self, u64 value) {
    if (!self->Unk_HasName())
        return false;
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793ac0(reinterpret_cast<u64>(Unk_27ce848), value, index);
}

// Unk_23a8100's slot 2.
// 0x7100794220
bool Unk_794220(Unk_23a8100_Self* self, const Unk_5cfaf0_Name* name, const Unk_5cfaf0_Name* other) {
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793ba0(Unk_27ce848, name, other, index);
}

// Unk_23a8100's slot 8.
// 0x7100794290
bool Unk_794290(Unk_23a8100_Self* self, u64 name, u32 arg2, f32 arg3) {
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793b20(reinterpret_cast<u64>(Unk_27ce848), name, arg3, index, arg2);
}

// Unk_23a8100's slot 4.
// 0x7100794330
u32 Unk_794330(Unk_23a8100_Self* self, const void* arg1) {
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return 0;
    return Unk_7938b0(Unk_27ce848, arg1, index);
}

// Unk_23a8100's slot 5.
// 0x7100794390
bool Unk_794390(Unk_23a8100_Self* self, f32 arg1) {
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793930(Unk_27ce848, index, arg1);
}

// Unk_23a8100's slot 6.
// 0x71007943f0
bool Unk_7943f0(Unk_23a8100_Self* self, const Unk_5cfaf0_Name* name, f32 decibels) {
    s64 index = Unk_791a00(Unk_24ba4f0, self, false);
    if (index == -1)
        return false;
    return Unk_793990(Unk_27ce848, name, decibels, index);
}

// 0x71007944c0, 0x7100794510
Unk_23a8158::~Unk_23a8158() {}
