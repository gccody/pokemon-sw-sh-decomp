// Scope: common
#include "battle/battle_logic/source/netwatch/Unk_8a8110.h"

#include "battle/battle_logic/source/netwatch/Unk_8a7f30.h"
#include "unsorted/Unk_2771620.h"

// 0x71008a8120
u8 Unk_8a8030::Unk_8a8120() const {
    if (field_31 == 0)
        return 6;
    return field_18[field_31 - 1];
}

// 0x71008a8140
u8 Unk_8a8030::Unk_8a8140(u8 index) const {
    if (index < field_31)
        return field_18[index];
    return 6;
}

// 0x71008a8160
void Unk_8a8030::Unk_8a8160(u32 a0, u8 a1, u16 a2, u8 a3) {
    if (field_31 < field_32) {
        field_4[field_31] = a0;
        field_18[field_31] = a1;
        field_1d[field_31] = 0;
        field_22[field_31] = a2;
        field_2c[field_31] = a3;
        field_31++;
    }
}

// 0x71008a81c0
bool Unk_8a8030::Unk_8a81c0(u32* a0, u8* a1, u16* a2, u8* a3) const {
    if (field_31 == 0)
        return false;
    u32 last = field_31 - 1;
    if (field_22[last] == 0) {
        *a0 = 5;
        *a1 = 0;
        *a3 = 0;
        *a2 = 0;
        return false;
    }
    *a0 = field_4[last];
    *a1 = field_18[last];
    *a3 = field_2c[last];
    *a2 = field_22[last];
    return true;
}

// Thirty flags, cleared together.
extern u8 Unk_27d12de[30];

// 0x71008a8230
void Unk_8a8230() {
    for (int i = 0; i < 30; i++)
        Unk_27d12de[i] = 0;
}

// 0x71008a8260
void Unk_8a8260(u8 index) {
    if (index < 30)
        Unk_27d12de[index] = 1;
}

// 0x71008a8290
bool Unk_8a8290(u8 index) {
    if (index < 30)
        return Unk_27d12de[index] != 0;
    return false;
}

// Read by Unk_8a82d0_get (src/unsorted/leaf/Unk_8a7f50.cpp).
extern u64 Unk_27d1300;

// 0x71008a82c0
void Unk_8a82c0(u64 value) {
    Unk_27d1300 = value;
}

// 0x71008a82e0
Unk_8a82e0::Unk_8a82e0(const Unk_8a82e0_Args& args) : field_0(args.field_10) {
    Unk_8a8330(args.field_0, args.field_8);
    Unk_8a8440(args.field_0, args.field_8);
}

// 0x71008a8330
void Unk_8a82e0::Unk_8a8330(Unk_239a418_Allocator* allocator, void* module) {
    Unk_23ac8d8_Args args = {allocator, module};
    field_8 = Unk_2771620_MakeUnique<Unk_23ac8d8>(allocator, args);
}

// 0x71008a8440
void Unk_8a82e0::Unk_8a8440(Unk_239a418_Allocator* allocator, void* module) {
    Unk_7dfde0_Args args = {allocator, module, field_8.get()};
    field_28 = Unk_2771620_MakeUnique<Unk_7dfde0>(allocator, args);
}

// The leaf accessors the two calls below go through
// (src/unsorted/leaf/Unk_7e88d0.cpp, Unk_8139c0.cpp, Unk_828410.cpp),
// declared with what they return here.
struct Unk_7e88d0;
struct Unk_7e8910;
struct Unk_8139d0;
struct Unk_828930;
struct Unk_828a60;
struct Unk_23ad258;
Unk_8139d0* Unk_7e88d0_getField10(const Unk_7e88d0* self);
void Unk_8139d0_clearField0(Unk_8139d0* self);
const void* Unk_7e8910_getField130(const Unk_7e8910* self);
Unk_23ad258* Unk_828a60_getFieldcc0(const Unk_828a60* self);
void* Unk_828930_getFielda20(const Unk_828930* self);

// Copies the module's state into its copy (0x71007fe080, not decompiled yet).
void Unk_7fe080(void* self, const void* other);

// src/unsorted/unk_82e410/Handler.h
struct Unk_8341a0_Arg {
    u8 field_0;
};
struct Unk_8341a0_Result {
    u8 field_0;
};
void Unk_8341a0(Unk_23ad258* self, Unk_8341a0_Result& result, const Unk_8341a0_Arg& arg);

// What Unk_8a85b0 asks Unk_855f20 with.
struct Unk_8a85b0_Query {
    void* field_0;
    bool field_8;
};
PKMN_SIZE_ASSERT(Unk_8a85b0_Query, 0x10);
void Unk_855f20(void* self, u64* out, const void* in);

// 0x71008a8550
u8 Unk_8a8550(void* self) {
    Unk_8a82e0* object = static_cast<Unk_8a82e0*>(self);
    Unk_7fe080(object->field_8.get(), object->field_0);
    Unk_8139d0_clearField0(
        Unk_7e88d0_getField10(reinterpret_cast<const Unk_7e88d0*>(object->field_28.get())));
    Unk_8341a0_Arg arg = {0x1f};
    Unk_8341a0_Result result;
    Unk_8341a0(Unk_828a60_getFieldcc0(static_cast<const Unk_828a60*>(Unk_7e8910_getField130(
                   reinterpret_cast<const Unk_7e8910*>(object->field_28.get())))),
               result, arg);
    return result.field_0;
}

// NON_MATCHING: the flag is a bool (the original masks it with `and #1`);
// the name, from its caller, gives it as u32.
// 0x71008a85b0
u16 Unk_8a85b0(void* self, void* other, u32 flag) {
    Unk_8a82e0* object = static_cast<Unk_8a82e0*>(self);
    Unk_7fe080(object->field_8.get(), object->field_0);
    Unk_8139d0_clearField0(
        Unk_7e88d0_getField10(reinterpret_cast<const Unk_7e88d0*>(object->field_28.get())));
    Unk_8a85b0_Query query = {other, flag != 0};
    u64 result;
    Unk_855f20(Unk_828930_getFielda20(static_cast<const Unk_828930*>(Unk_7e8910_getField130(
                   reinterpret_cast<const Unk_7e8910*>(object->field_28.get())))),
               &result, &query);
    return result;
}
