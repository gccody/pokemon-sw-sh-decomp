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
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType();
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
// Its base and its other functions aren't written here.
class Unk_23f4560 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23f4560() override;
    const Unk_239a418_Type* vf_type() override;
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
