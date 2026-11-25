// Scope: common
// Battle event helpers (0x710081aae0-0x710081b1f8): handler wrappers as in
// Unk_81a720.cpp, and checks on the event's targets and the Pokemon.
// Placeholder names.
#include "battle/battle_engine/Unk_7e8a20.h"
#include "battle/battle_engine/Unk_81a030.h"

// The handler objects' functions (game/unk_82e410), declared as Handler.h
// declares them.
struct Unk_8644b0_Arg;
void Unk_8644b0(Unk_23b13c0* self, Unk_23acc98_Result& result, const Unk_8644b0_Arg& arg);
struct Unk_862e20_Arg;
void Unk_862e20(Unk_23b11e0* self, Unk_23acc98_Result& result, const Unk_862e20_Arg& arg);
struct Unk_863ec0_Arg;
void Unk_863ec0(Unk_23b1320* self, Unk_23acc98_Result& result, const Unk_863ec0_Arg& arg);
struct Unk_8401a0_Arg;
void Unk_8401a0(Unk_23ada38* self, Unk_23acc98_Result& result, const Unk_8401a0_Arg& arg);
struct Unk_846a60_Arg;
void Unk_846a60(Unk_23addd8* self, Unk_23acc98_Result& result, const Unk_846a60_Arg& arg);

// 0x710081aae0
void Unk_81aae0(const Unk_819600_Self* self, const Unk_8644b0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8644b0(Unk_7e0080_Get1060(self->field_20), result, arg);
}

// 0x710081ab10
bool Unk_81ab10(const Unk_819600_Self* self, const Unk_863ec0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_863ec0(Unk_7e0080_Getd20(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081abd0
bool Unk_81abd0(const Unk_819600_Self* self, const Unk_8401a0_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_8401a0(Unk_7e0080_Get2a0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081ac50
bool Unk_81ac50(const Unk_819600_Self* self, const Unk_846a60_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_846a60(Unk_7e0080_Get5c0(self->field_20), result, arg);
    return result.field_0;
}

// 0x710081ac90
void Unk_81ac90(const Unk_819600_Self* self, const Unk_862e20_Arg& arg) {
    Unk_23acc98_Result result;
    Unk_862e20(Unk_7e0080_Getde0(self->field_20), result, arg);
}

// What the checks below call: the main module's (Unk_7cc000, Unk_7cb490 and
// leaf getters with their own placeholder types, src/unsorted/leaf) and the
// battle Pokemon's (src/battle/battle_engine/Unk_7ee6b0.h).
struct Unk_7ee6b0;
struct Unk_7ecc90_Con;
struct Unk_7fe1d0;
struct Unk_7ca1c0;
struct Unk_7c58b0;
struct Unk_7eef40;
struct Unk_7f09c0;
struct Unk_82ccb0;
u8 Unk_7cc000(void* self, u8 index);
u8 Unk_7cb490(u8 position);
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);
u32 Unk_7c58b0_get(const Unk_7c58b0* self);
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
Unk_7ee6b0* Unk_7ed1e0(Unk_7ecc90_Con* self, u8 pokeId);
u16 Unk_7eef40_getField70(const Unk_7eef40* self);
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u8 Unk_82ccb0_getFieldb48(const Unk_82ccb0* self);
bool Unk_81af00(u16 species, u16 item);

// One of the entries of the Pokemon's list (self->field_10): the Pokemon,
// and a flag.
struct Unk_82ce80_Entry {
    Unk_7ee6b0* field_0;
    u8 _8[0x59 - 0x8];
    u8 field_59;
};
PKMN_OFFSET_ASSERT(Unk_82ce80_Entry, field_59, 0x59);
Unk_82ce80_Entry* Unk_82ce80(void* self, u32 index);

// The event's targets: a count in variable 5, the Pokemon from variable 6
// (as in Unk_819600.cpp).
static inline u8 Unk_81ad70_Target(const Unk_819600_Self* self, u8 index) {
    void* event = self->field_30;
    if (index < Unk_7e9830(event, 5))
        return Unk_7e9830(event, 6 + index);
    return 0x1f;
}

// 0x710081ad70
// NON_MATCHING: Unk_7e9830's label is a u16 (as Unk_7e95a0's is): declared so,
// the index is zero-extended twice (no register kept for it) and this matches
bool Unk_81ad70(const Unk_819600_Self* self, u8 pokeId) {
    u32 count = Unk_7e9830(self->field_30, 5);
    for (u32 i = 0; i < count; i++) {
        u8 target = Unk_81ad70_Target(self, i);
        if (Unk_7cc000(const_cast<void*>(self->field_0), target) == pokeId)
            return true;
    }
    return false;
}

// 0x710081ae20
bool Unk_81ae20(const Unk_819600_Self* self, u8 pokeId) {
    u32 flagged = 0;
    u32 others = 0;
    for (u8 i = 0; i < Unk_82ccb0_getFieldb48(static_cast<const Unk_82ccb0*>(self->field_10));
         i++) {
        Unk_82ce80_Entry* entry = Unk_82ce80(const_cast<void*>(self->field_10), i);
        if (entry->field_0 != nullptr && Unk_7ee6b0_getField7d(entry->field_0) != pokeId) {
            others++;
            if (entry->field_59 != 0)
                flagged++;
        }
    }
    return others == flagged;
}

// 0x710081b100
bool Unk_81b100(const Unk_819600_Self* self, u8 pokeId, u8 otherId) {
    if (Unk_7ca1c0_getField150(static_cast<const Unk_7ca1c0*>(self->field_0)) != 2 &&
        Unk_7c58b0_get(static_cast<const Unk_7c58b0*>(self->field_0)) == 0) {
        u8 side = Unk_7cb490(pokeId);
        if (side == 1 || side == 3)
            return true;
    }
    Unk_7ee6b0* other =
        Unk_7ed1e0(Unk_7fe1d0_getField8(static_cast<const Unk_7fe1d0*>(self->field_8)), otherId);
    if (Unk_81af00(Unk_7eef40_getField70(reinterpret_cast<const Unk_7eef40*>(other)),
                   Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(other))))
        return true;
    Unk_7ee6b0* poke =
        Unk_7ed1e0(Unk_7fe1d0_getField8(static_cast<const Unk_7fe1d0*>(self->field_8)), pokeId);
    other =
        Unk_7ed1e0(Unk_7fe1d0_getField8(static_cast<const Unk_7fe1d0*>(self->field_8)), otherId);
    u16 species = Unk_7eef40_getField70(reinterpret_cast<const Unk_7eef40*>(poke));
    return Unk_81af00(species, Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(other)));
}
