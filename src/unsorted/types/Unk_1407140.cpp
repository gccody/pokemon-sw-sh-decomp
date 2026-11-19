// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027f0578: its getter is out of line.
struct Unk_27f0578 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102437ca0: vf_type and its thunks 0x71014071d0 (+0x48), 0x7101407240 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2437c90 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0578::Unk_GetType());
        return &type;
    }

    ~Unk_2437c90() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101407140
// 0x71014071d0
// 0x7101407240
const Unk_239a418_Type* Unk_2437c90::vf_type() {
    return Unk_GetType();
}
