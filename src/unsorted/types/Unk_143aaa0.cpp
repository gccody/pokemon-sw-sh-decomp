// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e05b0: its getter is out of line.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027e05f0: its getter is out of line.
struct Unk_2444b38 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x71027ce8c8.
struct Unk_23f6328 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e0b40.
struct Unk_23f6a68 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f6328::Unk_GetType());
        return &type;
    }
};

// 0x710143ad70: the copy of its getter that the getters below call (too big
// to be inlined into them: clang emits it here).
// The type 0x71027f0a48.
struct Unk_27f0a48 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }
};

// vtable 0x710243b4a0: vf_type and its thunks 0x710143abd0 (+0x48), 0x710143ac40 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243b490 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0a48::Unk_GetType());
        return &type;
    }

    ~Unk_243b490() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243b740: vf_type and its thunks 0x710143bc20 (+0x48), 0x710143bc90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243b730 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0a48::Unk_GetType());
        return &type;
    }

    ~Unk_243b730() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243ba40: vf_type and its thunks 0x710143ea20 (+0x48), 0x710143ea90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243ba30 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }

    ~Unk_243ba30() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243bd00: vf_type and its thunks 0x710143ff70 (+0x48), 0x7101440020 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243bcf0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_243bcf0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710243c468: vf_type and its thunks 0x710144c0d0 (+0x48), 0x710144c180 (+0x50).
// Its base and its other functions aren't written here.
class Unk_243c458 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_243c458() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e05e0.
struct Unk_24446c0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444b38::Unk_GetType());
        return &type;
    }
};

// The type 0x71027e05d0.
struct Unk_2445a38 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24446c0::Unk_GetType());
        return &type;
    }
};

// 0x710143aaa0
// 0x710143abd0
// 0x710143ac40
const Unk_239a418_Type* Unk_243b490::vf_type() {
    return Unk_GetType();
}

// 0x710143bb90
// 0x710143bc20
// 0x710143bc90
const Unk_239a418_Type* Unk_243b730::vf_type() {
    return Unk_GetType();
}

// 0x710143e990
// 0x710143ea20
// 0x710143ea90
const Unk_239a418_Type* Unk_243ba30::vf_type() {
    return Unk_GetType();
}

// 0x710143fea0
// 0x710143ff70
// 0x7101440020
const Unk_239a418_Type* Unk_243bcf0::vf_type() {
    return Unk_GetType();
}

// 0x710144c000
// 0x710144c0d0
// 0x710144c180
const Unk_239a418_Type* Unk_243c458::vf_type() {
    return Unk_GetType();
}

// Whether an object's type is the template argument or one derived from it,
// through the object's +0x50 interface.
template <class T>
bool Unk_61a530(Unk_239a498* object) {
    const Unk_239a418_Type* type = object->vf_type();
    const Unk_239a418_Type* kind = T::Unk_GetType();
    for (; type != nullptr; type = type->field_0)
        if (type == kind)
            return true;
    return false;
}

// 0x710143d390
template bool Unk_61a530<Unk_2445a38>(Unk_239a498* object);

// 0x7101441fb0
template bool Unk_61a530<Unk_23f6a68>(Unk_239a498* object);

// 0x710144b3c0
template bool Unk_61a530<Unk_243c458>(Unk_239a498* object);
