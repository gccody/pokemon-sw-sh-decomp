// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8528.
struct Unk_27d8528 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7100b76960: the copy of its getter that the getters below call (too big
// to be inlined into them: clang emits it here).
// The type 0x71027d85b8.
struct Unk_27d85b8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8528::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d85a8.
struct Unk_23d0db0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d85b8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d85e8.
struct Unk_23d0eb0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d0db0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8740.
struct Unk_27d8740 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d0db0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8770.
struct Unk_23d1348 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8740::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8780.
struct Unk_23d1448 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d0eb0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027d8818.
struct Unk_23d1760 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8740::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023d13f0: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23d13e0 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x71023d1508: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23d14f8 {
    const Unk_239a418_Type* vf5();
};

// vtable 0x71023d1808: a type getter in its slot 5, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_23d17f8 {
    const Unk_239a418_Type* vf5();
};

// 0x7100b7f500
const Unk_239a418_Type* Unk_23d13e0::vf5() {
    return Unk_23d1348::Unk_GetType();
}

// 0x7100b7fb70
const Unk_239a418_Type* Unk_23d14f8::vf5() {
    return Unk_23d1448::Unk_GetType();
}

// 0x7100b82a10
const Unk_239a418_Type* Unk_23d17f8::vf5() {
    return Unk_23d1760::Unk_GetType();
}
