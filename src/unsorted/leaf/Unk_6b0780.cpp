// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6b0780 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_6b0780, field_98, 0x98);

// 0x71006b0780
bool Unk_6b0780_check(const Unk_6b0780* self) {
    return self->field_98 != 0;
}

struct Unk_6b0b50 {
    u8 _0[0x98];
    u64 field_98;
    u8 _a0[0x58];
    u64 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_6b0b50, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_6b0b50, field_f8, 0xf8);

// 0x71006b0b50
void Unk_6b0b50_set(Unk_6b0b50* self) {
    self->field_98 = 0;
    self->field_f8 = 0;
}

struct Unk_6b2c10 {
    u8 _0[0x1f0];
    u32 field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_6b2c10, field_1f0, 0x1f0);

// 0x71006b2c10
void Unk_6b2c10_setField1f0(Unk_6b2c10* self, u32 value) {
    self->field_1f0 = value;
}

struct Unk_6b2c20 {
    u8 _0[0x4c8];
    u64 field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_6b2c20, field_4c8, 0x4c8);

// 0x71006b2c20
void Unk_6b2c20_clearField4c8(Unk_6b2c20* self) {
    self->field_4c8 = 0;
}
