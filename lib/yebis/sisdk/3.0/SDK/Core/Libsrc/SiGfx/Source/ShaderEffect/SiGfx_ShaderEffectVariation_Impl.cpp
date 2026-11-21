// Scope: common
// SiSDK3::SiGfxShaderEffectVariation: the destructors and what they call.
#define UNK_SIGFX_SHADEREFFECTVARIATION_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectVariation_Impl.h>

namespace SiSDK3 {

// 0x7100574710
SiGfxShaderEffectVariation::SiGfxShaderEffectVariation(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_48(pAllocator), field_98(pAllocator), field_c8(0),
      field_d0(pAllocator), field_120(pAllocator), field_150(0) {}

// 0x7100574850 (D2), 0x7100574c30 (D0)
SiGfxShaderEffectVariation::~SiGfxShaderEffectVariation() {
    Unk_574a20();
}

// 0x7100574a20
// NON_MATCHING: the same instructions, but the original stores the first string's zeroed capacity
// and flags after it has read the second array's flags, and this stores them before.
void SiGfxShaderEffectVariation::Unk_574a20() {
    field_48.Unk_4e3050();
    field_98.Unk_Clear();
    field_d0.Unk_4e3050();
    field_120.Unk_Clear();
}

}  // namespace SiSDK3
