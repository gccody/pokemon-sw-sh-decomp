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

struct Unk_7feb10_arg1 {
    u8 _0[0x10];
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_11, 0x11);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_13, 0x13);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_15, 0x15);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_17, 0x17);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_7feb10_arg1, field_19, 0x19);

struct Unk_7feb10 {
    u8 _0[0x10];
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_7feb10, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_11, 0x11);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_13, 0x13);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_15, 0x15);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_17, 0x17);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_7feb10, field_19, 0x19);

// 0x71007feb10
void Unk_7feb10_set(Unk_7feb10* self, const Unk_7feb10_arg1* value) {
    self->field_10 = value->field_10;
    self->field_11 = value->field_11;
    self->field_12 = value->field_12;
    self->field_13 = value->field_13;
    self->field_14 = value->field_14;
    self->field_15 = value->field_15;
    self->field_16 = value->field_16;
    self->field_17 = value->field_17;
    self->field_18 = value->field_18;
    self->field_19 = value->field_19;
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
