// Scope: common
// Battle event handlers (0x7100885b40-0x710088627c): they read the event's
// variables through the handler object's leaf accessors
// (src/unsorted/leaf/Unk_819600.cpp), set others, and pass parameter blocks
// to the battle state's handler objects (Unk_886280.h). Placeholder names.
#include "unsorted/unk_82e410/Unk_886280.h"

bool Unk_7f05a0(const Unk_7ee6b0* self, u32 flag);
bool Unk_7ef5d0(Unk_7ee6b0* self, u32 flag);
u32 Unk_7f79e0(Unk_7ee6b0* self, u32 divisor, bool check);
void Unk_819a80(const Unk_819600_Self* self, u8 pokeId);
void Unk_819ac0(const Unk_819600_Self* self, u8 pokeId);
bool Unk_81b5b0(const Unk_819600_Self* self, u8 pokeId);
u8 Unk_81bf40(const Unk_819600_Self* self, u8 pokeId);
struct Unk_803dd0;
void Unk_803dd0_update(Unk_803dd0* self, u32 value);

// The target 0x71007f8cf0 sets (as in Unk_7f7fe0.cpp), which 0x710081c1b0
// turns into a list of Pokemon.
struct Unk_885dd0_Target {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_885dd0_Target, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_885dd0_Target, 0x8);
struct Unk_7f8cf0;
struct Unk_7f98e0_Arg;
void Unk_7f8cf0_set(Unk_7f8cf0* self, u32 value, u8 arg2);
u8 Unk_81c1b0(const Unk_819600_Self* self, const Unk_7f98e0_Arg* arg, void* out);

// What 0x710081a0e0 and 0x710081a120 are given: a Pokemon and a value.
struct Unk_856390_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_856390_Arg, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_856390_Arg, 0x8);
void Unk_81a0e0(const Unk_819600_Self* self, const Unk_856390_Arg& arg);
struct Unk_857530_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_857530_Arg, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_857530_Arg, 0x8);
void Unk_81a120(const Unk_819600_Self* self, const Unk_857530_Arg& arg);

// The predicate 0x7100886100 hands Unk_819840.
struct Unk_81bdd0_Arg;
bool Unk_81bdd0(const Unk_81bdd0_Arg* arg);

// 0x7100885b40
void Unk_885b40(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 4);
    if (target != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) == target)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16) != 9)
        return;
    if (Unk_81bba0(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x12)))
        return;
    if (!Unk_819640_call(static_cast<const Unk_819640*>(self), 0x47, 1))
        return;
    Unk_819a80(flow, pokeId);
    if (Unk_7f05a0(Unk_8196d0(flow, pokeId), 0xd)) {
        Unk_840b50_Arg arg;
        arg.field_0 = pokeId;
        Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x120);
        Unk_803d60(&arg.field_4, target);
        Unk_81a030(flow, arg);
    } else {
        {
            Unk_840b50_Arg arg;
            arg.field_0 = pokeId;
            Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x242);
            Unk_803d60(&arg.field_4, target);
            Unk_81a030(flow, arg);
        }
        Unk_856390_Arg arg;
        arg.field_0 = pokeId;
        arg.field_4 = 0xd;
        Unk_81a0e0(flow, arg);
    }
    Unk_819ac0(flow, pokeId);
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x75, 1);
}

// 0x7100885cc0
void Unk_885cc0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (!Unk_7f05a0(Unk_8196d0(flow, pokeId), 0xd))
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16) == 9)
        Unk_819660_call(static_cast<const Unk_819660*>(self), 0x38, 0x1800);
}

// 0x7100885d40
void Unk_885d40(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (!Unk_7f05a0(Unk_8196d0(flow, pokeId), 0xd))
        return;
    Unk_857530_Arg arg;
    arg.field_0 = pokeId;
    arg.field_4 = 0xd;
    Unk_81a120(flow, arg);
}

// 0x7100885dd0
void Unk_885dd0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    u8 ids[6];
    Unk_885dd0_Target query;
    Unk_7f8cf0_set(reinterpret_cast<Unk_7f8cf0*>(&query), 2, Unk_81bf40(flow, pokeId));
    u8 count = Unk_81c1b0(flow, reinterpret_cast<const Unk_7f98e0_Arg*>(&query), ids);
    if (count == 0)
        return;
    u8 started = 0;
    u8 i = 0;
    do {
        Unk_7ee6b0* poke = Unk_8196d0(flow, ids[i]);
        if (Unk_7ef5d0(poke, 1)) {
            if (!started) {
                Unk_819a80(flow, pokeId);
                started = 1;
            }
            Unk_84d950_Arg arg;
            arg.field_0 = pokeId;
            arg.field_1 = ids[i];
            arg.field_2 = Unk_7f79e0(poke, 8, true);
            arg.field_4 = 0x19;
            arg.field_5 = pokeId;
            Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_10), 2, 0x28e);
            Unk_803d60(&arg.field_10, ids[i]);
            Unk_819b80(flow, arg);
        }
    } while (++i != count);
    if (started)
        Unk_819ac0(flow, pokeId);
}

// 0x7100885f80
void Unk_885f80(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (!Unk_81b5b0(flow, pokeId))
        return;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    arg.field_1 = 1;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 1, 0x56);
    Unk_803dd0_update(reinterpret_cast<Unk_803dd0*>(&arg.field_4), 0);
    Unk_81a030(flow, arg);
}

// 0x7100886030
void Unk_886030(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    u32 target = Unk_819600_call(static_cast<const Unk_819600*>(self), 2);
    if (target != pokeId)
        return;
    u16 move = Unk_819690_call(static_cast<const Unk_819690*>(self));
    u16 message;
    if (move == 0xa3)
        message = 0x2aa;
    else if (move == 0xa4)
        message = 0x2a6;
    else
        message = 0x256;
    Unk_819a80(flow, pokeId);
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, message);
    Unk_803d60(&arg.field_4, target);
    Unk_81a030(flow, arg);
    Unk_819ac0(flow, pokeId);
}

// 0x7100886100
void Unk_886100(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 3) != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) != 0)
        return;
    Unk_819840(flow, reinterpret_cast<u64>(&Unk_81bdd0));
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}

// 0x7100886170
void Unk_886170(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_819850(flow);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
}

// 0x71008861d0
void Unk_8861d0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    if (Unk_8196a0_call(static_cast<const Unk_8196a0*>(self), 0) == 0)
        return;
    Unk_819850(flow);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 0);
}

// 0x7100886250
void Unk_886250(void* self, u8 pokeId) {
    Unk_886420(self, pokeId);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, 1);
}
