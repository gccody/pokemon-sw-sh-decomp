// PPFX::CRenderTexture (RTTI; C:/workspace/YEBIS_draft/src/GPU/GPURenderTexture.cpp
// is the __FILE__ of its allocations and log lines): a render target, its
// description, its mip levels' surfaces and the device state it changes.
// Placeholder members. vf0 is "CRenderTexture::InitializeDevice()" in the log.
#pragma once

#include <vector>

#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/YEBIS_draft/src/GPU/GPUResourceManage.h>

namespace PPFX {
// what GPUPostEffect.h calls a render texture
struct Unk_RenderTexture;
class IGPUInterface;
class CRenderTexture;
}  // namespace PPFX

// 0x710049ad30: a render texture's viewport. It keeps the name its first
// caller (GPUPostEffect.h) gave it.
s32 Unk_49ad30(PPFX::CRenderTexture* texture, s32 width, s32 height, s32 x, s32 y);

namespace PPFX {

// What a render texture is made from. 0x21 bytes of members in 0x24: it has
// a constructor, so a copy leaves the padding alone.
struct Unk_49ab20_Desc {
    Unk_49ab20_Desc()
        : field_0(0), field_4(0), field_8(0), field_c(0), field_10(1), field_14(0), field_18(0), field_1c(0),
          field_20(false) {}
    Unk_49ab20_Desc(u32 flags, s32 width, s32 height, s32 format)
        : field_0(flags), field_4(width), field_8(height), field_c(format), field_10(1), field_14(0), field_18(0),
          field_1c(0), field_20(false) {}
    // memberwise (CRenderTextureArray::Initialize's copy is a load and a store
    // per member, the bool's a byte, not a block copy)
    Unk_49ab20_Desc(const Unk_49ab20_Desc& other)
        : field_0(other.field_0), field_4(other.field_4), field_8(other.field_8), field_c(other.field_c),
          field_10(other.field_10), field_14(other.field_14), field_18(other.field_18), field_1c(other.field_1c),
          field_20(other.field_20) {}

    u32 field_0;  // flags
    s32 field_4;  // width
    s32 field_8;  // height
    s32 field_c;  // format
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
    bool field_20;
};
PKMN_SIZE_ASSERT(Unk_49ab20_Desc, 0x24);

// Rectangles (0x20 bytes each) and the size they cover
class Unk_49a890 {
public:
    struct Unk_Rect {
        ~Unk_Rect() {}

        u64 field_0;  // left, top, right, bottom
        u64 field_8;
        u64 field_10;
        u64 field_18;
    };

    Unk_49a890() : field_0(0), field_8(nullptr) {}
    Unk_49a890(const Unk_49a890& other) { *this = other; }
    ~Unk_49a890() { UNK_DELETE_ARRAY(field_8); }
    Unk_49a890& operator=(const Unk_49a890& other);  // 0x710049a890
    // the widest and the tallest rectangle (inline)
    void Unk_UpdateSize() {
        field_10 = 0;
        field_14 = 0;
        u32 count = field_0;
        for (u32 i = 0; i < count; i++) {
            u32 width = field_8[i].field_10 - field_8[i].field_0;
            u32 height = field_8[i].field_18 - field_8[i].field_8;
            field_10 = field_10 > width ? field_10 : width;
            field_14 = field_14 > height ? field_14 : height;
        }
    }

    u32 field_0;  // the number of rectangles
    Unk_Rect* field_8;
    u32 field_10;  // the widest and the tallest
    u32 field_14;
};
PKMN_SIZE_ASSERT(Unk_49a890, 0x18);

// What 0x71024e53e0 points at, as far as the tiling calls it
struct Unk_49df00_Context {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23(u32 index, struct Unk_49b230_Object** out);
};

// The interfaces the texture's device hands out (PPFX::IGPUSurface,
// IGPUTexture: their classes are before this TU), as far as CRenderTexture
// calls them.
// what a texture's level tells of its size (0x18 bytes: vf6's frame)
struct Unk_49b230_Desc {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
};

struct Unk_49b230_Object {
    virtual void vf0();  // one reference more
    virtual void vf1();  // one less
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual s32 vf8(struct Unk_49b230_Desc* desc);  // a level's size
    virtual s32 vf9();  // 0x710048d7f0 calls it before it draws into the surface
    virtual s32 vf10();  // and this after
    virtual void vf11();
    virtual u32 vf12();  // a texture's number of mip levels
    virtual void vf13();
    virtual void vf14();
    virtual s32 vf15(u32 state);  // the sampler state's bits
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual s32 vf23(u32 level, Unk_49b230_Object** surface);  // a texture's mip level's surface

    u8 _8[0x24 - 0x8];
    u32 field_24;  // its usage flags (IGPUResource's; bit 0: a render target too)
    u32 field_28;  // a surface's flags (bit 28: tiled)
    u8 _2c[0x44 - 0x2c];
    s32 field_44;  // its format
    u8 _48[0x4c - 0x48];
    u32 field_4c;  // its size (as a depth target's, compared)
    u32 field_50;
    s32 field_54;  // a surface's size
    s32 field_58;
};

class CRenderTexture : public CGPUResourceManage {
public:
    // viewport, as the device's frame slots keep it
    struct Unk_Viewport {
        ~Unk_Viewport() {}

        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
    };
    // a mip level's size
    struct Unk_Level {
        ~Unk_Level() {}

        u64 field_0;
        u32 field_8;
        u32 field_c;
        f32 field_10;
        f32 field_14;
    };

    // the part of a render target a tile covers (16 bytes)
    struct Unk_Tile {
        Unk_Tile() : field_0(0), field_4(0), field_8(0), field_c(0) {}

        s32 field_0;
        s32 field_4;
        s32 field_8;
        s32 field_c;
    };

    explicit CRenderTexture(const char* name);  // 0x710049a9c0
    s32 vf0(IGPUDevice* device) override;       // 0x710049b080
    s32 vf1() override;                         // 0x710049c0b0
    s32 vf2() override;                         // 0x710049c610
    s32 vf3() override;                         // 0x710049c640
    ~CRenderTexture() override;                 // 0x710049afd0, 0x710049b020
    virtual s32 vf6(IGPUDevice* device, Unk_49b230_Object* texture);  // 0x710049bb30

    s32 Unk_49aa20(const char* name);             // 0x710049aa20
    s32 Unk_49ab20(const Unk_49ab20_Desc* desc);  // 0x710049ab20: (re)creates it
    s32 Unk_49b230();  // 0x710049b230: makes the device's objects
    // 0x710049c760: a render target of a set's slot, with its tiles
    // 0x710049cfa0: whether the device's target `slot` is this texture's
    // (every tile's, when it is tiled)
    s32 Unk_49cfa0(u32 slot, u32 level, u32 arg3, u32 arg4, s32 arg5, bool force, void* arg7, s32 arg8,
                   void* arg9, s32 arg10, bool* done, f32 arg11, f32 arg12);
    inline s32 Unk_CheckTarget(u32 slot, u32 level, u32 arg3, u32 arg4, s32 arg5, bool force, void* arg7,
                               s32 arg8, void* arg9, s32 arg10, bool* done, f32 arg11, f32 arg12);
    s32 Unk_49c760(s32 set, u32 slot, u32 width, u32 height, s32 format, s32 msaa, u32 quality, s32 tiled,
                   IGPUInterface** surface);
    // the tiles of a set (inline; negative: the current one)
    Unk_49a890* Unk_SetTiles(s32 set) {
        if (static_cast<s32>(field_2c.field_0) < 0)
            return nullptr;
        if (set < 0)
            set = field_a0;
        return field_f0[set];
    }
    // the tiles of a set's slot (inline)
    Unk_49a890* Unk_SlotTiles(s32 set, u32 slot) {
        if (static_cast<s32>(field_2c.field_0) < 0)
            return nullptr;
        if (set < 0)
            set = field_a0;
        return field_e0[set][slot];
    }
    // 0x710049d250: makes it the device's target
    s32 Unk_49d250(s32 slot, u32 flags, s32 first, u32 level, s32 arg5);
    // 0x710049cf50
    static s32 Unk_49cf50(Unk_49b230_Object* depth, void* owner);
    // 0x710049d7d0, 0x710049e080 (their log lines name them; EndTiling's
    // arguments are its callers', it reads none of them)
    static s32 BeginTiling(s32 mode, const Unk_Tile* tile, s32 arg2, f32 arg3);
    static s32 EndTiling(void* arg0, s32 arg1, s32* arg2, bool* arg3, f32 arg4);
    // the texture whose device objects this one shares (inline: field_120's chain)
    CRenderTexture* Unk_Root() {
        CRenderTexture* texture = this;
        while (texture->field_120 != nullptr)
            texture = texture->field_120;
        return texture;
    }
    // the first texture of field_108 whose root has a texture (inline)
    CRenderTexture* Unk_FindShared() {
        for (CRenderTexture* texture : field_108) {
            if (texture->Unk_Root()->field_a8 != nullptr)
                return texture;
        }
        return nullptr;
    }
    // the tiles of a slot of the current set (field_a0)
    Unk_49a890* Unk_Tiles(u32 slot) { return field_e0[field_a0][slot]; }

    // What the name setter and vf3 share (inline): everything but the frame slots
    void Unk_Reset() {
        field_2c.field_0 = 0;
        field_2c.field_4 = 0;
        field_2c.field_8 = 0;
        field_2c.field_c = 0;
        field_2c.field_10 = 1;
        field_50 = 0;
        field_78 = 0;
        field_98 = 0;
        field_9c = 0;
        field_80 = nullptr;
        field_2c.field_14 = 0;
        field_2c.field_18 = 0;
        field_2c.field_1c = 0;
        field_2c.field_20 = false;
        field_a8 = nullptr;
        field_f0[0] = nullptr;
        field_f0[1] = nullptr;
        field_e0[0] = nullptr;
        field_e0[1] = nullptr;
        field_d0[0] = nullptr;
        field_d0[1] = nullptr;
        field_b8[1] = nullptr;
        field_c8 = nullptr;
        field_b0 = nullptr;
        field_b8[0] = nullptr;
        while (field_a0 != 0)
            field_a0--;
    }
    // the current frame's slot, and every slot set to the viewport (inline)
    inline Unk_Viewport& Unk_Slot();
    inline void Unk_StoreViewport();
    static u32 Unk_Max(u32 a, u32 b) { return a > b ? a : b; }
    // inline: field_a0, stored only when it changes
    void Unk_SetA0(s32 value) {
        if (field_a0 != value)
            field_a0 = value;
    }
    // inline in its callers (its description sits above their own locals)
    s32 Unk_Create(u32 flags, s32 width, s32 height, s32 format) {
        Unk_49ab20_Desc desc(flags, width, height, format);
        return Unk_49ab20(&desc);
    }

    Unk_49ab20_Desc field_2c;
    u32 field_50;
    s32 field_54;  // the viewport
    s32 field_58;
    s32 field_5c;
    s32 field_60;
    Unk_Viewport* field_68;  // one per frame slot
    f32 field_70;
    f32 field_74;
    u32 field_78;
    s32 field_7c;
    Unk_Level* field_80;
    f32 field_88;
    f32 field_8c;
    f32 field_90;
    f32 field_94;
    u32 field_98;  // the number of mip levels
    s32 field_9c;
    s32 field_a0;
    Unk_49b230_Object* field_a8;
    Unk_49b230_Object* field_b0;
    Unk_49b230_Object* field_b8[2];  // a surface for each set
    Unk_49b230_Object** field_c8;
    Unk_49b230_Object** field_d0[2];  // each mip level's target, for two sets
    Unk_49a890** field_e0[2];  // the tiles of each slot, for two sets
    Unk_49a890* field_f0[2];   // the tiles of each set
    u64 field_100;
    std::vector<CRenderTexture*, Unk_StlAllocator<CRenderTexture*>> field_108;
    CRenderTexture* field_120;
};
PKMN_SIZE_ASSERT(CRenderTexture::Unk_Tile, 0x10);
PKMN_OFFSET_ASSERT(CRenderTexture, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(CRenderTexture, field_54, 0x54);
PKMN_OFFSET_ASSERT(CRenderTexture, field_68, 0x68);
PKMN_OFFSET_ASSERT(CRenderTexture, field_98, 0x98);
PKMN_OFFSET_ASSERT(CRenderTexture, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(CRenderTexture, field_108, 0x108);
PKMN_SIZE_ASSERT(CRenderTexture, 0x128);

// 0x710049df00, 0x710049e290: what the tiles of a target do (nothing on NX
// but ask the context for an object and release it)
s32 Unk_49df00(CRenderTexture* target, u32 flags, s32 arg2, s32 arg3, s32 arg4, bool* done, f32 arg6, f32 arg7);
s32 Unk_49e290(u32 flags, CRenderTexture* target, s32 arg2, bool* done, f32 arg4);
// 0x710049da70: makes up to `count` targets and a depth target the device's,
// and clears them or begins their tiling (arg9: its callers pass 1.0f)
s32 Unk_49da70(s32 count, CRenderTexture** targets, Unk_49b230_Object* depth, Unk_49b230_Object* arg3, s32 arg4,
               void* arg5, s32 arg6, s32 arg7, s32 arg8, f32 arg9);
// 0x710049c8e0: the tiles a target of that size is drawn in (none for one tile)
Unk_49a890* Unk_49c8e0(u32 width, u32 height, s32 format, s32 msaa, s32 tiled);
// 0x7100446e20 (Unk_447050.cpp): the size of a tile and how many there are
s32 Unk_446e20(u32* width, u32* height, u32 targetWidth, u32 targetHeight, s32 arg4, s32* format, s32 tiled,
               s32 msaa, s32 arg8);

}  // namespace PPFX
