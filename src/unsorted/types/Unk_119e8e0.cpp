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

// The type 0x71027eb320.
struct Unk_241e360 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419800::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241e4b0: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_241e4a0 {
    const Unk_239a418_Type* vf0();
};

// 0x710119e8e0
const Unk_239a418_Type* Unk_241e4a0::vf0() {
    return Unk_241e360::Unk_GetType();
}
