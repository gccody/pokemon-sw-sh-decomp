// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027fc5d8.
struct Unk_27fc5d8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(nullptr);
        return &type;
    }
};

// The type 0x71027fc5c8.
struct Unk_27fc5c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27fc5d8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027fc5b8.
struct Unk_27fc5b8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27fc5c8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027fc5e8.
struct Unk_27fc5e8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27fc5d8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027fc5f8.
struct Unk_27fc5f8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(nullptr);
        return &type;
    }
};

// vtable 0x710246a490: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_246a480 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710246a5c8: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_246a5b8 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710246a798: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_246a788 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710246a8c0: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_246a8b0 {
    const Unk_239a418_Type* vf0();
};

// vtable 0x710246a9f8: a type getter in its slot 0, whose class
// isn't known: declared without its bases or its vtable, which it doesn't use.
struct Unk_246a9e8 {
    const Unk_239a418_Type* vf0();
};

// 0x710177bde0
const Unk_239a418_Type* Unk_246a480::vf0() {
    return Unk_27fc5b8::Unk_GetType();
}

// 0x710177cc00
const Unk_239a418_Type* Unk_246a5b8::vf0() {
    return Unk_27fc5c8::Unk_GetType();
}

// 0x710177ceb0
const Unk_239a418_Type* Unk_246a788::vf0() {
    return Unk_27fc5d8::Unk_GetType();
}

// 0x710177d870
const Unk_239a418_Type* Unk_246a8b0::vf0() {
    return Unk_27fc5e8::Unk_GetType();
}

// 0x710177d930
const Unk_239a418_Type* Unk_246a9e8::vf0() {
    return Unk_27fc5f8::Unk_GetType();
}
