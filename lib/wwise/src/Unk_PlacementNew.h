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
