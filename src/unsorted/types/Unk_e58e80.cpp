// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6220: its getter is out of line.
struct Unk_23ddd68 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027dbdc8: its getter is out of line.
struct Unk_23de600 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efd50.
struct Unk_23e3950 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23ddd68::Unk_GetType());
        return &type;
    }
};

// The type 0x71027efd40.
struct Unk_23e60f0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e3950::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f2338: vf_type and its thunks 0x7100e58f10 (+0x48), 0x7100e58f80 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f2328 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23de600::Unk_GetType());
        return &type;
    }

    ~Unk_23f2328() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f25d8: vf_type and its thunks 0x7100e606c0 (+0x48), 0x7100e60770 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f25c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23f25c8() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023f2890: vf_type and its thunks 0x7100e61130 (+0x48), 0x7100e61140 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100e61170).
// Its base and its other functions aren't written here.
class Unk_23f2880 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23f2880() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100e58e80
// 0x7100e58f10
// 0x7100e58f80
const Unk_239a418_Type* Unk_23f2328::vf_type() {
    return Unk_GetType();
}

// 0x7100e60610
// 0x7100e606c0
// 0x7100e60770
const Unk_239a418_Type* Unk_23f25c8::vf_type() {
    return Unk_GetType();
}

// 0x7100e61100
// 0x7100e61130
// 0x7100e61140
const Unk_239a418_Type* Unk_23f2880::vf_type() {
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

// 0x7100e5de90
template bool Unk_61a530<Unk_23e60f0>(Unk_239a498* object);
