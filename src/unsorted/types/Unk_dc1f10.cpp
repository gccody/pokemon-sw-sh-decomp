// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9318.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023efa68: vf_type and its thunks 0x7100dc2000 (+0x48), 0x7100dc2010 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100dc2200).
// Its base and its other functions aren't written here.
class Unk_23efa58 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23efa58() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100dc1f10
// 0x7100dc2000
// 0x7100dc2010
const Unk_239a418_Type* Unk_23efa58::vf_type() {
    return Unk_GetType();
}
