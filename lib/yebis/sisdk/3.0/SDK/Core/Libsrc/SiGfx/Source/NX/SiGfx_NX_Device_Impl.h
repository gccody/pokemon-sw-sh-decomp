// SiSDK3::SiGfxNXDevice: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines,
// for the class's own translation unit (UNK_SIGFX_NX_DEVICE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxNXBufferPool;
class SiGfxNXCanvasPool;
class SiGfxNXFontPool;
class SiGfxNXQueryPool;
class SiGfxNXRenderTargetPool;
class SiGfxNXSamplerPool;
class SiGfxNXShaderPool;
class SiGfxNXShaderProgramPool;
class SiGfxNXSurfacePool;
class SiGfxNXTexturePool;
class SiGfxNXVertexFormatPool;
class SiGfxNXVolumePool;

class SiGfxNXDevice {
public:
    virtual ~SiGfxNXDevice();
    UNK_REFCOUNT_DECLARE;

    // 0x71004f82a0: makes its resource pools
    bool Unk_4f82a0();

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
    u8 field_14[0x94];
    // how many of each resource its pools are made for
    u32 field_a8;
    u32 field_ac;
    u32 field_b0;
    u32 field_b4;
    u32 field_b8;
    u32 field_bc;
    u32 field_c0;
    u32 field_c4;
    u32 field_c8;
    u32 field_cc;
    u32 field_d0;
    u8 field_d4[0x204];
    // the pools again, as what gives out each resource
    SiGfxNXTexturePool* field_2d8;
    SiGfxNXFontPool* field_2e0;
    SiGfxNXSurfacePool* field_2e8;
    SiGfxNXVolumePool* field_2f0;
    SiGfxNXCanvasPool* field_2f8;
    SiGfxNXVertexFormatPool* field_300;
    SiGfxNXShaderPool* field_308;
    SiGfxNXShaderProgramPool* field_310;
    SiGfxNXQueryPool* field_318;
    SiGfxNXBufferPool* field_320;
    SiGfxNXRenderTargetPool* field_328;
    SiGfxNXSamplerPool* field_330;
    // the pools
    SiGfxNXSurfacePool* field_338;
    SiGfxNXTexturePool* field_340;
    SiGfxNXCanvasPool* field_348;
    SiGfxNXRenderTargetPool* field_350;
    SiGfxNXBufferPool* field_358;
    SiGfxNXVolumePool* field_360;
    SiGfxNXVertexFormatPool* field_368;
    SiGfxNXShaderPool* field_370;
    SiGfxNXShaderProgramPool* field_378;
    SiGfxNXFontPool* field_380;
    SiGfxNXQueryPool* field_388;
    SiGfxNXSamplerPool* field_390;
};
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_2d8, 0x2d8);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_338, 0x338);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_DEVICE_IMPL
// 0x71004fb3a0 (vf2), 0x71004fb3c0 (vf3)
#line 69
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXDevice, field_8, field_10)
#endif
