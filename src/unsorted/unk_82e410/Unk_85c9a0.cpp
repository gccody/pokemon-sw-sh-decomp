// Scope: common
// Battle event handlers (0x710085c9a0-0x710085d1dc), after the TU of
// Unk_85c190.cpp: most check the species of the Pokemon (Unk_8196d0) and
// set an event variable (Unk_85c190.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_85c190.h"

// 0x710085c9a0
void Unk_85c9a0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u16 species = Unk_85c190_Species(Unk_8196d0(flow, pokeId));
    if (species != 0x361 && species != 0x53)
        return;
    u8 value = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x2f) + 2;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x2f, value);
}

// 0x710085ca20
void Unk_85ca20(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u32 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (!Unk_7f0aa0(Unk_8196d0(flow, other), 1))
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085cae0
void Unk_85cae0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    u16 percent = 100 - Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085cb80
void Unk_85cb80(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 1)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085cc20
void Unk_85cc20(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 2)
        return;
    s32 percent = 100 + Unk_85c190_Value(flow, 6);
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x34, UNK_85C190_FX_PERCENT(percent));
}

// 0x710085ccc0
void Unk_85ccc0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_85c190_Species(Unk_8196d0(flow, pokeId)) != 0x16e)
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 2)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x2000);
}

// 0x710085cd40
void Unk_85cd40(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (Unk_85c190_Species(Unk_8196d0(flow, pokeId)) != 0x16e)
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 2)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x2000);
}

// 0x710085cdc0
void Unk_85cdc0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    const Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_85c190_Species(poke) != 0x84)
        return;
    if (Unk_7ef220_get(reinterpret_cast<const Unk_7ef220*>(poke)))
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 1)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x2000);
}

// 0x710085ce50
void Unk_85ce50(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    const Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_85c190_Species(poke) != 0x84)
        return;
    if (Unk_7ef220_get(reinterpret_cast<const Unk_7ef220*>(poke)))
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x2000);
}

// The species 0x710085ced0 checks for, in a function of its own: the original
// folds the two compares into one ((species | 1) == 0x69).
static inline bool Unk_85ced0_IsSpecies(u16 species) {
    return species == 0x68 || species == 0x69;
}

// 0x710085ced0
void Unk_85ced0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (!Unk_85ced0_IsSpecies(Unk_85c190_Species(Unk_8196d0(flow, pokeId))))
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 1)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x2000);
}

// 0x710085cf50
void Unk_85cf50(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    u32 id = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12);
    u32 other = Unk_819600_call(static_cast<const Unk_819600*>(self), 0x14);
    if (Unk_819d40(flow, pokeId, id, other))
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x710085cfe0
void Unk_85cfe0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    Unk_85cfe0_Arg arg;
    arg.field_0 = pokeId;
    arg.field_26 = 1;
    arg.field_8 = pokeId;
    arg.field_4 = 0x1c;
    arg.field_28 = Unk_819690_call(static_cast<const Unk_819690*>(self));
    arg.field_2b = 1;
    Unk_819c80(flow, &arg);
}

// 0x710085d090
void Unk_85d090(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(Unk_8196d0(flow, pokeId))))
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 1)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x1800);
}

// 0x710085d100
void Unk_85d100(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_7ef4c0(Unk_8196d0(flow, pokeId), 0x13))
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x73, 0);
}

// 0x710085d170
void Unk_85d170(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(Unk_8196d0(flow, pokeId))))
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 2)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x1800);
}
