// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1176df0 {
    u8 _0[0xb8];
    u8 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_1176df0, field_b8, 0xb8);

// 0x7101176df0
u8* Unk_1176df0_getFieldb8Ptr(Unk_1176df0* self) {
    return &self->field_b8;
}

struct Unk_1178b00 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1178b00, field_a0, 0xa0);

// 0x7101178b00
u64 Unk_1178b00_getFielda0(const Unk_1178b00* self) {
    return self->field_a0;
}

struct Unk_1178b10 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_1178b10, field_a8, 0xa8);

// 0x7101178b10
u64 Unk_1178b10_getFielda8(const Unk_1178b10* self) {
    return self->field_a8;
}

struct Unk_1178b20 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_1178b20, field_b0, 0xb0);

// 0x7101178b20
u64 Unk_1178b20_getFieldb0(const Unk_1178b20* self) {
    return self->field_b0;
}
