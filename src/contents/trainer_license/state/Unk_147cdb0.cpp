// Scope: common
//
// The League Card's "StateDetailToInputCode" state (vtable 0x71243eda0): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243eda0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243dd28* field_78;
    Unk_243d7a0* field_80;
    Unk_243cff8* field_88;
};

// 0x710147cdb0
void Unk_243eda0::vf7() {
    field_70 = Unk_d0c0_String("StateDetailToInputCode");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243d7a0* code = views->Unk_a7bb80<Unk_243d7a0>("ViewCardCode");
    field_80 = code;
    Unk_eb6230(field_80, 2);
    field_80->Unk_146b8b0(0);
    Unk_243dd28* info = views->Unk_a7bb80<Unk_243dd28>("ViewCardInfo");
    field_78 = info;
    Unk_eb6230(field_78, 3);
    Unk_243cff8* card = views->Unk_a7bb80<Unk_243cff8>("ViewCard");
    field_88 = card;
    Unk_eb6230(field_88, 3);
}
