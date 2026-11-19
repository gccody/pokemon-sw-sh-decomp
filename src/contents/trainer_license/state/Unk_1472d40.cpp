// Scope: common
//
// The League Card album's "StateAlbumTop" state (vtable 0x71243df10): its type and
// thunks are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243df10 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243dc10* field_78;
    u32 field_80;
};

// 0x7101472d40
void Unk_243df10::vf7() {
    field_70 = Unk_d0c0_String("StateAlbumTop");
    Unk_243dc10* menu = Unk_StateViews(this)->Unk_a7bb80<Unk_243dc10>("ViewTopMenu");
    field_78 = menu;
    field_78->Unk_14705a0();
    {
        Unk_239a418_Ref<Unk_243d5a8_80> sound = Unk_AlbumApp(this)->field_80;
        sound.m_ptr->Unk_1458310(1);
    }
    if (Unk_243d5a8_88* p = Unk_AlbumApp(this)->field_88)
        p->Unk_1341270(1);
}

// 0x7101473040
void Unk_243df10::vf9() {
    if (field_80 == 4)
        return;
    if (Unk_243d5a8_88* p = Unk_AlbumApp(this)->field_88)
        p->Unk_1341270(0);
}
