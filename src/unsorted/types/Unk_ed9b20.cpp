// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027740c8: its getter is out of line.
struct Unk_239bb58 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102777178.
struct Unk_239b8d8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }
};

// The type 0x7102777248.
struct Unk_239c100 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b8d8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e0c30.
struct Unk_23f7ae0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f7b90: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23f7b80 {
    const Unk_239a418_Type* vf5();
};

// 0x7100ed9b20
const Unk_239a418_Type* Unk_23f7b80::vf5() {
    return Unk_23f7ae0::Unk_GetType();
}
