// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

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
