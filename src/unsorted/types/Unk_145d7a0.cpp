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

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x710243ce20: vf_type and its thunks 0x710145da60 (+0x48), 0x710145dad0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243ce10 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_243ce10() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243d2d8: vf_type and its thunks 0x7101460640 (+0x48), 0x7101460650 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101457c40).
// Its base and its other functions aren't written here.
class Unk_243d2c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_243d2c8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710145d7a0
// 0x710145da60
// 0x710145dad0
const Unk_239a418_Type* Unk_243ce10::vf_type() {
    return Unk_GetType();
}

// 0x7101460610
// 0x7101460640
// 0x7101460650
const Unk_239a418_Type* Unk_243d2c8::vf_type() {
    return Unk_GetType();
}
