// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027effa0: its getter is out of line.
struct Unk_23dfb38 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x71023e9ce0: vf_type and its thunks 0x7100d3bb20 (+0x48), 0x7100d3bb90 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23e9cd0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dfb38::Unk_GetType());
        return &type;
    }

    ~Unk_23e9cd0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d3ba10
// 0x7100d3bb20
// 0x7100d3bb90
const Unk_239a418_Type* Unk_23e9cd0::vf_type() {
    return Unk_GetType();
}
