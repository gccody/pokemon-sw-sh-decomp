// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_3043c0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u8 _18[0x10];
    u32 field_28;
    u8 _2c[0x24];
    u64 field_50;
    u64 field_58;
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_3043c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3043c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3043c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3043c0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_3043c0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_3043c0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_3043c0, field_60, 0x60);

// 0x71003043c0
void Unk_3043c0_set(Unk_3043c0* self) {
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_0 = 0;
    self->field_28 = 1;
    self->field_60 = 0;
    self->field_50 = 0;
    self->field_58 = 0;
}

// 0x71003045d0
u32 Unk_3045d0_get() {
    return 1;
}

extern u8 Unk_24bb9fc;
extern bool Unk_24bb9fd;

// 0x7100306990
void Unk_306990_set(bool self) {
    Unk_24bb9fc = 1;
    Unk_24bb9fd = self;
}
