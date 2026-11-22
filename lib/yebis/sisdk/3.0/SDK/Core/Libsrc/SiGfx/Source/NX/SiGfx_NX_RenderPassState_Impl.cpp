// Scope: common
// SiSDK3::SiGfxNXRenderPassState: its construction and destruction, its
// count, and the reference counts its header defines. (Its small accessors
// are lib/yebis/class's.)
#define UNK_SIGFX_NX_RENDERPASSSTATE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RenderPassState_Impl.h>

namespace SiSDK3 {

// 0x71005550c0
SiGfxNXRenderPassState::SiGfxNXRenderPassState(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(1), field_24(0), field_28(0) {}

// 0x7100555100 (D2), 0x7100555120 (D0)
SiGfxNXRenderPassState::~SiGfxNXRenderPassState() {}

// 0x71005551c0
bool SiGfxNXRenderPassState::vf9() {
    if (field_24 - 1 < 0) {
        return false;
    }
    field_24--;
    return true;
}

}  // namespace SiSDK3
