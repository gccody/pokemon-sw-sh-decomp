// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e9fe0: its getter is out of line.
struct Unk_2419968 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710241c730: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_241c720 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// 0x71011795f0
const Unk_239a418_Type* Unk_241c720::vf6() {
    return Unk_GetType();
}
