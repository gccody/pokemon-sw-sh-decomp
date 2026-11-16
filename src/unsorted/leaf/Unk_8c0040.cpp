// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8c0040 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_8c0040, field_88, 0x88);

// 0x71008c0040
u8 Unk_8c0040_getField88(const Unk_8c0040* self) {
    return self->field_88;
}

struct Unk_8c0050 {
    u8 _0[0x74];
    u8 field_74;
};
PKMN_OFFSET_ASSERT(Unk_8c0050, field_74, 0x74);

// 0x71008c0050
u8* Unk_8c0050_getField74Ptr(Unk_8c0050* self) {
    return &self->field_74;
}
