// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d85e8: its getter is out of line.
struct Unk_23d0eb0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d8740: its getter is out of line.
struct Unk_27d8740 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023d1358: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23d1348 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8740::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// vtable 0x71023d1458: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23d1448 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d0eb0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// vtable 0x71023d1770: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23d1760 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8740::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// 0x7100b7f470
const Unk_239a418_Type* Unk_23d1348::vf6() {
    return Unk_GetType();
}

// 0x7100b7fae0
const Unk_239a418_Type* Unk_23d1448::vf6() {
    return Unk_GetType();
}

// 0x7100b82840
const Unk_239a418_Type* Unk_23d1760::vf6() {
    return Unk_GetType();
}
