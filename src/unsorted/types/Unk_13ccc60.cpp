// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027efe80: its getter is out of line.
struct Unk_2434918 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027f0020.
struct Unk_27f0020 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2434918::Unk_GetType());
        return &type;
    }
};

// The type 0x71027f0030.
struct Unk_24356d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0020::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102435890: vf_type and its thunks 0x71013cfee0 (+0x48), 0x71013cff50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2435880 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2434918::Unk_GetType());
        return &type;
    }

    ~Unk_2435880() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027f0010.
struct Unk_2435b08 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0020::Unk_GetType());
        return &type;
    }
};

// The type 0x71027f0040.
struct Unk_2435be0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0020::Unk_GetType());
        return &type;
    }
};

// 0x71013cfe50
// 0x71013cfee0
// 0x71013cff50
const Unk_239a418_Type* Unk_2435880::vf_type() {
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

// 0x71013ccc60
template bool Unk_61a530<Unk_2435b08>(Unk_239a498* object);

// 0x71013ccd50
template bool Unk_61a530<Unk_24356d0>(Unk_239a498* object);

// 0x71013ccf30
template bool Unk_61a530<Unk_2435be0>(Unk_239a498* object);
