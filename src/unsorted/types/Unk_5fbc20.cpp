// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102777178: its getter is out of line.
struct Unk_239b8d8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71024ba7e8.
struct Unk_239a360 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x710239b3a8: vf_type and its thunks 0x71005fbd50 (+0x48), 0x71005fbd60 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71005fbe30).
// Its base and its other functions aren't written here.
class Unk_239b398 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a360::Unk_GetType());
        return &type;
    }

    ~Unk_239b398() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027740c8.
struct Unk_239bb58 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x7102777248.
struct Unk_239c100 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b8d8::Unk_GetType());
        return &type;
    }
};

// vtable 0x710239c578: vf_type and its thunks 0x710060e560 (+0x48), 0x710060e570 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710060e5a0).
// Its base and its other functions aren't written here.
class Unk_239c568 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    ~Unk_239c568() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027772c8.
struct Unk_239d108 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }
};

// 0x71005fbc20
// 0x71005fbd50
// 0x71005fbd60
const Unk_239a418_Type* Unk_239b398::vf_type() {
    return Unk_GetType();
}

// 0x710060e530
// 0x710060e560
// 0x710060e570
const Unk_239a418_Type* Unk_239c568::vf_type() {
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

// 0x710061a530
template bool Unk_61a530<Unk_239d108>(Unk_239a498* object);
