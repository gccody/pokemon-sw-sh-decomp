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

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023c0168: vf_type and its thunks 0x710093c1e0 (+0x48), 0x710093c1f0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100939c20).
// Its base and its other functions aren't written here.
class Unk_23c0158 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23c0158() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023c0570: vf_type and its thunks 0x710093e230 (+0x48), 0x710093e2e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c0560 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23c0560() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023c06d0: vf_type and its thunks 0x710093e840 (+0x48), 0x710093e850 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710093e3b0).
// Its base and its other functions aren't written here.
class Unk_23c06c0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23c06c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710093c1b0
// 0x710093c1e0
// 0x710093c1f0
const Unk_239a418_Type* Unk_23c0158::vf_type() {
    return Unk_GetType();
}

// 0x710093e160
// 0x710093e230
// 0x710093e2e0
const Unk_239a418_Type* Unk_23c0560::vf_type() {
    return Unk_GetType();
}

// 0x710093e730
// 0x710093e840
// 0x710093e850
const Unk_239a418_Type* Unk_23c06c0::vf_type() {
    return Unk_GetType();
}
