// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: its SDK MW tag and the image format queries. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// Info structs and the defaults their initialisers set. Only the stores are
// known, so the field types follow their widths.
struct Unk_17876c0_Info {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u16 field_18;
    u32 field_1c;
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_17876c0_Info, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17876c0_Info, field_1c, 0x1c);
PKMN_SIZE_ASSERT(Unk_17876c0_Info, 0x24);

struct Unk_17876e0_Info {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u16 field_24;
    u32 field_28;
    u32 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_17876e0_Info, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_17876e0_Info, field_28, 0x28);
PKMN_SIZE_ASSERT(Unk_17876e0_Info, 0x30);

struct Unk_1787710_Info {
    void* field_0;
    void* field_8;
    u8 _10[0x2000];
    u8 field_2010;
    Unk_1787ac0_Flags field_2011;
    u8 _2012[0xe];
    u64 field_2020;
};
PKMN_OFFSET_ASSERT(Unk_1787710_Info, field_2010, 0x2010);
PKMN_OFFSET_ASSERT(Unk_1787710_Info, field_2020, 0x2020);
PKMN_SIZE_ASSERT(Unk_1787710_Info, 0x2028);

// 0x71017876c0
void Unk_17876c0(Unk_17876c0_Info* self) {
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_c = 1;
    self->field_10 = 1;
    self->field_14 = 1;
    self->field_18 = 0;
    self->field_1c = 0;
    self->field_20 = 1;
}

// 0x71017876e0
void Unk_17876e0(Unk_17876e0_Info* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_18 = 1;
    self->field_1c = 1;
    self->field_20 = 1;
    self->field_24 = 0;
    self->field_28 = 0;
    self->field_2c = 1;
}

// 0x7101787710
void Unk_1787710(Unk_1787710_Info* self, void* second, void* first) {
    self->field_2010 = 1;
    self->field_2011.Set(1, true);
    self->field_2020 = 0;
    self->field_0 = first;
    self->field_8 = second;
}

// 0x7101787740
void Unk_1787740() {
    nn::util::ReferSymbol("SDK MW+Nintendo+NintendoSDK_gfx-7_3_2-Release");
}

// 0x7101787750
int Unk_1787750(int format) {
    switch (format) {
    case 0x27: return 16;
    case 0x28: return 8;
    case 0x29: return 16;
    case 0x2a: return 8;
    case 0x2b: return 8;
    case 0x2c: return 4;
    case 0x2d: return 4;
    case 0x2e: return 5;
    case 0x2f: return 5;
    case 0x30: return 6;
    case 0x31: return 6;
    case 0x32: return 8;
    case 0x33: return 8;
    case 0x34: return 8;
    case 0x35: return 10;
    case 0x36: return 10;
    case 0x37: return 10;
    case 0x38: return 10;
    case 0x39: return 12;
    case 0x3a: return 12;
    default: return 4;
    }
}

// 0x7101787780
int Unk_1787780(int format) {
    switch (format) {
    case 0x27: return 8;
    case 0x28: return 8;
    case 0x29: return 8;
    case 0x2a: return 8;
    case 0x2b: return 4;
    case 0x2c: return 4;
    case 0x2d: return 4;
    case 0x2e: return 4;
    case 0x2f: return 5;
    case 0x30: return 5;
    case 0x31: return 6;
    case 0x32: return 5;
    case 0x33: return 6;
    case 0x34: return 8;
    case 0x35: return 5;
    case 0x36: return 6;
    case 0x37: return 8;
    case 0x38: return 10;
    case 0x39: return 10;
    case 0x3a: return 12;
    default: return 4;
    }
}

// 0x71017877b0
bool Unk_17877b0(int format) {
    return static_cast<u32>(format - 0x1a) < 0x21;
}

// 0x71017877c0
int Unk_17877c0(int format) {
    switch (format) {
    case 0x1a: return 8;
    case 0x1b: return 16;
    case 0x1c: return 16;
    case 0x1d: return 8;
    case 0x1e: return 16;
    case 0x1f: return 16;
    case 0x20: return 16;
    case 0x21: return 8;
    case 0x22: return 16;
    case 0x23: return 8;
    case 0x24: return 8;
    case 0x25: return 8;
    case 0x26: return 16;
    case 0x27: return 32;
    case 0x28: return 32;
    case 0x29: return 32;
    case 0x2a: return 32;
    case 0x2b: return 8;
    case 0x2c: return 8;
    case 0x2d: return 16;
    case 0x2e: return 16;
    case 0x2f: return 16;
    case 0x30: return 16;
    case 0x31: return 16;
    case 0x32: return 16;
    case 0x33: return 16;
    case 0x34: return 16;
    case 0x35: return 16;
    case 0x36: return 16;
    case 0x37: return 16;
    case 0x38: return 16;
    case 0x39: return 16;
    case 0x3a: return 16;
    case 0x3b: return 2;
    }
    if (format < 3) {
        return 1;
    }
    if (format < 0xb) {
        return 2;
    }
    if (format < 0x15) {
        return 4;
    }
    if (format < 0x18) {
        return 8;
    }
    return format == 0x18 ? 0xc : 0x10;
}

// 0x7101787830
size_t Unk_1787830(u32 width, int format) {
    if (Unk_17877b0(format)) {
        u32 blockWidth = Unk_1787750(format);
        width = (width + blockWidth - 1) / blockWidth;
    }
    return Unk_17877c0(format) * width;
}

// 0x71017878f0
int Unk_17878f0(int type, bool isSigned, bool isNormalized) {
    switch (type) {
    case 1:
        return isSigned ? 4 : 0;
    case 2:
        if (isSigned) {
            return isNormalized ? 7 : 5;
        }
        return isNormalized ? 6 : 1;
    case 3:
        return 2;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}
