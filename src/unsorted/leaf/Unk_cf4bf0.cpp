// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

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
