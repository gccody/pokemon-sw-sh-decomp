#pragma once
// How gflib3 makes an object on its reference-counted base: allocate it from an
// allocator made the thread's current one for the time it's constructed (so
// that what the constructor allocates comes from it too), construct it, and
// record the allocation in the object (field_8 to field_20 of
// Unk_239a418_Base), which Unk_239a418::vf3 hands back to the allocator when
// the object goes. About 270 instances, one per class, take the allocator and
// their constructor's arguments (src/gflib3/families). Their first argument
// isn't used: a member function of something stateless, so a placeholder
// struct. Placeholder names: rename once the classes are known.
#include <new>
#include <utility>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"

struct Unk_New {
    template <class T, class... Args>
    T* Create(Unk_239a418_Allocator* allocator, Args&&... args) {
        Unk_2771620_Scope scope(allocator);
        void* p = allocator->vf2(sizeof(T), alignof(T));
        if (p == nullptr)
            allocator->vf23();
        T* object = ::new (p) T(std::forward<Args>(args)...);
        object->field_8 = allocator;
        object->field_10 = reinterpret_cast<u64>(object);
        object->field_18 = sizeof(T);
        object->field_20 = alignof(T);
        return object;
    }
};
