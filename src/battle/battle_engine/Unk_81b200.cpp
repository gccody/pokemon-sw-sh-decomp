// Scope: common
// Battle event helpers (0x710081b230-0x710081b8d0): checks on the event's
// variables and the Pokemon, which set other variables or add the Pokemon to
// the current entry's list (Unk_81b200.h). Placeholder names.
#include "battle/battle_engine/Unk_81b200.h"

struct Unk_7f0b70;
bool Unk_7f0b70_check(const Unk_7f0b70* self);
struct Unk_7ef330;
void* Unk_7ef330_getField60(const Unk_7ef330* self);
struct Unk_7f09c0;
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);
u8 Unk_764ca0(void* self);
bool Unk_7ebab0(u16 move);
// Named after the Pokemon it's given.
bool Unk_7ef2b0_call(void* self);
u32 Unk_7e9a00(u64 self, u8 index);
void Unk_7e9a10(u64 self, u8 index, u32 value);

// The parameter block of Unk_840b50 (0x710081a030 passes one): a Pokemon and
// a list of up to eight values, with a kind and their count in a bitfield
// (Unk_803d20_set, Unk_803d60).
struct Unk_840b50_List {
    u16 field_0;
    u16 field_2;
    u32 field_4[8];
};
PKMN_SIZE_ASSERT(Unk_840b50_List, 0x24);
struct Unk_803c60;
void Unk_803c60_set(Unk_803c60* self);
struct Unk_803d20;
void Unk_803d20_set(Unk_803d20* self, u32 value, u16 arg2);
void Unk_803d60(Unk_840b50_List* self, u32 value);

struct Unk_840b50_Arg {
    u8 field_0;
    u8 field_1;
    u8 _2[2];
    Unk_840b50_List field_4;

    Unk_840b50_Arg() : field_0(0x1f), field_1(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_4));
    }
};
PKMN_OFFSET_ASSERT(Unk_840b50_Arg, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_840b50_Arg, 0x28);
void Unk_840b50(Unk_23adad8* self, Unk_23acc98_Result& result, const Unk_840b50_Arg& arg);

static inline Unk_7ecc90_Con* Unk_81b200_Con(const Unk_819600_Self* self) {
    return Unk_7fe1d0_getField8(self->field_8);
}

// 0x710081b230
void Unk_81b230(void* arg, u8 pokeId) {
    const Unk_819600_Self* self = static_cast<const Unk_819600_Self*>(arg);
    if (Unk_7f0b70_check(
            reinterpret_cast<const Unk_7f0b70*>(Unk_7ed1e0(Unk_81b200_Con(self), pokeId))))
        return;
    u32 otherId = Unk_7e9830(self->field_30, 2);
    if (Unk_7cbf80(self->field_0, otherId, pokeId))
        return;
    u32 move = Unk_7e9830(self->field_30, 0x12);
    if (Unk_780da0(move) != 0xb)
        return;
    if (!Unk_780c60(move, 4))
        return;
    if (!Unk_7e97b0(self->field_30, 0x25, 0x19))
        return;
    u8 value = Unk_803600(Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_8)),
                          otherId);
    Unk_81b200_Add(&Unk_81b200_Entry(self)->list, pokeId, otherId, value);
}

// 0x710081b320
void Unk_81b320(const Unk_819600_Self* self, u8 pokeId) {
    if (Unk_7e9830(self->field_30, 0x55) != 0)
        return;
    if (Unk_7e9830(self->field_30, 4) != pokeId)
        return;
    if (Unk_7f0b70_check(
            reinterpret_cast<const Unk_7f0b70*>(Unk_7ecc90(Unk_81b200_Con(self), pokeId))))
        return;
    if (!Unk_780c60(Unk_7e9830(self->field_30, 0x12), 4))
        return;
    if (!Unk_7e97b0(self->field_30, 0x47, 1))
        return;
    u32 otherId = Unk_7e9830(self->field_30, 3);
    u8 value = Unk_803600(Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_8)),
                          otherId);
    Unk_81b200_Add(&Unk_81b200_Entry(self)->list, pokeId, otherId, value);
    Unk_7e97b0(self->field_30, 0x59, 1);
}

// 0x710081b430
void Unk_81b430(const Unk_819600_Self* self, u8 pokeId) {
    u32 attacker = Unk_7e9830(self->field_30, 2);
    if (attacker != pokeId)
        return;
    if (Unk_7f0b70_check(
            reinterpret_cast<const Unk_7f0b70*>(Unk_7ecc90(Unk_81b200_Con(self), pokeId))))
        return;
    Unk_23acc98_Result result;
    Unk_840b50_Arg arg;
    arg.field_0 = pokeId;
    Unk_803d20_set(reinterpret_cast<Unk_803d20*>(&arg.field_4), 2, 0x406);
    Unk_803d60(&arg.field_4, attacker);
    Unk_803d60(&arg.field_4, Unk_7e9830(self->field_30, 0x12));
    Unk_840b50(Unk_7e0080_Getdc0(self->field_20), result, arg);
}

// 0x710081b550
void Unk_81b550(void* arg, u32 pokeId) {
    const Unk_819600_Self* self = static_cast<const Unk_819600_Self*>(arg);
    u32 attacker = Unk_7e9830(self->field_30, 2);
    if (Unk_7cbf80(self->field_0, attacker, pokeId))
        Unk_7e97b0(self->field_30, 0x59, 1);
}

// 0x710081b5b0
bool Unk_81b5b0(const Unk_819600_Self* self, u8 pokeId) {
    u32 attacker = Unk_7e9830(self->field_30, 2);
    if (Unk_7cbf80(self->field_0, attacker, pokeId) && Unk_7e97b0(self->field_30, 0x59, 1))
        return true;
    return false;
}

// The event's targets: a count in variable 5, the Pokemon from variable 6
// (as in Unk_81aae0.cpp).
static inline u8 Unk_81b610_Target(const Unk_819600_Self* self, u8 index) {
    void* event = self->field_30;
    if (index < Unk_7e9830(event, 5))
        return Unk_7e9830(event, 6 + index);
    return 0x1f;
}

// 0x710081b610
// NON_MATCHING: Unk_7e9830's label is a u16 (as in Unk_81ad70): declared so,
// the index is zero-extended at each use as in the original; the loop's latch
// is still i < count where the original tests i != count. Unk_7ef2b0 is
// named without the Pokemon it's given
u32 Unk_81b610(const Unk_819600_Self* self, u8 pokeId) {
    if (Unk_7e9830(self->field_30, 3) != pokeId)
        return 0;
    u32 count = Unk_7e9830(self->field_30, 5);
    u32 total = 0;
    for (u32 i = 0; i < count; i++) {
        u8 target = Unk_81b610_Target(self, i);
        if (target == 0x1f)
            return 0;
        total += Unk_7ef2b0_call(Unk_7ed1e0(Unk_81b200_Con(self), target));
    }
    return total;
}

// 0x710081b6e0
bool Unk_81b6e0(const Unk_819600_Self* self, u8 pokeId) {
    if (Unk_7e9830(self->field_30, 2) == pokeId) {
        s32 count = Unk_7e9830(self->field_30, 0x35);
        if (count > 0)
            return Unk_7e97b0(self->field_30, 0x48, 1);
    }
    return false;
}

// 0x710081b750: its callers pass the Pokemon's id too (unused here).
bool Unk_81b750(const Unk_819600_Self* self, u8 /*pokeId*/) {
    if (Unk_7ebab0(Unk_7e9830(self->field_30, 0x12)) && Unk_7e97b0(self->field_30, 0x47, 1))
        return true;
    return false;
}

// 0x710081b7a0
u8 Unk_81b7a0(const Unk_819600_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_7ed1e0(Unk_81b200_Con(self), pokeId);
    if (poke == nullptr)
        return 0;
    return Unk_764ca0(Unk_7ef330_getField60(reinterpret_cast<const Unk_7ef330*>(poke)));
}

// 0x710081b7e0
bool Unk_81b7e0(const Unk_819600_Self* self, u8 pokeId, u32 value) {
    if (Unk_7e9830(self->field_30, 4) == pokeId && Unk_7e9830(self->field_30, 0x1e) == value)
        return Unk_7e97b0(self->field_30, 0x48, 1);
    return false;
}

// 0x710081b860
void Unk_81b860(const Unk_819600_Self* self, u8 pokeId) {
    if (Unk_7e9830(self->field_30, 3) == pokeId) {
        Unk_7ee6b0* poke = Unk_7ed1e0(Unk_81b200_Con(self), pokeId);
        bool flag = Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(poke)) != 0;
        Unk_7e9a10(reinterpret_cast<u64>(self->field_40), 0, flag);
    }
}

// 0x710081b8d0
bool Unk_81b8d0(const Unk_819600_Self* self, u8 pokeId) {
    if (Unk_7e9a00(reinterpret_cast<u64>(self->field_40), 0) != 0)
        return false;
    Unk_7ee6b0* poke = Unk_7ed1e0(Unk_81b200_Con(self), pokeId);
    return Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(poke)) == 0;
}
