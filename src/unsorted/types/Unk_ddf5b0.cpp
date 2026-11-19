// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027dbfd8: its getter is out of line.
struct Unk_23f0a88 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027dec10: its getter is out of line.
struct Unk_27dec10 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023f09e8: vf_type and its thunks 0x7100ddf620 (+0x48), 0x7100ddf690 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f09d8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f0a88::Unk_GetType());
        return &type;
    }

    ~Unk_23f09d8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f0b48: vf_type and its thunks 0x7100de0960 (+0x48), 0x7100de09d0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f0b38 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27dec10::Unk_GetType());
        return &type;
    }

    ~Unk_23f0b38() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100ddf5b0
// 0x7100ddf620
// 0x7100ddf690
const Unk_239a418_Type* Unk_23f09d8::vf_type() {
    return Unk_GetType();
}

// 0x7100de08f0
// 0x7100de0960
// 0x7100de09d0
const Unk_239a418_Type* Unk_23f0b38::vf_type() {
    return Unk_GetType();
}
