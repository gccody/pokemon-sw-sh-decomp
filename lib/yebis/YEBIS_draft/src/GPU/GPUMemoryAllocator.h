// PPFX::SiYebisAllocator: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <miniz/miniz_yebis.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace PPFX {

class SiYebisAllocator {
public:
    virtual ~SiYebisAllocator();
    UNK_REFCOUNT_DECLARE;

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
};

// The allocator of PPFX's libc++ containers (its allocate is this header's
// line 440 in every container's growth: std::vector's __push_back_slow_path,
// std::list's node allocation). It has a construct of its own: the vectors
// move their elements one by one, which libc++ only does for an allocator
// with one. Placeholder name.
template <class T>
class Unk_StlAllocator {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    template <class U>
    struct rebind {
        typedef Unk_StlAllocator<U> other;
    };

    Unk_StlAllocator() {}
    Unk_StlAllocator(const Unk_StlAllocator&) {}
    template <class U>
    Unk_StlAllocator(const Unk_StlAllocator<U>&) {}

    pointer address(reference value) const { return &value; }
    const_pointer address(const_reference value) const { return &value; }
#line 439
    pointer allocate(size_type count, const void* = nullptr) {
        return static_cast<pointer>(Unk_4b99a0(Unk_238d5f8, count * sizeof(T), __FILE__, __LINE__, nullptr));
    }
    void deallocate(pointer p, size_type) { Unk_4b9a60(Unk_238d5f8, p); }
    size_type max_size() const { return static_cast<size_type>(-1) / sizeof(T); }
    void construct(pointer p, const T& value) { new (p) T(value); }
    void destroy(pointer p) { p->~T(); }
};
template <class T, class U>
inline bool operator==(const Unk_StlAllocator<T>&, const Unk_StlAllocator<U>&) {
    return true;
}
template <class T, class U>
inline bool operator!=(const Unk_StlAllocator<T>&, const Unk_StlAllocator<U>&) {
    return false;
}

}  // namespace PPFX

// 0x710043c140 (vf2), 0x710043c160 (vf3): defined in the one TU that asks
// for them (GPUMemoryAllocator.cpp), since they aren't inline here.
#ifdef UNK_SIYEBISALLOCATOR_DEFINE
#line 486
UNK_REFCOUNT_DEFINE(PPFX::SiYebisAllocator, field_8, field_10)
#endif
