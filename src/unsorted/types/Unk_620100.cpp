// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d6250: its getter is out of line.
struct Unk_2399d08 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027736b8: its getter is out of line.
struct Unk_2399fa8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71024ba7e8: its getter is out of line.
struct Unk_239a360 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102777178: its getter is out of line.
struct Unk_239b8d8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027771e8: its getter is out of line.
struct Unk_27771e8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027771d8.
struct Unk_2399b40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771e8::Unk_GetType());
        return &type;
    }
};

// The type 0x71027740c8.
struct Unk_239bb58 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type 0x7102777248.
struct Unk_239c100 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b8d8::Unk_GetType());
        return &type;
    }
};

// vtable 0x710239cfe0: vf_type and its thunks 0x7100620140 (+0x48), 0x7100620150 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x710061e5b0).
// Its base and its other functions aren't written here.
class Unk_239cfd0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    ~Unk_239cfd0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239d118: vf_type and its thunks 0x7100621f50 (+0x48), 0x7100622000 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239d108 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }

    ~Unk_239d108() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239d5a8: vf_type and its thunks 0x710062ab60 (+0x48), 0x710062abd0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239d598 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a360::Unk_GetType());
        return &type;
    }

    ~Unk_239d598() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239d4e8: vf_type and its thunks 0x7100629c70 (+0x48), 0x7100629d20 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239d4d8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239d598::Unk_GetType());
        return &type;
    }

    ~Unk_239d4d8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239dbf0: vf_type and its thunks 0x7100635d60 (+0x48), 0x7100635dd0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239dbe0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_239dbe0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239e310: vf_type and its thunks 0x7100638330 (+0x48), 0x71006383a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239e300 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_239e300() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239e8e0: vf_type and its thunks 0x7100646790 (+0x48), 0x7100646840 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239e8d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }

    ~Unk_239e8d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239ec88: vf_type and its thunks 0x710064cef0 (+0x48), 0x710064cf60 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239ec78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_239ec78() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239f158: vf_type and its thunks 0x7100651b00 (+0x48), 0x7100651b70 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239f148 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399fa8::Unk_GetType());
        return &type;
    }

    ~Unk_239f148() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239f218: vf_type and its thunks 0x7100652e70 (+0x48), 0x7100652ee0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239f208 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
        return &type;
    }

    ~Unk_239f208() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710239f4c8: vf_type and its thunks 0x7100658ad0 (+0x48), 0x7100658b80 (+0x50).
// Its base and its other functions aren't written here.
class Unk_239f4b8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }

    ~Unk_239f4b8() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027771c8.
struct Unk_27771c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399b40::Unk_GetType());
        return &type;
    }
};

// 0x7100620100
// 0x7100620140
// 0x7100620150
const Unk_239a418_Type* Unk_239cfd0::vf_type() {
    return Unk_GetType();
}

// 0x7100621ca0
// 0x7100621f50
// 0x7100622000
const Unk_239a418_Type* Unk_239d108::vf_type() {
    return Unk_GetType();
}

// 0x7100629b00
// 0x7100629c70
// 0x7100629d20
const Unk_239a418_Type* Unk_239d4d8::vf_type() {
    return Unk_GetType();
}

// 0x710062aa30
// 0x710062ab60
// 0x710062abd0
const Unk_239a418_Type* Unk_239d598::vf_type() {
    return Unk_GetType();
}

// 0x71006355c0
// 0x7100635d60
// 0x7100635dd0
const Unk_239a418_Type* Unk_239dbe0::vf_type() {
    return Unk_GetType();
}

// 0x7100638200
// 0x7100638330
// 0x71006383a0
const Unk_239a418_Type* Unk_239e300::vf_type() {
    return Unk_GetType();
}

// 0x71006466c0
// 0x7100646790
// 0x7100646840
const Unk_239a418_Type* Unk_239e8d0::vf_type() {
    return Unk_GetType();
}

// 0x710064cdc0
// 0x710064cef0
// 0x710064cf60
const Unk_239a418_Type* Unk_239ec78::vf_type() {
    return Unk_GetType();
}

// 0x71006519d0
// 0x7100651b00
// 0x7100651b70
const Unk_239a418_Type* Unk_239f148::vf_type() {
    return Unk_GetType();
}

// 0x7100652dd0
// 0x7100652e70
// 0x7100652ee0
const Unk_239a418_Type* Unk_239f208::vf_type() {
    return Unk_GetType();
}

// 0x7100658a00
// 0x7100658ad0
// 0x7100658b80
const Unk_239a418_Type* Unk_239f4b8::vf_type() {
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

// 0x7100637d00
template bool Unk_61a530<Unk_27771c8>(Unk_239a498* object);
