// Scope: common
// Battle event handlers (0x7100890010-0x71008907a0), most of them of species
// 0x34d's forms (0x7100890330 sets them, 0x71008900d0 resets them). They
// read the event's variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp) and pass parameter blocks to the battle
// state's handler objects (Unk_890010.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_890010.h"

void Unk_890330(void* self, u8 pokeId);

static inline u32 Unk_890010_Var(void* self, u32 index) {
    return Unk_819600_call(static_cast<const Unk_819600*>(self), index);
}

// 0x7100890010
void Unk_890010(void* self, u8 pokeId) {
    if (Unk_890010_Var(self, 3) != pokeId)
        return;
    if (Unk_890010_Var(self, 0x12) != 0x123)
        return;
    Unk_890330(self, pokeId);
}

// 0x7100890070
void Unk_890070(void* self, u8 pokeId) {
    if (Unk_890010_Var(self, 3) != pokeId)
        return;
    if (Unk_890010_Var(self, 0x12) != 0x39)
        return;
    Unk_890330(self, pokeId);
}

// 0x71008900d0
void Unk_8900d0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_890010_Var(self, 4) != pokeId)
        return;
    if (Unk_890010_Var(self, 0x4d) != 0)
        return;
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    u8 form = poke->field_33d;
    u16 species = Unk_890010_Species(poke);
    if (form == 0)
        return;
    if (species != 0x34d)
        return;
    if (Unk_7f0b70_check(reinterpret_cast<const Unk_7f0b70*>(poke)))
        return;
    if (Unk_7ef220_get(reinterpret_cast<const Unk_7ef220*>(poke)))
        return;
    u8 targetId = Unk_890010_Var(self, 3);
    Unk_7ee6b0* target = Unk_8196d0(flow, targetId);
    if (Unk_7ef2b0_call(target))
        return;
    if (!Unk_819a30(flow, targetId))
        return;
    u16 message = poke->field_33d == 2 ? 0xe6 : 0xe5;
    {
        Unk_8557b0_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 0;
        arg.field_3 = 1;
        arg.field_4 = 0;
        arg.field_5 = 0;
        Unk_81aa70(flow, arg);
    }
    {
        Unk_84d950_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = targetId;
        arg.field_2 = Unk_7f79e0(target, 4, true);
        arg.field_4 = 0;
        arg.field_5 = pokeId;
        arg.field_7 = 1;
        arg.field_9 = 2;
        arg.field_a = message;
        arg.field_c = Unk_81bf40(flow, pokeId);
        arg.field_d = Unk_81bf40(flow, targetId);
        Unk_819b80(flow, arg);
    }
    switch (form) {
        case 1: {
            Unk_84a910_Arg arg;
            arg.field_0 = pokeId;
            arg.field_8 = 2;
            arg.field_c = 0xff;
            arg.field_1 = 1;
            arg.field_2 = targetId;
            arg.field_1a = 1;
            Unk_819df0(flow, arg);
            break;
        }
        case 2: {
            Unk_836520_Arg arg;
            arg.field_0 = pokeId;
            arg.field_1 = targetId;
            arg.field_4 = 1;
            arg.field_8 = Unk_7f78c0(1, pokeId);
            arg.field_10 = 0;
            Unk_819d00(flow, arg);
            break;
        }
    }
}

// 0x7100890330
void Unk_890330(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_7ee6b0* poke = Unk_8196d0(flow, pokeId);
    if (Unk_890010_Species(poke) != 0x34d)
        return;
    if (poke->field_33d != 0)
        return;
    if (Unk_7ef220_get(reinterpret_cast<const Unk_7ef220*>(poke)))
        return;
    Unk_8557b0_Arg arg;
    arg.field_0 = Unk_7ee6b0_getField7d(poke);
    arg.field_1 = Unk_7eef50(poke, 0xd) <= Unk_7f7990(poke, 2, false) ? 2 : 1;
    arg.field_5 = !Unk_819960_call(static_cast<const Unk_819960*>(self));
    Unk_81aa70(flow, arg);
}

// 0x7100890420
void Unk_890420(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_890010_Var(self, 2);
    if (target != pokeId)
        return;
    Unk_819a80(flow, pokeId);
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x772);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
    Unk_819ac0(flow, pokeId);
}

// The ids 0x71008904c0 tries in turn.
static const u32 sUnk_8904c0_Ids[] = {1, 2, 3, 4, 5, 14};

// 0x71008904c0
void Unk_8904c0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    for (u64 i = 0; i < 6; ++i) {
        bool done = Unk_81b7e0(flow, pokeId, sUnk_8904c0_Ids[i]);
        Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, done);
        if (done)
            return;
    }
}

// 0x7100890550
void Unk_890550(void* self, u8 pokeId) {
    if (Unk_890010_Var(self, 3) != pokeId)
        return;
    s32 count = Unk_890010_Var(self, 0x3d);
    if (count < 8)
        return;
    Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x1400);
}

// 0x71008905d0
void Unk_8905d0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_890010_Var(self, 2) != pokeId)
        return;
    if (Unk_819950_call(static_cast<const Unk_819950*>(self), 0x4000))
        return;
    Unk_84a910_Arg arg;
    arg.field_0 = pokeId;
    arg.field_8 = 1;
    arg.field_c = 1;
    arg.field_1 = 1;
    arg.field_2 = pokeId;
    arg.field_14 = 1;
    Unk_819df0(flow, arg);
}

// 0x7100890690
void Unk_890690(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_890010_Var(self, 2) != pokeId)
        return;
    if (Unk_819950_call(static_cast<const Unk_819950*>(self), 0x4000))
        return;
    Unk_84a910_Arg arg;
    arg.field_0 = pokeId;
    arg.field_8 = 2;
    arg.field_c = 1;
    arg.field_1 = 1;
    arg.field_2 = pokeId;
    arg.field_14 = 1;
    Unk_819df0(flow, arg);
}

// 0x7100890750
void Unk_890750(void* self, u8 pokeId) {
    if (Unk_890010_Var(self, 2) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x73, 0);
}

// 0x71008907a0
void Unk_8907a0(void* self, u8 pokeId) {
    if (Unk_890010_Var(self, 2) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x77, 1);
}
