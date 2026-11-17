// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

struct Unk_23f1a48_60 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_23f1a48_60, field_0, 0x0);

// A class on Unk_239a418 whose type getter (0x7100e41990) is out of line.
struct Unk_27e0ac0 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23f1a48 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e0ac0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    Unk_23f1a48_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_23f1a48, field_60, 0x60);

// 0x7100e41320
void Unk_23f1a48::vf8() {
    if (field_60 != nullptr) {
        field_60->field_0 = 1;
    }
}

// 0x7100e41490
const Unk_239a418_Type* Unk_23f1a48::vf_type() {
    return Unk_GetType();
}
