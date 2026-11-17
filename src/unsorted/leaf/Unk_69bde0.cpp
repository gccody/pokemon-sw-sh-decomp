// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_69bde0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_69bde0, field_50, 0x50);

void Unk_69a540(u64);

// 0x710069bde0
void Unk_69bde0_call(const Unk_69bde0* self) {
    Unk_69a540(self->field_50);
}

struct Unk_69bdf0_50 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_69bdf0_50, field_b0, 0xb0);

struct Unk_69bdf0 {
    u8 _0[0x50];
    Unk_69bdf0_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69bdf0, field_50, 0x50);

// 0x710069bdf0
u8 Unk_69bdf0_get(const Unk_69bdf0* self) {
    return self->field_50->field_b0;
}

struct Unk_69c1e0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_69c1e0, field_50, 0x50);

void Unk_69b100(u64);

// 0x710069c1e0
void Unk_69c1e0_call(const Unk_69c1e0* self) {
    Unk_69b100(self->field_50);
}
