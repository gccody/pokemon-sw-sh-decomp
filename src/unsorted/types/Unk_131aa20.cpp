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

// The type 0x71027ce9f8: its getter is out of line.
struct Unk_27ce9f8 {
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

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x710242f8d8: vf_type and its thunks 0x710131ae40 (+0x48), 0x710131ae50 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710131b690).
// Its base and its other functions aren't written here.
class Unk_242f8c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_242f8c8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710242f988: vf_type and its thunks 0x710131aaf0 (+0x48), 0x710131aba0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242f978 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_242f978() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710242fb40: vf_type and its thunks 0x710131f4d0 (+0x48), 0x710131f4e0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710131f690).
// Its base and its other functions aren't written here.
class Unk_242fb30 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_242fb30() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710242fc70: vf_type and its thunks 0x71013200e0 (+0x48), 0x7101320150 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242fc60 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_242fc60() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710131aa20
// 0x710131aaf0
// 0x710131aba0
const Unk_239a418_Type* Unk_242f978::vf_type() {
    return Unk_GetType();
}

// 0x710131ad50
// 0x710131ae40
// 0x710131ae50
const Unk_239a418_Type* Unk_242f8c8::vf_type() {
    return Unk_GetType();
}

// 0x710131f320
// 0x710131f4d0
// 0x710131f4e0
const Unk_239a418_Type* Unk_242fb30::vf_type() {
    return Unk_GetType();
}

// 0x710131fd00
// 0x71013200e0
// 0x7101320150
const Unk_239a418_Type* Unk_242fc60::vf_type() {
    return Unk_GetType();
}
