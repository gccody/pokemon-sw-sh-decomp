// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7100f67690: the copy of its getter that the getters below call (too big
// to be inlined into them: clang emits it here).
// The type 0x71027e15e0.
struct Unk_27e15e0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023ff280: vf_type and its thunks 0x7100f674f0 (+0x48), 0x7100f67560 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ff270 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }

    ~Unk_23ff270() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023ff3e0: vf_type and its thunks 0x7100f67b40 (+0x48), 0x7100f67bb0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ff3d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }

    ~Unk_23ff3d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e15d0.
struct Unk_27e15d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023ff750: vf_type and its thunks 0x7100f6b9c0 (+0x48), 0x7100f6ba70 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ff740 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15d0::Unk_GetType());
        return &type;
    }

    ~Unk_23ff740() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023ffb88: vf_type and its thunks 0x7100f71770 (+0x48), 0x7100f717e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ffb78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }

    ~Unk_23ffb78() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023ffe10: vf_type and its thunks 0x7100f74540 (+0x48), 0x7100f745f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ffe00 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15d0::Unk_GetType());
        return &type;
    }

    ~Unk_23ffe00() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100f673e0
// 0x7100f674f0
// 0x7100f67560
const Unk_239a418_Type* Unk_23ff270::vf_type() {
    return Unk_GetType();
}

// 0x7100f67ab0
// 0x7100f67b40
// 0x7100f67bb0
const Unk_239a418_Type* Unk_23ff3d0::vf_type() {
    return Unk_GetType();
}

// 0x7100f6b810
// 0x7100f6b9c0
// 0x7100f6ba70
const Unk_239a418_Type* Unk_23ff740::vf_type() {
    return Unk_GetType();
}

// 0x7100f716e0
// 0x7100f71770
// 0x7100f717e0
const Unk_239a418_Type* Unk_23ffb78::vf_type() {
    return Unk_GetType();
}

// 0x7100f74390
// 0x7100f74540
// 0x7100f745f0
const Unk_239a418_Type* Unk_23ffe00::vf_type() {
    return Unk_GetType();
}
