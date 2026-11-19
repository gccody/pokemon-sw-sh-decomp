// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d6250.
struct Unk_2399d08 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d6260.
struct Unk_239ca40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d6240.
struct Unk_23a19c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d6950.
struct Unk_23cf990 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d69a0.
struct Unk_23d1c18 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d6990.
struct Unk_23d19d8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d1c18::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d69b0.
struct Unk_23d1af8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d1c18::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d69c0.
struct Unk_23d2018 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23cf990::Unk_GetType());
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

// 0x710096c6c0
template bool Unk_61a530<Unk_23a19c8>(Unk_239a498* object);

// 0x710096ccf0
template bool Unk_61a530<Unk_239ca40>(Unk_239a498* object);

// 0x7100986d10
template bool Unk_61a530<Unk_23d19d8>(Unk_239a498* object);

// 0x7100986f50
template bool Unk_61a530<Unk_23d1af8>(Unk_239a498* object);

// 0x7100987040
template bool Unk_61a530<Unk_23d2018>(Unk_239a498* object);
