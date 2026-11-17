// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10f78e0 {
    u8 _0[0x190];
    u8 field_190;
};
PKMN_OFFSET_ASSERT(Unk_10f78e0, field_190, 0x190);

// 0x71010f78e0
void Unk_10f78e0_set(Unk_10f78e0* self) {
    self->field_190 = 1;
}

struct Unk_10f79f0 {
    u8 _0[0x1c8];
    u8 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_10f79f0, field_1c8, 0x1c8);

// 0x71010f79f0
void Unk_10f79f0_clearField1c8(Unk_10f79f0* self) {
    self->field_1c8 = 0;
}

struct Unk_10f7a10 {
    u8 _0[0x1c8];
    u8 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_10f7a10, field_1c8, 0x1c8);

// 0x71010f7a10
void Unk_10f7a10_set(Unk_10f7a10* self) {
    self->field_1c8 = 1;
}

struct Unk_10f7c20 {
    u8 _0[0x318];
    u64 field_318;
    u64 field_320;
};
PKMN_OFFSET_ASSERT(Unk_10f7c20, field_318, 0x318);
PKMN_OFFSET_ASSERT(Unk_10f7c20, field_320, 0x320);

// 0x71010f7c20
void Unk_10f7c20_set(Unk_10f7c20* self) {
    self->field_320 = self->field_318;
}

struct Unk_10f7c30 {
    u8 _0[0x310];
    u64 field_310;
};
PKMN_OFFSET_ASSERT(Unk_10f7c30, field_310, 0x310);

void Unk_10f95c0(u64);

// 0x71010f7c30
void Unk_10f7c30_call(const Unk_10f7c30* self) {
    Unk_10f95c0(self->field_310);
}
