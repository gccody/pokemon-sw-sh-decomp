// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8f98: its getter is out of line.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e9fe0.
struct Unk_2419968 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ea0e0.
struct Unk_2419800 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }
};

// The type 0x71027eb320.
struct Unk_241e360 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419800::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241e208: vf_type and its thunks 0x710119e120 (+0x48), 0x710119e130 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710119e200).
// Its base and its other functions aren't written here.
class Unk_241e1f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241e360::Unk_GetType());
        return &type;
    }

    ~Unk_241e1f8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710119e050
// 0x710119e120
// 0x710119e130
const Unk_239a418_Type* Unk_241e1f8::vf_type() {
    return Unk_GetType();
}
