// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8f98: its getter is out of line.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102419560: vf_type and its thunks 0x710112db30 (+0x48), 0x710112dba0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2419550 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2419550() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102419978: vf_type and its thunks 0x7101130f50 (+0x48), 0x7101130fc0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2419968 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_2419968() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102419810: vf_type and its thunks 0x7101130570 (+0x48), 0x7101130620 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2419800 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2419968::Unk_GetType());
        return &type;
    }

    ~Unk_2419800() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710112da80
// 0x710112db30
// 0x710112dba0
const Unk_239a418_Type* Unk_2419550::vf_type() {
    return Unk_GetType();
}

// 0x71011304a0
// 0x7101130570
// 0x7101130620
const Unk_239a418_Type* Unk_2419800::vf_type() {
    return Unk_GetType();
}

// 0x7101130e00
// 0x7101130f50
// 0x7101130fc0
const Unk_239a418_Type* Unk_2419968::vf_type() {
    return Unk_GetType();
}
