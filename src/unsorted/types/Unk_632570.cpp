// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027771d8: its getter is out of line.
struct Unk_27771d8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027771c8.
struct Unk_27771c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771d8::Unk_GetType());
        return &type;
    }
};

// vtable 0x710239d668: vf_type and its thunks 0x7100632b40 (+0x48), 0x7100632bf0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239d658 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771c8::Unk_GetType());
        return &type;
    }

    ~Unk_239d658() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239ea10: vf_type and its thunks 0x710064b480 (+0x48), 0x710064b530 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239ea00 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771c8::Unk_GetType());
        return &type;
    }

    ~Unk_239ea00() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100632570
// 0x7100632b40
// 0x7100632bf0
const Unk_239a418_Type* Unk_239d658::vf_type() {
    return Unk_GetType();
}

// 0x710064b3b0
// 0x710064b480
// 0x710064b530
const Unk_239a418_Type* Unk_239ea00::vf_type() {
    return Unk_GetType();
}
