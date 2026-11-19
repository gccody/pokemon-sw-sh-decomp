// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ea148: its getter is out of line.
struct Unk_241b640 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710241e948: vf_type and its thunks 0x71011a4030 (+0x48), 0x71011a40a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241e938 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241b640::Unk_GetType());
        return &type;
    }

    ~Unk_241e938() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71011a3de0
// 0x71011a4030
// 0x71011a40a0
const Unk_239a418_Type* Unk_241e938::vf_type() {
    return Unk_GetType();
}
