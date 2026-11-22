// SiSDK3::SiOSKernel (RTTI names the class): SiOS's kernel, the same shape as
// SiIOKernel and SiMathKernel, with a shared memory factory and three
// reference-counted objects more. Placeholder members; the virtual functions
// are vf<slot>. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIOS_KERNEL_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

namespace SiSDK3 {

class SiOSSharedMemory;

class SiOSKernel {
public:
    // 0x71005959e0
    SiOSKernel();
    virtual ~SiOSKernel();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5(ISiAllocator* pAllocator);  // sets the allocator
    virtual ISiAllocator* vf6();                 // the allocator
    virtual u64 vf7();
    virtual SiOSSharedMemory* vf8(ISiAllocator* pAllocator);  // a shared memory object
    virtual bool vf9(ISiInterface* object);                 // sets field_38
    virtual u64 vf10();
    virtual bool vf11(s32 index, ISiInterface* object);  // sets field_40 (0) or field_48 (1)
    virtual ISiInterface* vf12(s32 index);

    // 0x7100595c00: its initialisation, 0x7100595cc0: a part of it,
    // 0x7100595ae0: the reverse
    bool Unk_595c00(ISiAllocator* pAllocator);
    bool Unk_595cc0();
    void Unk_595ae0();

    Unk_4bf660 field_8;
    ISiAllocator* field_18;
    volatile u32 field_20;  // how many times it was initialised (read again after it's stored)
    u64 field_28;
    Unk_StringTableInterface* field_30;  // its string table
    ISiInterface* field_38;
    ISiInterface* field_40;
    ISiInterface* field_48;
};
PKMN_SIZE_ASSERT(SiOSKernel, 0x50);

}  // namespace SiSDK3

#ifdef UNK_SIOS_KERNEL_IMPL
// 0x7100595fa0 (vf2), 0x7100595fc0 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiOSKernel, field_8.m_pAllocator, field_8.m_count)
#endif
