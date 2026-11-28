// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0590: its getter is out of line.
// Unk_23f43c8 (unsorted/Unk_23f43c8.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23f43c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    ~Unk_23f43c8() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual u32 vf10();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023f3040: vf_type and its thunks 0x7100e6a010 (+0x48), 0x7100e6a020 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100e6a0f0).
// Its base and its other functions aren't written here.
class Unk_23f3030 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23f3030() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023f3148: vf_type and its thunks 0x7100e6cb30 (+0x48), 0x7100e6cb40 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71014e0b90).
// Its base and its other functions aren't written here.
class Unk_23f3138 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23f3138() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f31f8: vf_type and its thunks 0x7100e6c710 (+0x48), 0x7100e6c7c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f31e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23f31e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f3340: vf_type and its thunks 0x7100e6c3c0 (+0x48), 0x7100e6c430 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100e6c320
// 0x7100e6c3a0
// 0x7100e6c3b0
// 0x7100e6c4a0
// 0x7100e6c4b0
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_23f3330 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// vtable 0x71023f3410: vf_type and its thunks 0x7100e6c560 (+0x48), 0x7100e6c5d0 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100e6c4c0
// 0x7100e6c540
// 0x7100e6c550
// 0x7100e6c640
// 0x7100e6c650
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_23f3400 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// 0x7100e69f40
// 0x7100e6a010
// 0x7100e6a020
const Unk_239a418_Type* Unk_23f3030::vf_type() {
    return Unk_GetType();
}

// 0x7100e6c330
// 0x7100e6c3c0
// 0x7100e6c430
const Unk_239a418_Type* Unk_23f3330::vf_type() {
    return Unk_GetType();
}

// 0x7100e6c4d0
// 0x7100e6c560
// 0x7100e6c5d0
const Unk_239a418_Type* Unk_23f3400::vf_type() {
    return Unk_GetType();
}

// 0x7100e6c660
// 0x7100e6c710
// 0x7100e6c7c0
const Unk_239a418_Type* Unk_23f31e8::vf_type() {
    return Unk_GetType();
}

// 0x7100e6cb00
// 0x7100e6cb30
// 0x7100e6cb40
const Unk_239a418_Type* Unk_23f3138::vf_type() {
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

// 0x7100e6ce90
template bool Unk_61a530<Unk_23f31e8>(Unk_239a498* object);
