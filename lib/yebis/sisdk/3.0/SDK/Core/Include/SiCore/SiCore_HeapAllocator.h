// SiSDK3::SiHeapAllocator (RTTI): the allocator over SiSDK3::SiMemorySystem,
// the process's heap. Placeholder members. The reference counts are defined
// in this header (their __FILE__), at the original's lines, for the file that
// asks with UNK_SIHEAPALLOCATOR_DEFINE (SiCore_HeapAllocator.cpp).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

struct Unk_4be540_arg1;

namespace SiSDK3 {

class SiHeapAllocator {
public:
    // what the allocator tells about a failed allocation
    class Unk_Handler {
    public:
        virtual void vf0();
        virtual void vf1();
        virtual void vf2();
        virtual void vf3();
        virtual void vf4();
        virtual void vf5(SiHeapAllocator* pAllocator, size_t elementSize, size_t count, int alignment,
                         const char* file, int line);
    };

    SiHeapAllocator();           // 0x71004c2d70
    virtual ~SiHeapAllocator();  // 0x71004c2db0, 0x71004c2e00
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual u32 vf5(u32 value);
    virtual u32 vf6();
    virtual void* vf7(size_t size, int alignment, const char* file, int line);                       // 0x71004c2e70
    virtual void* vf8(size_t elementSize, size_t count, int alignment, const char* file, int line);  // 0x71004c2f10
    virtual void vf9(void* p, const char* file, int line);                                           // 0x71004c2fc0
    virtual size_t vf10(void* p);                                                                    // 0x71004c3050
    virtual void vf11(Unk_4be540_arg1* value);                                                       // 0x71004c3080
    virtual void vf12(u64 value);                                                                    // 0x71004c30b0
    virtual u64 vf13();                                                                              // 0x71004c30e0
    virtual void vf14(u64 value);                                                                    // 0x71004c3100
    virtual u64 vf15();                                                                              // 0x71004c3130
    virtual size_t vf16(void* p);                                                                    // 0x71004c3150
    virtual u64 vf17();                                                                              // 0x71004c3180
    virtual void vf18(u64 number);                                                                   // 0x71004c31a0
    virtual void vf19(Unk_Handler* handler);                                                         // 0x71004c31d0
    virtual u64 vf20();

    Unk_4bf660 field_8;
    int field_18;  // the alignment of an allocation that gives none
    Unk_Handler* field_20;
};
PKMN_SIZE_ASSERT(SiHeapAllocator, 0x28);

}  // namespace SiSDK3

#ifdef UNK_SIHEAPALLOCATOR_DEFINE
// 0x71004c3230 (vf2), 0x71004c3250 (vf3)
#line 33
UNK_REFCOUNT_DEFINE(SiSDK3::SiHeapAllocator, field_8.m_pAllocator, field_8.m_count)
#endif
