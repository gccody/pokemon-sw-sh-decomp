// Scope: common
// SiSDK3::SiGfxShaderBinaryCachePackage: its constructor and destructors, the
// release of its entries, the start of changes. The reference counts are its
// header's.
#define UNK_SIGFX_SHADERBINARYCACHEPACKAGE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderCache/SiGfx_ShaderCache_BinaryPackage_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_QSorter.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringCompare.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ShaderUtility_Impl.h>

// 0x71004c5520: copies at most count characters into size
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);
// 0x71004ed060, 0x71004ed070: names of a platform's graphics interface and
// shader language
const char* Unk_4ed060(u32 index);
const char* Unk_4ed070(u32 index);
// 0x710057d030: SiIO's kernel
u64 Unk_57d030_get();
// 0x71004c5630: compares two strings (-1, 0 or 1)
s64 Unk_4c5630(const char* a, const char* b, bool caseSensitive);

// 0x71004ee870: a shader's name in the package, from its request
// (placeholder name and types: the format helpers' file)
void Unk_4ee870(const SiSDK3::Unk_4e7710_Request* request, SiSDK3::SiString<char>* name);

namespace SiSDK3 {

// 0x71004e8460
SiGfxShaderBinaryCachePackage::SiGfxShaderBinaryCachePackage(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_68(pAllocator), field_b8(pAllocator),
      field_108(pAllocator), field_158(0), field_15c(false), field_1e0(0) {
    memset(&field_160, 0, sizeof(field_160));
}

// 0x71004e8590 (D2), 0x71004e8af0 (D0)
SiGfxShaderBinaryCachePackage::~SiGfxShaderBinaryCachePackage() {
    Unk_4e8750();
}

// 0x71004e8750
void SiGfxShaderBinaryCachePackage::Unk_4e8750() {
    Unk_566a00(field_8.m_pAllocator, &field_18, false);
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        Entry* entry = &field_68.m_pData[i];
        if (entry->field_28 != nullptr) {
            entry->field_28->vf3();
            entry->field_28 = nullptr;
        }
    }
    field_108.Unk_FreeAll();
    field_68.Unk_FreeAll();
    field_b8.Unk_FreeAll();
}

// 0x71004e8b20
bool SiGfxShaderBinaryCachePackage::Unk_4e8b20() {
    return true;
}

// 0x71004e8c60: starts changes (counted): the entries become shaders being
// edited
bool SiGfxShaderBinaryCachePackage::vf5() {
    if (field_158++ == 0) {
        field_15c = false;
        if (field_68.m_itemCount != 0) {
            field_18.Unk_ReserveAtLeast(field_68.m_itemCount);
            for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
                Entry* entry = &field_68.m_pData[i];
                vf7(entry->field_18, entry->field_c, entry->field_20);
            }
            field_15c = true;
        }
    }
    return true;
}

// 0x71004ea060
void SiGfxShaderBinaryCachePackage::Unk_4ea060(SiGfxNXDevice* device) {
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        Entry* entry = &field_68.m_pData[i];
        if (entry->field_28 != nullptr && entry->field_28->vf5() == device) {
            if (entry->field_28 != nullptr) {
                entry->field_28->vf3();
                entry->field_28 = nullptr;
            }
        }
    }
}

// The entries in the order of their names' hashes (placeholder name)
struct Unk_EntryCompare {
    static int Unk_Compare(SiGfxShaderBinaryCachePackage::Entry* a, SiGfxShaderBinaryCachePackage::Entry* b) {
        if (a->field_10 > b->field_10) {
            return 1;
        }
        if (a->field_10 < b->field_10) {
            return -1;
        }
        return 0;
    }
};

// 0x71004e8d50: ends changes (counted): the shaders being edited become the
// package's entries, their names and code in one block, sorted by name
// NON_MATCHING: two things. The sorter's test of its room is `cmp x8, #1 ;
// b.lt` in the original and `cmp x8, #0 ; b.le` here (every spelling of the
// test tried), and in the copies' loop the code's block and the name's offset
// are in each other's registers for the name's copy. The rest is the
// original's.
void SiGfxShaderBinaryCachePackage::vf6() {
    if (static_cast<s32>(field_158) <= 0) {
        return;
    }
    if (--field_158 != 0) {
        return;
    }
    field_68.Unk_SetCount(field_18.m_itemCount);
    field_b8.Unk_SetCount(field_18.m_itemCount);
    s64 i;
    s32 offset = 0;
    for (i = 0; i < static_cast<s32>(field_18.m_itemCount); i++) {
        EditEntry* edit = field_18.m_pData[i];
        Entry* entry = &field_68.m_pData[i];
        field_b8.m_pData[i] = entry;
        entry->field_14 = i;
        entry->field_0 = offset;
        entry->field_4 = edit->field_0.field_10;
        offset += (edit->field_0.field_10 + 0x10) & ~0xf;
        entry->field_8 = offset;
        entry->field_c = edit->field_30.m_itemCount;
        offset += (edit->field_30.m_itemCount + 0xf) & ~0xf;
    }
    if (static_cast<s64>(offset) >= 1) {
        field_108.Unk_SetCount(offset);
        memset(field_108.m_pData, 0, offset);
        for (s64 i = 0; i < static_cast<s32>(field_18.m_itemCount); i++) {
            EditEntry* edit = field_18.m_pData[i];
            Entry* entry = &field_68.m_pData[i];
            memcpy(field_108.m_pData + entry->field_0, edit->field_0.m_pBuffer, entry->field_4);
            s32 end = entry->field_0 + entry->field_4;
            field_108.m_pData[end] = 0;
            memcpy(field_108.m_pData + entry->field_8, edit->field_30.m_pData, entry->field_c);
            s32 name = entry->field_0;
            entry->field_18 = reinterpret_cast<const char*>(&field_108.m_pData[name]);
            entry->field_10 = Unk_4c34a0(entry->field_18);
            s32 code = entry->field_8;
            entry->field_20 = &field_108.m_pData[code];
        }
    }
    if (field_b8.m_itemCount != 0) {
        SiQSorter<Entry*, Unk_EntryCompare> sorter(field_8.m_pAllocator);
        sorter.Unk_Reserve(field_b8.m_itemCount);
        sorter.Unk_Sort(field_b8.m_itemCount, field_b8.m_pData);
        Unk_566a00(field_8.m_pAllocator, &field_18, false);
    }
}

// 0x71004e9410: adds a shader's code while changes are started, or replaces
// the code of the shader being edited of that name
bool SiGfxShaderBinaryCachePackage::vf7(const char* name, s32 size, const void* code) {
    if (static_cast<s32>(field_158) < 1) {
        return false;
    }
    EditEntry* entry = nullptr;
    if (field_15c) {
        for (s64 i = 0; i < static_cast<s32>(field_18.m_itemCount); i++) {
            if (Unk_CompareNoCase(&field_18.m_pData[i]->field_0, name) == 0) {
                entry = field_18.m_pData[i];
                break;
            }
        }
    }
    if (entry != nullptr) {
        Unk_StringAssign(&entry->field_0, name);
        entry->field_30.Unk_SetCount(size);
        memcpy(entry->field_30.m_pData, code, size);
        return true;
    }
#line 245
    entry = UNK_SI_NEW(field_8.m_pAllocator, 0x10) EditEntry(field_8.m_pAllocator);
    Unk_StringAssign(&entry->field_0, name);
    entry->field_30.Unk_SetCount(size);
    memcpy(entry->field_30.m_pData, code, size);
    field_18.Unk_Add(entry);
    return true;
}

// 0x71004e9740: writes the package to a file
bool SiGfxShaderBinaryCachePackage::vf8(const char* path, u32 platform, u32 a3) {
    Unk_4e9740_Header header;
    memset(&header, 0, sizeof(header));
    Unk_4c5520(header.field_0, sizeof(header.field_0), "SSKKShaderBinCache", -1);
    Unk_4c5520(header.field_20, sizeof(header.field_20), Unk_4ed060(platform), -1);
    Unk_4c5520(header.field_28, sizeof(header.field_28), Unk_4ed070(a3), -1);
    header.field_30 = true;
    header.field_40 = 3;
    header.field_44 = 0;
    header.field_48 = 0;
    header.field_4c = 1;
    s32 count = static_cast<s32>(field_68.m_itemCount);
    header.field_50 = count;
    header.field_54 = sizeof(header);
    s32 size = static_cast<s32>(field_108.m_itemCount);
    header.field_58 = (sizeof(header) + size + 0xf) & ~0xf;
    header.field_5c = header.field_58 + count * 0x20;
    header.field_60 = size;
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 0x15, nullptr);
    if (stream == nullptr) {
        return false;
    }
    stream->vf44(&header, sizeof(header), true);
    if (field_108.m_itemCount != 0) {
        stream->vf44(field_108.m_pData, field_108.m_itemCount, true);
    }
    for (s32 pos = static_cast<s32>(stream->vf17()); pos < header.field_58; pos++) {
        stream->vf52(0, true);
    }
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        Entry* entry = &field_68.m_pData[i];
        stream->vf50(entry->field_0, true);
        stream->vf50(entry->field_4, true);
        stream->vf50(entry->field_8, true);
        stream->vf50(entry->field_c, true);
        stream->vf54(entry->field_10, true);
        stream->vf50(entry->field_14, true);
        stream->vf50(0, true);
        stream->vf50(0, true);
    }
    for (s64 i = 0; i < static_cast<s32>(field_b8.m_itemCount); i++) {
        stream->vf50(field_b8.m_pData[i]->field_14, true);
    }
    stream->vf3();
    return true;
}

// 0x71004e9a30: reads the package from a file
bool SiGfxShaderBinaryCachePackage::vf9(const char* path) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 9, nullptr);
    if (stream == nullptr) {
        return false;
    }
    stream->vf21(&field_160, sizeof(field_160), true);
    if (Unk_4c5630(field_160.field_0, "SSKKShaderBinCache", true) != 0 || field_160.field_40 != 3 ||
        field_160.field_44 != 0 || field_160.field_48 != 0 || field_160.field_4c != 1) {
        stream->vf3();
        return false;
    }
    field_108.Unk_SetCount(field_160.field_60);
    field_68.Unk_SetCount(field_160.field_50);
    field_b8.Unk_SetCount(field_160.field_50);
    stream->vf18(field_160.field_54, false);
    if (field_108.m_itemCount != 0) {
        stream->vf21(field_108.m_pData, field_160.field_60, true);
    }
    stream->vf18(field_160.field_58, false);
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        Entry* entry = &field_68.m_pData[i];
        entry->field_0 = stream->vf27(true);
        entry->field_4 = stream->vf27(true);
        entry->field_8 = stream->vf27(true);
        entry->field_c = stream->vf27(true);
        entry->field_10 = stream->vf31(true);
        entry->field_14 = stream->vf27(true);
        stream->vf27(true);
        stream->vf27(true);
        s32 name = entry->field_0;
        entry->field_18 = reinterpret_cast<const char*>(&field_108.m_pData[name]);
        s32 code = entry->field_8;
        entry->field_20 = &field_108.m_pData[code];
    }
    stream->vf18(field_160.field_5c, false);
    for (s64 i = 0; i < static_cast<s32>(field_b8.m_itemCount); i++) {
        s32 index = stream->vf27(true);
        field_b8.m_pData[i] = &field_68.m_pData[index];
    }
    stream->vf3();
    return true;
}

inline s32 SiGfxShaderBinaryCachePackage::Unk_FindEntry(u32 hash) {
    s32 count = static_cast<s32>(field_b8.m_itemCount);
    Entry** entries = field_b8.m_pData;
    s32 high = count - 1;
    s32 low = 0;
    while (low < high - 1) {
        s32 middle = (low + high) >> 1;
        u32 value = entries[middle]->field_10;
        if (value > hash) {
            high = middle;
        } else if (value < hash) {
            low = middle;
        } else {
            return middle;
        }
    }
    if (entries[low]->field_10 == hash) {
        return low;
    }
    if (entries[high]->field_10 == hash) {
        return high;
    }
    return -1;
}

// 0x71004e9dd0: the shader of a request on a device, compiled from the
// package's code the first time
// NON_MATCHING: the search's end. The original reads the entry again from its
// index after the search (`ldr x22, [x8, w10, sxtw #3]`) and keeps the
// search's bounds in other registers; here GVN takes the entry the search
// compared. Written with an index set by the search and a break, the entry is
// read again but the not-found result becomes a select (`csel`), which the
// original doesn't have: it seems the not-found path was threaded to the null
// return only after GVN there.
void* SiGfxShaderBinaryCachePackage::vf10(const void* a1, void* a2) {
    if (a2 == nullptr) {
        return nullptr;
    }
    if (field_68.m_itemCount == 0 || field_b8.m_itemCount == 0 || field_108.m_itemCount == 0) {
        return nullptr;
    }
    const Unk_4e7710_Request* request = static_cast<const Unk_4e7710_Request*>(a1);
    SiGfxNXDevice* device = static_cast<SiGfxNXDevice*>(a2);
    Unk_NXString<0x400> name(field_8.m_pAllocator);
    Unk_4ee870(request, &name);
    s32 index = Unk_FindEntry(Unk_4c3510(&name));
    if (index < 0) {
        return nullptr;
    }
    Entry* entry = field_b8.m_pData[index];
    Unk_596640 lock(&field_1e0, true);
    if (entry->field_28 != nullptr) {
        if (entry->field_28->vf5() != device) {
            return nullptr;
        }
        return entry->field_28;
    }
    entry->field_28 = reinterpret_cast<Unk_BinaryCacheObject*>(device->vf42(request->field_58, nullptr, 0, nullptr));
    if (entry->field_28 == nullptr) {
        return nullptr;
    }
    if (!entry->field_28->vf18(entry->field_c, entry->field_20, 0)) {
        if (entry->field_28 != nullptr) {
            entry->field_28->vf3();
            entry->field_28 = nullptr;
        }
        return nullptr;
    }
    return entry->field_28;
}

// 0x71004ea4e0
SiGfxShaderBinaryCachePackage::EditEntry::~EditEntry() {
    field_0.Unk_Clear();
    field_30.Unk_FreeAll();
}

// 0x71004ea780: the entries' reserve (vf6 and vf9, not written yet, call it)
template bool SiArray<SiGfxShaderBinaryCachePackage::Entry, 16>::Unk_4bf190(size_t, bool);

}  // namespace SiSDK3
