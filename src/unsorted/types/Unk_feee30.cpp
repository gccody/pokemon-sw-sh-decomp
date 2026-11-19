// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d1a28.
struct Unk_27d1a28 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102405ee0: a type getter in its slot 2, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2405ed0 {
    const Unk_239a418_Type* vf2();
};

// 0x7100feee30
const Unk_239a418_Type* Unk_2405ed0::vf2() {
    return Unk_27d1a28::Unk_GetType();
}
