// SiSDK3::ISiIOBinaryArchive, SiSDK3::ISiIOBinaryArchive::ChunkHandler: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class ISiIOBinaryArchive {
public:
    class ChunkHandler {
    public:
        virtual ~ChunkHandler();
        UNK_REFCOUNT_DECLARE;

        SiSDK3::ISiAllocator* field_8;
        u32 field_10;
    };

    virtual ~ISiIOBinaryArchive();
    UNK_REFCOUNT_DECLARE;

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
};

}  // namespace SiSDK3

// 0x71004f1020 (vf2), 0x71004f1040 (vf3)
#line 211
UNK_REFCOUNT_DEFINE(SiSDK3::ISiIOBinaryArchive::ChunkHandler, field_8, field_10)

// 0x710057c6b0 (vf2), 0x710057c6d0 (vf3)
#line 112
UNK_REFCOUNT_DEFINE(SiSDK3::ISiIOBinaryArchive, field_8, field_10)
