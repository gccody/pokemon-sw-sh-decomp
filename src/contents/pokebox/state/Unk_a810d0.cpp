// Scope: common
//
// The box's "free" state (vtable 0x71023c6bf0): its vf9, type and thunks are
// tools/vtables.py's.
#include "contents/common/views.h"
#include "contents/pokebox/Unk_box.h"

class Unk_23c6bf0 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    Unk_23f6218* field_80;
    u32 field_88;
};

// 0x7100a810d0
void Unk_23c6bf0::vf7() {
    field_70 = Unk_d0c0_String("free");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    Unk_23f6218* view = Unk_StateViews(this)->Unk_a7bb80<Unk_23f6218>("SystemMessageView");
    field_80 = view;
    UNK_CHECK(field_80 != nullptr);
    field_88 = 0;
}

// 0x7100a81350
u32 Unk_23c6bf0::vf8() {
    switch (field_88) {
        case 0:
            field_78->Unk_aa59e0();
            field_88++;
            // fall through
        case 1:
            if (!field_78->Unk_aa5b30())
                return 0;
            field_88++;
            return 0;
        case 2: {
            field_78->Unk_aa4680(13, false);
            Unk_eb8930_Params params;
            params.field_0 = field_78->Unk_aa5350().m_ptr;
            Unk_e806b0(field_80, true, true);
            reinterpret_cast<Unk_23c81e8*>(field_80)->Unk_CallE807f0(false);
            field_80->Unk_eb8930(params);
            field_88++;
            return 0;
        }
        case 3:
            if (!field_80->Unk_IsDoneEb8e80())
                return 0;
            if (field_78->Unk_aa5c80()) {
                field_88 = 4;
                return 0;
            }
            field_88 = 5;
            return 0;
        case 4:
            if (!field_78->Unk_aa5e60())
                return 0;
            field_88++;
            // fall through
        case 5: {
            Unk_23c63c8* app = Unk_BoxApp(this);
            field_78->Unk_aa5eb0();
            Unk_a77610(app, field_78->Unk_aab510());
            app->Unk_SetField64(4);
            return 1;
        }
    }
    return 0;
}
