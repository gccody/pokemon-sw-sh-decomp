// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100ea2fe0
void Unk_ea2fe0() {}

struct Unk_ea3d10 {
    u8 _0[0x70];
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_ea3d10, field_70, 0x70);

// 0x7100ea3d10
u8* Unk_ea3d10_getField70Ptr(Unk_ea3d10* self) {
    return &self->field_70;
}

struct Unk_ea3d20 {
    u8 _0[0x160];
    u8 field_160;
};
PKMN_OFFSET_ASSERT(Unk_ea3d20, field_160, 0x160);

// 0x7100ea3d20
u8* Unk_ea3d20_getField160Ptr(Unk_ea3d20* self) {
    return &self->field_160;
}

struct Unk_ea4750 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_ea4750, field_90, 0x90);

// 0x7100ea4750
u64 Unk_ea4750_getField90(const Unk_ea4750* self) {
    return self->field_90;
}

struct Unk_ea4770 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_ea4770, field_98, 0x98);

// 0x7100ea4770
u64 Unk_ea4770_getField98(const Unk_ea4770* self) {
    return self->field_98;
}

struct Unk_ea4790 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_ea4790, field_a0, 0xa0);

// 0x7100ea4790
u64 Unk_ea4790_getFielda0(const Unk_ea4790* self) {
    return self->field_a0;
}

struct Unk_ea47d0 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_ea47d0, field_c0, 0xc0);

// 0x7100ea47d0
u8* Unk_ea47d0_getFieldc0Ptr(Unk_ea47d0* self) {
    return &self->field_c0;
}

struct Unk_ea47e0 {
    u8 _0[0xd0];
    u8 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_ea47e0, field_d0, 0xd0);

// 0x7100ea47e0
u8* Unk_ea47e0_getFieldd0Ptr(Unk_ea47e0* self) {
    return &self->field_d0;
}

struct Unk_ea47f0 {
    u8 _0[0xc8];
    u8 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_ea47f0, field_c8, 0xc8);

// 0x7100ea47f0
u8* Unk_ea47f0_getFieldc8Ptr(Unk_ea47f0* self) {
    return &self->field_c8;
}

struct Unk_ea4800 {
    u8 _0[0xb8];
    u8 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_ea4800, field_b8, 0xb8);

// 0x7100ea4800
u8* Unk_ea4800_getFieldb8Ptr(Unk_ea4800* self) {
    return &self->field_b8;
}

struct Unk_ea4810 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_ea4810, field_b0, 0xb0);

// 0x7100ea4810
u8* Unk_ea4810_getFieldb0Ptr(Unk_ea4810* self) {
    return &self->field_b0;
}
