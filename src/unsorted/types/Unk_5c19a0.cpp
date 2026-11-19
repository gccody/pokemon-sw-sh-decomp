// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71024ba7e8.
struct Unk_239a360 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102399090: vf_type and its thunks 0x71005c1ab0 (+0x48), 0x71005c1ac0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71005c1b90).
// Its base and its other functions aren't written here.
class Unk_2399080 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a360::Unk_GetType());
        return &type;
    }

    ~Unk_2399080() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71005c19a0
// 0x71005c1ab0
// 0x71005c1ac0
const Unk_239a418_Type* Unk_2399080::vf_type() {
    return Unk_GetType();
}
