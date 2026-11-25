#pragma once
// Scope: common
// What the battle event handlers of 0x710085e150-0x710085f0fc call, and the
// parameter blocks they give the battle state's handler objects. Placeholder
// names. Most come from Unk_85c190.h; the rest are copied from Unk_8798c0.h.
#include "unsorted/unk_82e410/Unk_85c190.h"

u32 Unk_7f79e0(Unk_7ee6b0* self, u32 divisor, bool check);
void Unk_81c300(const Unk_819600_Self* self, u8 pokeId, u32 value);
bool Unk_81b5b0(const Unk_819600_Self* self, u8 pokeId);
// Defined as void; it returns what its tail call gives (0x710085e150 keeps
// the byte).
u8 Unk_8198c0(const Unk_819600_Self* self, u8 pokeId);
struct Unk_803dd0;
void Unk_803dd0_update(Unk_803dd0* self, u32 value);

// As in Unk_8798c0.h: what Unk_819b80 is given, with a message list at +0x10.
// +0xa is a 16-bit value here: 0x710085e150 stores it with strh, and
// 0x710084d950 copies +0xa-+0xd as one 4-byte block.
struct Unk_84d950_Arg {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u16 field_a;
    u8 field_c;
    u8 field_d;
    u8 _e[2];
    Unk_840b50_List field_10;

    Unk_84d950_Arg()
        : field_0(0x1f),
          field_1(0x1f),
          field_2(0),
          field_4(0),
          field_5(0x1f),
          field_6(0),
          field_7(0),
          field_8(0),
          field_9(0),
          field_a(0),
          field_c(5),
          field_d(5) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_10));
    }
};
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_10, 0x10);
PKMN_SIZE_ASSERT(Unk_84d950_Arg, 0x34);
bool Unk_819b80(const Unk_819600_Self* self, const Unk_84d950_Arg& arg);

// 0x710085e2d0 and its neighbours: when the event's target (variable 3) is
// this Pokemon and the value of variable 0x16 is `kind`, variable 0x34 is
// scaled by 100% plus the handler's value.
inline void Unk_85e150_ScaleIfKind(void* self, u8 pokeId, u8 kind) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16)) != kind)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, UNK_85C190_FX_PERCENT(percent));
}
