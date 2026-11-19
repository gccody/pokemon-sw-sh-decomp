// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71024ba7e8: its getter is out of line.
struct Unk_239a360 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027740b8: its getter is out of line.
struct Unk_239bd80 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102399fb8: vf_type and its thunks 0x71005de3a0 (+0x48), 0x71005de410 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2399fa8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a360::Unk_GetType());
        return &type;
    }

    ~Unk_2399fa8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239a208: vf_type and its thunks 0x71005e19c0 (+0x48), 0x71005e1a30 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239a1f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bd80::Unk_GetType());
        return &type;
    }

    ~Unk_239a1f8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71005de190
// 0x71005de3a0
// 0x71005de410
const Unk_239a418_Type* Unk_2399fa8::vf_type() {
    return Unk_GetType();
}

// 0x71005e1830
// 0x71005e19c0
// 0x71005e1a30
const Unk_239a418_Type* Unk_239a1f8::vf_type() {
    return Unk_GetType();
}
