// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6220: its getter is out of line.
struct Unk_23ddd68 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027dbe78: its getter is out of line.
struct Unk_23dee88 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efd50.
struct Unk_23e3950 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23ddd68::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e63a8: vf_type and its thunks 0x7100d03b40 (+0x48), 0x7100d03bb0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e6398 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dee88::Unk_GetType());
        return &type;
    }

    ~Unk_23e6398() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023e6848: vf_type and its thunks 0x7100d045b0 (+0x48), 0x7100d04660 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e6838 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e3950::Unk_GetType());
        return &type;
    }

    ~Unk_23e6838() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023e6af0: vf_type and its thunks 0x7100d04ba0 (+0x48), 0x7100d04c50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e6ae0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e3950::Unk_GetType());
        return &type;
    }

    ~Unk_23e6ae0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d03ab0
// 0x7100d03b40
// 0x7100d03bb0
const Unk_239a418_Type* Unk_23e6398::vf_type() {
    return Unk_GetType();
}

// 0x7100d04460
// 0x7100d045b0
// 0x7100d04660
const Unk_239a418_Type* Unk_23e6838::vf_type() {
    return Unk_GetType();
}

// 0x7100d04a50
// 0x7100d04ba0
// 0x7100d04c50
const Unk_239a418_Type* Unk_23e6ae0::vf_type() {
    return Unk_GetType();
}
