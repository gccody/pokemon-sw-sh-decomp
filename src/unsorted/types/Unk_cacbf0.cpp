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

// The type 0x71027d61a0: its getter is out of line.
struct Unk_23de150 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d6190.
struct Unk_23df930 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23de150::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e1060: vf_type and its thunks 0x7100cb0dc0 (+0x48), 0x7100cb0e30 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e1050 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23e1050() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d6180.
struct Unk_23e9640 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23df930::Unk_GetType());
        return &type;
    }
};

// 0x7100cb0bb0
// 0x7100cb0dc0
// 0x7100cb0e30
const Unk_239a418_Type* Unk_23e1050::vf_type() {
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

// 0x7100cacbf0
template bool Unk_61a530<Unk_23e9640>(Unk_239a498* object);
