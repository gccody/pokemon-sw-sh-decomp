// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023d1c28: vf_type and its thunks 0x7100b85fd0 (+0x48), 0x7100b86040 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d1c18 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23d1c18() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d19e8: vf_type and its thunks 0x7100b859d0 (+0x48), 0x7100b85a80 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d19d8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d1c18::Unk_GetType());
        return &type;
    }

    ~Unk_23d19d8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d1b08: vf_type and its thunks 0x7100b85be0 (+0x48), 0x7100b85c90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d1af8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d1c18::Unk_GetType());
        return &type;
    }

    ~Unk_23d1af8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100b85920
// 0x7100b859d0
// 0x7100b85a80
const Unk_239a418_Type* Unk_23d19d8::vf_type() {
    return Unk_GetType();
}

// 0x7100b85b30
// 0x7100b85be0
// 0x7100b85c90
const Unk_239a418_Type* Unk_23d1af8::vf_type() {
    return Unk_GetType();
}

// 0x7100b85e50
// 0x7100b85fd0
// 0x7100b86040
const Unk_239a418_Type* Unk_23d1c18::vf_type() {
    return Unk_GetType();
}
