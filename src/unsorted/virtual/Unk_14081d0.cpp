// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x7101403820) is out of line.
struct Unk_27f0578 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_2437e00 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0578::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    u8 _60[0x18];
    Unk_239a418_Ref<Unk_239a418> field_78;
    u8 _80[0x8];
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
};
PKMN_OFFSET_ASSERT(Unk_2437e00, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_2437e00, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2437e00, field_90, 0x90);

// 0x7101408350
const Unk_239a418_Type* Unk_2437e00::vf_type() {
    return Unk_GetType();
}
