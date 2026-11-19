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

// The type 0x7102777178: its getter is out of line.
struct Unk_239b8d8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027740c8: its getter is out of line.
struct Unk_239bb58 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027740b8: its getter is out of line.
struct Unk_239bd80 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102777248.
struct Unk_239c100 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239b8d8::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023f7790: vf_type and its thunks 0x7100ed24e0 (+0x48), 0x7100ed2590 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f7780 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }

    ~Unk_23f7780() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f78c8: vf_type and its thunks 0x7100ed4f40 (+0x48), 0x7100ed4fb0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f78b8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bd80::Unk_GetType());
        return &type;
    }

    ~Unk_23f78b8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f7c18: vf_type and its thunks 0x7100eda1c0 (+0x48), 0x7100eda230 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f7c08 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    ~Unk_23f7c08() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f7d28: vf_type and its thunks 0x7100ede6a0 (+0x48), 0x7100ede710 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f7d18 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23f7d18() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023f7f70: vf_type and its thunks 0x7100ee30d0 (+0x48), 0x7100ee3180 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f7f60 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239c100::Unk_GetType());
        return &type;
    }

    ~Unk_23f7f60() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100ed2290
// 0x7100ed24e0
// 0x7100ed2590
const Unk_239a418_Type* Unk_23f7780::vf_type() {
    return Unk_GetType();
}

// 0x7100ed4df0
// 0x7100ed4f40
// 0x7100ed4fb0
const Unk_239a418_Type* Unk_23f78b8::vf_type() {
    return Unk_GetType();
}

// 0x7100eda000
// 0x7100eda1c0
// 0x7100eda230
const Unk_239a418_Type* Unk_23f7c08::vf_type() {
    return Unk_GetType();
}

// 0x7100ede4d0
// 0x7100ede6a0
// 0x7100ede710
const Unk_239a418_Type* Unk_23f7d18::vf_type() {
    return Unk_GetType();
}

// 0x7100ee2e20
// 0x7100ee30d0
// 0x7100ee3180
const Unk_239a418_Type* Unk_23f7f60::vf_type() {
    return Unk_GetType();
}
