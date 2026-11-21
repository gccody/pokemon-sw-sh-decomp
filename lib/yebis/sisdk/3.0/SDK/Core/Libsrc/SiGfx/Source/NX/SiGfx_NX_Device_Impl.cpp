// Scope: common
// SiSDK3::SiGfxNXDevice: the creation of its resource pools and the reference
// counts its header defines.
#define UNK_SIGFX_NX_DEVICE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

namespace SiSDK3 {

// 0x71004f82a0
bool SiGfxNXDevice::Unk_4f82a0() {
#line 1375
    field_338 = UNK_SI_NEW(field_8, 0x10) SiGfxNXSurfacePool(this);
    field_338->vf5(field_b0);
    field_2e8 = field_338;
#line 1379
    field_340 = UNK_SI_NEW(field_8, 0x10) SiGfxNXTexturePool(this);
    field_340->vf5(field_a8);
    field_2d8 = field_340;
#line 1383
    field_348 = UNK_SI_NEW(field_8, 0x10) SiGfxNXCanvasPool(this);
    field_348->vf5(field_b8);
    field_2f8 = field_348;
#line 1387
    field_350 = UNK_SI_NEW(field_8, 0x10) SiGfxNXRenderTargetPool(this);
    field_350->vf5(field_d0);
    field_328 = field_350;
#line 1391
    field_360 = UNK_SI_NEW(field_8, 0x10) SiGfxNXVolumePool(this);
    field_360->vf5(field_b4);
    field_2f0 = field_360;
#line 1395
    field_368 = UNK_SI_NEW(field_8, 0x10) SiGfxNXVertexFormatPool(this);
    field_368->vf5(field_bc);
    field_300 = field_368;
#line 1399
    field_370 = UNK_SI_NEW(field_8, 0x10) SiGfxNXShaderPool(this);
    field_370->vf5(field_c4);
    field_308 = field_370;
#line 1403
    field_378 = UNK_SI_NEW(field_8, 0x10) SiGfxNXShaderProgramPool(this);
    field_378->vf5(field_c8);
    field_310 = field_378;
#line 1407
    field_380 = UNK_SI_NEW(field_8, 0x10) SiGfxNXFontPool(this);
    field_380->vf5(field_ac);
    field_2e0 = field_380;
#line 1411
    field_358 = UNK_SI_NEW(field_8, 0x10) SiGfxNXBufferPool(this);
    field_358->vf5(field_c0);
    field_320 = field_358;
#line 1415
    field_388 = UNK_SI_NEW(field_8, 0x10) SiGfxNXQueryPool(this);
    field_388->vf5(field_cc);
    field_318 = field_388;
#line 1419
    field_390 = UNK_SI_NEW(field_8, 0x10) SiGfxNXSamplerPool(this);
    field_390->vf5(0x1000);
    field_330 = field_390;
    return true;
}

}  // namespace SiSDK3
