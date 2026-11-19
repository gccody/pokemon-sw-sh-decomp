// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d93e8.
struct Unk_27d93e8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(&Unk_239a418_RootType());
        return &type;
    }
};

// The type 0x71027d93d8.
struct Unk_27d93d8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d93e8::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023db5b0: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23db5a0 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x71023db6a8: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23db698 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x71023dba60: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23dba50 {
    const Unk_239a418_Type* vf0();
};

// 0x7100c46f10
const Unk_239a418_Type* Unk_23db5a0::vf5() {
    return Unk_27d93e8::Unk_GetType();
}

// 0x7100c47030
const Unk_239a418_Type* Unk_23db698::vf0() {
    return Unk_27d93e8::Unk_GetType();
}

// 0x7100c49de0
const Unk_239a418_Type* Unk_23dba50::vf0() {
    return Unk_27d93d8::Unk_GetType();
}
