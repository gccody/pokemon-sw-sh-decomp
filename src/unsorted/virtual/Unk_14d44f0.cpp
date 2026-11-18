// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_2443918 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    u32 vf9() override;
    void vf15() override;
    Unk_239a418_Ref<Unk_239a418> field_5d0;
    u8 _5d8[0x8];
    Unk_239a418_Ref<Unk_239a418> field_5e0;
    Unk_239a418_Ref<Unk_239a418> field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_2443918, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_2443918, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_2443918, field_5e8, 0x5e8);

// 0x71014d4610; its type 0x71014d4880
const Unk_239a418_Type* Unk_2443918::vf_type() {
    return Unk_GetType();
}
