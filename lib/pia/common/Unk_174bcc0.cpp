// Scope: common
// Unk_174bc30::Unk_174bcc0 (lib/pia/common/Unk_174aea0.h), in a file of its
// own: the pool's constructor calls it, and in one file clang inlines it.
#include "pia/common/Unk_174aea0.h"

#include "pia/common/Unk_17162d0.h"

namespace nn {
namespace pia {
namespace transport {

// 0x710174bcc0
// NON_MATCHING: the original clears the memory with a byte offset compared with the size and
// tests the size before the pointer (both to one block); the same code otherwise.
bool Unk_174bc30::Unk_174bcc0(u32 capacity) {
    if (capacity == 0) {
        return false;
    }
    u32 size = capacity * sizeof(Entry);
    u32 count = size / sizeof(u32);
    u32* memory = static_cast<u32*>(operator new(sizeof(u32) * count, Unk_1652bd0()));
    if (memory != nullptr) {
        for (u32 i = 0; i < count; i++) {
            memory[i] = 0;
        }
    }
    field_40 = memory;
    if (field_40 == nullptr) {
        return false;
    }
    m_Entries = reinterpret_cast<Entry*>(field_40);
    m_Capacity = capacity;
    for (u32 i = 0; i < capacity; i++) {
        AddToPool(&m_Entries[i]);
    }
    return true;
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
