// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8017b0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8017b0, field_10, 0x10);

// 0x71008017b0
u8 Unk_8017b0_getField10(const Unk_8017b0* self) {
    return self->field_10;
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

struct Unk_801920 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_801920, field_c, 0xc);

// 0x7100801920
u8 Unk_801920_getFieldc(const Unk_801920* self) {
    return self->field_c;
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

struct Unk_802490 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_802490, field_18, 0x18);

// 0x7100802490
u32 Unk_802490_getField18(const Unk_802490* self) {
    return self->field_18;
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

struct Unk_802590 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_802590, field_8, 0x8);

// 0x7100802590
void Unk_802590_clearField8(Unk_802590* self) {
    self->field_8 = 0;
}

struct Unk_802650 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_802650, field_0, 0x0);

// 0x7100802650
void Unk_802650_clearField0(Unk_802650* self) {
    self->field_0 = 0;
}
