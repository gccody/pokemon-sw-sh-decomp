// SiSDK3::SiOSSharedMemory (RTTI names the class): as far as the executable's
// functions show it, with placeholder members; the virtual functions are
// vf<slot>. The reference counts are defined in this header (their __FILE__),
// at the original's lines, for the class's own translation unit
// (UNK_SIOS_SHAREDMEMORY_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiOSSharedMemory {
public:
    // 0x71005960d0
    explicit SiOSSharedMemory(ISiAllocator* pAllocator);
    virtual ~SiOSSharedMemory();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();  // unmaps: one user less
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();

    Unk_4bf660 field_8;
    u64 field_18;
    s32 field_20;  // how many users have it mapped
    u64 field_28;
};
PKMN_SIZE_ASSERT(SiOSSharedMemory, 0x30);

}  // namespace SiSDK3

#ifdef UNK_SIOS_SHAREDMEMORY_IMPL
// 0x71005962e0 (vf2), 0x7100596300 (vf3)
#line 31
UNK_REFCOUNT_DEFINE(SiSDK3::SiOSSharedMemory, field_8.m_pAllocator, field_8.m_count)
#endif
