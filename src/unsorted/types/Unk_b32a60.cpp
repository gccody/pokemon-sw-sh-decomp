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

// The type 0x71027d6250.
struct Unk_2399d08 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8608.
struct Unk_2399e38 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
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

// vtable 0x71023cefd0: vf_type and its thunks 0x7100b32a90 (+0x48), 0x7100b32aa0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100b32b10).
// Its base and its other functions aren't written here.
class Unk_23cefc0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_23cefc0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d8528.
struct Unk_27d8528 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023cf770: vf_type and its thunks 0x7100b46010 (+0x48), 0x7100b46020 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100b46170).
// Its base and its other functions aren't written here.
class Unk_23cf760 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8528::Unk_GetType());
        return &type;
    }

    ~Unk_23cf760() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023cf9a0: vf_type and its thunks 0x7100b48770 (+0x48), 0x7100b487e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23cf990 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23cf990() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d8618.
struct Unk_23f8090 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
        return &type;
    }
};

// 0x7100b32a60
// 0x7100b32a90
// 0x7100b32aa0
const Unk_239a418_Type* Unk_23cefc0::vf_type() {
    return Unk_GetType();
}

// 0x7100b45ec0
// 0x7100b46010
// 0x7100b46020
const Unk_239a418_Type* Unk_23cf760::vf_type() {
    return Unk_GetType();
}

// 0x7100b48700
// 0x7100b48770
// 0x7100b487e0
const Unk_239a418_Type* Unk_23cf990::vf_type() {
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

// 0x7100b446c0
template bool Unk_61a530<Unk_2399e38>(Unk_239a498* object);

// 0x7100b449e0
template bool Unk_61a530<Unk_23f8090>(Unk_239a498* object);
