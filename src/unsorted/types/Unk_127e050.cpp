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

// vtable 0x7102429a18: vf_type and its thunks 0x710127e0e0 (+0x48), 0x710127e150 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2429a08 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24283e8::Unk_GetType());
        return &type;
    }

    ~Unk_2429a08() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710127e050
// 0x710127e0e0
// 0x710127e150
const Unk_239a418_Type* Unk_2429a08::vf_type() {
    return Unk_GetType();
}
