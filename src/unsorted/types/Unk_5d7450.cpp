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

// The type 0x7102773670.
struct Unk_2773670 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2771610::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102399890: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2399880 {
    const Unk_239a418_Type* vf5();
};

// 0x71005d7450
const Unk_239a418_Type* Unk_2399880::vf5() {
    return Unk_2773670::Unk_GetType();
}
