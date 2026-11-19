// SiSDK3::SiGfxNXCommandListPool: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxNXCommandListPool {
public:
    virtual ~SiGfxNXCommandListPool();
    UNK_REFCOUNT_DECLARE;

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
};

}  // namespace SiSDK3

// 0x710054f6d0 (vf2), 0x710054f6f0 (vf3)
#line 38
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXCommandListPool, field_8, field_10)
