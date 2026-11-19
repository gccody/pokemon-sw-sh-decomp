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

// The type 0x71027f0448: its getter is out of line.
struct Unk_2441f08 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027736b8.
struct Unk_2399fa8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a360::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102442228: vf_type and its thunks 0x71014b1f20 (+0x48), 0x71014b1fd0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2442218 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_2442218() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102442470: vf_type and its thunks 0x71014b5a70 (+0x48), 0x71014b5ae0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2442460 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2441f08::Unk_GetType());
        return &type;
    }

    ~Unk_2442460() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102442608: vf_type and its thunks 0x71014b6070 (+0x48), 0x71014b60e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24425f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2441f08::Unk_GetType());
        return &type;
    }

    ~Unk_24425f8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102442760: vf_type and its thunks 0x71014b64f0 (+0x48), 0x71014b6560 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2442750 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2441f08::Unk_GetType());
        return &type;
    }

    ~Unk_2442750() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024428b8: vf_type and its thunks 0x71014b69c0 (+0x48), 0x71014b6a30 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24428a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2441f08::Unk_GetType());
        return &type;
    }

    ~Unk_24428a8() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0b00.
struct Unk_27e0b00 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2441f08::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102442a10: vf_type and its thunks 0x71014b76b0 (+0x48), 0x71014b7760 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2442a00 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e0b00::Unk_GetType());
        return &type;
    }

    ~Unk_2442a00() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102442b88: vf_type and its thunks 0x71014b78d0 (+0x48), 0x71014b7980 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2442b78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e0b00::Unk_GetType());
        return &type;
    }

    ~Unk_2442b78() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102442d00: vf_type and its thunks 0x71014b87e0 (+0x48), 0x71014b8850 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2442cf0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2441f08::Unk_GetType());
        return &type;
    }

    ~Unk_2442cf0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71014b1e50
// 0x71014b1f20
// 0x71014b1fd0
const Unk_239a418_Type* Unk_2442218::vf_type() {
    return Unk_GetType();
}

// 0x71014b59d0
// 0x71014b5a70
// 0x71014b5ae0
const Unk_239a418_Type* Unk_2442460::vf_type() {
    return Unk_GetType();
}

// 0x71014b5fd0
// 0x71014b6070
// 0x71014b60e0
const Unk_239a418_Type* Unk_24425f8::vf_type() {
    return Unk_GetType();
}

// 0x71014b6460
// 0x71014b64f0
// 0x71014b6560
const Unk_239a418_Type* Unk_2442750::vf_type() {
    return Unk_GetType();
}

// 0x71014b6910
// 0x71014b69c0
// 0x71014b6a30
const Unk_239a418_Type* Unk_24428a8::vf_type() {
    return Unk_GetType();
}

// 0x71014b75f0
// 0x71014b76b0
// 0x71014b7760
const Unk_239a418_Type* Unk_2442a00::vf_type() {
    return Unk_GetType();
}

// 0x71014b7810
// 0x71014b78d0
// 0x71014b7980
const Unk_239a418_Type* Unk_2442b78::vf_type() {
    return Unk_GetType();
}

// 0x71014b8760
// 0x71014b87e0
// 0x71014b8850
const Unk_239a418_Type* Unk_2442cf0::vf_type() {
    return Unk_GetType();
}
