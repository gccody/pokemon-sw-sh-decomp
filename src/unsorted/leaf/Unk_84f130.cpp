// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_84f130 {
    u64 field_0;
    u32 field_8;
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_84f130, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_84f130, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_84f130, field_c, 0xc);

// 0x710084f130
void Unk_84f130_set(Unk_84f130* self, u64 value) {
    self->field_0 = value;
    self->field_c = 0;
    self->field_8 = 0;
}

struct Unk_84f140 {
    u8 _0[0xd];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_84f140, field_d, 0xd);

// 0x710084f140
void Unk_84f140_clearFieldd(Unk_84f140* self) {
    self->field_d = 0;
}

struct Unk_84f450 {
    u8 _0[0xd];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_84f450, field_d, 0xd);

// 0x710084f450
bool Unk_84f450_check(const Unk_84f450* self) {
    return self->field_d != 0;
}

struct Unk_84f560 {
    u8 _0[0xd];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_84f560, field_d, 0xd);

// 0x710084f560
u8 Unk_84f560_getFieldd(const Unk_84f560* self) {
    return self->field_d;
}
