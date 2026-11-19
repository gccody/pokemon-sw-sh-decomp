// Scope: common
//
// The League Card's "StateAlbumTopToCardPassMenu" state (vtable 0x71243f368): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243f368 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243d1c8* field_78;
    Unk_243e520* field_80;
    Unk_243d958* field_88;
    Unk_243dc10* field_90;
    bool field_98;
};

// 0x71014800f0
void Unk_243f368::vf7() {
    field_70 = Unk_d0c0_String("StateAlbumTopToCardPassMenu");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243d1c8* bg = views->Unk_a7bb80<Unk_243d1c8>("ViewBg");
    field_78 = bg;
    field_78->Unk_145fcc0(2);
    Unk_243d958* top = views->Unk_a7bb80<Unk_243d958>("ViewTop");
    field_88 = top;
    Unk_eb6230(field_88, 3);
    Unk_243dc10* menu = views->Unk_a7bb80<Unk_243dc10>("ViewTopMenu");
    field_90 = menu;
    Unk_eb6230(field_90, 3);
    Unk_243e520* pass = views->Unk_a7bb80<Unk_243e520>("ViewCardPassMenu");
    field_80 = pass;
    Unk_eb6230(field_80, 2);
    Unk_e806b0(field_80, true, true);
    Unk_243d7a0* code = views->Unk_a7bb80<Unk_243d7a0>("ViewCardCode");
    Unk_67bfa0(code->field_600);
    if (field_98)
        field_80->Unk_1478290();
}
