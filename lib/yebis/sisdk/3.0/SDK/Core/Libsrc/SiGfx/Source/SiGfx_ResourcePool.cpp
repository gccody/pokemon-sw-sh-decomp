// Scope: common
// SiSDK3::SiGfxResourcePool: its construction and destruction and the
// reference counts its header defines.
#define UNK_SIGFX_RESOURCEPOOL_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ResourcePool.h>

namespace SiSDK3 {

// 0x7100534000
SiGfxResourcePool::SiGfxResourcePool(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(0), field_48(pAllocator, true), field_170(false) {
    field_48.field_120 = true;
}

// 0x71005341b0 (D2), 0x71005343b0 (D0)
SiGfxResourcePool::~SiGfxResourcePool() {
    SiGfxResourcePool::vf6();
}

// 0x7100534430
void SiGfxResourcePool::vf6() {
    Unk_534460();
    field_48.Unk_4be7d0();
}

}  // namespace SiSDK3
