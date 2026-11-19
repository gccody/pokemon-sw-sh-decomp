// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023cea58: vf_type and its thunks 0x7100b2d7c0 (+0x48), 0x7100b2d7d0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100b2cc40).
// Its base and its other functions aren't written here.
class Unk_23cea48 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_23cea48() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9318.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023cebb0: vf_type and its thunks 0x7100b2e460 (+0x48), 0x7100b2e470 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100b2e480).
// Its base and its other functions aren't written here.
class Unk_23ceba0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23ceba0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100b2d790
// 0x7100b2d7c0
// 0x7100b2d7d0
const Unk_239a418_Type* Unk_23cea48::vf_type() {
    return Unk_GetType();
}

// 0x7100b2e450
// 0x7100b2e460
// 0x7100b2e470
const Unk_239a418_Type* Unk_23ceba0::vf_type() {
    return Unk_GetType();
}
