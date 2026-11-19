// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027eddd0: its getter is out of line.
struct Unk_24283e8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710242ada8: vf_type and its thunks 0x71012911b0 (+0x48), 0x7101291220 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242ad98 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24283e8::Unk_GetType());
        return &type;
    }

    ~Unk_242ad98() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101291080
// 0x71012911b0
// 0x7101291220
const Unk_239a418_Type* Unk_242ad98::vf_type() {
    return Unk_GetType();
}
