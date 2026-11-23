// Scope: common
// SiSDK3::SiGfxDisplayUtility: its constructor and destructors and the list
// of display adapters. The reference counts are its header's.
#define UNK_SIGFX_DISPLAYUTILITY_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_DisplayUtility_Impl.h>

namespace SiSDK3 {

// 0x71004d2ba0
SiGfxDisplayUtility::SiGfxDisplayUtility(ISiAllocator* pAllocator) : field_8(pAllocator), field_18(pAllocator) {}

// 0x71004d2c20 (D2), 0x71004d2d70 (D0)
SiGfxDisplayUtility::~SiGfxDisplayUtility() {
    Unk_ReleaseAll(&field_18);
}

// 0x71004d2e50
bool SiGfxDisplayUtility::Unk_4d2e50() {
    Unk_ReleaseAll(&field_18);
    return true;
}

// 0x71004d2f10
SiGfxDisplayAdapter* SiGfxDisplayUtility::vf6(s32 index) {
    return field_18.m_pData[index];
}

// 0x71004d2f20
SiGfxDisplayAdapter* SiGfxDisplayUtility::vf7(s32 index) {
    return field_18.m_pData[index];
}

// 0x71004d2f30
s32 SiGfxDisplayUtility::vf8(s32 index, void* a2) {
    if (index < 0 || index >= static_cast<s32>(field_18.m_itemCount)) {
        return -1;
    }
    SiGfxDisplayAdapter* pAdapter = field_18.m_pData[index];
    if (pAdapter == nullptr) {
        return -1;
    }
    return pAdapter->vf9(a2);
}

}  // namespace SiSDK3
