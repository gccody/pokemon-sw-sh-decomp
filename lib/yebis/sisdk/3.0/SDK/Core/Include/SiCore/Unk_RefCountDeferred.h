// The reference count of SiGfx's GPU resources whose deletion is deferred
// (SiGfxNXRenderTarget, SiGfxNXShader, SiGfxNXBuffer, ...): slot 2 is
// Unk_RefCount.h's, slot 3 is this header's. At zero the object isn't
// destroyed while its device says that the GPU may still use it (the device's
// slot 81): it's marked instead (Unk_538d70's field_c) and handed to the
// object that keeps such resources (0x71004cbec0's), which drops the last
// reference again later, with 0x710276cfe8 set, and that call destroys it.
// Placeholder header and names, like Unk_RefCount.h's; __FILE__ is the
// class's own header and the macro is expanded at the original's line.
#pragma once

#include "Unk_538d70.h"
#include "Unk_RefCount.h"

// 0x710276cfe8: set while the deferred resources are being destroyed
extern u8 Unk_276cfe8;
// 0x71004cbec0: the object that keeps the resources to destroy later (a
// function's static object), 0x71004ce9d0: gives it one (placeholder types:
// SiGfx's kernel translation units define them)
void* Unk_4cbec0();
void Unk_4ce9d0(void* self, void* resource);

// Defines Class's vf2 and vf3 at the line it's expanded on. allocator, count
// and deferred are the members of its Unk_538d70 (m_pAllocator, m_count and
// field_c); the class's slot 5 (vf5) is its device, whose slot 81 (vf81)
// tells whether resources have to wait.
#define UNK_REFCOUNT_DEFERRED_DEFINE(Class, allocator, count, deferred)                        \
    u32 Class::vf2() { return __atomic_add_fetch(&count, 1, __ATOMIC_SEQ_CST); }            \
    u32 Class::vf3() {                                                                     \
        typedef Class Unk_Self;                                                            \
        if (deferred == 1) {                                                                \
            if (Unk_276cfe8) {                                                             \
                SiSDK3::ISiAllocator* pAllocator = allocator;                              \
                this->~Unk_Self();                                                         \
                if (pAllocator != nullptr && static_cast<void*>(pAllocator) != this) {     \
                    SI_FREE(pAllocator, this);                                             \
                }                                                                          \
            }                                                                              \
            return 0;                                                                      \
        }                                                                                  \
        u32 n = __atomic_sub_fetch(&count, 1, __ATOMIC_SEQ_CST);                           \
        if (n == 0) {                                                                      \
            if (vf5() != nullptr && !vf5()->vf81()) {                                      \
                SiSDK3::ISiAllocator* pAllocator = allocator;                              \
                this->~Unk_Self();                                                         \
                if (pAllocator != nullptr && static_cast<void*>(pAllocator) != this) {     \
                    SI_FREE(pAllocator, this);                                             \
                }                                                                          \
            } else {                                                                       \
                deferred = 1;                                                              \
                Unk_4ce9d0(Unk_4cbec0(), this);                                            \
            }                                                                              \
            return 0;                                                                      \
        }                                                                                  \
        return n;                                                                          \
    }
