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

// vtable 0x71024293f8: vf_type and its thunks 0x71012792d0 (+0x48), 0x71012792e0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101278230).
// Its base and its other functions aren't written here.
class Unk_24293e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_24293e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102429538: vf_type and its thunks 0x7101279de0 (+0x48), 0x7101279e50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2429528 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_2429528() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71012791c0
// 0x71012792d0
// 0x71012792e0
const Unk_239a418_Type* Unk_24293e8::vf_type() {
    return Unk_GetType();
}

// 0x7101279a10
// 0x7101279de0
// 0x7101279e50
const Unk_239a418_Type* Unk_2429528::vf_type() {
    return Unk_GetType();
}
