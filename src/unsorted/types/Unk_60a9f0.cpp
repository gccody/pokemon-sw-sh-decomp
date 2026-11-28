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

// The type 0x7102777258.
struct Unk_239c208 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }
};

// vtable 0x710239c2f8: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239c2e8 {
    const Unk_239a418_Type* vf0();
};

// 0x710060a9f0
const Unk_239a418_Type* Unk_239c2e8::vf0() {
    return Unk_239c208::Unk_GetType();
}
