// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e3c5e0_68 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_e3c5e0_68, field_170, 0x170);

struct Unk_e3c5e0 {
    u8 _0[0x68];
    Unk_e3c5e0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_e3c5e0, field_68, 0x68);

// 0x7100e3c5e0
u8 Unk_e3c5e0_get(const Unk_e3c5e0* self) {
    if (self->field_68 == nullptr) {
        return 0;
    }
    return self->field_68->field_170;
}

struct Unk_e3cdc0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e3cdc0, field_60, 0x60);

// 0x7100e3cdc0
void Unk_e3cdc0_clearField60(Unk_e3cdc0* self) {
    self->field_60 = 0;
}
