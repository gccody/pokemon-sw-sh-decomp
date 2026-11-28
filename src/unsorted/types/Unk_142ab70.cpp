// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x710243a1b0: vf_type (its thunks 0x710142ac60 (+0x48), 0x710142ac70 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_243a1a0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x710243a4b8: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x710142d180
// 0x710142d2c0
// 0x710142d310
// 0x710142d380
// 0x710142d3d0
class Unk_243a4a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x710142ab70
const Unk_239a418_Type* Unk_243a1a0::vf_type() {
    return Unk_GetType();
}

// 0x710142d1d0
// 0x710142d360
// 0x710142d370
const Unk_239a418_Type* Unk_243a4a8::vf_type() {
    return Unk_GetType();
}
