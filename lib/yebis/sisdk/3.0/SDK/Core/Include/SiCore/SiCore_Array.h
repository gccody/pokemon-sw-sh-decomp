// SiSDK3's dynamic array, reconstructed from its instances in YEBIS (RTTI:
// SiSDK3::SiArray<T, 16>). Member names in asserts (m_itemCount,
// m_reservedCount) and __func__ are the original's; the other members are
// placeholders, Unk_<addr> after the lowest address an instance of a member
// function has. The original header's __LINE__s (the allocator's file/line
// arguments) are kept with #line.
#pragma once

#include "SiCore_Memory.h"

namespace SiSDK3 {

template <class T, int ALIGN = 16>
class SiArray {
public:
    SiArray()
        : m_pAllocator(nullptr), m_itemCount(0), m_reservedCount(0), field_20(sizeof(T)), m_pData(nullptr),
          field_30(nullptr), field_38(nullptr), field_40(0), field_48(0) {
        m_pAllocator = Unk_4bc640();
    }

    virtual ~SiArray() { Unk_4e3050(); }

    // 0x71004bf190 (8-byte elements): makes room for count elements, keeping
    // the first ones if keep
    bool Unk_4bf190(size_t count, bool keep);
    // the buffer's array delete, unless it isn't the array's own (inline in
    // every caller: placeholder name)
    void Unk_FreeData();
    // 0x71004e3050: frees the buffer and empties the array
    void Unk_4e3050();

    ISiAllocator* m_pAllocator;
    size_t m_itemCount;
    size_t m_reservedCount;
    size_t field_20;  // sizeof(T)
    T* m_pData;
    T* field_30;
    T* field_38;
    size_t field_40;
    u64 field_48;  // bit 0: m_pData isn't the array's own (not freed)
};

// Defined outside the class without `inline`, like the original's (inlined
// only where the plain threshold allows: SiArray<RollingPerfData<float>>'s
// destructor calls 0x71004e3050).
template <class T, int ALIGN>
bool SiArray<T, ALIGN>::Unk_4bf190(size_t count, bool keep) {
    if (m_reservedCount == count) {
        return true;
    }
    if (count == 0) {
        Unk_4e3050();
        return true;
    }
    if (m_pAllocator == nullptr) {
        return false;
    }
    size_t itemCount = m_itemCount;
#line 1489
    T* pData = SI_NEW_ARRAY(m_pAllocator, T, count, ALIGN);
    size_t n = itemCount > count ? count : itemCount;
    if (pData == nullptr) {
        return false;
    }
    if (n != 0 && keep) {
        for (size_t i = 0; i < n; i++) {
            pData[i] = m_pData[i];
        }
    }
    Unk_FreeData();
    field_48 = 0;
    m_pData = pData;
    field_30 = nullptr;
    field_38 = nullptr;
    m_itemCount = n;
    m_reservedCount = count;
    return true;
}

template <class T, int ALIGN>
void SiArray<T, ALIGN>::Unk_FreeData() {
    if (!(field_48 & 1) && m_pData != nullptr) {
        ISiAllocator* pAllocator = m_pAllocator;
        T* pData = m_pData;
#line 1522
        SI_DELETE_ARRAY(pAllocator, pData);
        m_pData = nullptr;
    }
}

template <class T, int ALIGN>
void SiArray<T, ALIGN>::Unk_4e3050() {
    Unk_FreeData();
    m_itemCount = 0;
    m_reservedCount = 0;
    m_pData = nullptr;
    field_30 = nullptr;
    field_38 = nullptr;
    field_48 = 0;
}

}  // namespace SiSDK3

PKMN_SIZE_ASSERT(SiSDK3::SiArray<void*>, 0x50);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, m_itemCount, 0x10);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, m_pData, 0x28);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, field_48, 0x48);
