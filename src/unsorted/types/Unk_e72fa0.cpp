// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ee808: its getter is out of line.
struct Unk_23f2df0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023f3850: vf_type and its thunks 0x7100e73040 (+0x48), 0x7100e730b0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f3840 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f2df0::Unk_GetType());
        return &type;
    }

    ~Unk_23f3840() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f3950: vf_type and its thunks 0x7100e731f0 (+0x48), 0x7100e73260 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f3940 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f2df0::Unk_GetType());
        return &type;
    }

    ~Unk_23f3940() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f3a50: vf_type and its thunks 0x7100e733a0 (+0x48), 0x7100e73410 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f3a40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f2df0::Unk_GetType());
        return &type;
    }

    ~Unk_23f3a40() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023f3c20: vf_type and its thunks 0x7100e74d10 (+0x48), 0x7100e74d20 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100e75330).
// Its base and its other functions aren't written here.
class Unk_23f3c10 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23f3c10() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f3cd0: vf_type and its thunks 0x7100e74b50 (+0x48), 0x7100e74c00 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f3cc0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23f3cc0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100e72fa0
// 0x7100e73040
// 0x7100e730b0
const Unk_239a418_Type* Unk_23f3840::vf_type() {
    return Unk_GetType();
}

// 0x7100e73150
// 0x7100e731f0
// 0x7100e73260
const Unk_239a418_Type* Unk_23f3940::vf_type() {
    return Unk_GetType();
}

// 0x7100e73300
// 0x7100e733a0
// 0x7100e73410
const Unk_239a418_Type* Unk_23f3a40::vf_type() {
    return Unk_GetType();
}

// 0x7100e74a80
// 0x7100e74b50
// 0x7100e74c00
const Unk_239a418_Type* Unk_23f3cc0::vf_type() {
    return Unk_GetType();
}

// 0x7100e74ce0
// 0x7100e74d10
// 0x7100e74d20
const Unk_239a418_Type* Unk_23f3c10::vf_type() {
    return Unk_GetType();
}
