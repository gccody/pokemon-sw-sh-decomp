// SiSDK3::SiGfxNXMemoryHeap (RTTI names the class; it derives from
// ISiGfxNXMemoryHeap and ISiGfxMemoryHeap, which is on ISiInterface and, at 8,
// ISiNamedObject): an NVN memory pool and the allocator that hands out its
// memory. Placeholder members; the virtual functions are vf<slot>. The
// reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_MEMORYHEAP_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_FixedHeapAllocator2.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the heap's slots 17 to 19.
UNK_NAMED_OBJECT(Unk_NXMemoryHeapNamedObject, vf17, vf18, vf19);

class SiGfxNXMemoryHeap : public Unk_NXInterface, public Unk_NXMemoryHeapNamedObject {
public:
    // What slot 7 returns (placeholder name): the heap as it was made.
    struct Unk_Info {
        u32 field_0;  // its size
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
    };
    // What 0x7100552f50 takes (placeholder name).
    struct Unk_552f50_Arg {
        u32 field_0;
        s32 field_4;  // a size
    };

    SiGfxNXMemoryHeap(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x71005528f0
    ~SiGfxNXMemoryHeap() override;                                        // 0x71005529a0, 0x7100552a90
    u32 vf2() override;                                                   // 0x7100553050
    u32 vf3() override;                                                   // 0x7100553070
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual const Unk_Info* vf7();
    virtual bool vf8(const Unk_NXMemoryHeapDesc* desc);  // 0x7100552bf0: makes the memory pool
    virtual void vf9();                                  // 0x7100552e70: releases it
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void* vf16();                      // the NVN memory pool
    bool vf17(const char* name) override;      // 0x7100552b00
    const SiString<char>* vf18() override;     // 0x7100552b80
    u32 vf19() override;                       // 0x7100552ba0

    // 0x7100552f50, 0x7100552fc0: room in the heap; its offset in the pool
    bool Unk_552f50(const Unk_552f50_Arg* arg, s64* offset);
    bool Unk_552fc0(s64 size, s64 alignment, s64* offset);
    // 0x7100553010: gives room back
    void Unk_553010(s64 offset);

    // (inline in both: placeholder name)
    inline bool Unk_Alloc(s64 size, s64* offset);

    Unk_4bf660 field_10;
    SiGfxNXDevice* field_20;
    SiString<char> field_28;  // the name
    u32 field_58;             // its hash
    Unk_Info field_5c;
    u32 field_74;    // the memory pool's flags
    bool field_78;   // whether the memory pool is made
    u64 field_80[0x20];  // NVNmemoryPool
    ISiAllocator* field_180;  // the memory's allocator
    SiFixedHeapAllocator2 field_188;
    u8* field_448;  // the memory
    void* field_450;  // where it's mapped
    u8* field_458;  // what offsets count from
};
PKMN_OFFSET_ASSERT(SiGfxNXMemoryHeap, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(SiGfxNXMemoryHeap, field_80, 0x80);
PKMN_OFFSET_ASSERT(SiGfxNXMemoryHeap, field_188, 0x188);
PKMN_SIZE_ASSERT(SiGfxNXMemoryHeap, 0x460);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_MEMORYHEAP_IMPL
// 0x7100553050 (vf2), 0x7100553070 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXMemoryHeap, field_10.m_pAllocator, field_10.m_count)
#endif
