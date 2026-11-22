// SiSDK3::SiGfxNXCommandQueue (RTTI names the class; it derives from
// ISiGfxNXCommandQueue, ISiGfxCommandQueue and ISiInterface): an NVN queue
// and the syncs its fences use. Placeholder members; the virtual functions
// are vf<slot>. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_COMMANDQUEUE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

// NVN's sync object (RTTI names it: the queue has an array of them).
struct NVNsync {
    u64 reserved[8];
};

namespace SiSDK3 {

class SiGfxNXCommandList;

class SiGfxNXCommandQueue : public Unk_NXInterface {
public:
    SiGfxNXCommandQueue(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054d9d0
    ~SiGfxNXCommandQueue() override;                                        // 0x710054da70, 0x710054dd60
    u32 vf2() override;                                                     // 0x710054e5c0
    u32 vf3() override;                                                     // 0x710054e5e0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual bool vf8();  // 0x710054e300: clears what it counted
    virtual u64 vf9();
    virtual bool vf10(s32 count, SiGfxNXCommandList** lists);  // 0x710054e330: submits command lists
    virtual void vf11();
    virtual u32 vf12();            // 0x710054e4a0: a fence; its sync's index
    virtual bool vf13(u64 fence);  // 0x710054e520: waits for a fence (its low 32 bits: the sync's index)
    virtual u32 vf14();
    virtual void vf15();  // 0x710054e5a0
    virtual u64 vf16();

    // 0x710054db30: releases the queue
    void Unk_54db30();
    // 0x710054de30: makes the queue
    bool Unk_54de30();
    // 0x710054e070: makes the syncs
    bool Unk_54e070();

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;      // the next fence's sync
    u32 field_24[10];  // what the submitted command lists counted
    u64 field_50[0x400];  // NVNqueue
    SiArray<NVNsync, 16> field_2050;
    void* field_20a0;  // the queue's memory
    bool field_20a8;   // whether the queue is made
};
PKMN_OFFSET_ASSERT(SiGfxNXCommandQueue, field_50, 0x50);
PKMN_OFFSET_ASSERT(SiGfxNXCommandQueue, field_2050, 0x2050);
PKMN_SIZE_ASSERT(SiGfxNXCommandQueue, 0x20b0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_COMMANDQUEUE_IMPL
// 0x710054e5c0 (vf2), 0x710054e5e0 (vf3)
#line 37
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXCommandQueue, field_8.m_pAllocator, field_8.m_count)
#endif
