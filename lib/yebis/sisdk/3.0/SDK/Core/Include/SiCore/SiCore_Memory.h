// SiSDK3's allocator interface and its array new/delete, as its containers use
// them (placeholder names: the slots' names aren't in the executable).
#pragma once

#include <assert.h>  // __assert_fail: SiSDK3's asserts are compiled in
#include <stddef.h>
#include <types.h>

// Construction in place (placeholder: these TUs have no <new>).
struct Unk_Placement {};
inline void* operator new(size_t, Unk_Placement, void* p) {
    return p;
}

namespace SiSDK3 {

class ISiAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void* vf7(size_t size, u32 alignment, const char* file, int line);  // allocates an object
    // allocates count elements of elementSize bytes (an array: vf10 returns the count)
    virtual void* vf8(u32 elementSize, size_t count, u32 alignment, const char* file, int line);
    virtual void vf9(void* p, const char* file, int line);  // frees
    virtual size_t vf10(void* p);                            // the element count of an array from vf8
    virtual void vf11(void* info);                           // fills in what it has allocated
};

// Element types the array delete needn't destroy (placeholder name): pointers
// and the builtin types SiSDK3's typedefs use. `unsigned long` isn't one of
// them (SI_UINT64 is `unsigned long long`): SiArray<unsigned long> asks for the
// count like a class's array does.
template <class T>
struct Unk_PodTraits {
    enum { value = false };
};
template <class T>
struct Unk_PodTraits<T*> {
    enum { value = true };
};
#define UNK_POD(T)            \
    template <>               \
    struct Unk_PodTraits<T> { \
        enum { value = true }; \
    };
UNK_POD(bool)
UNK_POD(char)
UNK_POD(signed char)
UNK_POD(unsigned char)
UNK_POD(wchar_t)
UNK_POD(short)
UNK_POD(unsigned short)
UNK_POD(int)
UNK_POD(unsigned int)
UNK_POD(long long)
UNK_POD(unsigned long long)
UNK_POD(float)
UNK_POD(double)
#undef UNK_POD

// 0x710056de40 (SIGFX_SHADER_PREPROCESSOR): the array delete. Destroys each
// element (asking the allocator for their count), frees, and clears the
// pointer.
template <class T>
void Unk_56de40(ISiAllocator* allocator, T*& p, const char* file, long line) {
    if (allocator == nullptr || p == nullptr) {
        return;
    }
    if (!Unk_PodTraits<T>::value) {
        size_t count = allocator->vf10(p);
        // the counter declared before the loop: a for-init declaration's
        // cleanup block puts the code after the loop ahead of its body,
        // which decides where a nested loop's preheader goes
        // (SiPool<SiGfxFreeTypeGlyph>::Unk_4be7d0)
        size_t i;
        for (i = 0; i < count; i++) {
            p[i].~T();
        }
    }
    allocator->vf9(p, file, line);
    p = nullptr;
}

// The array delete of a pointer that isn't null, which its caller clears
// (inline in every caller: placeholder name).
template <class T>
inline void Unk_DeleteArray(ISiAllocator* allocator, T* p, const char* file, long line) {
    if (allocator != nullptr) {
        if (!Unk_PodTraits<T>::value) {
            size_t count = allocator->vf10(p);
            for (size_t i = 0; i < count; i++) {
                p[i].~T();
            }
        }
        allocator->vf9(p, file, line);
    }
}

// 0x71004c25a0 (a SiMap node): the single-object delete. Destroys the object,
// then frees it.
template <class T>
void Unk_4c25a0(ISiAllocator* allocator, T* p, const char* file, long line) {
    if (allocator == nullptr || p == nullptr) {
        return;
    }
    p->~T();
    allocator->vf9(p, file, line);
}

}  // namespace SiSDK3

// What an allocator's slot 11 fills in (placeholder name, after the function
// of SiIOKernel that first showed it).
struct Unk_57d2a0_Info {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
};

// An object's allocation, as `new (allocator, alignment, file, line) T(...)`
// (placeholder: the original's macro isn't known). The result isn't tested.
inline void* operator new(size_t size, SiSDK3::ISiAllocator* allocator, u32 alignment, const char* file, int line) {
    return allocator->vf7(size, alignment, file, line);
}
#define UNK_SI_NEW(allocator, alignment) new (allocator, alignment, __FILE__, __LINE__)

#define SI_DELETE(allocator, p) ::SiSDK3::Unk_4c25a0(allocator, p, __FILE__, __LINE__)
// The array new: allocates into p, then constructs each element of a class
// that has a constructor. A statement, expanded in its caller, with the test
// for a constructor decided at compile time, which is what the original's
// code shows: for a class with a constructor the caller's own null test is
// threaded through this one (one test right after the allocation, then the
// loop's first test: an inline function would have merged those two before
// it was inlined), and for a class without one no test is left (an empty
// loop's would be threaded the same way).
#define SI_NEW_ARRAY(p, allocator, T, count, align)                                              \
    p = static_cast<T*>((allocator)->vf8(sizeof(T), count, align, __FILE__, __LINE__));          \
    if (!__has_trivial_constructor(T) && p != nullptr) {                                         \
        T* unk_q = p;                                                                            \
        for (s64 unk_i = 0; unk_i < static_cast<s64>(count); unk_i++, unk_q++) {                 \
            new (Unk_Placement(), unk_q) T;                                                      \
        }                                                                                        \
    }
#define SI_DELETE_ARRAY(allocator, p) ::SiSDK3::Unk_56de40(allocator, p, __FILE__, __LINE__)
#define SI_FREE(allocator, p) (allocator)->vf9(p, __FILE__, __LINE__)
// The array delete of a pointer that may be null, which is cleared without an
// allocator too (placeholder names): the pointer is read once and cleared
// once, by the code the macro is expanded in.
#define UNK_SAFE_DELETE_ARRAY(allocator, p)                                        if ((p) != nullptr) {                                                              ::SiSDK3::Unk_DeleteArray(allocator, p, __FILE__, __LINE__);                   (p) = nullptr;                                                             }

// 0x71004bc640: the kernel's allocator, or the default one
SiSDK3::ISiAllocator* Unk_4bc640();
