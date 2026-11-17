// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7fead0 {
    u8 _0[0x10];
    u64 field_10;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7fead0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7fead0, field_18, 0x18);

// 0x71007fead0
void Unk_7fead0_set(Unk_7fead0* self) {
    self->field_18 = 0;
    self->field_10 = 0;
}

struct Unk_7feb70 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7feb70, field_8, 0x8);

// 0x71007feb70
void Unk_7feb70_setField8(Unk_7feb70* self, u64 value) {
    self->field_8 = value;
}
