// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027da068: its getter is out of line.
struct Unk_23dd630 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023f1740: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23f1730 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dd630::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// 0x7100e3c930
const Unk_239a418_Type* Unk_23f1730::vf6() {
    return Unk_GetType();
}
