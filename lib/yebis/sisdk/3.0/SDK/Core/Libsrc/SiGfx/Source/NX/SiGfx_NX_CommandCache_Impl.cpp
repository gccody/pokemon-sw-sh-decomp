// Scope: common
// SiSDK3::SiGfxNXCommandCache: its construction and destruction, its command
// buffer, and the reference counts its header defines. (Its small accessors
// are lib/yebis/class's.)
#define UNK_SIGFX_NX_COMMANDCACHE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_CommandCache_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>

namespace SiSDK3 {

// Gives a heap's room back and releases the heap (placeholder name; the
// destructor takes the room's address before it tests the heap, which is what
// an inline function's reference parameter gives).
static inline void Unk_FreeRoom(SiGfxNXMemoryHeap*& heap, s64& offset) {
    if (heap != nullptr) {
        heap->Unk_553010(offset);
        if (heap != nullptr) {
            heap->vf3();
            heap = nullptr;
        }
    }
}

// 0x710054d430
SiGfxNXCommandCache::SiGfxNXCommandCache(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_f0(false) {
    memset(field_28, 0, sizeof(field_28));
    field_c8 = 0;
    field_d0 = nullptr;
    field_d8 = nullptr;
    field_e0 = 0;
    field_e8 = 0;
}

// 0x710054d4a0 (D2), 0x710054d580 (D0)
SiGfxNXCommandCache::~SiGfxNXCommandCache() {
    if (field_f0) {
        nvnCommandBufferFinalize(field_28);
        memset(field_28, 0, sizeof(field_28));
        field_f0 = false;
    }
    if (field_d8 != nullptr) {
#line 144
        SI_FREE(field_8.m_pAllocator, field_d8);
        field_d8 = nullptr;
    }
    Unk_FreeRoom(field_d0, field_e0);
    field_c8 = 0;
    field_e0 = 0;
    field_e8 = 0;
}

// 0x710054d660
bool SiGfxNXCommandCache::Unk_54d660(u32 kind) {
    field_20 = kind;
    void* device = Unk_NXDevice(field_18)->vf85();
    if (Unk_nvnCommandBufferInitialize(field_28, device) != 1) {
        return false;
    }
    int alignment = 0;
    int controlAlignment = 0;
    nvnDeviceGetInteger(device, 0x13, &alignment);
    nvnDeviceGetInteger(device, 0x14, &controlAlignment);
    const u32 size = 0x200;
    size_t heapSize = Unk_NXAlign(size, alignment);
    field_d0 = vf5()->vf30(0, nullptr);
    Unk_NXMemoryHeapDesc heapDesc(heapSize);
    heapDesc.field_10 = 0;
    if (!field_d0->vf8(&heapDesc)) {
        return false;
    }
    if (!field_d0->Unk_552fc0(static_cast<s32>(heapSize), alignment, &field_e0)) {
        return false;
    }
    field_e8 = Unk_NXAlign(field_e0, alignment);
#line 111
    field_d8 = field_8.m_pAllocator->vf7(size, controlAlignment, __FILE__, __LINE__);
    if (field_d8 == nullptr) {
        nvnCommandBufferFinalize(field_28);
        return false;
    }
    nvnCommandBufferAddCommandMemory(field_28, field_d0->vf16(), field_e8, size);
    nvnCommandBufferAddControlMemory(field_28, field_d8, size);
    field_c8 = 0;
    field_f0 = true;
    return true;
}

}  // namespace SiSDK3
