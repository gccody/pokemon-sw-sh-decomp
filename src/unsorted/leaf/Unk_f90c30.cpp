// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100f90c30
void Unk_f90c30_update() {}

// 0x7100f90c40
void Unk_f90c40_update() {}

// 0x7100f90c50
void Unk_f90c50_update() {}

// 0x7100f90c60
void Unk_f90c60_update() {}

struct Unk_f90c70_0 {
    u8 _0[0x1f8];
    u8 field_1f8;
    u8 _1f9[0x3];
    u32 field_1fc;
};
PKMN_OFFSET_ASSERT(Unk_f90c70_0, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_f90c70_0, field_1fc, 0x1fc);

struct Unk_f90c70 {
    Unk_f90c70_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90c70, field_0, 0x0);

// 0x7100f90c70
void Unk_f90c70_set(const Unk_f90c70* self) {
    Unk_f90c70_0* p0 = self->field_0;
    p0->field_1fc = 1;
    p0->field_1f8 = 1;
}

// 0x7100f90c90
void Unk_f90c90_update() {}

struct Unk_f90ca0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90ca0_arg1, field_0, 0x0);

struct Unk_f90ca0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90ca0, field_0, 0x0);

// 0x7100f90ca0
void Unk_f90ca0_set(const Unk_f90ca0* self, Unk_f90ca0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f90cb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90cb0_arg1, field_0, 0x0);

struct Unk_f90cb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f90cb0, field_0, 0x0);

// 0x7100f90cb0
void Unk_f90cb0_set(const Unk_f90cb0* self, Unk_f90cb0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f914f0
void Unk_f914f0_update() {}

// 0x7100f91500
void Unk_f91500_update() {}

// 0x7100f91510
void Unk_f91510_update() {}

// 0x7100f91520
void Unk_f91520_update() {}

// 0x7100f91720
void Unk_f91720_update() {}

struct Unk_f91730_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f91730_arg1, field_0, 0x0);

struct Unk_f91730 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f91730, field_0, 0x0);

// 0x7100f91730
void Unk_f91730_set(const Unk_f91730* self, Unk_f91730_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f91740_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f91740_arg1, field_0, 0x0);

struct Unk_f91740 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f91740, field_0, 0x0);

// 0x7100f91740
void Unk_f91740_set(const Unk_f91740* self, Unk_f91740_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f96170
void Unk_f96170_update() {}

struct Unk_f96180_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f96180_arg1, field_0, 0x0);

struct Unk_f96180 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f96180, field_0, 0x0);

// 0x7100f96180
void Unk_f96180_set(const Unk_f96180* self, Unk_f96180_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f96190_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f96190_arg1, field_0, 0x0);

struct Unk_f96190 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f96190, field_0, 0x0);

// 0x7100f96190
void Unk_f96190_set(const Unk_f96190* self, Unk_f96190_arg1* value) {
    value->field_0 = self->field_0;
}
