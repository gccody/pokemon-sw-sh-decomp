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

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// Unk_23f6328 (unsorted/Unk_23f6328.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23f6328 : public Unk_239a418 {
public:
    ~Unk_23f6328() override;
    const Unk_239a418_Type* vf_type() override;
    virtual u32 vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
    virtual void vf17();
    virtual u32 vf18();
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023bc870: vf_type and its thunks 0x71008e5110 (+0x48), 0x71008e51c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23bc860 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23bc860() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023bca28: vf_type and its thunks 0x71008e6210 (+0x48), 0x71008e6280 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x71008e6170
// 0x71008e61f0
// 0x71008e6200
// 0x71008e62f0
// 0x71008e6300
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_23bca18 : public Unk_23f6328 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf14() override;
    void vf17() override;
    u32 vf18() override;
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

// vtable 0x71023bcb50: vf_type and its thunks 0x71008e6fd0 (+0x48), 0x71008e6fe0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71008e5870).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x71008e6f90
// 0x71008e6fb0
// 0x71008e6fc0
// 0x71008e6ff0
// 0x71008e7000
class Unk_23bcb40 : public Unk_23f4318 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x71008e5040
// 0x71008e5110
// 0x71008e51c0
const Unk_239a418_Type* Unk_23bc860::vf_type() {
    return Unk_GetType();
}

// 0x71008e6180
// 0x71008e6210
// 0x71008e6280
const Unk_239a418_Type* Unk_23bca18::vf_type() {
    return Unk_GetType();
}

// 0x71008e6fa0
// 0x71008e6fd0
// 0x71008e6fe0
const Unk_239a418_Type* Unk_23bcb40::vf_type() {
    return Unk_GetType();
}
