// Scope: common
// SiSDK3::SiGfxNXCommandList: its construction and destruction, its command
// buffer and the memory NVN asks for while it records, and the reference
// counts its header defines. (Its small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_COMMANDLIST_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_CommandList_Impl.h>

namespace SiSDK3 {

// SiArray's RemoveByIndex as the original has it here (SiCore_Array.h's
// RemoveByIndex is the form its callers there show, where the assert is
// folded away): an assert that the build's NDEBUG doesn't compile out, at
// its line of the header, then the elements after it moved down (inline:
// the strings are the header's).
template <class T, int ALIGN>
inline void Unk_RemoveByIndexChecked(SiArray<T, ALIGN>* array, size_t iIndex) {
    if (!(iIndex < array->m_itemCount)) {
        __assert_fail("iIndex<m_itemCount", "../../../../Include\\SiCore/SiCore_Array.h", 1007, "RemoveByIndex");
    }
    for (s64 i = iIndex + 1; i < static_cast<s64>(array->m_itemCount); i++) {
        array->m_pData[i - 1] = array->m_pData[i];
    }
    array->m_itemCount--;
    array->Unk_UpdateRange();
}

// 0x7100539920
SiGfxNXCommandList::SiGfxNXCommandList(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice, void* pPool)
    : field_8(pAllocator), field_18(pDevice), field_20(pAllocator), field_50(pPool), field_80(0), field_88(nullptr),
      field_90(0), field_f0(nullptr), field_f8(0), field_120(false), field_121(false), field_124(), field_14c(0),
      field_150(pAllocator), field_1a0(pAllocator) {}

// 0x7100539a80 (D2), 0x7100539fd0 (D0)
SiGfxNXCommandList::~SiGfxNXCommandList() {
    Unk_539c40();
}

// 0x7100539c40
void SiGfxNXCommandList::Unk_539c40() {
    if (!field_121) {
        if (field_120) {
            if (nvnCommandBufferIsRecording(field_88)) {
                nvnCommandBufferEndRecording(field_88);
            }
            nvnCommandBufferFinalize(field_88);
            if (field_88 != nullptr) {
                if (field_8.m_pAllocator != nullptr) {
#line 187
                    SI_FREE(field_8.m_pAllocator, field_88);
                }
                field_88 = nullptr;
            }
            field_88 = nullptr;
            field_120 = false;
        }
        if (field_f0 != nullptr) {
#line 194
            SI_FREE(field_8.m_pAllocator, field_f0);
            field_f0 = nullptr;
        }
        for (s64 i = 0; i < static_cast<s32>(field_98.m_itemCount); i++) {
            if (field_98.m_pData[i] != nullptr) {
                field_98.m_pData[i]->Unk_553010(field_f8);
                if (field_98.m_pData[i] != nullptr) {
                    field_98.m_pData[i]->vf3();
                    field_98.m_pData[i] = nullptr;
                }
            }
        }
        for (size_t i = 0; i < field_150.m_itemCount; i++) {
            if (field_150.m_pData[i].field_0 != nullptr) {
                field_150.m_pData[i].field_0->vf3();
                field_150.m_pData[i].field_0 = nullptr;
            }
#line 210
            SI_FREE(field_8.m_pAllocator, field_150.m_pData[i].field_8);
        }
        for (size_t i = 0; i < field_1a0.m_itemCount; i++) {
            nvnSyncWait(field_1a0.m_pData[i].field_10, 0xffffffffffffffff);
            if (field_1a0.m_pData[i].field_0 != nullptr) {
                field_1a0.m_pData[i].field_0->vf3();
                field_1a0.m_pData[i].field_0 = nullptr;
            }
#line 216
            SI_FREE(field_8.m_pAllocator, field_1a0.m_pData[i].field_8);
        }
    }
    field_90 = 0;
    field_f8 = 0;
    field_100 = 0;
}

// (The heap's description is made by its constructor with the size, and its
// scope ends before the control memory is allocated: with it open to the end
// of the function, the branch for a failed vf8 isn't the original's.)
// 0x710053a000
bool SiGfxNXCommandList::Unk_53a000(u32 kind) {
    Unk_539c40();
    field_80 = kind;
    void* device = Unk_NXDevice(field_18)->vf85();
#line 92
    field_88 = field_8.m_pAllocator->vf7(0xa0, 0x10, __FILE__, __LINE__);
    if (field_88 == nullptr) {
        return false;
    }
    if (Unk_nvnCommandBufferInitialize(field_88, device) != 1) {
        return false;
    }
    nvnDeviceGetInteger(device, 0x13, &field_11c);
    nvnDeviceGetInteger(device, 0x14, &field_118);
    field_98.Unk_SetCount(1);
    field_98.m_pData[0] = vf5()->vf30(0, nullptr);
    const u32 size = 0x80000;
    size_t heapSize = Unk_NXAlign(size, field_11c);
    {
    Unk_NXMemoryHeapDesc heapDesc(heapSize);
    heapDesc.field_30 = 0x22;
    if (!field_98.m_pData[0]->vf8(&heapDesc)) {
        return false;
    }
    if (!field_98.m_pData[0]->Unk_552fc0(static_cast<s32>(heapSize), field_11c, &field_f8)) {
        return false;
    }
    }
    field_100 = (field_f8 + field_11c - 1) & -static_cast<s64>(field_11c);
#line 138
    field_f0 = field_8.m_pAllocator->vf7(0x10000, field_118, __FILE__, __LINE__);
    if (field_f0 == nullptr) {
        nvnCommandBufferFinalize(field_88);
        return false;
    }
    vf17();
    field_108 = 0x10000;
    field_110 = size;
    nvnCommandBufferSetMemoryCallback(field_88, Unk_53a310);
    nvnCommandBufferSetMemoryCallbackData(field_88, this);
    field_90 = 0;
    field_120 = true;
    field_121 = false;
    return true;
}

// NVN's memory callback (its data is the command list): event 0 asks for
// command memory, 1 for control memory. (The heaps are read through the
// array's operator[], which reads the index before the buffer.)
// 0x710053a310
void SiGfxNXCommandList::Unk_53a310(void* commandBuffer, int event, size_t minSize, void* data) {
    SiGfxNXCommandList* self = static_cast<SiGfxNXCommandList*>(data);
    if (self->field_121) {
        return;
    }
    switch (event) {
    case 0: {
        self->field_58.vf2();
        size_t size = static_cast<s32>(self->field_98[self->field_e8]->vf7()->field_0) + minSize;
        SiGfxNXMemoryHeap* heap;
        if (self->field_e8 < static_cast<s32>(self->field_98.m_itemCount) - 1) {
            heap = self->field_98.m_pData[self->field_e8 + 1];
        } else {
            s64 alignment = self->field_11c;
            heap = self->vf5()->vf30(0, nullptr);
            size_t heapSize = (alignment - 1 + size) & -alignment;
            Unk_NXMemoryHeapDesc heapDesc(heapSize);
            heapDesc.field_30 = 0x22;
            if (!heap->vf8(&heapDesc)) {
                return;
            }
            if (!heap->Unk_552fc0(static_cast<s32>(heapSize), alignment, &self->field_f8)) {
                return;
            }
            self->field_100 = (self->field_f8 + alignment - 1) & -alignment;
            self->field_98.Unk_Add(heap);
        }
        if (heap != nullptr) {
            nvnCommandBufferAddCommandMemory(self->field_88, heap->vf16(), self->field_100, size);
            memcpy(heap->field_448, self->field_98[self->field_e8]->field_448,
                   static_cast<s32>(self->field_98[self->field_e8]->vf7()->field_0));
            self->field_110 = size;
        }
        self->field_58.vf3();
        break;
    }
    case 1: {
        self->field_58.vf2();
        size_t size = self->field_108 * 2 > self->field_108 + minSize ? self->field_108 * 2 : self->field_108 + minSize;
#line 478
        void* memory = self->field_8.m_pAllocator->vf7(size, self->field_118, __FILE__, __LINE__);
        if (memory != nullptr) {
            nvnCommandBufferAddControlMemory(self->field_88, memory, size);
            size_t index = self->field_150.m_itemCount;
            self->field_150.Unk_SetCount(index + 1);
            OverwrittenEntry& entry = self->field_150.m_pData[index];
            entry.field_0 = nullptr;
            entry.field_8 = self->field_f0;
            self->field_f0 = memory;
            self->field_108 = size;
        }
        self->field_58.vf3();
        break;
    }
    }
}

// 0x710053a660
bool SiGfxNXCommandList::vf7(const char* name) {
    Unk_4c4700(&field_20, const_cast<char*>(name));
    return true;
}

// 0x710053a6f0
void SiGfxNXCommandList::vf17() {
    if (field_121) {
        return;
    }
    field_58.vf2();
    field_e8 = 0;
    nvnCommandBufferAddCommandMemory(field_88, field_98.m_pData[0]->vf16(), field_100, 0x80000);
    nvnCommandBufferAddControlMemory(field_88, field_f0, 0x10000);
    field_58.vf3();
}

// NON_MATCHING: 12 bytes short. The removal's guard compares the count with
// the index (`cmp x10, x8 ; b.le`) where this compares the index with the
// count, and the original keeps the addresses of field_150's count and data
// in two spilled registers across the second loop for the inline free at its
// end (this addresses them from `this`).
// 0x710053a790
// (Round 5: the removal's loop written `count > i`, as a while, from the
// index with `count - 1`, the count in a local: the same or worse.)
void SiGfxNXCommandList::Unk_53a790() {
    // the memory that the GPU is past is let go of
    size_t i = 0;
    while (i < field_1a0.m_itemCount) {
        DiscontinuedEntry* entry = &field_1a0.m_pData[i];
        if (nvnSyncWait(entry->field_10, 0) == 0) {
            if (entry->field_0 != nullptr) {
                entry->field_0->vf3();
                entry->field_0 = nullptr;
            }
#line 367
            SI_FREE(field_8.m_pAllocator, entry->field_8);
            Unk_RemoveByIndexChecked(&field_1a0, i);
        } else {
            i++;
        }
    }
    // what NVN replaced while it recorded waits for the commands
    if (field_150.m_itemCount != 0) {
        size_t base = field_1a0.m_itemCount;
        for (size_t j = 0; j < field_150.m_itemCount; j++) {
            field_1a0.Unk_SetCount(base + field_150.m_itemCount);
            DiscontinuedEntry* entry = &field_1a0.m_pData[base + j];
            static_cast<OverwrittenEntry&>(*entry) = field_150.m_pData[j];
            nvnSyncInitialize(entry->field_10, Unk_NXDevice(field_18)->vf85());
            nvnCommandBufferFenceSync(field_88, entry->field_10, 0, 1);
        }
        field_150.Unk_4e3050();
    }
    field_90 = nvnCommandBufferEndRecording(field_88);
}

// 0x710053aac0
bool SiGfxNXCommandList::vf18(void* commandBuffer) {
    if (commandBuffer != nullptr) {
        if (!field_121) {
            Unk_539c40();
        }
    } else if (!field_121) {
        return false;
    }
    field_88 = commandBuffer;
    field_90 = 0;
    field_121 = true;
    return true;
}

}  // namespace SiSDK3
