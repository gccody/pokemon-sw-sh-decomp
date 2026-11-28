// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71024ba7e8: its getter is out of line.
struct Unk_239a360 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e05b0: its getter is out of line.
// Unk_23f4660 (unsorted/Unk_23f4660.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23f4660 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    ~Unk_23f4660() override;
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
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027736b8.
struct Unk_2399fa8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a360::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f41e0: vf_type and its thunks 0x7100e7ccb0 (+0x48), 0x7100e7cd20 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f41d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }

    ~Unk_23f41d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f4570: vf_type and its thunks 0x7100e7f5c0 (+0x48), 0x7100e7f630 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100e7f490
// 0x7100e7f5a0
// 0x7100e7f5b0
// 0x7100e7f6a0
// 0x7100e7f6b0
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_23f4560 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf14() override;
};

// vtable 0x71023f4820: vf_type and its thunks 0x7100e85450 (+0x48), 0x7100e85500 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f4810 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_23f4810() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100e7cb50
// 0x7100e7ccb0
// 0x7100e7cd20
const Unk_239a418_Type* Unk_23f41d0::vf_type() {
    return Unk_GetType();
}

// 0x7100e7f4a0
// 0x7100e7f5c0
// 0x7100e7f630
const Unk_239a418_Type* Unk_23f4560::vf_type() {
    return Unk_GetType();
}

// 0x7100e852a0
// 0x7100e85450
// 0x7100e85500
const Unk_239a418_Type* Unk_23f4810::vf_type() {
    return Unk_GetType();
}
