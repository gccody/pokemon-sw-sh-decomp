// PPFX::IGPUInterface, the reference-counted base of YEBIS's GPU objects
// (RTTI names the class; its members are placeholders), and YEBIS's new and
// delete: every allocation goes through one allocator, with the caller's
// __FILE__ and __LINE__.
#pragma once

#include <miniz/miniz_yebis.h>
#include <types.h>

inline void* operator new(size_t, void* p) noexcept {
    return p;
}

namespace PPFX {

// the destructor, then the allocator's free (the allocator is read first)
template <class T>
inline void Unk_Delete(Unk_4b99a0_arg0* allocator, T* p) {
    p->~T();
    Unk_4b9a60(allocator, p);
}

#define PPFX_NEW(T) new (Unk_4b99a0(Unk_238d5f8, sizeof(T), __FILE__, __LINE__, nullptr)) T
#define PPFX_DELETE(p) ::PPFX::Unk_Delete(Unk_238d5f8, p)

class IGPUInterface {
public:
    IGPUInterface();  // 0x7100445dc0
    virtual s32 vf0();  // 0x7100445e00: adds a reference
    virtual s32 vf1();  // 0x7100445e20: drops one, and deletes the object with the last
    virtual ~IGPUInterface();  // 0x7100445de0, 0x7100445df0

    s32 field_8;  // the reference count
};
PKMN_SIZE_ASSERT(IGPUInterface, 0x10);

}  // namespace PPFX
