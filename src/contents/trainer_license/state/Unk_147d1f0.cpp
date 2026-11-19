// Scope: common
//
// The League Card's "StateAlbumDetailsToList" state (vtable 0x71243ee70): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243ee70 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243e198* field_78;
    Unk_243dd28* field_80;
};

// 0x710147d1f0
void Unk_243ee70::vf7() {
    field_70 = Unk_d0c0_String("StateAlbumDetailsToList");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243e198* list = views->Unk_a7bb80<Unk_243e198>("ViewList");
    field_78 = list;
    field_78->Unk_1475b00(0);
    Unk_eb6230(field_78, 2);
    Unk_e806b0(field_78, true, true);
    Unk_243dd28* info = views->Unk_a7bb80<Unk_243dd28>("ViewCardInfo");
    field_80 = info;
    Unk_eb6230(field_80, 3);
    Unk_239a418_Ref<Unk_243d5a8_70> ref = Unk_AlbumApp(this)->field_70;
    ref.m_ptr->Unk_Call14cc8c0();
}

// 0x710147d480
void Unk_243ee70::vf9() {
    Unk_e806b0(field_80, false, true);
}
