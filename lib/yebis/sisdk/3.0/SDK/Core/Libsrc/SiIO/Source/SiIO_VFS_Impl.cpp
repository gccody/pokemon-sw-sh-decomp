// Scope: common
// SiSDK3::SiIOVFS.
#define UNK_SIIO_VFS_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_VFS_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_MemoryStream_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_VFSManager_Impl.h>

// 0x710057cfb0: SiIO's kernel (leafgen's name), 0x710057d840: its archive
// manager (leafgen's name and types), 0x710057d030: the kernel as a number
// (leafgen's name and type)
struct Unk_57d840;
Unk_57d840* Unk_57cfb0();
u64 Unk_57d840_get(const Unk_57d840* self);
u64 Unk_57d030_get();
// 0x7100587510 (leafgen's name and type): an entry's initialisation
bool Unk_587510_get(u64 entry);
// 0x71004e4230: a path's directory, 0x71004c8020: a string's assignment,
// 0x71004ca0b0: replaces a substring, 0x71004c5630: compares
SiSDK3::SiString<char> Unk_4e4230(SiSDK3::SiString<char>* path);
void Unk_4c8020(SiSDK3::SiString<char>* self, const SiSDK3::SiString<char>* other);
void Unk_4ca0b0(SiSDK3::SiString<char>* self, const char* from, const char* to, u64, u64, bool);
s64 Unk_4c5630(const char* a, const char* b, bool);

// 0x71024e9360: the empty string a string without a buffer reads as
extern char Unk_24e9360[];

namespace SiSDK3 {

// 0x7100586910: sorts entries by field_88 (a member of an empty class: its
// caller passes the address of a local)
struct Unk_586910 {
    bool Unk_586910_Sort(s64 count, SiIOVFSEntry** entries);
};

namespace {

// SiIO's kernel: slot 11 makes a mapped file.
class Unk_IOKernelInterface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual Unk_MappedFileInterface* vf11(void*);
};

inline SiIOVFSManager* Unk_GetVFSManager() {
    return reinterpret_cast<SiIOVFSManager*>(Unk_57d840_get(Unk_57cfb0()));
}

template <class T>
inline void Unk_Release(T*& p) {
    if (p != nullptr) {
        p->vf3();
        p = nullptr;
    }
}

}  // namespace

// 0x7100583d80
SiIOVFS::SiIOVFS(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(false), field_19(false), field_1a(0), field_1c(0), field_20(nullptr),
      field_28(pAllocator), field_58(pAllocator), field_88(pAllocator), field_b8(pAllocator), field_e8(nullptr),
      field_f0(0), field_f8(pAllocator), field_148(pAllocator) {}

// 0x7100583f00 (D2), 0x71005843e0 (D0)
SiIOVFS::~SiIOVFS() {
    field_19 = false;
    // what vf6 does, spelled out again: the original inlines it here, which a
    // call of vf6 or of a shared inline function isn't small enough for
    Unk_Release(field_e8);
    field_f8.Unk_4e3050();
    field_148.Unk_4e3050();
    if (field_20 != nullptr) {
        field_20->vf6();
        Unk_Release(field_20);
    }
    Unk_Release(field_e8);
    if (Unk_GetVFSManager() != nullptr) {
        Unk_GetVFSManager()->Unk_583a80(this);
    }
}

// 0x7100584420
bool SiIOVFS::vf5(const char* path, const char* root) {
    vf6();
    field_20 = reinterpret_cast<Unk_IOKernelInterface*>(Unk_57d030_get())->vf11(nullptr);
    if (field_20 == nullptr) {
        return false;
    }
    if (!field_20->vf5(path, 0x29)) {
        Unk_Release(field_20);
        return false;
    }
    Unk_StringAssign(&field_28, path);
    if (root != nullptr) {
        Unk_StringAssign(&field_58, root);
    } else {
        SiString<char> directory = Unk_4e4230(&field_28);
        Unk_4c8020(&field_58, &directory);
    }
    Unk_4ca0b0(&field_58, "\\", "/", 0, 0, true);
    field_18 = true;
    SiIOMemoryStream stream(field_8.m_pAllocator);
    stream.SiIOMemoryStream::vf75(field_20->vf10(), field_20->vf7());
    Unk_Header header;
    bool result;
    if (Unk_5845e0(reinterpret_cast<ISiIOStream*>(&stream), &header)) {
        result = Unk_584750(reinterpret_cast<ISiIOStream*>(&stream), &header);
    } else {
        result = false;
    }
    return result;
}

// 0x71005845e0
bool SiIOVFS::Unk_5845e0(ISiIOStream* stream, Unk_Header* header) {
    bool result = false;
    stream->vf21(header, 8, true);
    if (Unk_4c5630(header->field_0, "SiIOVFS", true) == 0) {
        header->field_8 = stream->vf29(true);
        if (static_cast<u8>(header->field_8 - 1) <= 1) {
            stream->vf13(header->field_8);
            header->field_9 = stream->vf29(true);
            header->field_a = stream->vf29(true);
            header->field_b = stream->vf29(true);
            header->field_10 = stream->vf27(true);
            header->field_14 = stream->vf27(true);
            header->field_18 = stream->vf28(true);
            header->field_20 = stream->vf28(true);
            header->field_28 = stream->vf28(true);
            field_f0 = header->field_28;
            result = true;
        }
    }
    return result;
}

// 0x7100584750
bool SiIOVFS::Unk_584750(ISiIOStream* stream, Unk_Header* header) {
    if (header->field_18 > 0) {
        if (!field_f8.Unk_SetCount(header->field_18)) {
            return false;
        }
        if (!field_148.Unk_SetCount(header->field_18)) {
            return false;
        }
        for (s64 i = 0; i < header->field_18; i++) {
            SiIOVFSEntry* entry = &field_f8.m_pData[i];
            entry->field_18 = this;
            entry->field_b8 = i;
            Unk_5848c0(stream, header, entry);
        }
        field_e8 = field_f8.m_pData;
        field_e8->vf2();
        if (field_e8 != nullptr) {
            Unk_586310(field_e8);
        }
    }
    return true;
}

// 0x71005848c0
// NON_MATCHING: w23 and w24 are swapped (the value for field_88 and the directory flag): three
// long values are evicted to the stack for them, and the allocator picks them in another order.
bool SiIOVFS::Unk_5848c0(ISiIOStream* stream, Unk_Header* header, SiIOVFSEntry* entry) {
    s64 offset = stream->vf28(true);
    s64 size = stream->vf28(true);
    s64 index = stream->vf28(true);
    s64 count118 = stream->vf28(true);
    s64 countC8 = stream->vf28(true);
    s64 valueA0 = stream->vf28(true);
    s32 valueB0 = stream->vf27(true);
    u32 value88 = stream->vf31(true);
    u8 directory = stream->vf29(true);
    stream->vf29(true);
    stream->vf29(true);
    stream->vf29(true);
    stream->vf37(&entry->field_28, true);
    entry->field_8c = directory != 0;
    entry->field_c0 = index;
    entry->field_a0 = valueA0;
    entry->field_b0 = valueB0;
    entry->field_88 = value88;
    entry->field_90 = header->field_28 + offset;
    entry->field_98 = size;
    entry->field_a8 = field_20->vf10() + entry->field_90;
    field_148.m_pData[entry->field_c0] = entry;
    if (entry->vf11()) {
        entry->field_118.Unk_SetCount(count118);
        entry->field_c8.Unk_SetCount(countC8);
        for (s64 i = 0; i < entry->vf15(); i++) {
            SiIOVFSEntry* child = &field_f8.m_pData[stream->vf27(true)];
            child->field_20 = entry;
            entry->field_118.m_pData[i] = child;
            child->vf2();
        }
        for (s64 i = 0; i < entry->vf12(); i++) {
            SiIOVFSEntry* child = &field_f8.m_pData[stream->vf27(true)];
            child->field_20 = entry;
            entry->field_c8.m_pData[i] = child;
            child->vf2();
        }
    }
    return true;
}

// 0x7100584c30
void SiIOVFS::vf6() {
    Unk_Release(field_e8);
    field_f8.Unk_4e3050();
    field_148.Unk_4e3050();
    if (field_20 != nullptr) {
        field_20->vf6();
        Unk_Release(field_20);
    }
}

// 0x71005856e0
void SiIOVFS::vf19(const char* s) {
    Unk_StringAssign(&field_88, s);
}

// 0x7100585700
SiIOVFSEntry* SiIOVFS::vf21() {
#line 638
    SiIOVFSEntry* entry = UNK_NEW(field_8.m_pAllocator, 0x10) SiIOVFSEntry(field_8.m_pAllocator, this);
    if (entry != nullptr && !Unk_587510_get(reinterpret_cast<u64>(entry))) {
        entry->vf3();
        entry = nullptr;
    }
    return entry;
}

// 0x7100585ca0
void SiIOVFS::Unk_585ca0(SiArray<SiIOVFSEntry*>* list) {
    if (field_e8 == nullptr) {
        return;
    }
    list->Unk_Add(field_e8);
    Unk_586750(list, field_e8);
    for (s32 i = 0; i < static_cast<s32>(list->m_itemCount); i++) {
        list->m_pData[i]->field_b8 = i;
    }
}

// 0x7100585d70
void SiIOVFS::Unk_585d70(SiArray<SiIOVFSEntry*>* list, SiArray<SiIOVFSEntry*>* sorted) {
    sorted->Unk_SetCount(list->m_itemCount);
    for (s32 i = 0; i < static_cast<s32>(list->m_itemCount); i++) {
        sorted->m_pData[i] = list->m_pData[i];
    }
    Unk_586910 sorter;
    sorter.Unk_586910_Sort(static_cast<s32>(sorted->m_itemCount), sorted->m_pData);
    for (s32 i = 0; i < static_cast<s32>(sorted->m_itemCount); i++) {
        sorted->m_pData[i]->field_c0 = i;
    }
}

// 0x7100585e70
bool SiIOVFS::Unk_585e70(ISiIOStream* stream, void*, SiIOVFSEntry* entry, s64* offset) {
    u8 directory = entry->vf11();
    s64 count118 = static_cast<s32>(entry->vf15());
    s64 countC8 = static_cast<s32>(entry->vf12());
    s64 start = *offset;
    s64 index = entry->field_c0;
    u32 value88 = entry->field_88;
    s64 advance;
    s32 valueB0;
    s64 valueA0;
    s64 size;
    if (entry->vf11()) {
        valueB0 = 0;
        valueA0 = 0;
        size = 0;
        advance = 0;
    } else {
        size = entry->vf18();
        valueA0 = entry->field_a0;
        valueB0 = entry->field_b0;
        advance = valueA0 > 0 ? valueA0 : size;
    }
    stream->vf51(start, true);
    stream->vf51(size, true);
    stream->vf51(index, true);
    stream->vf51(count118, true);
    stream->vf51(countC8, true);
    stream->vf51(valueA0, true);
    stream->vf50(valueB0, true);
    stream->vf54(value88, true);
    stream->vf52(directory, true);
    stream->vf52(0, true);
    stream->vf52(0, true);
    stream->vf52(0, true);
    *offset += advance;
    SiString<char>* name = entry->vf9();
    stream->vf60(name->m_pBuffer != nullptr ? name->m_pBuffer : Unk_24e9360, true);
    if (entry->vf11()) {
        for (s32 i = 0; i < static_cast<s32>(entry->vf15()); i++) {
            stream->vf50(static_cast<s32>(entry->vf16(i)->field_b8), true);
        }
        for (s32 i = 0; i < static_cast<s32>(entry->vf12()); i++) {
            stream->vf50(static_cast<s32>(entry->vf13(i)->field_b8), true);
        }
    }
    return true;
}

// 0x71005861a0
bool SiIOVFS::vf23() {
    if (field_1c++ != 0) {
        return true;
    }
#line 917
    field_e8 = UNK_NEW(field_8.m_pAllocator, 0x10) SiIOVFSEntry(field_8.m_pAllocator, this);
    if (field_e8 == nullptr) {
        vf6();
        return false;
    }
    field_e8->field_8c = true;
    return true;
}

// 0x7100586240
bool SiIOVFS::vf24() {
    if (field_1c < 1) {
        return false;
    }
    field_1c--;
    return true;
}

// 0x7100586750
void SiIOVFS::Unk_586750(SiArray<SiIOVFSEntry*>* list, SiIOVFSEntry* entry) {
    for (s32 i = 0; i < static_cast<s32>(entry->vf15()); i++) {
        list->Unk_Add(entry->vf16(i));
    }
    for (s32 i = 0; i < static_cast<s32>(entry->vf12()); i++) {
        SiIOVFSEntry* child = entry->vf13(i);
        list->Unk_Add(child);
        Unk_586750(list, child);
    }
}

// 0x7100586910
// NON_MATCHING: x19, x20 and x21 hold the entries, the count and `this` instead of the count,
// `this` and the entries (three live ranges of nearly the same size).
bool Unk_586910::Unk_586910_Sort(s64 count, SiIOVFSEntry** entries) {
    if (count > 1) {
        s64 pivot = 0;
        s64 middle = count / 2;
        if (middle < count) {
            SiIOVFSEntry* t = entries[0];
            entries[0] = entries[middle];
            entries[middle] = t;
            SiIOVFSEntry* key = entries[0];
            s64 i = 1;
            s64 j = count - 1;
            do {
                // (each scan tests its first element before the loop: only this
                // spelling keeps the original's two copies of the test)
                if (key->field_88 > entries[i]->field_88) {
                    do {
                        i++;
                        if (i >= j) {
                            break;
                        }
                    } while (key->field_88 > entries[i]->field_88);
                }
                if (key->field_88 <= entries[j]->field_88) {
                    do {
                        j--;
                        if (j <= i) {
                            break;
                        }
                    } while (key->field_88 <= entries[j]->field_88);
                }
                if (i < j) {
                    t = entries[i];
                    entries[i] = entries[j];
                    entries[j] = t;
                }
            } while (i <= j);
            pivot = i - 1;
            t = entries[0];
            entries[0] = entries[pivot];
            entries[pivot] = t;
        }
        Unk_586910_Sort(pivot, entries);
        Unk_586910_Sort(count - pivot - 1, entries + pivot + 1);
    }
    return true;
}

// 0x7100586260
s32 SiIOVFS::Unk_586260(SiIOVFSEntry* entry) {
    s32 count = static_cast<s32>(entry->vf15() + entry->vf12());
    for (s32 i = 0; i < static_cast<s32>(entry->vf12()); i++) {
        count += Unk_586260(entry->vf13(i));
    }
    return count;
}

}  // namespace SiSDK3
