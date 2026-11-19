// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027715a0: its getter is out of line.
struct Unk_27715a0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// A forwarder in slot 5 of vtable 0x7102398ac8: it tail-calls its
// type's getter (0x71005b2f90, out of line). Declared without its bases or its vtable.
struct Unk_2398af8 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x7102398ac8: it tail-calls its
// type's getter (0x71005b2f90, out of line). Declared without its bases or its vtable.
struct Unk_2398c18 {
    const Unk_239a418_Type* vf0();
};

// 0x71005b2f10
const Unk_239a418_Type* Unk_2398af8::vf5() {
    return Unk_27715a0::Unk_GetType();
}

// 0x71005b2f20
const Unk_239a418_Type* Unk_2398c18::vf0() {
    return Unk_27715a0::Unk_GetType();
}
