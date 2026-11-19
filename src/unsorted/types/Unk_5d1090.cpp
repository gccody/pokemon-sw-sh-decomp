// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102771610: its getter is out of line.
struct Unk_2771610 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102771600.
struct Unk_2771600 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2771610::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023994e8: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23994d8 {
    const Unk_239a418_Type* vf5();
};

// 0x71005d1090
const Unk_239a418_Type* Unk_23994d8::vf5() {
    return Unk_2771600::Unk_GetType();
}
