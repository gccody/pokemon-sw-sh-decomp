// Scope: common
//
// Script commands of game/unk_133d350 (0x71013e6570-0x71013e6a40), entries of
// a command table that take the script's context and its arguments (as
// src/field/content/Unk_13f1360.h): the checks of a 16-bit value in their
// first argument, and calls of the objects the global Unk_24ba4e0 holds at
// +0x1d8 and +0x208 (through a reference held for the call, as
// src/unsorted/unk_133d350/Unk_13b0640.cpp). Placeholder names: rename once
// the classes are known.
#include <types.h>

#include "field/content/Unk_13f1360.h"
#include "gflib3/Unk_239a418.h"

// The owner of the block stores (as src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type {
    u8 _0[0x1d8];
    Unk_239a418_Ref2<Unk_239a418> field_1d8;
    u8 _1e0[0x208 - 0x1e0];
    Unk_239a418_Ref2<Unk_239a418> field_208;
};
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_1d8, 0x1d8);
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_208, 0x208);

extern Unk_24ba4e0_Type* Unk_24ba4e0;

// The functions of the object at +0x1d8. They take the values as u16s.
bool Unk_1367100(void* self, u32 arg1, u32 arg2, u32 arg3);
bool Unk_1367350(Unk_239a418* self, u16 arg1, u16 arg2);
bool Unk_1367510(Unk_239a418* self, u16 arg1, u16 arg2);
u32 Unk_1367a30(Unk_239a418* self, u16 arg1);

// The functions of the object at +0x208: 0x710137bb10 sets the pair at +0x27c
// (the value and 200, 100 or 250 for 0x4c, 0x4f and 0x4d; false for any other
// value), 0x710137bb60 looks the value up in a table while the count is set.
struct Unk_137bbb0;
bool Unk_137bb10(Unk_239a418* self, u32 value);
s32 Unk_137bb60(Unk_239a418* self);
s32 Unk_137bbb0_getField27e(const Unk_137bbb0* self);

// The checks of a value (src/unsorted/leaf/Unk_782c90.cpp).
u16 Unk_786c10_call(u32 value);
s32 Unk_786a40(u32 value, u32 arg1);
bool Unk_786b80(u16 value);
bool Unk_786d90(u16 value);
bool Unk_786e20(u16 value);
bool Unk_786e70(u16 value);
bool Unk_786ec0(u16 value);
bool Unk_786f10(u16 value);

// 0x71013e6570
// NON_MATCHING: Unk_1367100 takes the values as u16s (as Unk_1367350 and
// Unk_1367510: the original loads them with ldrh and passes them as they are),
// but its name gives u32s, so they're loaded as words and masked at the call.
s64 Unk_13e6570(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u16 value = args->field_8;
    u16 arg = args->field_10;
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_1d8;
    return Unk_1367100(object.m_ptr, value, arg, 1);
}

// 0x71013e6610
s64 Unk_13e6610(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u16 value = args->field_8;
    u16 arg = args->field_10;
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_1d8;
    return Unk_1367510(object.m_ptr, value, arg);
}

// 0x71013e66a0
s64 Unk_13e66a0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u16 value = args->field_8;
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_1d8;
    return Unk_1367a30(object.m_ptr, value);
}

// 0x71013e6730
s64 Unk_13e6730(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u16 value = args->field_8;
    u16 arg = args->field_10;
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_1d8;
    return Unk_1367350(object.m_ptr, value, arg);
}

// 0x71013e67e0
s64 Unk_13e67e0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u16 value = args->field_8;
    return Unk_786c10_call(value);
}

// 0x71013e6820: which of the six checks the value passes first, 0 for none.
s64 Unk_13e6820(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    u16 value = args->field_8;
    if (Unk_786b80(value))
        return 1;
    if (Unk_786d90(value))
        return 2;
    if (Unk_786e20(value))
        return 3;
    if (Unk_786e70(value))
        return 4;
    if (Unk_786ec0(value))
        return 5;
    return Unk_786f10(value) ? 6 : 0;
}

// 0x71013e6920
s64 Unk_13e6920(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    return Unk_786a40(args->field_8, 0xe);
}

// 0x71013e6940
s64 Unk_13e6940(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_208;
    Unk_137bb10(object.m_ptr, args->field_8);
    return 0;
}

// 0x71013e69c0
s64 Unk_13e69c0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_208;
    return Unk_137bb60(object.m_ptr);
}

// 0x71013e6a40
s64 Unk_13e6a40(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_239a418> object = Unk_24ba4e0->field_208;
    return Unk_137bbb0_getField27e(reinterpret_cast<const Unk_137bbb0*>(object.m_ptr));
}
