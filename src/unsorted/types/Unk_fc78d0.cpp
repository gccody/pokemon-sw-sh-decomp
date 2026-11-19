// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9350: its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d9380.
struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102403188: vf_type and its thunks 0x7100fc79a0 (+0x48), 0x7100fc7a50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2403178 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_2403178() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100fc78d0
// 0x7100fc79a0
// 0x7100fc7a50
const Unk_239a418_Type* Unk_2403178::vf_type() {
    return Unk_GetType();
}
