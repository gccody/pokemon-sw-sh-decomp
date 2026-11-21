// SiSDK3::SiStringTable and SiSDK3::SiStringTable::Entry (RTTI; the classes
// they derive from are the RTTI's too): a table of strings by id, each with
// one text per language. Placeholder members. The reference counts are defined
// in this header (their __FILE__), at the original's lines, for the file that
// asks with UNK_SISTRINGTABLE_DEFINE (SiCore_StringTable_Impl.cpp).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4ca820_arg0.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Guid.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

// RTTI: SiSDK3::ISiStringTable, on ISiInterface and (at 8) ISiNamedObject.
// The slots are placeholders; the last three of the table's vtable are the
// named object's, which the table overrides.
class ISiStringTable : public ISiInterface, public ISiNamedObject {
public:
    // RTTI: SiSDK3::ISiStringTable::IEntry
    class IEntry : public ISiInterface {
    public:
        virtual int vf5() = 0;  // the id
        virtual bool vf6(const Unk_4ca820_arg0& language, const char* text) = 0;
        virtual const SiString<char>& vf7(const Unk_4ca820_arg0& language) = 0;
        virtual const SiString<char>& vf8() = 0;
    };

    // an id and its text: what vf11 takes a list of, up to an id of 0
    struct Unk_Item {
        int field_0;
        const char* field_8;
    };

    virtual const SI_GUID* vf5() = 0;
    virtual bool vf6(const Unk_4ca820_arg0& language) = 0;
    virtual const Unk_4ca820_arg0* vf7() = 0;
    virtual void vf8() = 0;  // starts changes
    virtual void vf9() = 0;  // ends them: sorts the entries
    virtual IEntry* vf10(int id) = 0;
    virtual bool vf11(const Unk_4ca820_arg0& language, const Unk_Item* items) = 0;
    virtual bool vf12(int id, const Unk_4ca820_arg0& language, const char* text) = 0;
    virtual const SiString<char>& vf13(int id, const Unk_4ca820_arg0& language) = 0;
    virtual const SiString<char>& vf14(int id) = 0;
    virtual IEntry* vf15(int id) = 0;
    virtual IEntry* vf16(int id) = 0;
    virtual u32 vf17() = 0;
};

class SiStringTable : public ISiStringTable {
public:
    class Entry;

    // a language and the text in it, in a buffer of its own until it is set
    // (RTTI: SiArray<SiStringTable::StringPerLanguage, 16>)
    struct StringPerLanguage {
        // (one constructor with a default argument: with a second one for no
        // allocator, an entry's four would clear the language and the null
        // allocator in one 16-byte store)
        explicit StringPerLanguage(ISiAllocator* pAllocator = nullptr)
            : field_0(), field_8(pAllocator, field_38, sizeof(field_38)) {}
        // the language and the text: not the buffer
        StringPerLanguage& operator=(const StringPerLanguage& other) {
            field_0 = other.field_0;
            field_8 = other.field_8;
            return *this;
        }

        Unk_4ca820_arg0 field_0;
        SiString<char> field_8;
        char field_38[0x80];
    };

    // the entries' sort by id (an empty object on vf9's stack)
    struct Unk_Sorter {
        static int Unk_Compare(Entry* a, Entry* b);
        inline s64 Unk_4c83b0(s64 count, Entry** items);   // 0x71004c83b0
        inline bool Unk_4c7230(s64 count, Entry** items);  // 0x71004c7230
    };

    explicit SiStringTable(ISiAllocator* pAllocator);  // 0x71004c6b70
    virtual ~SiStringTable();                          // 0x71004c6d60, 0x71004c6fd0
    virtual u32 vf2();                                 // 0x71004c7bd0
    virtual u32 vf3();                                 // 0x71004c7bf0
    virtual u32 vf4();
    virtual const SI_GUID* vf5();
    virtual bool vf6(const Unk_4ca820_arg0& language);  // 0x71004c7110
    virtual const Unk_4ca820_arg0* vf7();
    virtual void vf8();
    virtual void vf9();                                                                  // 0x71004c7140
    virtual IEntry* vf10(int id);                                                        // 0x71004c72b0
    virtual bool vf11(const Unk_4ca820_arg0& language, const Unk_Item* items);           // 0x71004c73f0
    virtual bool vf12(int id, const Unk_4ca820_arg0& language, const char* text);        // 0x71004c7690
    virtual const SiString<char>& vf13(int id, const Unk_4ca820_arg0& language);         // 0x71004c7740
    virtual const SiString<char>& vf14(int id);                                          // 0x71004c7880
    virtual IEntry* vf15(int id);                                                        // 0x71004c78d0
    virtual IEntry* vf16(int id);                                                        // 0x71004c79f0
    virtual u32 vf17();
    virtual bool vf18(const char* name);   // 0x71004c7030
    virtual const SiString<char>* vf19();  // 0x71004c70b0
    virtual u32 vf20();                    // 0x71004c70d0

    void Unk_4c70f0(const SI_GUID* id);  // 0x71004c70f0

    // an entry by its id: among all of them while they change, in the sorted
    // ones otherwise (inline: placeholder names)
    Entry* Unk_FindLinear(int id);
    Entry* Unk_FindSorted(int id);
    Entry* Unk_Find(int id) { return field_140 >= 1 ? Unk_FindLinear(id) : Unk_FindSorted(id); }

    Unk_4bf660 field_10;
    SiString<char> field_20;  // the name
    u32 field_50;             // its hash
    SI_GUID field_54;
    Unk_4ca820_arg0 field_64;      // the language of vf14
    SiArray<Entry*, 16> field_70;  // in field_148
    SiArray<Entry*, 16> field_c0;  // sorted by id, in field_948
    SiString<char> field_110;      // what an id without a text reads as
    s32 field_140;                 // how many changes are going on
    Entry* field_148[0x100];
    Entry* field_948[0x100];
};
PKMN_SIZE_ASSERT(SiStringTable::StringPerLanguage, 0xb8);
PKMN_OFFSET_ASSERT(SiStringTable, field_54, 0x54);
PKMN_OFFSET_ASSERT(SiStringTable, field_70, 0x70);
PKMN_OFFSET_ASSERT(SiStringTable, field_110, 0x110);
PKMN_SIZE_ASSERT(SiStringTable, 0x1148);

class SiStringTable::Entry : public ISiStringTable::IEntry {
public:
    Entry(SiStringTable* pTable, ISiAllocator* pAllocator, int id);  // 0x71004c6090
    virtual ~Entry();                                                // 0x71004c6330, 0x71004c6680
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    virtual int vf5();
    virtual bool vf6(const Unk_4ca820_arg0& language, const char* text);  // 0x71004c66c0
    virtual const SiString<char>& vf7(const Unk_4ca820_arg0& language);   // 0x71004c6a00
    virtual const SiString<char>& vf8();                                  // 0x71004c6b30

    Unk_4bf660 field_8;
    SiStringTable* field_18;
    int field_20;                                  // the id
    SiString<char> field_28;                       // the text of no language
    SiArray<StringPerLanguage, 16> field_58;       // in field_a8
    StringPerLanguage field_a8[4];
};
PKMN_OFFSET_ASSERT(SiStringTable::Entry, field_58, 0x58);
PKMN_SIZE_ASSERT(SiStringTable::Entry, 0x388);

inline SiStringTable::Entry* SiStringTable::Unk_FindLinear(int id) {
    for (s64 i = 0; i < static_cast<int>(field_70.m_itemCount); i++) {
        Entry* pEntry = field_70.m_pData[i];
        if (pEntry->vf5() == id) {
            return pEntry;
        }
    }
    return nullptr;
}

inline SiStringTable::Entry* SiStringTable::Unk_FindSorted(int id) {
    int high = static_cast<int>(field_c0.m_itemCount) - 1;
    int low = 0;
    if (high < 0) {
        return nullptr;
    }
    Entry** ppEntries = field_c0.m_pData;
    Entry* pEntry = ppEntries[0];
    if (pEntry->field_20 > id) {
        return nullptr;
    }
    if (ppEntries[high]->field_20 < id) {
        return nullptr;
    }
    while (low < high - 1) {
        int middle = (low + high) >> 1;
        pEntry = ppEntries[middle];
        if (pEntry->field_20 > id) {
            high = middle;
        } else {
            low = middle;
            if (pEntry->field_20 >= id) {
                return pEntry;
            }
        }
    }
    pEntry = ppEntries[low];
    if (pEntry->field_20 == id) {
        return pEntry;
    }
    pEntry = ppEntries[high];
    return pEntry->field_20 == id ? pEntry : nullptr;
}

}  // namespace SiSDK3

#ifdef UNK_SISTRINGTABLE_DEFINE
// 0x71004c7bd0 (vf2), 0x71004c7bf0 (vf3)
#line 24
UNK_REFCOUNT_DEFINE(SiSDK3::SiStringTable, field_10.m_pAllocator, field_10.m_count)
// 0x71004c7b20 (vf2), 0x71004c7b40 (vf3)
#line 49
UNK_REFCOUNT_DEFINE(SiSDK3::SiStringTable::Entry, field_8.m_pAllocator, field_8.m_count)
#endif
