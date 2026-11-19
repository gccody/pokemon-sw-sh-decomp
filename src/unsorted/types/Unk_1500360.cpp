// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0620: its getter is out of line.
struct Unk_2444ca0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71024463a8: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2446398 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444ca0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// 0x7101500360
const Unk_239a418_Type* Unk_2446398::vf6() {
    return Unk_GetType();
}
