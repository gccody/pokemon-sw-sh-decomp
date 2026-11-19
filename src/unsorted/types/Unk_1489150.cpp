// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027f0458: its getter is out of line.
struct Unk_23c0390 {
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

// vtable 0x710243ff40: vf_type and its thunks 0x7101489530 (+0x48), 0x7101489540 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101489610).
// Its base and its other functions aren't written here.
class Unk_243ff30 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_243ff30() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243fff0: vf_type and its thunks 0x7101489220 (+0x48), 0x71014892d0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243ffe0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_243ffe0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102441f18: vf_type and its thunks 0x71014a96d0 (+0x48), 0x71014a9740 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2441f08 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c0390::Unk_GetType());
        return &type;
    }

    ~Unk_2441f08() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101489150
// 0x7101489220
// 0x71014892d0
const Unk_239a418_Type* Unk_243ffe0::vf_type() {
    return Unk_GetType();
}

// 0x7101489460
// 0x7101489530
// 0x7101489540
const Unk_239a418_Type* Unk_243ff30::vf_type() {
    return Unk_GetType();
}

// 0x71014a9650
// 0x71014a96d0
// 0x71014a9740
const Unk_239a418_Type* Unk_2441f08::vf_type() {
    return Unk_GetType();
}
