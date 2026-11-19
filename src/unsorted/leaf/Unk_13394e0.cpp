// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71013394e0
void Unk_13394e0_update() {}

struct Unk_13394f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13394f0_arg1, field_0, 0x0);

struct Unk_13394f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13394f0, field_0, 0x0);

// 0x71013394f0
void Unk_13394f0_set(const Unk_13394f0* self, Unk_13394f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1339500_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1339500_arg1, field_0, 0x0);

struct Unk_1339500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1339500, field_0, 0x0);

// 0x7101339500
void Unk_1339500_set(const Unk_1339500* self, Unk_1339500_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101339510
void Unk_1339510_update() {}

// 0x7101339520
void Unk_1339520_update() {}

// 0x7101339530
void Unk_1339530_update() {}

// 0x7101339540
void Unk_1339540_update() {}

// 0x7101339550
void Unk_1339550_update() {}

// 0x7101339560
void Unk_1339560_update() {}

// 0x7101339570
void Unk_1339570_update() {}

// 0x7101339580
void Unk_1339580_update() {}

// 0x7101339590
void Unk_1339590_update() {}

// 0x71013395a0
void Unk_13395a0_update() {}

// 0x71013395b0
void Unk_13395b0_update() {}

// 0x71013395c0
void Unk_13395c0_update() {}

// 0x7101339640
void Unk_1339640_update() {}

struct Unk_1339650_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1339650_arg1, field_0, 0x0);

struct Unk_1339650 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1339650, field_0, 0x0);

// 0x7101339650
void Unk_1339650_set(const Unk_1339650* self, Unk_1339650_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1339660_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1339660_arg1, field_0, 0x0);

struct Unk_1339660 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1339660, field_0, 0x0);

// 0x7101339660
void Unk_1339660_set(const Unk_1339660* self, Unk_1339660_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101339670
void Unk_1339670_update() {}

// 0x7101339680
void Unk_1339680_update() {}

// 0x7101339690
void Unk_1339690_update() {}

// 0x71013396a0
void Unk_13396a0_update() {}

struct Unk_133be90 {
    u8 _0[0x600];
    void* field_600;
};
PKMN_OFFSET_ASSERT(Unk_133be90, field_600, 0x600);

void Unk_14e1a00(void*, u32);

// 0x710133be90
void Unk_133be90_call(const Unk_133be90* self, bool value) {
    Unk_14e1a00(self->field_600, value);
}

struct Unk_133d080_0 {
    u8 _0[0x5f8];
    u8 field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_133d080_0, field_5f8, 0x5f8);

struct Unk_133d080 {
    Unk_133d080_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_133d080, field_0, 0x0);

// 0x710133d080
void Unk_133d080_set(const Unk_133d080* self) {
    self->field_0->field_5f8 = 1;
}

// 0x710133d090
void Unk_133d090_update() {}

struct Unk_133d0a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_133d0a0_arg1, field_0, 0x0);

struct Unk_133d0a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_133d0a0, field_0, 0x0);

// 0x710133d0a0
void Unk_133d0a0_set(const Unk_133d0a0* self, Unk_133d0a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_133d0b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_133d0b0_arg1, field_0, 0x0);

struct Unk_133d0b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_133d0b0, field_0, 0x0);

// 0x710133d0b0
void Unk_133d0b0_set(const Unk_133d0b0* self, Unk_133d0b0_arg1* value) {
    value->field_0 = self->field_0;
}
