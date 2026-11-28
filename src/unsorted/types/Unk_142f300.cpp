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

// The type 0x71027f0968: its getter is out of line.
struct Unk_27f0968 {
    static const Unk_239a418_Type* Unk_GetType();
};

// Unk_23f43c8 (unsorted/Unk_23f43c8.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23f43c8 : public Unk_239a418 {
public:
    ~Unk_23f43c8() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual u32 vf10();
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e0580.
struct Unk_23f4318 {
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

// vtable 0x710243a568: vf_type and its thunks 0x710142f3d0 (+0x48), 0x710142f480 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243a558 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_243a558() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243a9e0: vf_type and its thunks 0x71014336c0 (+0x48), 0x71014336d0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71014314e0).
// Its base and its other functions aren't written here.
class Unk_243a9d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_243a9d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243ab28: vf_type and its thunks 0x7101434ce0 (+0x48), 0x7101434cf0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71014302c0).
// Its base and its other functions aren't written here.
class Unk_243ab18 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_243ab18() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243abd8: vf_type and its thunks 0x71014358d0 (+0x48), 0x7101435940 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7101435830
// 0x71014358b0
// 0x71014358c0
// 0x71014359b0
// 0x71014359c0
// Its other virtual functions are declared only (written elsewhere, or not yet).
class Unk_243abc8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// vtable 0x710243b0e8: vf_type and its thunks 0x71014384f0 (+0x48), 0x7101438560 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243b0d8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0968::Unk_GetType());
        return &type;
    }

    ~Unk_243b0d8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243b358: vf_type and its thunks 0x7101439c00 (+0x48), 0x7101439cb0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243b348 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_243b348() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710142f300
// 0x710142f3d0
// 0x710142f480
const Unk_239a418_Type* Unk_243a558::vf_type() {
    return Unk_GetType();
}

// 0x7101433690
// 0x71014336c0
// 0x71014336d0
const Unk_239a418_Type* Unk_243a9d0::vf_type() {
    return Unk_GetType();
}

// 0x7101434b30
// 0x7101434ce0
// 0x7101434cf0
const Unk_239a418_Type* Unk_243ab18::vf_type() {
    return Unk_GetType();
}

// 0x7101435840
// 0x71014358d0
// 0x7101435940
const Unk_239a418_Type* Unk_243abc8::vf_type() {
    return Unk_GetType();
}

// 0x71014383c0
// 0x71014384f0
// 0x7101438560
const Unk_239a418_Type* Unk_243b0d8::vf_type() {
    return Unk_GetType();
}

// 0x7101439b30
// 0x7101439c00
// 0x7101439cb0
const Unk_239a418_Type* Unk_243b348::vf_type() {
    return Unk_GetType();
}
