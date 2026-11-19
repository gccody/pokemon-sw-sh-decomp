// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ec1f0: its getter is out of line.
struct Unk_2420ad0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102420810: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2420800 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2420ad0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// vtable 0x7102420c50: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2420c40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2420ad0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// vtable 0x7102420fc0: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2420fb0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2420ad0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// 0x71011d1a20
const Unk_239a418_Type* Unk_2420800::vf6() {
    return Unk_GetType();
}

// 0x71011d4b70
const Unk_239a418_Type* Unk_2420c40::vf6() {
    return Unk_GetType();
}

// 0x71011d73c0
const Unk_239a418_Type* Unk_2420fb0::vf6() {
    return Unk_GetType();
}
