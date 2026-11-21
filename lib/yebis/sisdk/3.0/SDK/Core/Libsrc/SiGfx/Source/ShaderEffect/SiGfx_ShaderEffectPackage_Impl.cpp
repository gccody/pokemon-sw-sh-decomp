// Scope: common
// SiSDK3::SiGfxShaderEffectPackage: its construction and destruction, its
// file's header and the small functions (the rest isn't written yet).
#define UNK_SIGFX_SHADEREFFECTPACKAGE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectPackage_Impl.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectDefinition_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectVariation_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffect_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x7100582f10, 0x7100582f70: skip to, and fill up to, a multiple of alignment
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment);
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);
// 0x71004c5520: copies a string into a buffer, 0x71004c5630: compares
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);
s64 Unk_4c5630(const char* a, const char* b, bool);
// 0x71004cbc40: compares two versions
s32 Unk_4cbc40(s32, s32, s32, s32, s32, s32, s32, s32);
// 0x710057d030: SiIO's kernel as a number (leafgen's name and type)
u64 Unk_57d030_get();
// 0x7100570d00 (leafgen's name and type): the variation list's initialisation
u64 Unk_570d00_get(u64 list);
// 0x710056ca20 (leafgen's name): whether an effect may be added
bool Unk_56ca20(void* package, void* effect);

namespace SiSDK3 {

inline void SiGfxShaderEffectPackage::Unk_ReadKey(ISiIOStream* stream, SiGfxShaderEffectKey* key, bool keep) {
    Unk_582f10(stream, 0x10);
    u32 value = stream->vf31(true);
    key->field_8 = keep ? value : 0;
    for (s64 i = 0; i < key->field_c; i++) {
        key->field_10[i] = stream->vf29(true);
    }
}

inline void SiGfxShaderEffectPackage::Unk_WriteKey(ISiIOStream* stream, const SiGfxShaderEffectKey* key) {
    Unk_582f70(stream, 0x10, 0);
    stream->vf54(key->field_8, true);
    for (s64 i = 0; i < key->field_c; i++) {
        stream->vf52(key->field_10[i], true);
    }
}

// 0x7100566070
ISiGfxShaderEffectPackage::ShaderProgramData::ShaderProgramData(ISiAllocator* pAllocator)
    : field_0(pAllocator), field_8(pAllocator), field_50(pAllocator), field_a0(0), field_c0(pAllocator), field_110(0),
      field_114(0) {
    for (s32 i = 0; i < 6; i++) {
        field_118[i] = -1;
    }
}

// 0x7100566150
ISiGfxShaderEffectPackage::ShaderProgramData::~ShaderProgramData() {}

// 0x7100566250
ISiGfxShaderEffectPackage::TechniqueData::TechniqueData(ISiAllocator* pAllocator)
    : field_0(pAllocator), field_8(0), field_10(pAllocator), field_40(pAllocator), field_70(pAllocator),
      field_a0(pAllocator), field_d0(pAllocator), field_100(pAllocator), field_130(pAllocator), field_160(pAllocator),
      field_190(pAllocator), field_1c0(pAllocator), field_1f0(pAllocator), field_220(pAllocator), field_250(0),
      field_a70(pAllocator), field_ac0(pAllocator), field_b10(0), field_b14(0) {
    memset(&field_254, 0, sizeof(field_254));
}

// 0x71005665d0
ISiGfxShaderEffectPackage::TechniqueData::~TechniqueData() {
    field_ac0.Unk_4e3050();
    Unk_566a00(field_0, &field_a70, false);
}

// Makes an effect's data (inline in its caller: placeholder name; its line
// is before the constructor's).
static ISiGfxShaderEffectPackage::ShaderEffectData* Unk_NewShaderEffectData(ISiAllocator* pAllocator);

// 0x7100566bb0
ISiGfxShaderEffectPackage::ShaderEffectData::ShaderEffectData(ISiAllocator* pAllocator)
    : field_0(pAllocator), field_8(pAllocator), field_38(0), field_3c(0), field_40(0), field_44(-1), field_48(0),
      field_4c(-1), field_50(0), field_58(nullptr), field_60(pAllocator), field_b0(nullptr) {
#line 174
    field_b0 = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderEffect::ShaderProgramMap(pAllocator);
}

// SiCore_Array.h's delete of what an array of pointers holds, for the three
// kinds of data (the programs' is the technique's destructor's).
// 0x7100566a00 = _ZN6SiSDK310Unk_566a00INS_25ISiGfxShaderEffectPackage17ShaderProgramDataELi16EEEvPNS_12ISiAllocatorEPNS_7SiArrayIPT_XT0_EEEb
// 0x71005675a0 = _ZN6SiSDK310Unk_566a00INS_25ISiGfxShaderEffectPackage13TechniqueDataELi16EEEvPNS_12ISiAllocatorEPNS_7SiArrayIPT_XT0_EEEb
template void Unk_566a00<ISiGfxShaderEffectPackage::TechniqueData, 16>(
    ISiAllocator*, SiArray<ISiGfxShaderEffectPackage::TechniqueData*, 16>*, bool);
// 0x710056bac0 = _ZN6SiSDK310Unk_566a00INS_25ISiGfxShaderEffectPackage16ShaderEffectDataELi16EEEvPNS_12ISiAllocatorEPNS_7SiArrayIPT_XT0_EEEb
template void Unk_566a00<ISiGfxShaderEffectPackage::ShaderEffectData, 16>(
    ISiAllocator*, SiArray<ISiGfxShaderEffectPackage::ShaderEffectData*, 16>*, bool);

// SiGfxShaderEffectKey's destructors (inline, in its header).
// 0x7100535ff0 = _ZN6SiSDK320SiGfxShaderEffectKeyD2Ev
// 0x7100536390 = _ZN6SiSDK320SiGfxShaderEffectKeyD0Ev

static ISiGfxShaderEffectPackage::ShaderEffectData* Unk_NewShaderEffectData(ISiAllocator* pAllocator) {
#line 150
    return UNK_SI_NEW(pAllocator, 0x10) ISiGfxShaderEffectPackage::ShaderEffectData(pAllocator);
}

}  // namespace SiSDK3

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
bool SiGfxShaderEffectPackage::vf14(s64 value108, void* valueBe8, u32 value104, const SiArray<Unk_5693e0>* shaders0,
                                    const SiArray<Unk_5693e0>* shaders1, const SiArray<Unk_5693e0>* shaders2,
                                    const SiArray<Unk_5693e0>* shaders3, const SiArray<Unk_5693e0>* shaders4,
                                    const SiArray<Unk_5693e0>* shaders5) {
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
    if (data == nullptr || field_138 < 1) {
        return false;
    }
    field_140.Unk_Add(data);
    return true;
}

// 0x7100569520
void SiGfxShaderEffectPackage::vf16(const Unk_567b80* options) {
    field_2d0 = *options;
}

// 0x71005695a0
bool SiGfxShaderEffectPackage::vf10(const char* path, u32 byteOrder) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 0x15, nullptr);
    if (stream == nullptr) {
        return false;
    }
    {
        Unk_5697b0(stream, byteOrder);
        Unk_582f70(stream, 0x10, 0);
        for (s64 i = 0; i < static_cast<s32>(field_230.m_itemCount); i++) {
            if (field_230.m_pData[i] != nullptr) {
                field_230.m_pData[i]->vf14(stream);
            }
        }
        Unk_582f70(stream, 0x10, 0);
        for (s64 i = 0; i < static_cast<s32>(field_280.m_itemCount); i++) {
            if (field_280.m_pData[i] != nullptr) {
                field_280.m_pData[i]->vf14(stream);
            }
        }
        Unk_582f70(stream, 0x10, 0);
        stream->vf50(field_2d0.field_e8, true);
        stream->vf50(field_2d0.field_ec, true);
        stream->vf54(field_2d0.field_f0, true);
        Unk_569c40(stream);
        Unk_582f70(stream, 0x10, 0);
        for (s64 i = 0; i < static_cast<s32>(field_140.m_itemCount); i++) {
            Unk_569dd0(stream, field_140.m_pData[i]);
        }
        Unk_582f70(stream, 0x10, 0);
        for (s64 i = 0; i < static_cast<s32>(field_190.m_itemCount); i++) {
            stream->vf50(field_190.m_pData[i]->field_3c, true);
        }
        Unk_StringAssign(&field_48, path);
        stream->vf3();
    }
    return true;
}

// 0x7100569c40
bool SiGfxShaderEffectPackage::Unk_569c40(ISiIOStream* stream) {
    if (stream == nullptr) {
        return false;
    }
    if (field_a0.field_68 >= 1) {
        Unk_582f70(stream, field_a0.field_64, 0);
        stream->vf44(field_be8, field_a0.field_68, true);
    }
    Unk_582f70(stream, 0x10, 0);
    if (field_a0.field_80 >= 1) {
        stream->vf44(field_bf8[0], static_cast<s64>(field_a0.field_80) * sizeof(Unk_5693e0), true);
    }
    if (field_a0.field_84 >= 1) {
        stream->vf44(field_bf8[1], static_cast<s64>(field_a0.field_84) * sizeof(Unk_5693e0), true);
    }
    if (field_a0.field_88 >= 1) {
        stream->vf44(field_bf8[2], static_cast<s64>(field_a0.field_88) * sizeof(Unk_5693e0), true);
    }
    if (field_a0.field_8c >= 1) {
        stream->vf44(field_bf8[3], static_cast<s64>(field_a0.field_8c) * sizeof(Unk_5693e0), true);
    }
    if (field_a0.field_90 >= 1) {
        stream->vf44(field_bf8[4], static_cast<s64>(field_a0.field_90) * sizeof(Unk_5693e0), true);
    }
    if (field_a0.field_94 >= 1) {
        stream->vf44(field_bf8[5], static_cast<s64>(field_a0.field_94) * sizeof(Unk_5693e0), true);
    }
    return true;
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

// 0x7100569dd0
bool SiGfxShaderEffectPackage::Unk_569dd0(ISiIOStream* stream, ISiGfxShaderEffectPackage::ShaderEffectData* data) {
    if (stream == nullptr || data == nullptr) {
        return false;
    }
    if (data->field_58 == nullptr) {
        return false;
    }
    Unk_582f70(stream, 0x10, 0);
    stream->vf58(Unk_StringCStr(&data->field_8), true);
    Unk_582f70(stream, 0x10, 0);
    stream->vf54(data->field_38, true);
    stream->vf58(Unk_StringCStr(data->field_58->vf5()), true);
    Unk_582f70(stream, 0x10, 0);
    stream->vf50(data->field_40, true);
    stream->vf50(data->field_60.m_itemCount, true);
    for (s64 i = 0; i < static_cast<s32>(data->field_60.m_itemCount); i++) {
        Unk_569f40(stream, data, data->field_60.m_pData[i]);
    }
    return true;
}

// 0x7100569f40
bool SiGfxShaderEffectPackage::Unk_569f40(ISiIOStream* stream, ISiGfxShaderEffectPackage::ShaderEffectData* data,
                                          ISiGfxShaderEffectPackage::TechniqueData* technique) {
    Unk_582f70(stream, 0x10, 0);
    stream->vf54(technique->field_8, true);
    if (technique->field_8 & 1) {
        Unk_582f70(stream, 0x10, 0);
        stream->vf60(Unk_StringCStr(&technique->field_10), true);
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&technique->field_40), true);
    }
    if (technique->field_8 & 2) {
        Unk_582f70(stream, 0x10, 0);
        stream->vf60(Unk_StringCStr(&technique->field_70), true);
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&technique->field_a0), true);
    }
    if (technique->field_8 & 4) {
        Unk_582f70(stream, 0x10, 0);
        stream->vf60(Unk_StringCStr(&technique->field_d0), true);
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&technique->field_100), true);
    }
    if (technique->field_8 & 0x10) {
        Unk_582f70(stream, 0x10, 0);
        stream->vf60(Unk_StringCStr(&technique->field_130), true);
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&technique->field_160), true);
    }
    if (technique->field_8 & 8) {
        Unk_582f70(stream, 0x10, 0);
        stream->vf60(Unk_StringCStr(&technique->field_190), true);
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&technique->field_1c0), true);
    }
    if (technique->field_8 & 0x20) {
        Unk_582f70(stream, 0x10, 0);
        stream->vf60(Unk_StringCStr(&technique->field_1f0), true);
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&technique->field_220), true);
    }
    Unk_582f70(stream, 0x10, 0);
    stream->vf50(technique->field_250, true);
    if (technique->field_250 != 0) {
        Unk_56a350_(stream, &technique->field_254);
    }
    Unk_582f70(stream, 0x10, 0);
    stream->vf50(technique->field_a70.m_itemCount, true);
    Unk_582f70(stream, 0x10, 0);
    for (s64 i = 0; i < static_cast<s32>(technique->field_a70.m_itemCount); i++) {
        Unk_56a4f0(stream, data, technique, technique->field_a70.m_pData[i]);
    }
    Unk_582f70(stream, 0x10, 0);
    for (s64 i = 0; i < static_cast<s32>(technique->field_ac0.m_itemCount); i++) {
        stream->vf50(technique->field_ac0.m_pData[i]->field_114, true);
    }
    return true;
}

// 0x710056a4f0
bool SiGfxShaderEffectPackage::Unk_56a4f0(ISiIOStream* stream, ISiGfxShaderEffectPackage::ShaderEffectData* data,
                                          ISiGfxShaderEffectPackage::TechniqueData* technique,
                                          ISiGfxShaderEffectPackage::ShaderProgramData* program) {
    if (stream == nullptr || program == nullptr) {
        return false;
    }
    Unk_582f70(stream, 0x10, 0);
    stream->vf58(Unk_StringCStr(&program->field_8), true);
    Unk_582f70(stream, 0x10, 0);
    Unk_WriteKey(stream, &program->field_38);
    Unk_582f70(stream, 0x10, 0);
    stream->vf54(program->field_a0, true);
    Unk_582f70(stream, 0x10, 0);
    Unk_WriteKey(stream, &program->field_a8);
    Unk_582f70(stream, 0x10, 0);
    stream->vf54(program->field_110, true);
    u32 flags = technique->field_8;
    if (flags & 1) {
        stream->vf50(program->field_118[0], true);
    }
    if (flags & 2) {
        stream->vf50(program->field_118[1], true);
    }
    if (flags & 4) {
        stream->vf50(program->field_118[2], true);
    }
    if (flags & 0x10) {
        stream->vf50(program->field_118[3], true);
    }
    if (flags & 8) {
        stream->vf50(program->field_118[4], true);
    }
    if (flags & 0x20) {
        stream->vf50(program->field_118[5], true);
    }
    return true;
}

// 0x710056a350 = _ZN6SiSDK324SiGfxShaderEffectPackage11Unk_56a350_EPNS_11ISiIOStreamEPNS_10Unk_56a350E
bool SiGfxShaderEffectPackage::Unk_56a350_(ISiIOStream* stream, Unk_56a350* table) {
    if (stream == nullptr) {
        return false;
    }
    Unk_582f70(stream, 0x10, 0);
    stream->vf50(table->field_0, true);
    stream->vf50(table->field_804, true);
    stream->vf50(table->field_818, true);
    for (s64 i = 0; i < table->field_0; i++) {
        stream->vf50(table->field_4[i].field_0, true);
        stream->vf50(table->field_4[i].field_4, true);
        stream->vf50(table->field_4[i].field_8, true);
        stream->vf50(table->field_4[i].field_c, true);
        stream->vf50(table->field_4[i].field_10, true);
        stream->vf50(table->field_4[i].field_14, true);
    }
    for (s64 i = 0; i < table->field_804; i++) {
        stream->vf50(table->field_808[i], true);
    }
    return true;
}

// 0x710056a770
bool SiGfxShaderEffectPackage::vf8(const char* path) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 9, nullptr);
    if (stream == nullptr) {
        return false;
    }
    {
        Unk_567750_Header header;
        if (!Unk_56a960(stream, &header)) {
            stream->vf3();
            return false;
        }
        field_a0 = header;
        field_bf0 = true;
        Unk_56ae10(stream, &header);
        Unk_56b000(stream, &header);
        Unk_582f10(stream, 0x10);
        field_2d0.field_e8 = stream->vf27(true);
        field_2d0.field_ec = stream->vf27(true);
        field_2d0.field_f0 = stream->vf31(true);
        Unk_56b230(stream, &header);
        Unk_56b8a0(stream, &header);
        field_190.Unk_SetCount(header.field_7c);
        Unk_582f10(stream, 0x10);
        for (s64 i = 0; i < static_cast<s32>(field_190.m_itemCount); i++) {
            s32 index = stream->vf27(true);
            field_190.m_pData[i] = field_140.m_pData[index];
        }
        stream->vf3();
        Unk_StringAssign(&field_48, path);
    }
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

// 0x710056ae10
bool SiGfxShaderEffectPackage::Unk_56ae10(ISiIOStream* stream, Unk_567750_Header* header) {
    if (stream == nullptr) {
        return false;
    }
    Unk_582f10(stream, 0x10);
    field_230.Unk_ReserveAtLeast(header->field_70);
    for (s32 i = 0; i < header->field_70; i++) {
#line 1510
        SiGfxShaderEffectVariation* variation = UNK_SI_NEW(field_8.m_pAllocator, 0x10) SiGfxShaderEffectVariation(field_8.m_pAllocator);
        if (variation->vf15(stream)) {
            field_230.Unk_Add(reinterpret_cast<ISiGfxShaderEffectVariation*>(variation));
        } else if (variation != nullptr) {
            variation->vf3();
        }
    }
    return true;
}

// 0x710056b000
bool SiGfxShaderEffectPackage::Unk_56b000(ISiIOStream* stream, Unk_567750_Header* header) {
    if (stream == nullptr) {
        return false;
    }
    Unk_582f10(stream, 0x10);
    field_280.Unk_ReserveAtLeast(header->field_78);
    for (s32 i = 0; i < header->field_78; i++) {
#line 1544
        SiGfxShaderEffectDefinition* definition = UNK_SI_NEW(field_8.m_pAllocator, 0x10) SiGfxShaderEffectDefinition(field_8.m_pAllocator);
        if (definition->vf15(stream)) {
            s32 index = definition->vf8();
            if (index >= 0 && index < static_cast<s32>(field_230.m_itemCount)) {
                definition->vf16(reinterpret_cast<Unk_570680*>(field_230.m_pData[index]));
            }
            field_280.Unk_Add(reinterpret_cast<ISiGfxShaderEffectDefinition*>(definition));
        } else if (definition != nullptr) {
            definition->vf3();
        }
    }
    return true;
}

// 0x710056b8a0
bool SiGfxShaderEffectPackage::Unk_56b8a0(ISiIOStream* stream, Unk_567750_Header* header) {
    field_140.Unk_ReserveAtLeast(header->field_7c);
    for (s32 i = 0; i < header->field_7c; i++) {
        ISiGfxShaderEffectPackage::ShaderEffectData* data = Unk_NewShaderEffectData(field_8.m_pAllocator);
        if (data != nullptr) {
            data->field_3c = i;
            Unk_56bbf0(stream, data);
            field_140.Unk_Add(data);
        }
    }
    return true;
}

// 0x710056ba50
bool SiGfxShaderEffectPackage::vf9() {
    field_1e0.Unk_4e3050();
    return Unk_5686f0();
}

// 0x710056bbf0
bool SiGfxShaderEffectPackage::Unk_56bbf0(ISiIOStream* stream, ISiGfxShaderEffectPackage::ShaderEffectData* data) {
    if (stream == nullptr || data == nullptr) {
        return false;
    }
    Unk_582f10(stream, 0x10);
    stream->vf35(&data->field_8, true);
    Unk_582f10(stream, 0x10);
    data->field_38 = stream->vf31(true);
    SiString<char> name(field_8.m_pAllocator);
    stream->vf35(&name, true);
    Unk_582f10(stream, 0x10);
    s32 size0 = 0;
    s32 size1 = 0;
    s32 index = stream->vf27(true);
    if (index >= 0 && index < static_cast<s32>(field_280.m_itemCount)) {
        data->Unk_SetDefinition(field_280.m_pData[index]);
        ISiGfxShaderEffectVariation* variation = data->field_58->vf17();
        if (variation != nullptr) {
            size0 = variation->vf7();
            size1 = variation->vf11();
        }
    }
    s32 count = stream->vf27(true);
    data->field_60.Unk_SetCount(count);
    for (s64 i = 0; i < count; i++) {
#line 1789
        ISiGfxShaderEffectPackage::TechniqueData* technique = UNK_SI_NEW(field_8.m_pAllocator, 0x10) ISiGfxShaderEffectPackage::TechniqueData(field_8.m_pAllocator);
        if (technique == nullptr) {
            return false;
        }
        technique->field_b10 = size0;
        technique->field_b14 = size1;
        data->field_60.m_pData[i] = technique;
        Unk_56bf40(stream, data, technique);
    }
    return true;
}

// 0x710056bf40
bool SiGfxShaderEffectPackage::Unk_56bf40(ISiIOStream* stream, ISiGfxShaderEffectPackage::ShaderEffectData* data,
                                          ISiGfxShaderEffectPackage::TechniqueData* technique) {
    Unk_582f10(stream, 0x10);
    technique->field_8 = stream->vf31(true);
    if (technique->field_8 & 1) {
        Unk_582f10(stream, 0x10);
        stream->vf37(&technique->field_10, true);
        Unk_582f10(stream, 0x10);
        stream->vf35(&technique->field_40, true);
    }
    if (technique->field_8 & 2) {
        Unk_582f10(stream, 0x10);
        stream->vf37(&technique->field_70, true);
        Unk_582f10(stream, 0x10);
        stream->vf35(&technique->field_a0, true);
    }
    if (technique->field_8 & 4) {
        Unk_582f10(stream, 0x10);
        stream->vf37(&technique->field_d0, true);
        Unk_582f10(stream, 0x10);
        stream->vf35(&technique->field_100, true);
    }
    if (technique->field_8 & 0x10) {
        Unk_582f10(stream, 0x10);
        stream->vf37(&technique->field_130, true);
        Unk_582f10(stream, 0x10);
        stream->vf35(&technique->field_160, true);
    }
    if (technique->field_8 & 8) {
        Unk_582f10(stream, 0x10);
        stream->vf37(&technique->field_190, true);
        Unk_582f10(stream, 0x10);
        stream->vf35(&technique->field_1c0, true);
    }
    if (technique->field_8 & 0x20) {
        Unk_582f10(stream, 0x10);
        stream->vf37(&technique->field_1f0, true);
        Unk_582f10(stream, 0x10);
        stream->vf35(&technique->field_220, true);
    }
    Unk_582f10(stream, 0x10);
    s32 table = stream->vf27(true);
    if (table != 0) {
        technique->field_250 = table;
        Unk_56c480(stream, &technique->field_254);
    }
    Unk_582f10(stream, 0x10);
    s32 count = stream->vf27(true);
    if (!technique->field_a70.Unk_SetCount(count)) {
        return false;
    }
    if (!technique->field_ac0.Unk_SetCount(count)) {
        return false;
    }
    Unk_582f10(stream, 0x10);
    for (s64 i = 0; i < static_cast<s32>(technique->field_a70.m_itemCount); i++) {
#line 1878
        ISiGfxShaderEffectPackage::ShaderProgramData* program = UNK_SI_NEW(field_8.m_pAllocator, 0x10) ISiGfxShaderEffectPackage::ShaderProgramData(field_8.m_pAllocator);
        if (technique->field_b10 > 0) {
            program->field_50.Unk_SetCount(technique->field_b10);
            program->field_38.Unk_Set(technique->field_b10, program->field_50.m_pData);
        }
        if (technique->field_b14 > 0) {
            program->field_c0.Unk_SetCount(technique->field_b14);
            program->field_a8.Unk_Set(technique->field_b14, program->field_c0.m_pData);
        }
        technique->field_a70.m_pData[i] = program;
        program->field_114 = i;
        Unk_56c610(stream, data, technique, program);
    }
    Unk_582f10(stream, 0x10);
    for (s32 i = 0; i < count; i++) {
        s32 index = stream->vf27(true);
        technique->field_ac0.m_pData[i] = technique->field_a70.m_pData[index];
    }
    return true;
}

// 0x710056c480
bool SiGfxShaderEffectPackage::Unk_56c480(ISiIOStream* stream, Unk_56a350* table) {
    if (stream == nullptr) {
        return false;
    }
    table->field_0 = stream->vf27(true);
    table->field_804 = stream->vf27(true);
    table->field_818 = stream->vf27(true);
    for (s64 i = 0; i < table->field_0; i++) {
        table->field_4[i].field_0 = stream->vf27(true);
        table->field_4[i].field_4 = stream->vf27(true);
        table->field_4[i].field_8 = stream->vf27(true);
        table->field_4[i].field_c = stream->vf27(true);
        table->field_4[i].field_10 = stream->vf27(true);
        table->field_4[i].field_14 = stream->vf27(true);
    }
    for (s64 i = 0; i < table->field_804; i++) {
        table->field_808[i] = stream->vf27(true);
    }
    return true;
}

// 0x710056c610
bool SiGfxShaderEffectPackage::Unk_56c610(ISiIOStream* stream, ISiGfxShaderEffectPackage::ShaderEffectData* data,
                                          ISiGfxShaderEffectPackage::TechniqueData* technique,
                                          ISiGfxShaderEffectPackage::ShaderProgramData* program) {
    if (stream == nullptr || program == nullptr) {
        return false;
    }
    Unk_582f10(stream, 0x10);
    stream->vf35(&program->field_8, true);
    Unk_582f10(stream, 0x10);
    Unk_ReadKey(stream, &program->field_38, true);
    Unk_582f10(stream, 0x10);
    program->field_a0 = stream->vf31(true);
    Unk_582f10(stream, 0x10);
    Unk_ReadKey(stream, &program->field_a8, false);
    Unk_582f10(stream, 0x10);
    program->field_110 = stream->vf31(true);
    u32 flags = technique->field_8;
    if (flags & 1) {
        program->field_118[0] = stream->vf27(true);
    }
    if (flags & 2) {
        program->field_118[1] = stream->vf27(true);
    }
    if (flags & 4) {
        program->field_118[2] = stream->vf27(true);
    }
    if (flags & 0x10) {
        program->field_118[3] = stream->vf27(true);
    }
    if (flags & 8) {
        program->field_118[4] = stream->vf27(true);
    }
    if (flags & 0x20) {
        program->field_118[5] = stream->vf27(true);
    }
    return true;
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
