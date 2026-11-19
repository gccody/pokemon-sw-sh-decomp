// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9318: its getter is out of line.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023fea78: vf_type and its thunks 0x7100f59730 (+0x48), 0x7100f597a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23fea68 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }

    ~Unk_23fea68() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023febb8: vf_type and its thunks 0x7100f5c490 (+0x48), 0x7100f5c500 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23feba8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23feba8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100f595e0
// 0x7100f59730
// 0x7100f597a0
const Unk_239a418_Type* Unk_23fea68::vf_type() {
    return Unk_GetType();
}

// 0x7100f5c400
// 0x7100f5c490
// 0x7100f5c500
const Unk_239a418_Type* Unk_23feba8::vf_type() {
    return Unk_GetType();
}
