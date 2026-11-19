// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d8f98: its getter is out of line.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710241f400: vf_type and its thunks 0x71011b69a0 (+0x48), 0x71011b6a10 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241f3f0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_241f3f0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71011b6910
// 0x71011b69a0
// 0x71011b6a10
const Unk_239a418_Type* Unk_241f3f0::vf_type() {
    return Unk_GetType();
}
