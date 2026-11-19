// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71024ba7e8: its getter is out of line.
struct Unk_239a360 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027740c8: its getter is out of line.
struct Unk_239bb58 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027736b8.
struct Unk_2399fa8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a360::Unk_GetType());
        return &type;
    }
};

// The type 0x7102777178.
struct Unk_239b8d8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }
};

// The type 0x71027772e8.
struct Unk_239cfd0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }
};

// vtable 0x710239d290: vf_type and its thunks 0x71006237a0 (+0x48), 0x7100623850 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239d280 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239cfd0::Unk_GetType());
        return &type;
    }

    ~Unk_239d280() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239e3d0: vf_type and its thunks 0x710063ddf0 (+0x48), 0x710063de60 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239e3c0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    ~Unk_239e3c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239e640: vf_type and its thunks 0x71006448d0 (+0x48), 0x7100644980 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239e630 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b8d8::Unk_GetType());
        return &type;
    }

    ~Unk_239e630() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239f348: vf_type and its thunks 0x71006556d0 (+0x48), 0x7100655780 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239f338 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_239f338() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239f408: vf_type and its thunks 0x7100657680 (+0x48), 0x7100657730 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239f3f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_239f3f8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71006236f0
// 0x71006237a0
// 0x7100623850
const Unk_239a418_Type* Unk_239d280::vf_type() {
    return Unk_GetType();
}

// 0x710063dce0
// 0x710063ddf0
// 0x710063de60
const Unk_239a418_Type* Unk_239e3c0::vf_type() {
    return Unk_GetType();
}

// 0x7100644740
// 0x71006448d0
// 0x7100644980
const Unk_239a418_Type* Unk_239e630::vf_type() {
    return Unk_GetType();
}

// 0x7100655600
// 0x71006556d0
// 0x7100655780
const Unk_239a418_Type* Unk_239f338::vf_type() {
    return Unk_GetType();
}

// 0x71006575b0
// 0x7100657680
// 0x7100657730
const Unk_239a418_Type* Unk_239f3f8::vf_type() {
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

// 0x7100623600
template bool Unk_61a530<Unk_239e630>(Unk_239a498* object);

// 0x7100644cd0
template bool Unk_61a530<Unk_239d280>(Unk_239a498* object);
