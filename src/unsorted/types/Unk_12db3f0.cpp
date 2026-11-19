// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e05b0.
struct Unk_23f4660 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// vtable 0x710242d848: vf_type and its thunks 0x71012db4e0 (+0x48), 0x71012db4f0 (+0x50).
// Its getter is too big to be inlined: vf_type and the thunks tail-call it (0x71012db5e0).
// Its base and its other functions aren't written here.
class Unk_242d838 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_242d838() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71012db3f0
// 0x71012db4e0
// 0x71012db4f0
const Unk_239a418_Type* Unk_242d838::vf_type() {
    return Unk_GetType();
}
