// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e1730: its getter is out of line.
struct Unk_24006c0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e15e0: its getter is out of line.
struct Unk_27e15e0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102400910: vf_type and its thunks 0x7100f81210 (+0x48), 0x7100f81280 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2400900 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }

    ~Unk_2400900() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102400a70: vf_type and its thunks 0x7100f825d0 (+0x48), 0x7100f825e0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100f82850).
// Its base and its other functions aren't written here.
class Unk_2400a60 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_2400a60() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102400be8: vf_type and its thunks 0x7100f83830 (+0x48), 0x7100f838a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2400bd8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }

    ~Unk_2400bd8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102400d60: vf_type and its thunks 0x7100f856b0 (+0x48), 0x7100f85720 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2400d50 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24006c0::Unk_GetType());
        return &type;
    }

    ~Unk_2400d50() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100f81180
// 0x7100f81210
// 0x7100f81280
const Unk_239a418_Type* Unk_2400900::vf_type() {
    return Unk_GetType();
}

// 0x7100f824a0
// 0x7100f825d0
// 0x7100f825e0
const Unk_239a418_Type* Unk_2400a60::vf_type() {
    return Unk_GetType();
}

// 0x7100f83640
// 0x7100f83830
// 0x7100f838a0
const Unk_239a418_Type* Unk_2400bd8::vf_type() {
    return Unk_GetType();
}

// 0x7100f85530
// 0x7100f856b0
// 0x7100f85720
const Unk_239a418_Type* Unk_2400d50::vf_type() {
    return Unk_GetType();
}
