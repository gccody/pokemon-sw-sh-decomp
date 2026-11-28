// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x7102413ca8: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x71010c75c0
// 0x71010c7700
// 0x71010c7750
// 0x71010c77c0
// 0x71010c7810
class Unk_2413c98 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102413f30: vf_type (its thunks 0x71010c90f0 (+0x48), 0x71010c9100 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_2413f20 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x71010c7610
// 0x71010c77a0
// 0x71010c77b0
const Unk_239a418_Type* Unk_2413c98::vf_type() {
    return Unk_GetType();
}

// 0x71010c8f20
const Unk_239a418_Type* Unk_2413f20::vf_type() {
    return Unk_GetType();
}
