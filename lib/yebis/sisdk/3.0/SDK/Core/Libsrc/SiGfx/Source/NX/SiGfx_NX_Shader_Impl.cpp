// Scope: common
// SiSDK3::SiGfxNXShader: its construction and destruction, its code, its
// name, and the reference counts its header defines. (Its small accessors are
// lib/yebis/class's.)
#define UNK_SIGFX_NX_SHADER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Shader_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>

// NVN's entry points that only the shader calls (nvn.h has them without
// their types).
inline void Unk_nvnMemoryPoolFlushMappedRange(const void* pool, s64 offset, size_t size) {
    reinterpret_cast<void (*)(const void*, s64, size_t)>(Unk_27fc9a8)(pool, offset, size);
}
inline u64 Unk_nvnMemoryPoolGetBufferAddress(const void* pool) {
    return reinterpret_cast<u64 (*)(const void*)>(Unk_27fc9b8)(pool);
}

namespace SiSDK3 {

// 0x710055ade0
SiGfxNXShader::SiGfxNXShader(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_60(0), field_88(0) {
    memset(&field_78, 0, sizeof(field_78));
    field_90 = 0;
    field_98 = 0;
    field_a0 = nullptr;
    field_a8 = nullptr;
    field_b0 = 0;
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 7;
}

// 0x710055ae80 (D2), 0x710055afc0 (D0); 0x710055af20 and 0x710055b060 are
// their thunks for the second base
SiGfxNXShader::~SiGfxNXShader() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf19();
}

// 0x710055b110 (0x710055b150: its thunk)
bool SiGfxNXShader::vf22(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    return true;
}

// 0x710055b190 (0x710055b1a0: its thunk)
const SiString<char>* SiGfxNXShader::vf23() {
    return &field_30;
}

// 0x710055b1b0 (0x710055b1c0: its thunk)
u32 SiGfxNXShader::vf24() {
    return field_60;
}

// The entries follow the header, found by integer arithmetic on the binary's
// address: LLVM keeps that address as a value of its own, and each read of
// entries[index] is a GEP of its own from it, so the entry's address is
// computed again in each block that reads it (`smaddl` before the
// allocation, `madd` after it), as the original's is. (An empty binary
// returns false, as the original's `cbz w8` does.)
// 0x710055b280
bool SiGfxNXShader::vf18(const void* desc, const Unk_Binary* binary) {
    vf19();
    if (desc == nullptr || binary == nullptr) {
        return false;
    }
    if (binary->field_0 != 0x19866891 || binary->field_4c == 0) {
        return false;
    }
    const Unk_BinaryEntry* entries = reinterpret_cast<const Unk_BinaryEntry*>(reinterpret_cast<uintptr_t>(binary) + sizeof(Unk_Binary));
    s32 index = -1;
    for (u32 i = 0; i < binary->field_4c; i++) {
        if (entries[i].field_8 == 0) {
            index = i;
            break;
        }
    }
    const u8* data = reinterpret_cast<const u8*>(binary) + entries[index].field_4;
#line 331
    field_a8 = UNK_ALLOC_ARRAY(field_10.m_pAllocator, u8, entries[index].field_3c, 8);
    if (field_a8 == nullptr) {
        return false;
    }
    const Unk_BinaryEntry& entry = entries[index];
    memcpy(field_a8, data + entry.field_30, entry.field_3c);
    s32 size = (entry.field_38 + 0xff) & ~0xff;
    if (field_a0 == nullptr) {
        size += 0x400;
        field_a0 = vf5()->vf30(0, nullptr);
        Unk_NXMemoryHeapDesc heapDesc;
        heapDesc.field_0 = size;
        heapDesc.field_24 = 1;
        heapDesc.field_30 = 0x62;
        if (!field_a0->vf8(&heapDesc)) {
            return false;
        }
    }
    if (!field_a0->Unk_552fc0(size, 0x100, &field_b0)) {
        return false;
    }
    s64 offset = Unk_NXAlign(field_b0, 0x100);
    memcpy(static_cast<u8*>(field_a0->field_450) + field_b0, data + entry.field_34, entry.field_38);
    Unk_nvnMemoryPoolFlushMappedRange(field_a0->vf16(), field_b0, size);
    field_98 = field_a8;
    field_90 = Unk_nvnMemoryPoolGetBufferAddress(field_a0->vf16()) + offset;
    return true;
}

// 0x710055b4d0
void SiGfxNXShader::vf19() {
    if (field_a8 != nullptr) {
        if (field_10.m_pAllocator != nullptr) {
#line 421
            SI_FREE(field_10.m_pAllocator, field_a8);
        }
        field_a8 = nullptr;
    }
    if (field_a0 != nullptr) {
        field_a0->Unk_553010(field_b0);
        field_b0 = 0;
        if (field_a0 != nullptr) {
            field_a0->vf3();
            field_a0 = nullptr;
        }
    }
    field_90 = 0;
    field_98 = 0;
}

}  // namespace SiSDK3
