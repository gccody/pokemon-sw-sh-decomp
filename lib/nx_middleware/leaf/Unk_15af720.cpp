// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71015af720
void Unk_15af720_update() {
}

struct Unk_15b05a0_arg1 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15b05a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_15b05a0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15b05a0_arg1, field_18, 0x18);

struct Unk_15b05a0 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_15b05a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_15b05a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15b05a0, field_18, 0x18);

// 0x71015b05a0
void Unk_15b05a0_set(Unk_15b05a0* self, const Unk_15b05a0_arg1* value) {
    self->field_8 = value->field_8;
    self->field_10 = value->field_10;
    self->field_18 = value->field_18;
}
