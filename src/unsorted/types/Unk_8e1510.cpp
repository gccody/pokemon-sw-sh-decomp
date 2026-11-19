// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x71023bc560: vf_type (its thunks 0x71008e1600 (+0x48), 0x71008e1610 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23bc550 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71023bc610: vf_type (its thunks 0x71008e19e0 (+0x48), 0x71008e19f0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23bc600 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71023bc6c0: vf_type (its thunks 0x71008e1d90 (+0x48), 0x71008e1da0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23bc6b0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x71008e1510
const Unk_239a418_Type* Unk_23bc550::vf_type() {
    return Unk_GetType();
}

// 0x71008e1850
const Unk_239a418_Type* Unk_23bc600::vf_type() {
    return Unk_GetType();
}

// 0x71008e1c00
const Unk_239a418_Type* Unk_23bc6b0::vf_type() {
    return Unk_GetType();
}
