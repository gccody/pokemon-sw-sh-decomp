// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9318: its getter is out of line.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102433df0: vf_type and its thunks 0x71013a5a10 (+0x48), 0x71013a5a80 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2433de0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_2433de0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102433ec0: vf_type and its thunks 0x71013a63a0 (+0x48), 0x71013a6410 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2433eb0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_2433eb0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71013a5800
// 0x71013a5a10
// 0x71013a5a80
const Unk_239a418_Type* Unk_2433de0::vf_type() {
    return Unk_GetType();
}

// 0x71013a6050
// 0x71013a63a0
// 0x71013a6410
const Unk_239a418_Type* Unk_2433eb0::vf_type() {
    return Unk_GetType();
}
