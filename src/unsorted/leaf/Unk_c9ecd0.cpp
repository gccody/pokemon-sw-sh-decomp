// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c9ecd0 {
    u8 _0[0xa4];
    u32 field_a4;
};
PKMN_OFFSET_ASSERT(Unk_c9ecd0, field_a4, 0xa4);

// 0x7100c9ecd0
void Unk_c9ecd0_set(Unk_c9ecd0* self) {
    self->field_a4 = 0x2d;
}

struct Unk_ca07d0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ca07d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ca07d0_arg1, field_8, 0x8);

struct Unk_ca07d0 {
    u8 _0[0x80];
    u64 field_80;
    u64 field_88;
    u8 _90[0x24];
    u32 field_b4;
};
PKMN_OFFSET_ASSERT(Unk_ca07d0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_ca07d0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_ca07d0, field_b4, 0xb4);

// 0x7100ca07d0
void Unk_ca07d0_set(Unk_ca07d0* self, const Unk_ca07d0_arg1* value, u32 arg2) {
    self->field_88 = value->field_8;
    self->field_80 = value->field_0;
    self->field_b4 = arg2;
}

struct Unk_ca4e20 {
    u8 _0[0xf0];
    u32 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_ca4e20, field_f0, 0xf0);

// 0x7100ca4e20
bool Unk_ca4e20_check(const Unk_ca4e20* self) {
    return self->field_f0 == 2;
}
