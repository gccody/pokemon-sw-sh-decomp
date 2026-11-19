// Scope: common
//
// The League Card's "StateDownloadCardDetail" state (vtable 0x710243f0f8):
// its type and thunks are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243f0f8 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243dd28* field_78;
};

// 0x710147e310
void Unk_243f0f8::vf7() {
    field_70 = Unk_d0c0_String("StateDownloadCardDetail");
    if (Unk_243d5a8* app = Unk_AlbumApp(this)) {
        Unk_239a418_Ref<Unk_243d5a8_80> sound = app->field_80;
        sound.m_ptr->Unk_1458310(12);
    }
    Unk_243dd28* info = Unk_StateViews(this)->Unk_a7bb80<Unk_243dd28>("ViewCardInfo");
    field_78 = info;
    field_78->Unk_1471d50(0);
    field_78->Unk_1471dd0(0);
}
