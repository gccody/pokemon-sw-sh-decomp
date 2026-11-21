// Scope: common
// SiSDK3::SiGfxShaderEffectVariation: the destructors and what they call.
#define UNK_SIGFX_SHADEREFFECTVARIATION_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectVariation_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>

// 0x7100582f10, 0x7100582f70: skip to, and fill up to, a multiple of alignment
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment);
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);

namespace SiSDK3 {

// 0x7100574710
SiGfxShaderEffectVariation::SiGfxShaderEffectVariation(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_48(pAllocator), field_98(pAllocator), field_c8(0),
      field_cc(0), field_d0(pAllocator), field_120(pAllocator), field_150(0), field_154(0) {}

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

// 0x7100575510
bool SiGfxShaderEffectVariation::vf14(ISiIOStream* stream) {
    Unk_582f70(stream, 0x10, 0);
    stream->vf58(Unk_StringCStr(&field_18), true);
    Unk_582f70(stream, 0x10, 0);
    stream->vf50(field_48.m_itemCount, true);
    stream->vf50(field_c8, true);
    stream->vf50(field_cc, true);
    stream->vf50(field_d0.m_itemCount, true);
    stream->vf50(field_150, true);
    stream->vf50(field_154, true);
    if (field_48.m_itemCount != 0) {
        for (s64 i = 0; i < static_cast<s32>(field_48.m_itemCount); i++) {
            VariationItem* item = &field_48.m_pData[i];
            stream->vf50(item->field_0, true);
            stream->vf50(item->field_4, true);
            stream->vf50(item->field_8, true);
            stream->vf50(item->field_c, true);
            stream->vf50(item->field_10, true);
            stream->vf50(item->field_14, true);
            stream->vf50(item->field_18, true);
            stream->vf50(item->field_1c, true);
            stream->vf50(item->field_20, true);
        }
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&field_98), true);
    }
    if (field_d0.m_itemCount != 0) {
        for (s64 i = 0; i < static_cast<s32>(field_d0.m_itemCount); i++) {
            VariationItem* item = &field_d0.m_pData[i];
            stream->vf50(item->field_0, true);
            stream->vf50(item->field_4, true);
            stream->vf50(item->field_8, true);
            stream->vf50(item->field_c, true);
            stream->vf50(item->field_10, true);
            stream->vf50(item->field_14, true);
            stream->vf50(item->field_18, true);
            stream->vf50(item->field_1c, true);
            stream->vf50(1, true);
        }
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&field_120), true);
    }
    return true;
}

// 0x71005758a0
bool SiGfxShaderEffectVariation::vf15(ISiIOStream* stream) {
    Unk_582f10(stream, 0x10);
    stream->vf35(&field_18, true);
    Unk_582f10(stream, 0x10);
    s32 count48 = stream->vf27(true);
    field_c8 = stream->vf27(true);
    field_cc = stream->vf27(true);
    s32 countD0 = stream->vf27(true);
    field_150 = stream->vf27(true);
    field_154 = stream->vf27(true);
    if (count48 <= 0 && countD0 < 1) {
        return false;
    }
    if (count48 >= 1) {
        field_48.Unk_SetCount(count48);
        for (s64 i = 0; i < static_cast<s32>(field_48.m_itemCount); i++) {
            VariationItem* item = &field_48.m_pData[i];
            item->field_0 = stream->vf27(true);
            item->field_4 = stream->vf27(true);
            item->field_8 = stream->vf27(true);
            item->field_c = stream->vf27(true);
            item->field_10 = stream->vf27(true);
            item->field_14 = stream->vf27(true);
            item->field_18 = stream->vf27(true);
            item->field_1c = stream->vf27(true);
            item->field_20 = stream->vf27(true);
        }
        Unk_582f10(stream, 0x10);
        stream->vf35(&field_98, true);
    }
    if (countD0 >= 1) {
        field_d0.Unk_SetCount(countD0);
        for (s64 i = 0; i < static_cast<s32>(field_d0.m_itemCount); i++) {
            VariationItem* item = &field_d0.m_pData[i];
            item->field_0 = stream->vf27(true);
            item->field_4 = stream->vf27(true);
            item->field_8 = stream->vf27(true);
            item->field_c = stream->vf27(true);
            item->field_10 = stream->vf27(true);
            item->field_14 = stream->vf27(true);
            item->field_18 = stream->vf27(true);
            item->field_1c = stream->vf27(true);
            item->field_20 = stream->vf27(true);
        }
        Unk_582f10(stream, 0x10);
        stream->vf35(&field_120, true);
    }
    return true;
}

}  // namespace SiSDK3

// The items' array's reserve, which this translation unit instantiates.
// 0x7100575df0 = _ZN6SiSDK37SiArrayINS_26SiGfxShaderEffectVariation13VariationItemELi16EE10Unk_4bf190Emb
