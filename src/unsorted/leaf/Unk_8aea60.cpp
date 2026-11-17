// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8aea60 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_8aea60, field_d8, 0xd8);

void Unk_8aea70(u64);

// 0x71008aea60
void Unk_8aea60_call(const Unk_8aea60* self) {
    if (self->field_d8 != 0) {
        Unk_8aea70(self->field_d8);
    }
}

struct Unk_8af080 {
    u8 _0[0xe0];
    u32 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_8af080, field_e0, 0xe0);

// 0x71008af080
bool Unk_8af080_check(const Unk_8af080* self) {
    return self->field_e0 == 1;
}

struct Unk_8af850 {
    u8 _0[0xf8];
    u32 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_8af850, field_f8, 0xf8);

// 0x71008af850
bool Unk_8af850_check(const Unk_8af850* self) {
    return self->field_f8 != 5;
}

struct Unk_8afc30 {
    u8 _0[0x2c28];
    u64 field_2c28;
};
PKMN_OFFSET_ASSERT(Unk_8afc30, field_2c28, 0x2c28);

// 0x71008afc30
bool Unk_8afc30_check(const Unk_8afc30* self) {
    return self->field_2c28 != 0;
}

struct Unk_8b0010 {
    u8 _0[0x3448];
    u64 field_3448;
};
PKMN_OFFSET_ASSERT(Unk_8b0010, field_3448, 0x3448);

// 0x71008b0010
bool Unk_8b0010_check(const Unk_8b0010* self) {
    return self->field_3448 != 0;
}

struct Unk_8b0380 {
    u8 _0[0x3450];
    u64 field_3450;
};
PKMN_OFFSET_ASSERT(Unk_8b0380, field_3450, 0x3450);

// 0x71008b0380
void Unk_8b0380_clearField3450(Unk_8b0380* self) {
    self->field_3450 = 0;
}

struct Unk_8b0390_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8b0390_arg1, field_0, 0x0);

struct Unk_8b0390_arg2 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8b0390_arg2, field_0, 0x0);

struct Unk_8b0390 {
    u8 _0[0x3450];
    u32 field_3450;
    u32 field_3454;
};
PKMN_OFFSET_ASSERT(Unk_8b0390, field_3450, 0x3450);
PKMN_OFFSET_ASSERT(Unk_8b0390, field_3454, 0x3454);

// 0x71008b0390
u32 Unk_8b0390_update(const Unk_8b0390* self, Unk_8b0390_arg1* value, Unk_8b0390_arg2* arg2) {
    if (self->field_3450 == 0) {
        return 0;
    }
    value->field_0 = self->field_3450;
    arg2->field_0 = self->field_3454;
    return 1;
}

struct Unk_8b09f0 {
    u8 _0[0x3458];
    u32 field_3458;
};
PKMN_OFFSET_ASSERT(Unk_8b09f0, field_3458, 0x3458);

// 0x71008b09f0
void Unk_8b09f0_clearField3458(Unk_8b09f0* self) {
    self->field_3458 = 0;
}
