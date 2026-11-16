// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e43c20
void Unk_e43c20() {}

// 0x7100e4cc50
void Unk_e4cc50() {}

struct Unk_e51bf0 {
    u8 _0[0x1c8];
    u8 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_e51bf0, field_1c8, 0x1c8);

// 0x7100e51bf0
void Unk_e51bf0_setField1c8(Unk_e51bf0* self, u8 value) {
    self->field_1c8 = value;
}

struct Unk_e51c00 {
    u8 _0[0x1c9];
    u8 field_1c9;
};
PKMN_OFFSET_ASSERT(Unk_e51c00, field_1c9, 0x1c9);

// 0x7100e51c00
void Unk_e51c00_setField1c9(Unk_e51c00* self, u8 value) {
    self->field_1c9 = value;
}
