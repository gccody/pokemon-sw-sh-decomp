// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d7860: its getter is out of line.
struct Unk_23c9470 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023c8ef0: vf_type and its thunks 0x7100ac59d0 (+0x48), 0x7100ac5a80 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c8ee0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23c8ee0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d7850.
struct Unk_27d7850 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023c9038: vf_type and its thunks 0x7100ac74b0 (+0x48), 0x7100ac7560 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c9028 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d7850::Unk_GetType());
        return &type;
    }

    ~Unk_23c9028() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023c9160: vf_type and its thunks 0x7100ac8070 (+0x48), 0x7100ac8120 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c9150 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d7850::Unk_GetType());
        return &type;
    }

    ~Unk_23c9150() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023c9288: vf_type and its thunks 0x7100ac8af0 (+0x48), 0x7100ac8ba0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c9278 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d7850::Unk_GetType());
        return &type;
    }

    ~Unk_23c9278() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100ac5900
// 0x7100ac59d0
// 0x7100ac5a80
const Unk_239a418_Type* Unk_23c8ee0::vf_type() {
    return Unk_GetType();
}

// 0x7100ac73c0
// 0x7100ac74b0
// 0x7100ac7560
const Unk_239a418_Type* Unk_23c9028::vf_type() {
    return Unk_GetType();
}

// 0x7100ac7fa0
// 0x7100ac8070
// 0x7100ac8120
const Unk_239a418_Type* Unk_23c9150::vf_type() {
    return Unk_GetType();
}

// 0x7100ac8a20
// 0x7100ac8af0
// 0x7100ac8ba0
const Unk_239a418_Type* Unk_23c9278::vf_type() {
    return Unk_GetType();
}
