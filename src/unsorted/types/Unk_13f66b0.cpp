// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6230: its getter is out of line.
struct Unk_23dcdd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d6220.
struct Unk_23ddd68 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dcdd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027efd50.
struct Unk_23e3950 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23ddd68::Unk_GetType());
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

// 0x71013f66b0
template bool Unk_61a530<Unk_23e3950>(Unk_239a498* object);
