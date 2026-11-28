// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102774038: its getter is out of line.
struct Unk_2399590 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d8f98: its getter is out of line.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e9d10: its getter is out of line.
struct Unk_27e9d10 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102774028.
struct Unk_2399708 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102418d78: vf_type and its thunks 0x710111a850 (+0x48), 0x710111a900 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2418d68 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399708::Unk_GetType());
        return &type;
    }

    ~Unk_2418d68() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102418e38: vf_type and its thunks 0x710111acb0 (+0x48), 0x710111ad20 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2418e28 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }

    ~Unk_2418e28() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102418ef0: vf_type and its thunks 0x710111ba30 (+0x48), 0x710111baa0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2418ee0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e9d10::Unk_GetType());
        return &type;
    }

    ~Unk_2418ee0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e9fe0.
struct Unk_2419968 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ea000.
struct Unk_2419ad0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8f88.
struct Unk_241b428 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e9fa8.
struct Unk_2427a70 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e9f48.
struct Unk_27e9f48 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241b428::Unk_GetType());
        return &type;
    }
};

// 0x710111a6b0
// 0x710111a850
// 0x710111a900
const Unk_239a418_Type* Unk_2418d68::vf_type() {
    return Unk_GetType();
}

// 0x710111ac20
// 0x710111acb0
// 0x710111ad20
const Unk_239a418_Type* Unk_2418e28::vf_type() {
    return Unk_GetType();
}

// 0x710111b9c0
// 0x710111ba30
// 0x710111baa0
const Unk_239a418_Type* Unk_2418ee0::vf_type() {
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

// 0x7101122400
template bool Unk_61a530<Unk_2427a70>(Unk_239a498* object);

// 0x7101124520
template bool Unk_61a530<Unk_27e9f48>(Unk_239a498* object);

// 0x7101127600
template bool Unk_61a530<Unk_2419ad0>(Unk_239a498* object);
