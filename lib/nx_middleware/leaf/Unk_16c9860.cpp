// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_16c9870(u64, u32);

// 0x71016c9860
void Unk_16c9860_call(void* /*unused*/, u64 value) {
    Unk_16c9870(value, 1);
}

void Unk_16c9e60(u64, u32);

// 0x71016c9f90
void Unk_16c9f90_call(void* /*unused*/, u64 value) {
    Unk_16c9e60(value, 1);
}

struct Unk_16ca5a0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16ca5a0, field_18, 0x18);

void Unk_16d2390(u64, u64, u32);

// 0x71016ca5a0
void Unk_16ca5a0_call(const Unk_16ca5a0* self, u64 value, bool arg2) {
    if (self->field_18 != 0) {
        Unk_16d2390(self->field_18, value, arg2);
    }
}

struct Unk_16ca5c0 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_16ca5c0, field_20, 0x20);

// 0x71016ca5c0
bool Unk_16ca5c0_check(const Unk_16ca5c0* self) {
    return self->field_20 == 3;
}

struct Unk_16ca650 {
    u8 _0[0x150];
    u8 field_150;
};
PKMN_OFFSET_ASSERT(Unk_16ca650, field_150, 0x150);

// 0x71016ca650
const u8* Unk_16ca650_get(const Unk_16ca650* self) {
    return &self->field_150;
}

struct Unk_16ca660 {
    u8 _0[0x22];
    u16 field_22;
};
PKMN_OFFSET_ASSERT(Unk_16ca660, field_22, 0x22);

// 0x71016ca660
u16 Unk_16ca660_get(const Unk_16ca660* self) {
    return self->field_22;
}

struct Unk_16ca670 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_16ca670, field_38, 0x38);

// 0x71016ca670
const u8* Unk_16ca670_get(const Unk_16ca670* self) {
    return &self->field_38;
}

struct Unk_16ca680 {
    u8 _0[0x200];
    u64 field_200;
};
PKMN_OFFSET_ASSERT(Unk_16ca680, field_200, 0x200);

// 0x71016ca680
u64 Unk_16ca680_get(const Unk_16ca680* self) {
    return self->field_200;
}

struct Unk_16ca690 {
    u8 _0[0x238];
    u8 field_238;
};
PKMN_OFFSET_ASSERT(Unk_16ca690, field_238, 0x238);

// 0x71016ca690
const u8* Unk_16ca690_get(const Unk_16ca690* self) {
    return &self->field_238;
}

extern u16 Unk_27fb420;

// 0x71016ca7a0
u16 Unk_16ca7a0_get() {
    return Unk_27fb420;
}

struct Unk_16cb980 {
    u8 _0[0x5c8];
    u32 field_5c8;
};
PKMN_OFFSET_ASSERT(Unk_16cb980, field_5c8, 0x5c8);

// 0x71016cb980
u32 Unk_16cb980_get(const Unk_16cb980* self) {
    return self->field_5c8;
}

// 0x71016cb9a0
void Unk_16cb9a0_update() {
}
