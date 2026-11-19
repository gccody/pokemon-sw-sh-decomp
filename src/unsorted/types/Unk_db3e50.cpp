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

// The type 0x71027effd0: its getter is out of line.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023ef6b8: vf_type and its thunks 0x7100db3ee0 (+0x48), 0x7100db3f50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ef6a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27de920::Unk_GetType());
        return &type;
    }

    ~Unk_23ef6a8() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9318.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023ef7a8: vf_type and its thunks 0x7100db5280 (+0x48), 0x7100db5290 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100db5380).
// Its base and its other functions aren't written here.
class Unk_23ef798 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23ef798() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027da210.
struct Unk_27da210 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027de9b0.
struct Unk_23ef868 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da210::Unk_GetType());
        return &type;
    }
};

// 0x7100db3e50
// 0x7100db3ee0
// 0x7100db3f50
const Unk_239a418_Type* Unk_23ef6a8::vf_type() {
    return Unk_GetType();
}

// 0x7100db5170
// 0x7100db5280
// 0x7100db5290
const Unk_239a418_Type* Unk_23ef798::vf_type() {
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

// 0x7100db5730
template bool Unk_61a530<Unk_23ef868>(Unk_239a498* object);
