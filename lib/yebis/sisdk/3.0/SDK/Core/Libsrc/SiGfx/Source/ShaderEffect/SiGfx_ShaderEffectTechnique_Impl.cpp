// Scope: common
// SiSDK3::SiGfxShaderEffectTechnique.
#define UNK_SIGFX_SHADEREFFECTTECHNIQUE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectTechnique_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>

// 0x7100582f10, 0x7100582f70: skip to, and fill up to, a multiple of alignment
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment);
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);

namespace SiSDK3 {

// 0x7100570820
SiGfxShaderEffectTechnique::SiGfxShaderEffectTechnique(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_48(0), field_4c(0), field_50(0), field_58(nullptr) {}

// 0x7100570890 (D2), 0x7100570920 (D0)
SiGfxShaderEffectTechnique::~SiGfxShaderEffectTechnique() {
#line 78
    SI_FREE(Unk_Allocator(), field_58);
    field_50 = 0;
}

// 0x71005709e0
bool SiGfxShaderEffectTechnique::Unk_5709e0(ISiIOStream* stream) {
    Unk_582f70(stream, 0x10, 0);
    stream->vf58(Unk_StringCStr(&field_18), true);
    Unk_582f70(stream, 0x10, 0);
    stream->vf54(field_48, true);
    stream->vf50(field_50, true);
    if (field_50 >= 1) {
        stream->vf44(field_58, field_50, true);
    }
    return true;
}

// 0x7100570aa0
bool SiGfxShaderEffectTechnique::Unk_570aa0(ISiIOStream* stream) {
    Unk_582f10(stream, 0x10);
    stream->vf35(&field_18, true);
    Unk_582f10(stream, 0x10);
    field_48 = stream->vf31(true);
    field_50 = stream->vf27(true);
    if (field_50 >= 1) {
#line 161
        field_58 = field_8.m_pAllocator->vf7(field_50, 0, __FILE__, __LINE__);
        stream->vf21(field_58, field_50, true);
    }
    return true;
}

}  // namespace SiSDK3
