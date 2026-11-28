// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x7102433630: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x710139ddb0
// 0x710139def0
// 0x710139df40
// 0x710139dfb0
// 0x710139e000
class Unk_2433620 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102433ad0: vf_type (its thunks 0x71013a2a80 (+0x48), 0x71013a2a90 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_2433ac0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// 0x710139de00
// 0x710139df90
// 0x710139dfa0
const Unk_239a418_Type* Unk_2433620::vf_type() {
    return Unk_GetType();
}

// 0x71013a2990
const Unk_239a418_Type* Unk_2433ac0::vf_type() {
    return Unk_GetType();
}
