// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102774058.
struct Unk_2774058 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(&Unk_239a418_RootType());
        return &type;
    }
};

// The type 0x7102774068.
struct Unk_2774068 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2774058::Unk_GetType());
        return &type;
    }
};

// The type 0x7102774078.
struct Unk_2774078 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2774058::Unk_GetType());
        return &type;
    }
};

// vtable 0x710239ad10: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239ad00 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710239ad38: a type getter in its slot 13, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239ad28 {
    const Unk_239a418_Type* vf13();
};

// vtable 0x710239ade8: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239add8 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710239aec0: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239aeb0 {
    const Unk_239a418_Type* vf0();
};

// 0x71005ee680
const Unk_239a418_Type* Unk_239ad00::vf0() {
    return Unk_2774068::Unk_GetType();
}

// 0x71005ee8f0
const Unk_239a418_Type* Unk_239ad28::vf13() {
    return Unk_2774058::Unk_GetType();
}

// 0x71005ee9e0
const Unk_239a418_Type* Unk_239add8::vf0() {
    return Unk_2774058::Unk_GetType();
}

// 0x71005ef020
const Unk_239a418_Type* Unk_239aeb0::vf0() {
    return Unk_2774078::Unk_GetType();
}
