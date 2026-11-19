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

// The type 0x71027de920: its getter is out of line.
struct Unk_27de920 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027effd0: its getter is out of line.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023eff20: vf_type and its thunks 0x7100dcd850 (+0x48), 0x7100dcd8c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23eff10 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27de920::Unk_GetType());
        return &type;
    }

    ~Unk_23eff10() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027da210.
struct Unk_27da210 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027deba0.
struct Unk_23f05a8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da210::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f0748: vf_type and its thunks 0x7100dd87b0 (+0x48), 0x7100dd8820 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f0738 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23f0738() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f0830: vf_type and its thunks 0x7100ddb4c0 (+0x48), 0x7100ddb530 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f0820 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23f0820() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100dcd7c0
// 0x7100dcd850
// 0x7100dcd8c0
const Unk_239a418_Type* Unk_23eff10::vf_type() {
    return Unk_GetType();
}

// 0x7100dd80a0
// 0x7100dd87b0
// 0x7100dd8820
const Unk_239a418_Type* Unk_23f0738::vf_type() {
    return Unk_GetType();
}

// 0x7100ddb040
// 0x7100ddb4c0
// 0x7100ddb530
const Unk_239a418_Type* Unk_23f0820::vf_type() {
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

// 0x7100dd4e40
template bool Unk_61a530<Unk_23f05a8>(Unk_239a498* object);
