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

// The type 0x71027d8980.
struct Unk_23d3130 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d89b0.
struct Unk_23d3008 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d3130::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023d3378: vf_type and its thunks 0x7100bb0790 (+0x48), 0x7100bb0840 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d3368 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d3130::Unk_GetType());
        return &type;
    }

    ~Unk_23d3368() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100bb0480
// 0x7100bb0790
// 0x7100bb0840
const Unk_239a418_Type* Unk_23d3368::vf_type() {
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

// 0x7100bb4e70
template bool Unk_61a530<Unk_23d3008>(Unk_239a498* object);
