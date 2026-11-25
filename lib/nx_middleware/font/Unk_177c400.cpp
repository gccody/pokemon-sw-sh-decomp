// Scope: common
// NintendoWare Font 7.3.2: the virtual functions of nn::font::ResFont's base
// (vtable 0x710246a5c8, shared by ResFont's 0x710246a490) that read a FFNT
// resource's glyphs, widths and kerning, and the FFNT block lookup. The class
// is declared here the way tools/leafgen.py declares it (lib/nx_middleware/
// class/nn_font_ResFont.cpp): Unk_177baf0.h's declares these slots with other
// signatures, so this file keeps its own placeholder layout of the object
// (the same offsets as Unk_177baf0.h's Unk_246a5b8). Placeholder names.
#include <types.h>

// The FFNT file header and its blocks (Unk_177baf0.h's Unk_177baf0_File).
struct Unk_177c400_File {
    u32 signature;
    u16 byteOrder;
    u16 headerSize;
    u32 version;
    u32 fileSize;
    u16 blockCount;
};
PKMN_OFFSET_ASSERT(Unk_177c400_File, headerSize, 0x6);
PKMN_OFFSET_ASSERT(Unk_177c400_File, blockCount, 0x10);

struct Unk_177c400_Block {
    u32 kind;
    u32 size;
};
PKMN_SIZE_ASSERT(Unk_177c400_Block, 0x8);

// A character's widths.
struct Unk_177c400_Widths {
    s8 field_0;
    u8 field_1;
    u8 field_2;
};
PKMN_SIZE_ASSERT(Unk_177c400_Widths, 0x3);

// The FINF block's data (Unk_177baf0.h's Unk_177baf0_Info). The offsets are
// from the start of the file.
struct Unk_177c400_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    s16 field_4;
    u16 field_6;  // the glyph index of characters the font has no glyph of
    Unk_177c400_Widths field_8;
    u8 field_b;
    u32 glyphOffset;  // TGLP data
    u32 widthOffset;  // the first CWDH data
    u32 mapOffset;  // the first CMAP data
};
PKMN_OFFSET_ASSERT(Unk_177c400_Info, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_177c400_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_177c400_Info, glyphOffset, 0xc);
PKMN_OFFSET_ASSERT(Unk_177c400_Info, widthOffset, 0x10);
PKMN_OFFSET_ASSERT(Unk_177c400_Info, mapOffset, 0x14);

// The TGLP block's data: the glyph sheets' cells and textures.
struct Unk_177c400_Glyph {
    u8 cellWidth;
    u8 cellHeight;
    u8 field_2;
    u8 field_3;
    u32 sheetSize;
    s16 field_8;
    u16 sheetFormat;
    u16 sheetRow;
    u16 sheetLine;
    u16 sheetWidth;
    u16 sheetHeight;
    u32 sheetOffset;  // from the start of the file (0: none)
};
PKMN_OFFSET_ASSERT(Unk_177c400_Glyph, sheetSize, 0x4);
PKMN_OFFSET_ASSERT(Unk_177c400_Glyph, sheetFormat, 0xa);
PKMN_OFFSET_ASSERT(Unk_177c400_Glyph, sheetRow, 0xc);
PKMN_OFFSET_ASSERT(Unk_177c400_Glyph, sheetWidth, 0x10);
PKMN_OFFSET_ASSERT(Unk_177c400_Glyph, sheetOffset, 0x14);

// A CWDH block's data: the widths of the glyphs [indexBegin, indexEnd].
struct Unk_177c400_Width {
    u16 indexBegin;
    u16 indexEnd;
    u32 next;  // the next CWDH data, from the start of the file (0: none)
    Unk_177c400_Widths widths[1];
};
PKMN_OFFSET_ASSERT(Unk_177c400_Width, next, 0x4);
PKMN_OFFSET_ASSERT(Unk_177c400_Width, widths, 0x8);

// The kerning table: sorted first characters, each with a sorted table of
// second characters and their kerning.
struct Unk_177c400_KerningSecond {
    u32 code;
    s16 value;
};
PKMN_SIZE_ASSERT(Unk_177c400_KerningSecond, 0x8);

struct Unk_177c400_KerningSecondTable {
    u16 count;
    Unk_177c400_KerningSecond entries[1];
};
PKMN_OFFSET_ASSERT(Unk_177c400_KerningSecondTable, entries, 0x4);

struct Unk_177c400_KerningFirst {
    u32 code;
    u32 offset;  // its second table, from the start of this table
};
PKMN_SIZE_ASSERT(Unk_177c400_KerningFirst, 0x8);

struct Unk_177c400_KerningTable {
    u16 count;
    Unk_177c400_KerningFirst entries[1];
};
PKMN_OFFSET_ASSERT(Unk_177c400_KerningTable, entries, 0x4);

// A glyph, as the slot 18 function fills it in.
struct Unk_177c400_GlyphOut {
    const void* texture;
    u16 left;
    u16 glyphWidth;
    u16 charWidth;
    u16 rawWidth;
    u16 height;
    u16 rawHeight;
    u16 sheetWidth;
    u16 sheetHeight;
    u16 cellX;
    u16 cellY;
    u16 sheetFormat;
    u8 field_1e;
    u8 sheetIndex;
    const void* textureObject;
    u16 field_28;
};
PKMN_OFFSET_ASSERT(Unk_177c400_GlyphOut, left, 0x8);
PKMN_OFFSET_ASSERT(Unk_177c400_GlyphOut, height, 0x10);
PKMN_OFFSET_ASSERT(Unk_177c400_GlyphOut, cellX, 0x18);
PKMN_OFFSET_ASSERT(Unk_177c400_GlyphOut, sheetFormat, 0x1c);
PKMN_OFFSET_ASSERT(Unk_177c400_GlyphOut, field_1e, 0x1e);
PKMN_OFFSET_ASSERT(Unk_177c400_GlyphOut, sheetIndex, 0x1f);
PKMN_OFFSET_ASSERT(Unk_177c400_GlyphOut, textureObject, 0x20);
PKMN_OFFSET_ASSERT(Unk_177c400_GlyphOut, field_28, 0x28);

// The entry of a second-character kerning table with the character `code`,
// or null.
inline const Unk_177c400_KerningSecond* Unk_177c400_Search(const Unk_177c400_KerningSecondTable* table,
                                                          u32 code) {
    u32 begin = 0;
    u32 end = table->count;
    while (true) {
        u32 middle = (begin + end) / 2;
        if (table->entries[middle].code == code) {
            return &table->entries[middle];
        }
        if (table->entries[middle].code < code) {
            if (begin == middle) {
                return nullptr;
            }
            begin = middle;
        } else {
            if (end == middle) {
                return nullptr;
            }
            end = middle;
        }
    }
}

// The base's layout (Unk_177baf0.h's Unk_246a5b8; the vtable pointer is in
// the first 8 bytes).
class Unk_246a5b8 {
public:
    u16 Unk_177c2d0(u32 code) const;

    u8 _0[0x8];
    u8 field_8;  // nn::font::Font's
    u8 field_9;
    u64 field_10;
    const u8* field_18;  // the resource
    Unk_177c400_Info* field_20;
    u8 field_28[0x30];  // the texture object
    u32 field_58;
    const Unk_177c400_KerningTable* field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    s32 rangeCount;
    u32 rangeBegin[16];
    u32 rangeEnd[16];
};
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_246a5b8, rangeCount, 0x80);
PKMN_OFFSET_ASSERT(Unk_246a5b8, rangeBegin, 0x84);
PKMN_OFFSET_ASSERT(Unk_246a5b8, rangeEnd, 0xc4);
PKMN_SIZE_ASSERT(Unk_246a5b8, 0x108);

namespace nn {
namespace font {

class ResFont : public Unk_246a5b8 {
public:
    Unk_177c400_Widths vf17(u32 code);
    void vf18(Unk_177c400_GlyphOut* glyph, u32 code);
    bool vf19(u32 code);
    s32 vf20(u32 first, u32 second);
    void vf25(bool arg1, bool arg2);
    u8 vf33();

    void Unk_177c500(Unk_177c400_GlyphOut* glyph, u16 index);

    const Unk_177c400_Glyph* Glyph() const {
        return reinterpret_cast<const Unk_177c400_Glyph*>(field_18 + field_20->glyphOffset);
    }

    u16 GlyphIndex(u32 code) const {
        u16 index = Unk_177c2d0(code);
        if (index == 0xffff) {
            index = field_20->field_6;
        }
        return index;
    }

    const Unk_177c400_Widths& Widths(u16 index) const {
        u32 offset = field_20->widthOffset;
        while (offset != 0) {
            const Unk_177c400_Width* width = reinterpret_cast<const Unk_177c400_Width*>(field_18 + offset);
            if (width->indexBegin <= index && index <= width->indexEnd) {
                return width->widths[index - width->indexBegin];
            }
            offset = width->next;
        }
        return field_20->field_8;
    }

    bool InRange(u32 code) const {
        for (s32 i = 0; i < rangeCount; i++) {
            if (rangeBegin[i] <= code && code <= rangeEnd[i]) {
                return true;
            }
        }
        return false;
    }
};

}  // namespace font
}  // namespace nn

// 0x710177c800
const void* Unk_177c800(const void* file, u32 kind) {
    const Unk_177c400_File* header = static_cast<const Unk_177c400_File*>(file);
    const void* data = nullptr;
    const u8* block = static_cast<const u8*>(file) + header->headerSize;
    for (u32 i = 0; i < header->blockCount; i++) {
        const Unk_177c400_Block* blockHeader = reinterpret_cast<const Unk_177c400_Block*>(block);
        if (blockHeader->kind == kind) {
            data = blockHeader + 1;
            break;
        }
        block += blockHeader->size;
    }
    return data;
}

namespace nn {
namespace font {

// 0x710177c420
Unk_177c400_Widths ResFont::vf17(u32 code) {
    return Widths(GlyphIndex(code));
}

// 0x710177c4b0
void ResFont::vf18(Unk_177c400_GlyphOut* glyph, u32 code) {
    Unk_177c500(glyph, GlyphIndex(code));
}

// 0x710177c500
void ResFont::Unk_177c500(Unk_177c400_GlyphOut* glyph, u16 index) {
    const Unk_177c400_Glyph* sheet = Glyph();
    u32 cellsPerSheet = sheet->sheetRow * sheet->sheetLine;
    u32 sheetIndex = index / cellsPerSheet;
    u32 offset = sheetIndex * sheet->sheetSize;
    if (sheet->sheetOffset != 0) {
        glyph->texture = field_18 + sheet->sheetOffset + offset;
    } else {
        glyph->texture = nullptr;
    }

    const Unk_177c400_Widths& widths = Widths(index);
    glyph->left = widths.field_0;
    glyph->glyphWidth = widths.field_1;
    glyph->charWidth = widths.field_2;
    glyph->rawWidth = widths.field_1;
    glyph->textureObject = field_28;
    glyph->sheetIndex = sheetIndex;
    glyph->field_1e = 0;
    glyph->field_28 = 0;

    u32 cell = index % (sheet->sheetRow * sheet->sheetLine);
    u32 cellX = cell % sheet->sheetRow;
    u32 cellY = cell / sheet->sheetRow;
    u32 pixelX = cellX * (sheet->cellWidth + 1);
    u32 pixelY = cellY * (sheet->cellHeight + 1);
    glyph->height = sheet->cellHeight;
    glyph->rawHeight = sheet->cellHeight;
    glyph->sheetFormat = sheet->sheetFormat & 0x3fff;
    glyph->sheetWidth = sheet->sheetWidth;
    glyph->sheetHeight = sheet->sheetHeight;
    glyph->cellX = pixelX + 1;
    glyph->cellY = pixelY + 1;
}

// 0x710177c640
bool ResFont::vf19(u32 code) {
    return Unk_177c2d0(code) != 0xffff;
}

// 0x710177c660
s32 ResFont::vf20(u32 first, u32 second) {
    if (field_60 == nullptr || !field_8) {
        return 0;
    }
    if (rangeCount != 0 && (!InRange(first) || !InRange(second))) {
        return 0;
    }

    const Unk_177c400_KerningTable* table = field_60;
    u32 begin = 0;
    u32 end = table->count;
    u32 middle;
    while (true) {
        middle = (begin + end) / 2;
        u32 code = table->entries[middle].code;
        if (code == first) {
            break;
        }
        if (code < first) {
            if (begin == middle) {
                return 0;
            }
            begin = middle;
        } else {
            if (end == middle) {
                return 0;
            }
            end = middle;
        }
    }

    const Unk_177c400_KerningSecondTable* seconds = reinterpret_cast<const Unk_177c400_KerningSecondTable*>(
        reinterpret_cast<const u8*>(table) + table->entries[middle].offset);
    const Unk_177c400_KerningSecond* secondEntry = Unk_177c400_Search(seconds, second);
    if (secondEntry == nullptr) {
        return 0;
    }
    return secondEntry->value;
}

// 0x710177c850
void ResFont::vf25(bool arg1, bool arg2) {
    field_58 = (static_cast<u32>(arg2) << 1) | (static_cast<u32>(arg1) << 2);
}

// 0x710177c8e0
u8 ResFont::vf33() {
    return Glyph()->field_2;
}

}  // namespace font
}  // namespace nn
