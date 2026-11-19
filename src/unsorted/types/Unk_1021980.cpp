// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e31a0.
struct Unk_27e31a0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71024087c8: a type getter in its slot 1, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_24087b8 {
    const Unk_239a418_Type* vf1();
};

// 0x7101021980
const Unk_239a418_Type* Unk_24087b8::vf1() {
    return Unk_27e31a0::Unk_GetType();
}
