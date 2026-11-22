// PPFX::SiYebisAllocator: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <miniz/miniz_yebis.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace PPFX {

class SiYebisAllocator {
public:
    // what is in front of each allocation: the address handed out, the
    // number of elements, and room up to the address; the eight bytes before
    // the address are its distance from this
    struct Unk_Block {
        u8* field_0;
        size_t field_8;
    };

    virtual ~SiYebisAllocator() {}  // 0x710041af50, 0x710043c100
    UNK_REFCOUNT_DECLARE;
    // slots 4 to 6 and 11 to 20 are lib/yebis/class's
    virtual u32 vf4();
    virtual u32 vf5(u32 value);
    virtual u32 vf6();
    virtual void* vf7(size_t size, s32 alignment, const char* file, int line);                        // 0x710043c210
    virtual void* vf8(size_t elementSize, size_t count, s32 alignment, const char* file, int line);  // 0x710043c230
    virtual void vf9(void* p);                                                                       // 0x710043c2d0
    virtual size_t vf10(void* p);                                                                    // 0x710043c2f0
    virtual void vf11();
    virtual void vf12();
    virtual u64 vf13();
    virtual void vf14();
    virtual u64 vf15();
    virtual u64 vf16();
    virtual u64 vf17();
    virtual void vf18();
    virtual void vf19();
    virtual u64 vf20();

    Unk_4bf660 field_8;
    s32 field_18;  // the alignment of an allocation that names none
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
UNK_REFCOUNT_DEFINE(PPFX::SiYebisAllocator, field_8.m_pAllocator, field_8.m_count)
#endif
