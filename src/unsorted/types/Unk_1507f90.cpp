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

// vtable 0x7102446818: vf_type and its thunks 0x7101508060 (+0x48), 0x7101508110 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2446808 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_2446808() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102446960: vf_type and its thunks 0x71015084c0 (+0x48), 0x71015084d0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101508500).
// Its base and its other functions aren't written here.
class Unk_2446950 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_2446950() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102446c18: vf_type and its thunks 0x710150c380 (+0x48), 0x710150c390 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710150c500).
// Its base and its other functions aren't written here.
class Unk_2446c08 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_2446c08() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101507f90
// 0x7101508060
// 0x7101508110
const Unk_239a418_Type* Unk_2446808::vf_type() {
    return Unk_GetType();
}

// 0x7101508490
// 0x71015084c0
// 0x71015084d0
const Unk_239a418_Type* Unk_2446950::vf_type() {
    return Unk_GetType();
}

// 0x710150c1c0
// 0x710150c380
// 0x710150c390
const Unk_239a418_Type* Unk_2446c08::vf_type() {
    return Unk_GetType();
}
