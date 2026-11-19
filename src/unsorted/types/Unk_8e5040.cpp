// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

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

// vtable 0x71023bc870: vf_type and its thunks 0x71008e5110 (+0x48), 0x71008e51c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23bc860 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23bc860() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023bca28: vf_type and its thunks 0x71008e6210 (+0x48), 0x71008e6280 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23bca18 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23bca18() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023bcb50: vf_type and its thunks 0x71008e6fd0 (+0x48), 0x71008e6fe0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71008e5870).
// Its base and its other functions aren't written here.
class Unk_23bcb40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23bcb40() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71008e5040
// 0x71008e5110
// 0x71008e51c0
const Unk_239a418_Type* Unk_23bc860::vf_type() {
    return Unk_GetType();
}

// 0x71008e6180
// 0x71008e6210
// 0x71008e6280
const Unk_239a418_Type* Unk_23bca18::vf_type() {
    return Unk_GetType();
}

// 0x71008e6fa0
// 0x71008e6fd0
// 0x71008e6fe0
const Unk_239a418_Type* Unk_23bcb40::vf_type() {
    return Unk_GetType();
}
