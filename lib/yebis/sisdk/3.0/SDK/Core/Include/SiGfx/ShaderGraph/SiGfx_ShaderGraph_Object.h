// SiSDK3::SiGfxShaderGraphObject: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxShaderGraphObject {
public:
    virtual ~SiGfxShaderGraphObject();
    UNK_REFCOUNT_DECLARE;

    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    SiSDK3::ISiAllocator* field_30;
    u32 field_38;
};

}  // namespace SiSDK3

// 0x71004dc340 (vf2), 0x71004dc360 (vf3)
#line 34
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderGraphObject, field_30, field_38)
