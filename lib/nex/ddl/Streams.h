#pragma once
// NEX 4.6.8's DDL stream functions (tools/nexddl.py streams): each writes or
// reads a structure's fields to or from a ByteStream. The structures are
// placeholders named after their function: nothing says which DDL class each
// one is.
#include <nn/nex/ByteStream.h>
#include <nn/nex/String.h>
#include <nn/nex/qList.h>
#include <nn/nex/qVector.h>

void Unk_15c8ca0_write(nn::nex::ByteStream* s, const bool& v);
void Unk_15c8ce0_read(nn::nex::ByteStream* s, bool& v);
void Unk_162cec0_write(nn::nex::ByteStream* s, const nn::nex::String& v);
void Unk_162d000_read(nn::nex::ByteStream* s, nn::nex::String& v);

// read by 0x71015a2fc0, which isn't one of these functions
struct Unk_15a2fc0 {
    u8 _0[0x18];
};
void Unk_15a2fc0_read(nn::nex::ByteStream* s, Unk_15a2fc0& v);

// written by 0x71015a3800, which isn't one of these functions
struct Unk_15a3800 {
    u8 _0[0x8];
};
void Unk_15a3800_write(nn::nex::ByteStream* s, const Unk_15a3800& v);

// written by 0x71015a4f80, which isn't one of these functions
struct Unk_15a4f80 {
    u8 _0[0x28];
};
void Unk_15a4f80_write(nn::nex::ByteStream* s, const Unk_15a4f80& v);

// read by 0x71015a5230, which isn't one of these functions
struct Unk_15a5230 {
    u8 _0[0x8];
};
void Unk_15a5230_read(nn::nex::ByteStream* s, Unk_15a5230& v);

// written by 0x71015a5a50, which isn't one of these functions
struct Unk_15a5a50 {
    u8 _0[0x150];
};
void Unk_15a5a50_write(nn::nex::ByteStream* s, const Unk_15a5a50& v);

// read by 0x71015a8860, which isn't one of these functions
struct Unk_15a8860 {
    u8 _0[0x18];
};
void Unk_15a8860_read(nn::nex::ByteStream* s, Unk_15a8860& v);

// read by 0x710162d5a0, which isn't one of these functions
struct Unk_162d5a0 {
    u8 _0[0x70];
};
void Unk_162d5a0_read(nn::nex::ByteStream* s, Unk_162d5a0& v);

// written by 0x710162d630, which isn't one of these functions
struct Unk_162d630 {
    u8 _0[0x38];
};
void Unk_162d630_write(nn::nex::ByteStream* s, const Unk_162d630& v);

struct Unk_158bc50 {
    u8 _0[0x8];
    u8 m_version;
    u8 field_9;
    u8 _a[0x6];
    nn::nex::qVector<u64> field_10;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158bc50, 0x28);
PKMN_OFFSET_ASSERT(Unk_158bc50, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_158bc50, field_10, 0x10);

struct Unk_1589f50 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    nn::nex::String field_10;
    Unk_158bc50 field_38;
    Unk_158bc50 field_60;
    u16 field_88;
    u8 _8a[0x6];
    Unk_162d630 field_90;
    nn::nex::qVector<nn::nex::String> field_c8;
    u32 field_e0;
    u16 field_e4;
    u8 field_e6;
    u8 _e7[0x1];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_1589f50, 0xe8);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_e4, 0xe4);
PKMN_OFFSET_ASSERT(Unk_1589f50, field_e6, 0xe6);

struct Unk_158c210 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u16 field_18;
    u8 _1a[0x6];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158c210, 0x20);
PKMN_OFFSET_ASSERT(Unk_158c210, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158c210, field_18, 0x18);

struct Unk_158a0f0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];
    nn::nex::String field_20;
    Unk_158bc50 field_48;
    Unk_158bc50 field_70;
    u16 field_98;
    u8 _9a[0x6];
    Unk_162d630 field_a0;
    nn::nex::qVector<nn::nex::String> field_d8;
    u64 field_f0;
    u32 field_f8;
    u16 field_fc;
    u8 field_fe;
    u8 _ff[0x1];
    Unk_1589f50 field_100;
    Unk_158c210 field_1e8;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158a0f0, 0x208);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_f8, 0xf8);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_fc, 0xfc);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_fe, 0xfe);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_158a0f0, field_1e8, 0x1e8);

struct Unk_158a2d0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];
    nn::nex::String field_20;
    Unk_158bc50 field_48;
    Unk_158bc50 field_70;
    u16 field_98;
    u8 _9a[0x6];
    Unk_162d630 field_a0;
    nn::nex::qVector<nn::nex::String> field_d8;
    u64 field_f0;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158a2d0, 0xf8);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_158a2d0, field_f0, 0xf0);

struct Unk_158a460 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    bool field_18;
    u8 _19[0x7];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158a460, 0x20);
PKMN_OFFSET_ASSERT(Unk_158a460, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158a460, field_18, 0x18);

struct Unk_158a540 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    bool field_10;
    u8 _11[0x7];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158a540, 0x18);
PKMN_OFFSET_ASSERT(Unk_158a540, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_158a540, field_10, 0x10);

struct Unk_158a620 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    bool field_1c;
    u8 _1d[0x3];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158a620, 0x20);
PKMN_OFFSET_ASSERT(Unk_158a620, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158a620, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158a620, field_1c, 0x1c);

struct Unk_158a880 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u64 field_18;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158a880, 0x20);
PKMN_OFFSET_ASSERT(Unk_158a880, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158a880, field_18, 0x18);

struct Unk_158a970 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    Unk_158c210 field_18;
    u8 field_38;
    u8 _39[0x7];
    u64 field_40;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158a970, 0x48);
PKMN_OFFSET_ASSERT(Unk_158a970, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158a970, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158a970, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_158a970, field_40, 0x40);

struct Unk_158aa70 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u16 field_18;
    u8 _1a[0x6];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158aa70, 0x20);
PKMN_OFFSET_ASSERT(Unk_158aa70, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158aa70, field_18, 0x18);

struct Unk_158ac40 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    nn::nex::qVector<u64> field_10;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158ac40, 0x28);
PKMN_OFFSET_ASSERT(Unk_158ac40, field_10, 0x10);

struct Unk_158ad60 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    nn::nex::qVector<u32> field_10;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158ad60, 0x28);
PKMN_OFFSET_ASSERT(Unk_158ad60, field_10, 0x10);

struct Unk_158ae80 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    nn::nex::String field_10;
    nn::nex::String field_38;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158ae80, 0x60);
PKMN_OFFSET_ASSERT(Unk_158ae80, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158ae80, field_38, 0x38);

struct Unk_158b6f0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u64 field_18;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158b6f0, 0x20);
PKMN_OFFSET_ASSERT(Unk_158b6f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158b6f0, field_18, 0x18);

struct Unk_158b890 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158b890, 0x20);
PKMN_OFFSET_ASSERT(Unk_158b890, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158b890, field_18, 0x18);

struct Unk_158ba20 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u64 field_18;
    u64 field_20;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158ba20, 0x28);
PKMN_OFFSET_ASSERT(Unk_158ba20, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158ba20, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158ba20, field_20, 0x20);

struct Unk_158bf20 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u16 field_18;
    u8 _1a[0x6];
    u64 field_20;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158bf20, 0x28);
PKMN_OFFSET_ASSERT(Unk_158bf20, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158bf20, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158bf20, field_20, 0x20);

struct Unk_158c110 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x1];
    u16 field_a;
    bool field_c;
    u8 _d[0x3];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158c110, 0x10);
PKMN_OFFSET_ASSERT(Unk_158c110, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_158c110, field_c, 0xc);

struct Unk_158c300 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];
    Unk_158c210 field_20;
    u64 field_40;
    nn::nex::qVector<nn::nex::String> field_48;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158c300, 0x60);
PKMN_OFFSET_ASSERT(Unk_158c300, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158c300, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158c300, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_158c300, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_158c300, field_48, 0x48);

struct Unk_158c460 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    u32 field_10;
    u8 _14[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158c460, 0x18);
PKMN_OFFSET_ASSERT(Unk_158c460, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_158c460, field_10, 0x10);

struct Unk_158f110 {
    u8 _0[0x8];
    u8 m_version;
    u8 field_9;
    u8 field_a;
    u8 field_b;
    u8 _c[0x4];
    u64 field_10;
    u32 field_18;
    u32 field_1c;
    u8 field_20;
    u8 _21[0x1];
    u16 field_22;
    u8 _24[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158f110, 0x28);
PKMN_OFFSET_ASSERT(Unk_158f110, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_158f110, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_158f110, field_b, 0xb);
PKMN_OFFSET_ASSERT(Unk_158f110, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158f110, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158f110, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_158f110, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_158f110, field_22, 0x22);

struct Unk_158f260 {
    u8 _0[0x8];
    u8 m_version;
    u8 field_9;
    u8 _a[0x6];
    Unk_158f110 field_10;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158f260, 0x38);
PKMN_OFFSET_ASSERT(Unk_158f260, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_158f260, field_10, 0x10);

struct Unk_158c980 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    nn::nex::String field_10;
    u16 field_38;
    u8 _3a[0x6];
    Unk_162d630 field_40;
    Unk_158bc50 field_78;
    Unk_158bc50 field_a0;
    u32 field_c8;
    u16 field_cc;
    u8 _ce[0x2];
    u32 field_d0;
    u8 _d4[0x4];
    nn::nex::qVector<nn::nex::String> field_d8;
    nn::nex::qVector<Unk_158f260> field_f0;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158c980, 0x108);
PKMN_OFFSET_ASSERT(Unk_158c980, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_158c980, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158c980, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_158c980, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_158c980, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_158c980, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_158c980, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_158c980, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_158c980, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_158c980, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_158c980, field_f0, 0xf0);

struct Unk_158cb70 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];
    u64 field_20;
    nn::nex::qVector<nn::nex::String> field_28;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158cb70, 0x40);
PKMN_OFFSET_ASSERT(Unk_158cb70, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158cb70, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158cb70, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_158cb70, field_28, 0x28);

struct Unk_158ec60 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    u64 field_10;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158ec60, 0x18);
PKMN_OFFSET_ASSERT(Unk_158ec60, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_158ec60, field_10, 0x10);

struct Unk_158ed50 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];
    u64 field_20;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158ed50, 0x28);
PKMN_OFFSET_ASSERT(Unk_158ed50, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158ed50, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_158ed50, field_20, 0x20);

struct Unk_158f560 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u8 field_18;
    u8 _19[0x7];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_158f560, 0x20);
PKMN_OFFSET_ASSERT(Unk_158f560, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_158f560, field_18, 0x18);

struct Unk_1591630 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];
    u64 field_20;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_1591630, 0x28);
PKMN_OFFSET_ASSERT(Unk_1591630, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1591630, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1591630, field_20, 0x20);

struct Unk_1591910 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u8 field_18;
    u8 _19[0x7];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_1591910, 0x20);
PKMN_OFFSET_ASSERT(Unk_1591910, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1591910, field_18, 0x18);

struct Unk_1591a00 {
    u8 _0[0x8];
    u8 m_version;
    u8 field_9;
    u8 field_a;
    u8 _b[0x5];
    Unk_162d630 field_10;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_1591a00, 0x48);
PKMN_OFFSET_ASSERT(Unk_1591a00, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_1591a00, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_1591a00, field_10, 0x10);

struct Unk_16345b0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    u32 field_10;
    u8 _14[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_16345b0, 0x18);
PKMN_OFFSET_ASSERT(Unk_16345b0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_16345b0, field_10, 0x10);

struct Unk_15a6e50 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    nn::nex::qVector<nn::nex::String> field_10;
    nn::nex::String field_28;
    nn::nex::String field_50;
    nn::nex::String field_78;
    nn::nex::String field_a0;
    bool field_c8;
    bool field_c9;
    bool field_ca;
    u8 _cb[0x1];
    u32 field_cc;
    u16 field_d0;
    u8 _d2[0x6];
    Unk_15a4f80 field_d8;
    bool field_100;
    bool field_101;
    u8 _102[0x2];
    u32 field_104;
    nn::nex::String field_108;
    Unk_16345b0 field_130;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a6e50, 0x148);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_c9, 0xc9);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_ca, 0xca);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_101, 0x101);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_104, 0x104);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_108, 0x108);
PKMN_OFFSET_ASSERT(Unk_15a6e50, field_130, 0x130);

struct Unk_15a1f30 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    Unk_15a5a50 field_10;
    nn::nex::qList<u64> field_160;
    u32 field_178;
    u32 field_17c;
    nn::nex::String field_180;
    u16 field_1a8;
    u8 _1aa[0x6];
    nn::nex::qList<Unk_15a6e50> field_1b0;
    nn::nex::qList<u32> field_1c8;
    Unk_15a3800 field_1e0;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a1f30, 0x1e8);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_160, 0x160);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_178, 0x178);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_17c, 0x17c);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_1a8, 0x1a8);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_1c8, 0x1c8);
PKMN_OFFSET_ASSERT(Unk_15a1f30, field_1e0, 0x1e0);

struct Unk_15a2850 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    nn::nex::String field_10;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a2850, 0x38);
PKMN_OFFSET_ASSERT(Unk_15a2850, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_15a2850, field_10, 0x10);

struct Unk_15a2e20 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    Unk_15a2fc0 field_10;
    u32 field_28;
    u8 _2c[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a2e20, 0x30);
PKMN_OFFSET_ASSERT(Unk_15a2e20, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15a2e20, field_28, 0x28);

struct Unk_15a3220 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    Unk_15a5a50 field_10;
    nn::nex::qList<u64> field_160;
    u32 field_178;
    u32 field_17c;
    nn::nex::String field_180;
    u16 field_1a8;
    u8 _1aa[0x6];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a3220, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_15a3220, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15a3220, field_160, 0x160);
PKMN_OFFSET_ASSERT(Unk_15a3220, field_178, 0x178);
PKMN_OFFSET_ASSERT(Unk_15a3220, field_17c, 0x17c);
PKMN_OFFSET_ASSERT(Unk_15a3220, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_15a3220, field_1a8, 0x1a8);

struct Unk_15a3380 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    nn::nex::qList<u64> field_10;
    u32 field_28;
    u8 _2c[0x4];
    Unk_15a3800 field_30;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a3380, 0x38);
PKMN_OFFSET_ASSERT(Unk_15a3380, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15a3380, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_15a3380, field_30, 0x30);

struct Unk_15a3640 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    nn::nex::qList<u64> field_10;
    u32 field_28;
    u32 field_2c;
    u8 field_30;
    u8 _31[0x7];
    nn::nex::String field_38;
    nn::nex::String field_60;
    nn::nex::String field_88;
    u16 field_b0;
    u16 field_b2;
    u8 _b4[0x4];
    Unk_15a3800 field_b8;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a3640, 0xc0);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_b2, 0xb2);
PKMN_OFFSET_ASSERT(Unk_15a3640, field_b8, 0xb8);

struct Unk_15a50e0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    Unk_15a5230 field_10;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a50e0, 0x18);
PKMN_OFFSET_ASSERT(Unk_15a50e0, field_10, 0x10);

struct Unk_15a86c0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    Unk_15a8860 field_10;
    u32 field_28;
    u8 _2c[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15a86c0, 0x30);
PKMN_OFFSET_ASSERT(Unk_15a86c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15a86c0, field_28, 0x28);

struct Unk_15aefd0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15aefd0, 0x20);
PKMN_OFFSET_ASSERT(Unk_15aefd0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15aefd0, field_18, 0x18);

struct Unk_15af470 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u8 _24[0x4];
    Unk_162d630 field_28;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15af470, 0x60);
PKMN_OFFSET_ASSERT(Unk_15af470, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15af470, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_15af470, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_15af470, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_15af470, field_28, 0x28);

struct Unk_15af2e0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    nn::nex::qVector<Unk_15af470> field_18;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15af2e0, 0x30);
PKMN_OFFSET_ASSERT(Unk_15af2e0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15af2e0, field_18, 0x18);

struct Unk_15af9d0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    u32 field_10;
    u8 _14[0x4];
    nn::nex::qVector<u64> field_18;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15af9d0, 0x30);
PKMN_OFFSET_ASSERT(Unk_15af9d0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_15af9d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15af9d0, field_18, 0x18);

struct Unk_15b04b0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    u32 field_10;
    u8 _14[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15b04b0, 0x18);
PKMN_OFFSET_ASSERT(Unk_15b04b0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_15b04b0, field_10, 0x10);

struct Unk_15b05c0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    u64 field_10;
    u32 field_18;
    u8 _1c[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15b05c0, 0x20);
PKMN_OFFSET_ASSERT(Unk_15b05c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15b05c0, field_18, 0x18);

struct Unk_15b2dc0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x3];
    u32 field_c;
    u64 field_10;
    u64 field_18;
    u16 field_20;
    u16 field_22;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u8 _34[0x4];
    nn::nex::String field_38;

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_15b2dc0, 0x60);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_22, 0x22);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_15b2dc0, field_38, 0x38);

struct Unk_162f8a0 {
    u8 _0[0x8];
    u8 m_version;
    u8 _9[0x7];
    Unk_162d5a0 field_10;
    u32 field_80;
    u8 _84[0x4];

    u8 GetVersion() const { return m_version; }
};
PKMN_SIZE_ASSERT(Unk_162f8a0, 0x88);
PKMN_OFFSET_ASSERT(Unk_162f8a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_162f8a0, field_80, 0x80);

void Unk_158bc50_write(nn::nex::ByteStream* s, const Unk_158bc50& v);
void Unk_1589f50_write(nn::nex::ByteStream* s, const Unk_1589f50& v);
void Unk_158c210_write(nn::nex::ByteStream* s, const Unk_158c210& v);
void Unk_158a0f0_write(nn::nex::ByteStream* s, const Unk_158a0f0& v);
void Unk_158a2d0_write(nn::nex::ByteStream* s, const Unk_158a2d0& v);
void Unk_158a460_write(nn::nex::ByteStream* s, const Unk_158a460& v);
void Unk_158a540_write(nn::nex::ByteStream* s, const Unk_158a540& v);
void Unk_158a620_write(nn::nex::ByteStream* s, const Unk_158a620& v);
void Unk_158a880_write(nn::nex::ByteStream* s, const Unk_158a880& v);
void Unk_158a970_write(nn::nex::ByteStream* s, const Unk_158a970& v);
void Unk_158aa70_write(nn::nex::ByteStream* s, const Unk_158aa70& v);
void Unk_158ac40_write(nn::nex::ByteStream* s, const Unk_158ac40& v);
void Unk_158ad60_write(nn::nex::ByteStream* s, const Unk_158ad60& v);
void Unk_158ae80_read(nn::nex::ByteStream* s, Unk_158ae80& v);
void Unk_158b6f0_read(nn::nex::ByteStream* s, Unk_158b6f0& v);
void Unk_158b890_read(nn::nex::ByteStream* s, Unk_158b890& v);
void Unk_158ba20_read(nn::nex::ByteStream* s, Unk_158ba20& v);
void Unk_158bf20_read(nn::nex::ByteStream* s, Unk_158bf20& v);
void Unk_158c110_write(nn::nex::ByteStream* s, const Unk_158c110& v);
void Unk_158c300_write(nn::nex::ByteStream* s, const Unk_158c300& v);
void Unk_158c460_write(nn::nex::ByteStream* s, const Unk_158c460& v);
void Unk_158f110_write(nn::nex::ByteStream* s, const Unk_158f110& v);
void Unk_158f260_write(nn::nex::ByteStream* s, const Unk_158f260& v);
void Unk_158c980_write(nn::nex::ByteStream* s, const Unk_158c980& v);
void Unk_158cb70_write(nn::nex::ByteStream* s, const Unk_158cb70& v);
void Unk_158ec60_write(nn::nex::ByteStream* s, const Unk_158ec60& v);
void Unk_158ed50_read(nn::nex::ByteStream* s, Unk_158ed50& v);
void Unk_158f560_write(nn::nex::ByteStream* s, const Unk_158f560& v);
void Unk_1591630_write(nn::nex::ByteStream* s, const Unk_1591630& v);
void Unk_1591910_write(nn::nex::ByteStream* s, const Unk_1591910& v);
void Unk_1591a00_write(nn::nex::ByteStream* s, const Unk_1591a00& v);
void Unk_16345b0_write(nn::nex::ByteStream* s, const Unk_16345b0& v);
void Unk_15a6e50_write(nn::nex::ByteStream* s, const Unk_15a6e50& v);
void Unk_15a1f30_write(nn::nex::ByteStream* s, const Unk_15a1f30& v);
void Unk_15a2850_write(nn::nex::ByteStream* s, const Unk_15a2850& v);
void Unk_15a2e20_read(nn::nex::ByteStream* s, Unk_15a2e20& v);
void Unk_15a3220_write(nn::nex::ByteStream* s, const Unk_15a3220& v);
void Unk_15a3380_write(nn::nex::ByteStream* s, const Unk_15a3380& v);
void Unk_15a3640_write(nn::nex::ByteStream* s, const Unk_15a3640& v);
void Unk_15a50e0_read(nn::nex::ByteStream* s, Unk_15a50e0& v);
void Unk_15a86c0_read(nn::nex::ByteStream* s, Unk_15a86c0& v);
void Unk_15aefd0_write(nn::nex::ByteStream* s, const Unk_15aefd0& v);
void Unk_15af470_write(nn::nex::ByteStream* s, const Unk_15af470& v);
void Unk_15af2e0_write(nn::nex::ByteStream* s, const Unk_15af2e0& v);
void Unk_15af9d0_write(nn::nex::ByteStream* s, const Unk_15af9d0& v);
void Unk_15b04b0_write(nn::nex::ByteStream* s, const Unk_15b04b0& v);
void Unk_15b05c0_write(nn::nex::ByteStream* s, const Unk_15b05c0& v);
void Unk_15b2dc0_write(nn::nex::ByteStream* s, const Unk_15b2dc0& v);
void Unk_162f8a0_read(nn::nex::ByteStream* s, Unk_162f8a0& v);
