// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027f08f0: its getter is out of line.
struct Unk_243a558 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710243a6b0: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_243a6a0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_243a558::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// vtable 0x710243a7f8: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_243a7e8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_243a558::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// 0x710142f700
const Unk_239a418_Type* Unk_243a6a0::vf6() {
    return Unk_GetType();
}

// 0x710142f9a0
const Unk_239a418_Type* Unk_243a7e8::vf6() {
    return Unk_GetType();
}
