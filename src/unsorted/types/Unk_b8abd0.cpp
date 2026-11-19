// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8538: its getter is out of line.
struct Unk_27d8538 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023d1df8: a type getter in its slot 6, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23d1de8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8538::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf6();
};

// A forwarder in slot 6 of vtable 0x71023d2980: it tail-calls its
// type's getter (0x7100b946e0, out of line). Declared without its bases or its vtable.
struct Unk_23d2970 {
    static const Unk_239a418_Type* Unk_GetType();
    const Unk_239a418_Type* vf6();
};

// A forwarder in slot 5 of vtable 0x71023d2980: it tail-calls its
// type's getter (0x7100b946e0, out of line). Declared without its bases or its vtable.
struct Unk_23d2af0 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x71023d2980: it tail-calls its
// type's getter (0x7100b946e0, out of line). Declared without its bases or its vtable.
struct Unk_23d2b30 {
    const Unk_239a418_Type* vf0();
};

// 0x7100b8abd0
const Unk_239a418_Type* Unk_23d1de8::vf6() {
    return Unk_GetType();
}

// 0x7100b9f5f0
const Unk_239a418_Type* Unk_23d2970::vf6() {
    return Unk_23d2970::Unk_GetType();
}

// 0x7100b9f7a0
const Unk_239a418_Type* Unk_23d2af0::vf5() {
    return Unk_23d2970::Unk_GetType();
}

// 0x7100b9f7b0
const Unk_239a418_Type* Unk_23d2b30::vf0() {
    return Unk_23d2970::Unk_GetType();
}
