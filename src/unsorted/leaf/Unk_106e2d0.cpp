// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_106e2d0 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_106e2d0, field_4, 0x4);

// 0x710106e2d0
u8* Unk_106e2d0_getField4Ptr(Unk_106e2d0* self) {
    return &self->field_4;
}

// 0x710106e2e0
void Unk_106e2e0() {}

struct Unk_106e2f0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_106e2f0, field_8, 0x8);

// 0x710106e2f0
u8* Unk_106e2f0_getField8Ptr(Unk_106e2f0* self) {
    return &self->field_8;
}

struct Unk_106e300 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_106e300, field_c, 0xc);

// 0x710106e300
u8* Unk_106e300_getFieldcPtr(Unk_106e300* self) {
    return &self->field_c;
}
