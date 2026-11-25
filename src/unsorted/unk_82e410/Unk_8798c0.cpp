// Scope: common
// Battle event handlers (0x71008798c0-0x710087a08c): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects. Placeholder names.
#include "unsorted/unk_82e410/Unk_8798c0.h"

// 0x7100879a60
void Unk_879a60(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1);
}

// 0x7100879ab0
void Unk_879ab0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1);
}

// 0x7100879b00
void Unk_879b00(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16) != 4)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x3d) == 0)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x3d, 7);
}

// 0x7100879b70
void Unk_879b70(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u32 count = Unk_819600_call(static_cast<const Unk_819600*>(self), 5);
    for (u32 i = 0; i != count; i++)
        Unk_877630(self, pokeId, Unk_819600_call(static_cast<const Unk_819600*>(self), i + 6));
}

// 0x7100879bf0
void Unk_879bf0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    Unk_81c300(flow, pokeId, 1);
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 1, 0x10f);
    Unk_81a030(flow, arg);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x78, 1);
}

// 0x7100879c90
void Unk_879c90(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, Unk_819600_call(static_cast<const Unk_819600*>(self), 4));
    u32 value = Unk_7eef50(poke, 0x13);
    if (value - 0x39 >= 2)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x22, 0);
}

// 0x7100879d10
void Unk_879d10(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, Unk_819600_call(static_cast<const Unk_819600*>(self), 4));
    if (!Unk_7ef4c0(poke, 5))
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x22, 0);
}

// 0x710087a010
void Unk_87a010(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    if (target != pokeId)
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x664);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
}
