// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d1b5a0_arg1 {
    u32 field_0;
    u8 field_4;
    u8 field_5;
};
PKMN_OFFSET_ASSERT(Unk_d1b5a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d1b5a0_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_d1b5a0_arg1, field_5, 0x5);

struct Unk_d1b5a0 {
    u8 _0[0x98];
    u32 field_98;
    u8 field_9c;
    u8 _9d[0x38];
    u8 field_d5;
    u8 field_d6;
};
PKMN_OFFSET_ASSERT(Unk_d1b5a0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_d1b5a0, field_9c, 0x9c);
PKMN_OFFSET_ASSERT(Unk_d1b5a0, field_d5, 0xd5);
PKMN_OFFSET_ASSERT(Unk_d1b5a0, field_d6, 0xd6);

// 0x7100d1b5a0
void Unk_d1b5a0_set(Unk_d1b5a0* self, const Unk_d1b5a0_arg1* value) {
    self->field_d6 = value->field_4;
    self->field_98 = value->field_0;
    self->field_9c = value->field_5 != 0;
    self->field_d5 = 1;
}

struct Unk_d1b6a0 {
    u8 _0[0x9e];
    u8 field_9e;
};
PKMN_OFFSET_ASSERT(Unk_d1b6a0, field_9e, 0x9e);

// 0x7100d1b6a0
void Unk_d1b6a0_clearField9e(Unk_d1b6a0* self) {
    self->field_9e = 0;
}

struct Unk_d1d280 {
    u8 _0[0x9e];
    u8 field_9e;
};
PKMN_OFFSET_ASSERT(Unk_d1d280, field_9e, 0x9e);

// 0x7100d1d280
u8 Unk_d1d280_getField9e(const Unk_d1d280* self) {
    return self->field_9e;
}
