// Scope: common
// Battle event handlers (0x7100860110-0x71008608cc): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_85c190.h, Unk_860110.h).
// Placeholder names.
#include "unsorted/unk_82e410/Unk_860110.h"

// 0x7100860110
void Unk_860110(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    Unk_838f90_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = pokeId;
    arg.field_2 = 0;
    arg.field_7 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_c), 2, 0x22c);
    Unk_803d60(&arg.field_c, pokeId);
    Unk_81a510(flow, arg);
}

// 0x71008601b0
void Unk_8601b0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (!Unk_81acc0(flow, pokeId))
        return;
    u8 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    if (Unk_81bf40(flow, target) == 5)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x54) != 0)
        return;
    if (!Unk_8199a0(flow, target))
        return;
    if (!Unk_81c220(flow, target))
        return;
    if (Unk_81be40(flow))
        return;
    {
        Unk_856020_Arg arg;
        arg.field_0 = pokeId;
        arg.field_3 = 1;
        Unk_840b50_List* list = reinterpret_cast<Unk_840b50_List*>(&arg.field_4);
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(list), 2, 0x234);
        Unk_803d60(list, pokeId);
        Unk_803d60(list, target);
        Unk_81a640(flow, arg);
    }
    {
        Unk_83c7b0_Arg arg;
        arg.field_2 = 0;
        arg.field_3 = 1;
        arg.field_4 = 0x3c;
        arg.field_8 = 0;
        arg.field_0 = pokeId;
        arg.field_1 = target;
        Unk_81a840(flow, arg);
    }
}

// 0x71008602d0
void Unk_8602d0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x52, 1);
}

// 0x7100860320
void Unk_860320(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    Unk_7f8a20(Unk_819680_call(static_cast<const Unk_819680*>(self), 0x1f), true);
}

// Shows the effect of `pokeId` (0x7100819a10, then 0x710081a5c0).
static inline void Unk_860370_Show(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_819a10_call(static_cast<const Unk_819a10*>(self));
    Unk_850fb0_Arg arg;
    arg.field_0 = pokeId;
    Unk_81a5c0(flow, arg);
}

// When the event's variable 4 is `pokeId`, its variable 0x4d is 0 and its
// variable 0x16 is 0xa, and the Pokemon's `stat` can rise, shows the effect.
static inline void Unk_860370_Check(void* self, u8 pokeId, u32 stat) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x4d) != 0)
        return;
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16)) != 0xa)
        return;
    if (!Unk_7f0c00(Unk_8196d0(flow, pokeId), stat, 1))
        return;
    Unk_860370_Show(self, pokeId);
}

// 0x7100860370
void Unk_860370(void* self, u8 pokeId) {
    Unk_860370_Check(self, pokeId, 3);
}

// Raises the Pokemon's `stat` (0x7100819df0) when the event's variable 2 is
// `pokeId`, then shows the effect and sets variable 0x50.
static inline void Unk_860410_Raise(void* self, u8 pokeId, u32 stat) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    {
        Unk_84a910_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_2 = pokeId;
        arg.field_8 = stat;
        arg.field_c = 1;
        arg.field_e = Unk_819690_call(static_cast<const Unk_819690*>(self));
        if (!Unk_819df0(flow, arg))
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

// 0x7100860410
void Unk_860410(void* self, u8 pokeId) {
    Unk_860410_Raise(self, pokeId, 3);
}

// 0x71008604f0
void Unk_8604f0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (!Unk_81acc0(flow, pokeId))
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 1)
        return;
    if (!Unk_7f0c00(Unk_8196d0(flow, pokeId), 2, 1))
        return;
    Unk_860370_Show(self, pokeId);
}

// 0x7100860570
void Unk_860570(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    u8 amount = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x60) != 0 ? 2 : 1;
    if (!Unk_7f0c00(poke, 2, amount))
        return;
    Unk_84a910_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    arg.field_2 = pokeId;
    arg.field_8 = 2;
    arg.field_c = amount;
    arg.field_e = Unk_819690_call(static_cast<const Unk_819690*>(self));
    if (!Unk_819df0(flow, arg))
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// 0x7100860660
void Unk_860660(void* self, u8 pokeId) {
    Unk_860370_Check(self, pokeId, 4);
}

// 0x7100860700
void Unk_860700(void* self, u8 pokeId) {
    Unk_860410_Raise(self, pokeId, 4);
}

// 0x71008607f0
void Unk_8607f0(void* self, u8 pokeId) {
    Unk_860410_Raise(self, pokeId, 1);
}
