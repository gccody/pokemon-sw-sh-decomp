// SiSDK3's byte allocation and free as its classes spell them (placeholder
// names): both test the allocator, and the free clears the pointer.
#pragma once

#include "SiCore_Memory.h"

namespace SiSDK3 {

inline void* Unk_Alloc(ISiAllocator* pAllocator, size_t size, const char* file, int line) {
    return pAllocator != nullptr ? pAllocator->vf8(1, size, 0xffffffff, file, line) : nullptr;
}

// count elements of a type, with an alignment (no constructors)
template <class T>
inline T* Unk_AllocArray(ISiAllocator* pAllocator, size_t count, u32 alignment, const char* file, int line) {
    return pAllocator != nullptr ? static_cast<T*>(pAllocator->vf8(sizeof(T), count, alignment, file, line))
                                 : nullptr;
}

template <class T>
inline void Unk_Free(ISiAllocator* pAllocator, T*& p, const char* file, int line) {
    if (pAllocator != nullptr) {
        pAllocator->vf9(p, file, line);
    }
    p = nullptr;
}

}  // namespace SiSDK3

#define UNK_ALLOC(allocator, size) ::SiSDK3::Unk_Alloc(allocator, size, __FILE__, __LINE__)
#define UNK_ALLOC_ARRAY(allocator, T, count, alignment)     ::SiSDK3::Unk_AllocArray<T>(allocator, count, alignment, __FILE__, __LINE__)
#define UNK_FREE(allocator, p) ::SiSDK3::Unk_Free(allocator, p, __FILE__, __LINE__)
