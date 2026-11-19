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

// The type 0x71027d8f98.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102421df8: vf_type and its thunks 0x71011e95a0 (+0x48), 0x71011e9650 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2421de8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2421de8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102421f38: vf_type and its thunks 0x71011eb7f0 (+0x48), 0x71011eb8a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2421f28 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2421f28() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102422078: vf_type and its thunks 0x71011ecad0 (+0x48), 0x71011ecb80 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2422068 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2422068() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024221b8: vf_type and its thunks 0x71011ede40 (+0x48), 0x71011edef0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24221a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_24221a8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024222f8: vf_type and its thunks 0x71011f1410 (+0x48), 0x71011f14c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24222e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_24222e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71011e94f0
// 0x71011e95a0
// 0x71011e9650
const Unk_239a418_Type* Unk_2421de8::vf_type() {
    return Unk_GetType();
}

// 0x71011eb520
// 0x71011eb7f0
// 0x71011eb8a0
const Unk_239a418_Type* Unk_2421f28::vf_type() {
    return Unk_GetType();
}

// 0x71011eca00
// 0x71011ecad0
// 0x71011ecb80
const Unk_239a418_Type* Unk_2422068::vf_type() {
    return Unk_GetType();
}

// 0x71011edb30
// 0x71011ede40
// 0x71011edef0
const Unk_239a418_Type* Unk_24221a8::vf_type() {
    return Unk_GetType();
}

// 0x71011f1360
// 0x71011f1410
// 0x71011f14c0
const Unk_239a418_Type* Unk_24222e8::vf_type() {
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

// 0x71011e9d30
template bool Unk_61a530<Unk_2422068>(Unk_239a498* object);

// 0x71011e9f70
template bool Unk_61a530<Unk_2421f28>(Unk_239a498* object);

// 0x71011ea4e0
template bool Unk_61a530<Unk_24221a8>(Unk_239a498* object);
