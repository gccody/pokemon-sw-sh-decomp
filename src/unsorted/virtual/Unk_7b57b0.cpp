// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_23a99d8 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf10() override;
    void vf14() override;
    Unk_239a418_Ref<Unk_239a418> field_5d0;
    u8 _5d8[0x20];
    Unk_239a418_Ref<Unk_239a418> field_5f8;
    Unk_239a418_Ref<Unk_239a418> field_600;
    Unk_239a418_Ref<Unk_239a418> field_608;
    Unk_239a418_Ref<Unk_239a418> field_610;
};
PKMN_OFFSET_ASSERT(Unk_23a99d8, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_23a99d8, field_5f8, 0x5f8);
PKMN_OFFSET_ASSERT(Unk_23a99d8, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_23a99d8, field_608, 0x608);
PKMN_OFFSET_ASSERT(Unk_23a99d8, field_610, 0x610);

// 0x71007b5930; its type 0x71007b5c60
const Unk_239a418_Type* Unk_23a99d8::vf_type() {
    return Unk_GetType();
}
