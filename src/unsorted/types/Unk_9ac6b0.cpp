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

// vtable 0x71023c45e0: vf_type and its thunks 0x71009ac840 (+0x48), 0x71009ac8b0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c45d0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23c45d0() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023c4738: vf_type and its thunks 0x71009acf80 (+0x48), 0x71009ad070 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c4728 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23c4728() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71009ac6b0
// 0x71009ac840
// 0x71009ac8b0
const Unk_239a418_Type* Unk_23c45d0::vf_type() {
    return Unk_GetType();
}

// 0x71009accd0
// 0x71009acf80
// 0x71009ad070
const Unk_239a418_Type* Unk_23c4728::vf_type() {
    return Unk_GetType();
}
