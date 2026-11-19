// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ee828: its getter is out of line.
struct Unk_242be70 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710242c1c8: vf_type and its thunks 0x71012b3910 (+0x48), 0x71012b3980 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242c1b8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242be70::Unk_GetType());
        return &type;
    }

    ~Unk_242c1b8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710242c2e0: vf_type and its thunks 0x71012b41f0 (+0x48), 0x71012b4260 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242c2d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242be70::Unk_GetType());
        return &type;
    }

    ~Unk_242c2d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710242c3f8: vf_type and its thunks 0x71012b46e0 (+0x48), 0x71012b4750 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242c3e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242be70::Unk_GetType());
        return &type;
    }

    ~Unk_242c3e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710242c510: vf_type and its thunks 0x71012b7760 (+0x48), 0x71012b77d0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242c500 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242be70::Unk_GetType());
        return &type;
    }

    ~Unk_242c500() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71012b3720
// 0x71012b3910
// 0x71012b3980
const Unk_239a418_Type* Unk_242c1b8::vf_type() {
    return Unk_GetType();
}

// 0x71012b4080
// 0x71012b41f0
// 0x71012b4260
const Unk_239a418_Type* Unk_242c2d0::vf_type() {
    return Unk_GetType();
}

// 0x71012b4570
// 0x71012b46e0
// 0x71012b4750
const Unk_239a418_Type* Unk_242c3e8::vf_type() {
    return Unk_GetType();
}

// 0x71012b76d0
// 0x71012b7760
// 0x71012b77d0
const Unk_239a418_Type* Unk_242c500::vf_type() {
    return Unk_GetType();
}
