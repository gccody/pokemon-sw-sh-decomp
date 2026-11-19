// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6250: its getter is out of line.
struct Unk_2399d08 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102774038.
struct Unk_2399590 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102399718: vf_type and its thunks 0x71005d58f0 (+0x48), 0x71005d5900 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71005eca40).
// Its base and its other functions aren't written here.
class Unk_2399708 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }

    ~Unk_2399708() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102399e48: vf_type and its thunks 0x71005dd350 (+0x48), 0x71005dd3c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2399e38 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
        return &type;
    }

    ~Unk_2399e38() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71005d5870
// 0x71005d58f0
// 0x71005d5900
const Unk_239a418_Type* Unk_2399708::vf_type() {
    return Unk_GetType();
}

// 0x71005dd2c0
// 0x71005dd350
// 0x71005dd3c0
const Unk_239a418_Type* Unk_2399e38::vf_type() {
    return Unk_GetType();
}
