// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ee808: its getter is out of line.
// Unk_23f2df0 (unsorted/Unk_23f2df0.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23f2df0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    ~Unk_23f2df0() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023f3850: vf_type and its thunks 0x7100e73040 (+0x48), 0x7100e730b0 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100e72f90
// 0x7100e73020
// 0x7100e73030
// 0x7100e73120
// 0x7100e73130
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_23f3840 : public Unk_23f2df0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f2df0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf13() override;
    void vf14() override;
    void vf15() override;
    void vf16() override;
};

// vtable 0x71023f3950: vf_type and its thunks 0x7100e731f0 (+0x48), 0x7100e73260 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100e73140
// 0x7100e731d0
// 0x7100e731e0
// 0x7100e732d0
// 0x7100e732e0
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_23f3940 : public Unk_23f2df0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f2df0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf13() override;
    void vf16() override;
};

// vtable 0x71023f3a50: vf_type and its thunks 0x7100e733a0 (+0x48), 0x7100e73410 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100e732f0
// 0x7100e73380
// 0x7100e73390
// 0x7100e73480
// 0x7100e73490
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_23f3a40 : public Unk_23f2df0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f2df0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf13() override;
    void vf16() override;
};

// The type 0x71027e0580.
// Unk_23f4318 (unsorted/Unk_23f43c8.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23f4318 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23f4318() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f3c20: vf_type and its thunks 0x7100e74d10 (+0x48), 0x7100e74d20 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100e75330).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100e74cd0
// 0x7100e74cf0
// 0x7100e74d00
// 0x7100e74d30
// 0x7100e74d40
class Unk_23f3c10 : public Unk_23f4318 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

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
