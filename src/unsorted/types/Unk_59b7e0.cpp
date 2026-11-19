// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027715d0: its getter is out of line.
struct Unk_2399080 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027736b8: its getter is out of line.
struct Unk_2399fa8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027715a0: its getter is out of line.
struct Unk_27715a0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023982b8: vf_type and its thunks 0x710059b870 (+0x48), 0x710059b8e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23982a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23982a8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102398858: vf_type and its thunks 0x71005b2b90 (+0x48), 0x71005b2dc0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2398848 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27715a0::Unk_GetType());
        return &type;
    }

    ~Unk_2398848() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102398f10: vf_type and its thunks 0x71005bf710 (+0x48), 0x71005bf780 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2398f00 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_2398f00() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102398fd0: vf_type and its thunks 0x71005c1740 (+0x48), 0x71005c17b0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2398fc0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399080::Unk_GetType());
        return &type;
    }

    ~Unk_2398fc0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102399358: vf_type and its thunks 0x71005ceef0 (+0x48), 0x71005cef60 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2399348 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_2399348() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710059b7e0
// 0x710059b870
// 0x710059b8e0
const Unk_239a418_Type* Unk_23982a8::vf_type() {
    return Unk_GetType();
}

// 0x71005b2890
// 0x71005b2b90
// 0x71005b2dc0
const Unk_239a418_Type* Unk_2398848::vf_type() {
    return Unk_GetType();
}

// 0x71005bf680
// 0x71005bf710
// 0x71005bf780
const Unk_239a418_Type* Unk_2398f00::vf_type() {
    return Unk_GetType();
}

// 0x71005c1530
// 0x71005c1740
// 0x71005c17b0
const Unk_239a418_Type* Unk_2398fc0::vf_type() {
    return Unk_GetType();
}

// 0x71005ced80
// 0x71005ceef0
// 0x71005cef60
const Unk_239a418_Type* Unk_2399348::vf_type() {
    return Unk_GetType();
}
