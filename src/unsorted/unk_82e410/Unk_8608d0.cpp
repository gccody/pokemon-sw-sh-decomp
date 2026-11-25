// Scope: common
// Battle event handlers (0x71008608d0-0x7100861124): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_85c190.h, Unk_860110.h).
// Placeholder names.
#include "unsorted/unk_82e410/Unk_860110.h"

// NON_MATCHING: named with a u64 Pokemon and a u32 kind; the original
// compares both as bytes and keeps w1 (mov w20, w1, not mov x20, x1).
// 0x71008608d0
void Unk_8608d0(void* self, u64 pokeId, u32 kind, u32 stat) {
    Unk_860370_Check(self, pokeId, kind, stat);
}

// 0x7100860990
void Unk_860990(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (!Unk_780c60(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12), 8))
        return;
    if (!Unk_7f0c00(Unk_8196d0(flow, pokeId), 3, 1))
        return;
    Unk_860370_Show(self, pokeId);
}

// 0x7100860a20
void Unk_860a20(void* self, u8 pokeId) {
    Unk_860410_Raise(self, pokeId, 3);
}

// 0x7100860b00
void Unk_860b00(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (!Unk_81acc0(flow, pokeId))
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x54) != 0)
        return;
    if (!Unk_860b00_CanShow(self, pokeId))
        return;
    Unk_860370_Show(self, pokeId);
}

// 0x7100860bb0
void Unk_860bb0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    {
        Unk_840b50_Arg arg;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x230);
        Unk_803d60(&arg.field_4, pokeId);
        Unk_81a030(flow, arg);
    }
    {
        Unk_8566e0_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        if (!Unk_81a760(flow, arg))
            return;
    }
    {
        Unk_856020_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_3 = 1;
        Unk_81a640(flow, arg);
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// 0x7100860cb0
void Unk_860cb0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (static_cast<s32>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x23)) < 0)
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x7100860dd0
void Unk_860dd0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_860d10(self, pokeId);
}

// 0x7100860e20
void Unk_860e20(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    {
        Unk_840b50_Arg arg;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x7ca);
        Unk_803d60(&arg.field_4, pokeId);
        Unk_81a030(flow, arg);
    }
    {
        Unk_8566e0_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        if (!Unk_81a760(flow, arg))
            return;
    }
    {
        Unk_856020_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_3 = 1;
        Unk_81a640(flow, arg);
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// NON_MATCHING: the original passes `pokeId` to 0x710081b750 (in w1), which
// is named without it; with a u8 parameter there, the rest matches.
// 0x7100860f30
void Unk_860f30(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (!Unk_81b750(flow))
        return;
    u32 move = Unk_819690_call(static_cast<const Unk_819690*>(self));
    u32 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x650);
    Unk_803d60(&arg.field_4, pokeId);
    Unk_803d60(&arg.field_4, move);
    Unk_803d60(&arg.field_4, value);
    Unk_81a030(flow, arg);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x75, 1);
}

// 0x7100861020
void Unk_861020(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u8 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x3e);
    if (value == 1 || value == 2 || value == 5 || value == 6)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1);
}

// 0x71008610b0
void Unk_8610b0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16)) != 9)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 1)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, 0x14cd);
}
