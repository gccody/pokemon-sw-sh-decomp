// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_243dd28 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf15() override;
    Unk_239a418_Ref<Unk_239a418> field_5d0;
    Unk_239a418_Ref<Unk_239a418> field_5d8;
    Unk_239a418_Ref<Unk_239a418> field_5e0;
    Unk_239a418_Ref<Unk_239a418> field_5e8;
    Unk_239a418_Ref<Unk_239a418> field_5f0;
    Unk_239a418_Ref<Unk_239a418> field_5f8;
    u8 _600[0x8];
    Unk_239a418_Ref<Unk_239a418> field_608;
    Unk_239a418_Ref<Unk_239a418> field_610;
};
PKMN_OFFSET_ASSERT(Unk_243dd28, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_243dd28, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_243dd28, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_243dd28, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_243dd28, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_243dd28, field_5f8, 0x5f8);
PKMN_OFFSET_ASSERT(Unk_243dd28, field_608, 0x608);
PKMN_OFFSET_ASSERT(Unk_243dd28, field_610, 0x610);

// 0x7101471fe0; its type 0x7101472050
const Unk_239a418_Type* Unk_243dd28::vf_type() {
    return Unk_GetType();
}
