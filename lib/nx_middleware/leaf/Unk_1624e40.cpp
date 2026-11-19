// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_1624e60(void*, void*, u64, u64);

// 0x7101624e40
void Unk_1624e40_call(void* self, u64 value, u64 arg2, void* arg3) {
    Unk_1624e60(arg3, self, value, arg2);
}

void Unk_1624fe0(void*, void*, u64, u64);

// 0x7101624fc0
void Unk_1624fc0_call(void* self, u64 value, u64 arg2, void* arg3) {
    Unk_1624fe0(arg3, self, value, arg2);
}

void Unk_1625150(void*, void*, u64, u64);

// 0x7101625130
void Unk_1625130_call(void* self, u64 value, u64 arg2, void* arg3) {
    Unk_1625150(arg3, self, value, arg2);
}

struct Unk_162a700 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_162a700, field_8, 0x8);

// 0x710162a700
u32 Unk_162a700_update(Unk_162a700* self, u32 value) {
    self->field_8 = value;
    return 0;
}

struct Unk_162ad70_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_162ad70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_162ad70_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_162ad70_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_162ad70_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_162ad70_arg1, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_162ad70_arg1, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_162ad70_arg1, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_162ad70_arg1, field_38, 0x38);

struct Unk_162ad70 {
    u8 _0[0x10c0];
    u64 field_10c0;
    u64 field_10c8;
    u64 field_10d0;
    u64 field_10d8;
    u64 field_10e0;
    u64 field_10e8;
    u64 field_10f0;
    u64 field_10f8;
};
PKMN_OFFSET_ASSERT(Unk_162ad70, field_10c0, 0x10c0);
PKMN_OFFSET_ASSERT(Unk_162ad70, field_10c8, 0x10c8);
PKMN_OFFSET_ASSERT(Unk_162ad70, field_10d0, 0x10d0);
PKMN_OFFSET_ASSERT(Unk_162ad70, field_10d8, 0x10d8);
PKMN_OFFSET_ASSERT(Unk_162ad70, field_10e0, 0x10e0);
PKMN_OFFSET_ASSERT(Unk_162ad70, field_10e8, 0x10e8);
PKMN_OFFSET_ASSERT(Unk_162ad70, field_10f0, 0x10f0);
PKMN_OFFSET_ASSERT(Unk_162ad70, field_10f8, 0x10f8);

// 0x710162ad70
void Unk_162ad70_set(Unk_162ad70* self, const Unk_162ad70_arg1* value) {
    u64 v0 = value->field_0;
    u64 v1 = value->field_10;
    u64 v2 = value->field_8;
    self->field_10d8 = value->field_18;
    self->field_10d0 = v1;
    self->field_10c8 = v2;
    self->field_10c0 = v0;
    u64 v3 = value->field_20;
    u64 v4 = value->field_28;
    u64 v5 = value->field_30;
    self->field_10f8 = value->field_38;
    self->field_10f0 = v5;
    self->field_10e8 = v4;
    self->field_10e0 = v3;
}

struct Unk_162bf70 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_162bf70, field_70, 0x70);

// 0x710162bf70
void Unk_162bf70_set(Unk_162bf70* self, u32 value) {
    self->field_70 = value;
}

struct Unk_162bf80 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_162bf80, field_20, 0x20);

// 0x710162bf80
u8 Unk_162bf80_get(const Unk_162bf80* self) {
    return self->field_20;
}

struct Unk_162c010 {
    u8 _0[0x21];
    u8 field_21;
};
PKMN_OFFSET_ASSERT(Unk_162c010, field_21, 0x21);

// 0x710162c010
u8 Unk_162c010_get(const Unk_162c010* self) {
    return self->field_21;
}

struct Unk_162c020 {
    u8 _0[0x11];
    u8 field_11;
};
PKMN_OFFSET_ASSERT(Unk_162c020, field_11, 0x11);

// 0x710162c020
u32 Unk_162c020_get(const Unk_162c020* self) {
    return self->field_11 & 1;
}

struct Unk_162c030 {
    u8 _0[0x11];
    u8 field_11;
};
PKMN_OFFSET_ASSERT(Unk_162c030, field_11, 0x11);

// 0x710162c030
u32 Unk_162c030_get(const Unk_162c030* self) {
    return (self->field_11 >> 2) & 1;
}

void Unk_162cae0(u64);

// 0x710162c180
void Unk_162c180_call(u64 self) {
    Unk_162cae0(self);
}

extern u32 Unk_27f9610 __attribute__((visibility("hidden")));

// 0x710162cb20
u32 Unk_162cb20_get() {
    return Unk_27f9610;
}

struct Unk_162cca0_0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_162cca0_0, field_0, 0x0);

struct Unk_162cca0 {
    Unk_162cca0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_162cca0, field_0, 0x0);

// 0x710162cca0
u64 Unk_162cca0_get(const Unk_162cca0* self) {
    return self->field_0->field_0;
}

struct Unk_162ccb0_8 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_162ccb0_8, field_0, 0x0);

struct Unk_162ccb0 {
    u8 _0[0x8];
    Unk_162ccb0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_162ccb0, field_8, 0x8);

// 0x710162ccb0
u64 Unk_162ccb0_get(const Unk_162ccb0* self) {
    return self->field_8->field_0;
}

struct Unk_162ccc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_162ccc0, field_0, 0x0);

// 0x710162ccc0
bool Unk_162ccc0_check(const Unk_162ccc0* self) {
    return self->field_0 == 0;
}
