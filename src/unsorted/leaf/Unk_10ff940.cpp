// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10ff940 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10ff940, field_18, 0x18);

// 0x71010ff940
u8* Unk_10ff940_getField18Ptr(Unk_10ff940* self) {
    return &self->field_18;
}

struct Unk_10ff9c0 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10ff9c0, field_18, 0x18);

// 0x71010ff9c0
u8* Unk_10ff9c0_getField18Ptr(Unk_10ff9c0* self) {
    return &self->field_18;
}

struct Unk_10ffb10 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10ffb10, field_18, 0x18);

// 0x71010ffb10
u8* Unk_10ffb10_getField18Ptr(Unk_10ffb10* self) {
    return &self->field_18;
}

struct Unk_10ffcf0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_10ffcf0, field_30, 0x30);

// 0x71010ffcf0
u8* Unk_10ffcf0_getField30Ptr(Unk_10ffcf0* self) {
    return &self->field_30;
}
