// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0580.
struct Unk_23f4318 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71023cee50: vf_type and its thunks 0x7100b30b10 (+0x48), 0x7100b30b20 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100b30410).
// Its base and its other functions aren't written here.
class Unk_23cee40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23cee40() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100b30ae0
// 0x7100b30b10
// 0x7100b30b20
const Unk_239a418_Type* Unk_23cee40::vf_type() {
    return Unk_GetType();
}
