// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e3908.
struct Unk_27e3908 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x710240b378: a type getter in its slot 1, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_240b368 {
    const Unk_239a418_Type* vf1();
};

// 0x710104ece0
const Unk_239a418_Type* Unk_240b368::vf1() {
    return Unk_27e3908::Unk_GetType();
}
