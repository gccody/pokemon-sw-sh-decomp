// Scope: common
//
// The box's "first" state (vtable 0x71023c6a08): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/common/views.h"
#include "contents/pokebox/Unk_box.h"

class Unk_23c6a08 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    Unk_23f6118* field_80;
    Unk_23f64b0* field_88;
};

// 0x71023c6ad8
static const Unk_5cfad0_Literal Unk_23c6ad8("Play_UI_common_pc_login");

// 0x7100a7f980
void Unk_23c6a08::vf7() {
    field_70 = Unk_d0c0_String("first");
    Unk_23c63c8* app = Unk_BoxApp(this);
    Unk_23c63c8_Data* data = app->Unk_GetField70();
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    Unk_e806b0(field_78, true, true);
    field_78->Unk_a96a70();
    field_80 = Unk_StateView<Unk_23f6118>(this, "OptionBar");
    UNK_CHECK(field_80 != nullptr);
    Unk_eb7730(field_80);
    Unk_23f64b0* tips = Unk_StateViews(this)->Unk_a7bb80<Unk_23f64b0>("TipsView");
    field_88 = tips;
    UNK_CHECK(field_88 != nullptr);
    if (data->field_12)
        field_88->Unk_ebb140(app->Unk_a777a0());
    if (data->field_0 == 3 && data->field_1a4 - 3 < 2)
        field_78->Unk_aa50d0(true);
    app->Unk_SetFieldB0(field_78->Unk_aab420());
    if (data->field_1a0)
        data->field_1a0 = false;
    else
        Unk_1502120(Unk_23c6ad8.Unk_5cfad0());
}
