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

// The type 0x71027effd0: its getter is out of line.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023e4a50: vf_type and its thunks 0x7100cf33c0 (+0x48), 0x7100cf3490 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e4a40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23e4a40() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023e4bb0: vf_type and its thunks 0x7100cf7950 (+0x48), 0x7100cf79c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e4ba0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23e4ba0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023e4cc8: vf_type and its thunks 0x7100cf7aa0 (+0x48), 0x7100cf7b10 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e4cb8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23e4cb8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023e4de8: vf_type and its thunks 0x7100cf7bf0 (+0x48), 0x7100cf7c60 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e4dd8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23e4dd8() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027effc0.
struct Unk_27effc0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027dbb20.
struct Unk_23e8d60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effc0::Unk_GetType());
        return &type;
    }
};

// 0x7100cf3170
// 0x7100cf33c0
// 0x7100cf3490
const Unk_239a418_Type* Unk_23e4a40::vf_type() {
    return Unk_GetType();
}

// 0x7100cf78e0
// 0x7100cf7950
// 0x7100cf79c0
const Unk_239a418_Type* Unk_23e4ba0::vf_type() {
    return Unk_GetType();
}

// 0x7100cf7a30
// 0x7100cf7aa0
// 0x7100cf7b10
const Unk_239a418_Type* Unk_23e4cb8::vf_type() {
    return Unk_GetType();
}

// 0x7100cf7b80
// 0x7100cf7bf0
// 0x7100cf7c60
const Unk_239a418_Type* Unk_23e4dd8::vf_type() {
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

// 0x7100cf38a0
template bool Unk_61a530<Unk_23e8d60>(Unk_239a498* object);
