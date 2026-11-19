// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0590.
struct Unk_23f43c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x71024053c0: vf_type and its thunks 0x7100fe2790 (+0x48), 0x7100fe27a0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100fe28c0).
// Its base and its other functions aren't written here.
class Unk_24053b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_24053b0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100fe2680
// 0x7100fe2790
// 0x7100fe27a0
const Unk_239a418_Type* Unk_24053b0::vf_type() {
    return Unk_GetType();
}
