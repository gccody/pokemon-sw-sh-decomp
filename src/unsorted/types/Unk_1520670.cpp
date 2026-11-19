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

// The type 0x71027ce9f8: its getter is out of line.
struct Unk_27ce9f8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x71027f1768.
struct Unk_242c630 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102447b08: vf_type and its thunks 0x7101520ba0 (+0x48), 0x7101520bb0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101520be0).
// Its base and its other functions aren't written here.
class Unk_2447af8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_2447af8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102447bb8: vf_type and its thunks 0x71015207c0 (+0x48), 0x7101520870 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2447ba8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_2447ba8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024482d0: vf_type and its thunks 0x710152ed90 (+0x48), 0x710152eda0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710152ee70).
// Its base and its other functions aren't written here.
class Unk_24482c0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_24482c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102448400: vf_type and its thunks 0x710152f8b0 (+0x48), 0x710152f920 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24483f0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_24483f0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101520670
// 0x71015207c0
// 0x7101520870
const Unk_239a418_Type* Unk_2447ba8::vf_type() {
    return Unk_GetType();
}

// 0x7101520b70
// 0x7101520ba0
// 0x7101520bb0
const Unk_239a418_Type* Unk_2447af8::vf_type() {
    return Unk_GetType();
}

// 0x710152ecc0
// 0x710152ed90
// 0x710152eda0
const Unk_239a418_Type* Unk_24482c0::vf_type() {
    return Unk_GetType();
}

// 0x710152f4e0
// 0x710152f8b0
// 0x710152f920
const Unk_239a418_Type* Unk_24483f0::vf_type() {
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

// 0x710153b910
template bool Unk_61a530<Unk_242c630>(Unk_239a498* object);
