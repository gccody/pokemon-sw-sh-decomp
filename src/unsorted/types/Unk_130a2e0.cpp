// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ef2b8.
struct Unk_27ef2b8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(nullptr);
        return &type;
    }
};

// vtable 0x710242f630: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_242f620 {
    const Unk_239a418_Type* vf0();
};

// 0x710130a2e0
const Unk_239a418_Type* Unk_242f620::vf0() {
    return Unk_27ef2b8::Unk_GetType();
}
