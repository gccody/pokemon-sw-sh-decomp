// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c99be0 {
    u8 _0[0xc4];
    u8 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_c99be0, field_c4, 0xc4);

// 0x7100c99be0
u8 Unk_c99be0_getFieldc4(const Unk_c99be0* self) {
    return self->field_c4;
}

struct Unk_c99c60 {
    u8 _0[0x1d0];
    u8 field_1d0;
};
PKMN_OFFSET_ASSERT(Unk_c99c60, field_1d0, 0x1d0);

// 0x7100c99c60
u8 Unk_c99c60_getField1d0(const Unk_c99c60* self) {
    return self->field_1d0;
}
