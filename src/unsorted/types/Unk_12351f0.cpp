// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ecec0: its getter is out of line.
struct Unk_2423d30 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71024247a8: vf_type and its thunks 0x7101235360 (+0x48), 0x71012353d0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2424798 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2423d30::Unk_GetType());
        return &type;
    }

    ~Unk_2424798() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71012351f0
// 0x7101235360
// 0x71012353d0
const Unk_239a418_Type* Unk_2424798::vf_type() {
    return Unk_GetType();
}
