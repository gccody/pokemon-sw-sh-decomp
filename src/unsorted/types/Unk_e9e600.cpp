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

// The type 0x7102774028.
struct Unk_2399708 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }
};

// The type 0x7102773680.
struct Unk_2399928 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399708::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f5088: vf_type and its thunks 0x7100e9e780 (+0x48), 0x7100e9e830 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f5078 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399708::Unk_GetType());
        return &type;
    }

    ~Unk_23f5078() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f5148: vf_type and its thunks 0x7100e9ec70 (+0x48), 0x7100e9ece0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f5138 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }

    ~Unk_23f5138() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f5508: vf_type and its thunks 0x7100ea1a60 (+0x48), 0x7100ea1ad0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f54f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }

    ~Unk_23f54f8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f55c0: vf_type and its thunks 0x7100ea2000 (+0x48), 0x7100ea2070 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f55b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }

    ~Unk_23f55b0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f5678: vf_type and its thunks 0x7100ea22d0 (+0x48), 0x7100ea2340 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f5668 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }

    ~Unk_23f5668() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100e9e600
// 0x7100e9e780
// 0x7100e9e830
const Unk_239a418_Type* Unk_23f5078::vf_type() {
    return Unk_GetType();
}

// 0x7100e9ebd0
// 0x7100e9ec70
// 0x7100e9ece0
const Unk_239a418_Type* Unk_23f5138::vf_type() {
    return Unk_GetType();
}

// 0x7100ea1910
// 0x7100ea1a60
// 0x7100ea1ad0
const Unk_239a418_Type* Unk_23f54f8::vf_type() {
    return Unk_GetType();
}

// 0x7100ea1f70
// 0x7100ea2000
// 0x7100ea2070
const Unk_239a418_Type* Unk_23f55b0::vf_type() {
    return Unk_GetType();
}

// 0x7100ea2240
// 0x7100ea22d0
// 0x7100ea2340
const Unk_239a418_Type* Unk_23f5668::vf_type() {
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

// 0x7100ea14c0
template bool Unk_61a530<Unk_2399928>(Unk_239a498* object);
