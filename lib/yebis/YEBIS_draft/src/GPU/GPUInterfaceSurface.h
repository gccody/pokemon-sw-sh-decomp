// PPFX::IGPUSurface (RTTI names the class; members are placeholders, virtual
// functions are vf<slot>), as far as the functions written so far read it.
#pragma once

#include <list>

#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceResource.h>

namespace PPFX {

class IGPUSurface;
class IGPUBaseTexture;

// what a kind 2 attachment's slot 17 describes (placeholder): its formats
// (as Unk_SiGfxTextureDesc has them), its size, its multisampling
struct Unk_SiGfxSurfaceDesc {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;  // (a level's) how many bytes a pixel is
};

// a kind 2 attachment, and a texture's level (placeholder): slot 8 gives its
// format's flags
// What a SiGfx render target's attachments are, as a surface changes them
// (placeholders; SiSDK3's SiGfxNXRenderTarget is one): slot 2 adds a
// reference, slot 3 drops one.
struct Unk_SiGfxAttachment {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_SiGfxSurface : Unk_SiGfxAttachment {
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual const Unk_SiGfxFormatInfo* vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual const Unk_SiGfxSurfaceDesc* vf17();
};

// What a surface is handed to and kept by (slots 12 and 13): the slots the
// surface calls. Placeholder.
struct Unk_SurfaceUser {
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
    // 0x7100444bc0: makes the surface a level and layer of a SiGfx texture
    // (IGPUSurface::RegisterSiGfxTexture, its log lines say)
    virtual s32 RegisterSiGfxTexture(Unk_SiGfxTexture* texture, u32 level, u32 layer, u32 flags);
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual s32 vf15(IGPUSurface* surface, s32 index);
    virtual s32 vf16(IGPUSurface* surface, s32 index);
};

// what a surface keeps in field_90: a surface attached to it, and the index
// it is attached at (placeholder)
struct Unk_SurfaceAttachment {
    s32 field_0;
    IGPUSurface* field_8;
};

class IGPUSurface : public IGPUPixelContainer {
public:
    // (inline in the functions that make a surface)
    explicit IGPUSurface(IGPUDevice* pDevice)
        : IGPUPixelContainer(pDevice), field_70(nullptr), field_a8(field_38), field_b0(false), field_b8(nullptr),
          field_c0(false) {
        field_c = 6;
        field_80 = nullptr;
        field_88 = -1;
    }
    ~IGPUSurface() override;  // 0x71004437f0, 0x71004438f0
    s32 vf5(void* a1, bool a2) override { return IGPUPixelContainer::vf5(a1, a2); }  // 0x7100445b30
    s32 vf6() override { return IGPUPixelContainer::vf6(); }                        // 0x7100445b40
    // 0x7100445b00: the base's errors only
    s32 vf7(void* a1, u32 a2, u32 a3, bool a4) override {
        s32 result = IGPUPixelContainer::vf7(a1, a2, a3, a4);
        return result < 0 ? result : 0;
    }
    s32 vf9(void* a1, u32 a2, u32 a3, bool a4) override { return 0; }  // 0x7100445b20
    // 0x7100444bc0: makes the surface a level and layer of a SiGfx texture
    // (IGPUSurface::RegisterSiGfxTexture, its log lines say)
    virtual s32 RegisterSiGfxTexture(Unk_SiGfxTexture* texture, u32 level, u32 layer, u32 flags);
    // 0x7100444f80: makes the surface SiGfx's render target `target`
    virtual s32 vf11(Unk_SiGfxRenderTarget* target, u32 width, u32 height, s32 format, u32 msaa, u32 quality);
    virtual s32 vf12(s32 index, Unk_SurfaceUser* user);  // 0x7100443c70
    virtual s32 vf13(s32 index);                         // 0x7100443cd0
    virtual s32 vf14();                                  // 0x7100443d20: frees what SiGfx made for it
    // 0x7100444720: attaches the surface to `surface`'s framebuffer at `index`
    // (IGPUSurface::AttachToOtherSurfaceFramebuffer, its log lines say)
    virtual s32 vf15(IGPUSurface* surface, s32 index);
    // 0x71004449a0: detaches `surface` (all of them for null) at `index` (all
    // of them for -1)
    virtual s32 vf16(IGPUSurface* surface, s32 index);

    // 0x7100445030 (the device's log line names it): a surface for SiGfx's
    // render target, its first colour attachment (kind 2) or its depth one (3)
    static IGPUSurface* CreateSurface_SiGfxDefaultRenderTarget(IGPUDevice* pDevice, s32 kind,
                                                               Unk_SiGfxRenderTarget* target);
    // 0x7100445370 (its log line names it): a texture's surface for a level
    static IGPUSurface* CreateSurface_SIGFX_TEXTURE_ATTACHED_SURFACE(IGPUDevice* pDevice, IGPUBaseTexture* texture,
                                                                     u32 level, u32 layer, u32 usage);
    // 0x7100445740 (its log lines name it): a new surface of a SiGfx texture of
    // its own, of a usage (1 a render target, 2 a depth target, 4 one with
    // unordered access)
    static IGPUSurface* CreateSurface(IGPUDevice* pDevice, u32 width, u32 height, s32 format, s32 usage, s32 msaa,
                                      u32 quality, u32 flags, void* arg8, u32 arg9);
    // (inline in 0x7100445370; its log line names it)
    s32 CreateOwnSiGfxRenderTarget();

    // 0x7100443b80 (its log line names it)
    void SetSiGfxRenderTarget(Unk_SiGfxInterface* resource);
    s32 CreateSiGfxRenderTarget();  // 0x7100443920 (its log line names it)
    s32 Unk_443a60();               // 0x7100443a60: releases what CreateSiGfxRenderTarget made
    s32 DetachFromSiGfxRenderTarget(s32 index);  // 0x71004443b0 (its log line names it)
    // 0x7100443ea0 (its log line names it)
    s32 AttachSiGfxRenderTargetFromOtherSurface(s32 index, IGPUSurface* other);

    IGPUInterface* field_70;
    u32 field_78;  // the level it is of its texture (field_68)
    u32 field_7c;  // and the layer or the slice
    Unk_SurfaceUser** field_80;  // ten of them
    s32 field_88;
    std::list<Unk_SurfaceAttachment, Unk_StlAllocator<Unk_SurfaceAttachment>> field_90;
    Unk_SiGfxInterface* field_a8;      // SiGfx's resource, and whether it is the surface's own
    bool field_b0;
    Unk_SiGfxRenderTarget* field_b8;   // what SiGfx draws to, and whether it is the surface's own
    bool field_c0;
};
PKMN_SIZE_ASSERT(IGPUSurface, 0xc8);
PKMN_OFFSET_ASSERT(IGPUSurface, field_90, 0x90);
PKMN_OFFSET_ASSERT(IGPUSurface, field_a8, 0xa8);

}  // namespace PPFX
