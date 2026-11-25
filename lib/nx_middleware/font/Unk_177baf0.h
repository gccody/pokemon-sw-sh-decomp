#pragma once
// NintendoWare Font 7.3.2: nn::font::ResFont (RTTI) and its base, the class of
// vtable 0x710246a5c8 (no RTTI: Unk_246a5b8), which reads a FFNT font resource,
// and the texture object it holds (nn::font::ResourceTextureObject, RTTI, and
// its abstract base, vtable 0x710246a768: Unk_246a758). Placeholder member
// names: vf<slot> for virtual functions (as tools/leafgen.py names them),
// Unk_<addr> for the others. Fields are named after their offsets.
#include <types.h>

struct Unk_239a418_Type;

// Free-function placeholders of lib/nx_middleware/leaf/Unk_17792a0.cpp. They
// take the object they set up as a pointer to their own placeholder struct.
struct Unk_177c0b0;
struct Unk_177c0d0;
struct Unk_177c9e0;
struct Unk_177cd90;
void Unk_177c0b0_set(Unk_177c0b0* self, u64 value, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6);
u64 Unk_177c0d0_update(Unk_177c0d0* self);
void Unk_177c9e0_call(Unk_177c9e0* self, u64 value);
void Unk_177cd90_set(Unk_177cd90* self, u64 value, u16 arg2, u16 arg3, u16 arg4, u8 arg5, bool arg6);

// The data blocks of a FFNT resource: a 4-character kind and the block's size
// (header included), followed by the block's data.
struct Unk_177baf0_Block {
    u32 kind;
    u32 size;
};
PKMN_SIZE_ASSERT(Unk_177baf0_Block, 0x8);

// The FFNT file header.
struct Unk_177baf0_File {
    u32 signature;
    u16 byteOrder;
    u16 headerSize;
    u32 version;
    u32 fileSize;
    u16 blockCount;
};
PKMN_OFFSET_ASSERT(Unk_177baf0_File, byteOrder, 0x4);
PKMN_OFFSET_ASSERT(Unk_177baf0_File, headerSize, 0x6);
PKMN_OFFSET_ASSERT(Unk_177baf0_File, version, 0x8);
PKMN_OFFSET_ASSERT(Unk_177baf0_File, fileSize, 0xc);
PKMN_OFFSET_ASSERT(Unk_177baf0_File, blockCount, 0x10);
PKMN_SIZE_ASSERT(Unk_177baf0_File, 0x14);

// A character's widths (the FINF block's default ones).
struct Unk_177baf0_Widths {
    s8 field_0;
    u8 field_1;
    s8 field_2;
};
PKMN_SIZE_ASSERT(Unk_177baf0_Widths, 0x3);

// The FINF block's data. The offsets are from the start of the file.
struct Unk_177baf0_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    s16 field_4;
    u16 field_6;
    Unk_177baf0_Widths field_8;
    u8 field_b;
    u32 glyphOffset;  // TGLP data
    u32 field_10;
    u32 mapOffset;  // the first CMAP data
};
PKMN_OFFSET_ASSERT(Unk_177baf0_Info, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_177baf0_Info, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_177baf0_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_177baf0_Info, field_b, 0xb);
PKMN_OFFSET_ASSERT(Unk_177baf0_Info, glyphOffset, 0xc);
PKMN_OFFSET_ASSERT(Unk_177baf0_Info, mapOffset, 0x14);

// The TGLP block's data.
struct Unk_177baf0_Glyph {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u32 field_4;
    s16 field_8;
    u16 field_a;
};
PKMN_OFFSET_ASSERT(Unk_177baf0_Glyph, field_3, 0x3);
PKMN_OFFSET_ASSERT(Unk_177baf0_Glyph, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_177baf0_Glyph, field_a, 0xa);

// An entry of a scanned CMAP: a character and its glyph index.
struct Unk_177baf0_ScanEntry {
    u32 code;
    u16 index;
};
PKMN_SIZE_ASSERT(Unk_177baf0_ScanEntry, 0x8);

// A CMAP block's data: the characters [codeBegin, codeEnd] and how they map
// to glyph indices (0: from an offset, 1: a table, 2: a sorted list).
struct Unk_177baf0_Map {
    u32 codeBegin;
    u32 codeEnd;
    u16 method;
    u16 field_a;
    u32 next;  // the next CMAP data, from the start of the file (0: none)
    u16 info[1];
};
PKMN_OFFSET_ASSERT(Unk_177baf0_Map, method, 0x8);
PKMN_OFFSET_ASSERT(Unk_177baf0_Map, next, 0xc);
PKMN_OFFSET_ASSERT(Unk_177baf0_Map, info, 0x10);

// A sorted CMAP's info: its entries' count, then the entries.
struct Unk_177baf0_Scan {
    u16 count;
    u16 field_2;
    Unk_177baf0_ScanEntry entries[1];
};
PKMN_OFFSET_ASSERT(Unk_177baf0_Scan, entries, 0x4);

// The texture object's abstract base (vtable 0x710246a768).
class Unk_246a758 {
public:
    Unk_246a758() : field_20(-1) { Reset(); }
    virtual ~Unk_246a758() { Reset(); }
    virtual void* vf2() = 0;
    virtual void* vf3() = 0;

    void Reset() {
        Unk_177cd90_set(reinterpret_cast<Unk_177cd90*>(this), 0, 0xc, 0, 0, 0, true);
        field_20 = -1;
        field_18 = false;
    }

    u8 _8[0x10];  // Unk_177cd90_set's
    bool field_18;
    s64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_246a758, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_246a758, field_20, 0x20);
PKMN_SIZE_ASSERT(Unk_246a758, 0x28);

struct Unk_177baf0_Texture {
    u8 _0[0x88];
    const void* field_88;
};
PKMN_OFFSET_ASSERT(Unk_177baf0_Texture, field_88, 0x88);

namespace nn {
namespace font {

class ResourceTextureObject : public Unk_246a758 {
public:
    ResourceTextureObject() : field_28(nullptr) { Reset(); }
    void* vf2() override;
    void* vf3() override;

    const Unk_177baf0_Texture* field_28;
};
PKMN_OFFSET_ASSERT(ResourceTextureObject, field_28, 0x28);
PKMN_SIZE_ASSERT(ResourceTextureObject, 0x30);

class Font {
public:
    Font();
    virtual const Unk_239a418_Type* vf0();
    virtual ~Font();
    virtual void vf3(u64 arg);
    virtual u32 vf4();
    virtual u32 vf5();
    virtual u32 vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual u32 vf9();
    virtual u32 vf10();
    virtual s32 vf11();
    virtual Unk_177baf0_Widths vf12();
    virtual void vf13(s8 value);
    virtual void vf14(const Unk_177baf0_Widths* value);
    virtual bool vf15(u32 code);
    virtual u32 vf16();
    virtual u32 vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual u32 vf21();
    virtual s32 vf22();
    virtual u32 vf23();
    virtual u32 vf24();
    virtual void vf25(bool arg1, bool arg2);
    virtual u32 vf26();
    virtual u32 vf27();
    virtual u32 vf28();
    virtual u32 vf29();
    virtual void vf30(bool value);
    virtual bool vf31();
    virtual bool vf32();

    u8 field_8;
    u8 field_9;
};
PKMN_OFFSET_ASSERT(Font, field_8, 0x8);
PKMN_OFFSET_ASSERT(Font, field_9, 0x9);

}  // namespace font
}  // namespace nn

class Unk_246a5b8 : public nn::font::Font {
public:
    using Callback = void (*)(s64* slot, const void* texture, void* arg);

    Unk_246a5b8();
    const Unk_239a418_Type* vf0() override;
    ~Unk_246a5b8() override;
    virtual void vf33();

    void Unk_177c0f0(Callback callback, void* arg);
    void Unk_177c120(Callback callback, void* arg);
    u16 Unk_177c2d0(u32 code) const;
    void Unk_177c900(u64 arg);

    u64 field_10;
    const u8* field_18;  // the resource
    Unk_177baf0_Info* field_20;
    nn::font::ResourceTextureObject field_28;
    u32 field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    s32 rangeCount;
    u32 rangeBegin[16];
    u32 rangeEnd[16];
};
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_10, 0x10);
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
    ResFont();
    const Unk_239a418_Type* vf0() override;
    ~ResFont() override;
    void vf3(u64 arg) override;
    u32 vf8() override;
    u32 vf10() override;
    s32 vf11() override;
    Unk_177baf0_Widths vf12() override;
    void vf13(s8 value) override;
    bool vf15(u32 code) override;
    s32 vf22() override;
    u32 vf23() override;
    u32 vf24() override;

    u64 Unk_177bbb0(u64 arg);
    bool Unk_177bbf0(u64 arg, void* resource, u64 arg3, u64 arg4, u64 arg5);

    const Unk_177baf0_Glyph* Glyph() const {
        return reinterpret_cast<const Unk_177baf0_Glyph*>(field_18 + field_20->glyphOffset);
    }
};

}  // namespace font
}  // namespace nn
