// SiSDK3::SiFixedHeapAllocator2 (RTTI names it, its MemoryBlockHeader,
// MemoryBlockPtr and MemoryBlockHeaderPool): an allocator over fixed regions
// of memory, whose blocks' headers come from a pool. Placeholder members. The
// reference counts are defined in this header (their __FILE__), at the
// original's lines.
#pragma once

// (this file defines the pool's element)
#define UNK_SIPOOL_WHOLE_ELEMENT

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_CriticalSection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Pool.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

struct Unk_4be540_arg1;

namespace SiSDK3 {

class SiFixedHeapAllocator2 {
public:
    struct MemoryBlockHeader;

    // a block's link in one of the allocator's lists
    struct MemoryBlockPtr {
        // an unlinked block's
        void Unk_Set(MemoryBlockHeader* pHeader) {
            m_pHeader = pHeader;
            m_pPrev = nullptr;
            m_pNext = nullptr;
        }

        MemoryBlockPtr* m_pPrev;
        MemoryBlockPtr* m_pNext;
        MemoryBlockHeader* m_pHeader;
    };

    struct MemoryBlockHeader {
        MemoryBlockHeader()
            : m_pPrev(nullptr), m_pNext(nullptr), field_10(static_cast<size_t>(-1)), field_18(false),
              field_50(reinterpret_cast<u8*>(this + 1)), field_58(nullptr), field_60(0), field_68(0), field_70(0),
              field_78(0), field_80(0), field_84(0), field_88(nullptr) {
            field_20.Unk_Set(this);
            field_38.Unk_Set(this);
        }

        // an unlinked block of nothing
        void Unk_Reset() {
            field_20.m_pHeader = this;
            field_20.m_pPrev = nullptr;
            field_20.m_pNext = nullptr;
            field_38.m_pPrev = nullptr;
            field_38.m_pNext = nullptr;
            field_38.m_pHeader = this;
            field_50 = nullptr;
            field_58 = nullptr;
            field_60 = 0;
            field_68 = 0;
            field_70 = 0;
            field_78 = 0;
            field_80 = 0;
            field_84 = 0;
            field_88 = nullptr;
        }

        // the pool's
        MemoryBlockHeader* m_pPrev;
        MemoryBlockHeader* m_pNext;
        size_t field_10;
        bool field_18;
        MemoryBlockPtr field_20;  // in the list of every block
        MemoryBlockPtr field_38;  // in the list of the free ones
        u8* field_50;             // the block's memory
        u8* field_58;             // what was allocated in it: null for a free block
        size_t field_60;          // the block's size
        size_t field_68;          // the allocation's size
        size_t field_70;          // the allocation's element count
        u64 field_78;             // bit 0: a region's first block
        int field_80;             // the allocation's number
        int field_84;             // its line
        const char* field_88;     // its file
    };

    class MemoryBlockHeaderPool : public SiPool<MemoryBlockHeader, 16> {
    public:
        MemoryBlockHeaderPool() : field_128(nullptr) {}
        ~MemoryBlockHeaderPool() override {}
        bool vf5(size_t count) override;  // 0x71004bc7f0

        SiFixedHeapAllocator2* field_128;  // the allocator
    };

    // a region of memory
    struct Unk_Region {
        u8* field_0;
        size_t field_8;
        u64 field_10;
    };

    // what the allocator tells about a failed allocation
    class Unk_Handler {
    public:
        virtual void vf0();
        virtual void vf1();
        virtual void vf2();
        virtual void vf3();
        virtual void vf4();
        virtual void vf5(SiFixedHeapAllocator2* pAllocator, size_t elementSize, size_t count, int alignment,
                         const char* file, int line);
    };

    // sorts blocks by their allocations' numbers
    struct Unk_Sorter {
        bool Unk_4be580(s64 count, MemoryBlockHeader** blocks);  // 0x71004be580
    };

    explicit SiFixedHeapAllocator2(ISiAllocator* pAllocator);  // 0x71004bca60
    virtual ~SiFixedHeapAllocator2();                          // 0x71004bcc40, 0x71004bcda0
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual u32 vf5(u32 value);
    virtual u32 vf6();
    virtual void* vf7(size_t size, int alignment, const char* file, int line);                         // 0x71004bd8e0
    virtual void* vf8(size_t elementSize, size_t count, int alignment, const char* file, int line);    // 0x71004bd900
    virtual void vf9(void* p, const char* file, int line);                                             // 0x71004bde60
    virtual size_t vf10(void* p);                                                                      // 0x71004be4c0
    virtual void vf11(Unk_4be540_arg1* value);
    virtual void vf12(u64 value);
    virtual u64 vf13();
    virtual void vf14(u64 value);
    virtual u64 vf15();
    virtual size_t vf16(void* p);  // 0x71004be700
    virtual u64 vf17();
    virtual void vf18(s64 number);           // 0x71004be730
    virtual void vf19(Unk_Handler* handler);  // 0x71004be740
    virtual u64 vf20();
    // 0x71004bcdd0: one region
    virtual bool vf21(ISiAllocator* pAllocator, int headerCount, u8* memory, size_t size);
    // 0x71004bd310: several
    virtual bool vf22(ISiAllocator* pAllocator, int headerCount, size_t regionCount, Unk_Region* regions);
    virtual void vf23();  // 0x71004bd550

    // 0x71004bd610: goes through the blocks allocated after number
    inline void Unk_4bd610(s64 number, bool arg2);

    Unk_4bf660 field_8;
    ISiAllocator* field_18;
    Unk_Region* field_20;  // the regions
    size_t field_28;       // how many
    size_t field_30;       // their sizes' sum
    u64 field_38;
    int field_40;  // the alignment of an allocation that gives none
    int field_44;
    Unk_Region field_48;
    u8* field_60;     // the lowest region
    size_t field_68;  // allocations so far
    size_t field_70;  // bytes allocated
    size_t field_78;  // the most there were
    u8* field_80;     // the highest end of a block
    s64 field_88;     // allocations now
    s64 field_90;     // the most there were
    s64 field_98;     // the largest
    s64 field_a0;
    s64 field_a8;
    s64 field_b0;
    Unk_Handler* field_b8;
    SiDirectLinkedList<MemoryBlockPtr*> field_c0;  // every block
    SiDirectLinkedList<MemoryBlockPtr*> field_e8;  // the free ones
    MemoryBlockHeaderPool field_110;
    u64 field_240[12];  // a SiCoreCriticalSection
    u64 field_2a0[4];

    ISiCriticalSection* Unk_CriticalSection() { return reinterpret_cast<ISiCriticalSection*>(field_240); }
};
PKMN_SIZE_ASSERT(SiFixedHeapAllocator2::MemoryBlockHeader, 0x90);
PKMN_SIZE_ASSERT(SiFixedHeapAllocator2, 0x2c0);
PKMN_OFFSET_ASSERT(SiFixedHeapAllocator2, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(SiFixedHeapAllocator2, field_110, 0x110);
PKMN_OFFSET_ASSERT(SiFixedHeapAllocator2, field_240, 0x240);

}  // namespace SiSDK3

// 0x71004be9d0 (vf2), 0x71004be9f0 (vf3)
#line 42
UNK_REFCOUNT_DEFINE(SiSDK3::SiFixedHeapAllocator2, field_8.m_pAllocator, field_8.m_count)
