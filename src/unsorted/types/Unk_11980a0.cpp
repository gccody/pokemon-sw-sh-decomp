// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d8f98.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e9fe0.
struct Unk_2419968 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ea118.
struct Unk_241c720 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241dc48: vf_type and its thunks 0x71011980d0 (+0x48), 0x71011980e0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7101198110).
// Its base and its other functions aren't written here.
class Unk_241dc38 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241c720::Unk_GetType());
        return &type;
    }

    ~Unk_241dc38() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71011980a0
// 0x71011980d0
// 0x71011980e0
const Unk_239a418_Type* Unk_241dc38::vf_type() {
    return Unk_GetType();
}
