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

// The type 0x7102777228.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023d9ac8: vf_type and its thunks 0x7100c1cc10 (+0x48), 0x7100c1cc20 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100c1cdd0).
// Its base and its other functions aren't written here.
class Unk_23d9ab8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23d9ab8() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023d9be0: vf_type and its thunks 0x7100c1e740 (+0x48), 0x7100c1e7b0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23d9bd0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399d08::Unk_GetType());
        return &type;
    }

    ~Unk_23d9bd0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100c1ca60
// 0x7100c1cc10
// 0x7100c1cc20
const Unk_239a418_Type* Unk_23d9ab8::vf_type() {
    return Unk_GetType();
}

// 0x7100c1e6b0
// 0x7100c1e740
// 0x7100c1e7b0
const Unk_239a418_Type* Unk_23d9bd0::vf_type() {
    return Unk_GetType();
}
