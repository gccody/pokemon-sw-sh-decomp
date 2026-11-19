// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ee828: its getter is out of line.
struct Unk_242be70 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710242bf98: vf_type and its thunks 0x71012aeb10 (+0x48), 0x71012aeb80 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242bf88 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242be70::Unk_GetType());
        return &type;
    }

    ~Unk_242bf88() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710242c0b0: vf_type and its thunks 0x71012b2840 (+0x48), 0x71012b28b0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242c0a0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242be70::Unk_GetType());
        return &type;
    }

    ~Unk_242c0a0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71012ae9a0
// 0x71012aeb10
// 0x71012aeb80
const Unk_239a418_Type* Unk_242bf88::vf_type() {
    return Unk_GetType();
}

// 0x71012b2610
// 0x71012b2840
// 0x71012b28b0
const Unk_239a418_Type* Unk_242c0a0::vf_type() {
    return Unk_GetType();
}
