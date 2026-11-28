// Scope: common
// Battle server commands (0x7100816ff0 to 0x71008174b0), next to the ones in
// Unk_8139c0.cpp: each looks up what it acts on through the main module and
// calls its member functions. Placeholder names: rename once they are known.
#include "battle/battle_engine/Unk_8139c0.h"

// The field state the main module's +0x28 holds (Unk_7ffb00.cpp).
bool Unk_7ffd80(Unk_7ee6b0_Field* self, u32 slot);
bool Unk_8000b0(Unk_7ee6b0_Field* self, u32 slot);

// The battle Pokemon's member functions.
bool Unk_7f2770(Unk_7ee6b0* self, u32 value);
void Unk_7f3090(Unk_7ee6b0* self, u8 count);
struct Unk_7f2370;
void Unk_7f2370_setField338(Unk_7f2370* self, u16 value);
void Unk_7f1940(Unk_7ee6b0* self, u16 value);
void Unk_7f2020(Unk_7ee6b0* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

// A client's party and the server's position table (Unk_7fc210.cpp,
// src/unsorted/unk_82e410/Unk_802dd0.cpp).
void Unk_7fc470(Unk_7fc430_Party* self, u8 index, u8 other);
u8 Unk_7c9b60(void* self, u8 client, u32 index);
struct Unk_802dd0_Self;
void Unk_803080(Unk_802dd0_Self* self, void* main, u8 index, u8 pokeId, Unk_7ecc90_Con* con);

// NON_MATCHING: the existing name gives Unk_7c9b60's index as a u32, so clang
// passes the zero-extended copy of index and allocates registers differently;
// the original passes it as a u8, and with a u8 declaration this matches
// (RENAME _Z10Unk_7c9b60Pvhj -> _Z10Unk_7c9b60Pvhh).
// 0x7100816ff0
void Unk_816ff0(const Unk_8139c0_Self* self, u8 client, u8 index, u8 other, u32 value) {
    Unk_7fc430_Party* party = Unk_7ed1a0(Unk_7fe1d0_getField8(self->field_10), client);
    if (index != other)
        Unk_7fc470(party, index, other);
    Unk_7ee6b0* poke = const_cast<Unk_7ee6b0*>(Unk_7fc430(party, index));
    Unk_7f1940(poke, value);
    Unk_7f2020(poke);
    u8 position = Unk_7c9b60(self->field_8, client, index);
    Unk_803080(static_cast<Unk_802dd0_Self*>(
                   Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_10))),
               self->field_8, position, Unk_7ee6b0_getField7d(poke),
               Unk_7fe1d0_getField8(self->field_10));
}

static inline Unk_7ee6b0_Field* Unk_816f90_Field(const Unk_8139c0_Self* self) {
    return static_cast<Unk_7ee6b0_Field*>(
        Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_10)));
}

// 0x7100817130
void Unk_817130(const Unk_8139c0_Self* self, u32 slot) {
    Unk_7ffd80(Unk_816f90_Field(self), slot);
}

// 0x7100817160
void Unk_817160(const Unk_8139c0_Self* self, u32 slot) {
    Unk_8000b0(Unk_816f90_Field(self), slot);
}

// 0x7100817270
void Unk_817270(const Unk_8139c0_Self* self, u8 pokeId, u32 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2770(poke, value);
}

// 0x7100817370
void Unk_817370(const Unk_8139c0_Self* self, u8 pokeId, u8 count) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f3090(poke, count);
}

// 0x71008174b0
void Unk_8174b0(const Unk_8139c0_Self* self, u8 pokeId, u16 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2370_setField338(reinterpret_cast<Unk_7f2370*>(poke), value);
}
