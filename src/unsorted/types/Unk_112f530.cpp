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

// The type 0x71027e9fe0.
struct Unk_2419968 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ea0e0.
struct Unk_2419800 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ea0d0.
struct Unk_2419690 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419800::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102419770: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2419760 {
    const Unk_239a418_Type* vf5();
};

// 0x710112f530
const Unk_239a418_Type* Unk_2419760::vf5() {
    return Unk_2419690::Unk_GetType();
}
