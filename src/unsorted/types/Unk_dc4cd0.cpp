// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027effc0: its getter is out of line.
struct Unk_27effc0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027dbb20.
struct Unk_23e8d60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effc0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023efb38: vf_type and its thunks 0x7100dc4ea0 (+0x48), 0x7100dc4f50 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23efb28 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e8d60::Unk_GetType());
        return &type;
    }

    ~Unk_23efb28() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100dc4cd0
// 0x7100dc4ea0
// 0x7100dc4f50
const Unk_239a418_Type* Unk_23efb28::vf_type() {
    return Unk_GetType();
}
