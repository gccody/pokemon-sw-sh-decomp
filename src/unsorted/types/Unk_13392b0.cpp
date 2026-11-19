// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0590.
struct Unk_23f43c8 {
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

// vtable 0x7102430e20: vf_type and its thunks 0x71013392e0 (+0x48), 0x71013392f0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101339320).
// Its base and its other functions aren't written here.
class Unk_2430e10 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_2430e10() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102430ef0: vf_type and its thunks 0x710133ca60 (+0x48), 0x710133ca70 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710133cb80).
// Its base and its other functions aren't written here.
class Unk_2430ee0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_2430ee0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71013392b0
// 0x71013392e0
// 0x71013392f0
const Unk_239a418_Type* Unk_2430e10::vf_type() {
    return Unk_GetType();
}

// 0x710133c950
// 0x710133ca60
// 0x710133ca70
const Unk_239a418_Type* Unk_2430ee0::vf_type() {
    return Unk_GetType();
}
