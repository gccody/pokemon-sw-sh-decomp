// Scope: common
// SiGfx's NX resource pools' small functions (placeholder file: each pool's
// are in its own translation unit): a pool's constructor keeps the device,
// its destructor and its slot 6 release the resources through the base, its
// slot 5 makes room for the items.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>

namespace SiSDK3 {

// 0x71004fe610
SiGfxNXFontPool::SiGfxNXFontPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x71004fe650 (D2), 0x71004fe690 (D0)
SiGfxNXFontPool::~SiGfxNXFontPool() {
    SiGfxResourcePool::vf6();
}

// 0x71004fe6d0
bool SiGfxNXFontPool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x71004fe940
void SiGfxNXFontPool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x7100536cb0
SiGfxNXBufferPool::SiGfxNXBufferPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100536cf0 (D2), 0x7100536d30 (D0)
SiGfxNXBufferPool::~SiGfxNXBufferPool() {
    SiGfxResourcePool::vf6();
}

// 0x7100536d70
bool SiGfxNXBufferPool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x7100536db0
void SiGfxNXBufferPool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x7100538e50
SiGfxNXCanvasPool::SiGfxNXCanvasPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100538e90 (D2), 0x7100538ed0 (D0)
SiGfxNXCanvasPool::~SiGfxNXCanvasPool() {
    SiGfxResourcePool::vf6();
}

// 0x7100538f10
bool SiGfxNXCanvasPool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x7100538f50
void SiGfxNXCanvasPool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x71005544e0
SiGfxNXQueryPool::SiGfxNXQueryPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100554520 (D2), 0x7100554560 (D0)
SiGfxNXQueryPool::~SiGfxNXQueryPool() {
    SiGfxResourcePool::vf6();
}

// 0x71005545a0
bool SiGfxNXQueryPool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x71005545e0
void SiGfxNXQueryPool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x7100555340
SiGfxNXRenderTargetPool::SiGfxNXRenderTargetPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100555380 (D2), 0x71005553c0 (D0)
SiGfxNXRenderTargetPool::~SiGfxNXRenderTargetPool() {
    SiGfxResourcePool::vf6();
}

// 0x7100555400
bool SiGfxNXRenderTargetPool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x7100555440
void SiGfxNXRenderTargetPool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x71005588d0
SiGfxNXSamplerPool::SiGfxNXSamplerPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100558910 (D2), 0x7100558950 (D0)
SiGfxNXSamplerPool::~SiGfxNXSamplerPool() {
    SiGfxResourcePool::vf6();
}

// 0x7100558990
bool SiGfxNXSamplerPool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x71005589d0
void SiGfxNXSamplerPool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x71005593f0
SiGfxNXShaderPool::SiGfxNXShaderPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100559430 (D2), 0x7100559470 (D0)
SiGfxNXShaderPool::~SiGfxNXShaderPool() {
    SiGfxResourcePool::vf6();
}

// 0x71005594b0
bool SiGfxNXShaderPool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x71005594f0
void SiGfxNXShaderPool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x710055c220
SiGfxNXSurfacePool::SiGfxNXSurfacePool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x710055c260 (D2), 0x710055c2a0 (D0)
SiGfxNXSurfacePool::~SiGfxNXSurfacePool() {
    SiGfxResourcePool::vf6();
}

// 0x710055c2e0
bool SiGfxNXSurfacePool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x710055c320
void SiGfxNXSurfacePool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x710055d5b0
SiGfxNXTexturePool::SiGfxNXTexturePool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x710055d5f0 (D2), 0x710055d630 (D0)
SiGfxNXTexturePool::~SiGfxNXTexturePool() {
    SiGfxResourcePool::vf6();
}

// 0x710055d670
bool SiGfxNXTexturePool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x710055d6b0
void SiGfxNXTexturePool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x7100563700
SiGfxNXVertexFormatPool::SiGfxNXVertexFormatPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100563740 (D2), 0x7100563780 (D0)
SiGfxNXVertexFormatPool::~SiGfxNXVertexFormatPool() {
    SiGfxResourcePool::vf6();
}

// 0x71005637c0
bool SiGfxNXVertexFormatPool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x7100563800
void SiGfxNXVertexFormatPool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x7100565560
SiGfxNXVolumePool::SiGfxNXVolumePool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x71005655a0 (D2), 0x71005655e0 (D0)
SiGfxNXVolumePool::~SiGfxNXVolumePool() {
    SiGfxResourcePool::vf6();
}

// 0x7100565620
bool SiGfxNXVolumePool::vf5(s32 count) {
    SiGfxResourcePool::vf5();
    field_48.vf2(count);
    return true;
}

// 0x7100565660
void SiGfxNXVolumePool::vf6() {
    SiGfxResourcePool::vf6();
}

// 0x7100559780
SiGfxNXShaderProgramPool::SiGfxNXShaderProgramPool(SiGfxNXDevice* pDevice)
    : SiGfxShaderProgramPoolBase(pDevice), field_248(nullptr) {
    Unk_StringAssign(&field_188, "SiGfx_NX_Common");
    Unk_StringAssign(&field_1b8, "SiGfx_NX_Common");
}

}  // namespace SiSDK3
