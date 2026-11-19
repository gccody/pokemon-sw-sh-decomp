// Scope: common
//
// The box's "npc_trade" state (vtable 0x71023c7270): its vf9, type and
// thunks are tools/vtables.py's.
#include "contents/common/views.h"
#include "contents/pokebox/Unk_box.h"

class Unk_23c7270 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    void Unk_a85ea0(u32 message, u32 arg, bool flag);
    void Unk_a86210(u32 value, bool keep);
    void Unk_a86310();
    void Unk_a863b0();

    Unk_23c81e8* field_78;
    Unk_23c7dd0* field_80;
    Unk_23f6218* field_88;
    Unk_23f5fa8* field_90;
    u32 field_98;
    u32 field_9c;
};

// 0x7100a852e0
void Unk_23c7270::vf7() {
    field_70 = Unk_d0c0_String("npc_trade");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_80 = Unk_StateView<Unk_23c7dd0>(this, "View_Model");
    UNK_CHECK(field_80 != nullptr);
    Unk_e806b0(field_80, true, true);
    field_80->Unk_ClearField5cc();
    Unk_a8b7c0_call(field_80);
    Unk_23f6218* view = Unk_StateViews(this)->Unk_a7bb80<Unk_23f6218>("SystemMessageView");
    field_88 = view;
    UNK_CHECK(field_88 != nullptr);
    field_90 = Unk_StateView<Unk_23f5fa8>(this, "AttentionView");
    UNK_CHECK(field_90 != nullptr);
    Unk_23c63c8* app = Unk_BoxApp(this);
    Unk_a77610(app, nullptr);
    app->Unk_SetFieldB0(field_80->Unk_a8b820());
    field_98 = 0;
}

// 0x7100a85ea0
void Unk_23c7270::Unk_a85ea0(u32 message, u32 arg, bool flag) {
    field_78->Unk_aa4680(message, false);
    Unk_eb8930_Params params;
    params.field_0 = field_78->Unk_aa5350().m_ptr;
    params.field_8 = arg;
    params.field_10 = flag;
    params.field_12 = field_78->Unk_GetField681();
    Unk_e806b0(field_88, true, true);
    reinterpret_cast<Unk_23c81e8*>(field_88)->Unk_CallE807f0(false);
    field_88->Unk_eb8930(params);
}

// 0x7100a86210
void Unk_23c7270::Unk_a86210(u32 value, bool keep) {
    Unk_23c63c8* app = Unk_BoxApp(this);
    Unk_23c63c8_Data* data = app->Unk_GetField70();
    data->field_1a4 = value;
    if (keep) {
        data->field_4c = 2;
    } else {
        u32 arg1 = 2;
        u32 arg2 = 0;
        u32 arg3 = 0;
        field_78->Unk_aaaf10(&arg1, &arg2, &arg3);
        data->field_4c = arg1;
        data->field_50 = arg3;
        data->field_52 = field_78->Unk_GetField614();
        data->field_19c = field_78->Unk_GetField618();
    }
    Unk_a86310();
    app->Unk_SetField64(2);
}

// 0x7100a86310
void Unk_23c7270::Unk_a86310() {
    Unk_23c63c8* app = Unk_BoxApp(this);
    app->Unk_CallA775f0(false);
    app->Unk_SetFieldB0(field_78->Unk_aab420());
    field_80->Unk_a8b790();
    Unk_a8b7d0_call(field_80);
}

// 0x7100a863b0
void Unk_23c7270::Unk_a863b0() {
    field_78->Unk_aa4680(40, false);
    Unk_eb5fb0_Params params;
    params.field_8 = field_78->Unk_aa5350().m_ptr;
    Unk_e806b0(field_90, true, true);
    Unk_e80580(field_90, 1, 1);
    reinterpret_cast<Unk_23c81e8*>(field_90)->Unk_CallE807f0(false);
    field_90->Unk_eb5fb0(params);
    field_9c = 0;
}
