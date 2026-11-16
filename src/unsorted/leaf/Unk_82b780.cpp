// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82b780 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b780, field_0, 0x0);

// 0x710082b780
void Unk_82b780_clearField0(Unk_82b780* self) {
    self->field_0 = 0;
}

struct Unk_82b790 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b790, field_0, 0x0);

// 0x710082b790
void Unk_82b790_clearField0(Unk_82b790* self) {
    self->field_0 = 0;
}

struct Unk_82b7a0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b7a0, field_0, 0x0);

// 0x710082b7a0
void Unk_82b7a0_setField0(Unk_82b7a0* self, u8 value) {
    self->field_0 = value;
}

struct Unk_82b7d0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b7d0, field_0, 0x0);

// 0x710082b7d0
u8 Unk_82b7d0_getField0(const Unk_82b7d0* self) {
    return self->field_0;
}
