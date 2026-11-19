// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// A forwarder in slot 6 of vtable 0x71023f0a98: it tail-calls its
// type's getter (0x7100ddf8c0, out of line). Declared without its bases or its vtable.
struct Unk_23f0a88 {
    static const Unk_239a418_Type* Unk_GetType();
    const Unk_239a418_Type* vf6();
};

// A forwarder in slot 5 of vtable 0x71023f0a98: it tail-calls its
// type's getter (0x7100ddf8c0, out of line). Declared without its bases or its vtable.
struct Unk_23f0ad0 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x71023f0a98: it tail-calls its
// type's getter (0x7100ddf8c0, out of line). Declared without its bases or its vtable.
struct Unk_23f0b10 {
    const Unk_239a418_Type* vf0();
};

// 0x7100ddf850
const Unk_239a418_Type* Unk_23f0a88::vf6() {
    return Unk_23f0a88::Unk_GetType();
}

// 0x7100ddf880
const Unk_239a418_Type* Unk_23f0ad0::vf5() {
    return Unk_23f0a88::Unk_GetType();
}

// 0x7100ddf890
const Unk_239a418_Type* Unk_23f0b10::vf0() {
    return Unk_23f0a88::Unk_GetType();
}
