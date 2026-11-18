// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100fb7930
void Unk_fb7930_update() {}

struct Unk_fb7940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb7940_arg1, field_0, 0x0);

struct Unk_fb7940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb7940, field_0, 0x0);

// 0x7100fb7940
void Unk_fb7940_set(const Unk_fb7940* self, Unk_fb7940_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb7950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb7950_arg1, field_0, 0x0);

struct Unk_fb7950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb7950, field_0, 0x0);

// 0x7100fb7950
void Unk_fb7950_set(const Unk_fb7950* self, Unk_fb7950_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb7960_0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_fb7960_0, field_58, 0x58);

struct Unk_fb7960 {
    Unk_fb7960_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb7960, field_0, 0x0);

// 0x7100fb7960
u32 Unk_fb7960_update(const Unk_fb7960* self) {
    self->field_0->field_58 = self->field_0->field_58 | 1;
    return 1;
}

// 0x7100fb7980
void Unk_fb7980_update() {}

struct Unk_fb7990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb7990_arg1, field_0, 0x0);

struct Unk_fb7990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb7990, field_0, 0x0);

// 0x7100fb7990
void Unk_fb7990_set(const Unk_fb7990* self, Unk_fb7990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_fb79a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb79a0_arg1, field_0, 0x0);

struct Unk_fb79a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_fb79a0, field_0, 0x0);

// 0x7100fb79a0
void Unk_fb79a0_set(const Unk_fb79a0* self, Unk_fb79a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100fb7a10
void Unk_fb7a10_update() {}

struct Unk_fb7a20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb7a20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb7a20, field_8, 0x8);

// 0x7100fb7a20
void Unk_fb7a20_set(const Unk_fb7a20* self, Unk_fb7a20* value) {
    *value = *self;
}

struct Unk_fb7a30 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_fb7a30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_fb7a30, field_8, 0x8);

// 0x7100fb7a30
void Unk_fb7a30_set(const Unk_fb7a30* self, Unk_fb7a30* value) {
    *value = *self;
}

struct Unk_fb9120 {
    u8 _0[0x154];
    u32 field_154;
};
PKMN_OFFSET_ASSERT(Unk_fb9120, field_154, 0x154);

// 0x7100fb9120
void Unk_fb9120_setField154(Unk_fb9120* self, u32 value) {
    self->field_154 = value;
}

struct Unk_fb9130 {
    u8 _0[0x154];
    u32 field_154;
};
PKMN_OFFSET_ASSERT(Unk_fb9130, field_154, 0x154);

// 0x7100fb9130
void Unk_fb9130_set(Unk_fb9130* self) {
    self->field_154 = 0xffffffff;
}
