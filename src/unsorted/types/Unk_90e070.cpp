// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0590: its getter is out of line.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e05b0: its getter is out of line.
struct Unk_23f4660 {
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

// vtable 0x71023bdbc0: vf_type and its thunks 0x710090e140 (+0x48), 0x710090e1f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23bdbb0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23bdbb0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023bdda8: vf_type and its thunks 0x710090f050 (+0x48), 0x710090f060 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100967370).
// Its base and its other functions aren't written here.
class Unk_23bdd98 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23bdd98() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d2f70.
struct Unk_27d2f70 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2f80.
struct Unk_23be158 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2f70::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2f60.
struct Unk_23be300 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2f70::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2fa0.
struct Unk_27d2fa0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2ff0.
struct Unk_23be5d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d3000.
struct Unk_23bed10 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2fc0.
struct Unk_23befd8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d3010.
struct Unk_23bf468 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2fb0.
struct Unk_23bf7e0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2fd0.
struct Unk_23bf9d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2fe0.
struct Unk_23bfb98 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d2f90.
struct Unk_23bff18 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }
};

// 0x710090e070
// 0x710090e140
// 0x710090e1f0
const Unk_239a418_Type* Unk_23bdbb0::vf_type() {
    return Unk_GetType();
}

// 0x710090f020
// 0x710090f050
// 0x710090f060
const Unk_239a418_Type* Unk_23bdd98::vf_type() {
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

// 0x710090f090
template bool Unk_61a530<Unk_23bdbb0>(Unk_239a498* object);

// 0x71009138b0
template bool Unk_61a530<Unk_23be300>(Unk_239a498* object);

// 0x71009139a0
template bool Unk_61a530<Unk_23be158>(Unk_239a498* object);

// 0x7100914cf0
template bool Unk_61a530<Unk_23bff18>(Unk_239a498* object);

// 0x7100914f30
template bool Unk_61a530<Unk_23bf7e0>(Unk_239a498* object);

// 0x7100915020
template bool Unk_61a530<Unk_23befd8>(Unk_239a498* object);

// 0x7100915110
template bool Unk_61a530<Unk_23bf9d0>(Unk_239a498* object);

// 0x7100915350
template bool Unk_61a530<Unk_23bfb98>(Unk_239a498* object);

// 0x7100915590
template bool Unk_61a530<Unk_23be5d0>(Unk_239a498* object);

// 0x7100915680
template bool Unk_61a530<Unk_23bed10>(Unk_239a498* object);

// 0x71009158c0
template bool Unk_61a530<Unk_23bf468>(Unk_239a498* object);
