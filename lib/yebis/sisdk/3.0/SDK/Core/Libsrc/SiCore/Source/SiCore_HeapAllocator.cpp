// Scope: common
// SiSDK3::SiHeapAllocator: every allocation goes to the memory system
// (SiSDK3::SiMemorySystem, 0x71024e98d0), which keeps the allocator that made a
// block right before it.
#define UNK_SIHEAPALLOCATOR_DEFINE
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_HeapAllocator.h>

// 0x71004c3640 (lib/yebis/leaf): the memory system, under leafgen's name and type
const u8* Unk_4c3640_get();
// 0x71004c4090 (lib/yebis/leaf): an empty function of the memory system's
void Unk_4c4090_update(void*, u64);

namespace SiSDK3 {

// the memory system, as far as the allocator calls it
class SiMemorySystem {
public:
    void* Unk_4c39e0(size_t size, size_t count, int alignment, const char* file, int line);
    void Unk_4c3c70(void* p, const char* file, int line);
    size_t Unk_4c3da0(void* p);
    size_t Unk_4c3df0(void* p);
    void Unk_4c3f80(Unk_4be540_arg1* value);
    void Unk_4c4040(u64 value);
    u64 Unk_4c4050();
    void Unk_4c4060(u64 value);
    u64 Unk_4c4070();
    u64 Unk_4c4080();
};

static inline SiMemorySystem* Unk_GetMemorySystem() {
    return reinterpret_cast<SiMemorySystem*>(const_cast<u8*>(Unk_4c3640_get()));
}

// 0x71004c2d70
SiHeapAllocator::SiHeapAllocator() : field_8(nullptr), field_18(0), field_20(nullptr) {
    field_8.m_pAllocator = reinterpret_cast<ISiAllocator*>(this);
}

// 0x71004c2db0, 0x71004c2e00
SiHeapAllocator::~SiHeapAllocator() {
    if (field_20 != nullptr) {
        field_20->vf3();
        field_20 = nullptr;
    }
}

// 0x71004c2e70
void* SiHeapAllocator::vf7(size_t size, int alignment, const char* file, int line) {
    if (alignment < 0) {
        alignment = field_18;
    }
    void* p = Unk_GetMemorySystem()->Unk_4c39e0(size, 1, alignment, file, line);
    if (p != nullptr) {
        static_cast<SiHeapAllocator**>(p)[-1] = this;
    } else if (field_20 != nullptr) {
        field_20->vf5(this, size, 1, alignment, file, line);
    }
    return p;
}

// 0x71004c2f10
void* SiHeapAllocator::vf8(size_t elementSize, size_t count, int alignment, const char* file, int line) {
    if (alignment < 0) {
        alignment = field_18;
    }
    size_t size = count * elementSize;
    void* p = Unk_GetMemorySystem()->Unk_4c39e0(size, count, alignment, file, line);
    if (p != nullptr) {
        static_cast<SiHeapAllocator**>(p)[-1] = this;
    } else if (field_20 != nullptr) {
        field_20->vf5(this, elementSize, count, alignment, file, line);
    }
    return p;
}

// 0x71004c2fc0
void SiHeapAllocator::vf9(void* p, const char* file, int line) {
    if (p == nullptr) {
        return;
    }
    SiHeapAllocator* pAllocator = static_cast<SiHeapAllocator**>(p)[-1];
    if (pAllocator != this) {
        pAllocator->vf9(p, file, line);
    } else {
        Unk_GetMemorySystem()->Unk_4c3c70(p, file, line);
    }
}

// 0x71004c3050
size_t SiHeapAllocator::vf10(void* p) {
    if (p == nullptr) {
        return 0;
    }
    return Unk_GetMemorySystem()->Unk_4c3da0(p);
}

// 0x71004c3080
void SiHeapAllocator::vf11(Unk_4be540_arg1* value) {
    if (value == nullptr) {
        return;
    }
    Unk_GetMemorySystem()->Unk_4c3f80(value);
}

// 0x71004c30b0
void SiHeapAllocator::vf12(u64 value) {
    Unk_GetMemorySystem()->Unk_4c4040(value);
}

// 0x71004c30e0
u64 SiHeapAllocator::vf13() {
    return Unk_GetMemorySystem()->Unk_4c4050();
}

// 0x71004c3100
void SiHeapAllocator::vf14(u64 value) {
    Unk_GetMemorySystem()->Unk_4c4060(value);
}

// 0x71004c3130
u64 SiHeapAllocator::vf15() {
    return Unk_GetMemorySystem()->Unk_4c4070();
}

// 0x71004c3150
size_t SiHeapAllocator::vf16(void* p) {
    return Unk_GetMemorySystem()->Unk_4c3df0(p);
}

// 0x71004c3180
u64 SiHeapAllocator::vf17() {
    return Unk_GetMemorySystem()->Unk_4c4080();
}

// 0x71004c31a0
void SiHeapAllocator::vf18(u64 number) {
    Unk_4c4090_update(Unk_GetMemorySystem(), number);
}

// 0x71004c31d0
void SiHeapAllocator::vf19(Unk_Handler* handler) {
    if (handler != nullptr) {
        handler->vf2();
    }
    if (field_20 != nullptr) {
        field_20->vf3();
    }
    field_20 = handler;
}

}  // namespace SiSDK3
