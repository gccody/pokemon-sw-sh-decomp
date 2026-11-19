// Scope: common
//
// The League Card's "StateCardPassMenu" state (vtable 0x71243e638): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243e638 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243e520* field_78;
};

// 0x7101478880
void Unk_243e638::vf7() {
    field_70 = Unk_d0c0_String("StateCardPassMenu");
    Unk_243e520* menu = Unk_StateViews(this)->Unk_a7bb80<Unk_243e520>("ViewCardPassMenu");
    field_78 = menu;
    if (field_78 != nullptr) {
        field_78->Unk_1478240();
        Unk_ViewE807f0(field_78, false);
        field_78->field_5cc = 3;
    }
    if (Unk_243d5a8* app = Unk_AlbumApp(this)) {
        Unk_239a418_Ref<Unk_243d5a8_80> sound = app->field_80;
        sound.m_ptr->Unk_1458310(8);
    }
}

// 0x7101478a90
u32 Unk_243e638::vf8() {
    return field_78->field_5cc != 3;
}
