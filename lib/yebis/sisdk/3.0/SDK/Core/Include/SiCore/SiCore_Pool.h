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
        explicit DataArray(ISiAllocator* pAllocator)
            : field_0(pAllocator), field_8(0), field_c(0), m_items(pAllocator) {}

        ISiAllocator* field_0;
        int field_8;  // the index of its first T in the pool
        int field_c;  // how many of its T's are used
        SiArray<T, ALIGN> m_items;
    };

    SiPool() : m_pAllocator(nullptr), m_firstBlock(nullptr), field_110(0), field_118(0), field_120(false) {
        field_121[0] = true;
        for (int i = 1; i < 7; i++) {
            field_121[i] = false;
        }
        m_pAllocator = Unk_4bc640();
    }
    // 0x7100534070 (SiGfxResourcePool::ResourceItem; its row has the complete
    // constructor's name, C1, which its callers use: check.py reads the base
    // variant only out of names without template arguments)
    SiPool(ISiAllocator* pAllocator, bool flag);
    virtual ~SiPool();
    // 0x71004bd0e0, 0x71004fe710 (SiGfxResourcePool::ResourceItem): the first
    // block's T's, count of them, and as many per block from then on
    virtual bool vf2(size_t count);
    // 0x71004be7d0: frees every block but the first, and empties the lists
    // (not written yet: its loop keeps other base registers than this
    // reconstruction does)
    virtual void Unk_4be7d0();
    virtual void Unk_4bd7e0();
    // 0x71004bec50: makes room for count T's
    virtual bool vf5(size_t count);

    // 0x71004bcfa0: empties the pool for another allocator
    void Unk_4bcfa0(ISiAllocator* pAllocator);
    // 0x71004be3f0: returns a T to the free list
    void Unk_4be3f0(T* item);

    // a free T, after making room for more if there's none (inline in every
    // caller: placeholder name)
    T* Unk_Alloc() {
        if (m_freeList.m_count == 0) {
            size_t count = field_118 * 2;
            if (count == 0) {
                count = field_120 ? 2 : 1;
            }
            vf5(count);
            if (m_freeList.m_count == 0) {
                return nullptr;
            }
        }
        T* item = m_freeList.RemoveHead();
        m_usedList.AddTail(item);
        item->field_18 = true;
        size_t index = item->field_10 / field_110;
        m_blocks.m_pData[index]->field_c++;
        return item;
    }

    // the T of an index (inline in every caller: placeholder name)
    T* Unk_Get(size_t index) {
        size_t block = index / field_110;
        size_t offset = index % field_110;
        return &m_blocks.m_pData[block]->m_items.m_pData[offset];
    }

    ISiAllocator* m_pAllocator;
    SiDirectLinkedList<T*> m_freeList;
    SiDirectLinkedList<T*> m_usedList;
    SiArray<DataArray*, ALIGN> m_blocks;
    DataArray m_firstBlock;
    size_t field_110;  // T's per block
    size_t field_118;  // T's in all blocks
    bool field_120;
    bool field_121[7];
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

// The member functions that make and number T's need the whole of T: only
// for the files that ask (they define T; the others give T only its links).
#ifdef UNK_SIPOOL_WHOLE_ELEMENT

template <class T, int ALIGN>
SiPool<T, ALIGN>::SiPool(ISiAllocator* pAllocator, bool flag)
    : m_pAllocator(pAllocator), m_freeList(pAllocator), m_usedList(pAllocator), m_blocks(pAllocator),
      m_firstBlock(pAllocator), field_110(0), field_118(0), field_120(false) {
    field_121[0] = flag;
    for (int i = 1; i < 7; i++) {
        field_121[i] = false;
    }
    if (pAllocator == nullptr) {
        m_pAllocator = Unk_4bc640();
    }
}

template <class T, int ALIGN>
bool SiPool<T, ALIGN>::vf2(size_t count) {
    if (!m_blocks.Unk_SetCount(1)) {
        return false;
    }
    field_110 = count;
    field_118 = count;
    m_blocks.m_pData[0] = &m_firstBlock;
    m_blocks.m_pData[0]->m_items.Unk_SetCount(count);
    for (s64 i = 0; i < static_cast<s64>(count); i++) {
        T* item = &m_blocks.m_pData[0]->m_items.m_pData[i];
        item->field_10 = i;
        if (i == 0 && field_120) {
            continue;
        }
        m_freeList.AddTail(item);
    }
    return true;
}

template <class T, int ALIGN>
bool SiPool<T, ALIGN>::vf5(size_t count) {
    if (field_118 == count) {
        return true;
    }
    if (field_118 > count || field_110 == 0) {
        return false;
    }
    int blockCount = static_cast<int>(count + (static_cast<int>(field_110) - 1)) / static_cast<int>(field_110);
    int oldBlockCount = static_cast<int>(m_blocks.m_itemCount);
    if (blockCount == oldBlockCount) {
        return true;
    }
    if (!m_blocks.Unk_SetCount(blockCount)) {
        return false;
    }
    int index = static_cast<int>(field_110) * oldBlockCount;
    for (s64 i = oldBlockCount; i < blockCount; i++) {
#line 541
        DataArray* block = UNK_SI_NEW(m_pAllocator, ALIGN) DataArray(m_pAllocator);
        if (block == nullptr) {
            return false;
        }
        m_blocks.m_pData[i] = block;
        block->field_8 = index;
        block->m_items.Unk_SetCount(field_110);
        for (s64 j = 0; j < static_cast<s64>(field_110); j++) {
            T* item = &block->m_items.m_pData[j];
            item->field_10 = index + j;
            item->m_pNext = nullptr;
            item->field_18 = false;
            item->m_pPrev = nullptr;
            m_freeList.AddTail(item);
        }
        index += static_cast<int>(field_110);
    }
    field_118 = field_110 * blockCount;
    return true;
}

template <class T, int ALIGN>
void SiPool<T, ALIGN>::Unk_4bcfa0(ISiAllocator* pAllocator) {
    Unk_4be7d0();
    m_freeList.Unk_SetAllocator(pAllocator);
    m_usedList.Unk_SetAllocator(pAllocator);
    m_blocks.Unk_SetAllocator(pAllocator);
    m_firstBlock.field_0 = pAllocator;
    m_firstBlock.m_items.Unk_SetAllocator(pAllocator);
    m_pAllocator = pAllocator;
    field_120 = false;
}

template <class T, int ALIGN>
void SiPool<T, ALIGN>::Unk_4be3f0(T* item) {
    m_usedList.Remove(item);
    m_freeList.AddTail(item);
    item->field_18 = false;
    size_t index = item->field_10 / field_110;
    m_blocks.m_pData[index]->field_c--;
}

#endif  // UNK_SIPOOL_WHOLE_ELEMENT

}  // namespace SiSDK3
