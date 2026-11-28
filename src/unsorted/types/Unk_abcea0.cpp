// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100ab8fb0: the copy of its getter that the getters below call (too big
// to be inlined into them: clang emits it here).
// The type 0x71027d7680.
struct Unk_23c8808 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023c8938: vf_type and its thunks 0x7100abcfe0 (+0x48), 0x7100abd050 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c8928 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c8808::Unk_GetType());
        return &type;
    }

    ~Unk_23c8928() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023c8a58: vf_type and its thunks 0x7100abd440 (+0x48), 0x7100abd4b0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c8a48 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c8808::Unk_GetType());
        return &type;
    }

    ~Unk_23c8a48() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023c8b78: vf_type and its thunks 0x7100abd820 (+0x48), 0x7100abd890 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c8b68 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c8808::Unk_GetType());
        return &type;
    }

    ~Unk_23c8b68() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100abcea0
// 0x7100abcfe0
// 0x7100abd050
const Unk_239a418_Type* Unk_23c8928::vf_type() {
    return Unk_GetType();
}

// 0x7100abd2a0
// 0x7100abd440
// 0x7100abd4b0
const Unk_239a418_Type* Unk_23c8a48::vf_type() {
    return Unk_GetType();
}

// 0x7100abd780
// 0x7100abd820
// 0x7100abd890
const Unk_239a418_Type* Unk_23c8b68::vf_type() {
    return Unk_GetType();
}
