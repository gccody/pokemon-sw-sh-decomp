// Scope: common
//
// The League Card's "StateAlbumListToDetails" state (vtable 0x71243f028): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243f028 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243e198* field_78;
    Unk_243dd28* field_80;
};

// 0x710147dee0
void Unk_243f028::vf7() {
    field_70 = Unk_d0c0_String("StateAlbumListToDetails");
    Unk_243d5a8* app = Unk_AlbumApp(this);
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243e198* list = views->Unk_a7bb80<Unk_243e198>("ViewList");
    field_78 = list;
    Unk_eb6230(field_78, 3);
    Unk_243dd28* info = views->Unk_a7bb80<Unk_243dd28>("ViewCardInfo");
    field_80 = info;
    field_80->Unk_1470d30(app->field_78->Unk_1459e50(app->field_90, app->field_94));
    Unk_eb6230(field_80, 2);
    Unk_e806b0(field_80, true, true);
}

// 0x710147e150
void Unk_243f028::vf9() {
    Unk_e806b0(field_78, false, true);
}
