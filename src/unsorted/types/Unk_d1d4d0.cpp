// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027effd0: its getter is out of line.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027effc0.
struct Unk_27effc0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e8d70: vf_type and its thunks 0x7100d1d6a0 (+0x48), 0x7100d1d750 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e8d60 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effc0::Unk_GetType());
        return &type;
    }

    ~Unk_23e8d60() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d1d4d0
// 0x7100d1d6a0
// 0x7100d1d750
const Unk_239a418_Type* Unk_23e8d60::vf_type() {
    return Unk_GetType();
}
