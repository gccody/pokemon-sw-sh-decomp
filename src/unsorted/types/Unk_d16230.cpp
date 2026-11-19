// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027efd90: its getter is out of line.
struct Unk_23dd820 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d6220: its getter is out of line.
struct Unk_23ddd68 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efd50.
struct Unk_23e3950 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23ddd68::Unk_GetType());
        return &type;
    }
};

// The type 0x71027efd80.
struct Unk_23e4758 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dd820::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e86c0: vf_type and its thunks 0x7100d16380 (+0x48), 0x7100d16430 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e86b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e3950::Unk_GetType());
        return &type;
    }

    ~Unk_23e86b0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023e8968: vf_type and its thunks 0x7100d17fa0 (+0x48), 0x7100d18050 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e8958 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e4758::Unk_GetType());
        return &type;
    }

    ~Unk_23e8958() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d16230
// 0x7100d16380
// 0x7100d16430
const Unk_239a418_Type* Unk_23e86b0::vf_type() {
    return Unk_GetType();
}

// 0x7100d17dc0
// 0x7100d17fa0
// 0x7100d18050
const Unk_239a418_Type* Unk_23e8958::vf_type() {
    return Unk_GetType();
}
