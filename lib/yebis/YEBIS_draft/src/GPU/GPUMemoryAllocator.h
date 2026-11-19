// PPFX::SiYebisAllocator: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace PPFX {

class SiYebisAllocator {
public:
    virtual ~SiYebisAllocator();
    UNK_REFCOUNT_DECLARE;

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
};

}  // namespace PPFX

// 0x710043c140 (vf2), 0x710043c160 (vf3)
#line 486
UNK_REFCOUNT_DEFINE(PPFX::SiYebisAllocator, field_8, field_10)
