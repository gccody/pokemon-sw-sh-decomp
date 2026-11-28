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

// The type 0x71027ea118.
struct Unk_241c720 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ebc80.
struct Unk_241f700 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419800::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ebc90.
struct Unk_241f868 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241c720::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241f850: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_241f840 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710241f9b8: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_241f9a8 {
    const Unk_239a418_Type* vf0();
};

// 0x71011b8c10
const Unk_239a418_Type* Unk_241f840::vf0() {
    return Unk_241f700::Unk_GetType();
}

// 0x71011b8ee0
const Unk_239a418_Type* Unk_241f9a8::vf0() {
    return Unk_241f868::Unk_GetType();
}
