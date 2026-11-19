// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023dd508: vf_type and its thunks 0x7100c75670 (+0x48), 0x7100c756e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23dd4f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_23dd4f8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100c75460
// 0x7100c75670
// 0x7100c756e0
const Unk_239a418_Type* Unk_23dd4f8::vf_type() {
    return Unk_GetType();
}
