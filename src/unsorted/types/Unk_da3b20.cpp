// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9318: its getter is out of line.
struct Unk_23f4e40 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023eeca8: vf_type and its thunks 0x7100da4430 (+0x48), 0x7100da44a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23eec98 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23eec98() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100da3b20
// 0x7100da4430
// 0x7100da44a0
const Unk_239a418_Type* Unk_23eec98::vf_type() {
    return Unk_GetType();
}
