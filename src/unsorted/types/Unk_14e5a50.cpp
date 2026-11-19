// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// A forwarder in slot 6 of vtable 0x7102444b48: it tail-calls its
// type's getter (0x7100f0ce40, out of line). Declared without its bases or its vtable.
struct Unk_2444b38 {
    static const Unk_239a418_Type* Unk_GetType();
    const Unk_239a418_Type* vf6();
};

// A forwarder in slot 5 of vtable 0x7102444b48: it tail-calls its
// type's getter (0x7100f0ce40, out of line). Declared without its bases or its vtable.
struct Unk_2444c38 {
    const Unk_239a418_Type* vf5();
};

// A forwarder in slot 0 of vtable 0x7102444b48: it tail-calls its
// type's getter (0x7100f0ce40, out of line). Declared without its bases or its vtable.
struct Unk_2444c78 {
    const Unk_239a418_Type* vf0();
};

// 0x71014e5a50
const Unk_239a418_Type* Unk_2444b38::vf6() {
    return Unk_2444b38::Unk_GetType();
}

// 0x71014e5c60
const Unk_239a418_Type* Unk_2444c38::vf5() {
    return Unk_2444b38::Unk_GetType();
}

// 0x71014e5c70
const Unk_239a418_Type* Unk_2444c78::vf0() {
    return Unk_2444b38::Unk_GetType();
}
