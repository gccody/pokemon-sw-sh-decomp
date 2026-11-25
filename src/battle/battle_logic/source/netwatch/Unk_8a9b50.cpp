// Scope: common
// Slots 173 to 175, 227 to 231, 239 to 245 and 262 of Unk_23b9048
// (Unk_8a9b50.h): questions about the battle's positions and its counts,
// asked of the main module at +0x58 and the module at +0x60, each with a
// default for when the module is missing.
#include "battle/battle_logic/source/netwatch/Unk_8a9b50.h"

// The main module's functions (src/battle/battle_engine/Unk_7c2d80.cpp).
u8 Unk_7cb540(const Unk_7c2d80_Main* self, u8 position);
u8 Unk_7cb7a0(const Unk_7c2d80_Main* self, u8 position);
u8 Unk_7cb4b0(const Unk_7c2d80_Main* self, Unk_7ecc90_Con* con, u8 pokeId);
u8 Unk_7c9b60(void* self, u8 client, u32 index);
u8 Unk_7cc000(void* self, u8 index);
bool Unk_7cce80(void* self, u8 id, u8 arg);
u32 Unk_7cb320(void* self, u32 value);

// The module at +0x60's counts, per side.
u32 Unk_8ac1f0(void* self, s32 index);

// Leaf functions with their own placeholder types (src/unsorted/leaf).
struct Unk_7cac80;
u8 Unk_7cac80_call(const Unk_7cac80* self, u8 value);
struct Unk_7cd220;
u32 Unk_7cd220_call(const Unk_7cd220* self, u32 value);
struct Unk_7d0bb0;
void* Unk_7d0bb0_getField250(const Unk_7d0bb0* self);
u32 Unk_7d0bc0(const Unk_7d0bb0* self, u32 index);
struct Unk_7dfdb0;
u8 Unk_7dfdb0_getField2a6(const Unk_7dfdb0* self);

struct Unk_800280;
u32 Unk_8004b0(const Unk_800280* self);
u32 Unk_800430(const Unk_800280* self);
u32 Unk_800480(const Unk_800280* self);
u32 Unk_8003e0(const Unk_800280* self);
struct Unk_8003c0;
u8 Unk_8003c0_getField11(const Unk_8003c0* self);
struct Unk_8003d0;
u32 Unk_8003d0_getField88(const Unk_8003d0* self);

struct Unk_7ee6b0_Field;
u32 Unk_7ffb00(const Unk_7ee6b0_Field* self);
struct Unk_7ffaa0;
u8 Unk_7ffaa0_getField0(const Unk_7ffaa0* self);
struct Unk_7ffaf0;
u8 Unk_7ffaf0_getField10(const Unk_7ffaf0* self);
struct Unk_7ffb30;
u32 Unk_7ffb30_getField8(const Unk_7ffb30* self);
struct Unk_7ffac0;
u32 Unk_7ffac0_get(const Unk_7ffac0* self);
struct Unk_7ffab0;
u32 Unk_7ffab0_getFieldc(const Unk_7ffab0* self);

struct Unk_8022b0_Entry;
u32 Unk_8024c0(const Unk_8022b0_Entry* self);
struct Unk_802460;
bool Unk_802460_check(const Unk_802460* self);
struct Unk_8024f0;
u32 Unk_8024f0_get(const Unk_8024f0* self);
struct Unk_802480;
u32 Unk_802480_get(const Unk_802480* self);
struct Unk_8024a0;
u32 Unk_8024a0_get(const Unk_8024a0* self);
struct Unk_802490;
u32 Unk_802490_getField18(const Unk_802490* self);

template <typename T>
static const T* As(const void* object) {
    return static_cast<const T*>(object);
}

// 0x71008a9b50
bool Unk_23b9048::vf262() {
    if (field_58 == nullptr)
        return true;
    if (!vf273())
        return true;
    u8 own = vf276();
    u8 other = vf277();
    u8 ownClient = Unk_7c9b60(field_58, own, 0);
    u8 otherClient = Unk_7c9b60(field_58, other, 0);
    return ownClient < otherClient;
}

// 0x71008a9c10
u8 Unk_23b9048::vf227(u8 position) {
    if (field_58 != nullptr)
        return Unk_7cb540(field_58, position);
    return 0xff;
}

// 0x71008a9c30
u8 Unk_23b9048::vf228(u8 client) {
    if (field_58 != nullptr)
        return Unk_7cb7a0(field_58, client);
    return 5;
}

// NON_MATCHING: Unk_7cd220_call is named with a u32 parameter, so the index
// gets masked; the original passes it as it is.
// 0x71008a9c50
u32 Unk_23b9048::vf229(u32 client) {
    if (field_58 == nullptr)
        return client != 0;
    u8 index = vf228(client);
    if (index == 5)
        return 2;
    return Unk_7cd220_call(As<Unk_7cd220>(field_58), index);
}

// 0x71008a9cc0
u8 Unk_23b9048::vf230(u8 pokeId) {
    if (field_58 == nullptr)
        return 0xff;
    return Unk_7cb4b0(field_58, vf252(), pokeId);
}

// NON_MATCHING: Unk_7cd220_call is named with a u32 parameter, so the index
// gets masked; the original passes it as it is.
// 0x71008a9d10
u32 Unk_23b9048::vf231(u32 client) {
    if (field_58 == nullptr)
        return 0;
    u8 index = vf228(client);
    if (index == 5)
        return 0;
    return Unk_7cb320(field_58, Unk_7cd220_call(As<Unk_7cd220>(field_58), index));
}

// 0x71008a9d80
u32 Unk_23b9048::vf173() {
    return Unk_8ac1f0(Unk_7d0bb0_getField250(As<Unk_7d0bb0>(field_60)), 0);
}

// 0x71008a9da0
u32 Unk_23b9048::vf174() {
    return Unk_8ac1f0(Unk_7d0bb0_getField250(As<Unk_7d0bb0>(field_60)), 2);
}

// 0x71008a9dc0
u32 Unk_23b9048::vf175(u32 client) {
    if (vf275())
        return Unk_7d0bc0(As<Unk_7d0bb0>(field_60), client);
    if (Unk_7dfdb0_getField2a6(As<Unk_7dfdb0>(field_60)) == client)
        return Unk_8ac1f0(Unk_7d0bb0_getField250(As<Unk_7d0bb0>(field_60)), 1);
    return Unk_7d0bc0(As<Unk_7d0bb0>(field_60), client);
}

// 0x71008a9e30
void Unk_23b9048::vf239(u32* out1, u32* out2) {
    *out1 = 0;
    *out2 = 0;
    const Unk_8a9b50_Info* info = vf263();
    if (!Unk_7ffaa0_getField0(As<Unk_7ffaa0>(info)))
        return;
    u8 position = vf276();
    u8 pokeId = Unk_7ffaf0_getField10(As<Unk_7ffaf0>(info));
    u32 arg4 = Unk_7ffb00(As<Unk_7ee6b0_Field>(info));
    u32 arg5 = Unk_7ffb30_getField8(As<Unk_7ffb30>(info));
    u32 arg6 = Unk_7ffac0_get(As<Unk_7ffac0>(info));
    u32 arg7 = Unk_7ffab0_getFieldc(As<Unk_7ffab0>(info));
    if (arg4 < 0xff)
        vf245(out1, out2, position, pokeId, arg4, arg5, arg6, arg7);
}

// 0x71008a9f30
void Unk_23b9048::vf240(u32* out1, u32* out2) {
    *out1 = 0;
    *out2 = 0;
    const Unk_8a9b50_Info* info = vf263();
    if (Unk_8003c0_getField11(As<Unk_8003c0>(info))) {
        const Unk_800280* move = As<Unk_800280>(info);
        vf245(out1, out2, vf276(), Unk_8004b0(move), Unk_800430(move), Unk_800480(move),
              Unk_8003e0(move), Unk_8003d0_getField88(As<Unk_8003d0>(info)));
    }
}

// 0x71008aa020
void Unk_23b9048::vf242(u32* out1, u32* out2, u32 index) {
    vf241(out1, out2, index, 1);
}

// 0x71008aa030
void Unk_23b9048::vf243(u32* out1, u32* out2, u32 index) {
    vf241(out1, out2, index, 0);
}

// 0x71008aa040
void Unk_23b9048::vf244(u32* out1, u32* out2, u32 index) {
    vf241(out1, out2, index, 0x11);
}

// 0x71008aa050
void Unk_23b9048::vf241(u32* out1, u32* out2, u32 index, u32 kind) {
    *out1 = 0;
    *out2 = 0;
    switch (kind) {
        case 0:
        case 1:
        case 0x11:
            break;
        default:
            return;
    }
    const Unk_8a9b50_Info* info = vf264(index, kind);
    if (!Unk_802460_check(As<Unk_802460>(info)))
        return;
    vf245(out1, out2, vf276(), Unk_8024f0_get(As<Unk_8024f0>(info)),
          Unk_802480_get(As<Unk_802480>(info)), Unk_8024c0(As<Unk_8022b0_Entry>(info)),
          Unk_8024a0_get(As<Unk_8024a0>(info)), Unk_802490_getField18(As<Unk_802490>(info)));
}

// 0x71008aa160
void Unk_23b9048::vf245(u32* out1,
                        u32* out2,
                        u8 value,
                        u8 pokeId,
                        u32 arg4,
                        u32 arg5,
                        u32 arg6,
                        u32 arg7) {
    *out1 = 0;
    *out2 = 0;
    if (field_58 == nullptr)
        return;
    if (pokeId != 0x1f) {
        if (!vf275()) {
            u8 position = Unk_7cc000(field_58, pokeId);
            u8 index = Unk_7cac80_call(As<Unk_7cac80>(field_58), value);
            if (Unk_7cce80(field_58, index, position)) {
                *out1 = arg6;
                *out2 = arg4;
                return;
            }
        }
        u32 rest = arg4 - arg5;
        if (rest > arg7) {
            arg4 = rest;
            arg6 -= arg5;
        }
    }
    *out1 = arg6;
    *out2 = arg4;
}
