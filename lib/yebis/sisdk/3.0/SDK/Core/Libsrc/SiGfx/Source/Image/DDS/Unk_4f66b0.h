// A DDS file's pixel format and the functions that tell which of SiGfx's
// formats it is (placeholder names: the translation unit's name isn't in the
// executable; the structure is the DDS file format's DDS_PIXELFORMAT).
#pragma once

#include <types.h>

struct Unk_4f66b0_PixelFormat {
    u32 field_0;   // the structure's size
    u32 field_4;   // flags: 1 alpha, 4 a four-character code, 0x40 RGB
    u32 field_8;   // the four-character code
    u32 field_c;   // bits in a pixel
    u32 field_10;  // the masks of red, green, blue and alpha
    u32 field_14;
    u32 field_18;
    u32 field_1c;
};
PKMN_SIZE_ASSERT(Unk_4f66b0_PixelFormat, 0x20);

// 0x71004f66b0: SiGfx's format of a pixel format, if it has one
bool Unk_4f66b0(const Unk_4f66b0_PixelFormat* pixelFormat, u32* format);
// 0x71004f6890: SiGfx's format of a DX10 header's
bool Unk_4f6890(u32 dxgiFormat, u32* format);
