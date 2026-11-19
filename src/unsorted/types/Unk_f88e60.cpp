// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e15e0: its getter is out of line.
struct Unk_27e15e0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71024010f0: vf_type and its thunks 0x7100f89040 (+0x48), 0x7100f89050 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100f893e0).
// Its base and its other functions aren't written here.
class Unk_24010e0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_24010e0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024013d0: vf_type and its thunks 0x7100f8d9e0 (+0x48), 0x7100f8da50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24013c0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }

    ~Unk_24013c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100f88e60
// 0x7100f89040
// 0x7100f89050
const Unk_239a418_Type* Unk_24010e0::vf_type() {
    return Unk_GetType();
}

// 0x7100f8d950
// 0x7100f8d9e0
// 0x7100f8da50
const Unk_239a418_Type* Unk_24013c0::vf_type() {
    return Unk_GetType();
}
