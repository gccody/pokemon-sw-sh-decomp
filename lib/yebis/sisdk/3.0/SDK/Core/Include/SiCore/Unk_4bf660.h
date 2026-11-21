// What every SiSDK3 object keeps right after its vtable pointer: the allocator
// that made it and its reference count (placeholder name, after its
// constructor). The constructor (0x71004bf660) takes the allocator, or the
// kernel's default one for a null pointer, and starts the count at 1. The
// destructor is an empty out-of-line function, 0x71004bf6a0, that leafgen
// named Unk_4bf6a0_update: the classes' destructors call it by that name, as
// their last statement (UNK_4BF660_DESTROY), where the member's destructor runs.
#pragma once

#include "SiCore_Memory.h"

void Unk_4bf6a0_update(u64);

struct Unk_4bf660 {
    explicit Unk_4bf660(SiSDK3::ISiAllocator* pAllocator);

    SiSDK3::ISiAllocator* m_pAllocator;
    u32 m_count;
    u32 field_c;
};
PKMN_SIZE_ASSERT(Unk_4bf660, 0x10);

#define UNK_4BF660_DESTROY(member) Unk_4bf6a0_update(reinterpret_cast<u64>(&(member)))
