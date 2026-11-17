// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82f7f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_82f7f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_82f7f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82f7f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82f7f0, field_18, 0x18);

// 0x710082f7f0
void Unk_82f7f0_set(Unk_82f7f0* self) {
    self->field_18 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_0 = 0;
}

// 0x710082f800
void Unk_82f800() {}

struct Unk_82f810 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_82f810, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_82f810, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82f810, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82f810, field_18, 0x18);

// 0x710082f810
void Unk_82f810_set(Unk_82f810* self) {
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_0 = 0;
    self->field_18 = 1;
}

struct Unk_82f830 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_82f830, field_18, 0x18);

// 0x710082f830
void Unk_82f830_clearField18(Unk_82f830* self) {
    self->field_18 = 0;
}
