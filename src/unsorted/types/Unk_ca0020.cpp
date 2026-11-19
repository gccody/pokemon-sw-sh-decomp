// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027effd0: its getter is out of line.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027da210.
struct Unk_27da210 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027da200.
struct Unk_23e0778 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da210::Unk_GetType());
        return &type;
    }
};

// The type 0x71027effc0.
struct Unk_27effc0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027effb0.
struct Unk_23e0920 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effc0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027da568.
struct Unk_27da568 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e0b60: vf_type and its thunks 0x7100ca2d40 (+0x48), 0x7100ca2df0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e0b50 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da568::Unk_GetType());
        return &type;
    }

    ~Unk_23e0b50() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027da3c0.
struct Unk_23ea798 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da210::Unk_GetType());
        return &type;
    }
};

// 0x7100ca2b10
// 0x7100ca2d40
// 0x7100ca2df0
const Unk_239a418_Type* Unk_23e0b50::vf_type() {
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

// 0x7100ca0020
template bool Unk_61a530<Unk_23ea798>(Unk_239a498* object);

// 0x7100ca0110
template bool Unk_61a530<Unk_23e0778>(Unk_239a498* object);

// 0x7100ca0b90
template bool Unk_61a530<Unk_23e0920>(Unk_239a498* object);
