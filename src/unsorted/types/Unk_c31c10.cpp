// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e05b0: its getter is out of line.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027ce9f8: its getter is out of line.
struct Unk_27ce9f8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023da648: vf_type and its thunks 0x7100c31d40 (+0x48), 0x7100c31db0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23da638 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23da638() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023da778: vf_type and its thunks 0x7100c32830 (+0x48), 0x7100c328a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23da768 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_23da768() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9318.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023dab38: vf_type and its thunks 0x7100c38080 (+0x48), 0x7100c38090 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100c38220).
// Its base and its other functions aren't written here.
class Unk_23dab28 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23dab28() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100c31c10
// 0x7100c31d40
// 0x7100c31db0
const Unk_239a418_Type* Unk_23da638::vf_type() {
    return Unk_GetType();
}

// 0x7100c32460
// 0x7100c32830
// 0x7100c328a0
const Unk_239a418_Type* Unk_23da768::vf_type() {
    return Unk_GetType();
}

// 0x7100c38040
// 0x7100c38080
// 0x7100c38090
const Unk_239a418_Type* Unk_23dab28::vf_type() {
    return Unk_GetType();
}
