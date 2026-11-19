// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102774028: its getter is out of line.
struct Unk_2399708 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102399658: vf_type and its thunks 0x71005d52d0 (+0x48), 0x71005d5340 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2399648 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399708::Unk_GetType());
        return &type;
    }

    ~Unk_2399648() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102399938: vf_type and its thunks 0x71005d7a20 (+0x48), 0x71005d7a90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2399928 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399708::Unk_GetType());
        return &type;
    }

    ~Unk_2399928() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x7102777228.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102399d18: vf_type and its thunks 0x71005dbb80 (+0x48), 0x71005dbb90 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100619640).
// Its base and its other functions aren't written here.
class Unk_2399d08 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_2399d08() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71005d51a0
// 0x71005d52d0
// 0x71005d5340
const Unk_239a418_Type* Unk_2399648::vf_type() {
    return Unk_GetType();
}

// 0x71005d7870
// 0x71005d7a20
// 0x71005d7a90
const Unk_239a418_Type* Unk_2399928::vf_type() {
    return Unk_GetType();
}

// 0x71005db9e0
// 0x71005dbb80
// 0x71005dbb90
const Unk_239a418_Type* Unk_2399d08::vf_type() {
    return Unk_GetType();
}
