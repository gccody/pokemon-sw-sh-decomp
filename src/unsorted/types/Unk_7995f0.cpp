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

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023a81b8: vf_type and its thunks 0x71007996c0 (+0x48), 0x7100799770 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a81a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23a81a8() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023a8368: vf_type and its thunks 0x7100799d90 (+0x48), 0x7100799da0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100799dd0).
// Its base and its other functions aren't written here.
class Unk_23a8358 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23a8358() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027ce8c8.
struct Unk_23f6328 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ce8b8.
struct Unk_23f6218 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f6328::Unk_GetType());
        return &type;
    }
};

// 0x71007995f0
// 0x71007996c0
// 0x7100799770
const Unk_239a418_Type* Unk_23a81a8::vf_type() {
    return Unk_GetType();
}

// 0x7100799d60
// 0x7100799d90
// 0x7100799da0
const Unk_239a418_Type* Unk_23a8358::vf_type() {
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

// 0x710079b990
template bool Unk_61a530<Unk_23f6218>(Unk_239a498* object);
