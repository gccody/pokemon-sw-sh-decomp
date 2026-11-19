// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8f98: its getter is out of line.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102777228.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x71027ec1c0.
struct Unk_2421620 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102421910: vf_type and its thunks 0x71011e4140 (+0x48), 0x71011e41b0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2421900 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2421900() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102421a50: vf_type and its thunks 0x71011e5080 (+0x48), 0x71011e50f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2421a40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2421a40() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102421ba0: vf_type and its thunks 0x71011e5f30 (+0x48), 0x71011e5f40 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71011e6110).
// Its base and its other functions aren't written here.
class Unk_2421b90 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_2421b90() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102421cb8: vf_type and its thunks 0x71011e77c0 (+0x48), 0x71011e7830 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2421ca8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2421ca8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102422438: vf_type and its thunks 0x71011f4910 (+0x48), 0x71011f49c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2422428 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2421620::Unk_GetType());
        return &type;
    }

    ~Unk_2422428() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71011e3f10
// 0x71011e4140
// 0x71011e41b0
const Unk_239a418_Type* Unk_2421900::vf_type() {
    return Unk_GetType();
}

// 0x71011e4e30
// 0x71011e5080
// 0x71011e50f0
const Unk_239a418_Type* Unk_2421a40::vf_type() {
    return Unk_GetType();
}

// 0x71011e5d60
// 0x71011e5f30
// 0x71011e5f40
const Unk_239a418_Type* Unk_2421b90::vf_type() {
    return Unk_GetType();
}

// 0x71011e7750
// 0x71011e77c0
// 0x71011e7830
const Unk_239a418_Type* Unk_2421ca8::vf_type() {
    return Unk_GetType();
}

// 0x71011f4850
// 0x71011f4910
// 0x71011f49c0
const Unk_239a418_Type* Unk_2422428::vf_type() {
    return Unk_GetType();
}
