// The four constants SiGfx's static initialiser 0x710057a190 makes
// (0x71027703d8, placeholder names): 0x40-byte descriptions that
// SiGfxNXDrawContext's 0x710053f490 hands to 0x710053f630 to compare a
// resource's with.
#pragma once

#include <string.h>
#include <types.h>

struct Unk_27703d8_Item {
    Unk_27703d8_Item(u32 a, u32 b)
        : field_0(a), field_4(b), field_8(b), field_c(b), field_10(0), field_18(100.0f), field_1c(1), field_20(8) {
        memset(field_24, 0, sizeof(field_24));
    }

    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u64 field_10;
    f32 field_18;
    u32 field_1c;
    u32 field_20;
    u8 field_24[0x1c];
};
PKMN_SIZE_ASSERT(Unk_27703d8_Item, 0x40);

extern Unk_27703d8_Item Unk_27703d8[4];
