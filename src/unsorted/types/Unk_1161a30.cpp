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

// vtable 0x710241b438: vf_type and its thunks 0x7101161ac0 (+0x48), 0x7101161b30 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241b428 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_241b428() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710241b720: vf_type and its thunks 0x7101164950 (+0x48), 0x71011649c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241b710 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_241b710() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101161a30
// 0x7101161ac0
// 0x7101161b30
const Unk_239a418_Type* Unk_241b428::vf_type() {
    return Unk_GetType();
}

// 0x7101164720
// 0x7101164950
// 0x71011649c0
const Unk_239a418_Type* Unk_241b710::vf_type() {
    return Unk_GetType();
}
