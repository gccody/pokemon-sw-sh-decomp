// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027f0020: its getter is out of line.
struct Unk_27f0020 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efe80.
struct Unk_2434918 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71024356e0: vf_type and its thunks 0x71013cdfc0 (+0x48), 0x71013ce030 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24356d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0020::Unk_GetType());
        return &type;
    }

    ~Unk_24356d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024357b8: vf_type and its thunks 0x71013ceb00 (+0x48), 0x71013ceb10 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71013ceb20).
// Its base and its other functions aren't written here.
class Unk_24357a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2434918::Unk_GetType());
        return &type;
    }

    ~Unk_24357a8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71013cdd50
// 0x71013cdfc0
// 0x71013ce030
const Unk_239a418_Type* Unk_24356d0::vf_type() {
    return Unk_GetType();
}

// 0x71013ceaf0
// 0x71013ceb00
// 0x71013ceb10
const Unk_239a418_Type* Unk_24357a8::vf_type() {
    return Unk_GetType();
}
