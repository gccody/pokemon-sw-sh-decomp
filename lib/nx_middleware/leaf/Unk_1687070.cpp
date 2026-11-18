// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101687070
u32 Unk_1687070_get() {
    return 8;
}

struct Unk_1688860 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1688860, field_10, 0x10);

// 0x7101688860
const u8* Unk_1688860_get(const Unk_1688860* self) {
    return &self->field_10;
}

struct Unk_16893c0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16893c0, field_18, 0x18);

void Unk_16966d0(u64);

// 0x71016893c0
void Unk_16893c0_call(const Unk_16893c0* self) {
    if (self->field_18 != 0) {
        Unk_16966d0(self->field_18);
    }
}

struct Unk_16894d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16894d0, field_18, 0x18);

void Unk_16968c0(u64);

// 0x71016894d0
void Unk_16894d0_call(const Unk_16894d0* self) {
    if (self->field_18 != 0) {
        Unk_16968c0(self->field_18);
    }
}

struct Unk_16895e0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16895e0, field_18, 0x18);

void Unk_1696c70(u64);

// 0x71016895e0
void Unk_16895e0_call(const Unk_16895e0* self) {
    if (self->field_18 != 0) {
        Unk_1696c70(self->field_18);
    }
}

struct Unk_1689770 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1689770, field_18, 0x18);

void Unk_1696d80(u64);

// 0x7101689770
void Unk_1689770_call(const Unk_1689770* self) {
    if (self->field_18 != 0) {
        Unk_1696d80(self->field_18);
    }
}

struct Unk_16898d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16898d0, field_18, 0x18);

void Unk_1696f80(u64);

// 0x71016898d0
void Unk_16898d0_call(const Unk_16898d0* self) {
    if (self->field_18 != 0) {
        Unk_1696f80(self->field_18);
    }
}

struct Unk_1689e30 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1689e30, field_18, 0x18);

void Unk_1695c30(u64);

// 0x7101689e30
void Unk_1689e30_call(const Unk_1689e30* self) {
    if (self->field_18 != 0) {
        Unk_1695c30(self->field_18);
    }
}

struct Unk_168a380 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_168a380, field_18, 0x18);

void Unk_1693c90(u64);

// 0x710168a380
void Unk_168a380_call(const Unk_168a380* self) {
    Unk_1693c90(self->field_18);
}

struct Unk_168a390 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_168a390, field_18, 0x18);

void Unk_1693c80(u64, u32);

// 0x710168a390
void Unk_168a390_call(const Unk_168a390* self, bool value) {
    Unk_1693c80(self->field_18, value);
}
