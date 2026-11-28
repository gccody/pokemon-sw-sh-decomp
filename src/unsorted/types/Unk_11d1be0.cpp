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

// The type 0x71027ec1f0.
struct Unk_2420ad0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ec210.
struct Unk_2420800 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2420ad0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ec220.
struct Unk_2420c40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2420ad0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027ec1e0.
struct Unk_2420fb0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2420ad0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71024208e8: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_24208d8 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x7102420d28: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2420d18 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x7102421098: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_2421088 {
    const Unk_239a418_Type* vf5();
};

// 0x71011d1be0
const Unk_239a418_Type* Unk_24208d8::vf5() {
    return Unk_2420800::Unk_GetType();
}

// 0x71011d4d00
const Unk_239a418_Type* Unk_2420d18::vf5() {
    return Unk_2420c40::Unk_GetType();
}

// 0x71011d7430
const Unk_239a418_Type* Unk_2421088::vf5() {
    return Unk_2420fb0::Unk_GetType();
}
