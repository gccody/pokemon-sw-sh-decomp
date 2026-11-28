// Scope: common
// Battle server commands (0x71008175f0 to 0x7100817a20), next to the ones in
// Unk_8139c0.cpp: each looks up a Pokemon through the main module and calls
// its member functions. Placeholder names: rename once they are known.
#include "battle/battle_engine/Unk_8139c0.h"

// The battle Pokemon's member functions (Unk_7ee6b0.cpp) and leaf functions
// on it with types of their own (src/unsorted/leaf/Unk_7ed7d0.cpp).
void Unk_7f2570(Unk_7ee6b0* self, u16 value);
struct Unk_7f2e60;
void Unk_7f2e60_call(Unk_7f2e60* self, u16 value);
struct Unk_7f1d10;
void Unk_7f1d10_clearField456(Unk_7f1d10* self);
bool Unk_7f10b0(Unk_7ee6b0* self);
bool Unk_7f11d0(Unk_7ee6b0* self);
bool Unk_7ef2b0_call(void* self);
void Unk_7f1400(u64 self, u32 flag);

// The server's position table and the main module's (Unk_7c2d80.cpp,
// src/unsorted/unk_82e410/Unk_802dd0.cpp).
void Unk_7fc470(Unk_7fc430_Party* self, u8 index, u8 other);
struct Unk_7c2d80_Main;
u8 Unk_7cb690(const Unk_7c2d80_Main* self, u8 position);
struct Unk_802dd0_Self;
void Unk_8032d0(Unk_802dd0_Self* self, u8 a, u8 b);

// 0x71008175f0
void Unk_8175f0(const Unk_8139c0_Self* self, u8 pokeId, u16 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2570(poke, value);
}

// 0x7100817630
void Unk_817630(const Unk_8139c0_Self* self, u8 client, u8 position, u8 otherPosition) {
    u8 index = Unk_7cb690(static_cast<const Unk_7c2d80_Main*>(self->field_8), position);
    u8 other = Unk_7cb690(static_cast<const Unk_7c2d80_Main*>(self->field_8), otherPosition);
    Unk_7fc430_Party* party = Unk_7ed1a0(Unk_7fe1d0_getField8(self->field_10), client);
    Unk_7fc470(party, index, other);
    Unk_7ee6b0* poke = const_cast<Unk_7ee6b0*>(Unk_7fc430(party, index));
    Unk_7ee6b0* otherPoke = const_cast<Unk_7ee6b0*>(Unk_7fc430(party, other));
    if (!Unk_7ef2b0_call(poke))
        Unk_7f1400(reinterpret_cast<u64>(poke), 0xc);
    if (!Unk_7ef2b0_call(otherPoke))
        Unk_7f1400(reinterpret_cast<u64>(otherPoke), 0xc);
    Unk_8032d0(static_cast<Unk_802dd0_Self*>(
                   Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_10))),
               position, otherPosition);
}

// 0x71008177f0
void Unk_8177f0(const Unk_8139c0_Self* self, u8 pokeId, u16 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2e60_call(reinterpret_cast<Unk_7f2e60*>(poke), value);
}

// 0x7100817830
void Unk_817830(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f1d10_clearField456(reinterpret_cast<Unk_7f1d10*>(Unk_8139c0_Poke(self, pokeId)));
}

// 0x71008179f0
void Unk_8179f0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f10b0(Unk_8139c0_Poke(self, pokeId));
}

// 0x7100817a20
void Unk_817a20(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f11d0(Unk_8139c0_Poke(self, pokeId));
}
