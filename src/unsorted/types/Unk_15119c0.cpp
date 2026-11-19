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

// vtable 0x71024471c8: vf_type and its thunks 0x7101511c50 (+0x48), 0x7101511c60 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101513650).
// Its base and its other functions aren't written here.
class Unk_24471b8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_24471b8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102447278: vf_type and its thunks 0x7101511a90 (+0x48), 0x7101511b40 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2447268 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_2447268() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71015119c0
// 0x7101511a90
// 0x7101511b40
const Unk_239a418_Type* Unk_2447268::vf_type() {
    return Unk_GetType();
}

// 0x7101511c20
// 0x7101511c50
// 0x7101511c60
const Unk_239a418_Type* Unk_24471b8::vf_type() {
    return Unk_GetType();
}
