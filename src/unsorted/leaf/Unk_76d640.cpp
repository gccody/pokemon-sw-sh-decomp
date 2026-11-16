// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_76d640 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_76d640, field_8, 0x8);

// 0x710076d640
u32 Unk_76d640_getField8(const Unk_76d640* self) {
    return self->field_8;
}

struct Unk_76d650 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_76d650, field_c, 0xc);

// 0x710076d650
u16 Unk_76d650_getFieldc(const Unk_76d650* self) {
    return self->field_c;
}

struct Unk_76d740 {
    u8 _0[0x112];
    u8 field_112;
};
PKMN_OFFSET_ASSERT(Unk_76d740, field_112, 0x112);

// 0x710076d740
u8 Unk_76d740_getField112(const Unk_76d740* self) {
    return self->field_112;
}
