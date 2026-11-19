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

// 0x7100fcd740
void Unk_fcd740_update() {}

struct Unk_fcd750_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fcd750_arg1, field_0, 0x0);

struct Unk_fcd750 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fcd750, field_0, 0x0);

// 0x7100fcd750
void Unk_fcd750_set(const Unk_fcd750* self, Unk_fcd750_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fcd760_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fcd760_arg1, field_0, 0x0);

struct Unk_fcd760 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fcd760, field_0, 0x0);

// 0x7100fcd760
void Unk_fcd760_set(const Unk_fcd760* self, Unk_fcd760_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fce9c0 {
    u8 _0[0x750];
    u64 field_750;
};
PKMN_OFFSET_ASSERT(Unk_fce9c0, field_750, 0x750);

void Unk_14bd880(u64, u32);

// 0x7100fce9c0
void Unk_fce9c0_call(const Unk_fce9c0* self, u32 value) {
    Unk_14bd880(self->field_750, value);
}

struct Unk_fce9d0 {
    u8 _0[0x750];
    u64 field_750;
};
PKMN_OFFSET_ASSERT(Unk_fce9d0, field_750, 0x750);

void Unk_14bd880(u64, u32);

// 0x7100fce9d0
void Unk_fce9d0_call(const Unk_fce9d0* self, u32 value) {
    Unk_14bd880(self->field_750, (value & 0xff) + 6);
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

struct Unk_fcff00_710 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_fcff00_710, field_58, 0x58);

struct Unk_fcff00 {
    u8 _0[0x710];
    Unk_fcff00_710* field_710;
};
PKMN_OFFSET_ASSERT(Unk_fcff00, field_710, 0x710);

void Unk_fcd070();

// 0x7100fcff00
void Unk_fcff00_call(const Unk_fcff00* self) {
    if ((self->field_710->field_58 & 1) == 0) {
        self->field_710->field_58 = self->field_710->field_58 | 1;
        Unk_fcd070();
    }
}

struct Unk_fcff20_718 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_fcff20_718, field_58, 0x58);

struct Unk_fcff20 {
    u8 _0[0x718];
    Unk_fcff20_718* field_718;
};
PKMN_OFFSET_ASSERT(Unk_fcff20, field_718, 0x718);

void Unk_fcd070();

// 0x7100fcff20
void Unk_fcff20_call(const Unk_fcff20* self) {
    if ((self->field_718->field_58 & 1) == 0) {
        self->field_718->field_58 = self->field_718->field_58 | 1;
        Unk_fcd070();
    }
}

struct Unk_fd15c0 {
    u8 _0[0x730];
    u64 field_730;
};
PKMN_OFFSET_ASSERT(Unk_fd15c0, field_730, 0x730);

void Unk_14e1b40(u64);
void Unk_fcd580(void*, u32);

// 0x7100fd15c0
void Unk_fd15c0_call(Unk_fd15c0* self) {
    Unk_fcd580(self, 0);
    Unk_14e1b40(self->field_730);
}

struct Unk_fd35b0_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_fd35b0_0, field_4c0, 0x4c0);

struct Unk_fd35b0 {
    Unk_fd35b0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd35b0, field_0, 0x0);

void Unk_1500c40(u64);

// 0x7100fd35b0
void Unk_fd35b0_call(const Unk_fd35b0* self) {
    if (self->field_0->field_4c0 != 0) {
        Unk_1500c40(self->field_0->field_4c0);
    }
}

// 0x7100fd35d0
void Unk_fd35d0_update() {}

struct Unk_fd35e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd35e0_arg1, field_0, 0x0);

struct Unk_fd35e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd35e0, field_0, 0x0);

// 0x7100fd35e0
void Unk_fd35e0_set(const Unk_fd35e0* self, Unk_fd35e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fd35f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd35f0_arg1, field_0, 0x0);

struct Unk_fd35f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd35f0, field_0, 0x0);

// 0x7100fd35f0
void Unk_fd35f0_set(const Unk_fd35f0* self, Unk_fd35f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fd3600_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_fd3600_0, field_4c0, 0x4c0);

struct Unk_fd3600 {
    Unk_fd3600_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3600, field_0, 0x0);

void Unk_1500c40(u64);

// 0x7100fd3600
void Unk_fd3600_call(const Unk_fd3600* self) {
    if (self->field_0->field_4c0 != 0) {
        Unk_1500c40(self->field_0->field_4c0);
    }
}

// 0x7100fd3620
void Unk_fd3620_update() {}

struct Unk_fd3630_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3630_arg1, field_0, 0x0);

struct Unk_fd3630 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3630, field_0, 0x0);

// 0x7100fd3630
void Unk_fd3630_set(const Unk_fd3630* self, Unk_fd3630_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fd3640_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3640_arg1, field_0, 0x0);

struct Unk_fd3640 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3640, field_0, 0x0);

// 0x7100fd3640
void Unk_fd3640_set(const Unk_fd3640* self, Unk_fd3640_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fd3660
void Unk_fd3660_update() {}

struct Unk_fd3670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3670_arg1, field_0, 0x0);

struct Unk_fd3670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3670, field_0, 0x0);

// 0x7100fd3670
void Unk_fd3670_set(const Unk_fd3670* self, Unk_fd3670_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fd3680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3680_arg1, field_0, 0x0);

struct Unk_fd3680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3680, field_0, 0x0);

// 0x7100fd3680
void Unk_fd3680_set(const Unk_fd3680* self, Unk_fd3680_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fd36a0
void Unk_fd36a0_update() {}

struct Unk_fd36b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd36b0_arg1, field_0, 0x0);

struct Unk_fd36b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd36b0, field_0, 0x0);

// 0x7100fd36b0
void Unk_fd36b0_set(const Unk_fd36b0* self, Unk_fd36b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fd36c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd36c0_arg1, field_0, 0x0);

struct Unk_fd36c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd36c0, field_0, 0x0);

// 0x7100fd36c0
void Unk_fd36c0_set(const Unk_fd36c0* self, Unk_fd36c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fd36e0
void Unk_fd36e0_update() {}

struct Unk_fd36f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd36f0_arg1, field_0, 0x0);

struct Unk_fd36f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd36f0, field_0, 0x0);

// 0x7100fd36f0
void Unk_fd36f0_set(const Unk_fd36f0* self, Unk_fd36f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fd3700_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3700_arg1, field_0, 0x0);

struct Unk_fd3700 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3700, field_0, 0x0);

// 0x7100fd3700
void Unk_fd3700_set(const Unk_fd3700* self, Unk_fd3700_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fd3720
void Unk_fd3720_update() {}

struct Unk_fd3730_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3730_arg1, field_0, 0x0);

struct Unk_fd3730 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3730, field_0, 0x0);

// 0x7100fd3730
void Unk_fd3730_set(const Unk_fd3730* self, Unk_fd3730_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fd3740_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3740_arg1, field_0, 0x0);

struct Unk_fd3740 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fd3740, field_0, 0x0);

// 0x7100fd3740
void Unk_fd3740_set(const Unk_fd3740* self, Unk_fd3740_arg1* value) {
    value->field_0 = self->field_0;
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
