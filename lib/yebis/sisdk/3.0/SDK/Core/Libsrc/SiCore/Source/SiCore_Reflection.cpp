// Scope: common
// SiSDK3::SiReflectionObject (SiCore_Reflection.cpp is the __FILE__ of its
// deletes): a reflected class and its properties. The translation unit's
// static initialiser is lib/yebis/static/Unk_4cba60.cpp.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/SiCore_Kernel_Impl.h>

// 0x71004bf730: the kernel
SiSDK3::SiKernel* Unk_4bf730();
// 0x71004c34a0: a name's hash
u32 Unk_4c34a0(const char* name);

namespace SiSDK3 {

// 0x71004caea0
SiReflectionObject::SiReflectionObject(ISiAllocator* pAllocator, const char* text, const char* name,
                                       SiReflectionObject* pBase)
    : field_8(pAllocator), field_10(pAllocator, text), field_40(name), field_50(pBase), field_58(pAllocator),
      field_80(pAllocator), field_d0(pAllocator), field_120(0), field_128(nullptr) {
    field_48 = Unk_4c34a0(name);
}

// 0x71004cafe0
SiReflectionObject::~SiReflectionObject() {
    Unk_4cb170();
    Unk_4bf730()->Unk_4c0d60(this);
    if (field_128 != nullptr) {
        field_128->vf3();
        field_128 = nullptr;
    }
}

// 0x71004cb170
void SiReflectionObject::Unk_4cb170() {
    ISiAllocator* pAllocator = field_8;
    for (s64 i = 0; i < static_cast<int>(field_80.m_itemCount); i++) {
        if (field_120 <= i) {
#line 80
            SI_DELETE(pAllocator, field_80.m_pData[i]);
            field_80.m_pData[i] = nullptr;
        }
    }
    field_80.Unk_FreeAll();
    field_d0.Unk_FreeAll();
}

// 0x71004cb420
// NON_MATCHING: 9 instructions: the loop's index is zero-extended from the
// base's count in the original (`and x12, x12, #0xffffffff`, here `sxtw`),
// and two registers are exchanged. The list's final size is the size before
// the loop plus the base's count, computed before the loop (`add x10, x12,
// x8`): the original adds them in the source, it doesn't reread the list's
// count (round 6; the index as u32, s64, size_t, counted up or down: the
// same or worse).
void SiReflectionObject::Unk_4cb420() {
    s64 count = 0;
    size_t total = field_58.m_count;
    SiReflectionObject* pBase = field_50;
    if (pBase != nullptr) {
        total += pBase->field_80.m_itemCount;
        for (int i = static_cast<int>(pBase->field_80.m_itemCount) - 1; i >= 0; i--) {
            field_58.AddHead(pBase->field_80.m_pData[i]);
            count++;
        }
    }
    int n = static_cast<int>(total);
    field_120 = count;
    field_80.Unk_SetCount(n);
    field_d0.Unk_SetCount(n);
    s64 index = 0;
    for (SiReflectionPropertyBase* p = field_58.m_pHead; p != nullptr; p = p->m_pNext) {
        field_80.m_pData[index] = p;
        field_d0.m_pData[index] = p;
        p->field_98 = index;
        index++;
    }
    Unk_Sorter sorter;
    sorter.Unk_4cb630(field_80.m_itemCount, field_d0.m_pData);
    field_58.RemoveAll();
    Unk_4bf730()->Unk_4c0910(this);
}

// (inline in the sort)
inline s64 SiReflectionObject::Unk_Sorter::Unk_Partition(s64 count, SiReflectionPropertyBase** items) {
    s64 pivot = count < 2 ? 1 : count / 2;
    if (pivot >= count) {
        return 0;
    }
    if (pivot != 0) {
        SiReflectionPropertyBase* t = items[0];
        items[0] = items[pivot];
        items[pivot] = t;
    }
    SiReflectionPropertyBase* first = items[0];
    s64 i = 1;
    s64 j = count - 1;
    while (i <= j) {
        if (Unk_Compare(first, items[i]) > 0) {
            do {
                if (++i >= j) {
                    break;
                }
            } while (Unk_Compare(first, items[i]) > 0);
        }
        if (Unk_Compare(first, items[j]) <= 0) {
            do {
                if (--j <= i) {
                    break;
                }
            } while (Unk_Compare(first, items[j]) <= 0);
        }
        if (i < j) {
            SiReflectionPropertyBase* t = items[i];
            items[i] = items[j];
            items[j] = t;
        }
    }
    s64 middle = i - 1;
    SiReflectionPropertyBase* t = items[0];
    items[0] = items[middle];
    items[middle] = t;
    return middle;
}

// 0x71004cb630
inline bool SiReflectionObject::Unk_Sorter::Unk_4cb630(s64 count, SiReflectionPropertyBase** items) {
    if (count < 2) {
        return true;
    }
    s64 middle = Unk_Partition(count, items);
    Unk_4cb630(middle, items);
    Unk_4cb630(count - middle - 1, &items[middle + 1]);
    return true;
}

// 0x71004cb410 (lib/yebis/leaf had it as Unk_4cb410_update(u64))
void SiReflectionObject::Unk_4cb410() {}

// 0x71004cb770
bool SiReflectionObject::Unk_4cb770(SiReflectionPropertyBase* pProperty) {
    field_58.AddTail(pProperty);
    return true;
}

// 0x71004cb7b0
void SiReflectionObject::Unk_4cb7b0(ISiInterface* pInterface) {
    if (pInterface != nullptr) {
        pInterface->vf2();
    }
    if (field_128 != nullptr) {
        field_128->vf3();
    }
    field_128 = pInterface;
}

}  // namespace SiSDK3
