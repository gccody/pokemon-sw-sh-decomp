// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101433730
void Unk_1433730_update() {}

struct Unk_1433740 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1433740, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1433740, field_8, 0x8);

// 0x7101433740
void Unk_1433740_set(const Unk_1433740* self, Unk_1433740* value) {
    *value = *self;
}

struct Unk_1433750 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1433750, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1433750, field_8, 0x8);

// 0x7101433750
void Unk_1433750_set(const Unk_1433750* self, Unk_1433750* value) {
    *value = *self;
}

// 0x7101433790
void Unk_1433790_update() {}

struct Unk_14337a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_14337a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14337a0, field_8, 0x8);

// 0x71014337a0
void Unk_14337a0_set(const Unk_14337a0* self, Unk_14337a0* value) {
    *value = *self;
}

struct Unk_14337b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_14337b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14337b0, field_8, 0x8);

// 0x71014337b0
void Unk_14337b0_set(const Unk_14337b0* self, Unk_14337b0* value) {
    *value = *self;
}

// 0x7101433830
void Unk_1433830_update() {}

struct Unk_1433840 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1433840, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1433840, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1433840, field_10, 0x10);

// 0x7101433840
void Unk_1433840_set(const Unk_1433840* self, Unk_1433840* value) {
    *value = *self;
}

struct Unk_1433860 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1433860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1433860, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1433860, field_10, 0x10);

// 0x7101433860
void Unk_1433860_set(const Unk_1433860* self, Unk_1433860* value) {
    *value = *self;
}

// 0x71014338a0
void Unk_14338a0_update() {}

struct Unk_14338b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14338b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14338b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14338b0, field_10, 0x10);

// 0x71014338b0
void Unk_14338b0_set(const Unk_14338b0* self, Unk_14338b0* value) {
    *value = *self;
}

struct Unk_14338d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14338d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14338d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14338d0, field_10, 0x10);

// 0x71014338d0
void Unk_14338d0_set(const Unk_14338d0* self, Unk_14338d0* value) {
    *value = *self;
}

struct Unk_1434750 {
    u8 _0[0x50];
    u32 field_50;
    u16 field_54;
};
PKMN_OFFSET_ASSERT(Unk_1434750, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_1434750, field_54, 0x54);

// 0x7101434750
void Unk_1434750_set(Unk_1434750* self) {
    self->field_54 = 0;
    self->field_50 = 0;
}

// 0x71014357f0
u64 Unk_14357f0_get() {
    return 0xfc06cb2c3f628f41;
}

// 0x7101435810
u64 Unk_1435810_get() {
    return 0xfc03492c3f5f7c84;
}

struct Unk_1435ec0 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_1435ec0, field_88, 0x88);

void Unk_eb8a30(u64, u32);

// 0x7101435ec0
void Unk_1435ec0_call(const Unk_1435ec0* self) {
    Unk_eb8a30(self->field_88, 1);
}

// 0x710143a230
void Unk_143a230_update() {}

struct Unk_143a240_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143a240_arg1, field_0, 0x0);

struct Unk_143a240 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143a240, field_0, 0x0);

// 0x710143a240
void Unk_143a240_set(const Unk_143a240* self, Unk_143a240_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_143a250_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143a250_arg1, field_0, 0x0);

struct Unk_143a250 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_143a250, field_0, 0x0);

// 0x710143a250
void Unk_143a250_set(const Unk_143a250* self, Unk_143a250_arg1* value) {
    value->field_0 = self->field_0;
}
