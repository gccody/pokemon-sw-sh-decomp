// Scope: common
// Setters of PPFX's parameters, between two static initialisers like
// Unk_4534d0.cpp's and written by hand in leafgen's style (it doesn't write
// selects of floats or copies of structures). Placeholder types: rename and
// move once the owning class is known.
#include <string.h>
#include <types.h>

// sixteen and eight bytes copied as they are (four and two floats)
struct Unk_455350_Float4 {
    u32 field_0[4];
};
struct Unk_455350_Float2 {
    u32 field_0[2];
};

// one of the things field_1f8 has (0x60 bytes)
struct Unk_455350_Item {
    u8 _0[0x24];
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    f32 field_30;
    Unk_455350_Float4 field_34;
    Unk_455350_Float2 field_44;
    Unk_455350_Float4 field_4c;
    u8 _5c[4];
};
PKMN_SIZE_ASSERT(Unk_455350_Item, 0x60);

struct Unk_455350 {
    u8 _0[0x184];
    f32 field_184;
    f32 field_188;
    u8 _18c[0x10];
    Unk_455350_Float4 field_19c;
    u8 _1ac[0xc];
    Unk_455350_Float4 field_1b8;
    u8 _1c8[4];
    Unk_455350_Float4 field_1cc;
    u8 _1dc[0x1c];
    Unk_455350_Item* field_1f8;
    u8 _200[0x70];
    f32 field_270[9];
    u32 field_294;
    f32 field_298;
    u8 _29c[0x140];
    f32 field_3dc;
    f32 field_3e0;
    f32 field_3e4;
    f32 field_3e8;
    f32 field_3ec;
    f32 field_3f0;
    f32 field_3f4;
    f32 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_455350, field_19c, 0x19c);
PKMN_OFFSET_ASSERT(Unk_455350, field_1b8, 0x1b8);
PKMN_OFFSET_ASSERT(Unk_455350, field_1cc, 0x1cc);
PKMN_OFFSET_ASSERT(Unk_455350, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_455350, field_270, 0x270);
PKMN_OFFSET_ASSERT(Unk_455350, field_3dc, 0x3dc);

// 0x7100455350
u32 Unk_455350_set(Unk_455350* self, s32 index, const Unk_455350_Float4* value, f32 a, f32 b, f32 c, f32 d) {
    self->field_1f8[index].field_24 = a;
    self->field_1f8[index].field_30 = b;
    self->field_1f8[index].field_28 = c;
    self->field_1f8[index].field_2c = d;
    self->field_1f8[index].field_34 = *value;
    return 0;
}

// 0x71004553a0
u32 Unk_4553a0_set(Unk_455350* self, s32 index, const Unk_455350_Float2* value) {
    self->field_1f8[index].field_44 = *value;
    return 0;
}

// 0x71004553c0: a size, or 64 for none (and for a NaN, which stays: the
// test is `<=`)
u32 Unk_4553c0_set(Unk_455350* self, f32 value) {
    if (value <= 0.0f) {
        value = 64.0f;
    }
    self->field_3dc = value;
    return 0;
}

// 0x71004553e0
u32 Unk_4553e0_set(Unk_455350* self, f32 value) {
    if (value <= 0.0f) {
        value = 2048.0f;
    }
    self->field_3e0 = value;
    return 0;
}

// 0x7100455400
u32 Unk_455400_set(Unk_455350* self, f32 value) {
    if (value <= 0.0f) {
        value = 128.0f;
    }
    self->field_3e4 = value;
    return 0;
}

// 0x7100455420
u32 Unk_455420_set(Unk_455350* self, f32 value) {
    if (value <= 0.0f) {
        value = 64.0f;
    }
    self->field_3e8 = value;
    return 0;
}

// 0x7100455440: a scale, or 1 for none
u32 Unk_455440_set(Unk_455350* self, f32 value) {
    if (value <= 0.0f) {
        value = 1.0f;
    }
    self->field_3ec = value;
    return 0;
}

// 0x7100455460
u32 Unk_455460_set(Unk_455350* self, f32 value) {
    if (value <= 0.0f) {
        value = 1.0f;
    }
    self->field_3f0 = value;
    return 0;
}

// 0x7100455480
u32 Unk_455480_set(Unk_455350* self, f32 value) {
    if (value <= 0.0f) {
        value = 1.0f;
    }
    self->field_3f4 = value;
    return 0;
}

// 0x71004554a0
u32 Unk_4554a0_set(Unk_455350* self, f32 value) {
    if (value <= 0.0f) {
        value = 1.0f;
    }
    self->field_3f8 = value;
    return 0;
}

// 0x71004554c0
u32 Unk_4554c0_set(Unk_455350* self, const Unk_455350_Float4* value, f32 a, f32 b) {
    self->field_184 = a;
    self->field_188 = b;
    self->field_19c = *value;
    return 0;
}

// 0x7100455530
u32 Unk_455530_set(Unk_455350* self, const Unk_455350_Float4* a, const Unk_455350_Float4* b) {
    self->field_1b8 = *a;
    self->field_1cc = *b;
    return 0;
}

// 0x7100455560
u32 Unk_455560_set(Unk_455350* self, u32 value, f32 a0, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8,
                   f32 a9) {
    self->field_270[0] = a0;
    self->field_270[1] = a1;
    self->field_270[2] = a2;
    self->field_270[3] = a3;
    self->field_270[4] = a4;
    self->field_270[5] = a5;
    self->field_270[6] = a6;
    self->field_270[7] = a7;
    self->field_270[8] = a8;
    self->field_294 = value;
    self->field_298 = a9;
    return 0;
}

// 0x710045e900
u32 Unk_45e900_set(Unk_455350* self, s32 index, const Unk_455350_Float4* value) {
    self->field_1f8[index].field_4c = *value;
    return 0;
}

// what 0x7100452800 orders: by the name at 8
struct Unk_452800 {
    u64 field_0;
    const char* field_8;
};

// 0x7100452800
bool Unk_452800_less(const Unk_452800* a, const Unk_452800* b) {
    return strcmp(a->field_8, b->field_8) < 0;
}

// what 0x7100482380 reads: an object at 0x29b48 with a flag at 0x4c
struct Unk_482380_29b48 {
    u8 _0[0x4c];
    bool field_4c;
};
struct Unk_482380 {
    u8 _0[0x29b48];
    Unk_482380_29b48* field_29b48;
};

// 0x7100482380
bool Unk_482380_get(const Unk_482380* self) {
    if (self->field_29b48 != nullptr) {
        return self->field_29b48->field_4c;
    }
    return false;
}

// what 0x7100488840 orders, the largest first: by the number at 8
struct Unk_488840 {
    u64 field_0;
    f32 field_8;
};

// 0x7100488840
s32 Unk_488840_compare(const Unk_488840* a, const Unk_488840* b) {
    if (a->field_8 > b->field_8) {
        return -1;
    }
    return a->field_8 < b->field_8;
}

struct Unk_4aa260 {
    u8 _0[0x1c8];
    u32 field_1c8;
    f32 field_1cc;
    f32 field_1d0;
};

// 0x71004aa260
s32 Unk_4aa260_set(Unk_4aa260* self, f32 a, f32 b) {
    if (a < 0.0f) {
        return -6;
    }
    self->field_1c8 = 0;
    self->field_1cc = a;
    self->field_1d0 = b;
    return 0;
}

struct Unk_4afa70 {
    u8 _0[0x1c0];
    f32 field_1c0;
    u8 _1c4[0x220];
    f32 field_3e4;
};
PKMN_OFFSET_ASSERT(Unk_4afa70, field_3e4, 0x3e4);

// 0x71004afa70
f32 Unk_4afa70_get(const Unk_4afa70* self) {
    f32 value = self->field_3e4;
    if (value > 0.0f) {
        return value / self->field_1c0;
    }
    return 0.0f;
}

// 0x71024e0a00
extern u32 Unk_24e0a00;

// 0x71004190e0
void Unk_4190e0_set(u32 value) {
    Unk_24e0a00 = value;
}
