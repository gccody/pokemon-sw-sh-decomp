// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027efce0: its getter is out of line.
struct Unk_2433b70 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102435d78: vf_type and its thunks 0x71013e2f70 (+0x48), 0x71013e2fe0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2435d68 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2433b70::Unk_GetType());
        return &type;
    }

    ~Unk_2435d68() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71013e2ee0
// 0x71013e2f70
// 0x71013e2fe0
const Unk_239a418_Type* Unk_2435d68::vf_type() {
    return Unk_GetType();
}
