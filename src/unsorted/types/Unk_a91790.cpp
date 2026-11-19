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

// vtable 0x71023c8010: vf_type and its thunks 0x7100a91b60 (+0x48), 0x7100a91bd0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c8000 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_23c8000() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023c80e0: vf_type and its thunks 0x7100a92770 (+0x48), 0x7100a927e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c80d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_23c80d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100a91790
// 0x7100a91b60
// 0x7100a91bd0
const Unk_239a418_Type* Unk_23c8000::vf_type() {
    return Unk_GetType();
}

// 0x7100a923d0
// 0x7100a92770
// 0x7100a927e0
const Unk_239a418_Type* Unk_23c80d0::vf_type() {
    return Unk_GetType();
}
