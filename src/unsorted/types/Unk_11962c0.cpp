// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ea148: its getter is out of line.
struct Unk_241b640 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027ea138.
struct Unk_27ea138 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241b640::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241d1a0: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_241d190 {
    const Unk_239a418_Type* vf6();
};

// 0x71011962c0
const Unk_239a418_Type* Unk_241d190::vf6() {
    return Unk_27ea138::Unk_GetType();
}
