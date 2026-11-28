// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x71023cde08: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x7100b13cc0
// 0x7100b13e00
// 0x7100b13e50
// 0x7100b13ec0
// 0x7100b13f10
class Unk_23cddf8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023cdeb8: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x7100b142b0
// 0x7100b143f0
// 0x7100b14440
// 0x7100b144b0
// 0x7100b14500
class Unk_23cdea8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x7100b13d10
// 0x7100b13ea0
// 0x7100b13eb0
const Unk_239a418_Type* Unk_23cddf8::vf_type() {
    return Unk_GetType();
}

// 0x7100b14300
// 0x7100b14490
// 0x7100b144a0
const Unk_239a418_Type* Unk_23cdea8::vf_type() {
    return Unk_GetType();
}
