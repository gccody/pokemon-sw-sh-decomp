// SiSDK3::SiMathKernel (RTTI names the class): SiMath's kernel, the same
// shape as SiIOKernel. Placeholder members; the virtual functions are
// vf<slot>. The reference counts are defined in this header (their __FILE__),
// at the original's lines, for the class's own translation unit
// (UNK_SIMATH_KERNEL_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiMathKernel {
public:
    // 0x7100594840
    SiMathKernel();
    virtual ~SiMathKernel();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5(ISiAllocator* pAllocator);  // sets the allocator
    virtual ISiAllocator* vf6();                 // the allocator
    virtual u64 vf7();

    // 0x7100594960: its initialisation, 0x7100594a20: a part of it
    bool Unk_594960(ISiAllocator* pAllocator);
    bool Unk_594a20();

    Unk_4bf660 field_8;
    ISiAllocator* field_18;
    volatile u32 field_20;  // how many times it was initialised (read again after it's stored)
    u64 field_28;
    u64 field_30;
};
PKMN_SIZE_ASSERT(SiMathKernel, 0x38);

}  // namespace SiSDK3

#ifdef UNK_SIMATH_KERNEL_IMPL
// 0x7100594c00 (vf2), 0x7100594c20 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiMathKernel, field_8.m_pAllocator, field_8.m_count)
#endif
