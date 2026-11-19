// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e9d10: its getter is out of line.
struct Unk_27e9d10 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102777228.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102418a30: vf_type and its thunks 0x7101115c40 (+0x48), 0x7101115cb0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2418a20 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e9d10::Unk_GetType());
        return &type;
    }

    ~Unk_2418a20() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102418ae0: vf_type and its thunks 0x7101117170 (+0x48), 0x7101117180 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101117560).
// Its base and its other functions aren't written here.
class Unk_2418ad0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_2418ad0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101115bb0
// 0x7101115c40
// 0x7101115cb0
const Unk_239a418_Type* Unk_2418a20::vf_type() {
    return Unk_GetType();
}

// 0x7101116fc0
// 0x7101117170
// 0x7101117180
const Unk_239a418_Type* Unk_2418ad0::vf_type() {
    return Unk_GetType();
}
