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

// vtable 0x71023c9ed8: vf_type and its thunks 0x7100adace0 (+0x48), 0x7100adad50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c9ec8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }

    ~Unk_23c9ec8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023c9db0: vf_type and its thunks 0x7100ada8f0 (+0x48), 0x7100ada9a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c9da0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9ec8::Unk_GetType());
        return &type;
    }

    ~Unk_23c9da0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023ca2f0: vf_type and its thunks 0x7100ae0930 (+0x48), 0x7100ae09e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ca2e0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9ec8::Unk_GetType());
        return &type;
    }

    ~Unk_23ca2e0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023cc5b0: vf_type and its thunks 0x7100aefbe0 (+0x48), 0x7100aefc90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23cc5a0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9ec8::Unk_GetType());
        return &type;
    }

    ~Unk_23cc5a0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023ccd70: vf_type and its thunks 0x7100af5780 (+0x48), 0x7100af57f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ccd60 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }

    ~Unk_23ccd60() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100ada760
// 0x7100ada8f0
// 0x7100ada9a0
const Unk_239a418_Type* Unk_23c9da0::vf_type() {
    return Unk_GetType();
}

// 0x7100adab90
// 0x7100adace0
// 0x7100adad50
const Unk_239a418_Type* Unk_23c9ec8::vf_type() {
    return Unk_GetType();
}

// 0x7100ae0740
// 0x7100ae0930
// 0x7100ae09e0
const Unk_239a418_Type* Unk_23ca2e0::vf_type() {
    return Unk_GetType();
}

// 0x7100aefa50
// 0x7100aefbe0
// 0x7100aefc90
const Unk_239a418_Type* Unk_23cc5a0::vf_type() {
    return Unk_GetType();
}

// 0x7100af5630
// 0x7100af5780
// 0x7100af57f0
const Unk_239a418_Type* Unk_23ccd60::vf_type() {
    return Unk_GetType();
}
