// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6ac0: its getter is out of line.
struct Unk_23c44f8 {
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

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
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

// The type 0x71027d9318.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102438f30: vf_type and its thunks 0x71014198b0 (+0x48), 0x7101419960 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2438f20 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_2438f20() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102439548: vf_type and its thunks 0x7101422470 (+0x48), 0x7101422520 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2439538 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_2439538() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102439910: vf_type and its thunks 0x71014259c0 (+0x48), 0x71014259d0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101425a50).
// Its base and its other functions aren't written here.
class Unk_2439900 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_2439900() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024399c0: vf_type and its thunks 0x71014255b0 (+0x48), 0x7101425660 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24399b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_24399b0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243a0e0: vf_type and its thunks 0x7101429e30 (+0x48), 0x7101429e40 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101429f10).
// Its base and its other functions aren't written here.
class Unk_243a0d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_243a0d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243a260: vf_type and its thunks 0x710142b0a0 (+0x48), 0x710142b110 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243a250 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c44f8::Unk_GetType());
        return &type;
    }

    ~Unk_243a250() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243a318: vf_type and its thunks 0x710142c6e0 (+0x48), 0x710142c6f0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710142c700).
// Its base and its other functions aren't written here.
class Unk_243a308 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_243a308() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71014197e0
// 0x71014198b0
// 0x7101419960
const Unk_239a418_Type* Unk_2438f20::vf_type() {
    return Unk_GetType();
}

// 0x71014223a0
// 0x7101422470
// 0x7101422520
const Unk_239a418_Type* Unk_2439538::vf_type() {
    return Unk_GetType();
}

// 0x71014254e0
// 0x71014255b0
// 0x7101425660
const Unk_239a418_Type* Unk_24399b0::vf_type() {
    return Unk_GetType();
}

// 0x7101425990
// 0x71014259c0
// 0x71014259d0
const Unk_239a418_Type* Unk_2439900::vf_type() {
    return Unk_GetType();
}

// 0x7101429d60
// 0x7101429e30
// 0x7101429e40
const Unk_239a418_Type* Unk_243a0d0::vf_type() {
    return Unk_GetType();
}

// 0x710142aeb0
// 0x710142b0a0
// 0x710142b110
const Unk_239a418_Type* Unk_243a250::vf_type() {
    return Unk_GetType();
}

// 0x710142c6d0
// 0x710142c6e0
// 0x710142c6f0
const Unk_239a418_Type* Unk_243a308::vf_type() {
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

// 0x7101418820
template bool Unk_61a530<Unk_2438f20>(Unk_239a498* object);
