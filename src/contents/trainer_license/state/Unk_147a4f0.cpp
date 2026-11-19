// Scope: common
//
// The League Card's "StateAlbumListToTop" state (vtable 0x710243e978): its
// type and thunks are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243e978 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243d1c8* field_78;
    Unk_243d958* field_80;
    Unk_243dc10* field_88;
    Unk_243e198* field_90;
    Unk_243cff8* field_98;
};

// 0x710147a4f0
void Unk_243e978::vf7() {
    field_70 = Unk_d0c0_String("StateAlbumListToTop");
    Unk_AlbumApp(this)->Unk_1463730();
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243d1c8* bg = views->Unk_a7bb80<Unk_243d1c8>("ViewBg");
    field_78 = bg;
    field_78->Unk_145fcc0(6);
    field_78->Unk_145fcc0(3);
    Unk_243d958* top = views->Unk_a7bb80<Unk_243d958>("ViewTop");
    field_80 = top;
    Unk_eb6230(field_80, 0);
    Unk_e806b0(field_80, true, true);
    Unk_243dc10* menu = views->Unk_a7bb80<Unk_243dc10>("ViewTopMenu");
    field_88 = menu;
    Unk_eb6230(field_88, 0);
    Unk_e806b0(field_88, true, true);
    Unk_243e198* list = views->Unk_a7bb80<Unk_243e198>("ViewList");
    field_90 = list;
    Unk_eb6230(field_90, 1);
    Unk_243cff8* card = views->Unk_a7bb80<Unk_243cff8>("ViewCard");
    field_98 = card;
    Unk_eb6230(field_98, 1);
}

// 0x710147a8b0
void Unk_243e978::vf9() {
    Unk_e806b0(field_90, false, true);
    Unk_e806b0(field_98, false, true);
}
