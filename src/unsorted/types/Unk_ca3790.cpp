// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027da568: its getter is out of line.
struct Unk_27da568 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027da558.
struct Unk_23e0b50 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da568::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e0cc0: vf_type and its thunks 0x7100ca39c0 (+0x48), 0x7100ca3a70 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e0cb0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e0b50::Unk_GetType());
        return &type;
    }

    ~Unk_23e0cb0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100ca3790
// 0x7100ca39c0
// 0x7100ca3a70
const Unk_239a418_Type* Unk_23e0cb0::vf_type() {
    return Unk_GetType();
}
