// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ebff0.
struct Unk_27ebff0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x710241fc78: a type getter in its slot 1, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_241fc68 {
    const Unk_239a418_Type* vf1();
};

// 0x71011bea00
const Unk_239a418_Type* Unk_241fc68::vf1() {
    return Unk_27ebff0::Unk_GetType();
}
