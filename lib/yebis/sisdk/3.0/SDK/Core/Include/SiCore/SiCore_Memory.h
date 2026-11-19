// SiSDK3's allocator interface and its array new/delete, as SiArray uses
// them (placeholder names: the slots' names aren't in the executable).
#pragma once

#include <assert.h>  // __assert_fail: SiSDK3's asserts are compiled in
#include <stddef.h>
#include <types.h>

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
    virtual void vf7();
    // allocates count elements of elementSize bytes (an array: vf10 returns the count)
    virtual void* vf8(u32 elementSize, size_t count, u32 alignment, const char* file, int line);
    virtual void vf9(void* p, const char* file, int line);  // frees
    virtual size_t vf10(void* p);                            // the element count of an array from vf8
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

// The array delete: destroys each element (asking the allocator for their
// count), then frees.
template <class T>
inline void SiDeleteArray(ISiAllocator* allocator, T* p, const char* file, int line) {
    if (!Unk_PodTraits<T>::value) {
        size_t count = allocator->vf10(p);
        for (size_t i = 0; i < count; i++) {
            p[i].~T();
        }
    }
    allocator->vf9(p, file, line);
}

}  // namespace SiSDK3

#define SI_DELETE_ARRAY(allocator, p) ::SiSDK3::SiDeleteArray(allocator, p, __FILE__, __LINE__)

// 0x71004bc640: the kernel's allocator, or the default one
SiSDK3::ISiAllocator* Unk_4bc640();
