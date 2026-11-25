// Scope: common
// More of the battle server's commands (see Unk_8139c0.cpp): each looks up a
// battle Pokemon by id and calls one of its member functions. Placeholder
// names: rename once the functions are known.
#include "battle/battle_engine/Unk_8139c0.h"

// The battle Pokemon's member functions (src/battle/battle_engine/Unk_7ee6b0.cpp)
// and leaf functions on it with types of their own (src/unsorted/leaf/Unk_7ed7d0.cpp).
struct Unk_7f0a80;
void Unk_7f0a80_set(Unk_7f0a80* self);
struct Unk_7f13b0;
void Unk_7f13b0_set(Unk_7f13b0* self, u16 value);
bool Unk_7ef2b0_call(void* self);
void Unk_7ef260(Unk_7ee6b0* self, u8 arg1, u8 arg2);
struct Unk_7f09d0;
void Unk_7f09d0_setField76(Unk_7f09d0* self, u16 value);
struct Unk_7f2490;
void Unk_7f2490_set(Unk_7f2490* self, u16 value);
struct Unk_7f24a0;
void Unk_7f24a0_clearField78(Unk_7f24a0* self);
void Unk_7f1530(Unk_7ee6b0* self);
void Unk_7f1820(void* self, u32 value);
void Unk_7f18b0(Unk_7ee6b0* self, u8 pokeId);

// 0x7100816b90
void Unk_816b90(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f0a80_set(reinterpret_cast<Unk_7f0a80*>(Unk_8139c0_Poke(self, pokeId)));
}

// 0x7100816c00
// NON_MATCHING: Unk_7ef2b0 is named with no parameters (_Z10Unk_7ef2b0v), but
// the original passes it the Pokemon; this calls the leaf's Unk_7ef2b0_call.
void Unk_816c00(const Unk_8139c0_Self* self, u8 pokeId, u32 value, u32 arg3, u8 arg4) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f13b0_set(reinterpret_cast<Unk_7f13b0*>(poke), value);
    if (Unk_7ef2b0_call(poke))
        Unk_7ef260(poke, arg3, arg4);
}

// 0x7100816e00
void Unk_816e00(const Unk_8139c0_Self* self, u8 pokeId, u16 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f09d0_setField76(reinterpret_cast<Unk_7f09d0*>(poke), value);
}

// 0x7100816e40
void Unk_816e40(const Unk_8139c0_Self* self, u8 pokeId, u16 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f2490_set(reinterpret_cast<Unk_7f2490*>(poke), value);
}

// 0x7100816e80
void Unk_816e80(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f24a0_clearField78(reinterpret_cast<Unk_7f24a0*>(Unk_8139c0_Poke(self, pokeId)));
}

// 0x7100816eb0
void Unk_816eb0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f1530(Unk_8139c0_Poke(self, pokeId));
}

// 0x7100816ee0
void Unk_816ee0(const Unk_8139c0_Self* self, u8 pokeId, u32 value) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f1820(poke, value);
}

// 0x7100816f20
void Unk_816f20(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f18b0(poke, otherId);
}
