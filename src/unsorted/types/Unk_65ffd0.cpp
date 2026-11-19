// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71024ba530: its getter is out of line.
struct Unk_24ba530 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71024ba520.
struct Unk_24ba520 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24ba530::Unk_GetType());
        return &type;
    }
};

// vtable 0x710239f920: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239f910 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x710239f9f8: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239f9e8 {
    const Unk_239a418_Type* vf0();
};

// 0x710065ffd0
const Unk_239a418_Type* Unk_239f910::vf5() {
    return Unk_24ba520::Unk_GetType();
}

// 0x7100660040
const Unk_239a418_Type* Unk_239f9e8::vf0() {
    return Unk_24ba520::Unk_GetType();
}
