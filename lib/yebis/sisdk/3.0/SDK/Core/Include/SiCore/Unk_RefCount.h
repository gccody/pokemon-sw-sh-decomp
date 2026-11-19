// The reference count every SiSDK3 class implements itself (its own copy of
// vtable slots 2 and 3, with __FILE__ the class's own header): a placeholder
// header name and placeholder member names, vf2 and vf3. vf2 increments, vf3
// decrements and, at zero, destroys the object (its virtual destructor) and
// frees it through the allocator it holds, unless that's the object itself.
#pragma once

#include "SiCore_Memory.h"

#define UNK_REFCOUNT_DECLARE \
    virtual u32 vf2();       \
    virtual u32 vf3()

// Defines Class's members at the line it's expanded on (the original's
// __LINE__): allocator and count are its members holding them.
#define UNK_REFCOUNT_DEFINE(Class, allocator, count)                                   \
    u32 Class::vf2() { return __atomic_add_fetch(&count, 1, __ATOMIC_SEQ_CST); }        \
    u32 Class::vf3() {                                                                 \
        u32 n = __atomic_sub_fetch(&count, 1, __ATOMIC_SEQ_CST);                       \
        if (n == 0) {                                                                  \
            typedef Class Unk_Self;                                                    \
            SiSDK3::ISiAllocator* pAllocator = allocator;                              \
            this->~Unk_Self();                                                         \
            if (pAllocator != nullptr && static_cast<void*>(pAllocator) != this) {     \
                SI_FREE(pAllocator, this);                                             \
            }                                                                          \
        }                                                                              \
        return n;                                                                      \
    }
