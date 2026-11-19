// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x71023ff1d0: vf_type (its thunks 0x7100f66800 (+0x48), 0x7100f66810 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23ff1c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71023ff540: vf_type (its thunks 0x7100f68120 (+0x48), 0x7100f68130 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23ff530 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71023ff5f0: vf_type (its thunks 0x7100f6a920 (+0x48), 0x7100f6a930 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23ff5e0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71023ff6a0: vf_type (its thunks 0x7100f6adc0 (+0x48), 0x7100f6add0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23ff690 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x7100f66670
const Unk_239a418_Type* Unk_23ff1c0::vf_type() {
    return Unk_GetType();
}

// 0x7100f67f10
const Unk_239a418_Type* Unk_23ff530::vf_type() {
    return Unk_GetType();
}

// 0x7100f6a730
const Unk_239a418_Type* Unk_23ff5e0::vf_type() {
    return Unk_GetType();
}

// 0x7100f6acb0
const Unk_239a418_Type* Unk_23ff690::vf_type() {
    return Unk_GetType();
}
