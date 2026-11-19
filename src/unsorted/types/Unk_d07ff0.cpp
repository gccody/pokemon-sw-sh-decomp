// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027daa18: its getter is out of line.
struct Unk_23e7560 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023e7380: vf_type and its thunks 0x7100d081b0 (+0x48), 0x7100d08220 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e7370 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e7560::Unk_GetType());
        return &type;
    }

    ~Unk_23e7370() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d07ff0
// 0x7100d081b0
// 0x7100d08220
const Unk_239a418_Type* Unk_23e7370::vf_type() {
    return Unk_GetType();
}
