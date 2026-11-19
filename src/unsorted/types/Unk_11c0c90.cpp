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

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x710241ff10: vf_type and its thunks 0x71011c0de0 (+0x48), 0x71011c0e90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241ff00 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_241ff00() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102420068: vf_type and its thunks 0x71011c6aa0 (+0x48), 0x71011c6ab0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71011c6ae0).
// Its base and its other functions aren't written here.
class Unk_2420058 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_2420058() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d8f98.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ec1c0.
struct Unk_2421620 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ec1d0.
struct Unk_2421de8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ec1a0.
struct Unk_24222e8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// 0x71011c0c90
// 0x71011c0de0
// 0x71011c0e90
const Unk_239a418_Type* Unk_241ff00::vf_type() {
    return Unk_GetType();
}

// 0x71011c6a70
// 0x71011c6aa0
// 0x71011c6ab0
const Unk_239a418_Type* Unk_2420058::vf_type() {
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

// 0x71011c6d60
template bool Unk_61a530<Unk_24222e8>(Unk_239a498* object);

// 0x71011c7280
template bool Unk_61a530<Unk_2421de8>(Unk_239a498* object);

// 0x71011c7fd0
template bool Unk_61a530<Unk_2421620>(Unk_239a498* object);
