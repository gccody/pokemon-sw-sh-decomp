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

// vtable 0x710243cb18: vf_type and its thunks 0x7101456a90 (+0x48), 0x7101456aa0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101456b90).
// Its base and its other functions aren't written here.
class Unk_243cb08 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_243cb08() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243cbc8: vf_type and its thunks 0x7101456740 (+0x48), 0x71014567f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243cbb8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_243cbb8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101456670
// 0x7101456740
// 0x71014567f0
const Unk_239a418_Type* Unk_243cbb8::vf_type() {
    return Unk_GetType();
}

// 0x71014569a0
// 0x7101456a90
// 0x7101456aa0
const Unk_239a418_Type* Unk_243cb08::vf_type() {
    return Unk_GetType();
}
