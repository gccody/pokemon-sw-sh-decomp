// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_243e198 : public Unk_23f4660 {
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
    Unk_239a418_Ref<Unk_239a418> field_600;
    Unk_239a418_Ref<Unk_239a418> field_608;
    Unk_239a418_Ref<Unk_239a418> field_610;
    Unk_239a418_Ref<Unk_239a418> field_618;
    Unk_239a418_Ref<Unk_239a418> field_620;
    Unk_239a418_Ref<Unk_239a418> field_628;
    Unk_239a418_Ref<Unk_239a418> field_630;
    Unk_239a418_Ref<Unk_239a418> field_638;
    Unk_239a418_Ref<Unk_239a418> field_640;
    Unk_239a418_Ref<Unk_239a418> field_648;
    Unk_239a418_Ref<Unk_239a418> field_650;
    Unk_239a418_Ref<Unk_239a418> field_658;
    Unk_239a418_Ref<Unk_239a418> field_660;
    Unk_239a418_Ref<Unk_239a418> field_668;
    Unk_239a418_Ref<Unk_239a418> field_670;
};
PKMN_OFFSET_ASSERT(Unk_243e198, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_243e198, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_243e198, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_243e198, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_243e198, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_243e198, field_5f8, 0x5f8);
PKMN_OFFSET_ASSERT(Unk_243e198, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_243e198, field_608, 0x608);
PKMN_OFFSET_ASSERT(Unk_243e198, field_610, 0x610);
PKMN_OFFSET_ASSERT(Unk_243e198, field_618, 0x618);
PKMN_OFFSET_ASSERT(Unk_243e198, field_620, 0x620);
PKMN_OFFSET_ASSERT(Unk_243e198, field_628, 0x628);
PKMN_OFFSET_ASSERT(Unk_243e198, field_630, 0x630);
PKMN_OFFSET_ASSERT(Unk_243e198, field_638, 0x638);
PKMN_OFFSET_ASSERT(Unk_243e198, field_640, 0x640);
PKMN_OFFSET_ASSERT(Unk_243e198, field_648, 0x648);
PKMN_OFFSET_ASSERT(Unk_243e198, field_650, 0x650);
PKMN_OFFSET_ASSERT(Unk_243e198, field_658, 0x658);
PKMN_OFFSET_ASSERT(Unk_243e198, field_660, 0x660);
PKMN_OFFSET_ASSERT(Unk_243e198, field_668, 0x668);
PKMN_OFFSET_ASSERT(Unk_243e198, field_670, 0x670);

// 0x7101476ae0; its type 0x7101476b50
const Unk_239a418_Type* Unk_243e198::vf_type() {
    return Unk_GetType();
}
