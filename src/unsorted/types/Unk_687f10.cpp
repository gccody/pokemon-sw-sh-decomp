// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6250: its getter is out of line.
struct Unk_2399d08 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102777140: its getter is out of line.
struct Unk_239b398 {
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

// The type 0x7102777248.
struct Unk_239c100 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b8d8::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023a1520: vf_type and its thunks 0x7100688180 (+0x48), 0x71006881f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a1510 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b398::Unk_GetType());
        return &type;
    }

    ~Unk_23a1510() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023a18a8: vf_type and its thunks 0x710068c7e0 (+0x48), 0x710068c890 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a1898 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }

    ~Unk_23a1898() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023a19d8: vf_type and its thunks 0x710068ea80 (+0x48), 0x710068eaf0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a19c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
        return &type;
    }

    ~Unk_23a19c8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023a1ca8: vf_type and its thunks 0x7100691640 (+0x48), 0x71006916f0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a1c98 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399b40::Unk_GetType());
        return &type;
    }

    ~Unk_23a1c98() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023a1dc8: vf_type and its thunks 0x7100692cc0 (+0x48), 0x7100692d30 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a1db8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b398::Unk_GetType());
        return &type;
    }

    ~Unk_23a1db8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023a1fd0: vf_type and its thunks 0x7100699290 (+0x48), 0x7100699340 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a1fc0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }

    ~Unk_23a1fc0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023a20d8: vf_type and its thunks 0x710069a2b0 (+0x48), 0x710069a320 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a20c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b8d8::Unk_GetType());
        return &type;
    }

    ~Unk_23a20c8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100687f10
// 0x7100688180
// 0x71006881f0
const Unk_239a418_Type* Unk_23a1510::vf_type() {
    return Unk_GetType();
}

// 0x710068c710
// 0x710068c7e0
// 0x710068c890
const Unk_239a418_Type* Unk_23a1898::vf_type() {
    return Unk_GetType();
}

// 0x710068e9f0
// 0x710068ea80
// 0x710068eaf0
const Unk_239a418_Type* Unk_23a19c8::vf_type() {
    return Unk_GetType();
}

// 0x7100691590
// 0x7100691640
// 0x71006916f0
const Unk_239a418_Type* Unk_23a1c98::vf_type() {
    return Unk_GetType();
}

// 0x7100692a90
// 0x7100692cc0
// 0x7100692d30
const Unk_239a418_Type* Unk_23a1db8::vf_type() {
    return Unk_GetType();
}

// 0x71006991c0
// 0x7100699290
// 0x7100699340
const Unk_239a418_Type* Unk_23a1fc0::vf_type() {
    return Unk_GetType();
}

// 0x710069a230
// 0x710069a2b0
// 0x710069a320
const Unk_239a418_Type* Unk_23a20c8::vf_type() {
    return Unk_GetType();
}
