// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x710240b4f0: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x71010539d0
// 0x7101053b10
// 0x7101053b60
// 0x7101053bd0
// 0x7101053c20
class Unk_240b4e0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x7101053a20
// 0x7101053bb0
// 0x7101053bc0
const Unk_239a418_Type* Unk_240b4e0::vf_type() {
    return Unk_GetType();
}
