// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102774028: its getter is out of line.
struct Unk_2399708 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023f5268: vf_type and its thunks 0x7100ea0030 (+0x48), 0x7100ea00a0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23f5258 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399708::Unk_GetType());
        return &type;
    }

    ~Unk_23f5258() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100e9fef0
// 0x7100ea0030
// 0x7100ea00a0
const Unk_239a418_Type* Unk_23f5258::vf_type() {
    return Unk_GetType();
}
