// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x7102416398: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x71010e6b30
// 0x71010e6c70
// 0x71010e6cc0
// 0x71010e6d30
// 0x71010e6d80
class Unk_2416388 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102416620: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x71010e8290
// 0x71010e83d0
// 0x71010e8420
// 0x71010e8490
// 0x71010e84e0
class Unk_2416610 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x71010e6b80
// 0x71010e6d10
// 0x71010e6d20
const Unk_239a418_Type* Unk_2416388::vf_type() {
    return Unk_GetType();
}

// 0x71010e82e0
// 0x71010e8470
// 0x71010e8480
const Unk_239a418_Type* Unk_2416610::vf_type() {
    return Unk_GetType();
}
