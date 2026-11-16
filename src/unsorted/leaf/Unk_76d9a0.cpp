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

struct Unk_770eb0 {
    u8 _0[0x19];
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_770eb0, field_19, 0x19);

// 0x7100770eb0
u8 Unk_770eb0_getField19(const Unk_770eb0* self) {
    return self->field_19;
}
