// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6b7650 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_6b7650, field_78, 0x78);

// 0x71006b7650
u32 Unk_6b7650_getField78(const Unk_6b7650* self) {
    return self->field_78;
}

struct Unk_6b7660 {
    u8 _0[0x160];
    u32 field_160;
};
PKMN_OFFSET_ASSERT(Unk_6b7660, field_160, 0x160);

// 0x71006b7660
u32 Unk_6b7660_getField160(const Unk_6b7660* self) {
    return self->field_160;
}
