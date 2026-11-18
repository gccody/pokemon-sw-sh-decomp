// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12e3f20_5e0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_12e3f20_5e0, field_58, 0x58);

struct Unk_12e3f20 {
    u8 _0[0x5e0];
    Unk_12e3f20_5e0* field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_12e3f20, field_5e0, 0x5e0);

// 0x71012e3f20
void Unk_12e3f20_set(const Unk_12e3f20* self, bool value) {
    self->field_5e0->field_58 = (self->field_5e0->field_58 & 0xfffffffe) | (value);
}

struct Unk_12e4930_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x2c8];
    u32 field_790;
};
PKMN_OFFSET_ASSERT(Unk_12e4930_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_12e4930_0, field_790, 0x790);

struct Unk_12e4930 {
    Unk_12e4930_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4930, field_0, 0x0);

void Unk_1500c40(u64);

// 0x71012e4930
void Unk_12e4930_call(const Unk_12e4930* self) {
    Unk_12e4930_0* p0 = self->field_0;
    p0->field_790 = 0;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x71012e4950
void Unk_12e4950_update() {}

struct Unk_12e4960_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4960_arg1, field_0, 0x0);

struct Unk_12e4960 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4960, field_0, 0x0);

// 0x71012e4960
void Unk_12e4960_set(const Unk_12e4960* self, Unk_12e4960_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12e4970_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4970_arg1, field_0, 0x0);

struct Unk_12e4970 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4970, field_0, 0x0);

// 0x71012e4970
void Unk_12e4970_set(const Unk_12e4970* self, Unk_12e4970_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012e4a70
void Unk_12e4a70_update() {}

struct Unk_12e4a80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4a80_arg1, field_0, 0x0);

struct Unk_12e4a80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4a80, field_0, 0x0);

// 0x71012e4a80
void Unk_12e4a80_set(const Unk_12e4a80* self, Unk_12e4a80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12e4a90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4a90_arg1, field_0, 0x0);

struct Unk_12e4a90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4a90, field_0, 0x0);

// 0x71012e4a90
void Unk_12e4a90_set(const Unk_12e4a90* self, Unk_12e4a90_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012e4fa0
void Unk_12e4fa0_update() {}

struct Unk_12e4fb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4fb0_arg1, field_0, 0x0);

struct Unk_12e4fb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4fb0, field_0, 0x0);

// 0x71012e4fb0
void Unk_12e4fb0_set(const Unk_12e4fb0* self, Unk_12e4fb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12e4fc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4fc0_arg1, field_0, 0x0);

struct Unk_12e4fc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e4fc0, field_0, 0x0);

// 0x71012e4fc0
void Unk_12e4fc0_set(const Unk_12e4fc0* self, Unk_12e4fc0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012e50e0
void Unk_12e50e0_update() {}

struct Unk_12e50f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e50f0_arg1, field_0, 0x0);

struct Unk_12e50f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e50f0, field_0, 0x0);

// 0x71012e50f0
void Unk_12e50f0_set(const Unk_12e50f0* self, Unk_12e50f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12e5100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e5100_arg1, field_0, 0x0);

struct Unk_12e5100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e5100, field_0, 0x0);

// 0x71012e5100
void Unk_12e5100_set(const Unk_12e5100* self, Unk_12e5100_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71012e5440
void Unk_12e5440_update() {}

struct Unk_12e5450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e5450_arg1, field_0, 0x0);

struct Unk_12e5450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e5450, field_0, 0x0);

// 0x71012e5450
void Unk_12e5450_set(const Unk_12e5450* self, Unk_12e5450_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12e5460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e5460_arg1, field_0, 0x0);

struct Unk_12e5460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12e5460, field_0, 0x0);

// 0x71012e5460
void Unk_12e5460_set(const Unk_12e5460* self, Unk_12e5460_arg1* value) {
    value->field_0 = self->field_0;
}
