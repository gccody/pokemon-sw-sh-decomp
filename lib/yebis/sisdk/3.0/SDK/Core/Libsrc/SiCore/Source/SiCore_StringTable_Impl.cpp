// Scope: common
// SiSDK3::SiStringTable and its entries: a table of strings by id, with a text
// per language, kept in the order they were added while they change and
// sorted by id otherwise.
#include <string.h>

#define UNK_SISTRINGTABLE_DEFINE
#define UNK_SICORE_STRING_ASSIGN_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/SiCore_StringTable_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringAssign.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c3510: a string's hash
u32 Unk_4c3510(const SiSDK3::SiString<char>* s);

namespace SiSDK3 {

// 0x71004c6090
SiStringTable::Entry::Entry(SiStringTable* pTable, ISiAllocator* pAllocator, int id)
    : field_8(pAllocator), field_18(pTable), field_20(id), field_28(pAllocator), field_58(pAllocator) {
    field_58.Unk_SetBuffer(field_a8, 4);
}

// 0x71004c6330, 0x71004c6680
SiStringTable::Entry::~Entry() {}

// 0x71004c66c0
bool SiStringTable::Entry::vf6(const Unk_4ca820_arg0& language, const char* text) {
    if (field_18->field_140 < 1) {
        return false;
    }
    if (language.field_0 == 0 && language.field_4 == 0) {
        field_28.Unk_SetView(text);
        return true;
    }
    for (s64 i = 0; i < static_cast<int>(field_58.m_itemCount); i++) {
        StringPerLanguage* pString = &field_58.m_pData[i];
        if (pString->field_0.field_0 == language.field_0 && pString->field_0.field_4 == language.field_4) {
            pString->field_8.Unk_SetView(text);
            return true;
        }
    }
    StringPerLanguage string(field_8.m_pAllocator);
    field_58.Unk_Add(string);
    StringPerLanguage* pString = &field_58.m_pData[field_58.m_itemCount - 1];
    pString->field_0 = language;
    pString->field_8.Unk_SetView(text);
    return true;
}

// 0x71004c6a00
const SiString<char>& SiStringTable::Entry::vf7(const Unk_4ca820_arg0& language) {
    if (language.field_0 == 0 && language.field_4 == 0) {
        return field_28;
    }
    StringPerLanguage* pLanguage = nullptr;
    StringPerLanguage* pNoCountry = nullptr;
    StringPerLanguage* pDefault = nullptr;
    for (s64 i = 0; i < static_cast<int>(field_58.m_itemCount); i++) {
        StringPerLanguage* pString = &field_58.m_pData[i];
        if (pString->field_0 == language) {
            return pString->field_8;
        }
        if (pString->field_0.field_0 == language.field_0) {
            if (pString->field_0.field_4 == 0) {
                pNoCountry = pString;
            }
            pLanguage = pString;
        } else if (pString->field_0 == *field_18->vf7()) {
            pDefault = pString;
        }
    }
    if (pNoCountry != nullptr) {
        return pNoCountry->field_8;
    }
    if (pLanguage != nullptr) {
        return pLanguage->field_8;
    }
    if (pDefault != nullptr) {
        return pDefault->field_8;
    }
    return field_28;
}

// 0x71004c6b30
const SiString<char>& SiStringTable::Entry::vf8() {
    return vf7(*Unk_GetKernel()->vf24());
}

// 0x71004c6b70
SiStringTable::SiStringTable(ISiAllocator* pAllocator)
    : field_10(pAllocator), field_20(pAllocator), field_50(0), field_54(), field_64(1, 0), field_70(pAllocator),
      field_c0(pAllocator), field_110(pAllocator), field_140(0) {
    field_64 = *Unk_GetKernel()->vf24();
    memset(field_148, 0, sizeof(field_148));
    memset(field_948, 0, sizeof(field_948));
    field_70.Unk_SetBuffer(field_148, 0x100);
    field_c0.Unk_SetBuffer(field_948, 0x100);
}

// 0x71004c6d60, 0x71004c6fd0
SiStringTable::~SiStringTable() {
    for (size_t i = 0; i < field_70.m_itemCount; i++) {
        Entry* pEntry = field_70.m_pData[i];
        if (pEntry != nullptr) {
            field_70.m_pData[i] = nullptr;
            pEntry->vf3();
        }
    }
    field_70.Unk_FreeAll();
}

// 0x71004c7030
bool SiStringTable::vf18(const char* name) {
    Unk_StringAssign(&field_20, name);
    field_50 = Unk_4c3510(&field_20);
    return true;
}

// 0x71004c70b0
const SiString<char>* SiStringTable::vf19() {
    return &field_20;
}

// 0x71004c70d0
u32 SiStringTable::vf20() {
    return field_50;
}

// 0x71004c7c70
u32 SiStringTable::vf4() {
    return field_10.m_count;
}

// 0x71004c7100
const SI_GUID* SiStringTable::vf5() {
    return &field_54;
}

// 0x71004c7120
const Unk_4ca820_arg0* SiStringTable::vf7() {
    return &field_64;
}

// 0x71004c7130
void SiStringTable::vf8() {
    field_140++;
}

// 0x71004c7b10
u32 SiStringTable::vf17() {
    return static_cast<u32>(field_70.m_itemCount);
}

// 0x71004c70f0
void SiStringTable::Unk_4c70f0(const SI_GUID* id) {
    field_54 = *id;
}

// 0x71004c7110
bool SiStringTable::vf6(const Unk_4ca820_arg0& language) {
    field_64 = language;
    return true;
}

// 0x71004c7140
void SiStringTable::vf9() {
    if (field_140 < 1) {
        return;
    }
    field_c0.Unk_Clear();
    if (field_70.m_itemCount != 0) {
        field_c0.Unk_SetCount(field_70.m_itemCount);
        for (s64 i = 0; i < static_cast<int>(field_70.m_itemCount); i++) {
            field_c0.m_pData[i] = field_70.m_pData[i];
        }
        Unk_Sorter sorter;
        sorter.Unk_4c7230(field_c0.m_itemCount, field_c0.m_pData);
    }
    field_140--;
}

// 0x71004c7230
inline bool SiStringTable::Unk_Sorter::Unk_4c7230(s64 count, Entry** items) {
    if (count < 2) {
        return true;
    }
    s64 middle = Unk_4c83b0(count, items);
    Unk_4c7230(middle, items);
    Unk_4c7230(count - middle - 1, &items[middle + 1]);
    return true;
}

// 0x71004c72b0
ISiStringTable::IEntry* SiStringTable::vf10(int id) {
    if (field_140 < 1) {
        return nullptr;
    }
    Entry* pEntry = Unk_FindLinear(id);
    if (pEntry != nullptr) {
        return pEntry;
    }
#line 459
    pEntry = UNK_SI_NEW(field_10.m_pAllocator, 0x10) Entry(this, field_10.m_pAllocator, id);
    if (pEntry == nullptr) {
        return nullptr;
    }
    field_70.Unk_Add(pEntry);
    return pEntry;
}

// 0x71004c73f0
// NON_MATCHING: the same instructions but for where the result's 0 is set.
// The original moves `this` out of x0 first and clears w0 once, before the two
// tests that return false at once (only the failed allocation in the loop has
// a block of its own for it); here the three share one block that clears w0.
bool SiStringTable::vf11(const Unk_4ca820_arg0& language, const Unk_Item* items) {
    if (items == nullptr) {
        return false;
    }
    if (field_140 < 1) {
        return false;
    }
    u32 count = 0;
    for (s64 i = 0; items[i].field_0 != 0 && items[i].field_8 != nullptr; i++) {
        if (Unk_FindLinear(items[i].field_0) == nullptr) {
            count++;
        }
    }
    field_70.Unk_ReserveAtLeast(field_70.m_reservedCount + count);
    for (s64 i = 0; items[i].field_0 != 0 && items[i].field_8 != nullptr; i++) {
        Entry* pEntry = Unk_FindLinear(items[i].field_0);
        if (pEntry == nullptr) {
#line 537
            pEntry = UNK_SI_NEW(field_10.m_pAllocator, 0x10) Entry(this, field_10.m_pAllocator, items[i].field_0);
            if (pEntry == nullptr) {
                return false;
            }
            field_70.Unk_Add(pEntry);
        }
        pEntry->vf6(language, items[i].field_8);
    }
    return true;
}

// 0x71004c7690
bool SiStringTable::vf12(int id, const Unk_4ca820_arg0& language, const char* text) {
    if (field_140 < 1) {
        return false;
    }
    Entry* pEntry = Unk_FindLinear(id);
    if (pEntry == nullptr) {
        return false;
    }
    pEntry->vf6(language, text);
    return true;
}

// 0x71004c7740
const SiString<char>& SiStringTable::vf13(int id, const Unk_4ca820_arg0& language) {
    Entry* pEntry = Unk_Find(id);
    if (pEntry == nullptr) {
        return field_110;
    }
    return pEntry->vf7(language);
}

// 0x71004c7880
const SiString<char>& SiStringTable::vf14(int id) {
    return vf13(id, *Unk_GetKernel()->vf24());
}

// 0x71004c78d0
ISiStringTable::IEntry* SiStringTable::vf15(int id) {
    return Unk_Find(id);
}

// 0x71004c79f0
ISiStringTable::IEntry* SiStringTable::vf16(int id) {
    return Unk_Find(id);
}

}  // namespace SiSDK3

// 0x71004c8020
// NON_MATCHING: the path for an empty string loads the flags (field_28) and
// doesn't use them in the original (as 0x71004c4700 does), and the growth's
// maximum compares its operands the other way round (`cmp x8, x9 ; csel lo`
// for the original's `cmp x9, x8 ; csel hi`, from the same IR as
// 0x71004c4700's, which has the original's); the rest is the original's. (The
// test is `count < 1`: with `count == 0`, call-site splitting gives the copy
// a second copy for the path that grows the buffer.)
SiSDK3::SiString<char>* Unk_4c8020(SiSDK3::SiString<char>* self, const SiSDK3::SiString<char>* other) {
    if (other->field_10 == 0) {
        SiSDK3::Unk_StringSetEmpty(self);
        return self;
    }
    SiSDK3::Unk_StringReserve(self, other->field_10 + 1);
    size_t count = other->field_10;
    if (count < 1) {
        SiSDK3::Unk_StringSetEmpty(self);
    } else {
        if (self->field_20 <= count) {
            SiSDK3::Unk_StringGrow(self, count + 1);
        }
        SiSDK3::Unk_StringCopyN(self->m_pBuffer, other->m_pBuffer, count);
        self->field_10 = count;
    }
    self->field_10 = other->field_10;
    return self;
}

namespace SiSDK3 {

// what a's id is to b's: below, above or the same (inline)
inline int SiStringTable::Unk_Sorter::Unk_Compare(Entry* a, Entry* b) {
    if (a->vf5() < b->vf5()) {
        return -1;
    }
    if (a->vf5() > b->vf5()) {
        return 1;
    }
    return 0;
}

// 0x71004c83b0
inline s64 SiStringTable::Unk_Sorter::Unk_4c83b0(s64 count, Entry** items) {
    s64 pivot = count < 2 ? 1 : count / 2;
    if (pivot >= count) {
        return 0;
    }
    if (pivot != 0) {
        Entry* t = items[0];
        items[0] = items[pivot];
        items[pivot] = t;
    }
    Entry* first = items[0];
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
            Entry* t = items[i];
            items[i] = items[j];
            items[j] = t;
        }
    }
    s64 middle = i - 1;
    Entry* t = items[0];
    items[0] = items[middle];
    items[middle] = t;
    return middle;
}

}  // namespace SiSDK3
