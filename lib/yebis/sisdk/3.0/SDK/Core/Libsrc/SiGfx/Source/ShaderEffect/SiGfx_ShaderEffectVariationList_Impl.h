// SiSDK3::SiGfxShaderEffectVariationList (RTTI names the class and the types
// of its lists: ISiGfxShaderEffectVariationList::ShaderVariationItem,
// ShaderEffectData, RequestNotFoundEntry): the variations of a package's
// shader effects that were asked for, with placeholder members. The
// reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_SHADEREFFECTVARIATIONLIST_IMPL).
#pragma once

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_LinkedList.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectKey.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

class ISiIOStream;
class SiGfxShaderEffectPackage;

// What the first argument of the list's slot 5 is read for (placeholder):
// field_b8's field_3c, the index of a program among the package's.
struct Unk_571440_Program {
    u8 _0[0x3c];
    s32 field_3c;
};
struct Unk_571440_Arg {
    u8 _0[0xb8];
    Unk_571440_Program* field_b8;
};

class ISiGfxShaderEffectVariationList {
public:
    // A variation that was asked for: a program's index, its two keys (in
    // four bytes of its own or in an array), and its strings with their hash.
    struct ShaderVariationItem {
        // 0x7100571670
        ShaderVariationItem(ISiAllocator* pAllocator, s32 program, const SiGfxShaderEffectKey& key0,
                            const SiGfxShaderEffectKey& key1, u32 hash, const SiArray<SiString<char>, 16>* strings);
        // an empty one, for a stream's (inline in its caller; the strings'
        // array takes the kernel's allocator)
        explicit ShaderVariationItem(ISiAllocator* pAllocator)
            : m_pPrev(nullptr), m_pNext(nullptr), field_40(0), field_44(0), field_50(pAllocator),
              field_a0(pAllocator) {
            field_48 = 0;
            field_4c = 0;
        }

        ShaderVariationItem* m_pPrev;
        ShaderVariationItem* m_pNext;
        SiGfxShaderEffectKey field_10;
        SiGfxShaderEffectKey field_28;
        u32 field_40;  // the strings' hash
        s32 field_44;  // the program
        u32 field_48;  // the keys' bytes, if there are four or fewer
        u32 field_4c;
        SiArray<u8, 16> field_50;  // else the keys' bytes
        SiArray<u8, 16> field_a0;
        SiArray<SiString<char>, 16> field_f0;
    };

    // An effect's data: its name and five numbers.
    struct ShaderEffectData {
        ShaderEffectData() : field_30(0), field_34(0), field_38(0), field_3c(0), field_40(0), field_44(0) {}
        SiString<char> field_0;
        u32 field_30;
        u32 field_34;
        s32 field_38;
        s32 field_3c;
        s32 field_40;
        s32 field_44;
    };

    // The links of a list's element (placeholder name).
    template <class T>
    struct Unk_Links {
        T* m_pPrev;
        T* m_pNext;
    };

    // A name that was asked for and not found.
    struct RequestNotFoundEntry : Unk_Links<RequestNotFoundEntry> {
        // (the links are a value-initialised pair: their 16-byte zero comes
        // before the string's stores)
        explicit RequestNotFoundEntry(ISiAllocator* pAllocator) : Unk_Links(), field_10(pAllocator) {}

        SiString<char> field_10;
    };
};
PKMN_SIZE_ASSERT(ISiGfxShaderEffectVariationList::ShaderVariationItem, 0x140);
PKMN_OFFSET_ASSERT(ISiGfxShaderEffectVariationList::ShaderVariationItem, field_f0, 0xf0);
PKMN_SIZE_ASSERT(ISiGfxShaderEffectVariationList::ShaderEffectData, 0x48);
PKMN_SIZE_ASSERT(ISiGfxShaderEffectVariationList::RequestNotFoundEntry, 0x40);

class SiGfxShaderEffectVariationList : public ISiGfxShaderEffectVariationList {
public:
    // 0x7100570d10
    explicit SiGfxShaderEffectVariationList(ISiAllocator* pAllocator);
    // 0x7100570e40
    virtual ~SiGfxShaderEffectVariationList();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    // adds a variation, of a program (5) or a program's index (6)
    virtual void vf5(Unk_571440_Arg* program, void* unused, const SiGfxShaderEffectKey& key0,
                     const SiGfxShaderEffectKey& key1, const SiArray<SiString<char>, 16>* strings);
    virtual void vf6(s32 program, void* unused, const SiGfxShaderEffectKey& key0, const SiGfxShaderEffectKey& key1,
                     const SiArray<SiString<char>, 16>* strings);
    virtual void vf7(const char* name);  // adds a name that wasn't found
    virtual u64 vf8();
    virtual u64 vf9();
    virtual bool vf10();  // sorts the variations and makes the effects' data
    virtual u32 vf11();
    virtual u64 vf12(s32 index);
    virtual u32 vf13();
    virtual s32 vf14(const char* name);
    virtual u8* vf15(s32 index);
    virtual u8 vf16();
    virtual bool vf17(ISiIOStream* stream, s32 alignment);  // writes it
    virtual bool vf18(ISiIOStream* stream, s32 alignment);  // reads it
    virtual void vf19();
    virtual const u8* vf20();
    virtual u64 vf21();
    // adds the names that weren't found to a list, each once
    virtual void vf22(SiArray<RequestNotFoundEntry*, 16>* names);

    // Sorts variations by program, keys, strings and hash (placeholder name).
    struct Unk_Sorter {
        static int Unk_Compare(ShaderVariationItem* a, ShaderVariationItem* b);
        inline s64 Unk_573b30(s64 count, ShaderVariationItem** items);   // 0x7100573b30
        inline bool Unk_572530(s64 count, ShaderVariationItem** items);  // 0x7100572530
    };

    // 0x7100571090: forgets the names that weren't found, then vf19
    void Unk_571090();
    // what a stream's list starts with (placeholder)
    struct Unk_Header {
        Unk_Header() : field_0(0), field_4(0), field_8(0), field_c(0) {}
        s32 field_0;  // 3
        s32 field_4;  // 0
        s32 field_8;  // 0
        s32 field_c;  // 2
        s32 field_10;  // the effects
        s32 field_14;  // the variations
    };

    // 0x7100572c40: reads the header and the package's name
    bool Unk_572c40(ISiIOStream* stream, s32 alignment, Unk_Header& header);
    // 0x7100572d70: reads a variation
    bool Unk_572d70(ISiIOStream* stream, s32 alignment, void* unused, s32 index);
    // 0x7100572840: writes a variation
    bool Unk_572840(ISiIOStream* stream, s32 alignment, void* unused, s32 index);

    Unk_4bf660 field_8;
    SiOSCriticalSection field_18;
    SiGfxShaderEffectPackage* field_48;  // the package it's in
    SiString<char> field_50;             // the package's name
    SiDirectLinkedList<ShaderVariationItem*> field_80;
    SiArray<ShaderVariationItem*, 16> field_a8;
    SiArray<ShaderEffectData, 16> field_f8;
    SiDirectLinkedList<RequestNotFoundEntry*> field_148;
    bool field_170;  // whether something was added
};
PKMN_SIZE_ASSERT(SiGfxShaderEffectVariationList, 0x178);
PKMN_OFFSET_ASSERT(SiGfxShaderEffectVariationList, field_80, 0x80);
PKMN_OFFSET_ASSERT(SiGfxShaderEffectVariationList, field_148, 0x148);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADEREFFECTVARIATIONLIST_IMPL
// 0x71005736d0 (vf2), 0x71005736f0 (vf3)
#line 34
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffectVariationList, field_8.m_pAllocator, field_8.m_count)
#endif
