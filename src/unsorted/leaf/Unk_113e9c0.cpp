// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_113e9c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_113e9c0_arg1, field_0, 0x0);

struct Unk_113e9c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_113e9c0, field_0, 0x0);

// 0x710113e9c0
bool Unk_113e9c0_check(const Unk_113e9c0* self, const Unk_113e9c0_arg1* value) {
    return self->field_0 == value->field_0;
}

struct Unk_113e9e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_113e9e0_arg1, field_0, 0x0);

struct Unk_113e9e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_113e9e0, field_0, 0x0);

// 0x710113e9e0
bool Unk_113e9e0_check(const Unk_113e9e0* self, const Unk_113e9e0_arg1* value) {
    return self->field_0 != value->field_0;
}

struct Unk_113ea00 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_113ea00, field_8, 0x8);

// 0x710113ea00
bool Unk_113ea00_check(const Unk_113ea00* self) {
    return (self->field_8 & 0x10) == 0;
}

struct Unk_113f1b0 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_113f1b0, field_90, 0x90);

// 0x710113f1b0
u8 Unk_113f1b0_getField90(const Unk_113f1b0* self) {
    return self->field_90;
}

struct Unk_113f1c0 {
    u8 _0[0x90];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_113f1c0, field_90, 0x90);

// 0x710113f1c0
void Unk_113f1c0_set(Unk_113f1c0* self, bool value) {
    self->field_90 = value;
}

void Unk_1144890(u32, void*, u64, u64);

// 0x7101144cc0
void Unk_1144cc0_call(void* self, u64 value, u64 arg2) {
    Unk_1144890(7, self, value, arg2);
}

// 0x71011467f0
void Unk_11467f0_update() {}

// 0x7101146860
void Unk_1146860_update() {}

struct Unk_1146870 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1146870, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1146870, field_8, 0x8);

// 0x7101146870
void Unk_1146870_set(const Unk_1146870* self, Unk_1146870* value) {
    *value = *self;
}

struct Unk_1146880 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1146880, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1146880, field_8, 0x8);

// 0x7101146880
void Unk_1146880_set(const Unk_1146880* self, Unk_1146880* value) {
    *value = *self;
}

struct Unk_1146890_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1146890_arg1, field_0, 0x0);

struct Unk_1146890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1146890, field_0, 0x0);

// 0x7101146890
void Unk_1146890_set(const Unk_1146890* self, Unk_1146890_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11468a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11468a0_arg1, field_0, 0x0);

struct Unk_11468a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11468a0, field_0, 0x0);

// 0x71011468a0
void Unk_11468a0_set(const Unk_11468a0* self, Unk_11468a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101146950
void Unk_1146950_update() {}

struct Unk_1146960 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1146960, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1146960, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1146960, field_10, 0x10);

// 0x7101146960
void Unk_1146960_set(const Unk_1146960* self, Unk_1146960* value) {
    *value = *self;
}

struct Unk_1146980 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1146980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1146980, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1146980, field_10, 0x10);

// 0x7101146980
void Unk_1146980_set(const Unk_1146980* self, Unk_1146980* value) {
    *value = *self;
}

// 0x71011470c0
void Unk_11470c0_update() {}

struct Unk_1147150 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1147150, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1147150, field_8, 0x8);

// 0x7101147150
void Unk_1147150_set(const Unk_1147150* self, Unk_1147150* value) {
    *value = *self;
}

struct Unk_1147160 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1147160, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1147160, field_8, 0x8);

// 0x7101147160
void Unk_1147160_set(const Unk_1147160* self, Unk_1147160* value) {
    *value = *self;
}

struct Unk_1148770 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1148770, field_18, 0x18);

// 0x7101148770
void Unk_1148770_set(Unk_1148770* self, u32 value) {
    self->field_18 = value;
}

struct Unk_1148780 {
    u8 _0[0x1c];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_1148780, field_1c, 0x1c);

// 0x7101148780
void Unk_1148780_set(Unk_1148780* self, u32 value) {
    self->field_1c = value;
}

struct Unk_1148790 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_1148790, field_20, 0x20);

// 0x7101148790
void Unk_1148790_set(Unk_1148790* self, u32 value) {
    self->field_20 = value;
}
