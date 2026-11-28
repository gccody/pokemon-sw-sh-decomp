// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x7102400088: vf_type (its thunks 0x7100f76da0 (+0x48), 0x7100f76db0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_2400078 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x71024004c0: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x7100f7c880
// 0x7100f7c9c0
// 0x7100f7ca10
// 0x7100f7ca80
// 0x7100f7cad0
class Unk_24004b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x7100f76b50
const Unk_239a418_Type* Unk_2400078::vf_type() {
    return Unk_GetType();
}

// 0x7100f7c8d0
// 0x7100f7ca60
// 0x7100f7ca70
const Unk_239a418_Type* Unk_24004b0::vf_type() {
    return Unk_GetType();
}
