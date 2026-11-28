// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6230: its getter is out of line.
struct Unk_23dcdd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d6220.
struct Unk_23ddd68 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dcdd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027efd50.
struct Unk_23e3950 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23ddd68::Unk_GetType());
        return &type;
    }
};

// The type 0x71027f03a8.
struct Unk_23e7fe8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e3950::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e8278: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23e8268 {
    const Unk_239a418_Type* vf0();
};

// 0x7100d11780
const Unk_239a418_Type* Unk_23e8268::vf0() {
    return Unk_23e7fe8::Unk_GetType();
}
