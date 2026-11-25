// Scope: common
// Battle server command wrappers: act on the server's state, then queue the
// command for the clients. Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

struct Unk_7c5910;
struct Unk_817c60;

bool Unk_7c5910_call(const Unk_7c5910* self, u32 value);
u32 Unk_817c60_call(const Unk_817c60* self);
void Unk_817c40(const Unk_8139c0_Self* self);

void Unk_816d00(const Unk_8139c0_Self* self, u8 arg1, u8 arg2);
void Unk_816d40(const Unk_8139c0_Self* self, u8 arg1, u8 arg2);
void Unk_816da0(const Unk_8139c0_Self* self, u8 arg1, u8 arg2);
void Unk_817630(const Unk_8139c0_Self* self, u8 client, u8 pokeId, u8 other);
void Unk_817710(const Unk_8139c0_Self* self, u8 pokeId, u8 slot, u32 move, u8 maxPP, u8 original);
void Unk_817a80(const Unk_8139c0_Self* self,
                u8 arg1,
                u8 arg2,
                u8 arg3,
                u8 arg4,
                u8 arg5,
                u8 arg6,
                u8 arg7,
                u8 arg8,
                u8 arg9);
void Unk_817bf0(const Unk_8139c0_Self* self, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void Unk_817d70(const Unk_8139c0_Self* self, u32 client);
void Unk_817db0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817e60(const Unk_8139c0_Self* self, u8 pokeId);

// The server's +8: what says which clients are in the battle.
struct Unk_811400_Self {
    u8 _0[0x8];
    const Unk_7c5910* field_8;
    u8 _10[0x8];
    u64 field_18;
    const Unk_8139c0_Self* field_20;
};
PKMN_OFFSET_ASSERT(Unk_811400_Self, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_811400_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_811400_Self, field_20, 0x20);

// 0x7100811400
void Unk_811400(const Unk_811d90_Self* self,
                u8 arg1,
                u8 arg2,
                u8 arg3,
                u8 arg4,
                u8 arg5,
                u8 arg6,
                u8 arg7,
                u8 arg8,
                u8 arg9) {
    Unk_817a80(self->field_20, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    Unk_8150c0(self->field_18, 0xe, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

// 0x71008114b0
void Unk_8114b0(const Unk_811d90_Self* self, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    Unk_817bf0(self->field_20, arg1, arg2, arg3, arg4);
    Unk_8150c0(self->field_18, 0x82, arg1, arg2, arg3, arg4, arg5);
}

// 0x7100811520
void Unk_811520(const Unk_811d90_Self* self) {
    Unk_817c40(self->field_20);
    Unk_8150c0(self->field_18, 0x68);
}

// 0x7100811550
void Unk_811550(const Unk_811d90_Self* self, u8 value) {
    Unk_8150c0(self->field_18, 0x94, value);
}

// 0x7100811560
u32 Unk_811560(const Unk_811d90_Self* self) {
    u32 result = Unk_817c60_call(reinterpret_cast<const Unk_817c60*>(self->field_20));
    Unk_8150c0(self->field_18, 0x4d, 0);
    return result;
}

// 0x71008116e0
void Unk_8116e0(const Unk_811400_Self* self, u32 client) {
    if (Unk_7c5910_call(self->field_8, client)) {
        Unk_817d70(self->field_20, client);
        Unk_8150c0(self->field_18, 0x3a, static_cast<u8>(client));
    }
}

// 0x71008115a0
void Unk_8115a0(const Unk_811400_Self* self) {
    for (u8 client = 0; client < 5; client++) {
        Unk_8116e0(self, client);
    }
}

// 0x7100811730
void Unk_811730(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817db0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x3b, pokeId);
}

// 0x7100811770
void Unk_811770(const Unk_811d90_Self* self, u8 value) {
    Unk_8150c0(self->field_18, 0xa0, value);
}

// 0x7100811780
void Unk_811780(const Unk_811d90_Self* self, u8 client, u32 pokeId, u32 other) {
    Unk_817630(self->field_20, client, pokeId, other);
    Unk_8150c0(self->field_18, 0x69, client, pokeId, other);
}

// 0x71008117d0
void Unk_8117d0(const Unk_811d90_Self* self, u8 arg1, u32 arg2, u32 arg3) {
    Unk_8150c0(self->field_18, 0x99, arg1, arg2, arg3);
}

// 0x71008117f0
void Unk_8117f0(const Unk_811d90_Self* self, u8 pokeId, u8 slot, u32 move, u8 maxPP, u8 original) {
    Unk_817710(self->field_20, pokeId, slot, move, maxPP, original);
    Unk_8150c0(self->field_18, 0x26, pokeId, slot, maxPP, original, move);
}

// 0x7100811860
void Unk_811860(const Unk_811d90_Self* self, u8 arg1, u8 arg2) {
    Unk_816d40(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x8, arg1, arg2);
}

// 0x71008118b0
void Unk_8118b0(const Unk_811d90_Self* self, u8 arg1, u8 arg2) {
    Unk_816da0(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x9, arg1, arg2);
}

// 0x7100811900
void Unk_811900(const Unk_811d90_Self* self, u8 arg1, u8 arg2) {
    Unk_816d00(self->field_20, arg1, arg2);
    Unk_8150c0(self->field_18, 0x7, arg1, arg2);
}

// 0x7100811950
void Unk_811950(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_817e60(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x5c, pokeId);
}
