// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_803a10 {
    u64 field_0;
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_803a10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_803a10, field_8, 0x8);

// 0x7100803a10
void Unk_803a10_set(Unk_803a10* self) {
    self->field_8 = 0;
    self->field_0 = 0;
}

struct Unk_803a20 {
    u64 field_0;
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_803a20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_803a20, field_8, 0x8);

// 0x7100803a20
void Unk_803a20_set(Unk_803a20* self) {
    self->field_8 = 0;
    self->field_0 = 0;
}

struct Unk_803c60 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_803c60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_803c60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_803c60, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_803c60, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_803c60, field_20, 0x20);

// 0x7100803c60
void Unk_803c60_set(Unk_803c60* self) {
    self->field_20 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

struct Unk_803c70 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_803c70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_803c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_803c70, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_803c70, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_803c70, field_20, 0x20);

// 0x7100803c70
void Unk_803c70_set(Unk_803c70* self) {
    self->field_20 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

struct Unk_803d10 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_803d10, field_2, 0x2);

// 0x7100803d10
bool Unk_803d10_check(const Unk_803d10* self) {
    return (self->field_2 & 0x7f) != 0;
}

struct Unk_803d20 {
    u16 field_0;
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_803d20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_803d20, field_2, 0x2);

// 0x7100803d20
void Unk_803d20_set(Unk_803d20* self, u32 value, u16 arg2) {
    self->field_0 = arg2;
    self->field_2 = ((self->field_2 & 0xc000) & 0xffffff80) | (value & 0x7f);
}

struct Unk_803d40 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_803d40, field_0, 0x0);

// 0x7100803d40
u16 Unk_803d40_getField0(const Unk_803d40* self) {
    return self->field_0;
}

struct Unk_803d50 {
    u8 _0[0x2];
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_803d50, field_2, 0x2);

// 0x7100803d50
u32 Unk_803d50_get(const Unk_803d50* self) {
    return self->field_2 & 0x7f;
}

struct Unk_803db0 {
    u8 _0[0x2];
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_803db0, field_2, 0x2);

// 0x7100803db0
u32 Unk_803db0_get(const Unk_803db0* self) {
    return (self->field_2 >> 7) & 0x7f;
}

struct Unk_803dc0 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_803dc0, field_4, 0x4);

// 0x7100803dc0
u8* Unk_803dc0_getField4Ptr(Unk_803dc0* self) {
    return &self->field_4;
}

struct Unk_803df0 {
    u8 _0[0x3];
    u8 field_3;
};
PKMN_OFFSET_ASSERT(Unk_803df0, field_3, 0x3);

// 0x7100803df0
u32 Unk_803df0_get(const Unk_803df0* self) {
    return (self->field_3 >> 6) & 1;
}

struct Unk_803e00 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_803e00, field_20, 0x20);

// 0x7100803e00
u32 Unk_803e00_getField20(const Unk_803e00* self) {
    return self->field_20;
}

struct Unk_803e10 {
    u8 _0[0x2];
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_803e10, field_2, 0x2);

// 0x7100803e10
void Unk_803e10_set(Unk_803e10* self) {
    self->field_2 = self->field_2 | 0x8000;
}

struct Unk_803e20 {
    u8 _0[0x2];
    s16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_803e20, field_2, 0x2);

// 0x7100803e20
bool Unk_803e20_check(const Unk_803e20* self) {
    return self->field_2 < 0;
}

// 0x7100803e30
u32 Unk_803e30_get() {
    return 3;
}
