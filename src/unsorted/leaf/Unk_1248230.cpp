// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1248230 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1248230, field_a0, 0xa0);

void Unk_14b9450(u64);

// 0x7101248230
void Unk_1248230_call(const Unk_1248230* self) {
    Unk_14b9450(self->field_a0);
}

// 0x7101248240
void Unk_1248240() {}

struct Unk_1248250 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1248250, field_a0, 0xa0);

void Unk_14b9510(u64);

// 0x7101248250
void Unk_1248250_call(const Unk_1248250* self) {
    Unk_14b9510(self->field_a0);
}

struct Unk_1248260 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1248260, field_a0, 0xa0);

void Unk_14b95d0(u64);

// 0x7101248260
void Unk_1248260_call(const Unk_1248260* self) {
    Unk_14b95d0(self->field_a0);
}
