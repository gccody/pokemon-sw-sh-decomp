// Scope: common
//
// The League Card's "StateAlbumList" state (vtable 0x71243e0c8): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243e0c8 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243e198* field_78;
    Unk_243cff8* field_80;
    u32 field_88;
};

// 0x71014743d0
void Unk_243e0c8::vf7() {
    field_70 = Unk_d0c0_String("StateAlbumList");
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_243e198* list = views->Unk_a7bb80<Unk_243e198>("ViewList");
    field_78 = list;
    field_78->Unk_14758f0();
    Unk_243cff8* card = views->Unk_a7bb80<Unk_243cff8>("ViewCard");
    field_80 = card;
    Unk_239a418_Ref<Unk_243d5a8_80> sound = Unk_AlbumApp(this)->field_80;
    sound.m_ptr->Unk_1458310(2);
}
