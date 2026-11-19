// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027da5a8.
struct Unk_27da5a8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(&Unk_239a418_RootType());
        return &type;
    }
};

// The type 0x71027da5b8.
struct Unk_27da5b8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da5a8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027da5c8.
struct Unk_27da5c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da5a8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027da5d8.
struct Unk_27da5d8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da5a8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027da5e8.
struct Unk_27da5e8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da5a8::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e0e48: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23e0e38 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x71023e0e70: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23e0e60 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x71023e0e98: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23e0e88 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x71023e0ec0: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23e0eb0 {
    const Unk_239a418_Type* vf0();
};

// 0x7100cac7b0
const Unk_239a418_Type* Unk_23e0e38::vf0() {
    return Unk_27da5b8::Unk_GetType();
}

// 0x7100cac8f0
const Unk_239a418_Type* Unk_23e0e60::vf0() {
    return Unk_27da5c8::Unk_GetType();
}

// 0x7100cac9f0
const Unk_239a418_Type* Unk_23e0e88::vf0() {
    return Unk_27da5d8::Unk_GetType();
}

// 0x7100cacaf0
const Unk_239a418_Type* Unk_23e0eb0::vf0() {
    return Unk_27da5e8::Unk_GetType();
}
