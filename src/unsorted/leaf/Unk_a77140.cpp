// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_a77140 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_a77140, field_68, 0x68);

// 0x7100a77140
u32 Unk_a77140_getField68(const Unk_a77140* self) {
    return self->field_68;
}

struct Unk_a77150 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_a77150, field_64, 0x64);

// 0x7100a77150
void Unk_a77150_setField64(Unk_a77150* self, u32 value) {
    self->field_64 = value;
}

struct Unk_a77160 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_a77160, field_70, 0x70);

// 0x7100a77160
u64 Unk_a77160_getField70(const Unk_a77160* self) {
    return self->field_70;
}

struct Unk_a77460 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_a77460, field_78, 0x78);

// 0x7100a77460
void Unk_a77460_setField78(Unk_a77460* self, u32 value) {
    self->field_78 = value;
}

struct Unk_a775e0 {
    u8 _0[0x88];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_a775e0, field_88, 0x88);

// 0x7100a775e0
u32 Unk_a775e0_getField88(const Unk_a775e0* self) {
    return self->field_88;
}

struct Unk_a77790 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_a77790, field_b0, 0xb0);

// 0x7100a77790
void Unk_a77790_setFieldb0(Unk_a77790* self, u64 value) {
    self->field_b0 = value;
}

struct Unk_a777c0 {
    u8 _0[0x7c0];
    u64 field_7c0;
};
PKMN_OFFSET_ASSERT(Unk_a777c0, field_7c0, 0x7c0);

// 0x7100a777c0
void Unk_a777c0_setField7c0(Unk_a777c0* self, u64 value) {
    self->field_7c0 = value;
}
