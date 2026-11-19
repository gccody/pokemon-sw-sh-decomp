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

// The type 0x71027e9fe0.
struct Unk_2419968 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
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

// The type 0x71027eac60.
struct Unk_241c3c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241b428::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ea118.
struct Unk_241c720 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }
};

// The type 0x71027eb4e0.
struct Unk_241dc38 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241c720::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241dae0: vf_type and its thunks 0x71011977f0 (+0x48), 0x7101197800 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101197830).
// Its base and its other functions aren't written here.
class Unk_241dad0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241dc38::Unk_GetType());
        return &type;
    }

    ~Unk_241dad0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71011977c0
// 0x71011977f0
// 0x7101197800
const Unk_239a418_Type* Unk_241dad0::vf_type() {
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

// 0x7101198980
template bool Unk_61a530<Unk_241c3c0>(Unk_239a498* object);
