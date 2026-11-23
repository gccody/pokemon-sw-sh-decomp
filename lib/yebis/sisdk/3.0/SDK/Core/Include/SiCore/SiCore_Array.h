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

    // with an allocator, or the kernel's for a null one
    explicit SiArray(ISiAllocator* pAllocator)
        : m_pAllocator(pAllocator), m_itemCount(0), m_reservedCount(0), field_20(sizeof(T)), m_pData(nullptr),
          field_30(nullptr), field_38(nullptr), field_40(0), field_48(0) {
        if (m_pAllocator == nullptr) {
            m_pAllocator = Unk_4bc640();
        }
    }

    virtual ~SiArray() { Unk_4e3050(); }

    // 0x710056e140 (SiString<char>): copies the other's elements (it returns
    // nothing)
    void operator=(const SiArray& other);

    // makes room for at least count elements (inline in every caller:
    // placeholder name)
    bool Unk_ReserveAtLeast(size_t count) {
        if (m_reservedCount < count) {
            if (!Unk_4bf190(count, true)) {
                m_itemCount = 0;
                field_30 = nullptr;
                field_38 = nullptr;
                return false;
            }
            if (m_reservedCount < m_itemCount) {
                m_itemCount = m_reservedCount;
            }
            if (m_itemCount == 0) {
                field_30 = nullptr;
                field_38 = nullptr;
            } else {
                field_30 = m_pData;
                field_38 = m_pData + m_itemCount;
            }
        }
        return true;
    }

    // sets the room to count elements (inline in the assignment: placeholder
    // name)
    bool Unk_SetReserved(size_t count) {
        if (m_reservedCount != count) {
            if (!Unk_4bf190(count, true)) {
                m_itemCount = 0;
                field_30 = nullptr;
                field_38 = nullptr;
                return false;
            }
            if (m_reservedCount < m_itemCount) {
                m_itemCount = m_reservedCount;
            }
            if (m_itemCount == 0) {
                field_30 = nullptr;
                field_38 = nullptr;
            } else {
                field_30 = m_pData;
                field_38 = m_pData + m_itemCount;
            }
        }
        return true;
    }

    // sets the number of elements, making room for them (inline in every
    // caller: placeholder name)
    bool Unk_SetCount(size_t count) {
        if (m_itemCount != count) {
            if (m_reservedCount <= count) {
                if (!Unk_4bf190(count, true)) {
                    m_itemCount = 0;
                    field_30 = nullptr;
                    field_38 = nullptr;
                    return false;
                }
            }
            m_itemCount = count;
            if (count == 0) {
                field_30 = nullptr;
                field_38 = nullptr;
            } else {
                field_30 = m_pData;
                field_38 = m_pData + count;
            }
        }
        return true;
    }

    // makes room for count elements (inline in every caller: placeholder name)
    bool Unk_Reserve(size_t count) {
        bool result = Unk_4bf190(count, true);
        if (!result) {
            m_itemCount = 0;
        }
        if (m_itemCount == 0) {
            field_30 = nullptr;
            field_38 = nullptr;
        } else {
            field_30 = m_pData;
            field_38 = m_pData + m_itemCount;
        }
        return result;
    }

    // appends an element, growing by field_40 elements or to twice the
    // room (inline in every caller: placeholder name)
    bool Unk_Add(const T& value) {
        if (m_itemCount >= m_reservedCount) {
            size_t step = field_40;
            size_t count;
            if (step != 0) {
                count = step + m_reservedCount;
            } else {
                count = m_reservedCount * 2 != 0 ? m_reservedCount * 2 : 1;
            }
            if (!Unk_4bf190(count, true)) {
                m_itemCount = 0;
                field_30 = nullptr;
                field_38 = nullptr;
                return false;
            }
        }
        m_pData[m_itemCount] = value;
        m_itemCount++;
        field_30 = m_pData;
        field_38 = m_pData + m_itemCount;
        return true;
    }

    // field_30 and field_38 for the elements there are (inline: placeholder
    // name)
    void Unk_UpdateRange() {
        if (m_itemCount != 0) {
            field_30 = m_pData;
            field_38 = m_pData + m_itemCount;
        } else {
            field_30 = nullptr;
            field_38 = nullptr;
        }
    }

    // takes an element out, moving the ones after it down (the name is its
    // assert's; the index is an int and the compare with the count is signed)
    void RemoveByIndex(int index) {
        for (s64 i = index + 1; i < static_cast<s64>(m_itemCount); i++) {
            m_pData[i - 1] = m_pData[i];
        }
        m_itemCount--;
    }

    // takes an element out, moving the last one into its place (the name and
    // the parameter's are its assert's; its __LINE__ is the original's, and
    // every later __LINE__ of this header has its own #line)
    void RemoveByIndexNonStable(size_t iIndex) {
        // (an assert that the build's NDEBUG doesn't compile out)
        if (!(iIndex < m_itemCount)) {
#line 1036
            __assert_fail("iIndex < m_itemCount", __FILE__, __LINE__, __func__);
        }
        m_pData[iIndex] = m_pData[m_itemCount - 1];
        m_itemCount--;
        Unk_UpdateRange();
    }

    // takes out every element equal to value, from the last one (inline in
    // every caller: placeholder name)
    void Unk_RemoveValue(const T& value) {
        for (int i = static_cast<int>(m_itemCount) - 1; i >= 0; i--) {
            if (m_pData[i] == value) {
                RemoveByIndex(i);
            }
        }
        Unk_UpdateRange();
    }

    // an empty array in a buffer that isn't its own, with room for count
    // elements (inline: placeholder name)
    void Unk_SetBuffer(T* pData, size_t count) {
        Unk_FreeData();
        m_reservedCount = count;
        m_itemCount = 0;
        m_pData = pData;
        field_30 = nullptr;
        field_38 = nullptr;
        field_48 = 1;
    }

    // frees the buffer and empties the array: 0x71004e3050 through one more
    // inline function (placeholder name). The level shows where the caller
    // also reads m_pData (SiKernel::vf28): the three pointers are cleared as
    // one 24-byte block there, which LLVM's MemCpyOpt only forms on its
    // second run over these stores, the one for this function.
    void Unk_FreeAll() { Unk_4e3050(); }

    // empties the array for another allocator (inline: placeholder name)
    void Unk_SetAllocator(ISiAllocator* pAllocator) {
        if (m_pAllocator != pAllocator) {
            Unk_4e3050();
            m_pAllocator = pAllocator;
        }
    }

    // appends an element made by its default constructor, growing like
    // Unk_Add (inline in its caller: placeholder name; the element's bytes
    // are stored as constants, which a reference to a temporary isn't)
    bool Unk_AddNew() {
        if (m_itemCount >= m_reservedCount) {
            size_t step = field_40;
            size_t count;
            if (step != 0) {
                count = step + m_reservedCount;
            } else {
                count = m_reservedCount * 2 != 0 ? m_reservedCount * 2 : 1;
            }
            if (!Unk_4bf190(count, true)) {
                m_itemCount = 0;
                field_30 = nullptr;
                field_38 = nullptr;
                return false;
            }
        }
        m_pData[m_itemCount] = T();
        m_itemCount++;
        field_30 = m_pData;
        field_38 = m_pData + m_itemCount;
        return true;
    }

    // empties the array, keeping its room (inline in every caller:
    // placeholder name)
    void Unk_Clear() {
        if (m_itemCount != 0) {
            m_itemCount = 0;
            field_30 = nullptr;
            field_38 = nullptr;
        }
    }

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
    T* pData; SI_NEW_ARRAY(pData, m_pAllocator, T, count, ALIGN)
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
    field_30 = nullptr;
    field_38 = nullptr;
    m_pData = pData;
    m_itemCount = n;
    m_reservedCount = count;
    return true;
}

// (0x710056e140 and the other copies.) The buffer is freed through
// Unk_FreeAll: one inline function more, whose own optimisation merges the
// three pointers' zeroing into one block before it is inlined here, so the
// later stores of field_30 aren't merged with that one's address (calling
// Unk_4e3050 directly, the reserve's failure and the loop's share an address
// computed before the reserve). The room's test is `!= 0` with the empty
// case last: with `== 0` first, the loop's end is duplicated into the
// element's two paths of an array of pointers.
template <class T, int ALIGN>
void SiArray<T, ALIGN>::operator=(const SiArray& other) {
    field_40 = other.field_40;
    if (other.m_reservedCount != 0) {
        Unk_FreeAll();
        Unk_SetReserved(other.m_reservedCount);
        for (size_t i = 0; i < other.m_itemCount; i++) {
            Unk_Add(other.m_pData[i]);
        }
    } else if (m_itemCount != 0) {
        m_itemCount = 0;
        field_30 = nullptr;
        field_38 = nullptr;
    }
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

// (The delete is written out here, not a call of Unk_FreeData: for an element
// with a large destructor, SiGfxNXRootSignature's parameters at
// 0x71005581e0, the original has the delete's loop inline in this function
// and this function out of line, where clang would keep Unk_FreeData out of
// line and inline this.)
template <class T, int ALIGN>
void SiArray<T, ALIGN>::Unk_4e3050() {
    if (!(field_48 & 1) && m_pData != nullptr) {
        ISiAllocator* pAllocator = m_pAllocator;
        T* pData = m_pData;
#line 1522
        SI_DELETE_ARRAY(pAllocator, pData);
        m_pData = nullptr;
    }
    m_itemCount = 0;
    m_reservedCount = 0;
    m_pData = nullptr;
    field_30 = nullptr;
    field_38 = nullptr;
    field_48 = 0;
}

// 0x7100566a00 (ISiGfxShaderEffectPackage::ShaderProgramData): deletes the
// objects an array of pointers holds, then empties the array, keeping its
// room if keep (a function of this header: its delete has the header's
// __FILE__).
template <class T, int ALIGN>
void Unk_566a00(ISiAllocator* pAllocator, SiArray<T*, ALIGN>* array, bool keep) {
    for (s64 i = 0; i < static_cast<s32>(array->m_itemCount); i++) {
        T* item = array->m_pData[i];
        if (item != nullptr) {
            array->m_pData[i] = nullptr;
#line 1685
            SI_DELETE(pAllocator, item);
        }
    }
    if (keep) {
        array->Unk_Clear();
    } else {
        array->Unk_4e3050();
    }
}

// Releases the objects an array of pointers holds (their slot 3), then frees
// the array's buffer (inline in every caller: placeholder name).
template <class T, int ALIGN>
inline void Unk_ReleaseAll(SiArray<T*, ALIGN>* array) {
    for (size_t i = 0; i < array->m_itemCount; i++) {
        T* item = array->m_pData[i];
        if (item != nullptr) {
            array->m_pData[i] = nullptr;
            item->vf3();
        }
    }
    array->Unk_4e3050();
}

}  // namespace SiSDK3

PKMN_SIZE_ASSERT(SiSDK3::SiArray<void*>, 0x50);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, m_itemCount, 0x10);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, m_pData, 0x28);
PKMN_OFFSET_ASSERT(SiSDK3::SiArray<void*>, field_48, 0x48);
