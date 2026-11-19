// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e3958: its getter is out of line.
struct Unk_27e3958 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710240b790: vf_type and its thunks 0x7101055a20 (+0x48), 0x7101055a90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_240b780 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e3958::Unk_GetType());
        return &type;
    }

    ~Unk_240b780() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710240ba80: vf_type and its thunks 0x7101057ca0 (+0x48), 0x7101057d10 (+0x50).
// Its base and its other functions aren't written here.
class Unk_240ba70 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e3958::Unk_GetType());
        return &type;
    }

    ~Unk_240ba70() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101055600
// 0x7101055a20
// 0x7101055a90
const Unk_239a418_Type* Unk_240b780::vf_type() {
    return Unk_GetType();
}

// 0x7101057840
// 0x7101057ca0
// 0x7101057d10
const Unk_239a418_Type* Unk_240ba70::vf_type() {
    return Unk_GetType();
}
