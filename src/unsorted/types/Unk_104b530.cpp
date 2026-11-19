// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e3800.
struct Unk_27e3800 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(&Unk_239a418_RootType());
        return &type;
    }
};

// vtable 0x710240b0e8: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_240b0d8 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x710240b160: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_240b150 {
    const Unk_239a418_Type* vf0();
};

// 0x710104b530
const Unk_239a418_Type* Unk_240b0d8::vf5() {
    return Unk_27e3800::Unk_GetType();
}

// 0x710104b680
const Unk_239a418_Type* Unk_240b150::vf0() {
    return Unk_27e3800::Unk_GetType();
}
