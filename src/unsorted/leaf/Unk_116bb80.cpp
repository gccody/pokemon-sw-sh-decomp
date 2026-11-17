// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_116bb80 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_116bb80, field_18, 0x18);

// 0x710116bb80
bool Unk_116bb80_check(const Unk_116bb80* self) {
    return self->field_18 == 0;
}

struct Unk_116ccd0 {
    u8 _0[0xe];
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_116ccd0, field_e, 0xe);

// 0x710116ccd0
u8 Unk_116ccd0_getFielde(const Unk_116ccd0* self) {
    return self->field_e;
}

void Unk_116f1d0(void*, u32);

// 0x710116f1c0
void Unk_116f1c0_call(void* self) {
    Unk_116f1d0(self, 0xd);
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

struct Unk_11726b0 {
    u8 _0[0xa0];
    f32 field_a0;
    f32 field_a4;
};
PKMN_OFFSET_ASSERT(Unk_11726b0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_11726b0, field_a4, 0xa4);

// 0x71011726b0
void Unk_11726b0_set(Unk_11726b0* self, f32 fvalue, f32 farg1) {
    self->field_a0 = fvalue;
    self->field_a4 = farg1;
}

struct Unk_1173310_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1173310_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1173310_arg1, field_8, 0x8);

struct Unk_1173310 {
    u8 _0[0xe0];
    u64 field_e0;
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_1173310, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_1173310, field_e8, 0xe8);

// 0x7101173310
void Unk_1173310_set(Unk_1173310* self, const Unk_1173310_arg1* value) {
    self->field_e8 = value->field_8;
    self->field_e0 = value->field_0;
}

struct Unk_1174460_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1174460_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1174460_arg1, field_8, 0x8);

struct Unk_1174460 {
    u8 _0[0x360];
    u64 field_360;
    u64 field_368;
};
PKMN_OFFSET_ASSERT(Unk_1174460, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_1174460, field_368, 0x368);

// 0x7101174460
void Unk_1174460_set(Unk_1174460* self, const Unk_1174460_arg1* value) {
    self->field_368 = value->field_8;
    self->field_360 = value->field_0;
}

struct Unk_1174480_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1174480_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1174480_arg1, field_8, 0x8);

struct Unk_1174480 {
    u8 _0[0x370];
    u64 field_370;
    u64 field_378;
};
PKMN_OFFSET_ASSERT(Unk_1174480, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_1174480, field_378, 0x378);

// 0x7101174480
void Unk_1174480_set(Unk_1174480* self, const Unk_1174480_arg1* value) {
    self->field_378 = value->field_8;
    self->field_370 = value->field_0;
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
