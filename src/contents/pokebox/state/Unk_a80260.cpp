// Scope: common
//
// The box's "execute" state (vtable 0x71023c6af0): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/pokebox/Unk_box.h"

class Unk_23c6af0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
};

// 0x7100a80260
void Unk_23c6af0::vf7() {
    field_70 = Unk_d0c0_String("execute");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    if (Unk_BoxApp(this)->Unk_GetField68() == 1) {
        field_78->Unk_a96900();
    } else {
        field_78->Unk_aa50d0(false);
        field_78->Unk_a9bb00();
        field_78->Unk_CallE807f0(false);
        field_78->Unk_CallA96b10();
        if (field_78->Unk_CheckAa75b0())
            field_78->Unk_a94fd0(true);
    }
    field_78->Unk_ClearField608();
    field_78->Unk_SetAab2c0(true);
}
