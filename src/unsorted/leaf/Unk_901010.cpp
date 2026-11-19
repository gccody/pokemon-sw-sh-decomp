// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100901010
void Unk_901010_update() {}

struct Unk_901020_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901020_arg1, field_0, 0x0);

struct Unk_901020 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901020, field_0, 0x0);

// 0x7100901020
void Unk_901020_set(const Unk_901020* self, Unk_901020_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_901030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901030_arg1, field_0, 0x0);

struct Unk_901030 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901030, field_0, 0x0);

// 0x7100901030
void Unk_901030_set(const Unk_901030* self, Unk_901030_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100901060
void Unk_901060_update() {}

struct Unk_901070_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901070_arg1, field_0, 0x0);

struct Unk_901070 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901070, field_0, 0x0);

// 0x7100901070
void Unk_901070_set(const Unk_901070* self, Unk_901070_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_901080_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901080_arg1, field_0, 0x0);

struct Unk_901080 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901080, field_0, 0x0);

// 0x7100901080
void Unk_901080_set(const Unk_901080* self, Unk_901080_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71009010b0
void Unk_9010b0_update() {}

struct Unk_9010c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9010c0_arg1, field_0, 0x0);

struct Unk_9010c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9010c0, field_0, 0x0);

// 0x71009010c0
void Unk_9010c0_set(const Unk_9010c0* self, Unk_9010c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9010d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9010d0_arg1, field_0, 0x0);

struct Unk_9010d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9010d0, field_0, 0x0);

// 0x71009010d0
void Unk_9010d0_set(const Unk_9010d0* self, Unk_9010d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100901100
void Unk_901100_update() {}

struct Unk_901110_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901110_arg1, field_0, 0x0);

struct Unk_901110 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901110, field_0, 0x0);

// 0x7100901110
void Unk_901110_set(const Unk_901110* self, Unk_901110_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_901120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901120_arg1, field_0, 0x0);

struct Unk_901120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_901120, field_0, 0x0);

// 0x7100901120
void Unk_901120_set(const Unk_901120* self, Unk_901120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_901130 {
    u64 field_0;
    u64 field_8;
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_901130, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_901130, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_901130, field_10, 0x10);

void Unk_9003a0(u64, u64, u64);

// 0x7100901130
u32 Unk_901130_call(const Unk_901130* self) {
    Unk_9003a0(self->field_0, self->field_10 == 0 ? 0 : self->field_8,
               self->field_10 == 0 ? self->field_8 : 0);
    return 1;
}

// 0x7100901160
void Unk_901160_update() {}

struct Unk_901170 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_901170, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_901170, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_901170, field_10, 0x10);

// 0x7100901170
void Unk_901170_set(const Unk_901170* self, Unk_901170* value) {
    *value = *self;
}

struct Unk_901190 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_901190, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_901190, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_901190, field_10, 0x10);

// 0x7100901190
void Unk_901190_set(const Unk_901190* self, Unk_901190* value) {
    *value = *self;
}
