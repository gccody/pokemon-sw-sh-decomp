// Scope: common
//
// The box's "tips" state (vtable 0x7123c7a90): its vf9, type and thunks
// are tools/vtables.py's.
#include "contents/common/views.h"
#include "contents/pokebox/Unk_box.h"

class Unk_23c7a90 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_23c81e8* field_78;
    Unk_23f64b0* field_80;
};

// 0x7100a89eb0
void Unk_23c7a90::vf7() {
    field_70 = Unk_d0c0_String("tips");
    field_78 = Unk_BoxTopView(this);
    UNK_CHECK(field_78 != nullptr);
    Unk_23f64b0* tips = Unk_StateViews(this)->Unk_a7bb80<Unk_23f64b0>("TipsView");
    field_80 = tips;
    UNK_CHECK(field_80 != nullptr);
    reinterpret_cast<Unk_23c81e8*>(field_80)->Unk_CallE807f0(false);
    field_80->Unk_ebb290(false);
}

// 0x7100a8a130
u32 Unk_23c7a90::vf8() {
    if (!field_80->vf17())
        return 0;
    Unk_23c63c8* app = Unk_BoxApp(this);
    Unk_23c63c8_Data* data = app->Unk_GetField70();
    switch (data->field_0) {
        case 2:
            if (!field_78->Unk_aaa5d0()) {
                field_78->Unk_aa4680(28, false);
                app->Unk_SetField64(10);
                return 1;
            }
            break;
        case 3:
            switch (data->field_1a4) {
                case 3:
                case 4:
                    app->Unk_SetField64(27);
                    return 1;
                case 5:
                    app->Unk_SetField64(28);
                    return 1;
            }
            break;
    }
    app->Unk_SetField64(4);
    return 1;
}
