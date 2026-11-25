// Scope: common
// Battle event helpers (0x710081bf40-0x710081c3a0): checks on a Pokemon and
// its side, asked through the main module (+0) and the battle's lookups (+8),
// as in src/battle/battle_engine/Unk_81aae0.cpp. Placeholder names.
#include "unsorted/unk_82e410/Handler.h"

// What the battle's event handlers are given, as in
// src/battle/battle_engine/Unk_81a030.h, with the field at +0x28 too.
struct Unk_819600_Self {
    const void* field_0;
    const void* field_8;
    const void* field_10;
    const void* field_18;
    const void* field_20;
    const void* field_28;
    void* field_30;
    u8 _38[0x40 - 0x38];
    void* field_40;
};
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_40, 0x40);

struct Unk_7c2d80_Main;
struct Unk_7ecc90_Con;
struct Unk_7fc430_Party;
struct Unk_7ee6b0;
struct Unk_7ee6b0_Field;

// The main module's (src/battle/battle_engine/Unk_7c2d80.cpp and its leaf
// getters in src/unsorted/leaf/Unk_7c2d90.cpp, each with its own type).
struct Unk_7ca1c0;
struct Unk_7ca890;
struct Unk_7caa70;
struct Unk_7caaf0;
struct Unk_7cb2c0;
struct Unk_7cb850;
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);
u8 Unk_7ca890_get(const Unk_7ca890* self);
bool Unk_7caa70_check(const Unk_7caa70* self);
bool Unk_7caaf0_check(const Unk_7caaf0* self);
u8 Unk_7cb2c0_call(const Unk_7cb2c0* self, u8 value);
u8 Unk_7cb850_getField174(const Unk_7cb850* self);
u8 Unk_7cb490(u8 pokeId);
void Unk_7cbcf0(Unk_7c2d80_Main* self, u32 amount);
void Unk_7cbd20(Unk_7c2d80_Main* self, u32 index);
bool Unk_7cbf80(void* self, u8 pokeId, u8 otherId);
bool Unk_7cad50(const Unk_7c2d80_Main* self, u8 position);

// The battle's lookups (+8): leaf getters with their own placeholder types
// (src/unsorted/leaf/Unk_7fe1d0.cpp), the Pokemon container's lookups
// (src/battle/battle_engine/Unk_7ecc90.cpp) and the Pokemon's.
struct Unk_7fe1d0;
struct Unk_7fe1e0;
struct Unk_7fe250;
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
const Unk_7ee6b0_Field* Unk_7fe1e0_getField28(const Unk_7fe1e0* self);
void* Unk_7fe250_getFielda8(const Unk_7fe250* self);
const Unk_7fc430_Party* Unk_7ed1b0(const Unk_7ecc90_Con* self, u32 client);
Unk_7ee6b0* Unk_7ed1e0(Unk_7ecc90_Con* self, u8 pokeId);
u8 Unk_7fc350(const Unk_7fc430_Party* self, u8 start);
u8 Unk_803600(void* self, u8 id);
struct Unk_7ef330;
struct Unk_7f09c0;
void* Unk_7ef330_getField60(const Unk_7ef330* self);
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u32 Unk_7eef50(void* self, u32 value);
bool Unk_7ef4c0(const Unk_7ee6b0* poke, u32 condition);
bool Unk_7ffe20(const Unk_7ee6b0_Field* self, u32 effect);
bool Unk_767da0(void* object);

// Elsewhere in the battle engine.
u8 Unk_84f4e0(const void* self, u32 client);
struct Unk_7f98e0_Arg;
void Unk_7f98e0(const Unk_7f98e0_Arg* arg, u32 rule, u8 value, Unk_7ecc90_Con* con, void* out);
struct Unk_82b4f0;
u64 Unk_82b4f0_getField8(const Unk_82b4f0* self);
u8* Unk_82afd0(void* self);
void Unk_812e40(unsigned long self, unsigned long value);

namespace {

const Unk_7c2d80_Main* Main(const Unk_819600_Self* self) {
    return static_cast<const Unk_7c2d80_Main*>(self->field_0);
}

Unk_7c2d80_Main* MutableMain(const Unk_819600_Self* self) {
    return const_cast<Unk_7c2d80_Main*>(Main(self));
}

Unk_7ecc90_Con* Con(const Unk_819600_Self* self) {
    return Unk_7fe1d0_getField8(static_cast<const Unk_7fe1d0*>(self->field_8));
}

}  // namespace

// 0x710081bf40
u8 Unk_81bf40(const Unk_819600_Self* self, u8 pokeId) {
    u8 position =
        Unk_803600(Unk_7fe250_getFielda8(static_cast<const Unk_7fe250*>(self->field_8)), pokeId);
    if (!Unk_7cad50(Main(self), position))
        return 5;
    return position;
}

// 0x710081bf90
bool Unk_81bf90(const Unk_819600_Self* self, u8 pokeId) {
    const Unk_7ee6b0* poke = Unk_7ed1e0(Con(self), pokeId);
    return Unk_767da0(Unk_7ef330_getField60(reinterpret_cast<const Unk_7ef330*>(poke)));
}

// 0x710081bfc0
bool Unk_81bfc0(const Unk_819600_Self* self, u8 pokeId) {
    Unk_7ee6b0* poke = Unk_7ed1e0(Con(self), pokeId);
    if (Unk_7eef50(poke, 0x13) == 0x67)
        return false;
    if (Unk_7ef4c0(poke, 0x13))
        return false;
    return !Unk_7ffe20(Unk_7fe1e0_getField28(static_cast<const Unk_7fe1e0*>(self->field_8)), 5);
}

// 0x710081c060
u16 Unk_81c060(const Unk_819600_Self* self, u8 pokeId) {
    if (!Unk_81bfc0(self, pokeId))
        return 0;
    return Unk_7f09c0_getField76(
        reinterpret_cast<const Unk_7f09c0*>(Unk_7ed1e0(Con(self), pokeId)));
}

// 0x710081c100
u8 Unk_81c100(const Unk_819600_Self* self, u8 pokeId, u8* out) {
    void* poke;
    Unk_804200_Iterator it;
    Unk_804200(&it, const_cast<void*>(self->field_0), const_cast<void*>(self->field_8));
    u8 count = 0;
    while (Unk_804480(&it, &poke)) {
        if (!Unk_7cbf80(const_cast<void*>(self->field_0), pokeId,
                        Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(poke))))
            out[count++] = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(poke));
    }
    return count;
}

// 0x710081c1b0
void Unk_81c1b0(const Unk_819600_Self* self, const Unk_7f98e0_Arg* arg, void* out) {
    u32 rule = Unk_7ca1c0_getField150(static_cast<const Unk_7ca1c0*>(self->field_0));
    u8 value = Unk_7ca890_get(static_cast<const Unk_7ca890*>(self->field_0));
    Unk_7f98e0(arg, rule, value, Con(self), out);
}

// 0x710081c220
// NON_MATCHING: a load is scheduled before the mask of the call's argument
// (the original masks first); otherwise the same.
bool Unk_81c220(const Unk_819600_Self* self, u8 pokeId) {
    u8 side = Unk_7cb490(pokeId);
    u8 count = Unk_84f4e0(self->field_18, side);
    u32 client = Unk_7cb490(pokeId);
    const Unk_7fc430_Party* party = Unk_7ed1b0(Con(self), client);
    u8 position = Unk_7cb490(pokeId);
    u8 start = Unk_7cb2c0_call(static_cast<const Unk_7cb2c0*>(self->field_0), position);
    return count < Unk_7fc350(party, start);
}

// 0x710081c2b0
bool Unk_81c2b0(const Unk_819600_Self* self, u32 amount) {
    if (!Unk_7caaf0_check(static_cast<const Unk_7caaf0*>(self->field_0)))
        return false;
    Unk_7cbcf0(MutableMain(self), amount);
    return true;
}

// 0x710081c300
void Unk_81c300(const Unk_819600_Self* self, u8 pokeId, u32 index) {
    if (Unk_7caa70_check(static_cast<const Unk_7caa70*>(self->field_0)) &&
        Unk_7cb490(pokeId) == Unk_7cb850_getField174(static_cast<const Unk_7cb850*>(self->field_0)))
        Unk_7cbd20(MutableMain(self), index);
}

// 0x710081c370
void Unk_81c370(const Unk_819600_Self* self, u32 value) {
    u8* table = Unk_82afd0(reinterpret_cast<void*>(
        Unk_82b4f0_getField8(static_cast<const Unk_82b4f0*>(self->field_28))));
    Unk_812e40(reinterpret_cast<unsigned long>(table + 0x10), value);
}
