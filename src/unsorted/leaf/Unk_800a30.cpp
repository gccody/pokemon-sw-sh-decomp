// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_800a30 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 field_14;
    u8 _15[0x3];
    u32 field_18;
    u8 field_1c;
    u8 _1d[0x3];
    u32 field_20;
    u8 field_24;
    u8 _25[0x3];
    u32 field_28;
    u8 field_2c;
    u8 _2d[0x3];
    u32 field_30;
    u8 field_34;
    u8 _35[0x3];
    u16 field_38;
    u8 _3a[0x2];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_800a30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_800a30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_800a30, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_800a30, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_800a30, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_800a30, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_800a30, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_800a30, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_800a30, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_800a30, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_800a30, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_800a30, field_34, 0x34);
PKMN_OFFSET_ASSERT(Unk_800a30, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_800a30, field_3c, 0x3c);

// 0x7100800a30
void Unk_800a30_set(Unk_800a30* self, u64 value, u64 arg2) {
    self->field_0 = value;
    self->field_8 = arg2;
    self->field_10 = 5;
    self->field_14 = 0;
    self->field_18 = 5;
    self->field_1c = 0;
    self->field_20 = 5;
    self->field_24 = 0;
    self->field_28 = 5;
    self->field_2c = 0;
    self->field_30 = 5;
    self->field_34 = 0;
    self->field_38 = 0;
    self->field_3c = 0;
}

struct Unk_800a70 {
    u8 _0[0x10];
    u32 field_10;
    u8 field_14;
    u8 _15[0x3];
    u32 field_18;
    u8 field_1c;
    u8 _1d[0x3];
    u32 field_20;
    u8 field_24;
    u8 _25[0x3];
    u32 field_28;
    u8 field_2c;
    u8 _2d[0x3];
    u32 field_30;
    u8 field_34;
    u8 _35[0x3];
    u16 field_38;
    u8 _3a[0x2];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_800a70, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_800a70, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_800a70, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_800a70, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_800a70, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_800a70, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_800a70, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_800a70, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_800a70, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_800a70, field_34, 0x34);
PKMN_OFFSET_ASSERT(Unk_800a70, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_800a70, field_3c, 0x3c);

// 0x7100800a70
void Unk_800a70_set(Unk_800a70* self) {
    self->field_10 = 5;
    self->field_14 = 0;
    self->field_18 = 5;
    self->field_1c = 0;
    self->field_20 = 5;
    self->field_24 = 0;
    self->field_28 = 5;
    self->field_2c = 0;
    self->field_30 = 5;
    self->field_34 = 0;
    self->field_38 = 0;
    self->field_3c = 0;
}

struct Unk_800bf0 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_800bf0, field_38, 0x38);

// 0x7100800bf0
u8 Unk_800bf0_getField38(const Unk_800bf0* self) {
    return self->field_38;
}
