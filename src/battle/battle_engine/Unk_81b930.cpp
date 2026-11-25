// Scope: common
// Battle event helpers (0x710081b930-0x710081bed0): ordering Pokemon by the
// priority a handler object gives them, setting the event's target and
// getters on the Pokemon and their parties. Placeholder names.
#include "battle/battle_engine/Unk_81b200.h"

struct Unk_7fc430_Party;
const Unk_7fc430_Party* Unk_7ed1b0(const Unk_7ecc90_Con* self, u32 client);
// NON_MATCHING callee: named without the Pokemon it's given.
u32 Unk_7ef6a0(const Unk_7ee6b0* poke);
bool Unk_855b30(const Unk_7ee6b0* poke);
bool Unk_7eb540(u16 value);
u8 Unk_781040(u32 id);
u32 Unk_7810b0(u32 arg1, u32 arg2, u32* out);
bool Unk_80d4b0(void* self, void* arg);
bool Unk_80d8f0(void* self);
bool Unk_7ef4c0(const Unk_7ee6b0* poke, u32 condition);
struct Unk_7ca1c0;
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);

// The parameter block of Unk_863cf0 (Unk_23b1300's function): the Pokemon,
// and a flag. Its result is a count (in the result's first byte).
struct Unk_863cf0_Arg {
    Unk_7ee6b0* field_0;
    bool field_8;
};
PKMN_OFFSET_ASSERT(Unk_863cf0_Arg, field_8, 0x8);
void Unk_863cf0(Unk_23b1300* self, Unk_23acc98_Result& result, const Unk_863cf0_Arg& arg);

// The priorities Unk_81b930 sorts by.
extern u16 Unk_27cefae[] __attribute__((visibility("hidden")));

// 0x710081b930
void Unk_81b930(const Unk_819600_Self* self, u8* pokeIds, u32 count, u8 otherId, bool bonus) {
    if (count > 5 || count == 0)
        return;
    for (u32 i = 0; i < count; i++) {
        Unk_863cf0_Arg arg = {};
        arg.field_0 = Unk_7ed1e0(Unk_7fe1d0_getField8(self->field_8), pokeIds[i]);
        arg.field_8 = true;
        Unk_23acc98_Result result;
        Unk_863cf0(Unk_7e0080_Geta40(self->field_20), result, arg);
        Unk_27cefae[i] = result.field_0;
        if (bonus && Unk_7cbf80(self->field_0, otherId, pokeIds[i]))
            Unk_27cefae[i] += 5;
    }
    for (u32 i = 0; i < count; i++) {
        for (u32 j = i + 1; j < count; j++) {
            if (Unk_27cefae[j] < Unk_27cefae[i]) {
                u16 priority = Unk_27cefae[i];
                Unk_27cefae[i] = Unk_27cefae[j];
                Unk_27cefae[j] = priority;
                u8 pokeId = pokeIds[i];
                pokeIds[i] = pokeIds[j];
                pokeIds[j] = pokeId;
            }
        }
    }
}

// 0x710081bb60
u32 Unk_81bb60(const Unk_819600_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_7ed1e0(Unk_7fe1d0_getField8(self->field_8), pokeId);
    if (poke != nullptr)
        return Unk_7ef6a0(poke);
    return 0;
}

// 0x710081bba0
bool Unk_81bba0(u32 id) {
    if (Unk_780da0(id) != 2)
        return false;
    u8 count = Unk_781040(id);
    if (count == 0)
        return false;
    for (u32 i = 0; i < count; i++) {
        u32 value;
        Unk_7810b0(id, i, &value);
        if (static_cast<s32>(value) < 0)
            return false;
    }
    return true;
}

// 0x710081bd40
void Unk_81bd40(const Unk_819600_Self* self, u8 pokeId, u8 count, u8 value) {
    u8 current = Unk_7e9830(self->field_30, 0x61);
    if (current < count) {
        Unk_7e97b0(self->field_30, 4, pokeId);
        Unk_7e97b0(self->field_30, 0x61, count);
        Unk_7e97b0(self->field_30, 0x62, value);
    }
}

// 0x710081bc20
void Unk_81bc20(void* arg, u64 pokeId, u32 count, u32 value) {
    const Unk_819600_Self* self = static_cast<const Unk_819600_Self*>(arg);
    if (Unk_7ca1c0_getField150(static_cast<const Unk_7ca1c0*>(self->field_0)) == 0)
        return;
    if (Unk_7cbf80(self->field_0, Unk_7e9830(self->field_30, 3), pokeId))
        return;
    if (Unk_7e9830(self->field_30, 0x12) == 0x1fb)
        return;
    if (Unk_7ef4c0(Unk_7ed1e0(Unk_7fe1d0_getField8(self->field_8), pokeId), 0x22))
        return;
    if (Unk_81b200_Entry(self)->field_36 != 0)
        return;
    Unk_81bd40(self, pokeId, count, value);
}

// 0x710081bd20
u8 Unk_81bd20(const Unk_819600_Self* self) {
    return Unk_81b200_Entry(self)->field_36;
}

// What 0x710081bdd0 is given (placeholder): a byte at +0x1a, a u16 at +0x1c.
struct Unk_81bdd0_Arg {
    u8 _0[0x1a];
    u8 field_1a;
    u8 _1b;
    u16 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_81bdd0_Arg, field_1a, 0x1a);
PKMN_OFFSET_ASSERT(Unk_81bdd0_Arg, field_1c, 0x1c);

// 0x710081bdd0
bool Unk_81bdd0(const Unk_81bdd0_Arg* arg) {
    if (arg->field_1a == 4 && Unk_7eb540(arg->field_1c))
        return true;
    return false;
}

// 0x710081be10
bool Unk_81be10(const Unk_819600_Self* self, u8 pokeId) {
    return Unk_855b30(Unk_7ed1e0(Unk_7fe1d0_getField8(self->field_8), pokeId));
}

// 0x710081be40
bool Unk_81be40(const Unk_819600_Self* self) {
    if (Unk_80d4b0(self->field_0, const_cast<Unk_7fe1d0*>(self->field_8)))
        return Unk_80d8f0(self->field_0);
    return false;
}

// 0x710081bea0
const Unk_7fc430_Party* Unk_81bea0(const Unk_819600_Self* self, u32 client) {
    return Unk_7ed1b0(Unk_7fe1d0_getField8(self->field_8), client);
}

// 0x710081bed0
const Unk_7fc430_Party* Unk_81bed0(const Unk_819600_Self* self, u8 pokeId) {
    u8 client = Unk_7cb490(pokeId);
    return Unk_7ed1b0(Unk_7fe1d0_getField8(self->field_8), client);
}
