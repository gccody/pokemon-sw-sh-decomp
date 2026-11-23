// SiSDK3::SiGfxDisplayUtility: what keeps the display adapters. As far as the
// executable's functions show it, with placeholder members (RTTI names the
// classes). The reference counts are defined in this header (their
// __FILE__), at the original's lines. vf4 and vf5 are lib/yebis/class's.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

// RTTI: SiSDK3::SiGfxDisplayAdapter (the array's element). The slots
// SiGfxDisplayUtility calls; placeholder names.
class SiGfxDisplayAdapter {
public:
    virtual ~SiGfxDisplayAdapter();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual s32 vf9(void* a1);
};

class SiGfxDisplayUtility {
public:
    explicit SiGfxDisplayUtility(ISiAllocator* pAllocator);
    virtual ~SiGfxDisplayUtility();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual u32 vf5();
    virtual SiGfxDisplayAdapter* vf6(s32 index);  // 0x71004d2f10
    virtual SiGfxDisplayAdapter* vf7(s32 index);  // 0x71004d2f20
    virtual s32 vf8(s32 index, void* a2);         // 0x71004d2f30

    // 0x71004d2e50: releases the adapters
    bool Unk_4d2e50();

    Unk_4bf660 field_8;
    SiArray<SiGfxDisplayAdapter*, 16> field_18;
};
PKMN_SIZE_ASSERT(SiGfxDisplayUtility, 0x68);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_DISPLAYUTILITY_IMPL
// 0x71004d2f70 (vf2), 0x71004d2f90 (vf3)
#line 33
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxDisplayUtility, field_8.m_pAllocator, field_8.m_count)
#endif
