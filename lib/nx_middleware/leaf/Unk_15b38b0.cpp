// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_15b38b0 {
    u8 _0[0x24];
    u32 field_24;
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b38b0, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_15b38b0, field_28, 0x28);

// 0x71015b38b0
void Unk_15b38b0_set(Unk_15b38b0* self, u32 value, u32 arg2) {
    self->field_24 = value;
    self->field_28 = arg2;
}

struct Unk_15b38c0 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_15b38c0, field_28, 0x28);

// 0x71015b38c0
u32 Unk_15b38c0_get(const Unk_15b38c0* self) {
    return self->field_28;
}

// 0x71015b3df0
void Unk_15b3df0_update() {
}

// 0x71015b3e00
void Unk_15b3e00_update() {
}
