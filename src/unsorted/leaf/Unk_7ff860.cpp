// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7ff860 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ff860, field_8, 0x8);

// 0x71007ff860
void Unk_7ff860_clearField8(Unk_7ff860* self) {
    self->field_8 = 0;
}

struct Unk_7ff870_arg1 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ff870_arg1, field_8, 0x8);

struct Unk_7ff870 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ff870, field_8, 0x8);

// 0x71007ff870
void Unk_7ff870_set(Unk_7ff870* self, const Unk_7ff870_arg1* value) {
    self->field_8 = value->field_8;
}

// 0x71007ffa70
void Unk_7ffa70() {}

void Unk_7ff8f0();

// 0x71007ffa80
void Unk_7ffa80_call() {
    Unk_7ff8f0();
}

struct Unk_7ffaa0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7ffaa0, field_0, 0x0);

// 0x71007ffaa0
u8 Unk_7ffaa0_getField0(const Unk_7ffaa0* self) {
    return self->field_0;
}

struct Unk_7ffab0 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_7ffab0, field_c, 0xc);

// 0x71007ffab0
u32 Unk_7ffab0_getFieldc(const Unk_7ffab0* self) {
    return self->field_c;
}

struct Unk_7ffac0 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
    u8 _8[0x4];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_7ffac0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ffac0, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ffac0, field_c, 0xc);

// 0x71007ffac0
u32 Unk_7ffac0_get(const Unk_7ffac0* self) {
    if (self->field_0 != 0) {
        if (self->field_4 == 0xff) {
            return 0xff;
        }
        return self->field_4 - self->field_c;
    }
    return 0;
}

struct Unk_7ffaf0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_7ffaf0, field_10, 0x10);

// 0x71007ffaf0
u8 Unk_7ffaf0_getField10(const Unk_7ffaf0* self) {
    return self->field_10;
}

struct Unk_7ffb30 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ffb30, field_8, 0x8);

// 0x71007ffb30
u32 Unk_7ffb30_getField8(const Unk_7ffb30* self) {
    return self->field_8;
}

struct Unk_7ffb40 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_7ffb40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ffb40, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ffb40, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7ffb40, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_7ffb40, field_10, 0x10);

// 0x71007ffb40
void Unk_7ffb40_set(Unk_7ffb40* self, u8 value, u32 arg2, u32 arg3, u8 arg4) {
    self->field_0 = value;
    self->field_4 = arg2 & 0xffff;
    self->field_8 = arg3 & 0xffff;
    self->field_c = 0;
    self->field_10 = arg4;
}

struct Unk_7ffb60 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
    u8 _8[0x4];
    u32 field_c;
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_7ffb60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ffb60, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ffb60, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_7ffb60, field_10, 0x10);

// 0x71007ffb60
void Unk_7ffb60_set(Unk_7ffb60* self) {
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_c = 0;
    self->field_10 = 0x1f;
}

struct Unk_800280 {
    u8 _0[0x1a4];
    u32 field_1a4;
};
PKMN_OFFSET_ASSERT(Unk_800280, field_1a4, 0x1a4);

// 0x7100800280
bool Unk_800280_check(const Unk_800280* self) {
    return self->field_1a4 != 0;
}

void Unk_7eb420(u32);

// 0x7100800290
void Unk_800290_call(void* /*unused*/, u32 value) {
    Unk_7eb420(value);
}

struct Unk_8003c0 {
    u8 _0[0x11];
    u8 field_11;
};
PKMN_OFFSET_ASSERT(Unk_8003c0, field_11, 0x11);

// 0x71008003c0
u8 Unk_8003c0_getField11(const Unk_8003c0* self) {
    return self->field_11;
}

struct Unk_8003d0 {
    u8 _0[0x88];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_8003d0, field_88, 0x88);

// 0x71008003d0
u32 Unk_8003d0_getField88(const Unk_8003d0* self) {
    return self->field_88;
}
