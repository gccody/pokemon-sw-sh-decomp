// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ce9f8: its getter is out of line.
struct Unk_27ce9f8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023a8be8: vf_type and its thunks 0x71007a39d0 (+0x48), 0x71007a39e0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71007a3af0).
// Its base and its other functions aren't written here.
class Unk_23a8bd8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23a8bd8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023a8d58: vf_type and its thunks 0x71007a47f0 (+0x48), 0x71007a4860 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a8d48 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_23a8d48() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71007a39a0
// 0x71007a39d0
// 0x71007a39e0
const Unk_239a418_Type* Unk_23a8bd8::vf_type() {
    return Unk_GetType();
}

// 0x71007a4560
// 0x71007a47f0
// 0x71007a4860
const Unk_239a418_Type* Unk_23a8d48::vf_type() {
    return Unk_GetType();
}
