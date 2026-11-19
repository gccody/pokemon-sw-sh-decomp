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

// The type 0x71027d7860.
struct Unk_23c9470 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d7910.
struct Unk_23c9660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d7920.
struct Unk_23c9788 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d7950.
struct Unk_23c9988 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d7900.
struct Unk_23c9c78 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d79c0.
struct Unk_23c9ff0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d7960.
struct Unk_23cbbc8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d79e0.
struct Unk_23cbe10 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d7930.
struct Unk_23cc148 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d79d0.
struct Unk_23cc7a0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d7940.
struct Unk_23ccd60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
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

// 0x7100ad46d0
template bool Unk_61a530<Unk_23c9c78>(Unk_239a498* object);

// 0x7100ad47c0
template bool Unk_61a530<Unk_23c9660>(Unk_239a498* object);

// 0x7100ad48b0
template bool Unk_61a530<Unk_23c9788>(Unk_239a498* object);

// 0x7100ad49a0
template bool Unk_61a530<Unk_23cc148>(Unk_239a498* object);

// 0x7100ad4c80
template bool Unk_61a530<Unk_23ccd60>(Unk_239a498* object);

// 0x7100ad4d70
template bool Unk_61a530<Unk_23c9988>(Unk_239a498* object);

// 0x7100ad4e60
template bool Unk_61a530<Unk_23cbbc8>(Unk_239a498* object);

// 0x7100ad5670
template bool Unk_61a530<Unk_23c9ff0>(Unk_239a498* object);

// 0x7100ad5760
template bool Unk_61a530<Unk_23cc7a0>(Unk_239a498* object);

// 0x7100ad5a40
template bool Unk_61a530<Unk_23cbe10>(Unk_239a498* object);
