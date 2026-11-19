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

// vtable 0x71023cd4b8: vf_type and its thunks 0x7100afbe00 (+0x48), 0x7100afbe10 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x7100ac5b50).
// Its base and its other functions aren't written here.
class Unk_23cd4a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    ~Unk_23cd4a8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100afbc90
// 0x7100afbe00
// 0x7100afbe10
const Unk_239a418_Type* Unk_23cd4a8::vf_type() {
    return Unk_GetType();
}
