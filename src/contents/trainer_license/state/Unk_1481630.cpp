// Scope: common
//
// The League Card's "StateCardPassMenuToDisplayMyCode" state (vtable 0x71243f778): its vf9, type
// and thunks are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243f778 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243e520* field_78;
    Unk_243d7a0* field_80;
};

// 0x7101481630
void Unk_243f778::vf7() {
    field_70 = Unk_d0c0_String("StateCardPassMenuToDisplayMyCode");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243e520* menu = views->Unk_a7bb80<Unk_243e520>("ViewCardPassMenu");
    field_78 = menu;
    Unk_eb6230(field_78, 3);
    Unk_243d7a0* code = views->Unk_a7bb80<Unk_243d7a0>("ViewCardCode");
    field_80 = code;
    Unk_eb6230(field_80, 2);
    Unk_e806b0(field_80, true, true);
    field_80->Unk_146b8b0(1);
}
