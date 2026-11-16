// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8384b0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8384b0, field_20, 0x20);

// 0x71008384b0
u64 Unk_8384b0_getField20(const Unk_8384b0* self) {
    return self->field_20;
}

struct Unk_8384c0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8384c0, field_10, 0x10);

// 0x71008384c0
u64 Unk_8384c0_getField10(const Unk_8384c0* self) {
    return self->field_10;
}

struct Unk_8384d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_8384d0, field_18, 0x18);

// 0x71008384d0
u64 Unk_8384d0_getField18(const Unk_8384d0* self) {
    return self->field_18;
}

struct Unk_8384e0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8384e0, field_30, 0x30);

// 0x71008384e0
u8 Unk_8384e0_getField30(const Unk_8384e0* self) {
    return self->field_30;
}
