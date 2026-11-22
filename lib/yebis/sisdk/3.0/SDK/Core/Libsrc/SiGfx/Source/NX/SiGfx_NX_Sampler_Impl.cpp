// Scope: common
// SiSDK3::SiGfxNXSampler: its construction and destruction, its NVN sampler,
// its name, and the reference counts its header defines. (Its small accessors
// are lib/yebis/class's.)
#define UNK_SIGFX_NX_SAMPLER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Sampler_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x7100562f40: a filter's NVN minification and magnification filters, and
// whether it compares and whether it's anisotropic
void Unk_562f40(u32 filter, s32* minFilter, s32* magFilter, bool* compare, bool* anisotropic);
// 0x71005630b0: a wrap mode's NVN one, 0x71005631a0: a comparison's
s32 Unk_5630b0(u32 mode);
s32 Unk_5631a0(u32 function);

namespace SiSDK3 {

// 0x7100558c60
SiGfxNXSampler::SiGfxNXSampler(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice, const Unk_Desc& desc)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_60(0), field_78(desc),
      field_b8(0), field_120(-1), field_124(false) {
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 12;
}

// 0x7100558d40 (D2), 0x7100558e30 (D0); 0x7100558e20 and 0x7100558e60 are
// their thunks for the second base
SiGfxNXSampler::~SiGfxNXSampler() {
    if (field_120 != -1 && field_20 != nullptr) {
        field_20->Unk_4fb2f0(field_120);
        field_120 = -1;
    }
    if (field_124) {
        nvnSamplerFinalize(field_c0);
        memset(field_c0, 0, sizeof(field_c0));
        field_124 = false;
    }
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
}

// 0x7100558e90
bool SiGfxNXSampler::Unk_558e90(size_t index) {
    field_28 = index;
    void* device = Unk_NXDevice(field_20)->vf85();
    s32 minFilter;
    s32 magFilter;
    bool compare;
    bool anisotropic;
    Unk_562f40(field_78.field_0, &minFilter, &magFilter, &compare, &anisotropic);
    // (the builder's scope: the two failures leave it through one block, the
    // success returns from inside)
    {
        u64 builder[12] = {};  // NVNsamplerBuilder
        nvnSamplerBuilderSetDefaults(builder);
        nvnSamplerBuilderSetDevice(builder, device);
        nvnSamplerBuilderSetMinMagFilter(builder, minFilter, magFilter);
        nvnSamplerBuilderSetWrapMode(builder, Unk_5630b0(field_78.field_4), Unk_5630b0(field_78.field_8),
                                     Unk_5630b0(field_78.field_c));
        if (compare) {
            nvnSamplerBuilderSetCompare(builder, 1, Unk_5631a0(field_78.field_20));
        }
        nvnSamplerBuilderSetBorderColor(builder, field_78.field_24.field_0);
        nvnSamplerBuilderSetLodBias(builder, field_78.field_10);
        nvnSamplerBuilderSetLodClamp(builder, field_78.field_14, field_78.field_18);
        nvnSamplerBuilderSetMaxAnisotropy(builder, static_cast<f32>(field_78.field_1c));
        nvnSamplerBuilderSetReductionFilter(builder, 0);
        if (nvnSamplerInitialize(field_c0, builder) == 1) {
            field_120 = static_cast<s32>(field_20->Unk_4fb260(reinterpret_cast<u64>(field_c0)));
            if (field_120 != -1) {
                field_124 = true;
                nvnSamplerSetDebugLabel(field_c0, Unk_StringCStr(&field_30));
                return true;
            }
        }
    }
    return false;
}

// 0x71005590b0 (0x7100559120: its thunk)
bool SiGfxNXSampler::vf20(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    if (field_124) {
        nvnSamplerSetDebugLabel(field_c0, Unk_StringCStr(&field_30));
    }
    return true;
}

// 0x7100559190 (0x71005591a0: its thunk)
const SiString<char>* SiGfxNXSampler::vf21() {
    return &field_30;
}

// 0x71005591b0 (0x71005591c0: its thunk)
u32 SiGfxNXSampler::vf22() {
    return field_60;
}

}  // namespace SiSDK3
