// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e9d10: its getter is out of line.
struct Unk_27e9d10 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710241a208: vf_type and its thunks 0x7101148de0 (+0x48), 0x7101148e50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241a1f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e9d10::Unk_GetType());
        return &type;
    }

    ~Unk_241a1f8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101148d70
// 0x7101148de0
// 0x7101148e50
const Unk_239a418_Type* Unk_241a1f8::vf_type() {
    return Unk_GetType();
}
