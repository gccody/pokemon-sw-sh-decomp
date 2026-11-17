// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a7f50 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7f50, field_8, 0x8);

// 0x71008a7f50
void Unk_8a7f50_clearField8(Unk_8a7f50* self) {
    self->field_8 = 0;
}

struct Unk_8a7f60 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7f60, field_8, 0x8);

// 0x71008a7f60
void Unk_8a7f60_setField8(Unk_8a7f60* self, u32 value) {
    self->field_8 = value;
}

struct Unk_8a7f70 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_8a7f70, field_c, 0xc);

// 0x71008a7f70
void Unk_8a7f70_setFieldc(Unk_8a7f70* self, u32 value) {
    self->field_c = value;
}

struct Unk_8a7f80 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7f80, field_8, 0x8);

// 0x71008a7f80
u32 Unk_8a7f80_getField8(const Unk_8a7f80* self) {
    return self->field_8;
}

struct Unk_8a7f90 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_8a7f90, field_c, 0xc);

// 0x71008a7f90
u32 Unk_8a7f90_getFieldc(const Unk_8a7f90* self) {
    return self->field_c;
}

struct Unk_8a8010 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8a8010, field_10, 0x10);

// 0x71008a8010
u8 Unk_8a8010_getField10(const Unk_8a8010* self) {
    return self->field_10;
}

struct Unk_8a8020 {
    u8 _0[0x11];
    u8 field_11;
};
PKMN_OFFSET_ASSERT(Unk_8a8020, field_11, 0x11);

// 0x71008a8020
void Unk_8a8020_set(Unk_8a8020* self) {
    self->field_11 = 1;
}

struct Unk_8a8100 {
    u8 _0[0x33];
    bool field_33;
};
PKMN_OFFSET_ASSERT(Unk_8a8100, field_33, 0x33);

// 0x71008a8100
void Unk_8a8100_set(Unk_8a8100* self, bool value) {
    self->field_33 = value;
}

struct Unk_8a8110 {
    u8 _0[0x33];
    u8 field_33;
};
PKMN_OFFSET_ASSERT(Unk_8a8110, field_33, 0x33);

// 0x71008a8110
bool Unk_8a8110_check(const Unk_8a8110* self) {
    return self->field_33 != 0;
}

// 0x71008a8250
void Unk_8a8250() {}
