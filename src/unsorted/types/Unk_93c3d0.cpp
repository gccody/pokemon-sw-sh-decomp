// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d5130: its getter is out of line.
struct Unk_23c0158 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023c0278: vf_type and its thunks 0x710093c470 (+0x48), 0x710093c4e0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23c0268 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c0158::Unk_GetType());
        return &type;
    }

    ~Unk_23c0268() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710093c3d0
// 0x710093c470
// 0x710093c4e0
const Unk_239a418_Type* Unk_23c0268::vf_type() {
    return Unk_GetType();
}
