// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e09b0.
struct Unk_27e09b0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(&Unk_239a418_RootType());
        return &type;
    }
};

// The type 0x71027e09c0.
struct Unk_27e09c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e09b0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e09d0.
struct Unk_27e09d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e09b0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e09e0.
struct Unk_27e09e0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e09b0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f59d0: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23f59c0 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x71023f5a00: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23f59f0 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x71023f5a30: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23f5a20 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x71023f5a60: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23f5a50 {
    const Unk_239a418_Type* vf0();
};

// 0x7100ea52a0
const Unk_239a418_Type* Unk_23f59c0::vf0() {
    return Unk_27e09c0::Unk_GetType();
}

// 0x7100ea5390
const Unk_239a418_Type* Unk_23f59f0::vf0() {
    return Unk_27e09b0::Unk_GetType();
}

// 0x7100ea5810
const Unk_239a418_Type* Unk_23f5a20::vf0() {
    return Unk_27e09d0::Unk_GetType();
}

// 0x7100ea5c40
const Unk_239a418_Type* Unk_23f5a50::vf0() {
    return Unk_27e09e0::Unk_GetType();
}
