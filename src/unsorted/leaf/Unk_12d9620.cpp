// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12d9620_5f0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_12d9620_5f0, field_58, 0x58);

struct Unk_12d9620 {
    u8 _0[0x5e8];
    u64 field_5e8;
    Unk_12d9620_5f0* field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_12d9620, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_12d9620, field_5f0, 0x5f0);

void Unk_14e6550(u64, void*, u32, u32);

// 0x71012d9620
void Unk_12d9620_call(const Unk_12d9620* self) {
    u64 l8;
    u64 v0 = self->field_5e8;
    l8 = 0;
    Unk_14e6550(v0, &l8, 1, 0);
    self->field_5f0->field_58 = self->field_5f0->field_58 | 1;
}

// 0x71012db770
void Unk_12db770_update() {}

struct Unk_12db780_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12db780_arg1, field_0, 0x0);

struct Unk_12db780 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12db780, field_0, 0x0);

// 0x71012db780
void Unk_12db780_set(const Unk_12db780* self, Unk_12db780_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12db790_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12db790_arg1, field_0, 0x0);

struct Unk_12db790 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12db790, field_0, 0x0);

// 0x71012db790
void Unk_12db790_set(const Unk_12db790* self, Unk_12db790_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012db9a0
void Unk_12db9a0_update() {}

struct Unk_12db9b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12db9b0_arg1, field_0, 0x0);

struct Unk_12db9b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12db9b0, field_0, 0x0);

// 0x71012db9b0
void Unk_12db9b0_set(const Unk_12db9b0* self, Unk_12db9b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12db9c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12db9c0_arg1, field_0, 0x0);

struct Unk_12db9c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12db9c0, field_0, 0x0);

// 0x71012db9c0
void Unk_12db9c0_set(const Unk_12db9c0* self, Unk_12db9c0_arg1* value) {
    value->field_0 = self->field_0;
}
