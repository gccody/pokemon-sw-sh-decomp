// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102778ed8: its getter is out of line.
struct Unk_23a34b8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d8980: its getter is out of line.
struct Unk_23d3130 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027ce9f8: its getter is out of line.
struct Unk_27ce9f8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023d3018: vf_type and its thunks 0x7100ba6f80 (+0x48), 0x7100ba6ff0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d3008 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d3130::Unk_GetType());
        return &type;
    }

    ~Unk_23d3008() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d3250: vf_type and its thunks 0x7100bad1f0 (+0x48), 0x7100bad260 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d3240 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d3130::Unk_GetType());
        return &type;
    }

    ~Unk_23d3240() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d34a0: vf_type and its thunks 0x7100bb1390 (+0x48), 0x7100bb1400 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d3490 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27ce9f8::Unk_GetType());
        return &type;
    }

    ~Unk_23d3490() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d3b50: vf_type and its thunks 0x7100bb7c90 (+0x48), 0x7100bb7d00 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d3b40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23a34b8::Unk_GetType());
        return &type;
    }

    ~Unk_23d3b40() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023d3e98: vf_type and its thunks 0x7100bb48e0 (+0x48), 0x7100bb48f0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100bb4d40).
// Its base and its other functions aren't written here.
class Unk_23d3e88 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_23d3e88() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100ba6d30
// 0x7100ba6f80
// 0x7100ba6ff0
const Unk_239a418_Type* Unk_23d3008::vf_type() {
    return Unk_GetType();
}

// 0x7100bacfa0
// 0x7100bad1f0
// 0x7100bad260
const Unk_239a418_Type* Unk_23d3240::vf_type() {
    return Unk_GetType();
}

// 0x7100bb0fb0
// 0x7100bb1390
// 0x7100bb1400
const Unk_239a418_Type* Unk_23d3490::vf_type() {
    return Unk_GetType();
}

// 0x7100bb46f0
// 0x7100bb48e0
// 0x7100bb48f0
const Unk_239a418_Type* Unk_23d3e88::vf_type() {
    return Unk_GetType();
}

// 0x7100bb7ad0
// 0x7100bb7c90
// 0x7100bb7d00
const Unk_239a418_Type* Unk_23d3b40::vf_type() {
    return Unk_GetType();
}
