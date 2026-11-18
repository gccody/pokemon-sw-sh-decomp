// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71012769c0
void Unk_12769c0_update() {}

// 0x71012769d0
void Unk_12769d0_update() {}

// 0x71012769e0
void Unk_12769e0_update() {}

// 0x71012769f0
void Unk_12769f0_update() {}

// 0x7101276a90
void Unk_1276a90_update() {}

struct Unk_1276aa0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1276aa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1276aa0, field_8, 0x8);

// 0x7101276aa0
void Unk_1276aa0_set(const Unk_1276aa0* self, Unk_1276aa0* value) {
    *value = *self;
}

struct Unk_1276ab0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1276ab0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1276ab0, field_8, 0x8);

// 0x7101276ab0
void Unk_1276ab0_set(const Unk_1276ab0* self, Unk_1276ab0* value) {
    *value = *self;
}

// 0x7101277460
void Unk_1277460_update() {}

// 0x7101277470
void Unk_1277470_update() {}

// 0x7101277480
void Unk_1277480_update() {}

// 0x7101277490
void Unk_1277490_update() {}

struct Unk_1278360 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278360, field_0, 0x0);

void Unk_1277bd0(u64);

// 0x7101278360
void Unk_1278360_call(const Unk_1278360* self) {
    Unk_1277bd0(self->field_0);
}

// 0x7101278370
void Unk_1278370_update() {}

struct Unk_1278380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278380_arg1, field_0, 0x0);

struct Unk_1278380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278380, field_0, 0x0);

// 0x7101278380
void Unk_1278380_set(const Unk_1278380* self, Unk_1278380_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1278390_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278390_arg1, field_0, 0x0);

struct Unk_1278390 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278390, field_0, 0x0);

// 0x7101278390
void Unk_1278390_set(const Unk_1278390* self, Unk_1278390_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101278670
void Unk_1278670_update() {}

struct Unk_1278680_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278680_arg1, field_0, 0x0);

struct Unk_1278680 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278680, field_0, 0x0);

// 0x7101278680
void Unk_1278680_set(const Unk_1278680* self, Unk_1278680_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1278690_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278690_arg1, field_0, 0x0);

struct Unk_1278690 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1278690, field_0, 0x0);

// 0x7101278690
void Unk_1278690_set(const Unk_1278690* self, Unk_1278690_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012786b0
void Unk_12786b0_update() {}

struct Unk_12786c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12786c0_arg1, field_0, 0x0);

struct Unk_12786c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12786c0, field_0, 0x0);

// 0x71012786c0
void Unk_12786c0_set(const Unk_12786c0* self, Unk_12786c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12786d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12786d0_arg1, field_0, 0x0);

struct Unk_12786d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12786d0, field_0, 0x0);

// 0x71012786d0
void Unk_12786d0_set(const Unk_12786d0* self, Unk_12786d0_arg1* value) {
    value->field_0 = self->field_0;
}
