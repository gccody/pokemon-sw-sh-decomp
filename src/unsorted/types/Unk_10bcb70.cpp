// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x7102412be8: vf_type (its thunks 0x71010bcd00 (+0x48), 0x71010bcd10 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_2412bd8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x7102412e70: vf_type (its thunks 0x71010be5a0 (+0x48), 0x71010be5b0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_2412e60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71024130f8: vf_type (its thunks 0x71010bfd20 (+0x48), 0x71010bfd30 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_24130e8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71024132d0: vf_type (its thunks 0x71010c0fe0 (+0x48), 0x71010c0ff0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_24132c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x71010bcb70
const Unk_239a418_Type* Unk_2412bd8::vf_type() {
    return Unk_GetType();
}

// 0x71010be390
const Unk_239a418_Type* Unk_2412e60::vf_type() {
    return Unk_GetType();
}

// 0x71010bfb90
const Unk_239a418_Type* Unk_24130e8::vf_type() {
    return Unk_GetType();
}

// 0x71010c0e50
const Unk_239a418_Type* Unk_24132c0::vf_type() {
    return Unk_GetType();
}
