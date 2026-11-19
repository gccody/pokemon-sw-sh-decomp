// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e0630: its getter is out of line.
struct Unk_2444850 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102444f60: vf_type and its thunks 0x71014eb620 (+0x48), 0x71014eb690 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2444f50 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2444850::Unk_GetType());
        return &type;
    }

    ~Unk_2444f50() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71014eb3b0
// 0x71014eb620
// 0x71014eb690
const Unk_239a418_Type* Unk_2444f50::vf_type() {
    return Unk_GetType();
}
