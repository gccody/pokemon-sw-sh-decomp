// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1160ce0 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_1160ce0, field_80, 0x80);

// 0x7101160ce0
u8* Unk_1160ce0_getField80Ptr(Unk_1160ce0* self) {
    return &self->field_80;
}

struct Unk_1162c90 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_1162c90, field_90, 0x90);

// 0x7101162c90
u8 Unk_1162c90_getField90(const Unk_1162c90* self) {
    return self->field_90;
}

struct Unk_1163130 {
    u8 _0[0xa0];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1163130, field_a0, 0xa0);

// 0x7101163130
u8 Unk_1163130_getFielda0(const Unk_1163130* self) {
    return self->field_a0;
}

struct Unk_1164120 {
    u8 _0[0xb8];
    f32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_1164120, field_b8, 0xb8);

// 0x7101164120
void Unk_1164120_setFieldb8(Unk_1164120* self, f32 value) {
    self->field_b8 = value;
}

struct Unk_1164130 {
    u8 _0[0x140];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_1164130, field_140, 0x140);

// 0x7101164130
u64 Unk_1164130_getField140(const Unk_1164130* self) {
    return self->field_140;
}

struct Unk_1164150 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_1164150, field_b0, 0xb0);

// 0x7101164150
u64 Unk_1164150_getFieldb0(const Unk_1164150* self) {
    return self->field_b0;
}

struct Unk_1165010 {
    u8 _0[0x68];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1165010, field_68, 0x68);

// 0x7101165010
u8 Unk_1165010_getField68(const Unk_1165010* self) {
    return self->field_68;
}

struct Unk_1167c40 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1167c40, field_60, 0x60);

// 0x7101167c40
u64 Unk_1167c40_getField60(const Unk_1167c40* self) {
    return self->field_60;
}
