// Scope: common
//
// The League Card's "StateInputCode" state (vtable 0x71243e2b0): its type and thunks
// are tools/vtables.py's.
#include "contents/trainer_license/Unk_trlicense.h"

class Unk_243e2b0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_243d7a0* field_78;
};

// 0x7101476dc0
void Unk_243e2b0::vf7() {
    field_70 = Unk_d0c0_String("StateInputCode");
    Unk_243d7a0* code = Unk_StateViews(this)->Unk_a7bb80<Unk_243d7a0>("ViewCardCode");
    field_78 = code;
    if (field_78 != nullptr) {
        field_78->field_5d0 = 6;
        field_78->Unk_146c040();
        Unk_ViewE807f0(field_78, false);
        Unk_e80580(field_78, 1, 1);
    }
    if (Unk_243d5a8* app = Unk_AlbumApp(this)) {
        Unk_239a418_Ref<Unk_243d5a8_80> sound = app->field_80;
        sound.m_ptr->Unk_1458310(8);
    }
}

// 0x7101476fd0
u32 Unk_243e2b0::vf8() {
    switch (field_78->field_5d0) {
        case 3:
            field_78->Unk_146c0a0();
            field_78->field_5d0 = 6;
            Unk_e80580(field_78, 1, 1);
            Unk_14e1a30(reinterpret_cast<u64>(field_78->field_5e0), 1);
            break;
        case 4:
        case 5:
            return 1;
    }
    return 0;
}
