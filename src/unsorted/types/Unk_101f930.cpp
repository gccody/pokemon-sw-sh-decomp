// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e1e60.
struct Unk_27e1e60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71024085a8: a type getter in its slot 8, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2408598 {
    const Unk_239a418_Type* vf8();
};

// 0x710101f930
const Unk_239a418_Type* Unk_2408598::vf8() {
    return Unk_27e1e60::Unk_GetType();
}
