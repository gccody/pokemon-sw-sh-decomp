// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_23bcdf0 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    Unk_239a418_Ref<Unk_239a418> field_78;
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
};
PKMN_OFFSET_ASSERT(Unk_23bcdf0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_23bcdf0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_23bcdf0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23bcdf0, field_90, 0x90);

// 0x71008e87e0; its type 0x71008e8e50
const Unk_239a418_Type* Unk_23bcdf0::vf_type() {
    return Unk_GetType();
}
