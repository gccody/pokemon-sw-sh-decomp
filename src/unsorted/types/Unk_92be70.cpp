// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d2fa0: its getter is out of line.
struct Unk_27d2fa0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023bf570: vf_type and its thunks 0x710092bf00 (+0x48), 0x710092bf70 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23bf560 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }

    ~Unk_23bf560() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710092be70
// 0x710092bf00
// 0x710092bf70
const Unk_239a418_Type* Unk_23bf560::vf_type() {
    return Unk_GetType();
}
