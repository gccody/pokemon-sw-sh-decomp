// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e0ab0: its getter is out of line.
struct Unk_23f5ec8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027ee808.
struct Unk_23f2df0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5ec8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ee7f8.
struct Unk_23f3840 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f2df0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x710242b588: vf_type and its thunks 0x71012a0c20 (+0x48), 0x71012a0cd0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242b578 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_242b578() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71012a0b50
// 0x71012a0c20
// 0x71012a0cd0
const Unk_239a418_Type* Unk_242b578::vf_type() {
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

// 0x71012a26a0
template bool Unk_61a530<Unk_23f3840>(Unk_239a498* object);
