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

// vtable 0x71023c5d78: vf_type and its thunks 0x7100a704b0 (+0x48), 0x7100a704c0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100a70780).
// Its base and its other functions aren't written here.
class Unk_23c5d68 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23c5d68() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023c5e28: vf_type and its thunks 0x7100a70220 (+0x48), 0x7100a702d0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c5e18 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23c5e18() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023c6040: vf_type and its thunks 0x7100a72ee0 (+0x48), 0x7100a72ef0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100a73040).
// Its base and its other functions aren't written here.
class Unk_23c6030 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23c6030() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100a70150
// 0x7100a70220
// 0x7100a702d0
const Unk_239a418_Type* Unk_23c5e18::vf_type() {
    return Unk_GetType();
}

// 0x7100a70480
// 0x7100a704b0
// 0x7100a704c0
const Unk_239a418_Type* Unk_23c5d68::vf_type() {
    return Unk_GetType();
}

// 0x7100a72d90
// 0x7100a72ee0
// 0x7100a72ef0
const Unk_239a418_Type* Unk_23c6030::vf_type() {
    return Unk_GetType();
}
