// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ac5d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u16 field_18;
    u8 field_1a;
    u8 _1b[0x5];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_1a, 0x1a);
PKMN_OFFSET_ASSERT(Unk_8ac5d0, field_20, 0x20);

// 0x71008ac5d0
void Unk_8ac5d0_set(Unk_8ac5d0* self) {
    self->field_20 = 0;
    self->field_1a = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
}
