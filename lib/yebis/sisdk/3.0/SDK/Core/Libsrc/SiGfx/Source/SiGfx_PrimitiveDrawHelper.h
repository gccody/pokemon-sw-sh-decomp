// SiSDK3::SiGfxPrimitiveDrawHelper: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxPrimitiveDrawHelper {
public:
    virtual ~SiGfxPrimitiveDrawHelper();
    UNK_REFCOUNT_DECLARE;

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
};

}  // namespace SiSDK3

// 0x710054d300 (vf2), 0x710054d320 (vf3)
#line 45
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxPrimitiveDrawHelper, field_8, field_10)
