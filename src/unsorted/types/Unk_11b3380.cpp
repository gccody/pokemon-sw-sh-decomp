// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027d8f98.
struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

// vtable 0x710241f078: vf_type and its thunks 0x71011b3450 (+0x48), 0x71011b3500 (+0x50).
// Its base and its other functions aren't written here.
class Unk_241f068 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }

    ~Unk_241f068() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71011b3380
// 0x71011b3450
// 0x71011b3500
const Unk_239a418_Type* Unk_241f068::vf_type() {
    return Unk_GetType();
}
