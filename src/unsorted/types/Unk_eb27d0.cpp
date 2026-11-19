// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x71023f5e20: vf_type (its thunks 0x7100eb28c0 (+0x48), 0x7100eb28d0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23f5e10 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71023f70c8: vf_type (its thunks 0x7100ec9550 (+0x48), 0x7100ec9560 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_23f70b8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x7100eb27d0
const Unk_239a418_Type* Unk_23f5e10::vf_type() {
    return Unk_GetType();
}

// 0x7100ec9460
const Unk_239a418_Type* Unk_23f70b8::vf_type() {
    return Unk_GetType();
}
