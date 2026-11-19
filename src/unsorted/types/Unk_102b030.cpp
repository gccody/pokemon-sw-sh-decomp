// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e51b8: its getter is out of line.
struct Unk_27e51b8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e51c8: its getter is out of line.
struct Unk_27e51c8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// A forwarder in slot 5 of vtable 0x7102409208: it tail-calls its
// type's getter (0x710102b0b0, out of line). Declared without its bases or its vtable.
struct Unk_2409238 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x7102409208: it tail-calls its
// type's getter (0x710102b0b0, out of line). Declared without its bases or its vtable.
struct Unk_2409290 {
    const Unk_239a418_Type* vf0();
};

// A forwarder in slot 5 of vtable 0x71024093a8: it tail-calls its
// type's getter (0x710102bda0, out of line). Declared without its bases or its vtable.
struct Unk_24093d8 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x71024093a8: it tail-calls its
// type's getter (0x710102bda0, out of line). Declared without its bases or its vtable.
struct Unk_2409430 {
    const Unk_239a418_Type* vf0();
};

// 0x710102b030
const Unk_239a418_Type* Unk_2409238::vf5() {
    return Unk_27e51c8::Unk_GetType();
}

// 0x710102b040
const Unk_239a418_Type* Unk_2409290::vf0() {
    return Unk_27e51c8::Unk_GetType();
}

// 0x710102bd20
const Unk_239a418_Type* Unk_24093d8::vf5() {
    return Unk_27e51b8::Unk_GetType();
}

// 0x710102bd30
const Unk_239a418_Type* Unk_2409430::vf0() {
    return Unk_27e51b8::Unk_GetType();
}
