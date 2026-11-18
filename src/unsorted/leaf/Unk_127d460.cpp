// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710127d460
void Unk_127d460_update() {}

// 0x710127d480
void Unk_127d480_update() {}

struct Unk_127d490_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d490_arg1, field_0, 0x0);

struct Unk_127d490 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d490, field_0, 0x0);

// 0x710127d490
void Unk_127d490_set(const Unk_127d490* self, Unk_127d490_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_127d4a0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d4a0_arg1, field_0, 0x0);

struct Unk_127d4a0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d4a0, field_0, 0x0);

// 0x710127d4a0
void Unk_127d4a0_set(const Unk_127d4a0* self, Unk_127d4a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_127d4b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_127d4b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_127d4b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_127d4b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_127d4b0, field_18, 0x18);

// 0x710127d4b0
void Unk_127d4b0_set(const Unk_127d4b0* self, Unk_127d4b0* value) {
    *value = *self;
}

struct Unk_127d4d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_127d4d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_127d4d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_127d4d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_127d4d0, field_18, 0x18);

// 0x710127d4d0
void Unk_127d4d0_set(const Unk_127d4d0* self, Unk_127d4d0* value) {
    *value = *self;
}

struct Unk_127d4f0_0 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_127d4f0_0, field_b0, 0xb0);

struct Unk_127d4f0 {
    Unk_127d4f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d4f0, field_0, 0x0);

// 0x710127d4f0
u32 Unk_127d4f0_update(const Unk_127d4f0* self) {
    self->field_0->field_b0 = 1;
    return 1;
}

// 0x710127d510
void Unk_127d510_update() {}

struct Unk_127d520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d520_arg1, field_0, 0x0);

struct Unk_127d520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d520, field_0, 0x0);

// 0x710127d520
void Unk_127d520_set(const Unk_127d520* self, Unk_127d520_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_127d530_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d530_arg1, field_0, 0x0);

struct Unk_127d530 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_127d530, field_0, 0x0);

// 0x710127d530
void Unk_127d530_set(const Unk_127d530* self, Unk_127d530_arg1* value) {
    value->field_0 = self->field_0;
}
