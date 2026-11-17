// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7ff3e0 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_7ff3e0, field_80, 0x80);

// 0x71007ff3e0
void Unk_7ff3e0_set(Unk_7ff3e0* self) {
    self->field_78 = 0;
    self->field_80 = 0;
    self->field_68 = 0;
    self->field_70 = 0;
    self->field_58 = 0;
    self->field_60 = 0;
    self->field_48 = 0;
    self->field_50 = 0;
    self->field_38 = 0;
    self->field_40 = 0;
    self->field_28 = 0;
    self->field_30 = 0;
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
}

struct Unk_7ff5e0 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ff5e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ff5e0, field_8, 0x8);

// 0x71007ff5e0
void Unk_7ff5e0_set(Unk_7ff5e0* self) {
    self->field_0 = 0x505050500000000;
    self->field_8 = 5;
}

// 0x71007ff600
void Unk_7ff600() {}

struct Unk_7ff610 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ff610, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ff610, field_8, 0x8);

// 0x71007ff610
void Unk_7ff610_set(Unk_7ff610* self) {
    self->field_0 = 0x505050500000000;
    self->field_8 = 5;
}

struct Unk_7ff780_arg1 {
    u32 field_0;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ff780_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ff780_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ff780_arg1, field_5, 0x5);
PKMN_OFFSET_ASSERT(Unk_7ff780_arg1, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_7ff780_arg1, field_7, 0x7);
PKMN_OFFSET_ASSERT(Unk_7ff780_arg1, field_8, 0x8);

struct Unk_7ff780 {
    u32 field_0;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ff780, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ff780, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ff780, field_5, 0x5);
PKMN_OFFSET_ASSERT(Unk_7ff780, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_7ff780, field_7, 0x7);
PKMN_OFFSET_ASSERT(Unk_7ff780, field_8, 0x8);

// 0x71007ff780
void Unk_7ff780_set(const Unk_7ff780* self, Unk_7ff780_arg1* value) {
    value->field_0 = self->field_0;
    value->field_4 = self->field_4;
    value->field_5 = self->field_5;
    value->field_6 = self->field_6;
    value->field_7 = self->field_7;
    value->field_8 = self->field_8;
}
