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

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102774028.
struct Unk_2399708 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241b010: vf_type and its thunks 0x7101159970 (+0x48), 0x7101159a20 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241b000 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399708::Unk_GetType());
        return &type;
    }

    ~Unk_241b000() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710241b0d0: vf_type and its thunks 0x7101159d60 (+0x48), 0x7101159dd0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241b0c0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }

    ~Unk_241b0c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d8f98.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ea730.
struct Unk_241f068 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// 0x71011597e0
// 0x7101159970
// 0x7101159a20
const Unk_239a418_Type* Unk_241b000::vf_type() {
    return Unk_GetType();
}

// 0x7101159cd0
// 0x7101159d60
// 0x7101159dd0
const Unk_239a418_Type* Unk_241b0c0::vf_type() {
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

// 0x710115f170
template bool Unk_61a530<Unk_241f068>(Unk_239a498* object);
