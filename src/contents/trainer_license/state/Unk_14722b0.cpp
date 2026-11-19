// Scope: common
//
// The League Card album's "StateAlbumEnd" state (vtable 0x71243de40): its type and
// thunks are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243de40 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243d1c8* field_78;
    Unk_243d958* field_80;
    Unk_243dc10* field_88;
    Unk_23f6118* field_90;
};

// 0x71014722b0
void Unk_243de40::vf7() {
    field_70 = Unk_d0c0_String("StateAlbumEnd");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243d1c8* bg = views->Unk_a7bb80<Unk_243d1c8>("ViewBg");
    field_78 = bg;
    Unk_eb6230(field_78, 1);
    Unk_243d958* top = views->Unk_a7bb80<Unk_243d958>("ViewTop");
    field_80 = top;
    Unk_eb6230(field_80, 1);
    Unk_243dc10* menu = views->Unk_a7bb80<Unk_243dc10>("ViewTopMenu");
    field_88 = menu;
    Unk_eb6230(field_88, 1);
    Unk_23f6118* bar = views->Unk_a7bb80<Unk_23f6118>("CommonOptionBar");
    field_90 = bar;
    Unk_eb77f0(field_90);
}

// 0x7101472580
void Unk_243de40::vf9() {
    Unk_e806b0(field_78, false, true);
    Unk_e806b0(field_80, false, true);
    Unk_e806b0(field_88, false, true);
    Unk_e806b0(field_90, false, true);
}
