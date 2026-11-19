// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_139ea50 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_139ea50, field_0, 0x0);

// 0x710139ea50
u32 Unk_139ea50_getField0(const Unk_139ea50* self) {
    return self->field_0;
}

struct Unk_139ffb0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_139ffb0, field_0, 0x0);

// 0x710139ffb0
u32 Unk_139ffb0_getField0(const Unk_139ffb0* self) {
    return self->field_0;
}

struct Unk_13a0f80 {
    u64 field_0;
    u8 field_8;
    u8 _9[0x77];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_13a0f80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13a0f80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13a0f80, field_80, 0x80);

// 0x71013a0f80
void Unk_13a0f80_set(Unk_13a0f80* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_80 = 0;
}

struct Unk_13a11f0 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_13a11f0, field_4, 0x4);

// 0x71013a11f0
bool Unk_13a11f0_check(const Unk_13a11f0* self) {
    return self->field_4 == 2;
}

struct Unk_13a1200 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13a1200, field_8, 0x8);

// 0x71013a1200
u32 Unk_13a1200_getField8(const Unk_13a1200* self) {
    return self->field_8;
}

struct Unk_13a2320_60_8 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_13a2320_60_8, field_170, 0x170);
struct Unk_13a2320_60 {
    u8 _0[0x8];
    Unk_13a2320_60_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13a2320_60, field_8, 0x8);
struct Unk_13a2320 {
    u8 _0[0x60];
    Unk_13a2320_60* field_60;
    u8 _68[0x60];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_13a2320, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_13a2320, field_c8, 0xc8);
void Unk_13a2370();

// 0x71013a2320
u32 Unk_13a2320_get(const Unk_13a2320* self) {
    if (self->field_c8 != 0) {
        return 1;
    }
    if (self->field_60->field_8 != nullptr) {
        if (self->field_60->field_8->field_170 != 0) {
            Unk_13a2370();
            return 1;
        }
        return 0;
    }
    return 0;
}
