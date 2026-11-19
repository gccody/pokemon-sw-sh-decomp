// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e05b0: its getter is out of line.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023f2ba0: vf_type and its thunks 0x7100e659e0 (+0x48), 0x7100e65a50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f2b90 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_23f2b90() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100e658b0
// 0x7100e659e0
// 0x7100e65a50
const Unk_239a418_Type* Unk_23f2b90::vf_type() {
    return Unk_GetType();
}
