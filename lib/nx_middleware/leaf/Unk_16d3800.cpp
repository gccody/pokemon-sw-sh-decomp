// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_16d3800 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16d3800, field_18, 0x18);

// 0x71016d3800
const u8* Unk_16d3800_get(const Unk_16d3800* self) {
    return &self->field_18;
}

struct Unk_16d3810 {
    u8 _0[0xb8];
    u8 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_16d3810, field_b8, 0xb8);

// 0x71016d3810
const u8* Unk_16d3810_get(const Unk_16d3810* self) {
    return &self->field_b8;
}

struct Unk_16d3820 {
    u8 _0[0x118];
    u16 field_118;
};
PKMN_OFFSET_ASSERT(Unk_16d3820, field_118, 0x118);

// 0x71016d3820
u16 Unk_16d3820_get(const Unk_16d3820* self) {
    return self->field_118;
}

struct Unk_16d3830 {
    u8 _0[0x11c];
    u32 field_11c;
};
PKMN_OFFSET_ASSERT(Unk_16d3830, field_11c, 0x11c);

// 0x71016d3830
u32 Unk_16d3830_get(const Unk_16d3830* self) {
    return self->field_11c;
}

struct Unk_16d3840 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_16d3840, field_120, 0x120);

// 0x71016d3840
u8 Unk_16d3840_get(const Unk_16d3840* self) {
    return self->field_120;
}

struct Unk_16d3850 {
    u8 _0[0x121];
    u8 field_121;
};
PKMN_OFFSET_ASSERT(Unk_16d3850, field_121, 0x121);

// 0x71016d3850
u8 Unk_16d3850_get(const Unk_16d3850* self) {
    return self->field_121;
}

struct Unk_16d3860 {
    u8 _0[0x122];
    u8 field_122;
};
PKMN_OFFSET_ASSERT(Unk_16d3860, field_122, 0x122);

// 0x71016d3860
u8 Unk_16d3860_get(const Unk_16d3860* self) {
    return self->field_122;
}

// 0x71016d4e00
void Unk_16d4e00_update() {
}
