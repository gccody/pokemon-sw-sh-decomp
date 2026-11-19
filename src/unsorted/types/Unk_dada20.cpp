// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027de920: its getter is out of line.
struct Unk_27de920 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023ef3f8: vf_type and its thunks 0x7100dada90 (+0x48), 0x7100dadb00 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ef3e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27de920::Unk_GetType());
        return &type;
    }

    ~Unk_23ef3e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100dada20
// 0x7100dada90
// 0x7100dadb00
const Unk_239a418_Type* Unk_23ef3e8::vf_type() {
    return Unk_GetType();
}
