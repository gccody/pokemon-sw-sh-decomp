// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x7102418400: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x7101102430
// 0x7101102570
// 0x71011025c0
// 0x7101102630
// 0x7101102680
class Unk_24183f0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x7101102480
// 0x7101102610
// 0x7101102620
const Unk_239a418_Type* Unk_24183f0::vf_type() {
    return Unk_GetType();
}
