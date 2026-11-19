// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0b20: its getter is out of line.
struct Unk_23f65d0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027f0448: its getter is out of line.
struct Unk_2441f08 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023f64c0: vf_type and its thunks 0x7100ebb4f0 (+0x48), 0x7100ebb560 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f64b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f65d0::Unk_GetType());
        return &type;
    }

    ~Unk_23f64b0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0b00.
struct Unk_27e0b00 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2441f08::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e0af0.
struct Unk_2442a00 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e0b00::Unk_GetType());
        return &type;
    }
};

// 0x7100ebb460
// 0x7100ebb4f0
// 0x7100ebb560
const Unk_239a418_Type* Unk_23f64b0::vf_type() {
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

// 0x7100eb85d0
template bool Unk_61a530<Unk_2442a00>(Unk_239a498* object);
