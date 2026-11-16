// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6d7aa0 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_6d7aa0, field_c0, 0xc0);

// 0x71006d7aa0
u8* Unk_6d7aa0_getFieldc0Ptr(Unk_6d7aa0* self) {
    return &self->field_c0;
}

struct Unk_6d7ab0 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_6d7ab0, field_120, 0x120);

// 0x71006d7ab0
u8* Unk_6d7ab0_getField120Ptr(Unk_6d7ab0* self) {
    return &self->field_120;
}
