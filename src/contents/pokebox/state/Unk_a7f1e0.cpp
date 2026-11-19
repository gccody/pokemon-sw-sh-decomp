// Scope: common
//
// The box's "end" state (vtable 0x71023c6920): its type and thunks are
// tools/vtables.py's (src/unsorted/virtual/Unk_a7f750.cpp).
#include "contents/pokebox/Unk_box.h"

class Unk_23c6920 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    Unk_23f6118* field_80;
};

// 0x71023c69f0
static const Unk_5cfad0_Literal Unk_23c69f0("Play_UI_common_pc_logoff");

// 0x7100a7f1e0
void Unk_23c6920::vf7() {
    field_70 = Unk_d0c0_String("end");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_a96aa0();
    field_80 = Unk_StateView<Unk_23f6118>(this, "OptionBar");
    UNK_CHECK(field_80 != nullptr);
    Unk_eb77f0(field_80);
    Unk_a77610(Unk_BoxApp(this), 0);
    Unk_23c63c8_Data* data = Unk_BoxApp(this)->Unk_GetField70();
    if (data->field_1a4 != 0)
        data->field_1a0 = true;
    else
        Unk_1502120(Unk_23c69f0.Unk_5cfad0());
}

// 0x7100a7f610
void Unk_23c6920::vf9() {
    field_78 = Unk_BoxTopView(this);
    if (field_78 != nullptr) {
        Unk_e806b0(field_78, false, true);
        Unk_e80580(field_78, 0, 1);
    }
}
