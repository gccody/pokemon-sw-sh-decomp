// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ce8c8: its getter is out of line.
struct Unk_23f6328 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e23d8: its getter is out of line.
struct Unk_24034f8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027ce8b8.
struct Unk_23f6218 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f6328::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102403c40: vf_type and its thunks 0x7100fd3350 (+0x48), 0x7100fd33c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2403c30 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
        return &type;
    }

    ~Unk_2403c30() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102403e70: vf_type and its thunks 0x7100fd5ee0 (+0x48), 0x7100fd5f90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2403e60 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f6218::Unk_GetType());
        return &type;
    }

    ~Unk_2403e60() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100fd3160
// 0x7100fd3350
// 0x7100fd33c0
const Unk_239a418_Type* Unk_2403c30::vf_type() {
    return Unk_GetType();
}

// 0x7100fd5e10
// 0x7100fd5ee0
// 0x7100fd5f90
const Unk_239a418_Type* Unk_2403e60::vf_type() {
    return Unk_GetType();
}
