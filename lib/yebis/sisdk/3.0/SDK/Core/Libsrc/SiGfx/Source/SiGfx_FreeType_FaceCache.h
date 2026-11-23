// SiSDK3::SiGfxFreeTypeFaceCache and SiGfxQuadTree<CacheData> (RTTI names
// the classes): the texture a FreeType face's glyphs are drawn into, the
// image they're drawn into first, and the quad tree that hands out the room
// for each glyph. Placeholder members; the virtual functions are vf<slot>.
// The reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_FREETYPE_FACECACHE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Pool.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DescriptorTable_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Texture_Impl.h>

namespace SiSDK3 {

class SiGfxFreeTypeFace;
class SiGfxNXDevice;

// SiSDK3::ISiGfxTexture (RTTI names it: the device's slot 49 makes one) as
// the cache calls it: like the NX texture it is on ISiInterface and, at 8, on
// the named object. Placeholder slots; slot 19 is its description, slot 22
// makes it from one.
struct Unk_FaceCacheTextureInfo {
    u32 field_0;  // what the texture chunk's reader compares with the kind it read
    u8 field_4[0x10];
    s32 field_14;  // width
    s32 field_18;  // height
};
class ISiGfxTexture : public Unk_NXInterface, public Unk_NXTextureNamedObject {
public:
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual const Unk_FaceCacheTextureInfo* vf19();
    virtual void vf20();
    virtual void vf21();
    virtual bool vf22(const void* desc);
    // fills the texture in from an image, by a description (the texture
    // utility's slot 8)
    virtual bool vf23(const void* desc, SiGfxImage* image);
    // (as the texture chunk's reader calls them: slot 37 tells whether slot
    // 39 sets the kind)
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual bool vf37();
    virtual void vf38();
    virtual bool vf39(u32 kind);
};

// SiSDK3::ISiGfxDescriptorTable (RTTI: the NX table's base, through
// ISiGfxNXDescriptorTable) as the cache calls it: placeholder slots. Slot 8
// starts the changes (a kind and a second number the NX table doesn't
// use), slot 9 ends them, slot 10 sets the first list's count and slot 12
// one of its resources.
class ISiGfxDescriptorTable : public Unk_NXInterface {
public:
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual bool vf8(u32 kind, u32 a2);
    virtual bool vf9();
    virtual bool vf10(s32 count);
    virtual void vf11();
    virtual bool vf12(s32 index, ISiGfxTexture* resource);
};

// What the cache makes its image of (placeholder name): the image's
// description and two more members its slot 8 doesn't read.
struct Unk_FaceCacheImageInfo {
    Unk_FaceCacheImageInfo() : field_20(0), field_28(true) {}

    SiGfxImage::Unk_Info field_0;
    u64 field_20;
    bool field_28;
};
PKMN_OFFSET_ASSERT(Unk_FaceCacheImageInfo, field_20, 0x20);

// FreeType's FT_Bitmap (lib/freetype's ftimage.h), as the cache reads a
// glyph's: placeholder names for the members.
struct Unk_FTBitmap {
    u32 field_0;   // rows
    u32 field_4;   // width
    s32 field_8;   // pitch
    u8* field_10;  // buffer
    u16 field_18;  // num_grays
    u8 field_1a;   // pixel_mode (1: one bit a pixel, 2: one byte)
};

// SiSDK3::SiGfxFreeTypeGlyph (RTTI: SiPool's element) as the cache uses
// it: 0x98 bytes, a pool's item. The cache fills in the glyph's metrics in
// pixels, where it is in the texture and its texture coordinates.
class SiGfxFreeTypeGlyph {
public:
    SiGfxFreeTypeGlyph();   // 0x710050ae10 (Unk_50ae50.cpp)
    ~SiGfxFreeTypeGlyph();  // 0x710050ae50

    SiGfxFreeTypeGlyph* m_pPrev;
    SiGfxFreeTypeGlyph* m_pNext;
    s64 field_10;
    bool field_18;
    u8 field_19[0x37];
    s32 field_50;  // the character
    s32 field_54;  // its glyph's index in the face
    s32 field_58;
    s32 field_5c;
    s32 field_60;
    s32 field_64;
    s32 field_68;
    s32 field_6c;
    s32 field_70;  // x in the texture
    s32 field_74;  // y in the texture
    s32 field_78;
    s32 field_7c;
    f32 field_80;
    f32 field_84;
    f32 field_88;
    f32 field_8c;
    s32 field_90;
    s32 field_94;
};
PKMN_OFFSET_ASSERT(SiGfxFreeTypeGlyph, field_58, 0x58);
PKMN_SIZE_ASSERT(SiGfxFreeTypeGlyph, 0x98);

// A range of coordinates (placeholder name): its first and its end.
struct Unk_FaceCacheRange {
    s32 field_0;
    s32 field_4;
};

// FreeType's FT_GlyphSlotRec (lib/freetype's freetype.h) as the cache reads
// the face's: placeholder names, FreeType's in the comments.
struct Unk_FTGlyphSlot {
    u8 _0[0x40];
    s64 field_40;  // metrics.horiBearingX
    s64 field_48;  // metrics.horiBearingY
    s64 field_50;  // metrics.horiAdvance
    u8 _58[0x10];
    s64 field_68;  // metrics.vertAdvance
    u8 _70[0x28];
    Unk_FTBitmap field_98;  // bitmap
};
PKMN_OFFSET_ASSERT(Unk_FTGlyphSlot, field_98, 0x98);

// A rectangle (placeholder name): its x and its y.
struct Unk_FaceCacheRect {
    Unk_FaceCacheRange field_0;
    Unk_FaceCacheRange field_8;
};

template <class T>
class SiGfxQuadTree {
public:
    // A node (SiPool's element): its links and index in the pool, whether
    // it's in use, its four children, the rectangle it covers, the glyph's
    // index and whether it holds one.
    struct QuadNode {
        // empties it (inline: placeholder name)
        void Unk_Reset() {
            field_54 = false;
            for (int i = 0; i < 4; i++) {
                field_20[i] = nullptr;
            }
        }

        QuadNode* m_pPrev;
        QuadNode* m_pNext;
        s64 field_10;
        bool field_18;
        QuadNode* field_20[4];
        Unk_FaceCacheRange field_40;  // x
        Unk_FaceCacheRange field_48;  // y
        s32 field_50;
        bool field_54;
    };

    explicit SiGfxQuadTree(ISiAllocator* pAllocator)
        : field_8(pAllocator), field_10(pAllocator, true), field_138(nullptr), field_140(0), field_144(0) {}
    // 0x7100530ed0 (D2), 0x7100531bd0 (D0)
    virtual ~SiGfxQuadTree() { vf3(); }
    // 0x7100531240: a tree of a size, with room for count nodes
    virtual bool vf2(u32 width, u32 height, size_t count);
    // 0x71005313f0: empties it
    virtual void vf3() {
        field_10.Unk_4bd7e0();
        field_138 = nullptr;
    }

    // 0x7100531750: empties it and makes its root again
    void Unk_531750();
    // 0x7100532ca0: the free node a rectangle fits, under a node, split off
    // the first leaf it fits into (null: none)
    QuadNode* Unk_532ca0(QuadNode* node, const Unk_FaceCacheRect* rect);
    // 0x7100532e90, 0x7100533120, 0x71005333b0: splits a leaf in two at a y,
    // in two at an x, in four at both
    bool Unk_532e90(QuadNode* node, s32 y);
    bool Unk_533120(QuadNode* node, s32 x);
    bool Unk_5333b0(QuadNode* node, s32 x, s32 y);

    ISiAllocator* field_8;
    SiPool<QuadNode, 16> field_10;
    QuadNode* field_138;  // the root
    u32 field_140;        // width
    u32 field_144;        // height
};

class SiGfxFreeTypeFaceCache : public ISiInterface {
public:
    struct CacheData;

    // 0x7100530d80
    SiGfxFreeTypeFaceCache(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);
    // 0x7100530e20 (D2; D0, 0x7100530f10, is a trap: the class is abstract)
    ~SiGfxFreeTypeFaceCache() override;
    u32 vf2() override;
    u32 vf3() override;
    u32 vf4() override;                         // 0x7100531a80
    virtual bool vf5(u32 width, u32 height);    // 0x7100530f50: makes the texture
    virtual void vf6();                         // 0x7100531390: lets go of it
    virtual u32 vf7() = 0;
    // 0x7100531880: draws a glyph's bitmap into the image
    virtual bool vf8(SiGfxFreeTypeGlyph* glyph, const Unk_FTBitmap* bitmap, SiGfxImage* image);

    // 0x7100530f20: the face whose glyphs it keeps
    void Unk_530f20(SiGfxFreeTypeFace* pFace);
    // 0x71005316f0: names the texture
    void Unk_5316f0(const char* name);
    // 0x7100531710: forgets every glyph
    void Unk_531710();
    // 0x7100531420: a new glyph's place in the texture (declared for the
    // face, 0x7100500890, which calls it; not written yet)
    bool Unk_531420(SiGfxFreeTypeGlyph* glyph);
    // what vf6 and the destructors do (inline: placeholder name)
    void Unk_Release() {
        field_1c0.vf3();
        field_40.vf15();
        if (field_38 != nullptr) {
            field_38->vf3();
            field_38 = nullptr;
        }
        if (field_30 != nullptr) {
            field_30->vf3();
            field_30 = nullptr;
        }
    }

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u64 field_20;                     // the FreeType face
    SiGfxFreeTypeFace* field_28;
    ISiGfxTexture* field_30;          // the texture
    ISiGfxDescriptorTable* field_38;  // the table that holds it
    SiGfxImage field_40;
    SiGfxQuadTree<CacheData> field_1c0;
    s32 field_308;  // the room around each glyph
    // the rectangle that has changed since the texture was last written
    Unk_FaceCacheRange field_30c;
    Unk_FaceCacheRange field_314;
};
PKMN_OFFSET_ASSERT(SiGfxFreeTypeFaceCache, field_40, 0x40);
PKMN_OFFSET_ASSERT(SiGfxFreeTypeFaceCache, field_1c0, 0x1c0);
PKMN_OFFSET_ASSERT(SiGfxFreeTypeFaceCache, field_308, 0x308);
PKMN_SIZE_ASSERT(SiGfxFreeTypeFaceCache, 0x320);

// SiSDK3::SiGfxNXFreeTypeFaceCache: the NX one, 0x320 bytes too.
class SiGfxNXFreeTypeFaceCache : public SiGfxFreeTypeFaceCache {
public:
    // 0x71005339d0
    explicit SiGfxNXFreeTypeFaceCache(SiGfxNXDevice* pDevice);
    // 0x7100533a10 (D2), 0x7100533a90 (D0)
    ~SiGfxNXFreeTypeFaceCache() override;
    bool vf5(u32 width, u32 height) override;  // 0x7100533b10
    void vf6() override;                       // 0x7100533da0
    u32 vf7() override;                        // 0x7100533e00
    // 0x7100533e10: draws it into the texture
    bool vf8(SiGfxFreeTypeGlyph* glyph, const Unk_FTBitmap* bitmap, SiGfxImage* image) override;
};

}  // namespace SiSDK3

#ifdef UNK_SIGFX_FREETYPE_FACECACHE_IMPL
// 0x71005319e0 (vf2), 0x7100531a00 (vf3)
#line 42
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxFreeTypeFaceCache, field_8.m_pAllocator, field_8.m_count)
#endif
