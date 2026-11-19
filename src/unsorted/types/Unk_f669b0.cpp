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

// The type 0x71027ce8c8: its getter is out of line.
struct Unk_23f6328 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027ce8b8.
struct Unk_23f6218 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f6328::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e15e0.
struct Unk_27e15e0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e1610.
struct Unk_23ff270 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e1680.
struct Unk_23ff3d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023ff8f0: vf_type and its thunks 0x7100f6d5f0 (+0x48), 0x7100f6d6a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ff8e0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f6218::Unk_GetType());
        return &type;
    }

    ~Unk_23ff8e0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e1630.
struct Unk_23ffb78 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e1650.
struct Unk_2400560 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e1670.
struct Unk_2400900 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e1620.
struct Unk_2400bd8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e1660.
struct Unk_24013c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }
};

// 0x7100f6d520
// 0x7100f6d5f0
// 0x7100f6d6a0
const Unk_239a418_Type* Unk_23ff8e0::vf_type() {
    return Unk_GetType();
}

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

// 0x7100f669b0
template bool Unk_61a530<Unk_23ff270>(Unk_239a498* object);

// 0x7100f66aa0
template bool Unk_61a530<Unk_2400bd8>(Unk_239a498* object);

// 0x7100f66b90
template bool Unk_61a530<Unk_23ffb78>(Unk_239a498* object);

// 0x7100f66e70
template bool Unk_61a530<Unk_2400560>(Unk_239a498* object);

// 0x7100f66f60
template bool Unk_61a530<Unk_24013c0>(Unk_239a498* object);

// 0x7100f67050
template bool Unk_61a530<Unk_2400900>(Unk_239a498* object);

// 0x7100f67140
template bool Unk_61a530<Unk_23ff3d0>(Unk_239a498* object);

// 0x7100f6cdd0
template bool Unk_61a530<Unk_23ff8e0>(Unk_239a498* object);
