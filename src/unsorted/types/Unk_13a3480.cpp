// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d1728.
struct Unk_239fd60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x7102433b80: vf_type and its thunks 0x71013a3490 (+0x48), 0x71013a34a0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71013a1bc0).
// Its base and its other functions aren't written here.
class Unk_2433b70 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239fd60::Unk_GetType());
        return &type;
    }

    ~Unk_2433b70() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71013a3480
// 0x71013a3490
// 0x71013a34a0
const Unk_239a418_Type* Unk_2433b70::vf_type() {
    return Unk_GetType();
}
