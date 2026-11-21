#pragma once
// Placement new, for the constructors the containers and the creation
// functions call on memory they allocated. The containers use a form of
// their own, whose result the compiler checks for null before it constructs.
#include <types.h>

inline void* operator new(size_t, void* p) noexcept {
    return p;
}

struct Unk_PlacementNewKey {};

inline void* operator new(size_t, void* p, const Unk_PlacementNewKey&) noexcept {
    return p;
}

#define Unk_PlacementNew(p) ::new (p, Unk_PlacementNewKey())

// Destroys an object of the default pool and frees it.
extern int Unk_237e820;
u32 Unk_3047c0(int poolId, void* ptr);

template <class T>
static inline void Unk_Delete(T* object) {
    if (object != nullptr) {
        int pool = Unk_237e820;
        object->~T();
        Unk_3047c0(pool, object);
    }
}
