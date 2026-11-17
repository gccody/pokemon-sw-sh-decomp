// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100d29850
u32 Unk_d29850() {
    return 0;
}

struct Unk_d369a0_4c0 {
    u8 _0[0x170];
    f32 field_170;
};
PKMN_OFFSET_ASSERT(Unk_d369a0_4c0, field_170, 0x170);

struct Unk_d369a0 {
    u8 _0[0x4c0];
    Unk_d369a0_4c0* field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_d369a0, field_4c0, 0x4c0);

// 0x7100d369a0
void Unk_d369a0_set(const Unk_d369a0* self, f32 fvalue) {
    self->field_4c0->field_170 = fvalue;
}

struct Unk_d369b0_4c8 {
    u8 _0[0xec];
    u8 field_ec;
};
PKMN_OFFSET_ASSERT(Unk_d369b0_4c8, field_ec, 0xec);

struct Unk_d369b0 {
    u8 _0[0x4c8];
    Unk_d369b0_4c8* field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_d369b0, field_4c8, 0x4c8);

// 0x7100d369b0
u8 Unk_d369b0_get(const Unk_d369b0* self) {
    return self->field_4c8->field_ec;
}

struct Unk_d36a60 {
    u8 _0[0x510];
    bool field_510;
};
PKMN_OFFSET_ASSERT(Unk_d36a60, field_510, 0x510);

// 0x7100d36a60
void Unk_d36a60_set(Unk_d36a60* self, bool value) {
    self->field_510 = value;
}
