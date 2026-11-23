// PPFX::IGPUBaseTexture, PPFX::IGPUTexture and PPFX::IGPUVolumeTexture (RTTI
// names the classes and their order: IGPUTexture and IGPUVolumeTexture derive
// from IGPUBaseTexture, which derives from IGPUPixelContainer). Members are
// placeholders, virtual functions are vf<slot>; those declared and not
// defined in GPUInterfaceTexture.cpp aren't decompiled yet.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceSurface.h>

namespace PPFX {

class IGPUBaseTexture : public IGPUPixelContainer {
public:
    // (inline in the functions that make a texture)
    explicit IGPUBaseTexture(IGPUDevice* pDevice)
        : IGPUPixelContainer(pDevice), field_70(&field_38), field_78(-1), field_7c(-1), field_80(0) {}

    s32 vf1() override;                                   // 0x71004472c0
    s32 vf5(void* a1, bool a2) override;                  // 0x7100447640
    s32 vf9(void* a1, u32 a2, u32 a3, bool a4) override;  // 0x7100447320
    virtual s32 vf10() = 0;                               // makes what the texture is of
    virtual s32 vf11() = 0;                               // and frees it, before the last reference goes
    virtual u32 vf12();                                   // 0x7100447300: how many levels
    virtual void vf13();                                  // 0x7100447310
    virtual s32 vf14();                                   // 0x7100447650
    virtual s32 vf15(u32 state);                          // 0x7100447660: sets the sampler state's bits
    virtual u32 vf16();                                   // 0x7100447680
    virtual s32 vf17(u32 value);                          // 0x7100447690: its bits 0 and 1
    virtual s32 vf18(u32 value);                          // 0x71004476d0: its bits 2 and 3
    virtual u32 vf19();                                   // 0x71004476c0
    virtual u32 vf20();                                   // 0x7100447700
    virtual s32 vf21(s32 state, bool check);              // 0x7100447710
    // 0x7100447790: the device's sampler for its sampler state
    Unk_SiGfxInterface* Unk_447790() const;

    Unk_SiGfxInterface** field_70;
    u32 field_78;  // the sampler state
    s32 field_7c;  // the one that was applied
    u32 field_80;  // how many levels
};
PKMN_OFFSET_ASSERT(IGPUBaseTexture, field_78, 0x78);

class IGPUTexture : public IGPUBaseTexture {
public:
    // (inline in the functions that make one)
    explicit IGPUTexture(IGPUDevice* pDevice)
        : IGPUBaseTexture(pDevice), field_88(nullptr), field_90(reinterpret_cast<Unk_SiGfxTexture**>(&field_38)) {
        field_c = 3;
    }
    ~IGPUTexture() override;                                // 0x7100447970, 0x7100447a10
    // 0x7100447da0 (its log lines name it): a new texture of a SiGfx texture
    // of its own
    static IGPUTexture* CreateTexture(IGPUDevice* pDevice, u32 width, u32 height, u32 levels, s32 format, s32 msaa,
                                      u32 quality, u32 usage, u32 flags);
    s32 vf5(void* a1, bool a2) override { return IGPUBaseTexture::vf5(a1, a2); }  // 0x7100447d80
    s32 vf6() override { return IGPUPixelContainer::vf6(); }                      // 0x7100447d90
    // 0x7100447d70
    s32 vf9(void* a1, u32 a2, u32 a3, bool a4) override { return IGPUBaseTexture::vf9(a1, a2, a3, a4); }
    s32 vf10() override;                                    // 0x7100447ac0
    s32 vf11() override;                                    // 0x7100447b80
    // 0x71004477a0: makes the texture SiGfx's `texture` (the first slot of
    // its own; IGPUVolumeTexture's is another function)
    virtual s32 vf22(Unk_SiGfxTexture* texture, u32 usage);
    virtual s32 vf23(u32 level, IGPUSurface** ppSurface);   // 0x7100447d30
    virtual s32 vf24(u32 level, IGPUPixelContainer::Unk_Desc* pDesc);  // 0x7100447cf0

    IGPUSurface** field_88;  // a surface for each level
    Unk_SiGfxTexture** field_90;
};
PKMN_SIZE_ASSERT(IGPUTexture, 0x98);
PKMN_OFFSET_ASSERT(IGPUTexture, field_88, 0x88);

class IGPUVolumeTexture : public IGPUBaseTexture {
public:
    // (inline in the functions that make one)
    explicit IGPUVolumeTexture(IGPUDevice* pDevice)
        : IGPUBaseTexture(pDevice), field_84(0), field_88(reinterpret_cast<Unk_SiGfxTexture**>(&field_38)) {
        field_c = 5;
    }
    ~IGPUVolumeTexture() override;  // 0x7100448530, 0x71004485d0
    s32 vf10() override;            // 0x7100448680
    s32 vf11() override;            // 0x7100448690
    // 0x71004483b0: makes the texture SiGfx's `texture`
    virtual s32 vf22(Unk_SiGfxTexture* texture, u32 arg2, u32 usage);

    u32 field_84;  // the depth
    Unk_SiGfxTexture** field_88;
};
PKMN_SIZE_ASSERT(IGPUVolumeTexture, 0x90);

}  // namespace PPFX
