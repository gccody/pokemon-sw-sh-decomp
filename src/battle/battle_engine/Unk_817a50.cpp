// Scope: common
// Battle server commands (0x7100817a50 to 0x7100817e30): each looks up a
// Pokemon or a part of the main module at +0x10 and calls one member
// function on it. Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_8139c0.h"

// The main module's getters, typed as src/unsorted/leaf/Unk_7fe1d0.cpp
// matches them.
struct Unk_7fe310;
struct Unk_7fe330;
void* Unk_7fe310_getField248(const Unk_7fe310* self);
void* Unk_7fe330_getField288(const Unk_7fe330* self);

// What they return, and the Pokemon's members called here.
struct Unk_7ffb60;
void Unk_7ffb60_set(Unk_7ffb60* self);
struct Unk_801870;
void Unk_801870_set(Unk_801870* self);
void Unk_7ff890(void* self, u16 index);
void Unk_7ff480(void* self, u8 index);
void Unk_8018c0(void* self, u32 index);
struct Unk_7f11b0;
void Unk_7f11b0_set(Unk_7f11b0* self);
void Unk_7f1cf0(Unk_7ee6b0* self);
struct Unk_7ef310;
void Unk_7ef310_setField342(Unk_7ef310* self, u8 value);

// 0x7100817a50
void Unk_817a50(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f11b0_set(reinterpret_cast<Unk_7f11b0*>(Unk_8139c0_Poke(self, pokeId)));
}

// 0x7100817bb0
void Unk_817bb0(const Unk_8139c0_Self* self, u8 pokeId, u8 value) {
    Unk_7ef310_setField342(reinterpret_cast<Unk_7ef310*>(Unk_8139c0_Poke(self, pokeId)), value);
}

// NON_MATCHING: the existing name gives Unk_817c40 no parameters, but it reads
// the server's +0x10 (RENAME _Z10Unk_817c40v -> _Z10Unk_817c40PK15Unk_8139c0_Self).
// 0x7100817c40
void Unk_817c40(const Unk_8139c0_Self* self) {
    Unk_7ffb60_set(static_cast<Unk_7ffb60*>(
        Unk_7fe1e0_getField28(reinterpret_cast<const Unk_7fe1e0*>(self->field_10))));
}

// 0x7100817c80
void Unk_817c80(const Unk_8139c0_Self* self, u16 index) {
    Unk_7ff890(Unk_7fe330_getField288(reinterpret_cast<const Unk_7fe330*>(self->field_10)), index);
}

// 0x7100817cb0
void Unk_817cb0(const Unk_8139c0_Self* self, u16 index) {
    Unk_7ff890(Unk_7fe330_getField288(reinterpret_cast<const Unk_7fe330*>(self->field_10)), index);
}

// 0x7100817ce0
void Unk_817ce0(const Unk_8139c0_Self* self, u8 index) {
    Unk_7ff480(Unk_7fe350_getField2a8(reinterpret_cast<const Unk_7fe350*>(self->field_10)), index);
}

// 0x7100817db0
void Unk_817db0(const Unk_8139c0_Self* self, u8 pokeId) {
    Unk_7f1cf0(Unk_8139c0_Poke(self, pokeId));
}

// NON_MATCHING: the existing name gives Unk_817de0 no parameters, but it reads
// the server's +0x10 (RENAME _Z10Unk_817de0v -> _Z10Unk_817de0PK15Unk_8139c0_Self).
// 0x7100817de0
void Unk_817de0(const Unk_8139c0_Self* self) {
    Unk_801870_set(static_cast<Unk_801870*>(
        Unk_7fe310_getField248(reinterpret_cast<const Unk_7fe310*>(self->field_10))));
}

// NON_MATCHING: the existing name takes a u8, but Unk_8018c0 uses the index as
// a u32, so clang zero-extends it first
// (RENAME _Z10Unk_817e00PK15Unk_8139c0_Selfh -> _Z10Unk_817e00PK15Unk_8139c0_Selfj).
// 0x7100817e00
void Unk_817e00(const Unk_8139c0_Self* self, u8 index) {
    Unk_8018c0(Unk_7fe310_getField248(reinterpret_cast<const Unk_7fe310*>(self->field_10)), index);
}
