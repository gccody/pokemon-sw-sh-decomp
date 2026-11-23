// Scope: common
// SiSDK3::SiGfxNXCommandQueue: its construction and destruction, its queue
// and syncs, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_COMMANDQUEUE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_CommandQueue_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXCommandList.h>

// NVN's entry points that only the queue calls (nvn.h has them without their
// types).
inline void Unk_nvnQueueBuilderSetDevice(void* builder, void* device) {
    reinterpret_cast<void (*)(void*, void*)>(Unk_27fc780)(builder, device);
}
inline void Unk_nvnQueueBuilderSetDefaults(void* builder) {
    reinterpret_cast<void (*)(void*)>(Unk_27fc788)(builder);
}
inline void Unk_nvnQueueBuilderSetCommandMemorySize(void* builder, size_t size) {
    reinterpret_cast<void (*)(void*, size_t)>(Unk_27fc798)(builder, size);
}
inline void Unk_nvnQueueBuilderSetControlMemorySize(void* builder, size_t size) {
    reinterpret_cast<void (*)(void*, size_t)>(Unk_27fc7a8)(builder, size);
}
inline size_t Unk_nvnQueueBuilderGetQueueMemorySize(const void* builder) {
    return reinterpret_cast<size_t (*)(const void*)>(Unk_27fc7b0)(builder);
}
inline void Unk_nvnQueueBuilderSetQueueMemory(void* builder, void* memory, size_t size) {
    reinterpret_cast<void (*)(void*, void*, size_t)>(Unk_27fc7b8)(builder, memory, size);
}
inline void Unk_nvnQueueBuilderSetCommandFlushThreshold(void* builder, size_t threshold) {
    reinterpret_cast<void (*)(void*, size_t)>(Unk_27fc7c0)(builder, threshold);
}
inline NvnBoolean Unk_nvnQueueInitialize(void* queue, const void* builder) {
    return reinterpret_cast<NvnBoolean (*)(void*, const void*)>(Unk_27fc818)(queue, builder);
}
inline void Unk_nvnQueueFinalize(void* queue) {
    reinterpret_cast<void (*)(void*)>(Unk_27fc820)(queue);
}
inline void Unk_nvnQueueFlush(void* queue) {
    reinterpret_cast<void (*)(void*)>(Unk_27fc838)(queue);
}

namespace SiSDK3 {

// Sets an array's number of elements, making room when there isn't enough
// (inline in the queue's function: a placeholder name; SiCore_Array.h's
// Unk_SetCount makes room also when there's exactly enough).
template <class T, int ALIGN>
static inline bool Unk_Resize(SiArray<T, ALIGN>* array, size_t count) {
    if (array->m_itemCount != count) {
        if (array->m_reservedCount < count) {
            if (!array->Unk_4bf190(count, true)) {
                array->m_itemCount = 0;
                array->field_30 = nullptr;
                array->field_38 = nullptr;
                return false;
            }
        }
        array->m_itemCount = count;
        array->field_30 = array->m_pData;
        array->field_38 = array->m_pData + count;
    }
    return true;
}

// 0x710054d9d0
SiGfxNXCommandQueue::SiGfxNXCommandQueue(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_24(), field_2050(pAllocator), field_20a0(nullptr),
      field_20a8(false) {}

// 0x710054da70 (D2), 0x710054dd60 (D0)
SiGfxNXCommandQueue::~SiGfxNXCommandQueue() {
    Unk_54db30();
}

// 0x710054db30
void SiGfxNXCommandQueue::Unk_54db30() {
    if (!field_20a8) {
        return;
    }
    nvnQueueFinish(field_50);
    for (size_t i = 0; i < field_2050.m_itemCount; i++) {
        nvnSyncWait(&field_2050.m_pData[i], 0xffffffffffffffff);
        nvnSyncFinalize(&field_2050.m_pData[i]);
    }
    field_2050.Unk_FreeAll();
    Unk_nvnQueueFinalize(field_50);
    memset(field_50, 0, sizeof(field_50));
    if (field_20a0 != nullptr) {
        if (field_8.m_pAllocator != nullptr) {
#line 156
            SI_FREE(field_8.m_pAllocator, field_20a0);
        }
        field_20a0 = nullptr;
    }
    field_20a8 = false;
}

// 0x710054de30
bool SiGfxNXCommandQueue::Unk_54de30() {
    Unk_54e070();
    void* device = Unk_NXDevice(field_18)->vf85();
    u64 builder[8] = {};  // NVNqueueBuilder
    Unk_nvnQueueBuilderSetDefaults(builder);
    Unk_nvnQueueBuilderSetDevice(builder, device);
    int commandSize = 0;
    int controlSize = 0;
    int flushThreshold = 0;
    nvnDeviceGetInteger(device, 0x51, &commandSize);
    nvnDeviceGetInteger(device, 0x5c, &controlSize);
    nvnDeviceGetInteger(device, 0x56, &flushThreshold);
    s32 value = field_18->field_50.field_a8;
    if (value >= 1) {
        commandSize = value;
    } else if (value < 0) {
        commandSize <<= 6;
    }
    value = field_18->field_50.field_ac;
    if (value >= 1) {
        controlSize = value;
    } else if (value < 0) {
        controlSize <<= 1;
    }
    value = field_18->field_50.field_b0;
    if (value >= 1) {
        flushThreshold = value;
    } else if (value < 0) {
        flushThreshold <<= 7;
    }
    Unk_nvnQueueBuilderSetCommandMemorySize(builder, commandSize);
    Unk_nvnQueueBuilderSetControlMemorySize(builder, controlSize);
    Unk_nvnQueueBuilderSetCommandFlushThreshold(builder, flushThreshold);
    size_t size = Unk_nvnQueueBuilderGetQueueMemorySize(builder);
#line 122
    field_20a0 = UNK_ALLOC_ARRAY(field_8.m_pAllocator, u8, size, 0x1000);
    Unk_nvnQueueBuilderSetQueueMemory(builder, field_20a0, size);
    if (Unk_nvnQueueInitialize(field_50, builder) != 1) {
        return false;
    }
    field_20a8 = true;
    return true;
}

// NON_MATCHING: the array's reserve is inline here as in the original, but
// its loop that copies the old syncs is unrolled by four where the original's
// is unrolled by two (`and x8, x23, #1`), and the branch that skips the
// reserve goes the other way round. An NVNsync whose copy costs LLVM one
// instruction more than these 64 bytes' would give the original's count.
// 0x710054e070
bool SiGfxNXCommandQueue::Unk_54e070() {
    Unk_Resize(&field_2050, 0x80);
    void* device = Unk_NXDevice(field_18)->vf85();
    for (s32 i = 0; i < 0x80; i++) {
        nvnSyncInitialize(&field_2050.m_pData[i], device);
    }
    field_20a8 = true;
    return true;
}

// 0x710054e300
bool SiGfxNXCommandQueue::vf8() {
    SiGfxNXCommandQueue::vf15();
    return true;
}

// 0x710054e330
bool SiGfxNXCommandQueue::vf10(s32 count, SiGfxNXCommandList** lists) {
    if (count >= 1) {
        u64 handles[0x80] = {};
        do {
            s32 n = count < 0x80 ? count : 0x80;
            for (s64 i = 0; i < n; i++) {
                SiGfxNXCommandList* list = lists[i];
                handles[i] = list->vf16();
                for (s32 j = 0; j < 10; j++) {
                    field_24[j] += list->field_124[j];
                }
            }
            nvnQueueSubmitCommands(field_50, n, handles);
            count -= n;
        } while (count > 0);
    }
    return true;
}

// 0x710054e4a0
u64 SiGfxNXCommandQueue::vf12() {
    u32 next = field_20;
    nvnQueueFenceSync(field_50, &field_2050.m_pData[next], 0, 1);
    Unk_nvnQueueFlush(field_50);
    u32 index = field_20;
    field_20 = (index + 1) % field_2050.m_itemCount;
    return index;
}

// 0x710054e520
bool SiGfxNXCommandQueue::vf13(u64 fence) {
    size_t i = static_cast<u32>(fence);
    if (static_cast<u32>(nvnSyncWait(&field_2050.m_pData[i], 0)) >= 2) {
        nvnSyncWait(&field_2050.m_pData[i], 0xffffffffffffffff);
    }
    return true;
}

// 0x710054e5a0
void SiGfxNXCommandQueue::vf15() {
    memset(field_24, 0, sizeof(field_24));
}

}  // namespace SiSDK3
