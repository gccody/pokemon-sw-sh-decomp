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

// The type 0x71027d6950: its getter is out of line.
struct Unk_23cf990 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d88f8: its getter is out of line.
struct Unk_23d2970 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d8528: its getter is out of line.
struct Unk_27d8528 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d6250.
struct Unk_2399d08 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8518.
struct Unk_23cf760 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8528::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8538.
struct Unk_27d8538 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23cf760::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8578.
struct Unk_23cf3c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8538::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023d2028: vf_type and its thunks 0x7100b8cb30 (+0x48), 0x7100b8cba0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d2018 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23cf990::Unk_GetType());
        return &type;
    }

    ~Unk_23d2018() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d2148: vf_type and its thunks 0x7100b94140 (+0x48), 0x7100b94150 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100b3adb0).
// Its base and its other functions aren't written here.
class Unk_23d2138 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23cf3c0::Unk_GetType());
        return &type;
    }

    ~Unk_23d2138() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d23a0: vf_type and its thunks 0x7100b957b0 (+0x48), 0x7100b95820 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d2390 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23cf990::Unk_GetType());
        return &type;
    }

    ~Unk_23d2390() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d2738: vf_type and its thunks 0x7100b9f180 (+0x48), 0x7100b9f1f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d2728 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d2970::Unk_GetType());
        return &type;
    }

    ~Unk_23d2728() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023d2d98: vf_type and its thunks 0x7100ba3c60 (+0x48), 0x7100ba3d10 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d2d88 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23d2d88() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023d2f68: vf_type and its thunks 0x7100ba4650 (+0x48), 0x7100ba4660 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100ba4690).
// Its base and its other functions aren't written here.
class Unk_23d2f58 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23d2f58() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d8908.
struct Unk_23f7638 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
        return &type;
    }
};

// 0x7100b8caa0
// 0x7100b8cb30
// 0x7100b8cba0
const Unk_239a418_Type* Unk_23d2018::vf_type() {
    return Unk_GetType();
}

// 0x7100b94120
// 0x7100b94140
// 0x7100b94150
const Unk_239a418_Type* Unk_23d2138::vf_type() {
    return Unk_GetType();
}

// 0x7100b95720
// 0x7100b957b0
// 0x7100b95820
const Unk_239a418_Type* Unk_23d2390::vf_type() {
    return Unk_GetType();
}

// 0x7100b9f0c0
// 0x7100b9f180
// 0x7100b9f1f0
const Unk_239a418_Type* Unk_23d2728::vf_type() {
    return Unk_GetType();
}

// 0x7100ba3b90
// 0x7100ba3c60
// 0x7100ba3d10
const Unk_239a418_Type* Unk_23d2d88::vf_type() {
    return Unk_GetType();
}

// 0x7100ba4620
// 0x7100ba4650
// 0x7100ba4660
const Unk_239a418_Type* Unk_23d2f58::vf_type() {
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

// 0x7100b9ff30
template bool Unk_61a530<Unk_23f7638>(Unk_239a498* object);
