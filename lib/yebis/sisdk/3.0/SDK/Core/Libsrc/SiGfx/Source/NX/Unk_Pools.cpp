// Scope: common
// SiGfx's NX resource pools' constructors (placeholder file: each is in its
// pool's own translation unit).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>

namespace SiSDK3 {

// 0x71004fe610
SiGfxNXFontPool::SiGfxNXFontPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100536cb0
SiGfxNXBufferPool::SiGfxNXBufferPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100538e50
SiGfxNXCanvasPool::SiGfxNXCanvasPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x71005544e0
SiGfxNXQueryPool::SiGfxNXQueryPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100555340
SiGfxNXRenderTargetPool::SiGfxNXRenderTargetPool(SiGfxNXDevice* pDevice)
    : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x71005588d0
SiGfxNXSamplerPool::SiGfxNXSamplerPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x71005593f0
SiGfxNXShaderPool::SiGfxNXShaderPool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100559780
SiGfxNXShaderProgramPool::SiGfxNXShaderProgramPool(SiGfxNXDevice* pDevice)
    : SiGfxShaderProgramPoolBase(pDevice), field_248(nullptr) {
    Unk_StringAssign(&field_188, "SiGfx_NX_Common");
    Unk_StringAssign(&field_1b8, "SiGfx_NX_Common");
}

// 0x710055c220
SiGfxNXSurfacePool::SiGfxNXSurfacePool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x710055d5b0
SiGfxNXTexturePool::SiGfxNXTexturePool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100563700
SiGfxNXVertexFormatPool::SiGfxNXVertexFormatPool(SiGfxNXDevice* pDevice)
    : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

// 0x7100565560
SiGfxNXVolumePool::SiGfxNXVolumePool(SiGfxNXDevice* pDevice) : SiGfxResourcePool(pDevice->field_8), field_178(pDevice) {}

}  // namespace SiSDK3
