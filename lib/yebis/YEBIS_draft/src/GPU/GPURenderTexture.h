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
}  // namespace PPFX

// 0x710049ad30: a render texture's viewport. It keeps the name its first
// caller (GPUPostEffect.h) gave it.
s32 Unk_49ad30(PPFX::Unk_RenderTexture* texture, s32 width, s32 height, s32 x, s32 y);

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

        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
        u32 field_18;
        u32 field_1c;
    };

    Unk_49a890() : field_0(0), field_8(nullptr) {}
    ~Unk_49a890() { UNK_DELETE_ARRAY(field_8); }
    Unk_49a890& operator=(const Unk_49a890& other);  // 0x710049a890

    u32 field_0;  // the number of rectangles
    Unk_Rect* field_8;
    u32 field_10;  // the widest and the tallest
    u32 field_14;
};
PKMN_SIZE_ASSERT(Unk_49a890, 0x18);

// The interfaces the texture's device hands out (PPFX::IGPUSurface,
// IGPUTexture: their classes are before this TU), as far as CRenderTexture
// calls them.
struct Unk_49b230_Object {
    virtual void vf0();  // one reference more
    virtual void vf1();  // one less
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
    // 0x710049cf50
    static s32 Unk_49cf50(Unk_49b230_Object* depth, void* owner);

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
        field_f0 = nullptr;
        field_f8 = nullptr;
        field_e0 = nullptr;
        field_e8 = nullptr;
        field_d0 = nullptr;
        field_d8 = nullptr;
        field_c0 = nullptr;
        field_c8 = nullptr;
        field_b0 = nullptr;
        field_b8 = nullptr;
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
    Unk_49b230_Object* field_b8;
    Unk_49b230_Object* field_c0;
    Unk_49b230_Object** field_c8;
    Unk_49b230_Object** field_d0;
    Unk_49b230_Object** field_d8;
    Unk_49a890** field_e0;
    Unk_49a890** field_e8;
    Unk_49a890* field_f0;
    Unk_49a890* field_f8;
    u64 field_100;
    std::vector<CRenderTexture*, Unk_StlAllocator<CRenderTexture*>> field_108;
    CRenderTexture* field_120;
};
PKMN_OFFSET_ASSERT(CRenderTexture, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(CRenderTexture, field_54, 0x54);
PKMN_OFFSET_ASSERT(CRenderTexture, field_68, 0x68);
PKMN_OFFSET_ASSERT(CRenderTexture, field_98, 0x98);
PKMN_OFFSET_ASSERT(CRenderTexture, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(CRenderTexture, field_108, 0x108);
PKMN_SIZE_ASSERT(CRenderTexture, 0x128);

}  // namespace PPFX
