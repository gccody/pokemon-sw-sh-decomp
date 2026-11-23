// Scope: common
// SiSDK3::SiGfxShaderEffectVariationList: its factory, construction,
// destruction, and the variations and names it's told about.
#define UNK_SIGFX_SHADEREFFECTVARIATIONLIST_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectVariationList_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringCompare.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectPackage_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x7100582f10: skips a stream's padding to a multiple of alignment
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment);
// 0x7100582f70: pads a stream to a multiple of alignment
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);
// 0x71004c3510: a string's hash
u32 Unk_4c3510(const SiSDK3::SiString<char>* s);

// A new variation list (placeholder name).
// 0x7100570cb0
SiSDK3::SiGfxShaderEffectVariationList* Unk_570cb0(SiSDK3::ISiAllocator* pAllocator) {
#line 36
    return UNK_SI_NEW(pAllocator, 0x10) SiSDK3::SiGfxShaderEffectVariationList(pAllocator);
}

namespace SiSDK3 {

// 0x7100570d10
SiGfxShaderEffectVariationList::SiGfxShaderEffectVariationList(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(0), field_48(nullptr), field_50(pAllocator), field_80(pAllocator),
      field_a8(pAllocator), field_f8(pAllocator), field_148(pAllocator) {
    field_170 = false;
}

// 0x7100570e40 (D2), 0x7100571410 (D0)
SiGfxShaderEffectVariationList::~SiGfxShaderEffectVariationList() {
    Unk_571090();
}

// 0x7100571090
void SiGfxShaderEffectVariationList::Unk_571090() {
    {
        Unk_596640 lock(&field_18, true);
        RequestNotFoundEntry* entry;
        while ((entry = field_148.m_pHead) != nullptr) {
            field_148.Remove(entry);
#line 97
            SI_DELETE(field_8.m_pAllocator, entry);
        }
    }
    vf19();
}

// 0x7100571440
void SiGfxShaderEffectVariationList::vf5(Unk_571440_Arg* program, void*, const SiGfxShaderEffectKey& key0,
                                         const SiGfxShaderEffectKey& key1,
                                         const SiArray<SiString<char>, 16>* strings) {
    Unk_596640 lock(&field_18, true);
    if (program == nullptr) {
        return;
    }
    size_t count = 0;
    u32 hash = 0;
    if (strings != nullptr) {
        count = strings->m_itemCount;
        for (size_t i = 0; i < strings->m_itemCount; i++) {
            hash ^= Unk_4c3510(&strings->m_pData[i]);
        }
    }
    for (ShaderVariationItem* item = field_80.m_pHead; item != nullptr; item = item->m_pNext) {
        if (item->field_44 == program->field_b8->field_3c && item->field_10.Unk_Compare(key0) == 0 && item->field_28.Unk_Compare(key1) == 0 &&
            static_cast<u32>(item->field_f0.m_itemCount) == static_cast<u32>(count) && item->field_40 == hash) {
            return;
        }
    }
#line 178
    ShaderVariationItem* item = UNK_SI_NEW(field_8.m_pAllocator, 0x10)
        ShaderVariationItem(field_8.m_pAllocator, program->field_b8->field_3c, key0, key1, hash, strings);
    field_80.AddTail(item);
    field_170 = true;
}

// 0x71005719d0
void SiGfxShaderEffectVariationList::vf6(s32 program, void*, const SiGfxShaderEffectKey& key0,
                                         const SiGfxShaderEffectKey& key1,
                                         const SiArray<SiString<char>, 16>* strings) {
    Unk_596640 lock(&field_18, true);
    size_t count = 0;
    u32 hash = 0;
    if (strings != nullptr) {
        count = strings->m_itemCount;
        for (size_t i = 0; i < strings->m_itemCount; i++) {
            hash ^= Unk_4c3510(&strings->m_pData[i]);
        }
    }
    for (ShaderVariationItem* item = field_80.m_pHead; item != nullptr; item = item->m_pNext) {
        if (item->field_44 == program && item->field_10.Unk_Compare(key0) == 0 && item->field_28.Unk_Compare(key1) == 0 &&
            static_cast<u32>(item->field_f0.m_itemCount) == static_cast<u32>(count) && item->field_40 == hash) {
            return;
        }
    }
#line 256
    ShaderVariationItem* item = UNK_SI_NEW(field_8.m_pAllocator, 0x10)
        ShaderVariationItem(field_8.m_pAllocator, program, key0, key1, hash, strings);
    field_80.AddTail(item);
    field_170 = true;
}

// 0x7100571c00
void SiGfxShaderEffectVariationList::vf7(const char* name) {
    Unk_596640 lock(&field_18, true);
    for (RequestNotFoundEntry* entry = field_148.m_pHead; entry != nullptr; entry = entry->m_pNext) {
        if (Unk_CompareNoCase(&entry->field_10, name) == 0) {
            return;
        }
    }
#line 297
    RequestNotFoundEntry* entry = UNK_SI_NEW(field_8.m_pAllocator, 0x10) RequestNotFoundEntry(field_8.m_pAllocator);
    if (entry == nullptr) {
        return;
    }
    Unk_StringAssign(&entry->field_10, name);
    field_148.AddTail(entry);
}

// 0x7100571670
ISiGfxShaderEffectVariationList::ShaderVariationItem::ShaderVariationItem(
    ISiAllocator* pAllocator, s32 program, const SiGfxShaderEffectKey& key0, const SiGfxShaderEffectKey& key1,
    u32 hash, const SiArray<SiString<char>, 16>* strings)
    : m_pPrev(nullptr), m_pNext(nullptr), field_40(hash), field_44(program), field_50(pAllocator),
      field_a0(pAllocator), field_f0(pAllocator) {
    field_48 = 0;
    field_4c = 0;
    if (key0.field_c <= 4) {
        field_10.Unk_Set(key0.field_c, reinterpret_cast<u8*>(&field_48));
    } else {
        field_50.Unk_SetCount(key0.field_c);
        field_10.Unk_Set(key0.field_c, field_50.m_pData);
    }
    if (key1.field_c <= 4) {
        field_28.Unk_Set(key1.field_c, reinterpret_cast<u8*>(&field_4c));
    } else {
        field_a0.Unk_SetCount(key1.field_c);
        field_28.Unk_Set(key1.field_c, field_a0.m_pData);
    }
    field_10.field_8 = key0.field_8;
    if (field_10.field_c > 0) {
        memcpy(field_10.field_10, key0.field_10, field_10.field_c);
    }
    field_28.field_8 = key1.field_8;
    if (field_28.field_c > 0) {
        memcpy(field_28.field_10, key1.field_10, field_28.field_c);
    }
    if (strings != nullptr && strings->m_itemCount != 0) {
        field_f0.Unk_SetCount(strings->m_itemCount);
        for (s32 i = 0; i < static_cast<s32>(strings->m_itemCount); i++) {
            field_f0.m_pData[i] = strings->m_pData[i];
        }
    }
}

// 0x7100573270: the index of an effect's data by its name, or -1
// NON_MATCHING: the count's sign extension: the original extends it in each
// of the two loops LLVM makes of the search (for a null name and for the
// others), this once before the name's test (tried: the count as s32, s64,
// size_t, read in the loop's test, the index as s64). The comparison's result
// is a `bool` of its own (`equal`), which keeps the original's `cset` of
// `(c1 | c2) != 0` and of the empty name's length test.
s32 SiGfxShaderEffectVariationList::vf14(const char* name) {
    s32 count = static_cast<s32>(field_f8.m_itemCount);
    for (s32 i = 0; i < count; i++) {
        bool equal = Unk_Compare(&field_f8.m_pData[i].field_0, name) == 0;
        if (equal) {
            return i;
        }
    }
    return -1;
}

// 0x7100573370: forgets every variation
void SiGfxShaderEffectVariationList::vf19() {
    Unk_596640 lock(&field_18, true);
    ShaderVariationItem* item;
    while ((item = field_80.m_pHead) != nullptr) {
        field_80.Remove(item);
#line 960
        SI_DELETE(field_8.m_pAllocator, item);
    }
    field_170 = false;
}

// 0x71005725d0
bool SiGfxShaderEffectVariationList::vf17(ISiIOStream* stream, s32 alignment) {
    if (field_48 == nullptr) {
        return false;
    }
    vf10();
    s32 effects = static_cast<s32>(field_f8.m_itemCount);
    s32 variations = static_cast<s32>(field_80.m_count);
    stream->vf50(3, true);
    stream->vf50(0, true);
    stream->vf50(0, true);
    stream->vf50(2, true);
    stream->vf50(effects, true);
    stream->vf50(variations, true);
    Unk_582f70(stream, alignment, 0);
    stream->vf58(Unk_StringCStr(field_48->vf6()), true);
    Unk_582f70(stream, alignment, 0);
    for (s64 i = 0; i < static_cast<s32>(field_f8.m_itemCount); i++) {
        Unk_582f70(stream, alignment, 0);
        ShaderEffectData* data = &field_f8.m_pData[i];
        stream->vf58(Unk_StringCStr(&data->field_0), true);
        Unk_582f70(stream, alignment, 0);
        stream->vf54(data->field_30, true);
        stream->vf50(data->field_38, true);
        stream->vf50(data->field_3c, true);
        stream->vf50(data->field_40, true);
        stream->vf50(data->field_44, true);
    }
    for (s32 i = 0; i < static_cast<s32>(field_a8.m_itemCount); i++) {
        Unk_572840(stream, alignment, nullptr, i);
    }
    return true;
}

// 0x7100572840
bool SiGfxShaderEffectVariationList::Unk_572840(ISiIOStream* stream, s32 alignment, void*, s32 index) {
    Unk_582f70(stream, alignment, 0);
    ShaderVariationItem* item = field_a8.m_pData[index];
    stream->vf50(item->field_44, true);
    stream->vf54(item->field_10.field_8, true);
    stream->vf50(item->field_10.field_c, true);
    stream->vf50(item->field_28.field_c, true);
    stream->vf50(item->field_40, true);
    stream->vf50(static_cast<s32>(item->field_f0.m_itemCount), true);
    for (s64 i = 0; i < item->field_10.field_c; i++) {
        stream->vf52(item->field_10.field_10[i], true);
    }
    for (s64 i = 0; i < item->field_28.field_c; i++) {
        stream->vf52(item->field_28.field_10[i], true);
    }
    for (s64 i = 0; i < static_cast<s32>(item->field_f0.m_itemCount); i++) {
        Unk_582f70(stream, alignment, 0);
        stream->vf58(Unk_StringCStr(&item->field_f0.m_pData[i]), true);
    }
    return true;
}

// 0x7100571df0
// NON_MATCHING: 24 bytes short: the loops that count the variations of each
// program keep their count and the index of the list's walk in 64 bits and
// test the count (`cinc` if it's above 0) where this one knows it is; the
// stack frame is 16 bytes larger (tried: the count as s64, a `for` from 1,
// a `while` from 0).
bool SiGfxShaderEffectVariationList::vf10() {
    Unk_596640 lock(&field_18, true);
    if (field_48 == nullptr) {
        return false;
    }
    field_a8.Unk_FreeAll();
    field_f8.Unk_FreeAll();
    if (field_80.m_count == 0) {
        return true;
    }
    field_a8.Unk_ReserveAtLeast(field_80.m_count);
    for (ShaderVariationItem* item = field_80.m_pHead; item != nullptr; item = item->m_pNext) {
        field_a8.Unk_Add(item);
    }
    Unk_Sorter sorter;
    sorter.Unk_572530(static_cast<s32>(field_a8.m_itemCount), field_a8.m_pData);
    if (field_a8.m_itemCount == 0) {
        return true;
    }
    s32 effects = 0;
    for (s32 i = 0; i < static_cast<s32>(field_a8.m_itemCount);) {
        s32 program = field_80.Unk_GetAt(i)->field_44;
        s32 n = 0;
        do {
            n++;
        } while (i + n < static_cast<s32>(field_a8.m_itemCount) && field_80.Unk_GetAt(i + n)->field_44 == program);
        if (n > 0) {
            effects++;
        }
        i += n;
    }
    u32 count = effects;
    field_f8.Unk_SetCount(count);
    for (u32 k = 0; k < count; k++) {
        field_f8.m_pData[k].field_0.Unk_SetAllocator(field_8.m_pAllocator);
    }
    s64 index = 0;
    for (s32 i = 0; i < static_cast<s32>(field_a8.m_itemCount); index++) {
        ShaderVariationItem* item = field_80.Unk_GetAt(i);
        ShaderEffectData* data = &field_f8.m_pData[index];
        data->field_38 = i;
        data->field_34 = item->field_44;
        ISiGfxShaderEffectPackage::ShaderEffectData* effect = field_48->field_140.m_pData[item->field_44];
        if (effect == nullptr) {
            return false;
        }
        data->field_0 = effect->field_8;
        data->field_30 = effect->field_38;
        data->field_40 = effect->field_48;
        data->field_44 = effect->field_50;
        s32 program = item->field_44;
        s32 n = 0;
        do {
            n++;
        } while (i + n < static_cast<s32>(field_a8.m_itemCount) && field_80.Unk_GetAt(i + n)->field_44 == program);
        data->field_3c = n;
        i += n;
    }
    for (u64 k = 0; k < count; k++) {
        ShaderEffectData* data = &field_f8.m_pData[k];
        for (s32 j = 0; j < data->field_3c; j++) {
            ShaderVariationItem* item = field_a8.m_pData[data->field_38 + j];
            if (item != nullptr) {
                item->field_44 = k;
            }
        }
    }
    return true;
}

// what a is to b: below, above or the same (inline)
inline int SiGfxShaderEffectVariationList::Unk_Sorter::Unk_Compare(ShaderVariationItem* a, ShaderVariationItem* b) {
    if (a->field_44 < b->field_44) {
        return -1;
    }
    if (a->field_44 > b->field_44) {
        return 1;
    }
    int result = a->field_10.Unk_Compare(b->field_10);
    if (result != 0) {
        return result;
    }
    result = a->field_28.Unk_Compare(b->field_28);
    if (result != 0) {
        return result;
    }
    if (a->field_f0.m_itemCount < b->field_f0.m_itemCount) {
        return -1;
    }
    if (a->field_f0.m_itemCount > b->field_f0.m_itemCount) {
        return 1;
    }
    if (a->field_40 < b->field_40) {
        return -1;
    }
    if (a->field_40 > b->field_40) {
        return 1;
    }
    return 0;
}

// 0x7100573b30
inline s64 SiGfxShaderEffectVariationList::Unk_Sorter::Unk_573b30(s64 count, ShaderVariationItem** items) {
    s64 pivot = count < 2 ? 1 : count / 2;
    if (pivot >= count) {
        return 0;
    }
    if (pivot != 0) {
        ShaderVariationItem* t = items[0];
        items[0] = items[pivot];
        items[pivot] = t;
    }
    ShaderVariationItem* first = items[0];
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
            ShaderVariationItem* t = items[i];
            items[i] = items[j];
            items[j] = t;
        }
    }
    s64 middle = i - 1;
    ShaderVariationItem* t = items[0];
    items[0] = items[middle];
    items[middle] = t;
    return middle;
}

// 0x7100572530
inline bool SiGfxShaderEffectVariationList::Unk_Sorter::Unk_572530(s64 count, ShaderVariationItem** items) {
    if (count < 2) {
        return true;
    }
    s64 middle = Unk_573b30(count, items);
    Unk_572530(middle, items);
    Unk_572530(count - middle - 1, &items[middle + 1]);
    return true;
}

// 0x7100572a00
bool SiGfxShaderEffectVariationList::vf18(ISiIOStream* stream, s32 alignment) {
    Unk_Header header;
    if (!Unk_572c40(stream, alignment, header)) {
        return false;
    }
    field_f8.Unk_SetCount(header.field_10);
    for (s64 i = 0; i < static_cast<s32>(field_f8.m_itemCount); i++) {
        Unk_582f10(stream, alignment);
        ShaderEffectData* data = &field_f8.m_pData[i];
        stream->vf35(&data->field_0, true);
        Unk_582f10(stream, alignment);
        data->field_30 = stream->vf31(true);
        data->field_38 = stream->vf27(true);
        data->field_3c = stream->vf27(true);
        data->field_40 = stream->vf27(true);
        data->field_44 = stream->vf27(true);
    }
    s32 variations = header.field_14;
    field_a8.Unk_SetCount(variations);
    for (s32 i = 0; i < variations; i++) {
        Unk_572d70(stream, alignment, nullptr, i);
    }
    return true;
}

// 0x7100572c40
bool SiGfxShaderEffectVariationList::Unk_572c40(ISiIOStream* stream, s32 alignment, Unk_Header& header) {
    memset(&header, 0, sizeof(header));
    header.field_0 = stream->vf27(true);
    header.field_4 = stream->vf27(true);
    header.field_8 = stream->vf27(true);
    header.field_c = stream->vf27(true);
    bool result = false;
    if (header.field_c == 2 && header.field_0 == 3 && header.field_4 == 0 && header.field_8 == 0) {
        result = true;
        header.field_10 = stream->vf27(true);
        header.field_14 = stream->vf27(true);
        Unk_582f10(stream, alignment);
        stream->vf35(&field_50, true);
        Unk_582f10(stream, alignment);
    }
    return result;
}

// 0x7100572d70
// NON_MATCHING: the allocator the new item is made with and the vtable of
// its byte arrays are exchanged (x25/x20/x27), and the first bytes loop's
// guard is a flag here (`mov w19, wzr` / `#1`, `cbz w19`: the clear's
// `size >= 1` test reused) where the original compares the size again
// (`cmp w10, #1; b.lt`). Tried: 64-bit indices, the loops bounded by the
// keys' sizes, each clear in its branch.
bool SiGfxShaderEffectVariationList::Unk_572d70(ISiIOStream* stream, s32 alignment, void*, s32 index) {
    Unk_582f10(stream, alignment);
    s32 program = stream->vf27(true);
    u32 value0 = stream->vf31(true);
    s32 size0 = stream->vf27(true);
    s32 size1 = stream->vf27(true);
    u32 hash = stream->vf31(true);
    s32 strings = stream->vf27(true);
#line 856
    ShaderVariationItem* item = UNK_SI_NEW(field_8.m_pAllocator, 0x10) ShaderVariationItem(field_8.m_pAllocator);
    item->field_44 = program;
    if (size0 <= 4) {
        item->field_10.Unk_Set(size0, reinterpret_cast<u8*>(&item->field_48));
    } else {
        item->field_50.Unk_SetCount(size0);
        item->field_10.Unk_Set(size0, item->field_50.m_pData);
    }
    item->field_10.Unk_Clear();
    if (size1 <= 4) {
        item->field_28.Unk_Set(size1, reinterpret_cast<u8*>(&item->field_4c));
    } else {
        item->field_a0.Unk_SetCount(size1);
        item->field_28.Unk_Set(size1, item->field_a0.m_pData);
    }
    item->field_28.Unk_Clear();
    item->field_40 = hash;
    item->field_10.field_8 = value0;
    for (s32 i = 0; i < size0; i++) {
        item->field_10.field_10[i] = stream->vf29(true);
    }
    for (s32 i = 0; i < size1; i++) {
        item->field_28.field_10[i] = stream->vf29(true);
    }
    item->field_f0.Unk_SetCount(strings);
    for (s32 i = 0; i < strings; i++) {
        Unk_582f10(stream, alignment);
        stream->vf35(&item->field_f0.m_pData[i], true);
    }
    field_80.AddTail(item);
    field_a8.m_pData[index] = item;
    return true;
}

// 0x7100573480
// The search ORs each comparison's result into a flag and leaves the loop on
// an equal name (the original's `orr` of a value that is zero on its path,
// which only a separate `equal` keeps); the index is declared before the
// flag (the order of their zeroings).
void SiGfxShaderEffectVariationList::vf22(SiArray<RequestNotFoundEntry*, 16>* names) {
    Unk_596640 lock(&field_18, true);
    if (field_148.m_count == 0) {
        return;
    }
    names->Unk_ReserveAtLeast(names->m_itemCount + field_148.m_count);
    for (RequestNotFoundEntry* entry = field_148.m_pHead; entry != nullptr; entry = entry->m_pNext) {
        s64 i;
        bool found = false;
        for (i = 0; i < static_cast<s32>(names->m_itemCount); i++) {
            RequestNotFoundEntry* name = names->m_pData[i];
            if (name != nullptr) {
                bool equal = Unk_CompareNoCase(&entry->field_10, &name->field_10) == 0;
                found |= equal;
                if (equal) {
                    break;
                }
            }
        }
        if (!found) {
            names->Unk_Add(entry);
        }
    }
}

}  // namespace SiSDK3
