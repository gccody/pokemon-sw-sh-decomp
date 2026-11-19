// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027740b8: its getter is out of line.
struct Unk_239bd80 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102443430: vf_type and its thunks 0x71014c7940 (+0x48), 0x71014c79b0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2443420 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bd80::Unk_GetType());
        return &type;
    }

    ~Unk_2443420() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102444300: vf_type and its thunks 0x71014de700 (+0x48), 0x71014de770 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24442f0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }

    ~Unk_24442f0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71014c78d0
// 0x71014c7940
// 0x71014c79b0
const Unk_239a418_Type* Unk_2443420::vf_type() {
    return Unk_GetType();
}

// 0x71014de380
// 0x71014de700
// 0x71014de770
const Unk_239a418_Type* Unk_24442f0::vf_type() {
    return Unk_GetType();
}
