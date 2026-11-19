// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1653860_arg1 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1653860_arg1, field_8, 0x8);

struct Unk_1653860 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1653860, field_8, 0x8);

extern "C" int memcmp(const void*, const void*, unsigned long);

// 0x7101653860
bool Unk_1653860_call(const Unk_1653860* self, const Unk_1653860_arg1* value) {
    s32 r0 = memcmp(&self->field_8, &value->field_8, 0x10);
    return r0 == 0;
}

// 0x7101653bb0
void Unk_1653bb0_update(void* /*unused*/, void* /*unused*/) {
}

extern u64 Unk_27f9db8;

// 0x71016540f0
u64 Unk_16540f0_get() {
    return Unk_27f9db8;
}

struct Unk_1654290 {
    u8 _0[0x570];
    u8 field_570;
};
PKMN_OFFSET_ASSERT(Unk_1654290, field_570, 0x570);

// 0x7101654290
const u8* Unk_1654290_get(const Unk_1654290* self) {
    return &self->field_570;
}

struct Unk_1654870 {
    u8 _0[0x590];
    u8 field_590;
};
PKMN_OFFSET_ASSERT(Unk_1654870, field_590, 0x590);

// 0x7101654870
u8 Unk_1654870_get(const Unk_1654870* self) {
    return self->field_590;
}

struct Unk_1654880 {
    u8 _0[0x598];
    u64 field_598;
};
PKMN_OFFSET_ASSERT(Unk_1654880, field_598, 0x598);

// 0x7101654880
void Unk_1654880_set(Unk_1654880* self, u64 value) {
    self->field_598 = value;
}

struct Unk_1654890 {
    u8 _0[0x598];
    u64 field_598;
};
PKMN_OFFSET_ASSERT(Unk_1654890, field_598, 0x598);

// 0x7101654890
void Unk_1654890_set(Unk_1654890* self) {
    self->field_598 = 0;
}

struct Unk_16548a0 {
    u8 _0[0x568];
    u8 field_568;
};
PKMN_OFFSET_ASSERT(Unk_16548a0, field_568, 0x568);

// 0x71016548a0
u8 Unk_16548a0_get(const Unk_16548a0* self) {
    return self->field_568;
}

struct Unk_16548b0 {
    u8 _0[0x590];
    bool field_590;
};
PKMN_OFFSET_ASSERT(Unk_16548b0, field_590, 0x590);

// 0x71016548b0
void Unk_16548b0_set(Unk_16548b0* self, bool value) {
    self->field_590 = value;
}

extern u64 Unk_2456c98 __attribute__((visibility("hidden")));

// 0x7101654ce0
u64 Unk_1654ce0_get() {
    return Unk_2456c98;
}

extern u64 Unk_2456d38 __attribute__((visibility("hidden")));

// 0x7101654d80
u64 Unk_1654d80_get() {
    return Unk_2456d38;
}

// 0x7101655170
void Unk_1655170_update(u64 /*unused*/) {
}

struct Unk_1655180 {
    u8 _0[0x18];
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_1655180, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1655180, field_20, 0x20);

// 0x7101655180
void Unk_1655180_set(Unk_1655180* self, u64 value, u64 arg2) {
    self->field_18 = value;
    self->field_20 = arg2;
}

struct Unk_1655190 {
    u32 field_0;
    u8 _4[0x24];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_1655190, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1655190, field_28, 0x28);

// 0x7101655190
u32 Unk_1655190_update(Unk_1655190* self) {
    self->field_0 = 1;
    self->field_28 = 0;
    return 1;
}

struct Unk_1655330 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_1655330, field_28, 0x28);

// 0x7101655330
void Unk_1655330_set(Unk_1655330* self) {
    self->field_28 = 1;
}

void Unk_16571e0(void*, void*, u32, void*, u32);

// 0x71016560d0
void Unk_16560d0_call(void* self, void* value, void* arg2) {
    Unk_16571e0(arg2, self, 0x10, value, 0x10);
}

// 0x7101657630
void Unk_1657630_update() {
}
