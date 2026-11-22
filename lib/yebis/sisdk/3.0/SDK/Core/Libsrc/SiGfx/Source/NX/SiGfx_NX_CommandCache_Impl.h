// SiSDK3::SiGfxNXCommandCache (RTTI names the class; it derives from
// ISiGfxNXCommandCache, ISiGfxCommandCache and ISiInterface): an NVN command
// buffer with memory of its own. Placeholder members; the virtual functions
// are vf<slot>. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_COMMANDCACHE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

class SiGfxNXCommandCache : public Unk_NXInterface {
public:
    SiGfxNXCommandCache(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054d430
    ~SiGfxNXCommandCache() override;                                        // 0x710054d4a0, 0x710054d580
    u32 vf2() override;                                                     // 0x710054d880
    u32 vf3() override;                                                     // 0x710054d8a0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual void* vf8();  // the NVN command buffer
    virtual u64 vf9();

    // 0x710054d660: makes the command buffer and its memory
    bool Unk_54d660(u32 kind);

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;
    u64 field_28[20];  // NVNcommandBuffer
    u64 field_c8;
    SiGfxNXMemoryHeap* field_d0;  // where its command memory is
    void* field_d8;               // its control memory
    s64 field_e0;                 // the command memory's room in the heap
    s64 field_e8;                 // its aligned offset
    bool field_f0;                // whether the command buffer is made
};
PKMN_OFFSET_ASSERT(SiGfxNXCommandCache, field_28, 0x28);
PKMN_SIZE_ASSERT(SiGfxNXCommandCache, 0xf8);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_COMMANDCACHE_IMPL
// 0x710054d880 (vf2), 0x710054d8a0 (vf3)
#line 37
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXCommandCache, field_8.m_pAllocator, field_8.m_count)
#endif
