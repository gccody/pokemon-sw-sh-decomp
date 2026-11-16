// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_65dd50 {
    u8 _0[0xd];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_65dd50, field_d, 0xd);

// 0x710065dd50
void Unk_65dd50_clearFieldd(Unk_65dd50* self) {
    self->field_d = 0;
}

struct Unk_65e0c0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65e0c0, field_8, 0x8);

// 0x710065e0c0
u32 Unk_65e0c0_getField8(const Unk_65e0c0* self) {
    return self->field_8;
}

struct Unk_65ea00 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_65ea00, field_8, 0x8);

// 0x710065ea00
u64 Unk_65ea00_getField8(const Unk_65ea00* self) {
    return self->field_8;
}

struct Unk_65edd0 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_65edd0, field_38, 0x38);

// 0x710065edd0
u64 Unk_65edd0_getField38(const Unk_65edd0* self) {
    return self->field_38;
}

struct Unk_65ede0 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_65ede0, field_40, 0x40);

// 0x710065ede0
u64 Unk_65ede0_getField40(const Unk_65ede0* self) {
    return self->field_40;
}

struct Unk_65ee30 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_65ee30, field_30, 0x30);

// 0x710065ee30
u64 Unk_65ee30_getField30(const Unk_65ee30* self) {
    return self->field_30;
}

struct Unk_65f1a0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_65f1a0, field_10, 0x10);

// 0x710065f1a0
u64 Unk_65f1a0_getField10(const Unk_65f1a0* self) {
    return self->field_10;
}

struct Unk_65f1b0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_65f1b0, field_10, 0x10);

// 0x710065f1b0
void Unk_65f1b0_setField10(Unk_65f1b0* self, u64 value) {
    self->field_10 = value;
}

// 0x710065fb00
void Unk_65fb00() {}

// 0x7100666a30
void Unk_666a30() {}

// 0x7100667cc0
void Unk_667cc0() {}

// 0x710066c130
u32 Unk_66c130() {
    return 0;
}

struct Unk_6707e0 {
    u8 _0[0x1d8];
    u32 field_1d8;
};
PKMN_OFFSET_ASSERT(Unk_6707e0, field_1d8, 0x1d8);

// 0x71006707e0
u32 Unk_6707e0_getField1d8(const Unk_6707e0* self) {
    return self->field_1d8;
}

struct Unk_670800 {
    u8 _0[0x1f0];
    u8 field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_670800, field_1f0, 0x1f0);

// 0x7100670800
u8 Unk_670800_getField1f0(const Unk_670800* self) {
    return self->field_1f0;
}

struct Unk_670810 {
    u8 _0[0x1f4];
    u32 field_1f4;
};
PKMN_OFFSET_ASSERT(Unk_670810, field_1f4, 0x1f4);

// 0x7100670810
u32 Unk_670810_getField1f4(const Unk_670810* self) {
    return self->field_1f4;
}

struct Unk_670820 {
    u8 _0[0x1f8];
    u32 field_1f8;
};
PKMN_OFFSET_ASSERT(Unk_670820, field_1f8, 0x1f8);

// 0x7100670820
u32 Unk_670820_getField1f8(const Unk_670820* self) {
    return self->field_1f8;
}

struct Unk_671ce0 {
    u8 _0[0x1f8];
    u32 field_1f8;
};
PKMN_OFFSET_ASSERT(Unk_671ce0, field_1f8, 0x1f8);

// 0x7100671ce0
void Unk_671ce0_setField1f8(Unk_671ce0* self, u32 value) {
    self->field_1f8 = value;
}

struct Unk_671cf0 {
    u8 _0[0x194];
    u32 field_194;
};
PKMN_OFFSET_ASSERT(Unk_671cf0, field_194, 0x194);

// 0x7100671cf0
void Unk_671cf0_setField194(Unk_671cf0* self, u32 value) {
    self->field_194 = value;
}
