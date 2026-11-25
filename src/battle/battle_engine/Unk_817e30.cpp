// Scope: common
// Battle server commands (0x7100817e30 to 0x71008181a0): each looks up a
// Pokemon or a part of the main module at +0x10 and calls one member
// function on it. Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_8139c0.h"

// The main module's getter, typed as src/unsorted/leaf/Unk_7fe1d0.cpp
// matches it, and the members called here.
struct Unk_7fe310;
void* Unk_7fe310_getField248(const Unk_7fe310* self);
void Unk_8018f0(void* self, u32 index);
void Unk_7f31f0(Unk_7ee6b0* self);
void Unk_7f33e0(Unk_7ee6b0* self);
void Unk_7f3500(Unk_7ee6b0* self);

// NON_MATCHING: the existing name takes a u8, but Unk_8018f0 uses the index as
// a u32, so clang zero-extends it first
// (RENAME _Z10Unk_817e30PK15Unk_8139c0_Selfh -> _Z10Unk_817e30PK15Unk_8139c0_Selfj).
// 0x7100817e30
void Unk_817e30(const Unk_8139c0_Self* self, u8 index) {
    Unk_8018f0(Unk_7fe310_getField248(reinterpret_cast<const Unk_7fe310*>(self->field_10)), index);
}

// 0x7100818140
void Unk_818140(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f31f0(Unk_8139c0_Poke(self, pokeId));
}

// 0x7100818170
void Unk_818170(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f33e0(Unk_8139c0_Poke(self, pokeId));
}

// 0x71008181a0
void Unk_8181a0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f3500(Unk_8139c0_Poke(self, pokeId));
}
