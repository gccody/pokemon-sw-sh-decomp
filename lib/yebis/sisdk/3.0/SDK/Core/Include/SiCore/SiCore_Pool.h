// SiSDK3's object pool, reconstructed from its instances in YEBIS (RTTI:
// SiSDK3::SiPool<T, 16>): T's come from blocks (DataArray, RTTI-named as the
// element of SiArray<SiPool<T, 16>::DataArray*, 16>), the first one inside
// the pool, and are linked into a free and a used list. Placeholder members;
// the original header's __LINE__s are kept with #line.
#pragma once

#include "SiCore_Array.h"
#include "SiCore_LinkedList.h"

namespace SiSDK3 {

template <class T, int ALIGN = 16>
class SiPool {
public:
    // a block of T's
    struct DataArray {
        ISiAllocator* field_0;
        int field_8;  // the index of its first T in the pool
        int field_c;  // how many of its T's are used
        SiArray<T, ALIGN> m_items;
    };

    // 0x7100534070 (SiGfxResourcePool::ResourceItem; its row has the complete
    // constructor's name, C1, which its callers use: check.py reads the base
    // variant only out of names without template arguments)
    SiPool(ISiAllocator* pAllocator, bool flag);
    virtual ~SiPool();
    // 0x71004fe710 (SiGfxResourcePool::ResourceItem): makes room for count T's
    virtual bool vf2(size_t count);
    // 0x71004be7d0: frees every block but the first, and empties the lists
    // (not written yet: its loop keeps other base registers than this
    // reconstruction does)
    virtual void Unk_4be7d0();
    virtual void Unk_4bd7e0();

    ISiAllocator* m_pAllocator;
    SiDirectLinkedList<T*> m_freeList;
    SiDirectLinkedList<T*> m_usedList;
    SiArray<DataArray*, ALIGN> m_blocks;
    DataArray m_firstBlock;
    size_t field_110;  // T's per block
    size_t field_118;  // T's in all blocks
    bool field_120;
};

template <class T, int ALIGN>
SiPool<T, ALIGN>::~SiPool() {
    Unk_4be7d0();
}

// 0x71004bd7e0: returns every used T to the free list
template <class T, int ALIGN>
void SiPool<T, ALIGN>::Unk_4bd7e0() {
    for (T* item = m_usedList.m_pHead; item != nullptr;) {
        T* next = item->m_pNext;
        m_usedList.Remove(item);
        m_freeList.AddTail(item);
        item->field_18 = false;
        item = next;
    }
    for (int i = 0; i < static_cast<int>(m_blocks.m_itemCount); i++) {
        m_blocks.m_pData[i]->field_c = 0;
    }
}

}  // namespace SiSDK3
