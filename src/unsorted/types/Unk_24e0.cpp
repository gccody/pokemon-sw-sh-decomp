// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71024ba540.
struct Unk_24ba540 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(&Unk_239a418_RootType());
        return &type;
    }
};

// The type 0x71024ba530.
struct Unk_24ba530 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24ba540::Unk_GetType());
        return &type;
    }
};

// 0x71000027d0: the copy of its getter that the getters below call (too big
// to be inlined into them: clang emits it here).
// The type 0x71024ba520.
struct Unk_24ba520 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24ba530::Unk_GetType());
        return &type;
    }
};

// The type 0x71024ba510.
struct Unk_24ba510 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24ba520::Unk_GetType());
        return &type;
    }
};

// vtable 0x710236d0c8: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_236d0b8 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x710236d1a0: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_236d190 {
    const Unk_239a418_Type* vf0();
};

// 0x71000024e0
const Unk_239a418_Type* Unk_236d0b8::vf5() {
    return Unk_24ba510::Unk_GetType();
}

// 0x7100002640
const Unk_239a418_Type* Unk_236d190::vf0() {
    return Unk_24ba510::Unk_GetType();
}
