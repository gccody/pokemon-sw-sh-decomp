// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// The type 0x71027f08f0.
struct Unk_243a558 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027f0928.
struct Unk_243a6a0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_243a558::Unk_GetType());
        return &type;
    }
};

// The type 0x71027f0938.
struct Unk_243a7e8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_243a558::Unk_GetType());
        return &type;
    }
};

// vtable 0x710243a7d0: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_243a7c0 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710243a918: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_243a908 {
    const Unk_239a418_Type* vf0();
};

// 0x710142f880
const Unk_239a418_Type* Unk_243a7c0::vf0() {
    return Unk_243a6a0::Unk_GetType();
}

// 0x710142fb20
const Unk_239a418_Type* Unk_243a908::vf0() {
    return Unk_243a7e8::Unk_GetType();
}
