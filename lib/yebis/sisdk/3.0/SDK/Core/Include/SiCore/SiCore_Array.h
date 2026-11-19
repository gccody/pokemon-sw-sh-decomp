// SiSDK3's dynamic array, reconstructed from its instances in YEBIS (RTTI:
// SiSDK3::SiArray<T, 16>). Member names in asserts (m_itemCount,
// m_reservedCount) and __func__ are the original's; the other members are
// placeholders. The original header's __LINE__s (the allocator's file/line
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

    virtual ~SiArray() { Release(); }

    void Release() {
        if (!(field_48 & 1) && m_pData != nullptr) {
            if (m_pAllocator != nullptr) {
#line 1522
                SI_DELETE_ARRAY(m_pAllocator, m_pData);
            }
            m_pData = nullptr;
        }
        m_itemCount = 0;
        m_reservedCount = 0;
        m_pData = nullptr;
        field_30 = nullptr;
        field_38 = nullptr;
        field_48 = 0;
    }

    ISiAllocator* m_pAllocator;
    size_t m_itemCount;
    size_t m_reservedCount;
    size_t field_20;
    T* m_pData;
    T* field_30;
    T* field_38;
    size_t field_40;
    u64 field_48;  // bit 0: m_pData isn't the array's own (not freed)
};

}  // namespace SiSDK3

PKMN_SIZE_ASSERT(SiSDK3::SiArray<void*>, 0x50);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, m_itemCount, 0x10);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, m_pData, 0x28);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, field_48, 0x48);
