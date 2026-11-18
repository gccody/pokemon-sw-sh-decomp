// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_503270 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u8 _18[0x10];
    u64 field_28;
    u64 field_30;
    u8 _38[0x8];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_503270, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_503270, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_503270, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_503270, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_503270, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_503270, field_40, 0x40);

// 0x7100503270
void Unk_503270_set(Unk_503270* self, u64 value, u64 arg2) {
    self->field_0 = value;
    self->field_8 = arg2;
    self->field_10 = 0;
    self->field_40 = 0;
    self->field_28 = 0;
    self->field_30 = 0;
}

struct Unk_507f30 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_507f30, field_10, 0x10);

// 0x7100507f30
u64 Unk_507f30_get(const Unk_507f30* self) {
    return self->field_10;
}

// 0x710050ae50
void Unk_50ae50_update() {
}
