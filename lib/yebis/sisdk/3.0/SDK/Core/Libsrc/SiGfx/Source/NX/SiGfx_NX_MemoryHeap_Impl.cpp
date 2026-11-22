// Scope: common
// SiSDK3::SiGfxNXMemoryHeap: its construction and destruction, its memory
// pool, the room it hands out, its name, and the reference counts its header
// defines. (Its small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_MEMORYHEAP_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>

namespace SiSDK3 {

// 0x71005528f0
SiGfxNXMemoryHeap::SiGfxNXMemoryHeap(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(pAllocator), field_58(0), field_74(0), field_78(false),
      field_180(nullptr), field_188(nullptr) {
    memset(&field_5c, 0, sizeof(field_5c));
    field_458 = nullptr;
    field_450 = nullptr;
    field_448 = nullptr;
    field_188.vf19(nullptr);
}

// 0x71005529a0 (D2), 0x7100552a90 (D0); 0x7100552a80 and 0x7100552ac0 are
// their thunks for the second base
SiGfxNXMemoryHeap::~SiGfxNXMemoryHeap() {
    SiGfxNXMemoryHeap::vf9();
}

// 0x7100552b00 (0x7100552b40: its thunk)
bool SiGfxNXMemoryHeap::vf17(const char* name) {
    Unk_4c4700(&field_28, const_cast<char*>(name));
    field_58 = Unk_4c3510(&field_28);
    return true;
}

// 0x7100552b80 (0x7100552b90: its thunk)
const SiString<char>* SiGfxNXMemoryHeap::vf18() {
    return &field_28;
}

// 0x7100552ba0 (0x7100552bb0: its thunk)
u32 SiGfxNXMemoryHeap::vf19() {
    return field_58;
}

// 0x7100552bf0
bool SiGfxNXMemoryHeap::vf8(const Unk_NXMemoryHeapDesc* desc) {
    if (field_78) {
        return false;
    }
    field_180 = field_10.m_pAllocator;
    Unk_NXKernelAllocatorSource* source = Unk_NXKernel()->vf37();
    if (source != nullptr) {
        if (source->vf6() != nullptr) {
            field_180 = source->vf6();
        }
    }
    s32 size = desc->field_0;
    size = size > 0x1000 ? size : 0x1000;
    size = (size + 0xfffu) & ~0xfffu;
#line 182
    field_448 = static_cast<u8*>(field_180->vf7(size, 0x1000, __FILE__, __LINE__));
    if (field_448 == nullptr) {
        return false;
    }
    if (desc->field_40 != nullptr) {
        memcpy(field_448, desc->field_40, desc->field_34);
    } else {
        memset(field_448, 0, size);
    }
    field_74 = desc->field_30;
    if (field_74 == 0) {
        field_74 = Unk_563620(10, desc->field_10, desc->field_18, desc->field_1c);
    }
    if (!(field_74 & 0x38)) {
        field_74 |= 0x20;
    }
    void* device = Unk_NXDevice(field_20)->vf85();
    u64 builder[8] = {};  // NVNmemoryPoolBuilder
    nvnMemoryPoolBuilderSetDefaults(builder);
    nvnMemoryPoolBuilderSetDevice(builder, device);
    nvnMemoryPoolBuilderSetFlags(builder, field_74);
    nvnMemoryPoolBuilderSetStorage(builder, field_448, size);
    if (nvnMemoryPoolInitialize(field_80, builder) != 1) {
#line 272
        SI_FREE(field_180, field_448);
        return false;
    }
    field_458 = field_448;
    if (field_74 & 6) {
        field_450 = nvnMemoryPoolMap(field_80);
    }
    s32 headerCount = desc->field_24;
    headerCount = headerCount > 1 ? headerCount : 1;
    field_188.vf21(field_10.m_pAllocator, headerCount, field_448, size);
    field_5c.field_0 = size;
    field_5c.field_c = desc->field_18;
    field_5c.field_8 = desc->field_14;
    field_5c.field_10 = desc->field_1c;
    field_5c.field_14 = desc->field_20;
    field_5c.field_4 = desc->field_10;
    field_78 = true;
    return true;
}

// 0x7100552e70
void SiGfxNXMemoryHeap::vf9() {
    field_188.vf23();
    if (field_78) {
        nvnMemoryPoolFinalize(field_80);
        field_78 = false;
    }
    if (field_448 != nullptr) {
#line 315
        SI_FREE(field_180, field_448);
        field_448 = nullptr;
    }
    field_458 = nullptr;
    field_450 = nullptr;
    field_180 = nullptr;
}

// 0x7100552f50
bool SiGfxNXMemoryHeap::Unk_552f50(const Unk_552f50_Arg* arg, s64* offset) {
    s64 result;
    if (!Unk_Alloc(arg->field_4, &result)) {
        return false;
    }
    *offset = result;
    return true;
}

// 0x7100552fc0
bool SiGfxNXMemoryHeap::Unk_552fc0(s64 size, s64 alignment, s64* offset) {
    return Unk_Alloc(size, offset);
}

// 0x7100553010
void SiGfxNXMemoryHeap::Unk_553010(s64 offset) {
    if (field_458 != nullptr) {
        u8* p = field_458 + offset;
#line 404
        field_188.vf9(p, __FILE__, __LINE__);
    }
}

inline bool SiGfxNXMemoryHeap::Unk_Alloc(s64 size, s64* offset) {
#line 411
    u8* p = static_cast<u8*>(field_188.vf7(size, 0, __FILE__, __LINE__));
    if (p == nullptr) {
        return false;
    }
    *offset = p - field_458;
    return *offset >= 0;
}

}  // namespace SiSDK3
