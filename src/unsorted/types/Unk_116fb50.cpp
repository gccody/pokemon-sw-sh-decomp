// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8f98: its getter is out of line.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e9d10: its getter is out of line.
struct Unk_27e9d10 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d8f88.
struct Unk_241b428 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241c020: vf_type and its thunks 0x710116fda0 (+0x48), 0x710116fe10 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241c010 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e9d10::Unk_GetType());
        return &type;
    }

    ~Unk_241c010() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710241c0e8: vf_type and its thunks 0x71011714f0 (+0x48), 0x7101171560 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241c0d8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_241c0d8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710241c228: vf_type and its thunks 0x7101173520 (+0x48), 0x7101173590 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241c218 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_241c218() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710241c3d0: vf_type and its thunks 0x7101176650 (+0x48), 0x7101176700 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241c3c0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241b428::Unk_GetType());
        return &type;
    }

    ~Unk_241c3c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710116fb50
// 0x710116fda0
// 0x710116fe10
const Unk_239a418_Type* Unk_241c010::vf_type() {
    return Unk_GetType();
}

// 0x7101171360
// 0x71011714f0
// 0x7101171560
const Unk_239a418_Type* Unk_241c0d8::vf_type() {
    return Unk_GetType();
}

// 0x7101173490
// 0x7101173520
// 0x7101173590
const Unk_239a418_Type* Unk_241c218::vf_type() {
    return Unk_GetType();
}

// 0x7101176440
// 0x7101176650
// 0x7101176700
const Unk_239a418_Type* Unk_241c3c0::vf_type() {
    return Unk_GetType();
}
