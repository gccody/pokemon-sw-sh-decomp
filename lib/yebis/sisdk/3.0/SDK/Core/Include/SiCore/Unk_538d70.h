// What a SiGfx GPU resource whose deletion is deferred keeps after its vtable
// pointers, where other SiSDK3 objects keep Unk_4bf660: the allocator that
// made it, its reference count and four bytes, the first of which marks a
// resource that waits to be destroyed (Unk_RefCountDeferred.h). Placeholder
// name, after its constructor (0x7100538d70), which takes the allocator, or
// the kernel's default one for a null pointer, and starts the count at 1.
// The destructor is an empty out-of-line function, 0x7100538dc0, which
// leafgen had named Unk_538dc0_update(u64): the inline destructor here only
// calls it by that name, as Unk_4bf660's does.
#pragma once

#include "SiCore_Memory.h"

void Unk_538dc0_update(u64);

struct Unk_538d70 {
    explicit Unk_538d70(SiSDK3::ISiAllocator* pAllocator);
    ~Unk_538d70() { Unk_538dc0_update(reinterpret_cast<u64>(this)); }

    SiSDK3::ISiAllocator* m_pAllocator;
    // volatile, as Unk_4bf660's
    volatile u32 m_count;
    // 1: the resource waits to be destroyed (the constructor clears it by
    // itself, the next two bytes together and the last one by itself)
    u8 field_c;
    u8 field_d;
    u8 field_e;
    u8 field_f;
};
PKMN_SIZE_ASSERT(Unk_538d70, 0x10);
