#pragma once
// Casts between the classes on gflib3's object (src/gflib3/Unk_239a418.h),
// through their type getters: contents/common/framework.h's, and the
// generated files' that declare their own classes (src/unsorted/views).
#include <types.h>

#include "gflib3/Unk_239a418.h"

// Whether an object's type is T's or one derived from it (the same template
// as tools/typegen.py's).
template <class T>
bool Unk_61a530(Unk_239a498* object) {
    const Unk_239a418_Type* type = object->vf_type();
    const Unk_239a418_Type* kind = T::Unk_GetType();
    for (; type != nullptr; type = type->field_0)
        if (type == kind)
            return true;
    return false;
}

// The object as a T, or null when it isn't one: through its +0x50 interface.
template <class T, class U>
T* Unk_DynamicCast(U* object) {
    if (object == nullptr)
        return nullptr;
    Unk_239a498* interface = object;
    if (!Unk_61a530<T>(interface))
        return nullptr;
    return static_cast<T*>(interface);
}
