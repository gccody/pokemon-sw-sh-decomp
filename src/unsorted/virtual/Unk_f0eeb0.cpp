// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4660.h"

class Unk_23fb3d0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf10() override;
    void vf14() override;
    void vf15() override;
    u32 vf16() override;
    Unk_239a418_Ref<Unk_239a418> field_5d0;
    Unk_239a418_Ref<Unk_239a418> field_5d8;
    Unk_239a418_Ref<Unk_239a418> field_5e0;
    u8 _5e8[0x8];
    Unk_23d4470_Callable field_5f0;
    u8 _670[0x28];
    Unk_239a418_Ref<Unk_239a418> field_698;
    Unk_239a418_Ref<Unk_239a418> field_6a0;
    Unk_239a418_Ref<Unk_239a418> field_6a8;
    Unk_239a418_Ref<Unk_239a418> field_6b0;
    Unk_239a418_Ref<Unk_239a418> field_6b8;
    Unk_239a418_Ref<Unk_239a418> field_6c0;
};
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_698, 0x698);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_6a0, 0x6a0);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_6a8, 0x6a8);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_6b0, 0x6b0);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_6b8, 0x6b8);
PKMN_OFFSET_ASSERT(Unk_23fb3d0, field_6c0, 0x6c0);

// 0x7100f11320; its type 0x7100f0eeb0
const Unk_239a418_Type* Unk_23fb3d0::vf_type() {
    return Unk_GetType();
}
