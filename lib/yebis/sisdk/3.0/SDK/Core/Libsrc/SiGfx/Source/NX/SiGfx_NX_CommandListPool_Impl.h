// SiSDK3::SiGfxNXCommandListPool (RTTI names the class; it derives from
// ISiGfxNXCommandListPool, ISiGfxCommandListPool and ISiInterface): command
// lists made ahead and handed out one after the other. Placeholder members;
// the virtual functions are vf<slot>. The reference counts are defined in
// this header (their __FILE__), at the original's lines, for the class's own
// translation unit (UNK_SIGFX_NX_COMMANDLISTPOOL_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

class SiGfxNXCommandList;

class SiGfxNXCommandListPool : public Unk_NXInterface {
public:
    SiGfxNXCommandListPool(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054f170
    ~SiGfxNXCommandListPool() override;                                        // 0x710054f1f0, 0x710054f340
    u32 vf2() override;                                                        // 0x710054f6d0
    u32 vf3() override;                                                        // 0x710054f6f0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual bool vf8(s32 count);         // 0x710054f460: makes its command lists
    virtual SiGfxNXCommandList* vf9();   // 0x710054f5d0: the next one
    virtual u32 vf10();
    virtual u64 vf11();
    virtual void vf12();  // 0x710054f650: waits for the ones handed out
    virtual u32 vf13();

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;
    SiArray<SiGfxNXCommandList*, 16> field_28;
    s32 field_78;  // how many are handed out
};
PKMN_SIZE_ASSERT(SiGfxNXCommandListPool, 0x80);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_COMMANDLISTPOOL_IMPL
// 0x710054f6d0 (vf2), 0x710054f6f0 (vf3)
#line 38
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXCommandListPool, field_8.m_pAllocator, field_8.m_count)
#endif
