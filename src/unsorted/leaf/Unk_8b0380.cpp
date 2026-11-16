// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8b0380 {
    u8 _0[0x3450];
    u64 field_3450;
};
PKMN_OFFSET_ASSERT(Unk_8b0380, field_3450, 0x3450);

// 0x71008b0380
void Unk_8b0380_clearField3450(Unk_8b0380* self) {
    self->field_3450 = 0;
}

struct Unk_8b09f0 {
    u8 _0[0x3458];
    u32 field_3458;
};
PKMN_OFFSET_ASSERT(Unk_8b09f0, field_3458, 0x3458);

// 0x71008b09f0
void Unk_8b09f0_clearField3458(Unk_8b09f0* self) {
    self->field_3458 = 0;
}
