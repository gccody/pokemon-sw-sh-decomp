// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8f98: its getter is out of line.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102420478: vf_type and its thunks 0x71011cd490 (+0x48), 0x71011cd500 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2420468 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2420468() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102420ae0: vf_type and its thunks 0x71011d2990 (+0x48), 0x71011d2a00 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2420ad0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2420ad0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102420e50: vf_type and its thunks 0x71011d5e90 (+0x48), 0x71011d5f40 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2420e40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2420ad0::Unk_GetType());
        return &type;
    }

    ~Unk_2420e40() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027ec1e0.
struct Unk_2420fb0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2420ad0::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102421130: vf_type and its thunks 0x71011d8820 (+0x48), 0x71011d8890 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2421120 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2421120() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024213b0: vf_type and its thunks 0x71011da860 (+0x48), 0x71011da8d0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24213a0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_24213a0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71011cd400
// 0x71011cd490
// 0x71011cd500
const Unk_239a418_Type* Unk_2420468::vf_type() {
    return Unk_GetType();
}

// 0x71011d27d0
// 0x71011d2990
// 0x71011d2a00
const Unk_239a418_Type* Unk_2420ad0::vf_type() {
    return Unk_GetType();
}

// 0x71011d5de0
// 0x71011d5e90
// 0x71011d5f40
const Unk_239a418_Type* Unk_2420e40::vf_type() {
    return Unk_GetType();
}

// 0x71011d87b0
// 0x71011d8820
// 0x71011d8890
const Unk_239a418_Type* Unk_2421120::vf_type() {
    return Unk_GetType();
}

// 0x71011da7f0
// 0x71011da860
// 0x71011da8d0
const Unk_239a418_Type* Unk_24213a0::vf_type() {
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

// 0x71011d6140
template bool Unk_61a530<Unk_2420fb0>(Unk_239a498* object);
