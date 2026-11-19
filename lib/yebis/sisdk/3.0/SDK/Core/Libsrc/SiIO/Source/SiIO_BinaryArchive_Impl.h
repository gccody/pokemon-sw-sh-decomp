// SiSDK3::SiIOBinaryArchive: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiIOBinaryArchive {
public:
    virtual ~SiIOBinaryArchive();
    UNK_REFCOUNT_DECLARE;

    u64 field_8;
    u64 field_10;
    SiSDK3::ISiAllocator* field_18;
    u32 field_20;
};

}  // namespace SiSDK3

// 0x710057c5d0 (vf2), 0x710057c5f0 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOBinaryArchive, field_18, field_20)
