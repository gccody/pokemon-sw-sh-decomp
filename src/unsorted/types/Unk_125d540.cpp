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

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102427970: vf_type and its thunks 0x710125d8b0 (+0x48), 0x710125d8c0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710125de00).
// Its base and its other functions aren't written here.
class Unk_2427960 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_2427960() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102427a80: vf_type and its thunks 0x710125d610 (+0x48), 0x710125d6c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2427a70 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_2427a70() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102427c58: vf_type and its thunks 0x710125f810 (+0x48), 0x710125f880 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2427c48 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_2427c48() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710125d540
// 0x710125d610
// 0x710125d6c0
const Unk_239a418_Type* Unk_2427a70::vf_type() {
    return Unk_GetType();
}

// 0x710125d880
// 0x710125d8b0
// 0x710125d8c0
const Unk_239a418_Type* Unk_2427960::vf_type() {
    return Unk_GetType();
}

// 0x710125f780
// 0x710125f810
// 0x710125f880
const Unk_239a418_Type* Unk_2427c48::vf_type() {
    return Unk_GetType();
}
