// Scope: common
// SiSDK3::SiGfxNXQuery: its construction and destruction, its buffer, its
// name, and the reference counts its header defines. (Its small accessors are
// lib/yebis/class's.)
#define UNK_SIGFX_NX_QUERY_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Query_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>

namespace SiSDK3 {

// 0x7100554870
SiGfxNXQuery::SiGfxNXQuery(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_60(0), field_158(false) {
    memset(&field_78, 0, sizeof(field_78));
    field_c0 = nullptr;
    field_c8 = 0;
    field_d0 = 0;
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 9;
}

// 0x7100554900 (D2), 0x7100554a40 (D0); 0x71005549a0 and 0x7100554ae0 are
// their thunks for the second base
SiGfxNXQuery::~SiGfxNXQuery() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf19();
}

// 0x7100554b90 (0x7100554bd0: its thunk)
bool SiGfxNXQuery::vf20(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    return true;
}

// 0x7100554c10 (0x7100554c20: its thunk)
const SiString<char>* SiGfxNXQuery::vf21() {
    return &field_30;
}

// 0x7100554c30 (0x7100554c40: its thunk)
u32 SiGfxNXQuery::vf22() {
    return field_60;
}

// 0x7100554d00
bool SiGfxNXQuery::vf18(const Unk_Desc* desc) {
    void* device = Unk_NXDevice(field_20)->vf85();
    u64 builder[8] = {};  // NVNbufferBuilder
    nvnBufferBuilderSetDefaults(builder);
    nvnBufferBuilderSetDevice(builder, device);
    int alignment = 0;
    nvnDeviceGetInteger(device, 10, &alignment);
    const u32 size = 0x10;
    size_t heapSize = Unk_NXAlign(size, alignment);
    field_c0 = vf5()->vf30(0, nullptr);
    Unk_NXMemoryHeapDesc heapDesc(heapSize);
    heapDesc.field_10 = 0;
    if (!field_c0->vf8(&heapDesc)) {
        return false;
    }
    if (!field_c0->Unk_552fc0(static_cast<s32>(heapSize), alignment, &field_c8)) {
        return false;
    }
    field_d0 = (field_c8 + alignment - 1) & -static_cast<s64>(alignment);
    nvnBufferBuilderSetStorage(builder, field_c0->vf16(), field_d0, size);
    if (Unk_nvnBufferInitialize(field_88, builder) != 1) {
        return false;
    }
    field_78.field_4 = desc->field_4;
    field_78.field_0 = desc->field_0;
    field_78.field_8 = size;
    field_b8 = nvnBufferGetAddress(field_88);
    field_158 = true;
    return true;
}

// 0x7100554ef0
void SiGfxNXQuery::vf19() {
    if (field_158) {
        nvnBufferFinalize(field_88);
        field_158 = false;
        memset(field_88, 0, sizeof(field_88));
        field_b8 = 0;
    }
    if (field_c0 != nullptr) {
        field_c0->Unk_553010(field_c8);
        field_c8 = 0;
        field_d0 = 0;
        if (field_c0 != nullptr) {
            field_c0->vf3();
            field_c0 = nullptr;
        }
    }
}

}  // namespace SiSDK3
