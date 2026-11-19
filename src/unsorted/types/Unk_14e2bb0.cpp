// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6ac0: its getter is out of line.
struct Unk_23c44f8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e0630: its getter is out of line.
struct Unk_2444850 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e05f0: its getter is out of line.
struct Unk_2444b38 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71024446d0: vf_type and its thunks 0x71014e2c80 (+0x48), 0x71014e2cf0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24446c0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444b38::Unk_GetType());
        return &type;
    }

    ~Unk_24446c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024449b0: vf_type and its thunks 0x71014e5780 (+0x48), 0x71014e57f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24449a0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444850::Unk_GetType());
        return &type;
    }

    ~Unk_24449a0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102444ea0: vf_type and its thunks 0x71014e9aa0 (+0x48), 0x71014e9b10 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2444e90 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c44f8::Unk_GetType());
        return &type;
    }

    ~Unk_2444e90() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71014e2bb0
// 0x71014e2c80
// 0x71014e2cf0
const Unk_239a418_Type* Unk_24446c0::vf_type() {
    return Unk_GetType();
}

// 0x71014e56d0
// 0x71014e5780
// 0x71014e57f0
const Unk_239a418_Type* Unk_24449a0::vf_type() {
    return Unk_GetType();
}

// 0x71014e98b0
// 0x71014e9aa0
// 0x71014e9b10
const Unk_239a418_Type* Unk_2444e90::vf_type() {
    return Unk_GetType();
}
