// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9318: its getter is out of line.
// Unk_23f4e40 (unsorted/Unk_23f4e40.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23f4e40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    ~Unk_23f4e40() override;
    const Unk_239a418_Type* vf_type() override;
    virtual u32 vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
};

// vtable 0x71023eebd0: vf_type and its thunks 0x7100da3550 (+0x48), 0x7100da35c0 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100da34b0
// 0x7100da3530
// 0x7100da3540
// 0x7100da3630
// 0x7100da3640
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_23eebc0 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
};

// 0x7100da34c0
// 0x7100da3550
// 0x7100da35c0
const Unk_239a418_Type* Unk_23eebc0::vf_type() {
    return Unk_GetType();
}
