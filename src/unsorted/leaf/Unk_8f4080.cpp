// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8f4080_80 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_8f4080_80, field_58, 0x58);

struct Unk_8f4080 {
    u8 _0[0x80];
    Unk_8f4080_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_8f4080, field_80, 0x80);

// 0x71008f4080
void Unk_8f4080_set(const Unk_8f4080* self) {
    self->field_80->field_58 = self->field_80->field_58 | 1;
}

struct Unk_8f40a0_80 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_8f40a0_80, field_58, 0x58);

struct Unk_8f40a0 {
    u8 _0[0x80];
    Unk_8f40a0_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_8f40a0, field_80, 0x80);

// 0x71008f40a0
void Unk_8f40a0_set(const Unk_8f40a0* self) {
    self->field_80->field_58 = self->field_80->field_58 & 0xfe;
}
