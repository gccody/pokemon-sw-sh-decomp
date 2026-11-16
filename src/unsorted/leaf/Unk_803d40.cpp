// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_803d40 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_803d40, field_0, 0x0);

// 0x7100803d40
u16 Unk_803d40_getField0(const Unk_803d40* self) {
    return self->field_0;
}

struct Unk_803dc0 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_803dc0, field_4, 0x4);

// 0x7100803dc0
u8* Unk_803dc0_getField4Ptr(Unk_803dc0* self) {
    return &self->field_4;
}

struct Unk_803e00 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_803e00, field_20, 0x20);

// 0x7100803e00
u32 Unk_803e00_getField20(const Unk_803e00* self) {
    return self->field_20;
}
