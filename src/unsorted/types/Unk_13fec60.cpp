// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x71024371b8: vf_type (its thunks 0x71013fed50 (+0x48), 0x71013fed60 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_24371a8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x7102437348: vf_type (its thunks 0x71014006e0 (+0x48), 0x71014006f0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_2437338 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x7102437428: vf_type (its thunks 0x7101400c70 (+0x48), 0x7101400c80 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_2437418 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71024374d8: vf_type (its thunks 0x7101401290 (+0x48), 0x71014012a0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_24374c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x71013fec60
const Unk_239a418_Type* Unk_24371a8::vf_type() {
    return Unk_GetType();
}

// 0x71014005f0
const Unk_239a418_Type* Unk_2437338::vf_type() {
    return Unk_GetType();
}

// 0x7101400a60
const Unk_239a418_Type* Unk_2437418::vf_type() {
    return Unk_GetType();
}

// 0x7101401180
const Unk_239a418_Type* Unk_24374c8::vf_type() {
    return Unk_GetType();
}
