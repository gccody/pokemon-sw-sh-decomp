// SiSDK3::SiGfxNXCommandList (RTTI names the class; it derives from
// ISiGfxNXCommandList, ISiGfxCommandList and ISiInterface): an NVN command
// buffer whose command memory comes from memory heaps and whose control
// memory from the allocator, both growing when NVN runs out of them.
// Placeholder members; the virtual functions are vf<slot>. The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit
// (UNK_SIGFX_NX_COMMANDLIST_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

class SiGfxNXCommandList : public Unk_NXInterface {
public:
    // Control memory that NVN replaced while it recorded (RTTI names the
    // type): kept until the commands are done with.
    struct OverwrittenEntry {
        SiGfxNXMemoryHeap* field_0;
        void* field_8;  // the control memory
    };
    // The same once the recording has ended, with the sync object that tells
    // when the GPU is past it (RTTI names the type).
    struct DiscontinuedEntry {
        SiGfxNXMemoryHeap* field_0;
        void* field_8;
        u64 field_10[8];  // NVNsync
    };
    // What slots 12 and 13 return (placeholder name).
    struct Unk_Counts {
        u32 field_0[10];
    };

    SiGfxNXCommandList(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice, void* pPool);  // 0x7100539920
    ~SiGfxNXCommandList() override;                                                     // 0x7100539a80, 0x7100539fd0
    u32 vf2() override;                                                                 // 0x710053ab20
    u32 vf3() override;                                                                 // 0x710053ab40
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual bool vf7(const char* name);  // 0x710053a660
    virtual const SiString<char>* vf8();
    virtual void* vf9();  // the pool it's from
    virtual void* vf10();
    virtual u32 vf11();
    virtual const Unk_Counts* vf12();
    virtual Unk_Counts* vf13();
    virtual bool vf14();
    virtual void* vf15();  // the NVN command buffer
    virtual u64 vf16();    // the handle of what it recorded
    virtual void vf17();   // 0x710053a6f0: gives the command buffer its first memory again
    virtual bool vf18(void* commandBuffer);  // 0x710053aac0: records into another's command buffer

    // 0x7100539c40: releases the command buffer and its memory
    void Unk_539c40();
    // 0x710053a000: makes the command buffer and its memory
    bool Unk_53a000(u32 kind);
    // 0x710053a310: NVN's callback for a command buffer that is out of
    // command (0) or control (1) memory
    static void Unk_53a310(void* commandBuffer, int event, size_t minSize, void* data);
    // 0x710053a790: ends the recording
    void Unk_53a790();

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    SiString<char> field_20;  // the name
    void* field_50;           // the pool it's from
    SiOSMutex field_58;
    u32 field_80;
    void* field_88;  // the NVN command buffer
    u64 field_90;    // the handle of what it recorded
    SiArray<SiGfxNXMemoryHeap*, 16> field_98;  // where its command memory is
    s32 field_e8;                              // which of them is in use
    void* field_f0;                            // its control memory
    s64 field_f8;                              // the command memory's room in the heap
    s64 field_100;                             // its aligned offset
    size_t field_108;                          // the control memory's size
    size_t field_110;                          // the command memory's size
    int field_118;                             // the control memory's alignment
    int field_11c;                             // the command memory's alignment
    bool field_120;                            // whether the command buffer is made
    bool field_121;                            // whether the command buffer is another's
    Unk_Counts field_124;
    volatile s32 field_14c;  // how many times it's in use
    SiArray<OverwrittenEntry, 16> field_150;
    SiArray<DiscontinuedEntry, 16> field_1a0;
};
PKMN_OFFSET_ASSERT(SiGfxNXCommandList, field_50, 0x50);
PKMN_OFFSET_ASSERT(SiGfxNXCommandList, field_80, 0x80);
PKMN_OFFSET_ASSERT(SiGfxNXCommandList, field_98, 0x98);
PKMN_OFFSET_ASSERT(SiGfxNXCommandList, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(SiGfxNXCommandList, field_124, 0x124);
PKMN_OFFSET_ASSERT(SiGfxNXCommandList, field_150, 0x150);
PKMN_SIZE_ASSERT(SiGfxNXCommandList, 0x1f0);
PKMN_SIZE_ASSERT(SiGfxNXCommandList::OverwrittenEntry, 0x10);
PKMN_SIZE_ASSERT(SiGfxNXCommandList::DiscontinuedEntry, 0x50);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_COMMANDLIST_IMPL
// 0x710053ab20 (vf2), 0x710053ab40 (vf3)
#line 39
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXCommandList, field_8.m_pAllocator, field_8.m_count)
#endif
