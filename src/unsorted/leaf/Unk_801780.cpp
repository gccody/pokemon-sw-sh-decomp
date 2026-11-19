// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_801780_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_801780_arg1, field_0, 0x0);

struct Unk_801780 {
    u8 _0[0x10];
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_801780, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_801780, field_14, 0x14);

// 0x7100801780
u32 Unk_801780_update(Unk_801780* self, const Unk_801780_arg1* value) {
    if (self->field_10 != 0) {
        return 0;
    }
    self->field_14 = value->field_0;
    self->field_10 = 1;
    return 1;
}

struct Unk_8017b0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8017b0, field_10, 0x10);

// 0x71008017b0
u8 Unk_8017b0_getField10(const Unk_8017b0* self) {
    return self->field_10;
}

struct Unk_8017c0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8017c0_arg1, field_0, 0x0);

struct Unk_8017c0 {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_8017c0, field_14, 0x14);

// 0x71008017c0
void Unk_8017c0_set(Unk_8017c0* self, const Unk_8017c0_arg1* value) {
    self->field_14 = value->field_0;
}

struct Unk_8017d0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8017d0, field_10, 0x10);

// 0x71008017d0
void Unk_8017d0_clearField10(Unk_8017d0* self) {
    self->field_10 = 0;
}

struct Unk_8017e0 {
    u8 _0[0x14];
    u8 field_14;
};
PKMN_OFFSET_ASSERT(Unk_8017e0, field_14, 0x14);

// 0x71008017e0
u8* Unk_8017e0_getField14Ptr(Unk_8017e0* self) {
    return &self->field_14;
}

struct Unk_801860 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_801860, field_0, 0x0);

// 0x7100801860
u8 Unk_801860_getField0(const Unk_801860* self) {
    return self->field_0;
}

struct Unk_801870 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_801870, field_0, 0x0);

// 0x7100801870
void Unk_801870_set(Unk_801870* self) {
    if (self->field_0 <= 3) {
        self->field_0 = self->field_0 + 1;
    }
}

struct Unk_801890 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_801890, field_0, 0x0);

// 0x7100801890
bool Unk_801890_check(const Unk_801890* self) {
    return self->field_0 > 3;
}

struct Unk_801910 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_801910, field_c, 0xc);

// 0x7100801910
void Unk_801910_set(Unk_801910* self) {
    self->field_c = 1;
}

struct Unk_801920 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_801920, field_c, 0xc);

// 0x7100801920
u8 Unk_801920_getFieldc(const Unk_801920* self) {
    return self->field_c;
}

struct Unk_802460 {
    u8 _0[0x1c];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_802460, field_1c, 0x1c);

// 0x7100802460
bool Unk_802460_check(const Unk_802460* self) {
    return self->field_1c != 0;
}

struct Unk_802470 {
    u8 _0[0x1c];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_802470, field_1c, 0x1c);

// 0x7100802470
u32 Unk_802470_getField1c(const Unk_802470* self) {
    return self->field_1c;
}

struct Unk_802480 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_802480, field_10, 0x10);

// 0x7100802480
u32 Unk_802480_get(const Unk_802480* self) {
    return (self->field_10 >> 8) & 0x3f;
}

struct Unk_802490 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_802490, field_18, 0x18);

// 0x7100802490
u32 Unk_802490_getField18(const Unk_802490* self) {
    return self->field_18;
}

struct Unk_8024a0 {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x4];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_8024a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8024a0, field_18, 0x18);

// 0x71008024a0
u32 Unk_8024a0_get(const Unk_8024a0* self) {
    return ((self->field_10 >> 8) & 0x3f) - self->field_18;
}

struct Unk_8024e0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8024e0, field_10, 0x10);

// 0x71008024e0
u8* Unk_8024e0_getField10Ptr(Unk_8024e0* self) {
    return &self->field_10;
}

struct Unk_802500 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_802500, field_18, 0x18);

// 0x7100802500
void Unk_802500_set(Unk_802500* self) {
    self->field_18 = self->field_18 + 1;
}

struct Unk_802580_arg1 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_802580_arg1, field_8, 0x8);

struct Unk_802580 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_802580, field_8, 0x8);

// 0x7100802580
void Unk_802580_set(Unk_802580* self, const Unk_802580_arg1* value) {
    self->field_8 = value->field_8;
}

struct Unk_802590 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_802590, field_8, 0x8);

// 0x7100802590
void Unk_802590_clearField8(Unk_802590* self) {
    self->field_8 = 0;
}

struct Unk_8025f0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8025f0, field_0, 0x0);

// 0x71008025f0
void Unk_8025f0_set(Unk_8025f0* self) {
    self->field_0 = 7;
}

struct Unk_802600 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_802600, field_0, 0x0);

// 0x7100802600
void Unk_802600_set(Unk_802600* self) {
    self->field_0 = 7;
}

struct Unk_802610_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_802610_arg1, field_0, 0x0);

struct Unk_802610 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_802610, field_0, 0x0);

// 0x7100802610
void Unk_802610_set(Unk_802610* self, const Unk_802610_arg1* value) {
    self->field_0 = value->field_0;
}

struct Unk_802620 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_802620, field_0, 0x0);

// 0x7100802620
bool Unk_802620_check(const Unk_802620* self) {
    return self->field_0 > 6;
}

struct Unk_802650 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_802650, field_0, 0x0);

// 0x7100802650
void Unk_802650_clearField0(Unk_802650* self) {
    self->field_0 = 0;
}
