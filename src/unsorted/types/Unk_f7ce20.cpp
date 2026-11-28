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

// 0x7100f67690: the copy of its getter that the getters below call (too big
// to be inlined into them: clang emits it here).
// The type 0x71027e15e0.
struct Unk_27e15e0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// vtable 0x7102400570: vf_type and its thunks 0x7100f7ceb0 (+0x48), 0x7100f7cf20 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2400560 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e15e0::Unk_GetType());
        return &type;
    }

    ~Unk_2400560() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100f7ce20
// 0x7100f7ceb0
// 0x7100f7cf20
const Unk_239a418_Type* Unk_2400560::vf_type() {
    return Unk_GetType();
}
