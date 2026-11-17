// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_b75640 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_b75640, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b75640, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b75640, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b75640, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_b75640, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_b75640, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_b75640, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_b75640, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_b75640, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_b75640, field_48, 0x48);

// 0x7100b75640
void Unk_b75640_set(Unk_b75640* self) {
    self->field_40 = 0;
    self->field_48 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

struct Unk_b75f00 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_b75f00, field_a8, 0xa8);

// 0x7100b75f00
u64 Unk_b75f00_getFielda8(const Unk_b75f00* self) {
    return self->field_a8;
}

struct Unk_b79510 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_b79510, field_b0, 0xb0);

// 0x7100b79510
u64 Unk_b79510_getFieldb0(const Unk_b79510* self) {
    return self->field_b0;
}

struct Unk_b7e3c0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_b7e3c0, field_10, 0x10);

// 0x7100b7e3c0
u32 Unk_b7e3c0_getField10(const Unk_b7e3c0* self) {
    return self->field_10;
}

struct Unk_b7f2f0 {
    u8 _0[0xc8];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_b7f2f0, field_c8, 0xc8);

// 0x7100b7f2f0
u64 Unk_b7f2f0_getFieldc8(const Unk_b7f2f0* self) {
    return self->field_c8;
}
