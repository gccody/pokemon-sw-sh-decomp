// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e3360: its getter is out of line.
struct Unk_27e3360 {
    static const Unk_239a418_Type* Unk_GetType();
};

// A forwarder in slot 5 of vtable 0x7102409bf8: it tail-calls its
// type's getter (0x7101034d10, out of line). Declared without its bases or its vtable.
struct Unk_2409c28 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x7102409bf8: it tail-calls its
// type's getter (0x7101034d10, out of line). Declared without its bases or its vtable.
struct Unk_2409c80 {
    const Unk_239a418_Type* vf0();
};

// 0x7101034c90
const Unk_239a418_Type* Unk_2409c28::vf5() {
    return Unk_27e3360::Unk_GetType();
}

// 0x7101034ca0
const Unk_239a418_Type* Unk_2409c80::vf0() {
    return Unk_27e3360::Unk_GetType();
}
