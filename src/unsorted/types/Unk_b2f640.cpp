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

// vtable 0x71023cec80: vf_type and its thunks 0x7100b2f710 (+0x48), 0x7100b2f7c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23cec70 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }

    ~Unk_23cec70() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100b2f640
// 0x7100b2f710
// 0x7100b2f7c0
const Unk_239a418_Type* Unk_23cec70::vf_type() {
    return Unk_GetType();
}
