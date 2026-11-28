// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8528: its getter is out of line.
struct Unk_27d8528 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d8518.
struct Unk_23cf760 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8528::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8538.
struct Unk_27d8538 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23cf760::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8578.
struct Unk_23cf3c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8538::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023cf550: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23cf540 {
    const Unk_239a418_Type* vf5();
};

// 0x7100b420c0
const Unk_239a418_Type* Unk_23cf540::vf5() {
    return Unk_23cf3c0::Unk_GetType();
}
