// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9438: its getter is out of line.
struct Unk_27d9438 {
    static const Unk_239a418_Type* Unk_GetType();
};

// A forwarder in slot 5 of vtable 0x7102409618: it tail-calls its
// type's getter (0x710102f5b0, out of line). Declared without its bases or its vtable.
struct Unk_2409648 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x7102409618: it tail-calls its
// type's getter (0x710102f5b0, out of line). Declared without its bases or its vtable.
struct Unk_24096a0 {
    const Unk_239a418_Type* vf0();
};

// 0x710102f530
const Unk_239a418_Type* Unk_2409648::vf5() {
    return Unk_27d9438::Unk_GetType();
}

// 0x710102f540
const Unk_239a418_Type* Unk_24096a0::vf0() {
    return Unk_27d9438::Unk_GetType();
}
