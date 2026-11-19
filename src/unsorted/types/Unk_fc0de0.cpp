// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9318: its getter is out of line.
struct Unk_23f4e40 {
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

// vtable 0x7102402dd8: vf_type and its thunks 0x7100fc0e70 (+0x48), 0x7100fc0ee0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2402dc8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_2402dc8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102402ea8: vf_type and its thunks 0x7100fc1e00 (+0x48), 0x7100fc1e70 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2402e98 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_2402e98() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e2348.
struct Unk_2403178 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }
};

// 0x7100fc0de0
// 0x7100fc0e70
// 0x7100fc0ee0
const Unk_239a418_Type* Unk_2402dc8::vf_type() {
    return Unk_GetType();
}

// 0x7100fc1bd0
// 0x7100fc1e00
// 0x7100fc1e70
const Unk_239a418_Type* Unk_2402e98::vf_type() {
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

// 0x7100fc5c70
template bool Unk_61a530<Unk_2403178>(Unk_239a498* object);
