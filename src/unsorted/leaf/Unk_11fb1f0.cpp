// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011fb1f0
void Unk_11fb1f0_update() {}

struct Unk_11fb200_arg1 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11fb200_arg1, field_0, 0x0);

struct Unk_11fb200 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11fb200, field_0, 0x0);

// 0x71011fb200
void Unk_11fb200_set(const Unk_11fb200* self, Unk_11fb200_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11fb210_arg1 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11fb210_arg1, field_0, 0x0);

struct Unk_11fb210 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11fb210, field_0, 0x0);

// 0x71011fb210
void Unk_11fb210_set(const Unk_11fb210* self, Unk_11fb210_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011fb310
void Unk_11fb310_update() {}

struct Unk_11fb320_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11fb320_arg1, field_0, 0x0);

struct Unk_11fb320 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11fb320, field_0, 0x0);

// 0x71011fb320
void Unk_11fb320_set(const Unk_11fb320* self, Unk_11fb320_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11fb330_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11fb330_arg1, field_0, 0x0);

struct Unk_11fb330 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11fb330, field_0, 0x0);

// 0x71011fb330
void Unk_11fb330_set(const Unk_11fb330* self, Unk_11fb330_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011fb4d0
void Unk_11fb4d0_update() {}

struct Unk_11fb4e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11fb4e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11fb4e0, field_8, 0x8);

// 0x71011fb4e0
void Unk_11fb4e0_set(const Unk_11fb4e0* self, Unk_11fb4e0* value) {
    *value = *self;
}

struct Unk_11fb4f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11fb4f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11fb4f0, field_8, 0x8);

// 0x71011fb4f0
void Unk_11fb4f0_set(const Unk_11fb4f0* self, Unk_11fb4f0* value) {
    *value = *self;
}
