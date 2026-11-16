// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

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
