// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_116ccd0 {
    u8 _0[0xe];
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_116ccd0, field_e, 0xe);

// 0x710116ccd0
u8 Unk_116ccd0_getFielde(const Unk_116ccd0* self) {
    return self->field_e;
}

struct Unk_1171010 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1171010, field_10, 0x10);

// 0x7101171010
u32 Unk_1171010_getField10(const Unk_1171010* self) {
    return self->field_10;
}

struct Unk_1174b20 {
    u8 _0[0x310];
    u8 field_310;
};
PKMN_OFFSET_ASSERT(Unk_1174b20, field_310, 0x310);

// 0x7101174b20
u8* Unk_1174b20_getField310Ptr(Unk_1174b20* self) {
    return &self->field_310;
}

struct Unk_1174cb0 {
    u8 _0[0x350];
    u32 field_350;
};
PKMN_OFFSET_ASSERT(Unk_1174cb0, field_350, 0x350);

// 0x7101174cb0
u32 Unk_1174cb0_getField350(const Unk_1174cb0* self) {
    return self->field_350;
}

struct Unk_1176260 {
    u8 _0[0x360];
    u8 field_360;
};
PKMN_OFFSET_ASSERT(Unk_1176260, field_360, 0x360);

// 0x7101176260
u8* Unk_1176260_getField360Ptr(Unk_1176260* self) {
    return &self->field_360;
}

struct Unk_1176270 {
    u8 _0[0x370];
    u8 field_370;
};
PKMN_OFFSET_ASSERT(Unk_1176270, field_370, 0x370);

// 0x7101176270
u8* Unk_1176270_getField370Ptr(Unk_1176270* self) {
    return &self->field_370;
}
