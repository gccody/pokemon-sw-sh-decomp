// SiSDK3::SiIOCodecZLib (RTTI names the class): zlib as one of SiIO's codecs.
// Placeholder members. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIIO_CODEC_ZLIB_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiIOCodecZLib {
public:
    explicit SiIOCodecZLib(ISiAllocator* pAllocator);
    virtual ~SiIOCodecZLib();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual s64 vf5(const void* src, s64 size);                             // the room a block's compression needs
    virtual bool vf6(const void* src, s64 size, void* dst, s64* dstSize);  // compresses
    virtual bool vf7(const void* src, s64 size, void* dst, s64 dstSize);   // decompresses

    Unk_4bf660 field_8;
};
PKMN_SIZE_ASSERT(SiIOCodecZLib, 0x18);

}  // namespace SiSDK3

#ifdef UNK_SIIO_CODEC_ZLIB_IMPL
// 0x710057df50 (vf2), 0x710057df70 (vf3)
#line 34
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOCodecZLib, field_8.m_pAllocator, field_8.m_count)
#endif
