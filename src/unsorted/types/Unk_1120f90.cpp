// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e9e60: its getter is out of line.
struct Unk_241ff00 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102418fd0: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2418fc0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241ff00::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// 0x7101120f90
const Unk_239a418_Type* Unk_2418fc0::vf6() {
    return Unk_GetType();
}
