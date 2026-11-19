// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ea0e0: its getter is out of line.
struct Unk_2419800 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e9fe0: its getter is out of line.
struct Unk_2419968 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71024196a0: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2419690 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419800::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// vtable 0x7102419ae0: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2419ad0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// 0x710112f4c0
const Unk_239a418_Type* Unk_2419690::vf6() {
    return Unk_GetType();
}

// 0x7101132e40
const Unk_239a418_Type* Unk_2419ad0::vf6() {
    return Unk_GetType();
}
