// Scope: common
// Battle event handlers (0x710085c190-0x710085c994): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_85c190.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_85c190.h"

// 0x710085c190
void Unk_85c190(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 6) == 0)
        return;
    if (!Unk_859570(self, pokeId, 0x2f, 0xdb))
        return;
    Unk_856020_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    arg.field_3 = 1;
    Unk_81a640(flow, arg);
}

// 0x710085c210
void Unk_85c210(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x54) != 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x710085c270
void Unk_85c270(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    Unk_819a10_call(static_cast<const Unk_819a10*>(self));
    Unk_850fb0_Arg arg;
    arg.field_0 = pokeId;
    Unk_81a5c0(flow, arg);
}

// 0x710085c2f0
void Unk_85c2f0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    {
        Unk_84a910_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_2 = pokeId;
        arg.field_8 = 5;
        arg.field_c = 2;
        arg.field_e = Unk_819690_call(static_cast<const Unk_819690*>(self));
        if (!Unk_819df0(flow, arg))
            return;
    }
    Unk_856020_Arg message;
    message.field_0 = pokeId;
    message.field_1 = 1;
    message.field_3 = 1;
    Unk_81a640(flow, message);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// 0x710085c3d0
void Unk_85c3d0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    u32 percent = 100 - Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085c460
void Unk_85c460(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x800);
}

// NON_MATCHING: the original tests Unk_7f7ff0's result with cmp/cset (a
// 32-bit result made a flag), where its bool gives and #1.
// 0x710085c4b0
void Unk_85c4b0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x11) != 1)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_82cd00(const_cast<void*>(flow->field_10), pokeId))
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0) {
        u8 percent = Unk_85c190_Value(flow, 6);
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, Unk_7f7ff0(percent));
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
    }
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 1) == 0)
        return;
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x11, 2))
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 2) != 0)
        return;
    Unk_819a10_call(static_cast<const Unk_819a10*>(self));
    Unk_850fb0_Arg arg;
    arg.field_0 = pokeId;
    Unk_81a5c0(flow, arg);
}

// 0x710085c5b0
void Unk_85c5b0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 attacker = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (attacker != pokeId)
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x56c);
    Unk_803d60(&arg.field_4, attacker);
    Unk_803d60(&arg.field_4, Unk_819690_call(static_cast<const Unk_819690*>(self)));
    Unk_81a030(flow, arg);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 2, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// 0x710085c670
void Unk_85c670(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, 0);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 2, 0);
}

// 0x710085c6e0
void Unk_85c6e0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x11) != 1)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819a60_call(static_cast<const Unk_819a60*>(self), pokeId))
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x11, 0);
}

// 0x710085c750
void Unk_85c750(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x28) != 0)
        return;
    u8 value = Unk_85c190_Value(flow, 6);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x29, value);
}

// 0x710085c7c0
void Unk_85c7c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_853920_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 100;
    if (Unk_81a7d0(flow, arg))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// 0x710085c830
void Unk_85c830(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085c8c0
void Unk_85c8c0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u8 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x2f) + 1;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x2f, value);
}

// 0x710085c920
void Unk_85c920(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_85c190_Species(Unk_8196d0(flow, pokeId)) != 0x71)
        return;
    u8 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x2f) + 2;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x2f, value);
}
