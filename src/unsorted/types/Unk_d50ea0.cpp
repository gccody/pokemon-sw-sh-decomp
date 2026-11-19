// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6220: its getter is out of line.
struct Unk_23ddd68 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027dcc30: its getter is out of line.
struct Unk_23dffd8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027dcbe0: its getter is out of line.
struct Unk_23eaf68 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efd50.
struct Unk_23e3950 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23ddd68::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023ead88: vf_type and its thunks 0x7100d50ff0 (+0x48), 0x7100d51060 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ead78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23eaf68::Unk_GetType());
        return &type;
    }

    ~Unk_23ead78() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023eb360: vf_type and its thunks 0x7100d51ce0 (+0x48), 0x7100d51d50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23eb350 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dffd8::Unk_GetType());
        return &type;
    }

    ~Unk_23eb350() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023eb600: vf_type and its thunks 0x7100d52160 (+0x48), 0x7100d52210 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23eb5f0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e3950::Unk_GetType());
        return &type;
    }

    ~Unk_23eb5f0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d50ea0
// 0x7100d50ff0
// 0x7100d51060
const Unk_239a418_Type* Unk_23ead78::vf_type() {
    return Unk_GetType();
}

// 0x7100d51c50
// 0x7100d51ce0
// 0x7100d51d50
const Unk_239a418_Type* Unk_23eb350::vf_type() {
    return Unk_GetType();
}

// 0x7100d52010
// 0x7100d52160
// 0x7100d52210
const Unk_239a418_Type* Unk_23eb5f0::vf_type() {
    return Unk_GetType();
}
