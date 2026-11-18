// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23ed510 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    Unk_239a418_Ref<Unk_239a418> field_88;
    u8 _90[0x170];
    Unk_239a418_Ref<Unk_239a418> field_200;
    Unk_239a418_Ref<Unk_239a418> field_208;
    Unk_239a418_Ref<Unk_239a418> field_210;
    u8 _218[0x20];
    Unk_239a418_Ref<Unk_239a418> field_238;
    u8 _240[0x20];
    Unk_239a418_Ref<Unk_239a418> field_260;
    Unk_239a418_Ref<Unk_239a418> field_268;
    u8 _270[0x18];
    Unk_239a418_Ref<Unk_239a418> field_288;
    Unk_239a418_Ref<Unk_239a418> field_290;
};
PKMN_OFFSET_ASSERT(Unk_23ed510, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23ed510, field_200, 0x200);
PKMN_OFFSET_ASSERT(Unk_23ed510, field_208, 0x208);
PKMN_OFFSET_ASSERT(Unk_23ed510, field_210, 0x210);
PKMN_OFFSET_ASSERT(Unk_23ed510, field_238, 0x238);
PKMN_OFFSET_ASSERT(Unk_23ed510, field_260, 0x260);
PKMN_OFFSET_ASSERT(Unk_23ed510, field_268, 0x268);
PKMN_OFFSET_ASSERT(Unk_23ed510, field_288, 0x288);
PKMN_OFFSET_ASSERT(Unk_23ed510, field_290, 0x290);

// 0x7100d6f540
u32 Unk_23ed510::vf7() {
    return 1;
}

// 0x7100d70030; its type 0x7100d70060
const Unk_239a418_Type* Unk_23ed510::vf_type() {
    return Unk_GetType();
}
