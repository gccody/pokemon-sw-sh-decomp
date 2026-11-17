// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9f9140_88 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_9f9140_88, field_170, 0x170);

struct Unk_9f9140 {
    u8 _0[0x88];
    Unk_9f9140_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_9f9140, field_88, 0x88);

// 0x71009f9140
bool Unk_9f9140_check(const Unk_9f9140* self) {
    if (self->field_88 == nullptr) {
        return true;
    }
    return self->field_88->field_170 != 0;
}

struct Unk_9f9320 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9320, field_10, 0x10);

void Unk_140c020(u64, u32, u32);

// 0x71009f9320
void Unk_9f9320_call(const Unk_9f9320* self) {
    Unk_140c020(self->field_10, 0xffffffff, 1);
}

struct Unk_9f9330 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9330, field_10, 0x10);

void Unk_140c020(u64, u32, u32);

// 0x71009f9330
void Unk_9f9330_call(const Unk_9f9330* self) {
    Unk_140c020(self->field_10, 0xffffffff, 0);
}

struct Unk_9f9340 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9340, field_10, 0x10);

void Unk_140bff0(u64);

// 0x71009f9340
void Unk_9f9340_call(const Unk_9f9340* self) {
    Unk_140bff0(self->field_10);
}

struct Unk_9f9350 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9350, field_10, 0x10);

// 0x71009f9350
bool Unk_9f9350_check(const Unk_9f9350* self) {
    return self->field_10 == 0;
}

struct Unk_9f9360_10 {
    u8 _0[0x180];
    u32 field_180;
};
PKMN_OFFSET_ASSERT(Unk_9f9360_10, field_180, 0x180);

struct Unk_9f9360 {
    u8 _0[0x10];
    Unk_9f9360_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9360, field_10, 0x10);

// 0x71009f9360
u32 Unk_9f9360_get(const Unk_9f9360* self) {
    if (self->field_10 == nullptr) {
        return 0;
    }
    return self->field_10->field_180;
}

struct Unk_9f9380_18 {
    u8 _0[0x180];
    u32 field_180;
};
PKMN_OFFSET_ASSERT(Unk_9f9380_18, field_180, 0x180);

struct Unk_9f9380 {
    u8 _0[0x18];
    Unk_9f9380_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_9f9380, field_18, 0x18);

// 0x71009f9380
u32 Unk_9f9380_get(const Unk_9f9380* self) {
    if (self->field_18 == nullptr) {
        return 0;
    }
    return self->field_18->field_180;
}
