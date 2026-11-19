// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102771600: its getter is out of line.
struct Unk_2771600 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e0530.
struct Unk_27e0530 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2771600::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f4128: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23f4118 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x71023f41b8: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23f41a8 {
    const Unk_239a418_Type* vf0();
};

// 0x7100e7af00
const Unk_239a418_Type* Unk_23f4118::vf5() {
    return Unk_27e0530::Unk_GetType();
}

// 0x7100e7b090
const Unk_239a418_Type* Unk_23f41a8::vf0() {
    return Unk_27e0530::Unk_GetType();
}
