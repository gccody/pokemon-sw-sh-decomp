// Scope: common
// SiSDK3::SiGfxShaderEffectPackage: its construction and destruction, its
// file's header and the small functions (the rest isn't written yet).
#define UNK_SIGFX_SHADEREFFECTPACKAGE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectPackage_Impl.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffect_Impl.h>

// 0x7100582f10, 0x7100582f70: skip to, and fill up to, a multiple of alignment
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment);
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);
// 0x71004c5520: copies a string into a buffer, 0x71004c5630: compares
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);
s64 Unk_4c5630(const char* a, const char* b, bool);
// 0x71004cbc40: compares two versions
s32 Unk_4cbc40(s32, s32, s32, s32, s32, s32, s32, s32);
// 0x7100570d00 (leafgen's name and type): the variation list's initialisation
u64 Unk_570d00_get(u64 list);
// 0x710056ca20 (leafgen's name): whether an effect may be added
bool Unk_56ca20(void* package, void* effect);

// 0x7100567750
SiSDK3::SiGfxShaderEffectPackage* Unk_567750(SiSDK3::ISiAllocator* pAllocator) {
#line 267
    SiSDK3::SiGfxShaderEffectPackage* package = UNK_SI_NEW(pAllocator, 0x10) SiSDK3::SiGfxShaderEffectPackage(pAllocator);
    if (package != nullptr) {
        Unk_570d00_get(reinterpret_cast<u64>(&package->field_e38));
        package->field_e38.field_48 = package;
        package->field_e38.field_50 = *package->vf6();
    }
    return package;
}

namespace SiSDK3 {

// 0x71005677d0
SiGfxShaderEffectPackage::SiGfxShaderEffectPackage(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_48(pAllocator), field_138(0), field_13c(false), field_13d(true),
      field_140(pAllocator), field_190(pAllocator), field_1e0(pAllocator), field_230(pAllocator), field_280(pAllocator),
      field_2d0(pAllocator), field_be8(nullptr), field_bf0(false), field_bf8(), field_c28(0),
      field_c58{SiArray<ISiGfxShader*>(pAllocator), SiArray<ISiGfxShader*>(pAllocator), SiArray<ISiGfxShader*>(pAllocator),
                SiArray<ISiGfxShader*>(pAllocator), SiArray<ISiGfxShader*>(pAllocator), SiArray<ISiGfxShader*>(pAllocator)},
      field_e38(pAllocator) {
    memset(&field_a0, 0, sizeof(field_a0));
    field_13e = false;
    field_13f = false;
    field_78.field_0.field_0 = 0;
    field_78.field_0.field_4 = 0;
    field_78.field_0.field_8.field_0 = 0;
    field_78.field_0.field_8.field_4 = 0;
    field_78.field_10.field_0 = 0;
    field_78.field_10.field_4 = 0;
    field_78.field_10.field_8.field_0 = 0;
    field_78.field_10.field_8.field_4 = 0;
}

// 0x7100567b80
Unk_567b80::Unk_567b80(ISiAllocator* pAllocator)
    : field_0(pAllocator), field_8(pAllocator), field_58(pAllocator), field_a8(0), field_b0(0), field_b8(field_0),
      field_e8(3), field_ec(4), field_f0(0xa0), field_f4(false), field_f5(false), field_fc(0), field_900(0),
      field_914(-1) {
    memset(field_100, 0, sizeof(field_100));
    field_904 = 0;
    field_908 = 0;
    field_90c = 0;
    field_910 = 0;
}

// 0x7100567cb0 (D2), 0x71005684e0 (D0)
SiGfxShaderEffectPackage::~SiGfxShaderEffectPackage() {
    SiGfxShaderEffectPackage::vf9();
}

// 0x7100568510
void SiGfxShaderEffectPackage::vf5(const char* name) {
    Unk_StringAssign(&field_18, name);
    field_e38.field_50 = *vf6();
}

// 0x7100568e10
bool SiGfxShaderEffectPackage::vf12(const Unk_567750_Desc* desc) {
    if (field_138++ == 0) {
        field_78 = *desc;
        field_140.field_40 = 0x10;
        if (field_140.m_itemCount != 0) {
            field_140.m_itemCount = 0;
            field_140.field_30 = nullptr;
            field_140.field_38 = nullptr;
        }
    }
    return true;
}

// 0x71005693e0
bool SiGfxShaderEffectPackage::vf14(u64 value108, void* valueBe8, u32 value104, const SiArray<ISiGfxShader*>* shaders0,
                                    const SiArray<ISiGfxShader*>* shaders1, const SiArray<ISiGfxShader*>* shaders2,
                                    const SiArray<ISiGfxShader*>* shaders3, const SiArray<ISiGfxShader*>* shaders4,
                                    const SiArray<ISiGfxShader*>* shaders5) {
    field_be8 = valueBe8;
    field_a0.field_68 = value108;
    field_a0.field_64 = value104;
    field_a0.field_80 = shaders0->m_itemCount;
    field_a0.field_84 = shaders1->m_itemCount;
    field_a0.field_88 = shaders2->m_itemCount;
    field_a0.field_8c = shaders3->m_itemCount;
    field_a0.field_90 = shaders4->m_itemCount;
    field_a0.field_94 = shaders5->m_itemCount;
    field_bf8[0] = shaders0->m_pData;
    field_bf8[1] = shaders1->m_pData;
    field_bf8[2] = shaders2->m_pData;
    field_bf8[3] = shaders3->m_pData;
    field_bf8[4] = shaders4->m_pData;
    field_bf8[5] = shaders5->m_pData;
    return true;
}

// 0x7100569460
// NON_MATCHING: the original has one `mov w0, wzr` before the two tests and one return for them;
// this has a copy of the return for each test (28 bytes more).
bool SiGfxShaderEffectPackage::vf15(ISiGfxShaderEffectPackage::ShaderEffectData* data) {
    bool result = false;
    if (data != nullptr && field_138 >= 1) {
        field_140.Unk_Add(data);
        result = true;
    }
    return result;
}

// 0x7100569520
void SiGfxShaderEffectPackage::vf16(const Unk_567b80* options) {
    field_2d0 = *options;
}

// 0x71005697b0
bool SiGfxShaderEffectPackage::Unk_5697b0(ISiIOStream* stream, u32 byteOrder) {
    Unk_582f70(stream, 0x10, 0);
    Unk_4c5520(field_a0.field_0, sizeof(field_a0.field_0), "SiGfxShaderEffectPackage", -1);
    field_a0.field_20 = byteOrder;
    field_a0.field_30.field_0 = 3;
    field_a0.field_30.field_4 = 0;
    field_a0.field_30.field_8 = 0;
    field_a0.field_30.field_c = 5;
    field_a0.field_40 = field_78.field_0;
    field_a0.field_50 = field_78.field_10;
    field_a0.field_60 = field_78.field_20;
    field_a0.field_70 = field_230.m_itemCount;
    field_a0.field_78 = field_280.m_itemCount;
    field_a0.field_7c = field_140.m_itemCount;
    stream->vf13(byteOrder);
    stream->vf44(field_a0.field_0, sizeof(field_a0.field_0), true);
    stream->vf52(field_a0.field_20, true);
    for (s32 i = 0; i < 15; i++) {
        stream->vf52(0, true);
    }
    stream->vf50(field_a0.field_30.field_0, true);
    stream->vf50(field_a0.field_30.field_4, true);
    stream->vf50(field_a0.field_30.field_8, true);
    stream->vf50(field_a0.field_30.field_c, true);
    stream->vf50(field_a0.field_40.field_0, true);
    stream->vf50(field_a0.field_40.field_4, true);
    stream->vf50(field_a0.field_40.field_8.field_0, true);
    stream->vf50(field_a0.field_40.field_8.field_4, true);
    stream->vf50(field_a0.field_50.field_0, true);
    stream->vf50(field_a0.field_50.field_4, true);
    stream->vf50(field_a0.field_50.field_8.field_0, true);
    stream->vf50(field_a0.field_50.field_8.field_4, true);
    stream->vf50(field_a0.field_60, true);
    stream->vf50(field_a0.field_64, true);
    stream->vf51(field_a0.field_68, true);
    stream->vf50(field_a0.field_70, true);
    stream->vf50(field_a0.field_78, true);
    stream->vf50(field_a0.field_7c, true);
    stream->vf50(field_a0.field_80, true);
    stream->vf50(field_a0.field_84, true);
    stream->vf50(field_a0.field_88, true);
    stream->vf50(field_a0.field_8c, true);
    stream->vf50(field_a0.field_90, true);
    stream->vf50(field_a0.field_94, true);
    return true;
}

// 0x710056a960
bool SiGfxShaderEffectPackage::Unk_56a960(ISiIOStream* stream, Unk_567750_Header* header) {
    bool result = false;
    if (stream != nullptr) {
        Unk_582f10(stream, 0x10);
        memset(header, 0, sizeof(*header));
        stream->vf21(header->field_0, sizeof(header->field_0), true);
        if (Unk_4c5630(header->field_0, "SiGfxShaderEffectPackage", true) == 0) {
            header->field_20 = stream->vf29(true);
            if (static_cast<u8>(header->field_20 - 1) <= 1) {
                stream->vf13(header->field_20);
                for (s32 i = 0; i < 15; i++) {
                    stream->vf29(true);
                }
                header->field_30.field_0 = stream->vf27(true);
                header->field_30.field_4 = stream->vf27(true);
                header->field_30.field_8 = stream->vf27(true);
                header->field_30.field_c = stream->vf27(true);
                if (Unk_4cbc40(header->field_30.field_0, header->field_30.field_4, header->field_30.field_8,
                               header->field_30.field_c, 3, 0, 0, 5) == 0) {
                    header->field_40.field_0 = stream->vf27(true);
                    header->field_40.field_4 = stream->vf27(true);
                    header->field_40.field_8.field_0 = stream->vf27(true);
                    header->field_40.field_8.field_4 = stream->vf27(true);
                    header->field_50.field_0 = stream->vf27(true);
                    header->field_50.field_4 = stream->vf27(true);
                    header->field_50.field_8.field_0 = stream->vf27(true);
                    header->field_50.field_8.field_4 = stream->vf27(true);
                    header->field_60 = stream->vf27(true);
                    header->field_64 = stream->vf27(true);
                    header->field_68 = stream->vf28(true);
                    header->field_70 = stream->vf27(true);
                    header->field_78 = stream->vf27(true);
                    header->field_7c = stream->vf27(true);
                    header->field_80 = stream->vf27(true);
                    header->field_84 = stream->vf27(true);
                    header->field_88 = stream->vf27(true);
                    header->field_8c = stream->vf27(true);
                    header->field_90 = stream->vf27(true);
                    header->field_94 = stream->vf27(true);
                    field_78.field_0.field_0 = header->field_40.field_0;
                    field_78.field_0.field_4 = header->field_40.field_4;
                    field_78.field_0.field_8 = header->field_40.field_8;
                    field_78.field_10.field_0 = header->field_50.field_0;
                    field_78.field_10.field_4 = header->field_50.field_4;
                    field_78.field_10.field_8 = header->field_50.field_8;
                    field_78.field_20 = header->field_60;
                    result = true;
                }
            }
        }
    }
    return result;
}

// 0x710056ba50
bool SiGfxShaderEffectPackage::vf9() {
    field_1e0.Unk_4e3050();
    return Unk_5686f0();
}

// 0x710056c870
ISiGfxShaderEffectPackage::ShaderEffectData* SiGfxShaderEffectPackage::vf20(s32 index) {
    return field_140.m_pData[index];
}

// 0x710056c960
bool SiGfxShaderEffectPackage::vf22(SiGfxShaderEffect* effect) {
    if (!Unk_56ca20(this, effect)) {
        return false;
    }
    field_1e0.Unk_Add(effect);
    return true;
}

// 0x710056d2c0
bool SiGfxShaderEffectPackage::vf28() {
    for (s32 i = 0; i < static_cast<s32>(field_1e0.m_itemCount); i++) {
        field_1e0.m_pData[i]->vf20();
    }
    return Unk_56d320();
}

}  // namespace SiSDK3
