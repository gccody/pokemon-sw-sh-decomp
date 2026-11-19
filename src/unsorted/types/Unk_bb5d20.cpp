// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x71023d3760: vf_type (its thunks 0x7100bb5e30 (+0x48), 0x7100bb5e40 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23d3750 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71023d3870: vf_type (its thunks 0x7100bb6a00 (+0x48), 0x7100bb6a10 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23d3860 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x7100bb5d20
const Unk_239a418_Type* Unk_23d3750::vf_type() {
    return Unk_GetType();
}

// 0x7100bb6270
const Unk_239a418_Type* Unk_23d3860::vf_type() {
    return Unk_GetType();
}
