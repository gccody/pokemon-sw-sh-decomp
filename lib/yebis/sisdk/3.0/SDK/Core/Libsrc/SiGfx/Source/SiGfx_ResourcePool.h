// SiSDK3::SiGfxResourcePool: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines,
// for the class's own translation unit (UNK_SIGFX_RESOURCEPOOL_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxResourcePool {
public:
    // 0x7100534000
    explicit SiGfxResourcePool(ISiAllocator* pAllocator);
    virtual ~SiGfxResourcePool();
    UNK_REFCOUNT_DECLARE;
    virtual void vf4();
    virtual void vf5(u32 count);  // (as the device calls a pool's)

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
    u8 field_18[0x160];
};
PKMN_SIZE_ASSERT(SiGfxResourcePool, 0x178);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_RESOURCEPOOL_IMPL
// 0x71004ff160 (vf2), 0x71004ff180 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxResourcePool, field_8, field_10)
#endif
