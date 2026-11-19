// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e05b0: its getter is out of line.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e23d8.
struct Unk_24034f8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e23c8.
struct Unk_24033d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e2418.
struct Unk_2403638 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e23f8.
struct Unk_24039e0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e23e8.
struct Unk_2403b08 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e2408.
struct Unk_2403c30 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
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

// 0x7100fcc240
template bool Unk_61a530<Unk_24033d0>(Unk_239a498* object);

// 0x7100fcc330
template bool Unk_61a530<Unk_2403b08>(Unk_239a498* object);

// 0x7100fcc420
template bool Unk_61a530<Unk_24039e0>(Unk_239a498* object);

// 0x7100fcc510
template bool Unk_61a530<Unk_2403c30>(Unk_239a498* object);

// 0x7100fcc600
template bool Unk_61a530<Unk_2403638>(Unk_239a498* object);
