// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x71024157c8: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x71010dea20
// 0x71010deb60
// 0x71010debb0
// 0x71010dec20
// 0x71010dec70
class Unk_24157b8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024159a0: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x71010dfc40
// 0x71010dfd80
// 0x71010dfdd0
// 0x71010dfe40
// 0x71010dfe90
class Unk_2415990 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102415d50: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x71010e2010
// 0x71010e2150
// 0x71010e21a0
// 0x71010e2210
// 0x71010e2260
class Unk_2415d40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x71010dea70
// 0x71010dec00
// 0x71010dec10
const Unk_239a418_Type* Unk_24157b8::vf_type() {
    return Unk_GetType();
}

// 0x71010dfc90
// 0x71010dfe20
// 0x71010dfe30
const Unk_239a418_Type* Unk_2415990::vf_type() {
    return Unk_GetType();
}

// 0x71010e2060
// 0x71010e21f0
// 0x71010e2200
const Unk_239a418_Type* Unk_2415d40::vf_type() {
    return Unk_GetType();
}
