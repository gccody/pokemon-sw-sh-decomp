// Scope: common
// Four more queries of the battle logic's object at +0x78 (Unk_8a82e0, see
// Unk_8a8110.cpp's Unk_8a8550 and Unk_8a85b0): each brings the module's
// copy up to date, clears the reader's state, and asks one of the handler
// objects (game/unk_82e410) through the copy's holder. Placeholder names.
#include "battle/battle_logic/source/netwatch/Unk_8a8110.h"
#include "unsorted/unk_82e410/Handler.h"

// The leaf accessors the queries go through (src/unsorted/leaf/Unk_7e88d0.cpp,
// Unk_8139c0.cpp), declared with what they return here.
struct Unk_7e88d0;
struct Unk_7e8900;
struct Unk_7e8910;
struct Unk_8139d0;
Unk_8139d0* Unk_7e88d0_getField10(const Unk_7e88d0* self);
void Unk_8139d0_clearField0(Unk_8139d0* self);
void* Unk_7e8900_getFieldb0(const Unk_7e8900* self);
const Unk_7e0080* Unk_7e8910_getField130(const Unk_7e8910* self);

// Copies the module's state into its copy (0x71007fe080, not decompiled yet).
void Unk_7fe080(void* self, const void* other);

// Brings the copy up to date and clears the reader's state.
static inline void Unk_8a8620_Sync(Unk_8a82e0* object) {
    Unk_7fe080(object->field_8.get(), object->field_0);
    Unk_8139d0_clearField0(
        Unk_7e88d0_getField10(reinterpret_cast<const Unk_7e88d0*>(object->field_28.get())));
}

// The holder of the reader's handler objects.
static inline const Unk_7e0080* Unk_8a8620_Holder(Unk_8a82e0* object) {
    return Unk_7e8910_getField130(reinterpret_cast<const Unk_7e8910*>(object->field_28.get()));
}

struct Unk_863cf0_Arg {
    void* field_0;
    bool field_8;
};
PKMN_SIZE_ASSERT(Unk_863cf0_Arg, 0x10);
void Unk_863cf0(Unk_23b1300* self, Unk_23acc98_Result& result, const Unk_863cf0_Arg& arg);

// 0x71008a8620
bool Unk_8a8620(void* self, void* other, bool flag) {
    Unk_8a82e0* object = static_cast<Unk_8a82e0*>(self);
    Unk_8a8620_Sync(object);
    Unk_863cf0_Arg arg = {other, flag};
    Unk_23acc98_Result result;
    Unk_863cf0(Unk_7e0080_Geta40(Unk_8a8620_Holder(object)), result, arg);
    return result.field_0;
}

// 0x7100818c30, not decompiled yet.
bool Unk_818c30(void* self, u32 a1, u32 a2);

// 0x71008a8690
bool Unk_8a8690(void* self, u32 a1, u32 a2) {
    Unk_8a82e0* object = static_cast<Unk_8a82e0*>(self);
    Unk_7fe080(object->field_8.get(), object->field_0);
    return Unk_818c30(
        Unk_7e8900_getFieldb0(reinterpret_cast<const Unk_7e8900*>(object->field_28.get())), a2, a1);
}

struct Unk_8544a0_Arg {
    u8 field_0;
    u8 field_1;
    u32 field_4;
    bool field_8;
    bool field_9;
};
PKMN_SIZE_ASSERT(Unk_8544a0_Arg, 0xc);
PKMN_OFFSET_ASSERT(Unk_8544a0_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_8544a0_Arg, field_8, 0x8);
struct Unk_8544a0_Result {
    u16 field_0;
};
void Unk_8544a0(Unk_23ae660* self, Unk_8544a0_Result& result, const Unk_8544a0_Arg& arg);

// 0x71008a86e0
u16 Unk_8a86e0(void* self, u8 a1, u8 a2, u32 a3, bool a4, bool a5) {
    Unk_8a82e0* object = static_cast<Unk_8a82e0*>(self);
    Unk_8a8620_Sync(object);
    Unk_8544a0_Arg arg = {a1, a2, a3, a4, a5};
    Unk_8544a0_Result result;
    Unk_8544a0(Unk_7e0080_Get1dc0(Unk_8a8620_Holder(object)), result, arg);
    return result.field_0;
}

struct Unk_8546d0_Arg {
    u8 field_0;
    u8 field_1;
    u32 field_4;
    bool field_8;
};
PKMN_SIZE_ASSERT(Unk_8546d0_Arg, 0xc);
PKMN_OFFSET_ASSERT(Unk_8546d0_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_8546d0_Arg, field_8, 0x8);
struct Unk_8546d0_Result {
    u32 field_0;
};
void Unk_8546d0(Unk_23ae680* self, Unk_8546d0_Result& result, const Unk_8546d0_Arg& arg);

// 0x71008a8770
u32 Unk_8a8770(void* self, u8 a1, u8 a2, u32 a3, bool a4) {
    Unk_8a82e0* object = static_cast<Unk_8a82e0*>(self);
    Unk_8a8620_Sync(object);
    Unk_8546d0_Arg arg = {a1, a2, a3, a4};
    Unk_8546d0_Result result;
    Unk_8546d0(Unk_7e0080_Get1da0(Unk_8a8620_Holder(object)), result, arg);
    return result.field_0;
}
