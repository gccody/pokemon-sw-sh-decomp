// Scope: common
//
// The League Card's "StateCardPassMenuToAlbumTop" state (vtable 0x71243f508): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243f508 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243d1c8* field_78;
    Unk_243e520* field_80;
    Unk_243d958* field_88;
    Unk_243dc10* field_90;
};

// 0x71014809d0
void Unk_243f508::vf7() {
    field_70 = Unk_d0c0_String("StateCardPassMenuToAlbumTop");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243d1c8* bg = views->Unk_a7bb80<Unk_243d1c8>("ViewBg");
    field_78 = bg;
    field_78->Unk_145fcc0(1);
    Unk_243d958* top = views->Unk_a7bb80<Unk_243d958>("ViewTop");
    field_88 = top;
    Unk_eb6230(field_88, 2);
    Unk_243dc10* menu = views->Unk_a7bb80<Unk_243dc10>("ViewTopMenu");
    field_90 = menu;
    Unk_eb6230(field_90, 2);
    Unk_243e520* pass = views->Unk_a7bb80<Unk_243e520>("ViewCardPassMenu");
    field_80 = pass;
    Unk_eb6230(field_80, 3);
}
