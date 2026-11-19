// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027f1520.
struct Unk_27f1520 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(nullptr);
        return &type;
    }
};

// The type 0x71027f1530.
struct Unk_27f1530 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f1520::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102443100: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_24430f0 {
    const Unk_239a418_Type* vf0();
};

// 0x71014bce50
const Unk_239a418_Type* Unk_24430f0::vf0() {
    return Unk_27f1530::Unk_GetType();
}
