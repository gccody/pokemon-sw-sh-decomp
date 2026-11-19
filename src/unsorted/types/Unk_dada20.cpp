// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027de920: its getter is out of line.
struct Unk_27de920 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027f0240: its getter is out of line.
struct Unk_27f0240 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9b90.
struct Unk_23dcb30 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0240::Unk_GetType());
        return &type;
    }
};

// The type 0x71027dc0c8.
struct Unk_23ea698 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dcb30::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023ef3f8: vf_type and its thunks 0x7100dada90 (+0x48), 0x7100dadb00 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ef3e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27de920::Unk_GetType());
        return &type;
    }

    ~Unk_23ef3e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100dada20
// 0x7100dada90
// 0x7100dadb00
const Unk_239a418_Type* Unk_23ef3e8::vf_type() {
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

// 0x7100dae310
template bool Unk_61a530<Unk_23ea698>(Unk_239a498* object);
