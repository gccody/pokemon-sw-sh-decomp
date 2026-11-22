// SiSDK3::SiGfxNXQuery (RTTI names the class; it derives from ISiGfxNXQuery,
// ISiGfxQuery and ISiGfxResource, which is on ISiInterface and, at 8,
// ISiNamedObject): a query's results in an NVN buffer of its own memory heap.
// Placeholder members; the virtual functions are vf<slot>. The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit (UNK_SIGFX_NX_QUERY_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the query's slots 20 to 22.
UNK_NAMED_OBJECT(Unk_NXQueryNamedObject, vf20, vf21, vf22);

class SiGfxNXQuery : public Unk_NXInterface, public Unk_NXQueryNamedObject {
public:
    // What slot 18 takes and slot 17 returns (placeholder name).
    struct Unk_Desc {
        u32 field_0;
        u32 field_4;
        u32 field_8;  // the results' size
        u32 field_c;
    };

    SiGfxNXQuery(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100554870
    ~SiGfxNXQuery() override;                                        // 0x7100554900, 0x7100554a40
    u32 vf2() override;                                              // 0x7100554f90
    u32 vf3() override;                                              // 0x7100554fb0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual size_t vf7();  // its index in the pool
    virtual const Unk_NXResourceInfo* vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
    virtual const Unk_Desc* vf17();
    virtual bool vf18(const Unk_Desc* desc);      // 0x7100554d00: makes the buffer
    virtual void vf19();                          // 0x7100554ef0: releases it
    bool vf20(const char* name) override;         // 0x7100554b90
    const SiString<char>* vf21() override;        // 0x7100554c10
    u32 vf22() override;                          // 0x7100554c30

    Unk_4bf660 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    Unk_Desc field_78;
    u64 field_88[6];  // NVNbuffer
    u64 field_b8;     // its address
    SiGfxNXMemoryHeap* field_c0;
    s64 field_c8;  // the buffer's room in the heap
    s64 field_d0;  // its aligned offset
    u8 field_d8[0x80];
    bool field_158;  // whether the buffer is made
};
PKMN_OFFSET_ASSERT(SiGfxNXQuery, field_64, 0x64);
PKMN_OFFSET_ASSERT(SiGfxNXQuery, field_88, 0x88);
PKMN_OFFSET_ASSERT(SiGfxNXQuery, field_c0, 0xc0);
PKMN_SIZE_ASSERT(SiGfxNXQuery, 0x160);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_QUERY_IMPL
// 0x7100554f90 (vf2), 0x7100554fb0 (vf3)
#line 37
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXQuery, field_10.m_pAllocator, field_10.m_count)
#endif
