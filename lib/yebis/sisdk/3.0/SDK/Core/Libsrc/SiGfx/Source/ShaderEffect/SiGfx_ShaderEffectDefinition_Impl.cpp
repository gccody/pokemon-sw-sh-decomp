// Scope: common
// SiSDK3::SiGfxShaderEffectDefinition.
#define UNK_SIGFX_SHADEREFFECTDEFINITION_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectDefinition_Impl.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>

// 0x7100582f10, 0x7100582f70: skip to, and fill up to, a multiple of alignment
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment);
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);
// 0x71004c34a0: a name's hash
u32 Unk_4c34a0(const char* name);

namespace SiSDK3 {

inline void SiGfxShaderEffectDefinition::Unk_Release() {
    if (field_c0 != nullptr) {
        field_c0->vf3();
        field_c0 = nullptr;
    }
    if (field_ac >= 1) {
        for (s64 i = 0; i < field_ac; i++) {
            field_b0[i].~SiGfxShaderEffectTechnique();
        }
#line 145
        SI_FREE(Unk_Allocator(), field_b0);
#line 146
        SI_FREE(Unk_Allocator(), field_b8);
        field_ac = 0;
    }
}

// 0x710056fd60
SiGfxShaderEffectDefinition::SiGfxShaderEffectDefinition(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_48(pAllocator), field_78(pAllocator), field_a8(-1), field_ac(0),
      field_b0(nullptr), field_b8(nullptr), field_c0(nullptr) {}

// 0x710056fe50 (D2), 0x710056ffe0 (D0)
SiGfxShaderEffectDefinition::~SiGfxShaderEffectDefinition() {
    Unk_Release();
}

// 0x7100570060
SiGfxShaderEffectTechnique* SiGfxShaderEffectDefinition::vf10(s32 index) {
    return &field_b0[index];
}

// 0x7100570070
// NON_MATCHING: the same instructions up to the last two returns, which the original has as
// their own copies (`mov x0, x8; ret` after the test of the low technique, `csel x0, ...; ret`
// for the high one) and this shares with the first return's.
// (The loop's two `continue`s are two back edges, which become the nested loops the original
// has; low is declared before high for the inner one to be the one that moves high.)
SiGfxShaderEffectTechnique* SiGfxShaderEffectDefinition::vf11(const char* name) {
    if (field_b8 == nullptr) {
        return nullptr;
    }
    u32 count = field_ac;
    u32 hash = Unk_4c34a0(name);
    SiGfxShaderEffectTechnique* technique = field_b8[0];
    if (count == 1) {
        return technique->field_48 == hash ? technique : nullptr;
    }
    if (hash < technique->field_48) {
        return nullptr;
    }
    s32 low = 0;
    s32 high = count - 1;
    if (hash > field_b8[high]->field_48) {
        return nullptr;
    }
    while (low < high - 1) {
        s32 middle = (high + low) >> 1;
        technique = field_b8[middle];
        if (hash < technique->field_48) {
            high = middle;
            continue;
        }
        low = middle;
        if (hash > technique->field_48) {
            continue;
        }
        return technique;
    }
    technique = field_b8[low];
    if (hash == technique->field_48) {
        return technique;
    }
    technique = field_b8[high];
    if (hash == technique->field_48) {
        return technique;
    }
    return nullptr;
}

// 0x7100570150
bool SiGfxShaderEffectDefinition::vf12(Unk_570150* out, const char* name) {
    if (out->field_c >= 1 && out->field_10 != nullptr) {
        memset(out->field_10, 0, out->field_c);
        out->field_8 = 0;
    }
    SiGfxShaderEffectTechnique* technique = vf11(name);
    if (technique == nullptr) {
        return false;
    }
    out->field_8 = technique->vf6();
    return true;
}

// 0x71005701d0
bool SiGfxShaderEffectDefinition::vf13(Unk_570150* out, u32 value) {
    if (out->field_c >= 1 && out->field_10 != nullptr) {
        memset(out->field_10, 0, out->field_c);
        out->field_8 = 0;
    }
    out->field_8 = value;
    return true;
}

// 0x7100570220
bool SiGfxShaderEffectDefinition::vf14(ISiIOStream* stream) {
    Unk_582f70(stream, 0x10, 0);
    stream->vf58(Unk_StringCStr(&field_18), true);
    Unk_582f70(stream, 0x10, 0);
    stream->vf58(Unk_StringCStr(&field_48), true);
    Unk_582f70(stream, 0x10, 0);
    stream->vf58(Unk_StringCStr(&field_78), true);
    Unk_582f70(stream, 0x10, 0);
    stream->vf50(field_a8, true);
    stream->vf50(field_ac, true);
    for (s64 i = 0; i < field_ac; i++) {
        field_b0[i].Unk_5709e0(stream);
    }
    for (s64 i = 0; i < field_ac; i++) {
        stream->vf50(field_b8[i]->vf6(), true);
    }
    return true;
}

// 0x71005703b0
bool SiGfxShaderEffectDefinition::vf15(ISiIOStream* stream) {
    Unk_Release();
    Unk_582f10(stream, 0x10);
    stream->vf35(&field_18, true);
    Unk_582f10(stream, 0x10);
    stream->vf35(&field_48, true);
    Unk_582f10(stream, 0x10);
    stream->vf35(&field_78, true);
    Unk_582f10(stream, 0x10);
    field_a8 = stream->vf27(true);
    Unk_570530(stream, stream->vf27(true));
    return true;
}

// 0x7100570530
bool SiGfxShaderEffectDefinition::Unk_570530(ISiIOStream* stream, s32 count) {
    if (count < 1) {
        return false;
    }
#line 459
    field_b0 = static_cast<SiGfxShaderEffectTechnique*>(
        field_8.m_pAllocator->vf7(static_cast<s64>(count) * sizeof(SiGfxShaderEffectTechnique), 0x10, __FILE__, 459));
    if (field_b0 == nullptr) {
        return false;
    }
#line 463
    field_b8 = static_cast<SiGfxShaderEffectTechnique**>(
        field_8.m_pAllocator->vf7(static_cast<s64>(count) * sizeof(SiGfxShaderEffectTechnique*), 0x10, __FILE__, 463));
    if (field_b8 == nullptr) {
        return false;
    }
    memset(field_b8, 0, static_cast<s64>(count) * sizeof(SiGfxShaderEffectTechnique*));
    field_ac = count;
    for (s32 i = 0; i < count; i++) {
        new (Unk_Placement(), &field_b0[i]) SiGfxShaderEffectTechnique(field_8.m_pAllocator);
        field_b0[i].field_4c = i;
    }
    for (s32 i = 0; i < count; i++) {
        field_b0[i].Unk_570aa0(stream);
    }
    for (s32 i = 0; i < count; i++) {
        s32 index = stream->vf27(true);
        field_b8[i] = &field_b0[index];
    }
    return true;
}

// 0x7100570680
void SiGfxShaderEffectDefinition::vf16(Unk_570680* object) {
    if (object != nullptr) {
        object->vf2();
    }
    if (field_c0 != nullptr) {
        field_c0->vf3();
    }
    field_c0 = object;
}

}  // namespace SiSDK3
