// Scope: common
// Battle server command wrappers: act on the server's state, then queue the
// command for the clients. Placeholder names: rename once they're known.
#include "unsorted/Unk_811d90.h"

struct Unk_8181d0;
void Unk_8181d0_call(const Unk_8181d0* self);

void Unk_818170(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8181a0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8181f0(const Unk_8139c0_Self* self);
bool Unk_818210(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818240(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8182e0(const Unk_8139c0_Self* self, u8 pokeId);

// 0x7100811d90
void Unk_811d90(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818170(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x58, pokeId);
}

// 0x7100811dd0
void Unk_811dd0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_8181a0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x59, pokeId);
}

// 0x7100811e10
void Unk_811e10(const Unk_811d90_Self* self, u32 value) {
    Unk_8181d0_call(reinterpret_cast<const Unk_8181d0*>(self->field_20));
    Unk_8150c0(self->field_18, 0x5a, value);
}

// 0x7100811e50
void Unk_811e50(const Unk_811d90_Self* self, u32 value) {
    Unk_8181f0(self->field_20);
    Unk_8150c0(self->field_18, 0x5b, value);
}

// 0x7100811e90
bool Unk_811e90(const Unk_811d90_Self* self, u8 pokeId) {
    bool result = Unk_818210(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x62, pokeId);
    return result;
}

// 0x7100811ee0
void Unk_811ee0(const Unk_811d90_Self* self, u8 pokeId) {
    Unk_818240(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x63, pokeId);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100811f20
void Unk_811f20(const Unk_811d90_Self* self, u8 pokeId, bool flag) {
    Unk_8150c0(self->field_18, 0xb3, pokeId, flag);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100811f40
void Unk_811f40(const Unk_811d90_Self* self, u8 pokeId, u8 value) {
    Unk_8182e0(self->field_20, pokeId);
    Unk_8150c0(self->field_18, 0x85, pokeId, value);
}

// 0x7100811f90
void Unk_811f90(const Unk_811d90_Self* self, u8 value) {
    Unk_8150c0(self->field_18, 0xb1, value);
}

// 0x7100811fa0
void Unk_811fa0(const Unk_811d90_Self* self, u8 value) {
    Unk_8150c0(self->field_18, 0xb2, value);
}

// 0x7100811fb0
void Unk_811fb0(const Unk_811d90_Self* self) {
    Unk_8150c0(self->field_18, 0xb0, 0);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100811fc0
void Unk_811fc0(const Unk_811d90_Self* self, u8 pokeId, bool flag) {
    Unk_8150c0(self->field_18, 0x8f, pokeId, flag);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100811fe0
void Unk_811fe0(const Unk_811d90_Self* self, u8 pokeId, bool flag) {
    Unk_8150c0(self->field_18, 0x87, pokeId, flag);
}

// 0x7100812000
void Unk_812000(const Unk_811d90_Self* self, u32 value) {
    Unk_8150c0(self->field_18, 0xa8, value);
}

// 0x7100812010
void Unk_812010(const Unk_811d90_Self* self) {
    Unk_8150c0(self->field_18, 0xad, 0);
}

// NON_MATCHING: only the callee's symbol differs: Unk_8150c0 is variadic, but
// functions.csv names it _Z10Unk_8150c0mjj. Matches as _Z10Unk_8150c0mjz.
// 0x7100812020
void Unk_812020(const Unk_811d90_Self* self, u8 pokeId, u32 value) {
    Unk_8150c0(self->field_18, 0xae, pokeId, value);
}
