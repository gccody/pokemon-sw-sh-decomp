// Scope: common
//
// The League Card's "StateCampEnd" state (vtable 0x71243d0f8): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243d0f8 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243d1c8* field_78;
    Unk_243cff8* field_80;
    Unk_243cee0* field_88;
    Unk_23f6118* field_90;
};

// 0x710145f570
void Unk_243d0f8::vf7() {
    field_70 = Unk_d0c0_String("StateCampEnd");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243d1c8* bg = views->Unk_a7bb80<Unk_243d1c8>("ViewBg");
    field_78 = bg;
    Unk_eb6230(field_78, 1);
    field_78->Unk_145fcc0(6);
    Unk_243cff8* card = views->Unk_a7bb80<Unk_243cff8>("ViewCard");
    field_80 = card;
    Unk_eb6230(field_80, 1);
    Unk_243cee0* camp = views->Unk_a7bb80<Unk_243cee0>("ViewCamp");
    field_88 = camp;
    Unk_eb6230(field_88, 1);
    Unk_23f6118* bar = views->Unk_a7bb80<Unk_23f6118>("CommonOptionBar");
    field_90 = bar;
    Unk_eb77f0(field_90);
}

// 0x710145f850
void Unk_243d0f8::vf9() {
    Unk_e806b0(field_78, false, true);
    Unk_e806b0(field_80, false, true);
    Unk_e806b0(field_88, false, true);
    Unk_e806b0(field_90, false, true);
}
