// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1211400 {
    u8 _0[0x4d8];
    u64 field_4d8;
    u64 field_4e0;
};
PKMN_OFFSET_ASSERT(Unk_1211400, field_4d8, 0x4d8);
PKMN_OFFSET_ASSERT(Unk_1211400, field_4e0, 0x4e0);

void Unk_117a630(u64);

// 0x7101211400
void Unk_1211400_call(const Unk_1211400* self) {
    Unk_117a630(self->field_4d8);
    Unk_117a630(self->field_4e0);
}

// 0x71012121f0
void Unk_12121f0_update() {}

struct Unk_1213420 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1213420, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1213420, field_8, 0x8);

// 0x7101213420
void Unk_1213420_set(const Unk_1213420* self, Unk_1213420* value) {
    *value = *self;
}

struct Unk_1213430 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1213430, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1213430, field_8, 0x8);

// 0x7101213430
void Unk_1213430_set(const Unk_1213430* self, Unk_1213430* value) {
    *value = *self;
}

// 0x7101213ce0
void Unk_1213ce0_update() {}

struct Unk_1214eb0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1214eb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1214eb0, field_8, 0x8);

// 0x7101214eb0
void Unk_1214eb0_set(const Unk_1214eb0* self, Unk_1214eb0* value) {
    *value = *self;
}

struct Unk_1214ec0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1214ec0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1214ec0, field_8, 0x8);

// 0x7101214ec0
void Unk_1214ec0_set(const Unk_1214ec0* self, Unk_1214ec0* value) {
    *value = *self;
}

struct Unk_1215350 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1215350, field_60, 0x60);

// 0x7101215350
u32 Unk_1215350_getField60(const Unk_1215350* self) {
    return self->field_60;
}

struct Unk_1215d60 {
    u8 _0[0xa0];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1215d60, field_a0, 0xa0);

// 0x7101215d60
u8 Unk_1215d60_getFielda0(const Unk_1215d60* self) {
    return self->field_a0;
}

struct Unk_1216490 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1216490, field_68, 0x68);

// 0x7101216490
u64 Unk_1216490_getField68(const Unk_1216490* self) {
    return self->field_68;
}

struct Unk_12165b0_68 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_12165b0_68, field_98, 0x98);

struct Unk_12165b0 {
    u8 _0[0x68];
    Unk_12165b0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_12165b0, field_68, 0x68);

// 0x71012165b0
u64 Unk_12165b0_get(const Unk_12165b0* self) {
    return self->field_68->field_98;
}

// 0x7101217440
void Unk_1217440_update() {}

struct Unk_1217450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217450_arg1, field_0, 0x0);

struct Unk_1217450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217450, field_0, 0x0);

// 0x7101217450
void Unk_1217450_set(const Unk_1217450* self, Unk_1217450_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1217460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217460_arg1, field_0, 0x0);

struct Unk_1217460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217460, field_0, 0x0);

// 0x7101217460
void Unk_1217460_set(const Unk_1217460* self, Unk_1217460_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1217470_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217470_arg1, field_0, 0x0);

void Unk_115ce10(u64, u32);

// 0x7101217470
void Unk_1217470_call(void* /*unused*/, const Unk_1217470_arg1* value) {
    Unk_115ce10(value->field_0, 1);
}

// 0x7101217480
void Unk_1217480_update() {}

// 0x7101217490
void Unk_1217490_update() {}

// 0x71012174a0
void Unk_12174a0_update() {}

// 0x7101217500
void Unk_1217500_update() {}

struct Unk_1217510_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217510_arg1, field_0, 0x0);

struct Unk_1217510 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217510, field_0, 0x0);

// 0x7101217510
void Unk_1217510_set(const Unk_1217510* self, Unk_1217510_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1217520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217520_arg1, field_0, 0x0);

struct Unk_1217520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1217520, field_0, 0x0);

// 0x7101217520
void Unk_1217520_set(const Unk_1217520* self, Unk_1217520_arg1* value) {
    value->field_0 = self->field_0;
}
