#pragma once
// Placement new, for the constructors the containers and the creation
// functions call on memory they allocated.
#include <types.h>

inline void* operator new(size_t, void* p) noexcept {
    return p;
}
