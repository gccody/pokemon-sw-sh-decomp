// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fcd060 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_fcd060, field_700, 0x700);

// 0x7100fcd060
void Unk_fcd060_setField700(Unk_fcd060* self, u64 value) {
    self->field_700 = value;
}

struct Unk_fcec80_738 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_fcec80_738, field_58, 0x58);

struct Unk_fcec80 {
    u8 _0[0x738];
    Unk_fcec80_738* field_738;
};
PKMN_OFFSET_ASSERT(Unk_fcec80, field_738, 0x738);

// 0x7100fcec80
void Unk_fcec80_set(const Unk_fcec80* self) {
    self->field_738->field_58 = self->field_738->field_58 | 1;
}

struct Unk_fcfee0_718 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_fcfee0_718, field_58, 0x58);

struct Unk_fcfee0 {
    u8 _0[0x718];
    Unk_fcfee0_718* field_718;
};
PKMN_OFFSET_ASSERT(Unk_fcfee0, field_718, 0x718);

// 0x7100fcfee0
void Unk_fcfee0_set(const Unk_fcfee0* self) {
    self->field_718->field_58 = self->field_718->field_58 & 0xfe;
}

struct Unk_fd3e20 {
    u8 _0[0xb30];
    u32 field_b30;
    u8 field_b34;
};
PKMN_OFFSET_ASSERT(Unk_fd3e20, field_b30, 0xb30);
PKMN_OFFSET_ASSERT(Unk_fd3e20, field_b34, 0xb34);

// 0x7100fd3e20
void Unk_fd3e20_set(Unk_fd3e20* self) {
    self->field_b30 = 0x3e7;
    self->field_b34 = 0;
}

struct Unk_fd43c0 {
    u8 _0[0x6f8];
    u32 field_6f8;
};
PKMN_OFFSET_ASSERT(Unk_fd43c0, field_6f8, 0x6f8);

// 0x7100fd43c0
bool Unk_fd43c0_check(const Unk_fd43c0* self) {
    return self->field_6f8 == 5;
}

struct Unk_fd4770 {
    u8 _0[0xb30];
    u64 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_fd4770, field_b30, 0xb30);

// 0x7100fd4770
u64 Unk_fd4770_getFieldb30(const Unk_fd4770* self) {
    return self->field_b30;
}
