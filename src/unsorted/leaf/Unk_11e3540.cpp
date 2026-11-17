// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11e3540 {
    u8 _0[0x33c];
    u8 field_33c;
};
PKMN_OFFSET_ASSERT(Unk_11e3540, field_33c, 0x33c);

void Unk_11e3550();

// 0x71011e3540
void Unk_11e3540_call(Unk_11e3540* self) {
    self->field_33c = 1;
    Unk_11e3550();
}

struct Unk_11e3990 {
    u8 _0[0x33c];
    u8 field_33c;
};
PKMN_OFFSET_ASSERT(Unk_11e3990, field_33c, 0x33c);

void Unk_11e3550();

// 0x71011e3990
void Unk_11e3990_call(Unk_11e3990* self) {
    self->field_33c = 0;
    Unk_11e3550();
}

struct Unk_11e39a0 {
    u8 _0[0x338];
    u32 field_338;
};
PKMN_OFFSET_ASSERT(Unk_11e39a0, field_338, 0x338);

void Unk_11e3550();

// 0x71011e39a0
void Unk_11e39a0_call(Unk_11e39a0* self, u32 value) {
    self->field_338 = value;
    Unk_11e3550();
}

void Unk_112e3e0(void*, u32);

// 0x71011e4c30
void Unk_11e4c30_call(void* self) {
    Unk_112e3e0(self, 0);
}

struct Unk_11e4c40 {
    u8 _0[0x114];
    f32 field_114;
};
PKMN_OFFSET_ASSERT(Unk_11e4c40, field_114, 0x114);

// 0x71011e4c40
void Unk_11e4c40_setField114(Unk_11e4c40* self, f32 value) {
    self->field_114 = value;
}
