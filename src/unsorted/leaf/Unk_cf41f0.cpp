// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100cf41f0
void Unk_cf41f0_update() {}

struct Unk_cf43a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cf43a0_arg1, field_0, 0x0);

struct Unk_cf43a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cf43a0, field_0, 0x0);

// 0x7100cf43a0
void Unk_cf43a0_set(const Unk_cf43a0* self, Unk_cf43a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cf43b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cf43b0_arg1, field_0, 0x0);

struct Unk_cf43b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cf43b0, field_0, 0x0);

// 0x7100cf43b0
void Unk_cf43b0_set(const Unk_cf43b0* self, Unk_cf43b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cf4bf0_78 {
    u8 _0[0x138];
    u64 field_138;
};
PKMN_OFFSET_ASSERT(Unk_cf4bf0_78, field_138, 0x138);

struct Unk_cf4bf0 {
    u8 _0[0x78];
    Unk_cf4bf0_78* field_78;
};
PKMN_OFFSET_ASSERT(Unk_cf4bf0, field_78, 0x78);

// 0x7100cf4bf0
void Unk_cf4bf0_set(const Unk_cf4bf0* self, u64 value) {
    self->field_78->field_138 = value;
}

struct Unk_cf5730 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_cf5730, field_78, 0x78);

void Unk_cf5740(u64);

// 0x7100cf5730
void Unk_cf5730_call(const Unk_cf5730* self) {
    Unk_cf5740(self->field_78);
}

struct Unk_cf7230_78 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_cf7230_78, field_60, 0x60);

struct Unk_cf7230 {
    u8 _0[0x78];
    Unk_cf7230_78* field_78;
};
PKMN_OFFSET_ASSERT(Unk_cf7230, field_78, 0x78);

// 0x7100cf7230
void Unk_cf7230_set(const Unk_cf7230* self, u64 value) {
    self->field_78->field_60 = value;
}

struct Unk_cf93e0 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_cf93e0, field_80, 0x80);

// 0x7100cf93e0
void Unk_cf93e0_set(Unk_cf93e0* self) {
    self->field_80 = self->field_80 - 1;
}

struct Unk_cf9870 {
    u8 _0[0x9c];
    u32 field_9c;
};
PKMN_OFFSET_ASSERT(Unk_cf9870, field_9c, 0x9c);

// 0x7100cf9870
void Unk_cf9870_set(Unk_cf9870* self) {
    self->field_9c = self->field_9c - 1;
}

struct Unk_cf9b90 {
    u8 _0[0xb8];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_cf9b90, field_b8, 0xb8);

// 0x7100cf9b90
void Unk_cf9b90_set(Unk_cf9b90* self) {
    self->field_b8 = self->field_b8 - 1;
}

// 0x7100cfa360
void Unk_cfa360_update() {}

struct Unk_cfa370 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_cfa370, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_cfa370, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_cfa370, field_10, 0x10);

// 0x7100cfa370
void Unk_cfa370_set(const Unk_cfa370* self, Unk_cfa370* value) {
    *value = *self;
}

struct Unk_cfa390 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_cfa390, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_cfa390, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_cfa390, field_10, 0x10);

// 0x7100cfa390
void Unk_cfa390_set(const Unk_cfa390* self, Unk_cfa390* value) {
    *value = *self;
}

struct Unk_cfe170 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe170, field_0, 0x0);

void Unk_cfe190(u64, u64, u32);

// 0x7100cfe170
void Unk_cfe170_call(const Unk_cfe170* self, u64 value) {
    Unk_cfe190(self->field_0, value, 0);
}

// 0x7100cfe180
void Unk_cfe180_update() {}

struct Unk_cfe590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe590_arg1, field_0, 0x0);

struct Unk_cfe590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe590, field_0, 0x0);

// 0x7100cfe590
void Unk_cfe590_set(const Unk_cfe590* self, Unk_cfe590_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cfe5a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe5a0_arg1, field_0, 0x0);

struct Unk_cfe5a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe5a0, field_0, 0x0);

// 0x7100cfe5a0
void Unk_cfe5a0_set(const Unk_cfe5a0* self, Unk_cfe5a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cfe5b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe5b0, field_0, 0x0);

void Unk_cfe5d0(u64);

// 0x7100cfe5b0
void Unk_cfe5b0_call(const Unk_cfe5b0* self) {
    Unk_cfe5d0(self->field_0);
}

// 0x7100cfe5c0
void Unk_cfe5c0_update() {}

struct Unk_cfe760_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe760_arg1, field_0, 0x0);

struct Unk_cfe760 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe760, field_0, 0x0);

// 0x7100cfe760
void Unk_cfe760_set(const Unk_cfe760* self, Unk_cfe760_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cfe770_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe770_arg1, field_0, 0x0);

struct Unk_cfe770 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe770, field_0, 0x0);

// 0x7100cfe770
void Unk_cfe770_set(const Unk_cfe770* self, Unk_cfe770_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cfe780 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe780, field_0, 0x0);

void Unk_cfe190(u64, u64, u32);

// 0x7100cfe780
void Unk_cfe780_call(const Unk_cfe780* self, u64 value) {
    Unk_cfe190(self->field_0, value, 1);
}

// 0x7100cfe790
void Unk_cfe790_update() {}

struct Unk_cfe7a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7a0_arg1, field_0, 0x0);

struct Unk_cfe7a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7a0, field_0, 0x0);

// 0x7100cfe7a0
void Unk_cfe7a0_set(const Unk_cfe7a0* self, Unk_cfe7a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cfe7b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7b0_arg1, field_0, 0x0);

struct Unk_cfe7b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7b0, field_0, 0x0);

// 0x7100cfe7b0
void Unk_cfe7b0_set(const Unk_cfe7b0* self, Unk_cfe7b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cfe7c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7c0, field_0, 0x0);

void Unk_cfe5d0(u64);

// 0x7100cfe7c0
void Unk_cfe7c0_call(const Unk_cfe7c0* self) {
    Unk_cfe5d0(self->field_0);
}

// 0x7100cfe7d0
void Unk_cfe7d0_update() {}

struct Unk_cfe7e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7e0_arg1, field_0, 0x0);

struct Unk_cfe7e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7e0, field_0, 0x0);

// 0x7100cfe7e0
void Unk_cfe7e0_set(const Unk_cfe7e0* self, Unk_cfe7e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cfe7f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7f0_arg1, field_0, 0x0);

struct Unk_cfe7f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cfe7f0, field_0, 0x0);

// 0x7100cfe7f0
void Unk_cfe7f0_set(const Unk_cfe7f0* self, Unk_cfe7f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d00dd0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d00dd0_arg1, field_0, 0x0);

struct Unk_d00dd0 {
    u8 _0[0x6a8];
    u32 field_6a8;
};
PKMN_OFFSET_ASSERT(Unk_d00dd0, field_6a8, 0x6a8);

// 0x7100d00dd0
void Unk_d00dd0_set(Unk_d00dd0* self, const Unk_d00dd0_arg1* value) {
    self->field_6a8 = value->field_0;
}

struct Unk_d00de0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d00de0_arg1, field_0, 0x0);

struct Unk_d00de0_arg2 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d00de0_arg2, field_0, 0x0);

struct Unk_d00de0 {
    u8 _0[0x6b4];
    u32 field_6b4;
    u32 field_6b8;
};
PKMN_OFFSET_ASSERT(Unk_d00de0, field_6b4, 0x6b4);
PKMN_OFFSET_ASSERT(Unk_d00de0, field_6b8, 0x6b8);

// 0x7100d00de0
void Unk_d00de0_set(Unk_d00de0* self, const Unk_d00de0_arg1* value, const Unk_d00de0_arg2* arg2) {
    self->field_6b4 = value->field_0;
    self->field_6b8 = arg2->field_0;
}

// 0x7100d021e0
void Unk_d021e0_update() {}

struct Unk_d021f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d021f0_arg1, field_0, 0x0);

struct Unk_d021f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d021f0, field_0, 0x0);

// 0x7100d021f0
void Unk_d021f0_set(const Unk_d021f0* self, Unk_d021f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d02200_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d02200_arg1, field_0, 0x0);

struct Unk_d02200 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d02200, field_0, 0x0);

// 0x7100d02200
void Unk_d02200_set(const Unk_d02200* self, Unk_d02200_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100d03590
void Unk_d03590_update() {}

struct Unk_d035a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d035a0_arg1, field_0, 0x0);

struct Unk_d035a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d035a0, field_0, 0x0);

// 0x7100d035a0
void Unk_d035a0_set(const Unk_d035a0* self, Unk_d035a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d035b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d035b0_arg1, field_0, 0x0);

struct Unk_d035b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d035b0, field_0, 0x0);

// 0x7100d035b0
void Unk_d035b0_set(const Unk_d035b0* self, Unk_d035b0_arg1* value) {
    value->field_0 = self->field_0;
}
