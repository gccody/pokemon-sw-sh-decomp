// Scope: common
// SiSDK3::SiGfxNXDescriptorSet: its construction and destruction, its
// parameters, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_DESCRIPTORSET_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DescriptorSet_Impl.h>

namespace SiSDK3 {

// 0x710054e790
SiGfxNXDescriptorSet::SiGfxNXDescriptorSet(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(1), field_24(0), field_28(pAllocator), field_78(0) {}

// 0x710054e810 (D2), 0x710054e960 (D0)
SiGfxNXDescriptorSet::~SiGfxNXDescriptorSet() {}

// 0x710054ea80
bool SiGfxNXDescriptorSet::vf9(s32 count) {
    if (static_cast<u32>(count) > 32) {
        return false;
    }
    field_28.Unk_SetCount(count);
    return true;
}

// The parameter of an index becomes one of a kind; that's a change, unless
// more are coming.
#define UNK_SET_PARAMETER(Slot, Kind)                                   \
    bool SiGfxNXDescriptorSet::Slot(s32 index, u32 a2, u64 a3) {       \
        ParameterEntry& entry = field_28.m_pData[index];                \
        entry.field_10 = false;                                         \
        entry.field_8 = 0;                                              \
        entry.field_c = 0;                                              \
        entry.field_18 = a3;                                            \
        entry.field_20 = 0;                                             \
        entry.field_0 = Kind;                                           \
        entry.field_4 = a2;                                             \
        if (field_24 == 0) {                                            \
            field_78++;                                                 \
        }                                                               \
        return true;                                                    \
    }

// 0x710054eb30
UNK_SET_PARAMETER(vf10, 1)
// 0x710054eb80
UNK_SET_PARAMETER(vf11, 2)
// 0x710054ebd0
UNK_SET_PARAMETER(vf12, 3)
#undef UNK_SET_PARAMETER

// 0x710054ec20 (the kind is set before what it is)
bool SiGfxNXDescriptorSet::vf13(s32 index, u32 a2, u64 a3) {
    ParameterEntry& entry = field_28.m_pData[index];
    entry.field_10 = false;
    entry.field_8 = 0;
    entry.field_c = 0;
    entry.field_0 = 4;
    entry.field_4 = a2;
    entry.field_18 = 0;
    entry.field_20 = a3;
    if (field_24 == 0) {
        field_78++;
    }
    return true;
}

// 0x710054ec70
bool SiGfxNXDescriptorSet::vf14(s32 index, bool flag) {
    field_28.m_pData[index].field_10 = flag;
    return true;
}

// 0x710054ec90
bool SiGfxNXDescriptorSet::vf15(s32 index) {
    return field_28.m_pData[index].field_10;
}

// 0x710054ecb0
bool SiGfxNXDescriptorSet::vf16() {
    if (field_24 - 1 < 0) {
        return false;
    }
    field_24--;
    if (field_24 == 0) {
        field_78++;
    }
    return true;
}

}  // namespace SiSDK3
