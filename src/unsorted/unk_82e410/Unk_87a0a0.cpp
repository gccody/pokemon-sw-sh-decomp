// Scope: common
// Battle event handlers (0x710087a0a0-0x710087a8c4), after the TU of
// Unk_8798c0.cpp. 0x710087a210 and 0x710087a7b0, which two of them call, are
// in their own TUs (Unk_87a210.cpp, Unk_87a7b0.cpp). Placeholder names.
#include "unsorted/unk_82e410/Unk_8798c0.h"

// 0x710087a0a0
void Unk_87a0a0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u64 packed = Unk_7f87a0(pokeId, 1);
    u32 value = Unk_8197a0_call(static_cast<const Unk_8197a0*>(self), pokeId);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    Unk_82fa10_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 0x10;
    arg.field_10 = value;
    arg.field_8 = packed;
    arg.field_38 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_14), 1, 0xe4);
    Unk_803d60(&arg.field_14, value);
    if (Unk_81a190(flow, arg))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x78, 1);
}

// 0x710087a1c0
void Unk_87a1c0(void* self, u8 pokeId) {
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 1) == 0)
        return;
    Unk_87a210(self, pokeId);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, 0);
}

// 0x710087a310
void Unk_87a310(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u32 count = Unk_819600_call(static_cast<const Unk_819600*>(self), 5);
    if (count == 0)
        return;
    u32 i = 0;
    do {
        u8 target = Unk_819600_call(static_cast<const Unk_819600*>(self), i + 6);
        if (!Unk_7ef4c0(Unk_8196d0(flow, target), 0x16)) {
            Unk_836520_Arg arg;
            arg.field_0 = pokeId;
            arg.field_1 = target;
            arg.field_4 = 0x16;
            arg.field_8 = Unk_7f7940(pokeId, pokeId);
            Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_18), 2, 0x49c);
            Unk_803d60(&arg.field_18, target);
            Unk_819d00(flow, arg);
        }
    } while (++i != count);
}

// 0x710087a430
void Unk_87a430(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    const Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_7ef200(poke) != 0x2d0)
        Unk_819650_call(static_cast<const Unk_819650*>(self), 0x1e);
    else if (poke->field_33d != 1)
        Unk_819650_call(static_cast<const Unk_819650*>(self), 0x1d);
}

// 0x710087a4c0
void Unk_87a4c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u8 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    const Unk_7ee6b0* poke = Unk_8196d0(flow, target);
    bool first = Unk_86ff60(self, target, true);
    bool second = Unk_7f0aa0(poke, 7);
    if (first || second)
        Unk_870270(self, pokeId, poke, 0x2be);
}

// 0x710087a560
void Unk_87a560(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_7ef200(Unk_8196d0(flow, pokeId)) != 0x36d)
        Unk_819650_call(static_cast<const Unk_819650*>(self), 0x20);
}

// 0x710087a5c0
void Unk_87a5c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    const Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_7ef200(poke) == 0x36d && poke->field_33d == 1)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x16, 0x10);
}

// 0x710087a640
void Unk_87a640(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x14) !=
        Unk_819690_call(static_cast<const Unk_819690*>(self)))
        return;
    const Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_7ef200(poke) == 0x36d && poke->field_33d == 1)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x12, Unk_82da30(0x10));
}

// 0x710087a6f0
void Unk_87a6f0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_7ef200(Unk_8196d0(flow, pokeId)) != 0x1eb)
        Unk_819650_call(static_cast<const Unk_819650*>(self), 0x1f);
}

// 0x710087a760
void Unk_87a760(void* self, u8 pokeId) {
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 1) == 0)
        return;
    Unk_87a7b0(self, pokeId);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, 0);
}

// 0x710087a860
void Unk_87a860(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u32 types = Unk_7f05d0(Unk_8196d0(flow, pokeId));
    u32 type = types & 0x1f;
    if (type == 0x12)
        type = (types >> 10) & 0x1f;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x16, type);
}
