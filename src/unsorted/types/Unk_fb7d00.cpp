// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e05b0.
// Unk_23f4660 (unsorted/Unk_23f4660.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23f4660 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23f4660() override;
    const Unk_239a418_Type* vf_type() override;
    virtual u32 vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
};

// vtable 0x7102402c28: vf_type and its thunks 0x7100fb7d30 (+0x48), 0x7100fb7d40 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100fa4960).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100fb7cf0
// 0x7100fb7d10
// 0x7100fb7d20
// 0x7100fb7d50
// 0x7100fb7d60
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_2402c18 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf14() override;
    u32 vf16() override;
};

// 0x7100fb7d00
// 0x7100fb7d30
// 0x7100fb7d40
const Unk_239a418_Type* Unk_2402c18::vf_type() {
    return Unk_GetType();
}
