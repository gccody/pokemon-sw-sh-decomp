// Scope: common
// SiSDK3::SiGfxNXRootSignature: its construction and destruction, its
// samplers' entries, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's; the functions that set its parameters
// aren't written yet.)
#define UNK_SIGFX_NX_ROOTSIGNATURE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RootSignature_Impl.h>

namespace SiSDK3 {

// 0x7100556cf0
SiGfxNXRootSignature::SiGfxNXRootSignature(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_24(false), field_25(false), field_28(pAllocator),
      field_78(pAllocator) {}

// (Both arrays are emptied here before their own destructors run: each
// array's vtable is stored after its buffer is freed.)
// NON_MATCHING (only the parameters' array's clear, 0x71005581e0, which this
// file instantiates): the same code, but in the loop over the parameters the
// original counts down before it advances the pointer (`subs ; add`), and
// this advances first. The samplers' array has the original's order with the
// same array delete.
// 0x7100556db0 (D2), 0x7100556fb0 (D0)
SiGfxNXRootSignature::~SiGfxNXRootSignature() {
    field_28.Unk_FreeAll();
    field_78.Unk_FreeAll();
}

// (In these two the flag is read into an int-sized local before the tests:
// the original has the index's test and the flag's as one condition, which
// LLVM only makes of two when the second costs one instruction besides its
// compare, and a byte's promotion would be a second.)
// 0x7100557b60
bool SiGfxNXRootSignature::vf18(s32 index, u32 a2, u32 a3, u32 a4, const Unk_SamplerDesc* desc) {
    u32 changing = field_25;
    if (index >= 0 && changing != 0) {
        if (static_cast<s32>(field_78.m_itemCount) <= index) {
            return false;
        }
        RootSamplerEntry& entry = field_78.m_pData[index];
        entry.field_0 = a2;
        entry.field_4 = a3;
        entry.field_8 = a4;
        entry.field_c = *desc;
        entry.field_50 = nullptr;
        return true;
    }
    return false;
}

// 0x7100557be0
bool SiGfxNXRootSignature::vf19(s32 index, u32 a2, u32 a3, u32 a4, Unk_NXRootSampler* sampler) {
    u32 changing = field_25;
    if (index >= 0 && changing != 0) {
        if (static_cast<s32>(field_78.m_itemCount) <= index) {
            return false;
        }
        RootSamplerEntry& entry = field_78.m_pData[index];
        entry.field_0 = a2;
        entry.field_4 = a3;
        entry.field_8 = a4;
        entry.field_50 = sampler;
        sampler->vf2();
        return true;
    }
    return false;
}

// 0x7100557c60
Unk_NXRootSampler* SiGfxNXRootSignature::vf21(s32 index) {
    return field_78.m_pData[index].field_50;
}

}  // namespace SiSDK3
