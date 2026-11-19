#pragma once
// gflib3's per-thread stack of allocators, and what allocates with one current:
// a container allocator and a unique_ptr maker (src/unsorted/Unk_23c4ef0.h,
// src/unsorted/Unk_81c630.cpp). Placeholder names: rename once the classes are
// known.
#include <cstdlib>
#include <memory>
#include <unordered_map>
#include <utility>

#include <nn/os.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f4660.h"

// The per-thread stack of allocators (gflib3; 0x71005cf910 initialises one):
// an allocator's construct pushes it for the time of the constructor.
struct Unk_2771620_Stack {
    Unk_239a418_Allocator* field_0[16];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_2771620_Stack, field_80, 0x80);

// The TLS slot that holds the current thread's stack.
extern nn::os::TlsSlot Unk_2771620;

// Makes an allocator the current one while it's alive.
class Unk_2771620_Scope {
public:
    explicit Unk_2771620_Scope(Unk_239a418_Allocator* allocator)
        : m_stack(reinterpret_cast<Unk_2771620_Stack*>(nn::os::GetTlsValue(Unk_2771620))) {
        if (m_stack->field_80 >= 16)
            abort();
        m_stack->field_0[m_stack->field_80] = allocator;
        m_stack->field_80++;
    }
    ~Unk_2771620_Scope() { m_stack->field_80--; }

private:
    Unk_2771620_Stack* m_stack;
};

// A container allocator, 0x18 bytes: allocates through slot 2 of its
// allocator (slot 23 when that fails), frees through slot 3 and constructs
// with the allocator current.
template <class T>
class Unk_2771620_Allocator {
public:
    using value_type = T;

    explicit Unk_2771620_Allocator(Unk_239a418_Allocator* allocator)
        : field_0(allocator), field_8(0), field_10(0) {}
    template <class U>
    Unk_2771620_Allocator(const Unk_2771620_Allocator<U>& other)
        : field_0(other.field_0), field_8(other.field_8), field_10(other.field_10) {}

    T* allocate(size_t n) {
        void* p = field_0->vf2(n * sizeof(T), alignof(T));
        if (p == nullptr)
            field_0->vf23();
        return static_cast<T*>(p);
    }
    void deallocate(T* p, size_t n) {
        field_0->vf3(reinterpret_cast<u64>(p), n * sizeof(T), alignof(T));
    }
    template <class U, class... Args>
    void construct(U* p, Args&&... args) {
        Unk_2771620_Scope scope(field_0);
        ::new (static_cast<void*>(p)) U(std::forward<Args>(args)...);
    }

    Unk_239a418_Allocator* field_0;
    u64 field_8;
    u32 field_10;
};

template <class T, class U>
bool operator==(const Unk_2771620_Allocator<T>& a, const Unk_2771620_Allocator<U>& b) {
    return a.field_0 == b.field_0;
}
template <class T, class U>
bool operator!=(const Unk_2771620_Allocator<T>& a, const Unk_2771620_Allocator<U>& b) {
    return !(a == b);
}

// Allocates a T from `allocator` and constructs it with the allocator current.
template <class T, class... Args>
std::unique_ptr<T, Unk_23f4660_Deleter> Unk_2771620_MakeUnique(Unk_239a418_Allocator* allocator,
                                                               Args&&... args) {
    void* p = allocator->vf2(sizeof(T), alignof(T));
    T* object;
    {
        Unk_2771620_Scope scope(allocator);
        object = ::new (p) T(std::forward<Args>(args)...);
    }
    return std::unique_ptr<T, Unk_23f4660_Deleter>(
        object, Unk_23f4660_Deleter{allocator, sizeof(T), alignof(T)});
}

// An unordered_map whose memory comes from the allocator.
template <class K, class T>
using Unk_2771620_Map = std::unordered_map<K,
                                           T,
                                           std::hash<K>,
                                           std::equal_to<K>,
                                           Unk_2771620_Allocator<std::pair<const K, T>>>;
