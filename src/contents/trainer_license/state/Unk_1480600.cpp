// Scope: common
//
// The League Card's "StateCardCodeToCardPassMenu" state (vtable 0x71243f438): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243f438 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243e520* field_78;
    Unk_243d7a0* field_80;
};

// 0x7101480600
void Unk_243f438::vf7() {
    field_70 = Unk_d0c0_String("StateCardCodeToCardPassMenu");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243e520* menu = views->Unk_a7bb80<Unk_243e520>("ViewCardPassMenu");
    field_78 = menu;
    Unk_eb6230(field_78, 2);
    Unk_243d7a0* code = views->Unk_a7bb80<Unk_243d7a0>("ViewCardCode");
    field_80 = code;
    Unk_eb6230(field_80, 3);
    Unk_67bfa0(field_80->field_600);
}
