// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_76d9a0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_76d9a0, field_8, 0x8);

// 0x710076d9a0
u32 Unk_76d9a0_getField8(const Unk_76d9a0* self) {
    return self->field_8;
}

struct Unk_76d9b0 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_76d9b0, field_c, 0xc);

// 0x710076d9b0
u16 Unk_76d9b0_getFieldc(const Unk_76d9b0* self) {
    return self->field_c;
}

struct Unk_76e810 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_76e810, field_8, 0x8);

// 0x710076e810
u32 Unk_76e810_getField8(const Unk_76e810* self) {
    return self->field_8;
}

// 0x710076f430
void Unk_76f430() {}

struct Unk_770ce0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_770ce0, field_8, 0x8);

// 0x7100770ce0
bool Unk_770ce0_check(const Unk_770ce0* self) {
    return self->field_8 != 0;
}

struct Unk_770eb0 {
    u8 _0[0x19];
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_770eb0, field_19, 0x19);

// 0x7100770eb0
u8 Unk_770eb0_getField19(const Unk_770eb0* self) {
    return self->field_19;
}

struct Unk_771260_10 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_771260_10, field_0, 0x0);

struct Unk_771260 {
    u8 _0[0x10];
    Unk_771260_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_771260, field_10, 0x10);

// 0x7100771260
u32 Unk_771260_get(const Unk_771260* self) {
    return self->field_10->field_0;
}

struct Unk_771270_10 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_771270_10, field_4, 0x4);

struct Unk_771270 {
    u8 _0[0x10];
    Unk_771270_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_771270, field_10, 0x10);

// 0x7100771270
u32 Unk_771270_get(const Unk_771270* self) {
    return (self->field_10->field_4 >> 2) & 1;
}
