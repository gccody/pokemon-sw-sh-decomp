// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71003357c0
u32 Unk_3357c0_get() {
    return 0x34;
}

// 0x71003357d0
u32 Unk_3357d0_get() {
    return 0x18;
}

// 0x71003357e0
u32 Unk_3357e0_get() {
    return 0x24;
}

// 0x71003357f0
u32 Unk_3357f0_get() {
    return 0x10;
}

// 0x7100335800
u32 Unk_335800_get() {
    return 0x14;
}

// 0x7100335810
u32 Unk_335810_get() {
    return 0x10;
}

// 0x7100335820
u32 Unk_335820_get() {
    return 0x14;
}

// 0x7100335830
u32 Unk_335830_get() {
    return 0xc;
}

// 0x7100335840
u32 Unk_335840_get() {
    return 0x30;
}

// 0x7100335850
u32 Unk_335850_get() {
    return 0x20;
}

// 0x7100335860
u32 Unk_335860_get() {
    return 0x18;
}

// 0x7100335870
u32 Unk_335870_get() {
    return 0xc;
}

// 0x7100335880
u32 Unk_335880_get() {
    return 0x10;
}

// 0x7100335890
u32 Unk_335890_get() {
    return 0x28;
}

// 0x71003358a0
u32 Unk_3358a0_get() {
    return 8;
}

struct Unk_33e830 {
    u8 _0[0x36];
    u8 field_36;
};
PKMN_OFFSET_ASSERT(Unk_33e830, field_36, 0x36);

// 0x710033e830
void Unk_33e830_set(Unk_33e830* self, u32 value) {
    self->field_36 = (self->field_36 & 0x7f) | ((value & 0x1ffffff) << 7);
}

struct Unk_33e840 {
    u8 _0[0x36];
    s8 field_36;
};
PKMN_OFFSET_ASSERT(Unk_33e840, field_36, 0x36);

// 0x710033e840
bool Unk_33e840_check(const Unk_33e840* self) {
    return self->field_36 < 0;
}
