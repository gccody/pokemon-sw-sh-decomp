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

// The type 0x7102777228.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
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

// vtable 0x7102437960: vf_type and its thunks 0x71014056f0 (+0x48), 0x7101405710 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71014058c0).
// Its base and its other functions aren't written here.
class Unk_2437950 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_2437950() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024384c0: vf_type and its thunks 0x710140ef60 (+0x48), 0x710140ef70 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710140f090).
// Its base and its other functions aren't written here.
class Unk_24384b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_24384b0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102438588: vf_type and its thunks 0x710140ecd0 (+0x48), 0x710140ed80 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2438578 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_2438578() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101405250
// 0x71014056f0
// 0x7101405710
const Unk_239a418_Type* Unk_2437950::vf_type() {
    return Unk_GetType();
}

// 0x710140ec00
// 0x710140ecd0
// 0x710140ed80
const Unk_239a418_Type* Unk_2438578::vf_type() {
    return Unk_GetType();
}

// 0x710140ef30
// 0x710140ef60
// 0x710140ef70
const Unk_239a418_Type* Unk_24384b0::vf_type() {
    return Unk_GetType();
}
