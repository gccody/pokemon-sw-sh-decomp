// Scope: common
// SiSDK3::SiIOVFSEntry.
#define UNK_SIIO_VFSENTRY_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_VFSEntry_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_MemoryStream_Impl.h>

namespace SiSDK3 {

namespace {

// Releases every entry of an array and empties it.
inline void Unk_ReleaseAll(SiArray<SiIOVFSEntry*>* array) {
    for (size_t i = 0; i < array->m_itemCount; i++) {
        if (array->m_pData[i] != nullptr) {
            SiIOVFSEntry* entry = array->m_pData[i];
            array->m_pData[i] = nullptr;
            entry->vf3();
        }
    }
    array->Unk_4e3050();
}

}  // namespace

// 0x7100587260
SiIOVFSEntry::SiIOVFSEntry(ISiAllocator* pAllocator, SiIOVFS* pVFS)
    : field_8(pAllocator), field_18(pVFS), field_20(nullptr), field_28(pAllocator), field_58(pAllocator), field_88(0),
      field_8c(false), field_90(0), field_98(0), field_a0(0), field_a8(0), field_b0(0), field_b4(0), field_b8(-1),
      field_c0(-1), field_c8(pAllocator), field_118(pAllocator), field_168(0) {
    field_8f = false;
    field_8d = false;
    field_8e = false;
}

// 0x7100587390 (D2), 0x71005874e0 (D0)
SiIOVFSEntry::~SiIOVFSEntry() {
    Unk_587520();
}

// 0x7100587520
void SiIOVFSEntry::Unk_587520() {
    Unk_ReleaseAll(&field_c8);
    Unk_ReleaseAll(&field_118);
}

// 0x71005876d0
SiIOVFSEntry* SiIOVFSEntry::vf13(s64 index) {
    return field_c8.m_pData[index];
}

// 0x71005876e0
SiIOVFSEntry* SiIOVFSEntry::vf14(s64 index) {
    return field_c8.m_pData[index];
}

// 0x7100587700
SiIOVFSEntry* SiIOVFSEntry::vf16(s64 index) {
    return field_118.m_pData[index];
}

// 0x7100587710
SiIOVFSEntry* SiIOVFSEntry::vf17(s64 index) {
    return field_118.m_pData[index];
}

// 0x7100587730
ISiIOStream* SiIOVFSEntry::vf19() {
#line 257
    SiIOMemoryStream* stream = UNK_NEW(field_8.m_pAllocator, 0x10) SiIOMemoryStream(field_8.m_pAllocator);
    stream->vf75(field_a8, field_98);
    return reinterpret_cast<ISiIOStream*>(stream);
}

// 0x71005877a0
bool SiIOVFSEntry::vf20(const char* name) {
    Unk_StringAssign(&field_28, name);
    field_8c = true;
    return true;
}

// 0x71005877d0
bool SiIOVFSEntry::vf21(SiIOVFSEntry* entry) {
    if (entry == nullptr) {
        return false;
    }
    entry->vf2();
    entry->field_20 = this;
    field_c8.Unk_Add(entry);
    return true;
}

// 0x7100587890
bool SiIOVFSEntry::vf22(SiIOVFSEntry* entry) {
    if (entry == nullptr) {
        return false;
    }
    entry->vf2();
    entry->field_20 = this;
    field_118.Unk_Add(entry);
    return true;
}

// 0x7100587950
bool SiIOVFSEntry::vf23(const char* name, s32 valueB0, u64 value168, s64 size, s64 valueA0) {
    Unk_StringAssign(&field_28, name);
    field_8c = false;
    field_b0 = valueB0;
    field_168 = value168;
    field_98 = size;
    field_a0 = valueA0;
    return true;
}

}  // namespace SiSDK3
