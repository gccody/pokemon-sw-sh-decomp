// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1509aa0_5f8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1509aa0_5f8, field_58, 0x58);

struct Unk_1509aa0 {
    u8 _0[0x5f8];
    Unk_1509aa0_5f8* field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_1509aa0, field_5f8, 0x5f8);

// 0x7101509aa0
void Unk_1509aa0_set(const Unk_1509aa0* self) {
    self->field_5f8->field_58 = self->field_5f8->field_58 | 1;
}

// 0x710150c650
void Unk_150c650_update() {}

struct Unk_150c660_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150c660_arg1, field_0, 0x0);

struct Unk_150c660 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150c660, field_0, 0x0);

// 0x710150c660
void Unk_150c660_set(const Unk_150c660* self, Unk_150c660_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_150c670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150c670_arg1, field_0, 0x0);

struct Unk_150c670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150c670, field_0, 0x0);

// 0x710150c670
void Unk_150c670_set(const Unk_150c670* self, Unk_150c670_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710150c6d0
void Unk_150c6d0_update() {}

struct Unk_150c6e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150c6e0_arg1, field_0, 0x0);

struct Unk_150c6e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150c6e0, field_0, 0x0);

// 0x710150c6e0
void Unk_150c6e0_set(const Unk_150c6e0* self, Unk_150c6e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_150c6f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150c6f0_arg1, field_0, 0x0);

struct Unk_150c6f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150c6f0, field_0, 0x0);

// 0x710150c6f0
void Unk_150c6f0_set(const Unk_150c6f0* self, Unk_150c6f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710150ca80
void Unk_150ca80_update() {}

struct Unk_150ca90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150ca90_arg1, field_0, 0x0);

struct Unk_150ca90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150ca90, field_0, 0x0);

// 0x710150ca90
void Unk_150ca90_set(const Unk_150ca90* self, Unk_150ca90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_150caa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150caa0_arg1, field_0, 0x0);

struct Unk_150caa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_150caa0, field_0, 0x0);

// 0x710150caa0
void Unk_150caa0_set(const Unk_150caa0* self, Unk_150caa0_arg1* value) {
    value->field_0 = self->field_0;
}
