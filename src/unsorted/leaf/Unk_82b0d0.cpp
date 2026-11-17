// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82b0d0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b0d0, field_0, 0x0);

// 0x710082b0d0
u8 Unk_82b0d0_getField0(const Unk_82b0d0* self) {
    return self->field_0;
}

struct Unk_82b0e0 {
    u8 _0[0x2];
    s16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_82b0e0, field_2, 0x2);

// 0x710082b0e0
bool Unk_82b0e0_check(const Unk_82b0e0* self) {
    return self->field_2 != -1;
}

struct Unk_82b4c0 {
    u8 _0[0x88];
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u64 field_a0;
    u64 field_a8;
    u64 field_b0;
    u64 field_b8;
    u32 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_82b4c0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_82b4c0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_82b4c0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_82b4c0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_82b4c0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_82b4c0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_82b4c0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_82b4c0, field_c0, 0xc0);

// 0x710082b4c0
void Unk_82b4c0_set(Unk_82b4c0* self) {
    self->field_c0 = 0;
    self->field_b0 = 0;
    self->field_b8 = 0;
    self->field_88 = 0;
    self->field_a0 = 0;
    self->field_a8 = 0;
    self->field_90 = 0;
    self->field_98 = 0;
}

struct Unk_82b4e0 {
    u8 _0[0xc8];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_82b4e0, field_c8, 0xc8);

// 0x710082b4e0
void Unk_82b4e0_clearFieldc8(Unk_82b4e0* self) {
    self->field_c8 = 0;
}

struct Unk_82b4f0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_82b4f0, field_8, 0x8);

// 0x710082b4f0
u64 Unk_82b4f0_getField8(const Unk_82b4f0* self) {
    return self->field_8;
}

struct Unk_82b500 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_82b500, field_28, 0x28);

// 0x710082b500
u64 Unk_82b500_getField28(const Unk_82b500* self) {
    return self->field_28;
}

struct Unk_82b510 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_82b510, field_48, 0x48);

// 0x710082b510
u64 Unk_82b510_getField48(const Unk_82b510* self) {
    return self->field_48;
}

struct Unk_82b520 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_82b520, field_68, 0x68);

// 0x710082b520
u64 Unk_82b520_getField68(const Unk_82b520* self) {
    return self->field_68;
}

struct Unk_82b530 {
    u8 _0[0xc4];
    u8 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_82b530, field_c4, 0xc4);

// 0x710082b530
u8 Unk_82b530_getFieldc4(const Unk_82b530* self) {
    return self->field_c4;
}

struct Unk_82b540 {
    u8 _0[0xc4];
    u8 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_82b540, field_c4, 0xc4);

// 0x710082b540
void Unk_82b540_set(Unk_82b540* self) {
    self->field_c4 = self->field_c4 + 1;
}

struct Unk_82b550 {
    u8 _0[0xc4];
    u8 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_82b550, field_c4, 0xc4);

// 0x710082b550
void Unk_82b550_clearFieldc4(Unk_82b550* self) {
    self->field_c4 = 0;
}
