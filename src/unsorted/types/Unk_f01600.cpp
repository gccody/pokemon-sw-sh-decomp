// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

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

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023f9c10: vf_type and its thunks 0x7100f016d0 (+0x48), 0x7100f01780 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f9c00 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23f9c00() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023fb0c8: vf_type and its thunks 0x7100f0cbe0 (+0x48), 0x7100f0cbf0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100f05610).
// Its base and its other functions aren't written here.
class Unk_23fb0b8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23fb0b8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023fb298: vf_type and its thunks 0x7100f0e150 (+0x48), 0x7100f0e200 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23fb288 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23fb288() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023fb730: vf_type and its thunks 0x7100f161e0 (+0x48), 0x7100f161f0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100f16300).
// Its base and its other functions aren't written here.
class Unk_23fb720 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_23fb720() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100f01600
// 0x7100f016d0
// 0x7100f01780
const Unk_239a418_Type* Unk_23f9c00::vf_type() {
    return Unk_GetType();
}

// 0x7100f0cbb0
// 0x7100f0cbe0
// 0x7100f0cbf0
const Unk_239a418_Type* Unk_23fb0b8::vf_type() {
    return Unk_GetType();
}

// 0x7100f0e080
// 0x7100f0e150
// 0x7100f0e200
const Unk_239a418_Type* Unk_23fb288::vf_type() {
    return Unk_GetType();
}

// 0x7100f160d0
// 0x7100f161e0
// 0x7100f161f0
const Unk_239a418_Type* Unk_23fb720::vf_type() {
    return Unk_GetType();
}
