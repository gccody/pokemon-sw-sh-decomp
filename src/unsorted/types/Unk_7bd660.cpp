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

// vtable 0x71023aa0f8: vf_type and its thunks 0x71007bd850 (+0x48), 0x71007bd8c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23aa0e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23aa0e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023aa1c8: vf_type and its thunks 0x71007be270 (+0x48), 0x71007be2e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23aa1b8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }

    ~Unk_23aa1b8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71007bd660
// 0x71007bd850
// 0x71007bd8c0
const Unk_239a418_Type* Unk_23aa0e8::vf_type() {
    return Unk_GetType();
}

// 0x71007bdf90
// 0x71007be270
// 0x71007be2e0
const Unk_239a418_Type* Unk_23aa1b8::vf_type() {
    return Unk_GetType();
}
