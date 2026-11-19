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

// vtable 0x71023ee180: vf_type and its thunks 0x7100d93ed0 (+0x48), 0x7100d93f40 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ee170 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23ee170() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d93e60
// 0x7100d93ed0
// 0x7100d93f40
const Unk_239a418_Type* Unk_23ee170::vf_type() {
    return Unk_GetType();
}
