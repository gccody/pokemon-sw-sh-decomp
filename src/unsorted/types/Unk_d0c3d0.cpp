// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027efd90: its getter is out of line.
struct Unk_23dd820 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efd80.
struct Unk_23e4758 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dd820::Unk_GetType());
        return &type;
    }
};

// The type 0x71027efe70.
struct Unk_23ea898 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e4758::Unk_GetType());
        return &type;
    }
};

// The type 0x71027eff40.
struct Unk_23e7750 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23ea898::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e79e0: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23e79d0 {
    const Unk_239a418_Type* vf5();
};

// 0x7100d0c3d0
const Unk_239a418_Type* Unk_23e79d0::vf5() {
    return Unk_23e7750::Unk_GetType();
}
