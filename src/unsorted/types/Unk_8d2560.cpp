// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023bb998: vf_type and its thunks 0x71008d2940 (+0x48), 0x71008d2950 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71008d2bf0).
// Its base and its other functions aren't written here.
class Unk_23bb988 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23bb988() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023bba48: vf_type and its thunks 0x71008d2630 (+0x48), 0x71008d26e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23bba38 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23bba38() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023bc2d0: vf_type and its thunks 0x71008dd270 (+0x48), 0x71008dd280 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71008dd2f0).
// Its base and its other functions aren't written here.
class Unk_23bc2c0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_23bc2c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9318.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023bc770: vf_type and its thunks 0x71008e33f0 (+0x48), 0x71008e3400 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71008e3410).
// Its base and its other functions aren't written here.
class Unk_23bc760 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23bc760() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71008d2560
// 0x71008d2630
// 0x71008d26e0
const Unk_239a418_Type* Unk_23bba38::vf_type() {
    return Unk_GetType();
}

// 0x71008d2870
// 0x71008d2940
// 0x71008d2950
const Unk_239a418_Type* Unk_23bb988::vf_type() {
    return Unk_GetType();
}

// 0x71008dd200
// 0x71008dd270
// 0x71008dd280
const Unk_239a418_Type* Unk_23bc2c0::vf_type() {
    return Unk_GetType();
}

// 0x71008e33e0
// 0x71008e33f0
// 0x71008e3400
const Unk_239a418_Type* Unk_23bc760::vf_type() {
    return Unk_GetType();
}
