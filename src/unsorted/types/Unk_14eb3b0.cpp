// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0630: its getter is out of line.
struct Unk_2444850 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e05f0: its getter is out of line.
struct Unk_2444b38 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e05e0.
struct Unk_24446c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444b38::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102444f60: vf_type and its thunks 0x71014eb620 (+0x48), 0x71014eb690 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2444f50 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444850::Unk_GetType());
        return &type;
    }

    ~Unk_2444f50() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024450f8: vf_type and its thunks 0x71014ecb50 (+0x48), 0x71014ecbc0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24450e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444b38::Unk_GetType());
        return &type;
    }

    ~Unk_24450e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102445a48: vf_type and its thunks 0x71014fb880 (+0x48), 0x71014fb930 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2445a38 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24446c0::Unk_GetType());
        return &type;
    }

    ~Unk_2445a38() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102445c30: vf_type and its thunks 0x71014fc630 (+0x48), 0x71014fc6a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2445c20 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444b38::Unk_GetType());
        return &type;
    }

    ~Unk_2445c20() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102445fd8: vf_type and its thunks 0x71014fefb0 (+0x48), 0x71014ff060 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2445fc8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24446c0::Unk_GetType());
        return &type;
    }

    ~Unk_2445fc8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024461c0: vf_type and its thunks 0x71014ff9b0 (+0x48), 0x71014ffa60 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24461b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24446c0::Unk_GetType());
        return &type;
    }

    ~Unk_24461b0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71014eb3b0
// 0x71014eb620
// 0x71014eb690
const Unk_239a418_Type* Unk_2444f50::vf_type() {
    return Unk_GetType();
}

// 0x71014ecac0
// 0x71014ecb50
// 0x71014ecbc0
const Unk_239a418_Type* Unk_24450e8::vf_type() {
    return Unk_GetType();
}

// 0x71014fb6f0
// 0x71014fb880
// 0x71014fb930
const Unk_239a418_Type* Unk_2445a38::vf_type() {
    return Unk_GetType();
}

// 0x71014fc3e0
// 0x71014fc630
// 0x71014fc6a0
const Unk_239a418_Type* Unk_2445c20::vf_type() {
    return Unk_GetType();
}

// 0x71014fee40
// 0x71014fefb0
// 0x71014ff060
const Unk_239a418_Type* Unk_2445fc8::vf_type() {
    return Unk_GetType();
}

// 0x71014ff840
// 0x71014ff9b0
// 0x71014ffa60
const Unk_239a418_Type* Unk_24461b0::vf_type() {
    return Unk_GetType();
}
