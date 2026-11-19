// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c95d60 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_c95d60, field_60, 0x60);

// 0x7100c95d60
bool Unk_c95d60_check(const Unk_c95d60* self) {
    return self->field_60 == 2;
}

struct Unk_c99bb0 {
    u8 _0[0x60];
    u32 field_60;
    u8 _64[0x6c];
    u8 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_c99bb0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_c99bb0, field_d0, 0xd0);

// 0x7100c99bb0
bool Unk_c99bb0_check(const Unk_c99bb0* self) {
    if (self->field_60 != 3) {
        return false;
    }
    return self->field_d0 != 0;
}

struct Unk_c99be0 {
    u8 _0[0xc4];
    u8 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_c99be0, field_c4, 0xc4);

// 0x7100c99be0
u8 Unk_c99be0_getFieldc4(const Unk_c99be0* self) {
    return self->field_c4;
}

struct Unk_c99c50 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_c99c50, field_60, 0x60);

// 0x7100c99c50
bool Unk_c99c50_check(const Unk_c99c50* self) {
    return self->field_60 == 6;
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
