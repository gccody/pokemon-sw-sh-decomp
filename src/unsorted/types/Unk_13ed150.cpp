// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027efd90: its getter is out of line.
struct Unk_23dd820 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efd80.
struct Unk_23e4758 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dd820::Unk_GetType());
        return &type;
    }
};

// The type 0x71027f0000.
struct Unk_23ea168 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e4758::Unk_GetType());
        return &type;
    }
};

// The type 0x71027f0328.
struct Unk_23ec020 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e4758::Unk_GetType());
        return &type;
    }
};

// Whether an object's type is the template argument or one derived from it,
// through the object's +0x50 interface.
template <class T>
bool Unk_61a530(Unk_239a498* object) {
    const Unk_239a418_Type* type = object->vf_type();
    const Unk_239a418_Type* kind = T::Unk_GetType();
    for (; type != nullptr; type = type->field_0)
        if (type == kind)
            return true;
    return false;
}

// 0x71013ed150
template bool Unk_61a530<Unk_23ec020>(Unk_239a498* object);

// 0x71013ed240
template bool Unk_61a530<Unk_23ea168>(Unk_239a498* object);
