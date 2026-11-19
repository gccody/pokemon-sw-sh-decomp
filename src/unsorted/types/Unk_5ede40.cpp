// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102774000: its getter is out of line.
struct Unk_2774000 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102774058: its getter is out of line.
struct Unk_2774058 {
    static const Unk_239a418_Type* Unk_GetType();
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

// A forwarder in slot 5 of vtable 0x710239aba0: it tail-calls its
// type's getter (0x71005eb880, out of line). Declared without its bases or its vtable.
struct Unk_239abd0 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x710239aba0: it tail-calls its
// type's getter (0x71005eb880, out of line). Declared without its bases or its vtable.
struct Unk_239ac28 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710239ac60: a type getter in its slot 13, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239ac50 {
    const Unk_239a418_Type* vf13();
};

// vtable 0x710239ae10: a type getter in its slot 13, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_239ae00 {
    const Unk_239a418_Type* vf13();
};

// 0x71005ede40
const Unk_239a418_Type* Unk_239abd0::vf5() {
    return Unk_2774000::Unk_GetType();
}

// 0x71005ede50
const Unk_239a418_Type* Unk_239ac28::vf0() {
    return Unk_2774000::Unk_GetType();
}

// 0x71005ee4d0
const Unk_239a418_Type* Unk_239ac50::vf13() {
    return Unk_2774068::Unk_GetType();
}

// 0x71005eee70
const Unk_239a418_Type* Unk_239ae00::vf13() {
    return Unk_2774078::Unk_GetType();
}
