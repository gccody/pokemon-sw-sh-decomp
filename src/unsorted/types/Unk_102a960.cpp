// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e51b8: its getter is out of line.
struct Unk_27e51b8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e51c8: its getter is out of line.
struct Unk_27e51c8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102409128: vf_type and its thunks 0x710102abc0 (+0x48), 0x710102adc0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2409118 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e51c8::Unk_GetType());
        return &type;
    }

    ~Unk_2409118() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71024092c8: vf_type and its thunks 0x710102b8f0 (+0x48), 0x710102bab0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_24092b8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e51b8::Unk_GetType());
        return &type;
    }

    ~Unk_24092b8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710102a960
// 0x710102abc0
// 0x710102adc0
const Unk_239a418_Type* Unk_2409118::vf_type() {
    return Unk_GetType();
}

// 0x710102b690
// 0x710102b8f0
// 0x710102bab0
const Unk_239a418_Type* Unk_24092b8::vf_type() {
    return Unk_GetType();
}
