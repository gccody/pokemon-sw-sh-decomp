// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100782dd0
void Unk_782dd0() {}

// 0x7100782de0
u32 Unk_782de0_get(void* /*unused*/, u32 value) {
    return value < 0x270f ? value : 0x270f;
}

// 0x7100782df0
void Unk_782df0() {}

// 0x7100782e00
u32 Unk_782e00_get(void* /*unused*/, u32 value) {
    return value & 0xff;
}

struct Unk_7847d0 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_7847d0, field_88, 0x88);

// 0x71007847d0
u8 Unk_7847d0_getField88(const Unk_7847d0* self) {
    return self->field_88;
}

void Unk_784800(void*, u64, u32);

// 0x71007847f0
void Unk_7847f0_call(void* self, u64 value) {
    Unk_784800(self, value, 0);
}

// 0x7100784f30
u32 Unk_784f30() {
    return 0x810;
}

void Unk_785330(void*, u64, u32);

// 0x7100785320
void Unk_785320_call(void* self, u64 value) {
    Unk_785330(self, value, 1);
}

struct Unk_785fe0_160 {
    u8 _0[0x6];
    u16 field_6;
};
PKMN_OFFSET_ASSERT(Unk_785fe0_160, field_6, 0x6);

struct Unk_785fe0 {
    u8 _0[0x160];
    Unk_785fe0_160* field_160;
};
PKMN_OFFSET_ASSERT(Unk_785fe0, field_160, 0x160);

// 0x7100785fe0
u16 Unk_785fe0_get(const Unk_785fe0* self) {
    return self->field_160->field_6;
}

// 0x7100786410
void Unk_786410() {}

struct Unk_786b30_0 {
    u8 _0[0x1d];
    u8 field_1d;
};
PKMN_OFFSET_ASSERT(Unk_786b30_0, field_1d, 0x1d);

struct Unk_786b30 {
    Unk_786b30_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_786b30, field_0, 0x0);

// 0x7100786b30
u8 Unk_786b30_get(const Unk_786b30* self) {
    return self->field_0->field_1d;
}

struct Unk_786bd0_0 {
    u8 _0[0x1c];
    u8 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_786bd0_0, field_1c, 0x1c);

struct Unk_786bd0 {
    Unk_786bd0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_786bd0, field_0, 0x0);

// 0x7100786bd0
bool Unk_786bd0_check(const Unk_786bd0* self) {
    return self->field_0->field_1c == 4;
}

struct Unk_786fb0_0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_786fb0_0, field_10, 0x10);

struct Unk_786fb0 {
    Unk_786fb0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_786fb0, field_0, 0x0);

// 0x7100786fb0
u32 Unk_786fb0_get(const Unk_786fb0* self) {
    return self->field_0->field_10 >> 7;
}

struct Unk_786fe0_0 {
    u8 _0[0x16];
    u8 field_16;
    u8 _17[0x1];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_786fe0_0, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_786fe0_0, field_18, 0x18);

struct Unk_786fe0 {
    Unk_786fe0_0* field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_786fe0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_786fe0, field_8, 0x8);

// 0x7100786fe0
u32 Unk_786fe0_get(const Unk_786fe0* self) {
    return (((self->field_0->field_16 << 0x1c) & 0xff00ffff) |
            ((self->field_0->field_18 & 0xff) << 0x10)) +
           self->field_8;
}
