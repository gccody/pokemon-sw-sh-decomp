// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027effd0.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x71013cc840: the copy of its getter that the getters below call (too big
// to be inlined into them: clang emits it here).
// The type 0x71027effc0.
struct Unk_27effc0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027dbb20.
struct Unk_23e8d60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effc0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023e8c50: vf_type and its thunks 0x7100d1ade0 (+0x48), 0x7100d1ae90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e8c40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e8d60::Unk_GetType());
        return &type;
    }

    ~Unk_23e8c40() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d1ac10
// 0x7100d1ade0
// 0x7100d1ae90
const Unk_239a418_Type* Unk_23e8c40::vf_type() {
    return Unk_GetType();
}
