// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e3a28.
struct Unk_27e3a28 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x71027e3a48.
struct Unk_27e3a48 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x71027e3a58.
struct Unk_27e3a58 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x710240c100: a type getter in its slot 3, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_240c0f0 {
    const Unk_239a418_Type* vf3();
};

// vtable 0x710240c2e8: a type getter in its slot 3, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_240c2d8 {
    const Unk_239a418_Type* vf3();
};

// vtable 0x710240c3f8: a type getter in its slot 2, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_240c3e8 {
    const Unk_239a418_Type* vf2();
};

// 0x710105ce20
const Unk_239a418_Type* Unk_240c0f0::vf3() {
    return Unk_27e3a28::Unk_GetType();
}

// 0x710105d620
const Unk_239a418_Type* Unk_240c2d8::vf3() {
    return Unk_27e3a48::Unk_GetType();
}

// 0x710105d9d0
const Unk_239a418_Type* Unk_240c3e8::vf2() {
    return Unk_27e3a58::Unk_GetType();
}
