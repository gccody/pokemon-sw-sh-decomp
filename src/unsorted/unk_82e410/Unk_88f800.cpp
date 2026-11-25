// Scope: common
// Battle event handlers (0x710088f800-0x710088ff20) of two species' forms:
// 0x30a, whose form 0 is replaced (0x710088f960), and 0x36b, whose form is
// set by 0x710088ff20. They read the event's variables through the handler
// object's leaf accessors (src/unsorted/leaf/Unk_819600.cpp) and pass
// parameter blocks to the battle state's handler objects (Unk_886280.h).
// Placeholder names.
#include "unsorted/unk_82e410/Unk_886280.h"

u32 Unk_7f79e0(Unk_7ee6b0* self, u32 divisor, bool check);
u8 Unk_81a310(const Unk_819600_Self* self);
void Unk_819a80(const Unk_819600_Self* self, u8 pokeId);
void Unk_819ac0(const Unk_819600_Self* self, u8 pokeId);

void Unk_88f960(void* self, u8 pokeId, u8 arg2, u8 arg3);
// Named (void*, u64, u32); its code takes two bytes (see below).
void Unk_88ff20(void* self, u8 pokeId, u8 form);

static inline u32 Unk_88f800_Var(void* self, u32 index) {
    return Unk_819600_call(static_cast<const Unk_819600*>(self), index);
}

// Whether the Pokemon is species `species` in form 0 (Unk_7ef220 not
// set).
static inline bool Unk_88f800_IsForm(const Unk_7ee6b0* poke, u16 species) {
    if (Unk_85c190_Species(poke) != species)
        return false;
    if (poke->field_33d != 0)
        return false;
    return !Unk_7ef220_get(reinterpret_cast<const Unk_7ef220*>(poke));
}

// 0x710088f800
void Unk_88f800(void* self, u8 pokeId) {
    if (Unk_88f800_Var(self, 4) != pokeId)
        return;
    if (Unk_88f800_Var(self, 0x4d) == 1)
        return;
    Unk_88f960(self, pokeId, Unk_88f800_Var(self, 3), 3);
}

// 0x710088f870
void Unk_88f870(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_88f800_Var(self, 2) != pokeId)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (!Unk_88f800_IsForm(poke, 0x30a))
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0)
        return;
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x3c, 1);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x710088f910
void Unk_88f910(void* self, u8 pokeId) {
    if (Unk_88f800_Var(self, 4) == pokeId)
        Unk_88f960(self, pokeId, pokeId, 2);
}

// 0x710088f960
void Unk_88f960(void* self, u8 pokeId, u8 arg2, u8 arg3) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (!Unk_88f800_IsForm(poke, 0x30a))
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    Unk_819a80(flow, pokeId);
    {
        Unk_840b50_Arg arg;
        arg.field_0 = pokeId;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 1, 0x16c);
        Unk_81a030(flow, arg);
    }
    {
        Unk_8557b0_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_2 = 1;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_8), 2, 0x776);
        Unk_803d60(&arg.field_8, pokeId);
        Unk_81aa70(flow, arg);
    }
    {
        Unk_84d950_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = pokeId;
        arg.field_2 = Unk_7f79e0(poke, 8, true);
        arg.field_4 = arg3;
        arg.field_5 = arg2;
        arg.field_7 = 1;
        Unk_819b80(flow, arg);
    }
    Unk_819ac0(flow, pokeId);
}

// 0x710088fb10
void Unk_88fb10(void* self, u8 pokeId) {
    if (Unk_88f800_Var(self, 2) == pokeId)
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, 1);
}

// 0x710088fb60
void Unk_88fb60(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 1) == 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 1, 0);
    if (Unk_81a310(flow) == 3)
        Unk_88ff20(self, pokeId, 0);
}

// 0x710088fbd0
void Unk_88fbd0(void* self, u8 pokeId) {
    if (Unk_81a310(static_cast<const Unk_819600_Self*>(self)) == 3)
        Unk_88ff20(self, pokeId, 0);
}

// 0x710088fc20
void Unk_88fc20(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_88f800_Var(self, 4) != pokeId)
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 1)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (!Unk_88f800_IsForm(poke, 0x36b))
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x59, 1);
}

// 0x710088fcd0
void Unk_88fcd0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_88f800_Var(self, 4) != pokeId)
        return;
    if (Unk_88f800_Var(self, 0x4d) == 1)
        return;
    if (Unk_819630_call(static_cast<const Unk_819630*>(self)) != 1)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (!Unk_88f800_IsForm(poke, 0x36b))
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x3c, 1);
}

// 0x710088fd90
void Unk_88fd90(void* self, u8 pokeId) {
    if (Unk_88f800_Var(self, 4) != pokeId)
        return;
    if (Unk_88f800_Var(self, 0x4d) == 1)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    Unk_88ff20(self, pokeId, 1);
}

// 0x710088fe10
void Unk_88fe10(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_88f800_Var(self, 2) != pokeId)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (!Unk_88f800_IsForm(poke, 0x36b))
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x3c, 1);
}

// 0x710088feb0
void Unk_88feb0(void* self, u8 pokeId) {
    if (Unk_88f800_Var(self, 4) != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
    Unk_88ff20(self, pokeId, 1);
}

// 0x710088ff20
void Unk_88ff20(void* self, u8 pokeId, u8 form) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_85c190_Species(poke) != 0x36b)
        return;
    if (poke->field_33d == form)
        return;
    if (Unk_7ef220_get(reinterpret_cast<const Unk_7ef220*>(poke)))
        return;
    Unk_8557b0_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = form;
    arg.field_2 = 1;
    arg.field_4 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_8), 2, 0x130);
    Unk_803d60(&arg.field_8, pokeId);
    Unk_81aa70(flow, arg);
}
