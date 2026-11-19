// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x71024066d8: vf_type (its thunks 0x7100ffaf20 (+0x48), 0x7100ffaf30 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_24066c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x7102406808: vf_type (its thunks 0x7101004760 (+0x48), 0x7101004770 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_24067f8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x7102406a70: vf_type (its thunks 0x71010054b0 (+0x48), 0x71010054c0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_2406a60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x7100ffae30
const Unk_239a418_Type* Unk_24066c8::vf_type() {
    return Unk_GetType();
}

// 0x7101004670
const Unk_239a418_Type* Unk_24067f8::vf_type() {
    return Unk_GetType();
}

// 0x7101004d20
const Unk_239a418_Type* Unk_2406a60::vf_type() {
    return Unk_GetType();
}
