// Scope: common
// Battle event handlers (0x710085f940-0x7100860108): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_85c190.h, Unk_886280.h).
// Placeholder names.
#include "unsorted/unk_82e410/Unk_886280.h"

bool Unk_819970(const Unk_819600_Self* self, u32 effect);
bool Unk_81bf90(const Unk_819600_Self* self, u8 pokeId);
u32 Unk_7f79e0(Unk_7ee6b0* self, u32 divisor, bool check);

// Raises variable 0x34 by the percentage of 0x7100819690's value 6, when the
// event's variable 0x16 is `type`.
static inline void Unk_85f940_Boost(void* self, u8 pokeId, u8 type) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16)) != type)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085f940
void Unk_85f940(void* self, u8 pokeId) {
    Unk_85f940_Boost(self, pokeId, 0xa);
}

// 0x710085f9f0
void Unk_85f9f0(void* self, u8 pokeId) {
    Unk_85f940_Boost(self, pokeId, 0xa);
}

// 0x710085faa0
void Unk_85faa0(void* self, u8 pokeId) {
    Unk_85f940_Boost(self, pokeId, 0xb);
}

// 0x710085fb50
void Unk_85fb50(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u32 species = Unk_85c190_Species(Unk_8196d0(flow, pokeId));
    if (species == 0x17d || species == 0x17c) {
        u8 type = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16);
        if (type == 0xd || type == 0xf)
            Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, UNK_85C190_FX_PERCENT(120));
    }
}

// 0x710085fbe0
void Unk_85fbe0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_85c190_Species(Unk_8196d0(flow, pokeId)) != 0x1e4)
        return;
    u8 type = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16);
    if (type != 0xf && type != 0xa)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085fcb0
void Unk_85fcb0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_85c190_Species(Unk_8196d0(flow, pokeId)) != 0x1e3)
        return;
    u8 type = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16);
    if (type != 0xf && type != 8)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085fd80
void Unk_85fd80(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x800);
}

// 0x710085fdd0
void Unk_85fdd0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1);
}

// 0x710085fe20
void Unk_85fe20(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x800);
}

// 0x710085fe70
void Unk_85fe70(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_85c190_Species(poke) == 0x29e && poke->field_33d == 5)
        return;
    if (Unk_81bf90(flow, pokeId))
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x1800);
}

// 0x710085ff00
void Unk_85ff00(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x4d) != 0)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x63) == 0)
        return;
    Unk_84d950_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = Unk_819600_call(static_cast<const Unk_819600*>(self), 3);
    Unk_7ee6b0* other = Unk_8196d0(flow, arg.field_1);
    u8 divisor = Unk_85c190_Value(flow, 6);
    arg.field_2 = Unk_7f79e0(other, divisor, true);
    arg.field_4 = 0x20;
    arg.field_5 = pokeId;
    arg.field_7 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_10), 2, 0x23e);
    Unk_803d60(&arg.field_10, arg.field_1);
    Unk_819b80(flow, arg);
}

// 0x7100860020
void Unk_860020(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (target != pokeId)
        return;
    if (Unk_819970(flow, 2))
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x228);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
}

// 0x71008600c0
void Unk_8600c0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1);
}
