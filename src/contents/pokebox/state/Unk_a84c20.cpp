// Scope: common
//
// The box's "message" state (vtable 0x7123c71a0): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/common/views.h"
#include "contents/pokebox/Unk_box.h"

class Unk_23c71a0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    // Goes back to the box's state 2.
    void Unk_Back() {
        Unk_23c63c8* app = Unk_BoxApp(this);
        Unk_23c63c8_Data* data = app->Unk_GetField70();
        data->field_4c = 2;
        data->field_1a4 = 0;
        app->Unk_SetField64(2);
    }

    Unk_23c81e8* field_78;
    Unk_23f6218* field_80;
};

// 0x7100a84c20
void Unk_23c71a0::vf7() {
    field_70 = Unk_d0c0_String("message");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    field_78->Unk_a94960(false);
    field_78->Unk_a94fd0(false);
    Unk_23f6218* view = Unk_StateViews(this)->Unk_a7bb80<Unk_23f6218>("SystemMessageView");
    field_80 = view;
    UNK_CHECK(field_80 != nullptr);
    Unk_e806b0(field_80, true, true);
    reinterpret_cast<Unk_23c81e8*>(field_80)->Unk_CallE807f0(false);
    Unk_eb8930_Params params;
    params.field_0 = field_78->Unk_aa5350().m_ptr;
    field_80->Unk_eb8930(params);
}

// 0x7100a84f00
u32 Unk_23c71a0::vf8() {
    if (!field_80->Unk_IsDoneEb8e80())
        return 0;
    switch (field_78->Unk_GetField688()) {
        case 0x1c:
            Unk_Back();
            return 1;
        case 0x22:
            Unk_Back();
            return 1;
        case 0x2b:
            Unk_Back();
            return 1;
    }
    Unk_BoxApp(this)->Unk_SetField64(4);
    return 1;
}
