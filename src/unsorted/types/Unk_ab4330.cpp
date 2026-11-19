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

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023c8540: vf_type and its thunks 0x7100ab4400 (+0x48), 0x7100ab4410 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100a8af70).
// Its base and its other functions aren't written here.
class Unk_23c8530 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23c8530() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9318.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023c8670: vf_type and its thunks 0x7100ab7540 (+0x48), 0x7100ab7550 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100ab7560).
// Its base and its other functions aren't written here.
class Unk_23c8660 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23c8660() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d7670.
struct Unk_23c8ee0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }
};

// 0x7100ab4330
// 0x7100ab4400
// 0x7100ab4410
const Unk_239a418_Type* Unk_23c8530::vf_type() {
    return Unk_GetType();
}

// 0x7100ab7530
// 0x7100ab7540
// 0x7100ab7550
const Unk_239a418_Type* Unk_23c8660::vf_type() {
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

// 0x7100ab8ec0
template bool Unk_61a530<Unk_23c8ee0>(Unk_239a498* object);
