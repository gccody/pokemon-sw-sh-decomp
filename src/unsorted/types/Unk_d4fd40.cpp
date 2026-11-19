// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027efd90: its getter is out of line.
struct Unk_23dd820 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efd80.
struct Unk_23e4758 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dd820::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023ea8a8: vf_type and its thunks 0x7100d4fe10 (+0x48), 0x7100d4fec0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ea898 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e4758::Unk_GetType());
        return &type;
    }

    ~Unk_23ea898() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d4fd40
// 0x7100d4fe10
// 0x7100d4fec0
const Unk_239a418_Type* Unk_23ea898::vf_type() {
    return Unk_GetType();
}
