// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1453cb0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1453cb0, field_0, 0x0);

// 0x7101453cb0
u32 Unk_1453cb0_get(const Unk_1453cb0* self) {
    return self->field_0 & 3;
}

struct Unk_1453cc0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1453cc0, field_0, 0x0);

// 0x7101453cc0
u32 Unk_1453cc0_get(const Unk_1453cc0* self) {
    return (self->field_0 >> 2) & 3;
}

struct Unk_1453cd0 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_1453cd0, field_1, 0x1);

// 0x7101453cd0
u8 Unk_1453cd0_getField1(const Unk_1453cd0* self) {
    return self->field_1;
}

struct Unk_1453ce0 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_1453ce0, field_2, 0x2);

// 0x7101453ce0
u8 Unk_1453ce0_getField2(const Unk_1453ce0* self) {
    return self->field_2;
}

struct Unk_1453e00 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1453e00, field_8, 0x8);

// 0x7101453e00
u64 Unk_1453e00_getField8(const Unk_1453e00* self) {
    return self->field_8;
}

struct Unk_1453e10 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1453e10, field_10, 0x10);

// 0x7101453e10
u64 Unk_1453e10_getField10(const Unk_1453e10* self) {
    return self->field_10;
}

struct Unk_1453e20 {
    u8 _0[0x3];
    u8 field_3;
};
PKMN_OFFSET_ASSERT(Unk_1453e20, field_3, 0x3);

// 0x7101453e20
bool Unk_1453e20_check(const Unk_1453e20* self) {
    return self->field_3 != 0;
}
